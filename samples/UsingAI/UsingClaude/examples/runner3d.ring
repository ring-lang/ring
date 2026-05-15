/*
**  3D Endless Runner - Using RingRayLib
**  ======================================
**  Run endlessly through a 3D world! Dodge obstacles, collect
**  coins and power-ups while the speed keeps increasing.
**
**  Controls:
**    Left/Right or A/D  -  Switch lanes
**    Up or W or Space   -  Jump
**    Down or S          -  Slide (duck)
**    C                  -  Cycle camera views
**    P                  -  Pause / Unpause
**    R                  -  Restart (any time)
**    ESC                -  Exit
**
**  Features:
**    - Three-lane running system with smooth lane switching
**    - Jump and slide mechanics to dodge obstacles
**    - Procedurally generated obstacles, coins, and power-ups
**    - Speed gradually increases over time
**    - Coin magnet and shield power-ups
**    - Particle effects on collection and death
**    - Three camera modes: Chase / High / Side
**    - Score, high score, coins, and distance tracking
**    - Start, pause, and game-over screens
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W        = 1024
SCREEN_H        = 768

// Lanes
LANE_COUNT      = 3
LANE_WIDTH      = 3.0         // Width of each lane
LANE_LEFT       = 1
LANE_CENTER     = 2
LANE_RIGHT      = 3

// Player
PLAYER_RAD      = 0.6
PLAYER_Y_BASE   = 0.7        // Standing height (center of sphere)
JUMP_FORCE      = 12.0
GRAVITY         = 28.0
SLIDE_DURATION  = 0.6
SLIDE_SCALE     = 0.35        // Squash scale when sliding

// World
TILE_LENGTH     = 8.0         // Length of each road tile
TILE_COUNT      = 16          // Tiles visible ahead
ROAD_Y          = 0.0

// Obstacles
OBS_NONE        = 0
OBS_BARRIER     = 1           // Tall barrier - jump over
OBS_LOW_BAR     = 2           // Low bar - slide under
OBS_CRATE       = 3           // Crate - switch lanes

// Collectibles
COL_NONE        = 0
COL_COIN        = 1
COL_MAGNET      = 2           // Coin magnet power-up
COL_SHIELD      = 3           // Shield power-up

// Game states
ST_START        = 1
ST_PLAYING      = 2
ST_PAUSED       = 3
ST_GAMEOVER     = 4

// Camera modes
CAM_CHASE       = 1
CAM_HIGH        = 2
CAM_SIDE        = 3
CAM_COUNT       = 3

// Speed
BASE_SPEED      = 12.0
MAX_SPEED       = 35.0
SPEED_ACCEL     = 0.15        // Speed increase per second

// Spawn
MIN_SPAWN_GAP   = 3           // Minimum tiles between obstacles
COIN_CHANCE     = 45          // Percent chance for coin row per tile
OBS_CHANCE      = 35          // Percent chance for obstacle per tile

// =============================================================
// Global Variables
// =============================================================

// Player state
playerLane      = LANE_CENTER
targetLane      = LANE_CENTER
playerX         = 0.0         // Actual X position (smooth lerp)
playerY         = PLAYER_Y_BASE
playerVY        = 0.0         // Vertical velocity
isJumping       = false
isSliding       = false
slideTimer      = 0.0
isAlive         = true

// Power-ups
hasMagnet       = false
magnetTimer     = 0.0
MAGNET_DUR      = 6.0
hasShield       = false
shieldTimer     = 0.0
SHIELD_DUR      = 8.0

// World scrolling
scrollZ         = 0.0         // How far player has traveled
runSpeed        = BASE_SPEED

// Road tiles: track which tiles exist
tileStartIdx    = 0           // Index of first visible tile

// Obstacles: list of [tileIndex, lane, type, active]
obstacles       = []
lastObsTile     = 0

// Collectibles: list of [tileIndex, lane, type, active, floatZ_offset]
collectibles    = []

// Particles: [x, y, z, vx, vy, vz, life, r, g, b]
particles       = []

// Stats
score           = 0
highScore       = 0
coins           = 0
totalCoins      = 0
distance        = 0.0

// Game state
gameState       = ST_START
animTime        = 0.0
cameraMode      = CAM_CHASE

// Camera smoothing
camPosX = 0.0    camPosY = 5.0   camPosZ = -8.0
camTgtX = 0.0    camTgtY = 1.5   camTgtZ = 10.0

// Shake effect on hit
shakeTimer      = 0.0
shakeIntensity  = 0.0

// Lane switch animation
laneSwitchSpeed = 10.0

// =============================================================
// Main Program - All executable code before functions
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Ring 3D Endless Runner - RingRayLib")
SetTargetFPS(60)

camera = Camera3D(
    0, 5, -8,
    0, 1.5, 10,
    0, 1, 0,
    55,
    CAMERA_PERSPECTIVE
)

run_resetGame()

// =============================================================
// Main Game Loop
// =============================================================

while !WindowShouldClose()

    dt = GetFrameTime()
    if dt > 0.05 dt = 0.05 ok
    animTime += dt

    // --- Global input ---
    if IsKeyPressed(KEY_C)
        cameraMode += 1
        if cameraMode > CAM_COUNT cameraMode = CAM_CHASE ok
    ok

    if IsKeyPressed(KEY_R)
        run_resetGame()
        gameState = ST_PLAYING
    ok

    // --- State updates ---
    if gameState = ST_START
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            run_resetGame()
            gameState = ST_PLAYING
        ok
        // Gentle scroll for background effect
        scrollZ += BASE_SPEED * 0.3 * dt
    ok

    stateHandled = false

    if gameState = ST_PLAYING and !stateHandled
        if IsKeyPressed(KEY_P)
            gameState = ST_PAUSED
            stateHandled = true
        else
            run_handleInput()
            run_updatePlayer(dt)
            run_updateWorld(dt)
            run_updateCollisions()
            run_updatePowerups(dt)
            run_updateParticles(dt)
        ok
    ok

    if gameState = ST_PAUSED and !stateHandled
        if IsKeyPressed(KEY_P) or IsKeyPressed(KEY_SPACE)
            gameState = ST_PLAYING
            stateHandled = true
        ok
    ok

    if gameState = ST_GAMEOVER and !stateHandled
        run_updateParticles(dt)
        if shakeTimer > 0
            shakeTimer -= dt
        ok
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            run_resetGame()
            gameState = ST_PLAYING
        ok
    ok

    run_positionCamera(dt)

    // --- Drawing ---
    BeginDrawing()
        ClearBackground(RAYLIBColor(15, 15, 25, 255))

        if gameState = ST_START
            run_drawTitleScreen()
        else
            BeginMode3D(camera)
                run_drawRoad()
                run_drawScenery()
                run_drawObstacles()
                run_drawCollectibles()
                run_drawPlayer()
                run_drawParticles3D()
            EndMode3D()

            run_drawHUD()

            if gameState = ST_PAUSED
                run_drawPauseOverlay()
            ok
            if gameState = ST_GAMEOVER
                run_drawGameOverScreen()
            ok
        ok

        DrawFPS(10, 10)
    EndDrawing()

end

CloseWindow()

// =============================================================
// =============================================================
// ALL FUNCTIONS BELOW
// =============================================================
// =============================================================

// =============================================================
// Reset Game
// =============================================================

func run_resetGame
    playerLane    = LANE_CENTER
    targetLane    = LANE_CENTER
    playerX       = 0.0
    playerY       = PLAYER_Y_BASE
    playerVY      = 0.0
    isJumping     = false
    isSliding     = false
    slideTimer    = 0.0
    isAlive       = true

    hasMagnet     = false
    magnetTimer   = 0.0
    hasShield     = false
    shieldTimer   = 0.0

    scrollZ       = 0.0
    runSpeed      = BASE_SPEED
    tileStartIdx  = 0

    obstacles     = []
    collectibles  = []
    particles     = []
    lastObsTile   = 0

    score         = 0
    coins         = 0
    distance      = 0.0

    shakeTimer    = 0.0
    shakeIntensity = 0.0

    // Pre-generate the first stretch (no obstacles for first few tiles)
    for i = 5 to TILE_COUNT + 10
        run_trySpawnOnTile(i)
    next

// =============================================================
// Input Handling
// =============================================================

func run_handleInput
    // Lane switching
    if IsKeyPressed(KEY_LEFT) or IsKeyPressed(KEY_A)
        if targetLane > LANE_LEFT
            targetLane -= 1
        ok
    ok
    if IsKeyPressed(KEY_RIGHT) or IsKeyPressed(KEY_D)
        if targetLane < LANE_RIGHT
            targetLane += 1
        ok
    ok

    // Jump
    if IsKeyPressed(KEY_UP) or IsKeyPressed(KEY_W) or IsKeyPressed(KEY_SPACE)
        if !isJumping and !isSliding
            isJumping = true
            playerVY  = JUMP_FORCE
        ok
    ok

    // Slide
    if IsKeyPressed(KEY_DOWN) or IsKeyPressed(KEY_S)
        if !isJumping and !isSliding
            isSliding  = true
            slideTimer = SLIDE_DURATION
        ok
    ok

// =============================================================
// Player Update
// =============================================================

func run_updatePlayer dt
    // Lane position smoothing (negated so left=screen-left, right=screen-right)
    goalX = (LANE_CENTER - targetLane) * LANE_WIDTH
    playerX += (goalX - playerX) * laneSwitchSpeed * dt

    // Jump physics
    if isJumping
        playerVY -= GRAVITY * dt
        playerY  += playerVY * dt
        if playerY <= PLAYER_Y_BASE
            playerY  = PLAYER_Y_BASE
            playerVY = 0.0
            isJumping = false
        ok
    ok

    // Slide timer
    if isSliding
        slideTimer -= dt
        if slideTimer <= 0
            isSliding  = false
            slideTimer = 0.0
        ok
    ok

    // Speed increases over time
    runSpeed += SPEED_ACCEL * dt
    if runSpeed > MAX_SPEED runSpeed = MAX_SPEED ok

    // Advance world
    scrollZ  += runSpeed * dt
    distance += runSpeed * dt

    // Score based on distance
    score = floor(distance * 2)

// =============================================================
// World Update - Spawn/Despawn
// =============================================================

func run_updateWorld dt
    // Current tile index player is on
    currentTile = floor(scrollZ / TILE_LENGTH)

    // Spawn new content ahead
    aheadTile = currentTile + TILE_COUNT
    for t = lastObsTile + 1 to aheadTile
        if t > currentTile + 3
            run_trySpawnOnTile(t)
        ok
    next
    if aheadTile > lastObsTile lastObsTile = aheadTile ok

    // Despawn old obstacles behind player
    i = 1
    while i <= len(obstacles)
        tileZ = obstacles[i][1] * TILE_LENGTH
        if tileZ < scrollZ - TILE_LENGTH * 2
            del(obstacles, i)
        else
            i += 1
        ok
    end

    // Despawn old collectibles
    i = 1
    while i <= len(collectibles)
        tileZ = collectibles[i][1] * TILE_LENGTH
        if tileZ < scrollZ - TILE_LENGTH * 2
            del(collectibles, i)
        else
            i += 1
        ok
    end

func run_trySpawnOnTile tileIdx
    // Random obstacle
    if GetRandomValue(1, 100) <= OBS_CHANCE
        lane = GetRandomValue(1, 3)
        obsType = GetRandomValue(1, 3)
        add(obstacles, [tileIdx, lane, obsType, true])
    ok

    // Random coins (can appear on any lane)
    if GetRandomValue(1, 100) <= COIN_CHANCE
        coinLane = GetRandomValue(1, 3)
        // Row of coins along this tile
        add(collectibles, [tileIdx, coinLane, COL_COIN, true, 0.0])
        // Sometimes add a second coin in adjacent lane
        if GetRandomValue(1, 100) <= 30
                adjLane = coinLane + 1
                if coinLane >= 3 adjLane = coinLane - 1 ok
                add(collectibles, [tileIdx, adjLane, COL_COIN, true, 0.3])
            ok
    ok

    // Rare power-up
    if GetRandomValue(1, 100) <= 5
        puLane = GetRandomValue(1, 3)
        puType = COL_MAGNET
        if GetRandomValue(1, 2) = 2 puType = COL_SHIELD ok
        add(collectibles, [tileIdx, puLane, puType, true, 0.0])
    ok

// =============================================================
// Collision Detection
// =============================================================

func run_updateCollisions
    pLane = targetLane
    pz = scrollZ
    px = playerX
    pTopY = playerY + PLAYER_RAD
    pBotY = playerY - PLAYER_RAD
    if isSliding
        pTopY = PLAYER_RAD * SLIDE_SCALE * 2
    ok

    // Check obstacles
    for i = 1 to len(obstacles)
        if !obstacles[i][4] loop ok

        obsZ = obstacles[i][1] * TILE_LENGTH + TILE_LENGTH / 2
        obsLane = obstacles[i][2]
        obsType = obstacles[i][3]

        // Z distance check (tight hitbox)
        dz = obsZ - pz
        if dz < -1.0 or dz > 1.5 loop ok

        // Lane check — primary: discrete lane match
        // Secondary: X distance for mid-transition safety
        obsX = (LANE_CENTER - obsLane) * LANE_WIDTH
        dx = fabs(px - obsX)
        // Only collide if player center is within half a lane of obstacle center
        // LANE_WIDTH=3.0, so threshold = 1.2 (player radius + small margin)
        if dx > 1.3 loop ok

        // Type-specific collision
        hit = false

        if obsType = OBS_BARRIER
            // Tall barrier (height ~2.5): must jump over
            // Player clears if their bottom is above the barrier top
            if pBotY < 2.2
                hit = true
            ok
        ok
        if obsType = OBS_LOW_BAR
            // Low bar at Y=1.5: slide under OR jump over
            // Bar bottom = 1.5 - 0.125 = 1.375
            // Player standing top = 1.3 < 1.375 => can walk under!
            // Player sliding top  = 0.42 < 1.375 => safe
            // Player jump bottom  = 2.67 > 1.625 => safe
            barBot = 1.375
            barTop2 = 1.625
            if pTopY > barBot and pBotY < barTop2
                hit = true
            ok
        ok
        if obsType = OBS_CRATE
            // Crate (height ~1.5): jump over or avoid lane
            if pBotY < 1.4
                hit = true
            ok
        ok

        if hit
            if hasShield
                // Shield absorbs hit
                hasShield = false
                shieldTimer = 0.0
                obstacles[i][4] = false
                run_spawnParticles(obsX, 1.0, obsZ, 100, 180, 255)
                shakeTimer = 0.15
                shakeIntensity = 0.3
            else
                run_die()
                return
            ok
        ok
    next

    // Check collectibles
    for i = 1 to len(collectibles)
        if !collectibles[i][4] loop ok

        colZ = collectibles[i][1] * TILE_LENGTH + TILE_LENGTH / 2 + collectibles[i][5] * TILE_LENGTH
        colLane = collectibles[i][2]
        colType = collectibles[i][3]

        dz = colZ - pz
        magnetRange = 1.5
        if hasMagnet magnetRange = 5.0 ok

        if fabs(dz) > magnetRange loop ok

        colX = (LANE_CENTER - colLane) * LANE_WIDTH
        dx = fabs(px - colX)

        collectRange = LANE_WIDTH * 0.7
        if hasMagnet collectRange = LANE_WIDTH * 2.5 ok

        if dx > collectRange loop ok

        // Collect!
        collectibles[i][4] = false

        if colType = COL_COIN
            coins += 1
            totalCoins += 1
            score += 25
            run_spawnParticles(colX, 1.2, colZ, 255, 215, 0)
        ok
        if colType = COL_MAGNET
            hasMagnet = true
            magnetTimer = MAGNET_DUR
            run_spawnParticles(colX, 1.2, colZ, 180, 80, 255)
        ok
        if colType = COL_SHIELD
            hasShield = true
            shieldTimer = SHIELD_DUR
            run_spawnParticles(colX, 1.2, colZ, 80, 200, 255)
        ok
    next

func run_die
    isAlive = false
    gameState = ST_GAMEOVER
    if score > highScore highScore = score ok
    shakeTimer = 0.4
    shakeIntensity = 0.8
    // Death particles
    for j = 1 to 20
        run_spawnParticles(playerX, playerY, scrollZ, 255, 60, 40)
    next

// =============================================================
// Power-up Update
// =============================================================

func run_updatePowerups dt
    if hasMagnet
        magnetTimer -= dt
        if magnetTimer <= 0
            hasMagnet = false
            magnetTimer = 0.0
        ok
    ok
    if hasShield
        shieldTimer -= dt
        if shieldTimer <= 0
            hasShield = false
            shieldTimer = 0.0
        ok
    ok

// =============================================================
// Particles
// =============================================================

func run_spawnParticles wx, wy, wz, pr, pg, pb
    for k = 1 to 8
        vx = (GetRandomValue(-100, 100) / 100.0) * 3.0
        vy = (GetRandomValue(50, 250) / 100.0) * 2.0
        vz = (GetRandomValue(-100, 100) / 100.0) * 3.0
        cr = pr + GetRandomValue(-30, 30)
        cg = pg + GetRandomValue(-30, 30)
        cb = pb + GetRandomValue(-30, 30)
        if cr < 0 cr = 0 ok    if cr > 255 cr = 255 ok
        if cg < 0 cg = 0 ok    if cg > 255 cg = 255 ok
        if cb < 0 cb = 0 ok    if cb > 255 cb = 255 ok
        add(particles, [wx, wy, wz, vx, vy, vz, 1.0, cr, cg, cb])
    next

func run_updateParticles dt
    i = 1
    while i <= len(particles)
        particles[i][1] += particles[i][4] * dt
        particles[i][2] += particles[i][5] * dt
        particles[i][3] += particles[i][6] * dt
        particles[i][5] -= 6.0 * dt
        particles[i][7] -= dt * 1.2
        if particles[i][7] <= 0
            del(particles, i)
        else
            i += 1
        ok
    end

func run_drawParticles3D
    for i = 1 to len(particles)
        p = particles[i]
        relZ = p[3] - scrollZ
        if relZ < -5 or relZ > TILE_LENGTH * TILE_COUNT loop ok
        alpha = floor(p[7] * 255)
        if alpha > 255 alpha = 255 ok
        if alpha < 0 alpha = 0 ok
        sz = 0.06 + p[7] * 0.12
        DrawSphereEx(
            Vector3(p[1], p[2], relZ),
            sz, 4, 4,
            RAYLIBColor(p[8], p[9], p[10], alpha)
        )
    next

// =============================================================
// Camera
// =============================================================

func run_positionCamera dt
    goalX = 0  goalY = 0  goalZ = 0  tgtX = 0  tgtY = 0  tgtZ = 0

    if cameraMode = CAM_CHASE
        goalX = playerX * 0.5
        goalY = 4.5 + playerY * 0.2
        goalZ = -7.0
        tgtX  = playerX * 0.3
        tgtY  = 1.5
        tgtZ  = 12.0
    ok

    if cameraMode = CAM_HIGH
        goalX = playerX * 0.3
        goalY = 10.0
        goalZ = -4.0
        tgtX  = playerX * 0.2
        tgtY  = 0.5
        tgtZ  = 15.0
    ok

    if cameraMode = CAM_SIDE
        goalX = playerX + 6.0
        goalY = 3.5
        goalZ = -1.0
        tgtX  = playerX
        tgtY  = 1.5
        tgtZ  = 8.0
    ok

    lerpSpd = 6.0 * dt
    if lerpSpd > 0.3 lerpSpd = 0.3 ok

    camPosX += (goalX - camPosX) * lerpSpd
    camPosY += (goalY - camPosY) * lerpSpd
    camPosZ += (goalZ - camPosZ) * lerpSpd
    camTgtX += (tgtX - camTgtX) * lerpSpd
    camTgtY += (tgtY - camTgtY) * lerpSpd
    camTgtZ += (tgtZ - camTgtZ) * lerpSpd

    // Apply shake
    skX = 0  skY = 0
    if shakeTimer > 0
        skX = (GetRandomValue(-100, 100) / 100.0) * shakeIntensity * shakeTimer
        skY = (GetRandomValue(-100, 100) / 100.0) * shakeIntensity * shakeTimer
    ok

    camera.position.x = camPosX + skX
    camera.position.y = camPosY + skY
    camera.position.z = camPosZ
    camera.target.x   = camTgtX
    camera.target.y   = camTgtY
    camera.target.z   = camTgtZ

// =============================================================
// 3D Drawing: Road & Ground
// =============================================================

func run_drawRoad
    currentTile = floor(scrollZ / TILE_LENGTH)
    offsetZ = scrollZ - currentTile * TILE_LENGTH

    for i = -2 to TILE_COUNT
        tileZ = i * TILE_LENGTH - offsetZ

        // Road surface
        for lane = 1 to LANE_COUNT
            lx = (LANE_CENTER - lane) * LANE_WIDTH

            if (i + currentTile + lane) % 2 = 0
                roadCol = RAYLIBColor(42, 42, 50, 255)
            else
                roadCol = RAYLIBColor(48, 48, 56, 255)
            ok

            DrawCube(
                Vector3(lx, -0.05, tileZ + TILE_LENGTH/2),
                LANE_WIDTH - 0.08, 0.1, TILE_LENGTH - 0.08,
                roadCol
            )
        next

        // Lane divider lines
        for d = 0 to LANE_COUNT
            lineX = (d - 1.5) * LANE_WIDTH
            if d = 0 or d = LANE_COUNT
                lineCol = RAYLIBColor(200, 200, 220, 200)
                lineW = 0.12
            else
                lineCol = RAYLIBColor(120, 120, 140, 150)
                lineW = 0.06
            ok
            DrawCube(
                Vector3(lineX, 0.01, tileZ + TILE_LENGTH/2),
                lineW, 0.02, TILE_LENGTH * 0.3,
                lineCol
            )
        next
    next

// =============================================================
// 3D Drawing: Scenery (side decoration)
// =============================================================

func run_drawScenery
    currentTile = floor(scrollZ / TILE_LENGTH)
    offsetZ = scrollZ - currentTile * TILE_LENGTH
    roadEdge = LANE_COUNT * LANE_WIDTH / 2 + 1.5

    for i = -1 to TILE_COUNT
        tileZ = i * TILE_LENGTH - offsetZ
        seed = (i + currentTile) * 7

        // Left side pillars/buildings
        if (seed + 3) % 4 = 0
            bh = 3.0 + (seed % 5) * 1.5
            bx = -roadEdge - 1.5 - (seed % 3)
            rv = 35 + (seed % 30)
            gv = 35 + ((seed * 3) % 25)
            bv = 45 + ((seed * 7) % 30)
            DrawCube(
                Vector3(bx, bh/2, tileZ + TILE_LENGTH/2),
                2.0 + (seed % 2), bh, 3.0,
                RAYLIBColor(rv, gv, bv, 255)
            )
            DrawCubeWires(
                Vector3(bx, bh/2, tileZ + TILE_LENGTH/2),
                2.0 + (seed % 2), bh, 3.0,
                RAYLIBColor(rv+20, gv+20, bv+20, 120)
            )
        ok

        // Right side
        if (seed + 1) % 3 = 0
            bh = 2.5 + ((seed * 11) % 6) * 1.0
            bx = roadEdge + 1.5 + ((seed * 3) % 3)
            rv = 40 + ((seed * 5) % 25)
            gv = 35 + ((seed * 2) % 20)
            bv = 50 + ((seed * 9) % 25)
            DrawCube(
                Vector3(bx, bh/2, tileZ + TILE_LENGTH/2),
                2.5, bh, 3.5,
                RAYLIBColor(rv, gv, bv, 255)
            )
            DrawCubeWires(
                Vector3(bx, bh/2, tileZ + TILE_LENGTH/2),
                2.5, bh, 3.5,
                RAYLIBColor(rv+20, gv+20, bv+20, 120)
            )
        ok

        // Ground plane extensions
        DrawCube(
            Vector3(-roadEdge - 5, -0.1, tileZ + TILE_LENGTH/2),
            10, 0.1, TILE_LENGTH,
            RAYLIBColor(25, 28, 22, 255)
        )
        DrawCube(
            Vector3(roadEdge + 5, -0.1, tileZ + TILE_LENGTH/2),
            10, 0.1, TILE_LENGTH,
            RAYLIBColor(25, 28, 22, 255)
        )
    next

    // Floating light orbs above road for ambiance
    for j = 0 to 4
        orbZ = j * TILE_LENGTH * 3 - (scrollZ % (TILE_LENGTH * 3))
        if orbZ > -5 and orbZ < TILE_LENGTH * TILE_COUNT
            orbX = sin(animTime * 0.5 + j * 2.0) * 2.0
            orbY = 6.0 + sin(animTime * 0.8 + j * 1.3) * 0.5
            pulse = 0.3 + sin(animTime * 2.0 + j * 1.7) * 0.1
            DrawSphereEx(
                Vector3(orbX, orbY, orbZ),
                pulse, 6, 6,
                RAYLIBColor(100, 140, 200, 60)
            )
            DrawSphereEx(
                Vector3(orbX, orbY, orbZ),
                pulse * 2.5, 6, 6,
                RAYLIBColor(80, 120, 180, 15)
            )
        ok
    next

// =============================================================
// 3D Drawing: Obstacles
// =============================================================

func run_drawObstacles
    for i = 1 to len(obstacles)
        if !obstacles[i][4] loop ok

        obsZ = obstacles[i][1] * TILE_LENGTH + TILE_LENGTH / 2
        relZ = obsZ - scrollZ
        if relZ < -3 or relZ > TILE_LENGTH * TILE_COUNT loop ok

        lane = obstacles[i][2]
        obsType = obstacles[i][3]
        ox = (LANE_CENTER - lane) * LANE_WIDTH

        if obsType = OBS_BARRIER
            // Tall red barrier - jump over
            DrawCube(
                Vector3(ox, 1.2, relZ),
                LANE_WIDTH * 0.8, 2.4, 0.5,
                RAYLIBColor(200, 50, 50, 255)
            )
            DrawCubeWires(
                Vector3(ox, 1.2, relZ),
                LANE_WIDTH * 0.8, 2.4, 0.5,
                RAYLIBColor(255, 100, 80, 200)
            )
            // Warning stripes (top)
            DrawCube(
                Vector3(ox, 2.45, relZ),
                LANE_WIDTH * 0.8, 0.1, 0.5,
                RAYLIBColor(255, 200, 50, 255)
            )
        ok

        if obsType = OBS_LOW_BAR
            // Low horizontal bar - slide under or jump over
            barY = 1.5
            DrawCube(
                Vector3(ox, barY, relZ),
                LANE_WIDTH * 0.9, 0.25, 0.25,
                RAYLIBColor(220, 140, 40, 255)
            )
            DrawCubeWires(
                Vector3(ox, barY, relZ),
                LANE_WIDTH * 0.9, 0.25, 0.25,
                RAYLIBColor(255, 180, 60, 200)
            )
            // Support posts
            postX1 = ox - LANE_WIDTH * 0.4
            postX2 = ox + LANE_WIDTH * 0.4
            DrawCube(Vector3(postX1, barY/2, relZ), 0.15, barY, 0.15, RAYLIBColor(180, 120, 40, 255))
            DrawCube(Vector3(postX2, barY/2, relZ), 0.15, barY, 0.15, RAYLIBColor(180, 120, 40, 255))
        ok

        if obsType = OBS_CRATE
            // Wooden crate in lane
            DrawCube(
                Vector3(ox, 0.9, relZ),
                1.6, 1.8, 1.6,
                RAYLIBColor(140, 90, 50, 255)
            )
            DrawCubeWires(
                Vector3(ox, 0.9, relZ),
                1.6, 1.8, 1.6,
                RAYLIBColor(180, 130, 70, 200)
            )
            // X mark on crate
            DrawLine3D(
                Vector3(ox - 0.5, 1.7, relZ - 0.81),
                Vector3(ox + 0.5, 0.3, relZ - 0.81),
                RAYLIBColor(200, 150, 80, 255)
            )
            DrawLine3D(
                Vector3(ox + 0.5, 1.7, relZ - 0.81),
                Vector3(ox - 0.5, 0.3, relZ - 0.81),
                RAYLIBColor(200, 150, 80, 255)
            )
        ok
    next

// =============================================================
// 3D Drawing: Collectibles
// =============================================================

func run_drawCollectibles
    for i = 1 to len(collectibles)
        if !collectibles[i][4] loop ok

        colZ = collectibles[i][1] * TILE_LENGTH + TILE_LENGTH / 2 + collectibles[i][5] * TILE_LENGTH
        relZ = colZ - scrollZ
        if relZ < -3 or relZ > TILE_LENGTH * TILE_COUNT loop ok

        lane = collectibles[i][2]
        colType = collectibles[i][3]
        cx = (LANE_CENTER - lane) * LANE_WIDTH
        cy = 1.2 + sin(animTime * 3.0 + i * 0.7) * 0.2

        if colType = COL_COIN
            // Golden spinning coin
            rot = animTime * 180.0 + i * 45.0
            coinRad = 0.35
            DrawSphereEx(
                Vector3(cx, cy, relZ),
                coinRad, 6, 6,
                RAYLIBColor(255, 215, 0, 255)
            )
            // Glow
            DrawSphereEx(
                Vector3(cx, cy, relZ),
                coinRad + 0.15, 6, 6,
                RAYLIBColor(255, 230, 50, 40)
            )
        ok

        if colType = COL_MAGNET
            // Purple magnet power-up
            DrawSphereEx(
                Vector3(cx, cy + 0.3, relZ),
                0.5, 8, 8,
                RAYLIBColor(180, 60, 255, 255)
            )
            DrawSphereEx(
                Vector3(cx, cy + 0.3, relZ),
                0.7, 6, 6,
                RAYLIBColor(200, 100, 255, 30)
            )
            // Spinning ring
            DrawCircle3D(
                Vector3(cx, cy + 0.3, relZ),
                0.65,
                Vector3(0, 1, 0), animTime * 120.0,
                RAYLIBColor(220, 130, 255, 180)
            )
        ok

        if colType = COL_SHIELD
            // Blue shield power-up
            DrawSphereEx(
                Vector3(cx, cy + 0.3, relZ),
                0.5, 8, 8,
                RAYLIBColor(60, 150, 255, 255)
            )
            DrawSphereEx(
                Vector3(cx, cy + 0.3, relZ),
                0.7, 6, 6,
                RAYLIBColor(80, 180, 255, 30)
            )
            DrawCircle3D(
                Vector3(cx, cy + 0.3, relZ),
                0.65,
                Vector3(1, 0, 0), animTime * 100.0,
                RAYLIBColor(100, 200, 255, 180)
            )
        ok
    next

// =============================================================
// 3D Drawing: Player
// =============================================================

func run_drawPlayer
    py = playerY
    scaleY = 1.0
    scaleXZ = 1.0

    if isSliding
        scaleY  = SLIDE_SCALE
        scaleXZ = 1.4
        py = PLAYER_RAD * SLIDE_SCALE + 0.05
    ok

    rad = PLAYER_RAD

    // Body
    DrawSphereEx(
        Vector3(playerX, py, 0),
        rad * scaleXZ, 16, 16,
        RAYLIBColor(60, 180, 220, 255)
    )
    // Glow aura
    DrawSphereEx(
        Vector3(playerX, py, 0),
        rad * scaleXZ + 0.15, 10, 10,
        RAYLIBColor(80, 200, 255, 35)
    )

    // Eyes (always forward)
    if !isSliding
        eyeOff = 0.18
        eRad = 0.09
        pRad = 0.05
        DrawSphere(Vector3(playerX - eyeOff, py + 0.12, rad * 0.6), eRad, WHITE)
        DrawSphere(Vector3(playerX + eyeOff, py + 0.12, rad * 0.6), eRad, WHITE)
        DrawSphere(Vector3(playerX - eyeOff, py + 0.12, rad * 0.85), pRad, BLACK)
        DrawSphere(Vector3(playerX + eyeOff, py + 0.12, rad * 0.85), pRad, BLACK)
    ok

    // Shadow
    DrawCircle3D(
        Vector3(playerX, 0.01, 0),
        rad + 0.2,
        Vector3(1, 0, 0), 90.0,
        RAYLIBColor(0, 0, 0, 60)
    )

    // Shield visual
    if hasShield
        shieldPulse = 0.8 + sin(animTime * 4.0) * 0.2
        DrawSphereEx(
            Vector3(playerX, py, 0),
            (rad + 0.4) * shieldPulse, 10, 10,
            RAYLIBColor(60, 180, 255, 35)
        )
        DrawCircle3D(
            Vector3(playerX, py, 0),
            (rad + 0.35) * shieldPulse,
            Vector3(0, 1, 0), animTime * 90.0,
            RAYLIBColor(80, 200, 255, 120)
        )
        DrawCircle3D(
            Vector3(playerX, py, 0),
            (rad + 0.35) * shieldPulse,
            Vector3(1, 0, 0), animTime * 70.0,
            RAYLIBColor(80, 200, 255, 90)
        )
    ok

    // Magnet visual
    if hasMagnet
        magPulse = 0.6 + sin(animTime * 5.0) * 0.15
        DrawCircle3D(
            Vector3(playerX, py + 0.5, 0),
            magPulse,
            Vector3(0, 1, 0), animTime * 150.0,
            RAYLIBColor(200, 100, 255, 100)
        )
    ok

// =============================================================
// HUD
// =============================================================

func run_drawHUD
    // Score panel (top left)
    panelW = 220
    panelH = 95
    DrawRectangle(10, 30, panelW, panelH, Fade(BLACK, 0.7))
    DrawRectangleLines(10, 30, panelW, panelH, RAYLIBColor(80, 160, 220, 180))

    DrawText("Score: " + score, 20, 38, 20, RAYLIBColor(255, 255, 255, 255))
    DrawText("High: " + highScore, 20, 62, 16, RAYLIBColor(200, 220, 255, 200))
    DrawText("Coins: " + coins, 20, 82, 16, RAYLIBColor(255, 215, 0, 230))
    dist = floor(distance)
    DrawText("Dist: " + dist + "m", 20, 102, 16, RAYLIBColor(180, 200, 220, 200))

    // Speed bar (top center)
    speedPct = floor((runSpeed - BASE_SPEED) / (MAX_SPEED - BASE_SPEED) * 100)
    if speedPct > 100 speedPct = 100 ok
    if speedPct < 0 speedPct = 0 ok
    barW = 200
    barH = 14
    barX = (SCREEN_W - barW) / 2
    barY = 35
    DrawRectangle(barX, barY, barW, barH, Fade(BLACK, 0.6))
    fillW = floor(barW * speedPct / 100)
    if fillW > barW fillW = barW ok
    sr = floor(50 + speedPct * 2)
    sg = floor(200 - speedPct * 1.5)
    if sr > 255 sr = 255 ok
    if sg < 50 sg = 50 ok
    DrawRectangle(barX, barY, fillW, barH, RAYLIBColor(sr, sg, 50, 220))
    DrawRectangleLines(barX, barY, barW, barH, RAYLIBColor(150, 150, 170, 150))
    DrawText("Speed", barX + barW/2 - 20, barY - 16, 14, RAYLIBColor(170, 180, 200, 200))

    // Power-up timers (top right)
    puY = 35
    if hasMagnet
        mPct = floor(magnetTimer / MAGNET_DUR * 100)
        DrawRectangle(SCREEN_W - 190, puY, 180, 20, Fade(BLACK, 0.6))
        mFill = floor(170 * mPct / 100)
        DrawRectangle(SCREEN_W - 185, puY + 3, mFill, 14, RAYLIBColor(180, 80, 255, 200))
        DrawText("MAGNET", SCREEN_W - 185, puY + 4, 12, WHITE)
        puY += 25
    ok
    if hasShield
        sPct = floor(shieldTimer / SHIELD_DUR * 100)
        DrawRectangle(SCREEN_W - 190, puY, 180, 20, Fade(BLACK, 0.6))
        sFill = floor(170 * sPct / 100)
        DrawRectangle(SCREEN_W - 185, puY + 3, sFill, 14, RAYLIBColor(60, 180, 255, 200))
        DrawText("SHIELD", SCREEN_W - 185, puY + 4, 12, WHITE)
    ok

    // Camera mode (bottom left)
    camName = "CHASE"
    if cameraMode = CAM_HIGH camName = "HIGH" ok
    if cameraMode = CAM_SIDE camName = "SIDE" ok
    DrawRectangle(10, SCREEN_H - 55, 200, 22, Fade(BLACK, 0.6))
    DrawText("Cam: " + camName + "  [C] switch", 16, SCREEN_H - 51, 14, RAYLIBColor(150, 180, 210, 220))

    // Controls hint (bottom right)
    DrawRectangle(SCREEN_W - 350, SCREEN_H - 32, 340, 22, Fade(BLACK, 0.6))
    DrawText("A/D: Lane | W/Space: Jump | S: Slide | P: Pause", SCREEN_W - 345, SCREEN_H - 28, 12,
             RAYLIBColor(140, 150, 170, 180))

// =============================================================
// Title Screen
// =============================================================

func run_drawTitleScreen
    // Animated background - draw road in background
    BeginMode3D(camera)
        run_drawRoad()
        run_drawScenery()
    EndMode3D()

    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.55))

    t1 = "3D ENDLESS RUNNER"
    t1w = MeasureText(t1, 52)
    DrawText(t1, (SCREEN_W - t1w)/2, 120, 52, RAYLIBColor(80, 200, 255, 255))

    t2 = "~ Run, jump, slide, survive! ~"
    t2w = MeasureText(t2, 18)
    DrawText(t2, (SCREEN_W - t2w)/2, 185, 18, RAYLIBColor(140, 190, 220, 220))

    cy = 230
    cLines = [
        "Left/Right or A/D  -  Switch lanes",
        "Up/W/Space         -  Jump over barriers",
        "Down/S             -  Slide under low bars",
        "C                  -  Cycle camera views",
        "P                  -  Pause game",
        "R                  -  Restart anytime",
        "",
        "Collect gold coins for bonus points",
        "Purple orb = Coin Magnet (wider pickup range)",
        "Blue orb = Shield (absorbs one hit)",
        "",
        "Speed increases the further you run!"
    ]
    for i = 1 to len(cLines)
        lw = MeasureText(cLines[i], 16)
        if i >= 8
            col = RAYLIBColor(255, 200, 100, 220)
        else
            col = RAYLIBColor(160, 190, 210, 230)
        ok
        DrawText(cLines[i], (SCREEN_W - lw)/2, cy + (i - 1) * 23, 16, col)
    next

    if floor(animTime * 2) % 2 = 0
        st = "Press ENTER or SPACE to Run!"
        stw = MeasureText(st, 26)
        DrawText(st, (SCREEN_W - stw)/2, 530, 26, WHITE)
    ok

    cr = "Developed using Ring Language + RingRayLib"
    crw = MeasureText(cr, 14)
    DrawText(cr, (SCREEN_W - crw)/2, SCREEN_H - 40, 14, RAYLIBColor(100, 120, 100, 180))

// =============================================================
// Pause Overlay
// =============================================================

func run_drawPauseOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.5))
    pt = "PAUSED"
    ptw = MeasureText(pt, 50)
    DrawText(pt, (SCREEN_W - ptw)/2, SCREEN_H/2 - 40, 50, WHITE)
    pt2 = "Press P or SPACE to resume"
    pt2w = MeasureText(pt2, 20)
    DrawText(pt2, (SCREEN_W - pt2w)/2, SCREEN_H/2 + 25, 20, RAYLIBColor(200, 210, 220, 220))

// =============================================================
// Game Over Screen
// =============================================================

func run_drawGameOverScreen
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.55))

    g1 = "GAME OVER"
    g1w = MeasureText(g1, 55)
    DrawText(g1, (SCREEN_W - g1w)/2, 200, 55, RAYLIBColor(255, 60, 60, 255))

    sy = 280
    DrawText("Score: " + score, (SCREEN_W)/2 - 80, sy, 26, WHITE)
    DrawText("Distance: " + floor(distance) + "m", (SCREEN_W)/2 - 80, sy + 35, 20, RAYLIBColor(180, 200, 220, 230))
    DrawText("Coins: " + coins, (SCREEN_W)/2 - 80, sy + 62, 20, RAYLIBColor(255, 215, 0, 230))

    if score >= highScore and score > 0
        if floor(animTime * 3) % 2 = 0
            hs = "NEW HIGH SCORE!"
            hsw = MeasureText(hs, 24)
            DrawText(hs, (SCREEN_W - hsw)/2, sy + 95, 24, RAYLIBColor(255, 215, 0, 255))
        ok
    else
        hs = "Best: " + highScore
        hsw = MeasureText(hs, 20)
        DrawText(hs, (SCREEN_W - hsw)/2, sy + 95, 20, RAYLIBColor(150, 170, 190, 200))
    ok

    if floor(animTime * 2) % 2 = 0
        rt = "Press ENTER or SPACE to try again"
        rtw = MeasureText(rt, 20)
        DrawText(rt, (SCREEN_W - rtw)/2, sy + 145, 20, WHITE)
    ok
