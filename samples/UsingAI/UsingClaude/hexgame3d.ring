/*
**  3D Hex Game - Using RingRayLib
**  =================================
**  The classic connection game on a diamond-shaped board!
**  Two players compete to connect opposite sides.
**
**  Controls:
**    Arrow Keys / WASD  - Move cursor on the hex grid
**    Mouse Click        - Place stone at hovered hex cell
**    ENTER / SPACE      - Place stone at cursor
**    U / Backspace      - Undo last move
**    M                  - Toggle game mode (PvP / vs AI)
**    N                  - New game (same board size)
**    R                  - Return to title screen
**    C                  - Cycle camera views
**    1/2/3/4/5          - Board: 5x5/7x7/9x9/11x11/13x13
**    ESC                - Exit
**
**  Rules:
**    - Red plays first, then Blue
**    - Red connects TOP edge to BOTTOM edge
**    - Blue connects LEFT edge to RIGHT edge
**    - Place one stone per turn on any empty hex
**    - First player to complete a connected path wins!
**    - No draws are possible in Hex (proven mathematically)
**
**  Features:
**    - Diamond-shaped hex grid (rhombus topology)
**    - Board sizes from 5x5 to 13x13
**    - 3D hexagonal cells with stone placement
**    - Smooth drop animation for placed stones
**    - BFS path connectivity for win detection
**    - Winning path highlighted with glow
**    - AI opponent (BFS-distance heuristic)
**    - Edge coloring shows connection goals
**    - Three camera modes
**    - Particle effects on placement and win
**    - Undo system
**    - Mini-map with hex layout
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W        = 1024
SCREEN_H        = 768

// Cell states
HEX_EMPTY       = 0
HEX_RED         = 1
HEX_BLUE        = 2

// Game states
ST_START        = 1
ST_PLAYING      = 2
ST_WON          = 3

// Camera modes
CAM_FRONT       = 1
CAM_ISOMETRIC   = 2
CAM_OVERHEAD    = 3
CAM_COUNT       = 3

// Game modes
MODE_PVP        = 1
MODE_PVA        = 2

PI              = 3.14159265

// =============================================================
// Global Variables
// =============================================================

BOARD_SZ        = 9
CELL_SZ         = 1.4
board           = []        // board[r][c] = HEX_EMPTY/RED/BLUE

currentPlayer   = HEX_RED
moveCount       = 0
gameState       = ST_START
animTime        = 0.0
gameMode        = MODE_PVA

cursorR         = 1
cursorC         = 1

// Winner info
winner          = 0
winPath         = []        // [[r,c], ...] winning connected path

// Undo: [[r, c, player], ...]
undoStack       = []

// Drop animations: [[r, c, player, progress], ...]
dropAnims       = []

// Particles
particles       = []

// Camera
cameraMode      = CAM_FRONT
camPosX = 0.0   camPosY = 18.0  camPosZ = 16.0
camTgtX = 0.0   camTgtY = 0.0   camTgtZ = 0.0

// Mouse hover
mouseHoverR     = 0
mouseHoverC     = 0
projScreenX     = 0.0
projScreenY     = 0.0

// Message
msgText         = ""
msgTimer        = 0.0

// =============================================================
// Initialize
// =============================================================

hx_initBoard()

// =============================================================
// Main Program
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Ring 3D Hex Game - RingRayLib")
SetTargetFPS(60)

camera = Camera3D(
    0, 18, 16,
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
        hx_initBoard()
        gameState = ST_START
    ok

    // Board size
    if gameState = ST_START or gameState = ST_WON
        hx_checkSizeKeys()
    ok

    // Mode toggle
    if IsKeyPressed(KEY_M)
        if gameMode = MODE_PVP
            gameMode = MODE_PVA
            hx_showMsg("Mode: vs AI (Blue)")
        else
            gameMode = MODE_PVP
            hx_showMsg("Mode: Player vs Player")
        ok
    ok

    // ========== STATE UPDATES ==========

    if gameState = ST_START
        hx_checkSizeKeys()
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(0)
            hx_initBoard()
            gameState = ST_PLAYING
        ok
    ok

    if gameState = ST_PLAYING
        hx_updateMouseHover()
        hx_handleInput()
        hx_handleMouse()
        hx_updateDropAnims(dt)
        hx_updateParticles(dt)

        // AI turn
        if gameMode = MODE_PVA and currentPlayer = HEX_BLUE
            if len(dropAnims) = 0
                hx_aiMove()
            ok
        ok
    ok

    if gameState = ST_WON
        hx_updateParticles(dt)
        hx_checkSizeKeys()
        if IsKeyPressed(KEY_N)
            hx_initBoard()
            gameState = ST_PLAYING
        ok
    ok

    hx_positionCamera()

    // ========== DRAWING ==========

    BeginDrawing()
        ClearBackground(RAYLIBColor(14, 12, 20, 255))

        if gameState = ST_START
            hx_drawTitleScreen()
        else
            BeginMode3D(camera)
                hx_drawBoard3D()
                hx_drawStones3D()
                hx_drawDropAnims3D()
                hx_drawCursor3D()
                hx_drawParticles3D()
            EndMode3D()

            hx_drawHUD()
            hx_drawMiniMap()

            if gameState = ST_WON
                hx_drawWonOverlay()
            ok
            if msgTimer > 0
                hx_drawMessage()
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

func hx_initBoard
    board = list(BOARD_SZ)
    for r = 1 to BOARD_SZ
        board[r] = list(BOARD_SZ)
        for c = 1 to BOARD_SZ
            board[r][c] = HEX_EMPTY
        next
    next

    currentPlayer = HEX_RED
    moveCount = 0
    winner = 0
    winPath = []
    undoStack = []
    dropAnims = []
    particles = []
    msgTimer = 0
    cursorR = floor(BOARD_SZ / 2) + 1
    cursorC = floor(BOARD_SZ / 2) + 1

    CELL_SZ = 16.0 / BOARD_SZ
    if CELL_SZ < 1.0 CELL_SZ = 1.0 ok
    if CELL_SZ > 2.0 CELL_SZ = 2.0 ok

// =============================================================
// Hex Grid Coordinate Helpers
// =============================================================

// Hex to world: offset coordinate system
// Rows go top-to-bottom, columns left-to-right
// Each row is offset by half a cell width to form diamond
func hx_cellToX r, c
    // Raw hex position: column spacing + row offset for diamond
    cx = (c - 1) * CELL_SZ * 0.866 * 2.0
    cx += (r - 1) * CELL_SZ * 0.866
    // Center: average of cell(1,1) and cell(N,N) raw positions
    // raw(1,1) = 0, raw(N,N) = (N-1)*sz*0.866*2 + (N-1)*sz*0.866 = (N-1)*sz*0.866*3
    cx -= (BOARD_SZ - 1) * CELL_SZ * 0.866 * 3.0 / 2.0
    return cx

func hx_cellToZ r, c
    cz = (r - 1) * CELL_SZ * 1.5
    cz -= (BOARD_SZ - 1) * CELL_SZ * 1.5 / 2.0
    return cz

// 6 hex neighbors (offset coords for hex grid)
func hx_getNeighbors r, c
    nbrs = []
    // Same-row neighbors
    if c > 1 add(nbrs, [r, c-1]) ok
    if c < BOARD_SZ add(nbrs, [r, c+1]) ok
    // Row above
    if r > 1
        add(nbrs, [r-1, c])
        if c < BOARD_SZ add(nbrs, [r-1, c+1]) ok
    ok
    // Row below
    if r < BOARD_SZ
        add(nbrs, [r+1, c])
        if c > 1 add(nbrs, [r+1, c-1]) ok
    ok
    return nbrs

// =============================================================
// Size Keys
// =============================================================

func hx_checkSizeKeys
    if IsKeyPressed(KEY_ONE)
        BOARD_SZ = 5
        hx_initBoard()
    ok
    if IsKeyPressed(KEY_TWO)
        BOARD_SZ = 7
        hx_initBoard()
    ok
    if IsKeyPressed(KEY_THREE)
        BOARD_SZ = 9
        hx_initBoard()
    ok
    if IsKeyPressed(KEY_FOUR)
        BOARD_SZ = 11
        hx_initBoard()
    ok
    if IsKeyPressed(KEY_FIVE)
        BOARD_SZ = 13
        hx_initBoard()
    ok

// =============================================================
// Input Handling
// =============================================================

func hx_handleInput
    // Cursor movement on hex grid
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

    // Place stone
    if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
        hx_placeStone(cursorR, cursorC)
    ok

    // Undo
    if IsKeyPressed(KEY_U) or IsKeyPressed(KEY_BACKSPACE)
        hx_undo()
    ok

    // New game
    if IsKeyPressed(KEY_N)
        hx_initBoard()
        gameState = ST_PLAYING
        hx_showMsg("New game!")
    ok

// =============================================================
// Mouse Handling
// =============================================================

func hx_updateMouseHover
    mx = GetMouseX()
    my = GetMouseY()

    bestDist = 999999.0
    bestR = 0
    bestC = 0

    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            wx = hx_cellToX(r, c)
            wz = hx_cellToZ(r, c)
            hx_projectToScreen(wx, 0.15, wz)
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
    if BOARD_SZ >= 9 threshDist = 1200 ok
    if BOARD_SZ >= 11 threshDist = 800 ok
    if BOARD_SZ >= 13 threshDist = 600 ok

    if bestDist < threshDist
        mouseHoverR = bestR
        mouseHoverC = bestC
    else
        mouseHoverR = 0
        mouseHoverC = 0
    ok

func hx_handleMouse
    if IsMouseButtonPressed(0)
        if mouseHoverR >= 1 and mouseHoverR <= BOARD_SZ
            hx_placeStone(mouseHoverR, mouseHoverC)
        ok
    ok

// =============================================================
// Place Stone
// =============================================================

func hx_placeStone r, c
    if r < 1 or r > BOARD_SZ or c < 1 or c > BOARD_SZ return ok
    if board[r][c] != HEX_EMPTY
        hx_showMsg("Cell occupied!")
        return
    ok
    if len(dropAnims) > 0 return ok

    board[r][c] = currentPlayer
    moveCount += 1

    // Undo
    add(undoStack, [r, c, currentPlayer])
    if len(undoStack) > 300
        del(undoStack, 1)
    ok

    // Drop animation
    add(dropAnims, [r, c, currentPlayer, 0.0])

    // Particles
    wx = hx_cellToX(r, c)
    wz = hx_cellToZ(r, c)
    hx_spawnPlaceParticles(wx, wz, currentPlayer)

    // Check win
    if hx_checkWin(currentPlayer)
        winner = currentPlayer
        gameState = ST_WON
        hx_spawnWinParticles()
        if currentPlayer = HEX_RED
            hx_showMsg("RED WINS!")
        else
            hx_showMsg("BLUE WINS!")
        ok
        return
    ok

    // Switch player
    if currentPlayer = HEX_RED
        currentPlayer = HEX_BLUE
    else
        currentPlayer = HEX_RED
    ok

// =============================================================
// Win Detection (BFS from one edge to opposite)
// =============================================================

func hx_checkWin player
    // Red: connect top (row=1) to bottom (row=BOARD_SZ)
    // Blue: connect left (col=1) to right (col=BOARD_SZ)

    visited = list(BOARD_SZ)
    parent = list(BOARD_SZ)
    for r = 1 to BOARD_SZ
        visited[r] = list(BOARD_SZ)
        parent[r] = list(BOARD_SZ)
        for c = 1 to BOARD_SZ
            visited[r][c] = false
            parent[r][c] = 0
        next
    next

    queue = []

    // Seed from starting edge
    if player = HEX_RED
        // Start from top row
        for c = 1 to BOARD_SZ
            if board[1][c] = player
                add(queue, [1, c])
                visited[1][c] = true
                parent[1][c] = -1
            ok
        next
    else
        // Start from left column
        for r = 1 to BOARD_SZ
            if board[r][1] = player
                add(queue, [r, 1])
                visited[r][1] = true
                parent[r][1] = -1
            ok
        next
    ok

    head = 1
    while head <= len(queue)
        cr = queue[head][1]
        cc = queue[head][2]
        head += 1

        // Check if reached opposite edge
        if player = HEX_RED and cr = BOARD_SZ
            // Build win path
            hx_buildWinPath(cr, cc, parent, visited)
            return true
        ok
        if player = HEX_BLUE and cc = BOARD_SZ
            hx_buildWinPath(cr, cc, parent, visited)
            return true
        ok

        // Explore neighbors
        nbrs = hx_getNeighbors(cr, cc)
        for i = 1 to len(nbrs)
            nr = nbrs[i][1]
            nc = nbrs[i][2]
            if visited[nr][nc] = false and board[nr][nc] = player
                visited[nr][nc] = true
                parent[nr][nc] = (cr - 1) * BOARD_SZ + cc
                add(queue, [nr, nc])
            ok
        next
    end

    return false

func hx_buildWinPath cr, cc, parent, visited
    winPath = []
    r = cr
    c = cc
    safetyCount = 0
    while r >= 1 and c >= 1 and safetyCount < BOARD_SZ * BOARD_SZ + 5
        safetyCount += 1
        add(winPath, [r, c])
        pval = parent[r][c]
        if pval = -1
            // Start node
            r = -1
        else
            pr = floor((pval - 1) / BOARD_SZ) + 1
            pc = ((pval - 1) % BOARD_SZ) + 1
            r = pr
            c = pc
        ok
    end

// =============================================================
// Undo
// =============================================================

func hx_undo
    if len(undoStack) = 0
        hx_showMsg("Nothing to undo!")
        return
    ok
    if gameState = ST_WON
        // Allow undo from win
        gameState = ST_PLAYING
        winner = 0
        winPath = []
    ok

    last = undoStack[len(undoStack)]
    del(undoStack, len(undoStack))

    board[last[1]][last[2]] = HEX_EMPTY
    currentPlayer = last[3]
    moveCount -= 1
    if moveCount < 0 moveCount = 0 ok
    hx_showMsg("Move undone")

// =============================================================
// AI Opponent (Blue)
// =============================================================

func hx_aiMove
    // Strategy: BFS-based evaluation
    // For each empty cell, simulate placing Blue
    // Score = own connectivity improvement - opponent threat
    bestScore = -99999
    bestR = 0
    bestC = 0

    // First move: center
    if moveCount <= 1
        mid = floor(BOARD_SZ / 2) + 1
        if board[mid][mid] = HEX_EMPTY
            hx_placeStone(mid, mid)
            return
        ok
    ok

    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if board[r][c] != HEX_EMPTY loop ok

            sc = 0

            // Evaluate Blue connectivity
            board[r][c] = HEX_BLUE
            blueDist = hx_shortestPath(HEX_BLUE)
            board[r][c] = HEX_EMPTY

            // Evaluate blocking Red
            board[r][c] = HEX_RED
            redDist = hx_shortestPath(HEX_RED)
            board[r][c] = HEX_EMPTY

            // Score: improve own path + block opponent
            if blueDist > 0
                sc += (BOARD_SZ * 3.0) / blueDist
            else
                sc += BOARD_SZ * 10.0
            ok

            if redDist > 0
                sc += (BOARD_SZ * 2.5) / redDist
            else
                sc += BOARD_SZ * 8.0
            ok

            // Adjacency bonus: prefer cells near existing stones
            nbrs = hx_getNeighbors(r, c)
            for ni = 1 to len(nbrs)
                nr = nbrs[ni][1]
                nc = nbrs[ni][2]
                if board[nr][nc] = HEX_BLUE sc += 1.5 ok
                if board[nr][nc] = HEX_RED sc += 0.8 ok
            next

            // Center bonus
            centerDist = (r - (BOARD_SZ+1)/2.0) * (r - (BOARD_SZ+1)/2.0)
            centerDist += (c - (BOARD_SZ+1)/2.0) * (c - (BOARD_SZ+1)/2.0)
            sc += (BOARD_SZ - centerDist * 0.1) * 0.2

            // Small randomness
            sc += GetRandomValue(0, 100) / 200.0

            if sc > bestScore
                bestScore = sc
                bestR = r
                bestC = c
            ok
        next
    next

    if bestR > 0
        hx_placeStone(bestR, bestC)
    ok

// =============================================================
// Shortest Path (BFS with empty cells as cost 1)
// =============================================================

func hx_shortestPath player
    // BFS from start edge through own stones + empty cells
    // Returns shortest path length (0 = already connected, -1 = impossible)
    dist = list(BOARD_SZ)
    for r = 1 to BOARD_SZ
        dist[r] = list(BOARD_SZ)
        for c = 1 to BOARD_SZ
            dist[r][c] = 99999
        next
    next

    queue = []

    if player = HEX_RED
        for c = 1 to BOARD_SZ
            if board[1][c] = player or board[1][c] = HEX_EMPTY
                d = 0
                if board[1][c] = HEX_EMPTY d = 1 ok
                dist[1][c] = d
                add(queue, [1, c, d])
            ok
        next
    else
        for r = 1 to BOARD_SZ
            if board[r][1] = player or board[r][1] = HEX_EMPTY
                d = 0
                if board[r][1] = HEX_EMPTY d = 1 ok
                dist[r][1] = d
                add(queue, [r, 1, d])
            ok
        next
    ok

    head = 1
    bestDist = 99999
    while head <= len(queue)
        cr = queue[head][1]
        cc = queue[head][2]
        cd = queue[head][3]
        head += 1

        // Check goal edge
        if player = HEX_RED and cr = BOARD_SZ
            if cd < bestDist bestDist = cd ok
        ok
        if player = HEX_BLUE and cc = BOARD_SZ
            if cd < bestDist bestDist = cd ok
        ok

        nbrs = hx_getNeighbors(cr, cc)
        for i = 1 to len(nbrs)
            nr = nbrs[i][1]
            nc = nbrs[i][2]
            // Can't pass through opponent stones
            opponent = HEX_RED
            if player = HEX_RED opponent = HEX_BLUE ok
            if board[nr][nc] = opponent loop ok
            nd = cd
            if board[nr][nc] = HEX_EMPTY nd = cd + 1 ok
            if nd < dist[nr][nc]
                dist[nr][nc] = nd
                add(queue, [nr, nc, nd])
            ok
        next
    end

    if bestDist >= 99999 return -1 ok
    return bestDist

// =============================================================
// Drop Animation
// =============================================================

func hx_updateDropAnims dt
    i = 1
    while i <= len(dropAnims)
        dropAnims[i][4] += dt * 6.0
        if dropAnims[i][4] >= 1.0
            del(dropAnims, i)
        else
            i += 1
        ok
    end

// =============================================================
// Particles
// =============================================================

func hx_spawnPlaceParticles wx, wz, player
    for i = 1 to 10
        vx = (GetRandomValue(-150, 150) / 100.0)
        vy = (GetRandomValue(200, 500) / 100.0)
        vz = (GetRandomValue(-150, 150) / 100.0)
        if player = HEX_RED
            cr = GetRandomValue(200, 255)
            cg = GetRandomValue(40, 100)
            cb = GetRandomValue(30, 80)
        else
            cr = GetRandomValue(30, 100)
            cg = GetRandomValue(80, 160)
            cb = GetRandomValue(200, 255)
        ok
        add(particles, [wx, 0.6, wz, vx, vy, vz, 1.0, cr, cg, cb])
    next

func hx_spawnWinParticles
    for i = 1 to 80
        wx = (GetRandomValue(-800, 800) / 100.0)
        wz = (GetRandomValue(-800, 800) / 100.0)
        vx = (GetRandomValue(-200, 200) / 100.0)
        vy = (GetRandomValue(400, 900) / 100.0)
        vz = (GetRandomValue(-200, 200) / 100.0)
        if winner = HEX_RED
            cr = GetRandomValue(180, 255)
            cg = GetRandomValue(50, 120)
            cb = GetRandomValue(30, 80)
        else
            cr = GetRandomValue(30, 100)
            cg = GetRandomValue(100, 200)
            cb = GetRandomValue(180, 255)
        ok
        add(particles, [wx, 0.5, wz, vx, vy, vz, 2.5, cr, cg, cb])
    next

func hx_updateParticles dt
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

func hx_drawParticles3D
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

func hx_showMsg text
    msgText = text
    msgTimer = 2.0

// =============================================================
// 3D-to-Screen Projection
// =============================================================

func hx_projectToScreen wx, wy, wz
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
    fovRad = 45.0 * PI / 180.0
    tanHalf = tan(fovRad / 2.0)
    aspect = SCREEN_W * 1.0 / SCREEN_H
    ndcX = (dotRight / dotFwd) / (tanHalf * aspect)
    ndcY = (dotUp / dotFwd) / tanHalf
    projScreenX = (ndcX * 0.5 + 0.5) * SCREEN_W
    projScreenY = (1.0 - (ndcY * 0.5 + 0.5)) * SCREEN_H

// =============================================================
// Camera
// =============================================================

func hx_positionCamera
    // Diamond board spans ~3x wider than a square grid
    boardSpanX = BOARD_SZ * CELL_SZ * 0.866 * 3.0
    boardSpanZ = BOARD_SZ * CELL_SZ * 1.5
    maxDim = boardSpanX
    if boardSpanZ > maxDim maxDim = boardSpanZ ok

    goalX = 0  goalY = 0  goalZ = 0
    tgtX = 0   tgtY = 0   tgtZ = 0

    if cameraMode = CAM_FRONT
        goalX = 0
        goalY = maxDim * 0.8 + 5.0
        goalZ = maxDim * 0.75 + 5.0
        tgtX = 0
        tgtY = 0.0
        tgtZ = -1.0
    ok
    if cameraMode = CAM_ISOMETRIC
        goalX = maxDim * 0.55 + 3.0
        goalY = maxDim * 0.75 + 4.0
        goalZ = maxDim * 0.55 + 3.0
        tgtX = 0
        tgtY = 0.0
        tgtZ = 0
    ok
    if cameraMode = CAM_OVERHEAD
        goalX = 0
        goalY = maxDim * 1.1 + 7.0
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
// 3D Drawing: Board (Hex Grid)
// =============================================================

func hx_drawBoard3D
    // Table surface
    DrawPlane(Vector3(0, -0.01, 0), Vector2(50, 50),
              RAYLIBColor(8, 8, 14, 255))

    // Draw hex cells
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            wx = hx_cellToX(r, c)
            wz = hx_cellToZ(r, c)

            // Determine edge coloring
            isRedEdge = false
            isBlueEdge = false
            if r = 1 or r = BOARD_SZ isRedEdge = true ok
            if c = 1 or c = BOARD_SZ isBlueEdge = true ok

            // Cell base color
            if isRedEdge and isBlueEdge
                baseCol = RAYLIBColor(60, 30, 60, 255)
                wireCol = RAYLIBColor(100, 60, 100, 180)
            but isRedEdge
                baseCol = RAYLIBColor(55, 25, 25, 255)
                wireCol = RAYLIBColor(120, 50, 50, 180)
            but isBlueEdge
                baseCol = RAYLIBColor(25, 25, 55, 255)
                wireCol = RAYLIBColor(50, 50, 120, 180)
            else
                baseCol = RAYLIBColor(35, 35, 45, 255)
                wireCol = RAYLIBColor(55, 55, 70, 160)
            ok

            // Win path glow
            isWinCell = false
            if winner > 0
                for wi = 1 to len(winPath)
                    if winPath[wi][1] = r and winPath[wi][2] = c
                        isWinCell = true
                    ok
                next
            ok

            // Draw hexagonal prism
            hx_drawHexCell(wx, wz, CELL_SZ * 0.92, 0.25, baseCol, wireCol)

            if isWinCell
                pulse = 0.5 + sin(animTime * 4.0 + r * 0.5 + c * 0.3) * 0.5
                wAlpha = floor(80 * pulse)
                if winner = HEX_RED
                    hx_drawHexCell(wx, wz, CELL_SZ * 0.95, 0.27,
                                   RAYLIBColor(255, 80, 40, wAlpha),
                                   RAYLIBColor(255, 100, 60, floor(wAlpha * 0.5)))
                else
                    hx_drawHexCell(wx, wz, CELL_SZ * 0.95, 0.27,
                                   RAYLIBColor(40, 80, 255, wAlpha),
                                   RAYLIBColor(60, 100, 255, floor(wAlpha * 0.5)))
                ok
            ok
        next
    next

    // Edge labels using colored border bars
    // Red edges (top and bottom rows)
    for c = 1 to BOARD_SZ
        // Top edge
        wx = hx_cellToX(1, c)
        wz = hx_cellToZ(1, c) - CELL_SZ * 0.9
        DrawCube(Vector3(wx, 0.15, wz), CELL_SZ * 0.6, 0.12, CELL_SZ * 0.2,
                 RAYLIBColor(220, 50, 40, 200))
        // Bottom edge
        wx = hx_cellToX(BOARD_SZ, c)
        wz = hx_cellToZ(BOARD_SZ, c) + CELL_SZ * 0.9
        DrawCube(Vector3(wx, 0.15, wz), CELL_SZ * 0.6, 0.12, CELL_SZ * 0.2,
                 RAYLIBColor(220, 50, 40, 200))
    next

    // Blue edges (left and right columns)
    for r = 1 to BOARD_SZ
        // Left edge
        wx = hx_cellToX(r, 1) - CELL_SZ * 0.95
        wz = hx_cellToZ(r, 1)
        DrawCube(Vector3(wx, 0.15, wz), CELL_SZ * 0.2, 0.12, CELL_SZ * 0.6,
                 RAYLIBColor(40, 60, 220, 200))
        // Right edge
        wx = hx_cellToX(r, BOARD_SZ) + CELL_SZ * 0.95
        wz = hx_cellToZ(r, BOARD_SZ)
        DrawCube(Vector3(wx, 0.15, wz), CELL_SZ * 0.2, 0.12, CELL_SZ * 0.6,
                 RAYLIBColor(40, 60, 220, 200))
    next

// =============================================================
// Draw Hexagonal Cell (6-sided prism approximation)
// =============================================================

func hx_drawHexCell wx, wz, radius, height, col, wireCol
    // Use a cylinder with 6 sides for hex shape
    DrawCylinder(Vector3(wx, 0, wz), radius, radius, height, 6, col)
    DrawCylinderWires(Vector3(wx, 0, wz), radius, radius, height, 6, wireCol)

// =============================================================
// 3D Drawing: Stones
// =============================================================

func hx_drawStones3D
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if board[r][c] = HEX_EMPTY loop ok

            // Skip if currently in drop animation
            isDropping = false
            for di = 1 to len(dropAnims)
                if dropAnims[di][1] = r and dropAnims[di][2] = c
                    isDropping = true
                ok
            next
            if isDropping loop ok

            wx = hx_cellToX(r, c)
            wz = hx_cellToZ(r, c)
            stoneY = 0.35

            hx_drawStone(wx, stoneY, wz, board[r][c], 1.0)
        next
    next

// =============================================================
// 3D Drawing: Drop Animations
// =============================================================

func hx_drawDropAnims3D
    for i = 1 to len(dropAnims)
        r = dropAnims[i][1]
        c = dropAnims[i][2]
        player = dropAnims[i][3]
        t = dropAnims[i][4]
        if t > 1.0 t = 1.0 ok

        smooth = t * t * (3.0 - 2.0 * t)

        wx = hx_cellToX(r, c)
        wz = hx_cellToZ(r, c)

        // Drop from height
        startY = 4.0
        endY = 0.35
        wy = startY + (endY - startY) * smooth

        // Scale bounce at landing
        scale = 1.0
        if t > 0.8
            bt = (t - 0.8) / 0.2
            scale = 1.0 + sin(bt * PI) * 0.15
        ok

        hx_drawStone(wx, wy, wz, player, scale)
    next

// =============================================================
// Draw Stone (sphere + shine)
// =============================================================

func hx_drawStone wx, wy, wz, player, scale
    stR = CELL_SZ * 0.35 * scale

    if player = HEX_RED
        col = RAYLIBColor(220, 50, 40, 255)
        wireCol = RAYLIBColor(160, 30, 25, 180)
        shineCol = RAYLIBColor(255, 150, 130, 100)
    else
        col = RAYLIBColor(40, 70, 220, 255)
        wireCol = RAYLIBColor(25, 45, 160, 180)
        shineCol = RAYLIBColor(130, 160, 255, 100)
    ok

    DrawSphere(Vector3(wx, wy, wz), stR, col)
    DrawSphereWires(Vector3(wx, wy, wz), stR, 8, 8, wireCol)

    // Highlight
    DrawSphere(Vector3(wx - stR * 0.25, wy + stR * 0.35, wz - stR * 0.2),
               stR * 0.22, shineCol)

    // Win path glow
    if winner > 0
        isOnPath = false
        for wi = 1 to len(winPath)
            if player = winner
                // Find which r,c this stone belongs to
                // Use world-coord matching
            ok
        next
    ok

// =============================================================
// 3D Drawing: Cursor
// =============================================================

func hx_drawCursor3D
    if gameState != ST_PLAYING return ok

    wx = hx_cellToX(cursorR, cursorC)
    wz = hx_cellToZ(cursorR, cursorC)

    ccR = 80   ccG = 120   ccB = 255
    if currentPlayer = HEX_RED
        ccR = 255   ccG = 120   ccB = 80
    ok

    // Ring cursor around hex
    pulse = 0.6 + sin(animTime * 4.0) * 0.4
    ringR = CELL_SZ * 0.9
    ringAlpha = floor(150 * pulse)
    DrawCylinderWires(Vector3(wx, 0.3, wz), ringR, ringR, 0.15, 6,
                      RAYLIBColor(ccR, ccG, ccB, ringAlpha))

    // Ghost stone preview
    if board[cursorR][cursorC] = HEX_EMPTY
        ghostAlpha = floor(60 * pulse)
        ghostR = CELL_SZ * 0.3
        DrawSphere(Vector3(wx, 0.4, wz), ghostR,
                   RAYLIBColor(ccR, ccG, ccB, ghostAlpha))
    ok

// =============================================================
// HUD
// =============================================================

func hx_drawHUD
    panelW = 250
    panelH = 150
    DrawRectangle(10, 30, panelW, panelH, Fade(BLACK, 0.75))
    DrawRectangleLines(10, 30, panelW, panelH, RAYLIBColor(140, 100, 180, 200))

    DrawText("HEX", 20, 38, 24, RAYLIBColor(200, 150, 255, 255))

    DrawText("Board: " + BOARD_SZ + "x" + BOARD_SZ, 20, 68, 14,
             RAYLIBColor(160, 180, 200, 200))

    // Current turn
    if currentPlayer = HEX_RED
        turnStr = "Turn: RED"
        turnCol = RAYLIBColor(255, 100, 80, 255)
    else
        turnStr = "Turn: BLUE"
        turnCol = RAYLIBColor(80, 120, 255, 255)
    ok
    DrawText(turnStr, 20, 86, 18, turnCol)
    // Turn indicator dot
    DrawCircle(160, 95, 6, turnCol)

    DrawText("Moves: " + moveCount, 20, 110, 14,
             RAYLIBColor(200, 200, 220, 220))

    // Mode
    modeStr = "PvP"
    if gameMode = MODE_PVA modeStr = "vs AI" ok
    DrawText("Mode: " + modeStr + "  [M]", 20, 128, 13,
             RAYLIBColor(140, 160, 180, 200))

    // Directions
    DrawText("Red: Top to Bottom", 20, 146, 12,
             RAYLIBColor(255, 100, 80, 200))
    DrawText("Blue: Left to Right", 20, 161, 12,
             RAYLIBColor(80, 120, 255, 200))

    // Camera
    camName = "FRONT"
    if cameraMode = CAM_ISOMETRIC camName = "ISOMETRIC" ok
    if cameraMode = CAM_OVERHEAD  camName = "OVERHEAD"  ok
    DrawRectangle(10, SCREEN_H - 60, 220, 25, Fade(BLACK, 0.6))
    DrawText("Cam: " + camName + "  [C] switch", 16, SCREEN_H - 56, 14,
             RAYLIBColor(150, 180, 210, 220))

    // Controls
    DrawRectangle(SCREEN_W - 480, SCREEN_H - 35, 470, 25, Fade(BLACK, 0.6))
    DrawText("Click/Enter: Place | U: Undo | M: Mode | N: New | R: Title",
             SCREEN_W - 476, SCREEN_H - 30, 12, RAYLIBColor(150, 160, 180, 200))

// =============================================================
// Mini Map
// =============================================================

func hx_drawMiniMap
    cellW = 10
    if BOARD_SZ >= 9 cellW = 8 ok
    if BOARD_SZ >= 11 cellW = 7 ok
    if BOARD_SZ >= 13 cellW = 6 ok

    mapW = (BOARD_SZ * 2 + BOARD_SZ) * cellW / 2 + 20
    mapH = BOARD_SZ * cellW + 20
    mapX = SCREEN_W - mapW - 10
    mapY = 30

    DrawRectangle(mapX - 3, mapY - 3, mapW + 6, mapH + 6, Fade(BLACK, 0.8))
    DrawRectangleLines(mapX - 3, mapY - 3, mapW + 6, mapH + 6,
                       RAYLIBColor(140, 100, 180, 200))

    DrawRectangle(mapX, mapY, mapW, mapH, RAYLIBColor(20, 18, 28, 230))

    // Draw hex cells as small circles in diamond layout
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            cx = mapX + 10 + (c - 1) * cellW + (r - 1) * cellW / 2
            cy = mapY + 10 + (r - 1) * cellW

            // Background
            isRedEdge = false
            isBlueEdge = false
            if r = 1 or r = BOARD_SZ isRedEdge = true ok
            if c = 1 or c = BOARD_SZ isBlueEdge = true ok

            if isRedEdge and isBlueEdge
                bgCol = RAYLIBColor(80, 40, 80, 200)
            but isRedEdge
                bgCol = RAYLIBColor(80, 30, 30, 200)
            but isBlueEdge
                bgCol = RAYLIBColor(30, 30, 80, 200)
            else
                bgCol = RAYLIBColor(45, 45, 55, 200)
            ok
            DrawCircle(cx, cy, cellW/2 - 1, bgCol)

            // Stone
            if board[r][c] = HEX_RED
                DrawCircle(cx, cy, cellW/2 - 2, RAYLIBColor(220, 50, 40, 255))
            ok
            if board[r][c] = HEX_BLUE
                DrawCircle(cx, cy, cellW/2 - 2, RAYLIBColor(40, 70, 220, 255))
            ok

            // Win path
            if winner > 0
                for wi = 1 to len(winPath)
                    if winPath[wi][1] = r and winPath[wi][2] = c
                        pulse = 0.5 + sin(animTime * 5.0) * 0.5
                        DrawCircleLines(cx, cy, cellW/2,
                                        RAYLIBColor(255, 255, 255, floor(200 * pulse)))
                    ok
                next
            ok
        next
    next

    // Cursor
    ccx = mapX + 10 + (cursorC - 1) * cellW + (cursorR - 1) * cellW / 2
    ccy = mapY + 10 + (cursorR - 1) * cellW
    DrawCircleLines(ccx, ccy, cellW/2 + 1,
                    RAYLIBColor(255, 255, 255, 220))

    DrawText("MAP", mapX + mapW/2 - 15, mapY - 16, 12,
             RAYLIBColor(140, 100, 180, 200))

// =============================================================
// Title Screen
// =============================================================

func hx_drawTitleScreen
    DrawRectangleGradientV(0, 0, SCREEN_W, SCREEN_H,
        RAYLIBColor(12, 10, 20, 255), RAYLIBColor(20, 16, 30, 255))

    t1 = "HEX"
    t1w = MeasureText(t1, 72)
    DrawText(t1, (SCREEN_W - t1w)/2, 25, 72, RAYLIBColor(200, 150, 255, 255))

    t1b = "3D CONNECTION GAME"
    t1bw = MeasureText(t1b, 20)
    DrawText(t1b, (SCREEN_W - t1bw)/2, 105, 20, RAYLIBColor(220, 180, 255, 230))

    t2 = "~ Connect Opposite Sides of the Board ~"
    t2w = MeasureText(t2, 16)
    DrawText(t2, (SCREEN_W - t2w)/2, 135, 16, RAYLIBColor(180, 160, 210, 230))

    ly = 160
    DrawLine(180, ly, SCREEN_W - 180, ly, RAYLIBColor(140, 100, 180, 180))

    // Demo hex grid
    dSz = 7
    dCellW = 14
    dStartX = (SCREEN_W - dSz * dCellW * 2) / 2
    dStartY = 175
    for dr = 1 to dSz
        for dc = 1 to dSz
            dx2 = dStartX + (dc - 1) * dCellW + (dr - 1) * dCellW / 2
            dy2 = dStartY + (dr - 1) * (dCellW - 2)

            isRE = false
            isBE = false
            if dr = 1 or dr = dSz isRE = true ok
            if dc = 1 or dc = dSz isBE = true ok

            if isRE and isBE
                col = RAYLIBColor(100, 50, 100, 200)
            but isRE
                col = RAYLIBColor(120, 40, 40, 200)
            but isBE
                col = RAYLIBColor(40, 40, 120, 200)
            else
                col = RAYLIBColor(55, 55, 65, 200)
            ok
            DrawCircle(dx2, dy2, dCellW / 2 - 1, col)

            // Some demo stones
            dHash = (dr * 7 + dc * 13) % 11
            if dHash < 2
                DrawCircle(dx2, dy2, dCellW / 2 - 3,
                           RAYLIBColor(220, 50, 40, 220))
            ok
            if dHash > 8
                DrawCircle(dx2, dy2, dCellW / 2 - 3,
                           RAYLIBColor(40, 70, 220, 220))
            ok
        next
    next

    cy = 285
    cLines = [
        "Click / ENTER / SPACE  -   Place stone on empty hex",
        "Arrow Keys / WASD      -   Move cursor on the board",
        "U / Backspace          -   Undo last move",
        "M                      -   Toggle mode: PvP / vs AI",
        "N                      -   New game (same board size)",
        "R                      -   Return to title screen",
        "C                      -   Cycle camera view",
        "",
        "Sizes: 1=5x5  2=7x7  3=9x9  4=11x11  5=13x13",
        "",
        "Players:",
        "  RED  (first) - Connect TOP edge to BOTTOM edge",
        "  BLUE (second) - Connect LEFT edge to RIGHT edge",
        "",
        "Rules:",
        "  Place one stone per turn on any empty hex cell.",
        "  Build a connected chain of your color from one side",
        "  to the other. No draws possible in Hex!",
        "  Edges are color-coded: red bars = top/bottom,",
        "  blue bars = left/right."
    ]
    for i = 1 to len(cLines)
        lw = MeasureText(cLines[i], 13)
        if i >= 9
            col = RAYLIBColor(200, 170, 255, 210)
        else
            col = RAYLIBColor(170, 165, 200, 230)
        ok
        DrawText(cLines[i], (SCREEN_W - lw)/2, cy + (i - 1) * 19, 13, col)
    next

    sizeStr = "Current: " + BOARD_SZ + "x" + BOARD_SZ
    ssw = MeasureText(sizeStr, 18)
    DrawText(sizeStr, (SCREEN_W - ssw)/2, 672, 18,
             RAYLIBColor(200, 150, 255, 230))

    if floor(animTime * 2) % 2 = 0
        st2 = "Click or Press ENTER / SPACE to Start"
        st2w = MeasureText(st2, 22)
        DrawText(st2, (SCREEN_W - st2w)/2, 700, 22, WHITE)
    ok

    cr = "Developed using Ring Language + RingRayLib"
    crw = MeasureText(cr, 14)
    DrawText(cr, (SCREEN_W - crw)/2, SCREEN_H - 25, 14,
             RAYLIBColor(80, 100, 80, 180))

// =============================================================
// Won Overlay
// =============================================================

func hx_drawWonOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.5))

    g1R = 80   g1G = 140   g1B = 255
    if winner = HEX_RED
        g1 = "RED WINS!"
        g1R = 255   g1G = 120   g1B = 80
    else
        g1 = "BLUE WINS!"
    ok
    g1w = MeasureText(g1, 52)
    pulse = floor(220 + sin(animTime * 3.0) * 35)
    DrawText(g1, (SCREEN_W - g1w)/2, 170, 52,
             RAYLIBColor(g1R, g1G, g1B, pulse))

    if winner = HEX_RED
        g2 = "Connected Top to Bottom!"
    else
        g2 = "Connected Left to Right!"
    ok
    g2w = MeasureText(g2, 20)
    DrawText(g2, (SCREEN_W - g2w)/2, 240, 20, RAYLIBColor(200, 220, 255, 220))

    g3 = "Moves: " + moveCount
    g3w = MeasureText(g3, 22)
    DrawText(g3, (SCREEN_W - g3w)/2, 280, 22, RAYLIBColor(255, 255, 255, 240))

    if floor(animTime * 2) % 2 = 0
        rt = "Press N for new game  |  R for title screen"
        rtw = MeasureText(rt, 16)
        DrawText(rt, (SCREEN_W - rtw)/2, 330, 16, WHITE)
    ok

    ss = "Change size: 1=5x5  2=7x7  3=9x9  4=11x11  5=13x13"
    ssw = MeasureText(ss, 14)
    DrawText(ss, (SCREEN_W - ssw)/2, 365, 14, RAYLIBColor(180, 200, 220, 200))

// =============================================================
// Message Overlay
// =============================================================

func hx_drawMessage
    alpha = floor((msgTimer / 2.0) * 255)
    if alpha > 255 alpha = 255 ok
    if alpha < 0 alpha = 0 ok

    mw = MeasureText(msgText, 24)
    mx = (SCREEN_W - mw) / 2
    my = SCREEN_H / 2 + 150

    DrawRectangle(mx - 15, my - 8, mw + 30, 40,
                  RAYLIBColor(0, 0, 0, floor(alpha * 0.7)))
    DrawText(msgText, mx, my, 24,
             RAYLIBColor(200, 150, 255, alpha))
