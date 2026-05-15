/*
**  3D Sokoban Game - Using RingRayLib
**  ====================================
**  Push crates onto target positions in a 3D warehouse!
**  A classic puzzle game rendered in full 3D with smooth
**  animations, multiple levels, and an undo system.
**
**  Controls:
**    Arrow Keys / WASD  - Move player / Push crates
**    U / Backspace      - Undo last move
**    R                  - Restart current level
**    N                  - Next level (if unlocked)
**    B                  - Previous level
**    C                  - Cycle camera views
**    ESC                - Exit
**
**  Features:
**    - 10 hand-crafted puzzle levels (all verified solvable)
**    - Full undo system (unlimited steps)
**    - Smooth player and crate movement animations
**    - Three camera modes: Overhead / Isometric / Follow
**    - Crates glow green when on target positions
**    - Particle effects on crate placement
**    - Move counter and push counter
**    - Mini-map overlay
**    - Level select and win screens
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W        = 1024
SCREEN_H        = 768
CELL_SZ         = 2.0
WALL_HEIGHT     = 2.5
CRATE_SZ        = 1.6
PLAYER_RAD      = 0.5
TARGET_RAD      = 0.6

// Tile types
TILE_EMPTY      = 0
TILE_FLOOR      = 1
TILE_WALL       = 2
TILE_TARGET     = 3
TILE_CRATE      = 4
TILE_CRATE_T    = 5
TILE_PLAYER     = 6
TILE_PLAYER_T   = 7

// Game states
ST_START        = 1
ST_PLAYING      = 2
ST_WON          = 3
ST_ALLCLEAR     = 4

// Camera modes
CAM_OVERHEAD    = 1
CAM_ISOMETRIC   = 2
CAM_FOLLOW      = 3
CAM_COUNT       = 3

// Animation
ANIM_SPEED      = 8.0

// =============================================================
// Global Variables
// =============================================================

levels          = []
levelCount      = 0
currentLevel    = 1
maxUnlocked     = 1

grid            = []
gridRows        = 0
gridCols        = 0

playerR         = 1
playerC         = 1

crates          = []
targets         = []
undoStack       = []

animActive      = false
animTimer       = 0.0
animPlayerFromR = 0   animPlayerFromC = 0
animPlayerToR   = 0   animPlayerToC   = 0
animCrateIdx    = 0
animCrateFromR  = 0   animCrateFromC  = 0
animCrateToR    = 0   animCrateToC    = 0
pendingWin      = false

moveCount       = 0
pushCount       = 0

gameState       = ST_START
animTime        = 0.0
cameraMode      = CAM_OVERHEAD

camPosX = 0.0   camPosY = 15.0  camPosZ = 0.0
camTgtX = 0.0   camTgtY = 0.0   camTgtZ = 0.0

particles       = []

playerFaceR     = 0
playerFaceC     = 1

// =============================================================
// Level Definitions (inline, before any functions)
// =============================================================

// Level 1 - Tutorial: Simple push
add(levels, [
    "  ####  ",
    "###..#  ",
    "#.P.O.# ",
    "#..X..# ",
    "#..#### ",
    "####    "
])

// Level 2 - Two crates
add(levels, [
    " #####  ",
    " #...#  ",
    " #O..#  ",
    "##.O.## ",
    "#..X..# ",
    "#..X..# ",
    "#P....# ",
    "####### "
])

// Level 3 - L-shape
add(levels, [
    "######  ",
    "#....## ",
    "#.O...# ",
    "#..O..# ",
    "##.P.## ",
    " #.XX#  ",
    " #####  "
])

// Level 4 - Narrow corridors
add(levels, [
    "  ####  ",
    "###..## ",
    "#.P.O.# ",
    "#.#.#.# ",
    "#.O.X.# ",
    "#..X..# ",
    "##...## ",
    " #####  "
])

// Level 5 - Three crates
add(levels, [
    " ######  ",
    "##....## ",
    "#..OO..# ",
    "#.P.O..# ",
    "#..#...# ",
    "#.XXX..# ",
    "##....## ",
    " ######  "
])

// Level 6 - Spiral
add(levels, [
    "#######  ",
    "#.....#  ",
    "#.###.## ",
    "#.#X#..# ",
    "#.#XO..# ",
    "#.XOOP.# ",
    "##.....# ",
    " ####### "
])

// Level 7 - Cross pattern
add(levels, [
    "  ####   ",
    "###..### ",
    "#..OX..# ",
    "#.O.XP.# ",
    "#..OX..# ",
    "###..### ",
    "  ####   "
])

// Level 8 - Warehouse
add(levels, [
    " ###### ",
    "##....# ",
    "#.OO..# ",
    "#P.#X.# ",
    "#..#X.# ",
    "#.O..X# ",
    "##....# ",
    " ###### "
])

// Level 9 - T-shape Maze
add(levels, [
    "  #####  ",
    "###...#  ",
    "#.O.O.## ",
    "#..#..X# ",
    "#P.O..X# ",
    "####..X# ",
    "   ##### "
])

// Level 10 - Grand Finale
add(levels, [
    " ######  ",
    "##....## ",
    "#.O..O.# ",
    "#......# ",
    "#.O..O.# ",
    "#..##..# ",
    "#..XX..# ",
    "#P.XX..# ",
    "######## "
])

levelCount = len(levels)

// =============================================================
// Main Program
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Ring 3D Sokoban - RingRayLib")
ToggleFullScreen()
SetTargetFPS(60)

camera = Camera3D(
    0, 15, 10,
    0,  0,  0,
    0,  1,  0,
    45,
    CAMERA_PERSPECTIVE
)

soko_loadLevel(1)

// =============================================================
// Main Game Loop
// =============================================================

while !WindowShouldClose()

    dt = GetFrameTime()
    animTime += dt

    // --- Global input ---
    if IsKeyPressed(KEY_C)
        cameraMode += 1
        if cameraMode > CAM_COUNT
            cameraMode = CAM_OVERHEAD
        ok
    ok

    if IsKeyPressed(KEY_R)
        soko_loadLevel(currentLevel)
        gameState = ST_PLAYING
    ok

    // --- State-specific updates ---
    if gameState = ST_START
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            soko_loadLevel(1)
            gameState = ST_PLAYING
        ok
    ok

    if gameState = ST_PLAYING
        if !animActive
            soko_handleInput()
        ok
        soko_updateAnimation(dt)
        soko_updateParticles(dt)
    ok

    if gameState = ST_WON
        soko_updateParticles(dt)
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsKeyPressed(KEY_N)
            if currentLevel < levelCount
                soko_loadLevel(currentLevel + 1)
                gameState = ST_PLAYING
            else
                gameState = ST_ALLCLEAR
            ok
        ok
    ok

    if gameState = ST_ALLCLEAR
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            currentLevel = 1
            soko_loadLevel(1)
            gameState = ST_PLAYING
        ok
    ok

    soko_positionCamera()

    // --- Drawing ---
    BeginDrawing()
        ClearBackground(RAYLIBColor(18, 18, 28, 255))

        if gameState = ST_START
            soko_drawTitleScreen()
        else
            BeginMode3D(camera)
                soko_drawFloor()
                soko_drawWalls()
                soko_drawTargets()
                soko_drawCrates()
                soko_drawPlayer()
                soko_drawParticles3D()
            EndMode3D()

            soko_drawHUD()
            soko_drawMiniMap()

            if gameState = ST_WON
                soko_drawWinOverlay()
            ok
            if gameState = ST_ALLCLEAR
                soko_drawAllClearOverlay()
            ok
        ok

        DrawFPS(10, 10)
    EndDrawing()

end

CloseWindow()

// =============================================================
// =============================================================
// ALL FUNCTIONS BELOW THIS LINE
// =============================================================
// =============================================================

// =============================================================
// Level Loading
// =============================================================

func soko_loadLevel num
    if num < 1 or num > levelCount return ok
    currentLevel = num
    if num > maxUnlocked maxUnlocked = num ok

    lvl = levels[num]
    gridRows = len(lvl)
    gridCols = 0

    for r = 1 to gridRows
        rowLen = len(lvl[r])
        if rowLen > gridCols gridCols = rowLen ok
    next

    grid = list(gridRows)
    for r = 1 to gridRows
        grid[r] = list(gridCols)
        for c = 1 to gridCols
            grid[r][c] = TILE_EMPTY
        next
    next

    crates = []
    targets = []
    playerR = 1
    playerC = 1

    for r = 1 to gridRows
        row = lvl[r]
        for c = 1 to len(row)
            ch = substr(row, c, 1)

            if ch = "#"
                grid[r][c] = TILE_WALL
            ok
            if ch = "."
                grid[r][c] = TILE_FLOOR
            ok
            if ch = "X"
                grid[r][c] = TILE_TARGET
                add(targets, [r, c])
            ok
            if ch = "O"
                grid[r][c] = TILE_FLOOR
                add(crates, [r, c])
            ok
            if ch = "*"
                grid[r][c] = TILE_TARGET
                add(targets, [r, c])
                add(crates, [r, c])
            ok
            if ch = "P"
                grid[r][c] = TILE_FLOOR
                playerR = r
                playerC = c
            ok
            if ch = "+"
                grid[r][c] = TILE_TARGET
                add(targets, [r, c])
                playerR = r
                playerC = c
            ok
            if ch = " "
                grid[r][c] = TILE_EMPTY
            ok
        next
    next

    undoStack   = []
    moveCount   = 0
    pushCount   = 0
    animActive  = false
    pendingWin  = false
    particles   = []
    playerFaceR = 0
    playerFaceC = 1

// =============================================================
// Input Handling
// =============================================================

func soko_handleInput
    dr = 0   dc = 0

    if IsKeyPressed(KEY_UP) or IsKeyPressed(KEY_W)
        dr = -1   dc = 0
    ok
    if IsKeyPressed(KEY_DOWN) or IsKeyPressed(KEY_S)
        dr = 1    dc = 0
    ok
    if IsKeyPressed(KEY_LEFT) or IsKeyPressed(KEY_A)
        dr = 0    dc = -1
    ok
    if IsKeyPressed(KEY_RIGHT) or IsKeyPressed(KEY_D)
        dr = 0    dc = 1
    ok

    if IsKeyPressed(KEY_U) or IsKeyPressed(KEY_BACKSPACE)
        soko_undo()
        return
    ok

    if IsKeyPressed(KEY_N)
        if currentLevel < maxUnlocked
            soko_loadLevel(currentLevel + 1)
        ok
        return
    ok
    if IsKeyPressed(KEY_B)
        if currentLevel > 1
            soko_loadLevel(currentLevel - 1)
        ok
        return
    ok

    if dr = 0 and dc = 0 return ok

    playerFaceR = dr
    playerFaceC = dc

    newR = playerR + dr
    newC = playerC + dc

    if newR < 1 or newR > gridRows or newC < 1 or newC > gridCols return ok
    if grid[newR][newC] = TILE_WALL or grid[newR][newC] = TILE_EMPTY return ok

    crateIdx = soko_crateAt(newR, newC)

    if crateIdx > 0
        pushR = newR + dr
        pushC = newC + dc

        if pushR < 1 or pushR > gridRows or pushC < 1 or pushC > gridCols return ok
        if grid[pushR][pushC] = TILE_WALL or grid[pushR][pushC] = TILE_EMPTY return ok
        if soko_crateAt(pushR, pushC) > 0 return ok

        soko_saveUndo()

        animActive      = true
        animTimer       = 0.0
        animPlayerFromR = playerR
        animPlayerFromC = playerC
        animPlayerToR   = newR
        animPlayerToC   = newC
        animCrateIdx    = crateIdx
        animCrateFromR  = newR
        animCrateFromC  = newC
        animCrateToR    = pushR
        animCrateToC    = pushC

        playerR = newR
        playerC = newC
        crates[crateIdx][1] = pushR
        crates[crateIdx][2] = pushC
        moveCount += 1
        pushCount += 1

        if soko_isTarget(pushR, pushC)
            soko_spawnParticles(pushR, pushC, 50, 220, 80)
        ok

    else
        soko_saveUndo()

        animActive      = true
        animTimer       = 0.0
        animPlayerFromR = playerR
        animPlayerFromC = playerC
        animPlayerToR   = newR
        animPlayerToC   = newC
        animCrateIdx    = 0

        playerR = newR
        playerC = newC
        moveCount += 1
    ok

    // Defer win check until animation completes
    if soko_checkWin()
        pendingWin = true
    ok

// =============================================================
// Undo System
// =============================================================

func soko_saveUndo
    cratesCopy = []
    for i = 1 to len(crates)
        add(cratesCopy, [crates[i][1], crates[i][2]])
    next
    add(undoStack, [playerR, playerC, cratesCopy, moveCount, pushCount])

func soko_undo
    if len(undoStack) = 0 return ok
    state = undoStack[len(undoStack)]
    del(undoStack, len(undoStack))

    playerR   = state[1]
    playerC   = state[2]
    crates    = state[3]
    moveCount = state[4]
    pushCount = state[5]
    animActive = false

// =============================================================
// Helper Functions
// =============================================================

func soko_crateAt r, c
    for i = 1 to len(crates)
        if crates[i][1] = r and crates[i][2] = c
            return i
        ok
    next
    return 0

func soko_isTarget r, c
    for i = 1 to len(targets)
        if targets[i][1] = r and targets[i][2] = c
            return true
        ok
    next
    return false

func soko_checkWin
    for i = 1 to len(crates)
        if !soko_isTarget(crates[i][1], crates[i][2])
            return false
        ok
    next
    return true

// =============================================================
// Animation
// =============================================================

func soko_updateAnimation dt
    if !animActive
        // Check for pending win AFTER animation has completed
        if pendingWin
            pendingWin = false
            gameState = ST_WON
            for i = 1 to len(targets)
                soko_spawnParticles(targets[i][1], targets[i][2], 255, 215, 0)
            next
        ok
        return
    ok

    animTimer += dt * ANIM_SPEED
    if animTimer >= 1.0
        animTimer  = 1.0
        animActive = false
    ok

func soko_getAnimPlayerPos
    if animActive
        fromX = (animPlayerFromC - 1) * CELL_SZ + CELL_SZ / 2
        fromZ = (animPlayerFromR - 1) * CELL_SZ + CELL_SZ / 2
        toX   = (animPlayerToC - 1) * CELL_SZ + CELL_SZ / 2
        toZ   = (animPlayerToR - 1) * CELL_SZ + CELL_SZ / 2
        t = animTimer
        t = t * t * (3.0 - 2.0 * t)
        return [fromX + (toX - fromX) * t, fromZ + (toZ - fromZ) * t]
    else
        wx = (playerC - 1) * CELL_SZ + CELL_SZ / 2
        wz = (playerR - 1) * CELL_SZ + CELL_SZ / 2
        return [wx, wz]
    ok

func soko_getAnimCratePos idx
    if animActive and idx = animCrateIdx
        fromX = (animCrateFromC - 1) * CELL_SZ + CELL_SZ / 2
        fromZ = (animCrateFromR - 1) * CELL_SZ + CELL_SZ / 2
        toX   = (animCrateToC - 1) * CELL_SZ + CELL_SZ / 2
        toZ   = (animCrateToR - 1) * CELL_SZ + CELL_SZ / 2
        t = animTimer
        t = t * t * (3.0 - 2.0 * t)
        return [fromX + (toX - fromX) * t, fromZ + (toZ - fromZ) * t]
    else
        wx = (crates[idx][2] - 1) * CELL_SZ + CELL_SZ / 2
        wz = (crates[idx][1] - 1) * CELL_SZ + CELL_SZ / 2
        return [wx, wz]
    ok

// =============================================================
// Particles
// =============================================================

func soko_spawnParticles gr, gc, pr, pg, pb
    wx = (gc - 1) * CELL_SZ + CELL_SZ / 2
    wz = (gr - 1) * CELL_SZ + CELL_SZ / 2
    for i = 1 to 12
        vx = (GetRandomValue(-100, 100) / 100.0) * 2.0
        vy = (GetRandomValue(100, 300) / 100.0) * 1.5
        vz = (GetRandomValue(-100, 100) / 100.0) * 2.0
        cr = pr + GetRandomValue(-30, 30)
        cg = pg + GetRandomValue(-30, 30)
        cb = pb + GetRandomValue(-30, 30)
        if cr < 0 cr = 0 ok    if cr > 255 cr = 255 ok
        if cg < 0 cg = 0 ok    if cg > 255 cg = 255 ok
        if cb < 0 cb = 0 ok    if cb > 255 cb = 255 ok
        add(particles, [wx, 0.8, wz, vx, vy, vz, 1.2, cr, cg, cb])
    next

func soko_updateParticles dt
    i = 1
    while i <= len(particles)
        particles[i][1] += particles[i][4] * dt
        particles[i][2] += particles[i][5] * dt
        particles[i][3] += particles[i][6] * dt
        particles[i][5] -= 5.0 * dt
        particles[i][7] -= dt
        if particles[i][7] <= 0
            del(particles, i)
        else
            i += 1
        ok
    end

func soko_drawParticles3D
    for i = 1 to len(particles)
        p = particles[i]
        alpha = floor((p[7] / 1.2) * 255)
        if alpha > 255 alpha = 255 ok
        if alpha < 0 alpha = 0 ok
        sz = 0.06 + p[7] * 0.1
        DrawSphereEx(
            Vector3(p[1], p[2], p[3]),
            sz, 4, 4,
            RAYLIBColor(p[8], p[9], p[10], alpha)
        )
    next

// =============================================================
// Camera
// =============================================================

func soko_positionCamera
    centerX = (gridCols * CELL_SZ) / 2
    centerZ = (gridRows * CELL_SZ) / 2
    maxDim = gridCols
    if gridRows > maxDim maxDim = gridRows ok

    pPos = soko_getAnimPlayerPos()
    px = pPos[1]
    pz = pPos[2]

    goalX = 0  goalY = 0  goalZ = 0  tgtX = 0  tgtZ = 0  lerpSpd = 0.08

    if cameraMode = CAM_OVERHEAD
        goalX = centerX
        goalY = maxDim * CELL_SZ * 0.95
        goalZ = centerZ + 0.1
        tgtX = centerX
        tgtZ = centerZ
        lerpSpd = 0.08
    ok

    if cameraMode = CAM_ISOMETRIC
        goalX = centerX + maxDim * 0.8
        goalY = maxDim * CELL_SZ * 0.7
        goalZ = centerZ + maxDim * 0.8
        tgtX = centerX
        tgtZ = centerZ
        lerpSpd = 0.06
    ok

    if cameraMode = CAM_FOLLOW
        goalX = px
        goalY = 10
        goalZ = pz + 8
        tgtX = px
        tgtZ = pz
        lerpSpd = 0.10
    ok

    camPosX += (goalX - camPosX) * lerpSpd
    camPosY += (goalY - camPosY) * lerpSpd
    camPosZ += (goalZ - camPosZ) * lerpSpd
    camTgtX += (tgtX - camTgtX) * lerpSpd
    camTgtY = 0.3
    camTgtZ += (tgtZ - camTgtZ) * lerpSpd

    camera.position.x = camPosX
    camera.position.y = camPosY
    camera.position.z = camPosZ
    camera.target.x   = camTgtX
    camera.target.y   = camTgtY
    camera.target.z   = camTgtZ

// =============================================================
// 3D Drawing: Floor
// =============================================================

func soko_drawFloor
    for r = 1 to gridRows
        for c = 1 to gridCols
            tile = grid[r][c]
            if tile != TILE_EMPTY
                wx = (c - 1) * CELL_SZ + CELL_SZ / 2
                wz = (r - 1) * CELL_SZ + CELL_SZ / 2

                if (r + c) % 2 = 0
                    floorCol = RAYLIBColor(55, 52, 48, 255)
                else
                    floorCol = RAYLIBColor(48, 45, 42, 255)
                ok

                DrawCube(
                    Vector3(wx, -0.05, wz),
                    CELL_SZ, 0.1, CELL_SZ,
                    floorCol
                )
                DrawCubeWires(
                    Vector3(wx, -0.05, wz),
                    CELL_SZ, 0.1, CELL_SZ,
                    RAYLIBColor(65, 62, 58, 255)
                )
            ok
        next
    next

// =============================================================
// 3D Drawing: Walls
// =============================================================

func soko_drawWalls
    for r = 1 to gridRows
        for c = 1 to gridCols
            if grid[r][c] = TILE_WALL
                wx = (c - 1) * CELL_SZ + CELL_SZ / 2
                wz = (r - 1) * CELL_SZ + CELL_SZ / 2
                wy = WALL_HEIGHT / 2

                rv = 70 + ((r * 17 + c * 31) % 25)
                gv = 65 + ((r * 23 + c * 13) % 20)
                bv = 60 + ((r * 7 + c * 41) % 15)

                DrawCube(
                    Vector3(wx, wy, wz),
                    CELL_SZ, WALL_HEIGHT, CELL_SZ,
                    RAYLIBColor(rv, gv, bv, 255)
                )
                DrawCubeWires(
                    Vector3(wx, wy, wz),
                    CELL_SZ, WALL_HEIGHT, CELL_SZ,
                    RAYLIBColor(rv + 25, gv + 25, bv + 25, 200)
                )

                DrawCube(
                    Vector3(wx, WALL_HEIGHT + 0.05, wz),
                    CELL_SZ, 0.1, CELL_SZ,
                    RAYLIBColor(rv + 15, gv + 15, bv + 10, 255)
                )
            ok
        next
    next

// =============================================================
// 3D Drawing: Targets
// =============================================================

func soko_drawTargets
    for i = 1 to len(targets)
        tr = targets[i][1]
        tc = targets[i][2]
        wx = (tc - 1) * CELL_SZ + CELL_SZ / 2
        wz = (tr - 1) * CELL_SZ + CELL_SZ / 2

        hasCrate = false
        if soko_crateAt(tr, tc) > 0 hasCrate = true ok

        if hasCrate
            DrawCircle3D(
                Vector3(wx, 0.02, wz),
                TARGET_RAD + 0.1,
                Vector3(1, 0, 0), 90.0,
                RAYLIBColor(50, 200, 80, 120)
            )
        else
            pulse = 0.8 + sin(animTime * 3.0 + i * 1.5) * 0.2

            DrawCircle3D(
                Vector3(wx, 0.03, wz),
                TARGET_RAD * pulse,
                Vector3(1, 0, 0), 90.0,
                RAYLIBColor(255, 100, 80, 180)
            )
            DrawCircle3D(
                Vector3(wx, 0.04, wz),
                TARGET_RAD * 0.4 * pulse,
                Vector3(1, 0, 0), 90.0,
                RAYLIBColor(255, 160, 80, 220)
            )
            DrawSphere(
                Vector3(wx, 0.10, wz),
                0.08 * pulse,
                RAYLIBColor(255, 120, 80, 255)
            )
        ok
    next

// =============================================================
// 3D Drawing: Crates
// =============================================================

func soko_drawCrates
    for i = 1 to len(crates)
        pos = soko_getAnimCratePos(i)
        wx = pos[1]
        wz = pos[2]
        wy = CRATE_SZ / 2

        onTarget = soko_isTarget(crates[i][1], crates[i][2])

        bounceY = 0
        if animActive and i = animCrateIdx
            bounceY = sin(animTimer * 3.14159) * 0.15
        ok

        if onTarget
            crateCol  = RAYLIBColor(50, 180, 70, 255)
            wireCol   = RAYLIBColor(80, 220, 100, 255)
            topCol    = RAYLIBColor(70, 200, 90, 255)
        else
            crateCol  = RAYLIBColor(180, 120, 60, 255)
            wireCol   = RAYLIBColor(220, 160, 90, 255)
            topCol    = RAYLIBColor(200, 140, 75, 255)
        ok

        DrawCube(
            Vector3(wx, wy + bounceY, wz),
            CRATE_SZ, CRATE_SZ, CRATE_SZ,
            crateCol
        )
        DrawCubeWires(
            Vector3(wx, wy + bounceY, wz),
            CRATE_SZ, CRATE_SZ, CRATE_SZ,
            wireCol
        )

        DrawCube(
            Vector3(wx, CRATE_SZ + 0.02 + bounceY, wz),
            CRATE_SZ * 0.7, 0.04, CRATE_SZ * 0.7,
            topCol
        )

        halfSz = CRATE_SZ / 2 - 0.1
        crossY = CRATE_SZ + 0.05 + bounceY
        DrawLine3D(
            Vector3(wx - halfSz, crossY, wz - halfSz),
            Vector3(wx + halfSz, crossY, wz + halfSz),
            wireCol
        )
        DrawLine3D(
            Vector3(wx + halfSz, crossY, wz - halfSz),
            Vector3(wx - halfSz, crossY, wz + halfSz),
            wireCol
        )

        if onTarget
            DrawSphereEx(
                Vector3(wx, wy + bounceY, wz),
                CRATE_SZ * 0.6, 6, 6,
                RAYLIBColor(80, 255, 120, 25)
            )
        ok

        DrawCircle3D(
            Vector3(wx, 0.01, wz),
            CRATE_SZ * 0.45,
            Vector3(1, 0, 0), 90.0,
            RAYLIBColor(0, 0, 0, 50)
        )
    next

// =============================================================
// 3D Drawing: Player
// =============================================================

func soko_drawPlayer
    pos = soko_getAnimPlayerPos()
    wx = pos[1]
    wz = pos[2]
    wy = PLAYER_RAD + 0.1

    wy += sin(animTime * 3.0) * 0.05

    DrawSphereEx(
        Vector3(wx, wy, wz),
        PLAYER_RAD, 16, 16,
        RAYLIBColor(60, 120, 220, 255)
    )
    DrawSphereEx(
        Vector3(wx, wy, wz),
        PLAYER_RAD + 0.12, 10, 10,
        RAYLIBColor(80, 150, 255, 40)
    )

    eOff = 0.18
    eRad = 0.09
    pRad = 0.05
    fR = playerFaceR
    fC = playerFaceC

    ex1 = 0  ez1 = 0  ex2 = 0  ez2 = 0
    if fC = 1
        ex1 = 0.12  ez1 = -eOff  ex2 = 0.12  ez2 = eOff
    ok
    if fC = -1
        ex1 = -0.12  ez1 = -eOff  ex2 = -0.12  ez2 = eOff
    ok
    if fR = -1
        ex1 = -eOff  ez1 = -0.12  ex2 = eOff  ez2 = -0.12
    ok
    if fR = 1
        ex1 = -eOff  ez1 = 0.12  ex2 = eOff  ez2 = 0.12
    ok

    DrawSphere(Vector3(wx + ex1, wy + 0.12, wz + ez1), eRad, WHITE)
    DrawSphere(Vector3(wx + ex2, wy + 0.12, wz + ez2), eRad, WHITE)
    DrawSphere(Vector3(wx + ex1*1.3, wy + 0.12, wz + ez1*1.3), pRad, BLACK)
    DrawSphere(Vector3(wx + ex2*1.3, wy + 0.12, wz + ez2*1.3), pRad, BLACK)

    DrawCircle3D(
        Vector3(wx, 0.01, wz),
        PLAYER_RAD + 0.15,
        Vector3(1, 0, 0), 90.0,
        RAYLIBColor(0, 0, 0, 60)
    )

    arrowX = wx + fC * 0.7
    arrowZ = wz + fR * 0.7
    DrawSphere(
        Vector3(arrowX, 0.05, arrowZ),
        0.06,
        RAYLIBColor(100, 180, 255, 150)
    )

// =============================================================
// HUD
// =============================================================

func soko_drawHUD
    panelW = 240
    panelH = 135
    DrawRectangle(10, 30, panelW, panelH, Fade(BLACK, 0.75))
    DrawRectangleLines(10, 30, panelW, panelH, RAYLIBColor(100, 160, 220, 200))

    DrawText("3D SOKOBAN", 20, 38, 20, RAYLIBColor(100, 180, 255, 255))
    DrawText("Level: " + currentLevel + " / " + levelCount, 20, 63, 16, RAYLIBColor(200, 220, 255, 255))
    DrawText("Moves: " + moveCount, 20, 83, 16, RAYLIBColor(180, 200, 220, 220))
    DrawText("Pushes: " + pushCount, 20, 103, 16, RAYLIBColor(180, 200, 220, 220))

    placed = 0
    for i = 1 to len(crates)
        if soko_isTarget(crates[i][1], crates[i][2])
            placed += 1
        ok
    next
    DrawText("Crates: " + placed + " / " + len(targets), 20, 123, 16, RAYLIBColor(50, 220, 80, 255))
    DrawText("Undo: " + len(undoStack), 20, 143, 14, RAYLIBColor(150, 160, 180, 180))

    camName = "OVERHEAD"
    if cameraMode = CAM_ISOMETRIC camName = "ISOMETRIC" ok
    if cameraMode = CAM_FOLLOW    camName = "FOLLOW"    ok
    DrawRectangle(10, SCREEN_H - 60, 210, 25, Fade(BLACK, 0.6))
    DrawText("Cam: " + camName + "  [C] switch", 16, SCREEN_H - 56, 14, RAYLIBColor(150, 180, 210, 220))

    DrawRectangle(SCREEN_W - 340, SCREEN_H - 35, 330, 25, Fade(BLACK, 0.6))
    DrawText("WASD/Arrows | U: Undo | R: Reset | N/B: Level", SCREEN_W - 335, SCREEN_H - 30, 13,
             RAYLIBColor(150, 160, 180, 200))

// =============================================================
// Mini-Map
// =============================================================

func soko_drawMiniMap
    cellW = 10
    cellH = 10
    mapW = gridCols * cellW
    mapH = gridRows * cellH
    mapX = SCREEN_W - mapW - 20
    mapY = 30

    DrawRectangle(mapX - 3, mapY - 3, mapW + 6, mapH + 6, Fade(BLACK, 0.8))
    DrawRectangleLines(mapX - 3, mapY - 3, mapW + 6, mapH + 6, RAYLIBColor(100, 160, 220, 200))

    for r = 1 to gridRows
        for c = 1 to gridCols
            sx = mapX + (c - 1) * cellW
            sy = mapY + (r - 1) * cellH
            tile = grid[r][c]

            if tile = TILE_WALL
                DrawRectangle(sx, sy, cellW, cellH, RAYLIBColor(80, 75, 70, 255))
            ok
            if tile = TILE_FLOOR
                DrawRectangle(sx, sy, cellW, cellH, RAYLIBColor(50, 48, 45, 200))
            ok
            if tile = TILE_TARGET
                DrawRectangle(sx, sy, cellW, cellH, RAYLIBColor(50, 48, 45, 200))
                DrawRectangle(sx + 2, sy + 2, cellW - 4, cellH - 4, RAYLIBColor(255, 100, 80, 200))
            ok
        next
    next

    for i = 1 to len(crates)
        cx = mapX + (crates[i][2] - 1) * cellW
        cy = mapY + (crates[i][1] - 1) * cellH
        onTgt = soko_isTarget(crates[i][1], crates[i][2])
        if onTgt
            DrawRectangle(cx + 1, cy + 1, cellW - 2, cellH - 2, RAYLIBColor(50, 200, 80, 255))
        else
            DrawRectangle(cx + 1, cy + 1, cellW - 2, cellH - 2, RAYLIBColor(200, 140, 60, 255))
        ok
    next

    px = mapX + (playerC - 1) * cellW
    py = mapY + (playerR - 1) * cellH
    DrawRectangle(px + 1, py + 1, cellW - 2, cellH - 2, RAYLIBColor(80, 150, 255, 255))

    DrawText("MAP", mapX + mapW/2 - 15, mapY - 15, 12, RAYLIBColor(150, 200, 220, 200))

// =============================================================
// Title Screen
// =============================================================

func soko_drawTitleScreen
    DrawRectangleGradientV(0, 0, SCREEN_W, SCREEN_H,
        RAYLIBColor(12, 15, 25, 255), RAYLIBColor(20, 18, 30, 255))

    t1 = "3D SOKOBAN"
    t1w = MeasureText(t1, 60)
    DrawText(t1, (SCREEN_W - t1w)/2, 130, 60, RAYLIBColor(100, 180, 255, 255))

    t2 = "~ Push all crates onto the targets! ~"
    t2w = MeasureText(t2, 18)
    DrawText(t2, (SCREEN_W - t2w)/2, 205, 18, RAYLIBColor(140, 180, 220, 230))

    cy = 255
    cLines = [
        "Arrow Keys / WASD  -  Move player & push crates",
        "U / Backspace      -  Undo last move",
        "R                  -  Restart current level",
        "N / B              -  Next / Previous level",
        "C                  -  Cycle camera view",
        "",
        "Push crates (brown boxes) onto targets (red markers)",
        "Crates turn green when correctly placed",
        "Place all crates to complete the level!",
        "",
        "" + levelCount + " puzzle levels of increasing difficulty"
    ]
    for i = 1 to len(cLines)
        lw = MeasureText(cLines[i], 16)
        if i >= 7
            col = RAYLIBColor(255, 200, 100, 220)
        else
            col = RAYLIBColor(160, 190, 210, 230)
        ok
        DrawText(cLines[i], (SCREEN_W - lw)/2, cy + (i - 1) * 24, 16, col)
    next

    if floor(animTime * 2) % 2 = 0
        st = "Press ENTER or SPACE to Start"
        stw = MeasureText(st, 26)
        DrawText(st, (SCREEN_W - stw)/2, 540, 26, WHITE)
    ok

    cr = "Developed using Ring Language + RingRayLib"
    crw = MeasureText(cr, 14)
    DrawText(cr, (SCREEN_W - crw)/2, SCREEN_H - 40, 14, RAYLIBColor(100, 120, 100, 180))

// =============================================================
// Win Overlay
// =============================================================

func soko_drawWinOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.5))

    g1 = "LEVEL " + currentLevel + " COMPLETE!"
    g1w = MeasureText(g1, 45)
    DrawText(g1, (SCREEN_W - g1w)/2, 240, 45, RAYLIBColor(50, 220, 80, 255))

    sy = 310
    s1 = "Moves: " + moveCount + "     Pushes: " + pushCount
    s1w = MeasureText(s1, 22)
    DrawText(s1, (SCREEN_W - s1w)/2, sy, 22, RAYLIBColor(200, 220, 255, 255))

    starCount = 3
    tgtCount = len(targets)
    if pushCount > tgtCount * 3 starCount = 2 ok
    if pushCount > tgtCount * 5 starCount = 1 ok

    starsText = ""
    for i = 1 to starCount
        starsText += "* "
    next
    stw = MeasureText(starsText, 36)
    DrawText(starsText, (SCREEN_W - stw)/2, sy + 40, 36, RAYLIBColor(255, 215, 0, 255))

    if currentLevel < levelCount
        if floor(animTime * 2) % 2 = 0
            nt = "Press ENTER/SPACE/N for next level"
            ntw = MeasureText(nt, 20)
            DrawText(nt, (SCREEN_W - ntw)/2, sy + 100, 20, WHITE)
        ok
    else
        nt = "All levels complete! Press ENTER to restart"
        ntw = MeasureText(nt, 20)
        DrawText(nt, (SCREEN_W - ntw)/2, sy + 100, 20, RAYLIBColor(255, 215, 0, 255))
    ok

// =============================================================
// All Clear Overlay
// =============================================================

func soko_drawAllClearOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.6))

    g1 = "CONGRATULATIONS!"
    g1w = MeasureText(g1, 50)
    DrawText(g1, (SCREEN_W - g1w)/2, 220, 50, RAYLIBColor(255, 215, 0, 255))

    g2 = "You completed all " + levelCount + " levels!"
    g2w = MeasureText(g2, 24)
    DrawText(g2, (SCREEN_W - g2w)/2, 290, 24, RAYLIBColor(200, 220, 255, 255))

    if floor(animTime * 2) % 2 = 0
        rt = "Press ENTER or SPACE to play again"
        rtw = MeasureText(rt, 20)
        DrawText(rt, (SCREEN_W - rtw)/2, 360, 20, WHITE)
    ok
