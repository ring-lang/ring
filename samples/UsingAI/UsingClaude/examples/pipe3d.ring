/*
**  3D Pipe Connect - Using RingRayLib
**  =====================================
**  Rotate pipe segments to connect water flow from the
**  source to the drain! Build a continuous path of pipes.
**
**  Controls:
**    Arrow Keys / WASD  - Move cursor on the board
**    Mouse              - Hover over pipes
**    ENTER / SPACE /    - Rotate pipe clockwise
**      Left Click
**    Right Click / X    - Rotate pipe counter-clockwise
**    U / Backspace      - Undo last rotation
**    H                  - Toggle flow hint overlay
**    N                  - New puzzle (same board size)
**    R                  - Restart to title
**    C                  - Cycle camera views
**    1 / 2 / 3 / 4      - Board size: 5x5 / 6x6 / 7x7 / 8x8
**    ESC                - Exit
**
**  Pipe Types:
**    Straight  - Connects two opposite sides
**    Bend      - Connects two adjacent sides (L-shape)
**    T-piece   - Connects three sides
**    Cross     - Connects all four sides
**    Source    - Water origin (fixed, cannot rotate)
**    Drain     - Water destination (fixed, cannot rotate)
**
**  Rules:
**    - Rotate pipes to create a continuous path from Source to Drain
**    - Water flows through connected pipe openings
**    - All pipe openings must align with their neighbors
**    - Solve the puzzle when water reaches the drain!
**
**  Features:
**    - Board sizes from 5x5 to 8x8
**    - 3D pipe rendering with cylinders and connectors
**    - Smooth rotation animation
**    - Real-time flow simulation (BFS from source)
**    - Flowing water particles through connected pipes
**    - Color coding: blue = has water, gray = dry
**    - Source and drain with special 3D models
**    - Undo system for rotations
**    - Three camera modes
**    - Mini-map with pipe connections
**    - Timer and move counter
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W        = 1024
SCREEN_H        = 768
CELL_SZ         = 2.4

// Pipe types
PIPE_NONE       = 0
PIPE_STRAIGHT   = 1     // connects N-S or E-W depending on rotation
PIPE_BEND       = 2     // connects two adjacent dirs (L shape)
PIPE_TEE        = 3     // connects three dirs (T shape)
PIPE_CROSS      = 4     // connects all four dirs
PIPE_SOURCE     = 5     // water origin
PIPE_DRAIN      = 6     // water destination

// Directions: bitmask  N=1, E=2, S=4, W=8
DIR_N           = 1
DIR_E           = 2
DIR_S           = 4
DIR_W           = 8

// Game states
ST_START        = 1
ST_PLAYING      = 2
ST_SOLVED       = 3

// Camera modes
CAM_FRONT       = 1
CAM_ISOMETRIC   = 2
CAM_OVERHEAD    = 3
CAM_COUNT       = 3

// =============================================================
// Global Variables
// =============================================================

BOARD_SZ        = 6
board           = []        // board[r][c] = pipe type
rotation        = []        // rotation[r][c] = 0..3 (number of 90-deg CW rotations)
flowMap         = []        // flowMap[r][c] = true/false (has water)
locked          = []        // locked[r][c] = true/false (source/drain, can't rotate)

cursorR         = 1
cursorC         = 1
moveCount       = 0
gameState       = ST_START
animTime        = 0.0

sourceR         = 0  sourceC = 0
drainR          = 0  drainC  = 0

// Undo stack: [[r, c, oldRotation], ...]
undoStack       = []

// Rotation animation: [[r, c, fromAngle, toAngle, progress], ...]
rotAnims        = []

// Flow particles: [x, y, z, vx, vy, vz, life, progress]
flowParticles   = []

// Celebration particles
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

// Show flow hints
showHints       = false

// Timer
gameTimer       = 0.0

// Message
msgText         = ""
msgTimer        = 0.0

// =============================================================
// Initialize
// =============================================================

pc_initBoard()

// =============================================================
// Main Program
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Ring 3D Pipe Connect - RingRayLib")
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

    // Board size
    if gameState = ST_START or gameState = ST_SOLVED
        pc_checkSizeKeys()
    ok

    // Restart
    if IsKeyPressed(KEY_R)
        pc_initBoard()
        gameState = ST_START
    ok

    // ========== STATE UPDATES ==========

    if gameState = ST_START
        pc_checkSizeKeys()
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(0)
            pc_initBoard()
            pc_generatePuzzle()
            gameState = ST_PLAYING
        ok
    ok

    if gameState = ST_PLAYING
        pc_updateMouseHover()
        pc_handleInput()
        pc_handleMouse()
        pc_updateRotAnims(dt)
        pc_updateFlow()
        pc_updateFlowParticles(dt)
        pc_updateParticles(dt)
        gameTimer += dt

        // Check solved
        if flowMap[drainR][drainC] = true
            gameState = ST_SOLVED
            pc_spawnWinParticles()
            pc_showMsg("CONNECTED! Water flows!")
        ok
    ok

    if gameState = ST_SOLVED
        pc_updateFlowParticles(dt)
        pc_updateParticles(dt)
        pc_checkSizeKeys()
        if IsKeyPressed(KEY_N)
            pc_initBoard()
            pc_generatePuzzle()
            gameState = ST_PLAYING
        ok
    ok

    pc_positionCamera()

    // ========== DRAWING ==========

    BeginDrawing()
        ClearBackground(RAYLIBColor(12, 14, 22, 255))

        if gameState = ST_START
            pc_drawTitleScreen()
        else
            BeginMode3D(camera)
                pc_drawBoard3D()
                pc_drawPipes3D()
                pc_drawFlowParticles3D()
                pc_drawCursor3D()
                pc_drawParticles3D()
            EndMode3D()

            pc_drawHUD()
            pc_drawMiniMap()

            if gameState = ST_SOLVED
                pc_drawSolvedOverlay()
            ok
            if msgTimer > 0
                pc_drawMessage()
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

func pc_initBoard
    board = list(BOARD_SZ)
    rotation = list(BOARD_SZ)
    flowMap = list(BOARD_SZ)
    locked = list(BOARD_SZ)
    for r = 1 to BOARD_SZ
        board[r] = list(BOARD_SZ)
        rotation[r] = list(BOARD_SZ)
        flowMap[r] = list(BOARD_SZ)
        locked[r] = list(BOARD_SZ)
        for c = 1 to BOARD_SZ
            board[r][c] = PIPE_NONE
            rotation[r][c] = 0
            flowMap[r][c] = false
            locked[r][c] = false
        next
    next

    moveCount = 0
    undoStack = []
    rotAnims = []
    flowParticles = []
    particles = []
    gameTimer = 0.0
    msgTimer = 0
    showHints = false
    cursorR = 1
    cursorC = 1

    CELL_SZ = 14.0 / BOARD_SZ
    if CELL_SZ < 1.6 CELL_SZ = 1.6 ok
    if CELL_SZ > 3.0 CELL_SZ = 3.0 ok

// =============================================================
// Puzzle Generation
// =============================================================

func pc_generatePuzzle
    // 1. Place source on left edge, drain on right edge
    sourceR = GetRandomValue(2, BOARD_SZ - 1)
    sourceC = 1
    drainR = GetRandomValue(2, BOARD_SZ - 1)
    drainC = BOARD_SZ

    // 2. Generate a random path from source to drain using random walk
    path = []
    visited = list(BOARD_SZ)
    for r = 1 to BOARD_SZ
        visited[r] = list(BOARD_SZ)
        for c = 1 to BOARD_SZ
            visited[r][c] = false
        next
    next

    // Random walk from source toward drain
    cr = sourceR
    cc = sourceC
    add(path, [cr, cc])
    visited[cr][cc] = true

    maxSteps = BOARD_SZ * BOARD_SZ * 3
    stepCount = 0
    while (cr != drainR or cc != drainC) and stepCount < maxSteps
        stepCount += 1

        // Possible directions: bias toward drain
        dirs = []
        // Up
        if cr > 1 and visited[cr-1][cc] = false add(dirs, [cr-1, cc]) ok
        // Down
        if cr < BOARD_SZ and visited[cr+1][cc] = false add(dirs, [cr+1, cc]) ok
        // Left
        if cc > 1 and visited[cr][cc-1] = false add(dirs, [cr, cc-1]) ok
        // Right
        if cc < BOARD_SZ and visited[cr][cc+1] = false add(dirs, [cr, cc+1]) ok

        if len(dirs) = 0
            // Backtrack
            if len(path) > 1
                del(path, len(path))
                cr = path[len(path)][1]
                cc = path[len(path)][2]
            ok
            loop
        ok

        // Bias toward drain: prefer directions that get closer
        bestIdx = GetRandomValue(1, len(dirs))
        bestDist = 9999
        for di = 1 to len(dirs)
            dr = dirs[di][1]
            dc = dirs[di][2]
            dist = (dr - drainR) * (dr - drainR) + (dc - drainC) * (dc - drainC)
            // Random bias factor
            dist = dist + GetRandomValue(0, BOARD_SZ)
            if dist < bestDist
                bestDist = dist
                bestIdx = di
            ok
        next

        cr = dirs[bestIdx][1]
        cc = dirs[bestIdx][2]
        add(path, [cr, cc])
        visited[cr][cc] = true
    end

    // 3. Place pipes along the path
    for i = 1 to len(path)
        pr = path[i][1]
        pcc = path[i][2]

        // Determine connections needed
        conns = 0
        if i > 1
            prevR = path[i-1][1]
            prevC = path[i-1][2]
            if prevR < pr conns = conns | DIR_N ok
            if prevR > pr conns = conns | DIR_S ok
            if prevC < pcc conns = conns | DIR_W ok
            if prevC > pcc conns = conns | DIR_E ok
        ok
        if i < len(path)
            nextR = path[i+1][1]
            nextC = path[i+1][2]
            if nextR < pr conns = conns | DIR_N ok
            if nextR > pr conns = conns | DIR_S ok
            if nextC < pcc conns = conns | DIR_W ok
            if nextC > pcc conns = conns | DIR_E ok
        ok

        if i = 1
            // Source
            board[pr][pcc] = PIPE_SOURCE
            locked[pr][pcc] = true
            // Source connects East (toward board)
            rotation[pr][pcc] = 0
        but i = len(path)
            // Drain
            board[pr][pcc] = PIPE_DRAIN
            locked[pr][pcc] = true
            rotation[pr][pcc] = 0
        else
            // Find pipe type and rotation that produces these connections
            pc_assignPipe(pr, pcc, conns)
        ok
    next

    // 4. Fill remaining cells with random pipes
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if board[r][c] = PIPE_NONE
                // Random pipe type (no source/drain)
                ptype = GetRandomValue(1, 4)
                board[r][c] = ptype
                rotation[r][c] = 0
            ok
        next
    next

    // 5. Save solution rotations, then randomize all non-locked
    solvedRot = list(BOARD_SZ)
    for r = 1 to BOARD_SZ
        solvedRot[r] = list(BOARD_SZ)
        for c = 1 to BOARD_SZ
            solvedRot[r][c] = rotation[r][c]
        next
    next

    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if locked[r][c] = false
                rndRot = GetRandomValue(1, 3)
                rotation[r][c] = (rotation[r][c] + rndRot) % 4
            ok
        next
    next

// =============================================================
// Assign Pipe Type from Connection Bitmask
// =============================================================

func pc_assignPipe r, c, conns
    // Count connections
    cnt = 0
    if (conns & DIR_N) = DIR_N cnt += 1 ok
    if (conns & DIR_E) = DIR_E cnt += 1 ok
    if (conns & DIR_S) = DIR_S cnt += 1 ok
    if (conns & DIR_W) = DIR_W cnt += 1 ok

    if cnt = 2
        // Check if opposite (straight) or adjacent (bend)
        if conns = (DIR_N | DIR_S)
            board[r][c] = PIPE_STRAIGHT
            rotation[r][c] = 0
        but conns = (DIR_E | DIR_W)
            board[r][c] = PIPE_STRAIGHT
            rotation[r][c] = 1
        but conns = (DIR_N | DIR_E)
            board[r][c] = PIPE_BEND
            rotation[r][c] = 0
        but conns = (DIR_E | DIR_S)
            board[r][c] = PIPE_BEND
            rotation[r][c] = 1
        but conns = (DIR_S | DIR_W)
            board[r][c] = PIPE_BEND
            rotation[r][c] = 2
        but conns = (DIR_N | DIR_W)
            board[r][c] = PIPE_BEND
            rotation[r][c] = 3
        ok
    but cnt = 3
        board[r][c] = PIPE_TEE
        if conns = (DIR_N | DIR_E | DIR_S)
            rotation[r][c] = 0
        but conns = (DIR_E | DIR_S | DIR_W)
            rotation[r][c] = 1
        but conns = (DIR_S | DIR_W | DIR_N)
            rotation[r][c] = 2
        but conns = (DIR_W | DIR_N | DIR_E)
            rotation[r][c] = 3
        ok
    but cnt = 4
        board[r][c] = PIPE_CROSS
        rotation[r][c] = 0
    but cnt = 1
        // Dead end - use a bend or straight
        board[r][c] = PIPE_STRAIGHT
        if (conns & DIR_N) = DIR_N rotation[r][c] = 0 ok
        if (conns & DIR_E) = DIR_E rotation[r][c] = 1 ok
        if (conns & DIR_S) = DIR_S rotation[r][c] = 0 ok
        if (conns & DIR_W) = DIR_W rotation[r][c] = 1 ok
    ok

// =============================================================
// Get Pipe Openings (bitmask based on type + rotation)
// =============================================================

func pc_getOpenings ptype, rot
    base = 0

    if ptype = PIPE_STRAIGHT
        base = DIR_N | DIR_S
    ok
    if ptype = PIPE_BEND
        base = DIR_N | DIR_E
    ok
    if ptype = PIPE_TEE
        base = DIR_N | DIR_E | DIR_S
    ok
    if ptype = PIPE_CROSS
        base = DIR_N | DIR_E | DIR_S | DIR_W
    ok
    if ptype = PIPE_SOURCE
        base = DIR_N | DIR_E | DIR_S | DIR_W
    ok
    if ptype = PIPE_DRAIN
        base = DIR_N | DIR_E | DIR_S | DIR_W
    ok

    // Rotate CW 'rot' times
    result = base
    for i = 1 to rot
        result = pc_rotateBitmask(result)
    next

    return result

func pc_rotateBitmask mask
    // Rotate 90 CW: N->E, E->S, S->W, W->N
    result = 0
    if (mask & DIR_N) = DIR_N result = result | DIR_E ok
    if (mask & DIR_E) = DIR_E result = result | DIR_S ok
    if (mask & DIR_S) = DIR_S result = result | DIR_W ok
    if (mask & DIR_W) = DIR_W result = result | DIR_N ok
    return result

// =============================================================
// Opposite Direction
// =============================================================

func pc_oppositeDir d
    if d = DIR_N return DIR_S ok
    if d = DIR_S return DIR_N ok
    if d = DIR_E return DIR_W ok
    if d = DIR_W return DIR_E ok
    return 0

// =============================================================
// Flow Simulation (BFS from source)
// =============================================================

func pc_updateFlow
    // Reset flow
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            flowMap[r][c] = false
        next
    next

    // BFS from source
    queue = []
    add(queue, [sourceR, sourceC])
    flowMap[sourceR][sourceC] = true

    head = 1
    while head <= len(queue)
        cr = queue[head][1]
        cc = queue[head][2]
        head += 1

        openings = pc_getOpenings(board[cr][cc], rotation[cr][cc])

        // Check each direction
        // North
        if (openings & DIR_N) = DIR_N
            nr = cr - 1   nc = cc
            if nr >= 1 and flowMap[nr][nc] = false
                nOpen = pc_getOpenings(board[nr][nc], rotation[nr][nc])
                if (nOpen & DIR_S) = DIR_S
                    flowMap[nr][nc] = true
                    add(queue, [nr, nc])
                ok
            ok
        ok
        // South
        if (openings & DIR_S) = DIR_S
            nr = cr + 1   nc = cc
            if nr <= BOARD_SZ and flowMap[nr][nc] = false
                nOpen = pc_getOpenings(board[nr][nc], rotation[nr][nc])
                if (nOpen & DIR_N) = DIR_N
                    flowMap[nr][nc] = true
                    add(queue, [nr, nc])
                ok
            ok
        ok
        // East
        if (openings & DIR_E) = DIR_E
            nr = cr   nc = cc + 1
            if nc <= BOARD_SZ and flowMap[nr][nc] = false
                nOpen = pc_getOpenings(board[nr][nc], rotation[nr][nc])
                if (nOpen & DIR_W) = DIR_W
                    flowMap[nr][nc] = true
                    add(queue, [nr, nc])
                ok
            ok
        ok
        // West
        if (openings & DIR_W) = DIR_W
            nr = cr   nc = cc - 1
            if nc >= 1 and flowMap[nr][nc] = false
                nOpen = pc_getOpenings(board[nr][nc], rotation[nr][nc])
                if (nOpen & DIR_E) = DIR_E
                    flowMap[nr][nc] = true
                    add(queue, [nr, nc])
                ok
            ok
        ok
    end

// =============================================================
// Size Keys
// =============================================================

func pc_checkSizeKeys
    if IsKeyPressed(KEY_ONE)
        BOARD_SZ = 5
        pc_initBoard()
    ok
    if IsKeyPressed(KEY_TWO)
        BOARD_SZ = 6
        pc_initBoard()
    ok
    if IsKeyPressed(KEY_THREE)
        BOARD_SZ = 7
        pc_initBoard()
    ok
    if IsKeyPressed(KEY_FOUR)
        BOARD_SZ = 8
        pc_initBoard()
    ok

// =============================================================
// Input Handling
// =============================================================

func pc_handleInput
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

    // Rotate CW
    if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
        pc_rotateTile(cursorR, cursorC, 1)
    ok

    // Rotate CCW
    if IsKeyPressed(KEY_X)
        pc_rotateTile(cursorR, cursorC, 3)
    ok

    // Undo
    if IsKeyPressed(KEY_U) or IsKeyPressed(KEY_BACKSPACE)
        pc_undo()
    ok

    // Toggle hints
    if IsKeyPressed(KEY_H)
        if showHints = true
            showHints = false
            pc_showMsg("Flow hints OFF")
        else
            showHints = true
            pc_showMsg("Flow hints ON")
        ok
    ok

    // New puzzle
    if IsKeyPressed(KEY_N)
        pc_initBoard()
        pc_generatePuzzle()
        gameState = ST_PLAYING
        pc_showMsg("New puzzle generated!")
    ok

// =============================================================
// Mouse Handling
// =============================================================

func pc_updateMouseHover
    mx = GetMouseX()
    my = GetMouseY()

    bestDist = 999999.0
    bestR = 0
    bestC = 0

    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            wx = pc_cellToX(c)
            wz = pc_cellToZ(r)
            pc_projectToScreen(wx, 0.3, wz)
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
    if BOARD_SZ >= 8 threshDist = 1000 ok

    if bestDist < threshDist and bestR >= 1 and bestR <= BOARD_SZ
        mouseHoverR = bestR
        mouseHoverC = bestC
        cursorR = bestR
        cursorC = bestC
    else
        mouseHoverR = 0
        mouseHoverC = 0
    ok

func pc_handleMouse
    if IsMouseButtonPressed(0)
        if mouseHoverR >= 1 and mouseHoverR <= BOARD_SZ
            pc_rotateTile(mouseHoverR, mouseHoverC, 1)
        ok
    ok
    if IsMouseButtonPressed(1)
        if mouseHoverR >= 1 and mouseHoverR <= BOARD_SZ
            pc_rotateTile(mouseHoverR, mouseHoverC, 3)
        ok
    ok

// =============================================================
// Rotate Tile
// =============================================================

func pc_rotateTile r, c, amount
    if locked[r][c] = true
        pc_showMsg("This pipe is fixed!")
        return
    ok

    oldRot = rotation[r][c]
    rotation[r][c] = (rotation[r][c] + amount) % 4
    moveCount += 1

    add(undoStack, [r, c, oldRot])
    if len(undoStack) > 200
        del(undoStack, 1)
    ok

    // Animation
    fromAngle = oldRot * 90.0
    toAngle = rotation[r][c] * 90.0
    if amount = 1 and rotation[r][c] = 0
        toAngle = 360.0
    ok
    if amount = 3 and oldRot = 0
        fromAngle = 360.0
        toAngle = rotation[r][c] * 90.0
    ok
    add(rotAnims, [r, c, fromAngle, toAngle, 0.0])

// =============================================================
// Undo
// =============================================================

func pc_undo
    if len(undoStack) = 0
        pc_showMsg("Nothing to undo!")
        return
    ok

    last = undoStack[len(undoStack)]
    del(undoStack, len(undoStack))
    rotation[last[1]][last[2]] = last[3]
    moveCount -= 1
    if moveCount < 0 moveCount = 0 ok
    pc_showMsg("Move undone")

// =============================================================
// Rotation Animations
// =============================================================

func pc_updateRotAnims dt
    i = 1
    while i <= len(rotAnims)
        rotAnims[i][5] += dt * 6.0
        if rotAnims[i][5] >= 1.0
            del(rotAnims, i)
        else
            i += 1
        ok
    end

func pc_getDisplayAngle r, c
    baseAngle = rotation[r][c] * 90.0
    for i = 1 to len(rotAnims)
        if rotAnims[i][1] = r and rotAnims[i][2] = c
            t = rotAnims[i][5]
            smooth = t * t * (3.0 - 2.0 * t)
            fromA = rotAnims[i][3]
            toA = rotAnims[i][4]
            return fromA + (toA - fromA) * smooth
        ok
    next
    return baseAngle

// =============================================================
// Flow Particles
// =============================================================

func pc_updateFlowParticles dt
    // Spawn flow particles in pipes that have water
    // Limit particle count
    if len(flowParticles) > 300 return ok

    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if flowMap[r][c] = false loop ok
            if GetRandomValue(1, 8) > 1 loop ok

            wx = pc_cellToX(c)
            wz = pc_cellToZ(r)
            offX = (GetRandomValue(-30, 30) / 100.0) * CELL_SZ * 0.3
            offZ = (GetRandomValue(-30, 30) / 100.0) * CELL_SZ * 0.3

            // Determine flow direction for velocity
            openings = pc_getOpenings(board[r][c], rotation[r][c])
            vx = 0.0  vz = 0.0
            if (openings & DIR_E) = DIR_E vx += 0.5 ok
            if (openings & DIR_W) = DIR_W vx -= 0.5 ok
            if (openings & DIR_S) = DIR_S vz += 0.5 ok
            if (openings & DIR_N) = DIR_N vz -= 0.5 ok

            add(flowParticles, [wx + offX, 0.4, wz + offZ,
                                vx + (GetRandomValue(-20,20)/100.0),
                                (GetRandomValue(20,80)/100.0),
                                vz + (GetRandomValue(-20,20)/100.0),
                                0.6 + (GetRandomValue(0,40)/100.0)])
        next
    next

    // Update
    i = 1
    while i <= len(flowParticles)
        flowParticles[i][1] += flowParticles[i][4] * dt
        flowParticles[i][2] += flowParticles[i][5] * dt
        flowParticles[i][3] += flowParticles[i][6] * dt
        flowParticles[i][5] -= 1.5 * dt
        flowParticles[i][7] -= dt
        if flowParticles[i][7] <= 0
            del(flowParticles, i)
        else
            i += 1
        ok
    end

func pc_drawFlowParticles3D
    for i = 1 to len(flowParticles)
        p = flowParticles[i]
        alpha = floor((p[7] / 1.0) * 200)
        if alpha > 200 alpha = 200 ok
        if alpha < 0 alpha = 0 ok
        sz = 0.04 + p[7] * 0.04
        DrawSphereEx(
            Vector3(p[1], p[2], p[3]),
            sz, 4, 4,
            RAYLIBColor(80, 160, 255, alpha)
        )
    next

// =============================================================
// Celebration Particles
// =============================================================

func pc_spawnWinParticles
    for i = 1 to 80
        wx = (GetRandomValue(-600, 600) / 100.0)
        wz = (GetRandomValue(-600, 600) / 100.0)
        vx = (GetRandomValue(-200, 200) / 100.0)
        vy = (GetRandomValue(400, 900) / 100.0)
        vz = (GetRandomValue(-200, 200) / 100.0)
        cr = GetRandomValue(50, 150)
        cg = GetRandomValue(150, 255)
        cb = GetRandomValue(200, 255)
        add(particles, [wx, 0.5, wz, vx, vy, vz, 2.5, cr, cg, cb])
    next

func pc_updateParticles dt
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

func pc_drawParticles3D
    for i = 1 to len(particles)
        p = particles[i]
        alpha = floor((p[7] / 2.5) * 255)
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
// Helpers
// =============================================================

func pc_cellToX c
    return (c - 1) * CELL_SZ - (BOARD_SZ - 1) * CELL_SZ / 2

func pc_cellToZ r
    return (r - 1) * CELL_SZ - (BOARD_SZ - 1) * CELL_SZ / 2

func pc_showMsg text
    msgText = text
    msgTimer = 2.0

// =============================================================
// 3D-to-Screen Projection
// =============================================================

func pc_projectToScreen wx, wy, wz
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

func pc_positionCamera
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
        goalY = maxDim * 0.8 + 3.0
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

func pc_drawBoard3D
    boardW = BOARD_SZ * CELL_SZ

    // Board slab
    slabH = 0.3
    DrawCube(Vector3(0, -slabH/2, 0),
             boardW + 0.8, slabH, boardW + 0.8,
             RAYLIBColor(40, 45, 55, 255))
    DrawCubeWires(Vector3(0, -slabH/2, 0),
                  boardW + 0.8, slabH, boardW + 0.8,
                  RAYLIBColor(28, 32, 38, 200))

    // Cell slots
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            wx = pc_cellToX(c)
            wz = pc_cellToZ(r)
            tileSz = CELL_SZ * 0.94
            DrawCube(Vector3(wx, 0.02, wz), tileSz, 0.04, tileSz,
                     RAYLIBColor(30, 35, 45, 255))
        next
    next

    // Border
    bThick = 0.18
    bH = 0.2
    halfE = boardW / 2 + 0.3
    edgeCol = RAYLIBColor(55, 60, 72, 255)
    DrawCube(Vector3(0, bH/2, -halfE), boardW + 0.8, bH, bThick, edgeCol)
    DrawCube(Vector3(0, bH/2, halfE),  boardW + 0.8, bH, bThick, edgeCol)
    DrawCube(Vector3(-halfE, bH/2, 0), bThick, bH, boardW + 0.5, edgeCol)
    DrawCube(Vector3(halfE, bH/2, 0),  bThick, bH, boardW + 0.5, edgeCol)

    // Table
    DrawPlane(Vector3(0, -slabH - 0.01, 0), Vector2(40, 40),
              RAYLIBColor(8, 10, 16, 255))

// =============================================================
// 3D Drawing: Pipes
// =============================================================

func pc_drawPipes3D
    PI = 3.14159265
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            ptype = board[r][c]
            if ptype = PIPE_NONE loop ok

            wx = pc_cellToX(c)
            wz = pc_cellToZ(r)
            angle = pc_getDisplayAngle(r, c)
            hasWater = flowMap[r][c]

            if hasWater = true
                pipeCol = RAYLIBColor(50, 140, 220, 255)
                wireCol = RAYLIBColor(30, 100, 180, 200)
                jointCol = RAYLIBColor(60, 160, 240, 255)
            else
                pipeCol = RAYLIBColor(120, 115, 110, 255)
                wireCol = RAYLIBColor(80, 75, 72, 200)
                jointCol = RAYLIBColor(140, 135, 130, 255)
            ok

            // Convert angle to radians
            rad = angle * PI / 180.0

            pipeR = CELL_SZ * 0.08
            pipeLen = CELL_SZ * 0.42
            baseY = 0.3

            // Central joint sphere
            DrawSphere(Vector3(wx, baseY, wz), pipeR * 1.6, jointCol)

            // Get openings for this pipe at current rotation
            openings = pc_getOpenings(ptype, rotation[r][c])

            if ptype = PIPE_SOURCE
                // Source: big blue cylinder
                DrawCylinder(Vector3(wx, 0.05, wz), CELL_SZ * 0.3, CELL_SZ * 0.25,
                             0.5, 16, RAYLIBColor(30, 100, 200, 255))
                DrawCylinderWires(Vector3(wx, 0.05, wz), CELL_SZ * 0.3, CELL_SZ * 0.25,
                                  0.5, 16, RAYLIBColor(20, 70, 150, 200))
                // Water spout
                pulse = 0.7 + sin(animTime * 4.0) * 0.3
                DrawSphere(Vector3(wx, 0.55, wz), CELL_SZ * 0.12 * pulse,
                           RAYLIBColor(80, 180, 255, 200))
                // Draw connectors in all 4 directions
                pc_drawPipeArm(wx, baseY, wz, 0, pipeR, pipeLen, pipeCol, wireCol)
                pc_drawPipeArm(wx, baseY, wz, 1, pipeR, pipeLen, pipeCol, wireCol)
                pc_drawPipeArm(wx, baseY, wz, 2, pipeR, pipeLen, pipeCol, wireCol)
                pc_drawPipeArm(wx, baseY, wz, 3, pipeR, pipeLen, pipeCol, wireCol)
                loop
            ok

            if ptype = PIPE_DRAIN
                // Drain: dark cylinder with grate
                if hasWater = true
                    drainCol = RAYLIBColor(40, 180, 80, 255)
                    drainWire = RAYLIBColor(30, 130, 60, 200)
                else
                    drainCol = RAYLIBColor(100, 60, 60, 255)
                    drainWire = RAYLIBColor(70, 40, 40, 200)
                ok
                DrawCylinder(Vector3(wx, 0.05, wz), CELL_SZ * 0.3, CELL_SZ * 0.25,
                             0.45, 16, drainCol)
                DrawCylinderWires(Vector3(wx, 0.05, wz), CELL_SZ * 0.3, CELL_SZ * 0.25,
                                  0.45, 16, drainWire)
                // Grate lines
                gs = CELL_SZ * 0.18
                gy = 0.51
                DrawLine3D(Vector3(wx - gs, gy, wz - gs),
                           Vector3(wx + gs, gy, wz + gs), drainWire)
                DrawLine3D(Vector3(wx + gs, gy, wz - gs),
                           Vector3(wx - gs, gy, wz + gs), drainWire)
                DrawLine3D(Vector3(wx, gy, wz - gs),
                           Vector3(wx, gy, wz + gs), drainWire)
                DrawLine3D(Vector3(wx - gs, gy, wz),
                           Vector3(wx + gs, gy, wz), drainWire)
                // Connectors in all 4 dirs
                pc_drawPipeArm(wx, baseY, wz, 0, pipeR, pipeLen, pipeCol, wireCol)
                pc_drawPipeArm(wx, baseY, wz, 1, pipeR, pipeLen, pipeCol, wireCol)
                pc_drawPipeArm(wx, baseY, wz, 2, pipeR, pipeLen, pipeCol, wireCol)
                pc_drawPipeArm(wx, baseY, wz, 3, pipeR, pipeLen, pipeCol, wireCol)
                loop
            ok

            // Regular pipes - draw arms based on openings
            if (openings & DIR_N) = DIR_N
                pc_drawPipeArm(wx, baseY, wz, 0, pipeR, pipeLen, pipeCol, wireCol)
            ok
            if (openings & DIR_E) = DIR_E
                pc_drawPipeArm(wx, baseY, wz, 1, pipeR, pipeLen, pipeCol, wireCol)
            ok
            if (openings & DIR_S) = DIR_S
                pc_drawPipeArm(wx, baseY, wz, 2, pipeR, pipeLen, pipeCol, wireCol)
            ok
            if (openings & DIR_W) = DIR_W
                pc_drawPipeArm(wx, baseY, wz, 3, pipeR, pipeLen, pipeCol, wireCol)
            ok

            // Pipe end caps (small spheres at arm tips)
            if (openings & DIR_N) = DIR_N
                DrawSphere(Vector3(wx, baseY, wz - pipeLen), pipeR * 1.3, jointCol)
            ok
            if (openings & DIR_E) = DIR_E
                DrawSphere(Vector3(wx + pipeLen, baseY, wz), pipeR * 1.3, jointCol)
            ok
            if (openings & DIR_S) = DIR_S
                DrawSphere(Vector3(wx, baseY, wz + pipeLen), pipeR * 1.3, jointCol)
            ok
            if (openings & DIR_W) = DIR_W
                DrawSphere(Vector3(wx - pipeLen, baseY, wz), pipeR * 1.3, jointCol)
            ok
        next
    next

// =============================================================
// Draw Pipe Arm (horizontal cylinder segment)
// =============================================================

func pc_drawPipeArm wx, wy, wz, dir, pipeR, pipeLen, pipeCol, wireCol
    // dir: 0=N, 1=E, 2=S, 3=W
    // Draw a cube as pipe segment from center toward direction
    halfLen = pipeLen / 2.0
    h = pipeR * 2.2

    if dir = 0
        // North: center to -Z
        DrawCube(Vector3(wx, wy, wz - halfLen), h, h, pipeLen, pipeCol)
        DrawCubeWires(Vector3(wx, wy, wz - halfLen), h, h, pipeLen, wireCol)
    ok
    if dir = 1
        // East: center to +X
        DrawCube(Vector3(wx + halfLen, wy, wz), pipeLen, h, h, pipeCol)
        DrawCubeWires(Vector3(wx + halfLen, wy, wz), pipeLen, h, h, wireCol)
    ok
    if dir = 2
        // South: center to +Z
        DrawCube(Vector3(wx, wy, wz + halfLen), h, h, pipeLen, pipeCol)
        DrawCubeWires(Vector3(wx, wy, wz + halfLen), h, h, pipeLen, wireCol)
    ok
    if dir = 3
        // West: center to -X
        DrawCube(Vector3(wx - halfLen, wy, wz), pipeLen, h, h, pipeCol)
        DrawCubeWires(Vector3(wx - halfLen, wy, wz), pipeLen, h, h, wireCol)
    ok

// =============================================================
// 3D Drawing: Cursor
// =============================================================

func pc_drawCursor3D
    if gameState != ST_PLAYING return ok

    wx = pc_cellToX(cursorC)
    wz = pc_cellToZ(cursorR)

    // Color based on lock status
    if locked[cursorR][cursorC] = true
        curCol = RAYLIBColor(255, 100, 60, 180)
    else
        curCol = RAYLIBColor(80, 255, 180, 200)
    ok

    // Corner brackets
    hs = CELL_SZ * 0.45
    bLen = CELL_SZ * 0.18
    by = 0.08

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

func pc_drawHUD
    panelW = 255
    panelH = 145
    DrawRectangle(10, 30, panelW, panelH, Fade(BLACK, 0.75))
    DrawRectangleLines(10, 30, panelW, panelH, RAYLIBColor(50, 140, 220, 200))

    DrawText("PIPE CONNECT", 20, 38, 20, RAYLIBColor(50, 180, 255, 255))

    DrawText("Board: " + BOARD_SZ + "x" + BOARD_SZ, 20, 64, 14,
             RAYLIBColor(160, 180, 200, 200))

    DrawText("Moves: " + moveCount, 20, 82, 16, RAYLIBColor(255, 255, 255, 240))

    // Timer
    mins = floor(gameTimer / 60)
    secs = floor(gameTimer) % 60
    if secs < 10
        timeStr = "" + mins + ":0" + secs
    else
        timeStr = "" + mins + ":" + secs
    ok
    DrawText("Time: " + timeStr, 20, 102, 14,
             RAYLIBColor(200, 200, 220, 200))

    // Flow count
    flowCount = 0
    totalPipes = BOARD_SZ * BOARD_SZ
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if flowMap[r][c] = true
                flowCount += 1
            ok
        next
    next
    DrawText("Flow: " + flowCount + "/" + totalPipes + " pipes", 20, 122, 14,
             RAYLIBColor(80, 180, 255, 220))

    // Progress bar
    barX = 20
    barY = 140
    barW = 225
    barH = 10
    DrawRectangle(barX, barY, barW, barH, RAYLIBColor(40, 40, 50, 200))
    if totalPipes > 0
        fillW = floor(barW * flowCount / totalPipes)
        if fillW > 0
            DrawRectangle(barX, barY, fillW, barH,
                          RAYLIBColor(50, 160, 240, 220))
        ok
    ok
    DrawRectangleLines(barX, barY, barW, barH, RAYLIBColor(80, 120, 160, 180))

    // Hints
    if showHints = true
        hStr = "Hints: ON [H]"
    else
        hStr = "Hints: OFF [H]"
    ok
    DrawText(hStr, 20, 156, 12, RAYLIBColor(140, 155, 175, 160))

    // Camera
    camName = "FRONT"
    if cameraMode = CAM_ISOMETRIC camName = "ISOMETRIC" ok
    if cameraMode = CAM_OVERHEAD  camName = "OVERHEAD"  ok
    DrawRectangle(10, SCREEN_H - 60, 220, 25, Fade(BLACK, 0.6))
    DrawText("Cam: " + camName + "  [C] switch", 16, SCREEN_H - 56, 14,
             RAYLIBColor(150, 180, 210, 220))

    // Controls
    DrawRectangle(SCREEN_W - 520, SCREEN_H - 35, 510, 25, Fade(BLACK, 0.6))
    DrawText("Click/Enter: Rotate CW | RClick/X: CCW | U: Undo | H: Hints | N: New",
             SCREEN_W - 515, SCREEN_H - 30, 12, RAYLIBColor(150, 160, 180, 200))

// =============================================================
// Mini Map
// =============================================================

func pc_drawMiniMap
    cellW = 18
    if BOARD_SZ >= 7 cellW = 15 ok
    if BOARD_SZ >= 8 cellW = 13 ok
    mapW = BOARD_SZ * cellW + 4
    mapH = BOARD_SZ * cellW + 4
    mapX = SCREEN_W - mapW - 15
    mapY = 30

    DrawRectangle(mapX - 3, mapY - 3, mapW + 6, mapH + 6, Fade(BLACK, 0.8))
    DrawRectangleLines(mapX - 3, mapY - 3, mapW + 6, mapH + 6,
                       RAYLIBColor(50, 140, 220, 200))

    DrawRectangle(mapX, mapY, mapW, mapH, RAYLIBColor(30, 35, 45, 230))

    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            tx = mapX + 2 + (c - 1) * cellW
            ty = mapY + 2 + (r - 1) * cellW
            tw = cellW - 2
            th = cellW - 2
            cx = tx + tw / 2
            cy = ty + th / 2

            ptype = board[r][c]
            hasWater = flowMap[r][c]

            if hasWater = true
                DrawRectangle(tx, ty, tw, th, RAYLIBColor(30, 80, 140, 200))
            else
                DrawRectangle(tx, ty, tw, th, RAYLIBColor(50, 48, 55, 200))
            ok

            // Draw pipe connections
            if hasWater = true
                lineCol = RAYLIBColor(80, 180, 255, 255)
            else
                lineCol = RAYLIBColor(120, 115, 110, 200)
            ok

            openings = pc_getOpenings(ptype, rotation[r][c])
            hw = tw / 2
            hh = th / 2

            if (openings & DIR_N) = DIR_N
                DrawLine(cx, cy, cx, ty, lineCol)
            ok
            if (openings & DIR_S) = DIR_S
                DrawLine(cx, cy, cx, ty + th, lineCol)
            ok
            if (openings & DIR_E) = DIR_E
                DrawLine(cx, cy, tx + tw, cy, lineCol)
            ok
            if (openings & DIR_W) = DIR_W
                DrawLine(cx, cy, tx, cy, lineCol)
            ok

            // Source/Drain markers
            if ptype = PIPE_SOURCE
                DrawRectangle(tx + 2, ty + 2, tw - 4, th - 4,
                              RAYLIBColor(30, 120, 220, 255))
            ok
            if ptype = PIPE_DRAIN
                if hasWater = true
                    DrawRectangle(tx + 2, ty + 2, tw - 4, th - 4,
                                  RAYLIBColor(40, 200, 80, 255))
                else
                    DrawRectangle(tx + 2, ty + 2, tw - 4, th - 4,
                                  RAYLIBColor(150, 60, 60, 255))
                ok
            ok

            // Central dot
            DrawCircle(cx, cy, 2, lineCol)

            DrawRectangleLines(tx, ty, tw, th,
                               RAYLIBColor(40, 45, 55, 120))
        next
    next

    // Cursor
    cx2 = mapX + 2 + (cursorC - 1) * cellW
    cy2 = mapY + 2 + (cursorR - 1) * cellW
    DrawRectangleLines(cx2, cy2, cellW - 2, cellW - 2,
                       RAYLIBColor(255, 255, 255, 220))

    DrawText("MAP", mapX + mapW/2 - 15, mapY - 16, 12,
             RAYLIBColor(50, 140, 220, 200))

// =============================================================
// Title Screen
// =============================================================

func pc_drawTitleScreen
    DrawRectangleGradientV(0, 0, SCREEN_W, SCREEN_H,
        RAYLIBColor(10, 14, 24, 255), RAYLIBColor(18, 22, 36, 255))

    t1 = "PIPE CONNECT"
    t1w = MeasureText(t1, 56)
    DrawText(t1, (SCREEN_W - t1w)/2, 35, 56, RAYLIBColor(50, 180, 255, 255))

    t1b = "3D EDITION"
    t1bw = MeasureText(t1b, 22)
    DrawText(t1b, (SCREEN_W - t1bw)/2, 100, 22, RAYLIBColor(100, 200, 255, 230))

    t2 = "~ Rotate Pipes to Connect Source to Drain ~"
    t2w = MeasureText(t2, 17)
    DrawText(t2, (SCREEN_W - t2w)/2, 135, 17, RAYLIBColor(150, 180, 220, 230))

    lx1 = 180
    lx2 = SCREEN_W - 180
    ly = 165
    DrawLine(lx1, ly, lx2, ly, RAYLIBColor(50, 140, 220, 180))

    cy = 180
    cLines = [
        "Click / ENTER / SPACE  -   Rotate pipe clockwise",
        "Right Click / X        -   Rotate pipe counter-clockwise",
        "Arrow Keys / WASD      -   Move cursor on the board",
        "U / Backspace          -   Undo last rotation",
        "H                      -   Toggle flow hints",
        "N                      -   New puzzle (same size)",
        "R                      -   Return to title screen",
        "C                      -   Cycle camera view",
        "",
        "Board Sizes:   1=5x5   2=6x6   3=7x7   4=8x8",
        "",
        "Pipe Types:",
        "  Straight - connects 2 opposite sides",
        "  Bend     - connects 2 adjacent sides (L-shape)",
        "  T-piece  - connects 3 sides",
        "  Cross    - connects all 4 sides",
        "",
        "Rules:",
        "  Rotate pipes to build a continuous path from the blue",
        "  SOURCE to the DRAIN. Water flows through aligned openings.",
        "  Connected pipes turn blue. Solve when water reaches drain!"
    ]
    for i = 1 to len(cLines)
        lw = MeasureText(cLines[i], 13)
        if i >= 10
            col = RAYLIBColor(100, 200, 255, 210)
        else
            col = RAYLIBColor(150, 170, 200, 230)
        ok
        DrawText(cLines[i], (SCREEN_W - lw)/2, cy + (i - 1) * 20, 13, col)
    next

    // Current size
    sizeStr = "Current: " + BOARD_SZ + "x" + BOARD_SZ
    ssw = MeasureText(sizeStr, 18)
    DrawText(sizeStr, (SCREEN_W - ssw)/2, 610, 18,
             RAYLIBColor(50, 180, 255, 230))

    if floor(animTime * 2) % 2 = 0
        st2 = "Click or Press ENTER / SPACE to Start"
        st2w = MeasureText(st2, 24)
        DrawText(st2, (SCREEN_W - st2w)/2, 640, 24, WHITE)
    ok

    cr = "Developed using Ring Language + RingRayLib"
    crw = MeasureText(cr, 14)
    DrawText(cr, (SCREEN_W - crw)/2, SCREEN_H - 30, 14,
             RAYLIBColor(80, 100, 80, 180))

// =============================================================
// Solved Overlay
// =============================================================

func pc_drawSolvedOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.5))

    g1 = "PIPES CONNECTED!"
    g1w = MeasureText(g1, 48)
    pulse = floor(220 + sin(animTime * 3.0) * 35)
    DrawText(g1, (SCREEN_W - g1w)/2, 170, 48,
             RAYLIBColor(50, 220, 255, pulse))

    g2 = "Water flows from Source to Drain!"
    g2w = MeasureText(g2, 20)
    DrawText(g2, (SCREEN_W - g2w)/2, 235, 20, RAYLIBColor(80, 255, 120, 230))

    g3 = "Moves: " + moveCount
    g3w = MeasureText(g3, 22)
    DrawText(g3, (SCREEN_W - g3w)/2, 275, 22, RAYLIBColor(255, 255, 255, 240))

    mins = floor(gameTimer / 60)
    secs = floor(gameTimer) % 60
    if secs < 10
        timeStr = "" + mins + ":0" + secs
    else
        timeStr = "" + mins + ":" + secs
    ok
    ts = "Time: " + timeStr
    tsw = MeasureText(ts, 20)
    DrawText(ts, (SCREEN_W - tsw)/2, 305, 20, RAYLIBColor(200, 200, 220, 220))

    if floor(animTime * 2) % 2 = 0
        rt = "Press N for new puzzle  |  R for title screen"
        rtw = MeasureText(rt, 16)
        DrawText(rt, (SCREEN_W - rtw)/2, 355, 16, WHITE)
    ok

    ss = "Change size: 1=5x5  2=6x6  3=7x7  4=8x8"
    ssw = MeasureText(ss, 14)
    DrawText(ss, (SCREEN_W - ssw)/2, 385, 14, RAYLIBColor(150, 180, 220, 200))

// =============================================================
// Message Overlay
// =============================================================

func pc_drawMessage
    alpha = floor((msgTimer / 2.0) * 255)
    if alpha > 255 alpha = 255 ok
    if alpha < 0 alpha = 0 ok

    mw = MeasureText(msgText, 24)
    mx = (SCREEN_W - mw) / 2
    my = SCREEN_H / 2 + 140

    DrawRectangle(mx - 15, my - 8, mw + 30, 40,
                  RAYLIBColor(0, 0, 0, floor(alpha * 0.7)))
    DrawText(msgText, mx, my, 24,
             RAYLIBColor(80, 200, 255, alpha))
