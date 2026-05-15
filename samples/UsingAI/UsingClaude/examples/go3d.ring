/*
**  3D Go Game (Weiqi/Baduk) - Using RingRayLib
**  ===============================================
**  The ancient board game of Go rendered in beautiful 3D!
**  Place black and white stones on a wooden board to surround
**  territory and capture your opponent's stones.
**
**  Controls:
**    Arrow Keys / WASD  - Move cursor on the board
**    Mouse              - Hover and click to place stones
**    ENTER / SPACE      - Place stone at cursor position
**    P                  - Pass turn
**    U                  - Undo last move
**    R                  - Restart game
**    C                  - Cycle camera views
**    T                  - Toggle territory estimation display
**    1 / 2 / 3          - Board size: 9x9 / 13x13 / 19x19
**    M                  - Toggle game mode (PvP / vs AI)
**    ESC                - Exit
**
**  Rules:
**    - Black plays first, players alternate placing stones
**    - Stones with no liberties (empty adjacent points) are captured
**    - Ko rule: Cannot recreate previous board position
**    - Game ends when both players pass consecutively
**    - Score = Territory + Captures + Komi (6.5 for White)
**
**  Features:
**    - Three board sizes: 9x9, 13x13, 19x19
**    - Full Go rules: liberties, captures, ko, suicide prevention
**    - AI opponent (territory-aware heuristic)
**    - Smooth 3D stone placement with drop animation
**    - Three camera modes: Front-Angle / Isometric / Overhead
**    - Particle effects on stone capture
**    - Territory estimation overlay
**    - Captured stones display
**    - Move history with undo
**    - Mouse + keyboard support
**    - Title, playing, scoring, and game-over screens
**    - Star points (hoshi) drawn on standard positions
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W        = 1024
SCREEN_H        = 768

// Cell states
CELL_EMPTY      = 0
CELL_BLACK      = 1
CELL_WHITE      = 2

// Game states
ST_START        = 1
ST_PLAYING      = 2
ST_SCORING      = 3
ST_GAMEOVER     = 4

// Camera modes
CAM_FRONT       = 1
CAM_ISOMETRIC   = 2
CAM_OVERHEAD    = 3
CAM_COUNT       = 3

// Game modes
MODE_PVP        = 1
MODE_PVA        = 2

// Scoring
KOMI            = 6.5

// =============================================================
// Global Variables
// =============================================================

BOARD_SZ        = 9
CELL_SZ         = 1.4
stoneRadius     = 0.55
stoneHeight     = 0.28

board           = []
prevBoard       = []      // For ko detection

cursorR         = 5
cursorC         = 5
currentPlayer   = CELL_BLACK
gameState       = ST_START
gameMode        = MODE_PVP
animTime        = 0.0

// Move history: [[r, c, player, capturedList], ...]
moveHistory     = []

// Captures
blackCaptures   = 0
whiteCaptures   = 0

// Pass tracking
blackPassed     = false
whitePassed     = false
consecutivePasses = 0

// Ko
koR             = 0
koC             = 0

// Camera
cameraMode      = CAM_FRONT
camPosX = 0.0   camPosY = 14.0  camPosZ = 12.0
camTgtX = 0.0   camTgtY = 0.0   camTgtZ = 0.0

// Mouse
mouseHoverR     = 0
mouseHoverC     = 0
projScreenX     = 0.0
projScreenY     = 0.0

// Particles: [x, y, z, vx, vy, vz, life, cr, cg, cb]
particles       = []

// Stone drop animation
dropAnims       = []   // [[r, c, player, progress], ...]

// Territory (for scoring display)
territory       = []
showTerritory   = false
blackTerritory  = 0
whiteTerritory  = 0

// AI
aiTimer         = 0.0
aiDelay         = 0.4

// Last move highlight
lastMoveR       = 0
lastMoveC       = 0

// Message display
msgText         = ""
msgTimer        = 0.0

// =============================================================
// Initialize
// =============================================================

go_initBoard()

// =============================================================
// Main Program
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Ring 3D Go (Weiqi) - RingRayLib")
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

    // --- Message timer ---
    if msgTimer > 0
        msgTimer -= dt
        if msgTimer < 0 msgTimer = 0 ok
    ok

    // --- Global input ---
    if IsKeyPressed(KEY_C)
        cameraMode += 1
        if cameraMode > CAM_COUNT cameraMode = CAM_FRONT ok
    ok

    // Board size selection
    if gameState = ST_START or gameState = ST_GAMEOVER
        if IsKeyPressed(KEY_ONE)
            BOARD_SZ = 9
            CELL_SZ = 1.4
            go_initBoard()
        ok
        if IsKeyPressed(KEY_TWO)
            BOARD_SZ = 13
            CELL_SZ = 1.0
            go_initBoard()
        ok
        if IsKeyPressed(KEY_THREE)
            BOARD_SZ = 19
            CELL_SZ = 0.72
            go_initBoard()
        ok
    ok

    if IsKeyPressed(KEY_R)
        go_initBoard()
        gameState = ST_PLAYING
    ok

    // --- State updates ---
    if gameState = ST_START
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(0)
            go_initBoard()
            gameState = ST_PLAYING
        ok
        if IsKeyPressed(KEY_M)
            if gameMode = MODE_PVP
                gameMode = MODE_PVA
            else
                gameMode = MODE_PVP
            ok
        ok
    ok

    if gameState = ST_PLAYING
        go_updateMouseHover()

        if gameMode = MODE_PVA and currentPlayer = CELL_WHITE
            aiTimer += dt
            if aiTimer >= aiDelay
                aiTimer = 0
                go_aiMove()
            ok
        else
            go_handleInput()
            go_handleMouse()
        ok

        go_updateDropAnims(dt)
        go_updateParticles(dt)
    ok

    if gameState = ST_SCORING
        if showTerritory = false
            showTerritory = true
            go_calculateTerritory()
        ok
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(0)
            gameState = ST_GAMEOVER
        ok
    ok

    if gameState = ST_GAMEOVER
        go_updateParticles(dt)
        if IsKeyPressed(KEY_R)
            go_initBoard()
            gameState = ST_PLAYING
        ok
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            go_initBoard()
            gameState = ST_START
        ok
    ok

    // Toggle territory display
    if IsKeyPressed(KEY_T)
        if showTerritory = true
            showTerritory = false
        else
            showTerritory = true
            go_calculateTerritory()
        ok
    ok

    // Toggle game mode
    if IsKeyPressed(KEY_M) and gameState = ST_PLAYING
        if gameMode = MODE_PVP
            gameMode = MODE_PVA
            go_showMsg("Mode: Player vs AI")
        else
            gameMode = MODE_PVP
            go_showMsg("Mode: Player vs Player")
        ok
    ok

    go_positionCamera()

    // --- Drawing ---
    BeginDrawing()
        ClearBackground(RAYLIBColor(18, 22, 30, 255))

        if gameState = ST_START
            go_drawTitleScreen()
        else
            BeginMode3D(camera)
                go_drawBoard3D()
                go_drawStones3D()
                go_drawCursor3D()
                go_drawLastMoveMarker3D()
                if showTerritory
                    go_drawTerritory3D()
                ok
                go_drawDropAnims3D()
                go_drawParticles3D()
            EndMode3D()

            go_drawHUD()
            go_drawMiniBoard()

            if gameState = ST_SCORING
                go_drawScoringOverlay()
            ok
            if gameState = ST_GAMEOVER
                go_drawGameOverOverlay()
            ok

            // Message overlay
            if msgTimer > 0
                go_drawMessage()
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

func go_initBoard
    board = list(BOARD_SZ)
    for r = 1 to BOARD_SZ
        board[r] = list(BOARD_SZ)
        for c = 1 to BOARD_SZ
            board[r][c] = CELL_EMPTY
        next
    next
    prevBoard = []
    cursorR = floor(BOARD_SZ / 2) + 1
    cursorC = floor(BOARD_SZ / 2) + 1
    currentPlayer = CELL_BLACK
    moveHistory = []
    blackCaptures = 0
    whiteCaptures = 0
    blackPassed = false
    whitePassed = false
    consecutivePasses = 0
    koR = 0
    koC = 0
    particles = []
    dropAnims = []
    territory = []
    showTerritory = false
    blackTerritory = 0
    whiteTerritory = 0
    lastMoveR = 0
    lastMoveC = 0
    msgTimer = 0
    aiTimer = 0

    stoneRadius = CELL_SZ * 0.40
    stoneHeight = CELL_SZ * 0.20

// =============================================================
// Input Handling
// =============================================================

func go_handleInput
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
        go_tryPlaceStone(cursorR, cursorC)
    ok

    // Pass
    if IsKeyPressed(KEY_P)
        go_pass()
    ok

    // Undo
    if IsKeyPressed(KEY_U)
        go_undo()
    ok

// =============================================================
// Mouse Handling
// =============================================================

func go_updateMouseHover
    mx = GetMouseX()
    my = GetMouseY()

    bestDist = 999999.0
    bestR = 0
    bestC = 0

    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            wx = go_cellToX(c)
            wz = go_cellToZ(r)
            go_projectToScreen(wx, 0.05, wz)
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

    threshDist = 1600
    if BOARD_SZ > 13 threshDist = 900 ok

    if bestDist < threshDist and bestR >= 1 and bestR <= BOARD_SZ
        mouseHoverR = bestR
        mouseHoverC = bestC
        cursorR = bestR
        cursorC = bestC
    else
        mouseHoverR = 0
        mouseHoverC = 0
    ok

func go_handleMouse
    if IsMouseButtonPressed(0)
        if mouseHoverR >= 1 and mouseHoverR <= BOARD_SZ and
           mouseHoverC >= 1 and mouseHoverC <= BOARD_SZ
            go_tryPlaceStone(mouseHoverR, mouseHoverC)
        ok
    ok

// =============================================================
// Stone Placement
// =============================================================

func go_tryPlaceStone r, c
    if board[r][c] != CELL_EMPTY
        go_showMsg("Position occupied!")
        return
    ok

    // Ko check
    if r = koR and c = koC
        go_showMsg("Ko! Cannot recapture immediately")
        return
    ok

    // Save board state for ko detection
    savedBoard = go_copyBoard()

    // Tentatively place stone
    board[r][c] = currentPlayer

    // Check for captures
    opponent = CELL_WHITE
    if currentPlayer = CELL_WHITE opponent = CELL_BLACK ok

    capturedStones = []

    // Check all 4 neighbors for opponent groups with no liberties
    neighbors = [[r-1,c],[r+1,c],[r,c-1],[r,c+1]]
    for i = 1 to len(neighbors)
        nr = neighbors[i][1]
        nc = neighbors[i][2]
        if nr >= 1 and nr <= BOARD_SZ and nc >= 1 and nc <= BOARD_SZ
            if board[nr][nc] = opponent
                group = []
                if go_countLiberties(nr, nc, group) = 0
                    for g = 1 to len(group)
                        add(capturedStones, [group[g][1], group[g][2]])
                    next
                ok
            ok
        ok
    next

    // Remove captured stones
    for i = 1 to len(capturedStones)
        cr = capturedStones[i][1]
        cc = capturedStones[i][2]
        board[cr][cc] = CELL_EMPTY
    next

    // Suicide check: if placing stone leaves own group with no liberties
    // and no captures were made, it's an illegal move
    myGroup = []
    if go_countLiberties(r, c, myGroup) = 0 and len(capturedStones) = 0
        // Illegal - restore board
        board = savedBoard
        go_showMsg("Suicide! Illegal move")
        return
    ok

    // Ko detection: set ko point if exactly 1 stone captured
    // and the capturing stone has exactly 1 stone in its group
    koR = 0
    koC = 0
    if len(capturedStones) = 1
        myGrp2 = []
        go_countLiberties(r, c, myGrp2)
        if len(myGrp2) = 1
            koR = capturedStones[1][1]
            koC = capturedStones[1][2]
        ok
    ok

    // Valid move! Record it
    prevBoard = savedBoard

    // Update captures
    if currentPlayer = CELL_BLACK
        blackCaptures += len(capturedStones)
    else
        whiteCaptures += len(capturedStones)
    ok

    // Save move to history
    add(moveHistory, [r, c, currentPlayer, capturedStones, savedBoard])

    // Reset pass tracking
    consecutivePasses = 0
    blackPassed = false
    whitePassed = false

    // Spawn drop animation
    add(dropAnims, [r, c, currentPlayer, 0.0])

    // Spawn capture particles
    for i = 1 to len(capturedStones)
        wx = go_cellToX(capturedStones[i][2])
        wz = go_cellToZ(capturedStones[i][1])
        go_spawnCaptureParticles(wx, wz, opponent)
    next

    // Mark last move
    lastMoveR = r
    lastMoveC = c

    // Switch player
    if currentPlayer = CELL_BLACK
        currentPlayer = CELL_WHITE
    else
        currentPlayer = CELL_BLACK
    ok

// =============================================================
// Pass
// =============================================================

func go_pass
    if currentPlayer = CELL_BLACK
        blackPassed = true
        go_showMsg("Black passes")
    else
        whitePassed = true
        go_showMsg("White passes")
    ok

    consecutivePasses += 1
    koR = 0
    koC = 0

    // Save pass in history
    add(moveHistory, [0, 0, currentPlayer, [], go_copyBoard()])

    // Switch player
    if currentPlayer = CELL_BLACK
        currentPlayer = CELL_WHITE
    else
        currentPlayer = CELL_BLACK
    ok

    // Two consecutive passes = game ends
    if consecutivePasses >= 2
        go_calculateTerritory()
        showTerritory = true
        gameState = ST_SCORING
    ok

// =============================================================
// Undo
// =============================================================

func go_undo
    if len(moveHistory) = 0
        go_showMsg("Nothing to undo!")
        return
    ok

    lastMove = moveHistory[len(moveHistory)]
    del(moveHistory, len(moveHistory))

    // Restore board from saved state
    board = lastMove[5]

    // Undo captures
    capturedStones = lastMove[4]
    if lastMove[3] = CELL_BLACK
        blackCaptures -= len(capturedStones)
        if blackCaptures < 0 blackCaptures = 0 ok
    else
        whiteCaptures -= len(capturedStones)
        if whiteCaptures < 0 whiteCaptures = 0 ok
    ok

    // Switch back
    currentPlayer = lastMove[3]

    // Reset ko
    koR = 0
    koC = 0

    // Reset pass
    consecutivePasses = 0
    blackPassed = false
    whitePassed = false

    // Update last move marker
    if len(moveHistory) > 0
        prev = moveHistory[len(moveHistory)]
        lastMoveR = prev[1]
        lastMoveC = prev[2]
    else
        lastMoveR = 0
        lastMoveC = 0
    ok

    go_showMsg("Move undone")

// =============================================================
// Liberty Counting (Flood Fill)
// =============================================================

func go_countLiberties r, c, group
    color = board[r][c]
    if color = CELL_EMPTY return 0 ok

    visited = list(BOARD_SZ)
    for i = 1 to BOARD_SZ
        visited[i] = list(BOARD_SZ)
        for j = 1 to BOARD_SZ
            visited[i][j] = 0
        next
    next

    liberties = 0
    // Use iterative flood fill
    stack = [[r, c]]
    visited[r][c] = 1
    add(group, [r, c])

    while len(stack) > 0
        cur = stack[len(stack)]
        del(stack, len(stack))
        cr = cur[1]
        cc = cur[2]

        neighbors = [[cr-1,cc],[cr+1,cc],[cr,cc-1],[cr,cc+1]]
        for i = 1 to len(neighbors)
            nr = neighbors[i][1]
            nc = neighbors[i][2]
            if nr >= 1 and nr <= BOARD_SZ and nc >= 1 and nc <= BOARD_SZ
                if visited[nr][nc] = 0
                    if board[nr][nc] = CELL_EMPTY
                        liberties += 1
                        visited[nr][nc] = 1
                    ok
                    if board[nr][nc] = color
                        visited[nr][nc] = 1
                        add(stack, [nr, nc])
                        add(group, [nr, nc])
                    ok
                ok
            ok
        next
    end

    return liberties

// =============================================================
// Territory Calculation
// =============================================================

func go_calculateTerritory
    territory = list(BOARD_SZ)
    for r = 1 to BOARD_SZ
        territory[r] = list(BOARD_SZ)
        for c = 1 to BOARD_SZ
            territory[r][c] = CELL_EMPTY
        next
    next

    visited = list(BOARD_SZ)
    for r = 1 to BOARD_SZ
        visited[r] = list(BOARD_SZ)
        for c = 1 to BOARD_SZ
            visited[r][c] = 0
        next
    next

    blackTerritory = 0
    whiteTerritory = 0

    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if board[r][c] = CELL_EMPTY and visited[r][c] = 0
                // Flood fill to find empty region
                region = []
                touchesBlack = false
                touchesWhite = false
                stack = [[r, c]]
                visited[r][c] = 1

                while len(stack) > 0
                    cur = stack[len(stack)]
                    del(stack, len(stack))
                    add(region, [cur[1], cur[2]])

                    neighbors = [[cur[1]-1,cur[2]],[cur[1]+1,cur[2]],
                                 [cur[1],cur[2]-1],[cur[1],cur[2]+1]]
                    for i = 1 to len(neighbors)
                        nr = neighbors[i][1]
                        nc = neighbors[i][2]
                        if nr >= 1 and nr <= BOARD_SZ and nc >= 1 and nc <= BOARD_SZ
                            if board[nr][nc] = CELL_BLACK
                                touchesBlack = true
                            ok
                            if board[nr][nc] = CELL_WHITE
                                touchesWhite = true
                            ok
                            if board[nr][nc] = CELL_EMPTY and visited[nr][nc] = 0
                                visited[nr][nc] = 1
                                add(stack, [nr, nc])
                            ok
                        ok
                    next
                end

                // Assign territory
                if touchesBlack = true and touchesWhite = false
                    for i = 1 to len(region)
                        territory[region[i][1]][region[i][2]] = CELL_BLACK
                        blackTerritory += 1
                    next
                ok
                if touchesWhite = true and touchesBlack = false
                    for i = 1 to len(region)
                        territory[region[i][1]][region[i][2]] = CELL_WHITE
                        whiteTerritory += 1
                    next
                ok
            ok
        next
    next

// =============================================================
// AI (Simple Heuristic)
// =============================================================

func go_aiMove
    // Priority: 1) Capture  2) Save own group  3) Territory-aware placement

    bestR = 0
    bestC = 0
    bestScore = -99999

    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if board[r][c] != CELL_EMPTY loop ok
            if r = koR and c = koC loop ok

            score = 0

            // Try placing
            saved = go_copyBoard()
            board[r][c] = CELL_WHITE

            // Check captures
            capCount = 0
            neighbors = [[r-1,c],[r+1,c],[r,c-1],[r,c+1]]
            for i = 1 to len(neighbors)
                nr = neighbors[i][1]
                nc = neighbors[i][2]
                if nr >= 1 and nr <= BOARD_SZ and nc >= 1 and nc <= BOARD_SZ
                    if board[nr][nc] = CELL_BLACK
                        grp = []
                        if go_countLiberties(nr, nc, grp) = 0
                            capCount += len(grp)
                        ok
                    ok
                ok
            next
            score += capCount * 15

            // Check if this saves our own group
            myGrp = []
            myLibs = go_countLiberties(r, c, myGrp)

            // Suicide check
            if myLibs = 0 and capCount = 0
                board = saved
                loop
            ok

            // Prefer moves near center
            centerDist = fabs(r - (BOARD_SZ+1)/2.0) + fabs(c - (BOARD_SZ+1)/2.0)
            score += (BOARD_SZ - centerDist) * 0.3

            // Prefer moves near existing stones
            adjCount = 0
            for i = 1 to len(neighbors)
                nr = neighbors[i][1]
                nc = neighbors[i][2]
                if nr >= 1 and nr <= BOARD_SZ and nc >= 1 and nc <= BOARD_SZ
                    if saved[nr][nc] != CELL_EMPTY
                        adjCount += 1
                    ok
                ok
            next
            if adjCount > 0 and adjCount < 4
                score += adjCount * 1.5
            ok

            // Check if move threatens opponent (reduces their liberties)
            board = saved
            board[r][c] = CELL_WHITE
            for i = 1 to len(neighbors)
                nr = neighbors[i][1]
                nc = neighbors[i][2]
                if nr >= 1 and nr <= BOARD_SZ and nc >= 1 and nc <= BOARD_SZ
                    if board[nr][nc] = CELL_BLACK
                        grp2 = []
                        libs2 = go_countLiberties(nr, nc, grp2)
                        if libs2 = 1
                            score += len(grp2) * 8   // Atari!
                        ok
                        if libs2 = 2
                            score += len(grp2) * 2
                        ok
                    ok
                ok
            next

            // Avoid self-atari
            myGrp3 = []
            myLibs3 = go_countLiberties(r, c, myGrp3)
            if myLibs3 = 1 and capCount = 0
                score -= 8
            ok

            // Prefer star points in opening
            if len(moveHistory) < BOARD_SZ * 2
                if go_isStarPoint(r, c)
                    score += 3
                ok
            ok

            // Add small randomness
            score += GetRandomValue(0, 100) / 100.0

            board = saved

            if score > bestScore
                bestScore = score
                bestR = r
                bestC = c
            ok
        next
    next

    if bestR > 0 and bestC > 0
        go_tryPlaceStone(bestR, bestC)
    else
        go_pass()
    ok

// =============================================================
// Board Helpers
// =============================================================

func go_copyBoard
    copy = list(BOARD_SZ)
    for r = 1 to BOARD_SZ
        copy[r] = list(BOARD_SZ)
        for c = 1 to BOARD_SZ
            copy[r][c] = board[r][c]
        next
    next
    return copy

func go_cellToX c
    return (c - 1) * CELL_SZ - (BOARD_SZ - 1) * CELL_SZ / 2

func go_cellToZ r
    return (r - 1) * CELL_SZ - (BOARD_SZ - 1) * CELL_SZ / 2

func go_isStarPoint r, c
    if BOARD_SZ = 9
        if (r = 3 or r = 5 or r = 7) and (c = 3 or c = 5 or c = 7)
            return true
        ok
    ok
    if BOARD_SZ = 13
        if (r = 4 or r = 7 or r = 10) and (c = 4 or c = 7 or c = 10)
            return true
        ok
    ok
    if BOARD_SZ = 19
        if (r = 4 or r = 10 or r = 16) and (c = 4 or c = 10 or c = 16)
            return true
        ok
    ok
    return false

func go_showMsg text
    msgText = text
    msgTimer = 2.0

// =============================================================
// Manual 3D to Screen Projection
// =============================================================

func go_projectToScreen wx, wy, wz
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

func go_updateDropAnims dt
    i = 1
    while i <= len(dropAnims)
        dropAnims[i][4] += dt * 4.0
        if dropAnims[i][4] >= 1.0
            del(dropAnims, i)
        else
            i += 1
        ok
    end

func go_drawDropAnims3D
    for i = 1 to len(dropAnims)
        r = dropAnims[i][1]
        c = dropAnims[i][2]
        player = dropAnims[i][3]
        prog = dropAnims[i][4]

        wx = go_cellToX(c)
        wz = go_cellToZ(r)

        // Bounce curve
        t = prog
        dropH = (1.0 - t) * (1.0 - t) * 2.5
        wy = stoneHeight / 2 + dropH

        if player = CELL_BLACK
            col = RAYLIBColor(30, 30, 35, 255)
        else
            col = RAYLIBColor(240, 235, 220, 255)
        ok

        DrawCylinder(Vector3(wx, wy - stoneHeight/2, wz),
                     stoneRadius, stoneRadius, stoneHeight, 24, col)
    next

// =============================================================
// Particles
// =============================================================

func go_spawnCaptureParticles wx, wz, player
    for i = 1 to 12
        vx = (GetRandomValue(-100, 100) / 100.0) * 2.0
        vy = (GetRandomValue(200, 500) / 100.0) * 1.5
        vz = (GetRandomValue(-100, 100) / 100.0) * 2.0
        if player = CELL_BLACK
            cr = GetRandomValue(20, 60)
            cg = GetRandomValue(20, 60)
            cb = GetRandomValue(30, 70)
        else
            cr = GetRandomValue(200, 255)
            cg = GetRandomValue(200, 240)
            cb = GetRandomValue(180, 220)
        ok
        add(particles, [wx, 0.3, wz, vx, vy, vz, 1.2, cr, cg, cb])
    next

func go_updateParticles dt
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

func go_drawParticles3D
    for i = 1 to len(particles)
        p = particles[i]
        alpha = floor((p[7] / 1.2) * 255)
        if alpha > 255 alpha = 255 ok
        if alpha < 0 alpha = 0 ok
        sz = 0.03 + p[7] * 0.05
        DrawSphereEx(
            Vector3(p[1], p[2], p[3]),
            sz, 4, 4,
            RAYLIBColor(p[8], p[9], p[10], alpha)
        )
    next

// =============================================================
// Camera
// =============================================================

func go_positionCamera
    boardW = BOARD_SZ * CELL_SZ
    maxDim = boardW

    goalX = 0  goalY = 0  goalZ = 0
    tgtX = 0   tgtY = 0   tgtZ = 0

    if cameraMode = CAM_FRONT
        goalX = 0
        goalY = maxDim * 0.75 + 4.0
        goalZ = maxDim * 0.65 + 4.0
        tgtX = 0
        tgtY = 0
        tgtZ = -0.5
    ok
    if cameraMode = CAM_ISOMETRIC
        goalX = maxDim * 0.55 + 2.0
        goalY = maxDim * 0.65 + 3.0
        goalZ = maxDim * 0.55 + 2.0
        tgtX = 0
        tgtY = 0
        tgtZ = 0
    ok
    if cameraMode = CAM_OVERHEAD
        goalX = 0
        goalY = maxDim + 6.0
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

func go_drawBoard3D
    boardW = BOARD_SZ * CELL_SZ
    halfBoard = (BOARD_SZ - 1) * CELL_SZ / 2

    // Wooden board surface (thick slab)
    slabH = 0.25
    DrawCube(Vector3(0, -slabH/2, 0),
             boardW + CELL_SZ * 0.6, slabH, boardW + CELL_SZ * 0.6,
             RAYLIBColor(200, 160, 80, 255))
    DrawCubeWires(Vector3(0, -slabH/2, 0),
                  boardW + CELL_SZ * 0.6, slabH, boardW + CELL_SZ * 0.6,
                  RAYLIBColor(160, 120, 50, 200))

    // Board surface (top) - slightly darker center
    DrawCube(Vector3(0, 0.005, 0),
             boardW - CELL_SZ * 0.1, 0.01, boardW - CELL_SZ * 0.1,
             RAYLIBColor(210, 170, 90, 255))

    // Border edge highlight
    bThick = 0.15
    bH = 0.12
    halfE = boardW / 2 + CELL_SZ * 0.15
    edgeCol = RAYLIBColor(150, 110, 40, 255)

    DrawCube(Vector3(0, bH/2, -halfE), boardW + CELL_SZ * 0.6, bH, bThick, edgeCol)
    DrawCube(Vector3(0, bH/2, halfE),  boardW + CELL_SZ * 0.6, bH, bThick, edgeCol)
    DrawCube(Vector3(-halfE, bH/2, 0), bThick, bH, boardW + CELL_SZ * 0.3, edgeCol)
    DrawCube(Vector3(halfE, bH/2, 0),  bThick, bH, boardW + CELL_SZ * 0.3, edgeCol)

    // Grid lines
    lineY = 0.015
    lineCol = RAYLIBColor(40, 30, 10, 200)

    for i = 1 to BOARD_SZ
        // Horizontal lines
        x1 = go_cellToX(1)
        x2 = go_cellToX(BOARD_SZ)
        z  = go_cellToZ(i)
        DrawLine3D(Vector3(x1, lineY, z), Vector3(x2, lineY, z), lineCol)

        // Vertical lines
        z1 = go_cellToZ(1)
        z2 = go_cellToZ(BOARD_SZ)
        x  = go_cellToX(i)
        DrawLine3D(Vector3(x, lineY, z1), Vector3(x, lineY, z2), lineCol)
    next

    // Star points (hoshi)
    starCol = RAYLIBColor(30, 20, 5, 255)
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if go_isStarPoint(r, c)
                wx = go_cellToX(c)
                wz = go_cellToZ(r)
                DrawCylinder(Vector3(wx, lineY, wz),
                             CELL_SZ * 0.08, CELL_SZ * 0.08, 0.02, 12,
                             starCol)
            ok
        next
    next

    // Table/floor beneath
    DrawPlane(Vector3(0, -slabH - 0.01, 0), Vector2(40, 40),
              RAYLIBColor(15, 18, 25, 255))

// =============================================================
// 3D Drawing: Stones
// =============================================================

func go_drawStones3D
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if board[r][c] = CELL_EMPTY loop ok

            wx = go_cellToX(c)
            wz = go_cellToZ(r)
            wy = stoneHeight / 2

            if board[r][c] = CELL_BLACK
                // Black stone - dark with subtle highlight
                DrawCylinder(Vector3(wx, 0.01, wz),
                             stoneRadius, stoneRadius * 0.95, stoneHeight, 24,
                             RAYLIBColor(25, 25, 30, 255))
                // Top highlight
                DrawCylinder(Vector3(wx, stoneHeight - 0.01, wz),
                             stoneRadius * 0.3, 0, 0.04, 12,
                             RAYLIBColor(60, 60, 70, 180))
                // Sheen
                DrawSphere(Vector3(wx - stoneRadius*0.2, stoneHeight + 0.02,
                           wz - stoneRadius*0.2),
                           stoneRadius * 0.12,
                           RAYLIBColor(120, 120, 140, 80))
            else
                // White stone - creamy with shadow
                DrawCylinder(Vector3(wx, 0.01, wz),
                             stoneRadius, stoneRadius * 0.95, stoneHeight, 24,
                             RAYLIBColor(235, 230, 215, 255))
                // Subtle edge ring
                DrawCylinder(Vector3(wx, 0.01, wz),
                             stoneRadius + 0.01, stoneRadius + 0.01, 0.01, 24,
                             RAYLIBColor(200, 190, 170, 150))
                // Top dome highlight
                DrawCylinder(Vector3(wx, stoneHeight - 0.01, wz),
                             stoneRadius * 0.3, 0, 0.04, 12,
                             RAYLIBColor(255, 250, 240, 200))
                // Sheen
                DrawSphere(Vector3(wx - stoneRadius*0.2, stoneHeight + 0.02,
                           wz - stoneRadius*0.2),
                           stoneRadius * 0.12,
                           RAYLIBColor(255, 255, 255, 100))
            ok
        next
    next

// =============================================================
// 3D Drawing: Cursor
// =============================================================

func go_drawCursor3D
    if gameState != ST_PLAYING return ok

    wx = go_cellToX(cursorC)
    wz = go_cellToZ(cursorR)

    // Show ghost stone if position is empty
    if board[cursorR][cursorC] = CELL_EMPTY
        pulse = 0.7 + sin(animTime * 4.0) * 0.3
        if currentPlayer = CELL_BLACK
            ghostCol = RAYLIBColor(25, 25, 30, floor(80 * pulse))
        else
            ghostCol = RAYLIBColor(235, 230, 215, floor(80 * pulse))
        ok
        DrawCylinder(Vector3(wx, 0.01, wz),
                     stoneRadius * 0.9, stoneRadius * 0.85, stoneHeight * 0.8, 20,
                     ghostCol)
    ok

    // Corner brackets
    hs = CELL_SZ * 0.45
    bracketLen = CELL_SZ * 0.18
    by = 0.02

    isValid = (board[cursorR][cursorC] = CELL_EMPTY)
    if isValid
        curCol = RAYLIBColor(80, 200, 80, 200)
    else
        curCol = RAYLIBColor(200, 60, 60, 150)
    ok

    DrawLine3D(Vector3(wx-hs, by, wz-hs), Vector3(wx-hs+bracketLen, by, wz-hs), curCol)
    DrawLine3D(Vector3(wx-hs, by, wz-hs), Vector3(wx-hs, by, wz-hs+bracketLen), curCol)
    DrawLine3D(Vector3(wx+hs, by, wz-hs), Vector3(wx+hs-bracketLen, by, wz-hs), curCol)
    DrawLine3D(Vector3(wx+hs, by, wz-hs), Vector3(wx+hs, by, wz-hs+bracketLen), curCol)
    DrawLine3D(Vector3(wx-hs, by, wz+hs), Vector3(wx-hs+bracketLen, by, wz+hs), curCol)
    DrawLine3D(Vector3(wx-hs, by, wz+hs), Vector3(wx-hs, by, wz+hs-bracketLen), curCol)
    DrawLine3D(Vector3(wx+hs, by, wz+hs), Vector3(wx+hs-bracketLen, by, wz+hs), curCol)
    DrawLine3D(Vector3(wx+hs, by, wz+hs), Vector3(wx+hs, by, wz+hs-bracketLen), curCol)

// =============================================================
// 3D Drawing: Last Move Marker
// =============================================================

func go_drawLastMoveMarker3D
    if lastMoveR = 0 return ok

    wx = go_cellToX(lastMoveC)
    wz = go_cellToZ(lastMoveR)

    pulse = 0.8 + sin(animTime * 3.0) * 0.2

    if board[lastMoveR][lastMoveC] = CELL_BLACK
        markCol = RAYLIBColor(255, 80, 80, floor(180 * pulse))
    else
        markCol = RAYLIBColor(80, 80, 255, floor(180 * pulse))
    ok

    DrawCircle3D(Vector3(wx, stoneHeight + 0.03, wz),
                 stoneRadius * 0.35 * pulse,
                 Vector3(1, 0, 0), 90.0, markCol)

// =============================================================
// 3D Drawing: Territory
// =============================================================

func go_drawTerritory3D
    if len(territory) = 0 return ok

    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if territory[r][c] = CELL_EMPTY loop ok

            wx = go_cellToX(c)
            wz = go_cellToZ(r)

            if territory[r][c] = CELL_BLACK
                tCol = RAYLIBColor(20, 20, 40, 100)
            else
                tCol = RAYLIBColor(240, 240, 240, 100)
            ok

            DrawCube(Vector3(wx, 0.02, wz),
                     CELL_SZ * 0.7, 0.04, CELL_SZ * 0.7, tCol)
        next
    next

// =============================================================
// HUD
// =============================================================

func go_drawHUD
    panelW = 230
    panelH = 175
    DrawRectangle(10, 30, panelW, panelH, Fade(BLACK, 0.75))
    DrawRectangleLines(10, 30, panelW, panelH, RAYLIBColor(180, 140, 60, 200))

    DrawText("3D GO (WEIQI)", 20, 38, 18, RAYLIBColor(220, 180, 80, 255))

    // Board size
    DrawText("Board: " + BOARD_SZ + "x" + BOARD_SZ, 20, 62, 14,
             RAYLIBColor(160, 180, 200, 200))

    // Current player
    if currentPlayer = CELL_BLACK
        pName = "BLACK"
        pCol = RAYLIBColor(150, 150, 170, 255)
    else
        pName = "WHITE"
        pCol = RAYLIBColor(240, 235, 215, 255)
    ok
    DrawText("Turn: " + pName, 20, 80, 16, pCol)

    // Mode
    if gameMode = MODE_PVP
        modeName = "PvP"
    else
        modeName = "vs AI"
    ok
    DrawText("Mode: " + modeName + "  [M]", 20, 100, 14,
             RAYLIBColor(140, 155, 175, 180))

    // Captures
    DrawText("Black captures: " + blackCaptures, 20, 120, 14,
             RAYLIBColor(150, 150, 170, 220))
    DrawText("White captures: " + whiteCaptures, 20, 138, 14,
             RAYLIBColor(240, 235, 215, 220))

    // Move count
    DrawText("Move: " + len(moveHistory), 20, 158, 14,
             RAYLIBColor(140, 155, 175, 180))

    // Komi
    DrawText("Komi: 6.5", 20, 176, 14,
             RAYLIBColor(120, 130, 150, 160))

    // Camera info
    camName = "FRONT"
    if cameraMode = CAM_ISOMETRIC camName = "ISOMETRIC" ok
    if cameraMode = CAM_OVERHEAD  camName = "OVERHEAD"  ok
    DrawRectangle(10, SCREEN_H - 60, 210, 25, Fade(BLACK, 0.6))
    DrawText("Cam: " + camName + "  [C] switch", 16, SCREEN_H - 56, 14,
             RAYLIBColor(150, 180, 210, 220))

    // Controls
    DrawRectangle(SCREEN_W - 480, SCREEN_H - 35, 470, 25, Fade(BLACK, 0.6))
    DrawText("Click/Enter: Place | P: Pass | U: Undo | T: Territory | R: Restart",
             SCREEN_W - 475, SCREEN_H - 30, 12, RAYLIBColor(150, 160, 180, 200))

// =============================================================
// Mini Board (2D overlay)
// =============================================================

func go_drawMiniBoard
    cellW = 10
    if BOARD_SZ <= 9 cellW = 14 ok
    if BOARD_SZ <= 13 and BOARD_SZ > 9 cellW = 11 ok
    mapW = BOARD_SZ * cellW
    mapH = BOARD_SZ * cellW
    mapX = SCREEN_W - mapW - 15
    mapY = 30

    DrawRectangle(mapX - 3, mapY - 3, mapW + 6, mapH + 6, Fade(BLACK, 0.8))
    DrawRectangleLines(mapX - 3, mapY - 3, mapW + 6, mapH + 6,
                       RAYLIBColor(180, 140, 60, 200))

    // Board background
    DrawRectangle(mapX, mapY, mapW, mapH, RAYLIBColor(200, 160, 80, 230))

    // Grid
    for i = 1 to BOARD_SZ
        sx1 = mapX + (0.5) * cellW
        sx2 = mapX + (BOARD_SZ - 0.5) * cellW
        sy  = mapY + (i - 0.5) * cellW
        DrawLine(floor(sx1), floor(sy), floor(sx2), floor(sy),
                 RAYLIBColor(80, 60, 20, 200))

        sy1 = mapY + (0.5) * cellW
        sy2 = mapY + (BOARD_SZ - 0.5) * cellW
        sx  = mapX + (i - 0.5) * cellW
        DrawLine(floor(sx), floor(sy1), floor(sx), floor(sy2),
                 RAYLIBColor(80, 60, 20, 200))
    next

    // Stones on minimap
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if board[r][c] != CELL_EMPTY
                sx = mapX + floor((c - 0.5) * cellW)
                sy = mapY + floor((r - 0.5) * cellW)
                rad = floor(cellW / 2.5)
                if board[r][c] = CELL_BLACK
                    DrawCircle(sx, sy, rad, RAYLIBColor(20, 20, 25, 255))
                else
                    DrawCircle(sx, sy, rad, RAYLIBColor(240, 235, 220, 255))
                    DrawCircleLines(sx, sy, rad, RAYLIBColor(180, 170, 150, 200))
                ok
            ok
        next
    next

    // Cursor on minimap
    cx = mapX + floor((cursorC - 0.5) * cellW)
    cy = mapY + floor((cursorR - 0.5) * cellW)
    DrawCircleLines(cx, cy, floor(cellW / 2), RAYLIBColor(255, 100, 80, 220))

    // Last move marker
    if lastMoveR > 0
        lx = mapX + floor((lastMoveC - 0.5) * cellW)
        ly = mapY + floor((lastMoveR - 0.5) * cellW)
        DrawCircleLines(lx, ly, floor(cellW / 3), RAYLIBColor(255, 50, 50, 255))
    ok

    DrawText("MAP", mapX + mapW/2 - 15, mapY - 16, 12,
             RAYLIBColor(180, 140, 60, 200))

// =============================================================
// Title Screen
// =============================================================

func go_drawTitleScreen
    DrawRectangleGradientV(0, 0, SCREEN_W, SCREEN_H,
        RAYLIBColor(15, 12, 8, 255), RAYLIBColor(25, 20, 12, 255))

    t1 = "3D GO (WEIQI)"
    t1w = MeasureText(t1, 55)
    DrawText(t1, (SCREEN_W - t1w)/2, 60, 55, RAYLIBColor(220, 180, 80, 255))

    t2 = "~ The Ancient Game of Strategy ~"
    t2w = MeasureText(t2, 17)
    DrawText(t2, (SCREEN_W - t2w)/2, 125, 17, RAYLIBColor(180, 150, 100, 230))

    // Decorative line
    lx1 = 200
    lx2 = SCREEN_W - 200
    ly = 155
    DrawLine(lx1, ly, lx2, ly, RAYLIBColor(180, 140, 60, 180))

    // Decorative stones
    DrawCircle(lx1 - 15, ly, 10, RAYLIBColor(25, 25, 30, 255))
    DrawCircle(lx2 + 15, ly, 10, RAYLIBColor(235, 230, 215, 255))
    DrawCircleLines(lx2 + 15, ly, 10, RAYLIBColor(180, 170, 150, 200))

    cy = 180
    cLines = [
        "Mouse Click / ENTER    -   Place stone",
        "Arrow Keys / WASD      -   Move cursor",
        "P                      -   Pass turn",
        "U                      -   Undo last move",
        "T                      -   Toggle territory view",
        "R                      -   Restart game",
        "C                      -   Cycle camera view",
        "M                      -   Toggle PvP / vs AI",
        "",
        "Board Sizes:",
        "  1 = 9x9 (Beginner)    2 = 13x13    3 = 19x19 (Standard)",
        "",
        "Rules:",
        "  Place stones to surround territory and capture opponents",
        "  Game ends when both players pass consecutively",
        "  Score = Territory + Captures + Komi (6.5 for White)"
    ]
    for i = 1 to len(cLines)
        lw = MeasureText(cLines[i], 14)
        if i >= 10
            col = RAYLIBColor(220, 180, 100, 210)
        else
            col = RAYLIBColor(150, 170, 200, 230)
        ok
        DrawText(cLines[i], (SCREEN_W - lw)/2, cy + (i - 1) * 21, 14, col)
    next

    // Current settings
    settingY = 530
    modeName = "Player vs Player"
    if gameMode = MODE_PVA modeName = "Player vs AI" ok
    st = "Board: " + BOARD_SZ + "x" + BOARD_SZ + "  |  Mode: " + modeName
    stw = MeasureText(st, 16)
    DrawText(st, (SCREEN_W - stw)/2, settingY, 16, RAYLIBColor(200, 180, 120, 230))

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
// Scoring Overlay
// =============================================================

func go_drawScoringOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.55))

    g1 = "GAME FINISHED - SCORING"
    g1w = MeasureText(g1, 38)
    DrawText(g1, (SCREEN_W - g1w)/2, 150, 38, RAYLIBColor(220, 180, 80, 255))

    blackScore = blackTerritory + blackCaptures
    whiteScore = whiteTerritory + whiteCaptures + KOMI

    cy = 210
    DrawText("BLACK:", 300, cy, 22, RAYLIBColor(150, 150, 170, 255))
    DrawText("Territory:  " + blackTerritory, 320, cy + 30, 16,
             RAYLIBColor(160, 160, 180, 220))
    DrawText("Captures:   " + blackCaptures, 320, cy + 52, 16,
             RAYLIBColor(160, 160, 180, 220))
    DrawText("Total:      " + blackScore, 320, cy + 78, 18,
             RAYLIBColor(200, 200, 220, 255))

    DrawText("WHITE:", 550, cy, 22, RAYLIBColor(240, 235, 215, 255))
    DrawText("Territory:  " + whiteTerritory, 570, cy + 30, 16,
             RAYLIBColor(230, 225, 210, 220))
    DrawText("Captures:   " + whiteCaptures, 570, cy + 52, 16,
             RAYLIBColor(230, 225, 210, 220))
    DrawText("Komi:       6.5", 570, cy + 74, 16,
             RAYLIBColor(230, 225, 210, 220))
    // Format whiteScore carefully
    wScoreInt = floor(whiteScore)
    wScoreFrac = whiteScore - wScoreInt
    if wScoreFrac > 0.4
        wScoreStr = "" + wScoreInt + ".5"
    else
        wScoreStr = "" + wScoreInt
    ok
    DrawText("Total:      " + wScoreStr, 570, cy + 100, 18,
             RAYLIBColor(255, 250, 235, 255))

    if blackScore > whiteScore
        winner = "BLACK WINS!"
        wCol = RAYLIBColor(150, 150, 200, 255)
    else
        winner = "WHITE WINS!"
        wCol = RAYLIBColor(255, 250, 230, 255)
    ok

    ww = MeasureText(winner, 36)
    DrawText(winner, (SCREEN_W - ww)/2, cy + 140, 36, wCol)

    if floor(animTime * 2) % 2 = 0
        nt = "Click or ENTER to continue"
        ntw = MeasureText(nt, 18)
        DrawText(nt, (SCREEN_W - ntw)/2, cy + 195, 18, WHITE)
    ok

// =============================================================
// Game Over Overlay
// =============================================================

func go_drawGameOverOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.5))

    blackScore = blackTerritory + blackCaptures
    whiteScore = whiteTerritory + whiteCaptures + KOMI

    if blackScore > whiteScore
        winner = "BLACK WINS!"
        wCol = RAYLIBColor(150, 150, 200, 255)
    else
        winner = "WHITE WINS!"
        wCol = RAYLIBColor(255, 250, 230, 255)
    ok

    ww = MeasureText(winner, 52)
    DrawText(winner, (SCREEN_W - ww)/2, 220, 52, wCol)

    bStr = "Black: " + blackScore
    wScoreInt = floor(whiteScore)
    wScoreFrac = whiteScore - wScoreInt
    if wScoreFrac > 0.4
        wStr = "White: " + wScoreInt + ".5"
    else
        wStr = "White: " + wScoreInt
    ok

    bw = MeasureText(bStr, 22)
    DrawText(bStr, (SCREEN_W - bw)/2, 290, 22, RAYLIBColor(150, 150, 170, 255))
    ww2 = MeasureText(wStr, 22)
    DrawText(wStr, (SCREEN_W - ww2)/2, 320, 22, RAYLIBColor(240, 235, 215, 255))

    rt = "Press R to play again  |  ENTER for title screen"
    rtw = MeasureText(rt, 16)
    if floor(animTime * 2) % 2 = 0
        DrawText(rt, (SCREEN_W - rtw)/2, 370, 16, WHITE)
    ok

    st = "1: 9x9  |  2: 13x13  |  3: 19x19"
    stw = MeasureText(st, 14)
    DrawText(st, (SCREEN_W - stw)/2, 400, 14, RAYLIBColor(180, 160, 120, 200))

// =============================================================
// Message Overlay
// =============================================================

func go_drawMessage
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
