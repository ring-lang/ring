/*
**  3D Snake Game - Using RingRayLib
**  ==================================
**  A classic snake game in full 3D! Guide a glowing snake made of
**  connected spheres across a grid to eat food and grow longer.
**
**  Controls:
**    Arrow Keys / WASD  - Change snake direction
**    R                  - Restart game
**    P                  - Pause / Unpause
**    C                  - Cycle camera views (Follow / Top-Down / Isometric)
**    ESC                - Exit
**
**  Features:
**    - Smooth 3D snake movement on a grid
**    - Snake body grows with each food eaten
**    - Self-collision and wall-collision detection
**    - Three camera modes: Follow / Top-Down / Isometric
**    - Food with pulsing glow animation
**    - Bonus food (golden) that appears temporarily
**    - Particle burst effects on eating
**    - Speed increases as snake grows
**    - Score, high score, and length display
**    - Bordered arena with decorative walls
**    - Mini-map overlay
**    - Start, pause, and game-over screens
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W        = 1024
SCREEN_H        = 768
GRID_SIZE       = 20          // 20 x 20 grid
CELL_SZ         = 1.5         // World units per cell
SPHERE_RAD      = 0.55        // Snake segment radius
FOOD_RAD        = 0.4         // Food radius
WALL_H          = 1.2         // Border wall height

// Directions
DIR_NONE        = 0
DIR_UP          = 1           // -Z direction
DIR_DOWN        = 2           // +Z direction
DIR_LEFT        = 3           // -X direction
DIR_RIGHT       = 4           // +X direction

// Game states
ST_START        = 1
ST_PLAYING      = 2
ST_PAUSED       = 3
ST_GAMEOVER     = 4

// Camera modes
CAM_FOLLOW      = 1
CAM_TOPDOWN     = 2
CAM_ISOMETRIC   = 3

// Timing
BASE_INTERVAL   = 0.18        // Seconds between moves at start
MIN_INTERVAL    = 0.07        // Fastest possible speed

// =============================================================
// Global Variables
// =============================================================

// Snake body: list of [gridX, gridZ] pairs
// Index 1 = head, last index = tail
snakeBody       = []
snakeDir        = DIR_RIGHT
nextDir         = DIR_RIGHT
snakeAlive      = true

// Food position
foodX           = 10
foodZ           = 10
foodActive      = true

// Bonus food (golden, temporary)
bonusX          = 0
bonusZ          = 0
bonusActive     = false
bonusTimer      = 0.0
BONUS_DURATION  = 8.0

// Particles: list of [x, y, z, vx, vy, vz, life, r, g, b]
particles       = []

// Game state variables
gameState       = ST_START
score           = 0
highScore       = 0
moveTimer       = 0.0
moveInterval    = BASE_INTERVAL
animTime        = 0.0
cameraMode      = CAM_FOLLOW

// Smooth movement interpolation
interpFactor    = 0.0         // 0.0 to 1.0 between grid steps
prevBody        = []          // Previous positions for lerp

// Camera smoothing - initialize to match follow camera at grid center
camPosX = GRID_SIZE * CELL_SZ / 2
camPosY = 14.0
camPosZ = GRID_SIZE * CELL_SZ / 2 + 12
camTgtX = GRID_SIZE * CELL_SZ / 2
camTgtY = 0.5
camTgtZ = GRID_SIZE * CELL_SZ / 2

// =============================================================
// Main Program
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Ring 3D Snake - RingRayLib")
ToggleFullScreen()
SetTargetFPS(60)

camera = Camera3D(
    0, 20, 15,
    0,  0,  0,
    0,  1,  0,
    45,
    CAMERA_PERSPECTIVE
)

snake_resetGame()

// =============================================================
// Main Game Loop
// =============================================================

while !WindowShouldClose()

    dt = GetFrameTime()
    animTime += dt

    // --- Global input ---
    if IsKeyPressed(KEY_R)
        snake_resetGame()
        gameState = ST_PLAYING
    ok

    if IsKeyPressed(KEY_C)
        cameraMode += 1
        if cameraMode > CAM_ISOMETRIC
            cameraMode = CAM_FOLLOW
        ok
    ok

    // --- State-specific updates ---
    if gameState = ST_START
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            snake_resetGame()
            gameState = ST_PLAYING
        ok
    ok

    if gameState = ST_PLAYING
        if IsKeyPressed(KEY_P)
            gameState = ST_PAUSED
        else
            snake_handleInput()
            snake_updateMovement(dt)
            snake_updateBonus(dt)
            snake_updateParticles(dt)
        ok
    ok

    if gameState = ST_PAUSED
        if IsKeyPressed(KEY_P) or IsKeyPressed(KEY_SPACE)
            gameState = ST_PLAYING
        ok
    ok

    if gameState = ST_GAMEOVER
        snake_updateParticles(dt)
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            snake_resetGame()
            gameState = ST_PLAYING
        ok
    ok

    snake_positionCamera()

    // --- Drawing ---
    BeginDrawing()
        ClearBackground(RAYLIBColor(12, 12, 20, 255))

        if gameState = ST_START
            snake_drawTitleScreen()
        else
            BeginMode3D(camera)
                snake_drawArena()
                snake_drawFood()
                snake_drawBonusFood()
                snake_drawSnake()
                snake_drawParticles3D()
                snake_drawLightOrbs()
            EndMode3D()

            snake_drawHUD()
            snake_drawMiniMap()

            if gameState = ST_PAUSED
                snake_drawPauseOverlay()
            ok
            if gameState = ST_GAMEOVER
                snake_drawGameOver()
            ok
        ok

        DrawFPS(10, 10)
    EndDrawing()

end

CloseWindow()

// =============================================================
// Game Reset
// =============================================================

func snake_resetGame
    snakeBody = []
    startX = floor(GRID_SIZE / 2)
    startZ = floor(GRID_SIZE / 2)
    for i = 0 to 3
        add(snakeBody, [startX - i, startZ])
    next

    // Copy for smooth interpolation
    prevBody = []
    for i = 1 to len(snakeBody)
        add(prevBody, [snakeBody[i][1], snakeBody[i][2]])
    next

    snakeDir     = DIR_RIGHT
    nextDir      = DIR_RIGHT
    snakeAlive   = true
    score        = 0
    moveTimer    = 0.0
    moveInterval = BASE_INTERVAL
    interpFactor = 1.0
    particles    = []
    bonusActive  = false
    bonusTimer   = 0.0

    snake_spawnFood()

// =============================================================
// Input Handling
// =============================================================

func snake_handleInput
    // Queue next direction (prevent 180-degree reversal)
    // Use IsKeyDown for responsive held-key input
    if IsKeyPressed(KEY_UP) or IsKeyPressed(KEY_W) or IsKeyDown(KEY_UP) or IsKeyDown(KEY_W)
        if snakeDir != DIR_DOWN and nextDir != DIR_DOWN
            nextDir = DIR_UP
        ok
    ok
    if IsKeyPressed(KEY_DOWN) or IsKeyPressed(KEY_S) or IsKeyDown(KEY_DOWN) or IsKeyDown(KEY_S)
        if snakeDir != DIR_UP and nextDir != DIR_UP
            nextDir = DIR_DOWN
        ok
    ok
    if IsKeyPressed(KEY_LEFT) or IsKeyPressed(KEY_A) or IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_A)
        if snakeDir != DIR_RIGHT and nextDir != DIR_RIGHT
            nextDir = DIR_LEFT
        ok
    ok
    if IsKeyPressed(KEY_RIGHT) or IsKeyPressed(KEY_D) or IsKeyDown(KEY_RIGHT) or IsKeyDown(KEY_D)
        if snakeDir != DIR_LEFT and nextDir != DIR_LEFT
            nextDir = DIR_RIGHT
        ok
    ok

// =============================================================
// Snake Movement & Logic
// =============================================================

func snake_updateMovement dt
    if !snakeAlive return ok

    moveTimer += dt
    interpFactor = moveTimer / moveInterval
    if interpFactor > 1.0 interpFactor = 1.0 ok

    if moveTimer >= moveInterval
        moveTimer -= moveInterval

        // Save previous positions for smooth interpolation
        prevBody = []
        for i = 1 to len(snakeBody)
            add(prevBody, [snakeBody[i][1], snakeBody[i][2]])
        next

        // Apply queued direction
        snakeDir = nextDir

        // Calculate new head position
        headX = snakeBody[1][1]
        headZ = snakeBody[1][2]

        if snakeDir = DIR_UP    headZ -= 1  ok
        if snakeDir = DIR_DOWN  headZ += 1  ok
        if snakeDir = DIR_LEFT  headX -= 1  ok
        if snakeDir = DIR_RIGHT headX += 1  ok

        // Check wall collision
        if headX < 0 or headX >= GRID_SIZE or headZ < 0 or headZ >= GRID_SIZE
            snake_die()
            return
        ok

        // Check self collision (skip tail since it moves away)
        for i = 1 to len(snakeBody) - 1
            if snakeBody[i][1] = headX and snakeBody[i][2] = headZ
                snake_die()
                return
            ok
        next

        // Check food collision
        ateFood = false
        if headX = foodX and headZ = foodZ
            ateFood = true
            score += 10
            snake_spawnEatParticles(foodX, foodZ, 0, 255, 100)
            snake_spawnFood()
            // 1 in 3 chance to spawn bonus
            if !bonusActive
                if GetRandomValue(1, 3) = 1
                    snake_spawnBonusFood()
                ok
            ok
        ok

        // Check bonus food collision
        if bonusActive
            if headX = bonusX and headZ = bonusZ
                ateFood = true
                score += 50
                bonusActive = false
                snake_spawnEatParticles(bonusX, bonusZ, 255, 215, 0)
            ok
        ok

        // Move body: insert new head
        newBody = []
        add(newBody, [headX, headZ])
        for i = 1 to len(snakeBody)
            add(newBody, [snakeBody[i][1], snakeBody[i][2]])
        next
        // Remove tail unless food was eaten (growth)
        if !ateFood
            del(newBody, len(newBody))
        ok
        snakeBody = newBody

        // Sync prevBody length with new snakeBody length
        while len(prevBody) < len(snakeBody)
            lastIdx = len(snakeBody)
            add(prevBody, [snakeBody[lastIdx][1], snakeBody[lastIdx][2]])
        end
        while len(prevBody) > len(snakeBody)
            del(prevBody, len(prevBody))
        end

        // Speed increases as snake grows
        speedBonus = len(snakeBody) - 4
        if speedBonus < 0 speedBonus = 0 ok
        moveInterval = BASE_INTERVAL - (speedBonus * 0.003)
        if moveInterval < MIN_INTERVAL moveInterval = MIN_INTERVAL ok

        // Reset interpolation for new step
        interpFactor = 0.0
    ok

func snake_die
    snakeAlive = false
    gameState = ST_GAMEOVER
    if score > highScore
        highScore = score
    ok
    // Burst red particles at head
    hx = snakeBody[1][1]
    hz = snakeBody[1][2]
    for i = 1 to 30
        wx = hx * CELL_SZ + CELL_SZ / 2
        wz = hz * CELL_SZ + CELL_SZ / 2
        vx = (GetRandomValue(-100, 100) / 100.0) * 3.0
        vy = (GetRandomValue(50, 200) / 100.0) * 2.0
        vz = (GetRandomValue(-100, 100) / 100.0) * 3.0
        cr = GetRandomValue(200, 255)
        cg = GetRandomValue(30, 80)
        cb = GetRandomValue(10, 40)
        add(particles, [wx, SPHERE_RAD, wz, vx, vy, vz, 1.5, cr, cg, cb])
    next

// =============================================================
// Food Spawning
// =============================================================

func snake_spawnFood
    tries = 0
    while true
        fx = GetRandomValue(1, GRID_SIZE - 2)
        fz = GetRandomValue(1, GRID_SIZE - 2)
        onSnake = false
        for i = 1 to len(snakeBody)
            if snakeBody[i][1] = fx and snakeBody[i][2] = fz
                onSnake = true
            ok
        next
        if !onSnake
            foodX = fx
            foodZ = fz
            foodActive = true
            return
        ok
        tries += 1
        if tries > 200
            foodX = fx
            foodZ = fz
            foodActive = true
            return
        ok
    end

func snake_spawnBonusFood
    tries = 0
    while true
        bx = GetRandomValue(1, GRID_SIZE - 2)
        bz = GetRandomValue(1, GRID_SIZE - 2)
        onSnake = false
        for i = 1 to len(snakeBody)
            if snakeBody[i][1] = bx and snakeBody[i][2] = bz
                onSnake = true
            ok
        next
        if !onSnake
            if !(bx = foodX and bz = foodZ)
                bonusX = bx
                bonusZ = bz
                bonusActive = true
                bonusTimer = BONUS_DURATION
                return
            ok
        ok
        tries += 1
        if tries > 100 return ok
    end

func snake_updateBonus dt
    if bonusActive
        bonusTimer -= dt
        if bonusTimer <= 0
            bonusActive = false
        ok
    ok

// =============================================================
// Particles
// =============================================================

func snake_spawnEatParticles gx, gz, pr, pg, pb
    wx = gx * CELL_SZ + CELL_SZ / 2
    wz = gz * CELL_SZ + CELL_SZ / 2
    for i = 1 to 15
        vx = (GetRandomValue(-100, 100) / 100.0) * 2.0
        vy = (GetRandomValue(80, 250) / 100.0) * 1.5
        vz = (GetRandomValue(-100, 100) / 100.0) * 2.0
        cr = pr + GetRandomValue(-30, 30)
        cg = pg + GetRandomValue(-30, 30)
        cb = pb + GetRandomValue(-30, 30)
        if cr < 0 cr = 0 ok    if cr > 255 cr = 255 ok
        if cg < 0 cg = 0 ok    if cg > 255 cg = 255 ok
        if cb < 0 cb = 0 ok    if cb > 255 cb = 255 ok
        add(particles, [wx, 0.5, wz, vx, vy, vz, 1.0, cr, cg, cb])
    next

func snake_updateParticles dt
    i = 1
    while i <= len(particles)
        particles[i][1] += particles[i][4] * dt
        particles[i][2] += particles[i][5] * dt
        particles[i][3] += particles[i][6] * dt
        particles[i][5] -= 4.0 * dt
        particles[i][7] -= dt
        if particles[i][7] <= 0
            del(particles, i)
        else
            i += 1
        ok
    end

// =============================================================
// Camera Positioning
// =============================================================

func snake_positionCamera
    hx = snakeBody[1][1] * CELL_SZ + CELL_SZ / 2
    hz = snakeBody[1][2] * CELL_SZ + CELL_SZ / 2
    arenaCenter = GRID_SIZE * CELL_SZ / 2

    if cameraMode = CAM_FOLLOW
        // Fixed angle: always behind (+Z) and above the snake head
        // This keeps controls consistent: UP=forward(-Z), DOWN=back(+Z)
        camH = 14
        goalX = hx
        goalZ = hz + 12

        // Responsive lerp
        camPosX += (goalX - camPosX) * 0.12
        camPosY += (camH  - camPosY) * 0.12
        camPosZ += (goalZ - camPosZ) * 0.12

        camTgtX += (hx - camTgtX) * 0.15
        camTgtY = 0.5
        camTgtZ += (hz - camTgtZ) * 0.15
    ok

    if cameraMode = CAM_TOPDOWN
        camPosX += (arenaCenter       - camPosX) * 0.08
        camPosY += (GRID_SIZE * 1.6   - camPosY) * 0.08
        camPosZ += (arenaCenter + 0.1 - camPosZ) * 0.08
        camTgtX += (arenaCenter - camTgtX) * 0.08
        camTgtY = 0
        camTgtZ += (arenaCenter - camTgtZ) * 0.08
    ok

    if cameraMode = CAM_ISOMETRIC
        isoX = arenaCenter + GRID_SIZE * 0.9
        isoY = GRID_SIZE * CELL_SZ * 0.8
        isoZ = arenaCenter + GRID_SIZE * 0.9
        camPosX += (isoX - camPosX) * 0.06
        camPosY += (isoY - camPosY) * 0.06
        camPosZ += (isoZ - camPosZ) * 0.06
        camTgtX += (arenaCenter - camTgtX) * 0.06
        camTgtY = 0
        camTgtZ += (arenaCenter - camTgtZ) * 0.06
    ok

    camera.position.x = camPosX
    camera.position.y = camPosY
    camera.position.z = camPosZ
    camera.target.x   = camTgtX
    camera.target.y   = camTgtY
    camera.target.z   = camTgtZ

// =============================================================
// 3D Drawing: Arena
// =============================================================

func snake_drawArena
    arenaW = GRID_SIZE * CELL_SZ
    halfCell = CELL_SZ / 2

    // Floor plane
    DrawPlane(
        Vector3(arenaW / 2, -0.01, arenaW / 2),
        Vector2(arenaW, arenaW),
        RAYLIBColor(25, 30, 40, 255)
    )

    // Grid lines
    for i = 0 to GRID_SIZE
        linePos = i * CELL_SZ
        DrawLine3D(
            Vector3(0, 0.005, linePos),
            Vector3(arenaW, 0.005, linePos),
            RAYLIBColor(40, 50, 60, 255)
        )
        DrawLine3D(
            Vector3(linePos, 0.005, 0),
            Vector3(linePos, 0.005, arenaW),
            RAYLIBColor(40, 50, 60, 255)
        )
    next

    // Checkerboard pattern
    for r = 0 to GRID_SIZE - 1
        for c = 0 to GRID_SIZE - 1
            if (r + c) % 2 = 0
                DrawCube(
                    Vector3(c * CELL_SZ + halfCell, -0.005, r * CELL_SZ + halfCell),
                    CELL_SZ, 0.01, CELL_SZ,
                    RAYLIBColor(30, 35, 48, 255)
                )
            ok
        next
    next

    // Border walls
    wallCol  = RAYLIBColor(50, 65, 90, 255)
    wireCol  = RAYLIBColor(70, 90, 130, 255)
    wallY    = WALL_H / 2
    thick    = 0.3

    // North wall (z = 0)
    DrawCube(Vector3(arenaW/2, wallY, -thick/2), arenaW + thick*2, WALL_H, thick, wallCol)
    DrawCubeWires(Vector3(arenaW/2, wallY, -thick/2), arenaW + thick*2, WALL_H, thick, wireCol)
    // South wall
    DrawCube(Vector3(arenaW/2, wallY, arenaW + thick/2), arenaW + thick*2, WALL_H, thick, wallCol)
    DrawCubeWires(Vector3(arenaW/2, wallY, arenaW + thick/2), arenaW + thick*2, WALL_H, thick, wireCol)
    // West wall (x = 0)
    DrawCube(Vector3(-thick/2, wallY, arenaW/2), thick, WALL_H, arenaW + thick*2, wallCol)
    DrawCubeWires(Vector3(-thick/2, wallY, arenaW/2), thick, WALL_H, arenaW + thick*2, wireCol)
    // East wall
    DrawCube(Vector3(arenaW + thick/2, wallY, arenaW/2), thick, WALL_H, arenaW + thick*2, wallCol)
    DrawCubeWires(Vector3(arenaW + thick/2, wallY, arenaW/2), thick, WALL_H, arenaW + thick*2, wireCol)

    // Corner pillars
    pillarCol = RAYLIBColor(70, 80, 110, 255)
    ps = 0.5
    DrawCube(Vector3(-ps/2,        wallY+0.2, -ps/2),        ps, WALL_H+0.4, ps, pillarCol)
    DrawCube(Vector3(arenaW+ps/2,  wallY+0.2, -ps/2),        ps, WALL_H+0.4, ps, pillarCol)
    DrawCube(Vector3(-ps/2,        wallY+0.2, arenaW+ps/2),  ps, WALL_H+0.4, ps, pillarCol)
    DrawCube(Vector3(arenaW+ps/2,  wallY+0.2, arenaW+ps/2),  ps, WALL_H+0.4, ps, pillarCol)

// =============================================================
// 3D Drawing: Snake
// =============================================================

func snake_drawSnake
    bodyLen = len(snakeBody)
    for i = 1 to bodyLen
        // Current grid position in world space
        cx = snakeBody[i][1] * CELL_SZ + CELL_SZ / 2
        cz = snakeBody[i][2] * CELL_SZ + CELL_SZ / 2

        // Previous grid position for interpolation
        if i <= len(prevBody)
            px = prevBody[i][1] * CELL_SZ + CELL_SZ / 2
            pz = prevBody[i][2] * CELL_SZ + CELL_SZ / 2
        else
            px = cx
            pz = cz
        ok

        // Lerp between previous and current
        wx = px + (cx - px) * interpFactor
        wz = pz + (cz - pz) * interpFactor
        wy = SPHERE_RAD

        if i = 1
            // ===== HEAD =====
            wy += 0.08 + sin(animTime * 4.0) * 0.05

            // Main head sphere (bright green)
            DrawSphereEx(
                Vector3(wx, wy, wz),
                SPHERE_RAD + 0.05, 16, 16,
                RAYLIBColor(50, 220, 80, 255)
            )
            // Glow aura
            DrawSphereEx(
                Vector3(wx, wy, wz),
                SPHERE_RAD + 0.18, 10, 10,
                RAYLIBColor(80, 255, 120, 45)
            )

            // Eyes depend on direction
            eOff = 0.25
            eRad = 0.12
            pRad = 0.07
            ex1 = 0  ez1 = 0  ex2 = 0  ez2 = 0

            if snakeDir = DIR_RIGHT
                ex1 = 0.15  ez1 = -eOff  ex2 = 0.15  ez2 = eOff
            ok
            if snakeDir = DIR_LEFT
                ex1 = -0.15  ez1 = -eOff  ex2 = -0.15  ez2 = eOff
            ok
            if snakeDir = DIR_UP
                ex1 = -eOff  ez1 = -0.15  ex2 = eOff  ez2 = -0.15
            ok
            if snakeDir = DIR_DOWN
                ex1 = -eOff  ez1 = 0.15  ex2 = eOff  ez2 = 0.15
            ok

            // White of eyes
            DrawSphere(Vector3(wx + ex1, wy + 0.15, wz + ez1), eRad, WHITE)
            DrawSphere(Vector3(wx + ex2, wy + 0.15, wz + ez2), eRad, WHITE)
            // Pupils
            DrawSphere(Vector3(wx + ex1*1.3, wy + 0.15, wz + ez1*1.3), pRad, BLACK)
            DrawSphere(Vector3(wx + ex2*1.3, wy + 0.15, wz + ez2*1.3), pRad, BLACK)

            // Tongue (flicking red line in movement direction)
            tongueLen = 0.3 + sin(animTime * 8.0) * 0.15
            tdx = 0  tdz = 0
            if snakeDir = DIR_RIGHT tdx = 1   ok
            if snakeDir = DIR_LEFT  tdx = -1  ok
            if snakeDir = DIR_UP    tdz = -1  ok
            if snakeDir = DIR_DOWN  tdz = 1   ok
            DrawLine3D(
                Vector3(wx + tdx * 0.5, wy - 0.05, wz + tdz * 0.5),
                Vector3(wx + tdx * (0.5 + tongueLen), wy - 0.08, wz + tdz * (0.5 + tongueLen)),
                RAYLIBColor(255, 50, 50, 220)
            )

            // Head shadow
            DrawCircle3D(
                Vector3(wx, 0.01, wz),
                SPHERE_RAD + 0.2,
                Vector3(1, 0, 0), 90.0,
                RAYLIBColor(0, 0, 0, 60)
            )

        else
            // ===== BODY SEGMENTS =====
            // Color gradient: bright green -> teal -> dark blue toward tail
            ratio = (i - 1.0) / bodyLen
            sr = 30  + floor((20  - 30)  * ratio)
            sg = 200 + floor((100 - 200) * ratio)
            sb = 60  + floor((180 - 60)  * ratio)

            // Segments taper toward tail
            segRad = SPHERE_RAD - (ratio * 0.15)
            if segRad < 0.25 segRad = 0.25 ok

            // Gentle bobbing wave along body
            wy += sin(animTime * 3.0 + i * 0.5) * 0.03

            DrawSphereEx(
                Vector3(wx, wy, wz),
                segRad, 12, 12,
                RAYLIBColor(sr, sg, sb, 255)
            )

            // Wire highlight on every other segment
            if i % 2 = 0
                DrawSphereWires(
                    Vector3(wx, wy, wz),
                    segRad + 0.02, 6, 6,
                    RAYLIBColor(sr + 40, sg + 30, sb + 20, 70)
                )
            ok

            // Body shadow
            DrawCircle3D(
                Vector3(wx, 0.01, wz),
                segRad + 0.1,
                Vector3(1, 0, 0), 90.0,
                RAYLIBColor(0, 0, 0, 30)
            )
        ok
    next

// =============================================================
// 3D Drawing: Food
// =============================================================

func snake_drawFood
    if !foodActive return ok

    wx = foodX * CELL_SZ + CELL_SZ / 2
    wz = foodZ * CELL_SZ + CELL_SZ / 2
    wy = FOOD_RAD + 0.1 + sin(animTime * 4.0) * 0.15

    // Main food sphere (red)
    DrawSphereEx(
        Vector3(wx, wy, wz),
        FOOD_RAD + sin(animTime * 3.0) * 0.05, 12, 12,
        RAYLIBColor(255, 60, 60, 255)
    )

    // Outer glow
    DrawSphereEx(
        Vector3(wx, wy, wz),
        FOOD_RAD + 0.2 + sin(animTime * 5.0) * 0.08, 8, 8,
        RAYLIBColor(255, 100, 50, 40)
    )

    // Spinning ring
    DrawCircle3D(
        Vector3(wx, wy, wz),
        FOOD_RAD + 0.3,
        Vector3(0, 1, 0), animTime * 120,
        RAYLIBColor(255, 80, 50, 150)
    )

    // Ground glow
    DrawCircle3D(
        Vector3(wx, 0.02, wz),
        0.5 + sin(animTime * 3.0) * 0.1,
        Vector3(1, 0, 0), 90.0,
        RAYLIBColor(255, 50, 30, 50)
    )

func snake_drawBonusFood
    if !bonusActive return ok

    wx = bonusX * CELL_SZ + CELL_SZ / 2
    wz = bonusZ * CELL_SZ + CELL_SZ / 2
    wy = 0.5 + sin(animTime * 5.0) * 0.2

    // Blink when about to expire
    if bonusTimer < 3.0
        if floor(animTime * 6) % 2 = 0 return ok
    ok

    // Golden sphere
    DrawSphereEx(
        Vector3(wx, wy, wz),
        0.35 + sin(animTime * 4.0) * 0.05, 8, 8,
        RAYLIBColor(255, 215, 0, 255)
    )
    // Golden glow
    DrawSphereEx(
        Vector3(wx, wy, wz),
        0.55, 6, 6,
        RAYLIBColor(255, 230, 50, 50)
    )
    // Double spinning rings
    DrawCircle3D(
        Vector3(wx, wy, wz),
        0.6, Vector3(0, 1, 0), animTime * 180,
        RAYLIBColor(255, 215, 0, 200)
    )
    DrawCircle3D(
        Vector3(wx, wy, wz),
        0.5, Vector3(1, 0, 0), animTime * 150,
        RAYLIBColor(255, 240, 100, 150)
    )
    // Ground glow
    DrawCircle3D(
        Vector3(wx, 0.02, wz),
        0.6, Vector3(1, 0, 0), 90.0,
        RAYLIBColor(255, 200, 0, 60)
    )

// =============================================================
// 3D Drawing: Particles
// =============================================================

func snake_drawParticles3D
    for i = 1 to len(particles)
        p = particles[i]
        alpha = floor((p[7] / 1.5) * 255)
        if alpha > 255 alpha = 255 ok
        if alpha < 0 alpha = 0 ok
        sz = 0.08 + p[7] * 0.12
        DrawSphereEx(
            Vector3(p[1], p[2], p[3]),
            sz, 4, 4,
            RAYLIBColor(p[8], p[9], p[10], alpha)
        )
    next

// =============================================================
// 3D Drawing: Light Orbs (decorative)
// =============================================================

func snake_drawLightOrbs
    arenaW = GRID_SIZE * CELL_SZ
    h = WALL_H + 1.5

    // Corner lights
    snake_drawOneOrb(1, h, 1,              200, 220, 255)
    snake_drawOneOrb(arenaW - 1, h, 1,     255, 200, 150)
    snake_drawOneOrb(1, h, arenaW - 1,     150, 255, 200)
    snake_drawOneOrb(arenaW - 1, h, arenaW - 1, 255, 150, 200)
    // Center light
    snake_drawOneOrb(arenaW/2, h + 1, arenaW/2, 255, 255, 220)

func snake_drawOneOrb lx, ly, lz, lr, lg, lb
    DrawSphere(Vector3(lx, ly, lz), 0.15, RAYLIBColor(lr, lg, lb, 255))
    DrawSphereEx(Vector3(lx, ly, lz), 0.4, 6, 6, RAYLIBColor(lr, lg, lb, 35))

// =============================================================
// HUD
// =============================================================

func snake_drawHUD
    // Top-left info panel
    DrawRectangle(10, 30, 230, 115, Fade(BLACK, 0.75))
    DrawRectangleLines(10, 30, 230, 115, RAYLIBColor(50, 200, 120, 200))

    DrawText("3D SNAKE", 20, 38, 20, RAYLIBColor(50, 220, 80, 255))
    DrawText("Score: " + score, 20, 63, 18, RAYLIBColor(200, 220, 255, 255))
    DrawText("Best:  " + highScore, 20, 85, 16, RAYLIBColor(255, 215, 0, 220))
    DrawText("Length: " + len(snakeBody), 20, 107, 16, RAYLIBColor(180, 200, 220, 200))
    DrawText("Speed:  " + (100 - floor(moveInterval * 500)) + "%", 20, 125, 14, RAYLIBColor(150, 180, 210, 180))

    // Camera mode (bottom left)
    camName = "FOLLOW"
    if cameraMode = CAM_TOPDOWN    camName = "TOP-DOWN"  ok
    if cameraMode = CAM_ISOMETRIC  camName = "ISOMETRIC" ok
    DrawRectangle(10, SCREEN_H - 60, 210, 25, Fade(BLACK, 0.6))
    DrawText("Cam: " + camName + "  [C] switch", 16, SCREEN_H - 56, 14, RAYLIBColor(150, 180, 210, 220))

    // Controls reminder (bottom right)
    DrawRectangle(SCREEN_W - 275, SCREEN_H - 35, 265, 25, Fade(BLACK, 0.6))
    DrawText("WASD/Arrows | P: Pause | R: Restart", SCREEN_W - 270, SCREEN_H - 30, 13,
             RAYLIBColor(150, 160, 180, 200))

    // Bonus timer bar
    if bonusActive
        barW = 160
        DrawRectangle(SCREEN_W / 2 - barW/2, 35, barW, 28, Fade(BLACK, 0.7))
        DrawRectangleLines(SCREEN_W / 2 - barW/2, 35, barW, 28, RAYLIBColor(255, 215, 0, 200))
        // Timer fill bar
        fillW = floor((bonusTimer / BONUS_DURATION) * (barW - 8))
        if fillW > 0
            DrawRectangle(SCREEN_W / 2 - barW/2 + 4, 39, fillW, 20, RAYLIBColor(255, 215, 0, 100))
        ok
        bText = "BONUS " + floor(bonusTimer) + "s (+50)"
        DrawText(bText, SCREEN_W / 2 - barW/2 + 10, 41, 16, RAYLIBColor(255, 215, 0, 255))
    ok

// =============================================================
// Mini-Map
// =============================================================

func snake_drawMiniMap
    mapSz = 140
    mapX = SCREEN_W - mapSz - 15
    mapY = 30
    cellW = mapSz / GRID_SIZE
    cellH = mapSz / GRID_SIZE

    // Background
    DrawRectangle(mapX - 2, mapY - 2, mapSz + 4, mapSz + 4, Fade(BLACK, 0.8))
    DrawRectangleLines(mapX - 2, mapY - 2, mapSz + 4, mapSz + 4, RAYLIBColor(50, 200, 120, 200))
    DrawRectangle(mapX, mapY, mapSz, mapSz, RAYLIBColor(25, 30, 40, 200))

    // Draw snake body (tail first so head draws on top)
    for i = len(snakeBody) to 1 step -1
        sx = mapX + snakeBody[i][1] * cellW
        sy = mapY + snakeBody[i][2] * cellH
        if i = 1
            // Head: bright green
            DrawRectangle(sx, sy, cellW + 1, cellH + 1, RAYLIBColor(80, 255, 120, 255))
        else
            // Body: gradient color
            ratio = (i - 1.0) / len(snakeBody)
            mr = 30  + floor((20  - 30)  * ratio)
            mg = 200 + floor((100 - 200) * ratio)
            mb = 60  + floor((180 - 60)  * ratio)
            DrawRectangle(sx, sy, cellW + 1, cellH + 1, RAYLIBColor(mr, mg, mb, 220))
        ok
    next

    // Food on minimap
    fx = mapX + foodX * cellW
    fy = mapY + foodZ * cellH
    DrawRectangle(fx, fy, cellW + 1, cellH + 1, RAYLIBColor(255, 60, 60, 255))

    // Bonus on minimap
    if bonusActive
        bx = mapX + bonusX * cellW
        by = mapY + bonusZ * cellH
        DrawRectangle(bx, by, cellW + 1, cellH + 1, RAYLIBColor(255, 215, 0, 255))
    ok

    DrawText("MAP", mapX + mapSz/2 - 15, mapY - 15, 12, RAYLIBColor(150, 200, 180, 200))

// =============================================================
// Title Screen
// =============================================================

func snake_drawTitleScreen
    DrawRectangleGradientV(0, 0, SCREEN_W, SCREEN_H,
        RAYLIBColor(8, 15, 25, 255), RAYLIBColor(15, 30, 20, 255))

    // Title
    t1 = "3D SNAKE GAME"
    t1w = MeasureText(t1, 60)
    DrawText(t1, (SCREEN_W - t1w)/2, 150, 60, RAYLIBColor(50, 220, 80, 255))

    // Subtitle
    t2 = "~ Eat food ~ Grow longer ~ Don't crash! ~"
    t2w = MeasureText(t2, 18)
    DrawText(t2, (SCREEN_W - t2w)/2, 225, 18, RAYLIBColor(100, 200, 150, 230))

    // Controls info
    cy = 275
    cLines = [
        "Arrow Keys / WASD  -  Change direction",
        "  UP/W = Forward   DOWN/S = Backward",
        "  LEFT/A = Left    RIGHT/D = Right",
        "P  -  Pause game",
        "C  -  Cycle camera (Follow / Top-Down / Isometric)",
        "R  -  Restart at any time",
        "",
        "Red food = +10 points",
        "Golden bonus food = +50 points (limited time!)",
        "Snake speeds up as it grows - good luck!"
    ]
    for i = 1 to len(cLines)
        lw = MeasureText(cLines[i], 16)
        if i >= 6
            col = RAYLIBColor(255, 200, 100, 220)
        else
            col = RAYLIBColor(160, 190, 210, 230)
        ok
        DrawText(cLines[i], (SCREEN_W - lw)/2, cy + (i - 1) * 26, 16, col)
    next

    // Blinking start prompt
    if floor(animTime * 2) % 2 = 0
        st = "Press ENTER or SPACE to Start"
        stw = MeasureText(st, 26)
        DrawText(st, (SCREEN_W - stw)/2, 520, 26, WHITE)
    ok

    // Credit
    cr = "Developed using Ring Language + RingRayLib"
    crw = MeasureText(cr, 14)
    DrawText(cr, (SCREEN_W - crw)/2, SCREEN_H - 40, 14, RAYLIBColor(100, 120, 100, 180))

// =============================================================
// Pause Overlay
// =============================================================

func snake_drawPauseOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.55))

    pt = "PAUSED"
    ptw = MeasureText(pt, 50)
    DrawText(pt, (SCREEN_W - ptw)/2, SCREEN_H/2 - 50, 50, RAYLIBColor(200, 220, 255, 255))

    pt2 = "Press P or SPACE to resume"
    pt2w = MeasureText(pt2, 20)
    DrawText(pt2, (SCREEN_W - pt2w)/2, SCREEN_H/2 + 20, 20, RAYLIBColor(150, 170, 200, 220))

// =============================================================
// Game Over Screen
// =============================================================

func snake_drawGameOver
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.65))

    // Title
    g1 = "GAME OVER"
    g1w = MeasureText(g1, 55)
    DrawText(g1, (SCREEN_W - g1w)/2, 200, 55, RAYLIBColor(255, 60, 60, 255))

    // Stats
    sy = 280
    s1 = "Score: " + score
    s2 = "Length: " + len(snakeBody)
    s3 = "High Score: " + highScore

    s1w = MeasureText(s1, 26)
    s2w = MeasureText(s2, 26)
    s3w = MeasureText(s3, 26)

    DrawText(s1, (SCREEN_W - s1w)/2, sy,      26, RAYLIBColor(200, 220, 255, 255))
    DrawText(s2, (SCREEN_W - s2w)/2, sy + 38,  26, RAYLIBColor(200, 220, 255, 255))
    DrawText(s3, (SCREEN_W - s3w)/2, sy + 76,  26, RAYLIBColor(255, 215, 0, 255))

    // New high score indicator
    if score = highScore
        if score > 0
            nh = "*** NEW HIGH SCORE! ***"
            nhw = MeasureText(nh, 22)
            DrawText(nh, (SCREEN_W - nhw)/2, sy + 115, 22, RAYLIBColor(255, 215, 0, 255))
        ok
    ok

    // Restart prompt
    if floor(animTime * 2) % 2 = 0
        rt = "Press ENTER or SPACE to play again"
        rtw = MeasureText(rt, 20)
        DrawText(rt, (SCREEN_W - rtw)/2, sy + 160, 20, WHITE)
    ok
