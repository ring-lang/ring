/*
**  3D Sliding Puzzle (15-Puzzle) - Using RingRayLib
**  ==================================================
**  Slide numbered tiles into the correct order!
**  The classic 15-puzzle in stunning 3D.
**
**  Controls:
**    Arrow Keys / WASD  - Slide tile into the empty space
**    Mouse Click        - Click a tile adjacent to empty space
**    U / Backspace      - Undo last move
**    N                  - New shuffle (same board size)
**    R                  - Restart to title
**    C                  - Cycle camera views
**    1 / 2 / 3          - Board size: 3x3 / 4x4 / 5x5
**    ESC                - Exit
**
**  Rules:
**    - Slide tiles one at a time into the empty space
**    - Arrange all tiles in order: 1, 2, 3, ... from
**      top-left to bottom-right with the empty space last
**    - Fewer moves = better score!
**
**  Features:
**    - Three board sizes: 3x3 (8-puzzle), 4x4 (15-puzzle), 5x5 (24-puzzle)
**    - 3D numbered cubes with color gradient
**    - Smooth slide animation with ease-in-out
**    - Guaranteed solvable shuffles
**    - Tile correctness highlighting (green = correct position)
**    - Move counter and timer
**    - Full undo system
**    - Three camera modes: Front / Isometric / Overhead
**    - Particle effects on tile placement
**    - Projected number labels on 3D tiles
**    - Mini-map with numbered tiles
**    - Title, playing, and solved screens
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W        = 1024
SCREEN_H        = 768
CELL_SZ         = 3.0
TILE_GAP        = 0.2
TILE_SZ         = CELL_SZ - TILE_GAP
TILE_H          = 0.8

// Game states
ST_START        = 1
ST_PLAYING      = 2
ST_ANIMATING    = 3
ST_SOLVED       = 4

// Camera modes
CAM_FRONT       = 1
CAM_ISOMETRIC   = 2
CAM_OVERHEAD    = 3
CAM_COUNT       = 3

// Animation
ANIM_SPEED      = 8.0

// =============================================================
// Global Variables
// =============================================================

BOARD_SZ        = 4
board           = []        // board[r][c] = tile number (0 = empty)
emptyR          = 0
emptyC          = 0
moveCount       = 0
gameState       = ST_START
animTime        = 0.0

// Undo stack: [[fromR, fromC, toR, toC], ...]
undoStack       = []

// Slide animation
animActive      = false
animProgress    = 0.0
animTileVal     = 0
animFromR       = 0  animFromC = 0
animToR         = 0  animToC   = 0

// Camera
cameraMode      = CAM_FRONT
camPosX = 0.0   camPosY = 16.0  camPosZ = 14.0
camTgtX = 0.0   camTgtY = 0.0   camTgtZ = 0.0

// Particles: [x, y, z, vx, vy, vz, life, cr, cg, cb]
particles       = []

// Mouse hover
mouseHoverR     = 0
mouseHoverC     = 0

// Projection helper
projScreenX     = 0.0
projScreenY     = 0.0

// Timer
gameTimer       = 0.0

// Message
msgText         = ""
msgTimer        = 0.0

// =============================================================
// Initialize
// =============================================================

sp_initBoard()

// =============================================================
// Main Program
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Ring 3D Sliding Puzzle - RingRayLib")
SetTargetFPS(60)

camera = Camera3D(
    0, 16, 14,
    0,  0,  0,
    0,  1,  0,
    45,
    CAMERA_PERSPECTIVE
)

// =============================================================
// Main Game Loop
// =============================================================

while !WindowShouldClose()

    dt = GetFrameTime()
    animTime += dt

    // Message timer
    if msgTimer > 0
        msgTimer -= dt
        if msgTimer < 0 msgTimer = 0 ok
    ok

    // Camera toggle (always)
    if IsKeyPressed(KEY_C)
        cameraMode += 1
        if cameraMode > CAM_COUNT cameraMode = CAM_FRONT ok
    ok

    // Board size selection
    if gameState = ST_START or gameState = ST_SOLVED
        sp_checkSizeKeys()
    ok

    // Restart to title
    if IsKeyPressed(KEY_R)
        sp_initBoard()
        gameState = ST_START
    ok

    // ========== STATE UPDATES ==========

    if gameState = ST_START
        sp_checkSizeKeys()
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(0)
            sp_initBoard()
            sp_shuffle()
            gameState = ST_PLAYING
        ok
    ok

    if gameState = ST_PLAYING
        sp_updateMouseHover()
        sp_handleInput()
        sp_handleMouse()
        sp_updateParticles(dt)
        gameTimer += dt
    ok

    if gameState = ST_ANIMATING
        sp_updateSlideAnim(dt)
        sp_updateParticles(dt)
        gameTimer += dt
    ok

    if gameState = ST_SOLVED
        sp_updateParticles(dt)
        sp_checkSizeKeys()
        if IsKeyPressed(KEY_N)
            sp_initBoard()
            sp_shuffle()
            gameState = ST_PLAYING
        ok
    ok

    sp_positionCamera()

    // ========== DRAWING ==========

    BeginDrawing()
        ClearBackground(RAYLIBColor(16, 14, 24, 255))

        if gameState = ST_START
            sp_drawTitleScreen()
        else
            BeginMode3D(camera)
                sp_drawBoard3D()
                sp_drawTiles3D()
                sp_drawSlideAnim3D()
                sp_drawEmptySlot3D()
                sp_drawParticles3D()
            EndMode3D()

            sp_drawTileLabels()
            sp_drawHUD()
            sp_drawMiniMap()

            if gameState = ST_SOLVED
                sp_drawSolvedOverlay()
            ok

            if msgTimer > 0
                sp_drawMessage()
            ok
        ok

        DrawFPS(10, 10)
    EndDrawing()

end

CloseWindow()

// =============================================================
// ALL FUNCTIONS BELOW
// =============================================================

// =============================================================
// Board Initialization
// =============================================================

func sp_initBoard
    board = list(BOARD_SZ)
    for r = 1 to BOARD_SZ
        board[r] = list(BOARD_SZ)
        for c = 1 to BOARD_SZ
            board[r][c] = (r - 1) * BOARD_SZ + c
        next
    next
    // Last cell is empty (0)
    board[BOARD_SZ][BOARD_SZ] = 0
    emptyR = BOARD_SZ
    emptyC = BOARD_SZ

    moveCount = 0
    undoStack = []
    particles = []
    animActive = false
    animProgress = 0.0
    gameTimer = 0.0
    msgTimer = 0

    CELL_SZ = 12.0 / BOARD_SZ
    if CELL_SZ < 2.0 CELL_SZ = 2.0 ok
    if CELL_SZ > 3.6 CELL_SZ = 3.6 ok
    TILE_SZ = CELL_SZ - TILE_GAP

// =============================================================
// Shuffle (guaranteed solvable)
// =============================================================

func sp_shuffle
    // Perform random valid moves from solved state
    numMoves = BOARD_SZ * BOARD_SZ * 40
    lastDir = 0
    for i = 1 to numMoves
        // Collect valid directions (don't reverse last move)
        dirs = []
        // Can move tile from above into empty = empty moves up visually
        if emptyR > 1 and lastDir != 2 add(dirs, 1) ok
        if emptyR < BOARD_SZ and lastDir != 1 add(dirs, 2) ok
        if emptyC > 1 and lastDir != 4 add(dirs, 3) ok
        if emptyC < BOARD_SZ and lastDir != 3 add(dirs, 4) ok

        if len(dirs) = 0 loop ok

        d = dirs[GetRandomValue(1, len(dirs))]
        lastDir = d

        if d = 1
            // Slide tile from above into empty
            board[emptyR][emptyC] = board[emptyR - 1][emptyC]
            board[emptyR - 1][emptyC] = 0
            emptyR -= 1
        ok
        if d = 2
            board[emptyR][emptyC] = board[emptyR + 1][emptyC]
            board[emptyR + 1][emptyC] = 0
            emptyR += 1
        ok
        if d = 3
            board[emptyR][emptyC] = board[emptyR][emptyC - 1]
            board[emptyR][emptyC - 1] = 0
            emptyC -= 1
        ok
        if d = 4
            board[emptyR][emptyC] = board[emptyR][emptyC + 1]
            board[emptyR][emptyC + 1] = 0
            emptyC += 1
        ok
    next

// =============================================================
// Size Key Handling
// =============================================================

func sp_checkSizeKeys
    if IsKeyPressed(KEY_ONE)
        BOARD_SZ = 3
        sp_initBoard()
    ok
    if IsKeyPressed(KEY_TWO)
        BOARD_SZ = 4
        sp_initBoard()
    ok
    if IsKeyPressed(KEY_THREE)
        BOARD_SZ = 5
        sp_initBoard()
    ok

// =============================================================
// Input Handling
// =============================================================

func sp_handleInput
    // Arrow keys slide a tile into the empty space
    // UP arrow = slide the tile below the empty space up
    if IsKeyPressed(KEY_UP) or IsKeyPressed(KEY_W)
        if emptyR < BOARD_SZ
            sp_slideTile(emptyR + 1, emptyC)
        ok
    ok
    if IsKeyPressed(KEY_DOWN) or IsKeyPressed(KEY_S)
        if emptyR > 1
            sp_slideTile(emptyR - 1, emptyC)
        ok
    ok
    if IsKeyPressed(KEY_LEFT) or IsKeyPressed(KEY_A)
        if emptyC < BOARD_SZ
            sp_slideTile(emptyR, emptyC + 1)
        ok
    ok
    if IsKeyPressed(KEY_RIGHT) or IsKeyPressed(KEY_D)
        if emptyC > 1
            sp_slideTile(emptyR, emptyC - 1)
        ok
    ok

    // Undo
    if IsKeyPressed(KEY_U) or IsKeyPressed(KEY_BACKSPACE)
        sp_undo()
    ok

    // New shuffle
    if IsKeyPressed(KEY_N)
        sp_initBoard()
        sp_shuffle()
        gameState = ST_PLAYING
        sp_showMsg("New puzzle shuffled!")
    ok

// =============================================================
// Mouse Handling
// =============================================================

func sp_updateMouseHover
    mx = GetMouseX()
    my = GetMouseY()

    bestDist = 999999.0
    bestR = 0
    bestC = 0

    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            wx = sp_cellToX(c)
            wz = sp_cellToZ(r)
            sp_projectToScreen(wx, 0.05, wz)
            dx = projScreenX - mx
            dy = projScreenY - my
            dist = dx * dx + dy * dy
            if dist < bestDist
                bestDist = dist
                bestR = r
                bestC = c
            ok
        next
    next

    threshDist = 2000
    if BOARD_SZ >= 4 threshDist = 1600 ok
    if BOARD_SZ >= 5 threshDist = 1200 ok

    if bestDist < threshDist and bestR >= 1 and bestR <= BOARD_SZ
        mouseHoverR = bestR
        mouseHoverC = bestC
    else
        mouseHoverR = 0
        mouseHoverC = 0
    ok

func sp_handleMouse
    if IsMouseButtonPressed(0)
        if mouseHoverR >= 1 and mouseHoverR <= BOARD_SZ and
           mouseHoverC >= 1 and mouseHoverC <= BOARD_SZ
            // Check if clicked tile is adjacent to empty
            if sp_isAdjacentToEmpty(mouseHoverR, mouseHoverC)
                sp_slideTile(mouseHoverR, mouseHoverC)
            ok
        ok
    ok

func sp_isAdjacentToEmpty r, c
    if r = emptyR and c = emptyC - 1 return true ok
    if r = emptyR and c = emptyC + 1 return true ok
    if c = emptyC and r = emptyR - 1 return true ok
    if c = emptyC and r = emptyR + 1 return true ok
    return false

// =============================================================
// Slide Tile
// =============================================================

func sp_slideTile fromR, fromC
    if board[fromR][fromC] = 0 return ok
    if sp_isAdjacentToEmpty(fromR, fromC) = false return ok

    // Start animation
    animTileVal = board[fromR][fromC]
    animFromR = fromR
    animFromC = fromC
    animToR = emptyR
    animToC = emptyC
    animActive = true
    animProgress = 0.0

    // Save undo
    add(undoStack, [emptyR, emptyC, fromR, fromC])
    if len(undoStack) > 200
        del(undoStack, 1)
    ok

    // Update board immediately for state tracking
    board[emptyR][emptyC] = board[fromR][fromC]
    board[fromR][fromC] = 0
    emptyR = fromR
    emptyC = fromC
    moveCount += 1

    gameState = ST_ANIMATING

// =============================================================
// Slide Animation Update
// =============================================================

func sp_updateSlideAnim dt
    if animActive = false return ok

    animProgress += dt * ANIM_SPEED
    if animProgress >= 1.0
        animActive = false
        animProgress = 1.0

        // Spawn particles at destination
        wx = sp_cellToX(animToC)
        wz = sp_cellToZ(animToR)
        sp_spawnSlideParticles(wx, wz, animTileVal)

        // Check win
        if sp_isSolved()
            gameState = ST_SOLVED
            sp_spawnWinParticles()
            sp_showMsg("PUZZLE SOLVED!")
            return
        ok

        gameState = ST_PLAYING
    ok

// =============================================================
// Win Check
// =============================================================

func sp_isSolved
    expected = 1
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if r = BOARD_SZ and c = BOARD_SZ
                if board[r][c] != 0 return false ok
            else
                if board[r][c] != expected return false ok
            ok
            expected += 1
        next
    next
    return true

// =============================================================
// Check if tile is in correct position
// =============================================================

func sp_isCorrectPos r, c
    if board[r][c] = 0 return false ok
    expected = (r - 1) * BOARD_SZ + c
    if board[r][c] = expected return true ok
    return false

// =============================================================
// Undo
// =============================================================

func sp_undo
    if len(undoStack) = 0
        sp_showMsg("Nothing to undo!")
        return
    ok
    if animActive return ok

    last = undoStack[len(undoStack)]
    del(undoStack, len(undoStack))

    // last = [toR, toC, fromR, fromC] where tile moved from (fromR,fromC) to (toR,toC)
    // To undo: move tile back from (toR,toC) to (fromR,fromC)
    toR = last[1]
    toC = last[2]
    fromR = last[3]
    fromC = last[4]

    // Currently empty is at (fromR,fromC), tile is at (toR,toC)
    board[fromR][fromC] = board[toR][toC]
    board[toR][toC] = 0
    emptyR = toR
    emptyC = toC
    moveCount -= 1
    if moveCount < 0 moveCount = 0 ok
    sp_showMsg("Move undone")

// =============================================================
// Helpers
// =============================================================

func sp_cellToX c
    return (c - 1) * CELL_SZ - (BOARD_SZ - 1) * CELL_SZ / 2

func sp_cellToZ r
    return (r - 1) * CELL_SZ - (BOARD_SZ - 1) * CELL_SZ / 2

func sp_showMsg text
    msgText = text
    msgTimer = 2.0

// =============================================================
// Tile Color (gradient from blue to warm based on number)
// =============================================================

func sp_tileColor val
    maxVal = BOARD_SZ * BOARD_SZ - 1
    if maxVal < 1 maxVal = 1 ok
    t = (val - 1.0) / maxVal

    // Blue -> Teal -> Green -> Yellow -> Orange
    if t < 0.25
        tt = t / 0.25
        cr = floor(50 + tt * 20)
        cg = floor(120 + tt * 80)
        cb = floor(200 - tt * 40)
    but t < 0.5
        tt = (t - 0.25) / 0.25
        cr = floor(70 + tt * 80)
        cg = floor(200 - tt * 30)
        cb = floor(160 - tt * 80)
    but t < 0.75
        tt = (t - 0.5) / 0.25
        cr = floor(150 + tt * 70)
        cg = floor(170 - tt * 30)
        cb = floor(80 - tt * 40)
    else
        tt = (t - 0.75) / 0.25
        cr = floor(220 + tt * 35)
        cg = floor(140 - tt * 50)
        cb = floor(40 + tt * 20)
    ok

    if cr > 255 cr = 255 ok
    if cg > 255 cg = 255 ok
    if cb > 255 cb = 255 ok

    return RAYLIBColor(cr, cg, cb, 255)

func sp_tileWireColor val
    maxVal = BOARD_SZ * BOARD_SZ - 1
    if maxVal < 1 maxVal = 1 ok
    t = (val - 1.0) / maxVal

    cr = floor(80 + t * 120)
    cg = floor(80 + (1.0 - t) * 80)
    cb = floor(80 + (1.0 - t) * 100)

    if cr > 220 cr = 220 ok
    if cg > 200 cg = 200 ok
    if cb > 200 cb = 200 ok

    return RAYLIBColor(cr, cg, cb, 180)

// =============================================================
// 3D-to-Screen Projection
// =============================================================

func sp_projectToScreen wx, wy, wz
    fwdX = camTgtX - camPosX
    fwdY = camTgtY - camPosY
    fwdZ = camTgtZ - camPosZ
    fLen = sqrt(fwdX*fwdX + fwdY*fwdY + fwdZ*fwdZ)
    if fLen < 0.0001
        projScreenX = SCREEN_W / 2
        projScreenY = SCREEN_H / 2
        return
    ok
    fwdX = fwdX / fLen
    fwdY = fwdY / fLen
    fwdZ = fwdZ / fLen
    rightX = -fwdZ
    rightY = 0
    rightZ = fwdX
    rLen = sqrt(rightX*rightX + rightY*rightY + rightZ*rightZ)
    if rLen < 0.0001
        projScreenX = SCREEN_W / 2
        projScreenY = SCREEN_H / 2
        return
    ok
    rightX = rightX / rLen
    rightY = rightY / rLen
    rightZ = rightZ / rLen
    upX = rightY * fwdZ - rightZ * fwdY
    upY = rightZ * fwdX - rightX * fwdZ
    upZ = rightX * fwdY - rightY * fwdX
    dx = wx - camPosX
    dy = wy - camPosY
    dz = wz - camPosZ
    dotFwd   = dx * fwdX   + dy * fwdY   + dz * fwdZ
    dotRight = dx * rightX + dy * rightY + dz * rightZ
    dotUp    = dx * upX    + dy * upY    + dz * upZ
    if dotFwd < 0.01
        projScreenX = -9999
        projScreenY = -9999
        return
    ok
    fovRad = 45.0 * 3.14159265 / 180.0
    tanHalf = tan(fovRad / 2.0)
    aspect = SCREEN_W * 1.0 / SCREEN_H
    ndcX = (dotRight / dotFwd) / (tanHalf * aspect)
    ndcY = (dotUp / dotFwd) / tanHalf
    projScreenX = (ndcX * 0.5 + 0.5) * SCREEN_W
    projScreenY = (1.0 - (ndcY * 0.5 + 0.5)) * SCREEN_H

// =============================================================
// Particles
// =============================================================

func sp_spawnSlideParticles wx, wz, val
    col = sp_tileColor(val)
    for i = 1 to 6
        vx = (GetRandomValue(-100, 100) / 100.0) * 1.5
        vy = (GetRandomValue(100, 350) / 100.0)
        vz = (GetRandomValue(-100, 100) / 100.0) * 1.5
        cr = GetRandomValue(180, 255)
        cg = GetRandomValue(180, 255)
        cb = GetRandomValue(100, 200)
        add(particles, [wx, 0.5, wz, vx, vy, vz, 0.8, cr, cg, cb])
    next

func sp_spawnWinParticles
    for i = 1 to 80
        wx = (GetRandomValue(-600, 600) / 100.0)
        wz = (GetRandomValue(-600, 600) / 100.0)
        vx = (GetRandomValue(-200, 200) / 100.0)
        vy = (GetRandomValue(400, 900) / 100.0)
        vz = (GetRandomValue(-200, 200) / 100.0)
        cr = GetRandomValue(150, 255)
        cg = GetRandomValue(200, 255)
        cb = GetRandomValue(50, 255)
        add(particles, [wx, 0.5, wz, vx, vy, vz, 2.5, cr, cg, cb])
    next

func sp_updateParticles dt
    i = 1
    while i <= len(particles)
        particles[i][1] += particles[i][4] * dt
        particles[i][2] += particles[i][5] * dt
        particles[i][3] += particles[i][6] * dt
        particles[i][5] -= 6.0 * dt
        particles[i][7] -= dt
        if particles[i][7] <= 0
            del(particles, i)
        else
            i += 1
        ok
    end

func sp_drawParticles3D
    for i = 1 to len(particles)
        p = particles[i]
        alpha = floor((p[7] / 2.5) * 255)
        if alpha > 255 alpha = 255 ok
        if alpha < 0 alpha = 0 ok
        sz = 0.04 + p[7] * 0.05
        DrawSphereEx(
            Vector3(p[1], p[2], p[3]),
            sz, 4, 4,
            RAYLIBColor(p[8], p[9], p[10], alpha)
        )
    next

// =============================================================
// Camera
// =============================================================

func sp_positionCamera
    boardW = BOARD_SZ * CELL_SZ
    maxDim = boardW

    goalX = 0  goalY = 0  goalZ = 0
    tgtX = 0   tgtY = 0   tgtZ = 0

    if cameraMode = CAM_FRONT
        goalX = 0
        goalY = maxDim * 0.85 + 4.0
        goalZ = maxDim * 0.75 + 4.0
        tgtX = 0
        tgtY = 0.3
        tgtZ = -0.5
    ok
    if cameraMode = CAM_ISOMETRIC
        goalX = maxDim * 0.65 + 2.0
        goalY = maxDim * 0.75 + 3.0
        goalZ = maxDim * 0.65 + 2.0
        tgtX = 0
        tgtY = 0.3
        tgtZ = 0
    ok
    if cameraMode = CAM_OVERHEAD
        goalX = 0
        goalY = maxDim * 1.1 + 6.0
        goalZ = 0.1
        tgtX = 0
        tgtY = 0
        tgtZ = 0
    ok

    lerpSpd = 0.06
    camPosX += (goalX - camPosX) * lerpSpd
    camPosY += (goalY - camPosY) * lerpSpd
    camPosZ += (goalZ - camPosZ) * lerpSpd
    camTgtX += (tgtX - camTgtX) * lerpSpd
    camTgtY += (tgtY - camTgtY) * lerpSpd
    camTgtZ += (tgtZ - camTgtZ) * lerpSpd

    camera.position.x = camPosX
    camera.position.y = camPosY
    camera.position.z = camPosZ
    camera.target.x   = camTgtX
    camera.target.y   = camTgtY
    camera.target.z   = camTgtZ

// =============================================================
// 3D Drawing: Board
// =============================================================

func sp_drawBoard3D
    boardW = BOARD_SZ * CELL_SZ

    // Board slab
    slabH = 0.35
    DrawCube(Vector3(0, -slabH/2, 0),
             boardW + 0.8, slabH, boardW + 0.8,
             RAYLIBColor(50, 45, 60, 255))
    DrawCubeWires(Vector3(0, -slabH/2, 0),
                  boardW + 0.8, slabH, boardW + 0.8,
                  RAYLIBColor(35, 30, 42, 200))

    // Cell slots (darker recessed look)
    slotH = 0.04
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            wx = sp_cellToX(c)
            wz = sp_cellToZ(r)
            DrawCube(Vector3(wx, slotH/2, wz),
                     TILE_SZ + 0.05, slotH, TILE_SZ + 0.05,
                     RAYLIBColor(35, 30, 45, 255))
        next
    next

    // Border frame
    bThick = 0.2
    bH = 0.2
    halfE = boardW / 2 + 0.3
    edgeCol = RAYLIBColor(70, 60, 80, 255)
    DrawCube(Vector3(0, bH/2, -halfE), boardW + 0.8, bH, bThick, edgeCol)
    DrawCube(Vector3(0, bH/2, halfE),  boardW + 0.8, bH, bThick, edgeCol)
    DrawCube(Vector3(-halfE, bH/2, 0), bThick, bH, boardW + 0.5, edgeCol)
    DrawCube(Vector3(halfE, bH/2, 0),  bThick, bH, boardW + 0.5, edgeCol)

    // Table beneath
    DrawPlane(Vector3(0, -slabH - 0.01, 0), Vector2(40, 40),
              RAYLIBColor(10, 8, 16, 255))

// =============================================================
// 3D Drawing: Empty Slot
// =============================================================

func sp_drawEmptySlot3D
    wx = sp_cellToX(emptyC)
    wz = sp_cellToZ(emptyR)

    // Glowing empty indicator
    pulse = 0.4 + sin(animTime * 3.0) * 0.3
    alpha = floor(60 * pulse)
    DrawCube(Vector3(wx, 0.03, wz), TILE_SZ * 0.8, 0.02, TILE_SZ * 0.8,
             RAYLIBColor(100, 180, 255, alpha))

// =============================================================
// 3D Drawing: Tiles (non-animating)
// =============================================================

func sp_drawTiles3D
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            val = board[r][c]
            if val = 0 loop ok

            // Skip if this tile is currently animating
            if animActive
                if r = animToR and c = animToC loop ok
            ok

            wx = sp_cellToX(c)
            wz = sp_cellToZ(r)

            isCorrect = sp_isCorrectPos(r, c)

            // Hover highlight
            isHover = false
            if mouseHoverR = r and mouseHoverC = c
                if sp_isAdjacentToEmpty(r, c)
                    isHover = true
                ok
            ok

            sp_drawTileCube(wx, wz, val, isCorrect, isHover, 1.0)
        next
    next

// =============================================================
// 3D Drawing: Slide Animation
// =============================================================

func sp_drawSlideAnim3D
    if animActive = false return ok

    t = animProgress
    smooth = t * t * (3.0 - 2.0 * t)

    fromX = sp_cellToX(animFromC)
    fromZ = sp_cellToZ(animFromR)
    toX   = sp_cellToX(animToC)
    toZ   = sp_cellToZ(animToR)

    wx = fromX + (toX - fromX) * smooth
    wz = fromZ + (toZ - fromZ) * smooth

    // Slight lift during slide
    lift = sin(t * 3.14159265) * 0.15

    sp_drawTileCubeAt(wx, lift, wz, animTileVal, false, false, 1.0)

// =============================================================
// Draw Single Tile Cube
// =============================================================

func sp_drawTileCube wx, wz, val, isCorrect, isHover, scale
    sp_drawTileCubeAt(wx, 0, wz, val, isCorrect, isHover, scale)

func sp_drawTileCubeAt wx, wy, wz, val, isCorrect, isHover, scale
    h = TILE_H * scale
    tSz = TILE_SZ * scale

    col = sp_tileColor(val)
    wireCol = sp_tileWireColor(val)

    DrawCube(Vector3(wx, wy + h/2 + 0.05, wz), tSz, h, tSz, col)
    DrawCubeWires(Vector3(wx, wy + h/2 + 0.05, wz), tSz, h, tSz, wireCol)

    // Top face highlight
    topY = wy + h + 0.06
    highlightSz = tSz * 0.5
    DrawCube(Vector3(wx, topY, wz), highlightSz, 0.02, highlightSz,
             RAYLIBColor(255, 255, 255, 50))

    // Green tint for correct position
    if isCorrect
        DrawCube(Vector3(wx, wy + h/2 + 0.05, wz),
                 tSz + 0.02, h + 0.02, tSz + 0.02,
                 RAYLIBColor(0, 255, 80, 40))
    ok

    // Hover glow
    if isHover
        pulse = 0.5 + sin(animTime * 5.0) * 0.5
        gAlpha = floor(60 * pulse)
        DrawCube(Vector3(wx, wy + h/2 + 0.05, wz),
                 tSz + 0.08, h + 0.08, tSz + 0.08,
                 RAYLIBColor(255, 255, 200, gAlpha))
    ok

// =============================================================
// 2D Tile Value Labels
// =============================================================

func sp_drawTileLabels
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            val = board[r][c]
            if val = 0 loop ok

            // Skip animating tile at destination (it's still moving)
            if animActive
                if r = animToR and c = animToC loop ok
            ok

            wx = sp_cellToX(c)
            wz = sp_cellToZ(r)

            sp_projectToScreen(wx, TILE_H + 0.15, wz)
            if projScreenX < -100 or projScreenX > SCREEN_W + 100 loop ok
            if projScreenY < -100 or projScreenY > SCREEN_H + 100 loop ok

            valStr = "" + val
            fontSize = 28
            if BOARD_SZ >= 5 fontSize = 22 ok
            if val >= 10 fontSize = fontSize - 2 ok

            txtW = MeasureText(valStr, fontSize)
            sx = floor(projScreenX) - txtW / 2
            sy = floor(projScreenY) - fontSize / 2

            // Background pill
            DrawRectangle(sx - 5, sy - 3, txtW + 10, fontSize + 6,
                          RAYLIBColor(0, 0, 0, 160))

            DrawText(valStr, sx, sy, fontSize, WHITE)
        next
    next

    // Also draw label for animating tile
    if animActive
        t = animProgress
        smooth = t * t * (3.0 - 2.0 * t)
        fromX = sp_cellToX(animFromC)
        fromZ = sp_cellToZ(animFromR)
        toX   = sp_cellToX(animToC)
        toZ   = sp_cellToZ(animToR)
        wx = fromX + (toX - fromX) * smooth
        wz = fromZ + (toZ - fromZ) * smooth
        lift = sin(t * 3.14159265) * 0.15

        sp_projectToScreen(wx, TILE_H + 0.15 + lift, wz)
        if projScreenX > -100 and projScreenX < SCREEN_W + 100
            if projScreenY > -100 and projScreenY < SCREEN_H + 100
                valStr = "" + animTileVal
                fontSize = 28
                if BOARD_SZ >= 5 fontSize = 22 ok
                if animTileVal >= 10 fontSize = fontSize - 2 ok
                txtW = MeasureText(valStr, fontSize)
                sx = floor(projScreenX) - txtW / 2
                sy = floor(projScreenY) - fontSize / 2
                DrawRectangle(sx - 5, sy - 3, txtW + 10, fontSize + 6,
                              RAYLIBColor(0, 0, 0, 160))
                DrawText(valStr, sx, sy, fontSize, WHITE)
            ok
        ok
    ok

// =============================================================
// HUD
// =============================================================

func sp_drawHUD
    panelW = 250
    panelH = 140
    DrawRectangle(10, 30, panelW, panelH, Fade(BLACK, 0.75))
    DrawRectangleLines(10, 30, panelW, panelH, RAYLIBColor(100, 160, 220, 200))

    pName = "8-PUZZLE"
    if BOARD_SZ = 4 pName = "15-PUZZLE" ok
    if BOARD_SZ = 5 pName = "24-PUZZLE" ok
    DrawText(pName, 20, 38, 22, RAYLIBColor(100, 180, 240, 255))

    DrawText("Board: " + BOARD_SZ + "x" + BOARD_SZ, 20, 66, 14,
             RAYLIBColor(160, 180, 200, 200))

    // Moves
    DrawText("Moves: " + moveCount, 20, 84, 18, RAYLIBColor(255, 255, 255, 240))

    // Timer
    mins = floor(gameTimer / 60)
    secs = floor(gameTimer) % 60
    if secs < 10
        timeStr = "" + mins + ":0" + secs
    else
        timeStr = "" + mins + ":" + secs
    ok
    DrawText("Time: " + timeStr, 20, 108, 16,
             RAYLIBColor(200, 200, 220, 200))

    // Correct count
    correctCount = 0
    totalTiles = BOARD_SZ * BOARD_SZ - 1
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if sp_isCorrectPos(r, c)
                correctCount += 1
            ok
        next
    next
    DrawText("Correct: " + correctCount + "/" + totalTiles, 20, 130, 14,
             RAYLIBColor(80, 220, 80, 220))

    // Progress bar
    barX = 20
    barY = 150
    barW = 220
    barH = 10
    DrawRectangle(barX, barY, barW, barH, RAYLIBColor(40, 40, 50, 200))
    if totalTiles > 0
        fillW = floor(barW * correctCount / totalTiles)
        if fillW > 0
            DrawRectangle(barX, barY, fillW, barH,
                          RAYLIBColor(80, 200, 80, 220))
        ok
    ok
    DrawRectangleLines(barX, barY, barW, barH, RAYLIBColor(120, 120, 140, 180))

    // Camera
    camName = "FRONT"
    if cameraMode = CAM_ISOMETRIC camName = "ISOMETRIC" ok
    if cameraMode = CAM_OVERHEAD  camName = "OVERHEAD"  ok
    DrawRectangle(10, SCREEN_H - 60, 220, 25, Fade(BLACK, 0.6))
    DrawText("Cam: " + camName + "  [C] switch", 16, SCREEN_H - 56, 14,
             RAYLIBColor(150, 180, 210, 220))

    // Controls
    DrawRectangle(SCREEN_W - 480, SCREEN_H - 35, 470, 25, Fade(BLACK, 0.6))
    DrawText("Arrows: Slide | Click: Move tile | U: Undo | N: New | R: Title",
             SCREEN_W - 475, SCREEN_H - 30, 12, RAYLIBColor(150, 160, 180, 200))

// =============================================================
// Mini Map
// =============================================================

func sp_drawMiniMap
    cellW = 28
    if BOARD_SZ >= 5 cellW = 22 ok
    mapW = BOARD_SZ * cellW + 4
    mapH = BOARD_SZ * cellW + 4
    mapX = SCREEN_W - mapW - 15
    mapY = 30

    DrawRectangle(mapX - 3, mapY - 3, mapW + 6, mapH + 6, Fade(BLACK, 0.8))
    DrawRectangleLines(mapX - 3, mapY - 3, mapW + 6, mapH + 6,
                       RAYLIBColor(100, 160, 220, 200))

    DrawRectangle(mapX, mapY, mapW, mapH, RAYLIBColor(50, 45, 60, 230))

    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            tx = mapX + 2 + (c - 1) * cellW
            ty = mapY + 2 + (r - 1) * cellW
            tw = cellW - 2
            th = cellW - 2

            val = board[r][c]
            if val = 0
                DrawRectangle(tx, ty, tw, th, RAYLIBColor(30, 25, 40, 200))
            else
                col = sp_tileColor(val)
                DrawRectangle(tx, ty, tw, th, col)

                if sp_isCorrectPos(r, c)
                    DrawRectangle(tx, ty, tw, th, RAYLIBColor(0, 255, 0, 40))
                ok

                valStr = "" + val
                fs = 11
                if val >= 10 fs = 9 ok
                vw = MeasureText(valStr, fs)
                DrawText(valStr, tx + (tw - vw)/2, ty + (th - fs)/2,
                         fs, WHITE)
            ok

            DrawRectangleLines(tx, ty, tw, th,
                               RAYLIBColor(60, 50, 70, 150))
        next
    next

    DrawText("MAP", mapX + mapW/2 - 15, mapY - 16, 12,
             RAYLIBColor(100, 160, 220, 200))

// =============================================================
// Title Screen
// =============================================================

func sp_drawTitleScreen
    DrawRectangleGradientV(0, 0, SCREEN_W, SCREEN_H,
        RAYLIBColor(14, 12, 22, 255), RAYLIBColor(24, 20, 34, 255))

    t1 = "SLIDING PUZZLE"
    t1w = MeasureText(t1, 56)
    DrawText(t1, (SCREEN_W - t1w)/2, 40, 56, RAYLIBColor(100, 180, 240, 255))

    t1b = "3D EDITION"
    t1bw = MeasureText(t1b, 22)
    DrawText(t1b, (SCREEN_W - t1bw)/2, 105, 22, RAYLIBColor(140, 200, 255, 230))

    // Puzzle name
    pName = "8-Puzzle (3x3)"
    if BOARD_SZ = 4 pName = "15-Puzzle (4x4)" ok
    if BOARD_SZ = 5 pName = "24-Puzzle (5x5)" ok
    pnw = MeasureText(pName, 20)
    DrawText(pName, (SCREEN_W - pnw)/2, 140, 20, RAYLIBColor(200, 220, 255, 230))

    // Line
    lx1 = 200
    lx2 = SCREEN_W - 200
    ly = 172
    DrawLine(lx1, ly, lx2, ly, RAYLIBColor(100, 160, 220, 180))

    // Sample tile row
    sampleN = BOARD_SZ * BOARD_SZ - 1
    tileW = 36
    startX = (SCREEN_W - sampleN * (tileW + 3)) / 2
    for i = 1 to sampleN
        col = sp_tileColor(i)
        sx = startX + (i - 1) * (tileW + 3)
        DrawRectangle(sx, 182, tileW, 24, col)
        vs = "" + i
        fs = 10
        if i >= 10 fs = 8 ok
        vw = MeasureText(vs, fs)
        DrawText(vs, sx + (tileW - vw)/2, 182 + (24 - fs)/2, fs, WHITE)
    next

    cy = 225
    cLines = [
        "Arrow Keys / WASD      -   Slide tile into empty space",
        "Mouse Click            -   Click tile next to empty space",
        "U / Backspace          -   Undo last move",
        "N                      -   New shuffle (same board size)",
        "R                      -   Return to title screen",
        "C                      -   Cycle camera view",
        "",
        "Board Sizes:",
        "  1 = 3x3 (8-puzzle)    Easy - great for beginners",
        "  2 = 4x4 (15-puzzle)   Classic - the original puzzle!",
        "  3 = 5x5 (24-puzzle)   Hard - a real challenge!",
        "",
        "Rules:",
        "  Slide numbered tiles one at a time into the empty space.",
        "  Arrange all tiles in order: 1, 2, 3, ... from top-left",
        "  to bottom-right, with the empty space in the last corner.",
        "  Green tint = tile is in the correct position."
    ]
    for i = 1 to len(cLines)
        lw = MeasureText(cLines[i], 14)
        if i >= 8
            col = RAYLIBColor(200, 220, 255, 210)
        else
            col = RAYLIBColor(150, 170, 200, 230)
        ok
        DrawText(cLines[i], (SCREEN_W - lw)/2, cy + (i - 1) * 21, 14, col)
    next

    if floor(animTime * 2) % 2 = 0
        st2 = "Click or Press ENTER / SPACE to Start"
        st2w = MeasureText(st2, 26)
        DrawText(st2, (SCREEN_W - st2w)/2, 610, 26, WHITE)
    ok

    cr = "Developed using Ring Language + RingRayLib"
    crw = MeasureText(cr, 14)
    DrawText(cr, (SCREEN_W - crw)/2, SCREEN_H - 35, 14,
             RAYLIBColor(80, 100, 80, 180))

// =============================================================
// Solved Overlay
// =============================================================

func sp_drawSolvedOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.5))

    pName = "8-PUZZLE"
    if BOARD_SZ = 4 pName = "15-PUZZLE" ok
    if BOARD_SZ = 5 pName = "24-PUZZLE" ok

    g1 = "" + pName + " SOLVED!"
    g1w = MeasureText(g1, 48)
    pulse = floor(220 + sin(animTime * 3.0) * 35)
    DrawText(g1, (SCREEN_W - g1w)/2, 170, 48,
             RAYLIBColor(100, 220, 255, pulse))

    g2 = "Moves: " + moveCount
    g2w = MeasureText(g2, 28)
    DrawText(g2, (SCREEN_W - g2w)/2, 240, 28, RAYLIBColor(255, 255, 255, 240))

    // Timer
    mins = floor(gameTimer / 60)
    secs = floor(gameTimer) % 60
    if secs < 10
        timeStr = "" + mins + ":0" + secs
    else
        timeStr = "" + mins + ":" + secs
    ok
    ts = "Time: " + timeStr
    tsw = MeasureText(ts, 22)
    DrawText(ts, (SCREEN_W - tsw)/2, 280, 22, RAYLIBColor(200, 200, 220, 220))

    if floor(animTime * 2) % 2 = 0
        rt = "Press N for new puzzle  |  R for title screen"
        rtw = MeasureText(rt, 16)
        DrawText(rt, (SCREEN_W - rtw)/2, 340, 16, WHITE)
    ok

    ss = "Change size: 1=3x3  2=4x4  3=5x5"
    ssw = MeasureText(ss, 14)
    DrawText(ss, (SCREEN_W - ssw)/2, 375, 14, RAYLIBColor(180, 200, 220, 200))

// =============================================================
// Message Overlay
// =============================================================

func sp_drawMessage
    alpha = floor((msgTimer / 2.0) * 255)
    if alpha > 255 alpha = 255 ok
    if alpha < 0 alpha = 0 ok

    mw = MeasureText(msgText, 24)
    mx = (SCREEN_W - mw) / 2
    my = SCREEN_H / 2 + 140

    DrawRectangle(mx - 15, my - 8, mw + 30, 40,
                  RAYLIBColor(0, 0, 0, floor(alpha * 0.7)))
    DrawText(msgText, mx, my, 24,
             RAYLIBColor(100, 200, 255, alpha))
