/*
**  3D 2048 Game - Using RingRayLib
**  ==================================
**  Slide numbered tiles on a 4x4 grid. When two tiles
**  with the same number collide, they merge into one!
**  Reach the 2048 tile to win!
**
**  Controls:
**    Arrow Keys / WASD  - Slide tiles in that direction
**    U / Backspace      - Undo last move
**    R                  - Restart game
**    C                  - Cycle camera views
**    ESC                - Exit
**
**  Rules:
**    - Tiles slide as far as possible in the chosen direction
**    - When two tiles with the same value collide, they merge
**    - After each move a new 2 or 4 tile appears randomly
**    - Reach 2048 to win! (continue playing for higher scores)
**    - Game ends when no moves are possible
**
**  Features:
**    - 3D cubes with height proportional to tile value
**    - Smooth slide animation with ease-in-out
**    - Merge pop animation with particle burst
**    - Spawn animation (scale up from zero)
**    - Value-based color gradient (warm tones)
**    - Score and best score tracking
**    - Full undo system
**    - Three camera modes: Front / Isometric / Overhead
**    - Particle effects on merges
**    - Mini-map with colored tiles
**    - Win screen at 2048 with continue option
**    - Game over detection with retry
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W        = 1024
SCREEN_H        = 768
BOARD_SZ        = 4
CELL_SZ         = 2.8
TILE_GAP        = 0.2
TILE_SZ         = CELL_SZ - TILE_GAP

// Game states
ST_START        = 1
ST_PLAYING      = 2
ST_ANIMATING    = 3
ST_WON          = 4
ST_GAMEOVER     = 5

// Directions
DIR_UP          = 1
DIR_DOWN        = 2
DIR_LEFT        = 3
DIR_RIGHT       = 4

// Camera modes
CAM_FRONT       = 1
CAM_ISOMETRIC   = 2
CAM_OVERHEAD    = 3
CAM_COUNT       = 3

// Animation
ANIM_SPEED      = 7.0
SPAWN_SPEED     = 5.0

// =============================================================
// Global Variables
// =============================================================

board           = []        // board[r][c] = tile value (0=empty)
score           = 0
bestScore       = 0
moveCount       = 0
gameState       = ST_START
animTime        = 0.0
wonShown        = false     // only show win overlay once

// Undo: [boardCopy, scoreCopy]
undoStack       = []

// Slide animation data
slideAnims      = []        // [[fromR, fromC, toR, toC, value, progress], ...]
slideActive     = false
slideProgress   = 0.0

// After-slide state
pendingBoard    = []
pendingScore    = 0
pendingMerges   = []        // [[r, c], ...] cells that merged

// Merge pop animation
mergeAnims      = []        // [[r, c, progress], ...]

// Spawn animation
spawnAnims      = []        // [[r, c, progress], ...]

// Particles: [x, y, z, vx, vy, vz, life, cr, cg, cb]
particles       = []

// Camera
cameraMode      = CAM_FRONT
camPosX = 0.0   camPosY = 16.0  camPosZ = 14.0
camTgtX = 0.0   camTgtY = 0.0   camTgtZ = 0.0

// Message
msgText         = ""
msgTimer        = 0.0

// Projection helper
projScreenX     = 0.0
projScreenY     = 0.0

// =============================================================
// Initialize
// =============================================================

t48_initBoard()

// =============================================================
// Main Program
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Ring 3D 2048 - RingRayLib")
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

    // Restart
    if IsKeyPressed(KEY_R)
        t48_initBoard()
        gameState = ST_PLAYING
    ok

    // ========== STATE UPDATES ==========

    if gameState = ST_START
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(0)
            t48_initBoard()
            gameState = ST_PLAYING
        ok
    ok

    if gameState = ST_PLAYING
        t48_handleInput()
        t48_updateSpawnAnims(dt)
        t48_updateMergeAnims(dt)
        t48_updateParticles(dt)
    ok

    if gameState = ST_ANIMATING
        t48_updateSlideAnim(dt)
        t48_updateSpawnAnims(dt)
        t48_updateMergeAnims(dt)
        t48_updateParticles(dt)
    ok

    if gameState = ST_WON
        t48_updateSpawnAnims(dt)
        t48_updateMergeAnims(dt)
        t48_updateParticles(dt)
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(0)
            // Continue playing
            wonShown = true
            gameState = ST_PLAYING
        ok
        if IsKeyPressed(KEY_R)
            t48_initBoard()
            gameState = ST_PLAYING
        ok
    ok

    if gameState = ST_GAMEOVER
        t48_updateParticles(dt)
        if IsKeyPressed(KEY_R)
            t48_initBoard()
            gameState = ST_PLAYING
        ok
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            t48_initBoard()
            gameState = ST_START
        ok
    ok

    t48_positionCamera()

    // ========== DRAWING ==========

    BeginDrawing()
        ClearBackground(RAYLIBColor(20, 18, 28, 255))

        if gameState = ST_START
            t48_drawTitleScreen()
        else
            BeginMode3D(camera)
                t48_drawBoard3D()
                t48_drawTiles3D()
                t48_drawSlideAnims3D()
                t48_drawParticles3D()
            EndMode3D()

            t48_drawTileLabels()
            t48_drawHUD()
            t48_drawMiniMap()

            if gameState = ST_WON and wonShown = false
                t48_drawWonOverlay()
            ok
            if gameState = ST_GAMEOVER
                t48_drawGameOverOverlay()
            ok

            if msgTimer > 0
                t48_drawMessage()
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

func t48_initBoard
    board = list(BOARD_SZ)
    for r = 1 to BOARD_SZ
        board[r] = list(BOARD_SZ)
        for c = 1 to BOARD_SZ
            board[r][c] = 0
        next
    next
    score = 0
    moveCount = 0
    undoStack = []
    slideAnims = []
    mergeAnims = []
    spawnAnims = []
    particles = []
    slideActive = false
    slideProgress = 0.0
    wonShown = false
    msgTimer = 0
    pendingBoard = []
    pendingMerges = []

    // Spawn two initial tiles
    t48_spawnTile()
    t48_spawnTile()

// =============================================================
// Spawn Tile
// =============================================================

func t48_spawnTile
    // Find empty cells
    emptyCells = []
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if board[r][c] = 0
                add(emptyCells, [r, c])
            ok
        next
    next

    if len(emptyCells) = 0 return ok

    idx = GetRandomValue(1, len(emptyCells))
    r = emptyCells[idx][1]
    c = emptyCells[idx][2]

    // 90% chance of 2, 10% chance of 4
    if GetRandomValue(1, 10) = 1
        board[r][c] = 4
    else
        board[r][c] = 2
    ok

    // Spawn animation
    add(spawnAnims, [r, c, 0.0])

// =============================================================
// Input Handling
// =============================================================

func t48_handleInput
    moved = false

    if IsKeyPressed(KEY_UP) or IsKeyPressed(KEY_W)
        moved = t48_doMove(DIR_UP)
    ok
    if IsKeyPressed(KEY_DOWN) or IsKeyPressed(KEY_S)
        moved = t48_doMove(DIR_DOWN)
    ok
    if IsKeyPressed(KEY_LEFT) or IsKeyPressed(KEY_A)
        moved = t48_doMove(DIR_LEFT)
    ok
    if IsKeyPressed(KEY_RIGHT) or IsKeyPressed(KEY_D)
        moved = t48_doMove(DIR_RIGHT)
    ok

    // Undo
    if IsKeyPressed(KEY_U) or IsKeyPressed(KEY_BACKSPACE)
        t48_undo()
    ok

// =============================================================
// Move Logic
// =============================================================

func t48_doMove direction
    // Save undo state
    savedBoard = t48_copyBoard()
    savedScore = score

    // Build slide animations and compute result
    slideAnims = []
    pendingMerges = []

    // Work on a copy to compute final positions
    newBoard = list(BOARD_SZ)
    for r = 1 to BOARD_SZ
        newBoard[r] = list(BOARD_SZ)
        for c = 1 to BOARD_SZ
            newBoard[r][c] = 0
        next
    next

    mergeScore = 0

    if direction = DIR_LEFT
        for r = 1 to BOARD_SZ
            writePos = 1
            lastVal = 0
            lastWritePos = 0
            for c = 1 to BOARD_SZ
                val = board[r][c]
                if val = 0 loop ok
                if lastVal = val and lastWritePos > 0
                    // Merge
                    merged = val * 2
                    newBoard[r][lastWritePos] = merged
                    mergeScore += merged
                    add(slideAnims, [r, c, r, lastWritePos, val, 0.0])
                    add(pendingMerges, [r, lastWritePos])
                    lastVal = 0
                    lastWritePos = 0
                else
                    newBoard[r][writePos] = val
                    add(slideAnims, [r, c, r, writePos, val, 0.0])
                    lastVal = val
                    lastWritePos = writePos
                    writePos += 1
                ok
            next
        next
    ok

    if direction = DIR_RIGHT
        for r = 1 to BOARD_SZ
            writePos = BOARD_SZ
            lastVal = 0
            lastWritePos = 0
            for c = BOARD_SZ to 1 step -1
                val = board[r][c]
                if val = 0 loop ok
                if lastVal = val and lastWritePos > 0
                    merged = val * 2
                    newBoard[r][lastWritePos] = merged
                    mergeScore += merged
                    add(slideAnims, [r, c, r, lastWritePos, val, 0.0])
                    add(pendingMerges, [r, lastWritePos])
                    lastVal = 0
                    lastWritePos = 0
                else
                    newBoard[r][writePos] = val
                    add(slideAnims, [r, c, r, writePos, val, 0.0])
                    lastVal = val
                    lastWritePos = writePos
                    writePos -= 1
                ok
            next
        next
    ok

    if direction = DIR_UP
        for c = 1 to BOARD_SZ
            writePos = 1
            lastVal = 0
            lastWritePos = 0
            for r = 1 to BOARD_SZ
                val = board[r][c]
                if val = 0 loop ok
                if lastVal = val and lastWritePos > 0
                    merged = val * 2
                    newBoard[lastWritePos][c] = merged
                    mergeScore += merged
                    add(slideAnims, [r, c, lastWritePos, c, val, 0.0])
                    add(pendingMerges, [lastWritePos, c])
                    lastVal = 0
                    lastWritePos = 0
                else
                    newBoard[writePos][c] = val
                    add(slideAnims, [r, c, writePos, c, val, 0.0])
                    lastVal = val
                    lastWritePos = writePos
                    writePos += 1
                ok
            next
        next
    ok

    if direction = DIR_DOWN
        for c = 1 to BOARD_SZ
            writePos = BOARD_SZ
            lastVal = 0
            lastWritePos = 0
            for r = BOARD_SZ to 1 step -1
                val = board[r][c]
                if val = 0 loop ok
                if lastVal = val and lastWritePos > 0
                    merged = val * 2
                    newBoard[lastWritePos][c] = merged
                    mergeScore += merged
                    add(slideAnims, [r, c, lastWritePos, c, val, 0.0])
                    add(pendingMerges, [lastWritePos, c])
                    lastVal = 0
                    lastWritePos = 0
                else
                    newBoard[writePos][c] = val
                    add(slideAnims, [r, c, writePos, c, val, 0.0])
                    lastVal = val
                    lastWritePos = writePos
                    writePos -= 1
                ok
            next
        next
    ok

    // Check if anything actually moved
    changed = false
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if newBoard[r][c] != board[r][c]
                changed = true
            ok
        next
    next

    if changed = false
        slideAnims = []
        pendingMerges = []
        return false
    ok

    // Save undo
    add(undoStack, [savedBoard, savedScore])
    if len(undoStack) > 50
        del(undoStack, 1)
    ok

    // Store pending state
    pendingBoard = newBoard
    pendingScore = score + mergeScore
    moveCount += 1

    // Start slide animation
    slideActive = true
    slideProgress = 0.0
    gameState = ST_ANIMATING

    return true

// =============================================================
// Slide Animation
// =============================================================

func t48_updateSlideAnim dt
    if slideActive = false return ok

    slideProgress += dt * ANIM_SPEED
    for i = 1 to len(slideAnims)
        slideAnims[i][6] = slideProgress
    next

    if slideProgress >= 1.0
        slideActive = false
        slideAnims = []

        // Apply pending board
        board = pendingBoard
        score = pendingScore
        if score > bestScore
            bestScore = score
        ok

        // Merge animations and particles
        for i = 1 to len(pendingMerges)
            mr = pendingMerges[i][1]
            mc = pendingMerges[i][2]
            add(mergeAnims, [mr, mc, 0.0])
            wx = t48_cellToX(mc)
            wz = t48_cellToZ(mr)
            t48_spawnMergeParticles(wx, wz, board[mr][mc])
        next
        pendingMerges = []

        // Spawn new tile
        t48_spawnTile()

        // Check win
        if wonShown = false
            for r = 1 to BOARD_SZ
                for c = 1 to BOARD_SZ
                    if board[r][c] = 2048
                        gameState = ST_WON
                        t48_spawnWinParticles()
                        return
                    ok
                next
            next
        ok

        // Check game over
        if t48_hasValidMoves() = false
            gameState = ST_GAMEOVER
            return
        ok

        gameState = ST_PLAYING
    ok

// =============================================================
// Game Over Check
// =============================================================

func t48_hasValidMoves
    // Check for empty cells
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if board[r][c] = 0 return true ok
        next
    next
    // Check for adjacent matches
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            val = board[r][c]
            if r < BOARD_SZ
                if board[r+1][c] = val return true ok
            ok
            if c < BOARD_SZ
                if board[r][c+1] = val return true ok
            ok
        next
    next
    return false

// =============================================================
// Undo
// =============================================================

func t48_undo
    if len(undoStack) = 0
        t48_showMsg("Nothing to undo!")
        return
    ok

    last = undoStack[len(undoStack)]
    del(undoStack, len(undoStack))
    board = last[1]
    score = last[2]
    moveCount -= 1
    if moveCount < 0 moveCount = 0 ok
    t48_showMsg("Move undone")

// =============================================================
// Helpers
// =============================================================

func t48_copyBoard
    copy = list(BOARD_SZ)
    for r = 1 to BOARD_SZ
        copy[r] = list(BOARD_SZ)
        for c = 1 to BOARD_SZ
            copy[r][c] = board[r][c]
        next
    next
    return copy

func t48_cellToX c
    return (c - 1) * CELL_SZ - (BOARD_SZ - 1) * CELL_SZ / 2

func t48_cellToZ r
    return (r - 1) * CELL_SZ - (BOARD_SZ - 1) * CELL_SZ / 2

func t48_showMsg text
    msgText = text
    msgTimer = 2.0

// =============================================================
// Tile Value to Height
// =============================================================

func t48_tileHeight val
    if val = 0 return 0 ok
    // log2(val) based height
    h = 0.3
    v = val
    while v > 2
        v = v / 2
        h += 0.25
    end
    return h

// =============================================================
// Tile Value to Color
// =============================================================

func t48_tileColor val
    if val = 2    return RAYLIBColor(238, 228, 218, 255) ok
    if val = 4    return RAYLIBColor(237, 224, 200, 255) ok
    if val = 8    return RAYLIBColor(242, 177, 121, 255) ok
    if val = 16   return RAYLIBColor(245, 149, 99, 255)  ok
    if val = 32   return RAYLIBColor(246, 124, 95, 255)  ok
    if val = 64   return RAYLIBColor(246, 94, 59, 255)   ok
    if val = 128  return RAYLIBColor(237, 207, 114, 255) ok
    if val = 256  return RAYLIBColor(237, 204, 97, 255)  ok
    if val = 512  return RAYLIBColor(237, 200, 80, 255)  ok
    if val = 1024 return RAYLIBColor(237, 197, 63, 255)  ok
    if val = 2048 return RAYLIBColor(237, 194, 46, 255)  ok
    // Higher
    return RAYLIBColor(60, 58, 50, 255)

func t48_tileTextColor val
    if val <= 4
        return RAYLIBColor(119, 110, 101, 255)
    ok
    return RAYLIBColor(249, 246, 242, 255)

func t48_tileWireColor val
    if val = 2    return RAYLIBColor(200, 190, 180, 180) ok
    if val = 4    return RAYLIBColor(200, 186, 162, 180) ok
    if val = 8    return RAYLIBColor(200, 140, 90, 180)  ok
    if val = 16   return RAYLIBColor(200, 115, 70, 180)  ok
    if val = 32   return RAYLIBColor(200, 95, 70, 180)   ok
    if val = 64   return RAYLIBColor(200, 70, 40, 180)   ok
    if val = 128  return RAYLIBColor(200, 170, 80, 180)  ok
    if val = 256  return RAYLIBColor(200, 168, 65, 180)  ok
    if val = 512  return RAYLIBColor(200, 165, 50, 180)  ok
    if val = 1024 return RAYLIBColor(200, 162, 40, 180)  ok
    if val = 2048 return RAYLIBColor(200, 160, 30, 180)  ok
    return RAYLIBColor(40, 38, 34, 180)

// =============================================================
// Spawn / Merge Animations
// =============================================================

func t48_updateSpawnAnims dt
    i = 1
    while i <= len(spawnAnims)
        spawnAnims[i][3] += dt * SPAWN_SPEED
        if spawnAnims[i][3] >= 1.0
            del(spawnAnims, i)
        else
            i += 1
        ok
    end

func t48_updateMergeAnims dt
    i = 1
    while i <= len(mergeAnims)
        mergeAnims[i][3] += dt * 5.0
        if mergeAnims[i][3] >= 1.0
            del(mergeAnims, i)
        else
            i += 1
        ok
    end

// =============================================================
// Particles
// =============================================================

func t48_spawnMergeParticles wx, wz, val
    cr0 = 255  cg0 = 200  cb0 = 60
    if val >= 64
        cr0 = 255  cg0 = 120  cb0 = 40
    ok
    if val >= 512
        cr0 = 255  cg0 = 220  cb0 = 30
    ok
    for i = 1 to 14
        vx = (GetRandomValue(-100, 100) / 100.0) * 2.5
        vy = (GetRandomValue(200, 600) / 100.0)
        vz = (GetRandomValue(-100, 100) / 100.0) * 2.5
        cr = cr0 + GetRandomValue(-30, 30)
        cg = cg0 + GetRandomValue(-30, 30)
        cb = cb0 + GetRandomValue(-20, 20)
        if cr > 255 cr = 255 ok  if cr < 0 cr = 0 ok
        if cg > 255 cg = 255 ok  if cg < 0 cg = 0 ok
        if cb > 255 cb = 255 ok  if cb < 0 cb = 0 ok
        h = t48_tileHeight(val)
        add(particles, [wx, h + 0.2, wz, vx, vy, vz, 1.2, cr, cg, cb])
    next

func t48_spawnWinParticles
    for i = 1 to 80
        wx = (GetRandomValue(-500, 500) / 100.0)
        wz = (GetRandomValue(-500, 500) / 100.0)
        vx = (GetRandomValue(-200, 200) / 100.0)
        vy = (GetRandomValue(400, 900) / 100.0)
        vz = (GetRandomValue(-200, 200) / 100.0)
        cr = GetRandomValue(200, 255)
        cg = GetRandomValue(180, 255)
        cb = GetRandomValue(30, 150)
        add(particles, [wx, 1.0, wz, vx, vy, vz, 2.5, cr, cg, cb])
    next

func t48_updateParticles dt
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

func t48_drawParticles3D
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
// Camera
// =============================================================

func t48_positionCamera
    boardW = BOARD_SZ * CELL_SZ
    maxDim = boardW

    goalX = 0  goalY = 0  goalZ = 0
    tgtX = 0   tgtY = 0   tgtZ = 0

    if cameraMode = CAM_FRONT
        goalX = 0
        goalY = maxDim * 0.9 + 4.0
        goalZ = maxDim * 0.8 + 4.0
        tgtX = 0
        tgtY = 1.0
        tgtZ = -0.5
    ok
    if cameraMode = CAM_ISOMETRIC
        goalX = maxDim * 0.7 + 2.0
        goalY = maxDim * 0.8 + 3.0
        goalZ = maxDim * 0.7 + 2.0
        tgtX = 0
        tgtY = 1.0
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
// 3D Drawing: Board Base
// =============================================================

func t48_drawBoard3D
    boardW = BOARD_SZ * CELL_SZ

    // Board slab
    slabH = 0.35
    DrawCube(Vector3(0, -slabH/2, 0),
             boardW + 0.6, slabH, boardW + 0.6,
             RAYLIBColor(187, 173, 160, 255))
    DrawCubeWires(Vector3(0, -slabH/2, 0),
                  boardW + 0.6, slabH, boardW + 0.6,
                  RAYLIBColor(150, 138, 128, 200))

    // Empty cell slots
    slotH = 0.06
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            wx = t48_cellToX(c)
            wz = t48_cellToZ(r)
            DrawCube(Vector3(wx, slotH/2, wz),
                     TILE_SZ, slotH, TILE_SZ,
                     RAYLIBColor(205, 193, 180, 255))
        next
    next

    // Border frame
    bThick = 0.2
    bH = 0.2
    halfE = boardW / 2 + 0.2
    edgeCol = RAYLIBColor(160, 148, 138, 255)
    DrawCube(Vector3(0, bH/2, -halfE), boardW + 0.6, bH, bThick, edgeCol)
    DrawCube(Vector3(0, bH/2, halfE),  boardW + 0.6, bH, bThick, edgeCol)
    DrawCube(Vector3(-halfE, bH/2, 0), bThick, bH, boardW + 0.3, edgeCol)
    DrawCube(Vector3(halfE, bH/2, 0),  bThick, bH, boardW + 0.3, edgeCol)

    // Table beneath
    DrawPlane(Vector3(0, -slabH - 0.01, 0), Vector2(40, 40),
              RAYLIBColor(12, 10, 18, 255))

// =============================================================
// 3D Drawing: Tiles (static, non-animating)
// =============================================================

func t48_drawTiles3D
    // Don't draw tiles that are currently sliding
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if board[r][c] = 0 loop ok

            // Skip if this cell is source of a slide animation
            if slideActive
                isSliding = false
                for si = 1 to len(slideAnims)
                    if slideAnims[si][1] = r and slideAnims[si][2] = c
                        isSliding = true
                    ok
                next
                if isSliding loop ok
            ok

            wx = t48_cellToX(c)
            wz = t48_cellToZ(r)
            val = board[r][c]

            // Check for spawn animation scale
            spawnScale = 1.0
            for si = 1 to len(spawnAnims)
                if spawnAnims[si][1] = r and spawnAnims[si][2] = c
                    t = spawnAnims[si][3]
                    // Overshoot ease
                    spawnScale = t * t * (3.0 - 2.0 * t)
                    if spawnScale > 1.0 spawnScale = 1.0 ok
                ok
            next

            // Check for merge pop
            mergeScale = 1.0
            for mi = 1 to len(mergeAnims)
                if mergeAnims[mi][1] = r and mergeAnims[mi][2] = c
                    t = mergeAnims[mi][3]
                    // Pop: grow then shrink
                    if t < 0.4
                        mergeScale = 1.0 + (t / 0.4) * 0.3
                    else
                        mergeScale = 1.3 - ((t - 0.4) / 0.6) * 0.3
                    ok
                ok
            next

            scale = spawnScale * mergeScale
            t48_drawTileCube(wx, wz, val, scale)
        next
    next

// =============================================================
// 3D Drawing: Slide Animations
// =============================================================

func t48_drawSlideAnims3D
    if slideActive = false return ok

    for i = 1 to len(slideAnims)
        fromR = slideAnims[i][1]
        fromC = slideAnims[i][2]
        toR   = slideAnims[i][3]
        toC   = slideAnims[i][4]
        val   = slideAnims[i][5]
        prog  = slideAnims[i][6]
        if prog > 1.0 prog = 1.0 ok

        // Smooth ease
        t = prog * prog * (3.0 - 2.0 * prog)

        fromX = t48_cellToX(fromC)
        fromZ = t48_cellToZ(fromR)
        toX   = t48_cellToX(toC)
        toZ   = t48_cellToZ(toR)

        wx = fromX + (toX - fromX) * t
        wz = fromZ + (toZ - fromZ) * t

        t48_drawTileCube(wx, wz, val, 1.0)
    next

// =============================================================
// Draw Single Tile Cube
// =============================================================

func t48_drawTileCube wx, wz, val, scale
    h = t48_tileHeight(val) * scale
    tSz = TILE_SZ * scale

    col = t48_tileColor(val)
    wireCol = t48_tileWireColor(val)

    DrawCube(Vector3(wx, h/2 + 0.05, wz), tSz, h, tSz, col)
    DrawCubeWires(Vector3(wx, h/2 + 0.05, wz), tSz, h, tSz, wireCol)

    // Top face highlight
    topY = h + 0.06
    highlightSz = tSz * 0.6
    DrawCube(Vector3(wx, topY, wz), highlightSz, 0.02, highlightSz,
             RAYLIBColor(255, 255, 255, 40))

    // Glow for high values
    if val >= 128
        glowPulse = 0.5 + sin(animTime * 2.5) * 0.3
        glowAlpha = floor(50 * glowPulse)
        DrawCube(Vector3(wx, h/2 + 0.05, wz),
                 tSz + 0.1, h + 0.1, tSz + 0.1,
                 RAYLIBColor(255, 220, 50, glowAlpha))
    ok

    if val >= 2048
        glowPulse2 = 0.5 + sin(animTime * 4.0) * 0.5
        glowAlpha2 = floor(80 * glowPulse2)
        DrawCube(Vector3(wx, h/2 + 0.05, wz),
                 tSz + 0.2, h + 0.2, tSz + 0.2,
                 RAYLIBColor(255, 255, 100, glowAlpha2))
    ok

// =============================================================
// 3D-to-Screen Projection
// =============================================================

func t48_projectToScreen wx, wy, wz
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
// 2D Tile Value Labels (drawn after EndMode3D)
// =============================================================

func t48_drawTileLabels
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            val = board[r][c]
            if val = 0 loop ok

            wx = t48_cellToX(c)
            wz = t48_cellToZ(r)
            h = t48_tileHeight(val)

            // Project top of tile to screen
            t48_projectToScreen(wx, h + 0.15, wz)

            if projScreenX < -100 or projScreenX > SCREEN_W + 100 loop ok
            if projScreenY < -100 or projScreenY > SCREEN_H + 100 loop ok

            // Choose font size based on value and distance
            valStr = "" + val
            fontSize = 26
            if val >= 100 fontSize = 22 ok
            if val >= 1000 fontSize = 18 ok
            if val >= 10000 fontSize = 15 ok

            txtW = MeasureText(valStr, fontSize)
            sx = floor(projScreenX) - txtW / 2
            sy = floor(projScreenY) - fontSize / 2

            // Background pill
            DrawRectangle(sx - 5, sy - 3, txtW + 10, fontSize + 6,
                          RAYLIBColor(0, 0, 0, 150))

            // Text color - white for readability
            DrawText(valStr, sx, sy, fontSize, WHITE)
        next
    next

func t48_drawHUD
    panelW = 240
    panelH = 150
    DrawRectangle(10, 30, panelW, panelH, Fade(BLACK, 0.75))
    DrawRectangleLines(10, 30, panelW, panelH, RAYLIBColor(237, 194, 46, 200))

    DrawText("2048", 20, 38, 28, RAYLIBColor(237, 194, 46, 255))

    // Score
    DrawText("Score: " + score, 20, 72, 18, RAYLIBColor(255, 255, 255, 240))

    // Best
    DrawText("Best:  " + bestScore, 20, 96, 16, RAYLIBColor(200, 200, 220, 200))

    // Moves
    DrawText("Moves: " + moveCount, 20, 118, 14, RAYLIBColor(160, 180, 200, 200))

    // Find highest tile
    maxTile = 0
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if board[r][c] > maxTile
                maxTile = board[r][c]
            ok
        next
    next
    DrawText("Best tile: " + maxTile, 20, 138, 14,
             RAYLIBColor(237, 204, 97, 220))

    // Camera
    camName = "FRONT"
    if cameraMode = CAM_ISOMETRIC camName = "ISOMETRIC" ok
    if cameraMode = CAM_OVERHEAD  camName = "OVERHEAD"  ok
    DrawRectangle(10, SCREEN_H - 60, 220, 25, Fade(BLACK, 0.6))
    DrawText("Cam: " + camName + "  [C] switch", 16, SCREEN_H - 56, 14,
             RAYLIBColor(150, 180, 210, 220))

    // Controls
    DrawRectangle(SCREEN_W - 400, SCREEN_H - 35, 390, 25, Fade(BLACK, 0.6))
    DrawText("Arrow Keys: Slide | U: Undo | R: Restart | C: Camera",
             SCREEN_W - 395, SCREEN_H - 30, 12, RAYLIBColor(150, 160, 180, 200))

// =============================================================
// Mini Map
// =============================================================

func t48_drawMiniMap
    cellW = 30
    mapW = BOARD_SZ * cellW + 4
    mapH = BOARD_SZ * cellW + 4
    mapX = SCREEN_W - mapW - 15
    mapY = 30

    DrawRectangle(mapX - 3, mapY - 3, mapW + 6, mapH + 6, Fade(BLACK, 0.8))
    DrawRectangleLines(mapX - 3, mapY - 3, mapW + 6, mapH + 6,
                       RAYLIBColor(237, 194, 46, 200))

    // Background
    DrawRectangle(mapX, mapY, mapW, mapH, RAYLIBColor(187, 173, 160, 230))

    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            tx = mapX + 2 + (c - 1) * cellW
            ty = mapY + 2 + (r - 1) * cellW
            tw = cellW - 2
            th = cellW - 2

            if board[r][c] = 0
                DrawRectangle(tx, ty, tw, th, RAYLIBColor(205, 193, 180, 220))
            else
                col = t48_tileColor(board[r][c])
                DrawRectangle(tx, ty, tw, th, col)

                // Value text
                valStr = "" + board[r][c]
                fontSize = 12
                if board[r][c] >= 100 fontSize = 10 ok
                if board[r][c] >= 1000 fontSize = 8 ok
                txtW = MeasureText(valStr, fontSize)
                txtCol = t48_tileTextColor(board[r][c])
                DrawText(valStr, tx + (tw - txtW) / 2, ty + (th - fontSize) / 2,
                         fontSize, txtCol)
            ok
        next
    next

    DrawText("BOARD", mapX + mapW/2 - 22, mapY - 16, 12,
             RAYLIBColor(237, 194, 46, 200))

// =============================================================
// Title Screen
// =============================================================

func t48_drawTitleScreen
    DrawRectangleGradientV(0, 0, SCREEN_W, SCREEN_H,
        RAYLIBColor(18, 15, 25, 255), RAYLIBColor(30, 25, 38, 255))

    // Big 2048
    t1 = "2048"
    t1w = MeasureText(t1, 90)
    DrawText(t1, (SCREEN_W - t1w)/2, 50, 90, RAYLIBColor(237, 194, 46, 255))

    t1b = "3D EDITION"
    t1bw = MeasureText(t1b, 24)
    DrawText(t1b, (SCREEN_W - t1bw)/2, 145, 24, RAYLIBColor(237, 207, 114, 230))

    t2 = "~ Slide, Merge, and Reach 2048! ~"
    t2w = MeasureText(t2, 17)
    DrawText(t2, (SCREEN_W - t2w)/2, 185, 17, RAYLIBColor(180, 150, 100, 230))

    // Decorative line
    lx1 = 200
    lx2 = SCREEN_W - 200
    ly = 215
    DrawLine(lx1, ly, lx2, ly, RAYLIBColor(237, 194, 46, 180))

    // Sample tiles
    sampleVals = [2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048]
    startX = (SCREEN_W - len(sampleVals) * 42) / 2
    for i = 1 to len(sampleVals)
        col = t48_tileColor(sampleVals[i])
        sx = startX + (i - 1) * 42
        DrawRectangle(sx, 225, 38, 26, col)
        vs = "" + sampleVals[i]
        fs = 10
        if sampleVals[i] >= 100 fs = 8 ok
        if sampleVals[i] >= 1000 fs = 7 ok
        vw = MeasureText(vs, fs)
        tc = t48_tileTextColor(sampleVals[i])
        DrawText(vs, sx + (38 - vw)/2, 225 + (26 - fs)/2, fs, tc)
    next

    cy = 270
    cLines = [
        "Arrow Keys / WASD      -   Slide all tiles in that direction",
        "U / Backspace           -   Undo last move",
        "R                       -   Restart game",
        "C                       -   Cycle camera view",
        "",
        "How to Play:",
        "  Slide tiles in any direction. Tiles with the same number",
        "  merge when they collide, doubling their value!",
        "  A new tile (2 or 4) spawns after each move.",
        "  Reach the 2048 tile to win - then keep going for a high score!",
        "",
        "  3D cubes grow taller as their values increase.",
        "  Higher tiles glow with golden light!"
    ]
    for i = 1 to len(cLines)
        lw = MeasureText(cLines[i], 14)
        if i >= 6
            col = RAYLIBColor(220, 180, 100, 210)
        else
            col = RAYLIBColor(150, 170, 200, 230)
        ok
        DrawText(cLines[i], (SCREEN_W - lw)/2, cy + (i - 1) * 22, 14, col)
    next

    if floor(animTime * 2) % 2 = 0
        st2 = "Click or Press ENTER / SPACE to Start"
        st2w = MeasureText(st2, 26)
        DrawText(st2, (SCREEN_W - st2w)/2, 570, 26, WHITE)
    ok

    cr = "Developed using Ring Language + RingRayLib"
    crw = MeasureText(cr, 14)
    DrawText(cr, (SCREEN_W - crw)/2, SCREEN_H - 35, 14,
             RAYLIBColor(80, 100, 80, 180))

// =============================================================
// Won Overlay
// =============================================================

func t48_drawWonOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.5))

    g1 = "YOU REACHED 2048!"
    g1w = MeasureText(g1, 48)
    pulse = floor(220 + sin(animTime * 3.0) * 35)
    DrawText(g1, (SCREEN_W - g1w)/2, 180, 48,
             RAYLIBColor(237, 194, 46, pulse))

    g2 = "Score: " + score
    g2w = MeasureText(g2, 28)
    DrawText(g2, (SCREEN_W - g2w)/2, 250, 28, RAYLIBColor(255, 255, 255, 240))

    g3 = "Moves: " + moveCount
    g3w = MeasureText(g3, 20)
    DrawText(g3, (SCREEN_W - g3w)/2, 290, 20, RAYLIBColor(200, 200, 220, 200))

    if floor(animTime * 2) % 2 = 0
        rt = "Click or ENTER to continue playing!"
        rtw = MeasureText(rt, 20)
        DrawText(rt, (SCREEN_W - rtw)/2, 340, 20, WHITE)
    ok

    r2 = "Press R to restart"
    r2w = MeasureText(r2, 16)
    DrawText(r2, (SCREEN_W - r2w)/2, 375, 16, RAYLIBColor(180, 170, 160, 200))

// =============================================================
// Game Over Overlay
// =============================================================

func t48_drawGameOverOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.55))

    g1 = "GAME OVER"
    g1w = MeasureText(g1, 52)
    DrawText(g1, (SCREEN_W - g1w)/2, 170, 52, RAYLIBColor(255, 80, 60, 255))

    g2 = "Final Score: " + score
    g2w = MeasureText(g2, 28)
    DrawText(g2, (SCREEN_W - g2w)/2, 245, 28, RAYLIBColor(255, 255, 255, 240))

    g3 = "Best Score: " + bestScore
    g3w = MeasureText(g3, 20)
    DrawText(g3, (SCREEN_W - g3w)/2, 285, 20, RAYLIBColor(237, 194, 46, 220))

    g4 = "Moves: " + moveCount
    g4w = MeasureText(g4, 18)
    DrawText(g4, (SCREEN_W - g4w)/2, 315, 18, RAYLIBColor(200, 200, 220, 200))

    // Find max tile
    maxT = 0
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if board[r][c] > maxT
                maxT = board[r][c]
            ok
        next
    next
    g5 = "Highest tile: " + maxT
    g5w = MeasureText(g5, 18)
    DrawText(g5, (SCREEN_W - g5w)/2, 345, 18, RAYLIBColor(237, 204, 97, 220))

    if floor(animTime * 2) % 2 = 0
        rt = "Press R to retry  |  ENTER for title screen"
        rtw = MeasureText(rt, 16)
        DrawText(rt, (SCREEN_W - rtw)/2, 395, 16, WHITE)
    ok

// =============================================================
// Message Overlay
// =============================================================

func t48_drawMessage
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
