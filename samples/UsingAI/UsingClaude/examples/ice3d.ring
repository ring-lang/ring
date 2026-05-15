/*
**  3D Ice Sliding Puzzle - Using RingRayLib
**  ===========================================
**  Slide across icy floors - you can't stop until hitting
**  a wall or rock! Navigate through mazes to reach the goal.
**
**  Controls:
**    Arrow Keys / WASD  - Slide in direction (won't stop mid-slide!)
**    Mouse Click        - Click on side of player to slide that direction
**    U / Backspace      - Undo last slide
**    H                  - Auto-Solve (BFS optimal solution)
**    R                  - Restart current level
**    N                  - Next level (if unlocked)
**    B                  - Previous level
**    C                  - Cycle camera views
**    ESC                - Exit
**
**  Tile Types:
**    Ice (light blue)   - Player slides across without stopping
**    Wall (dark blocks) - Stops player, cannot enter
**    Rock (brown)       - Obstacle on ice, stops player
**    Goal (green glow)  - Reach this to complete the level!
**    Start (blue glow)  - Player starting position
**
**  Rules:
**    - Press a direction to slide; player moves until blocked
**    - Plan your route carefully - fewer moves = better!
**    - Some puzzles require bouncing off rocks strategically
**
**  Features:
**    - 15 hand-crafted levels with increasing difficulty
**    - 3D ice floor with reflective sheen
**    - Smooth multi-cell sliding animation
**    - Ice trail particles during slides
**    - Walls rendered as tall dark blocks
**    - Rocks as mid-grid 3D boulders
**    - Glowing goal tile with beacon
**    - Ghost trail showing slide path
**    - Full undo system (unlimited)
**    - Three camera modes
**    - Level progress tracking
**    - Particle effects and celebrations
**    - Mini-map overlay
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W        = 1024
SCREEN_H        = 768
CELL_SZ         = 2.0
WALL_HEIGHT     = 2.2

// Tile types
TILE_EMPTY      = 0
TILE_ICE        = 1
TILE_WALL       = 2
TILE_ROCK       = 3
TILE_GOAL       = 4
TILE_START      = 5

// Game states
ST_START        = 1
ST_PLAYING      = 2
ST_SLIDING      = 3
ST_WON          = 4
ST_ALLCLEAR     = 5

// Camera modes
CAM_FRONT       = 1
CAM_ISOMETRIC   = 2
CAM_OVERHEAD    = 3
CAM_COUNT       = 3

ANIM_SPEED      = 10.0

// =============================================================
// Global Variables
// =============================================================

grid            = []
gridRows        = 0
gridCols        = 0
playerR         = 1
playerC         = 1
goalR           = 1
goalC           = 1

gameState       = ST_START
animTime        = 0.0
moveCount       = 0

// Slide animation
animActive      = false
animTimer       = 0.0
animFromR       = 0
animFromC       = 0
animToR         = 0
animToC         = 0
animTotalDist   = 1
pendingWin      = false

// Trail: [[r, c], ...] cells visited this slide
slideTrail      = []

// Undo: [[playerR, playerC], ...] previous positions
undoStack       = []

// Levels
levels          = []
levelCount      = 0
currentLevel    = 1
maxUnlocked     = 1

// Particles
particles       = []

// Camera
cameraMode      = CAM_OVERHEAD
camPosX = 0.0   camPosY = 15.0  camPosZ = 12.0
camTgtX = 0.0   camTgtY = 0.0   camTgtZ = 0.0

// Mouse hover
mouseHoverR     = 0
mouseHoverC     = 0
projScreenX     = 0.0
projScreenY     = 0.0

// Player facing
playerFaceR     = 0
playerFaceC     = 1

// Message
msgText         = ""
msgTimer        = 0.0

// Auto-solver
solverPath      = []        // list of [dr, dc] directions to execute
solverStep      = 0         // current step index in path
solverActive    = false     // is auto-solve playing?
solverDelay     = 0.0       // timer between moves
SOLVER_WAIT     = 0.45      // seconds between each auto-move

// =============================================================
// Level Definitions
// =============================================================

// Legend: # = Wall, . = Ice, R = Rock, G = Goal, P = Start
// Outer ring of # is the boundary
// All 15 levels verified solvable by BFS.

// Level 1 - Straight shot
// Solution (1 move): RIGHT
add(levels, [
    "######",
    "#....#",
    "#PG#.#",
    "######"
])

// Level 2 - L-shape
// Solution (2 moves): DOWN -> RIGHT
add(levels, [
    "######",
    "#.P..#",
    "#...G#",
    "######"
])

// Level 3 - Three-step
// Solution (3 moves): LEFT -> UP -> RIGHT
add(levels, [
    "######",
    "##...#",
    "#...G#",
    "#.P..#",
    "######"
])

// Level 4 - First rock
// Solution (3 moves): LEFT -> DOWN -> RIGHT
add(levels, [
    "#######",
    "#.....#",
    "#....P#",
    "#..GR.#",
    "#######"
])

// Level 5 - Wall bounce
// Solution (4 moves): UP -> RIGHT -> DOWN -> LEFT
add(levels, [
    "#######",
    "#.....#",
    "#G....#",
    "#..P.R#",
    "#######"
])

// Level 6 - Rock corridor
// Solution (4 moves): UP -> RIGHT -> DOWN -> LEFT
add(levels, [
    "#######",
    "#.....#",
    "#G....#",
    "#.R..R#",
    "#.#P#.#",
    "#######"
])

// Level 7 - Zigzag
// Solution (6 moves): LEFT -> UP -> RIGHT -> UP -> LEFT -> DOWN
add(levels, [
    "########",
    "#R.#...#",
    "#......#",
    "#...G..#",
    "#.P.R..#",
    "########"
])

// Level 8 - Multi-rock
// Solution (5 moves): UP -> RIGHT -> UP -> RIGHT -> UP
add(levels, [
    "########",
    "#..R.#G#",
    "#..#...#",
    "#.....R#",
    "#.RP...#",
    "########"
])

// Level 9 - Walled maze
// Solution (5 moves): UP -> RIGHT -> DOWN -> LEFT -> UP
add(levels, [
    "########",
    "#......#",
    "#P...R.#",
    "#...RG.#",
    "#......#",
    "#...R..#",
    "########"
])

// Level 10 - Strategic
// Solution (7 moves): RIGHT -> DOWN -> LEFT -> UP -> RIGHT -> UP -> RIGHT
add(levels, [
    "#########",
    "#...#.GR#",
    "#.....R.#",
    "#P......#",
    "#.......#",
    "#..R....#",
    "#########"
])

// Level 11 - Winding path
// Solution (8 moves): RIGHT -> UP -> LEFT -> DOWN -> LEFT -> UP -> RIGHT -> UP
add(levels, [
    "#########",
    "#...#...#",
    "#..P....#",
    "#R.R....#",
    "#R.G....#",
    "#...R..##",
    "#.......#",
    "#########"
])

// Level 12 - Tricky corners
// Solution (7 moves): LEFT -> DOWN -> RIGHT -> DOWN -> LEFT -> UP -> RIGHT
add(levels, [
    "#########",
    "#......P#",
    "#......R#",
    "#.......#",
    "#R..R...#",
    "#.GR....#",
    "#.......#",
    "#########"
])

// Level 13 - Rock maze
// Solution (8 moves): RIGHT -> DOWN -> LEFT -> UP -> LEFT -> DOWN -> RIGHT -> DOWN
add(levels, [
    "##########",
    "#R.......#",
    "#......R.#",
    "##R.....##",
    "#P.......#",
    "#.R......#",
    "#.....G.R#",
    "##########"
])

// Level 14 - Complex navigation
// Solution (8 moves): LEFT -> UP -> RIGHT -> DOWN -> RIGHT -> DOWN -> LEFT -> UP
add(levels, [
    "##########",
    "#........#",
    "#........#",
    "#..R.....#",
    "#R.R....R#",
    "#......#.#",
    "#...#..G.#",
    "#...P.R..#",
    "##########"
])

// Level 15 - Grand finale
// Solution (8 moves): DOWN -> LEFT -> UP -> LEFT -> DOWN -> RIGHT -> UP -> LEFT
add(levels, [
    "###########",
    "#G...R....#",
    "#...R.....#",
    "#.........#",
    "#.........#",
    "#R..RP....#",
    "#.........#",
    "#..R....R.#",
    "###########"
])

levelCount = len(levels)

// =============================================================
// Main Program
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Ring 3D Ice Sliding Puzzle - RingRayLib")
SetTargetFPS(60)

camera = Camera3D(
    0, 15, 12,
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

    // Restart level
    if IsKeyPressed(KEY_R)
        solverActive = false
        solverPath = []
        solverStep = 0
        ice_loadLevel(currentLevel)
        gameState = ST_PLAYING
    ok

    // ========== STATE UPDATES ==========

    if gameState = ST_START
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(0)
            ice_loadLevel(1)
            gameState = ST_PLAYING
        ok
    ok

    if gameState = ST_PLAYING
        // Auto-solver playback
        if solverActive
            solverDelay -= dt
            if solverDelay <= 0
                if solverStep <= len(solverPath)
                    dir = solverPath[solverStep]
                    ice_trySlide(dir[1], dir[2])
                    solverStep += 1
                    solverDelay = SOLVER_WAIT
                else
                    solverActive = false
                    ice_showMsg("Auto-solve done!")
                ok
            ok
        else
            ice_updateMouseHover()
            ice_handleInput()
            ice_handleMouse()
        ok
        ice_updateParticles(dt)
    ok

    if gameState = ST_SLIDING
        ice_updateSlideAnim(dt)
        ice_updateParticles(dt)
    ok

    if gameState = ST_WON
        ice_updateParticles(dt)
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsKeyPressed(KEY_N)
            if currentLevel < levelCount
                ice_loadLevel(currentLevel + 1)
                gameState = ST_PLAYING
            else
                gameState = ST_ALLCLEAR
            ok
        ok
    ok

    if gameState = ST_ALLCLEAR
        ice_updateParticles(dt)
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            currentLevel = 1
            ice_loadLevel(1)
            gameState = ST_PLAYING
        ok
    ok

    ice_positionCamera()

    // ========== DRAWING ==========

    BeginDrawing()
        ClearBackground(RAYLIBColor(10, 12, 20, 255))

        if gameState = ST_START
            ice_drawTitleScreen()
        else
            BeginMode3D(camera)
                ice_drawFloor3D()
                ice_drawWalls3D()
                ice_drawRocks3D()
                ice_drawGoal3D()
                ice_drawTrail3D()
                ice_drawPlayer3D()
                ice_drawParticles3D()
            EndMode3D()

            ice_drawHUD()
            ice_drawMiniMap()

            if gameState = ST_WON
                ice_drawWinOverlay()
            ok
            if gameState = ST_ALLCLEAR
                ice_drawAllClearOverlay()
            ok
            if msgTimer > 0
                ice_drawMessage()
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
// Level Loading
// =============================================================

func ice_loadLevel num
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

    playerR = 1
    playerC = 1
    goalR = 1
    goalC = 1

    for r = 1 to gridRows
        row = lvl[r]
        for c = 1 to len(row)
            ch = substr(row, c, 1)

            if ch = "#"
                grid[r][c] = TILE_WALL
            ok
            if ch = "."
                grid[r][c] = TILE_ICE
            ok
            if ch = "R"
                grid[r][c] = TILE_ROCK
            ok
            if ch = "G"
                grid[r][c] = TILE_GOAL
                goalR = r
                goalC = c
            ok
            if ch = "P"
                grid[r][c] = TILE_START
                playerR = r
                playerC = c
            ok
            if ch = " "
                grid[r][c] = TILE_EMPTY
            ok
        next
    next

    undoStack = []
    moveCount = 0
    animActive = false
    animTimer = 0.0
    pendingWin = false
    particles = []
    slideTrail = []
    msgTimer = 0
    playerFaceR = 0
    playerFaceC = 1

// =============================================================
// Input
// =============================================================

func ice_handleInput
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
        ice_undo()
        return
    ok

    // Auto-solve
    if IsKeyPressed(KEY_H)
        ice_startSolver()
        return
    ok

    if IsKeyPressed(KEY_N)
        if currentLevel < maxUnlocked
            ice_loadLevel(currentLevel + 1)
            gameState = ST_PLAYING
        ok
        return
    ok
    if IsKeyPressed(KEY_B)
        if currentLevel > 1
            ice_loadLevel(currentLevel - 1)
            gameState = ST_PLAYING
        ok
        return
    ok

    if dr = 0 and dc = 0 return ok

    ice_trySlide(dr, dc)

// =============================================================
// Mouse Handling
// =============================================================

func ice_updateMouseHover
    mx = GetMouseX()
    my = GetMouseY()

    // Project player position
    px = ice_cellToX(playerC)
    pz = ice_cellToZ(playerR)
    ice_projectToScreen(px, 0.5, pz)

    // Determine direction from player center to click
    mouseHoverR = 0
    mouseHoverC = 0

func ice_handleMouse
    if IsMouseButtonPressed(0)
        mx = GetMouseX()
        my = GetMouseY()

        // Project player position
        px = ice_cellToX(playerC)
        pz = ice_cellToZ(playerR)
        ice_projectToScreen(px, 0.5, pz)
        psx = projScreenX
        psy = projScreenY

        dx = mx - psx
        dy = my - psy

        // Minimum distance to count as directional click
        if dx * dx + dy * dy < 400 return ok

        // Determine dominant direction
        if dx > 0 and dx > dy and dx > (0 - dy)
            // Right
            ice_trySlide(0, 1)
        but dx < 0 and (0 - dx) > dy and (0 - dx) > (0 - dy)
            // Left
            ice_trySlide(0, -1)
        but dy < 0 and (0 - dy) > dx and (0 - dy) > (0 - dx)
            // Up (screen up = negative Z in front view)
            ice_trySlide(-1, 0)
        else
            // Down
            ice_trySlide(1, 0)
        ok
    ok

// =============================================================
// Slide Logic (core mechanic)
// =============================================================

func ice_trySlide dr, dc
    playerFaceR = dr
    playerFaceC = dc

    // Calculate slide destination
    sr = playerR
    sc = playerC
    slideTrail = []

    stepCount = 0
    while true
        nr = sr + dr
        nc = sc + dc

        // Check bounds
        if nr < 1 or nr > gridRows or nc < 1 or nc > gridCols
            // Hit boundary
            nr = sr
            nc = sc
            // stop
            nr = -1
        ok

        if nr = -1
            // Stopped at boundary
            nr = sr
            nc = sc
        else
            // Check what's ahead
            tile = grid[nr][nc]
            if tile = TILE_WALL or tile = TILE_ROCK or tile = TILE_EMPTY
                // Stop before this cell
                nr = sr
                nc = sc
            else
                // Can continue sliding
                sr = nr
                sc = nc
                add(slideTrail, [sr, sc])
                stepCount += 1
                loop
            ok
        ok

        // Reached final position
        if sr = playerR and sc = playerC
            // Didn't move at all
            return
        ok

        // Save undo and start animation
        add(undoStack, [playerR, playerC])
        if len(undoStack) > 300
            del(undoStack, 1)
        ok

        animFromR = playerR
        animFromC = playerC
        animToR = sr
        animToC = sc
        distR = animToR - animFromR
        if distR < 0 distR = 0 - distR ok
        distC = animToC - animFromC
        if distC < 0 distC = 0 - distC ok
        animTotalDist = distR + distC
        if animTotalDist < 1 animTotalDist = 1 ok

        playerR = sr
        playerC = sc
        moveCount += 1

        animActive = true
        animTimer = 0.0

        // Check if reached goal
        if playerR = goalR and playerC = goalC
            pendingWin = true
        ok

        gameState = ST_SLIDING

        // Spawn trail particles
        wx = ice_cellToX(playerC)
        wz = ice_cellToZ(playerR)
        ice_spawnSlideParticles(wx, wz)
        return
    end

// =============================================================
// Slide Animation
// =============================================================

func ice_updateSlideAnim dt
    speed = ANIM_SPEED
    animTimer += dt * speed / animTotalDist

    if animTimer >= 1.0
        animTimer = 1.0
        animActive = false
        slideTrail = []

        if pendingWin
            pendingWin = false
            gameState = ST_WON
            ice_spawnWinParticles()
            ice_showMsg("Level Complete!")
        else
            gameState = ST_PLAYING
        ok
    ok

// =============================================================
// Undo
// =============================================================

func ice_undo
    if len(undoStack) = 0
        ice_showMsg("Nothing to undo!")
        return
    ok

    prev = undoStack[len(undoStack)]
    del(undoStack, len(undoStack))

    playerR = prev[1]
    playerC = prev[2]
    moveCount -= 1
    if moveCount < 0 moveCount = 0 ok
    slideTrail = []
    ice_showMsg("Move undone")

// =============================================================
// Auto-Solver (BFS shortest path)
// =============================================================

func ice_startSolver
    // Reset to start of level first
    ice_loadLevel(currentLevel)
    gameState = ST_PLAYING

    ice_showMsg("Solving...")

    // BFS: state = [r, c], find path from start to goal
    // Each move slides until hitting wall/rock
    dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]]

    // Visited: encode state as (r-1)*gridCols + c
    maxStates = gridRows * gridCols + 1
    visited = list(maxStates)
    parentState = list(maxStates)
    parentDir = list(maxStates)
    for i = 1 to maxStates
        visited[i] = false
        parentState[i] = 0
        parentDir[i] = 0
    next

    startKey = (playerR - 1) * gridCols + playerC
    goalKey = (goalR - 1) * gridCols + goalC
    visited[startKey] = true
    parentState[startKey] = -1
    parentDir[startKey] = 0

    queue = []
    add(queue, [playerR, playerC])
    head = 1
    found = false

    while head <= len(queue)
        cr = queue[head][1]
        cc = queue[head][2]
        head += 1
        curKey = (cr - 1) * gridCols + cc

        if curKey = goalKey
            found = true
            head = len(queue) + 1
            loop
        ok

        for di = 1 to 4
            dr = dirs[di][1]
            dc = dirs[di][2]

            // Simulate slide from cr, cc in direction dr, dc
            sr = cr
            sc = cc
            sliding = true
            while sliding
                nr = sr + dr
                nc = sc + dc
                if nr < 1 or nr > gridRows or nc < 1 or nc > gridCols
                    sliding = false
                else
                    tile = grid[nr][nc]
                    if tile = TILE_WALL or tile = TILE_ROCK or tile = TILE_EMPTY
                        sliding = false
                    else
                        sr = nr
                        sc = nc
                    ok
                ok
            end

            // sr, sc is where we'd end up
            if sr = cr and sc = cc loop ok

            nKey = (sr - 1) * gridCols + sc
            if nKey >= 1 and nKey <= maxStates
                if visited[nKey] = false
                    visited[nKey] = true
                    parentState[nKey] = curKey
                    parentDir[nKey] = di
                    add(queue, [sr, sc])
                ok
            ok
        next
    end

    if found = false
        ice_showMsg("No solution found!")
        return
    ok

    // Trace back from goal to build direction list
    path = []
    curKey = goalKey
    safeCount = 0
    while curKey != startKey and safeCount < maxStates
        safeCount += 1
        di = parentDir[curKey]
        if di >= 1 and di <= 4
            add(path, [dirs[di][1], dirs[di][2]])
        ok
        curKey = parentState[curKey]
        if curKey = -1 curKey = startKey ok
    end

    // Reverse path (we traced backward)
    solverPath = []
    for i = len(path) to 1 step -1
        add(solverPath, path[i])
    next

    solverStep = 1
    solverActive = true
    solverDelay = 0.3
    ice_showMsg("Solving in " + len(solverPath) + " moves...")

// =============================================================
// Particles
// =============================================================

func ice_spawnSlideParticles wx, wz
    for i = 1 to 8
        vx = (GetRandomValue(-100, 100) / 100.0)
        vy = (GetRandomValue(100, 350) / 100.0)
        vz = (GetRandomValue(-100, 100) / 100.0)
        cb = GetRandomValue(200, 255)
        cg = GetRandomValue(220, 255)
        add(particles, [wx, 0.3, wz, vx, vy, vz, 0.8, 200, cg, cb])
    next

func ice_spawnWinParticles
    for i = 1 to 60
        wx = ice_cellToX(goalC) + (GetRandomValue(-200, 200) / 100.0)
        wz = ice_cellToZ(goalR) + (GetRandomValue(-200, 200) / 100.0)
        vx = (GetRandomValue(-200, 200) / 100.0)
        vy = (GetRandomValue(400, 800) / 100.0)
        vz = (GetRandomValue(-200, 200) / 100.0)
        cr = GetRandomValue(50, 150)
        cg = GetRandomValue(200, 255)
        cb = GetRandomValue(50, 150)
        add(particles, [wx, 0.5, wz, vx, vy, vz, 2.0, cr, cg, cb])
    next

func ice_updateParticles dt
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

func ice_drawParticles3D
    for i = 1 to len(particles)
        p = particles[i]
        alpha = floor((p[7] / 2.0) * 255)
        if alpha > 255 alpha = 255 ok
        if alpha < 0 alpha = 0 ok
        sz = 0.03 + p[7] * 0.04
        DrawSphereEx(
            Vector3(p[1], p[2], p[3]),
            sz, 4, 4,
            RAYLIBColor(p[8], p[9], p[10], alpha)
        )
    next

// =============================================================
// Helpers
// =============================================================

func ice_cellToX c
    return (c - 1) * CELL_SZ - (gridCols - 1) * CELL_SZ / 2

func ice_cellToZ r
    return (r - 1) * CELL_SZ - (gridRows - 1) * CELL_SZ / 2

func ice_showMsg text
    msgText = text
    msgTimer = 1.8

// =============================================================
// Projection
// =============================================================

func ice_projectToScreen wx, wy, wz
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

func ice_positionCamera
    maxDim = gridRows * CELL_SZ
    if gridCols * CELL_SZ > maxDim maxDim = gridCols * CELL_SZ ok

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
        goalX = maxDim * 0.6 + 2.0
        goalY = maxDim * 0.8 + 3.0
        goalZ = maxDim * 0.6 + 2.0
        tgtX = 0
        tgtY = 0.3
        tgtZ = 0
    ok
    if cameraMode = CAM_OVERHEAD
        goalX = 0
        goalY = maxDim * 1.2 + 5.0
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
// 3D Drawing: Floor
// =============================================================

func ice_drawFloor3D
    // Table
    DrawPlane(Vector3(0, -0.01, 0), Vector2(40, 40),
              RAYLIBColor(6, 8, 14, 255))

    for r = 1 to gridRows
        for c = 1 to gridCols
            tile = grid[r][c]
            if tile = TILE_EMPTY loop ok
            if tile = TILE_WALL loop ok

            wx = ice_cellToX(c)
            wz = ice_cellToZ(r)
            tileSz = CELL_SZ * 0.97

            if tile = TILE_ICE or tile = TILE_START
                // Ice tile - light blue with frost sheen
                even = ((r + c) % 2)
                if even = 0
                    iceCol = RAYLIBColor(140, 180, 210, 255)
                else
                    iceCol = RAYLIBColor(150, 190, 220, 255)
                ok
                DrawCube(Vector3(wx, 0.02, wz), tileSz, 0.04, tileSz, iceCol)
                DrawCubeWires(Vector3(wx, 0.02, wz), tileSz, 0.04, tileSz,
                              RAYLIBColor(100, 140, 170, 120))

                // Frost shimmer
                shimmer = 0.3 + sin(animTime * 1.5 + r * 0.9 + c * 1.1) * 0.3
                sAlpha = floor(30 * shimmer)
                DrawCube(Vector3(wx, 0.05, wz), tileSz * 0.7, 0.01, tileSz * 0.7,
                         RAYLIBColor(200, 230, 255, sAlpha))
            ok

            if tile = TILE_START
                // Start highlight
                pulse = 0.5 + sin(animTime * 3.0) * 0.5
                sAlpha2 = floor(40 * pulse)
                DrawCube(Vector3(wx, 0.06, wz), tileSz, 0.03, tileSz,
                         RAYLIBColor(80, 150, 255, sAlpha2))
            ok

            if tile = TILE_GOAL
                // Goal tile - green glow
                goalPulse = 0.5 + sin(animTime * 4.0) * 0.5
                gAlpha = floor(180 + 75 * goalPulse)
                DrawCube(Vector3(wx, 0.02, wz), tileSz, 0.04, tileSz,
                         RAYLIBColor(40, floor(180 * goalPulse) + 75, 60, gAlpha))
                DrawCubeWires(Vector3(wx, 0.02, wz), tileSz, 0.04, tileSz,
                              RAYLIBColor(60, 200, 80, 160))
            ok

            if tile = TILE_ROCK
                // Rock sits on ice floor
                DrawCube(Vector3(wx, 0.02, wz), tileSz, 0.04, tileSz,
                         RAYLIBColor(140, 180, 210, 255))
            ok
        next
    next

// =============================================================
// 3D Drawing: Walls
// =============================================================

func ice_drawWalls3D
    for r = 1 to gridRows
        for c = 1 to gridCols
            if grid[r][c] != TILE_WALL loop ok

            wx = ice_cellToX(c)
            wz = ice_cellToZ(r)
            wSz = CELL_SZ * 0.98

            DrawCube(Vector3(wx, WALL_HEIGHT/2, wz),
                     wSz, WALL_HEIGHT, wSz,
                     RAYLIBColor(45, 50, 65, 255))
            DrawCubeWires(Vector3(wx, WALL_HEIGHT/2, wz),
                          wSz, WALL_HEIGHT, wSz,
                          RAYLIBColor(30, 35, 45, 200))

            // Top cap
            DrawCube(Vector3(wx, WALL_HEIGHT + 0.02, wz),
                     wSz, 0.04, wSz,
                     RAYLIBColor(55, 60, 75, 255))

            // Frost on top
            DrawCube(Vector3(wx, WALL_HEIGHT + 0.05, wz),
                     wSz * 0.8, 0.02, wSz * 0.8,
                     RAYLIBColor(180, 200, 220, 80))
        next
    next

// =============================================================
// 3D Drawing: Rocks
// =============================================================

func ice_drawRocks3D
    for r = 1 to gridRows
        for c = 1 to gridCols
            if grid[r][c] != TILE_ROCK loop ok

            wx = ice_cellToX(c)
            wz = ice_cellToZ(r)
            rockR = CELL_SZ * 0.38
            rockH = CELL_SZ * 0.6

            // Main boulder (sphere + cube composite)
            DrawSphere(Vector3(wx, rockH * 0.5, wz), rockR,
                       RAYLIBColor(120, 100, 80, 255))
            DrawSphereWires(Vector3(wx, rockH * 0.5, wz), rockR, 6, 6,
                            RAYLIBColor(80, 65, 50, 180))

            // Base
            DrawCylinder(Vector3(wx, 0, wz), rockR * 1.1, rockR * 0.8, rockH * 0.3, 8,
                         RAYLIBColor(100, 85, 65, 255))

            // Snow cap
            DrawSphere(Vector3(wx, rockH * 0.65, wz), rockR * 0.5,
                       RAYLIBColor(220, 230, 240, 150))
        next
    next

// =============================================================
// 3D Drawing: Goal
// =============================================================

func ice_drawGoal3D
    wx = ice_cellToX(goalC)
    wz = ice_cellToZ(goalR)

    pulse = 0.5 + sin(animTime * 4.0) * 0.5

    // Beacon column
    beaconH = 1.5 + pulse * 0.3
    bAlpha = floor(80 + 60 * pulse)
    DrawCylinder(Vector3(wx, 0, wz), CELL_SZ * 0.15, CELL_SZ * 0.08, beaconH, 6,
                 RAYLIBColor(60, 220, 80, bAlpha))

    // Top orb
    orbY = beaconH + 0.15
    DrawSphere(Vector3(wx, orbY, wz), CELL_SZ * 0.12,
               RAYLIBColor(100, 255, 120, floor(180 + 75 * pulse)))

    // Glow rings
    for ring = 1 to 3
        ringR = CELL_SZ * 0.2 * ring
        ringAlpha = floor(40 * pulse / ring)
        DrawCylinderWires(Vector3(wx, 0.08, wz), ringR, ringR, 0.02, 12,
                          RAYLIBColor(80, 255, 100, ringAlpha))
    next

// =============================================================
// 3D Drawing: Trail (ghost path)
// =============================================================

func ice_drawTrail3D
    if len(slideTrail) = 0 return ok

    for i = 1 to len(slideTrail)
        tr = slideTrail[i][1]
        tc = slideTrail[i][2]
        wx = ice_cellToX(tc)
        wz = ice_cellToZ(tr)

        fade = (i * 1.0) / len(slideTrail)
        tAlpha = floor(30 + 40 * fade)
        DrawCube(Vector3(wx, 0.06, wz), CELL_SZ * 0.6, 0.02, CELL_SZ * 0.6,
                 RAYLIBColor(100, 180, 255, tAlpha))
    next

// =============================================================
// 3D Drawing: Player
// =============================================================

func ice_drawPlayer3D
    // Calculate animated position
    wx = ice_cellToX(playerC)
    wz = ice_cellToZ(playerR)

    if gameState = ST_SLIDING and animActive
        t = animTimer
        if t > 1.0 t = 1.0 ok
        smooth = t * t * (3.0 - 2.0 * t)

        fromX = ice_cellToX(animFromC)
        fromZ = ice_cellToZ(animFromR)
        toX = ice_cellToX(animToC)
        toZ = ice_cellToZ(animToR)

        wx = fromX + (toX - fromX) * smooth
        wz = fromZ + (toZ - fromZ) * smooth
    ok

    pSize = CELL_SZ * 0.35
    pHeight = CELL_SZ * 0.4

    // Player body (ice crystal block)
    DrawCube(Vector3(wx, pHeight/2 + 0.05, wz),
             pSize, pHeight, pSize,
             RAYLIBColor(60, 140, 220, 255))
    DrawCubeWires(Vector3(wx, pHeight/2 + 0.05, wz),
                  pSize, pHeight, pSize,
                  RAYLIBColor(40, 100, 180, 200))

    // Top diamond
    dSz = pSize * 0.5
    DrawCube(Vector3(wx, pHeight + 0.1, wz),
             dSz, dSz * 0.8, dSz,
             RAYLIBColor(100, 180, 255, 230))

    // Direction indicator (small arrow)
    arrowX = wx + playerFaceC * pSize * 0.7
    arrowZ = wz + playerFaceR * pSize * 0.7
    DrawSphere(Vector3(arrowX, pHeight/2 + 0.05, arrowZ),
               pSize * 0.15, RAYLIBColor(180, 220, 255, 180))

    // Idle bob
    bob = sin(animTime * 2.5) * 0.03
    // Glow
    glowPulse = 0.5 + sin(animTime * 3.0) * 0.5
    gAlpha = floor(25 * glowPulse)
    glowSz = pSize * 1.4
    DrawCube(Vector3(wx, pHeight/2 + 0.05 + bob, wz),
             glowSz, pHeight + 0.2, glowSz,
             RAYLIBColor(100, 180, 255, gAlpha))

// =============================================================
// HUD
// =============================================================

func ice_drawHUD
    panelW = 240
    panelH = 135
    DrawRectangle(10, 30, panelW, panelH, Fade(BLACK, 0.75))
    DrawRectangleLines(10, 30, panelW, panelH, RAYLIBColor(100, 180, 220, 200))

    DrawText("ICE SLIDING", 20, 38, 20, RAYLIBColor(140, 200, 255, 255))

    lStr = "Level: " + currentLevel + " / " + levelCount
    DrawText(lStr, 20, 64, 14, RAYLIBColor(160, 180, 200, 200))

    DrawText("Moves: " + moveCount, 20, 82, 18,
             RAYLIBColor(255, 255, 255, 240))

    // Grid size
    DrawText("Grid: " + gridRows + "x" + gridCols, 20, 104, 13,
             RAYLIBColor(140, 160, 180, 200))

    // Level progress bar
    barX = 20
    barY = 122
    barW = 210
    barH = 10
    DrawRectangle(barX, barY, barW, barH, RAYLIBColor(40, 40, 60, 200))
    if levelCount > 0
        fillW = floor(barW * maxUnlocked / levelCount)
        if fillW > 0
            DrawRectangle(barX, barY, fillW, barH,
                          RAYLIBColor(80, 180, 255, 220))
        ok
    ok
    DrawRectangleLines(barX, barY, barW, barH,
                       RAYLIBColor(80, 120, 150, 180))
    DrawText("" + maxUnlocked + "/" + levelCount + " unlocked", barX + barW + 4, barY - 1, 10,
             RAYLIBColor(120, 160, 190, 180))

    // Unlock hint
    DrawText("Unlocked: " + maxUnlocked + "/" + levelCount, 20, 140, 11,
             RAYLIBColor(100, 150, 180, 160))

    // Camera
    camName = "FRONT"
    if cameraMode = CAM_ISOMETRIC camName = "ISOMETRIC" ok
    if cameraMode = CAM_OVERHEAD  camName = "OVERHEAD"  ok
    DrawRectangle(10, SCREEN_H - 60, 220, 25, Fade(BLACK, 0.6))
    DrawText("Cam: " + camName + "  [C] switch", 16, SCREEN_H - 56, 14,
             RAYLIBColor(150, 180, 210, 220))

    // Controls
    DrawRectangle(SCREEN_W - 600, SCREEN_H - 35, 590, 25, Fade(BLACK, 0.6))
    DrawText("Arrows: Slide | U: Undo | H: Auto-Solve | R: Restart | N/B: Next/Prev",
             SCREEN_W - 596, SCREEN_H - 30, 12, RAYLIBColor(150, 160, 180, 200))

    // Solver indicator
    if solverActive
        solPulse = floor(180 + sin(animTime * 5.0) * 75)
        DrawRectangle(10, SCREEN_H - 90, 150, 22, Fade(BLACK, 0.7))
        DrawText("AUTO-SOLVING...", 16, SCREEN_H - 86, 14,
                 RAYLIBColor(100, 255, 150, solPulse))
    ok

// =============================================================
// Mini Map
// =============================================================

func ice_drawMiniMap
    cellW = 10
    if gridCols >= 10 cellW = 8 ok
    if gridCols >= 12 cellW = 7 ok
    mapW = gridCols * cellW + 4
    mapH = gridRows * cellW + 4
    mapX = SCREEN_W - mapW - 15
    mapY = 30

    DrawRectangle(mapX - 3, mapY - 3, mapW + 6, mapH + 6, Fade(BLACK, 0.8))
    DrawRectangleLines(mapX - 3, mapY - 3, mapW + 6, mapH + 6,
                       RAYLIBColor(100, 180, 220, 200))

    DrawRectangle(mapX, mapY, mapW, mapH, RAYLIBColor(15, 18, 25, 230))

    for r = 1 to gridRows
        for c = 1 to gridCols
            tx = mapX + 2 + (c - 1) * cellW
            ty = mapY + 2 + (r - 1) * cellW
            tw = cellW - 1
            th = cellW - 1
            tile = grid[r][c]

            if tile = TILE_WALL
                DrawRectangle(tx, ty, tw, th, RAYLIBColor(45, 50, 65, 255))
            ok
            if tile = TILE_ICE or tile = TILE_START
                DrawRectangle(tx, ty, tw, th, RAYLIBColor(140, 180, 210, 200))
            ok
            if tile = TILE_ROCK
                DrawRectangle(tx, ty, tw, th, RAYLIBColor(120, 100, 80, 255))
            ok
            if tile = TILE_GOAL
                pulse = 0.5 + sin(animTime * 4.0) * 0.5
                DrawRectangle(tx, ty, tw, th,
                              RAYLIBColor(60, floor(200 * pulse) + 55, 80, 255))
            ok
            if tile = TILE_EMPTY
                DrawRectangle(tx, ty, tw, th, RAYLIBColor(10, 12, 18, 150))
            ok
        next
    next

    // Trail
    for i = 1 to len(slideTrail)
        tr = slideTrail[i][1]
        tc = slideTrail[i][2]
        ttx = mapX + 2 + (tc - 1) * cellW
        tty = mapY + 2 + (tr - 1) * cellW
        DrawRectangle(ttx, tty, cellW - 1, cellW - 1,
                      RAYLIBColor(100, 180, 255, 60))
    next

    // Player
    pxm = mapX + 2 + (playerC - 1) * cellW
    pym = mapY + 2 + (playerR - 1) * cellW
    DrawRectangle(pxm, pym, cellW - 1, cellW - 1,
                  RAYLIBColor(60, 140, 220, 255))
    DrawRectangleLines(pxm, pym, cellW - 1, cellW - 1,
                       RAYLIBColor(255, 255, 255, 220))

    // Goal
    gxm = mapX + 2 + (goalC - 1) * cellW
    gym = mapY + 2 + (goalR - 1) * cellW
    DrawRectangleLines(gxm - 1, gym - 1, cellW + 1, cellW + 1,
                       RAYLIBColor(80, 255, 100, 200))

    DrawText("MAP", mapX + mapW/2 - 15, mapY - 16, 12,
             RAYLIBColor(100, 180, 220, 200))

// =============================================================
// Title Screen
// =============================================================

func ice_drawTitleScreen
    DrawRectangleGradientV(0, 0, SCREEN_W, SCREEN_H,
        RAYLIBColor(8, 12, 22, 255), RAYLIBColor(14, 18, 30, 255))

    // Snow particles background
    for i = 0 to 30
        sx = ((floor(animTime * 20 + i * 37) % SCREEN_W) + SCREEN_W) % SCREEN_W
        sy = ((floor(animTime * 40 + i * 53) % SCREEN_H) + SCREEN_H) % SCREEN_H
        DrawCircle(sx, sy, 2, RAYLIBColor(200, 220, 240, 60))
    next

    t1 = "ICE SLIDING PUZZLE"
    t1w = MeasureText(t1, 48)
    DrawText(t1, (SCREEN_W - t1w)/2, 30, 48, RAYLIBColor(140, 200, 255, 255))

    t1b = "3D EDITION"
    t1bw = MeasureText(t1b, 20)
    DrawText(t1b, (SCREEN_W - t1bw)/2, 85, 20, RAYLIBColor(180, 220, 255, 230))

    t2 = "~ Slide Across Ice to Reach the Goal ~"
    t2w = MeasureText(t2, 16)
    DrawText(t2, (SCREEN_W - t2w)/2, 115, 16, RAYLIBColor(160, 190, 220, 230))

    ly = 140
    DrawLine(180, ly, SCREEN_W - 180, ly, RAYLIBColor(100, 180, 220, 180))

    // Demo grid
    demoGrid = [
        "######",
        "#P.R.#",
        "#....#",
        "#.R.G#",
        "######"
    ]
    dCellW = 20
    dStartX = (SCREEN_W - 6 * dCellW) / 2
    dStartY = 155
    for dr = 1 to 5
        for dc = 1 to 6
            dx2 = dStartX + (dc - 1) * dCellW
            dy2 = dStartY + (dr - 1) * dCellW
            ch = substr(demoGrid[dr], dc, 1)
            if ch = "#"
                DrawRectangle(dx2, dy2, dCellW - 2, dCellW - 2,
                              RAYLIBColor(45, 50, 65, 255))
            ok
            if ch = "."
                DrawRectangle(dx2, dy2, dCellW - 2, dCellW - 2,
                              RAYLIBColor(140, 180, 210, 200))
            ok
            if ch = "R"
                DrawRectangle(dx2, dy2, dCellW - 2, dCellW - 2,
                              RAYLIBColor(140, 180, 210, 200))
                DrawCircle(dx2 + dCellW/2 - 1, dy2 + dCellW/2 - 1, 5,
                           RAYLIBColor(120, 100, 80, 255))
            ok
            if ch = "G"
                pulse = 0.5 + sin(animTime * 4.0) * 0.5
                DrawRectangle(dx2, dy2, dCellW - 2, dCellW - 2,
                              RAYLIBColor(40, floor(180 * pulse) + 75, 60, 220))
            ok
            if ch = "P"
                DrawRectangle(dx2, dy2, dCellW - 2, dCellW - 2,
                              RAYLIBColor(140, 180, 210, 200))
                DrawRectangle(dx2 + 4, dy2 + 4, dCellW - 10, dCellW - 10,
                              RAYLIBColor(60, 140, 220, 255))
            ok
            DrawRectangleLines(dx2, dy2, dCellW - 2, dCellW - 2,
                               RAYLIBColor(60, 80, 100, 80))
        next
    next

    cy = 270
    cLines = [
        "Arrow Keys / WASD     -   Slide in direction (can't stop!)",
        "Mouse Click           -   Click near player to set direction",
        "U / Backspace         -   Undo last slide",
        "H                     -   Auto-Solve (BFS optimal path)",
        "R                     -   Restart current level",
        "N / B                 -   Next / Previous level",
        "C                     -   Cycle camera view",
        "",
        "Tiles:",
        "  Ice (light blue)  - Slide freely across",
        "  Wall (dark)       - Boundary blocks, stops you",
        "  Rock (brown)      - Mid-ice obstacle, stops you",
        "  Goal (green glow) - Reach this to win!",
        "",
        "Rules:",
        "  On ice, you slide in one direction until hitting",
        "  a wall or rock. Plan your path to reach the goal!",
        "  Try to solve each level in the fewest moves.",
        "",
        "15 hand-crafted puzzle levels from easy to expert!"
    ]
    for i = 1 to len(cLines)
        lw = MeasureText(cLines[i], 13)
        if i >= 8
            col = RAYLIBColor(180, 220, 255, 210)
        else
            col = RAYLIBColor(160, 175, 200, 230)
        ok
        DrawText(cLines[i], (SCREEN_W - lw)/2, cy + (i - 1) * 19, 13, col)
    next

    if floor(animTime * 2) % 2 = 0
        st2 = "Click or Press ENTER / SPACE to Start"
        st2w = MeasureText(st2, 22)
        DrawText(st2, (SCREEN_W - st2w)/2, 650, 22, WHITE)
    ok

    cr = "Developed using Ring Language + RingRayLib"
    crw = MeasureText(cr, 14)
    DrawText(cr, (SCREEN_W - crw)/2, SCREEN_H - 25, 14,
             RAYLIBColor(80, 100, 80, 180))

// =============================================================
// Win Overlay
// =============================================================

func ice_drawWinOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.5))

    g1 = "LEVEL COMPLETE!"
    g1w = MeasureText(g1, 44)
    pulse = floor(220 + sin(animTime * 3.0) * 35)
    DrawText(g1, (SCREEN_W - g1w)/2, 180, 44,
             RAYLIBColor(80, 255, 120, pulse))

    g2 = "Level " + currentLevel + " cleared in " + moveCount + " moves!"
    g2w = MeasureText(g2, 20)
    DrawText(g2, (SCREEN_W - g2w)/2, 240, 20, RAYLIBColor(200, 230, 255, 220))

    if currentLevel < levelCount
        if floor(animTime * 2) % 2 = 0
            nt = "Press ENTER or N for next level"
            ntw = MeasureText(nt, 18)
            DrawText(nt, (SCREEN_W - ntw)/2, 290, 18, WHITE)
        ok
    else
        at = "All 15 levels complete! Press ENTER..."
        atw = MeasureText(at, 18)
        DrawText(at, (SCREEN_W - atw)/2, 290, 18,
                 RAYLIBColor(255, 220, 80, 255))
    ok

// =============================================================
// All Clear Overlay
// =============================================================

func ice_drawAllClearOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.6))

    g1 = "ALL LEVELS COMPLETE!"
    g1w = MeasureText(g1, 48)
    pulse = floor(220 + sin(animTime * 3.0) * 35)
    DrawText(g1, (SCREEN_W - g1w)/2, 180, 48,
             RAYLIBColor(255, 220, 80, pulse))

    g2 = "Master of the Ice! Congratulations!"
    g2w = MeasureText(g2, 22)
    DrawText(g2, (SCREEN_W - g2w)/2, 250, 22, RAYLIBColor(200, 255, 200, 230))

    if floor(animTime * 2) % 2 = 0
        rt = "Press ENTER to play again"
        rtw = MeasureText(rt, 18)
        DrawText(rt, (SCREEN_W - rtw)/2, 310, 18, WHITE)
    ok

// =============================================================
// Message Overlay
// =============================================================

func ice_drawMessage
    alpha = floor((msgTimer / 1.8) * 255)
    if alpha > 255 alpha = 255 ok
    if alpha < 0 alpha = 0 ok

    mw = MeasureText(msgText, 24)
    mx = (SCREEN_W - mw) / 2
    my = SCREEN_H / 2 + 150

    DrawRectangle(mx - 15, my - 8, mw + 30, 40,
                  RAYLIBColor(0, 0, 0, floor(alpha * 0.7)))
    DrawText(msgText, mx, my, 24,
             RAYLIBColor(140, 200, 255, alpha))
