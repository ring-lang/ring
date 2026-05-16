/*
**  Pegblaster - RingRayLib
**  ===================================
**  Aim a ball, launch it, and bounce through fields of pegs.
**  Clear all the orange pegs to win the level. Hit blue pegs
**  for bonus points. Land in the moving bucket for an extra
**  ball. Get all 100% bonuses for massive score multipliers!
**
**  Controls:
**    Mouse Move        - Aim
**    Left Click / Space - Launch ball
**    R                 - Restart level
**    N                 - Next level (after clearing)
**    P                 - Pause
**    1-3               - Difficulty (Easy / Normal / Hard)
**    G                 - Toggle gravity strength preview
**    ESC               - Exit
**
**  Features:
**    - Mouse-aimed cannon with trajectory dots
**    - Real circle-vs-circle physics with restitution
**    - Procedural peg layouts (10 levels)
**    - Orange (target) and blue (bonus) pegs
**    - Green "power" peg gives multi-ball burst
**    - Moving bucket at bottom for free-ball catch
**    - Hit streak scoring and combo multipliers
**    - Particle explosions and screen shake
**    - Persistent best score per session
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W = 900
SCREEN_H = 760

PI = 3.14159265
DEG2RAD = PI / 180.0
RAD2DEG = 180.0 / PI

// Physics
GRAVITY      = 1100.0
RESTITUTION  = 0.78        // bounciness of pegs
WALL_REST    = 0.85
DRAG         = 0.998       // velocity dampening per frame
MAX_SPEED    = 1500.0

// Cannon
CANNON_X = SCREEN_W / 2
CANNON_Y = 90
CANNON_LEN = 56

// Ball
BALL_R = 9.0
BALL_LAUNCH_SPEED = 800.0

// Pegs
PEG_R = 12.0
MAX_PEGS = 140
PEG_NORMAL = 1     // blue, bonus
PEG_TARGET = 2     // orange, must clear
PEG_POWER  = 3     // green, gives multiball
PEG_BONUS  = 4     // purple, big score

// Bucket
BUCKET_W = 100
BUCKET_H = 32
BUCKET_Y = SCREEN_H - 40

// Game states
ST_MENU    = 1
ST_AIMING  = 2
ST_FLYING  = 3
ST_CLEARED = 4
ST_FAILED  = 5
ST_PAUSED  = 6

// Difficulty
DIFF_EASY   = 1
DIFF_NORMAL = 2
DIFF_HARD   = 3
pb_diffNames = ["Easy", "Normal", "Hard"]
pb_diffBalls = [12, 10, 7]
pb_diffGravity = [950.0, 1100.0, 1280.0]

MAX_LEVELS = 10

// =============================================================
// State
// =============================================================

gameState = ST_MENU
difficulty = DIFF_NORMAL
animTime = 0.0
screenShake = 0.0
shakeX = 0.0
shakeY = 0.0

level = 1
score = 0
bestScore = 0
ballsLeft = 10
hitStreak = 0
combo = 1
levelComboBonus = 0

// Cannon aim
aimAngle = 90.0       // degrees from horizontal (90 = down)

// Pegs:  each entry = [x, y, type, hit, fadeTimer]
pegs = []

// Active balls: each entry = [x, y, vx, vy, alive]
MAX_BALLS = 8
balls = []

// Bucket
bucketX = SCREEN_W / 2.0
bucketVX = 120.0
bucketCatch = false      // flash when ball caught
bucketFlash = 0.0

// Hit counters per level
orangeTotal = 0
orangeHit = 0

// Particles
MAX_PARTS = 120
partX = list(MAX_PARTS)
partY = list(MAX_PARTS)
partVX = list(MAX_PARTS)
partVY = list(MAX_PARTS)
partLife = list(MAX_PARTS)
partActive = list(MAX_PARTS)
partR = list(MAX_PARTS)
partG = list(MAX_PARTS)
partB = list(MAX_PARTS)
partSize = list(MAX_PARTS)

for i = 1 to MAX_PARTS
    partActive[i] = 0
next

// Score popups: [x, y, value, life, r, g, b]
MAX_POPS = 12
popText = list(MAX_POPS)
popX = list(MAX_POPS)
popY = list(MAX_POPS)
popLife = list(MAX_POPS)
popR = list(MAX_POPS)
popG = list(MAX_POPS)
popB = list(MAX_POPS)
popActive = list(MAX_POPS)
for i = 1 to MAX_POPS popActive[i] = 0 next

// Stars background
MAX_STARS = 70
starX = list(MAX_STARS)
starY = list(MAX_STARS)
starBr = list(MAX_STARS)
starPh = list(MAX_STARS)
for i = 1 to MAX_STARS
    starX[i] = GetRandomValue(0, SCREEN_W)
    starY[i] = GetRandomValue(0, SCREEN_H)
    starBr[i] = GetRandomValue(60, 220)
    starPh[i] = GetRandomValue(0, 628) / 100.0
next

// Trajectory preview
trajX = list(20)
trajY = list(20)
trajN = 0

// =============================================================
// Main
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Pegblaster - RingRayLib")
SetTargetFPS(60)
SetExitKey(0)

pb_resetGame()

while !WindowShouldClose()
    pb_update()
    BeginDrawing()
        pb_draw()
    EndDrawing()
end

CloseWindow()

// =============================================================
// Reset / Level Build
// =============================================================

func pb_resetGame
    level = 1
    score = 0
    ballsLeft = pb_diffBalls[difficulty]
    hitStreak = 0
    combo = 1
    levelComboBonus = 0
    balls = []
    pb_buildLevel(level)
    gameState = ST_MENU

func pb_startGame
    score = 0
    ballsLeft = pb_diffBalls[difficulty]
    level = 1
    pb_buildLevel(level)
    gameState = ST_AIMING

func pb_nextLevel
    level++
    if level > MAX_LEVELS level = 1 ok    // loop back
    ballsLeft = pb_diffBalls[difficulty] + 2   // bonus refill
    pb_buildLevel(level)
    gameState = ST_AIMING

func pb_buildLevel lv
    pegs = []
    orangeHit = 0
    hitStreak = 0
    combo = 1
    levelComboBonus = 0

    // Layout selection by level number (1..MAX_LEVELS)
    switch lv
    on 1
        pb_layoutGrid(7, 6, 130)
    on 2
        pb_layoutDiamond(180)
    on 3
        pb_layoutCircles()
    on 4
        pb_layoutZigzag(250)
    on 5
        pb_layoutHexagon()
    on 6
        pb_layoutSpiral()
    on 7
        pb_layoutWaves()
    on 8
        pb_layoutGrid(9, 8, 220)
    on 9
        pb_layoutChevrons()
    on 10
        pb_layoutBoss()
    other
        pb_layoutGrid(7, 6, 130)
    off

    // Count target pegs
    orangeTotal = 0
    for i = 1 to len(pegs)
        if pegs[i][3] = PEG_TARGET orangeTotal++ ok
    next

    // Add power peg(s) randomly among non-targets
    pb_promoteRandom(PEG_POWER, 1)
    pb_promoteRandom(PEG_BONUS, 2)

// Add a peg
func pb_addPeg x, y, ptype
    if len(pegs) >= MAX_PEGS return ok
    add(pegs, [x * 1.0, y * 1.0, ptype, 0, 0.0])

// Promote N random normal pegs to a special type
func pb_promoteRandom newType, count
    placed = 0
    tries = 0
    while placed < count and tries < 200
        tries++
        i = GetRandomValue(1, len(pegs))
        if pegs[i][3] = PEG_NORMAL
            pegs[i][3] = newType
            placed++
        ok
    end

// =============================================================
// Level Layouts
// =============================================================

func pb_layoutGrid cols, rowsTargets, topY
    spacingX = (SCREEN_W - 160) / (cols - 1)
    spacingY = 50
    for r = 0 to rowsTargets + 3
        for c = 0 to cols - 1
            offset = 0
            if r % 2 = 1 offset = spacingX / 2 ok
            x = 80 + c * spacingX + offset
            y = topY + r * spacingY
            if x > SCREEN_W - 60 loop ok
            ptype = PEG_NORMAL
            // Make middle rows targets
            if r >= 2 and r <= rowsTargets ptype = PEG_TARGET ok
            pb_addPeg(x, y, ptype)
        next
    next

func pb_layoutDiamond topY
    cx = SCREEN_W / 2.0
    rows = 11
    for r = 0 to rows - 1
        rowWidth = r
        if r > rows / 2 rowWidth = rows - 1 - r ok
        for c = -rowWidth to rowWidth
            x = cx + c * 44
            y = topY + r * 42
            ptype = PEG_NORMAL
            if r >= 2 and r <= 8 and (r + c) % 2 = 0 ptype = PEG_TARGET ok
            pb_addPeg(x, y, ptype)
        next
    next

func pb_layoutCircles
    cx = SCREEN_W / 2.0
    // Two concentric rings + scattered pegs
    radii = [70, 130, 200]
    counts = [10, 18, 26]
    centerY = 380
    for ringIdx = 1 to 3
        rad = radii[ringIdx]
        cnt = counts[ringIdx]
        for k = 0 to cnt - 1
            ang = k * 2 * PI / cnt
            x = cx + cos(ang) * rad
            y = centerY + sin(ang) * rad
            if y < 150 or y > SCREEN_H - 100 loop ok
            ptype = PEG_NORMAL
            if ringIdx = 2 ptype = PEG_TARGET ok
            pb_addPeg(x, y, ptype)
        next
    next
    // Center peg
    pb_addPeg(cx, centerY, PEG_TARGET)

func pb_layoutZigzag topY
    rows = 7
    for r = 0 to rows - 1
        zig = 0
        if r % 2 = 0 zig = 60 ok
        for c = 0 to 9
            x = 90 + c * 75 + zig
            y = topY + r * 55
            if x > SCREEN_W - 60 loop ok
            ptype = PEG_NORMAL
            if r >= 1 and r <= 5 and c % 2 = 0 ptype = PEG_TARGET ok
            pb_addPeg(x, y, ptype)
        next
    next

func pb_layoutHexagon
    cx = SCREEN_W / 2.0
    cy = 400
    // 3 nested hexagons
    sizes = [80, 160, 240]
    for s = 1 to 3
        sz = sizes[s]
        steps = 6 * s
        for k = 0 to steps - 1
            ang = k * 2 * PI / steps
            x = cx + cos(ang) * sz
            y = cy + sin(ang) * sz
            if y < 160 or y > SCREEN_H - 100 loop ok
            ptype = PEG_NORMAL
            if s = 2 ptype = PEG_TARGET ok
            pb_addPeg(x, y, ptype)
        next
    next

func pb_layoutSpiral
    cx = SCREEN_W / 2.0
    cy = 410
    pts = 60
    for i = 0 to pts - 1
        t = i / 6.0
        rad = 30 + i * 4
        x = cx + cos(t) * rad
        y = cy + sin(t) * rad
        if y < 150 or y > SCREEN_H - 100 loop ok
        if x < 60 or x > SCREEN_W - 60 loop ok
        ptype = PEG_NORMAL
        if i % 3 = 0 ptype = PEG_TARGET ok
        pb_addPeg(x, y, ptype)
    next

func pb_layoutWaves
    // Sinusoidal rows
    for r = 0 to 5
        baseY = 200 + r * 80
        for c = 0 to 13
            x = 70 + c * 60
            y = baseY + sin(c * 0.7 + r * 0.5) * 28
            if x > SCREEN_W - 60 loop ok
            ptype = PEG_NORMAL
            if r >= 1 and r <= 4 and c % 2 = 1 ptype = PEG_TARGET ok
            pb_addPeg(x, y, ptype)
        next
    next

func pb_layoutChevrons
    // Two V-shapes pointing down
    for chev = 0 to 1
        cx = 240 + chev * 420
        topY = 200
        for arm = 0 to 9
            // Left arm
            pb_addPeg(cx - arm * 28, topY + arm * 30, PEG_TARGET)
            // Right arm
            pb_addPeg(cx + arm * 28, topY + arm * 30, PEG_TARGET)
        next
    next
    // Fill between with normal pegs
    for r = 0 to 4
        for c = 0 to 8
            x = 150 + c * 75
            y = 220 + r * 70
            if x > SCREEN_W - 80 loop ok
            pb_addPeg(x, y, PEG_NORMAL)
        next
    next

func pb_layoutBoss
    // Final level: mix of everything, densely packed
    cx = SCREEN_W / 2.0
    cy = 420
    // Central cluster
    for r = 0 to 4
        for c = -4 to 4
            x = cx + c * 44 + (r % 2) * 22
            y = 280 + r * 46
            ptype = PEG_TARGET
            if (r + c) % 3 = 0 ptype = PEG_NORMAL ok
            pb_addPeg(x, y, ptype)
        next
    next
    // Outer ring of normals
    for k = 0 to 23
        ang = k * 2 * PI / 24
        x = cx + cos(ang) * 280
        y = cy + sin(ang) * 220
        if y < 160 or y > SCREEN_H - 110 loop ok
        if x < 60 or x > SCREEN_W - 60 loop ok
        pb_addPeg(x, y, PEG_NORMAL)
    next

// =============================================================
// Update
// =============================================================

func pb_update
    dt = GetFrameTime()
    if dt > 0.033 dt = 0.033 ok
    animTime += dt

    if IsKeyPressed(KEY_ESCAPE)
        CloseWindow()
        shutdown(0)
    ok

    if IsKeyPressed(KEY_ONE)   difficulty = DIFF_EASY   pb_resetGame() ok
    if IsKeyPressed(KEY_TWO)   difficulty = DIFF_NORMAL pb_resetGame() ok
    if IsKeyPressed(KEY_THREE) difficulty = DIFF_HARD   pb_resetGame() ok

    if IsKeyPressed(KEY_P)
        if gameState = ST_PAUSED
            gameState = ST_AIMING
        but gameState = ST_AIMING or gameState = ST_FLYING
            gameState = ST_PAUSED
        ok
    ok

    // Bucket always moves
    pb_updateBucket(dt)

    // Particles always update
    pb_updateParticles(dt)
    pb_updatePopups(dt)

    // Screen shake decay
    if screenShake > 0
        screenShake -= dt * 30
        if screenShake < 0 screenShake = 0 ok
        shakeX = (GetRandomValue(-100, 100) / 100.0) * screenShake
        shakeY = (GetRandomValue(-100, 100) / 100.0) * screenShake
    else
        shakeX = 0
        shakeY = 0
    ok

    // Peg fade timers (after being hit)
    for i = 1 to len(pegs)
        if pegs[i][4] = 1 and pegs[i][5] > 0
            pegs[i][5] -= dt
        ok
    next

    if gameState = ST_MENU
        if IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
            pb_startGame()
        ok
        return
    ok

    if gameState = ST_PAUSED
        return
    ok

    if gameState = ST_CLEARED
        if IsKeyPressed(KEY_N) or IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
            pb_nextLevel()
        ok
        return
    ok

    if gameState = ST_FAILED
        if IsKeyPressed(KEY_R) or IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
            ballsLeft = pb_diffBalls[difficulty]
            pb_buildLevel(level)
            gameState = ST_AIMING
        ok
        return
    ok

    if gameState = ST_AIMING
        pb_updateAiming(dt)
        return
    ok

    if gameState = ST_FLYING
        pb_updateFlying(dt)
        return
    ok

// =============================================================
// Aiming State
// =============================================================

func pb_updateAiming dt
    if IsKeyPressed(KEY_R)
        pb_buildLevel(level)
        return
    ok

    // Aim at mouse
    mx = GetMouseX()
    my = GetMouseY()
    dx = mx - CANNON_X
    dy = my - CANNON_Y
    // Avoid aiming upward; clamp angle between cannon's natural sweep (downward-ish)
    if dy < 10 dy = 10 ok
    ang = atan2(dy, dx) * RAD2DEG    // 0 = right, 90 = down
    if ang < 15 ang = 15 ok
    if ang > 165 ang = 165 ok
    aimAngle = ang

    // Predict trajectory (simulate a few steps with no peg collisions)
    pb_predictTrajectory()

    // Launch
    if IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
        if ballsLeft > 0
            rad = aimAngle * DEG2RAD
            vx = cos(rad) * BALL_LAUNCH_SPEED
            vy = sin(rad) * BALL_LAUNCH_SPEED
            startX = CANNON_X + cos(rad) * CANNON_LEN
            startY = CANNON_Y + sin(rad) * CANNON_LEN
            balls = [[startX, startY, vx, vy, 1]]
            ballsLeft--
            hitStreak = 0
            combo = 1
            gameState = ST_FLYING
        ok
    ok

// =============================================================
// Trajectory prediction
// =============================================================

func pb_predictTrajectory
    trajN = 0
    rad = aimAngle * DEG2RAD
    px = CANNON_X + cos(rad) * CANNON_LEN
    py = CANNON_Y + sin(rad) * CANNON_LEN
    vx = cos(rad) * BALL_LAUNCH_SPEED
    vy = sin(rad) * BALL_LAUNCH_SPEED
    step = 0.018
    for i = 1 to 14
        // Advance with gravity (no peg collision in prediction)
        for s = 1 to 3
            vy += pb_diffGravity[difficulty] * step / 3.0
            px += vx * step / 3.0
            py += vy * step / 3.0
        next
        if px < 0 or px > SCREEN_W or py > SCREEN_H exit ok
        trajN++
        trajX[trajN] = px
        trajY[trajN] = py
    next

// =============================================================
// Flying State - simulate balls & collisions
// =============================================================

func pb_updateFlying dt
    grav = pb_diffGravity[difficulty]

    // Substep physics for stability
    substeps = 4
    sdt = dt / substeps

    for s = 1 to substeps
        for b = 1 to len(balls)
            if balls[b][5] = 0 loop ok

            // Gravity
            balls[b][4] += grav * sdt

            // Drag
            balls[b][3] *= DRAG
            balls[b][4] *= DRAG

            // Cap speed
            spd = sqrt(balls[b][3] * balls[b][3] + balls[b][4] * balls[b][4])
            if spd > MAX_SPEED
                balls[b][3] = balls[b][3] / spd * MAX_SPEED
                balls[b][4] = balls[b][4] / spd * MAX_SPEED
            ok

            // Move
            balls[b][1] += balls[b][3] * sdt
            balls[b][2] += balls[b][4] * sdt

            // Wall bounces
            if balls[b][1] < BALL_R
                balls[b][1] = BALL_R
                balls[b][3] = -balls[b][3] * WALL_REST
            ok
            if balls[b][1] > SCREEN_W - BALL_R
                balls[b][1] = SCREEN_W - BALL_R
                balls[b][3] = -balls[b][3] * WALL_REST
            ok
            if balls[b][2] < BALL_R
                balls[b][2] = BALL_R
                balls[b][4] = -balls[b][4] * WALL_REST
            ok

            // Peg collisions
            pb_collideWithPegs(b)

            // Bucket check (only when descending past bucket line)
            if balls[b][4] > 0 and balls[b][2] > BUCKET_Y and balls[b][2] < BUCKET_Y + BUCKET_H
                if balls[b][1] > bucketX - BUCKET_W / 2 and balls[b][1] < bucketX + BUCKET_W / 2
                    // Caught!
                    balls[b][5] = 0
                    ballsLeft++
                    bucketCatch = true
                    bucketFlash = 0.6
                    pb_addPopup("FREE BALL!", balls[b][1], BUCKET_Y - 20, 255, 220, 80)
                    score += 250 * combo
                    screenShake = 3
                ok
            ok

            // Off bottom
            if balls[b][2] > SCREEN_H + 30
                balls[b][5] = 0
            ok
        next
    next

    // Cleanup: are any balls still alive?
    alive = 0
    for b = 1 to len(balls)
        if balls[b][5] = 1 alive++ ok
    next

    if alive = 0
        // End of shot. Check level state.
        pb_endOfShot()
    ok

// =============================================================
// Peg collision for one ball
// =============================================================

func pb_collideWithPegs b
    for i = 1 to len(pegs)
        if pegs[i][4] = 1 loop ok        // already hit
        dx = balls[b][1] - pegs[i][1]
        dy = balls[b][2] - pegs[i][2]
        dist2 = dx * dx + dy * dy
        rSum = BALL_R + PEG_R
        if dist2 < rSum * rSum
            // Collision
            dist = sqrt(dist2)
            if dist < 0.001 dist = 0.001 ok
            nx = dx / dist
            ny = dy / dist

            // Reflect velocity along the normal
            vdotn = balls[b][3] * nx + balls[b][4] * ny
            if vdotn < 0
                balls[b][3] -= 2 * vdotn * nx
                balls[b][4] -= 2 * vdotn * ny
                // Apply restitution
                balls[b][3] *= RESTITUTION
                balls[b][4] *= RESTITUTION
            ok

            // Push out of overlap
            push = rSum - dist + 0.5
            balls[b][1] += nx * push
            balls[b][2] += ny * push

            // Register peg hit
            pb_hitPeg(i, balls[b][1], balls[b][2])
        ok
    next

// =============================================================
// Peg hit logic
// =============================================================

func pb_hitPeg i, hx, hy
    pegs[i][4] = 1
    pegs[i][5] = 1.5    // fade out timer

    hitStreak++
    if hitStreak % 8 = 0 and combo < 10
        combo++
    ok

    ptype = pegs[i][3]
    baseScore = 10
    pr = 100  pg = 180  pbl = 255

    switch ptype
    on PEG_NORMAL
        baseScore = 10
        pr = 80  pg = 160  pbl = 255
    on PEG_TARGET
        baseScore = 50
        pr = 255  pg = 140  pbl = 40
        orangeHit++
    on PEG_POWER
        baseScore = 100
        pr = 80  pg = 255  pbl = 100
        // Multi-ball: split current ball into 3
        pb_multiBall(pegs[i][1], pegs[i][2])
        pb_addPopup("MULTI!", pegs[i][1], pegs[i][2] - 20, 80, 255, 100)
        screenShake = 4
    on PEG_BONUS
        baseScore = 500
        pr = 220  pg = 100  pbl = 220
        pb_addPopup("+500", pegs[i][1], pegs[i][2] - 20, 220, 120, 220)
        screenShake = 3
    off

    earned = baseScore * combo
    score += earned

    // Spark particles
    pb_burst(pegs[i][1], pegs[i][2], 8, pr, pg, pbl)

    // Combo popup at high streaks
    if combo > 1 and ptype = PEG_TARGET
        pb_addPopup("x" + string(combo), pegs[i][1] + 12, pegs[i][2] - 10, 255, 255, 100)
    ok

// =============================================================
// Multi-ball
// =============================================================

func pb_multiBall mx, my
    // Find first active ball nearby to clone from
    src = -1
    for b = 1 to len(balls)
        if balls[b][5] = 1
            src = b
            exit
        ok
    next
    if src = -1 return ok

    // Spawn 2 new balls at the peg position with spread velocities
    baseVX = balls[src][3]
    baseVY = balls[src][4]
    spd = sqrt(baseVX * baseVX + baseVY * baseVY)
    if spd < 100 spd = 300 ok

    for k = -1 to 1
        if k = 0 loop ok
        ang = atan2(baseVY, baseVX) + k * 0.6
        nvx = cos(ang) * spd
        nvy = sin(ang) * spd
        if len(balls) < MAX_BALLS
            add(balls, [mx * 1.0, my * 1.0, nvx, nvy, 1])
        ok
    next

// =============================================================
// End of shot - check win/lose
// =============================================================

func pb_endOfShot
    // Did we clear all orange pegs?
    if orangeHit >= orangeTotal
        // Compute bonus
        remainingBalls = ballsLeft
        bonus = remainingBalls * 1000
        score += bonus
        levelComboBonus = bonus
        gameState = ST_CLEARED
        screenShake = 6
        pb_addPopup("LEVEL CLEAR!", SCREEN_W / 2 - 60, SCREEN_H / 2 - 60, 100, 255, 100)
        if score > bestScore bestScore = score ok
        return
    ok

    if ballsLeft <= 0
        gameState = ST_FAILED
        if score > bestScore bestScore = score ok
        return
    ok

    // Otherwise: back to aiming
    balls = []
    gameState = ST_AIMING

// =============================================================
// Bucket movement
// =============================================================

func pb_updateBucket dt
    bucketX += bucketVX * dt
    if bucketX < BUCKET_W / 2 + 10
        bucketX = BUCKET_W / 2 + 10
        bucketVX = -bucketVX
    ok
    if bucketX > SCREEN_W - BUCKET_W / 2 - 10
        bucketX = SCREEN_W - BUCKET_W / 2 - 10
        bucketVX = -bucketVX
    ok
    if bucketFlash > 0
        bucketFlash -= dt
        if bucketFlash <= 0
            bucketCatch = false
            bucketFlash = 0
        ok
    ok

// =============================================================
// Particles
// =============================================================

func pb_burst x, y, n, r, g, b
    for k = 1 to n
        ang = GetRandomValue(0, 628) / 100.0
        spd = GetRandomValue(80, 320) * 1.0
        vx = cos(ang) * spd
        vy = sin(ang) * spd
        pb_spawnPart(x, y, vx, vy, r, g, b)
    next

func pb_spawnPart x, y, vx, vy, r, g, b
    for i = 1 to MAX_PARTS
        if partActive[i] = 0
            partX[i] = x
            partY[i] = y
            partVX[i] = vx
            partVY[i] = vy
            partLife[i] = 0.7 + GetRandomValue(0, 50) / 100.0
            partR[i] = r
            partG[i] = g
            partB[i] = b
            partSize[i] = GetRandomValue(2, 5)
            partActive[i] = 1
            return
        ok
    next

func pb_updateParticles dt
    for i = 1 to MAX_PARTS
        if partActive[i] = 0 loop ok
        partVY[i] += 400 * dt
        partVX[i] *= 0.97
        partX[i] += partVX[i] * dt
        partY[i] += partVY[i] * dt
        partLife[i] -= dt
        if partLife[i] <= 0
            partActive[i] = 0
        ok
    next

// =============================================================
// Popups
// =============================================================

func pb_addPopup txt, x, y, r, g, b
    for i = 1 to MAX_POPS
        if popActive[i] = 0
            popText[i] = txt
            popX[i] = x
            popY[i] = y
            popLife[i] = 1.0
            popR[i] = r
            popG[i] = g
            popB[i] = b
            popActive[i] = 1
            return
        ok
    next

func pb_updatePopups dt
    for i = 1 to MAX_POPS
        if popActive[i] = 0 loop ok
        popY[i] -= 30 * dt
        popLife[i] -= dt
        if popLife[i] <= 0 popActive[i] = 0 ok
    next

// =============================================================
// Drawing
// =============================================================

func pb_draw
    sx = floor(shakeX)
    sy = floor(shakeY)

    // Background
    ClearBackground(RAYLIBColor(8, 8, 28, 255))
    pb_drawStars(sx, sy)
    pb_drawNebula(sx, sy)

    // Bottom danger zone hint
    DrawRectangle(sx, SCREEN_H - 10 + sy, SCREEN_W, 10, RAYLIBColor(200, 30, 30, 70))

    // Pegs
    pb_drawPegs(sx, sy)

    // Bucket
    pb_drawBucket(sx, sy)

    // Balls
    pb_drawBalls(sx, sy)

    // Trajectory dots
    if gameState = ST_AIMING
        pb_drawTrajectory(sx, sy)
    ok

    // Cannon
    pb_drawCannon(sx, sy)

    // Particles
    pb_drawParticles(sx, sy)

    // Popups
    pb_drawPopups(sx, sy)

    // HUD on top of everything
    pb_drawHUD()

    // Overlays for various states
    if gameState = ST_MENU
        pb_drawMenu()
    but gameState = ST_PAUSED
        pb_drawPause()
    but gameState = ST_CLEARED
        pb_drawCleared()
    but gameState = ST_FAILED
        pb_drawFailed()
    ok

// =============================================================
// Background
// =============================================================

func pb_drawStars sx, sy
    for i = 1 to MAX_STARS
        bri = starBr[i] + floor(sin(animTime * 2 + starPh[i]) * 40)
        if bri < 0 bri = 0 ok
        if bri > 255 bri = 255 ok
        DrawCircle(starX[i] + sx, starY[i] + sy, 1, RAYLIBColor(bri, bri, bri, 200))
    next

func pb_drawNebula sx, sy
    // Soft glowing patches
    DrawCircle(150 + sx, 600 + sy, 220, RAYLIBColor(80, 30, 120, 18))
    DrawCircle(750 + sx, 200 + sy, 180, RAYLIBColor(30, 100, 150, 22))
    DrawCircle(450 + sx, 380 + sy, 260, RAYLIBColor(60, 20, 90, 12))

// =============================================================
// Pegs
// =============================================================

func pb_drawPegs sx, sy
    for i = 1 to len(pegs)
        px = pegs[i][1] + sx
        py = pegs[i][2] + sy
        ptype = pegs[i][3]
        hit = pegs[i][4]
        fade = pegs[i][5]

        // Skip fully faded out pegs
        if hit = 1 and fade <= 0 loop ok

        r = 80  g = 160  b = 255
        switch ptype
        on PEG_NORMAL
            r = 80   g = 160  b = 255
        on PEG_TARGET
            r = 255  g = 140  b = 40
        on PEG_POWER
            r = 80   g = 255  b = 120
        on PEG_BONUS
            r = 220  g = 100  b = 220
        off

        if hit = 1
            // Fading
            al = floor((fade / 1.5) * 255)
            if al < 0 al = 0 ok
            // Expanding ring
            ringR = PEG_R + (1.5 - fade) * 18
            ringA = floor((fade / 1.5) * 140)
            DrawCircleLines(px, py, ringR, RAYLIBColor(r, g, b, ringA))
            DrawCircle(px, py, PEG_R * (fade / 1.5), RAYLIBColor(r, g, b, al))
        else
            // Halo glow for targets and special pegs
            if ptype = PEG_TARGET
                glow = floor(fabs(sin(animTime * 3 + py * 0.01)) * 100) + 30
                DrawCircle(px, py, PEG_R + 5, RAYLIBColor(r, g, b, glow))
            but ptype = PEG_POWER
                glow = floor(fabs(sin(animTime * 5 + px * 0.02)) * 140) + 40
                DrawCircle(px, py, PEG_R + 7, RAYLIBColor(r, g, b, glow))
            but ptype = PEG_BONUS
                glow = floor(fabs(sin(animTime * 4)) * 120) + 40
                DrawCircle(px, py, PEG_R + 6, RAYLIBColor(r, g, b, glow))
            ok

            // Body shadow
            DrawCircle(px + 1, py + 2, PEG_R, RAYLIBColor(0, 0, 0, 80))
            // Main body
            DrawCircle(px, py, PEG_R, RAYLIBColor(r, g, b, 255))
            // Inner brightness
            DrawCircle(px - 3, py - 3, PEG_R - 4, RAYLIBColor(255, 255, 255, 90))
            // Outline
            DrawCircleLines(px, py, PEG_R, RAYLIBColor(0, 0, 0, 200))
        ok
    next

// =============================================================
// Balls
// =============================================================

func pb_drawBalls sx, sy
    for b = 1 to len(balls)
        if balls[b][5] = 0 loop ok
        bx = balls[b][1] + sx
        by = balls[b][2] + sy
        // Motion trail
        spd = sqrt(balls[b][3] * balls[b][3] + balls[b][4] * balls[b][4])
        trailLen = spd / 80
        if trailLen > 6 trailLen = 6 ok
        for t = 1 to trailLen
            tx = bx - balls[b][3] * t * 0.005
            ty = by - balls[b][4] * t * 0.005
            al = 80 - t * 12
            DrawCircle(tx, ty, BALL_R - t, RAYLIBColor(255, 240, 200, al))
        next
        // Shadow
        DrawCircle(bx + 1, by + 2, BALL_R, RAYLIBColor(0, 0, 0, 100))
        // Body
        DrawCircle(bx, by, BALL_R, RAYLIBColor(255, 230, 140, 255))
        // Highlight
        DrawCircle(bx - 2, by - 3, BALL_R - 4, RAYLIBColor(255, 255, 220, 220))
        // Outline
        DrawCircleLines(bx, by, BALL_R, RAYLIBColor(140, 90, 30, 220))
    next

// =============================================================
// Cannon
// =============================================================

func pb_drawCannon sx, sy
    cx = CANNON_X + sx
    cy = CANNON_Y + sy

    // Base
    DrawRectangle(cx - 40, cy - 20, 80, 30, RAYLIBColor(60, 60, 80, 255))
    DrawRectangleLines(cx - 40, cy - 20, 80, 30, RAYLIBColor(120, 120, 160, 255))
    DrawCircle(cx, cy, 26, RAYLIBColor(80, 80, 110, 255))
    DrawCircleLines(cx, cy, 26, RAYLIBColor(140, 140, 180, 255))

    // Barrel
    rad = aimAngle * DEG2RAD
    endX = cx + cos(rad) * CANNON_LEN
    endY = cy + sin(rad) * CANNON_LEN

    // Perpendicular for thickness
    perpX = -sin(rad) * 8
    perpY = cos(rad) * 8

    DrawTriangle(
        Vector2(cx + perpX, cy + perpY),
        Vector2(cx - perpX, cy - perpY),
        Vector2(endX - perpX, endY - perpY),
        RAYLIBColor(140, 140, 170, 255))
    DrawTriangle(
        Vector2(cx + perpX, cy + perpY),
        Vector2(endX - perpX, endY - perpY),
        Vector2(endX + perpX, endY + perpY),
        RAYLIBColor(140, 140, 170, 255))

    // Barrel rim
    DrawCircle(endX, endY, 9, RAYLIBColor(40, 40, 60, 255))
    DrawCircle(endX, endY, 6, RAYLIBColor(20, 20, 30, 255))

    // Center cap
    DrawCircle(cx, cy, 8, RAYLIBColor(180, 180, 220, 255))

// =============================================================
// Trajectory dots
// =============================================================

func pb_drawTrajectory sx, sy
    for i = 1 to trajN
        al = 200 - i * 12
        if al < 30 al = 30 ok
        DrawCircle(trajX[i] + sx, trajY[i] + sy, 3, RAYLIBColor(255, 255, 255, al))
    next

// =============================================================
// Bucket
// =============================================================

func pb_drawBucket sx, sy
    bx = bucketX - BUCKET_W / 2 + sx
    by = BUCKET_Y + sy

    bodyCol = RAYLIBColor(180, 120, 60, 255)
    rimCol  = RAYLIBColor(220, 160, 90, 255)

    if bucketCatch
        bri = floor(bucketFlash / 0.6 * 255)
        bodyCol = RAYLIBColor(255, 220, bri, 255)
        rimCol = RAYLIBColor(255, 240, 150, 255)
    ok

    // Slight perspective: trapezoid shape
    DrawTriangle(
        Vector2(bx, by),
        Vector2(bx + 10, by + BUCKET_H),
        Vector2(bx + BUCKET_W - 10, by + BUCKET_H),
        bodyCol)
    DrawTriangle(
        Vector2(bx, by),
        Vector2(bx + BUCKET_W - 10, by + BUCKET_H),
        Vector2(bx + BUCKET_W, by),
        bodyCol)

    // Rim
    DrawRectangle(bx - 4, by - 4, BUCKET_W + 8, 6, rimCol)
    DrawRectangleLines(bx - 4, by - 4, BUCKET_W + 8, 6, RAYLIBColor(120, 80, 30, 255))

    // Inner darkness
    DrawTriangle(
        Vector2(bx + 6, by + 2),
        Vector2(bx + 14, by + BUCKET_H - 2),
        Vector2(bx + BUCKET_W - 14, by + BUCKET_H - 2),
        RAYLIBColor(60, 40, 20, 200))
    DrawTriangle(
        Vector2(bx + 6, by + 2),
        Vector2(bx + BUCKET_W - 14, by + BUCKET_H - 2),
        Vector2(bx + BUCKET_W - 6, by + 2),
        RAYLIBColor(60, 40, 20, 200))

    // "FREE BALL" label
    DrawText("FREE BALL", bx + 14, by + 9, 12, RAYLIBColor(255, 240, 200, 220))

// =============================================================
// Particles
// =============================================================

func pb_drawParticles sx, sy
    for i = 1 to MAX_PARTS
        if partActive[i] = 0 loop ok
        al = floor(partLife[i] * 200)
        if al > 255 al = 255 ok
        if al < 0 loop ok
        DrawCircle(partX[i] + sx, partY[i] + sy, partSize[i], RAYLIBColor(partR[i], partG[i], partB[i], al))
    next

// =============================================================
// Popups
// =============================================================

func pb_drawPopups sx, sy
    for i = 1 to MAX_POPS
        if popActive[i] = 0 loop ok
        al = floor(popLife[i] * 255)
        if al > 255 al = 255 ok
        if al < 0 loop ok
        // Shadow
        DrawText(popText[i], floor(popX[i]) + 2 + sx, floor(popY[i]) + 2 + sy, 22, RAYLIBColor(0, 0, 0, al / 2))
        DrawText(popText[i], floor(popX[i]) + sx, floor(popY[i]) + sy, 22, RAYLIBColor(popR[i], popG[i], popB[i], al))
    next

// =============================================================
// HUD
// =============================================================

func pb_drawHUD
    // Top status bar
    DrawRectangle(0, 0, SCREEN_W, 36, RAYLIBColor(0, 0, 0, 180))

    DrawText("PEGBLASTER", 10, 8, 22, RAYLIBColor(255, 200, 80, 255))

    // Score
    DrawText("Score:", 230, 12, 16, RAYLIBColor(200, 200, 220, 200))
    DrawText(string(score), 290, 10, 20, WHITE)

    // Best
    DrawText("Best:", 430, 12, 16, RAYLIBColor(200, 200, 220, 200))
    DrawText(string(bestScore), 478, 10, 20, RAYLIBColor(255, 230, 100, 255))

    // Level
    DrawText("Level:", 580, 12, 16, RAYLIBColor(200, 200, 220, 200))
    DrawText(string(level) + "/" + string(MAX_LEVELS), 638, 10, 20, RAYLIBColor(140, 220, 255, 255))

    // Balls
    DrawText("Balls:", 720, 12, 16, RAYLIBColor(200, 200, 220, 200))
    DrawText(string(ballsLeft), 770, 10, 20, RAYLIBColor(255, 240, 140, 255))

    // Combo (right side)
    if combo > 1
        cmText = "COMBO x" + string(combo)
        cmW = MeasureText(cmText, 18)
        DrawText(cmText, SCREEN_W - cmW - 12, 12, 18, RAYLIBColor(255, 220, 80, 255))
    ok

    // Target progress (bottom of HUD bar)
    DrawText("Orange: " + string(orangeHit) + "/" + string(orangeTotal),
             10, SCREEN_H - 22, 14, RAYLIBColor(255, 160, 60, 220))

    DrawText(pb_diffNames[difficulty], SCREEN_W - 70, SCREEN_H - 22, 12, RAYLIBColor(180, 180, 200, 160))

    DrawText(string(GetFPS()) + " FPS", SCREEN_W - 70, SCREEN_H - 38, 10, RAYLIBColor(180, 180, 200, 100))

// =============================================================
// Menu
// =============================================================

func pb_drawMenu
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 160))

    titleY = 140 + floor(sin(animTime * 2) * 6)
    DrawText("PEGBLASTER", SCREEN_W / 2 - 150, titleY, 56, RAYLIBColor(255, 200, 80, 255))
    DrawText("PEGBLASTER", SCREEN_W / 2 - 150 + 3, titleY + 3, 56, RAYLIBColor(120, 60, 0, 120))

    DrawText("A RingRayLib bouncing-peg adventure", SCREEN_W / 2 - 175, titleY + 70, 16, RAYLIBColor(220, 220, 240, 180))

    // Instructions panel
    panelX = SCREEN_W / 2 - 230
    panelY = 290
    DrawRectangle(panelX, panelY, 460, 240, RAYLIBColor(20, 20, 50, 220))
    DrawRectangleLines(panelX, panelY, 460, 240, RAYLIBColor(120, 120, 200, 255))

    DrawText("HOW TO PLAY", panelX + 20, panelY + 15, 22, RAYLIBColor(255, 200, 80, 255))

    DrawText("Aim with mouse, click to fire", panelX + 30, panelY + 60, 16, WHITE)
    DrawText("Clear all ORANGE pegs to advance", panelX + 30, panelY + 85, 16, RAYLIBColor(255, 160, 60, 255))
    DrawText("BLUE pegs give bonus points", panelX + 30, panelY + 110, 16, RAYLIBColor(120, 180, 255, 255))
    DrawText("GREEN pegs = multi-ball burst", panelX + 30, panelY + 135, 16, RAYLIBColor(120, 255, 140, 255))
    DrawText("PURPLE pegs = +500 jackpot", panelX + 30, panelY + 160, 16, RAYLIBColor(220, 130, 220, 255))
    DrawText("Catch the bucket = free ball!", panelX + 30, panelY + 185, 16, RAYLIBColor(255, 200, 100, 255))

    flashA = floor(fabs(sin(animTime * 3)) * 200) + 55
    DrawText("Click or Space to start", SCREEN_W / 2 - 110, 570, 20, RAYLIBColor(255, 255, 255, flashA))

    DrawText("1=Easy  2=Normal  3=Hard      Current: " + pb_diffNames[difficulty],
             SCREEN_W / 2 - 180, 620, 14, RAYLIBColor(200, 200, 220, 180))

    if bestScore > 0
        DrawText("Session Best: " + string(bestScore), SCREEN_W / 2 - 80, 660, 16, RAYLIBColor(255, 215, 80, 230))
    ok

// =============================================================
// Pause / Cleared / Failed
// =============================================================

func pb_drawPause
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 150))
    txt = "PAUSED"
    tw = MeasureText(txt, 60)
    DrawText(txt, (SCREEN_W - tw) / 2, SCREEN_H / 2 - 40, 60, WHITE)
    DrawText("Press P to resume", SCREEN_W / 2 - 80, SCREEN_H / 2 + 30, 18, RAYLIBColor(220, 220, 220, 200))

func pb_drawCleared
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 170))

    bobY = floor(sin(animTime * 3) * 6)

    DrawText("LEVEL CLEAR!", SCREEN_W / 2 - 160, 220 + bobY, 48, RAYLIBColor(120, 255, 140, 255))

    DrawText("Level " + string(level) + " complete!", SCREEN_W / 2 - 90, 290, 22, WHITE)
    DrawText("Balls remaining bonus: +" + string(levelComboBonus), SCREEN_W / 2 - 130, 330, 18, RAYLIBColor(255, 220, 120, 255))
    DrawText("Total Score: " + string(score), SCREEN_W / 2 - 90, 365, 20, RAYLIBColor(255, 200, 80, 255))

    if level >= MAX_LEVELS
        DrawText("LOOPING BACK TO LEVEL 1", SCREEN_W / 2 - 130, 410, 16, RAYLIBColor(220, 180, 255, 220))
    ok

    flashA = floor(fabs(sin(animTime * 3)) * 200) + 55
    DrawText("Click / Space / N for next level", SCREEN_W / 2 - 135, 460, 18, RAYLIBColor(255, 255, 255, flashA))

func pb_drawFailed
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(30, 0, 0, 170))

    DrawText("OUT OF BALLS", SCREEN_W / 2 - 160, 220, 48, RAYLIBColor(255, 100, 80, 255))

    DrawText("You hit " + string(orangeHit) + " / " + string(orangeTotal) + " orange pegs",
             SCREEN_W / 2 - 130, 290, 20, WHITE)
    DrawText("Final Score: " + string(score), SCREEN_W / 2 - 80, 325, 20, RAYLIBColor(255, 200, 80, 255))

    if score >= bestScore and score > 0
        DrawText("NEW BEST!", SCREEN_W / 2 - 60, 365, 22, RAYLIBColor(255, 215, 80, 255))
    ok

    flashA = floor(fabs(sin(animTime * 3)) * 200) + 55
    DrawText("Click / Space / R to retry this level", SCREEN_W / 2 - 155, 420, 18, RAYLIBColor(255, 255, 255, flashA))
