/*
**  3D Knight's Tour - Using RingRayLib
**  ======================================
**  Complete a full tour of the chessboard with a knight!
**  Visit every square exactly once using only L-shaped moves.
**
**  Controls:
**    Arrow Keys / WASD  - Move cursor on the board
**    Mouse              - Hover and click valid moves
**    ENTER / SPACE      - Move knight to cursor position
**    U / Backspace      - Undo last move
**    H                  - Toggle Warnsdorff hints
**    S                  - Auto-solve from current position
**    R                  - Restart current board
**    C                  - Cycle camera views
**    1 / 2 / 3 / 4      - Board size: 5x5 / 6x6 / 7x7 / 8x8
**    ESC                - Exit
**
**  Goal:
**    Visit all NxN squares exactly once using L-shaped knight
**    moves (2+1 squares). If you get stuck with no valid moves
**    remaining, you lose. Visit all squares to win!
**
**  Features:
**    - Four board sizes: 5x5, 6x6, 7x7, 8x8
**    - Smooth knight hop animation with arc trajectory
**    - Numbered visited tiles with color gradient (cool->warm)
**    - Valid move highlighting with Warnsdorff degree hints
**    - Auto-solver using Warnsdorff's heuristic
**    - Full undo system (unlimited steps)
**    - Three camera modes: Front / Isometric / Overhead
**    - Particle trail on knight landing
**    - Timer and move counter
**    - Mini-map overlay with path visualization
**    - Title, playing, won, and stuck screens
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W        = 1024
SCREEN_H        = 768
CELL_SZ         = 2.0

// Cell states
CELL_EMPTY      = 0
CELL_VISITED    = 1
CELL_KNIGHT     = 2

// Game states
ST_START        = 1
ST_PLAYING      = 2
ST_ANIMATING    = 3
ST_WON          = 4
ST_STUCK        = 5

// Camera modes
CAM_FRONT       = 1
CAM_ISOMETRIC   = 2
CAM_OVERHEAD    = 3
CAM_COUNT       = 3

// Knight move offsets (8 L-shaped moves)
KNIGHT_DR       = [-2, -2, -1, -1,  1,  1,  2,  2]
KNIGHT_DC       = [-1,  1, -2,  2, -2,  2, -1,  1]

// =============================================================
// Global Variables
// =============================================================

BOARD_SZ        = 8
board           = []
visitOrder      = []        // visitOrder[r][c] = move number (1..N*N)
moveNumber      = 0
totalCells      = 0

knightR         = 1
knightC         = 1
cursorR         = 1
cursorC         = 1

gameState       = ST_START
animTime        = 0.0

// Undo stack: [[fromR, fromC], ...]
undoStack       = []

// Animation
animActive      = false
animProgress    = 0.0
animFromR       = 0     animFromC = 0
animToR         = 0     animToC   = 0
animSpeed       = 3.5

// Camera
cameraMode      = CAM_FRONT
camPosX = 0.0   camPosY = 14.0  camPosZ = 12.0
camTgtX = 0.0   camTgtY = 0.0   camTgtZ = 0.0

// Mouse hover
mouseHoverR     = 0
mouseHoverC     = 0
projScreenX     = 0.0
projScreenY     = 0.0

// Particles: [x, y, z, vx, vy, vz, life, cr, cg, cb]
particles       = []

// Hints
showHints       = true

// Timer
gameTimer       = 0.0

// Auto-solve
autoSolving     = false
autoSolveTimer  = 0.0
autoSolveDelay  = 0.15

// Valid moves cache
validMoves      = []

// Message
msgText         = ""
msgTimer        = 0.0

// =============================================================
// Initialize
// =============================================================

kt_initBoard()

// =============================================================
// Main Program
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Ring 3D Knight's Tour - RingRayLib")
SetTargetFPS(60)

camera = Camera3D(
    0, 14, 12,
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

    // Camera toggle (always available)
    if IsKeyPressed(KEY_C)
        cameraMode += 1
        if cameraMode > CAM_COUNT cameraMode = CAM_FRONT ok
    ok

    // Board size selection (title/won/stuck screens)
    if gameState = ST_START or gameState = ST_WON or gameState = ST_STUCK
        if IsKeyPressed(KEY_ONE)
            BOARD_SZ = 5
            kt_initBoard()
        ok
        if IsKeyPressed(KEY_TWO)
            BOARD_SZ = 6
            kt_initBoard()
        ok
        if IsKeyPressed(KEY_THREE)
            BOARD_SZ = 7
            kt_initBoard()
        ok
        if IsKeyPressed(KEY_FOUR)
            BOARD_SZ = 8
            kt_initBoard()
        ok
    ok

    // Restart
    if IsKeyPressed(KEY_R)
        kt_initBoard()
        gameState = ST_PLAYING
    ok

    // ========== STATE UPDATES ==========

    if gameState = ST_START
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(0)
            kt_initBoard()
            gameState = ST_PLAYING
        ok
    ok

    if gameState = ST_PLAYING
        kt_updateMouseHover()
        kt_computeValidMoves()

        if autoSolving
            autoSolveTimer += dt
            if autoSolveTimer >= autoSolveDelay
                autoSolveTimer = 0
                kt_autoSolveStep()
            ok
        else
            kt_handleInput()
            kt_handleMouse()
        ok

        gameTimer += dt
        kt_updateParticles(dt)
    ok

    if gameState = ST_ANIMATING
        kt_updateAnimation(dt)
        kt_updateParticles(dt)
    ok

    if gameState = ST_WON or gameState = ST_STUCK
        kt_updateParticles(dt)
        if IsKeyPressed(KEY_R)
            kt_initBoard()
            gameState = ST_PLAYING
        ok
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            kt_initBoard()
            gameState = ST_START
        ok
    ok

    kt_positionCamera()

    // ========== DRAWING ==========

    BeginDrawing()
        ClearBackground(RAYLIBColor(12, 15, 25, 255))

        if gameState = ST_START
            kt_drawTitleScreen()
        else
            BeginMode3D(camera)
                kt_drawBoard3D()
                kt_drawVisitedTiles3D()
                kt_drawValidMoves3D()
                kt_drawKnight3D()
                kt_drawCursor3D()
                kt_drawParticles3D()
            EndMode3D()

            kt_drawHUD()
            kt_drawMiniMap()

            if gameState = ST_WON
                kt_drawWonOverlay()
            ok
            if gameState = ST_STUCK
                kt_drawStuckOverlay()
            ok

            if msgTimer > 0
                kt_drawMessage()
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

func kt_initBoard
    totalCells = BOARD_SZ * BOARD_SZ
    board = list(BOARD_SZ)
    visitOrder = list(BOARD_SZ)
    for r = 1 to BOARD_SZ
        board[r] = list(BOARD_SZ)
        visitOrder[r] = list(BOARD_SZ)
        for c = 1 to BOARD_SZ
            board[r][c] = CELL_EMPTY
            visitOrder[r][c] = 0
        next
    next

    // Place knight at a corner for best solvability
    knightR = 1
    knightC = 1
    board[knightR][knightC] = CELL_KNIGHT
    moveNumber = 1
    visitOrder[knightR][knightC] = 1

    cursorR = knightR
    cursorC = knightC
    undoStack = []
    particles = []
    validMoves = []
    animActive = false
    animProgress = 0.0
    gameTimer = 0.0
    autoSolving = false
    autoSolveTimer = 0.0
    msgTimer = 0

    CELL_SZ = 14.0 / BOARD_SZ
    if CELL_SZ < 1.4 CELL_SZ = 1.4 ok
    if CELL_SZ > 2.4 CELL_SZ = 2.4 ok

    kt_computeValidMoves()

// =============================================================
// Input Handling
// =============================================================

func kt_handleInput
    // Cursor movement
    if IsKeyPressed(KEY_UP) or IsKeyPressed(KEY_W)
        cursorR -= 1
        if cursorR < 1 cursorR = 1 ok
    ok
    if IsKeyPressed(KEY_DOWN) or IsKeyPressed(KEY_S)
        cursorR += 1
        if cursorR > BOARD_SZ cursorR = BOARD_SZ ok
    ok
    if IsKeyPressed(KEY_LEFT) or IsKeyPressed(KEY_A)
        cursorC -= 1
        if cursorC < 1 cursorC = 1 ok
    ok
    if IsKeyPressed(KEY_RIGHT) or IsKeyPressed(KEY_D)
        cursorC += 1
        if cursorC > BOARD_SZ cursorC = BOARD_SZ ok
    ok

    // Place / move knight
    if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
        kt_tryMove(cursorR, cursorC)
    ok

    // Undo
    if IsKeyPressed(KEY_U) or IsKeyPressed(KEY_BACKSPACE)
        kt_undo()
    ok

    // Toggle hints
    if IsKeyPressed(KEY_H)
        if showHints = true
            showHints = false
            kt_showMsg("Hints OFF")
        else
            showHints = true
            kt_showMsg("Hints ON")
        ok
    ok

    // Auto-solve
    if IsKeyPressed(KEY_S)
        if autoSolving = true
            autoSolving = false
            kt_showMsg("Auto-solve stopped")
        else
            autoSolving = true
            autoSolveTimer = 0
            kt_showMsg("Auto-solving...")
        ok
    ok

// =============================================================
// Mouse Handling
// =============================================================

func kt_updateMouseHover
    mx = GetMouseX()
    my = GetMouseY()

    bestDist = 999999.0
    bestR = 0
    bestC = 0

    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            wx = kt_cellToX(c)
            wz = kt_cellToZ(r)
            kt_projectToScreen(wx, 0.05, wz)
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
    if BOARD_SZ >= 7 threshDist = 1400 ok

    if bestDist < threshDist and bestR >= 1 and bestR <= BOARD_SZ
        mouseHoverR = bestR
        mouseHoverC = bestC
        cursorR = bestR
        cursorC = bestC
    else
        mouseHoverR = 0
        mouseHoverC = 0
    ok

func kt_handleMouse
    if IsMouseButtonPressed(0)
        if mouseHoverR >= 1 and mouseHoverR <= BOARD_SZ and
           mouseHoverC >= 1 and mouseHoverC <= BOARD_SZ
            kt_tryMove(mouseHoverR, mouseHoverC)
        ok
    ok

// =============================================================
// Move Logic
// =============================================================

func kt_tryMove r, c
    // Check if it's a valid knight move from current position
    if kt_isValidKnightMove(knightR, knightC, r, c) = false
        kt_showMsg("Not a valid L-shaped move!")
        return
    ok

    if board[r][c] != CELL_EMPTY
        kt_showMsg("Square already visited!")
        return
    ok

    // Start hop animation
    animFromR = knightR
    animFromC = knightC
    animToR = r
    animToC = c
    animProgress = 0.0
    animActive = true
    gameState = ST_ANIMATING

func kt_finishMove
    // Record undo
    add(undoStack, [knightR, knightC])

    // Update board
    board[knightR][knightC] = CELL_VISITED
    knightR = animToR
    knightC = animToC
    moveNumber += 1
    board[knightR][knightC] = CELL_KNIGHT
    visitOrder[knightR][knightC] = moveNumber

    // Cursor follows knight
    cursorR = knightR
    cursorC = knightC

    // Spawn landing particles
    wx = kt_cellToX(knightC)
    wz = kt_cellToZ(knightR)
    kt_spawnLandingParticles(wx, wz)

    // Check win
    if moveNumber = totalCells
        gameState = ST_WON
        kt_spawnWinParticles()
        return
    ok

    // Update valid moves
    kt_computeValidMoves()

    // Check if stuck
    if len(validMoves) = 0
        gameState = ST_STUCK
        return
    ok

    gameState = ST_PLAYING

// =============================================================
// Undo
// =============================================================

func kt_undo
    if len(undoStack) = 0
        kt_showMsg("Nothing to undo!")
        return
    ok

    autoSolving = false

    // Remove current knight position
    board[knightR][knightC] = CELL_EMPTY
    visitOrder[knightR][knightC] = 0
    moveNumber -= 1

    // Restore previous position
    prev = undoStack[len(undoStack)]
    del(undoStack, len(undoStack))
    knightR = prev[1]
    knightC = prev[2]
    board[knightR][knightC] = CELL_KNIGHT

    cursorR = knightR
    cursorC = knightC

    kt_computeValidMoves()
    gameState = ST_PLAYING
    kt_showMsg("Move undone")

// =============================================================
// Valid Move Computation
// =============================================================

func kt_isValidKnightMove fromR, fromC, toR, toC
    dr = toR - fromR
    dc = toC - fromC
    if dr < 0 dr = -dr ok
    if dc < 0 dc = -dc ok
    if (dr = 2 and dc = 1) or (dr = 1 and dc = 2)
        return true
    ok
    return false

func kt_computeValidMoves
    validMoves = []
    for i = 1 to 8
        nr = knightR + KNIGHT_DR[i]
        nc = knightC + KNIGHT_DC[i]
        if nr >= 1 and nr <= BOARD_SZ and nc >= 1 and nc <= BOARD_SZ
            if board[nr][nc] = CELL_EMPTY
                deg = kt_warnsdorffDegree(nr, nc)
                add(validMoves, [nr, nc, deg])
            ok
        ok
    next

func kt_warnsdorffDegree r, c
    // Count how many onward moves from (r,c)
    count = 0
    for i = 1 to 8
        nr = r + KNIGHT_DR[i]
        nc = c + KNIGHT_DC[i]
        if nr >= 1 and nr <= BOARD_SZ and nc >= 1 and nc <= BOARD_SZ
            if board[nr][nc] = CELL_EMPTY
                count += 1
            ok
        ok
    next
    return count

// =============================================================
// Auto-Solver (Warnsdorff's Heuristic)
// =============================================================

func kt_autoSolveStep
    if len(validMoves) = 0
        autoSolving = false
        return
    ok

    // Pick move with lowest Warnsdorff degree (fewest onward moves)
    bestIdx = 1
    bestDeg = validMoves[1][3]
    for i = 2 to len(validMoves)
        if validMoves[i][3] < bestDeg
            bestDeg = validMoves[i][3]
            bestIdx = i
        ok
    next

    targetR = validMoves[bestIdx][1]
    targetC = validMoves[bestIdx][2]
    kt_tryMove(targetR, targetC)

// =============================================================
// Animation
// =============================================================

func kt_updateAnimation dt
    if animActive = false return ok

    animProgress += dt * animSpeed
    if animProgress >= 1.0
        animProgress = 1.0
        animActive = false
        kt_finishMove()
    ok

// =============================================================
// Helpers
// =============================================================

func kt_cellToX c
    return (c - 1) * CELL_SZ - (BOARD_SZ - 1) * CELL_SZ / 2

func kt_cellToZ r
    return (r - 1) * CELL_SZ - (BOARD_SZ - 1) * CELL_SZ / 2

func kt_showMsg text
    msgText = text
    msgTimer = 2.0

func kt_tileColorR r, c
    // Checkerboard pattern
    if (r + c) % 2 = 0
        return RAYLIBColor(180, 160, 120, 255)
    else
        return RAYLIBColor(100, 70, 45, 255)
    ok

// Visit gradient: blue (early) -> green -> yellow -> red (late)
func kt_visitColor step
    t = (step - 1.0) / (totalCells - 1.0)
    if totalCells <= 1 t = 0 ok

    if t < 0.33
        s = t / 0.33
        cr = floor(40 + s * 20)
        cg = floor(100 + s * 155)
        cb = floor(220 - s * 120)
    but t < 0.66
        s = (t - 0.33) / 0.33
        cr = floor(60 + s * 195)
        cg = floor(255 - s * 55)
        cb = floor(100 - s * 60)
    else
        s = (t - 0.66) / 0.34
        cr = floor(255 - s * 25)
        cg = floor(200 - s * 140)
        cb = floor(40 + s * 20)
    ok

    if cr > 255 cr = 255 ok
    if cg > 255 cg = 255 ok
    if cb > 255 cb = 255 ok
    if cr < 0 cr = 0 ok
    if cg < 0 cg = 0 ok
    if cb < 0 cb = 0 ok

    return RAYLIBColor(cr, cg, cb, 255)

// =============================================================
// 3D-to-Screen Projection
// =============================================================

func kt_projectToScreen wx, wy, wz
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

func kt_spawnLandingParticles wx, wz
    for i = 1 to 16
        vx = (GetRandomValue(-100, 100) / 100.0) * 2.5
        vy = (GetRandomValue(150, 450) / 100.0)
        vz = (GetRandomValue(-100, 100) / 100.0) * 2.5
        cr = GetRandomValue(180, 255)
        cg = GetRandomValue(160, 230)
        cb = GetRandomValue(50, 120)
        add(particles, [wx, 0.1, wz, vx, vy, vz, 1.0, cr, cg, cb])
    next

func kt_spawnWinParticles
    for i = 1 to 60
        wx = (GetRandomValue(-500, 500) / 100.0)
        wz = (GetRandomValue(-500, 500) / 100.0)
        vx = (GetRandomValue(-200, 200) / 100.0)
        vy = (GetRandomValue(300, 800) / 100.0)
        vz = (GetRandomValue(-200, 200) / 100.0)
        cr = GetRandomValue(100, 255)
        cg = GetRandomValue(180, 255)
        cb = GetRandomValue(50, 255)
        add(particles, [wx, 0.5, wz, vx, vy, vz, 2.0, cr, cg, cb])
    next

func kt_updateParticles dt
    i = 1
    while i <= len(particles)
        particles[i][1] += particles[i][4] * dt
        particles[i][2] += particles[i][5] * dt
        particles[i][3] += particles[i][6] * dt
        particles[i][5] -= 6.0 * dt       // gravity
        particles[i][7] -= dt
        if particles[i][7] <= 0
            del(particles, i)
        else
            i += 1
        ok
    end

func kt_drawParticles3D
    for i = 1 to len(particles)
        p = particles[i]
        maxLife = 1.0
        if gameState = ST_WON maxLife = 2.0 ok
        alpha = floor((p[7] / maxLife) * 255)
        if alpha > 255 alpha = 255 ok
        if alpha < 0 alpha = 0 ok
        sz = 0.04 + p[7] * 0.06
        DrawSphereEx(
            Vector3(p[1], p[2], p[3]),
            sz, 4, 4,
            RAYLIBColor(p[8], p[9], p[10], alpha)
        )
    next

// =============================================================
// Camera
// =============================================================

func kt_positionCamera
    boardW = BOARD_SZ * CELL_SZ
    maxDim = boardW

    goalX = 0  goalY = 0  goalZ = 0
    tgtX = 0   tgtY = 0   tgtZ = 0

    if cameraMode = CAM_FRONT
        goalX = 0
        goalY = maxDim * 0.8 + 3.0
        goalZ = maxDim * 0.7 + 3.0
        tgtX = 0
        tgtY = 0
        tgtZ = -0.5
    ok
    if cameraMode = CAM_ISOMETRIC
        goalX = maxDim * 0.6 + 2.0
        goalY = maxDim * 0.7 + 3.0
        goalZ = maxDim * 0.6 + 2.0
        tgtX = 0
        tgtY = 0
        tgtZ = 0
    ok
    if cameraMode = CAM_OVERHEAD
        goalX = 0
        goalY = maxDim + 5.0
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

func kt_drawBoard3D
    boardW = BOARD_SZ * CELL_SZ
    halfBoard = (BOARD_SZ - 1) * CELL_SZ / 2

    // Board base slab
    slabH = 0.3
    DrawCube(Vector3(0, -slabH/2, 0),
             boardW + CELL_SZ * 0.3, slabH, boardW + CELL_SZ * 0.3,
             RAYLIBColor(60, 45, 30, 255))
    DrawCubeWires(Vector3(0, -slabH/2, 0),
                  boardW + CELL_SZ * 0.3, slabH, boardW + CELL_SZ * 0.3,
                  RAYLIBColor(40, 30, 18, 200))

    // Individual tiles (checkerboard)
    tileH = 0.08
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            wx = kt_cellToX(c)
            wz = kt_cellToZ(r)

            if board[r][c] = CELL_EMPTY
                col = kt_tileColorR(r, c)
            else
                col = kt_tileColorR(r, c)
            ok

            tileSz = CELL_SZ * 0.96
            DrawCube(Vector3(wx, tileH/2, wz), tileSz, tileH, tileSz, col)
        next
    next

    // Border frame
    bThick = 0.15
    bH = 0.18
    halfE = boardW / 2 + CELL_SZ * 0.08
    edgeCol = RAYLIBColor(50, 35, 22, 255)
    DrawCube(Vector3(0, bH/2, -halfE), boardW + CELL_SZ * 0.3, bH, bThick, edgeCol)
    DrawCube(Vector3(0, bH/2, halfE),  boardW + CELL_SZ * 0.3, bH, bThick, edgeCol)
    DrawCube(Vector3(-halfE, bH/2, 0), bThick, bH, boardW + CELL_SZ * 0.15, edgeCol)
    DrawCube(Vector3(halfE, bH/2, 0),  bThick, bH, boardW + CELL_SZ * 0.15, edgeCol)

    // Table beneath
    DrawPlane(Vector3(0, -slabH - 0.01, 0), Vector2(40, 40),
              RAYLIBColor(10, 12, 20, 255))

// =============================================================
// 3D Drawing: Visited Tiles
// =============================================================

func kt_drawVisitedTiles3D
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if visitOrder[r][c] = 0 loop ok
            if board[r][c] = CELL_KNIGHT loop ok

            wx = kt_cellToX(c)
            wz = kt_cellToZ(r)
            step = visitOrder[r][c]

            // Colored overlay on visited tile
            vCol = kt_visitColor(step)
            tileSz = CELL_SZ * 0.88
            DrawCube(Vector3(wx, 0.10, wz), tileSz, 0.05, tileSz, vCol)

            // Step number pillar
            pillarH = 0.08 + (step * 1.0 / totalCells) * 0.25
            DrawCube(Vector3(wx, 0.12 + pillarH/2, wz),
                     CELL_SZ * 0.25, pillarH, CELL_SZ * 0.25,
                     Fade(vCol, 0.7))

            // Connection line to previous step
            if step > 1
                // Find previous step position
                for pr = 1 to BOARD_SZ
                    for pc = 1 to BOARD_SZ
                        if visitOrder[pr][pc] = step - 1
                            pwx = kt_cellToX(pc)
                            pwz = kt_cellToZ(pr)
                            lineY = 0.14
                            DrawLine3D(
                                Vector3(pwx, lineY, pwz),
                                Vector3(wx, lineY, wz),
                                Fade(vCol, 0.5))
                        ok
                    next
                next
            ok
        next
    next

// =============================================================
// 3D Drawing: Valid Moves
// =============================================================

func kt_drawValidMoves3D
    if gameState != ST_PLAYING return ok

    for i = 1 to len(validMoves)
        vr = validMoves[i][1]
        vc = validMoves[i][2]
        deg = validMoves[i][3]
        wx = kt_cellToX(vc)
        wz = kt_cellToZ(vr)

        pulse = 0.6 + sin(animTime * 3.0 + i * 0.8) * 0.4

        // Green ring for valid moves
        ringCol = RAYLIBColor(80, 220, 80, floor(160 * pulse))
        DrawCircle3D(Vector3(wx, 0.12, wz), CELL_SZ * 0.38,
                     Vector3(1, 0, 0), 90.0, ringCol)

        // Warnsdorff hint number (degree)
        if showHints
            // Small colored marker showing degree
            if deg <= 2
                hCol = RAYLIBColor(255, 60, 60, floor(200 * pulse))
            but deg <= 4
                hCol = RAYLIBColor(255, 200, 40, floor(200 * pulse))
            else
                hCol = RAYLIBColor(60, 200, 255, floor(180 * pulse))
            ok
            DrawSphere(Vector3(wx, 0.25, wz), CELL_SZ * 0.08, hCol)
        ok
    next

// =============================================================
// 3D Drawing: Knight
// =============================================================

func kt_drawKnight3D
    if animActive
        // Animated position
        t = animProgress
        fromX = kt_cellToX(animFromC)
        fromZ = kt_cellToZ(animFromR)
        toX   = kt_cellToX(animToC)
        toZ   = kt_cellToZ(animToR)

        // Smooth interpolation
        smooth = t * t * (3.0 - 2.0 * t)
        wx = fromX + (toX - fromX) * smooth
        wz = fromZ + (toZ - fromZ) * smooth

        // Arc trajectory for hop
        arcH = sin(t * 3.14159265) * 2.5
        wy = 0.15 + arcH
    else
        wx = kt_cellToX(knightC)
        wz = kt_cellToZ(knightR)
        wy = 0.15 + sin(animTime * 2.0) * 0.05    // subtle float
    ok

    // Knight body - base
    bodyW = CELL_SZ * 0.45
    bodyH = CELL_SZ * 0.4
    bodyCol = RAYLIBColor(50, 45, 55, 255)
    DrawCube(Vector3(wx, wy + bodyH/2, wz), bodyW, bodyH, bodyW, bodyCol)
    DrawCubeWires(Vector3(wx, wy + bodyH/2, wz), bodyW, bodyH, bodyW,
                  RAYLIBColor(80, 75, 90, 200))

    // Knight head (angled)
    headW = CELL_SZ * 0.3
    headH = CELL_SZ * 0.35
    headOff = CELL_SZ * 0.08
    DrawCube(Vector3(wx + headOff, wy + bodyH + headH/2, wz),
             headW, headH, headW * 0.7,
             RAYLIBColor(60, 55, 65, 255))
    DrawCubeWires(Vector3(wx + headOff, wy + bodyH + headH/2, wz),
                  headW, headH, headW * 0.7,
                  RAYLIBColor(90, 85, 100, 200))

    // Mane ridge
    maneW = CELL_SZ * 0.08
    maneH = CELL_SZ * 0.5
    DrawCube(Vector3(wx - headOff, wy + bodyH * 0.6 + maneH/2, wz),
             maneW, maneH, maneW,
             RAYLIBColor(80, 40, 40, 255))

    // Eyes (two small spheres)
    eyeOff = headW * 0.35
    eyeY = wy + bodyH + headH * 0.3
    DrawSphere(Vector3(wx + headOff, eyeY, wz - eyeOff),
               CELL_SZ * 0.04, RAYLIBColor(255, 200, 50, 255))
    DrawSphere(Vector3(wx + headOff, eyeY, wz + eyeOff),
               CELL_SZ * 0.04, RAYLIBColor(255, 200, 50, 255))

    // Ears (small cones)
    earY = wy + bodyH + headH
    DrawCylinder(Vector3(wx + headOff - headW*0.15, earY, wz - headW*0.15),
                 CELL_SZ * 0.04, 0, CELL_SZ * 0.15, 6,
                 RAYLIBColor(70, 65, 75, 255))
    DrawCylinder(Vector3(wx + headOff - headW*0.15, earY, wz + headW*0.15),
                 CELL_SZ * 0.04, 0, CELL_SZ * 0.15, 6,
                 RAYLIBColor(70, 65, 75, 255))

    // Base glow
    glowPulse = 0.6 + sin(animTime * 3.0) * 0.4
    DrawCircle3D(Vector3(wx, 0.12, wz), CELL_SZ * 0.4 * glowPulse,
                 Vector3(1, 0, 0), 90.0,
                 RAYLIBColor(200, 180, 60, floor(120 * glowPulse)))

// =============================================================
// 3D Drawing: Cursor
// =============================================================

func kt_drawCursor3D
    if gameState != ST_PLAYING return ok

    wx = kt_cellToX(cursorC)
    wz = kt_cellToZ(cursorR)

    // Check if cursor is on a valid move
    isValid = false
    for i = 1 to len(validMoves)
        if validMoves[i][1] = cursorR and validMoves[i][2] = cursorC
            isValid = true
        ok
    next

    if isValid
        curCol = RAYLIBColor(80, 255, 80, 200)
    else
        curCol = RAYLIBColor(255, 100, 60, 150)
    ok

    // Corner brackets
    hs = CELL_SZ * 0.45
    bLen = CELL_SZ * 0.18
    by = 0.11

    DrawLine3D(Vector3(wx-hs, by, wz-hs), Vector3(wx-hs+bLen, by, wz-hs), curCol)
    DrawLine3D(Vector3(wx-hs, by, wz-hs), Vector3(wx-hs, by, wz-hs+bLen), curCol)
    DrawLine3D(Vector3(wx+hs, by, wz-hs), Vector3(wx+hs-bLen, by, wz-hs), curCol)
    DrawLine3D(Vector3(wx+hs, by, wz-hs), Vector3(wx+hs, by, wz-hs+bLen), curCol)
    DrawLine3D(Vector3(wx-hs, by, wz+hs), Vector3(wx-hs+bLen, by, wz+hs), curCol)
    DrawLine3D(Vector3(wx-hs, by, wz+hs), Vector3(wx-hs, by, wz+hs-bLen), curCol)
    DrawLine3D(Vector3(wx+hs, by, wz+hs), Vector3(wx+hs-bLen, by, wz+hs), curCol)
    DrawLine3D(Vector3(wx+hs, by, wz+hs), Vector3(wx+hs, by, wz+hs-bLen), curCol)

// =============================================================
// HUD
// =============================================================

func kt_drawHUD
    panelW = 240
    panelH = 165
    DrawRectangle(10, 30, panelW, panelH, Fade(BLACK, 0.75))
    DrawRectangleLines(10, 30, panelW, panelH, RAYLIBColor(180, 140, 60, 200))

    DrawText("KNIGHT'S TOUR", 20, 38, 18, RAYLIBColor(220, 180, 80, 255))

    // Board size
    DrawText("Board: " + BOARD_SZ + "x" + BOARD_SZ, 20, 62, 14,
             RAYLIBColor(160, 180, 200, 200))

    // Progress
    pct = floor((moveNumber * 100.0) / totalCells)
    DrawText("Visited: " + moveNumber + " / " + totalCells + "  (" + pct + "%)",
             20, 80, 14, RAYLIBColor(100, 220, 100, 220))

    // Progress bar
    barX = 20
    barY = 100
    barW = 210
    barH = 12
    DrawRectangle(barX, barY, barW, barH, RAYLIBColor(40, 40, 50, 200))
    fillW = floor(barW * moveNumber / totalCells)
    if fillW > 0
        DrawRectangle(barX, barY, fillW, barH, RAYLIBColor(80, 200, 80, 220))
    ok
    DrawRectangleLines(barX, barY, barW, barH, RAYLIBColor(120, 120, 140, 180))

    // Valid moves
    DrawText("Valid moves: " + len(validMoves), 20, 118, 14,
             RAYLIBColor(160, 180, 200, 200))

    // Timer
    mins = floor(gameTimer / 60)
    secs = floor(gameTimer) % 60
    if secs < 10
        timeStr = "" + mins + ":0" + secs
    else
        timeStr = "" + mins + ":" + secs
    ok
    DrawText("Time: " + timeStr, 20, 136, 14,
             RAYLIBColor(160, 180, 200, 200))

    // Hints status
    if showHints
        hStr = "Hints: ON  [H]"
    else
        hStr = "Hints: OFF [H]"
    ok
    DrawText(hStr, 20, 154, 14, RAYLIBColor(140, 155, 175, 180))

    // Auto-solve indicator
    if autoSolving
        pulse = floor(180 + sin(animTime * 6.0) * 75)
        DrawText("AUTO-SOLVING...", 20, 175, 14,
                 RAYLIBColor(255, 200, 50, pulse))
    ok

    // Camera
    camName = "FRONT"
    if cameraMode = CAM_ISOMETRIC camName = "ISOMETRIC" ok
    if cameraMode = CAM_OVERHEAD  camName = "OVERHEAD"  ok
    DrawRectangle(10, SCREEN_H - 60, 220, 25, Fade(BLACK, 0.6))
    DrawText("Cam: " + camName + "  [C] switch", 16, SCREEN_H - 56, 14,
             RAYLIBColor(150, 180, 210, 220))

    // Controls
    DrawRectangle(SCREEN_W - 520, SCREEN_H - 35, 510, 25, Fade(BLACK, 0.6))
    DrawText("Click/Enter: Move | U: Undo | H: Hints | S: Auto-solve | R: Restart",
             SCREEN_W - 515, SCREEN_H - 30, 12, RAYLIBColor(150, 160, 180, 200))

// =============================================================
// Mini Map
// =============================================================

func kt_drawMiniMap
    cellW = 18
    if BOARD_SZ >= 7 cellW = 14 ok
    if BOARD_SZ >= 8 cellW = 12 ok
    mapW = BOARD_SZ * cellW
    mapH = BOARD_SZ * cellW
    mapX = SCREEN_W - mapW - 15
    mapY = 30

    DrawRectangle(mapX - 3, mapY - 3, mapW + 6, mapH + 6, Fade(BLACK, 0.8))
    DrawRectangleLines(mapX - 3, mapY - 3, mapW + 6, mapH + 6,
                       RAYLIBColor(180, 140, 60, 200))

    // Tiles
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            tx = mapX + (c - 1) * cellW
            ty = mapY + (r - 1) * cellW

            if board[r][c] = CELL_KNIGHT
                DrawRectangle(tx, ty, cellW, cellW, RAYLIBColor(255, 200, 50, 255))
            but visitOrder[r][c] > 0
                vCol = kt_visitColor(visitOrder[r][c])
                DrawRectangle(tx, ty, cellW, cellW, vCol)
            else
                if (r + c) % 2 = 0
                    DrawRectangle(tx, ty, cellW, cellW,
                                  RAYLIBColor(180, 160, 120, 200))
                else
                    DrawRectangle(tx, ty, cellW, cellW,
                                  RAYLIBColor(100, 70, 45, 200))
                ok
            ok
            DrawRectangleLines(tx, ty, cellW, cellW,
                               RAYLIBColor(40, 30, 20, 150))
        next
    next

    // Path lines on minimap
    for step = 2 to moveNumber
        // Find both step positions
        sr1 = 0  sc1 = 0  sr2 = 0  sc2 = 0
        for r = 1 to BOARD_SZ
            for c = 1 to BOARD_SZ
                if visitOrder[r][c] = step - 1
                    sr1 = r   sc1 = c
                ok
                if visitOrder[r][c] = step
                    sr2 = r   sc2 = c
                ok
            next
        next
        if sr1 > 0 and sr2 > 0
            x1 = mapX + (sc1 - 1) * cellW + cellW/2
            y1 = mapY + (sr1 - 1) * cellW + cellW/2
            x2 = mapX + (sc2 - 1) * cellW + cellW/2
            y2 = mapY + (sr2 - 1) * cellW + cellW/2
            DrawLine(x1, y1, x2, y2, RAYLIBColor(255, 255, 255, 120))
        ok
    next

    // Valid moves on minimap
    for i = 1 to len(validMoves)
        vr = validMoves[i][1]
        vc = validMoves[i][2]
        sx = mapX + (vc - 1) * cellW + cellW / 2
        sy = mapY + (vr - 1) * cellW + cellW / 2
        DrawCircle(sx, sy, cellW / 4, RAYLIBColor(80, 255, 80, 150))
    next

    // Cursor on minimap
    cx = mapX + (cursorC - 1) * cellW + cellW / 2
    cy = mapY + (cursorR - 1) * cellW + cellW / 2
    DrawCircleLines(cx, cy, cellW / 2, RAYLIBColor(255, 100, 80, 220))

    DrawText("MAP", mapX + mapW/2 - 15, mapY - 16, 12,
             RAYLIBColor(180, 140, 60, 200))

// =============================================================
// Title Screen
// =============================================================

func kt_drawTitleScreen
    DrawRectangleGradientV(0, 0, SCREEN_W, SCREEN_H,
        RAYLIBColor(10, 8, 18, 255), RAYLIBColor(20, 15, 30, 255))

    t1 = "3D KNIGHT'S TOUR"
    t1w = MeasureText(t1, 52)
    DrawText(t1, (SCREEN_W - t1w)/2, 55, 52, RAYLIBColor(220, 180, 80, 255))

    t2 = "~ Visit Every Square Exactly Once ~"
    t2w = MeasureText(t2, 17)
    DrawText(t2, (SCREEN_W - t2w)/2, 120, 17, RAYLIBColor(180, 150, 100, 230))

    // Decorative line
    lx1 = 200
    lx2 = SCREEN_W - 200
    ly = 150
    DrawLine(lx1, ly, lx2, ly, RAYLIBColor(180, 140, 60, 180))

    // Knight icon
    DrawRectangle((SCREEN_W-20)/2, ly - 15, 20, 30, RAYLIBColor(50, 45, 55, 255))
    DrawRectangleLines((SCREEN_W-20)/2, ly - 15, 20, 30, RAYLIBColor(100, 90, 110, 200))

    cy = 170
    cLines = [
        "Mouse Click / ENTER     -   Move knight to highlighted square",
        "Arrow Keys / WASD       -   Move cursor",
        "U / Backspace           -   Undo last move",
        "H                       -   Toggle Warnsdorff hints",
        "S                       -   Auto-solve from current position",
        "R                       -   Restart board",
        "C                       -   Cycle camera view",
        "",
        "Board Sizes:",
        "  1 = 5x5     2 = 6x6     3 = 7x7     4 = 8x8 (Standard)",
        "",
        "Rules:",
        "  The knight moves in an L-shape: 2 squares in one direction",
        "  and 1 square perpendicular. Visit every square exactly once.",
        "  Green dots show valid moves. Colored spheres show Warnsdorff",
        "  degree hints (red=fewer exits, prioritize these first!)."
    ]
    for i = 1 to len(cLines)
        lw = MeasureText(cLines[i], 14)
        if i >= 9
            col = RAYLIBColor(220, 180, 100, 210)
        else
            col = RAYLIBColor(150, 170, 200, 230)
        ok
        DrawText(cLines[i], (SCREEN_W - lw)/2, cy + (i - 1) * 21, 14, col)
    next

    // Current settings
    settingY = 520
    st = "Board: " + BOARD_SZ + "x" + BOARD_SZ + "  (" + (BOARD_SZ * BOARD_SZ) + " squares)"
    stw = MeasureText(st, 16)
    DrawText(st, (SCREEN_W - stw)/2, settingY, 16, RAYLIBColor(200, 180, 120, 230))

    if floor(animTime * 2) % 2 = 0
        st2 = "Click or Press ENTER / SPACE to Start"
        st2w = MeasureText(st2, 26)
        DrawText(st2, (SCREEN_W - st2w)/2, 560, 26, WHITE)
    ok

    cr = "Developed using Ring Language + RingRayLib"
    crw = MeasureText(cr, 14)
    DrawText(cr, (SCREEN_W - crw)/2, SCREEN_H - 35, 14,
             RAYLIBColor(80, 100, 80, 180))

// =============================================================
// Won Overlay
// =============================================================

func kt_drawWonOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.5))

    g1 = "KNIGHT'S TOUR COMPLETE!"
    g1w = MeasureText(g1, 42)
    pulse = floor(220 + sin(animTime * 3.0) * 35)
    DrawText(g1, (SCREEN_W - g1w)/2, 180, 42,
             RAYLIBColor(255, 220, 50, pulse))

    g2 = "All " + totalCells + " squares visited!"
    g2w = MeasureText(g2, 22)
    DrawText(g2, (SCREEN_W - g2w)/2, 240, 22, RAYLIBColor(100, 255, 100, 230))

    // Time
    mins = floor(gameTimer / 60)
    secs = floor(gameTimer) % 60
    if secs < 10
        timeStr = "" + mins + ":0" + secs
    else
        timeStr = "" + mins + ":" + secs
    ok
    ts = "Time: " + timeStr
    tsw = MeasureText(ts, 20)
    DrawText(ts, (SCREEN_W - tsw)/2, 280, 20, RAYLIBColor(200, 200, 220, 220))

    ms = "Moves: " + moveNumber
    msw = MeasureText(ms, 20)
    DrawText(ms, (SCREEN_W - msw)/2, 310, 20, RAYLIBColor(200, 200, 220, 220))

    if floor(animTime * 2) % 2 = 0
        rt = "Press R to play again  |  ENTER for title screen"
        rtw = MeasureText(rt, 16)
        DrawText(rt, (SCREEN_W - rtw)/2, 370, 16, WHITE)
    ok

    ss = "1: 5x5  |  2: 6x6  |  3: 7x7  |  4: 8x8"
    ssw = MeasureText(ss, 14)
    DrawText(ss, (SCREEN_W - ssw)/2, 400, 14, RAYLIBColor(180, 160, 120, 200))

// =============================================================
// Stuck Overlay
// =============================================================

func kt_drawStuckOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.55))

    g1 = "KNIGHT IS STUCK!"
    g1w = MeasureText(g1, 42)
    DrawText(g1, (SCREEN_W - g1w)/2, 180, 42, RAYLIBColor(255, 80, 60, 255))

    remaining = totalCells - moveNumber
    g2 = "Visited " + moveNumber + " of " + totalCells + " squares (" + remaining + " remaining)"
    g2w = MeasureText(g2, 18)
    DrawText(g2, (SCREEN_W - g2w)/2, 240, 18, RAYLIBColor(200, 180, 160, 220))

    pct = floor((moveNumber * 100.0) / totalCells)
    g3 = "Coverage: " + pct + "%"
    g3w = MeasureText(g3, 20)
    DrawText(g3, (SCREEN_W - g3w)/2, 270, 20, RAYLIBColor(255, 200, 100, 230))

    g4 = "Tip: Follow Warnsdorff's rule - move to the square with"
    g5 = "the fewest onward moves (red hints). Press H for hints!"
    g4w = MeasureText(g4, 14)
    g5w = MeasureText(g5, 14)
    DrawText(g4, (SCREEN_W - g4w)/2, 310, 14, RAYLIBColor(160, 180, 200, 200))
    DrawText(g5, (SCREEN_W - g5w)/2, 328, 14, RAYLIBColor(160, 180, 200, 200))

    if floor(animTime * 2) % 2 = 0
        rt = "Press R to retry  |  U to undo  |  ENTER for title screen"
        rtw = MeasureText(rt, 16)
        DrawText(rt, (SCREEN_W - rtw)/2, 375, 16, WHITE)
    ok

    ss = "1: 5x5  |  2: 6x6  |  3: 7x7  |  4: 8x8"
    ssw = MeasureText(ss, 14)
    DrawText(ss, (SCREEN_W - ssw)/2, 405, 14, RAYLIBColor(180, 160, 120, 200))

// =============================================================
// Message Overlay
// =============================================================

func kt_drawMessage
    alpha = floor((msgTimer / 2.0) * 255)
    if alpha > 255 alpha = 255 ok
    if alpha < 0 alpha = 0 ok

    mw = MeasureText(msgText, 24)
    mx = (SCREEN_W - mw) / 2
    my = SCREEN_H / 2 + 120

    DrawRectangle(mx - 15, my - 8, mw + 30, 40,
                  RAYLIBColor(0, 0, 0, floor(alpha * 0.7)))
    DrawText(msgText, mx, my, 24,
             RAYLIBColor(255, 220, 100, alpha))
