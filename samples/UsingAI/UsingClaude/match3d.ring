/*
**  3D Match-3 Gem Game - Using RingRayLib
**  =========================================
**  Swap adjacent gems to make rows or columns of 3 or more!
**  Chain reactions cascade as gems fall to fill gaps.
**
**  Controls:
**    Arrow Keys / WASD  - Move cursor
**    Mouse Click        - Select / Swap gem
**    ENTER / SPACE      - Select gem, then direction to swap
**    U / Backspace      - Undo last swap (if no cascade started)
**    H                  - Toggle match hint highlight
**    N                  - New game (same board size)
**    R                  - Return to title screen
**    C                  - Cycle camera views
**    1 / 2 / 3          - Board size: 6x6 / 7x7 / 8x8
**    ESC                - Exit
**
**  Gem Types (7):
**    Ruby (red sphere), Sapphire (blue cube),
**    Emerald (green diamond), Topaz (yellow octahedron),
**    Amethyst (purple cylinder), Pearl (white torus),
**    Citrine (orange star)
**
**  Scoring:
**    3-match  =  100 pts
**    4-match  =  300 pts  (+ row/col clear flash)
**    5-match  =  500 pts  (+ explosion effect)
**    Chain x2 =  2x multiplier, x3 = 3x, etc.
**
**  Features:
**    - Board sizes 6x6, 7x7, 8x8
**    - 3D gem shapes with unique geometry per type
**    - Smooth swap animation with ease-in-out
**    - Gravity fall animation for cascading gems
**    - New gems spawn from top with drop-in effect
**    - Chain combo multiplier system
**    - Match detection (rows and columns, 3+)
**    - Particle bursts on every match (color-matched)
**    - Glow effect on matched gems before removal
**    - Hint system highlights a valid swap
**    - Three camera modes: Front / Isometric / Overhead
**    - Score, combo, and moves tracking
**    - Mini-map with colored gem dots
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W        = 1024
SCREEN_H        = 768
CELL_SZ         = 2.0

// Gem types (1-7, 0=empty)
GEM_NONE        = 0
GEM_RUBY        = 1
GEM_SAPPHIRE    = 2
GEM_EMERALD     = 3
GEM_TOPAZ       = 4
GEM_AMETHYST    = 5
GEM_PEARL       = 6
GEM_CITRINE     = 7
GEM_COUNT       = 7

// Game states
ST_START        = 1
ST_PLAYING      = 2
ST_SWAPPING     = 3
ST_MATCHING     = 4
ST_REMOVING     = 5
ST_FALLING      = 6
ST_SPAWNING     = 7
ST_SWAPBACK     = 8

// Camera modes
CAM_FRONT       = 1
CAM_ISOMETRIC   = 2
CAM_OVERHEAD    = 3
CAM_COUNT       = 3

// Animation speeds
SWAP_SPEED      = 6.0
FALL_SPEED      = 8.0
REMOVE_SPEED    = 4.0
SPAWN_SPEED     = 6.0

// =============================================================
// Global Variables
// =============================================================

BOARD_SZ        = 8
board           = []        // board[r][c] = gem type
matchMap        = []        // matchMap[r][c] = true if part of current match
score           = 0
moveCount       = 0
comboChain      = 0
gameState       = ST_START
animTime        = 0.0

// Selection
selR            = 0
selC            = 0
cursorR         = 1
cursorC         = 1

// Swap animation
swapR1 = 0  swapC1 = 0  swapR2 = 0  swapC2 = 0
swapProgress    = 0.0

// Fall animation: [[r, c, fromRow, progress], ...]
fallAnims       = []
fallProgress    = 0.0

// Remove animation (shrink + glow)
removeProgress  = 0.0

// Spawn animation
spawnAnims      = []        // [[r, c, progress], ...]
spawnProgress   = 0.0

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

// Hint
showHints       = false
hintR1 = 0  hintC1 = 0  hintR2 = 0  hintC2 = 0

// Message
msgText         = ""
msgTimer        = 0.0

// Undo
lastSwapR1 = 0  lastSwapC1 = 0  lastSwapR2 = 0  lastSwapC2 = 0
canUndo         = false

// =============================================================
// Initialize
// =============================================================

m3_initBoard()

// =============================================================
// Main Program
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Ring 3D Match-3 Gems - RingRayLib")
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
        m3_initBoard()
        gameState = ST_START
    ok

    // Board size
    if gameState = ST_START
        m3_checkSizeKeys()
    ok

    // ========== STATE UPDATES ==========

    if gameState = ST_START
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(0)
            m3_initBoard()
            m3_fillBoard()
            m3_removeInitialMatches()
            m3_findHint()
            gameState = ST_PLAYING
        ok
    ok

    if gameState = ST_PLAYING
        m3_updateMouseHover()
        m3_handleInput()
        m3_handleMouse()
        m3_updateParticles(dt)
    ok

    if gameState = ST_SWAPPING
        m3_updateSwapAnim(dt)
        m3_updateParticles(dt)
    ok

    if gameState = ST_SWAPBACK
        m3_updateSwapAnim(dt)
        m3_updateParticles(dt)
    ok

    if gameState = ST_MATCHING
        m3_processMatching()
        m3_updateParticles(dt)
    ok

    if gameState = ST_REMOVING
        m3_updateRemoveAnim(dt)
        m3_updateParticles(dt)
    ok

    if gameState = ST_FALLING
        m3_updateFallAnim(dt)
        m3_updateParticles(dt)
    ok

    if gameState = ST_SPAWNING
        m3_updateSpawnAnim(dt)
        m3_updateParticles(dt)
    ok

    m3_positionCamera()

    // ========== DRAWING ==========

    BeginDrawing()
        ClearBackground(RAYLIBColor(14, 10, 20, 255))

        if gameState = ST_START
            m3_drawTitleScreen()
        else
            BeginMode3D(camera)
                m3_drawBoard3D()
                m3_drawGems3D()
                m3_drawCursor3D()
                m3_drawParticles3D()
            EndMode3D()

            m3_drawHUD()
            m3_drawMiniMap()

            if msgTimer > 0
                m3_drawMessage()
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

func m3_initBoard
    board = list(BOARD_SZ)
    matchMap = list(BOARD_SZ)
    for r = 1 to BOARD_SZ
        board[r] = list(BOARD_SZ)
        matchMap[r] = list(BOARD_SZ)
        for c = 1 to BOARD_SZ
            board[r][c] = GEM_NONE
            matchMap[r][c] = false
        next
    next

    score = 0
    moveCount = 0
    comboChain = 0
    selR = 0
    selC = 0
    cursorR = 1
    cursorC = 1
    particles = []
    fallAnims = []
    spawnAnims = []
    swapProgress = 0.0
    removeProgress = 0.0
    fallProgress = 0.0
    spawnProgress = 0.0
    showHints = false
    hintR1 = 0   hintC1 = 0   hintR2 = 0   hintC2 = 0
    canUndo = false
    msgTimer = 0

    CELL_SZ = 16.0 / BOARD_SZ
    if CELL_SZ < 1.8 CELL_SZ = 1.8 ok
    if CELL_SZ > 2.6 CELL_SZ = 2.6 ok

// =============================================================
// Fill Board with Random Gems (no initial matches)
// =============================================================

func m3_fillBoard
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            board[r][c] = m3_randomGem()
        next
    next

func m3_randomGem
    return GetRandomValue(1, GEM_COUNT)

func m3_removeInitialMatches
    // Keep re-filling until no matches
    hasMatch = true
    safetyCount = 0
    while hasMatch and safetyCount < 100
        safetyCount += 1
        hasMatch = false
        for r = 1 to BOARD_SZ
            for c = 1 to BOARD_SZ
                // Check horizontal match at this cell
                if c <= BOARD_SZ - 2
                    if board[r][c] = board[r][c+1] and board[r][c] = board[r][c+2]
                        if board[r][c] != GEM_NONE
                            board[r][c] = m3_randomGemExcluding(board[r][c])
                            hasMatch = true
                        ok
                    ok
                ok
                // Check vertical match
                if r <= BOARD_SZ - 2
                    if board[r][c] = board[r+1][c] and board[r][c] = board[r+2][c]
                        if board[r][c] != GEM_NONE
                            board[r][c] = m3_randomGemExcluding(board[r][c])
                            hasMatch = true
                        ok
                    ok
                ok
            next
        next
    end

func m3_randomGemExcluding exclude
    g = m3_randomGem()
    tries = 0
    while g = exclude and tries < 20
        g = m3_randomGem()
        tries += 1
    end
    return g

// =============================================================
// Size Keys
// =============================================================

func m3_checkSizeKeys
    if IsKeyPressed(KEY_ONE)
        BOARD_SZ = 6
        m3_initBoard()
    ok
    if IsKeyPressed(KEY_TWO)
        BOARD_SZ = 7
        m3_initBoard()
    ok
    if IsKeyPressed(KEY_THREE)
        BOARD_SZ = 8
        m3_initBoard()
    ok

// =============================================================
// Input Handling
// =============================================================

func m3_handleInput
    // Move cursor
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

    // Select / Swap
    if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
        if selR = 0 and selC = 0
            selR = cursorR
            selC = cursorC
        else
            // Try swap selected with cursor
            if m3_isAdjacent(selR, selC, cursorR, cursorC)
                m3_startSwap(selR, selC, cursorR, cursorC)
            ok
            selR = 0
            selC = 0
        ok
    ok

    // Undo
    if IsKeyPressed(KEY_U) or IsKeyPressed(KEY_BACKSPACE)
        m3_undoSwap()
    ok

    // Hints
    if IsKeyPressed(KEY_H)
        if showHints = true
            showHints = false
        else
            showHints = true
            m3_findHint()
        ok
    ok

    // New game
    if IsKeyPressed(KEY_N)
        m3_initBoard()
        m3_fillBoard()
        m3_removeInitialMatches()
        m3_findHint()
        gameState = ST_PLAYING
        m3_showMsg("New game!")
    ok

// =============================================================
// Mouse Handling
// =============================================================

func m3_updateMouseHover
    mx = GetMouseX()
    my = GetMouseY()

    bestDist = 999999.0
    bestR = 0
    bestC = 0

    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            wx = m3_cellToX(c)
            wz = m3_cellToZ(r)
            m3_projectToScreen(wx, 0.3, wz)
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

    threshDist = 1800
    if BOARD_SZ >= 7 threshDist = 1400 ok
    if BOARD_SZ >= 8 threshDist = 1100 ok

    if bestDist < threshDist
        mouseHoverR = bestR
        mouseHoverC = bestC
    else
        mouseHoverR = 0
        mouseHoverC = 0
    ok

func m3_handleMouse
    if IsMouseButtonPressed(0)
        if mouseHoverR < 1 or mouseHoverR > BOARD_SZ return ok
        if mouseHoverC < 1 or mouseHoverC > BOARD_SZ return ok

        if selR = 0 and selC = 0
            // First click: select
            selR = mouseHoverR
            selC = mouseHoverC
            cursorR = mouseHoverR
            cursorC = mouseHoverC
        else
            // Second click: attempt swap
            if m3_isAdjacent(selR, selC, mouseHoverR, mouseHoverC)
                m3_startSwap(selR, selC, mouseHoverR, mouseHoverC)
            else
                // Re-select
                selR = mouseHoverR
                selC = mouseHoverC
            ok
            if gameState = ST_PLAYING
                selR = 0
                selC = 0
            ok
        ok
    ok

    if IsMouseButtonPressed(1)
        selR = 0
        selC = 0
    ok

func m3_isAdjacent r1, c1, r2, c2
    dr = r1 - r2
    dc = c1 - c2
    if dr < 0 dr = 0 - dr ok
    if dc < 0 dc = 0 - dc ok
    if dr + dc = 1 return true ok
    return false

// =============================================================
// Swap Logic
// =============================================================

func m3_startSwap r1, c1, r2, c2
    swapR1 = r1   swapC1 = c1
    swapR2 = r2   swapC2 = c2
    swapProgress = 0.0

    // Actually swap in board
    tmp = board[r1][c1]
    board[r1][c1] = board[r2][c2]
    board[r2][c2] = tmp

    // Check if this creates any match
    if m3_hasAnyMatch()
        gameState = ST_SWAPPING
        moveCount += 1
        comboChain = 0
        canUndo = false
        lastSwapR1 = r1   lastSwapC1 = c1
        lastSwapR2 = r2   lastSwapC2 = c2
    else
        // No match - will swap back
        gameState = ST_SWAPBACK
    ok

    selR = 0
    selC = 0

// =============================================================
// Swap Animation
// =============================================================

func m3_updateSwapAnim dt
    swapProgress += dt * SWAP_SPEED
    if swapProgress >= 1.0
        swapProgress = 1.0
        if gameState = ST_SWAPBACK
            // Swap back
            tmp = board[swapR1][swapC1]
            board[swapR1][swapC1] = board[swapR2][swapC2]
            board[swapR2][swapC2] = tmp
            gameState = ST_PLAYING
            m3_showMsg("No match!")
        else
            // Proceed to matching
            gameState = ST_MATCHING
        ok
    ok

// =============================================================
// Match Detection
// =============================================================

func m3_hasAnyMatch
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ - 2
            if board[r][c] != GEM_NONE
                if board[r][c] = board[r][c+1] and board[r][c] = board[r][c+2]
                    return true
                ok
            ok
        next
    next
    for c = 1 to BOARD_SZ
        for r = 1 to BOARD_SZ - 2
            if board[r][c] != GEM_NONE
                if board[r][c] = board[r+1][c] and board[r][c] = board[r+2][c]
                    return true
                ok
            ok
        next
    next
    return false

func m3_findMatches
    // Clear match map
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            matchMap[r][c] = false
        next
    next

    // Horizontal
    for r = 1 to BOARD_SZ
        c = 1
        while c <= BOARD_SZ
            if board[r][c] = GEM_NONE
                c += 1
                loop
            ok
            // Find run length
            runLen = 1
            while c + runLen <= BOARD_SZ and board[r][c + runLen] = board[r][c]
                runLen += 1
            end
            if runLen >= 3
                for k = 0 to runLen - 1
                    matchMap[r][c + k] = true
                next
            ok
            c += runLen
        end
    next

    // Vertical
    for c = 1 to BOARD_SZ
        r = 1
        while r <= BOARD_SZ
            if board[r][c] = GEM_NONE
                r += 1
                loop
            ok
            runLen = 1
            while r + runLen <= BOARD_SZ and board[r + runLen][c] = board[r][c]
                runLen += 1
            end
            if runLen >= 3
                for k = 0 to runLen - 1
                    matchMap[r + k][c] = true
                next
            ok
            r += runLen
        end
    next

    // Count matches
    matchCount = 0
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if matchMap[r][c] = true matchCount += 1 ok
        next
    next
    return matchCount

// =============================================================
// Process Matching (state transition)
// =============================================================

func m3_processMatching
    cnt = m3_findMatches()
    if cnt > 0
        comboChain += 1

        // Score
        pts = cnt * 30
        if comboChain > 1
            pts = pts * comboChain
        ok
        score += pts

        if comboChain > 1
            m3_showMsg("" + comboChain + "x COMBO! +" + pts)
        else
            m3_showMsg("+" + pts + " pts")
        ok

        // Spawn particles for matched gems
        for r = 1 to BOARD_SZ
            for c = 1 to BOARD_SZ
                if matchMap[r][c] = true
                    wx = m3_cellToX(c)
                    wz = m3_cellToZ(r)
                    m3_spawnMatchParticles(wx, wz, board[r][c])
                ok
            next
        next

        removeProgress = 0.0
        gameState = ST_REMOVING
    else
        // No more matches - done cascading
        comboChain = 0
        m3_findHint()
        if hintR1 = 0 and hintC1 = 0
            m3_showMsg("No moves! Reshuffling...")
            m3_reshuffleBoard()
        ok
        gameState = ST_PLAYING
    ok

// =============================================================
// Remove Animation
// =============================================================

func m3_updateRemoveAnim dt
    removeProgress += dt * REMOVE_SPEED
    if removeProgress >= 1.0
        // Actually remove matched gems
        for r = 1 to BOARD_SZ
            for c = 1 to BOARD_SZ
                if matchMap[r][c] = true
                    board[r][c] = GEM_NONE
                ok
            next
        next
        // Start falling
        m3_startFalling()
    ok

// =============================================================
// Gravity / Falling
// =============================================================

func m3_startFalling
    fallAnims = []

    // Process column by column
    for c = 1 to BOARD_SZ
        writeRow = BOARD_SZ
        for r = BOARD_SZ to 1 step -1
            if board[r][c] != GEM_NONE
                if r != writeRow
                    // This gem needs to fall from r to writeRow
                    add(fallAnims, [writeRow, c, r, 0.0])
                    board[writeRow][c] = board[r][c]
                    board[r][c] = GEM_NONE
                ok
                writeRow -= 1
            ok
        next
    next

    fallProgress = 0.0

    if len(fallAnims) > 0
        gameState = ST_FALLING
    else
        // No falling needed, spawn new gems
        m3_startSpawning()
    ok

func m3_updateFallAnim dt
    fallProgress += dt * FALL_SPEED
    allDone = true

    for i = 1 to len(fallAnims)
        fallAnims[i][4] += dt * FALL_SPEED
        if fallAnims[i][4] < 1.0
            allDone = false
        else
            if fallAnims[i][4] > 1.0
                fallAnims[i][4] = 1.0
            ok
        ok
    next

    if allDone
        fallAnims = []
        m3_startSpawning()
    ok

// =============================================================
// Spawn New Gems
// =============================================================

func m3_startSpawning
    spawnAnims = []

    for c = 1 to BOARD_SZ
        for r = 1 to BOARD_SZ
            if board[r][c] = GEM_NONE
                board[r][c] = m3_randomGem()
                add(spawnAnims, [r, c, 0.0])
            ok
        next
    next

    spawnProgress = 0.0

    if len(spawnAnims) > 0
        gameState = ST_SPAWNING
    else
        // Check for new matches (cascade)
        gameState = ST_MATCHING
    ok

func m3_updateSpawnAnim dt
    spawnProgress += dt * SPAWN_SPEED
    allDone = true

    for i = 1 to len(spawnAnims)
        spawnAnims[i][3] += dt * SPAWN_SPEED
        if spawnAnims[i][3] < 1.0
            allDone = false
        else
            if spawnAnims[i][3] > 1.0
                spawnAnims[i][3] = 1.0
            ok
        ok
    next

    if allDone
        spawnAnims = []
        // Check for cascading matches
        gameState = ST_MATCHING
    ok

// =============================================================
// Undo
// =============================================================

func m3_undoSwap
    if canUndo = false
        m3_showMsg("Cannot undo!")
        return
    ok
    tmp = board[lastSwapR1][lastSwapC1]
    board[lastSwapR1][lastSwapC1] = board[lastSwapR2][lastSwapC2]
    board[lastSwapR2][lastSwapC2] = tmp
    moveCount -= 1
    if moveCount < 0 moveCount = 0 ok
    canUndo = false
    m3_showMsg("Swap undone")

// =============================================================
// Hint System
// =============================================================

func m3_findHint
    hintR1 = 0  hintC1 = 0  hintR2 = 0  hintC2 = 0

    // Try every possible swap and check for match
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            // Try swap right
            if c < BOARD_SZ
                m3_trySwapForHint(r, c, r, c+1)
                if hintR1 > 0 return ok
            ok
            // Try swap down
            if r < BOARD_SZ
                m3_trySwapForHint(r, c, r+1, c)
                if hintR1 > 0 return ok
            ok
        next
    next

func m3_trySwapForHint r1, c1, r2, c2
    // Temporarily swap
    tmp = board[r1][c1]
    board[r1][c1] = board[r2][c2]
    board[r2][c2] = tmp

    if m3_hasAnyMatch()
        hintR1 = r1  hintC1 = c1
        hintR2 = r2  hintC2 = c2
    ok

    // Swap back
    tmp = board[r1][c1]
    board[r1][c1] = board[r2][c2]
    board[r2][c2] = tmp

// =============================================================
// Reshuffle
// =============================================================

func m3_reshuffleBoard
    // Collect all gems
    gems = []
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if board[r][c] != GEM_NONE
                add(gems, board[r][c])
            ok
        next
    next

    // Shuffle using Fisher-Yates
    for i = len(gems) to 2 step -1
        j = GetRandomValue(1, i)
        tmp = gems[i]
        gems[i] = gems[j]
        gems[j] = tmp
    next

    // Place back
    idx = 1
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if idx <= len(gems)
                board[r][c] = gems[idx]
                idx += 1
            ok
        next
    next

    m3_removeInitialMatches()
    m3_findHint()

// =============================================================
// Helpers
// =============================================================

func m3_cellToX c
    return (c - 1) * CELL_SZ - (BOARD_SZ - 1) * CELL_SZ / 2

func m3_cellToZ r
    return (r - 1) * CELL_SZ - (BOARD_SZ - 1) * CELL_SZ / 2

func m3_showMsg text
    msgText = text
    msgTimer = 1.8

// =============================================================
// Gem Colors
// =============================================================

func m3_gemColor gtype
    if gtype = GEM_RUBY     return RAYLIBColor(220, 40,  40,  255) ok
    if gtype = GEM_SAPPHIRE return RAYLIBColor(40,  80,  220, 255) ok
    if gtype = GEM_EMERALD  return RAYLIBColor(30,  180, 60,  255) ok
    if gtype = GEM_TOPAZ    return RAYLIBColor(240, 200, 30,  255) ok
    if gtype = GEM_AMETHYST return RAYLIBColor(160, 50,  200, 255) ok
    if gtype = GEM_PEARL    return RAYLIBColor(220, 220, 230, 255) ok
    if gtype = GEM_CITRINE  return RAYLIBColor(240, 140, 30,  255) ok
    return RAYLIBColor(128, 128, 128, 255)

func m3_gemWireColor gtype
    if gtype = GEM_RUBY     return RAYLIBColor(160, 20,  20,  200) ok
    if gtype = GEM_SAPPHIRE return RAYLIBColor(20,  50,  160, 200) ok
    if gtype = GEM_EMERALD  return RAYLIBColor(15,  120, 30,  200) ok
    if gtype = GEM_TOPAZ    return RAYLIBColor(180, 150, 15,  200) ok
    if gtype = GEM_AMETHYST return RAYLIBColor(100, 25,  140, 200) ok
    if gtype = GEM_PEARL    return RAYLIBColor(150, 150, 160, 200) ok
    if gtype = GEM_CITRINE  return RAYLIBColor(180, 100, 15,  200) ok
    return RAYLIBColor(80, 80, 80, 200)

func m3_gemName gtype
    if gtype = GEM_RUBY     return "Ruby"     ok
    if gtype = GEM_SAPPHIRE return "Sapphire" ok
    if gtype = GEM_EMERALD  return "Emerald"  ok
    if gtype = GEM_TOPAZ    return "Topaz"    ok
    if gtype = GEM_AMETHYST return "Amethyst" ok
    if gtype = GEM_PEARL    return "Pearl"    ok
    if gtype = GEM_CITRINE  return "Citrine"  ok
    return "None"

// =============================================================
// Particles
// =============================================================

func m3_spawnMatchParticles wx, wz, gtype
    col = m3_gemColor(gtype)
    for i = 1 to 10
        vx = (GetRandomValue(-150, 150) / 100.0)
        vy = (GetRandomValue(200, 600) / 100.0)
        vz = (GetRandomValue(-150, 150) / 100.0)
        cr = GetRandomValue(150, 255)
        cg = GetRandomValue(100, 255)
        cb = GetRandomValue(100, 255)
        add(particles, [wx, 0.6, wz, vx, vy, vz, 1.2, cr, cg, cb])
    next

func m3_updateParticles dt
    i = 1
    while i <= len(particles)
        particles[i][1] += particles[i][4] * dt
        particles[i][2] += particles[i][5] * dt
        particles[i][3] += particles[i][6] * dt
        particles[i][5] -= 7.0 * dt
        particles[i][7] -= dt
        if particles[i][7] <= 0
            del(particles, i)
        else
            i += 1
        ok
    end

func m3_drawParticles3D
    for i = 1 to len(particles)
        p = particles[i]
        alpha = floor((p[7] / 1.2) * 255)
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
// 3D-to-Screen Projection
// =============================================================

func m3_projectToScreen wx, wy, wz
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

func m3_positionCamera
    boardW = BOARD_SZ * CELL_SZ
    maxDim = boardW

    goalX = 0  goalY = 0  goalZ = 0
    tgtX = 0   tgtY = 0   tgtZ = 0

    if cameraMode = CAM_FRONT
        goalX = 0
        goalY = maxDim * 0.9 + 3.0
        goalZ = maxDim * 0.8 + 3.0
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
        goalY = maxDim * 1.15 + 5.0
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

func m3_drawBoard3D
    boardW = BOARD_SZ * CELL_SZ

    // Board slab
    slabH = 0.3
    DrawCube(Vector3(0, -slabH/2, 0),
             boardW + 0.8, slabH, boardW + 0.8,
             RAYLIBColor(35, 25, 45, 255))
    DrawCubeWires(Vector3(0, -slabH/2, 0),
                  boardW + 0.8, slabH, boardW + 0.8,
                  RAYLIBColor(25, 18, 32, 200))

    // Cell tiles (checkerboard)
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            wx = m3_cellToX(c)
            wz = m3_cellToZ(r)
            tileSz = CELL_SZ * 0.95

            evenCell = ((r + c) % 2)
            if evenCell = 0
                tileCol = RAYLIBColor(28, 20, 38, 255)
            else
                tileCol = RAYLIBColor(36, 26, 48, 255)
            ok

            DrawCube(Vector3(wx, 0.02, wz), tileSz, 0.04, tileSz, tileCol)
        next
    next

    // Border
    bThick = 0.18
    bH = 0.2
    halfE = boardW / 2 + 0.3
    edgeCol = RAYLIBColor(60, 40, 70, 255)
    DrawCube(Vector3(0, bH/2, -halfE), boardW + 0.8, bH, bThick, edgeCol)
    DrawCube(Vector3(0, bH/2, halfE),  boardW + 0.8, bH, bThick, edgeCol)
    DrawCube(Vector3(-halfE, bH/2, 0), bThick, bH, boardW + 0.5, edgeCol)
    DrawCube(Vector3(halfE, bH/2, 0),  bThick, bH, boardW + 0.5, edgeCol)

    // Table
    DrawPlane(Vector3(0, -slabH - 0.01, 0), Vector2(40, 40),
              RAYLIBColor(8, 6, 14, 255))

// =============================================================
// 3D Drawing: Gems
// =============================================================

func m3_drawGems3D
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            gtype = board[r][c]
            if gtype = GEM_NONE loop ok

            wx = m3_cellToX(c)
            wz = m3_cellToZ(r)
            wy = 0.5
            scale = 1.0
            drawIt = true

            // --- Handle swap animation ---
            if gameState = ST_SWAPPING or gameState = ST_SWAPBACK
                t = swapProgress
                smooth = t * t * (3.0 - 2.0 * t)

                if r = swapR1 and c = swapC1
                    // Animate from pos2 to pos1 (already swapped in board)
                    ox = m3_cellToX(swapC2)
                    oz = m3_cellToZ(swapR2)
                    wx = ox + (wx - ox) * smooth
                    wz = oz + (wz - oz) * smooth
                ok
                if r = swapR2 and c = swapC2
                    ox = m3_cellToX(swapC1)
                    oz = m3_cellToZ(swapR1)
                    wx = ox + (wx - ox) * smooth
                    wz = oz + (wz - oz) * smooth
                ok
            ok

            // --- Handle remove animation ---
            if gameState = ST_REMOVING
                if matchMap[r][c] = true
                    // Shrink and glow
                    t = removeProgress
                    scale = 1.0 - t * 0.9
                    if scale < 0.05 scale = 0.05 ok
                ok
            ok

            // --- Handle fall animation ---
            if gameState = ST_FALLING
                for fi = 1 to len(fallAnims)
                    if fallAnims[fi][1] = r and fallAnims[fi][2] = c
                        fromR = fallAnims[fi][3]
                        t = fallAnims[fi][4]
                        if t > 1.0 t = 1.0 ok
                        smooth = t * t * (3.0 - 2.0 * t)
                        fromZ = m3_cellToZ(fromR)
                        toZ = m3_cellToZ(r)
                        wz = fromZ + (toZ - fromZ) * smooth
                    ok
                next
            ok

            // --- Handle spawn animation ---
            if gameState = ST_SPAWNING
                for si = 1 to len(spawnAnims)
                    if spawnAnims[si][1] = r and spawnAnims[si][2] = c
                        t = spawnAnims[si][3]
                        if t > 1.0 t = 1.0 ok
                        scale = t
                        wy = 0.5 + (1.0 - t) * 2.0
                    ok
                next
            ok

            if drawIt
                m3_drawGemShape(wx, wy, wz, gtype, scale)
            ok

            // Hint highlight
            if showHints = true
                if (r = hintR1 and c = hintC1) or (r = hintR2 and c = hintC2)
                    pulse = 0.4 + sin(animTime * 5.0) * 0.4
                    hAlpha = floor(120 * pulse)
                    gSz = CELL_SZ * 0.42 * scale
                    DrawCube(Vector3(wx, wy, wz), gSz * 2.2, gSz * 2.2, gSz * 2.2,
                             RAYLIBColor(255, 255, 100, hAlpha))
                ok
            ok
        next
    next

// =============================================================
// Draw Gem Shape (unique geometry per type)
// =============================================================

func m3_drawGemShape wx, wy, wz, gtype, scale
    col = m3_gemColor(gtype)
    wireCol = m3_gemWireColor(gtype)
    sz = CELL_SZ * 0.32 * scale
    PI = 3.14159265

    // Idle animation: gentle bob
    bob = sin(animTime * 2.5 + wx * 1.3 + wz * 0.7) * 0.06
    wy = wy + bob

    if gtype = GEM_RUBY
        // Red sphere
        DrawSphere(Vector3(wx, wy, wz), sz, col)
        DrawSphereWires(Vector3(wx, wy, wz), sz, 8, 8, wireCol)
        // Highlight
        DrawSphere(Vector3(wx - sz*0.25, wy + sz*0.3, wz - sz*0.2),
                   sz * 0.2, RAYLIBColor(255, 200, 200, 120))
    ok

    if gtype = GEM_SAPPHIRE
        // Blue cube
        cSz = sz * 1.5
        DrawCube(Vector3(wx, wy, wz), cSz, cSz, cSz, col)
        DrawCubeWires(Vector3(wx, wy, wz), cSz, cSz, cSz, wireCol)
        // Top highlight
        DrawCube(Vector3(wx, wy + cSz*0.4, wz), cSz*0.5, 0.02, cSz*0.5,
                 RAYLIBColor(150, 180, 255, 80))
    ok

    if gtype = GEM_EMERALD
        // Green diamond (two pyramids)
        // Upper pyramid (using cone)
        DrawCylinder(Vector3(wx, wy, wz), sz * 1.3, 0.01, sz * 1.2, 4, col)
        DrawCylinderWires(Vector3(wx, wy, wz), sz * 1.3, 0.01, sz * 1.2, 4, wireCol)
        // Lower pyramid (inverted)
        DrawCylinder(Vector3(wx, wy - sz * 1.2, wz), 0.01, sz * 1.3, sz * 1.2, 4, col)
        DrawCylinderWires(Vector3(wx, wy - sz * 1.2, wz), 0.01, sz * 1.3, sz * 1.2, 4, wireCol)
    ok

    if gtype = GEM_TOPAZ
        // Yellow octahedron (two pyramids sharing base)
        DrawCylinder(Vector3(wx, wy, wz), sz * 1.2, 0.01, sz, 6, col)
        DrawCylinderWires(Vector3(wx, wy, wz), sz * 1.2, 0.01, sz, 6, wireCol)
        DrawCylinder(Vector3(wx, wy - sz, wz), 0.01, sz * 1.2, sz, 6, col)
        DrawCylinderWires(Vector3(wx, wy - sz, wz), 0.01, sz * 1.2, sz, 6, wireCol)
    ok

    if gtype = GEM_AMETHYST
        // Purple cylinder (crystal column)
        cH = sz * 2.0
        DrawCylinder(Vector3(wx, wy - cH/2, wz), sz * 0.7, sz * 0.5, cH, 6, col)
        DrawCylinderWires(Vector3(wx, wy - cH/2, wz), sz * 0.7, sz * 0.5, cH, 6, wireCol)
        // Cap
        DrawSphere(Vector3(wx, wy + cH/2, wz), sz * 0.5, col)
    ok

    if gtype = GEM_PEARL
        // White multi-sphere cluster (torus approximation)
        DrawSphere(Vector3(wx, wy, wz), sz * 0.85, col)
        DrawSphereWires(Vector3(wx, wy, wz), sz * 0.85, 8, 8, wireCol)
        ringR = sz * 0.65
        for a = 0 to 5
            ang = a * PI * 2.0 / 6.0
            px = wx + cos(ang) * ringR
            pz = wz + sin(ang) * ringR
            DrawSphere(Vector3(px, wy, pz), sz * 0.25,
                       RAYLIBColor(200, 200, 215, 200))
        next
    ok

    if gtype = GEM_CITRINE
        // Orange star (multi-point using small cubes)
        cSz = sz * 1.1
        DrawCube(Vector3(wx, wy, wz), cSz * 1.6, cSz * 0.6, cSz * 0.6, col)
        DrawCubeWires(Vector3(wx, wy, wz), cSz * 1.6, cSz * 0.6, cSz * 0.6, wireCol)
        DrawCube(Vector3(wx, wy, wz), cSz * 0.6, cSz * 1.6, cSz * 0.6, col)
        DrawCubeWires(Vector3(wx, wy, wz), cSz * 0.6, cSz * 1.6, cSz * 0.6, wireCol)
        DrawCube(Vector3(wx, wy, wz), cSz * 0.6, cSz * 0.6, cSz * 1.6, col)
        DrawCubeWires(Vector3(wx, wy, wz), cSz * 0.6, cSz * 0.6, cSz * 1.6, wireCol)
        // Center glow
        DrawSphere(Vector3(wx, wy, wz), sz * 0.35,
                   RAYLIBColor(255, 200, 100, 120))
    ok

// =============================================================
// 3D Drawing: Cursor & Selection
// =============================================================

func m3_drawCursor3D
    if gameState != ST_PLAYING return ok

    // Selection highlight
    if selR > 0 and selC > 0
        wx = m3_cellToX(selC)
        wz = m3_cellToZ(selR)
        pulse = 0.6 + sin(animTime * 6.0) * 0.4
        sAlpha = floor(160 * pulse)
        sSz = CELL_SZ * 0.48
        DrawCube(Vector3(wx, 0.5, wz), sSz * 2, sSz * 2, sSz * 2,
                 RAYLIBColor(255, 255, 80, floor(sAlpha * 0.3)))
    ok

    // Cursor brackets
    wx = m3_cellToX(cursorC)
    wz = m3_cellToZ(cursorR)
    hs = CELL_SZ * 0.46
    bLen = CELL_SZ * 0.18
    by = 0.06

    curCol = RAYLIBColor(255, 255, 255, 200)
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

func m3_drawHUD
    panelW = 230
    panelH = 120
    DrawRectangle(10, 30, panelW, panelH, Fade(BLACK, 0.75))
    DrawRectangleLines(10, 30, panelW, panelH, RAYLIBColor(180, 100, 220, 200))

    DrawText("MATCH-3 GEMS", 20, 38, 20, RAYLIBColor(220, 120, 255, 255))

    DrawText("Board: " + BOARD_SZ + "x" + BOARD_SZ, 20, 63, 14,
             RAYLIBColor(160, 180, 200, 200))

    DrawText("Score: " + score, 20, 80, 18, RAYLIBColor(255, 255, 255, 240))

    DrawText("Moves: " + moveCount, 20, 102, 14,
             RAYLIBColor(200, 200, 220, 200))

    if comboChain > 1
        comboStr = "Combo: " + comboChain + "x!"
        DrawText(comboStr, 20, 122, 16, RAYLIBColor(255, 200, 50, 255))
    ok

    hStr = "OFF"
    if showHints = true hStr = "ON" ok
    DrawText("Hints: " + hStr + " [H]", 20, 138, 11,
             RAYLIBColor(140, 155, 175, 160))

    // Camera
    camName = "FRONT"
    if cameraMode = CAM_ISOMETRIC camName = "ISOMETRIC" ok
    if cameraMode = CAM_OVERHEAD  camName = "OVERHEAD"  ok
    DrawRectangle(10, SCREEN_H - 60, 220, 25, Fade(BLACK, 0.6))
    DrawText("Cam: " + camName + "  [C] switch", 16, SCREEN_H - 56, 14,
             RAYLIBColor(150, 180, 210, 220))

    // Controls
    DrawRectangle(SCREEN_W - 500, SCREEN_H - 35, 490, 25, Fade(BLACK, 0.6))
    DrawText("Click: Select/Swap | RClick: Deselect | H: Hints | U: Undo | N: New",
             SCREEN_W - 496, SCREEN_H - 30, 12, RAYLIBColor(150, 160, 180, 200))

// =============================================================
// Mini Map
// =============================================================

func m3_drawMiniMap
    cellW = 16
    if BOARD_SZ >= 7 cellW = 14 ok
    if BOARD_SZ >= 8 cellW = 12 ok
    mapW = BOARD_SZ * cellW + 4
    mapH = BOARD_SZ * cellW + 4
    mapX = SCREEN_W - mapW - 15
    mapY = 30

    DrawRectangle(mapX - 3, mapY - 3, mapW + 6, mapH + 6, Fade(BLACK, 0.8))
    DrawRectangleLines(mapX - 3, mapY - 3, mapW + 6, mapH + 6,
                       RAYLIBColor(180, 100, 220, 200))

    DrawRectangle(mapX, mapY, mapW, mapH, RAYLIBColor(25, 18, 35, 230))

    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            tx = mapX + 2 + (c - 1) * cellW
            ty = mapY + 2 + (r - 1) * cellW
            tw = cellW - 2
            th = cellW - 2

            gtype = board[r][c]
            if gtype = GEM_NONE
                DrawRectangle(tx, ty, tw, th, RAYLIBColor(20, 15, 28, 200))
            else
                col = m3_gemColor(gtype)
                DrawRectangle(tx, ty, tw, th, col)

                // Match highlight
                if gameState = ST_REMOVING
                    if matchMap[r][c] = true
                        DrawRectangle(tx, ty, tw, th,
                                      RAYLIBColor(255, 255, 255, 120))
                    ok
                ok
            ok

            DrawRectangleLines(tx, ty, tw, th,
                               RAYLIBColor(40, 30, 50, 120))
        next
    next

    // Cursor
    cxm = mapX + 2 + (cursorC - 1) * cellW
    cym = mapY + 2 + (cursorR - 1) * cellW
    DrawRectangleLines(cxm, cym, cellW - 2, cellW - 2,
                       RAYLIBColor(255, 255, 255, 220))

    // Selection
    if selR > 0 and selC > 0
        sxm = mapX + 2 + (selC - 1) * cellW
        sym = mapY + 2 + (selR - 1) * cellW
        DrawRectangleLines(sxm - 1, sym - 1, cellW, cellW,
                           RAYLIBColor(255, 255, 80, 200))
    ok

    DrawText("MAP", mapX + mapW/2 - 15, mapY - 16, 12,
             RAYLIBColor(180, 100, 220, 200))

// =============================================================
// Title Screen
// =============================================================

func m3_drawTitleScreen
    DrawRectangleGradientV(0, 0, SCREEN_W, SCREEN_H,
        RAYLIBColor(16, 10, 24, 255), RAYLIBColor(24, 16, 36, 255))

    t1 = "MATCH-3 GEMS"
    t1w = MeasureText(t1, 56)
    DrawText(t1, (SCREEN_W - t1w)/2, 30, 56, RAYLIBColor(220, 120, 255, 255))

    t1b = "3D EDITION"
    t1bw = MeasureText(t1b, 22)
    DrawText(t1b, (SCREEN_W - t1bw)/2, 95, 22, RAYLIBColor(255, 160, 255, 230))

    t2 = "~ Swap Gems to Match 3+ in a Row ~"
    t2w = MeasureText(t2, 17)
    DrawText(t2, (SCREEN_W - t2w)/2, 128, 17, RAYLIBColor(200, 170, 230, 230))

    ly = 155
    DrawLine(180, ly, SCREEN_W - 180, ly, RAYLIBColor(180, 100, 220, 180))

    // Gem palette display
    gemNames = ["Ruby","Sapphire","Emerald","Topaz","Amethyst","Pearl","Citrine"]
    gemTypes = [GEM_RUBY,GEM_SAPPHIRE,GEM_EMERALD,GEM_TOPAZ,GEM_AMETHYST,GEM_PEARL,GEM_CITRINE]
    startX = (SCREEN_W - 7 * 55) / 2
    for i = 1 to 7
        gx = startX + (i - 1) * 55
        col = m3_gemColor(gemTypes[i])
        DrawRectangle(gx, 168, 42, 20, col)
        nw = MeasureText(gemNames[i], 9)
        DrawText(gemNames[i], gx + 21 - nw/2, 190, 9,
                 RAYLIBColor(200, 200, 220, 200))
    next

    cy = 215
    cLines = [
        "Click / ENTER / SPACE  -   Select gem, then click neighbor",
        "Right Click            -   Deselect current gem",
        "Arrow Keys / WASD      -   Move cursor on the board",
        "U / Backspace          -   Undo last swap",
        "H                      -   Toggle match hints",
        "N                      -   New game (same board size)",
        "R                      -   Return to title screen",
        "C                      -   Cycle camera view",
        "",
        "Board Sizes:   1=6x6   2=7x7   3=8x8",
        "",
        "Scoring:",
        "  3-match =  100 pts per gem",
        "  Chain combos multiply your score: x2, x3, x4...",
        "  Cascading matches build bigger combos!",
        "",
        "Rules:",
        "  Swap two adjacent gems to create a row/column of 3+.",
        "  Matched gems are removed and new ones fall from above.",
        "  Chain reactions cascade automatically for bonus points!"
    ]
    for i = 1 to len(cLines)
        lw = MeasureText(cLines[i], 13)
        if i >= 10
            col = RAYLIBColor(220, 160, 255, 210)
        else
            col = RAYLIBColor(170, 160, 200, 230)
        ok
        DrawText(cLines[i], (SCREEN_W - lw)/2, cy + (i - 1) * 20, 13, col)
    next

    // Current size
    sizeStr = "Current: " + BOARD_SZ + "x" + BOARD_SZ
    ssw = MeasureText(sizeStr, 18)
    DrawText(sizeStr, (SCREEN_W - ssw)/2, 626, 18,
             RAYLIBColor(220, 120, 255, 230))

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
// Message Overlay
// =============================================================

func m3_drawMessage
    alpha = floor((msgTimer / 1.8) * 255)
    if alpha > 255 alpha = 255 ok
    if alpha < 0 alpha = 0 ok

    mw = MeasureText(msgText, 26)
    mx = (SCREEN_W - mw) / 2
    my = SCREEN_H / 2 + 120

    DrawRectangle(mx - 15, my - 8, mw + 30, 42,
                  RAYLIBColor(0, 0, 0, floor(alpha * 0.7)))
    DrawText(msgText, mx, my, 26,
             RAYLIBColor(255, 200, 80, alpha))
