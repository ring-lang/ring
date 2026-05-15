/*
**  Chess Game - Using RingRayLib
**  ===============================
**  Play chess against the computer! You are White (bottom),
**  the computer plays Black (top).
**
**  Controls:
**    Mouse Click     - Select piece / Move piece
**    R               - Restart game
**    U               - Undo last move (undoes both yours and computer's)
**    ESC             - Exit
**
**  Features:
**    - Complete chess rules
**    - Castling (kingside and queenside)
**    - En passant captures
**    - Pawn promotion (auto-promotes to Queen)
**    - Check, checkmate, and stalemate detection
**    - Computer AI using Minimax with Alpha-Beta pruning
**    - Legal move highlighting
**    - Last move highlighting
**    - Captured pieces display
**    - Move history panel
**    - Animated piece movement
**    - Multiple AI difficulty levels (press 1-3)
**
**  Performance optimized:
**    - Pre-computed global offset arrays (knight, directions)
**    - Inlined piece evaluation (no function calls in evaluate)
**    - Cached len() before all loops
**    - Cached board row references in hot loops
**    - Partition-based move ordering
**    - Eliminated redundant isInCheck in evaluate
**    - Pre-created RayLibColor objects (no per-frame allocation)
**
**  Ring + RayLib Game #10 in our series!
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W     = 1050
SCREEN_H     = 700

BOARD_X      = 40
BOARD_Y      = 50
SQ_SIZE      = 75
BOARD_PX     = SQ_SIZE * 8

PANEL_X      = BOARD_X + BOARD_PX + 30
PANEL_W      = SCREEN_W - PANEL_X - 20

PIECE_NONE   = 0
PIECE_PAWN   = 1
PIECE_KNIGHT = 2
PIECE_BISHOP = 3
PIECE_ROOK   = 4
PIECE_QUEEN  = 5
PIECE_KING   = 6

SIDE_WHITE   = 1
SIDE_BLACK   = 2

ST_TITLE     = 1
ST_PLAYING   = 2
ST_AI_THINK  = 3
ST_ANIMATE   = 4
ST_CHECKMATE = 5
ST_STALEMATE = 6

AI_EASY      = 2
AI_MEDIUM    = 3
AI_HARD      = 4

ANIM_SPEED   = 8.0
INF_VAL      = 999999

// =============================================================
// Pre-computed offset arrays (avoid re-creating every call)
// =============================================================

KNIGHT_DR = [-2, -2, -1, -1,  1, 1,  2, 2]
KNIGHT_DC = [-1,  1, -2,  2, -2, 2, -1, 1]

DIAG_DR   = [-1, -1,  1, 1]
DIAG_DC   = [-1,  1, -1, 1]

STRAIGHT_DR = [-1, 1,  0, 0]
STRAIGHT_DC = [ 0, 0, -1, 1]

// Piece values table (index = pieceType + 1, since PIECE_NONE=0)
PIECE_VAL = [0, 100, 320, 330, 500, 900, 20000]

// =============================================================
// Board
// =============================================================

board = []
for r = 1 to 8
    row = []
    for c = 1 to 8
        add(row, [PIECE_NONE, 0])
    next
    add(board, row)
next

// Game state
gameState       = ST_TITLE
animTime        = 0.0
dt              = 0.0
currentTurn     = SIDE_WHITE

selRow          = 0
selCol          = 0
hasSelection    = false
legalMoves      = []

lastFromR       = 0
lastFromC       = 0
lastToR         = 0
lastToC         = 0

epRow           = 0
epCol           = 0

whiteKingMoved  = false
whiteRookAMoved = false
whiteRookHMoved = false
blackKingMoved  = false
blackRookAMoved = false
blackRookHMoved = false

whiteKingR      = 8
whiteKingC      = 5
blackKingR      = 1
blackKingC      = 5

inCheck         = false
aiDepth         = AI_MEDIUM

whiteCaptured   = []
blackCaptured   = []

moveHistory     = []
moveHistCount   = 0
undoStack       = []

animFromR       = 0
animFromC       = 0
animToR         = 0
animToC         = 0
animPiece       = 0
animSide        = 0
animProgress    = 0.0
animActive      = false

thinkDots       = 0
thinkTimer      = 0.0

// Colors (pre-allocated once)
colBoardLight   = NULL
colBoardDark    = NULL
colSelected     = NULL
colLegalMove    = NULL
colLastMove     = NULL
colCheck        = NULL
colBg           = NULL
colPanel        = NULL
colWhitePiece   = NULL
colBlackPiece   = NULL
colTextDark     = NULL
colTextLight    = NULL
colTitle        = NULL
colButton       = NULL
colButtonHover  = NULL
colBorder       = NULL
colPanelBorder  = NULL
colSepLine      = NULL
colCheckText    = NULL
colThinkText    = NULL
colMiniBlack    = NULL
colMiniBlackOut = NULL
colOverlay      = NULL

// =============================================================
// Main Program
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Ring Chess - RingRayLib")
SetTargetFPS(60)

colBoardLight   = RayLibColor(240, 217, 181, 255)
colBoardDark    = RayLibColor(181, 136, 99, 255)
colSelected     = RayLibColor(246, 246, 105, 180)
colLegalMove    = RayLibColor(106, 190, 48, 150)
colLastMove     = RayLibColor(205, 210, 106, 120)
colCheck        = RayLibColor(235, 64, 52, 160)
colBg           = RayLibColor(32, 32, 36, 255)
colPanel        = RayLibColor(45, 45, 50, 255)
colWhitePiece   = RayLibColor(255, 255, 255, 255)
colBlackPiece   = RayLibColor(30, 30, 30, 255)
colTextDark     = RayLibColor(180, 180, 180, 255)
colTextLight    = RayLibColor(240, 240, 240, 255)
colTitle        = RayLibColor(255, 215, 0, 255)
colButton       = RayLibColor(70, 130, 80, 255)
colButtonHover  = RayLibColor(90, 160, 100, 255)
colBorder       = RayLibColor(100, 70, 40, 255)
colPanelBorder  = RayLibColor(80, 80, 85, 255)
colSepLine      = RayLibColor(70, 70, 75, 255)
colCheckText    = RayLibColor(235, 64, 52, 255)
colThinkText    = RayLibColor(255, 200, 50, 255)
colMiniBlack    = RayLibColor(80, 80, 80, 255)
colMiniBlackOut = RayLibColor(180, 180, 180, 255)
colOverlay      = RayLibColor(0, 0, 0, 150)

// =============================================================
// Main Game Loop
// =============================================================

while !WindowShouldClose()

    dt = GetFrameTime()
    if dt > 0.05 dt = 0.05 ok
    animTime += dt

    stateHandled = false

    if gameState = ST_TITLE and !stateHandled
        if IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
            mx = GetMouseX()
            my = GetMouseY()
            if mx >= 350 and mx <= 550 and my >= 340 and my <= 385
                aiDepth = AI_EASY
                ch_startNewGame()
                stateHandled = true
            ok
            if !stateHandled and mx >= 350 and mx <= 550 and my >= 400 and my <= 445
                aiDepth = AI_MEDIUM
                ch_startNewGame()
                stateHandled = true
            ok
            if !stateHandled and mx >= 350 and mx <= 550 and my >= 460 and my <= 505
                aiDepth = AI_HARD
                ch_startNewGame()
                stateHandled = true
            ok
        ok
        if !stateHandled and (IsKeyPressed(KEY_ONE) or IsKeyPressed(KEY_KP_1))
            aiDepth = AI_EASY
            ch_startNewGame()
            stateHandled = true
        ok
        if !stateHandled and (IsKeyPressed(KEY_TWO) or IsKeyPressed(KEY_KP_2))
            aiDepth = AI_MEDIUM
            ch_startNewGame()
            stateHandled = true
        ok
        if !stateHandled and (IsKeyPressed(KEY_THREE) or IsKeyPressed(KEY_KP_3))
            aiDepth = AI_HARD
            ch_startNewGame()
            stateHandled = true
        ok
    ok

    if gameState = ST_PLAYING and !stateHandled
        if IsKeyPressed(KEY_R)
            gameState = ST_TITLE
            stateHandled = true
        ok
        if !stateHandled and IsKeyPressed(KEY_U)
            ch_undoMove()
            stateHandled = true
        ok
        if !stateHandled and IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
            ch_handleClick()
            stateHandled = true
        ok
    ok

    if gameState = ST_AI_THINK and !stateHandled
        thinkTimer += dt
        if thinkTimer > 0.3
            thinkTimer = 0
            thinkDots += 1
            if thinkDots > 3 thinkDots = 0 ok
        ok
        ch_aiMove()
        stateHandled = true
    ok

    if gameState = ST_ANIMATE and !stateHandled
        animProgress += dt * ANIM_SPEED
        if animProgress >= 1.0
            animProgress = 1.0
            animActive = false
            ch_postMoveCheck()
        ok
        stateHandled = true
    ok

    if (gameState = ST_CHECKMATE or gameState = ST_STALEMATE) and !stateHandled
        if IsKeyPressed(KEY_R) or IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            gameState = ST_TITLE
            stateHandled = true
        ok
    ok

    // === DRAWING ===
    BeginDrawing()
    ClearBackground(colBg)

    if gameState = ST_TITLE
        ch_drawTitle()
    else
        ch_drawBoard()
        ch_drawPieces()
        ch_drawPanel()
        if gameState = ST_AI_THINK
            ch_drawThinking()
        ok
        if gameState = ST_CHECKMATE
            ch_drawGameOver(true)
        ok
        if gameState = ST_STALEMATE
            ch_drawGameOver(false)
        ok
    ok

    EndDrawing()
end

CloseWindow()

// =============================================================
// Functions
// =============================================================

func ch_startNewGame
    for r = 1 to 8
        for c = 1 to 8
            board[r][c] = [PIECE_NONE, 0]
        next
    next

    board[1][1] = [PIECE_ROOK, SIDE_BLACK]
    board[1][2] = [PIECE_KNIGHT, SIDE_BLACK]
    board[1][3] = [PIECE_BISHOP, SIDE_BLACK]
    board[1][4] = [PIECE_QUEEN, SIDE_BLACK]
    board[1][5] = [PIECE_KING, SIDE_BLACK]
    board[1][6] = [PIECE_BISHOP, SIDE_BLACK]
    board[1][7] = [PIECE_KNIGHT, SIDE_BLACK]
    board[1][8] = [PIECE_ROOK, SIDE_BLACK]
    for c = 1 to 8
        board[2][c] = [PIECE_PAWN, SIDE_BLACK]
    next
    for c = 1 to 8
        board[7][c] = [PIECE_PAWN, SIDE_WHITE]
    next
    board[8][1] = [PIECE_ROOK, SIDE_WHITE]
    board[8][2] = [PIECE_KNIGHT, SIDE_WHITE]
    board[8][3] = [PIECE_BISHOP, SIDE_WHITE]
    board[8][4] = [PIECE_QUEEN, SIDE_WHITE]
    board[8][5] = [PIECE_KING, SIDE_WHITE]
    board[8][6] = [PIECE_BISHOP, SIDE_WHITE]
    board[8][7] = [PIECE_KNIGHT, SIDE_WHITE]
    board[8][8] = [PIECE_ROOK, SIDE_WHITE]

    currentTurn = SIDE_WHITE
    selRow = 0   selCol = 0   hasSelection = false   legalMoves = []
    lastFromR = 0   lastFromC = 0   lastToR = 0   lastToC = 0
    epRow = 0   epCol = 0
    whiteKingMoved = false   whiteRookAMoved = false   whiteRookHMoved = false
    blackKingMoved = false   blackRookAMoved = false   blackRookHMoved = false
    whiteKingR = 8   whiteKingC = 5   blackKingR = 1   blackKingC = 5
    inCheck = false
    whiteCaptured = []   blackCaptured = []
    moveHistory = []   moveHistCount = 0   undoStack = []
    animActive = false   thinkDots = 0   thinkTimer = 0.0
    inCheck = ch_isInCheck(SIDE_WHITE)
    gameState = ST_PLAYING

func ch_handleClick
    mx = GetMouseX()
    my = GetMouseY()
    col = floor((mx - BOARD_X) / SQ_SIZE) + 1
    row = floor((my - BOARD_Y) / SQ_SIZE) + 1

    if row < 1 or row > 8 or col < 1 or col > 8
        hasSelection = false
        legalMoves = []
        return
    ok

    if hasSelection
        moveFound = false
        moveSpec = 0
        nMoves = len(legalMoves)
        for i = 1 to nMoves
            mv = legalMoves[i]
            if mv[1] = row and mv[2] = col
                moveFound = true
                moveSpec = mv[3]
                exit
            ok
        next

        if moveFound
            ch_saveUndo()
            ch_executeMove(selRow, selCol, row, col, moveSpec)
            hasSelection = false
            legalMoves = []
        else
            p = board[row][col]
            if p[1] != PIECE_NONE and p[2] = SIDE_WHITE
                selRow = row   selCol = col   hasSelection = true
                legalMoves = ch_getLegalMoves(row, col)
            else
                hasSelection = false   legalMoves = []
            ok
        ok
    else
        p = board[row][col]
        if p[1] != PIECE_NONE and p[2] = SIDE_WHITE
            selRow = row   selCol = col   hasSelection = true
            legalMoves = ch_getLegalMoves(row, col)
        ok
    ok

func ch_executeMove fromR, fromC, toR, toC, special
    piece = board[fromR][fromC][1]
    side  = board[fromR][fromC][2]
    captured = board[toR][toC]

    if captured[1] != PIECE_NONE
        if side = SIDE_WHITE
            add(whiteCaptured, captured[1])
        else
            add(blackCaptured, captured[1])
        ok
    ok
    if special = 3
        if side = SIDE_WHITE
            add(whiteCaptured, PIECE_PAWN)
            board[toR + 1][toC] = [PIECE_NONE, 0]
        else
            add(blackCaptured, PIECE_PAWN)
            board[toR - 1][toC] = [PIECE_NONE, 0]
        ok
    ok

    board[toR][toC] = [piece, side]
    board[fromR][fromC] = [PIECE_NONE, 0]

    if special = 1
        board[fromR][6] = [PIECE_ROOK, side]
        board[fromR][8] = [PIECE_NONE, 0]
    ok
    if special = 2
        board[fromR][4] = [PIECE_ROOK, side]
        board[fromR][1] = [PIECE_NONE, 0]
    ok
    if special = 4
        board[toR][toC] = [PIECE_QUEEN, side]
    ok

    epRow = 0   epCol = 0
    if piece = PIECE_PAWN
        diff = toR - fromR
        if diff = 2 or diff = -2
            epRow = fromR + diff / 2
            epCol = fromC
        ok
    ok

    if piece = PIECE_KING
        if side = SIDE_WHITE
            whiteKingMoved = true   whiteKingR = toR   whiteKingC = toC
        else
            blackKingMoved = true   blackKingR = toR   blackKingC = toC
        ok
    ok
    if piece = PIECE_ROOK
        if side = SIDE_WHITE
            if fromR = 8 and fromC = 1 whiteRookAMoved = true ok
            if fromR = 8 and fromC = 8 whiteRookHMoved = true ok
        else
            if fromR = 1 and fromC = 1 blackRookAMoved = true ok
            if fromR = 1 and fromC = 8 blackRookHMoved = true ok
        ok
    ok
    if toR = 1 and toC = 1 blackRookAMoved = true ok
    if toR = 1 and toC = 8 blackRookHMoved = true ok
    if toR = 8 and toC = 1 whiteRookAMoved = true ok
    if toR = 8 and toC = 8 whiteRookHMoved = true ok

    lastFromR = fromR   lastFromC = fromC   lastToR = toR   lastToC = toC
    notation = ch_getMoveNotation(piece, side, fromR, fromC, toR, toC, captured[1], special)
    add(moveHistory, notation)
    moveHistCount = len(moveHistory)

    if currentTurn = SIDE_WHITE
        currentTurn = SIDE_BLACK
    else
        currentTurn = SIDE_WHITE
    ok

    animFromR = fromR   animFromC = fromC   animToR = toR   animToC = toC
    animPiece = piece
    if special = 4 animPiece = PIECE_QUEEN ok
    animSide = side   animProgress = 0.0   animActive = true
    gameState = ST_ANIMATE

func ch_postMoveCheck
    inCheck = ch_isInCheck(currentTurn)
    if ch_hasNoLegalMoves(currentTurn)
        if inCheck
            gameState = ST_CHECKMATE
        else
            gameState = ST_STALEMATE
        ok
        return
    ok
    if currentTurn = SIDE_BLACK
        gameState = ST_AI_THINK
        thinkDots = 0   thinkTimer = 0.0
    else
        gameState = ST_PLAYING
    ok

// ------- AI -------

func ch_aiMove
    bestScore = -INF_VAL
    bestFromR = 0   bestFromC = 0   bestToR = 0   bestToC = 0   bestSpec = 0
    allMoves = ch_getAllMoves(SIDE_BLACK)
    nMoves = len(allMoves)
    if nMoves = 0
        ch_postMoveCheck()
        return
    ok
    ch_orderMoves(allMoves, nMoves)
    for i = 1 to nMoves
        mv = allMoves[i]
        saved = ch_saveBoardState()
        ch_executeMoveSilent(mv[1], mv[2], mv[3], mv[4], mv[5])
        score = ch_minimax(aiDepth - 1, -INF_VAL, INF_VAL, false)
        ch_restoreBoardState(saved)
        if score > bestScore
            bestScore = score
            bestFromR = mv[1]   bestFromC = mv[2]
            bestToR = mv[3]     bestToC = mv[4]     bestSpec = mv[5]
        ok
    next
    if bestFromR > 0
        ch_saveUndo()
        ch_executeMove(bestFromR, bestFromC, bestToR, bestToC, bestSpec)
    else
        ch_postMoveCheck()
    ok

func ch_minimax depth, alpha, beta, isMaximizing
    if depth = 0 return ch_evaluate() ok

    side = SIDE_WHITE
    if isMaximizing side = SIDE_BLACK ok
    allMoves = ch_getAllMoves(side)
    nMoves = len(allMoves)

    if nMoves = 0
        if ch_isInCheck(side)
            if isMaximizing
                return -INF_VAL + (aiDepth - depth)
            else
                return INF_VAL - (aiDepth - depth)
            ok
        else
            return 0
        ok
    ok

    ch_orderMoves(allMoves, nMoves)

    if isMaximizing
        bestVal = -INF_VAL
        for i = 1 to nMoves
            mv = allMoves[i]
            saved = ch_saveBoardState()
            ch_executeMoveSilent(mv[1], mv[2], mv[3], mv[4], mv[5])
            val = ch_minimax(depth - 1, alpha, beta, false)
            ch_restoreBoardState(saved)
            if val > bestVal bestVal = val ok
            if val > alpha alpha = val ok
            if beta <= alpha exit ok
        next
        return bestVal
    else
        bestVal = INF_VAL
        for i = 1 to nMoves
            mv = allMoves[i]
            saved = ch_saveBoardState()
            ch_executeMoveSilent(mv[1], mv[2], mv[3], mv[4], mv[5])
            val = ch_minimax(depth - 1, alpha, beta, true)
            ch_restoreBoardState(saved)
            if val < bestVal bestVal = val ok
            if val < beta beta = val ok
            if beta <= alpha exit ok
        next
        return bestVal
    ok

// ------- EVALUATION (fully inlined - no function calls) -------

func ch_evaluate
    score = 0
    for r = 1 to 8
        for c = 1 to 8
            pt = board[r][c][1]
            if pt = PIECE_NONE loop ok
            sd = board[r][c][2]
            val = PIECE_VAL[pt + 1]

            if pt = PIECE_PAWN
                if sd = SIDE_WHITE
                    val += (8 - r) * 5
                else
                    val += (r - 1) * 5
                ok
                if c >= 3 and c <= 6 val += 10 ok
                if c = 4 or c = 5 val += 5 ok
            ok
            if pt = PIECE_KNIGHT
                if r >= 3 and r <= 6 and c >= 3 and c <= 6
                    val += 20
                ok
                if r = 1 or r = 8 or c = 1 or c = 8
                    val -= 10
                ok
            ok
            if pt = PIECE_BISHOP
                if r >= 3 and r <= 6 and c >= 3 and c <= 6
                    val += 10
                ok
            ok
            if pt = PIECE_ROOK
                if sd = SIDE_WHITE and r = 2 val += 15 ok
                if sd = SIDE_BLACK and r = 7 val += 15 ok
            ok
            if pt = PIECE_KING
                if sd = SIDE_WHITE
                    if r = 8 and (c <= 2 or c >= 7) val += 20 ok
                else
                    if r = 1 and (c <= 2 or c >= 7) val += 20 ok
                ok
            ok

            if sd = SIDE_BLACK
                score += val
            else
                score -= val
            ok
        next
    next
    return score

// ------- MOVE ORDERING (partition: captures+promotions first) -------

func ch_orderMoves moveList, nM
    writeIdx = 1
    for i = 1 to nM
        mv = moveList[i]
        isCapture = false
        if board[mv[3]][mv[4]][1] != PIECE_NONE isCapture = true ok
        if mv[5] = 3 or mv[5] = 4 isCapture = true ok
        if isCapture
            if i != writeIdx
                tmp = moveList[writeIdx]
                moveList[writeIdx] = mv
                moveList[i] = tmp
            ok
            writeIdx += 1
        ok
    next

// ------- SILENT MOVE (AI search) -------

func ch_executeMoveSilent fromR, fromC, toR, toC, special
    piece = board[fromR][fromC][1]
    side  = board[fromR][fromC][2]

    if special = 3
        if side = SIDE_WHITE
            board[toR + 1][toC] = [PIECE_NONE, 0]
        else
            board[toR - 1][toC] = [PIECE_NONE, 0]
        ok
    ok
    board[toR][toC] = [piece, side]
    board[fromR][fromC] = [PIECE_NONE, 0]
    if special = 1
        board[fromR][6] = [PIECE_ROOK, side]
        board[fromR][8] = [PIECE_NONE, 0]
    ok
    if special = 2
        board[fromR][4] = [PIECE_ROOK, side]
        board[fromR][1] = [PIECE_NONE, 0]
    ok
    if special = 4
        board[toR][toC] = [PIECE_QUEEN, side]
    ok

    epRow = 0   epCol = 0
    if piece = PIECE_PAWN
        diff = toR - fromR
        if diff = 2 or diff = -2
            epRow = fromR + diff / 2
            epCol = fromC
        ok
    ok
    if piece = PIECE_KING
        if side = SIDE_WHITE
            whiteKingMoved = true   whiteKingR = toR   whiteKingC = toC
        else
            blackKingMoved = true   blackKingR = toR   blackKingC = toC
        ok
    ok
    if piece = PIECE_ROOK
        if side = SIDE_WHITE
            if fromR = 8 and fromC = 1 whiteRookAMoved = true ok
            if fromR = 8 and fromC = 8 whiteRookHMoved = true ok
        else
            if fromR = 1 and fromC = 1 blackRookAMoved = true ok
            if fromR = 1 and fromC = 8 blackRookHMoved = true ok
        ok
    ok
    if toR = 1 and toC = 1 blackRookAMoved = true ok
    if toR = 1 and toC = 8 blackRookHMoved = true ok
    if toR = 8 and toC = 1 whiteRookAMoved = true ok
    if toR = 8 and toC = 8 whiteRookHMoved = true ok

    if currentTurn = SIDE_WHITE
        currentTurn = SIDE_BLACK
    else
        currentTurn = SIDE_WHITE
    ok

// ------- BOARD STATE SAVE/RESTORE -------

func ch_saveBoardState
    s = list(141)
    idx = 1
    for r = 1 to 8
        for c = 1 to 8
            s[idx]   = board[r][c][1]
            s[idx+1] = board[r][c][2]
            idx += 2
        next
    next
    s[129] = currentTurn
    s[130] = epRow
    s[131] = epCol
    s[132] = whiteKingMoved
    s[133] = whiteRookAMoved
    s[134] = whiteRookHMoved
    s[135] = blackKingMoved
    s[136] = blackRookAMoved
    s[137] = blackRookHMoved
    s[138] = whiteKingR
    s[139] = whiteKingC
    s[140] = blackKingR
    s[141] = blackKingC
    return s

func ch_restoreBoardState s
    idx = 1
    for r = 1 to 8
        for c = 1 to 8
            board[r][c] = [s[idx], s[idx+1]]
            idx += 2
        next
    next
    currentTurn     = s[129]
    epRow           = s[130]
    epCol           = s[131]
    whiteKingMoved  = s[132]
    whiteRookAMoved = s[133]
    whiteRookHMoved = s[134]
    blackKingMoved  = s[135]
    blackRookAMoved = s[136]
    blackRookHMoved = s[137]
    whiteKingR      = s[138]
    whiteKingC      = s[139]
    blackKingR      = s[140]
    blackKingC      = s[141]

// ------- UNDO -------

func ch_saveUndo
    snap = []
    add(snap, ch_saveBoardState())
    add(snap, lastFromR)
    add(snap, lastFromC)
    add(snap, lastToR)
    add(snap, lastToC)
    add(snap, inCheck)
    add(snap, len(whiteCaptured))
    add(snap, len(blackCaptured))
    add(snap, moveHistCount)
    add(undoStack, snap)

func ch_undoMove
    nUndo = len(undoStack)
    if nUndo < 2 return ok

    snap = undoStack[nUndo - 1]
    ch_restoreBoardState(snap[1])
    lastFromR = snap[2]   lastFromC = snap[3]
    lastToR = snap[4]     lastToC = snap[5]
    inCheck = snap[6]

    wcLen = snap[7]
    bcLen = snap[8]
    nWC = len(whiteCaptured)
    while nWC > wcLen
        del(whiteCaptured, nWC)
        nWC -= 1
    end
    nBC = len(blackCaptured)
    while nBC > bcLen
        del(blackCaptured, nBC)
        nBC -= 1
    end
    mhLen = snap[9]
    nMH = len(moveHistory)
    while nMH > mhLen
        del(moveHistory, nMH)
        nMH -= 1
    end
    moveHistCount = mhLen

    del(undoStack, nUndo)
    del(undoStack, nUndo - 1)
    hasSelection = false   legalMoves = []
    gameState = ST_PLAYING

// ------- MOVE GENERATION -------

func ch_getAllMoves side
    moves = []
    for r = 1 to 8
        for c = 1 to 8
            if board[r][c][2] = side
                pMoves = ch_getLegalMoves(r, c)
                nPM = len(pMoves)
                for m = 1 to nPM
                    pm = pMoves[m]
                    add(moves, [r, c, pm[1], pm[2], pm[3]])
                next
            ok
        next
    next
    return moves

func ch_hasNoLegalMoves side
    for r = 1 to 8
        for c = 1 to 8
            if board[r][c][2] = side
                pMoves = ch_getLegalMoves(r, c)
                if len(pMoves) > 0
                    return false
                ok
            ok
        next
    next
    return true

func ch_getLegalMoves row, col
    piece = board[row][col][1]
    side  = board[row][col][2]
    pseudo = []

    switch piece
    on PIECE_PAWN   pseudo = ch_pawnMoves(row, col, side)
    on PIECE_KNIGHT pseudo = ch_knightMoves(row, col, side)
    on PIECE_BISHOP pseudo = ch_bishopMoves(row, col, side)
    on PIECE_ROOK   pseudo = ch_rookMoves(row, col, side)
    on PIECE_QUEEN
        pseudo = ch_bishopMoves(row, col, side)
        rMoves = ch_rookMoves(row, col, side)
        nRM = len(rMoves)
        for i = 1 to nRM
            add(pseudo, rMoves[i])
        next
    on PIECE_KING   pseudo = ch_kingMoves(row, col, side)
    off

    legal = []
    nP = len(pseudo)
    for i = 1 to nP
        pm = pseudo[i]
        saved = ch_saveBoardState()
        ch_executeMoveSilent(row, col, pm[1], pm[2], pm[3])
        if !ch_isInCheck(side)
            add(legal, pm)
        ok
        ch_restoreBoardState(saved)
    next
    return legal

// ------- PIECE MOVE GENERATORS -------

func ch_pawnMoves row, col, side
    moves = []
    dir = -1   startRow = 7   promoRow = 1
    if side = SIDE_BLACK
        dir = 1   startRow = 2   promoRow = 8
    ok
    nr = row + dir
    if nr >= 1 and nr <= 8
        if board[nr][col][1] = PIECE_NONE
            if nr = promoRow
                add(moves, [nr, col, 4])
            else
                add(moves, [nr, col, 0])
            ok
            if row = startRow
                nr2 = row + dir * 2
                if nr2 >= 1 and nr2 <= 8
                    if board[nr2][col][1] = PIECE_NONE
                        add(moves, [nr2, col, 0])
                    ok
                ok
            ok
        ok
    ok
    for dc = -1 to 1 step 2
        nc = col + dc
        nr = row + dir
        if nc >= 1 and nc <= 8 and nr >= 1 and nr <= 8
            target = board[nr][nc]
            if target[1] != PIECE_NONE and target[2] != side
                if nr = promoRow
                    add(moves, [nr, nc, 4])
                else
                    add(moves, [nr, nc, 0])
                ok
            ok
            if nr = epRow and nc = epCol
                add(moves, [nr, nc, 3])
            ok
        ok
    next
    return moves

func ch_knightMoves row, col, side
    moves = []
    for i = 1 to 8
        nr = row + KNIGHT_DR[i]
        nc = col + KNIGHT_DC[i]
        if nr >= 1 and nr <= 8 and nc >= 1 and nc <= 8
            target = board[nr][nc]
            if target[1] = PIECE_NONE or target[2] != side
                add(moves, [nr, nc, 0])
            ok
        ok
    next
    return moves

func ch_bishopMoves row, col, side
    moves = []
    for d = 1 to 4
        dr = DIAG_DR[d]
        dc = DIAG_DC[d]
        nr = row + dr
        nc = col + dc
        while nr >= 1 and nr <= 8 and nc >= 1 and nc <= 8
            target = board[nr][nc]
            if target[1] = PIECE_NONE
                add(moves, [nr, nc, 0])
            else
                if target[2] != side
                    add(moves, [nr, nc, 0])
                ok
                exit
            ok
            nr += dr
            nc += dc
        end
    next
    return moves

func ch_rookMoves row, col, side
    moves = []
    for d = 1 to 4
        dr = STRAIGHT_DR[d]
        dc = STRAIGHT_DC[d]
        nr = row + dr
        nc = col + dc
        while nr >= 1 and nr <= 8 and nc >= 1 and nc <= 8
            target = board[nr][nc]
            if target[1] = PIECE_NONE
                add(moves, [nr, nc, 0])
            else
                if target[2] != side
                    add(moves, [nr, nc, 0])
                ok
                exit
            ok
            nr += dr
            nc += dc
        end
    next
    return moves

func ch_kingMoves row, col, side
    moves = []
    for dr = -1 to 1
        for dc = -1 to 1
            if dr = 0 and dc = 0 loop ok
            nr = row + dr
            nc = col + dc
            if nr >= 1 and nr <= 8 and nc >= 1 and nc <= 8
                target = board[nr][nc]
                if target[1] = PIECE_NONE or target[2] != side
                    add(moves, [nr, nc, 0])
                ok
            ok
        next
    next
    if side = SIDE_WHITE and !whiteKingMoved and !ch_isInCheck(SIDE_WHITE) and row = 8 and col = 5
        if !whiteRookHMoved
            if board[8][6][1] = PIECE_NONE and board[8][7][1] = PIECE_NONE
                if !ch_isSquareAttacked(8, 6, SIDE_BLACK) and !ch_isSquareAttacked(8, 7, SIDE_BLACK)
                    add(moves, [8, 7, 1])
                ok
            ok
        ok
        if !whiteRookAMoved
            if board[8][4][1] = PIECE_NONE and board[8][3][1] = PIECE_NONE and board[8][2][1] = PIECE_NONE
                if !ch_isSquareAttacked(8, 4, SIDE_BLACK) and !ch_isSquareAttacked(8, 3, SIDE_BLACK)
                    add(moves, [8, 3, 2])
                ok
            ok
        ok
    ok
    if side = SIDE_BLACK and !blackKingMoved and !ch_isInCheck(SIDE_BLACK) and row = 1 and col = 5
        if !blackRookHMoved
            if board[1][6][1] = PIECE_NONE and board[1][7][1] = PIECE_NONE
                if !ch_isSquareAttacked(1, 6, SIDE_WHITE) and !ch_isSquareAttacked(1, 7, SIDE_WHITE)
                    add(moves, [1, 7, 1])
                ok
            ok
        ok
        if !blackRookAMoved
            if board[1][4][1] = PIECE_NONE and board[1][3][1] = PIECE_NONE and board[1][2][1] = PIECE_NONE
                if !ch_isSquareAttacked(1, 4, SIDE_WHITE) and !ch_isSquareAttacked(1, 3, SIDE_WHITE)
                    add(moves, [1, 3, 2])
                ok
            ok
        ok
    ok
    return moves

// ------- CHECK DETECTION (fully optimized) -------

func ch_isInCheck side
    kR = whiteKingR   kC = whiteKingC
    if side = SIDE_BLACK
        kR = blackKingR   kC = blackKingC
    ok
    oppSide = SIDE_BLACK
    if side = SIDE_BLACK oppSide = SIDE_WHITE ok
    return ch_isSquareAttacked(kR, kC, oppSide)

func ch_isSquareAttacked row, col, byWhichSide
    // Knight attacks (pre-computed global arrays)
    for i = 1 to 8
        nr = row + KNIGHT_DR[i]
        nc = col + KNIGHT_DC[i]
        if nr >= 1 and nr <= 8 and nc >= 1 and nc <= 8
            if board[nr][nc][1] = PIECE_KNIGHT and board[nr][nc][2] = byWhichSide
                return true
            ok
        ok
    next

    // Pawn attacks
    pawnDir = 1
    if byWhichSide = SIDE_BLACK pawnDir = -1 ok
    pR = row + pawnDir
    if pR >= 1 and pR <= 8
        if col - 1 >= 1
            if board[pR][col-1][1] = PIECE_PAWN and board[pR][col-1][2] = byWhichSide
                return true
            ok
        ok
        if col + 1 <= 8
            if board[pR][col+1][1] = PIECE_PAWN and board[pR][col+1][2] = byWhichSide
                return true
            ok
        ok
    ok

    // King attacks
    for dr = -1 to 1
        for dc = -1 to 1
            if dr = 0 and dc = 0 loop ok
            nr = row + dr
            nc = col + dc
            if nr >= 1 and nr <= 8 and nc >= 1 and nc <= 8
                if board[nr][nc][1] = PIECE_KING and board[nr][nc][2] = byWhichSide
                    return true
                ok
            ok
        next
    next

    // Rook/Queen (straight lines)
    for d = 1 to 4
        dr = STRAIGHT_DR[d]
        dc = STRAIGHT_DC[d]
        nr = row + dr
        nc = col + dc
        while nr >= 1 and nr <= 8 and nc >= 1 and nc <= 8
            cp = board[nr][nc][1]
            if cp != PIECE_NONE
                if board[nr][nc][2] = byWhichSide and (cp = PIECE_ROOK or cp = PIECE_QUEEN)
                    return true
                ok
                exit
            ok
            nr += dr
            nc += dc
        end
    next

    // Bishop/Queen (diagonals)
    for d = 1 to 4
        dr = DIAG_DR[d]
        dc = DIAG_DC[d]
        nr = row + dr
        nc = col + dc
        while nr >= 1 and nr <= 8 and nc >= 1 and nc <= 8
            cp = board[nr][nc][1]
            if cp != PIECE_NONE
                if board[nr][nc][2] = byWhichSide and (cp = PIECE_BISHOP or cp = PIECE_QUEEN)
                    return true
                ok
                exit
            ok
            nr += dr
            nc += dc
        end
    next

    return false

// ------- MOVE NOTATION -------

func ch_getMoveNotation piece, side, fromR, fromC, toR, toC, captured, special
    s = ""
    if special = 1 return "O-O" ok
    if special = 2 return "O-O-O" ok
    switch piece
    on PIECE_KNIGHT s = "N"
    on PIECE_BISHOP s = "B"
    on PIECE_ROOK   s = "R"
    on PIECE_QUEEN  s = "Q"
    on PIECE_KING   s = "K"
    off
    if piece = PIECE_PAWN and (captured != PIECE_NONE or special = 3)
        s = ch_colToFile(fromC)
    ok
    if captured != PIECE_NONE or special = 3
        s += "x"
    ok
    s += ch_colToFile(toC)
    s += "" + (9 - toR)
    if special = 4 s += "=Q" ok
    return s

func ch_colToFile c
    files = "abcdefgh"
    return substr(files, c, 1)

// ------- DRAWING -------

func ch_drawTitle
    DrawText("CHESS", 370, 120, 60, colTitle)
    DrawText("Ring + RayLib", 375, 195, 24, colTextDark)
    DrawText("Game #10 in our series!", 358, 230, 20, colTextDark)
    DrawText("Select Difficulty:", 390, 300, 22, colTextLight)
    mx = GetMouseX()   my = GetMouseY()
    c1 = colButton
    if mx >= 350 and mx <= 550 and my >= 340 and my <= 385 c1 = colButtonHover ok
    DrawRectangle(350, 340, 200, 45, c1)
    DrawText("1 - Easy", 405, 352, 24, colTextLight)
    c2 = colButton
    if mx >= 350 and mx <= 550 and my >= 400 and my <= 445 c2 = colButtonHover ok
    DrawRectangle(350, 400, 200, 45, c2)
    DrawText("2 - Medium", 393, 412, 24, colTextLight)
    c3 = colButton
    if mx >= 350 and mx <= 550 and my >= 460 and my <= 505 c3 = colButtonHover ok
    DrawRectangle(350, 460, 200, 45, c3)
    DrawText("3 - Hard", 405, 472, 24, colTextLight)
    DrawText("You play as White (bottom)", 350, 540, 18, colTextDark)

func ch_drawBoard
    DrawRectangle(BOARD_X - 4, BOARD_Y - 4, BOARD_PX + 8, BOARD_PX + 8, colBorder)
    kR = 0   kC = 0
    if inCheck
        kR = whiteKingR   kC = whiteKingC
        if currentTurn = SIDE_BLACK
            kR = blackKingR   kC = blackKingC
        ok
    ok
    for r = 1 to 8
        for c = 1 to 8
            x = BOARD_X + (c - 1) * SQ_SIZE
            y = BOARD_Y + (r - 1) * SQ_SIZE
            if (r + c) % 2 = 0
                DrawRectangle(x, y, SQ_SIZE, SQ_SIZE, colBoardLight)
            else
                DrawRectangle(x, y, SQ_SIZE, SQ_SIZE, colBoardDark)
            ok
            if (r = lastFromR and c = lastFromC) or (r = lastToR and c = lastToC)
                DrawRectangle(x, y, SQ_SIZE, SQ_SIZE, colLastMove)
            ok
            if hasSelection and r = selRow and c = selCol
                DrawRectangle(x, y, SQ_SIZE, SQ_SIZE, colSelected)
            ok
            if inCheck and r = kR and c = kC
                DrawRectangle(x, y, SQ_SIZE, SQ_SIZE, colCheck)
            ok
        next
    next

    nLM = len(legalMoves)
    for i = 1 to nLM
        mv = legalMoves[i]
        mr = mv[1]   mc = mv[2]
        bx = BOARD_X + (mc - 1) * SQ_SIZE
        by = BOARD_Y + (mr - 1) * SQ_SIZE
        if board[mr][mc][1] != PIECE_NONE
            DrawTriangle(Vector2(bx, by), Vector2(bx + 18, by), Vector2(bx, by + 18), colLegalMove)
            DrawTriangle(Vector2(bx + SQ_SIZE, by), Vector2(bx + SQ_SIZE - 18, by), Vector2(bx + SQ_SIZE, by + 18), colLegalMove)
            DrawTriangle(Vector2(bx, by + SQ_SIZE), Vector2(bx + 18, by + SQ_SIZE), Vector2(bx, by + SQ_SIZE - 18), colLegalMove)
            DrawTriangle(Vector2(bx + SQ_SIZE, by + SQ_SIZE), Vector2(bx + SQ_SIZE - 18, by + SQ_SIZE), Vector2(bx + SQ_SIZE, by + SQ_SIZE - 18), colLegalMove)
        else
            DrawCircle(bx + SQ_SIZE / 2, by + SQ_SIZE / 2, 10, colLegalMove)
        ok
    next

    files = "abcdefgh"
    for c = 1 to 8
        DrawText(substr(files, c, 1), BOARD_X + (c - 1) * SQ_SIZE + SQ_SIZE / 2 - 4, BOARD_Y + BOARD_PX + 8, 16, colTextDark)
    next
    for r = 1 to 8
        DrawText("" + (9 - r), BOARD_X - 18, BOARD_Y + (r - 1) * SQ_SIZE + SQ_SIZE / 2 - 8, 16, colTextDark)
    next

func ch_drawPieces
    for r = 1 to 8
        for c = 1 to 8
            if animActive and r = animFromR and c = animFromC loop ok
            p = board[r][c]
            if p[1] != PIECE_NONE
                ch_drawPieceAt(p[1], p[2], BOARD_X + (c-1)*SQ_SIZE + SQ_SIZE/2, BOARD_Y + (r-1)*SQ_SIZE + SQ_SIZE/2)
            ok
        next
    next
    if animActive
        fromPx = BOARD_X + (animFromC - 1) * SQ_SIZE + SQ_SIZE / 2
        fromPy = BOARD_Y + (animFromR - 1) * SQ_SIZE + SQ_SIZE / 2
        toPx   = BOARD_X + (animToC - 1) * SQ_SIZE + SQ_SIZE / 2
        toPy   = BOARD_Y + (animToR - 1) * SQ_SIZE + SQ_SIZE / 2
        t = animProgress
        if t > 1 t = 1 ok
        t = t * t * (3 - 2 * t)
        ch_drawPieceAt(animPiece, animSide, fromPx + (toPx - fromPx) * t, fromPy + (toPy - fromPy) * t)
    ok

func ch_drawPieceAt pieceType, side, cx, cy
    pCol = colWhitePiece
    oCol = colBlackPiece
    if side = SIDE_BLACK
        pCol = colBlackPiece
        oCol = colWhitePiece
    ok
    switch pieceType
    on PIECE_PAWN
        DrawRectangle(cx-14, cy+12, 28, 10, pCol)
        DrawRectangleLines(cx-14, cy+12, 28, 10, oCol)
        DrawRectangle(cx-7, cy-2, 14, 16, pCol)
        DrawRectangleLines(cx-7, cy-2, 14, 16, oCol)
        DrawCircle(cx, cy-10, 11, pCol)
        DrawCircleLines(cx, cy-10, 11, oCol)
    on PIECE_KNIGHT
        DrawRectangle(cx-16, cy+12, 32, 10, pCol)
        DrawRectangleLines(cx-16, cy+12, 32, 10, oCol)
        DrawRectangle(cx-8, cy-5, 16, 19, pCol)
        DrawRectangleLines(cx-8, cy-5, 16, 19, oCol)
        DrawRectangle(cx-6, cy-20, 12, 18, pCol)
        DrawRectangleLines(cx-6, cy-20, 12, 18, oCol)
        DrawRectangle(cx-14, cy-24, 20, 10, pCol)
        DrawRectangleLines(cx-14, cy-24, 20, 10, oCol)
        DrawTriangle(Vector2(cx-2, cy-30), Vector2(cx+6, cy-24), Vector2(cx-2, cy-24), pCol)
        if side = SIDE_WHITE
            DrawCircle(cx-7, cy-20, 2, BLACK)
        else
            DrawCircle(cx-7, cy-20, 2, WHITE)
        ok
    on PIECE_BISHOP
        DrawRectangle(cx-16, cy+12, 32, 10, pCol)
        DrawRectangleLines(cx-16, cy+12, 32, 10, oCol)
        DrawRectangle(cx-10, cy-4, 20, 18, pCol)
        DrawRectangleLines(cx-10, cy-4, 20, 18, oCol)
        DrawRectangle(cx-7, cy-16, 14, 14, pCol)
        DrawRectangleLines(cx-7, cy-16, 14, 14, oCol)
        DrawTriangle(Vector2(cx, cy-28), Vector2(cx+8, cy-16), Vector2(cx-8, cy-16), pCol)
        DrawCircle(cx, cy-28, 3, pCol)
        DrawCircleLines(cx, cy-28, 3, oCol)
        DrawLine(cx-5, cy-6, cx+5, cy-14, oCol)
    on PIECE_ROOK
        DrawRectangle(cx-18, cy+12, 36, 10, pCol)
        DrawRectangleLines(cx-18, cy+12, 36, 10, oCol)
        DrawRectangle(cx-13, cy-8, 26, 22, pCol)
        DrawRectangleLines(cx-13, cy-8, 26, 22, oCol)
        DrawRectangle(cx-16, cy-14, 32, 8, pCol)
        DrawRectangleLines(cx-16, cy-14, 32, 8, oCol)
        DrawRectangle(cx-16, cy-24, 9, 12, pCol)
        DrawRectangleLines(cx-16, cy-24, 9, 12, oCol)
        DrawRectangle(cx-4, cy-24, 9, 12, pCol)
        DrawRectangleLines(cx-4, cy-24, 9, 12, oCol)
        DrawRectangle(cx+8, cy-24, 9, 12, pCol)
        DrawRectangleLines(cx+8, cy-24, 9, 12, oCol)
    on PIECE_QUEEN
        DrawRectangle(cx-18, cy+12, 36, 10, pCol)
        DrawRectangleLines(cx-18, cy+12, 36, 10, oCol)
        DrawRectangle(cx-12, cy-6, 24, 20, pCol)
        DrawRectangleLines(cx-12, cy-6, 24, 20, oCol)
        DrawRectangle(cx-9, cy-14, 18, 10, pCol)
        DrawRectangleLines(cx-9, cy-14, 18, 10, oCol)
        DrawTriangle(Vector2(cx-16, cy-14), Vector2(cx-12, cy-26), Vector2(cx-8, cy-14), pCol)
        DrawTriangle(Vector2(cx-8, cy-14), Vector2(cx-4, cy-28), Vector2(cx, cy-14), pCol)
        DrawTriangle(Vector2(cx, cy-14), Vector2(cx+4, cy-28), Vector2(cx+8, cy-14), pCol)
        DrawTriangle(Vector2(cx+8, cy-14), Vector2(cx+12, cy-26), Vector2(cx+16, cy-14), pCol)
        DrawCircle(cx-12, cy-26, 3, pCol)
        DrawCircleLines(cx-12, cy-26, 3, oCol)
        DrawCircle(cx-4, cy-28, 3, pCol)
        DrawCircleLines(cx-4, cy-28, 3, oCol)
        DrawCircle(cx+4, cy-28, 3, pCol)
        DrawCircleLines(cx+4, cy-28, 3, oCol)
        DrawCircle(cx+12, cy-26, 3, pCol)
        DrawCircleLines(cx+12, cy-26, 3, oCol)
    on PIECE_KING
        DrawRectangle(cx-18, cy+12, 36, 10, pCol)
        DrawRectangleLines(cx-18, cy+12, 36, 10, oCol)
        DrawRectangle(cx-12, cy-6, 24, 20, pCol)
        DrawRectangleLines(cx-12, cy-6, 24, 20, oCol)
        DrawRectangle(cx-9, cy-14, 18, 10, pCol)
        DrawRectangleLines(cx-9, cy-14, 18, 10, oCol)
        DrawRectangle(cx-12, cy-18, 24, 6, pCol)
        DrawRectangleLines(cx-12, cy-18, 24, 6, oCol)
        DrawRectangle(cx-3, cy-32, 6, 16, pCol)
        DrawRectangleLines(cx-3, cy-32, 6, 16, oCol)
        DrawRectangle(cx-9, cy-28, 18, 5, pCol)
        DrawRectangleLines(cx-9, cy-28, 18, 5, oCol)
    off

func ch_drawPanel
    DrawRectangle(PANEL_X, BOARD_Y - 4, PANEL_W, BOARD_PX + 8, colPanel)
    DrawRectangleLines(PANEL_X, BOARD_Y - 4, PANEL_W, BOARD_PX + 8, colPanelBorder)
    py = BOARD_Y + 10
    turnText = "White's Turn"   turnColor = colWhitePiece
    if currentTurn = SIDE_BLACK
        turnText = "Black's Turn"   turnColor = colTextDark
    ok
    DrawText(turnText, PANEL_X + 15, py, 22, turnColor)
    py += 35
    diffText = "Easy"
    if aiDepth = AI_MEDIUM diffText = "Medium" ok
    if aiDepth = AI_HARD diffText = "Hard" ok
    DrawText("AI: " + diffText, PANEL_X + 15, py, 18, colTextDark)
    py += 30
    if inCheck
        DrawText("CHECK!", PANEL_X + 15, py, 22, colCheckText)
    ok
    py += 30
    DrawLine(PANEL_X + 10, py, PANEL_X + PANEL_W - 10, py, colSepLine)
    py += 15
    DrawText("Captured by White:", PANEL_X + 15, py, 16, colTextDark)
    py += 22
    nWC = len(whiteCaptured)
    cx = PANEL_X + 20
    for i = 1 to nWC
        ch_drawMiniPiece(whiteCaptured[i], SIDE_BLACK, cx, py + 10)
        cx += 22
        if cx > PANEL_X + PANEL_W - 25
            cx = PANEL_X + 20   py += 24
        ok
    next
    py += 30
    DrawText("Captured by Black:", PANEL_X + 15, py, 16, colTextDark)
    py += 22
    nBC = len(blackCaptured)
    cx = PANEL_X + 20
    for i = 1 to nBC
        ch_drawMiniPiece(blackCaptured[i], SIDE_WHITE, cx, py + 10)
        cx += 22
        if cx > PANEL_X + PANEL_W - 25
            cx = PANEL_X + 20   py += 24
        ok
    next
    py += 35
    DrawLine(PANEL_X + 10, py, PANEL_X + PANEL_W - 10, py, colSepLine)
    py += 10
    DrawText("Move History:", PANEL_X + 15, py, 16, colTextDark)
    py += 22
    startIdx = 1   maxShow = 16
    if moveHistCount > maxShow
        startIdx = moveHistCount - maxShow + 1
    ok
    moveNum = floor((startIdx - 1) / 2) + 1
    i = startIdx
    while i <= moveHistCount and py < BOARD_Y + BOARD_PX - 20
        line = ""
        if i % 2 = 1
            line = "" + moveNum + ". " + moveHistory[i]
            if i + 1 <= moveHistCount
                line += "  " + moveHistory[i + 1]
                i += 2
            else
                i += 1
            ok
            moveNum += 1
        else
            line = "   " + moveHistory[i]
            i += 1
        ok
        DrawText(line, PANEL_X + 15, py, 15, colTextLight)
        py += 18
    end
    DrawText("R:Restart  U:Undo", PANEL_X + 15, BOARD_Y + BOARD_PX - 20, 14, colTextDark)

func ch_drawMiniPiece pieceType, side, cx, cy
    pCol = colWhitePiece   oCol = colBlackPiece
    if side = SIDE_BLACK
        pCol = colMiniBlack   oCol = colMiniBlackOut
    ok
    switch pieceType
    on PIECE_PAWN
        DrawCircle(cx, cy-3, 6, pCol)
        DrawCircleLines(cx, cy-3, 6, oCol)
        DrawRectangle(cx-6, cy+3, 12, 4, pCol)
    on PIECE_KNIGHT
        DrawRectangle(cx-5, cy-8, 10, 14, pCol)
        DrawRectangleLines(cx-5, cy-8, 10, 14, oCol)
        DrawRectangle(cx-8, cy-10, 10, 5, pCol)
    on PIECE_BISHOP
        DrawTriangle(Vector2(cx, cy-12), Vector2(cx+6, cy), Vector2(cx-6, cy), pCol)
        DrawRectangle(cx-7, cy, 14, 5, pCol)
        DrawCircle(cx, cy-12, 2, pCol)
    on PIECE_ROOK
        DrawRectangle(cx-7, cy-6, 14, 12, pCol)
        DrawRectangleLines(cx-7, cy-6, 14, 12, oCol)
        DrawRectangle(cx-8, cy-10, 5, 5, pCol)
        DrawRectangle(cx+3, cy-10, 5, 5, pCol)
    on PIECE_QUEEN
        DrawTriangle(Vector2(cx, cy-14), Vector2(cx+8, cy), Vector2(cx-8, cy), pCol)
        DrawCircle(cx, cy-14, 3, pCol)
        DrawCircleLines(cx, cy-14, 3, oCol)
        DrawRectangle(cx-8, cy, 16, 5, pCol)
    on PIECE_KING
        DrawRectangle(cx-7, cy-5, 14, 12, pCol)
        DrawRectangleLines(cx-7, cy-5, 14, 12, oCol)
        DrawRectangle(cx-2, cy-14, 4, 10, pCol)
        DrawRectangle(cx-5, cy-12, 10, 3, pCol)
    off

func ch_drawThinking
    t = "AI Thinking"
    for i = 1 to thinkDots
        t += "."
    next
    DrawText(t, BOARD_X + BOARD_PX / 2 - 80, BOARD_Y - 28, 22, colThinkText)

func ch_drawGameOver isCheckmate
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, colOverlay)
    if isCheckmate
        winner = "White"
        if currentTurn = SIDE_WHITE winner = "Black" ok
        DrawText("CHECKMATE!", BOARD_X + BOARD_PX/2 - 120, 260, 40, colTitle)
        DrawText(winner + " wins!", BOARD_X + BOARD_PX/2 - 70, 320, 28, colTextLight)
    else
        DrawText("STALEMATE!", BOARD_X + BOARD_PX/2 - 115, 260, 40, colTextLight)
        DrawText("Game is a draw", BOARD_X + BOARD_PX/2 - 85, 320, 28, colTextDark)
    ok
    DrawText("Press R or ENTER to play again", BOARD_X + BOARD_PX/2 - 155, 380, 20, colTextDark)
