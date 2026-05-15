/*
**  Flappy Bird - RingRayLib
**  ===================================
**  Classic pipe dodging with gravity physics!
**  Tap to flap, survive as long as you can.
**
**  Controls:
**    Space / Up / W   - Flap (jump)
**    Left Click       - Flap
**    R                - Restart after game over
**    M                - Toggle mute (visual flash)
**    D                - Toggle day/night
**    N                - New game
**    1-3              - Difficulty (Easy/Normal/Hard)
**    ESC              - Exit
**
**  Features:
**    - Gravity physics with terminal velocity
**    - Procedural pipe generation with gap sizing
**    - Parallax scrolling (sky, mountains, city, ground)
**    - Bird rotation follows velocity
**    - Score medals (bronze/silver/gold/platinum)
**    - Speed increases over time
**    - Day/night cycle
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W = 480
SCREEN_H = 700

PI = 3.14159265

// Physics
GRAVITY = 1400.0
FLAP_FORCE = -420.0
MAX_FALL = 600.0
MAX_RISE = -500.0

// Bird
BIRD_X = 100
BIRD_W = 34
BIRD_H = 24
BIRD_RADIUS = 14

// Pipes
PIPE_W = 60
PIPE_GAP = 160        // vertical gap
PIPE_SPACING = 220     // horizontal spacing
PIPE_SPEED = 150.0
MAX_PIPES = 8

// Ground
GROUND_Y = 620
GROUND_H = 80

// Game states
STATE_MENU    = 1
STATE_READY   = 2
STATE_PLAYING = 3
STATE_DYING   = 4
STATE_DEAD    = 5

// Difficulty
DIFF_EASY   = 1
DIFF_NORMAL = 2
DIFF_HARD   = 3
diffNames = ["Easy", "Normal", "Hard"]
diffGaps  = [180, 155, 125]
diffSpeeds = [130.0, 155.0, 190.0]

// =============================================================
// State
// =============================================================

gameState = STATE_MENU
difficulty = DIFF_NORMAL
animTime = 0.0
screenShake = 0.0

// Bird
birdY = 300.0
birdVel = 0.0
birdAngle = 0.0      // visual rotation (degrees)
birdFrame = 0        // wing animation frame
birdFlapTime = 0.0
birdAlive = true

// Pipes: [x, gapY, scored, active]
pipes = []

// Scroll positions
groundScroll = 0.0
bgScroll1 = 0.0      // far mountains
bgScroll2 = 0.0      // near city
cloudScroll = 0.0

// Score
score = 0
bestScore = 0
newBest = false

// Speed scaling
currentSpeed = 150.0

// Day/night
isNight = false
dayTimer = 0.0

// Particles (death feathers + score sparkle)
MAX_PARTS = 30
partX = list(MAX_PARTS)
partY = list(MAX_PARTS)
partVX = list(MAX_PARTS)
partVY = list(MAX_PARTS)
partLife = list(MAX_PARTS)
partActive = list(MAX_PARTS)
partR = list(MAX_PARTS)
partG = list(MAX_PARTS)
partB = list(MAX_PARTS)

for i = 1 to MAX_PARTS
    partActive[i] = 0
next

// Stars (night sky)
MAX_STARS = 60
starX = list(MAX_STARS)
starY = list(MAX_STARS)
starBr = list(MAX_STARS)
starPh = list(MAX_STARS)

for i = 1 to MAX_STARS
    starX[i] = GetRandomValue(0, SCREEN_W)
    starY[i] = GetRandomValue(0, GROUND_Y - 50)
    starBr[i] = GetRandomValue(80, 255)
    starPh[i] = GetRandomValue(0, 628) / 100.0
next

// Clouds
MAX_CLOUDS = 6
cloudX2 = list(MAX_CLOUDS)
cloudY2 = list(MAX_CLOUDS)
cloudW2 = list(MAX_CLOUDS)
cloudSp = list(MAX_CLOUDS)

for i = 1 to MAX_CLOUDS
    cloudX2[i] = GetRandomValue(0, SCREEN_W + 100) * 1.0
    cloudY2[i] = GetRandomValue(30, 200) * 1.0
    cloudW2[i] = GetRandomValue(50, 120) * 1.0
    cloudSp[i] = GetRandomValue(10, 30) * 1.0
next

// Score popup
popupScore = 0
popupTimer = 0.0
popupY = 0.0

// =============================================================
// Main
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Flappy Bird - RingRayLib")
SetTargetFPS(60)
SetExitKey(0)

fb_resetGame()

while !WindowShouldClose()
    fb_update()
    BeginDrawing()
        fb_draw()
    EndDrawing()
end

CloseWindow()

// =============================================================
// Reset
// =============================================================

func fb_resetGame
    birdY = 300.0
    birdVel = 0.0
    birdAngle = 0.0
    birdFrame = 0
    birdFlapTime = 0.0
    birdAlive = true
    score = 0
    newBest = false
    pipes = []
    currentSpeed = diffSpeeds[difficulty]
    screenShake = 0.0
    popupTimer = 0.0

    for i = 1 to MAX_PARTS
        partActive[i] = 0
    next

    // Pre-generate pipes
    for i = 1 to MAX_PIPES
        px = SCREEN_W + 200 + (i - 1) * PIPE_SPACING
        gapY = GetRandomValue(100, GROUND_Y - diffGaps[difficulty] - 80)
        add(pipes, [px * 1.0, gapY * 1.0, 0, 1])
    next

    gameState = STATE_READY

// =============================================================
// Update
// =============================================================

func fb_update
    dt = GetFrameTime()
    if dt > 0.03 dt = 0.03 ok
    animTime += dt

    if IsKeyPressed(KEY_ESCAPE)
        CloseWindow()
        shutdown(0)
    ok

    if IsKeyPressed(KEY_N)
        fb_resetGame()
        gameState = STATE_MENU
    ok

    if IsKeyPressed(KEY_D) isNight = !isNight ok

    if IsKeyPressed(KEY_ONE)   difficulty = DIFF_EASY   fb_resetGame() ok
    if IsKeyPressed(KEY_TWO)   difficulty = DIFF_NORMAL  fb_resetGame() ok
    if IsKeyPressed(KEY_THREE) difficulty = DIFF_HARD    fb_resetGame() ok

    // Screen shake decay
    if screenShake > 0
        screenShake -= dt * 20
        if screenShake < 0 screenShake = 0 ok
    ok

    // Popup decay
    if popupTimer > 0
        popupTimer -= dt
        popupY -= 40 * dt
    ok

    // Scroll background regardless of state
    if gameState = STATE_PLAYING or gameState = STATE_READY
        scrollSpd = currentSpeed
        if gameState = STATE_READY scrollSpd = currentSpeed * 0.3 ok
        groundScroll += scrollSpd * dt
        if groundScroll > 48 groundScroll -= 48 ok
        bgScroll1 += scrollSpd * 0.15 * dt
        bgScroll2 += scrollSpd * 0.35 * dt
    ok

    // Clouds always scroll
    for i = 1 to MAX_CLOUDS
        cloudX2[i] -= cloudSp[i] * dt
        if cloudX2[i] < -cloudW2[i]
            cloudX2[i] = SCREEN_W + cloudW2[i]
            cloudY2[i] = GetRandomValue(30, 200) * 1.0
        ok
    next

    // Bird wing animation
    birdFlapTime += dt
    if birdFlapTime > 0.1
        birdFlapTime -= 0.1
        birdFrame++
        if birdFrame > 2 birdFrame = 0 ok
    ok

    // Particles
    fb_updateParticles(dt)

    // State machine
    if gameState = STATE_MENU
        fb_updateMenu(dt)
        return
    ok

    if gameState = STATE_READY
        fb_updateReady(dt)
        return
    ok

    if gameState = STATE_PLAYING
        fb_updatePlaying(dt)
        return
    ok

    if gameState = STATE_DYING
        fb_updateDying(dt)
        return
    ok

    if gameState = STATE_DEAD
        fb_updateDead(dt)
        return
    ok

// =============================================================
// Menu State
// =============================================================

func fb_updateMenu dt
    // Bird bobs on menu
    birdY = 280 + sin(animTime * 2.5) * 20

    if fb_isFlap()
        fb_resetGame()
        gameState = STATE_READY
    ok

// =============================================================
// Ready State
// =============================================================

func fb_updateReady dt
    birdY = 300 + sin(animTime * 3) * 12

    if fb_isFlap()
        gameState = STATE_PLAYING
        birdVel = FLAP_FORCE
        fb_spawnFlapParticles()
    ok

// =============================================================
// Playing State
// =============================================================

func fb_updatePlaying dt
    // Flap
    if fb_isFlap()
        birdVel = FLAP_FORCE
        fb_spawnFlapParticles()
    ok

    // Gravity
    birdVel += GRAVITY * dt
    if birdVel > MAX_FALL birdVel = MAX_FALL ok
    if birdVel < MAX_RISE birdVel = MAX_RISE ok

    birdY += birdVel * dt

    // Bird angle based on velocity
    targetAngle = birdVel * 0.09
    if targetAngle > 70 targetAngle = 70 ok
    if targetAngle < -25 targetAngle = -25 ok
    birdAngle += (targetAngle - birdAngle) * 8 * dt

    // Move pipes
    for i = 1 to len(pipes)
        if pipes[i][4] = 0 loop ok
        pipes[i][1] -= currentSpeed * dt

        // Score when passing
        if pipes[i][3] = 0 and pipes[i][1] + PIPE_W < BIRD_X
            pipes[i][3] = 1
            score++
            popupScore = score
            popupTimer = 1.0
            popupY = birdY - 30

            // Speed up every 5 points
            if score % 5 = 0
                currentSpeed += 8.0
            ok
        ok

        // Deactivate off-screen
        if pipes[i][1] < -PIPE_W - 10
            pipes[i][4] = 0
        ok
    next

    // Spawn new pipes
    lastX = 0.0
    for i = 1 to len(pipes)
        if pipes[i][4] = 1 and pipes[i][1] > lastX
            lastX = pipes[i][1]
        ok
    next

    if lastX < SCREEN_W
        newX = lastX + PIPE_SPACING
        gapY = GetRandomValue(80, GROUND_Y - diffGaps[difficulty] - 60)
        // Reuse inactive pipe
        found = false
        for i = 1 to len(pipes)
            if pipes[i][4] = 0
                pipes[i] = [newX * 1.0, gapY * 1.0, 0, 1]
                found = true
                exit
            ok
        next
        if !found
            add(pipes, [newX * 1.0, gapY * 1.0, 0, 1])
        ok
    ok

    // Collision detection
    // Ground
    if birdY + BIRD_H / 2 >= GROUND_Y
        birdY = GROUND_Y - BIRD_H / 2
        fb_die()
        return
    ok

    // Ceiling
    if birdY - BIRD_H / 2 <= 0
        birdY = BIRD_H / 2
        birdVel = 0
    ok

    // Pipe collision
    for i = 1 to len(pipes)
        if pipes[i][4] = 0 loop ok
        px = pipes[i][1]
        gapY = pipes[i][2]
        gap = diffGaps[difficulty]

        // Check horizontal overlap
        if BIRD_X + BIRD_RADIUS > px and BIRD_X - BIRD_RADIUS < px + PIPE_W
            // Check if bird is in the gap
            if birdY - BIRD_RADIUS < gapY or birdY + BIRD_RADIUS > gapY + gap
                fb_die()
                return
            ok
        ok
    next

// =============================================================
// Dying State
// =============================================================

func fb_updateDying dt
    birdVel += GRAVITY * dt
    if birdVel > MAX_FALL birdVel = MAX_FALL ok
    birdY += birdVel * dt
    birdAngle += 400 * dt   // spin

    if birdY + BIRD_H / 2 >= GROUND_Y
        birdY = GROUND_Y - BIRD_H / 2
        gameState = STATE_DEAD
        birdVel = 0
    ok

// =============================================================
// Dead State
// =============================================================

func fb_updateDead dt
    if IsKeyPressed(KEY_R) or IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
        fb_resetGame()
    ok

// =============================================================
// Die
// =============================================================

func fb_die
    gameState = STATE_DYING
    birdAlive = false
    birdVel = -250.0    // bounce up
    screenShake = 5.0

    if score > bestScore
        bestScore = score
        newBest = true
    ok

    // Death feathers
    for p = 1 to 8
        fb_spawnParticle(BIRD_X, birdY,
                         GetRandomValue(-150, 150) * 1.0,
                         GetRandomValue(-250, -50) * 1.0,
                         255, 220, 80)
    next

// =============================================================
// Flap Detection
// =============================================================

func fb_isFlap
    if IsKeyPressed(KEY_SPACE) return true ok
    if IsKeyPressed(KEY_UP) return true ok
    if IsKeyPressed(KEY_W) return true ok
    if IsMouseButtonPressed(MOUSE_LEFT_BUTTON) return true ok
    return false

// =============================================================
// Particles
// =============================================================

func fb_spawnFlapParticles
    for p = 1 to 3
        fb_spawnParticle(BIRD_X - 10, birdY + 5,
                         GetRandomValue(-80, -20) * 1.0,
                         GetRandomValue(-30, 30) * 1.0,
                         200, 220, 255)
    next

func fb_spawnParticle px, py, vx, vy, r, g, b
    for i = 1 to MAX_PARTS
        if partActive[i] = 0
            partX[i] = px
            partY[i] = py
            partVX[i] = vx
            partVY[i] = vy
            partLife[i] = 1.0
            partActive[i] = 1
            partR[i] = r
            partG[i] = g
            partB[i] = b
            return
        ok
    next

func fb_updateParticles dt
    for i = 1 to MAX_PARTS
        if partActive[i] = 0 loop ok
        partX[i] += partVX[i] * dt
        partY[i] += partVY[i] * dt
        partVY[i] += 400 * dt    // gravity on particles
        partLife[i] -= dt * 1.5
        if partLife[i] <= 0
            partActive[i] = 0
        ok
    next

// =============================================================
// Draw
// =============================================================

func fb_draw
    // Screen shake offset
    shakeX = 0  shakeY = 0
    if screenShake > 0
        shakeX = GetRandomValue(-3, 3)
        shakeY = GetRandomValue(-3, 3)
    ok

    // Sky
    fb_drawSky(shakeX, shakeY)

    // Stars (night)
    if isNight
        fb_drawStars(shakeX, shakeY)
    ok

    // Clouds
    fb_drawClouds(shakeX, shakeY)

    // Background layers
    fb_drawBG(shakeX, shakeY)

    // Pipes
    fb_drawPipes(shakeX, shakeY)

    // Bird
    fb_drawBird(shakeX, shakeY)

    // Ground
    fb_drawGround(shakeX, shakeY)

    // Particles
    fb_drawParticles(shakeX, shakeY)

    // Score popup
    if popupTimer > 0
        pa = floor(popupTimer * 255)
        if pa > 255 pa = 255 ok
        pTxt = "" + string(popupScore)
        DrawText(pTxt, BIRD_X + 20 + shakeX, floor(popupY) + shakeY, 22, RAYLIBColor(255, 255, 255, pa))
    ok

    // HUD
    fb_drawHUD()

    // State overlays
    if gameState = STATE_MENU
        fb_drawMenu()
    ok

    if gameState = STATE_READY
        fb_drawReady()
    ok

    if gameState = STATE_DEAD
        fb_drawGameOver()
    ok

// =============================================================
// Draw Sky
// =============================================================

func fb_drawSky sx, sy
    if isNight
        // Night gradient
        for i = 0 to 10
            f = i / 10.0
            r = floor(5 + f * 10)
            g = floor(5 + f * 15)
            b = floor(20 + f * 30)
            bh = GROUND_Y / 11
            DrawRectangle(sx, sy + i * bh, SCREEN_W, bh + 1, RAYLIBColor(r, g, b, 255))
        next
    else
        // Day gradient
        for i = 0 to 10
            f = i / 10.0
            r = floor(70 + f * 60)
            g = floor(160 + f * 60)
            b = floor(230 + f * 20)
            if r > 255 r = 255 ok  if g > 255 g = 255 ok  if b > 255 b = 255 ok
            bh = GROUND_Y / 11
            DrawRectangle(sx, sy + i * bh, SCREEN_W, bh + 1, RAYLIBColor(r, g, b, 255))
        next
    ok

// =============================================================
// Draw Stars
// =============================================================

func fb_drawStars sx, sy
    for i = 1 to MAX_STARS
        twinkle = sin(animTime * 3 + starPh[i])
        bright = floor(starBr[i] * (0.5 + twinkle * 0.5))
        if bright < 20 loop ok
        if bright > 255 bright = 255 ok
        DrawCircle(starX[i] + sx, starY[i] + sy, 1, RAYLIBColor(255, 255, 240, bright))
    next

// =============================================================
// Draw Clouds
// =============================================================

func fb_drawClouds sx, sy
    for i = 1 to MAX_CLOUDS
        cx = floor(cloudX2[i]) + sx
        cy = floor(cloudY2[i]) + sy
        cw = floor(cloudW2[i])
        al = 60
        if isNight al = 25 ok
        DrawCircle(cx, cy, cw / 3, RAYLIBColor(255, 255, 255, al))
        DrawCircle(cx + cw / 5, cy - 5, cw / 4, RAYLIBColor(255, 255, 255, al))
        DrawCircle(cx - cw / 5, cy + 3, cw / 3.5, RAYLIBColor(255, 255, 255, al))
    next

// =============================================================
// Draw Background
// =============================================================

func fb_drawBG sx, sy
    // Far mountains
    mCol = RAYLIBColor(80, 120, 80, 150)
    if isNight mCol = RAYLIBColor(20, 35, 30, 180) ok

    for x = -50 to SCREEN_W + 50 step 3
        scrollX = x + floor(bgScroll1) % SCREEN_W
        mh = sin(scrollX * 0.015) * 50 + sin(scrollX * 0.008 + 1) * 30 + 60
        DrawRectangle(x + sx, GROUND_Y - floor(mh) + sy - 40, 4, floor(mh) + 40, mCol)
    next

    // Near buildings
    bCol = RAYLIBColor(60, 80, 60, 180)
    if isNight bCol = RAYLIBColor(15, 25, 25, 200) ok

    for x = -50 to SCREEN_W + 50 step 24
        scrollX = x + floor(bgScroll2) % SCREEN_W
        bh = 30 + (floor(sin(scrollX * 0.05) * 20 + cos(scrollX * 0.03) * 15 + 30))
        DrawRectangle(x + sx, GROUND_Y - bh + sy, 20, bh, bCol)
        // Windows (night)
        if isNight
            for wy = GROUND_Y - bh + 5 to GROUND_Y - 8 step 10
                for wx = x + 3 to x + 15 step 7
                    if GetRandomValue(1, 3) != 1
                        DrawRectangle(wx + sx, wy + sy, 4, 4, RAYLIBColor(255, 230, 100, GetRandomValue(40, 100)))
                    ok
                next
            next
        ok
    next

// =============================================================
// Draw Pipes
// =============================================================

func fb_drawPipes sx, sy
    for i = 1 to len(pipes)
        if pipes[i][4] = 0 loop ok
        px = floor(pipes[i][1]) + sx
        gapY = floor(pipes[i][2])
        gap = diffGaps[difficulty]

        // Pipe colors
        pCol1 = RAYLIBColor(80, 190, 50, 255)       // main
        pCol2 = RAYLIBColor(60, 160, 35, 255)        // dark edge
        pCol3 = RAYLIBColor(110, 220, 80, 255)       // highlight
        capCol = RAYLIBColor(70, 175, 45, 255)

        if isNight
            pCol1 = RAYLIBColor(40, 120, 30, 255)
            pCol2 = RAYLIBColor(30, 100, 20, 255)
            pCol3 = RAYLIBColor(55, 140, 40, 255)
            capCol = RAYLIBColor(35, 110, 25, 255)
        ok

        // Top pipe
        topH = gapY + sy
        DrawRectangle(px, 0 + sy, PIPE_W, topH, pCol1)
        // Highlight stripe
        DrawRectangle(px + 5, 0 + sy, 8, topH, pCol3)
        // Dark edge
        DrawRectangle(px + PIPE_W - 5, 0 + sy, 5, topH, pCol2)
        // Cap
        DrawRectangle(px - 4, topH - 26, PIPE_W + 8, 26, capCol)
        DrawRectangleLines(px - 4, topH - 26, PIPE_W + 8, 26, pCol2)

        // Bottom pipe
        botY = gapY + gap + sy
        botH = GROUND_Y - gapY - gap
        DrawRectangle(px, botY, PIPE_W, botH, pCol1)
        DrawRectangle(px + 5, botY, 8, botH, pCol3)
        DrawRectangle(px + PIPE_W - 5, botY, 5, botH, pCol2)
        // Cap
        DrawRectangle(px - 4, botY, PIPE_W + 8, 26, capCol)
        DrawRectangleLines(px - 4, botY, PIPE_W + 8, 26, pCol2)
    next

// =============================================================
// Draw Bird
// =============================================================

func fb_drawBird sx, sy
    bx = BIRD_X + sx
    by = floor(birdY) + sy

    // Wing positions based on frame
    wingOff = 0
    if birdFrame = 0 wingOff = -4 ok
    if birdFrame = 1 wingOff = 0 ok
    if birdFrame = 2 wingOff = 4 ok

    // Rotation effect: shift body elements
    angleRad = birdAngle * PI / 180.0
    rotShiftY = sin(angleRad) * 4

    // Shadow
    DrawCircle(bx + 2, by + 3, BIRD_RADIUS, RAYLIBColor(0, 0, 0, 40))

    // Body
    DrawCircle(bx, by + floor(rotShiftY * 0.3), BIRD_RADIUS, RAYLIBColor(255, 210, 50, 255))
    DrawCircle(bx, by + floor(rotShiftY * 0.3), BIRD_RADIUS - 2, RAYLIBColor(255, 230, 80, 255))

    // Belly
    DrawCircle(bx - 2, by + 4 + floor(rotShiftY * 0.3), BIRD_RADIUS - 5, RAYLIBColor(240, 220, 180, 230))

    // Wing
    wCol = RAYLIBColor(230, 190, 40, 240)
    DrawCircle(bx - 6, by + wingOff + floor(rotShiftY * 0.5), 9, wCol)

    // Eye
    DrawCircle(bx + 7, by - 4 + floor(rotShiftY * 0.2), 5, WHITE)
    DrawCircle(bx + 9, by - 4 + floor(rotShiftY * 0.2), 3, RAYLIBColor(20, 20, 30, 255))

    // Pupil highlight
    DrawCircle(bx + 10, by - 5 + floor(rotShiftY * 0.2), 1, RAYLIBColor(255, 255, 255, 200))

    // Beak
    beakY = by + 1 + floor(rotShiftY * 0.3)
    DrawTriangle(
        Vector2(bx + 12, beakY - 3),
        Vector2(bx + 12, beakY + 3),
        Vector2(bx + 22, beakY),
        RAYLIBColor(230, 100, 40, 255))

    // Dead X eyes
    if gameState = STATE_DYING or gameState = STATE_DEAD
        ex = bx + 7
        ey = by - 4 + floor(rotShiftY * 0.2)
        DrawLine(ex - 3, ey - 3, ex + 3, ey + 3, RAYLIBColor(20, 20, 30, 255))
        DrawLine(ex - 3, ey + 3, ex + 3, ey - 3, RAYLIBColor(20, 20, 30, 255))
    ok

// =============================================================
// Draw Ground
// =============================================================

func fb_drawGround sx, sy
    gy = GROUND_Y + sy

    // Main ground
    gCol = RAYLIBColor(210, 190, 120, 255)
    if isNight gCol = RAYLIBColor(80, 70, 50, 255) ok
    DrawRectangle(sx, gy, SCREEN_W, GROUND_H, gCol)

    // Top grass strip
    grassCol = RAYLIBColor(100, 200, 60, 255)
    if isNight grassCol = RAYLIBColor(30, 80, 25, 255) ok
    DrawRectangle(sx, gy, SCREEN_W, 12, grassCol)

    // Scrolling dashes on ground
    dCol = RAYLIBColor(190, 170, 100, 200)
    if isNight dCol = RAYLIBColor(60, 55, 40, 200) ok
    for x = -50 to SCREEN_W + 50 step 48
        dx = x - floor(groundScroll) % 48 + sx
        DrawRectangle(dx, gy + 18, 24, 4, dCol)
    next

// =============================================================
// Draw Particles
// =============================================================

func fb_drawParticles sx, sy
    for i = 1 to MAX_PARTS
        if partActive[i] = 0 loop ok
        al = floor(partLife[i] * 255)
        if al > 255 al = 255 ok
        if al < 0 loop ok
        sz = floor(partLife[i] * 5) + 1
        DrawCircle(floor(partX[i]) + sx, floor(partY[i]) + sy, sz, RAYLIBColor(partR[i], partG[i], partB[i], al))
    next

// =============================================================
// HUD
// =============================================================

func fb_drawHUD
    if gameState = STATE_PLAYING or gameState = STATE_DYING
        // Score - large centered at top
        sTxt = "" + string(score)
        sw = MeasureText(sTxt, 52)
        // Shadow
        DrawText(sTxt, (SCREEN_W - sw) / 2 + 2, 42, 52, RAYLIBColor(0, 0, 0, 100))
        // White
        DrawText(sTxt, (SCREEN_W - sw) / 2, 40, 52, WHITE)
    ok

    // Difficulty
    DrawText(diffNames[difficulty], 8, SCREEN_H - 22, 12, RAYLIBColor(255, 255, 255, 60))

    // FPS
    DrawText("" + string(GetFPS()) + " FPS", SCREEN_W - 55, SCREEN_H - 18, 10, RAYLIBColor(255, 255, 255, 50))

// =============================================================
// Menu Screen
// =============================================================

func fb_drawMenu
    // Title
    titleY = 120 + floor(sin(animTime * 2) * 8)
    DrawText("FLAPPY", SCREEN_W / 2 - 95, titleY, 48, RAYLIBColor(255, 230, 50, 255))
    DrawText("BIRD", SCREEN_W / 2 - 52, titleY + 50, 48, WHITE)

    // Subtitle
    DrawText("RingRayLib Edition", SCREEN_W / 2 - 75, titleY + 105, 16, RAYLIBColor(200, 220, 200, 180))

    // Start prompt
    flashA = floor(fabs(sin(animTime * 3)) * 200) + 55
    DrawText("Tap / Space to Start", SCREEN_W / 2 - 90, 440, 18, RAYLIBColor(255, 255, 255, flashA))

    // Difficulty
    DrawText("1:Easy  2:Normal  3:Hard", SCREEN_W / 2 - 95, 490, 14, RAYLIBColor(200, 200, 220, 150))

    // Best score
    if bestScore > 0
        DrawText("Best: " + string(bestScore), SCREEN_W / 2 - 35, 530, 16, RAYLIBColor(255, 215, 0, 200))
    ok

// =============================================================
// Ready Screen
// =============================================================

func fb_drawReady
    flashA = floor(fabs(sin(animTime * 3)) * 200) + 55
    DrawText("GET READY!", SCREEN_W / 2 - 75, 200, 24, RAYLIBColor(255, 255, 255, flashA))

    // Tap icon
    tapY = 260 + floor(sin(animTime * 4) * 5)
    DrawCircle(SCREEN_W / 2, tapY, 20, RAYLIBColor(255, 255, 255, 100))
    DrawCircle(SCREEN_W / 2, tapY, 15, RAYLIBColor(255, 255, 255, 60))
    DrawText("TAP", SCREEN_W / 2 - 15, tapY - 8, 16, WHITE)

// =============================================================
// Game Over Screen
// =============================================================

func fb_drawGameOver
    // Darken
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 120))

    // Panel
    panelW = 260
    panelH = 220
    px = (SCREEN_W - panelW) / 2
    py = 180

    DrawRectangle(px, py, panelW, panelH, RAYLIBColor(220, 200, 140, 245))
    DrawRectangleLines(px, py, panelW, panelH, RAYLIBColor(160, 140, 80, 255))
    DrawRectangle(px + 2, py + 2, panelW - 4, 35, RAYLIBColor(200, 180, 120, 255))

    // Game Over text
    DrawText("GAME OVER", px + 55, py + 8, 24, RAYLIBColor(200, 60, 40, 255))

    // Score
    DrawText("Score", px + 30, py + 55, 16, RAYLIBColor(120, 100, 60, 230))
    scTxt = "" + string(score)
    DrawText(scTxt, px + panelW - 50 - MeasureText(scTxt, 22), py + 50, 22, RAYLIBColor(40, 30, 20, 255))

    // Best
    DrawText("Best", px + 30, py + 90, 16, RAYLIBColor(120, 100, 60, 230))
    bsTxt = "" + string(bestScore)
    DrawText(bsTxt, px + panelW - 50 - MeasureText(bsTxt, 22), py + 85, 22, RAYLIBColor(40, 30, 20, 255))

    // New best indicator
    if newBest
        DrawText("NEW!", px + panelW - 55, py + 85, 14, RAYLIBColor(255, 50, 50, floor(fabs(sin(animTime * 5)) * 200 + 55)))
    ok

    // Medal
    medalX = px + 40
    medalY = py + 125
    DrawCircle(medalX + 25, medalY + 25, 28, RAYLIBColor(0, 0, 0, 80))

    if score >= 40
        // Platinum
        DrawCircle(medalX + 25, medalY + 25, 25, RAYLIBColor(180, 220, 240, 255))
        DrawText("P", medalX + 17, medalY + 14, 24, RAYLIBColor(80, 120, 160, 255))
    but score >= 25
        // Gold
        DrawCircle(medalX + 25, medalY + 25, 25, RAYLIBColor(255, 215, 50, 255))
        DrawText("G", medalX + 16, medalY + 14, 24, RAYLIBColor(180, 140, 20, 255))
    but score >= 15
        // Silver
        DrawCircle(medalX + 25, medalY + 25, 25, RAYLIBColor(200, 200, 210, 255))
        DrawText("S", medalX + 17, medalY + 14, 24, RAYLIBColor(120, 120, 130, 255))
    but score >= 5
        // Bronze
        DrawCircle(medalX + 25, medalY + 25, 25, RAYLIBColor(200, 150, 80, 255))
        DrawText("B", medalX + 17, medalY + 14, 24, RAYLIBColor(140, 90, 40, 255))
    else
        // No medal
        DrawCircle(medalX + 25, medalY + 25, 25, RAYLIBColor(100, 100, 100, 150))
        DrawText("?", medalX + 17, medalY + 14, 24, RAYLIBColor(60, 60, 60, 180))
    ok

    // Medal labels
    DrawText("5=B  15=S  25=G  40=P", px + 90, medalY + 15, 11, RAYLIBColor(100, 80, 50, 160))

    // Restart prompt
    flashA = floor(fabs(sin(animTime * 3)) * 200) + 55
    DrawText("Tap / R to Restart", px + 50, py + panelH - 30, 16, RAYLIBColor(100, 80, 40, flashA))
