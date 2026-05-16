/*
**  3D Line Trace Puzzle - Inspired by The Witness
**  Using RingRayLib
**  ================================================
**  Trace a path on glowing grid panels from the start
**  circle to the exit notch. Follow the rules!
**
**  Controls:
**    Arrow Keys / WASD  - Move path cursor along grid edges
**    Mouse Drag         - Hold and drag to draw path
**    Backspace / U      - Undo last path segment
**    Z                  - Clear entire path (restart drawing)
**    F                  - Auto-solve puzzle
**    N                  - Next puzzle (if unlocked)
**    B                  - Previous puzzle
**    R                  - Reset current puzzle
**    C                  - Cycle camera views
**    ESC                - Exit
**
**  Rules:
**    - Path must start at the START circle (bottom-left usually)
**    - Path must end at the EXIT notch (top edge usually)
**    - Path travels along grid edges (lines between nodes)
**    - Must pass through all REQUIRED DOTS (yellow diamonds)
**    - Must not cross BROKEN EDGES (marked with X)
**    - BLACK/WHITE squares must be separated by the path
**      (same-color squares must be in same region)
**
**  Features:
**    - 15 hand-crafted puzzles of increasing difficulty
**    - Glowing amber/gold panel aesthetic
**    - 3D floating panel with environment
**    - Smooth path drawing with glow trail
**    - Visual validation (green flash = correct, red = wrong)
**    - Multiple constraint types
**    - Hint system (BFS solver)
**    - Three camera modes
**    - Particle effects
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W        = 1024
SCREEN_H        = 768

// Grid dimensions (nodes, not cells)
// A puzzle of gridW x gridH nodes has (gridW-1)*(gridH-1) cells
MAX_GRID_W      = 8
MAX_GRID_H      = 8

// Game states
ST_TITLE        = 1
ST_DRAWING      = 2
ST_VALIDATING   = 3
ST_SUCCESS      = 4
ST_FAILED       = 5

// Camera modes
CAM_FRONT       = 1
CAM_ANGLE       = 2
CAM_CLOSE       = 3
CAM_COUNT       = 3

// Constraint types for cells
CONS_NONE       = 0
CONS_BLACK      = 1     // Black square
CONS_WHITE      = 2     // White square

// Edge states
EDGE_NORMAL     = 0
EDGE_BROKEN     = 1     // Cannot traverse
EDGE_REQUIRED   = 2     // Path must use this edge (dot on edge)

// Node markers
NODE_NONE       = 0
NODE_START      = 1     // Start circle
NODE_EXIT       = 2     // Exit point
NODE_DOT        = 3     // Required: path must pass through

PI              = 3.14159265

// =============================================================
// Global Variables
// =============================================================

gridW           = 4     // nodes wide
gridH           = 4     // nodes tall

// Node markers: nodeMarker[row][col]
nodeMarker      = []

// Horizontal edges: hEdge[row][col] = edge between node(row,col) and node(row,col+1)
// Size: gridH rows, (gridW-1) cols
hEdge           = []

// Vertical edges: vEdge[row][col] = edge between node(row,col) and node(row+1,col)
// Size: (gridH-1) rows, gridW cols
vEdge           = []

// Cell constraints: cellCons[row][col] where row=1..gridH-1, col=1..gridW-1
// Cell (row,col) is bounded by nodes (row,col), (row,col+1), (row+1,col), (row+1,col+1)
cellCons        = []

// Current path: list of [nodeRow, nodeCol] forming the traced path
pathNodes       = []

// Start and exit positions
startR          = 0
startC          = 0
exitR           = 0
exitC           = 0

// Cursor (current head of path)
cursorR         = 0
cursorC         = 0

// Game state
gameState       = ST_TITLE
animTime        = 0.0
validTimer      = 0.0   // Timer for success/fail flash

// Puzzles
puzzles         = []
puzzleCount     = 0
currentPuzzle   = 1
maxUnlocked     = 1

// Hint path
hintPath        = []
showHint        = false

// Auto-solver playback
solverActive    = false
solverStep      = 0
solverDelay     = 0.0
SOLVER_WAIT     = 0.15      // seconds between each step
successTimer    = 0.0       // auto-advance after success

// Particles
particles       = []

// Camera
cameraMode      = CAM_FRONT
camPosX = 0.0   camPosY = 0.0   camPosZ = 8.0
camTgtX = 0.0   camTgtY = 0.0   camTgtZ = 0.0

// Message
msgText         = ""
msgTimer        = 0.0

// Screen projection output
projSX          = 0.0
projSY          = 0.0

// Panel drawing scale
panelScale      = 1.0

// =============================================================
// Puzzle Definitions
// =============================================================
// Format: [gridW, gridH, startR, startC, exitR, exitC,
//          nodeDotsStr, brokenEdgesStr, cellConsStr]
//
// nodeDotsStr:   "r,c;r,c;..." nodes that must be visited
// brokenEdgesStr: "type,r,c;..." where type=H or V
// cellConsStr:   "r,c,type;..." where type=B(black) or W(white)
// Coordinates are 1-based

// Level 1: Simple 3x3 path, no constraints
// Just trace from bottom-left to top-right
add(puzzles, [3, 3, 3, 1, 1, 3, "", "", ""])

// Level 2: 3x3, one required dot
add(puzzles, [3, 3, 3, 1, 1, 3, "2,2", "", ""])

// Level 3: 4x4, two required dots
add(puzzles, [4, 4, 4, 1, 1, 4, "3,2;2,3", "", ""])

// Level 4: 3x3, broken edge
add(puzzles, [3, 3, 3, 1, 1, 3, "", "H,2,1", ""])

// Level 5: 4x4, dots + broken edges
add(puzzles, [4, 4, 4, 1, 1, 4, "3,2", "H,2,2;V,2,3", ""])

// Level 6: 3x3, black/white separation
add(puzzles, [3, 3, 3, 1, 1, 3, "", "", "1,1,B;1,2,W"])

// Level 7: 4x4, color separation
add(puzzles, [4, 4, 4, 1, 1, 4, "", "", "1,1,B;1,3,B;3,1,W;3,3,W"])

// Level 8: 4x4, dots + colors
add(puzzles, [4, 4, 4, 1, 1, 4, "2,2", "", "1,1,B;1,3,W;3,1,W;3,3,B"])

// Level 9: 5x5, multi-dot
add(puzzles, [5, 5, 5, 1, 1, 5, "4,2;3,3;2,4", "", ""])

// Level 10: 4x4, broken edges maze
add(puzzles, [4, 4, 4, 1, 1, 4, "", "H,2,1;H,3,2;V,1,2;V,3,3", ""])

// Level 11: 5x5, colors + dots
add(puzzles, [5, 5, 5, 1, 1, 5, "3,3", "", "1,1,B;1,4,W;4,1,W;4,4,B"])

// Level 12: 5x5, complex broken edges + dot
add(puzzles, [5, 5, 5, 1, 1, 5, "4,2;2,4", "H,2,2;H,4,3;V,2,1;V,3,4", ""])

// Level 13: 5x5, full challenge (all types)
add(puzzles, [5, 5, 5, 1, 1, 5, "3,3", "V,2,3;H,4,2", "1,1,B;1,4,W;4,1,W;4,4,B"])

// Level 14: 6x6, all constraint types (constrained maze)
add(puzzles, [6, 6, 6, 1, 1, 6, "4,3;3,4", "H,1,2;H,2,4;H,3,1;H,4,3;H,5,5;V,1,3;V,2,1;V,3,5;V,4,2;V,5,4", "1,1,B;1,5,B;5,1,W;5,5,W;3,3,B"])

// Level 15: 6x6, grand finale (corridor maze)
add(puzzles, [6, 6, 6, 1, 1, 6, "4,3;2,5", "H,1,1;H,2,3;H,3,5;H,4,2;H,5,4;V,1,4;V,2,2;V,3,3;V,4,5;V,5,1", "1,2,B;1,5,W;5,2,W;5,5,B"])

puzzleCount = len(puzzles)

// =============================================================
// Main Program
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Ring 3D Line Trace Puzzle - RingRayLib")
SetTargetFPS(60)

camera = Camera3D(
    0, 0, 8,
    0, 0, 0,
    0, 1, 0,
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

    // ========== STATE UPDATES ==========

    if gameState = ST_TITLE
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(0)
            wt_loadPuzzle(currentPuzzle)
            gameState = ST_DRAWING
        ok
    ok

    if gameState = ST_DRAWING
        if solverActive
            solverDelay -= dt
            if solverDelay <= 0
                if solverStep <= len(hintPath)
                    // Set path directly up to this step
                    pathNodes = []
                    for si = 1 to solverStep
                        add(pathNodes, [hintPath[si][1], hintPath[si][2]])
                    next
                    cursorR = hintPath[solverStep][1]
                    cursorC = hintPath[solverStep][2]
                    // Spawn particles at current step
                    wx = wt_nodeToWorldX(cursorC)
                    wy = wt_nodeToWorldY(cursorR)
                    wt_spawnPathParticles(wx, wy)
                    // Auto-validate when reaching exit
                    if cursorR = exitR and cursorC = exitC
                        solverActive = false
                        wt_validatePath()
                    else
                        solverStep += 1
                        solverDelay = SOLVER_WAIT
                    ok
                else
                    solverActive = false
                ok
            ok
        else
            wt_handleInput()
            wt_handleMouse()
        ok
        wt_updateParticles(dt)
    ok

    if gameState = ST_VALIDATING
        validTimer -= dt
        if validTimer <= 0
            validTimer = 0
            gameState = ST_DRAWING
        ok
        wt_updateParticles(dt)
    ok

    if gameState = ST_SUCCESS
        wt_updateParticles(dt)
        successTimer -= dt
        if successTimer <= 0 or IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsKeyPressed(KEY_N)
            if currentPuzzle < puzzleCount
                wt_loadPuzzle(currentPuzzle + 1)
                gameState = ST_DRAWING
            else
                // Last puzzle - stay on success but allow B/R navigation
                gameState = ST_DRAWING
            ok
        ok
    ok

    if gameState = ST_FAILED
        validTimer -= dt
        wt_updateParticles(dt)
        if validTimer <= 0 or IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            validTimer = 0
            gameState = ST_DRAWING
        ok
    ok

    // Puzzle navigation
    if gameState = ST_DRAWING or gameState = ST_SUCCESS or gameState = ST_FAILED
        if IsKeyPressed(KEY_N)
            if currentPuzzle < maxUnlocked
                wt_loadPuzzle(currentPuzzle + 1)
                gameState = ST_DRAWING
            ok
        ok
        if IsKeyPressed(KEY_B)
            if currentPuzzle > 1
                wt_loadPuzzle(currentPuzzle - 1)
                gameState = ST_DRAWING
            ok
        ok
        if IsKeyPressed(KEY_R)
            wt_loadPuzzle(currentPuzzle)
            gameState = ST_DRAWING
        ok
    ok

    wt_positionCamera()

    // ========== DRAWING ==========

    BeginDrawing()
        ClearBackground(RAYLIBColor(20, 22, 28, 255))

        if gameState = ST_TITLE
            wt_drawTitleScreen()
        else
            BeginMode3D(camera)
                wt_drawEnvironment3D()
                wt_drawPanel3D()
                wt_drawParticles3D()
            EndMode3D()

            wt_drawHUD()

            if gameState = ST_SUCCESS
                wt_drawSuccessOverlay()
            ok
            if msgTimer > 0
                wt_drawMessage()
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
// Load Puzzle
// =============================================================

func wt_loadPuzzle num
    if num < 1 or num > puzzleCount return ok
    currentPuzzle = num
    if num > maxUnlocked maxUnlocked = num ok

    pz = puzzles[num]
    gridW = pz[1]
    gridH = pz[2]
    startR = pz[3]
    startC = pz[4]
    exitR = pz[5]
    exitC = pz[6]
    dotsStr = pz[7]
    brokenStr = pz[8]
    consStr = pz[9]

    // Compute scale
    maxDim = gridW - 1
    if gridH - 1 > maxDim maxDim = gridH - 1 ok
    panelScale = 4.0 / maxDim

    // Init node markers
    nodeMarker = list(gridH)
    for r = 1 to gridH
        nodeMarker[r] = list(gridW)
        for c = 1 to gridW
            nodeMarker[r][c] = NODE_NONE
        next
    next
    nodeMarker[startR][startC] = NODE_START
    nodeMarker[exitR][exitC] = NODE_EXIT

    // Parse dot nodes
    if len(dotsStr) > 0
        parts = wt_splitStr(dotsStr, ";")
        for i = 1 to len(parts)
            coords = wt_splitStr(parts[i], ",")
            if len(coords) >= 2
                dr = number(coords[1])
                dc = number(coords[2])
                if dr >= 1 and dr <= gridH and dc >= 1 and dc <= gridW
                    nodeMarker[dr][dc] = NODE_DOT
                ok
            ok
        next
    ok

    // Init horizontal edges
    hEdge = list(gridH)
    for r = 1 to gridH
        hEdge[r] = list(gridW - 1)
        for c = 1 to gridW - 1
            hEdge[r][c] = EDGE_NORMAL
        next
    next

    // Init vertical edges
    vEdge = list(gridH - 1)
    for r = 1 to gridH - 1
        vEdge[r] = list(gridW)
        for c = 1 to gridW
            vEdge[r][c] = EDGE_NORMAL
        next
    next

    // Parse broken edges
    if len(brokenStr) > 0
        parts = wt_splitStr(brokenStr, ";")
        for i = 1 to len(parts)
            tokens = wt_splitStr(parts[i], ",")
            if len(tokens) >= 3
                etype = tokens[1]
                er = number(tokens[2])
                ec = number(tokens[3])
                if etype = "H" and er >= 1 and er <= gridH and ec >= 1 and ec <= gridW - 1
                    hEdge[er][ec] = EDGE_BROKEN
                ok
                if etype = "V" and er >= 1 and er <= gridH - 1 and ec >= 1 and ec <= gridW
                    vEdge[er][ec] = EDGE_BROKEN
                ok
            ok
        next
    ok

    // Init cell constraints
    cellCons = list(gridH - 1)
    for r = 1 to gridH - 1
        cellCons[r] = list(gridW - 1)
        for c = 1 to gridW - 1
            cellCons[r][c] = CONS_NONE
        next
    next

    // Parse cell constraints
    if len(consStr) > 0
        parts = wt_splitStr(consStr, ";")
        for i = 1 to len(parts)
            tokens = wt_splitStr(parts[i], ",")
            if len(tokens) >= 3
                cr = number(tokens[1])
                cc = number(tokens[2])
                ctype = tokens[3]
                if cr >= 1 and cr <= gridH - 1 and cc >= 1 and cc <= gridW - 1
                    if ctype = "B" cellCons[cr][cc] = CONS_BLACK ok
                    if ctype = "W" cellCons[cr][cc] = CONS_WHITE ok
                ok
            ok
        next
    ok

    // Init path at start
    pathNodes = []
    add(pathNodes, [startR, startC])
    cursorR = startR
    cursorC = startC

    hintPath = []
    showHint = false
    solverActive = false
    solverStep = 0
    particles = []
    validTimer = 0

// =============================================================
// String Split Helper
// =============================================================

func wt_splitStr str, delim
    result = []
    current = ""
    for i = 1 to len(str)
        ch = substr(str, i, 1)
        if ch = delim
            if len(current) > 0
                add(result, current)
                current = ""
            ok
        else
            current += ch
        ok
    next
    if len(current) > 0
        add(result, current)
    ok
    return result

// =============================================================
// Input
// =============================================================

func wt_handleInput
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

    if dr != 0 or dc != 0
        wt_tryExtendPath(dr, dc)
    ok

    // Submit
    if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
        wt_validatePath()
    ok

    // Undo
    if IsKeyPressed(KEY_BACKSPACE) or IsKeyPressed(KEY_U)
        wt_undoPath()
    ok

    // Clear
    if IsKeyPressed(KEY_Z)
        wt_clearPath()
    ok

    // Auto-solve
    if IsKeyPressed(KEY_F)
        wt_computeHint()
    ok

// =============================================================
// Mouse Handling (hold and drag to draw)
// =============================================================

func wt_handleMouse
    if IsMouseButtonDown(0) = false return ok

    mx = GetMouseX()
    my = GetMouseY()

    // Project current cursor to screen
    wt_nodeToScreen(cursorR, cursorC)
    curSX = projSX
    curSY = projSY

    // Check: is mouse far enough from current cursor to want to move?
    ddx = mx - curSX
    ddy = my - curSY

    // Compute half the distance between adjacent nodes on screen
    // by projecting a neighbor
    threshold = 0.0
    if cursorC < gridW
        wt_nodeToScreen(cursorR, cursorC + 1)
        nsx = projSX
        halfDist = (nsx - curSX) * 0.35
        if halfDist < 0 halfDist = 0 - halfDist ok
        threshold = halfDist
    but cursorR > 1
        wt_nodeToScreen(cursorR - 1, cursorC)
        nsy = projSY
        halfDist = (nsy - curSY) * 0.35
        if halfDist < 0 halfDist = 0 - halfDist ok
        threshold = halfDist
    else
        threshold = 25.0
    ok
    if threshold < 15.0 threshold = 15.0 ok

    mouseDist = sqrt(ddx * ddx + ddy * ddy)
    if mouseDist < threshold return ok

    // Find which adjacent node the mouse is closest to
    bestDist = 99999.0
    bestDR = 0
    bestDC = 0
    dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]]

    for di = 1 to 4
        nr = cursorR + dirs[di][1]
        nc = cursorC + dirs[di][2]
        if nr < 1 or nr > gridH or nc < 1 or nc > gridW loop ok

        wt_nodeToScreen(nr, nc)
        ndx = projSX - mx
        ndy = projSY - my
        ndist = ndx * ndx + ndy * ndy
        if ndist < bestDist
            bestDist = ndist
            bestDR = dirs[di][1]
            bestDC = dirs[di][2]
        ok
    next

    if bestDR = 0 and bestDC = 0 return ok

    wt_tryExtendPath(bestDR, bestDC)

// =============================================================
// Path Extension
// =============================================================

func wt_tryExtendPath dr, dc
    newR = cursorR + dr
    newC = cursorC + dc

    // Bounds check
    if newR < 1 or newR > gridH or newC < 1 or newC > gridW return ok

    // Check if this would retrace (undo last step)
    if len(pathNodes) >= 2
        prevR = pathNodes[len(pathNodes) - 1][1]
        prevC = pathNodes[len(pathNodes) - 1][2]
        if newR = prevR and newC = prevC
            // This is going backward - undo
            wt_undoPath()
            return
        ok
    ok

    // Check if node already in path (no crossing)
    for i = 1 to len(pathNodes)
        if pathNodes[i][1] = newR and pathNodes[i][2] = newC
            return
        ok
    next

    // Check edge validity
    if dr = 0
        // Horizontal move
        edgeC = cursorC
        if dc < 0 edgeC = cursorC - 1 ok
        if edgeC < 1 or edgeC > gridW - 1 return ok
        if hEdge[cursorR][edgeC] = EDGE_BROKEN return ok
    else
        // Vertical move
        edgeR = cursorR
        if dr < 0 edgeR = cursorR - 1 ok
        if edgeR < 1 or edgeR > gridH - 1 return ok
        if vEdge[edgeR][cursorC] = EDGE_BROKEN return ok
    ok

    // Valid move - extend path
    add(pathNodes, [newR, newC])
    cursorR = newR
    cursorC = newC

    // Spawn particles
    wx = wt_nodeToWorldX(newC)
    wy = wt_nodeToWorldY(newR)
    wt_spawnPathParticles(wx, wy)

    // Auto-validate when reaching exit
    if cursorR = exitR and cursorC = exitC
        wt_validatePath()
    ok

// =============================================================
// Undo / Clear
// =============================================================

func wt_undoPath
    if len(pathNodes) <= 1 return ok
    del(pathNodes, len(pathNodes))
    cursorR = pathNodes[len(pathNodes)][1]
    cursorC = pathNodes[len(pathNodes)][2]

func wt_clearPath
    pathNodes = []
    add(pathNodes, [startR, startC])
    cursorR = startR
    cursorC = startC
    showHint = false

// =============================================================
// Validation
// =============================================================

func wt_validatePath
    // Check 1: Path must end at exit
    if cursorR != exitR or cursorC != exitC
        wt_showMsg("Path must reach the EXIT!")
        gameState = ST_FAILED
        validTimer = 1.5
        wt_spawnFailParticles()
        return
    ok

    // Check 2: All required dot nodes must be visited
    for r = 1 to gridH
        for c = 1 to gridW
            if nodeMarker[r][c] = NODE_DOT
                found = false
                for i = 1 to len(pathNodes)
                    if pathNodes[i][1] = r and pathNodes[i][2] = c
                        found = true
                    ok
                next
                if found = false
                    wt_showMsg("Missing required dot!")
                    gameState = ST_FAILED
                    validTimer = 1.5
                    wt_spawnFailParticles()
                    return
                ok
            ok
        next
    next

    // Check 3: Color separation (black/white squares)
    if wt_checkColorSeparation() = false
        wt_showMsg("Colors not properly separated!")
        gameState = ST_FAILED
        validTimer = 1.5
        wt_spawnFailParticles()
        return
    ok

    // All checks passed!
    gameState = ST_SUCCESS
    successTimer = 2.0
    if currentPuzzle + 1 > maxUnlocked
        maxUnlocked = currentPuzzle + 1
        if maxUnlocked > puzzleCount maxUnlocked = puzzleCount ok
    ok
    wt_showMsg("SOLVED!")
    wt_spawnSuccessParticles()

// =============================================================
// Color Separation Check
// =============================================================

func wt_checkColorSeparation
    // Build region map by flood-filling cells not separated by path
    // Two cells are in same region if the edge between them is NOT on the path

    numCellR = gridH - 1
    numCellC = gridW - 1
    if numCellR < 1 or numCellC < 1 return true ok

    regionMap = list(numCellR)
    for r = 1 to numCellR
        regionMap[r] = list(numCellC)
        for c = 1 to numCellC
            regionMap[r][c] = 0
        next
    next

    regionID = 0

    for r = 1 to numCellR
        for c = 1 to numCellC
            if regionMap[r][c] = 0
                // New region - flood fill
                regionID += 1
                queue = []
                add(queue, [r, c])
                regionMap[r][c] = regionID
                head = 1
                while head <= len(queue)
                    cr = queue[head][1]
                    cc = queue[head][2]
                    head += 1

                    // Check 4 neighbors
                    // Up: cell(cr-1,cc) shares top edge of cr = bottom edge of cr-1
                    // Edge between is the horizontal edge at node-row cr, from col cc to cc+1
                    if cr > 1
                        if regionMap[cr-1][cc] = 0
                            if wt_isEdgeOnPath(cr, cc, cr, cc+1) = false
                                regionMap[cr-1][cc] = regionID
                                add(queue, [cr-1, cc])
                            ok
                        ok
                    ok
                    // Down
                    if cr < numCellR
                        if regionMap[cr+1][cc] = 0
                            if wt_isEdgeOnPath(cr+1, cc, cr+1, cc+1) = false
                                regionMap[cr+1][cc] = regionID
                                add(queue, [cr+1, cc])
                            ok
                        ok
                    ok
                    // Left
                    if cc > 1
                        if regionMap[cr][cc-1] = 0
                            if wt_isEdgeOnPath(cr, cc, cr+1, cc) = false
                                regionMap[cr][cc-1] = regionID
                                add(queue, [cr, cc-1])
                            ok
                        ok
                    ok
                    // Right
                    if cc < numCellC
                        if regionMap[cr][cc+1] = 0
                            if wt_isEdgeOnPath(cr, cc+1, cr+1, cc+1) = false
                                regionMap[cr][cc+1] = regionID
                                add(queue, [cr, cc+1])
                            ok
                        ok
                    ok
                end
            ok
        next
    next

    // Now check: in each region, all colored cells must be same color
    for rid = 1 to regionID
        hasBlack = false
        hasWhite = false
        for r = 1 to numCellR
            for c = 1 to numCellC
                if regionMap[r][c] = rid
                    if cellCons[r][c] = CONS_BLACK hasBlack = true ok
                    if cellCons[r][c] = CONS_WHITE hasWhite = true ok
                ok
            next
        next
        if hasBlack and hasWhite
            return false
        ok
    next

    return true

// =============================================================
// Check if edge between two nodes is on the path
// =============================================================

func wt_isEdgeOnPath r1, c1, r2, c2
    for i = 1 to len(pathNodes) - 1
        pr1 = pathNodes[i][1]
        pc1 = pathNodes[i][2]
        pr2 = pathNodes[i+1][1]
        pc2 = pathNodes[i+1][2]
        if (pr1 = r1 and pc1 = c1 and pr2 = r2 and pc2 = c2) or (pr1 = r2 and pc1 = c2 and pr2 = r1 and pc2 = c1)
            return true
        ok
    next
    return false

// =============================================================
// Hint System (BFS)
// =============================================================

func wt_computeHint
    // DFS to find valid path, then auto-play it

    // Reset path first
    wt_clearPath()

    hintPath = []
    showHint = false
    solverActive = false
    path = []
    add(path, [startR, startC])
    visited = list(gridH)
    for r = 1 to gridH
        visited[r] = list(gridW)
        for c = 1 to gridW
            visited[r][c] = false
        next
    next
    visited[startR][startC] = true

    result = wt_dfsSolve(path, visited)
    if result
        // Copy solution
        hintPath = []
        for i = 1 to len(path)
            add(hintPath, [path[i][1], path[i][2]])
        next
        showHint = true
        // Start auto-playback
        solverActive = true
        solverStep = 1
        solverDelay = 0.3
        wt_showMsg("Auto-solving: " + (len(hintPath) - 1) + " steps")
    else
        wt_showMsg("No solution found!")
    ok

func wt_dfsSolve pathRef, visitedRef
    // Iterative DFS using explicit stack
    // Stack entries: [nodeR, nodeC, dirIndex]
    // dirIndex = which direction to try next (1-4), 5 means backtrack

    stack = []
    add(stack, [startR, startC, 1])
    dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]]

    while len(stack) > 0
        top = stack[len(stack)]
        cr = top[1]
        cc = top[2]
        di = top[3]

        // Check if at exit before trying directions
        if di = 1 and cr = exitR and cc = exitC
            // Validate: build pathNodes temporarily
            oldPath = pathNodes
            pathNodes = []
            for si = 1 to len(stack)
                add(pathNodes, [stack[si][1], stack[si][2]])
            next
            cursorR = exitR
            cursorC = exitC

            allDots = true
            for r = 1 to gridH
                for c = 1 to gridW
                    if nodeMarker[r][c] = NODE_DOT
                        found = false
                        for pi = 1 to len(pathNodes)
                            if pathNodes[pi][1] = r and pathNodes[pi][2] = c
                                found = true
                            ok
                        next
                        if found = false allDots = false ok
                    ok
                next
            next

            colorOk = wt_checkColorSeparation()

            pathNodes = oldPath
            if len(pathNodes) > 0
                cursorR = pathNodes[len(pathNodes)][1]
                cursorC = pathNodes[len(pathNodes)][2]
            ok

            if allDots and colorOk
                // Copy solution to pathRef
                while len(pathRef) > 0
                    del(pathRef, len(pathRef))
                end
                for si = 1 to len(stack)
                    add(pathRef, [stack[si][1], stack[si][2]])
                next
                return true
            ok
            // Not valid, backtrack
            stack[len(stack)][3] = 5
            loop
        ok

        // Try direction di
        if di > 4
            // All directions exhausted, backtrack
            visitedRef[cr][cc] = false
            del(stack, len(stack))
            loop
        ok

        // Advance to next direction for next time
        stack[len(stack)][3] = di + 1

        dr = dirs[di][1]
        dc = dirs[di][2]
        nr = cr + dr
        nc = cc + dc

        if nr < 1 or nr > gridH or nc < 1 or nc > gridW loop ok
        if visitedRef[nr][nc] loop ok

        // Check edge
        edgeOk = true
        if dr = 0
            edgeC = cc
            if dc < 0 edgeC = cc - 1 ok
            if edgeC < 1 or edgeC > gridW - 1 edgeOk = false ok
            if edgeOk
                if hEdge[cr][edgeC] = EDGE_BROKEN edgeOk = false ok
            ok
        else
            edgeR = cr
            if dr < 0 edgeR = cr - 1 ok
            if edgeR < 1 or edgeR > gridH - 1 edgeOk = false ok
            if edgeOk
                if vEdge[edgeR][cc] = EDGE_BROKEN edgeOk = false ok
            ok
        ok

        if edgeOk = false loop ok

        // Push new node
        visitedRef[nr][nc] = true
        add(stack, [nr, nc, 1])
    end

    return false

// =============================================================
// Coordinate Helpers
// =============================================================

func wt_nodeToWorldX c
    // Center grid on panel
    return (c - 1 - (gridW - 1) / 2.0) * panelScale

func wt_nodeToWorldY r
    // Row 1 = top, gridH = bottom, but in world Y is up
    return ((gridH - 1) / 2.0 - (r - 1)) * panelScale

func wt_nodeToScreen r, c
    wx = wt_nodeToWorldX(c)
    wy = wt_nodeToWorldY(r)
    wt_projectToScreen(wx, wy, 0.05)

// =============================================================
// 3D Projection
// =============================================================

func wt_projectToScreen wx, wy, wz
    fwdX = camTgtX - camPosX
    fwdY = camTgtY - camPosY
    fwdZ = camTgtZ - camPosZ
    fLen = sqrt(fwdX*fwdX + fwdY*fwdY + fwdZ*fwdZ)
    if fLen < 0.0001
        projSX = SCREEN_W / 2
        projSY = SCREEN_H / 2
        return
    ok
    fwdX = fwdX / fLen   fwdY = fwdY / fLen   fwdZ = fwdZ / fLen
    rightX = -fwdZ   rightY = 0   rightZ = fwdX
    rLen = sqrt(rightX*rightX + rightY*rightY + rightZ*rightZ)
    if rLen < 0.0001
        projSX = SCREEN_W / 2
        projSY = SCREEN_H / 2
        return
    ok
    rightX = rightX / rLen   rightY = rightY / rLen   rightZ = rightZ / rLen
    upX = rightY * fwdZ - rightZ * fwdY
    upY = rightZ * fwdX - rightX * fwdZ
    upZ = rightX * fwdY - rightY * fwdX
    dx = wx - camPosX   dy = wy - camPosY   dz = wz - camPosZ
    dotFwd   = dx * fwdX   + dy * fwdY   + dz * fwdZ
    dotRight = dx * rightX + dy * rightY + dz * rightZ
    dotUp    = dx * upX    + dy * upY    + dz * upZ
    if dotFwd < 0.01
        projSX = -9999   projSY = -9999
        return
    ok
    fovRad = 45.0 * PI / 180.0
    tanHalf = tan(fovRad / 2.0)
    aspect = SCREEN_W * 1.0 / SCREEN_H
    ndcX = (dotRight / dotFwd) / (tanHalf * aspect)
    ndcY = (dotUp / dotFwd) / tanHalf
    projSX = (ndcX * 0.5 + 0.5) * SCREEN_W
    projSY = (1.0 - (ndcY * 0.5 + 0.5)) * SCREEN_H

// =============================================================
// Camera
// =============================================================

func wt_positionCamera
    goalX = 0.0  goalY = 0.0  goalZ = 8.0
    tgtX = 0.0   tgtY = 0.0   tgtZ = 0.0

    if cameraMode = CAM_FRONT
        goalX = 0.0   goalY = 0.0   goalZ = 7.0
    ok
    if cameraMode = CAM_ANGLE
        goalX = 3.0   goalY = 2.0   goalZ = 6.5
    ok
    if cameraMode = CAM_CLOSE
        goalX = 0.0   goalY = 0.0   goalZ = 5.0
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
// Particles
// =============================================================

func wt_spawnPathParticles wx, wy
    for i = 1 to 6
        vx = (GetRandomValue(-100, 100) / 100.0)
        vy = (GetRandomValue(-100, 100) / 100.0)
        vz = (GetRandomValue(50, 200) / 100.0)
        add(particles, [wx, wy, 0.05, vx, vy, vz, 0.6, 255, 200, 80])
    next

func wt_spawnSuccessParticles
    for i = 1 to 50
        wx = (GetRandomValue(-300, 300) / 100.0)
        wy = (GetRandomValue(-300, 300) / 100.0)
        vx = (GetRandomValue(-200, 200) / 100.0)
        vy = (GetRandomValue(-200, 200) / 100.0)
        vz = (GetRandomValue(100, 400) / 100.0)
        add(particles, [wx, wy, 0.1, vx, vy, vz, 2.0, 80, 255, 120])
    next

func wt_spawnFailParticles
    for i = 1 to 20
        wx = (GetRandomValue(-200, 200) / 100.0)
        wy = (GetRandomValue(-200, 200) / 100.0)
        vx = (GetRandomValue(-150, 150) / 100.0)
        vy = (GetRandomValue(-150, 150) / 100.0)
        vz = (GetRandomValue(50, 200) / 100.0)
        add(particles, [wx, wy, 0.1, vx, vy, vz, 1.0, 255, 60, 60])
    next

func wt_updateParticles dt
    i = 1
    while i <= len(particles)
        particles[i][1] += particles[i][4] * dt
        particles[i][2] += particles[i][5] * dt
        particles[i][3] += particles[i][6] * dt
        particles[i][6] -= 3.0 * dt
        particles[i][7] -= dt
        if particles[i][7] <= 0
            del(particles, i)
        else
            i += 1
        ok
    end

func wt_drawParticles3D
    for i = 1 to len(particles)
        p = particles[i]
        alpha = floor((p[7] / 2.0) * 255)
        if alpha > 255 alpha = 255 ok
        if alpha < 0 alpha = 0 ok
        sz = 0.02 + p[7] * 0.03
        DrawSphereEx(
            Vector3(p[1], p[2], p[3]),
            sz, 4, 4,
            RAYLIBColor(p[8], p[9], p[10], alpha)
        )
    next

// =============================================================
// Helpers
// =============================================================

func wt_showMsg text
    msgText = text
    msgTimer = 2.0

// =============================================================
// 3D Drawing: Environment
// =============================================================

func wt_drawEnvironment3D
    // Back wall
    DrawCube(Vector3(0, 0, -1.5), 14, 10, 0.5, RAYLIBColor(30, 32, 38, 255))

    // Floor
    DrawCube(Vector3(0, -4, 0), 14, 0.3, 8, RAYLIBColor(25, 28, 34, 255))

    // Ambient glow behind panel
    pulse = 0.5 + sin(animTime * 1.5) * 0.2
    gAlpha = floor(40 * pulse)
    DrawCube(Vector3(0, 0, -0.8), 5.5, 5.5, 0.1,
             RAYLIBColor(180, 140, 50, gAlpha))

// =============================================================
// 3D Drawing: Panel
// =============================================================

func wt_drawPanel3D
    // Panel frame
    panelW2 = (gridW - 1) * panelScale / 2.0 + 0.5
    panelH2 = (gridH - 1) * panelScale / 2.0 + 0.5

    // Panel backing (dark amber)
    DrawCube(Vector3(0, 0, -0.15), panelW2 * 2.0 + 0.2, panelH2 * 2.0 + 0.2, 0.3,
             RAYLIBColor(50, 45, 35, 255))

    // Panel face (amber/gold)
    panelCol = RAYLIBColor(180, 150, 60, 255)
    if gameState = ST_SUCCESS
        panelCol = RAYLIBColor(80, 220, 100, 255)
    ok
    if gameState = ST_FAILED
        panelCol = RAYLIBColor(220, 60, 50, 255)
    ok

    DrawCube(Vector3(0, 0, -0.02), panelW2 * 2.0, panelH2 * 2.0, 0.04, panelCol)

    // Frame border
    DrawCubeWires(Vector3(0, 0, -0.02), panelW2 * 2.0 + 0.15, panelH2 * 2.0 + 0.15, 0.08,
                  RAYLIBColor(100, 90, 60, 200))

    // Draw grid edges
    wt_drawGridEdges3D()

    // Draw cell constraints
    wt_drawCellConstraints3D()

    // Draw node markers
    wt_drawNodeMarkers3D()

    // Draw the current path
    wt_drawPath3D()

    // Draw hint path
    if showHint
        wt_drawHintPath3D()
    ok

    // Draw cursor
    wt_drawCursor3D()

// =============================================================
// Draw Grid Edges
// =============================================================

func wt_drawGridEdges3D
    lineR = panelScale * 0.04
    z = 0.02

    // Draw horizontal edges
    for r = 1 to gridH
        for c = 1 to gridW - 1
            x1 = wt_nodeToWorldX(c)
            x2 = wt_nodeToWorldX(c + 1)
            y1 = wt_nodeToWorldY(r)
            mx = (x1 + x2) / 2.0
            edgeLen = x2 - x1

            if hEdge[r][c] = EDGE_BROKEN
                // Draw broken edge as dashed
                seg = edgeLen / 3.0
                DrawCube(Vector3(x1 + seg * 0.3, y1, z), seg * 0.4, lineR, lineR,
                         RAYLIBColor(80, 60, 30, 200))
                DrawCube(Vector3(x2 - seg * 0.3, y1, z), seg * 0.4, lineR, lineR,
                         RAYLIBColor(80, 60, 30, 200))
                // X marker
                DrawSphere(Vector3(mx, y1, z + 0.02), lineR * 2.5,
                           RAYLIBColor(200, 60, 40, 200))
            else
                DrawCube(Vector3(mx, y1, z), edgeLen, lineR, lineR,
                         RAYLIBColor(100, 85, 40, 200))
            ok
        next
    next

    // Draw vertical edges
    for r = 1 to gridH - 1
        for c = 1 to gridW
            x1 = wt_nodeToWorldX(c)
            y1 = wt_nodeToWorldY(r)
            y2 = wt_nodeToWorldY(r + 1)
            my = (y1 + y2) / 2.0
            edgeLen = y1 - y2

            if vEdge[r][c] = EDGE_BROKEN
                seg = edgeLen / 3.0
                DrawCube(Vector3(x1, y1 - seg * 0.3, z), lineR, seg * 0.4, lineR,
                         RAYLIBColor(80, 60, 30, 200))
                DrawCube(Vector3(x1, y2 + seg * 0.3, z), lineR, seg * 0.4, lineR,
                         RAYLIBColor(80, 60, 30, 200))
                DrawSphere(Vector3(x1, my, z + 0.02), lineR * 2.5,
                           RAYLIBColor(200, 60, 40, 200))
            else
                DrawCube(Vector3(x1, my, z), lineR, edgeLen, lineR,
                         RAYLIBColor(100, 85, 40, 200))
            ok
        next
    next

// =============================================================
// Draw Cell Constraints
// =============================================================

func wt_drawCellConstraints3D
    z = 0.04
    sz = panelScale * 0.22

    for r = 1 to gridH - 1
        for c = 1 to gridW - 1
            if cellCons[r][c] = CONS_NONE loop ok

            // Cell center
            cx = (wt_nodeToWorldX(c) + wt_nodeToWorldX(c + 1)) / 2.0
            cy = (wt_nodeToWorldY(r) + wt_nodeToWorldY(r + 1)) / 2.0

            if cellCons[r][c] = CONS_BLACK
                DrawCube(Vector3(cx, cy, z), sz, sz, sz * 0.3,
                         RAYLIBColor(20, 20, 25, 255))
                DrawCubeWires(Vector3(cx, cy, z), sz, sz, sz * 0.3,
                              RAYLIBColor(60, 60, 70, 200))
            ok
            if cellCons[r][c] = CONS_WHITE
                DrawCube(Vector3(cx, cy, z), sz, sz, sz * 0.3,
                         RAYLIBColor(240, 235, 220, 255))
                DrawCubeWires(Vector3(cx, cy, z), sz, sz, sz * 0.3,
                              RAYLIBColor(180, 175, 160, 200))
            ok
        next
    next

// =============================================================
// Draw Node Markers
// =============================================================

func wt_drawNodeMarkers3D
    z = 0.04

    for r = 1 to gridH
        for c = 1 to gridW
            wx = wt_nodeToWorldX(c)
            wy = wt_nodeToWorldY(r)

            // Regular nodes: small junction dot
            if nodeMarker[r][c] = NODE_NONE
                DrawSphere(Vector3(wx, wy, z), panelScale * 0.04,
                           RAYLIBColor(120, 100, 50, 180))
            ok

            // Start circle
            if nodeMarker[r][c] = NODE_START
                pulse = 0.7 + sin(animTime * 3.0) * 0.3
                sRad = panelScale * 0.15
                DrawSphere(Vector3(wx, wy, z + 0.02), sRad,
                           RAYLIBColor(255, 200, 80, floor(200 * pulse)))
                DrawSphereWires(Vector3(wx, wy, z + 0.02), sRad, 8, 8,
                                RAYLIBColor(255, 240, 150, floor(150 * pulse)))
            ok

            // Exit notch
            if nodeMarker[r][c] = NODE_EXIT
                pulse = 0.7 + sin(animTime * 3.5) * 0.3
                // Draw short bar extending outward from grid
                barLen = panelScale * 0.25
                barDir = 0.0
                // Determine exit direction (outward from grid)
                if r = 1
                    // Top exit - extend upward
                    DrawCube(Vector3(wx, wy + barLen / 2.0, z), panelScale * 0.08, barLen, panelScale * 0.06,
                             RAYLIBColor(255, 200, 80, floor(200 * pulse)))
                ok
                if r = gridH
                    DrawCube(Vector3(wx, wy - barLen / 2.0, z), panelScale * 0.08, barLen, panelScale * 0.06,
                             RAYLIBColor(255, 200, 80, floor(200 * pulse)))
                ok
                if c = 1
                    DrawCube(Vector3(wx - barLen / 2.0, wy, z), barLen, panelScale * 0.08, panelScale * 0.06,
                             RAYLIBColor(255, 200, 80, floor(200 * pulse)))
                ok
                if c = gridW
                    DrawCube(Vector3(wx + barLen / 2.0, wy, z), barLen, panelScale * 0.08, panelScale * 0.06,
                             RAYLIBColor(255, 200, 80, floor(200 * pulse)))
                ok
                // Node glow
                DrawSphere(Vector3(wx, wy, z + 0.01), panelScale * 0.06,
                           RAYLIBColor(255, 220, 100, floor(180 * pulse)))
            ok

            // Required dot
            if nodeMarker[r][c] = NODE_DOT
                pulse = 0.6 + sin(animTime * 4.0 + r * 1.1 + c * 0.7) * 0.4
                dotSz = panelScale * 0.08
                // Diamond shape (rotated cube)
                DrawCube(Vector3(wx, wy, z + 0.03), dotSz, dotSz, dotSz * 0.6,
                         RAYLIBColor(255, 220, 50, floor(255 * pulse)))
                DrawCubeWires(Vector3(wx, wy, z + 0.03), dotSz, dotSz, dotSz * 0.6,
                              RAYLIBColor(255, 255, 150, floor(150 * pulse)))
            ok
        next
    next

// =============================================================
// Draw Path
// =============================================================

func wt_drawPath3D
    if len(pathNodes) < 1 return ok

    z = 0.06
    pathR = panelScale * 0.07

    pathCol = RAYLIBColor(255, 240, 180, 255)
    if gameState = ST_SUCCESS
        pathCol = RAYLIBColor(120, 255, 150, 255)
    ok
    if gameState = ST_FAILED
        pathCol = RAYLIBColor(255, 80, 60, 255)
    ok

    // Draw path segments
    for i = 1 to len(pathNodes) - 1
        x1 = wt_nodeToWorldX(pathNodes[i][2])
        y1 = wt_nodeToWorldY(pathNodes[i][1])
        x2 = wt_nodeToWorldX(pathNodes[i+1][2])
        y2 = wt_nodeToWorldY(pathNodes[i+1][1])
        mx = (x1 + x2) / 2.0
        my = (y1 + y2) / 2.0

        if y1 = y2
            // Horizontal
            segLen = x2 - x1
            if segLen < 0 segLen = 0 - segLen ok
            DrawCube(Vector3(mx, my, z), segLen + pathR * 2.0, pathR * 2.0, pathR,
                     pathCol)
        else
            // Vertical
            segLen = y1 - y2
            if segLen < 0 segLen = 0 - segLen ok
            DrawCube(Vector3(mx, my, z), pathR * 2.0, segLen + pathR * 2.0, pathR,
                     pathCol)
        ok
    next

    // Draw path nodes (circles)
    for i = 1 to len(pathNodes)
        wx = wt_nodeToWorldX(pathNodes[i][2])
        wy = wt_nodeToWorldY(pathNodes[i][1])
        DrawSphere(Vector3(wx, wy, z + 0.01), pathR * 1.1, pathCol)
    next

    // Glow on path
    glowAlpha = floor(30 + sin(animTime * 3.0) * 15)
    for i = 1 to len(pathNodes) - 1
        x1 = wt_nodeToWorldX(pathNodes[i][2])
        y1 = wt_nodeToWorldY(pathNodes[i][1])
        x2 = wt_nodeToWorldX(pathNodes[i+1][2])
        y2 = wt_nodeToWorldY(pathNodes[i+1][1])
        mx = (x1 + x2) / 2.0
        my = (y1 + y2) / 2.0
        gR = pathR * 3.5
        if y1 = y2
            segLen = x2 - x1
            if segLen < 0 segLen = 0 - segLen ok
            DrawCube(Vector3(mx, my, z + 0.02), segLen + gR, gR, 0.01,
                     RAYLIBColor(255, 230, 150, glowAlpha))
        else
            segLen = y1 - y2
            if segLen < 0 segLen = 0 - segLen ok
            DrawCube(Vector3(mx, my, z + 0.02), gR, segLen + gR, 0.01,
                     RAYLIBColor(255, 230, 150, glowAlpha))
        ok
    next

// =============================================================
// Draw Hint Path
// =============================================================

func wt_drawHintPath3D
    if len(hintPath) < 2 return ok

    z = 0.04
    hR = panelScale * 0.03

    pulse = 0.4 + sin(animTime * 5.0) * 0.3
    hAlpha = floor(120 * pulse)

    for i = 1 to len(hintPath) - 1
        x1 = wt_nodeToWorldX(hintPath[i][2])
        y1 = wt_nodeToWorldY(hintPath[i][1])
        x2 = wt_nodeToWorldX(hintPath[i+1][2])
        y2 = wt_nodeToWorldY(hintPath[i+1][1])
        mx = (x1 + x2) / 2.0
        my = (y1 + y2) / 2.0

        if y1 = y2
            segLen = x2 - x1
            if segLen < 0 segLen = 0 - segLen ok
            DrawCube(Vector3(mx, my, z), segLen, hR * 2.0, hR,
                     RAYLIBColor(100, 255, 200, hAlpha))
        else
            segLen = y1 - y2
            if segLen < 0 segLen = 0 - segLen ok
            DrawCube(Vector3(mx, my, z), hR * 2.0, segLen, hR,
                     RAYLIBColor(100, 255, 200, hAlpha))
        ok
    next

// =============================================================
// Draw Cursor
// =============================================================

func wt_drawCursor3D
    if gameState != ST_DRAWING return ok

    wx = wt_nodeToWorldX(cursorC)
    wy = wt_nodeToWorldY(cursorR)
    z = 0.08

    pulse = 0.6 + sin(animTime * 4.0) * 0.4
    cRad = panelScale * 0.1
    cAlpha = floor(200 * pulse)
    DrawSphere(Vector3(wx, wy, z), cRad,
               RAYLIBColor(255, 255, 220, cAlpha))
    DrawSphereWires(Vector3(wx, wy, z), cRad * 1.3, 6, 6,
                    RAYLIBColor(255, 240, 150, floor(cAlpha * 0.5)))

// =============================================================
// HUD
// =============================================================

func wt_drawHUD
    panelW2 = 240
    panelH2 = 120
    DrawRectangle(10, 30, panelW2, panelH2, Fade(BLACK, 0.75))
    DrawRectangleLines(10, 30, panelW2, panelH2, RAYLIBColor(180, 150, 60, 200))

    DrawText("LINE TRACE", 20, 38, 20, RAYLIBColor(255, 220, 100, 255))

    lStr = "Puzzle: " + currentPuzzle + " / " + puzzleCount
    DrawText(lStr, 20, 64, 14, RAYLIBColor(200, 180, 120, 200))

    // Grid info
    DrawText("Grid: " + gridW + "x" + gridH, 20, 82, 13,
             RAYLIBColor(160, 150, 110, 200))

    // Path length
    DrawText("Path: " + (len(pathNodes) - 1) + " segments", 20, 98, 13,
             RAYLIBColor(160, 150, 110, 200))

    // Status
    statusStr = "Drawing..."
    statusCol = RAYLIBColor(255, 220, 100, 220)
    if solverActive
        statusStr = "AUTO-SOLVING..."
        statusCol = RAYLIBColor(100, 255, 200, 255)
    ok
    if gameState = ST_SUCCESS
        statusStr = "SOLVED!"
        statusCol = RAYLIBColor(80, 255, 120, 255)
    ok
    if gameState = ST_FAILED
        statusStr = "Invalid!"
        statusCol = RAYLIBColor(255, 80, 60, 255)
    ok
    DrawText(statusStr, 20, 118, 16, statusCol)

    // Progress bar
    barX = 20
    barY = 138
    barW = 210
    barH = 8
    DrawRectangle(barX, barY, barW, barH, RAYLIBColor(40, 40, 50, 200))
    if puzzleCount > 0
        fillW = floor(barW * maxUnlocked / puzzleCount)
        if fillW > 0
            DrawRectangle(barX, barY, fillW, barH,
                          RAYLIBColor(180, 150, 60, 220))
        ok
    ok
    DrawRectangleLines(barX, barY, barW, barH,
                       RAYLIBColor(100, 90, 60, 180))

    // Camera
    camName = "FRONT"
    if cameraMode = CAM_ANGLE camName = "ANGLE" ok
    if cameraMode = CAM_CLOSE camName = "CLOSE" ok
    DrawRectangle(10, SCREEN_H - 60, 200, 25, Fade(BLACK, 0.6))
    DrawText("Cam: " + camName + "  [C] switch", 16, SCREEN_H - 56, 14,
             RAYLIBColor(180, 160, 100, 220))

    // Controls
    DrawRectangle(SCREEN_W - 600, SCREEN_H - 35, 590, 25, Fade(BLACK, 0.6))
    DrawText("Arrows: Draw | Enter: Submit | U: Undo | X: Clear | H: Hint | N/B: Nav",
             SCREEN_W - 596, SCREEN_H - 30, 12, RAYLIBColor(160, 150, 120, 200))

// =============================================================
// Title Screen
// =============================================================

func wt_drawTitleScreen
    DrawRectangleGradientV(0, 0, SCREEN_W, SCREEN_H,
        RAYLIBColor(20, 18, 12, 255), RAYLIBColor(30, 28, 20, 255))

    // Ambient particles
    for i = 0 to 20
        sx = ((floor(animTime * 15 + i * 41) % SCREEN_W) + SCREEN_W) % SCREEN_W
        sy = ((floor(animTime * 25 + i * 67) % SCREEN_H) + SCREEN_H) % SCREEN_H
        DrawCircle(sx, sy, 2, RAYLIBColor(255, 200, 80, 40))
    next

    t1 = "LINE TRACE PUZZLE"
    t1w = MeasureText(t1, 48)
    DrawText(t1, (SCREEN_W - t1w)/2, 40, 48, RAYLIBColor(255, 220, 100, 255))

    t1b = "~ Inspired by The Witness ~"
    t1bw = MeasureText(t1b, 18)
    DrawText(t1b, (SCREEN_W - t1bw)/2, 95, 18, RAYLIBColor(200, 180, 120, 230))

    ly = 125
    DrawLine(200, ly, SCREEN_W - 200, ly, RAYLIBColor(180, 150, 60, 180))

    // Demo panel
    dSz = 30
    dStartX = (SCREEN_W - 4 * dSz) / 2
    dStartY = 140
    // Draw 4x4 grid lines
    for r = 0 to 4
        y2 = dStartY + r * dSz
        DrawLine(dStartX, y2, dStartX + 4 * dSz, y2, RAYLIBColor(120, 100, 50, 180))
    next
    for c = 0 to 4
        x2 = dStartX + c * dSz
        DrawLine(x2, dStartY, x2, dStartY + 4 * dSz, RAYLIBColor(120, 100, 50, 180))
    next
    // Demo path (animated)
    pathLen = floor(animTime * 2) % 8
    demoPath = [[4,0],[3,0],[2,0],[2,1],[2,2],[1,2],[1,3],[0,3]]
    for i = 1 to len(demoPath) - 1
        if i > pathLen + 1 loop ok
        x1d = dStartX + demoPath[i][2] * dSz
        y1d = dStartY + demoPath[i][1] * dSz
        x2d = dStartX + demoPath[i+1][2] * dSz
        y2d = dStartY + demoPath[i+1][1] * dSz
        DrawLineEx(Vector2(x1d, y1d), Vector2(x2d, y2d), 4,
                   RAYLIBColor(255, 230, 150, 255))
    next
    // Start circle
    DrawCircle(dStartX, dStartY + 4 * dSz, 8, RAYLIBColor(255, 200, 80, 220))
    // Exit
    DrawCircle(dStartX + 3 * dSz, dStartY - 5, 5, RAYLIBColor(255, 200, 80, 220))
    DrawLine(dStartX + 3 * dSz, dStartY, dStartX + 3 * dSz, dStartY - 10,
             RAYLIBColor(255, 200, 80, 220))

    cy = 295
    cKeys = [
        "Arrows / WASD",
        "Mouse Drag",
        "U / Backspace",
        "Z",
        "F",
        "N / B",
        "R",
        "C"
    ]
    cDescs = [
        "Move path along grid edges",
        "Hold and drag to draw path",
        "Undo last segment",
        "Clear path and restart",
        "Auto-solve puzzle",
        "Next / Previous puzzle",
        "Reset current puzzle",
        "Cycle camera view"
    ]
    keyCol = RAYLIBColor(255, 220, 100, 240)
    descCol = RAYLIBColor(180, 170, 140, 230)
    kx = 180
    dx = 410
    for i = 1 to len(cKeys)
        DrawText(cKeys[i], kx, cy + (i - 1) * 20, 14, keyCol)
        DrawText("-   " + cDescs[i], dx, cy + (i - 1) * 20, 13, descCol)
    next

    ry = cy + len(cKeys) * 20 + 10
    ruleCol = RAYLIBColor(255, 220, 130, 210)
    rLines = [
        "Rules:",
        "  Trace from START circle to EXIT notch along edges",
        "  Pass through all yellow DOTS (required)",
        "  Avoid BROKEN edges (red markers)",
        "  Separate BLACK and WHITE squares by path",
        "",
        "15 puzzles from simple to challenging!"
    ]
    for i = 1 to len(rLines)
        lw = MeasureText(rLines[i], 13)
        DrawText(rLines[i], (SCREEN_W - lw)/2, ry + (i - 1) * 18, 13, ruleCol)
    next

    if floor(animTime * 2) % 2 = 0
        st2 = "Click or Press ENTER / SPACE to Start"
        st2w = MeasureText(st2, 22)
        DrawText(st2, (SCREEN_W - st2w)/2, 650, 22, WHITE)
    ok

    cr = "Developed using Ring Language + RingRayLib"
    crw = MeasureText(cr, 14)
    DrawText(cr, (SCREEN_W - crw)/2, SCREEN_H - 25, 14,
             RAYLIBColor(80, 80, 60, 180))

// =============================================================
// Success Overlay
// =============================================================

func wt_drawSuccessOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.3))

    g1 = "PUZZLE SOLVED!"
    g1w = MeasureText(g1, 44)
    pulse = floor(220 + sin(animTime * 3.0) * 35)
    DrawText(g1, (SCREEN_W - g1w)/2, 60, 44,
             RAYLIBColor(80, 255, 120, pulse))

    g2 = "Puzzle " + currentPuzzle + " complete in " + (len(pathNodes) - 1) + " steps!"
    g2w = MeasureText(g2, 20)
    DrawText(g2, (SCREEN_W - g2w)/2, 120, 20, RAYLIBColor(200, 255, 200, 220))

    if currentPuzzle < puzzleCount
        if floor(animTime * 2) % 2 = 0
            nt = "Press ENTER or N for next puzzle"
            ntw = MeasureText(nt, 18)
            DrawText(nt, (SCREEN_W - ntw)/2, 160, 18, WHITE)
        ok
    else
        at = "All 15 puzzles complete! Congratulations!"
        atw = MeasureText(at, 18)
        DrawText(at, (SCREEN_W - atw)/2, 160, 18,
                 RAYLIBColor(255, 220, 80, 255))
    ok

// =============================================================
// Message
// =============================================================

func wt_drawMessage
    alpha = floor((msgTimer / 2.0) * 255)
    if alpha > 255 alpha = 255 ok
    if alpha < 0 alpha = 0 ok

    mw = MeasureText(msgText, 24)
    mx = (SCREEN_W - mw) / 2
    my = SCREEN_H / 2 + 180

    DrawRectangle(mx - 15, my - 8, mw + 30, 40,
                  RAYLIBColor(0, 0, 0, floor(alpha * 0.7)))
    DrawText(msgText, mx, my, 24,
             RAYLIBColor(255, 220, 100, alpha))
