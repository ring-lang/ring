/*
**  3D Checkers (Draughts) Game - Using RingRayLib
**  ================================================
**  Classic checkers on a full 3D board! Select and move pieces
**  diagonally, jump to capture opponents, and crown kings!
**
**  Controls:
**    Arrow Keys / WASD  - Move cursor on the board
**    ENTER / SPACE      - Select piece / Confirm move
**    Mouse Click        - Select piece / Move to cell
**    U                  - Undo last move
**    H                  - Toggle valid move hints
**    R                  - Restart game
**    C                  - Cycle camera views
**    1                  - Player vs Player mode
**    2                  - Player vs AI mode
**    ESC                - Exit
**
**  Rules:
**    - Pieces move diagonally forward on dark squares
**    - Jump over opponent pieces to capture them
**    - Multiple jumps allowed in one turn (mandatory)
**    - Reaching the opposite end promotes to King
**    - Kings can move and jump diagonally in all directions
**    - If a capture is available, it MUST be taken
**    - Player with no pieces or no valid moves loses
**
**  Features:
**    - Full 3D rendered 8x8 board
**    - Smooth piece movement and jump animations
**    - Capture animation (piece sinks and fades)
**    - King crown with golden ring
**    - Valid move highlighting
**    - Simple AI opponent
**    - Three camera modes
**    - Undo system
**    - Particle effects
**    - Mini-board overlay
**    - Mouse + keyboard support
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W        = 1024
SCREEN_H        = 768

BOARD_SZ        = 8
CELL_SZ         = 1.5
PIECE_RAD       = 0.52
PIECE_H         = 0.22

// Cell states
CELL_EMPTY      = 0
CELL_RED        = 1
CELL_BLACK      = 2
CELL_RED_K      = 3     // Red King
CELL_BLACK_K    = 4     // Black King

// Game states
ST_START        = 1
ST_PLAYING      = 2
ST_ANIMATING    = 3     // Move/jump animation in progress
ST_GAMEOVER     = 4

// Camera modes
CAM_FRONT       = 1
CAM_ISOMETRIC   = 2
CAM_OVERHEAD    = 3
CAM_COUNT       = 3

// Animation
MOVE_SPEED      = 6.0
JUMP_ARC_H      = 1.8
CAPTURE_SPEED   = 3.0

// Game modes
MODE_PVP        = 1
MODE_PVA        = 2

// =============================================================
// Global Variables
// =============================================================

board           = []
currentPlayer   = CELL_RED      // Red goes first
cursorR         = 6
cursorC         = 1
gameState       = ST_START
animTime        = 0.0
gameMode        = MODE_PVP
showHints       = true
winner          = 0

// Selection
selectedR       = 0
selectedC       = 0
validMoves      = []    // [[destR, destC, jumpR, jumpC], ...]
                        // jumpR/jumpC = 0 if not a jump

// Multi-jump tracking
multiJumpR      = 0
multiJumpC      = 0
multiJumpActive = false

// Move animation
animActive      = false
animFromX       = 0.0
animFromZ       = 0.0
animToX         = 0.0
animToZ         = 0.0
animProgress    = 0.0
animPieceType   = 0
animJump        = false     // True if jump (arc animation)

// Capture animation
captureAnimActive = false
captureAnimX    = 0.0
captureAnimZ    = 0.0
captureAnimProgress = 0.0
captureAnimType = 0

// Crown animation
crownAnimActive = false
crownAnimR      = 0
crownAnimC      = 0
crownAnimProgress = 0.0

// Undo stack
undoStack       = []

// Camera
cameraMode      = CAM_FRONT
camPosX = 0.0   camPosY = 14.0  camPosZ = 14.0
camTgtX = 0.0   camTgtY = 0.0   camTgtZ = 0.0

// Mouse
mouseHoverR     = 0
mouseHoverC     = 0
projScreenX     = 0.0
projScreenY     = 0.0

// Particles
particles       = []

// Score/counts
redCount        = 12
blackCount      = 12

// AI thinking delay
aiThinkTimer    = 0.0
aiThinkDelay    = 0.4

// Post-animation tracking
animDestR       = 0
animDestC       = 0
animWasJump     = false
animWasCrowned  = false

// =============================================================
// Initialize
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Ring 3D Checkers - RingRayLib")
SetTargetFPS(60)

chk_resetGame()

// =============================================================
// Main Game Loop
// =============================================================

while !WindowShouldClose()

    dt = GetFrameTime()
    animTime += dt

    // --- Global input ---
    if IsKeyPressed(KEY_C)
        cameraMode += 1
        if cameraMode > CAM_COUNT cameraMode = CAM_FRONT ok
    ok

    if IsKeyPressed(KEY_R)
        chk_resetGame()
        gameState = ST_PLAYING
    ok

    if IsKeyPressed(KEY_H)
        showHints = !showHints
    ok

    if IsKeyPressed(KEY_ONE)
        gameMode = MODE_PVP
        chk_resetGame()
        gameState = ST_PLAYING
    ok

    if IsKeyPressed(KEY_TWO)
        gameMode = MODE_PVA
        chk_resetGame()
        gameState = ST_PLAYING
    ok

    // --- State updates ---
    if gameState = ST_START
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(0)
            chk_resetGame()
            gameState = ST_PLAYING
        ok
        // Allow mode selection on title screen to also start
        if IsKeyPressed(KEY_ONE)
            gameMode = MODE_PVP
            chk_resetGame()
            gameState = ST_PLAYING
        ok
        if IsKeyPressed(KEY_TWO)
            gameMode = MODE_PVA
            chk_resetGame()
            gameState = ST_PLAYING
        ok
    ok

    if gameState = ST_PLAYING
        chk_updateMouseHover()

        // AI turn
        if gameMode = MODE_PVA and currentPlayer = CELL_BLACK
            aiThinkTimer += dt
            if aiThinkTimer >= aiThinkDelay
                chk_aiMove()
                aiThinkTimer = 0.0
            ok
        else
            chk_handleInput()
            chk_handleMouse()
        ok
    ok

    if gameState = ST_ANIMATING
        chk_updateAnimation(dt)
    ok

    if gameState = ST_GAMEOVER
        chk_updateParticles(dt)
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(0)
            chk_resetGame()
            gameState = ST_PLAYING
        ok
    ok

    chk_positionCamera()
    chk_updateParticles(dt)

    // --- Drawing ---
    BeginDrawing()
        ClearBackground(RAYLIBColor(18, 14, 22, 255))

        if gameState = ST_START
            chk_drawTitleScreen()
        else
            BeginMode3D(
                Camera3D(
                    camPosX, camPosY, camPosZ,
                    camTgtX, camTgtY, camTgtZ,
                    0, 1, 0, 45.0, 0
                )
            )
                chk_drawBoard3D()
                chk_drawPieces3D()
                chk_drawCursor3D()
                chk_drawAnimatingPiece()
                chk_drawCaptureAnim()
                chk_drawParticles3D()
            EndMode3D()

            chk_drawHUD()
            chk_drawMiniBoard()

            if gameState = ST_GAMEOVER
                chk_drawGameOverOverlay()
            ok
        ok

        DrawFPS(10, 10)
    EndDrawing()

end

CloseWindow()

// =============================================================
// Reset Game
// =============================================================

func chk_resetGame
    board = list(BOARD_SZ)
    for r = 1 to BOARD_SZ
        board[r] = list(BOARD_SZ)
        for c = 1 to BOARD_SZ
            board[r][c] = CELL_EMPTY
        next
    next

    // Place pieces on dark squares
    // Black pieces: rows 1-3 (top)
    for r = 1 to 3
        for c = 1 to BOARD_SZ
            if (r + c) % 2 = 1
                board[r][c] = CELL_BLACK
            ok
        next
    next

    // Red pieces: rows 6-8 (bottom)
    for r = 6 to 8
        for c = 1 to BOARD_SZ
            if (r + c) % 2 = 1
                board[r][c] = CELL_RED
            ok
        next
    next

    currentPlayer = CELL_RED
    selectedR = 0
    selectedC = 0
    validMoves = []
    multiJumpActive = false
    multiJumpR = 0
    multiJumpC = 0
    undoStack = []
    particles = []
    animActive = false
    captureAnimActive = false
    crownAnimActive = false
    crownAnimProgress = 0.0
    winner = 0
    aiThinkTimer = 0.0
    cursorR = 6
    cursorC = 1
    chk_countPieces()

// =============================================================
// Piece Helpers
// =============================================================

func chk_isRed p
    return p = CELL_RED or p = CELL_RED_K

func chk_isBlack p
    return p = CELL_BLACK or p = CELL_BLACK_K

func chk_isKing p
    return p = CELL_RED_K or p = CELL_BLACK_K

func chk_isOwn p, player
    if player = CELL_RED
        return chk_isRed(p)
    ok
    if player = CELL_BLACK
        return chk_isBlack(p)
    ok
    return false

func chk_isEnemy p, player
    if player = CELL_RED
        return chk_isBlack(p)
    ok
    if player = CELL_BLACK
        return chk_isRed(p)
    ok
    return false

func chk_countPieces
    redCount = 0
    blackCount = 0
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if chk_isRed(board[r][c]) redCount += 1 ok
            if chk_isBlack(board[r][c]) blackCount += 1 ok
        next
    next

// =============================================================
// Move Generation
// =============================================================

func chk_getMovesForPiece r, c
    // Returns list of [destR, destC, jumpR, jumpC]
    // jumpR/jumpC = captured piece position (0 if simple move)
    moves = []
    piece = board[r][c]
    if piece = CELL_EMPTY return moves ok

    // Determine allowed directions
    dirs = []
    if piece = CELL_RED or piece = CELL_RED_K
        // Red moves UP (decreasing row)
        add(dirs, [-1, -1])
        add(dirs, [-1,  1])
    ok
    if piece = CELL_BLACK or piece = CELL_BLACK_K
        // Black moves DOWN (increasing row)
        add(dirs, [ 1, -1])
        add(dirs, [ 1,  1])
    ok
    // Kings also go backward
    if piece = CELL_RED_K
        add(dirs, [ 1, -1])
        add(dirs, [ 1,  1])
    ok
    if piece = CELL_BLACK_K
        add(dirs, [-1, -1])
        add(dirs, [-1,  1])
    ok

    player = CELL_RED
    if chk_isBlack(piece) player = CELL_BLACK ok

    for i = 1 to len(dirs)
        dr = dirs[i][1]
        dc = dirs[i][2]

        // Simple move
        nr = r + dr
        nc = c + dc
        if nr >= 1 and nr <= BOARD_SZ and nc >= 1 and nc <= BOARD_SZ
            if board[nr][nc] = CELL_EMPTY
                add(moves, [nr, nc, 0, 0])
            ok
        ok

        // Jump
        jr = r + dr * 2
        jc = c + dc * 2
        if jr >= 1 and jr <= BOARD_SZ and jc >= 1 and jc <= BOARD_SZ
            if nr >= 1 and nr <= BOARD_SZ and nc >= 1 and nc <= BOARD_SZ
                if chk_isEnemy(board[nr][nc], player) and board[jr][jc] = CELL_EMPTY
                    add(moves, [jr, jc, nr, nc])
                ok
            ok
        ok
    next

    return moves

func chk_getJumpsForPiece r, c
    // Returns only jump moves
    allMoves = chk_getMovesForPiece(r, c)
    jumps = []
    for i = 1 to len(allMoves)
        if allMoves[i][3] != 0
            add(jumps, allMoves[i])
        ok
    next
    return jumps

func chk_playerHasJumps player
    // Check if any piece of this player can jump
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if chk_isOwn(board[r][c], player)
                jumps = chk_getJumpsForPiece(r, c)
                if len(jumps) > 0
                    return true
                ok
            ok
        next
    next
    return false

func chk_playerHasMoves player
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if chk_isOwn(board[r][c], player)
                moves = chk_getMovesForPiece(r, c)
                if len(moves) > 0
                    return true
                ok
            ok
        next
    next
    return false

func chk_getValidMovesForSelection r, c
    // Returns valid moves for selected piece, enforcing mandatory jumps
    piece = board[r][c]
    if !chk_isOwn(piece, currentPlayer) return [] ok

    hasJumps = chk_playerHasJumps(currentPlayer)
    allMoves = chk_getMovesForPiece(r, c)

    if hasJumps
        // Must jump: only return jump moves
        result = []
        for i = 1 to len(allMoves)
            if allMoves[i][3] != 0
                add(result, allMoves[i])
            ok
        next
        return result
    ok

    return allMoves

// =============================================================
// Input Handling
// =============================================================

func chk_handleInput
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

    // Select / Move
    if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
        chk_handleSelection(cursorR, cursorC)
    ok

    // Undo
    if IsKeyPressed(KEY_U)
        chk_undo()
    ok

// =============================================================
// Mouse Handling
// =============================================================

func chk_updateMouseHover
    mx = GetMouseX()
    my = GetMouseY()

    bestDist = 999999.0
    bestR = 0
    bestC = 0

    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            wx = chk_cellToX(c)
            wz = chk_cellToZ(r)
            chk_projectToScreen(wx, 0.1, wz)
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

    if bestDist < 2500 and bestR >= 1 and bestR <= BOARD_SZ
        mouseHoverR = bestR
        mouseHoverC = bestC
        cursorR = bestR
        cursorC = bestC
    else
        mouseHoverR = 0
        mouseHoverC = 0
    ok

func chk_handleMouse
    if IsMouseButtonPressed(0)
        if mouseHoverR >= 1 and mouseHoverR <= BOARD_SZ and
           mouseHoverC >= 1 and mouseHoverC <= BOARD_SZ
            chk_handleSelection(mouseHoverR, mouseHoverC)
        ok
    ok
    // Right click deselect
    if IsMouseButtonPressed(1)
        if !multiJumpActive
            selectedR = 0
            selectedC = 0
            validMoves = []
        ok
    ok

// =============================================================
// Selection & Move Logic
// =============================================================

func chk_handleSelection r, c
    // If in multi-jump, only allow continuing the jump chain
    if multiJumpActive
        // Check if clicked cell is a valid jump destination
        for i = 1 to len(validMoves)
            if validMoves[i][1] = r and validMoves[i][2] = c
                chk_executeMove(multiJumpR, multiJumpC, validMoves[i])
                return
            ok
        next
        return  // Must continue multi-jump
    ok

    // If a piece is selected, check if clicking a valid destination
    if selectedR > 0 and selectedC > 0
        for i = 1 to len(validMoves)
            if validMoves[i][1] = r and validMoves[i][2] = c
                chk_executeMove(selectedR, selectedC, validMoves[i])
                return
            ok
        next
    ok

    // Try selecting a piece
    if chk_isOwn(board[r][c], currentPlayer)
        moves = chk_getValidMovesForSelection(r, c)
        if len(moves) > 0
            selectedR = r
            selectedC = c
            validMoves = moves
        else
            selectedR = 0
            selectedC = 0
            validMoves = []
        ok
    else
        // Clicked empty or enemy: deselect
        selectedR = 0
        selectedC = 0
        validMoves = []
    ok

func chk_executeMove fromR, fromC, move
    destR = move[1]
    destC = move[2]
    jumpR = move[3]
    jumpC = move[4]
    isJump = (jumpR != 0)

    // Save undo state
    chk_saveUndo()

    // Start animation
    animActive = true
    animFromX = chk_cellToX(fromC)
    animFromZ = chk_cellToZ(fromR)
    animToX = chk_cellToX(destC)
    animToZ = chk_cellToZ(destR)
    animProgress = 0.0
    animPieceType = board[fromR][fromC]
    animJump = isJump

    // Move the piece in data
    board[destR][destC] = board[fromR][fromC]
    board[fromR][fromC] = CELL_EMPTY

    // Capture
    if isJump
        captureAnimActive = true
        captureAnimX = chk_cellToX(jumpC)
        captureAnimZ = chk_cellToZ(jumpR)
        captureAnimProgress = 0.0
        captureAnimType = board[jumpR][jumpC]
        board[jumpR][jumpC] = CELL_EMPTY
        chk_spawnCaptureParticles(jumpR, jumpC)
    ok

    // Check for king promotion
    crownAnimActive = false
    if board[destR][destC] = CELL_RED and destR = 1
        board[destR][destC] = CELL_RED_K
        crownAnimActive = true
        crownAnimR = destR
        crownAnimC = destC
        crownAnimProgress = 0.0
    ok
    if board[destR][destC] = CELL_BLACK and destR = BOARD_SZ
        board[destR][destC] = CELL_BLACK_K
        crownAnimActive = true
        crownAnimR = destR
        crownAnimC = destC
        crownAnimProgress = 0.0
    ok

    // Deselect
    selectedR = 0
    selectedC = 0
    validMoves = []

    // Switch to animation state
    gameState = ST_ANIMATING

    // Store move info for post-animation logic
    animDestR = destR
    animDestC = destC
    animWasJump = isJump
    animWasCrowned = crownAnimActive

func chk_saveUndo
    snapshot = list(BOARD_SZ)
    for r = 1 to BOARD_SZ
        snapshot[r] = list(BOARD_SZ)
        for c = 1 to BOARD_SZ
            snapshot[r][c] = board[r][c]
        next
    next
    add(undoStack, [snapshot, currentPlayer, multiJumpActive, multiJumpR, multiJumpC])

func chk_undo
    if len(undoStack) = 0 return ok
    state = undoStack[len(undoStack)]
    del(undoStack, len(undoStack))
    snapshot = state[1]
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            board[r][c] = snapshot[r][c]
        next
    next
    currentPlayer = state[2]
    multiJumpActive = state[3]
    multiJumpR = state[4]
    multiJumpC = state[5]
    selectedR = 0
    selectedC = 0
    validMoves = []
    animActive = false
    captureAnimActive = false
    crownAnimActive = false
    chk_countPieces()

    // If restoring to multi-jump, recalculate valid jumps
    if multiJumpActive
        validMoves = chk_getJumpsForPiece(multiJumpR, multiJumpC)
        selectedR = multiJumpR
        selectedC = multiJumpC
    ok

// =============================================================
// Animation Update
// =============================================================

func chk_updateAnimation dt
    if !animActive return ok

    animProgress += MOVE_SPEED * dt
    if animProgress >= 1.0
        animProgress = 1.0
        animActive = false

        // Spawn landing particles
        chk_spawnMoveParticles(animDestR, animDestC)

        // Update capture animation
        if captureAnimActive
            captureAnimProgress += CAPTURE_SPEED * dt
        ok

        // Crown animation
        if crownAnimActive
            crownAnimProgress += 2.0 * dt
        ok

        // Post-move logic
        chk_countPieces()

        // Check for multi-jump
        if animWasJump and !animWasCrowned
            jumps = chk_getJumpsForPiece(animDestR, animDestC)
            if len(jumps) > 0
                // Continue multi-jump
                multiJumpActive = true
                multiJumpR = animDestR
                multiJumpC = animDestC
                selectedR = animDestR
                selectedC = animDestC
                validMoves = jumps
                gameState = ST_PLAYING
                return
            ok
        ok

        // End turn
        multiJumpActive = false
        multiJumpR = 0
        multiJumpC = 0
        chk_switchPlayer()
        gameState = ST_PLAYING

        // Check win condition
        chk_checkWin()
    ok

    // Update capture animation independently
    if captureAnimActive
        captureAnimProgress += CAPTURE_SPEED * dt
        if captureAnimProgress >= 1.0
            captureAnimActive = false
        ok
    ok

    // Crown animation
    if crownAnimActive
        crownAnimProgress += 2.0 * dt
        if crownAnimProgress > 1.0
            crownAnimProgress = 1.0
        ok
    ok

func chk_switchPlayer
    if currentPlayer = CELL_RED
        currentPlayer = CELL_BLACK
    else
        currentPlayer = CELL_RED
    ok
    selectedR = 0
    selectedC = 0
    validMoves = []
    aiThinkTimer = 0.0

func chk_checkWin
    if redCount = 0
        winner = CELL_BLACK
        gameState = ST_GAMEOVER
        chk_spawnWinParticles()
        return
    ok
    if blackCount = 0
        winner = CELL_RED
        gameState = ST_GAMEOVER
        chk_spawnWinParticles()
        return
    ok
    if !chk_playerHasMoves(currentPlayer)
        // Current player has no moves - they lose
        if currentPlayer = CELL_RED
            winner = CELL_BLACK
        else
            winner = CELL_RED
        ok
        gameState = ST_GAMEOVER
        chk_spawnWinParticles()
    ok

// =============================================================
// AI (Simple greedy)
// =============================================================

func chk_aiMove
    // If multi-jump in progress, continue it
    if multiJumpActive
        jumps = chk_getJumpsForPiece(multiJumpR, multiJumpC)
        if len(jumps) > 0
            // Pick random jump
            idx = GetRandomValue(1, len(jumps))
            chk_executeMove(multiJumpR, multiJumpC, jumps[idx])
            return
        ok
        // No more jumps: end turn
        multiJumpActive = false
        chk_switchPlayer()
        chk_checkWin()
        return
    ok

    // Collect all possible moves
    allMoves = []   // [[fromR, fromC, destR, destC, jumpR, jumpC, score], ...]
    hasJumps = chk_playerHasJumps(CELL_BLACK)

    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if chk_isBlack(board[r][c])
                moves = chk_getMovesForPiece(r, c)
                for i = 1 to len(moves)
                    isJump = (moves[i][3] != 0)
                    if hasJumps and !isJump
                        // Must jump - skip non-jumps
                    else
                        score = chk_aiScoreMove(r, c, moves[i])
                        add(allMoves, [r, c, moves[i][1], moves[i][2],
                                       moves[i][3], moves[i][4], score])
                    ok
                next
            ok
        next
    next

    if len(allMoves) = 0
        // No moves: switch turn, will trigger game over
        chk_switchPlayer()
        chk_checkWin()
        return
    ok

    // Find best score
    bestScore = -9999
    for i = 1 to len(allMoves)
        if allMoves[i][7] > bestScore
            bestScore = allMoves[i][7]
        ok
    next

    // Collect all moves with best score
    bestMoves = []
    for i = 1 to len(allMoves)
        if allMoves[i][7] = bestScore
            add(bestMoves, allMoves[i])
        ok
    next

    // Pick random among best
    idx = GetRandomValue(1, len(bestMoves))
    chosen = bestMoves[idx]
    move = [chosen[3], chosen[4], chosen[5], chosen[6]]
    chk_executeMove(chosen[1], chosen[2], move)

func chk_aiScoreMove fromR, fromC, move
    score = 0
    destR = move[1]
    destC = move[2]
    isJump = (move[3] != 0)

    // Captures are very valuable
    if isJump score += 10 ok

    // Capturing a king is extra valuable
    if isJump
        capPiece = board[move[3]][move[4]]
        if chk_isKing(capPiece) score += 5 ok
    ok

    // Getting kinged
    if !chk_isKing(board[fromR][fromC]) and destR = BOARD_SZ
        score += 8
    ok

    // Advance toward king row
    score += destR

    // Prefer edges (harder to capture)
    if destC = 1 or destC = BOARD_SZ score += 2 ok

    // Avoid being in capture danger (simple check)
    // Simulate move and check if piece can be captured
    origDest = board[destR][destC]
    origFrom = board[fromR][fromC]
    board[destR][destC] = origFrom
    board[fromR][fromC] = CELL_EMPTY
    if isJump
        origCap = board[move[3]][move[4]]
        board[move[3]][move[4]] = CELL_EMPTY
    ok

    // Check if opponent can jump this piece
    inDanger = false
    oppDirs = [[-1,-1], [-1,1], [1,-1], [1,1]]
    for d = 1 to len(oppDirs)
        adjR = destR + oppDirs[d][1]
        adjC = destC + oppDirs[d][2]
        landR = destR - oppDirs[d][1]
        landC = destC - oppDirs[d][2]
        if adjR >= 1 and adjR <= BOARD_SZ and adjC >= 1 and adjC <= BOARD_SZ and
           landR >= 1 and landR <= BOARD_SZ and landC >= 1 and landC <= BOARD_SZ
            if chk_isRed(board[adjR][adjC]) and board[landR][landC] = CELL_EMPTY
                inDanger = true
            ok
        ok
    next

    // Restore board
    board[fromR][fromC] = origFrom
    board[destR][destC] = origDest
    if isJump
        board[move[3]][move[4]] = origCap
    ok

    if inDanger score -= 6 ok

    return score

// =============================================================
// Coordinate Helpers
// =============================================================

func chk_cellToX c
    return (c - 1) * CELL_SZ - (BOARD_SZ - 1) * CELL_SZ / 2

func chk_cellToZ r
    return (r - 1) * CELL_SZ - (BOARD_SZ - 1) * CELL_SZ / 2

// =============================================================
// Manual 3D to Screen Projection
// =============================================================

func chk_projectToScreen wx, wy, wz
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

    rightX = fwdY * 0 - fwdZ * 1
    rightY = fwdZ * 0 - fwdX * 0
    rightZ = fwdX * 1 - fwdY * 0
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

func chk_spawnMoveParticles r, c
    wx = chk_cellToX(c)
    wz = chk_cellToZ(r)
    for i = 1 to 8
        vx = (GetRandomValue(-100, 100) / 100.0) * 1.0
        vy = (GetRandomValue(50, 200) / 100.0) * 0.8
        vz = (GetRandomValue(-100, 100) / 100.0) * 1.0
        add(particles, [wx, 0.15, wz, vx, vy, vz, 0.8,
                        180, 180, 200])
    next

func chk_spawnCaptureParticles r, c
    wx = chk_cellToX(c)
    wz = chk_cellToZ(r)
    piece = captureAnimType
    if chk_isRed(piece)
        pr = 255  pg = 60  pb = 40
    else
        pr = 40  pg = 40  pb = 40
    ok
    for i = 1 to 15
        vx = (GetRandomValue(-100, 100) / 100.0) * 2.0
        vy = (GetRandomValue(100, 350) / 100.0) * 1.5
        vz = (GetRandomValue(-100, 100) / 100.0) * 2.0
        cr = pr + GetRandomValue(-30, 30)
        cg = pg + GetRandomValue(-15, 15)
        cb = pb + GetRandomValue(-15, 15)
        if cr < 0 cr = 0 ok   if cr > 255 cr = 255 ok
        if cg < 0 cg = 0 ok   if cg > 255 cg = 255 ok
        if cb < 0 cb = 0 ok   if cb > 255 cb = 255 ok
        add(particles, [wx, 0.3, wz, vx, vy, vz, 1.5, cr, cg, cb])
    next

func chk_spawnWinParticles
    for i = 1 to 40
        wx = (GetRandomValue(-50, 50) / 10.0)
        wz = (GetRandomValue(-50, 50) / 10.0)
        vx = (GetRandomValue(-100, 100) / 100.0) * 1.5
        vy = (GetRandomValue(200, 500) / 100.0) * 1.5
        vz = (GetRandomValue(-100, 100) / 100.0) * 1.5
        if winner = CELL_RED
            cr = 255  cg = GetRandomValue(40, 120)  cb = GetRandomValue(20, 60)
        else
            cr = GetRandomValue(20, 60)  cg = GetRandomValue(20, 60)  cb = GetRandomValue(20, 60)
        ok
        add(particles, [wx, 0.5, wz, vx, vy, vz, 2.5, cr, cg, cb])
    next

func chk_updateParticles dt
    i = 1
    while i <= len(particles)
        particles[i][1] += particles[i][4] * dt   // x += vx
        particles[i][2] += particles[i][5] * dt   // y += vy
        particles[i][3] += particles[i][6] * dt   // z += vz
        particles[i][5] -= 5.0 * dt               // gravity
        particles[i][7] -= dt                      // life
        if particles[i][7] <= 0
            del(particles, i)
        else
            i += 1
        ok
    end

func chk_drawParticles3D
    for i = 1 to len(particles)
        px = particles[i][1]
        py = particles[i][2]
        pz = particles[i][3]
        life = particles[i][7]
        pr = particles[i][8]
        pg = particles[i][9]
        pb = particles[i][10]
        alpha = floor(life * 180)
        if alpha > 255 alpha = 255 ok
        if alpha < 0 alpha = 0 ok
        sz = 0.06 + life * 0.04
        DrawSphere(Vector3(px, py, pz), sz,
                   RAYLIBColor(pr, pg, pb, alpha))
    next

// =============================================================
// Camera
// =============================================================

func chk_positionCamera
    boardHalf = BOARD_SZ * CELL_SZ / 2

    if cameraMode = CAM_FRONT
        // Red player's perspective (looking from positive Z toward negative Z)
        goalPX = 0.0
        goalPY = boardHalf * 1.3
        goalPZ = boardHalf * 1.8
        goalTX = 0.0
        goalTY = 0.0
        goalTZ = -boardHalf * 0.15
    ok

    if cameraMode = CAM_ISOMETRIC
        goalPX = boardHalf * 1.4
        goalPY = boardHalf * 1.5
        goalPZ = boardHalf * 1.4
        goalTX = 0.0
        goalTY = 0.0
        goalTZ = 0.0
    ok

    if cameraMode = CAM_OVERHEAD
        goalPX = 0.0
        goalPY = boardHalf * 2.8
        goalPZ = 1.0
        goalTX = 0.0
        goalTY = 0.0
        goalTZ = 0.0
    ok

    lerp = 0.04
    camPosX += (goalPX - camPosX) * lerp
    camPosY += (goalPY - camPosY) * lerp
    camPosZ += (goalPZ - camPosZ) * lerp
    camTgtX += (goalTX - camTgtX) * lerp
    camTgtY += (goalTY - camTgtY) * lerp
    camTgtZ += (goalTZ - camTgtZ) * lerp

// =============================================================
// 3D Drawing: Board
// =============================================================

func chk_drawBoard3D
    boardW = BOARD_SZ * CELL_SZ
    boardH = BOARD_SZ * CELL_SZ

    // Main surface (lowered well below tiles to prevent Z-fighting)
    DrawCube(Vector3(0, -0.25, 0), boardW + 0.3, 0.3, boardH + 0.3,
             RAYLIBColor(50, 35, 20, 255))

    // Border frame
    bThick = 0.35
    bH = 0.4
    halfW = boardW / 2 + bThick / 2 + 0.15
    halfH = boardH / 2 + bThick / 2 + 0.15
    borderCol = RAYLIBColor(85, 55, 25, 255)

    DrawCube(Vector3(0, bH/2 - 0.1, -halfH), boardW + bThick*2 + 0.3, bH, bThick, borderCol)
    DrawCube(Vector3(0, bH/2 - 0.1, halfH), boardW + bThick*2 + 0.3, bH, bThick, borderCol)
    DrawCube(Vector3(-halfW, bH/2 - 0.1, 0), bThick, bH, boardH + 0.3, borderCol)
    DrawCube(Vector3(halfW, bH/2 - 0.1, 0), bThick, bH, boardH + 0.3, borderCol)

    // Grid cells (raised well above base)
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            wx = chk_cellToX(c)
            wz = chk_cellToZ(r)

            if (r + c) % 2 = 0
                // Light square
                tileCol = RAYLIBColor(210, 185, 140, 255)
            else
                // Dark square
                tileCol = RAYLIBColor(100, 60, 30, 255)
            ok

            DrawCube(Vector3(wx, 0.03, wz), CELL_SZ - 0.04, 0.06, CELL_SZ - 0.04, tileCol)

            // Valid move highlight (raised above tile)
            if showHints and selectedR > 0
                for m = 1 to len(validMoves)
                    if validMoves[m][1] = r and validMoves[m][2] = c
                        pulse = 0.5 + sin(animTime * 4.0) * 0.3
                        if validMoves[m][3] != 0
                            // Jump target: red highlight
                            DrawCube(Vector3(wx, 0.08, wz),
                                     CELL_SZ - 0.1, 0.02, CELL_SZ - 0.1,
                                     RAYLIBColor(255, 80, 40, floor(pulse * 140)))
                        else
                            // Simple move: green highlight
                            DrawCube(Vector3(wx, 0.08, wz),
                                     CELL_SZ - 0.1, 0.02, CELL_SZ - 0.1,
                                     RAYLIBColor(60, 220, 80, floor(pulse * 120)))
                        ok
                    ok
                next
            ok

            // Pieces with mandatory jump highlight
            if showHints and selectedR = 0 and gameState = ST_PLAYING
                if chk_isOwn(board[r][c], currentPlayer)
                    moves = chk_getValidMovesForSelection(r, c)
                    if len(moves) > 0
                        // Subtle ring to indicate movable pieces
                        DrawCircle3D(Vector3(wx, 0.10, wz), PIECE_RAD + 0.1,
                                     Vector3(1, 0, 0), 90.0,
                                     RAYLIBColor(255, 255, 100, 50))
                    ok
                ok
            ok
        next
    next

// =============================================================
// 3D Drawing: Pieces
// =============================================================

func chk_drawPieces3D
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            piece = board[r][c]
            if piece = CELL_EMPTY loop ok

            // Don't draw piece being animated (it's drawn separately)
            if animActive
                if r = animDestR and c = animDestC loop ok
            ok

            wx = chk_cellToX(c)
            wz = chk_cellToZ(r)
            chk_drawPieceAt(wx, wz, piece, r, c)
        next
    next

func chk_drawPieceAt wx, wz, piece, r, c
    baseY = 0.07     // Pieces sit on top of tiles (tile top ~0.06)

    // Colors
    if chk_isRed(piece)
        bodyCol = RAYLIBColor(200, 35, 25, 255)
        topCol  = RAYLIBColor(230, 55, 35, 255)
        wireCol = RAYLIBColor(255, 80, 60, 180)
    else
        bodyCol = RAYLIBColor(35, 30, 28, 255)
        topCol  = RAYLIBColor(55, 48, 42, 255)
        wireCol = RAYLIBColor(80, 70, 60, 180)
    ok

    // Selected piece highlight
    isSelected = (selectedR = r and selectedC = c)
    if isSelected
        pulse = 0.8 + sin(animTime * 6.0) * 0.2
        DrawCylinder(Vector3(wx, baseY, wz), PIECE_RAD + 0.12, PIECE_RAD + 0.12,
                     0.02, 20, RAYLIBColor(255, 255, 80, floor(pulse * 150)))
    ok

    // Main cylinder body
    DrawCylinder(Vector3(wx, baseY, wz), PIECE_RAD, PIECE_RAD, PIECE_H, 20, bodyCol)

    // Top face (clearly above body)
    DrawCylinder(Vector3(wx, baseY + PIECE_H + 0.01, wz), PIECE_RAD - 0.02, PIECE_RAD - 0.02, 0.03, 20, topCol)

    // Ring detail (well above top face)
    DrawCircle3D(Vector3(wx, baseY + PIECE_H + 0.05, wz), PIECE_RAD * 0.65,
                 Vector3(1, 0, 0), 90.0, wireCol)

    // King crown
    if chk_isKing(piece)
        chk_drawCrown(wx, wz, piece, baseY)
    ok

func chk_drawCrown wx, wz, piece, baseY
    crownY = baseY + PIECE_H + 0.06

    // Crown base ring
    DrawCylinder(Vector3(wx, crownY, wz), PIECE_RAD * 0.55, PIECE_RAD * 0.55,
                 0.06, 20, RAYLIBColor(255, 200, 30, 255))

    // Crown points (5 small cones around the ring)
    for i = 0 to 4
        angle = i * 72.0 * 3.14159265 / 180.0
        px = wx + cos(angle) * PIECE_RAD * 0.4
        pz = wz + sin(angle) * PIECE_RAD * 0.4
        DrawCylinder(Vector3(px, crownY + 0.06, pz), 0.06, 0.01, 0.12, 6,
                     RAYLIBColor(255, 210, 40, 255))
    next

    // Crown gem on top
    DrawSphere(Vector3(wx, crownY + 0.2, wz), 0.06,
               RAYLIBColor(255, 50, 50, 255))

    // Glow
    pulse = 0.8 + sin(animTime * 3.0) * 0.2
    DrawSphere(Vector3(wx, crownY + 0.15, wz), 0.12 * pulse,
               RAYLIBColor(255, 200, 50, 40))

// =============================================================
// 3D Drawing: Animating Piece
// =============================================================

func chk_drawAnimatingPiece
    if !animActive return ok

    t = animProgress
    // Smooth ease-in-out
    t = t * t * (3.0 - 2.0 * t)

    cx = animFromX + (animToX - animFromX) * t
    cz = animFromZ + (animToZ - animFromZ) * t

    // Jump arc
    arcY = 0.0
    if animJump
        arcY = JUMP_ARC_H * sin(animProgress * 3.14159265)
    ok

    baseY = 0.07 + arcY

    // Colors
    if chk_isRed(animPieceType)
        bodyCol = RAYLIBColor(200, 35, 25, 255)
        topCol  = RAYLIBColor(230, 55, 35, 255)
    else
        bodyCol = RAYLIBColor(35, 30, 28, 255)
        topCol  = RAYLIBColor(55, 48, 42, 255)
    ok

    DrawCylinder(Vector3(cx, baseY, cz), PIECE_RAD, PIECE_RAD, PIECE_H, 20, bodyCol)
    DrawCylinder(Vector3(cx, baseY + PIECE_H + 0.01, cz), PIECE_RAD - 0.02, PIECE_RAD - 0.02, 0.03, 20, topCol)

    if chk_isKing(animPieceType)
        crownY = baseY + PIECE_H + 0.06
        DrawCylinder(Vector3(cx, crownY, cz), PIECE_RAD * 0.55, PIECE_RAD * 0.55,
                     0.06, 20, RAYLIBColor(255, 200, 30, 255))
        for i = 0 to 4
            angle = i * 72.0 * 3.14159265 / 180.0
            px = cx + cos(angle) * PIECE_RAD * 0.4
            pz = cz + sin(angle) * PIECE_RAD * 0.4
            DrawCylinder(Vector3(px, crownY + 0.06, pz), 0.06, 0.01, 0.12, 6,
                         RAYLIBColor(255, 210, 40, 255))
        next
        DrawSphere(Vector3(cx, crownY + 0.2, cz), 0.06,
                   RAYLIBColor(255, 50, 50, 255))
    ok

    // Shadow on ground
    if arcY > 0.01
        shadowAlpha = floor(100 * (1.0 - arcY / JUMP_ARC_H))
        if shadowAlpha < 20 shadowAlpha = 20 ok
        if shadowAlpha > 100 shadowAlpha = 100 ok
        DrawCylinder(Vector3(cx, 0.065, cz), PIECE_RAD * 0.7, PIECE_RAD * 0.7,
                     0.005, 16, RAYLIBColor(0, 0, 0, shadowAlpha))
    ok

// =============================================================
// 3D Drawing: Capture Animation
// =============================================================

func chk_drawCaptureAnim
    if !captureAnimActive return ok

    t = captureAnimProgress
    // Piece sinks and fades
    sinkY = -t * 0.8
    fadeAlpha = floor(255 * (1.0 - t))
    if fadeAlpha < 0 fadeAlpha = 0 ok

    if chk_isRed(captureAnimType)
        bodyCol = RAYLIBColor(200, 35, 25, fadeAlpha)
    else
        bodyCol = RAYLIBColor(35, 30, 28, fadeAlpha)
    ok

    DrawCylinder(Vector3(captureAnimX, 0.07 + sinkY, captureAnimZ),
                 PIECE_RAD * (1.0 - t * 0.5), PIECE_RAD * (1.0 - t * 0.5),
                 PIECE_H, 16, bodyCol)

// =============================================================
// 3D Drawing: Cursor
// =============================================================

func chk_drawCursor3D
    if gameState != ST_PLAYING return ok

    wx = chk_cellToX(cursorC)
    wz = chk_cellToZ(cursorR)

    // Determine cursor color
    piece = board[cursorR][cursorC]
    if chk_isOwn(piece, currentPlayer)
        pulse = 0.8 + sin(animTime * 5.0) * 0.2
        curCol = RAYLIBColor(80, 255, 120, floor(pulse * 200))
    else
        pulse = 1.0
        curCol = RAYLIBColor(180, 180, 200, 100)
    ok

    // Corner brackets
    hs = CELL_SZ * 0.48
    bracketLen = 0.28
    by = 0.10

    DrawLine3D(Vector3(wx - hs, by, wz - hs), Vector3(wx - hs + bracketLen, by, wz - hs), curCol)
    DrawLine3D(Vector3(wx - hs, by, wz - hs), Vector3(wx - hs, by, wz - hs + bracketLen), curCol)
    DrawLine3D(Vector3(wx + hs, by, wz - hs), Vector3(wx + hs - bracketLen, by, wz - hs), curCol)
    DrawLine3D(Vector3(wx + hs, by, wz - hs), Vector3(wx + hs, by, wz - hs + bracketLen), curCol)
    DrawLine3D(Vector3(wx - hs, by, wz + hs), Vector3(wx - hs + bracketLen, by, wz + hs), curCol)
    DrawLine3D(Vector3(wx - hs, by, wz + hs), Vector3(wx - hs, by, wz + hs - bracketLen), curCol)
    DrawLine3D(Vector3(wx + hs, by, wz + hs), Vector3(wx + hs - bracketLen, by, wz + hs), curCol)
    DrawLine3D(Vector3(wx + hs, by, wz + hs), Vector3(wx + hs, by, wz + hs - bracketLen), curCol)

// =============================================================
// HUD
// =============================================================

func chk_drawHUD
    panelW = 250
    panelH = 165
    DrawRectangle(10, 30, panelW, panelH, RAYLIBColor(0, 0, 0, 190))
    DrawRectangleLines(10, 30, panelW, panelH, RAYLIBColor(160, 100, 40, 200))

    DrawText("3D CHECKERS", 20, 38, 18, RAYLIBColor(255, 200, 80, 255))

    // Current player
    if currentPlayer = CELL_RED
        pName = "RED"
        pCol = RAYLIBColor(255, 80, 50, 255)
    else
        pName = "BLACK"
        pCol = RAYLIBColor(160, 150, 140, 255)
    ok

    if gameState = ST_ANIMATING
        DrawText("Turn: " + pName + " (moving...)", 20, 62, 14, pCol)
    else
        DrawText("Turn: " + pName, 20, 62, 14, pCol)
    ok

    if gameMode = MODE_PVA and currentPlayer = CELL_BLACK and gameState = ST_PLAYING
        DrawText("AI thinking...", 20, 80, 13, RAYLIBColor(180, 180, 100, 200))
    ok

    // Piece counts
    DrawText("Red: " + string(redCount), 20, 98, 16, RAYLIBColor(255, 80, 50, 255))
    DrawText("Black: " + string(blackCount), 120, 98, 16, RAYLIBColor(160, 150, 140, 255))

    // Multi-jump indicator
    if multiJumpActive
        DrawText("MULTI-JUMP! Continue jumping!", 20, 120, 14,
                 RAYLIBColor(255, 255, 50, 255))
    ok

    // Mode
    if gameMode = MODE_PVP
        modeText = "Mode: PvP [1/2]"
    else
        modeText = "Mode: vs AI [1/2]"
    ok
    DrawText(modeText, 20, 140, 13, RAYLIBColor(140, 155, 175, 180))

    // Hints
    hintText = "Hints: ON [H]"
    if !showHints hintText = "Hints: OFF [H]" ok
    DrawText(hintText, 20, 158, 13, RAYLIBColor(140, 155, 175, 180))

    // Camera
    camName = "FRONT"
    if cameraMode = CAM_ISOMETRIC camName = "ISOMETRIC" ok
    if cameraMode = CAM_OVERHEAD  camName = "OVERHEAD"  ok
    DrawRectangle(10, SCREEN_H - 60, 220, 25, RAYLIBColor(0, 0, 0, 153))
    DrawText("Cam: " + camName + "  [C] switch", 16, SCREEN_H - 56, 14,
             RAYLIBColor(150, 180, 210, 220))

    // Controls
    DrawRectangle(SCREEN_W - 500, SCREEN_H - 35, 490, 25, RAYLIBColor(0, 0, 0, 153))
    DrawText("Click/Space: Select & Move | RClick: Deselect | U: Undo | R: Reset | H: Hints",
             SCREEN_W - 495, SCREEN_H - 30, 12, RAYLIBColor(150, 160, 180, 200))

// =============================================================
// Mini Board
// =============================================================

func chk_drawMiniBoard
    cellW = 14
    cellH = 14
    mapW = BOARD_SZ * cellW
    mapH = BOARD_SZ * cellH
    mapX = SCREEN_W - mapW - 20
    mapY = 30

    DrawRectangle(mapX - 3, mapY - 3, mapW + 6, mapH + 6, RAYLIBColor(0, 0, 0, 204))
    DrawRectangleLines(mapX - 3, mapY - 3, mapW + 6, mapH + 6,
                       RAYLIBColor(160, 100, 40, 200))

    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            sx = mapX + (c - 1) * cellW
            sy = mapY + (r - 1) * cellH

            if (r + c) % 2 = 0
                bg = RAYLIBColor(180, 160, 120, 220)
            else
                bg = RAYLIBColor(80, 50, 25, 220)
            ok
            DrawRectangle(sx, sy, cellW, cellH, bg)

            piece = board[r][c]
            if chk_isRed(piece)
                DrawCircle(sx + cellW/2, sy + cellH/2, 4,
                           RAYLIBColor(230, 50, 30, 255))
                if chk_isKing(piece)
                    DrawCircle(sx + cellW/2, sy + cellH/2, 2,
                               RAYLIBColor(255, 200, 50, 255))
                ok
            ok
            if chk_isBlack(piece)
                DrawCircle(sx + cellW/2, sy + cellH/2, 4,
                           RAYLIBColor(40, 35, 30, 255))
                if chk_isKing(piece)
                    DrawCircle(sx + cellW/2, sy + cellH/2, 2,
                               RAYLIBColor(255, 200, 50, 255))
                ok
            ok
        next
    next

    // Cursor
    cx = mapX + (cursorC - 1) * cellW
    cy = mapY + (cursorR - 1) * cellH
    DrawRectangleLines(cx, cy, cellW, cellH, RAYLIBColor(255, 255, 100, 220))

    DrawText("MAP", mapX + floor(mapW/2) - 15, mapY - 16, 12,
             RAYLIBColor(180, 120, 50, 200))

// =============================================================
// Title Screen
// =============================================================

func chk_drawTitleScreen
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(18, 14, 22, 255))

    t1 = "3D CHECKERS"
    t1w = MeasureText(t1, 48)
    t1x = (SCREEN_W - t1w) / 2
    DrawText(t1, floor(t1x) + 3, 43, 48, RAYLIBColor(80, 30, 10, 200))
    DrawText(t1, floor(t1x), 40, 48, RAYLIBColor(255, 200, 80, 255))

    t2 = "~ Classic board game in full 3D! ~"
    t2w = MeasureText(t2, 16)
    DrawText(t2, floor((SCREEN_W - t2w)/2), 95, 16, RAYLIBColor(180, 150, 100, 220))

    cy = 130
    cLines = [
        "Left Click / SPACE     -   Select piece / Move to cell",
        "Right Click            -   Deselect piece",
        "Arrow Keys / WASD      -   Move cursor",
        "U                      -   Undo last move",
        "H                      -   Toggle move hints",
        "R                      -   Restart game",
        "C                      -   Cycle camera view",
        "",
        "Rules:",
        "  Pieces move DIAGONALLY on dark squares",
        "  Jump over enemies to CAPTURE them",
        "  Multiple jumps in one turn (mandatory)",
        "  Reach the far end to become a KING",
        "  Kings move forward AND backward",
        "  If a capture is possible, you MUST take it!"
    ]
    for i = 1 to len(cLines)
        lw = MeasureText(cLines[i], 14)
        if i >= 9
            col = RAYLIBColor(255, 200, 100, 210)
        else
            col = RAYLIBColor(150, 170, 200, 230)
        ok
        DrawText(cLines[i], floor((SCREEN_W - lw)/2), cy + (i - 1) * 20, 14, col)
    next

    // Mode selection box
    boxW = 380
    boxH = 80
    boxX = floor((SCREEN_W - boxW) / 2)
    boxY = 445
    DrawRectangle(boxX, boxY, boxW, boxH, RAYLIBColor(40, 50, 80, 204))
    DrawRectangleLines(boxX, boxY, boxW, boxH, RAYLIBColor(120, 180, 255, 180))

    modeTitle = "SELECT MODE:"
    mtw = MeasureText(modeTitle, 16)
    DrawText(modeTitle, floor((SCREEN_W - mtw)/2), boxY + 10, 16, RAYLIBColor(120, 180, 255, 255))

    pvpCol = RAYLIBColor(120, 130, 150, 200)
    aiCol  = RAYLIBColor(120, 130, 150, 200)
    if gameMode = MODE_PVP
        pvpCol = RAYLIBColor(255, 255, 80, 255)
    else
        aiCol = RAYLIBColor(255, 255, 80, 255)
    ok

    opt1 = "[1] Player vs Player"
    opt2 = "[2] Player vs AI"
    o1w = MeasureText(opt1, 18)
    o2w = MeasureText(opt2, 18)
    DrawText(opt1, floor(SCREEN_W/2) - o1w - 15, boxY + 38, 18, pvpCol)
    DrawText(opt2, floor(SCREEN_W/2) + 15, boxY + 38, 18, aiCol)

    // Arrow indicator on selected mode
    if gameMode = MODE_PVP
        DrawText(">", floor(SCREEN_W/2) - o1w - 30, boxY + 38, 18, RAYLIBColor(255, 200, 50, 255))
    else
        DrawText(">", floor(SCREEN_W/2), boxY + 38, 18, RAYLIBColor(255, 200, 50, 255))
    ok

    if floor(animTime * 2) % 2 = 0
        st = "Click or Press ENTER / SPACE to Start"
        stw = MeasureText(st, 24)
        DrawText(st, floor((SCREEN_W - stw)/2), 555, 24, RAYLIBColor(255, 255, 255, 255))
    ok

    modeText = ""
    if gameMode = MODE_PVP
        modeText = "You play Red vs a friend (Black)"
    else
        modeText = "You play Red vs AI (Black)"
    ok
    mw = MeasureText(modeText, 16)
    DrawText(modeText, floor((SCREEN_W - mw)/2), 590, 16, RAYLIBColor(160, 180, 140, 200))

    cr = "Developed using Ring Language + RingRayLib"
    crw = MeasureText(cr, 14)
    DrawText(cr, floor((SCREEN_W - crw)/2), SCREEN_H - 35, 14,
             RAYLIBColor(80, 70, 50, 180))

// =============================================================
// Game Over Overlay
// =============================================================

func chk_drawGameOverOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 166))

    if winner = CELL_RED
        wText = "RED WINS!"
        wCol = RAYLIBColor(255, 80, 50, 255)
    else
        wText = "BLACK WINS!"
        wCol = RAYLIBColor(200, 190, 170, 255)
    ok

    tw = MeasureText(wText, 56)
    tx = floor((SCREEN_W - tw) / 2)
    DrawText(wText, tx + 3, 243, 56, RAYLIBColor(0, 0, 0, 130))
    DrawText(wText, tx, 240, 56, wCol)

    score = "Red: " + string(redCount) + "  |  Black: " + string(blackCount)
    sw = MeasureText(score, 24)
    DrawText(score, floor((SCREEN_W - sw) / 2), 310, 24, RAYLIBColor(200, 200, 220, 240))

    // Stars based on remaining pieces
    remaining = 0
    if winner = CELL_RED remaining = redCount ok
    if winner = CELL_BLACK remaining = blackCount ok
    stars = 1
    if remaining >= 6 stars = 2 ok
    if remaining >= 10 stars = 3 ok

    starStr = ""
    for i = 1 to stars
        starStr += "* "
    next
    ssw = MeasureText(starStr, 40)
    DrawText(starStr, floor((SCREEN_W - ssw) / 2), 350, 40,
             RAYLIBColor(255, 220, 50, 255))

    hint = "Click or Press ENTER to Play Again"
    hw = MeasureText(hint, 20)
    DrawText(hint, floor((SCREEN_W - hw) / 2), 410, 20,
             RAYLIBColor(180, 190, 210, 220))
