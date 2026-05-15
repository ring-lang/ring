/*
**  3D N-Queens Puzzle - Using RingRayLib
**  ========================================
**  Place N queens on an NxN chessboard so that no two
**  queens threaten each other! No two queens may share
**  the same row, column, or diagonal.
**
**  Controls:
**    Arrow Keys / WASD  - Move cursor on the board
**    Mouse              - Hover and click to place/remove queens
**    ENTER / SPACE      - Place or remove queen at cursor
**    U / Backspace      - Undo last action
**    H                  - Toggle threat heatmap overlay
**    S                  - Auto-solve (animated backtracking)
**    R                  - Restart / clear board
**    C                  - Cycle camera views
**    1..9, 0            - Board size: 4..12 (0=10, -, +=11,12)
**    ESC                - Exit
**
**  Goal:
**    Place exactly N queens on the NxN board such that
**    no queen attacks another. Queens attack along rows,
**    columns, and both diagonals.
**
**  Features:
**    - Board sizes from 4x4 to 12x12
**    - Elegant 3D queen pieces with crown and jewels
**    - Real-time conflict detection and threat highlighting
**    - Threat heatmap overlay showing danger zones
**    - Drop animation when placing queens
**    - Shake animation for conflicting queens
**    - Auto-solver with animated backtracking
**    - Full undo system
**    - Three camera modes: Front / Isometric / Overhead
**    - Particle effects on placement and solution
**    - Timer and queen counter in HUD
**    - Mini-map with threat visualization
**    - Title, playing, solved, and info screens
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
CELL_QUEEN      = 1

// Game states
ST_START        = 1
ST_PLAYING      = 2
ST_SOLVED       = 3
ST_AUTOSOLVE    = 4

// Camera modes
CAM_FRONT       = 1
CAM_ISOMETRIC   = 2
CAM_OVERHEAD    = 3
CAM_COUNT       = 3

// =============================================================
// Global Variables
// =============================================================

BOARD_SZ        = 8
board           = []
queenCount      = 0
totalSolutions  = 0

cursorR         = 1
cursorC         = 1

gameState       = ST_START
animTime        = 0.0

// Threat map: threatMap[r][c] = number of queens attacking this cell
threatMap       = []
showThreats     = false

// Conflicts: list of [r,c] pairs for queens in conflict
conflicts       = []

// Undo stack: [[r, c, action], ...]  action: 1=placed, 0=removed
undoStack       = []

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

// Drop animations: [[r, c, progress], ...]
dropAnims       = []

// Timer
gameTimer       = 0.0

// Auto-solve
autoSolveActive = false
autoSolveTimer  = 0.0
autoSolveDelay  = 0.08
autoSolveRow    = 1
autoSolveStack  = []

// Message
msgText         = ""
msgTimer        = 0.0

// Known solution counts for display
solutionCounts  = [0, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712]
// Index: 1=1x1, 2=2x2, ... 13=13x13 (but we use 4-12)

// =============================================================
// Initialize
// =============================================================

nq_initBoard()

// =============================================================
// Main Program
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Ring 3D N-Queens Puzzle - RingRayLib")
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

    // Camera toggle (always)
    if IsKeyPressed(KEY_C)
        cameraMode += 1
        if cameraMode > CAM_COUNT cameraMode = CAM_FRONT ok
    ok

    // Board size selection (title/solved screens)
    if gameState = ST_START or gameState = ST_SOLVED
        nq_checkSizeKeys()
    ok

    // Restart
    if IsKeyPressed(KEY_R)
        autoSolveActive = false
        nq_initBoard()
        gameState = ST_PLAYING
    ok

    // ========== STATE UPDATES ==========

    if gameState = ST_START
        nq_checkSizeKeys()
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(0)
            nq_initBoard()
            gameState = ST_PLAYING
        ok
    ok

    if gameState = ST_PLAYING
        nq_updateMouseHover()
        nq_handleInput()
        nq_handleMouse()
        nq_updateThreatMap()
        nq_updateConflicts()
        nq_updateDropAnims(dt)
        nq_updateParticles(dt)
        gameTimer += dt

        // Check for solution
        if queenCount = BOARD_SZ and len(conflicts) = 0
            gameState = ST_SOLVED
            nq_spawnSolveParticles()
            nq_showMsg("SOLVED! All " + BOARD_SZ + " queens placed safely!")
        ok
    ok

    if gameState = ST_AUTOSOLVE
        nq_updateAutoSolve(dt)
        nq_updateThreatMap()
        nq_updateConflicts()
        nq_updateDropAnims(dt)
        nq_updateParticles(dt)
        gameTimer += dt

        // Cancel auto-solve
        if IsKeyPressed(KEY_ESCAPE) or IsKeyPressed(KEY_R)
            autoSolveActive = false
            gameState = ST_PLAYING
            nq_showMsg("Auto-solve cancelled")
        ok
    ok

    if gameState = ST_SOLVED
        nq_updateParticles(dt)
        if IsKeyPressed(KEY_R)
            nq_initBoard()
            gameState = ST_PLAYING
        ok
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            nq_initBoard()
            gameState = ST_START
        ok
    ok

    nq_positionCamera()

    // ========== DRAWING ==========

    BeginDrawing()
        ClearBackground(RAYLIBColor(14, 10, 22, 255))

        if gameState = ST_START
            nq_drawTitleScreen()
        else
            BeginMode3D(camera)
                nq_drawBoard3D()
                nq_drawThreatOverlay3D()
                nq_drawQueens3D()
                nq_drawDropAnims3D()
                nq_drawCursor3D()
                nq_drawThreatLines3D()
                nq_drawParticles3D()
            EndMode3D()

            nq_drawHUD()
            nq_drawMiniMap()

            if gameState = ST_SOLVED
                nq_drawSolvedOverlay()
            ok

            if gameState = ST_AUTOSOLVE
                pulse = floor(180 + sin(animTime * 6.0) * 75)
                DrawText("AUTO-SOLVING... (S to cancel)", 320, 30, 18,
                         RAYLIBColor(255, 200, 50, pulse))
            ok

            if msgTimer > 0
                nq_drawMessage()
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

func nq_initBoard
    board = list(BOARD_SZ)
    threatMap = list(BOARD_SZ)
    for r = 1 to BOARD_SZ
        board[r] = list(BOARD_SZ)
        threatMap[r] = list(BOARD_SZ)
        for c = 1 to BOARD_SZ
            board[r][c] = CELL_EMPTY
            threatMap[r][c] = 0
        next
    next

    queenCount = 0
    cursorR = floor(BOARD_SZ / 2) + 1
    cursorC = floor(BOARD_SZ / 2) + 1
    undoStack = []
    conflicts = []
    particles = []
    dropAnims = []
    gameTimer = 0.0
    autoSolveActive = false
    autoSolveTimer = 0.0
    autoSolveRow = 1
    autoSolveStack = []
    msgTimer = 0
    showThreats = false

    CELL_SZ = 14.0 / BOARD_SZ
    if CELL_SZ < 1.2 CELL_SZ = 1.2 ok
    if CELL_SZ > 2.8 CELL_SZ = 2.8 ok

// =============================================================
// Size Key Handling
// =============================================================

func nq_checkSizeKeys
    if IsKeyPressed(KEY_FOUR)
        BOARD_SZ = 4
        nq_initBoard()
    ok
    if IsKeyPressed(KEY_FIVE)
        BOARD_SZ = 5
        nq_initBoard()
    ok
    if IsKeyPressed(KEY_SIX)
        BOARD_SZ = 6
        nq_initBoard()
    ok
    if IsKeyPressed(KEY_SEVEN)
        BOARD_SZ = 7
        nq_initBoard()
    ok
    if IsKeyPressed(KEY_EIGHT)
        BOARD_SZ = 8
        nq_initBoard()
    ok
    if IsKeyPressed(KEY_NINE)
        BOARD_SZ = 9
        nq_initBoard()
    ok
    if IsKeyPressed(KEY_ZERO)
        BOARD_SZ = 10
        nq_initBoard()
    ok
    if IsKeyPressed(KEY_MINUS)
        BOARD_SZ = 11
        nq_initBoard()
    ok
    if IsKeyPressed(KEY_EQUAL)
        BOARD_SZ = 12
        nq_initBoard()
    ok

// =============================================================
// Input Handling
// =============================================================

func nq_handleInput
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

    // Place / remove queen
    if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
        nq_toggleQueen(cursorR, cursorC)
    ok

    // Undo
    if IsKeyPressed(KEY_U) or IsKeyPressed(KEY_BACKSPACE)
        nq_undo()
    ok

    // Toggle threats
    if IsKeyPressed(KEY_H)
        if showThreats = true
            showThreats = false
            nq_showMsg("Threat heatmap OFF")
        else
            showThreats = true
            nq_showMsg("Threat heatmap ON")
        ok
    ok

    // Auto-solve
    if IsKeyPressed(KEY_S)
        nq_startAutoSolve()
    ok

// =============================================================
// Mouse Handling
// =============================================================

func nq_updateMouseHover
    mx = GetMouseX()
    my = GetMouseY()

    bestDist = 999999.0
    bestR = 0
    bestC = 0

    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            wx = nq_cellToX(c)
            wz = nq_cellToZ(r)
            nq_projectToScreen(wx, 0.05, wz)
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
    if BOARD_SZ >= 8 threshDist = 1400 ok
    if BOARD_SZ >= 10 threshDist = 900 ok

    if bestDist < threshDist and bestR >= 1 and bestR <= BOARD_SZ
        mouseHoverR = bestR
        mouseHoverC = bestC
        cursorR = bestR
        cursorC = bestC
    else
        mouseHoverR = 0
        mouseHoverC = 0
    ok

func nq_handleMouse
    if IsMouseButtonPressed(0)
        if mouseHoverR >= 1 and mouseHoverR <= BOARD_SZ and
           mouseHoverC >= 1 and mouseHoverC <= BOARD_SZ
            nq_toggleQueen(mouseHoverR, mouseHoverC)
        ok
    ok

// =============================================================
// Queen Placement / Removal
// =============================================================

func nq_toggleQueen r, c
    if board[r][c] = CELL_QUEEN
        // Remove queen
        board[r][c] = CELL_EMPTY
        queenCount -= 1
        add(undoStack, [r, c, 0])

        wx = nq_cellToX(c)
        wz = nq_cellToZ(r)
        nq_spawnRemoveParticles(wx, wz)
        nq_showMsg("Queen removed")
    else
        // Place queen
        if queenCount >= BOARD_SZ
            nq_showMsg("Maximum " + BOARD_SZ + " queens reached!")
            return
        ok
        board[r][c] = CELL_QUEEN
        queenCount += 1
        add(undoStack, [r, c, 1])
        add(dropAnims, [r, c, 0.0])
        nq_showMsg("Queen placed (" + queenCount + "/" + BOARD_SZ + ")")
    ok

// =============================================================
// Undo
// =============================================================

func nq_undo
    if len(undoStack) = 0
        nq_showMsg("Nothing to undo!")
        return
    ok

    last = undoStack[len(undoStack)]
    del(undoStack, len(undoStack))
    r = last[1]
    c = last[2]
    action = last[3]

    if action = 1
        // Was placed, so remove
        board[r][c] = CELL_EMPTY
        queenCount -= 1
    else
        // Was removed, so place back
        board[r][c] = CELL_QUEEN
        queenCount += 1
    ok

    cursorR = r
    cursorC = c
    nq_showMsg("Undone")

// =============================================================
// Threat Map Calculation
// =============================================================

func nq_updateThreatMap
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            threatMap[r][c] = 0
        next
    next

    // For each queen, mark all attacked cells
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if board[r][c] = CELL_QUEEN
                // Row
                for cc = 1 to BOARD_SZ
                    if cc != c
                        threatMap[r][cc] += 1
                    ok
                next
                // Column
                for rr = 1 to BOARD_SZ
                    if rr != r
                        threatMap[rr][c] += 1
                    ok
                next
                // Diagonals
                for d = 1 to BOARD_SZ
                    // Up-left
                    nr = r - d   nc = c - d
                    if nr >= 1 and nc >= 1
                        threatMap[nr][nc] += 1
                    ok
                    // Up-right
                    nr = r - d   nc = c + d
                    if nr >= 1 and nc <= BOARD_SZ
                        threatMap[nr][nc] += 1
                    ok
                    // Down-left
                    nr = r + d   nc = c - d
                    if nr <= BOARD_SZ and nc >= 1
                        threatMap[nr][nc] += 1
                    ok
                    // Down-right
                    nr = r + d   nc = c + d
                    if nr <= BOARD_SZ and nc <= BOARD_SZ
                        threatMap[nr][nc] += 1
                    ok
                next
            ok
        next
    next

// =============================================================
// Conflict Detection
// =============================================================

func nq_updateConflicts
    conflicts = []

    // Collect all queen positions
    queens = []
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if board[r][c] = CELL_QUEEN
                add(queens, [r, c])
            ok
        next
    next

    // Check each pair
    for i = 1 to len(queens)
        for j = i + 1 to len(queens)
            r1 = queens[i][1]  c1 = queens[i][2]
            r2 = queens[j][1]  c2 = queens[j][2]

            hasConflict = false

            // Same row
            if r1 = r2 hasConflict = true ok
            // Same column
            if c1 = c2 hasConflict = true ok
            // Same diagonal
            dr = r1 - r2
            dc = c1 - c2
            if dr < 0 dr = -dr ok
            if dc < 0 dc = -dc ok
            if dr = dc hasConflict = true ok

            if hasConflict
                // Add both queens to conflict list (avoid duplicates)
                nq_addConflict(r1, c1)
                nq_addConflict(r2, c2)
            ok
        next
    next

func nq_addConflict r, c
    for i = 1 to len(conflicts)
        if conflicts[i][1] = r and conflicts[i][2] = c
            return
        ok
    next
    add(conflicts, [r, c])

// =============================================================
// Auto-Solver (Animated Backtracking)
// =============================================================

func nq_startAutoSolve
    // Clear board first
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            board[r][c] = CELL_EMPTY
        next
    next
    queenCount = 0
    undoStack = []
    autoSolveActive = true
    autoSolveRow = 1
    autoSolveStack = []
    gameState = ST_AUTOSOLVE
    nq_showMsg("Auto-solving " + BOARD_SZ + " Queens...")

func nq_updateAutoSolve dt
    if autoSolveActive = false return ok

    autoSolveTimer += dt
    if autoSolveTimer < autoSolveDelay return ok
    autoSolveTimer = 0

    nq_autoSolveStep()

func nq_autoSolveStep
    if autoSolveRow > BOARD_SZ
        // All queens placed = solved!
        autoSolveActive = false
        queenCount = BOARD_SZ
        gameState = ST_SOLVED
        nq_spawnSolveParticles()
        nq_showMsg("Solved by backtracking!")
        return
    ok

    if autoSolveRow < 1
        // No solution found (shouldn't happen for N>=4)
        autoSolveActive = false
        gameState = ST_PLAYING
        nq_showMsg("No solution found!")
        return
    ok

    // Determine starting column for this row
    startCol = 1
    if len(autoSolveStack) >= autoSolveRow
        // Backtracking: try next column after previous attempt
        prevCol = autoSolveStack[autoSolveRow]
        // Remove queen from previous position
        board[autoSolveRow][prevCol] = CELL_EMPTY
        startCol = prevCol + 1
        // Trim stack
        while len(autoSolveStack) >= autoSolveRow
            del(autoSolveStack, len(autoSolveStack))
        end
    ok

    // Try columns from startCol
    foundCol = 0
    for cc = startCol to BOARD_SZ
        if nq_isSafeForAutoSolve(autoSolveRow, cc)
            foundCol = cc
            exit
        ok
    next

    if foundCol > 0
        // Place queen
        board[autoSolveRow][foundCol] = CELL_QUEEN
        add(autoSolveStack, foundCol)

        // Particles
        wx = nq_cellToX(foundCol)
        wz = nq_cellToZ(autoSolveRow)
        nq_spawnPlaceParticles(wx, wz)

        autoSolveRow += 1
    else
        // Backtrack
        autoSolveRow -= 1
    ok

func nq_isSafeForAutoSolve r, c
    // Check rows above (already placed)
    for rr = 1 to r - 1
        for cc = 1 to BOARD_SZ
            if board[rr][cc] = CELL_QUEEN
                // Same column
                if cc = c return false ok
                // Same diagonal
                dr = r - rr
                dc = c - cc
                if dc < 0 dc = -dc ok
                if dr = dc return false ok
            ok
        next
    next
    return true

// =============================================================
// Helpers
// =============================================================

func nq_cellToX c
    return (c - 1) * CELL_SZ - (BOARD_SZ - 1) * CELL_SZ / 2

func nq_cellToZ r
    return (r - 1) * CELL_SZ - (BOARD_SZ - 1) * CELL_SZ / 2

func nq_showMsg text
    msgText = text
    msgTimer = 2.0

func nq_tileColor r, c
    if (r + c) % 2 = 0
        return RAYLIBColor(200, 180, 140, 255)
    else
        return RAYLIBColor(120, 80, 50, 255)
    ok

// =============================================================
// 3D-to-Screen Projection
// =============================================================

func nq_projectToScreen wx, wy, wz
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
// Drop Animation
// =============================================================

func nq_updateDropAnims dt
    i = 1
    while i <= len(dropAnims)
        dropAnims[i][3] += dt * 4.0
        if dropAnims[i][3] >= 1.0
            del(dropAnims, i)
        else
            i += 1
        ok
    end

func nq_drawDropAnims3D
    for i = 1 to len(dropAnims)
        r = dropAnims[i][1]
        c = dropAnims[i][2]
        prog = dropAnims[i][3]

        wx = nq_cellToX(c)
        wz = nq_cellToZ(r)

        t = prog
        dropH = (1.0 - t) * (1.0 - t) * 3.0
        wy = 0.1 + dropH

        // Ghost queen during drop
        nq_drawQueenPiece(wx, wy, wz, false, floor(180 * (1.0 - prog)))
    next

// =============================================================
// Particles
// =============================================================

func nq_spawnPlaceParticles wx, wz
    for i = 1 to 10
        vx = (GetRandomValue(-100, 100) / 100.0) * 1.5
        vy = (GetRandomValue(150, 400) / 100.0)
        vz = (GetRandomValue(-100, 100) / 100.0) * 1.5
        cr = GetRandomValue(200, 255)
        cg = GetRandomValue(180, 240)
        cb = GetRandomValue(50, 130)
        add(particles, [wx, 0.2, wz, vx, vy, vz, 1.0, cr, cg, cb])
    next

func nq_spawnRemoveParticles wx, wz
    for i = 1 to 8
        vx = (GetRandomValue(-100, 100) / 100.0) * 2.0
        vy = (GetRandomValue(100, 300) / 100.0)
        vz = (GetRandomValue(-100, 100) / 100.0) * 2.0
        cr = GetRandomValue(150, 200)
        cg = GetRandomValue(60, 100)
        cb = GetRandomValue(60, 100)
        add(particles, [wx, 0.3, wz, vx, vy, vz, 0.8, cr, cg, cb])
    next

func nq_spawnSolveParticles
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

func nq_updateParticles dt
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

func nq_drawParticles3D
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

func nq_positionCamera
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

func nq_drawBoard3D
    boardW = BOARD_SZ * CELL_SZ

    // Board base slab
    slabH = 0.3
    DrawCube(Vector3(0, -slabH/2, 0),
             boardW + CELL_SZ * 0.3, slabH, boardW + CELL_SZ * 0.3,
             RAYLIBColor(55, 40, 28, 255))
    DrawCubeWires(Vector3(0, -slabH/2, 0),
                  boardW + CELL_SZ * 0.3, slabH, boardW + CELL_SZ * 0.3,
                  RAYLIBColor(35, 25, 15, 200))

    // Individual tiles
    tileH = 0.08
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            wx = nq_cellToX(c)
            wz = nq_cellToZ(r)
            col = nq_tileColor(r, c)
            tileSz = CELL_SZ * 0.96
            DrawCube(Vector3(wx, tileH/2, wz), tileSz, tileH, tileSz, col)
        next
    next

    // Border frame
    bThick = 0.15
    bH = 0.18
    halfE = boardW / 2 + CELL_SZ * 0.08
    edgeCol = RAYLIBColor(45, 32, 20, 255)
    DrawCube(Vector3(0, bH/2, -halfE), boardW + CELL_SZ * 0.3, bH, bThick, edgeCol)
    DrawCube(Vector3(0, bH/2, halfE),  boardW + CELL_SZ * 0.3, bH, bThick, edgeCol)
    DrawCube(Vector3(-halfE, bH/2, 0), bThick, bH, boardW + CELL_SZ * 0.15, edgeCol)
    DrawCube(Vector3(halfE, bH/2, 0),  bThick, bH, boardW + CELL_SZ * 0.15, edgeCol)

    // Table beneath
    DrawPlane(Vector3(0, -slabH - 0.01, 0), Vector2(40, 40),
              RAYLIBColor(10, 8, 16, 255))

// =============================================================
// 3D Drawing: Threat Overlay
// =============================================================

func nq_drawThreatOverlay3D
    if showThreats = false return ok

    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if threatMap[r][c] = 0 loop ok
            if board[r][c] = CELL_QUEEN loop ok

            wx = nq_cellToX(c)
            wz = nq_cellToZ(r)

            intensity = threatMap[r][c]
            if intensity > 5 intensity = 5 ok

            alpha = 40 + intensity * 30
            if alpha > 200 alpha = 200 ok
            red = 80 + intensity * 35
            if red > 255 red = 255 ok

            tileSz = CELL_SZ * 0.9
            DrawCube(Vector3(wx, 0.09, wz), tileSz, 0.02, tileSz,
                     RAYLIBColor(red, 30, 20, alpha))
        next
    next

// =============================================================
// 3D Drawing: Threat Lines (from queens in conflict)
// =============================================================

func nq_drawThreatLines3D
    if len(conflicts) < 2 return ok

    // Draw lines between conflicting pairs
    queens = []
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if board[r][c] = CELL_QUEEN
                add(queens, [r, c])
            ok
        next
    next

    lineY = 0.15
    for i = 1 to len(queens)
        for j = i + 1 to len(queens)
            r1 = queens[i][1]  c1 = queens[i][2]
            r2 = queens[j][1]  c2 = queens[j][2]

            hasConflict = false
            if r1 = r2 hasConflict = true ok
            if c1 = c2 hasConflict = true ok
            dr = r1 - r2  dc = c1 - c2
            if dr < 0 dr = -dr ok
            if dc < 0 dc = -dc ok
            if dr = dc hasConflict = true ok

            if hasConflict
                wx1 = nq_cellToX(c1)
                wz1 = nq_cellToZ(r1)
                wx2 = nq_cellToX(c2)
                wz2 = nq_cellToZ(r2)

                pulse = floor(150 + sin(animTime * 5.0) * 100)
                DrawLine3D(Vector3(wx1, lineY, wz1),
                           Vector3(wx2, lineY, wz2),
                           RAYLIBColor(255, 50, 30, pulse))
            ok
        next
    next

// =============================================================
// 3D Drawing: Queens
// =============================================================

func nq_drawQueens3D
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if board[r][c] = CELL_QUEEN
                wx = nq_cellToX(c)
                wz = nq_cellToZ(r)
                wy = 0.1

                // Check if in conflict (for shake)
                inConflict = false
                for k = 1 to len(conflicts)
                    if conflicts[k][1] = r and conflicts[k][2] = c
                        inConflict = true
                    ok
                next

                if inConflict
                    // Shake effect
                    shakeAmt = sin(animTime * 18.0 + r * 3.7 + c * 2.3) * 0.06
                    wx += shakeAmt
                    wz += cos(animTime * 15.0 + r * 2.1) * 0.04
                ok

                nq_drawQueenPiece(wx, wy, wz, inConflict, 255)
            ok
        next
    next

// =============================================================
// Queen Piece Drawing (reusable)
// =============================================================

func nq_drawQueenPiece wx, wy, wz, inConflict, alpha
    sc = CELL_SZ * 0.22

    if inConflict
        bodyCol = RAYLIBColor(180, 40, 30, alpha)
        crownCol = RAYLIBColor(200, 60, 40, alpha)
        jewelCol = RAYLIBColor(255, 100, 80, alpha)
        wireCol = RAYLIBColor(220, 80, 60, floor(alpha * 0.7))
    else
        bodyCol = RAYLIBColor(220, 190, 80, alpha)
        crownCol = RAYLIBColor(240, 210, 60, alpha)
        jewelCol = RAYLIBColor(180, 50, 50, alpha)
        wireCol = RAYLIBColor(180, 150, 40, floor(alpha * 0.7))
    ok

    // Base (wide cylinder)
    baseH = sc * 1.2
    baseR = sc * 2.2
    DrawCylinder(Vector3(wx, wy, wz), baseR, baseR * 0.9, baseH, 16, bodyCol)
    DrawCylinderWires(Vector3(wx, wy, wz), baseR, baseR * 0.9, baseH, 16, wireCol)

    // Stem (narrower cylinder)
    stemH = sc * 2.8
    stemR = sc * 1.0
    DrawCylinder(Vector3(wx, wy + baseH, wz), stemR * 0.8, stemR, stemH, 12, bodyCol)

    // Crown body (wider at top)
    crownH = sc * 2.0
    crownR = sc * 1.6
    DrawCylinder(Vector3(wx, wy + baseH + stemH, wz),
                 stemR, crownR, crownH, 16, crownCol)
    DrawCylinderWires(Vector3(wx, wy + baseH + stemH, wz),
                      stemR, crownR, crownH, 16, wireCol)

    // Crown points (5 small cones around the top)
    topY = wy + baseH + stemH + crownH
    pointH = sc * 1.5
    for p = 1 to 5
        angle = (p - 1) * 72.0 * 3.14159265 / 180.0
        px = wx + cos(angle) * crownR * 0.7
        pz = wz + sin(angle) * crownR * 0.7
        DrawCylinder(Vector3(px, topY, pz),
                     sc * 0.35, 0, pointH, 6, crownCol)
    next

    // Central jewel (sphere on top)
    DrawSphere(Vector3(wx, topY + pointH * 0.6, wz),
               sc * 0.5, jewelCol)

    // Side jewels (on crown body)
    for p = 1 to 4
        angle = (p - 1) * 90.0 * 3.14159265 / 180.0
        jx = wx + cos(angle) * crownR * 0.85
        jz = wz + sin(angle) * crownR * 0.85
        jy = wy + baseH + stemH + crownH * 0.5
        DrawSphere(Vector3(jx, jy, jz), sc * 0.25, jewelCol)
    next

// =============================================================
// 3D Drawing: Cursor
// =============================================================

func nq_drawCursor3D
    if gameState != ST_PLAYING return ok

    wx = nq_cellToX(cursorC)
    wz = nq_cellToZ(cursorR)

    // Color based on safety
    if board[cursorR][cursorC] = CELL_QUEEN
        curCol = RAYLIBColor(255, 180, 60, 200)
    but threatMap[cursorR][cursorC] > 0
        curCol = RAYLIBColor(255, 80, 50, 180)
    else
        curCol = RAYLIBColor(80, 255, 80, 200)
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

func nq_drawHUD
    panelW = 250
    panelH = 180
    DrawRectangle(10, 30, panelW, panelH, Fade(BLACK, 0.75))
    DrawRectangleLines(10, 30, panelW, panelH, RAYLIBColor(180, 140, 60, 200))

    DrawText("N-QUEENS PUZZLE", 20, 38, 18, RAYLIBColor(220, 180, 80, 255))

    // Board size
    DrawText("Board: " + BOARD_SZ + "x" + BOARD_SZ, 20, 62, 14,
             RAYLIBColor(160, 180, 200, 200))

    // Queen count
    if queenCount = BOARD_SZ and len(conflicts) = 0
        qCol = RAYLIBColor(80, 255, 80, 255)
    but len(conflicts) > 0
        qCol = RAYLIBColor(255, 100, 70, 255)
    else
        qCol = RAYLIBColor(200, 200, 220, 220)
    ok
    DrawText("Queens: " + queenCount + " / " + BOARD_SZ, 20, 80, 16, qCol)

    // Progress bar
    barX = 20
    barY = 102
    barW = 220
    barH = 12
    DrawRectangle(barX, barY, barW, barH, RAYLIBColor(40, 40, 50, 200))
    fillW = floor(barW * queenCount / BOARD_SZ)
    if fillW > 0
        if len(conflicts) > 0
            DrawRectangle(barX, barY, fillW, barH, RAYLIBColor(255, 80, 50, 220))
        else
            DrawRectangle(barX, barY, fillW, barH, RAYLIBColor(80, 200, 80, 220))
        ok
    ok
    DrawRectangleLines(barX, barY, barW, barH, RAYLIBColor(120, 120, 140, 180))

    // Conflicts
    if len(conflicts) > 0
        DrawText("Conflicts: " + len(conflicts) + " queens threatened!",
                 20, 120, 14, RAYLIBColor(255, 100, 70, 230))
    else
        if queenCount > 0
            DrawText("No conflicts - looking good!", 20, 120, 14,
                     RAYLIBColor(80, 220, 80, 220))
        else
            DrawText("Place queens on the board", 20, 120, 14,
                     RAYLIBColor(140, 155, 175, 180))
        ok
    ok

    // Timer
    mins = floor(gameTimer / 60)
    secs = floor(gameTimer) % 60
    if secs < 10
        timeStr = "" + mins + ":0" + secs
    else
        timeStr = "" + mins + ":" + secs
    ok
    DrawText("Time: " + timeStr, 20, 140, 14,
             RAYLIBColor(160, 180, 200, 200))

    // Heatmap status
    if showThreats = true
        hStr = "Threats: ON  [H]"
    else
        hStr = "Threats: OFF [H]"
    ok
    DrawText(hStr, 20, 158, 14, RAYLIBColor(140, 155, 175, 180))

    // Known solutions
    if BOARD_SZ >= 4 and BOARD_SZ <= 12
        solCount = solutionCounts[BOARD_SZ + 1]
        DrawText("Known solutions: " + solCount, 20, 176, 14,
                 RAYLIBColor(120, 130, 150, 160))
    ok

    // Camera info
    camName = "FRONT"
    if cameraMode = CAM_ISOMETRIC camName = "ISOMETRIC" ok
    if cameraMode = CAM_OVERHEAD  camName = "OVERHEAD"  ok
    DrawRectangle(10, SCREEN_H - 60, 220, 25, Fade(BLACK, 0.6))
    DrawText("Cam: " + camName + "  [C] switch", 16, SCREEN_H - 56, 14,
             RAYLIBColor(150, 180, 210, 220))

    // Controls
    DrawRectangle(SCREEN_W - 520, SCREEN_H - 35, 510, 25, Fade(BLACK, 0.6))
    DrawText("Click/Enter: Place/Remove | U: Undo | H: Threats | S: Solve | R: Clear",
             SCREEN_W - 515, SCREEN_H - 30, 12, RAYLIBColor(150, 160, 180, 200))

// =============================================================
// Mini Map
// =============================================================

func nq_drawMiniMap
    cellW = 18
    if BOARD_SZ >= 8 cellW = 14 ok
    if BOARD_SZ >= 10 cellW = 11 ok
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

            // Checkerboard
            if (r + c) % 2 = 0
                DrawRectangle(tx, ty, cellW, cellW, RAYLIBColor(180, 160, 120, 200))
            else
                DrawRectangle(tx, ty, cellW, cellW, RAYLIBColor(100, 70, 45, 200))
            ok

            // Threat overlay
            if showThreats = true and threatMap[r][c] > 0 and board[r][c] = CELL_EMPTY
                tAlpha = 60 + threatMap[r][c] * 25
                if tAlpha > 180 tAlpha = 180 ok
                DrawRectangle(tx, ty, cellW, cellW,
                              RAYLIBColor(255, 50, 30, tAlpha))
            ok

            // Queen
            if board[r][c] = CELL_QUEEN
                inConflict = false
                for k = 1 to len(conflicts)
                    if conflicts[k][1] = r and conflicts[k][2] = c
                        inConflict = true
                    ok
                next
                if inConflict
                    DrawRectangle(tx + 2, ty + 2, cellW - 4, cellW - 4,
                                  RAYLIBColor(255, 60, 40, 255))
                else
                    DrawRectangle(tx + 2, ty + 2, cellW - 4, cellW - 4,
                                  RAYLIBColor(240, 200, 60, 255))
                ok
            ok

            DrawRectangleLines(tx, ty, cellW, cellW,
                               RAYLIBColor(40, 30, 20, 120))
        next
    next

    // Cursor on minimap
    cx = mapX + (cursorC - 1) * cellW
    cy = mapY + (cursorR - 1) * cellW
    DrawRectangleLines(cx, cy, cellW, cellW, RAYLIBColor(255, 255, 255, 220))

    DrawText("MAP", mapX + mapW/2 - 15, mapY - 16, 12,
             RAYLIBColor(180, 140, 60, 200))

// =============================================================
// Title Screen
// =============================================================

func nq_drawTitleScreen
    DrawRectangleGradientV(0, 0, SCREEN_W, SCREEN_H,
        RAYLIBColor(12, 8, 20, 255), RAYLIBColor(22, 15, 32, 255))

    t1 = "3D N-QUEENS PUZZLE"
    t1w = MeasureText(t1, 50)
    DrawText(t1, (SCREEN_W - t1w)/2, 45, 50, RAYLIBColor(220, 180, 80, 255))

    t2 = "~ Place N Queens Without Conflict ~"
    t2w = MeasureText(t2, 17)
    DrawText(t2, (SCREEN_W - t2w)/2, 108, 17, RAYLIBColor(180, 150, 100, 230))

    // Decorative line
    lx1 = 180
    lx2 = SCREEN_W - 180
    ly = 138
    DrawLine(lx1, ly, lx2, ly, RAYLIBColor(180, 140, 60, 180))

    // Crown icons
    DrawTriangle(
        Vector2(lx1 - 18, ly + 8), Vector2(lx1 - 10, ly - 12), Vector2(lx1 - 2, ly + 8),
        RAYLIBColor(220, 190, 60, 255))
    DrawTriangle(
        Vector2(lx2 + 2, ly + 8), Vector2(lx2 + 10, ly - 12), Vector2(lx2 + 18, ly + 8),
        RAYLIBColor(220, 190, 60, 255))

    cy = 155
    cLines = [
        "Mouse Click / ENTER     -   Place or remove a queen",
        "Arrow Keys / WASD       -   Move cursor on the board",
        "U / Backspace           -   Undo last action",
        "H                       -   Toggle threat heatmap",
        "S                       -   Auto-solve (watch backtracking!)",
        "R                       -   Clear all queens",
        "C                       -   Cycle camera view",
        "",
        "Board Sizes:",
        "  4..9  = press that number key",
        "  0=10x10   -=11x11   +=12x12",
        "",
        "Rules:",
        "  Place exactly N queens on the NxN board so that no two",
        "  queens share the same row, column, or diagonal.",
        "  Green cursor = safe square, Red cursor = threatened square.",
        "  Queens in conflict shake and glow red with threat lines."
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
    if BOARD_SZ >= 4 and BOARD_SZ <= 12
        solC = solutionCounts[BOARD_SZ + 1]
    else
        solC = 0
    ok
    st = "Board: " + BOARD_SZ + "x" + BOARD_SZ + "  |  " + solC + " known solutions"
    stw = MeasureText(st, 16)
    DrawText(st, (SCREEN_W - stw)/2, settingY, 16, RAYLIBColor(200, 180, 120, 230))

    if floor(animTime * 2) % 2 = 0
        st2 = "Click or Press ENTER / SPACE to Start"
        st2w = MeasureText(st2, 26)
        DrawText(st2, (SCREEN_W - st2w)/2, 555, 26, WHITE)
    ok

    cr = "Developed using Ring Language + RingRayLib"
    crw = MeasureText(cr, 14)
    DrawText(cr, (SCREEN_W - crw)/2, SCREEN_H - 35, 14,
             RAYLIBColor(80, 100, 80, 180))

// =============================================================
// Solved Overlay
// =============================================================

func nq_drawSolvedOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.5))

    g1 = "" + BOARD_SZ + "-QUEENS SOLVED!"
    g1w = MeasureText(g1, 48)
    pulse = floor(220 + sin(animTime * 3.0) * 35)
    DrawText(g1, (SCREEN_W - g1w)/2, 170, 48,
             RAYLIBColor(255, 220, 50, pulse))

    g2 = "All " + BOARD_SZ + " queens placed with no conflicts!"
    g2w = MeasureText(g2, 20)
    DrawText(g2, (SCREEN_W - g2w)/2, 235, 20, RAYLIBColor(100, 255, 100, 230))

    // Timer
    mins = floor(gameTimer / 60)
    secs = floor(gameTimer) % 60
    if secs < 10
        timeStr = "" + mins + ":0" + secs
    else
        timeStr = "" + mins + ":" + secs
    ok
    ts = "Time: " + timeStr
    tsw = MeasureText(ts, 20)
    DrawText(ts, (SCREEN_W - tsw)/2, 275, 20, RAYLIBColor(200, 200, 220, 220))

    // Solution count info
    if BOARD_SZ >= 4 and BOARD_SZ <= 12
        solC = solutionCounts[BOARD_SZ + 1]
        si = "This is one of " + solC + " possible solutions"
        siw = MeasureText(si, 16)
        DrawText(si, (SCREEN_W - siw)/2, 310, 16,
                 RAYLIBColor(180, 170, 200, 200))
    ok

    if floor(animTime * 2) % 2 = 0
        rt = "Press R to play again  |  ENTER for title screen"
        rtw = MeasureText(rt, 16)
        DrawText(rt, (SCREEN_W - rtw)/2, 360, 16, WHITE)
    ok

    ss = "Change size: 4..9, 0=10, -=11, +=12"
    ssw = MeasureText(ss, 14)
    DrawText(ss, (SCREEN_W - ssw)/2, 395, 14, RAYLIBColor(180, 160, 120, 200))

// =============================================================
// Message Overlay
// =============================================================

func nq_drawMessage
    alpha = floor((msgTimer / 2.0) * 255)
    if alpha > 255 alpha = 255 ok
    if alpha < 0 alpha = 0 ok

    mw = MeasureText(msgText, 24)
    mx = (SCREEN_W - mw) / 2
    my = SCREEN_H / 2 + 130

    DrawRectangle(mx - 15, my - 8, mw + 30, 40,
                  RAYLIBColor(0, 0, 0, floor(alpha * 0.7)))
    DrawText(msgText, mx, my, 24,
             RAYLIBColor(255, 220, 100, alpha))
