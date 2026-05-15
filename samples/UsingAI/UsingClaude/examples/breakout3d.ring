/*
**  3D Breakout / Brick Breaker - Using RingRayLib
**  =================================================
**  Bounce the ball off your paddle to smash the bricks!
**  Collect falling power-up gems for special abilities.
**
**  Controls:
**    Left / Right  or  A / D   -  Move paddle
**    SPACE                     -  Launch ball / Confirm
**    P                         -  Pause / Unpause
**    C                         -  Cycle camera angle
**    R                         -  Restart game
**    ESC                       -  Exit
**
**  Brick Types:
**    Green   (1 hit)   - Standard brick
**    Yellow  (2 hits)  - Tougher brick
**    Orange  (3 hits)  - Strong brick
**    Red     (4 hits)  - Very strong brick
**    Silver  (5 hits)  - Armored brick
**    Gold    (indestructible) - Cannot be broken
**
**  Power-Ups (falling gems):
**    Green   - Wide Paddle (8 seconds)
**    Blue    - Multi-Ball (splits into 3)
**    Red     - Fire Ball (pierces bricks, 6 seconds)
**    Purple  - Extra Life (+1)
**
**  Features:
**    - 8 unique brick layouts
**    - Ball speed increases over time
**    - Combo multiplier for consecutive hits
**    - Particle effects on brick break
**    - 3 camera angles
**    - 3D rendered arena with walls
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W    = 1024
SCREEN_H    = 768

// Arena dimensions (world units)
ARENA_W     = 18.0
ARENA_D     = 22.0
ARENA_LEFT  = -ARENA_W / 2
ARENA_RIGHT = ARENA_W / 2
ARENA_NEAR  = 0.0
ARENA_FAR   = ARENA_D
WALL_H      = 1.5

// Paddle
PAD_W       = 3.2
PAD_H       = 0.4
PAD_D       = 0.8
PAD_Z       = 1.5
PAD_SPEED   = 18.0

// Ball
BALL_RAD    = 0.3
BALL_SPD    = 12.0
BALL_MAX    = 22.0

// Bricks
BRICK_COLS  = 10
BRICK_ROWS  = 8
BRICK_W     = 1.55
BRICK_H     = 0.6
BRICK_D     = 0.75
BRICK_GAP   = 0.12
BRICK_Z0    = 12.0

// Power-up types
PW_NONE     = 0
PW_WIDE     = 1
PW_MULTI    = 2
PW_FIRE     = 3
PW_LIFE     = 4

// Game states
ST_TITLE    = 1
ST_PLAY     = 2
ST_LAUNCH   = 3
ST_PAUSE    = 4
ST_CLEAR    = 5
ST_DEAD     = 6
ST_GAMEOVER = 7
ST_WIN      = 8

// Camera
CAM_BEHIND  = 1
CAM_HIGH    = 2
CAM_SIDE    = 3
CAM_MODES   = 3

// =============================================================
// Global Variables
// =============================================================

// Paddle
padX        = 0.0
padW        = PAD_W
padWideT    = 0.0

// Balls: list of [x, y, z, vx, vy, vz, alive, fireball]
balls       = []

// Bricks: list of [row, col, hp, maxhp, alive, x, y, z, btype]
bricks      = []

// Power-ups: list of [x, y, z, ptype, alive]
powerups    = []

// Particles: list of [x, y, z, vx, vy, vz, life, r, g, b]
partList    = []

gameState   = ST_TITLE
animTime    = 0.0
camMode     = CAM_BEHIND

lives       = 3
score       = 0
combo       = 0
level       = 1
maxLevel    = 8
ballSpeed   = BALL_SPD
fireTimer   = 0.0

// Camera smoothing
cpX = 0.0  cpY = 0.0  cpZ = 0.0
ctX = 0.0  ctY = 0.0  ctZ = 0.0

// Level cleared timer
clearTimer  = 0.0

// =============================================================
// Level Layouts (inline before functions)
// Each level: list of strings, '#' = brick
// Digits 1-5 for hit counts, 'G' for gold (indestructible)
// '.' = empty
// =============================================================

levelData = list(maxLevel)

levelData[1] = [
    "..........",
    "..111111..",
    ".11111111.",
    ".11222211.",
    ".11222211.",
    ".11111111.",
    "..111111..",
    ".........."
]

levelData[2] = [
    "1.1.1.1.1.",
    ".2.2.2.2.2",
    "1.1.1.1.1.",
    ".2.2.2.2.2",
    "1.1.1.1.1.",
    ".2.2.2.2.2",
    "1.1.1.1.1.",
    ".2.2.2.2.2"
]

levelData[3] = [
    "1111111111",
    "2222222222",
    "3333333333",
    "..........",
    "..........",
    "3333333333",
    "2222222222",
    "1111111111"
]

levelData[4] = [
    "G1111111G.",
    "12222222..",
    "1233333...",
    "1234444...",
    "...44432..",
    "...3333321",
    "..22222221",
    ".G1111111G"
]

levelData[5] = [
    "...1221...",
    "..123321..",
    ".12344321.",
    "1234554321",
    "1234554321",
    ".12344321.",
    "..123321..",
    "...1221..."
]

levelData[6] = [
    "G.G.G.G.G.",
    "1111111111",
    "2222222222",
    "G.G.G.G.G.",
    ".G.G.G.G.G",
    "3333333333",
    "4444444444",
    ".G.G.G.G.G"
]

levelData[7] = [
    "5544332211",
    "5544332211",
    "..........",
    "..GGGGGG..",
    "..GGGGGG..",
    "..........",
    "1122334455",
    "1122334455"
]

levelData[8] = [
    "G111111G..",
    "5G1111G5..",
    "55G11G55..",
    "555GG555..",
    "..555GG555",
    "..55G11G55",
    "..5G1111G5",
    "..G111111G"
]

// =============================================================
// Main Program
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Ring 3D Breakout - RingRayLib")
toggleFullScreen()
SetTargetFPS(60)

camera = Camera3D(
    0, 20, -5,
    0,  0, 14,
    0,  1,  0,
    50,
    CAMERA_PERSPECTIVE
)

cpX = 0.0   cpY = 24.0  cpZ = -8.0
ctX = 0.0   ctY = 0.0   ctZ = 12.0

// =============================================================
// Main Game Loop
// =============================================================

while !WindowShouldClose()

    dt = GetFrameTime()
    if dt > 0.05 dt = 0.05 ok
    animTime += dt

    if IsKeyPressed(KEY_R) br_fullReset() ok
    if IsKeyPressed(KEY_C)
        camMode += 1
        if camMode > CAM_MODES camMode = CAM_BEHIND ok
    ok

    stateHandled = false

    if gameState = ST_TITLE and !stateHandled
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            br_fullReset()
            gameState = ST_LAUNCH
            stateHandled = true
        ok
    ok

    if gameState = ST_LAUNCH and !stateHandled
        if IsKeyPressed(KEY_P)
            gameState = ST_PAUSE
            stateHandled = true
        else
            br_movePaddle(dt)
            // Ball sits on paddle
            if len(balls) > 0
                balls[1][1] = padX
                balls[1][3] = PAD_Z + PAD_D / 2 + BALL_RAD + 0.05
                balls[1][2] = PAD_H + BALL_RAD
            ok
            if IsKeyPressed(KEY_SPACE)
                if len(balls) > 0
                    balls[1][4] = ballSpeed * 0.3
                    balls[1][5] = 0.0
                    balls[1][6] = ballSpeed * 0.95
                ok
                gameState = ST_PLAY
                stateHandled = true
            ok
            br_updateParts(dt)
        ok
    ok

    if gameState = ST_PLAY and !stateHandled
        if IsKeyPressed(KEY_P)
            gameState = ST_PAUSE
            stateHandled = true
        else
            br_movePaddle(dt)
            br_updateBalls(dt)
            br_updatePowerups(dt)
            br_updateParts(dt)
            br_checkClear()
        ok
    ok

    if gameState = ST_PAUSE and !stateHandled
        if IsKeyPressed(KEY_P) or IsKeyPressed(KEY_SPACE)
            if clearTimer > 0
                gameState = ST_CLEAR
            else
                gameState = ST_PLAY
            ok
            stateHandled = true
        ok
    ok

    if gameState = ST_CLEAR and !stateHandled
        clearTimer -= dt
        br_updateParts(dt)
        if clearTimer <= 0
            level += 1
            if level > maxLevel
                gameState = ST_WIN
            else
                br_loadLevel()
                gameState = ST_LAUNCH
            ok
            stateHandled = true
        ok
    ok

    if gameState = ST_DEAD and !stateHandled
        br_updateParts(dt)
        clearTimer -= dt
        if clearTimer <= 0
            lives -= 1
            if lives <= 0
                gameState = ST_GAMEOVER
            else
                br_spawnBall()
                gameState = ST_LAUNCH
            ok
            stateHandled = true
        ok
    ok

    if gameState = ST_GAMEOVER and !stateHandled
        br_updateParts(dt)
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            br_fullReset()
            stateHandled = true
        ok
    ok

    if gameState = ST_WIN and !stateHandled
        br_updateParts(dt)
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            br_fullReset()
            stateHandled = true
        ok
    ok

    br_moveCamera()

    BeginDrawing()
        ClearBackground(RAYLIBColor(8, 8, 18, 255))

        if gameState = ST_TITLE
            br_drawTitle()
        else
            BeginMode3D(camera)
                br_drawArena()
                br_drawBricks()
                br_drawPaddle()
                br_drawBalls()
                br_drawPowerups3D()
                br_drawParts3D()
            EndMode3D()

            br_drawHUD()

            if gameState = ST_PAUSE    br_drawPause()    ok
            if gameState = ST_CLEAR    br_drawClear()    ok
            if gameState = ST_DEAD     br_drawDead()     ok
            if gameState = ST_GAMEOVER br_drawGameOver() ok
            if gameState = ST_WIN      br_drawWinScr()   ok
            if gameState = ST_LAUNCH   br_drawLaunch()   ok
        ok

        DrawFPS(10, 10)
    EndDrawing()

end

CloseWindow()

// =============================================================
// ALL FUNCTIONS BELOW
// =============================================================

// =============================================================
// Reset / Load
// =============================================================

func br_fullReset
    lives     = 3
    score     = 0
    combo     = 0
    level     = 1
    ballSpeed = BALL_SPD
    padX      = 0.0
    padW      = PAD_W
    padWideT  = 0.0
    fireTimer = 0.0
    powerups  = []
    partList  = []
    br_loadLevel()
    gameState = ST_LAUNCH

func br_loadLevel
    bricks   = []
    powerups = []
    partList = []
    balls    = []
    padX     = 0.0
    padW     = PAD_W
    padWideT = 0.0
    fireTimer = 0.0
    combo    = 0

    // Speed increases per level
    ballSpeed = BALL_SPD + (level - 1) * 0.8
    if ballSpeed > BALL_MAX ballSpeed = BALL_MAX ok

    // Parse level layout
    if level >= 1 and level <= maxLevel
        layout = levelData[level]
        for r = 1 to BRICK_ROWS
            row = layout[r]
            for c = 1 to BRICK_COLS
                ch = "."
                if c <= len(row) ch = substr(row, c, 1) ok
                if ch != "."
                    hp = 1
                    btype = 1
                    if ch = "2" hp = 2  btype = 2 ok
                    if ch = "3" hp = 3  btype = 3 ok
                    if ch = "4" hp = 4  btype = 4 ok
                    if ch = "5" hp = 5  btype = 5 ok
                    if ch = "G" hp = 99 btype = 6 ok
                    bx = ARENA_LEFT + (c - 0.5) * (BRICK_W + BRICK_GAP) + BRICK_GAP
                    by = BRICK_H / 2
                    bz = BRICK_Z0 + (BRICK_ROWS - r) * (BRICK_D + BRICK_GAP)
                    add(bricks, [r, c, hp, hp, true, bx, by, bz, btype])
                ok
            next
        next
    ok

    br_spawnBall()

func br_spawnBall
    bx = padX
    by = PAD_H + BALL_RAD
    bz = PAD_Z + PAD_D / 2 + BALL_RAD + 0.05
    // [x, y, z, vx, vy, vz, alive, fireball]
    balls = [[bx, by, bz, 0.0, 0.0, 0.0, true, false]]

// =============================================================
// Paddle Movement
// =============================================================

func br_movePaddle dt
    spd = PAD_SPEED
    // Camera looks from -Z toward +Z; positive X is screen-LEFT
    if IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_A)
        padX += spd * dt
    ok
    if IsKeyDown(KEY_RIGHT) or IsKeyDown(KEY_D)
        padX -= spd * dt
    ok
    halfW = padW / 2
    if padX - halfW < ARENA_LEFT  padX = ARENA_LEFT + halfW  ok
    if padX + halfW > ARENA_RIGHT padX = ARENA_RIGHT - halfW ok

    // Wide paddle timer
    if padWideT > 0
        padWideT -= dt
        padW = PAD_W * 1.6
        if padWideT <= 0
            padW = PAD_W
            padWideT = 0
        ok
    ok

    // Fire ball timer
    if fireTimer > 0
        fireTimer -= dt
        if fireTimer <= 0
            fireTimer = 0
            bcnt2 = len(balls)
            for i = 1 to bcnt2
                balls[i][8] = false
            next
        ok
    ok

// =============================================================
// Ball Update
// =============================================================

func br_updateBalls dt
    anyAlive = false
    ballCnt = len(balls)
    for bi = 1 to ballCnt
        if !balls[bi][7] loop ok
        anyAlive = true

        bx = balls[bi][1]
        by = balls[bi][2]
        bz = balls[bi][3]
        vx = balls[bi][4]
        vy = balls[bi][5]
        vz = balls[bi][6]

        // Move
        bx += vx * dt
        by += vy * dt
        bz += vz * dt

        // Wall bounces (left/right)
        if bx - BALL_RAD < ARENA_LEFT
            bx = ARENA_LEFT + BALL_RAD
            vx = fabs(vx)
        ok
        if bx + BALL_RAD > ARENA_RIGHT
            bx = ARENA_RIGHT - BALL_RAD
            vx = -fabs(vx)
        ok

        // Ceiling (far wall)
        if bz + BALL_RAD > ARENA_FAR
            bz = ARENA_FAR - BALL_RAD
            vz = -fabs(vz)
        ok

        // Floor bounce (keep ball on surface)
        if by - BALL_RAD < 0
            by = BALL_RAD
            vy = fabs(vy)
        ok

        // Ball lost (behind paddle)
        if bz - BALL_RAD < ARENA_NEAR - 1.0
            balls[bi][7] = false
            br_burst(bx, by, bz, 255, 80, 80)
            loop
        ok

        // Paddle collision
        halfPW = padW / 2
        if vz < 0 and bz - BALL_RAD < PAD_Z + PAD_D/2 and bz + BALL_RAD > PAD_Z - PAD_D/2
            if bx + BALL_RAD > padX - halfPW and bx - BALL_RAD < padX + halfPW
                if by < PAD_H + BALL_RAD + 0.5
                    bz = PAD_Z + PAD_D/2 + BALL_RAD
                    // Angle based on hit position
                    hitPct = (bx - padX) / halfPW
                    if hitPct < -1.0 hitPct = -1.0 ok
                    if hitPct > 1.0  hitPct = 1.0  ok
                    spd = sqrt(vx*vx + vy*vy + vz*vz)
                    if spd < 1.0 spd = ballSpeed ok
                    angle = hitPct * 1.1
                    vx = sin(angle) * spd
                    vz = cos(angle) * spd * 0.85
                    if vz < 2.0 vz = 2.0 ok
                    vy = fabs(vy) * 0.2
                    combo = 0
                    br_burst(bx, PAD_H, bz, 100, 180, 255)
                ok
            ok
        ok

        // Brick collision
        for bi2 = 1 to len(bricks)
            if !bricks[bi2][5] loop ok
            bkx = bricks[bi2][6]
            bky = bricks[bi2][7]
            bkz = bricks[bi2][8]
            hw = BRICK_W / 2
            hh = BRICK_H / 2
            hd = BRICK_D / 2

            // AABB check
            if bx + BALL_RAD > bkx - hw and bx - BALL_RAD < bkx + hw
                if bz + BALL_RAD > bkz - hd and bz - BALL_RAD < bkz + hd
                    if by + BALL_RAD > bky - hh and by - BALL_RAD < bky + hh
                        // Hit! Determine which face
                        overlapL = (bx + BALL_RAD) - (bkx - hw)
                        overlapR = (bkx + hw) - (bx - BALL_RAD)
                        overlapN = (bz + BALL_RAD) - (bkz - hd)
                        overlapF = (bkz + hd) - (bz - BALL_RAD)

                        minOver = overlapL
                        face = 1
                        if overlapR < minOver minOver = overlapR  face = 2 ok
                        if overlapN < minOver minOver = overlapN  face = 3 ok
                        if overlapF < minOver minOver = overlapF  face = 4 ok

                        isFire = balls[bi][8]

                        // Reflect only if not fireball
                        if !isFire
                            if face = 1 vx = -fabs(vx)  bx = bkx - hw - BALL_RAD ok
                            if face = 2 vx = fabs(vx)   bx = bkx + hw + BALL_RAD ok
                            if face = 3 vz = -fabs(vz)  bz = bkz - hd - BALL_RAD ok
                            if face = 4 vz = fabs(vz)   bz = bkz + hd + BALL_RAD ok
                        ok

                        // Damage brick
                        if bricks[bi2][9] != 6
                            bricks[bi2][3] -= 1
                            combo += 1
                            sc = 10 * combo
                            score += sc

                            if bricks[bi2][3] <= 0
                                bricks[bi2][5] = false
                                br_brickBreakFx(bkx, bky, bkz, bricks[bi2][9])
                                // Maybe spawn power-up (15% chance)
                                if GetRandomValue(1, 100) <= 15
                                    br_spawnPower(bkx, bky, bkz)
                                ok
                            else
                                br_burst(bkx, bky, bkz, 200, 200, 100)
                            ok
                        else
                            // Gold brick - just bounce, no damage
                            br_burst(bkx, bky, bkz, 255, 215, 0)
                        ok

                        if !isFire loop ok
                    ok
                ok
            ok
        next

        // Normalize speed
        spd = sqrt(vx*vx + vy*vy + vz*vz)
        if spd > 0.1
            ratio = ballSpeed / spd
            vx = vx * ratio
            vy = vy * ratio * 0.3
            vz = vz * ratio
            // Re-normalize xz to maintain ball speed
            xzSpd = sqrt(vx*vx + vz*vz)
            if xzSpd < ballSpeed * 0.4
                vz = ballSpeed * 0.7
                if vz > 0 ok
            ok
        ok

        balls[bi][1] = bx
        balls[bi][2] = by
        balls[bi][3] = bz
        balls[bi][4] = vx
        balls[bi][5] = vy
        balls[bi][6] = vz
    next

    if !anyAlive
        clearTimer = 1.0
        gameState = ST_DEAD
    ok

// =============================================================
// Power-Ups
// =============================================================

func br_spawnPower px, py, pz
    pt = GetRandomValue(1, 4)
    add(powerups, [px, py, pz, pt, true])

func br_updatePowerups dt
    i = 1
    while i <= len(powerups)
        if !powerups[i][5]
            del(powerups, i)
            loop
        ok
        // Fall toward paddle
        powerups[i][3] -= 4.0 * dt
        powerups[i][2] += sin(animTime * 4.0 + i) * 0.02

        px = powerups[i][1]
        pz = powerups[i][3]
        pt = powerups[i][4]

        // Out of arena
        if pz < ARENA_NEAR - 1.0
            powerups[i][5] = false
            i += 1
            loop
        ok

        // Check paddle catch
        halfPW = padW / 2
        if pz < PAD_Z + PAD_D and pz > PAD_Z - PAD_D
            if px > padX - halfPW - 0.5 and px < padX + halfPW + 0.5
                powerups[i][5] = false
                br_applyPower(pt)
                br_burst(px, PAD_H + 0.5, pz, 255, 255, 255)
            ok
        ok
        i += 1
    end

func br_applyPower pt
    if pt = PW_WIDE
        padWideT = 8.0
        padW = PAD_W * 1.6
    ok
    if pt = PW_MULTI
        // Split first alive ball into 3 — capture count FIRST
        cnt = len(balls)
        foundBall = 0
        for i = 1 to cnt
            if balls[i][7] and foundBall = 0
                foundBall = i
            ok
        next
        if foundBall > 0
            bx = balls[foundBall][1]
            by = balls[foundBall][2]
            bz = balls[foundBall][3]
            isFire = balls[foundBall][8]
            spd = ballSpeed
            add(balls, [bx, by, bz, -spd * 0.5, 0.0, spd * 0.85, true, isFire])
            add(balls, [bx, by, bz,  spd * 0.5, 0.0, spd * 0.85, true, isFire])
        ok
    ok
    if pt = PW_FIRE
        fireTimer = 6.0
        cnt = len(balls)
        for i = 1 to cnt
            balls[i][8] = true
        next
    ok
    if pt = PW_LIFE
        lives += 1
    ok

// =============================================================
// Level Clear Check
// =============================================================

func br_checkClear
    allGone = true
    for i = 1 to len(bricks)
        if bricks[i][5] and bricks[i][9] != 6
            allGone = false
        ok
    next
    if allGone
        clearTimer = 2.0
        gameState = ST_CLEAR
        score += 500 + level * 100
        br_celebrationFx()
    ok

// =============================================================
// Particles / Effects
// =============================================================

func br_burst wx, wy, wz, pr, pg, pb
    for k = 1 to 5
        vx = (GetRandomValue(-100, 100) / 100.0) * 2.0
        vy = (GetRandomValue(50, 200) / 100.0)
        vz = (GetRandomValue(-100, 100) / 100.0) * 2.0
        cr = pr + GetRandomValue(-30, 30)
        cg = pg + GetRandomValue(-30, 30)
        cb = pb + GetRandomValue(-30, 30)
        if cr < 0 cr = 0 ok  if cr > 255 cr = 255 ok
        if cg < 0 cg = 0 ok  if cg > 255 cg = 255 ok
        if cb < 0 cb = 0 ok  if cb > 255 cb = 255 ok
        add(partList, [wx, wy, wz, vx, vy, vz, 0.8, cr, cg, cb])
    next

func br_brickBreakFx bx, by, bz, btype
    pr = 100  pg = 220  pb = 100
    if btype = 2 pr = 230  pg = 220  pb = 50  ok
    if btype = 3 pr = 240  pg = 160  pb = 40  ok
    if btype = 4 pr = 240  pg = 60   pb = 60  ok
    if btype = 5 pr = 180  pg = 190  pb = 200 ok
    for k = 1 to 10
        vx = (GetRandomValue(-100, 100) / 100.0) * 3.0
        vy = (GetRandomValue(80, 300) / 100.0)
        vz = (GetRandomValue(-100, 100) / 100.0) * 3.0
        cr = pr + GetRandomValue(-25, 25)
        cg = pg + GetRandomValue(-25, 25)
        cb = pb + GetRandomValue(-25, 25)
        if cr < 0 cr = 0 ok  if cr > 255 cr = 255 ok
        if cg < 0 cg = 0 ok  if cg > 255 cg = 255 ok
        if cb < 0 cb = 0 ok  if cb > 255 cb = 255 ok
        add(partList, [bx, by, bz, vx, vy, vz, 1.0, cr, cg, cb])
    next

func br_celebrationFx
    for k = 1 to 30
        px = ARENA_LEFT + GetRandomValue(0, 100) / 100.0 * ARENA_W
        pz = BRICK_Z0 + GetRandomValue(0, 100) / 100.0 * 6.0
        vx = (GetRandomValue(-100, 100) / 100.0) * 2.0
        vy = (GetRandomValue(150, 400) / 100.0)
        vz = (GetRandomValue(-100, 100) / 100.0) * 2.0
        cr = GetRandomValue(100, 255)
        cg = GetRandomValue(100, 255)
        cb = GetRandomValue(100, 255)
        add(partList, [px, 0.5, pz, vx, vy, vz, 1.5, cr, cg, cb])
    next

func br_updateParts dt
    i = 1
    while i <= len(partList)
        partList[i][1] += partList[i][4] * dt
        partList[i][2] += partList[i][5] * dt
        partList[i][3] += partList[i][6] * dt
        partList[i][5] -= 6.0 * dt
        partList[i][7] -= dt * 1.3
        if partList[i][7] <= 0
            del(partList, i)
        else
            i += 1
        ok
    end

func br_drawParts3D
    for i = 1 to len(partList)
        p = partList[i]
        alpha = floor(p[7] / 1.0 * 255)
        if alpha > 255 alpha = 255 ok
        if alpha < 0   alpha = 0   ok
        sz = 0.04 + p[7] * 0.07
        DrawSphereEx(Vector3(p[1], p[2], p[3]), sz, 4, 4,
            RAYLIBColor(p[8], p[9], p[10], alpha))
    next

// =============================================================
// Camera
// =============================================================

func br_moveCamera
    midZ = ARENA_D / 2
    if camMode = CAM_BEHIND
        gX = 0.0    gY = 24.0   gZ = -8.0
        tX = 0.0    tZ = midZ + 1.0
    ok
    if camMode = CAM_HIGH
        gX = 0.0    gY = 32.0   gZ = midZ
        tX = 0.0    tZ = midZ
    ok
    if camMode = CAM_SIDE
        gX = -18.0  gY = 16.0   gZ = midZ
        tX = 0.0    tZ = midZ
    ok
    sp = 0.06
    cpX += (gX - cpX) * sp
    cpY += (gY - cpY) * sp
    cpZ += (gZ - cpZ) * sp
    ctX += (tX - ctX) * sp
    ctY = 0.5
    ctZ += (tZ - ctZ) * sp
    camera.position.x = cpX
    camera.position.y = cpY
    camera.position.z = cpZ
    camera.target.x   = ctX
    camera.target.y   = ctY
    camera.target.z   = ctZ

// =============================================================
// Drawing: Arena
// =============================================================

func br_drawArena
    // Floor
    DrawCube(Vector3(0.0, -0.1, ARENA_D/2), ARENA_W + 0.5, 0.05, ARENA_D + 0.5,
        RAYLIBColor(20, 20, 35, 255))
    // Floor grid lines
    for i = 0 to 20
        gz = i * (ARENA_D / 20.0)
        DrawLine3D(Vector3(ARENA_LEFT, 0.01, gz), Vector3(ARENA_RIGHT, 0.01, gz),
            RAYLIBColor(30, 30, 50, 80))
    next
    for i = 0 to 10
        gx = ARENA_LEFT + i * (ARENA_W / 10.0)
        DrawLine3D(Vector3(gx, 0.01, ARENA_NEAR), Vector3(gx, 0.01, ARENA_FAR),
            RAYLIBColor(30, 30, 50, 80))
    next

    // Left wall
    DrawCube(Vector3(ARENA_LEFT - 0.25, WALL_H/2, ARENA_D/2),
        0.5, WALL_H, ARENA_D, RAYLIBColor(40, 40, 70, 200))
    // Right wall
    DrawCube(Vector3(ARENA_RIGHT + 0.25, WALL_H/2, ARENA_D/2),
        0.5, WALL_H, ARENA_D, RAYLIBColor(40, 40, 70, 200))
    // Back wall (far)
    DrawCube(Vector3(0.0, WALL_H/2, ARENA_FAR + 0.25),
        ARENA_W + 1.0, WALL_H, 0.5, RAYLIBColor(40, 40, 70, 200))

    // Glow lines on walls
    DrawLine3D(Vector3(ARENA_LEFT, WALL_H, ARENA_NEAR),
        Vector3(ARENA_LEFT, WALL_H, ARENA_FAR), RAYLIBColor(60, 80, 160, 150))
    DrawLine3D(Vector3(ARENA_RIGHT, WALL_H, ARENA_NEAR),
        Vector3(ARENA_RIGHT, WALL_H, ARENA_FAR), RAYLIBColor(60, 80, 160, 150))

// =============================================================
// Drawing: Bricks
// =============================================================

func br_drawBricks
    for i = 1 to len(bricks)
        if !bricks[i][5] loop ok
        bx = bricks[i][6]
        by = bricks[i][7]
        bz = bricks[i][8]
        bt = bricks[i][9]
        hp = bricks[i][3]
        mhp = bricks[i][4]

        bc = RAYLIBColor(80, 210, 80, 255)
        wc = RAYLIBColor(120, 255, 120, 150)
        if bt = 2 bc = RAYLIBColor(220, 210, 50, 255)  wc = RAYLIBColor(255, 245, 90, 150)  ok
        if bt = 3 bc = RAYLIBColor(230, 150, 40, 255)  wc = RAYLIBColor(255, 190, 70, 150)  ok
        if bt = 4 bc = RAYLIBColor(230, 55, 55, 255)   wc = RAYLIBColor(255, 100, 100, 150) ok
        if bt = 5 bc = RAYLIBColor(170, 180, 195, 255) wc = RAYLIBColor(210, 220, 235, 150) ok
        if bt = 6
            // Gold - pulsing
            pulse = 200 + floor(sin(animTime * 3.0 + i * 0.5) * 40)
            bc = RAYLIBColor(pulse, floor(pulse * 0.82), 20, 255)
            wc = RAYLIBColor(255, 230, 50, 180)
        ok

        // Damage flash: brighter when hit (hp < maxhp)
        if hp < mhp and bt != 6
            flash = floor(sin(animTime * 8.0) * 30)
            if flash < 0 flash = 0 ok
        ok

        DrawCube(Vector3(bx, by, bz), BRICK_W, BRICK_H, BRICK_D, bc)
        DrawCubeWires(Vector3(bx, by, bz), BRICK_W, BRICK_H, BRICK_D, wc)
    next

// =============================================================
// Drawing: Paddle
// =============================================================

func br_drawPaddle
    pc = RAYLIBColor(60, 140, 230, 255)
    if padWideT > 0 pc = RAYLIBColor(60, 230, 120, 255) ok
    DrawCube(Vector3(padX, PAD_H/2, PAD_Z), padW, PAD_H, PAD_D, pc)
    DrawCubeWires(Vector3(padX, PAD_H/2, PAD_Z), padW, PAD_H, PAD_D,
        RAYLIBColor(120, 200, 255, 180))

    // Glow on top
    DrawCube(Vector3(padX, PAD_H + 0.02, PAD_Z), padW * 0.9, 0.02, PAD_D * 0.6,
        RAYLIBColor(150, 210, 255, 60))

// =============================================================
// Drawing: Balls
// =============================================================

func br_drawBalls
    for i = 1 to len(balls)
        if !balls[i][7] loop ok
        bx = balls[i][1]
        by = balls[i][2]
        bz = balls[i][3]

        if balls[i][8]
            // Fireball - red/orange glow
            DrawSphereEx(Vector3(bx, by, bz), BALL_RAD, 10, 10,
                RAYLIBColor(255, 100, 30, 255))
            DrawSphereEx(Vector3(bx, by, bz), BALL_RAD + 0.15, 6, 6,
                RAYLIBColor(255, 60, 20, 50))
        else
            DrawSphereEx(Vector3(bx, by, bz), BALL_RAD, 10, 10,
                RAYLIBColor(240, 240, 255, 255))
            DrawSphereEx(Vector3(bx, by, bz), BALL_RAD + 0.08, 6, 6,
                RAYLIBColor(180, 200, 255, 40))
        ok

        // Shadow
        DrawCircle3D(Vector3(bx, 0.01, bz), BALL_RAD + 0.05,
            Vector3(1, 0, 0), 90.0, RAYLIBColor(0, 0, 0, 40))
    next

// =============================================================
// Drawing: Power-ups
// =============================================================

func br_drawPowerups3D
    for i = 1 to len(powerups)
        if !powerups[i][5] loop ok
        px = powerups[i][1]
        py = powerups[i][2]
        pz = powerups[i][3]
        pt = powerups[i][4]

        pc = RAYLIBColor(60, 220, 60, 255)
        gc = RAYLIBColor(100, 255, 100, 60)
        if pt = PW_MULTI pc = RAYLIBColor(60, 120, 240, 255)  gc = RAYLIBColor(100, 160, 255, 60) ok
        if pt = PW_FIRE  pc = RAYLIBColor(240, 80, 40, 255)   gc = RAYLIBColor(255, 120, 60, 60)  ok
        if pt = PW_LIFE  pc = RAYLIBColor(200, 60, 220, 255)  gc = RAYLIBColor(230, 100, 255, 60) ok

        // Spinning gem shape (two tetrahedra approximation with cube)
        rot = animTime * 120.0 + i * 90.0
        DrawSphereEx(Vector3(px, py, pz), 0.35, 6, 4, pc)
        DrawSphereEx(Vector3(px, py, pz), 0.5, 4, 4, gc)
    next

// =============================================================
// HUD
// =============================================================

func br_drawHUD
    DrawRectangle(10, 28, SCREEN_W - 20, 28, Fade(BLACK, 0.75))
    DrawText("Score: " + score, 20, 32, 17, WHITE)
    DrawText("Lives: " + lives, 170, 32, 17, RAYLIBColor(255, 80, 80, 255))
    DrawText("Level: " + level + "/" + maxLevel, 300, 32, 17, RAYLIBColor(100, 200, 255, 255))
    DrawText("Combo: x" + combo, 460, 32, 17, RAYLIBColor(255, 215, 0, 255))

    // Active power-ups
    px = 600
    if padWideT > 0
        DrawText("WIDE " + floor(padWideT) + "s", px, 32, 14, RAYLIBColor(60, 230, 120, 230))
        px += 80
    ok
    if fireTimer > 0
        DrawText("FIRE " + floor(fireTimer) + "s", px, 32, 14, RAYLIBColor(255, 100, 40, 230))
        px += 80
    ok

    bCnt = 0
    for i = 1 to len(balls)
        if balls[i][7] bCnt += 1 ok
    next
    if bCnt > 1
        DrawText("Balls:" + bCnt, px, 32, 14, RAYLIBColor(100, 160, 255, 230))
    ok

    cn = "BEHIND"
    if camMode = CAM_HIGH cn = "HIGH" ok
    if camMode = CAM_SIDE cn = "SIDE" ok
    DrawText("Cam:" + cn + " [C]", SCREEN_W - 155, 32, 14, RAYLIBColor(130, 150, 170, 200))

// =============================================================
// Title Screen
// =============================================================

func br_drawTitle
    DrawRectangleGradientV(0, 0, SCREEN_W, SCREEN_H,
        RAYLIBColor(6, 6, 20, 255), RAYLIBColor(12, 12, 30, 255))

    t1 = "3D BREAKOUT"
    t1w = MeasureText(t1, 58)
    DrawText(t1, (SCREEN_W - t1w)/2, 85, 58, RAYLIBColor(80, 160, 255, 255))

    t2 = "~ Smash the bricks with style! ~"
    t2w = MeasureText(t2, 18)
    DrawText(t2, (SCREEN_W - t2w)/2, 155, 18, RAYLIBColor(120, 170, 230, 220))

    cy = 200
    cLines = [
        "Left / Right  or  A / D   -  Move paddle",
        "SPACE                     -  Launch ball",
        "P                         -  Pause",
        "C                         -  Cycle camera",
        "R                         -  Restart",
        "",
        "Green brick (1 hit)   Yellow (2)   Orange (3)",
        "Red (4 hits)   Silver (5)   Gold (indestructible)",
        "",
        "Power-Ups (catch with paddle):",
        "  Green gem  = Wide Paddle (8s)",
        "  Blue gem   = Multi-Ball (split into 3)",
        "  Red gem    = Fire Ball (pierces bricks, 6s)",
        "  Purple gem = Extra Life",
        "",
        "Combo multiplier: consecutive hits = more points!"
    ]
    for i = 1 to len(cLines)
        lw = MeasureText(cLines[i], 15)
        if i >= 7 and i <= 8
            col = RAYLIBColor(255, 210, 90, 220)
        but i >= 10
            col = RAYLIBColor(120, 230, 150, 220)
        else
            col = RAYLIBColor(150, 190, 230, 230)
        ok
        DrawText(cLines[i], (SCREEN_W - lw)/2, cy + (i - 1) * 22, 15, col)
    next

    if floor(animTime * 2) % 2 = 0
        st = "Press ENTER or SPACE to Start"
        stw = MeasureText(st, 26)
        DrawText(st, (SCREEN_W - stw)/2, 580, 26, WHITE)
    ok

    cr = "Developed using Ring Language + RingRayLib"
    crw = MeasureText(cr, 14)
    DrawText(cr, (SCREEN_W - crw)/2, SCREEN_H - 35, 14, RAYLIBColor(60, 80, 130, 175))

// =============================================================
// Overlays
// =============================================================

func br_drawLaunch
    lt = "Press SPACE to launch"
    ltw = MeasureText(lt, 22)
    DrawText(lt, (SCREEN_W - ltw)/2, SCREEN_H - 120, 22, RAYLIBColor(200, 220, 255, 200))

func br_drawPause
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.5))
    pt = "PAUSED"
    ptw = MeasureText(pt, 50)
    DrawText(pt, (SCREEN_W - ptw)/2, SCREEN_H/2 - 40, 50, WHITE)
    p2 = "Press P or SPACE to resume"
    p2w = MeasureText(p2, 20)
    DrawText(p2, (SCREEN_W - p2w)/2, SCREEN_H/2 + 25, 20, RAYLIBColor(180, 200, 230, 220))

func br_drawClear
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.35))
    ct = "LEVEL " + level + " CLEAR!"
    ctw = MeasureText(ct, 48)
    DrawText(ct, (SCREEN_W - ctw)/2, SCREEN_H/2 - 30, 48, RAYLIBColor(50, 255, 100, 255))
    c2 = "+500 bonus"
    c2w = MeasureText(c2, 22)
    DrawText(c2, (SCREEN_W - c2w)/2, SCREEN_H/2 + 30, 22, RAYLIBColor(255, 215, 0, 230))

func br_drawDead
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.3))
    dt2 = "Ball Lost!"
    dw = MeasureText(dt2, 36)
    DrawText(dt2, (SCREEN_W - dw)/2, SCREEN_H/2 - 20, 36, RAYLIBColor(255, 80, 80, 230))

func br_drawGameOver
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.55))
    g1 = "GAME OVER"
    g1w = MeasureText(g1, 55)
    DrawText(g1, (SCREEN_W - g1w)/2, 250, 55, RAYLIBColor(255, 55, 55, 255))
    DrawText("Final Score: " + score,
        (SCREEN_W - MeasureText("Final Score: " + score, 22))/2, 320, 22, WHITE)
    DrawText("Reached Level " + level,
        (SCREEN_W - MeasureText("Reached Level " + level, 18))/2, 355, 18,
        RAYLIBColor(180, 200, 230, 220))
    if floor(animTime * 2) % 2 = 0
        rt = "Press ENTER or SPACE to retry"
        rtw = MeasureText(rt, 20)
        DrawText(rt, (SCREEN_W - rtw)/2, 405, 20, WHITE)
    ok

func br_drawWinScr
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.5))
    g1 = "YOU WIN!"
    g1w = MeasureText(g1, 55)
    DrawText(g1, (SCREEN_W - g1w)/2, 240, 55, RAYLIBColor(50, 255, 100, 255))
    DrawText("All " + maxLevel + " levels complete!",
        (SCREEN_W - MeasureText("All " + maxLevel + " levels complete!", 22))/2, 310, 22, WHITE)
    w3 = "Final Score: " + score + "   Lives: " + lives
    DrawText(w3, (SCREEN_W - MeasureText(w3, 18))/2, 350, 18, RAYLIBColor(255, 215, 0, 230))
    if floor(animTime * 2) % 2 = 0
        rt = "Press ENTER or SPACE to play again"
        rtw = MeasureText(rt, 20)
        DrawText(rt, (SCREEN_W - rtw)/2, 400, 20, WHITE)
    ok
