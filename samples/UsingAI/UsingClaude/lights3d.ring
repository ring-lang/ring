/*
**  3D Lights Out - Using RingRayLib
**  ===================================
**  Toggle lights on a grid to turn them ALL off!
**  Each press flips the pressed cell AND its orthogonal neighbors.
**
**  Controls:
**    Arrow Keys / WASD  - Move cursor on the board
**    Mouse Click        - Toggle light at cursor / hover position
**    ENTER / SPACE      - Toggle light at cursor
**    U / Backspace      - Undo last toggle
**    S                  - Show solution overlay (hints)
**    N                  - New puzzle (same board size)
**    R                  - Return to title screen
**    C                  - Cycle camera views
**    1 / 2 / 3 / 4 / 5  - Board size: 3x3/4x4/5x5/6x6/7x7
**    ESC                - Exit
**
**  Rules:
**    - Click any cell to toggle it and all orthogonal neighbors
**    - "Toggle" means ON becomes OFF, OFF becomes ON
**    - Goal: turn ALL lights OFF!
**    - Fewer moves = better score
**
**  Features:
**    - Board sizes 3x3 through 7x7
**    - 3D light pillars that rise when ON (glowing) and flatten when OFF
**    - Smooth toggle animation with height interpolation
**    - Ripple wave effect when toggling neighbors
**    - Particle bursts on each toggle
**    - Glow bloom effect around lit cells
**    - Auto-solver using Gaussian elimination over GF(2)
**    - Solution overlay shows which cells to press
**    - Guaranteed solvable puzzle generation
**    - Undo system
**    - Three camera modes: Front / Isometric / Overhead
**    - Timer and move counter
**    - Mini-map with light states
**    - Win celebration with fireworks
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W        = 1024
SCREEN_H        = 768
CELL_SZ         = 2.8

PILLAR_OFF_H    = 0.15
PILLAR_ON_H     = 1.6

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

// =============================================================
// Global Variables
// =============================================================

BOARD_SZ        = 5
board           = []        // board[r][c] = 1 (on) or 0 (off)
pillarH         = []        // current visual height (animated)
targetH         = []        // target height (PILLAR_ON_H or PILLAR_OFF_H)
toggleTime      = []        // ripple delay timers

moveCount       = 0
gameState       = ST_START
animTime        = 0.0

cursorR         = 1
cursorC         = 1

// Undo stack: [[r, c], ...] stores which cell was toggled
undoStack       = []

// Solution overlay: solution[r][c] = 1 means press this cell
solution        = []
showSolution    = false
solutionValid   = false

// Toggle animation tracking
animActive      = false
animTimer       = 0.0

// Particles: [x, y, z, vx, vy, vz, life, cr, cg, cb]
particles       = []

// Camera
cameraMode      = CAM_FRONT
camPosX = 0.0   camPosY = 16.0  camPosZ = 14.0
camTgtX = 0.0   camTgtY = 0.0   camTgtZ = 0.0

// Mouse hover
mouseHoverR     = 0
mouseHoverC     = 0
projScreenX     = 0.0
projScreenY     = 0.0

// Timer
gameTimer       = 0.0

// Message
msgText         = ""
msgTimer        = 0.0

// Light count
lightsOn        = 0

// =============================================================
// Initialize
// =============================================================

lo_initBoard()

// =============================================================
// Main Program
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Ring 3D Lights Out - RingRayLib")
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

    if msgTimer > 0
        msgTimer -= dt
        if msgTimer < 0 msgTimer = 0 ok
    ok

    // Camera
    if IsKeyPressed(KEY_C)
        cameraMode += 1
        if cameraMode > CAM_COUNT cameraMode = CAM_FRONT ok
    ok

    // Restart
    if IsKeyPressed(KEY_R)
        lo_initBoard()
        gameState = ST_START
    ok

    // Board size
    if gameState = ST_START or gameState = ST_SOLVED
        lo_checkSizeKeys()
    ok

    // ========== STATE UPDATES ==========

    if gameState = ST_START
        lo_checkSizeKeys()
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(0)
            lo_initBoard()
            lo_generatePuzzle()
            gameState = ST_PLAYING
        ok
    ok

    if gameState = ST_PLAYING
        lo_updateMouseHover()
        lo_handleInput()
        lo_handleMouse()
        lo_updatePillarAnims(dt)
        lo_updateParticles(dt)
        gameTimer += dt
    ok

    if gameState = ST_ANIMATING
        lo_updatePillarAnims(dt)
        lo_updateParticles(dt)
        animTimer -= dt
        gameTimer += dt
        if animTimer <= 0
            // Check win
            if lightsOn = 0
                gameState = ST_SOLVED
                lo_spawnWinParticles()
                lo_showMsg("ALL LIGHTS OUT!")
            else
                gameState = ST_PLAYING
            ok
        ok
    ok

    if gameState = ST_SOLVED
        lo_updatePillarAnims(dt)
        lo_updateParticles(dt)
        lo_checkSizeKeys()
        if IsKeyPressed(KEY_N)
            lo_initBoard()
            lo_generatePuzzle()
            gameState = ST_PLAYING
        ok
    ok

    lo_positionCamera()

    // ========== DRAWING ==========

    BeginDrawing()
        ClearBackground(RAYLIBColor(6, 6, 12, 255))

        if gameState = ST_START
            lo_drawTitleScreen()
        else
            BeginMode3D(camera)
                lo_drawBoard3D()
                lo_drawPillars3D()
                lo_drawCursor3D()
                lo_drawParticles3D()
            EndMode3D()

            lo_drawHUD()
            lo_drawMiniMap()

            if showSolution = true and solutionValid = true
                lo_drawSolutionOverlay()
            ok

            if gameState = ST_SOLVED
                lo_drawSolvedOverlay()
            ok

            if msgTimer > 0
                lo_drawMessage()
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
// Board Init
// =============================================================

func lo_initBoard
    board = list(BOARD_SZ)
    pillarH = list(BOARD_SZ)
    targetH = list(BOARD_SZ)
    toggleTime = list(BOARD_SZ)
    for r = 1 to BOARD_SZ
        board[r] = list(BOARD_SZ)
        pillarH[r] = list(BOARD_SZ)
        targetH[r] = list(BOARD_SZ)
        toggleTime[r] = list(BOARD_SZ)
        for c = 1 to BOARD_SZ
            board[r][c] = 0
            pillarH[r][c] = PILLAR_OFF_H
            targetH[r][c] = PILLAR_OFF_H
            toggleTime[r][c] = 0.0
        next
    next

    moveCount = 0
    undoStack = []
    particles = []
    solution = []
    showSolution = false
    solutionValid = false
    gameTimer = 0.0
    msgTimer = 0
    animActive = false
    animTimer = 0.0
    lightsOn = 0
    cursorR = floor(BOARD_SZ / 2) + 1
    cursorC = floor(BOARD_SZ / 2) + 1

    CELL_SZ = 14.0 / BOARD_SZ
    if CELL_SZ < 1.8 CELL_SZ = 1.8 ok
    if CELL_SZ > 3.6 CELL_SZ = 3.6 ok

// =============================================================
// Puzzle Generation (guaranteed solvable)
// =============================================================

func lo_generatePuzzle
    // Start from solved state (all off)
    // Apply random toggles to create puzzle
    numToggles = BOARD_SZ * BOARD_SZ / 2 + GetRandomValue(2, BOARD_SZ)
    if numToggles < 3 numToggles = 3 ok

    for i = 1 to numToggles
        tr = GetRandomValue(1, BOARD_SZ)
        tc = GetRandomValue(1, BOARD_SZ)
        lo_applyToggleRaw(tr, tc)
    next

    // Ensure at least some lights are on
    lightsOn = 0
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if board[r][c] = 1 lightsOn += 1 ok
        next
    next
    if lightsOn < 3
        // Add more toggles
        for i = 1 to 3
            tr = GetRandomValue(1, BOARD_SZ)
            tc = GetRandomValue(1, BOARD_SZ)
            lo_applyToggleRaw(tr, tc)
        next
        lightsOn = 0
        for r = 1 to BOARD_SZ
            for c = 1 to BOARD_SZ
                if board[r][c] = 1 lightsOn += 1 ok
            next
        next
    ok

    // Set initial pillar heights
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if board[r][c] = 1
                pillarH[r][c] = PILLAR_ON_H
                targetH[r][c] = PILLAR_ON_H
            else
                pillarH[r][c] = PILLAR_OFF_H
                targetH[r][c] = PILLAR_OFF_H
            ok
        next
    next

    // Compute solution
    lo_computeSolution()

func lo_applyToggleRaw r, c
    // Toggle without animation - for puzzle generation
    lo_flipCell(r, c)
    if r > 1 lo_flipCell(r-1, c) ok
    if r < BOARD_SZ lo_flipCell(r+1, c) ok
    if c > 1 lo_flipCell(r, c-1) ok
    if c < BOARD_SZ lo_flipCell(r, c+1) ok

func lo_flipCell r, c
    if board[r][c] = 0
        board[r][c] = 1
    else
        board[r][c] = 0
    ok

// =============================================================
// Toggle with Animation
// =============================================================

func lo_doToggle r, c
    // Save undo
    add(undoStack, [r, c])
    if len(undoStack) > 300
        del(undoStack, 1)
    ok

    moveCount += 1
    showSolution = false

    // Toggle cell and neighbors with ripple delay
    lo_toggleCellAnim(r, c, 0.0)
    if r > 1 lo_toggleCellAnim(r-1, c, 0.06) ok
    if r < BOARD_SZ lo_toggleCellAnim(r+1, c, 0.06) ok
    if c > 1 lo_toggleCellAnim(r, c-1, 0.06) ok
    if c < BOARD_SZ lo_toggleCellAnim(r, c+1, 0.06) ok

    // Spawn particles at toggled cell
    wx = lo_cellToX(c)
    wz = lo_cellToZ(r)
    lo_spawnToggleParticles(wx, wz)

    // Count lights
    lightsOn = 0
    for pr = 1 to BOARD_SZ
        for pc = 1 to BOARD_SZ
            if board[pr][pc] = 1 lightsOn += 1 ok
        next
    next

    // Recompute solution
    lo_computeSolution()

    animTimer = 0.35
    gameState = ST_ANIMATING

func lo_toggleCellAnim r, c, delay
    lo_flipCell(r, c)
    if board[r][c] = 1
        targetH[r][c] = PILLAR_ON_H
    else
        targetH[r][c] = PILLAR_OFF_H
    ok
    toggleTime[r][c] = delay

// =============================================================
// Undo
// =============================================================

func lo_undo
    if len(undoStack) = 0
        lo_showMsg("Nothing to undo!")
        return
    ok

    last = undoStack[len(undoStack)]
    del(undoStack, len(undoStack))

    // Re-toggle same cell (toggles are self-inverse)
    r = last[1]
    c = last[2]
    lo_flipCell(r, c)
    if r > 1 lo_flipCell(r-1, c) ok
    if r < BOARD_SZ lo_flipCell(r+1, c) ok
    if c > 1 lo_flipCell(r, c-1) ok
    if c < BOARD_SZ lo_flipCell(r, c+1) ok

    // Update targets
    for pr = 1 to BOARD_SZ
        for pc = 1 to BOARD_SZ
            if board[pr][pc] = 1
                targetH[pr][pc] = PILLAR_ON_H
            else
                targetH[pr][pc] = PILLAR_OFF_H
            ok
        next
    next

    moveCount -= 1
    if moveCount < 0 moveCount = 0 ok

    lightsOn = 0
    for pr = 1 to BOARD_SZ
        for pc = 1 to BOARD_SZ
            if board[pr][pc] = 1 lightsOn += 1 ok
        next
    next

    lo_computeSolution()
    lo_showMsg("Move undone")

// =============================================================
// Solution Solver (Gaussian elimination over GF(2))
// =============================================================

func lo_computeSolution
    n = BOARD_SZ * BOARD_SZ

    // Build augmented matrix [A | b] over GF(2)
    // A[i][j] = 1 if pressing cell j affects cell i
    // b[i] = board state of cell i
    mat = list(n)
    for i = 1 to n
        mat[i] = list(n + 1)
        for j = 1 to n + 1
            mat[i][j] = 0
        next
    next

    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            idx = (r - 1) * BOARD_SZ + c
            // Pressing (r,c) affects itself and neighbors
            mat[idx][idx] = 1
            if r > 1
                nidx = (r - 2) * BOARD_SZ + c
                mat[nidx][idx] = 1
            ok
            if r < BOARD_SZ
                nidx = r * BOARD_SZ + c
                mat[nidx][idx] = 1
            ok
            if c > 1
                nidx = (r - 1) * BOARD_SZ + c - 1
                mat[nidx][idx] = 1
            ok
            if c < BOARD_SZ
                nidx = (r - 1) * BOARD_SZ + c + 1
                mat[nidx][idx] = 1
            ok
        next
    next

    // Set b column (we want to turn off all lights that are on)
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            idx = (r - 1) * BOARD_SZ + c
            mat[idx][n + 1] = board[r][c]
        next
    next

    // Gaussian elimination over GF(2)
    pivotRow = 1
    pivotCols = list(n)
    for i = 1 to n
        pivotCols[i] = 0
    next

    for col = 1 to n
        // Find pivot
        found = false
        for row = pivotRow to n
            if mat[row][col] = 1
                found = true
                // Swap rows
                if row != pivotRow
                    for k = 1 to n + 1
                        tmp = mat[pivotRow][k]
                        mat[pivotRow][k] = mat[row][k]
                        mat[row][k] = tmp
                    next
                ok
                // Eliminate
                for row2 = 1 to n
                    if row2 != pivotRow and mat[row2][col] = 1
                        for k = 1 to n + 1
                            mat[row2][k] = (mat[row2][k] + mat[pivotRow][k]) % 2
                        next
                    ok
                next
                pivotCols[pivotRow] = col
                pivotRow += 1
                // Break out of for row loop
                row = n + 1
            ok
        next
    next

    // Extract solution
    solution = list(BOARD_SZ)
    for r = 1 to BOARD_SZ
        solution[r] = list(BOARD_SZ)
        for c = 1 to BOARD_SZ
            solution[r][c] = 0
        next
    next

    solutionValid = true

    // Check consistency and extract
    for i = 1 to n
        if pivotCols[i] > 0
            col = pivotCols[i]
            val = mat[i][n + 1]
            sr = floor((col - 1) / BOARD_SZ) + 1
            sc = ((col - 1) % BOARD_SZ) + 1
            solution[sr][sc] = val
        ok
    next

    // Count solution moves
    solMoves = 0
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if solution[r][c] = 1 solMoves += 1 ok
        next
    next

// =============================================================
// Size Keys
// =============================================================

func lo_checkSizeKeys
    if IsKeyPressed(KEY_ONE)
        BOARD_SZ = 3
        lo_initBoard()
    ok
    if IsKeyPressed(KEY_TWO)
        BOARD_SZ = 4
        lo_initBoard()
    ok
    if IsKeyPressed(KEY_THREE)
        BOARD_SZ = 5
        lo_initBoard()
    ok
    if IsKeyPressed(KEY_FOUR)
        BOARD_SZ = 6
        lo_initBoard()
    ok
    if IsKeyPressed(KEY_FIVE)
        BOARD_SZ = 7
        lo_initBoard()
    ok

// =============================================================
// Input Handling
// =============================================================

func lo_handleInput
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

    // Toggle
    if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
        lo_doToggle(cursorR, cursorC)
    ok

    // Undo
    if IsKeyPressed(KEY_U) or IsKeyPressed(KEY_BACKSPACE)
        lo_undo()
    ok

    // Solution overlay
    if IsKeyPressed(KEY_S)
        if showSolution = true
            showSolution = false
            lo_showMsg("Solution hints OFF")
        else
            showSolution = true
            lo_showMsg("Solution hints ON")
        ok
    ok

    // New puzzle
    if IsKeyPressed(KEY_N)
        lo_initBoard()
        lo_generatePuzzle()
        gameState = ST_PLAYING
        lo_showMsg("New puzzle!")
    ok

// =============================================================
// Mouse Handling
// =============================================================

func lo_updateMouseHover
    mx = GetMouseX()
    my = GetMouseY()

    bestDist = 999999.0
    bestR = 0
    bestC = 0

    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            wx = lo_cellToX(c)
            wz = lo_cellToZ(r)
            lo_projectToScreen(wx, 0.3, wz)
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

    threshDist = 2200
    if BOARD_SZ >= 5 threshDist = 1800 ok
    if BOARD_SZ >= 6 threshDist = 1400 ok
    if BOARD_SZ >= 7 threshDist = 1100 ok

    if bestDist < threshDist
        mouseHoverR = bestR
        mouseHoverC = bestC
        cursorR = bestR
        cursorC = bestC
    else
        mouseHoverR = 0
        mouseHoverC = 0
    ok

func lo_handleMouse
    if IsMouseButtonPressed(0)
        if mouseHoverR >= 1 and mouseHoverR <= BOARD_SZ
            lo_doToggle(mouseHoverR, mouseHoverC)
        ok
    ok

// =============================================================
// Pillar Height Animation
// =============================================================

func lo_updatePillarAnims dt
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            // Ripple delay
            if toggleTime[r][c] > 0
                toggleTime[r][c] -= dt
                loop
            ok

            // Lerp toward target
            diff = targetH[r][c] - pillarH[r][c]
            if diff > 0.01 or diff < -0.01
                pillarH[r][c] += diff * 10.0 * dt
            else
                pillarH[r][c] = targetH[r][c]
            ok
        next
    next

// =============================================================
// Particles
// =============================================================

func lo_spawnToggleParticles wx, wz
    for i = 1 to 12
        vx = (GetRandomValue(-150, 150) / 100.0)
        vy = (GetRandomValue(200, 500) / 100.0)
        vz = (GetRandomValue(-150, 150) / 100.0)
        cr = GetRandomValue(200, 255)
        cg = GetRandomValue(200, 255)
        cb = GetRandomValue(50, 150)
        add(particles, [wx, 0.8, wz, vx, vy, vz, 0.9, cr, cg, cb])
    next

func lo_spawnWinParticles
    for i = 1 to 80
        wx = (GetRandomValue(-600, 600) / 100.0)
        wz = (GetRandomValue(-600, 600) / 100.0)
        vx = (GetRandomValue(-250, 250) / 100.0)
        vy = (GetRandomValue(400, 900) / 100.0)
        vz = (GetRandomValue(-250, 250) / 100.0)
        cr = GetRandomValue(100, 255)
        cg = GetRandomValue(200, 255)
        cb = GetRandomValue(50, 255)
        add(particles, [wx, 0.5, wz, vx, vy, vz, 2.5, cr, cg, cb])
    next

func lo_updateParticles dt
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

func lo_drawParticles3D
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
// Helpers
// =============================================================

func lo_cellToX c
    return (c - 1) * CELL_SZ - (BOARD_SZ - 1) * CELL_SZ / 2

func lo_cellToZ r
    return (r - 1) * CELL_SZ - (BOARD_SZ - 1) * CELL_SZ / 2

func lo_showMsg text
    msgText = text
    msgTimer = 2.0

// =============================================================
// 3D-to-Screen Projection
// =============================================================

func lo_projectToScreen wx, wy, wz
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
// Camera
// =============================================================

func lo_positionCamera
    boardW = BOARD_SZ * CELL_SZ
    maxDim = boardW

    goalX = 0  goalY = 0  goalZ = 0
    tgtX = 0   tgtY = 0   tgtZ = 0

    if cameraMode = CAM_FRONT
        goalX = 0
        goalY = maxDim * 0.9 + 4.0
        goalZ = maxDim * 0.8 + 4.0
        tgtX = 0
        tgtY = 0.5
        tgtZ = -0.5
    ok
    if cameraMode = CAM_ISOMETRIC
        goalX = maxDim * 0.7 + 2.0
        goalY = maxDim * 0.85 + 3.0
        goalZ = maxDim * 0.7 + 2.0
        tgtX = 0
        tgtY = 0.5
        tgtZ = 0
    ok
    if cameraMode = CAM_OVERHEAD
        goalX = 0
        goalY = maxDim * 1.2 + 6.0
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

func lo_drawBoard3D
    boardW = BOARD_SZ * CELL_SZ

    // Board slab
    slabH = 0.3
    DrawCube(Vector3(0, -slabH/2, 0),
             boardW + 1.0, slabH, boardW + 1.0,
             RAYLIBColor(25, 25, 35, 255))
    DrawCubeWires(Vector3(0, -slabH/2, 0),
                  boardW + 1.0, slabH, boardW + 1.0,
                  RAYLIBColor(15, 15, 22, 200))

    // Cell bases
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            wx = lo_cellToX(c)
            wz = lo_cellToZ(r)
            tileSz = CELL_SZ * 0.92
            DrawCube(Vector3(wx, 0.02, wz), tileSz, 0.04, tileSz,
                     RAYLIBColor(18, 18, 28, 255))
            DrawCubeWires(Vector3(wx, 0.02, wz), tileSz, 0.04, tileSz,
                          RAYLIBColor(35, 35, 50, 180))
        next
    next

    // Border
    bThick = 0.2
    bH = 0.22
    halfE = boardW / 2 + 0.4
    edgeCol = RAYLIBColor(40, 40, 55, 255)
    DrawCube(Vector3(0, bH/2, -halfE), boardW + 1.0, bH, bThick, edgeCol)
    DrawCube(Vector3(0, bH/2, halfE),  boardW + 1.0, bH, bThick, edgeCol)
    DrawCube(Vector3(-halfE, bH/2, 0), bThick, bH, boardW + 0.7, edgeCol)
    DrawCube(Vector3(halfE, bH/2, 0),  bThick, bH, boardW + 0.7, edgeCol)

    // Table
    DrawPlane(Vector3(0, -slabH - 0.01, 0), Vector2(40, 40),
              RAYLIBColor(4, 4, 8, 255))

// =============================================================
// 3D Drawing: Light Pillars
// =============================================================

func lo_drawPillars3D
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            wx = lo_cellToX(c)
            wz = lo_cellToZ(r)
            h = pillarH[r][c]
            isOn = board[r][c]
            tileSz = CELL_SZ * 0.85

            if isOn = 1
                // ON state: bright glowing pillar
                // Glow intensity with subtle pulse
                pulse = 0.85 + sin(animTime * 3.0 + r * 1.1 + c * 0.7) * 0.15

                // Main pillar body
                DrawCube(Vector3(wx, h/2 + 0.05, wz),
                         tileSz, h, tileSz,
                         RAYLIBColor(floor(255 * pulse), floor(220 * pulse),
                                     floor(60 * pulse), 255))
                DrawCubeWires(Vector3(wx, h/2 + 0.05, wz),
                              tileSz, h, tileSz,
                              RAYLIBColor(200, 180, 40, 180))

                // Top glow cap
                DrawCube(Vector3(wx, h + 0.06, wz),
                         tileSz * 0.7, 0.06, tileSz * 0.7,
                         RAYLIBColor(255, 255, 200, 200))

                // Bloom glow (larger transparent cube)
                glowSz = tileSz * 1.2
                gAlpha = floor(40 * pulse)
                DrawCube(Vector3(wx, h/2 + 0.05, wz),
                         glowSz, h + 0.3, glowSz,
                         RAYLIBColor(255, 230, 80, gAlpha))

                // Light beam above
                beamH = 0.6
                beamAlpha = floor(30 * pulse)
                DrawCube(Vector3(wx, h + beamH/2 + 0.1, wz),
                         tileSz * 0.4, beamH, tileSz * 0.4,
                         RAYLIBColor(255, 255, 180, beamAlpha))

                // Solution hint marker
                if showSolution = true and solutionValid = true
                    if solution[r][c] = 1
                        hintPulse = 0.5 + sin(animTime * 8.0) * 0.5
                        hAlpha = floor(100 * hintPulse)
                        DrawCube(Vector3(wx, h + 0.2, wz),
                                 tileSz * 1.1, 0.1, tileSz * 1.1,
                                 RAYLIBColor(0, 255, 100, hAlpha))
                    ok
                ok
            else
                // OFF state: low dark tile
                DrawCube(Vector3(wx, h/2 + 0.05, wz),
                         tileSz, h, tileSz,
                         RAYLIBColor(40, 40, 55, 255))
                DrawCubeWires(Vector3(wx, h/2 + 0.05, wz),
                              tileSz, h, tileSz,
                              RAYLIBColor(55, 55, 70, 160))

                // Subtle top
                DrawCube(Vector3(wx, h + 0.06, wz),
                         tileSz * 0.8, 0.03, tileSz * 0.8,
                         RAYLIBColor(50, 50, 65, 200))

                // Solution hint on OFF cells too
                if showSolution = true and solutionValid = true
                    if solution[r][c] = 1
                        hintPulse = 0.5 + sin(animTime * 8.0) * 0.5
                        hAlpha = floor(80 * hintPulse)
                        DrawCube(Vector3(wx, h + 0.12, wz),
                                 tileSz * 1.05, 0.08, tileSz * 1.05,
                                 RAYLIBColor(0, 255, 100, hAlpha))
                    ok
                ok
            ok
        next
    next

// =============================================================
// 3D Drawing: Cursor
// =============================================================

func lo_drawCursor3D
    if gameState != ST_PLAYING return ok

    wx = lo_cellToX(cursorC)
    wz = lo_cellToZ(cursorR)

    curCol = RAYLIBColor(100, 220, 255, 200)

    // Corner brackets
    hs = CELL_SZ * 0.48
    bLen = CELL_SZ * 0.2
    by = 0.06

    DrawLine3D(Vector3(wx-hs, by, wz-hs), Vector3(wx-hs+bLen, by, wz-hs), curCol)
    DrawLine3D(Vector3(wx-hs, by, wz-hs), Vector3(wx-hs, by, wz-hs+bLen), curCol)
    DrawLine3D(Vector3(wx+hs, by, wz-hs), Vector3(wx+hs-bLen, by, wz-hs), curCol)
    DrawLine3D(Vector3(wx+hs, by, wz-hs), Vector3(wx+hs, by, wz-hs+bLen), curCol)
    DrawLine3D(Vector3(wx-hs, by, wz+hs), Vector3(wx-hs+bLen, by, wz+hs), curCol)
    DrawLine3D(Vector3(wx-hs, by, wz+hs), Vector3(wx-hs, by, wz+hs-bLen), curCol)
    DrawLine3D(Vector3(wx+hs, by, wz+hs), Vector3(wx+hs-bLen, by, wz+hs), curCol)
    DrawLine3D(Vector3(wx+hs, by, wz+hs), Vector3(wx+hs, by, wz+hs-bLen), curCol)

    // Neighbor indicator lines
    nAlpha = floor(80 + sin(animTime * 4.0) * 40)
    nCol = RAYLIBColor(100, 200, 255, nAlpha)
    nsz = CELL_SZ * 0.3

    if cursorR > 1
        nwx = lo_cellToX(cursorC)
        nwz = lo_cellToZ(cursorR - 1)
        DrawCube(Vector3(nwx, 0.07, nwz), nsz, 0.04, nsz, nCol)
    ok
    if cursorR < BOARD_SZ
        nwx = lo_cellToX(cursorC)
        nwz = lo_cellToZ(cursorR + 1)
        DrawCube(Vector3(nwx, 0.07, nwz), nsz, 0.04, nsz, nCol)
    ok
    if cursorC > 1
        nwx = lo_cellToX(cursorC - 1)
        nwz = lo_cellToZ(cursorR)
        DrawCube(Vector3(nwx, 0.07, nwz), nsz, 0.04, nsz, nCol)
    ok
    if cursorC < BOARD_SZ
        nwx = lo_cellToX(cursorC + 1)
        nwz = lo_cellToZ(cursorR)
        DrawCube(Vector3(nwx, 0.07, nwz), nsz, 0.04, nsz, nCol)
    ok

// =============================================================
// HUD
// =============================================================

func lo_drawHUD
    panelW = 255
    panelH = 155
    DrawRectangle(10, 30, panelW, panelH, Fade(BLACK, 0.75))
    DrawRectangleLines(10, 30, panelW, panelH, RAYLIBColor(255, 220, 60, 200))

    DrawText("LIGHTS OUT", 20, 38, 22, RAYLIBColor(255, 230, 80, 255))

    DrawText("Board: " + BOARD_SZ + "x" + BOARD_SZ, 20, 66, 14,
             RAYLIBColor(160, 180, 200, 200))

    DrawText("Moves: " + moveCount, 20, 84, 18, RAYLIBColor(255, 255, 255, 240))

    // Timer
    mins = floor(gameTimer / 60)
    secs = floor(gameTimer) % 60
    if secs < 10
        timeStr = "" + mins + ":0" + secs
    else
        timeStr = "" + mins + ":" + secs
    ok
    DrawText("Time: " + timeStr, 20, 106, 14,
             RAYLIBColor(200, 200, 220, 200))

    // Lights remaining
    total = BOARD_SZ * BOARD_SZ
    DrawText("Lights ON: " + lightsOn + "/" + total, 20, 126, 16,
             RAYLIBColor(255, 200, 60, 230))

    // Progress bar (inverted - full when all off)
    barX = 20
    barY = 148
    barW = 225
    barH = 10
    DrawRectangle(barX, barY, barW, barH, RAYLIBColor(60, 60, 30, 200))
    if total > 0
        offCount = total - lightsOn
        fillW = floor(barW * offCount / total)
        if fillW > 0
            DrawRectangle(barX, barY, fillW, barH,
                          RAYLIBColor(80, 200, 80, 220))
        ok
    ok
    DrawRectangleLines(barX, barY, barW, barH, RAYLIBColor(120, 120, 60, 180))

    // Solution hint count
    if solutionValid = true
        solMoves = 0
        for r = 1 to BOARD_SZ
            for c = 1 to BOARD_SZ
                if solution[r][c] = 1 solMoves += 1 ok
            next
        next
        DrawText("Optimal: " + solMoves + " moves [S]", 20, 163, 11,
                 RAYLIBColor(100, 200, 100, 160))
    ok

    // Camera
    camName = "FRONT"
    if cameraMode = CAM_ISOMETRIC camName = "ISOMETRIC" ok
    if cameraMode = CAM_OVERHEAD  camName = "OVERHEAD"  ok
    DrawRectangle(10, SCREEN_H - 60, 220, 25, Fade(BLACK, 0.6))
    DrawText("Cam: " + camName + "  [C] switch", 16, SCREEN_H - 56, 14,
             RAYLIBColor(150, 180, 210, 220))

    // Controls
    DrawRectangle(SCREEN_W - 480, SCREEN_H - 35, 470, 25, Fade(BLACK, 0.6))
    DrawText("Click/Enter: Toggle | U: Undo | S: Solution | N: New | R: Title",
             SCREEN_W - 476, SCREEN_H - 30, 12, RAYLIBColor(150, 160, 180, 200))

// =============================================================
// Mini Map
// =============================================================

func lo_drawMiniMap
    cellW = 24
    if BOARD_SZ >= 5 cellW = 20 ok
    if BOARD_SZ >= 6 cellW = 16 ok
    if BOARD_SZ >= 7 cellW = 14 ok
    mapW = BOARD_SZ * cellW + 4
    mapH = BOARD_SZ * cellW + 4
    mapX = SCREEN_W - mapW - 15
    mapY = 30

    DrawRectangle(mapX - 3, mapY - 3, mapW + 6, mapH + 6, Fade(BLACK, 0.8))
    DrawRectangleLines(mapX - 3, mapY - 3, mapW + 6, mapH + 6,
                       RAYLIBColor(255, 220, 60, 200))

    DrawRectangle(mapX, mapY, mapW, mapH, RAYLIBColor(15, 15, 22, 230))

    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            tx = mapX + 2 + (c - 1) * cellW
            ty = mapY + 2 + (r - 1) * cellW
            tw = cellW - 2
            th = cellW - 2

            if board[r][c] = 1
                // ON
                pulse = 0.8 + sin(animTime * 3.0 + r + c) * 0.2
                br = floor(255 * pulse)
                bg = floor(220 * pulse)
                bb = floor(60 * pulse)
                DrawRectangle(tx, ty, tw, th, RAYLIBColor(br, bg, bb, 255))
            else
                // OFF
                DrawRectangle(tx, ty, tw, th, RAYLIBColor(30, 30, 42, 220))
            ok

            // Solution marker
            if showSolution = true and solutionValid = true
                if solution[r][c] = 1
                    DrawRectangleLines(tx + 1, ty + 1, tw - 2, th - 2,
                                       RAYLIBColor(0, 255, 100, 200))
                ok
            ok

            DrawRectangleLines(tx, ty, tw, th,
                               RAYLIBColor(45, 45, 60, 120))
        next
    next

    // Cursor
    cxm = mapX + 2 + (cursorC - 1) * cellW
    cym = mapY + 2 + (cursorR - 1) * cellW
    DrawRectangleLines(cxm, cym, cellW - 2, cellW - 2,
                       RAYLIBColor(100, 220, 255, 220))

    DrawText("MAP", mapX + mapW/2 - 15, mapY - 16, 12,
             RAYLIBColor(255, 220, 60, 200))

// =============================================================
// Solution Overlay (2D projected markers)
// =============================================================

func lo_drawSolutionOverlay
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if solution[r][c] = 1
                wx = lo_cellToX(c)
                wz = lo_cellToZ(r)
                h = pillarH[r][c]
                lo_projectToScreen(wx, h + 0.5, wz)
                if projScreenX > -100 and projScreenX < SCREEN_W + 100
                    if projScreenY > -100 and projScreenY < SCREEN_H + 100
                        sx = floor(projScreenX)
                        sy = floor(projScreenY)
                        pulse = 0.5 + sin(animTime * 6.0 + r + c) * 0.5
                        alpha = floor(200 * pulse)
                        // Arrow down indicator
                        DrawTriangle(
                            Vector2(sx, sy + 12),
                            Vector2(sx + 10, sy - 4),
                            Vector2(sx - 10, sy - 4),
                            RAYLIBColor(0, 255, 100, alpha)
                        )
                        DrawText("!", sx - 3, sy - 20, 16,
                                 RAYLIBColor(0, 255, 100, alpha))
                    ok
                ok
            ok
        next
    next

// =============================================================
// Title Screen
// =============================================================

func lo_drawTitleScreen
    DrawRectangleGradientV(0, 0, SCREEN_W, SCREEN_H,
        RAYLIBColor(4, 4, 10, 255), RAYLIBColor(12, 10, 20, 255))

    // Animated light grid background
    bgCellW = 50
    for br = 0 to floor(SCREEN_H / bgCellW)
        for bc = 0 to floor(SCREEN_W / bgCellW)
            bx = bc * bgCellW + 10
            by2 = br * bgCellW + 10
            litBg = sin(animTime * 1.5 + br * 0.8 + bc * 1.2)
            if litBg > 0.3
                bAlpha = floor(20 + litBg * 25)
                DrawRectangle(bx, by2, bgCellW - 4, bgCellW - 4,
                              RAYLIBColor(255, 220, 60, bAlpha))
            ok
        next
    next

    t1 = "LIGHTS OUT"
    t1w = MeasureText(t1, 60)
    DrawText(t1, (SCREEN_W - t1w)/2, 30, 60, RAYLIBColor(255, 230, 80, 255))

    t1b = "3D EDITION"
    t1bw = MeasureText(t1b, 22)
    DrawText(t1b, (SCREEN_W - t1bw)/2, 98, 22, RAYLIBColor(255, 255, 180, 230))

    t2 = "~ Turn All the Lights Off! ~"
    t2w = MeasureText(t2, 17)
    DrawText(t2, (SCREEN_W - t2w)/2, 130, 17, RAYLIBColor(200, 200, 180, 230))

    ly = 158
    DrawLine(180, ly, SCREEN_W - 180, ly, RAYLIBColor(255, 220, 60, 180))

    // Mini demo grid
    demoSz = 22
    demoX = (SCREEN_W - 5 * (demoSz + 3)) / 2
    for dr = 0 to 4
        for dc = 0 to 4
            dx2 = demoX + dc * (demoSz + 3)
            dy2 = 170 + dr * (demoSz + 3)
            litDemo = sin(animTime * 2.0 + dr * 1.0 + dc * 1.3)
            if litDemo > 0
                DrawRectangle(dx2, dy2, demoSz, demoSz,
                              RAYLIBColor(255, 220, 60, 220))
            else
                DrawRectangle(dx2, dy2, demoSz, demoSz,
                              RAYLIBColor(40, 40, 55, 200))
            ok
            DrawRectangleLines(dx2, dy2, demoSz, demoSz,
                               RAYLIBColor(80, 80, 100, 120))
        next
    next

    cy = 310
    cLines = [
        "Click / ENTER / SPACE  -   Toggle cell + neighbors",
        "Arrow Keys / WASD      -   Move cursor",
        "U / Backspace          -   Undo last toggle",
        "S                      -   Show solution hints",
        "N                      -   New puzzle (same size)",
        "R                      -   Return to title screen",
        "C                      -   Cycle camera view",
        "",
        "Board Sizes:  1=3x3  2=4x4  3=5x5  4=6x6  5=7x7",
        "",
        "Rules:",
        "  Each press toggles the cell AND its 4 neighbors.",
        "  Toggle means ON becomes OFF and OFF becomes ON.",
        "  Goal: turn ALL lights OFF using fewest moves!",
        "  Press S to see which cells to press for the solution."
    ]
    for i = 1 to len(cLines)
        lw = MeasureText(cLines[i], 13)
        if i >= 9
            col = RAYLIBColor(255, 240, 180, 210)
        else
            col = RAYLIBColor(180, 180, 200, 230)
        ok
        DrawText(cLines[i], (SCREEN_W - lw)/2, cy + (i - 1) * 20, 13, col)
    next

    sizeStr = "Current: " + BOARD_SZ + "x" + BOARD_SZ
    ssw = MeasureText(sizeStr, 18)
    DrawText(sizeStr, (SCREEN_W - ssw)/2, 625, 18,
             RAYLIBColor(255, 230, 80, 230))

    if floor(animTime * 2) % 2 = 0
        st2 = "Click or Press ENTER / SPACE to Start"
        st2w = MeasureText(st2, 24)
        DrawText(st2, (SCREEN_W - st2w)/2, 655, 24, WHITE)
    ok

    cr = "Developed using Ring Language + RingRayLib"
    crw = MeasureText(cr, 14)
    DrawText(cr, (SCREEN_W - crw)/2, SCREEN_H - 28, 14,
             RAYLIBColor(80, 100, 80, 180))

// =============================================================
// Solved Overlay
// =============================================================

func lo_drawSolvedOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.55))

    g1 = "ALL LIGHTS OUT!"
    g1w = MeasureText(g1, 48)
    pulse = floor(220 + sin(animTime * 3.0) * 35)
    DrawText(g1, (SCREEN_W - g1w)/2, 170, 48,
             RAYLIBColor(80, 255, 120, pulse))

    g2 = "Darkness achieved!"
    g2w = MeasureText(g2, 20)
    DrawText(g2, (SCREEN_W - g2w)/2, 230, 20, RAYLIBColor(200, 255, 200, 220))

    g3 = "Moves: " + moveCount
    g3w = MeasureText(g3, 24)
    DrawText(g3, (SCREEN_W - g3w)/2, 270, 24, RAYLIBColor(255, 255, 255, 240))

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
    DrawText(ts, (SCREEN_W - tsw)/2, 304, 20, RAYLIBColor(200, 200, 220, 220))

    if floor(animTime * 2) % 2 = 0
        rt = "Press N for new puzzle  |  R for title screen"
        rtw = MeasureText(rt, 16)
        DrawText(rt, (SCREEN_W - rtw)/2, 350, 16, WHITE)
    ok

    ss = "Change size: 1=3x3  2=4x4  3=5x5  4=6x6  5=7x7"
    ssw = MeasureText(ss, 14)
    DrawText(ss, (SCREEN_W - ssw)/2, 385, 14, RAYLIBColor(180, 200, 220, 200))

// =============================================================
// Message Overlay
// =============================================================

func lo_drawMessage
    alpha = floor((msgTimer / 2.0) * 255)
    if alpha > 255 alpha = 255 ok
    if alpha < 0 alpha = 0 ok

    mw = MeasureText(msgText, 24)
    mx = (SCREEN_W - mw) / 2
    my = SCREEN_H / 2 + 150

    DrawRectangle(mx - 15, my - 8, mw + 30, 40,
                  RAYLIBColor(0, 0, 0, floor(alpha * 0.7)))
    DrawText(msgText, mx, my, 24,
             RAYLIBColor(255, 230, 80, alpha))
