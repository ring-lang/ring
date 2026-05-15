/*
**  Chess 3D - Using RingRayLib (Performance Optimized)
**  =====================================================
**  Play chess against the computer in 3D!
**  You are White (front), computer plays Black (back).
**
**  Controls:
**    Mouse Click     - Select piece / Move piece
**    C               - Cycle camera (Front/Isometric/Overhead)
**    R               - Restart game
**    U               - Undo last move
**    1/2/3           - AI difficulty (Easy/Medium/Hard)
**    ESC             - Exit
**
**  Performance optimized:
**    - Lightweight make/unmake for AI search (no list alloc)
**    - Move ordering (captures first) for better pruning
**    - All len() cached before loops
**    - No board reference caching (Ring reference safety)
**    - Inlined evaluation
**
**  Ring + RayLib 3D Game
*/

load "raylib.ring"

SCREEN_W     = 1100
SCREEN_H     = 750
BOARD_SZ     = 8
CELL_SZ      = 1.4

PC_NONE = 0  PC_PAWN = 1  PC_KNIGHT = 2  PC_BISHOP = 3
PC_ROOK = 4  PC_QUEEN = 5  PC_KING = 6
SD_WHITE = 1  SD_BLACK = 2

ST_TITLE = 1  ST_PLAYING = 2  ST_AI_THINK = 3
ST_ANIMATE = 4  ST_CHECKMATE = 5  ST_STALEMATE = 6
CAM_FRONT = 1  CAM_ISO = 2  CAM_OVERHEAD = 3  CAM_COUNT = 3
AI_EASY = 2  AI_MEDIUM = 3  AI_HARD = 4
ANIM_SPEED = 4.0  INF_VAL = 999999

KNIGHT_DR = [-2, -2, -1, -1,  1, 1,  2, 2]
KNIGHT_DC = [-1,  1, -2,  2, -2, 2, -1, 1]
DIAG_DR   = [-1, -1,  1, 1]
DIAG_DC   = [-1,  1, -1, 1]
STRAIGHT_DR = [-1, 1,  0, 0]
STRAIGHT_DC = [ 0, 0, -1, 1]
PIECE_VAL = [0, 100, 320, 330, 500, 900, 20000]

board = []
for rr = 1 to 8
    row = []
    for cc = 1 to 8
        add(row, [PC_NONE, 0])
    next
    add(board, row)
next

gameState = ST_TITLE  animTime = 0.0  dt = 0.0  currentTurn = SD_WHITE
selRow = 0  selCol = 0  hasSelection = false  legalMoves = []
lastFromR = 0  lastFromC = 0  lastToR = 0  lastToC = 0
epRow = 0  epCol = 0
wKingMoved = false  wRookAMoved = false  wRookHMoved = false
bKingMoved = false  bRookAMoved = false  bRookHMoved = false
wKingR = 8  wKingC = 5  bKingR = 1  bKingC = 5
inCheck = false  aiDepth = AI_MEDIUM
whiteCaptured = []  blackCaptured = []
moveHistory = []  undoStack = []
cameraMode = CAM_FRONT
camPosX = 0.0  camPosY = 16.0  camPosZ = 15.0
camTgtX = 0.0  camTgtY = -0.5  camTgtZ = -1.0
camZoom = 1.0
camOffX = 0.0  camOffZ = 0.0
animActive = false  animFromR = 0  animFromC = 0
animToR = 0  animToC = 0  animPiece = 0  animSide = 0  animProgress = 0.0
thinkDots = 0  thinkTimer = 0.0
hoverRow = 0  hoverCol = 0
particles = []
scoreWhite = 0  scoreBlack = 0
projSX = 0.0  projSY = 0.0

InitWindow(SCREEN_W, SCREEN_H, "Ring 3D Chess - RingRayLib")
//ToggleFullScreen()
SetTargetFPS(60)

camera = Camera3D(
    0, 16, 15,
    0, -0.5, -1,
    0, 1, 0,
    45,
    CAMERA_PERSPECTIVE
)

while !WindowShouldClose()
    dt = GetFrameTime()
    if dt > 0.05 dt = 0.05 ok
    animTime += dt

    if IsKeyPressed(KEY_ONE)   aiDepth = AI_EASY   ok
    if IsKeyPressed(KEY_TWO)   aiDepth = AI_MEDIUM  ok
    if IsKeyPressed(KEY_THREE) aiDepth = AI_HARD    ok
    if IsKeyPressed(KEY_C)
        cameraMode += 1
        if cameraMode > CAM_COUNT cameraMode = CAM_FRONT ok
        camOffX = 0.0  camOffZ = 0.0  camZoom = 1.0
    ok
    wheel = GetMouseWheelMove()
    if wheel != 0
        camZoom -= wheel * 0.08
        if camZoom < 0.4 camZoom = 0.4 ok
        if camZoom > 2.0 camZoom = 2.0 ok
    ok
    panSpd = 8.0 * dt
    if IsKeyDown(KEY_A) camOffX -= panSpd ok
    if IsKeyDown(KEY_D) camOffX += panSpd ok
    if IsKeyDown(KEY_W) camOffZ -= panSpd ok
    if IsKeyDown(KEY_S) camOffZ += panSpd ok
    if camOffX > 12.0 camOffX = 12.0 ok  if camOffX < -12.0 camOffX = -12.0 ok
    if camOffZ > 12.0 camOffZ = 12.0 ok  if camOffZ < -12.0 camOffZ = -12.0 ok

    stateHandled = false
    if gameState = ST_TITLE and !stateHandled
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or
           IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
            c3_startNewGame()
            stateHandled = true
        ok
    ok
    if gameState = ST_PLAYING and !stateHandled
        c3_updateHover()
        c3_handleInput()
        stateHandled = true
    ok
    if gameState = ST_AI_THINK and !stateHandled
        thinkTimer += dt
        if thinkTimer > 0.25
            thinkTimer = 0
            thinkDots += 1
            if thinkDots > 3 thinkDots = 0 ok
        ok
        c3_aiMove()
        stateHandled = true
    ok
    if gameState = ST_ANIMATE and !stateHandled
        animProgress += dt * ANIM_SPEED
        if animProgress >= 1.0
            animProgress = 1.0
            animActive = false
            c3_postMoveCheck()
        ok
        stateHandled = true
    ok
    if (gameState = ST_CHECKMATE or gameState = ST_STALEMATE) and !stateHandled
        if IsKeyPressed(KEY_R) or IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            gameState = ST_TITLE
            stateHandled = true
        ok
    ok

    c3_updateCamera()
    c3_updateParticles()

    BeginDrawing()
    ClearBackground(RAYLIBColor(25, 22, 30, 255))
    if gameState = ST_TITLE
        c3_drawTitle()
    else
        BeginMode3D(camera)
            c3_drawBoard3D()
            c3_drawPieces3D()
            if animActive c3_drawAnimPiece3D() ok
            c3_drawParticles3D()
        EndMode3D()
        c3_drawHUD()
    ok
    EndDrawing()
end
CloseWindow()


// ─── GAME SETUP ───

func c3_startNewGame
    for r = 1 to 8
        for c = 1 to 8
            board[r][c] = [PC_NONE, 0]
        next
    next
    board[1][1] = [PC_ROOK, SD_BLACK]    board[1][2] = [PC_KNIGHT, SD_BLACK]
    board[1][3] = [PC_BISHOP, SD_BLACK]  board[1][4] = [PC_QUEEN, SD_BLACK]
    board[1][5] = [PC_KING, SD_BLACK]    board[1][6] = [PC_BISHOP, SD_BLACK]
    board[1][7] = [PC_KNIGHT, SD_BLACK]  board[1][8] = [PC_ROOK, SD_BLACK]
    for c = 1 to 8 board[2][c] = [PC_PAWN, SD_BLACK] next
    for c = 1 to 8 board[7][c] = [PC_PAWN, SD_WHITE] next
    board[8][1] = [PC_ROOK, SD_WHITE]    board[8][2] = [PC_KNIGHT, SD_WHITE]
    board[8][3] = [PC_BISHOP, SD_WHITE]  board[8][4] = [PC_QUEEN, SD_WHITE]
    board[8][5] = [PC_KING, SD_WHITE]    board[8][6] = [PC_BISHOP, SD_WHITE]
    board[8][7] = [PC_KNIGHT, SD_WHITE]  board[8][8] = [PC_ROOK, SD_WHITE]
    currentTurn = SD_WHITE  hasSelection = false  selRow = 0  selCol = 0
    legalMoves = []
    lastFromR = 0  lastFromC = 0  lastToR = 0  lastToC = 0
    epRow = 0  epCol = 0
    wKingMoved = false  wRookAMoved = false  wRookHMoved = false
    bKingMoved = false  bRookAMoved = false  bRookHMoved = false
    wKingR = 8  wKingC = 5  bKingR = 1  bKingC = 5
    inCheck = false  whiteCaptured = []  blackCaptured = []
    moveHistory = []  undoStack = []  animActive = false
    thinkDots = 0  thinkTimer = 0.0  particles = []
    hoverRow = 0  hoverCol = 0  gameState = ST_PLAYING

func c3_cellToX c return (c - 4.5) * CELL_SZ
func c3_cellToZ r return (r - 4.5) * CELL_SZ

// ─── 3D PROJECTION ───

func c3_projectToScreen wx, wy, wz
    fwdX = camTgtX - camPosX  fwdY = camTgtY - camPosY  fwdZ = camTgtZ - camPosZ
    fLen = sqrt(fwdX*fwdX + fwdY*fwdY + fwdZ*fwdZ)
    if fLen < 0.0001
        projSX = SCREEN_W / 2  projSY = SCREEN_H / 2  return ok
    fwdX = fwdX / fLen  fwdY = fwdY / fLen  fwdZ = fwdZ / fLen
    rightX = -fwdZ  rightY = 0  rightZ = fwdX
    rLen = sqrt(rightX*rightX + rightZ*rightZ)
    if rLen < 0.0001
        projSX = SCREEN_W / 2  projSY = SCREEN_H / 2  return ok
    rightX = rightX / rLen  rightZ = rightZ / rLen
    upX = rightY * fwdZ - rightZ * fwdY
    upY = rightZ * fwdX - rightX * fwdZ
    upZ = rightX * fwdY - rightY * fwdX
    dx = wx - camPosX  dy = wy - camPosY  dz = wz - camPosZ
    dotFwd   = dx * fwdX   + dy * fwdY   + dz * fwdZ
    dotRight = dx * rightX + dy * rightY + dz * rightZ
    dotUp    = dx * upX    + dy * upY    + dz * upZ
    if dotFwd < 0.01  projSX = -9999  projSY = -9999  return ok
    fovRad = 45.0 * 3.14159265 / 180.0
    tanHalf = sin(fovRad / 2.0) / cos(fovRad / 2.0)
    aspect = SCREEN_W * 1.0 / SCREEN_H
    ndcX = (dotRight / dotFwd) / (tanHalf * aspect)
    ndcY = (dotUp / dotFwd) / tanHalf
    projSX = (ndcX * 0.5 + 0.5) * SCREEN_W
    projSY = (1.0 - (ndcY * 0.5 + 0.5)) * SCREEN_H

func c3_updateHover
    hoverRow = 0  hoverCol = 0
    mx = GetMouseX()  my = GetMouseY()
    bestDist = 999999.0  bestR = 0  bestC = 0
    for r = 1 to 8
        for c = 1 to 8
            c3_projectToScreen(c3_cellToX(c), 0.0, c3_cellToZ(r))
            dx = projSX - mx  dy = projSY - my
            dist = dx * dx + dy * dy
            if dist < bestDist  bestDist = dist  bestR = r  bestC = c ok
        next
    next
    if bestDist < 2500  hoverRow = bestR  hoverCol = bestC ok

// ─── PLAYER INPUT ───

func c3_handleInput
    if !IsMouseButtonPressed(MOUSE_LEFT_BUTTON) return ok
    if hoverRow = 0 return ok
    r = hoverRow  c = hoverCol
    if IsKeyPressed(KEY_R) c3_startNewGame() return ok
    if IsKeyPressed(KEY_U) c3_undoMove() return ok

    if hasSelection
        movesLen = len(legalMoves)
        for mi = 1 to movesLen
            if legalMoves[mi][1] = r and legalMoves[mi][2] = c
                c3_executePlayerMove(selRow, selCol, r, c, legalMoves[mi][3])
                hasSelection = false  legalMoves = []  return
            ok
        next
        hasSelection = false  legalMoves = []
    ok
    if board[r][c][1] != PC_NONE and board[r][c][2] = currentTurn
        selRow = r  selCol = c  hasSelection = true
        legalMoves = c3_getLegalMoves(r, c)
    ok

// ─── PLAYER MOVE ───

func c3_executePlayerMove fromR, fromC, toR, toC, special
    c3_pushUndo()
    piece = board[fromR][fromC][1]  side = board[fromR][fromC][2]
    if board[toR][toC][1] != PC_NONE
        c3_spawnCapture(toR, toC, board[toR][toC][2])
        if board[toR][toC][2] = SD_WHITE add(whiteCaptured, board[toR][toC][1])
        else add(blackCaptured, board[toR][toC][1]) ok
    ok
    animFromR = fromR  animFromC = fromC  animToR = toR  animToC = toC
    animPiece = piece  animSide = side  animProgress = 0.0
    animActive = true  gameState = ST_ANIMATE
    if special = 5
        if side = SD_WHITE epCaptR = toR + 1 else epCaptR = toR - 1 ok
        if board[epCaptR][toC][1] != PC_NONE
            c3_spawnCapture(epCaptR, toC, board[epCaptR][toC][2])
            if board[epCaptR][toC][2] = SD_WHITE add(whiteCaptured, board[epCaptR][toC][1])
            else add(blackCaptured, board[epCaptR][toC][1]) ok
        ok
        board[epCaptR][toC] = [PC_NONE, 0]
    ok
    board[toR][toC] = [piece, side]  board[fromR][fromC] = [PC_NONE, 0]
    if piece = PC_PAWN
        if (side = SD_WHITE and toR = 1) or (side = SD_BLACK and toR = 8)
            board[toR][toC] = [PC_QUEEN, side]  animPiece = PC_QUEEN ok ok
    epRow = 0  epCol = 0
    if piece = PC_PAWN
        diff = fromR - toR
        if diff = 2 or diff = -2  epRow = fromR + (toR - fromR) / 2  epCol = fromC ok ok
    if special = 1  board[fromR][6] = [board[fromR][8][1], board[fromR][8][2]]  board[fromR][8] = [PC_NONE, 0] ok
    if special = 2  board[fromR][4] = [board[fromR][1][1], board[fromR][1][2]]  board[fromR][1] = [PC_NONE, 0] ok
    if piece = PC_KING
        if side = SD_WHITE wKingMoved = true wKingR = toR wKingC = toC
        else bKingMoved = true bKingR = toR bKingC = toC ok ok
    if piece = PC_ROOK
        if side = SD_WHITE
            if fromR = 8 and fromC = 1 wRookAMoved = true ok
            if fromR = 8 and fromC = 8 wRookHMoved = true ok
        else
            if fromR = 1 and fromC = 1 bRookAMoved = true ok
            if fromR = 1 and fromC = 8 bRookHMoved = true ok
        ok ok
    lastFromR = fromR  lastFromC = fromC  lastToR = toR  lastToC = toC
    if side = SD_WHITE currentTurn = SD_BLACK else currentTurn = SD_WHITE ok
    if currentTurn = SD_WHITE inCheck = c3_isSquareAttacked(wKingR, wKingC, SD_BLACK)
    else inCheck = c3_isSquareAttacked(bKingR, bKingC, SD_WHITE) ok

func c3_postMoveCheck
    if c3_hasNoLegalMoves(currentTurn)
        if inCheck
            gameState = ST_CHECKMATE
            if currentTurn = SD_WHITE scoreBlack += 1 else scoreWhite += 1 ok
        else gameState = ST_STALEMATE ok
        return
    ok
    if currentTurn = SD_BLACK
        gameState = ST_AI_THINK  thinkDots = 0  thinkTimer = 0
    else gameState = ST_PLAYING ok

// ─── FAST MAKE/UNMAKE (AI search - no allocs for undo stack) ───

func c3_makeMoveFast fromR, fromC, toR, toC, special
    piece = board[fromR][fromC][1]  side = board[fromR][fromC][2]
    captPc = board[toR][toC][1]  captSd = board[toR][toC][2]
    undo = list(20)
    undo[1] = piece  undo[2] = side  undo[3] = captPc  undo[4] = captSd
    undo[5] = epRow  undo[6] = epCol
    if wKingMoved undo[7] = 1 else undo[7] = 0 ok
    if wRookAMoved undo[8] = 1 else undo[8] = 0 ok
    if wRookHMoved undo[9] = 1 else undo[9] = 0 ok
    if bKingMoved undo[10] = 1 else undo[10] = 0 ok
    if bRookAMoved undo[11] = 1 else undo[11] = 0 ok
    if bRookHMoved undo[12] = 1 else undo[12] = 0 ok
    undo[13] = wKingR  undo[14] = wKingC  undo[15] = bKingR  undo[16] = bKingC
    undo[17] = special  undo[18] = 0  undo[19] = 0  undo[20] = 0
    if special = 5
        if side = SD_WHITE epCaptR = toR + 1 else epCaptR = toR - 1 ok
        undo[18] = board[epCaptR][toC][1]  undo[19] = board[epCaptR][toC][2]  undo[20] = epCaptR
        board[epCaptR][toC][1] = PC_NONE  board[epCaptR][toC][2] = 0
    ok
    board[toR][toC][1] = piece  board[toR][toC][2] = side
    board[fromR][fromC][1] = PC_NONE  board[fromR][fromC][2] = 0
    if piece = PC_PAWN
        if (side = SD_WHITE and toR = 1) or (side = SD_BLACK and toR = 8)
            board[toR][toC][1] = PC_QUEEN ok ok
    epRow = 0  epCol = 0
    if piece = PC_PAWN
        diff = fromR - toR
        if diff = 2 or diff = -2  epRow = fromR + (toR - fromR) / 2  epCol = fromC ok ok
    if special = 1
        board[fromR][6][1] = board[fromR][8][1]  board[fromR][6][2] = board[fromR][8][2]
        board[fromR][8][1] = PC_NONE  board[fromR][8][2] = 0 ok
    if special = 2
        board[fromR][4][1] = board[fromR][1][1]  board[fromR][4][2] = board[fromR][1][2]
        board[fromR][1][1] = PC_NONE  board[fromR][1][2] = 0 ok
    if piece = PC_KING
        if side = SD_WHITE wKingMoved = true wKingR = toR wKingC = toC
        else bKingMoved = true bKingR = toR bKingC = toC ok ok
    if piece = PC_ROOK
        if side = SD_WHITE
            if fromR = 8 and fromC = 1 wRookAMoved = true ok
            if fromR = 8 and fromC = 8 wRookHMoved = true ok
        else
            if fromR = 1 and fromC = 1 bRookAMoved = true ok
            if fromR = 1 and fromC = 8 bRookHMoved = true ok
        ok ok
    if side = SD_WHITE currentTurn = SD_BLACK else currentTurn = SD_WHITE ok
    return undo

func c3_unmakeMoveFast fromR, fromC, toR, toC, undo
    board[fromR][fromC][1] = undo[1]  board[fromR][fromC][2] = undo[2]
    board[toR][toC][1] = undo[3]  board[toR][toC][2] = undo[4]
    if undo[17] = 5
        board[undo[20]][toC][1] = undo[18]  board[undo[20]][toC][2] = undo[19] ok
    if undo[17] = 1
        board[fromR][8][1] = board[fromR][6][1]  board[fromR][8][2] = board[fromR][6][2]
        board[fromR][6][1] = PC_NONE  board[fromR][6][2] = 0 ok
    if undo[17] = 2
        board[fromR][1][1] = board[fromR][4][1]  board[fromR][1][2] = board[fromR][4][2]
        board[fromR][4][1] = PC_NONE  board[fromR][4][2] = 0 ok
    epRow = undo[5]  epCol = undo[6]
    wKingMoved = (undo[7] = 1)  wRookAMoved = (undo[8] = 1)  wRookHMoved = (undo[9] = 1)
    bKingMoved = (undo[10] = 1)  bRookAMoved = (undo[11] = 1)  bRookHMoved = (undo[12] = 1)
    wKingR = undo[13]  wKingC = undo[14]  bKingR = undo[15]  bKingC = undo[16]
    currentTurn = undo[2]

// ─── AI ───

func c3_aiMove
    bestScore = -INF_VAL  bestIdx = 0
    allMoves = c3_getAllMovesForSide(SD_BLACK)
    movesLen = len(allMoves)
    if movesLen > 1 c3_orderMoves(allMoves, movesLen) ok
    for mi = 1 to movesLen
        mv = allMoves[mi]
        undo = c3_makeMoveFast(mv[1], mv[2], mv[3], mv[4], mv[5])
        score = c3_alphaBeta(aiDepth - 1, -INF_VAL, INF_VAL, false)
        c3_unmakeMoveFast(mv[1], mv[2], mv[3], mv[4], undo)
        if score > bestScore  bestScore = score  bestIdx = mi ok
    next
    if bestIdx > 0
        mv = allMoves[bestIdx]
        c3_executePlayerMove(mv[1], mv[2], mv[3], mv[4], mv[5])
    else gameState = ST_PLAYING ok

func c3_orderMoves moves, mLen
    writeIdx = 1
    for ri = 1 to mLen
        if board[moves[ri][3]][moves[ri][4]][1] != PC_NONE
            if ri != writeIdx
                tmp = moves[writeIdx]  moves[writeIdx] = moves[ri]  moves[ri] = tmp ok
            writeIdx += 1
        ok
    next

func c3_alphaBeta depth, alpha, beta, isMaximizing
    if depth = 0 return c3_evaluate() ok
    if isMaximizing
        maxEval = -INF_VAL
        allMoves = c3_getAllMovesForSide(SD_BLACK)
        movesLen = len(allMoves)
        if movesLen > 1 c3_orderMoves(allMoves, movesLen) ok
        for mi = 1 to movesLen
            mv = allMoves[mi]
            undo = c3_makeMoveFast(mv[1], mv[2], mv[3], mv[4], mv[5])
            eval = c3_alphaBeta(depth - 1, alpha, beta, false)
            c3_unmakeMoveFast(mv[1], mv[2], mv[3], mv[4], undo)
            if eval > maxEval maxEval = eval ok
            if eval > alpha alpha = eval ok
            if beta <= alpha exit ok
        next
        return maxEval
    else
        minEval = INF_VAL
        allMoves = c3_getAllMovesForSide(SD_WHITE)
        movesLen = len(allMoves)
        if movesLen > 1 c3_orderMoves(allMoves, movesLen) ok
        for mi = 1 to movesLen
            mv = allMoves[mi]
            undo = c3_makeMoveFast(mv[1], mv[2], mv[3], mv[4], mv[5])
            eval = c3_alphaBeta(depth - 1, alpha, beta, true)
            c3_unmakeMoveFast(mv[1], mv[2], mv[3], mv[4], undo)
            if eval < minEval minEval = eval ok
            if eval < beta beta = eval ok
            if beta <= alpha exit ok
        next
        return minEval
    ok

func c3_evaluate
    score = 0
    for r = 1 to 8
        for c = 1 to 8
            pc = board[r][c][1]
            if pc = PC_NONE loop ok
            sd = board[r][c][2]
            val = PIECE_VAL[pc + 1]
            if pc = PC_PAWN
                if sd = SD_WHITE val += (8 - r) * 5
                else val += (r - 1) * 5 ok
            elseif pc = PC_KNIGHT or pc = PC_BISHOP
                cdist = fabs(c - 4.5) + fabs(r - 4.5)
                val += floor((7 - cdist) * 4)
            ok
            if sd = SD_BLACK score += val else score -= val ok
        next
    next
    return score

// ─── UNDO (player moves only) ───

func c3_pushUndo
    s = list(141)
    idx = 1
    for r = 1 to 8
        for c = 1 to 8
            s[idx] = board[r][c][1]  s[idx + 1] = board[r][c][2]  idx += 2
        next
    next
    s[129] = currentTurn  s[130] = epRow  s[131] = epCol
    if wKingMoved s[132] = 1 else s[132] = 0 ok
    if wRookAMoved s[133] = 1 else s[133] = 0 ok
    if wRookHMoved s[134] = 1 else s[134] = 0 ok
    if bKingMoved s[135] = 1 else s[135] = 0 ok
    if bRookAMoved s[136] = 1 else s[136] = 0 ok
    if bRookHMoved s[137] = 1 else s[137] = 0 ok
    s[138] = wKingR  s[139] = wKingC  s[140] = bKingR  s[141] = bKingC
    add(undoStack, s)

func c3_restoreState s
    idx = 1
    for r = 1 to 8
        for c = 1 to 8
            board[r][c][1] = s[idx]  board[r][c][2] = s[idx + 1]  idx += 2
        next
    next
    currentTurn = s[129]  epRow = s[130]  epCol = s[131]
    wKingMoved = (s[132] = 1)  wRookAMoved = (s[133] = 1)  wRookHMoved = (s[134] = 1)
    bKingMoved = (s[135] = 1)  bRookAMoved = (s[136] = 1)  bRookHMoved = (s[137] = 1)
    wKingR = s[138]  wKingC = s[139]  bKingR = s[140]  bKingC = s[141]
    if currentTurn = SD_WHITE inCheck = c3_isSquareAttacked(wKingR, wKingC, SD_BLACK)
    else inCheck = c3_isSquareAttacked(bKingR, bKingC, SD_WHITE) ok

func c3_undoMove
    sLen = len(undoStack)
    if sLen = 0 return ok
    c3_restoreState(undoStack[sLen])  del(undoStack, sLen)
    sLen = len(undoStack)
    if sLen > 0  c3_restoreState(undoStack[sLen])  del(undoStack, sLen) ok
    hasSelection = false  legalMoves = []  animActive = false  gameState = ST_PLAYING

// ─── MOVE GENERATION ───

func c3_getAllMovesForSide side
    moves = []
    for r = 1 to 8
        for c = 1 to 8
            if board[r][c][2] = side
                raw = c3_getRawMoves(r, c)
                rawLen = len(raw)
                for mi = 1 to rawLen
                    tr = raw[mi][1]  tc = raw[mi][2]  sp = raw[mi][3]
                    undo = c3_makeMoveFast(r, c, tr, tc, sp)
                    if side = SD_WHITE
                        legal = !c3_isSquareAttacked(wKingR, wKingC, SD_BLACK)
                    else
                        legal = !c3_isSquareAttacked(bKingR, bKingC, SD_WHITE)
                    ok
                    c3_unmakeMoveFast(r, c, tr, tc, undo)
                    if legal add(moves, [r, c, tr, tc, sp]) ok
                next
            ok
        next
    next
    return moves

func c3_getLegalMoves fromR, fromC
    raw = c3_getRawMoves(fromR, fromC)
    legal = []
    side = board[fromR][fromC][2]
    rawLen = len(raw)
    for mi = 1 to rawLen
        tr = raw[mi][1]  tc = raw[mi][2]  sp = raw[mi][3]
        undo = c3_makeMoveFast(fromR, fromC, tr, tc, sp)
        if side = SD_WHITE isLegal = !c3_isSquareAttacked(wKingR, wKingC, SD_BLACK)
        else isLegal = !c3_isSquareAttacked(bKingR, bKingC, SD_WHITE) ok
        c3_unmakeMoveFast(fromR, fromC, tr, tc, undo)
        if isLegal add(legal, raw[mi]) ok
    next
    return legal

func c3_getRawMoves fromR, fromC
    moves = []
    piece = board[fromR][fromC][1]
    side  = board[fromR][fromC][2]
    if piece = PC_PAWN
        if side = SD_WHITE dir = -1  startRow = 7
        else dir = 1  startRow = 2 ok
        nr = fromR + dir
        if nr >= 1 and nr <= 8
            if board[nr][fromC][1] = PC_NONE
                add(moves, [nr, fromC, 0])
                if fromR = startRow
                    nr2 = fromR + dir * 2
                    if board[nr2][fromC][1] = PC_NONE add(moves, [nr2, fromC, 0]) ok
                ok
            ok
        ok
        for dc = -1 to 1 step 2
            nc = fromC + dc
            if nc >= 1 and nc <= 8 and nr >= 1 and nr <= 8
                if board[nr][nc][1] != PC_NONE and board[nr][nc][2] != side
                    add(moves, [nr, nc, 0]) ok
                if nr = epRow and nc = epCol add(moves, [nr, nc, 5]) ok
            ok
        next
    ok
    if piece = PC_KNIGHT
        for ki = 1 to 8
            nr = fromR + KNIGHT_DR[ki]  nc = fromC + KNIGHT_DC[ki]
            if nr >= 1 and nr <= 8 and nc >= 1 and nc <= 8
                if board[nr][nc][1] = PC_NONE or board[nr][nc][2] != side
                    add(moves, [nr, nc, 0]) ok ok
        next
    ok
    if piece = PC_BISHOP or piece = PC_QUEEN
        for d = 1 to 4
            dr = DIAG_DR[d]  dc = DIAG_DC[d]
            nr = fromR + dr  nc = fromC + dc
            while nr >= 1 and nr <= 8 and nc >= 1 and nc <= 8
                if board[nr][nc][1] = PC_NONE add(moves, [nr, nc, 0])
                else
                    if board[nr][nc][2] != side add(moves, [nr, nc, 0]) ok
                    exit
                ok
                nr += dr  nc += dc
            end
        next
    ok
    if piece = PC_ROOK or piece = PC_QUEEN
        for d = 1 to 4
            dr = STRAIGHT_DR[d]  dc = STRAIGHT_DC[d]
            nr = fromR + dr  nc = fromC + dc
            while nr >= 1 and nr <= 8 and nc >= 1 and nc <= 8
                if board[nr][nc][1] = PC_NONE add(moves, [nr, nc, 0])
                else
                    if board[nr][nc][2] != side add(moves, [nr, nc, 0]) ok
                    exit
                ok
                nr += dr  nc += dc
            end
        next
    ok
    if piece = PC_KING
        for dr = -1 to 1
            for dc = -1 to 1
                if dr = 0 and dc = 0 loop ok
                nr = fromR + dr  nc = fromC + dc
                if nr >= 1 and nr <= 8 and nc >= 1 and nc <= 8
                    if board[nr][nc][1] = PC_NONE or board[nr][nc][2] != side
                        add(moves, [nr, nc, 0]) ok ok
            next
        next
        if side = SD_WHITE and !wKingMoved and !inCheck
            if !wRookHMoved and board[8][8][1] = PC_ROOK and board[8][6][1] = PC_NONE and board[8][7][1] = PC_NONE
                if !c3_isSquareAttacked(8, 6, SD_BLACK) and !c3_isSquareAttacked(8, 7, SD_BLACK)
                    add(moves, [8, 7, 1]) ok ok
            if !wRookAMoved and board[8][1][1] = PC_ROOK and board[8][4][1] = PC_NONE and board[8][3][1] = PC_NONE and board[8][2][1] = PC_NONE
                if !c3_isSquareAttacked(8, 4, SD_BLACK) and !c3_isSquareAttacked(8, 3, SD_BLACK)
                    add(moves, [8, 3, 2]) ok ok
        ok
        if side = SD_BLACK and !bKingMoved and !inCheck
            if !bRookHMoved and board[1][8][1] = PC_ROOK and board[1][6][1] = PC_NONE and board[1][7][1] = PC_NONE
                if !c3_isSquareAttacked(1, 6, SD_WHITE) and !c3_isSquareAttacked(1, 7, SD_WHITE)
                    add(moves, [1, 7, 1]) ok ok
            if !bRookAMoved and board[1][1][1] = PC_ROOK and board[1][4][1] = PC_NONE and board[1][3][1] = PC_NONE and board[1][2][1] = PC_NONE
                if !c3_isSquareAttacked(1, 4, SD_WHITE) and !c3_isSquareAttacked(1, 3, SD_WHITE)
                    add(moves, [1, 3, 2]) ok ok
        ok
    ok
    return moves

// ─── ATTACK DETECTION ───

func c3_isSquareAttacked row, col, byWhichSide
    if byWhichSide = SD_WHITE pr = row + 1 else pr = row - 1 ok
    if pr >= 1 and pr <= 8
        if col > 1
            if board[pr][col-1][1] = PC_PAWN and board[pr][col-1][2] = byWhichSide
                return true ok ok
        if col < 8
            if board[pr][col+1][1] = PC_PAWN and board[pr][col+1][2] = byWhichSide
                return true ok ok
    ok
    for ki = 1 to 8
        nr = row + KNIGHT_DR[ki]  nc = col + KNIGHT_DC[ki]
        if nr >= 1 and nr <= 8 and nc >= 1 and nc <= 8
            if board[nr][nc][1] = PC_KNIGHT and board[nr][nc][2] = byWhichSide
                return true ok ok
    next
    for d = 1 to 4
        dr = STRAIGHT_DR[d]  dc = STRAIGHT_DC[d]
        nr = row + dr  nc = col + dc
        while nr >= 1 and nr <= 8 and nc >= 1 and nc <= 8
            cp = board[nr][nc][1]
            if cp != PC_NONE
                if board[nr][nc][2] = byWhichSide and (cp = PC_ROOK or cp = PC_QUEEN)
                    return true ok
                exit
            ok
            nr += dr  nc += dc
        end
    next
    for d = 1 to 4
        dr = DIAG_DR[d]  dc = DIAG_DC[d]
        nr = row + dr  nc = col + dc
        while nr >= 1 and nr <= 8 and nc >= 1 and nc <= 8
            cp = board[nr][nc][1]
            if cp != PC_NONE
                if board[nr][nc][2] = byWhichSide and (cp = PC_BISHOP or cp = PC_QUEEN)
                    return true ok
                exit
            ok
            nr += dr  nc += dc
        end
    next
    for dr = -1 to 1
        for dc = -1 to 1
            if dr = 0 and dc = 0 loop ok
            nr = row + dr  nc = col + dc
            if nr >= 1 and nr <= 8 and nc >= 1 and nc <= 8
                if board[nr][nc][1] = PC_KING and board[nr][nc][2] = byWhichSide
                    return true ok ok
        next
    next
    return false

func c3_hasNoLegalMoves side
    for r = 1 to 8
        for c = 1 to 8
            if board[r][c][2] = side
                raw = c3_getRawMoves(r, c)
                rawLen = len(raw)
                for mi = 1 to rawLen
                    undo = c3_makeMoveFast(r, c, raw[mi][1], raw[mi][2], raw[mi][3])
                    if side = SD_WHITE
                        legal = !c3_isSquareAttacked(wKingR, wKingC, SD_BLACK)
                    else
                        legal = !c3_isSquareAttacked(bKingR, bKingC, SD_WHITE)
                    ok
                    c3_unmakeMoveFast(r, c, raw[mi][1], raw[mi][2], undo)
                    if legal return false ok
                next
            ok
        next
    next
    return true

// ─── CAMERA ───

func c3_updateCamera
    boardW = BOARD_SZ * CELL_SZ
    goalX = 0  goalY = 0  goalZ = 0  tgtX = 0  tgtY = 0  tgtZ = 0
    if cameraMode = CAM_FRONT
        goalY = (boardW * 1.1 + 3.0) * camZoom  goalZ = (boardW * 1.0 + 3.0) * camZoom
        tgtY = -0.5  tgtZ = -1.0 ok
    if cameraMode = CAM_ISO
        goalX = (boardW * 0.7 + 2.5) * camZoom  goalY = (boardW * 1.0 + 3.0) * camZoom
        goalZ = (boardW * 0.7 + 2.5) * camZoom  tgtY = -0.3 ok
    if cameraMode = CAM_OVERHEAD
        goalY = (boardW * 1.5 + 5.0) * camZoom  goalZ = 0.3 * camZoom ok
    goalX += camOffX  goalZ += camOffZ
    tgtX += camOffX   tgtZ += camOffZ
    lerpSpd = 0.06
    camPosX += (goalX - camPosX) * lerpSpd  camPosY += (goalY - camPosY) * lerpSpd
    camPosZ += (goalZ - camPosZ) * lerpSpd
    camTgtX += (tgtX - camTgtX) * lerpSpd  camTgtY += (tgtY - camTgtY) * lerpSpd
    camTgtZ += (tgtZ - camTgtZ) * lerpSpd
    camera.position.x = camPosX  camera.position.y = camPosY  camera.position.z = camPosZ
    camera.target.x = camTgtX  camera.target.y = camTgtY  camera.target.z = camTgtZ

// ─── PARTICLES ───

func c3_spawnCapture r, c, side
    wx = c3_cellToX(c)  wz = c3_cellToZ(r)
    for pi = 1 to 12
        vx = (fabs(sin(pi * 137.5)) - 0.5) * 3.0
        vy = 1.5 + fabs(cos(pi * 73.1)) * 2.5
        vz = (fabs(cos(pi * 211.3)) - 0.5) * 3.0
        if side = SD_WHITE pr = 220 pg = 220 pb = 240
        else pr = 60 pg = 50 pb = 50 ok
        add(particles, [wx, 0.3, wz, vx, vy, vz, 1.2, pr, pg, pb])
    next

func c3_updateParticles
    idx = 1  pLen = len(particles)
    while idx <= pLen
        p = particles[idx]
        p[1] += p[4] * dt  p[2] += p[5] * dt  p[3] += p[6] * dt
        p[5] -= 6.0 * dt  p[7] -= dt
        particles[idx] = p
        if p[7] <= 0  del(particles, idx)  pLen -= 1
        else idx += 1 ok
    end

func c3_drawParticles3D
    pLen = len(particles)
    for pi = 1 to pLen
        p = particles[pi]
        alpha = floor(p[7] / 1.2 * 200)
        if alpha < 0 alpha = 0 ok
        if alpha > 255 alpha = 255 ok
        sz = 0.06 + p[7] * 0.05
        DrawSphere(Vector3(p[1], p[2], p[3]), sz, RAYLIBColor(p[8], p[9], p[10], alpha))
    next

// ─── 3D BOARD ───

func c3_drawBoard3D
    boardW = BOARD_SZ * CELL_SZ
    slabH = 0.25
    DrawCube(Vector3(0, -slabH/2, 0), boardW + 0.6, slabH, boardW + 0.6, RAYLIBColor(50, 35, 22, 255))
    DrawCubeWires(Vector3(0, -slabH/2, 0), boardW + 0.6, slabH, boardW + 0.6, RAYLIBColor(35, 25, 15, 200))
    bThick = 0.15  bH = 0.15  halfE = boardW / 2 + 0.22
    rimCol = RAYLIBColor(85, 60, 35, 255)
    DrawCube(Vector3(0, bH/2, -halfE), boardW + 0.6, bH, bThick, rimCol)
    DrawCube(Vector3(0, bH/2,  halfE), boardW + 0.6, bH, bThick, rimCol)
    DrawCube(Vector3(-halfE, bH/2, 0), bThick, bH, boardW + 0.6, rimCol)
    DrawCube(Vector3( halfE, bH/2, 0), bThick, bH, boardW + 0.6, rimCol)
    tileH = 0.06
    lmLen = len(legalMoves)
    for r = 1 to 8
        for c = 1 to 8
            wx = c3_cellToX(c)  wz = c3_cellToZ(r)
            tileSz = CELL_SZ * 0.96
            if (r + c) % 2 = 0 tCol = RAYLIBColor(230, 210, 175, 255)
            else tCol = RAYLIBColor(165, 120, 80, 255) ok
            if (r = lastFromR and c = lastFromC) or (r = lastToR and c = lastToC)
                if (r + c) % 2 = 0 tCol = RAYLIBColor(240, 235, 140, 255)
                else tCol = RAYLIBColor(195, 185, 95, 255) ok ok
            if hasSelection and r = selRow and c = selCol
                tCol = RAYLIBColor(245, 245, 100, 255) ok
            isLegal = false
            for lmi = 1 to lmLen
                if legalMoves[lmi][1] = r and legalMoves[lmi][2] = c
                    isLegal = true  exit ok
            next
            if isLegal
                if board[r][c][1] != PC_NONE tCol = RAYLIBColor(220, 80, 60, 180)
                else tCol = RAYLIBColor(100, 180, 80, 200) ok ok
            if inCheck
                if currentTurn = SD_WHITE and r = wKingR and c = wKingC
                    tCol = RAYLIBColor(220, 50, 40, 255) ok
                if currentTurn = SD_BLACK and r = bKingR and c = bKingC
                    tCol = RAYLIBColor(220, 50, 40, 255) ok ok
            if r = hoverRow and c = hoverCol and gameState = ST_PLAYING
                DrawCube(Vector3(wx, tileH/2, wz), tileSz, tileH, tileSz, tCol)
                pulse = 0.85 + sin(animTime * 5) * 0.15
                DrawCube(Vector3(wx, tileH + 0.01, wz), tileSz * pulse, 0.02, tileSz * pulse,
                         RAYLIBColor(255, 255, 255, 40))
            else
                DrawCube(Vector3(wx, tileH/2, wz), tileSz, tileH, tileSz, tCol)
            ok
        next
    next

// ─── 3D PIECES ───

func c3_drawPieces3D
    for r = 1 to 8
        for c = 1 to 8
            pc = board[r][c][1]
            if pc = PC_NONE loop ok
            if animActive and r = animToR and c = animToC loop ok
            c3_drawPieceAt(c3_cellToX(c), 0.06, c3_cellToZ(r), pc, board[r][c][2])
        next
    next

func c3_drawAnimPiece3D
    fx = c3_cellToX(animFromC)  fz = c3_cellToZ(animFromR)
    tx = c3_cellToX(animToC)  tz = c3_cellToZ(animToR)
    t = animProgress  t2 = t * t * (3.0 - 2.0 * t)
    px = fx + (tx - fx) * t2  pz = fz + (tz - fz) * t2
    py = 0.06 + sin(t * 3.14159) * 0.8
    c3_drawPieceAt(px, py, pz, animPiece, animSide)

func c3_drawPieceAt wx, wy, wz, piece, side
    // ── Rich color palettes (matching Knight Tour / N-Queens style) ──
    if side = SD_WHITE
        // Warm ivory / cream with golden accents
        baseCol   = RAYLIBColor(235, 225, 200, 255)
        bodyCol   = RAYLIBColor(245, 238, 218, 255)
        topCol    = RAYLIBColor(255, 248, 230, 255)
        wireCol   = RAYLIBColor(195, 175, 140, 160)
        accentCol = RAYLIBColor(220, 190, 80, 255)
        crownCol  = RAYLIBColor(240, 210, 60, 255)
        jewelCol  = RAYLIBColor(180, 50, 50, 255)
        gemCol    = RAYLIBColor(30, 100, 200, 255)
    else
        // Rich dark ebony with purple-blue accents
        baseCol   = RAYLIBColor(40, 35, 45, 255)
        bodyCol   = RAYLIBColor(50, 45, 55, 255)
        topCol    = RAYLIBColor(65, 58, 68, 255)
        wireCol   = RAYLIBColor(85, 75, 95, 160)
        accentCol = RAYLIBColor(120, 90, 160, 255)
        crownCol  = RAYLIBColor(140, 100, 180, 255)
        jewelCol  = RAYLIBColor(200, 60, 60, 255)
        gemCol    = RAYLIBColor(60, 180, 220, 255)
    ok

    switch piece

    // ═══════════════════════════════════════════
    // PAWN - Smooth soldier with collar and round head
    // ═══════════════════════════════════════════
    on PC_PAWN
        // Wide base
        DrawCylinder(Vector3(wx, wy, wz), 0.34, 0.36, 0.10, 20, baseCol)
        DrawCylinderWires(Vector3(wx, wy, wz), 0.34, 0.36, 0.10, 20, wireCol)
        // Tapered body
        DrawCylinder(Vector3(wx, wy + 0.10, wz), 0.28, 0.16, 0.32, 16, bodyCol)
        DrawCylinderWires(Vector3(wx, wy + 0.10, wz), 0.28, 0.16, 0.32, 16, wireCol)
        // Collar ring
        DrawCylinder(Vector3(wx, wy + 0.42, wz), 0.18, 0.18, 0.04, 16, accentCol)
        // Head sphere
        DrawSphere(Vector3(wx, wy + 0.56, wz), 0.15, topCol)
        // Head ring detail
        DrawCircle3D(Vector3(wx, wy + 0.56, wz), 0.13,
                     Vector3(1, 0, 0), 90.0, wireCol)

    // ═══════════════════════════════════════════
    // ROOK - Castle tower with battlements and arrow slits
    // ═══════════════════════════════════════════
    on PC_ROOK
        // Wide base
        DrawCylinder(Vector3(wx, wy, wz), 0.38, 0.40, 0.10, 20, baseCol)
        DrawCylinderWires(Vector3(wx, wy, wz), 0.38, 0.40, 0.10, 20, wireCol)
        // Tower body
        DrawCylinder(Vector3(wx, wy + 0.10, wz), 0.30, 0.28, 0.42, 20, bodyCol)
        DrawCylinderWires(Vector3(wx, wy + 0.10, wz), 0.30, 0.28, 0.42, 20, wireCol)
        // Battlement platform
        DrawCylinder(Vector3(wx, wy + 0.52, wz), 0.34, 0.34, 0.06, 20, accentCol)
        DrawCylinderWires(Vector3(wx, wy + 0.52, wz), 0.34, 0.34, 0.06, 20, wireCol)
        // Battlements (4 merlons)
        for bi = 0 to 3
            angle = bi * 90.0 * 3.14159 / 180.0
            bx = wx + cos(angle) * 0.22
            bz = wz + sin(angle) * 0.22
            DrawCube(Vector3(bx, wy + 0.68, bz), 0.13, 0.18, 0.13, topCol)
            DrawCubeWires(Vector3(bx, wy + 0.68, bz), 0.13, 0.18, 0.13, wireCol)
        next
        // Arrow slit details on body
        DrawCube(Vector3(wx + 0.29, wy + 0.35, wz), 0.02, 0.14, 0.04, wireCol)
        DrawCube(Vector3(wx - 0.29, wy + 0.35, wz), 0.02, 0.14, 0.04, wireCol)
        DrawCube(Vector3(wx, wy + 0.35, wz + 0.29), 0.04, 0.14, 0.02, wireCol)

    // ═══════════════════════════════════════════
    // KNIGHT - Horse with mane, ears, glowing eyes (Knight Tour style)
    // ═══════════════════════════════════════════
    on PC_KNIGHT
        // Wide base
        DrawCylinder(Vector3(wx, wy, wz), 0.36, 0.38, 0.10, 20, baseCol)
        DrawCylinderWires(Vector3(wx, wy, wz), 0.36, 0.38, 0.10, 20, wireCol)
        // Body (cube-based like Knight Tour)
        DrawCube(Vector3(wx, wy + 0.28, wz), 0.38, 0.28, 0.34, bodyCol)
        DrawCubeWires(Vector3(wx, wy + 0.28, wz), 0.38, 0.28, 0.34, wireCol)
        // Neck
        DrawCube(Vector3(wx, wy + 0.50, wz - 0.02), 0.26, 0.18, 0.24, bodyCol)
        DrawCubeWires(Vector3(wx, wy + 0.50, wz - 0.02), 0.26, 0.18, 0.24, wireCol)
        // Head (angled forward)
        DrawCube(Vector3(wx, wy + 0.64, wz - 0.10), 0.24, 0.22, 0.20, topCol)
        DrawCubeWires(Vector3(wx, wy + 0.64, wz - 0.10), 0.24, 0.22, 0.20, wireCol)
        // Snout
        DrawCube(Vector3(wx, wy + 0.62, wz - 0.24), 0.18, 0.14, 0.12, topCol)
        DrawCubeWires(Vector3(wx, wy + 0.62, wz - 0.24), 0.18, 0.14, 0.12, wireCol)
        // Mane ridge (along back of head+neck)
        DrawCube(Vector3(wx, wy + 0.55, wz + 0.10), 0.06, 0.34, 0.06,
                 accentCol)
        // Ears (pointed cones)
        DrawCylinder(Vector3(wx - 0.07, wy + 0.76, wz - 0.04), 0.04, 0.0, 0.12, 6, topCol)
        DrawCylinder(Vector3(wx + 0.07, wy + 0.76, wz - 0.04), 0.04, 0.0, 0.12, 6, topCol)
        // Eyes (golden glow like Knight Tour)
        DrawSphere(Vector3(wx - 0.09, wy + 0.66, wz - 0.18), 0.035,
                   RAYLIBColor(255, 200, 50, 255))
        DrawSphere(Vector3(wx + 0.09, wy + 0.66, wz - 0.18), 0.035,
                   RAYLIBColor(255, 200, 50, 255))
        // Eye pupils
        DrawSphere(Vector3(wx - 0.09, wy + 0.66, wz - 0.21), 0.018,
                   RAYLIBColor(20, 20, 20, 255))
        DrawSphere(Vector3(wx + 0.09, wy + 0.66, wz - 0.21), 0.018,
                   RAYLIBColor(20, 20, 20, 255))
        // Nostrils
        DrawSphere(Vector3(wx - 0.04, wy + 0.60, wz - 0.30), 0.02, wireCol)
        DrawSphere(Vector3(wx + 0.04, wy + 0.60, wz - 0.30), 0.02, wireCol)

    // ═══════════════════════════════════════════
    // BISHOP - Tall mitre with slit and jewel tip
    // ═══════════════════════════════════════════
    on PC_BISHOP
        // Wide base
        DrawCylinder(Vector3(wx, wy, wz), 0.35, 0.38, 0.10, 20, baseCol)
        DrawCylinderWires(Vector3(wx, wy, wz), 0.35, 0.38, 0.10, 20, wireCol)
        // Tapered body
        DrawCylinder(Vector3(wx, wy + 0.10, wz), 0.28, 0.14, 0.42, 16, bodyCol)
        DrawCylinderWires(Vector3(wx, wy + 0.10, wz), 0.28, 0.14, 0.42, 16, wireCol)
        // Collar ring
        DrawCylinder(Vector3(wx, wy + 0.52, wz), 0.16, 0.16, 0.04, 16, accentCol)
        // Mitre (pointed hat)
        DrawCylinder(Vector3(wx, wy + 0.56, wz), 0.16, 0.03, 0.28, 12, topCol)
        DrawCylinderWires(Vector3(wx, wy + 0.56, wz), 0.16, 0.03, 0.28, 12, wireCol)
        // Diagonal slit on mitre
        DrawCircle3D(Vector3(wx, wy + 0.68, wz), 0.10,
                     Vector3(0.3, 0, 1), 45.0, accentCol)
        // Jewel at tip
        DrawSphere(Vector3(wx, wy + 0.87, wz), 0.055, jewelCol)
        // Jewel glow
        gp = 0.7 + sin(animTime * 4.0) * 0.3
        DrawSphere(Vector3(wx, wy + 0.87, wz), 0.08 * gp,
                   RAYLIBColor(255, 80, 60, 30))

    // ═══════════════════════════════════════════
    // QUEEN - N-Queens style: base→stem→crown→points→jewels
    // ═══════════════════════════════════════════
    on PC_QUEEN
        // Wide base
        DrawCylinder(Vector3(wx, wy, wz), 0.38, 0.40, 0.10, 20, baseCol)
        DrawCylinderWires(Vector3(wx, wy, wz), 0.38, 0.40, 0.10, 20, wireCol)
        // Stem (narrowing body)
        DrawCylinder(Vector3(wx, wy + 0.10, wz), 0.30, 0.18, 0.36, 16, bodyCol)
        DrawCylinderWires(Vector3(wx, wy + 0.10, wz), 0.30, 0.18, 0.36, 16, wireCol)
        // Crown body (widens at top)
        DrawCylinder(Vector3(wx, wy + 0.46, wz), 0.18, 0.26, 0.14, 16, crownCol)
        DrawCylinderWires(Vector3(wx, wy + 0.46, wz), 0.18, 0.26, 0.14, 16, wireCol)
        // Crown points (5 pointed cones around top)
        for ci = 0 to 4
            angle = ci * 72.0 * 3.14159 / 180.0
            cx = wx + cos(angle) * 0.18
            cz = wz + sin(angle) * 0.18
            DrawCylinder(Vector3(cx, wy + 0.60, cz), 0.05, 0.0, 0.16, 6, crownCol)
        next
        // Side jewels on crown body (4 gems)
        for ji = 0 to 3
            angle = (ji * 90.0 + 45.0) * 3.14159 / 180.0
            jx = wx + cos(angle) * 0.24
            jz = wz + sin(angle) * 0.24
            DrawSphere(Vector3(jx, wy + 0.53, jz), 0.04, jewelCol)
        next
        // Central crown jewel
        DrawSphere(Vector3(wx, wy + 0.80, wz), 0.07, jewelCol)
        // Crown jewel glow
        gPulse = 0.7 + sin(animTime * 3.0) * 0.3
        DrawSphere(Vector3(wx, wy + 0.80, wz), 0.11 * gPulse,
                   RAYLIBColor(255, 80, 60, 35))

    // ═══════════════════════════════════════════
    // KING - Tallest piece: ornate base, cross, gem-studded crown
    // ═══════════════════════════════════════════
    on PC_KING
        // Wide base
        DrawCylinder(Vector3(wx, wy, wz), 0.40, 0.42, 0.12, 20, baseCol)
        DrawCylinderWires(Vector3(wx, wy, wz), 0.40, 0.42, 0.12, 20, wireCol)
        // Body stem
        DrawCylinder(Vector3(wx, wy + 0.12, wz), 0.30, 0.20, 0.40, 16, bodyCol)
        DrawCylinderWires(Vector3(wx, wy + 0.12, wz), 0.30, 0.20, 0.40, 16, wireCol)
        // Crown band
        DrawCylinder(Vector3(wx, wy + 0.52, wz), 0.24, 0.24, 0.08, 20, crownCol)
        DrawCylinderWires(Vector3(wx, wy + 0.52, wz), 0.24, 0.24, 0.08, 20, wireCol)
        // Crown arch points (4 arches rising)
        for gi = 0 to 3
            angle = gi * 90.0 * 3.14159 / 180.0
            gx = wx + cos(angle) * 0.16
            gz = wz + sin(angle) * 0.16
            DrawCylinder(Vector3(gx, wy + 0.60, gz), 0.05, 0.03, 0.18, 6, crownCol)
            // Gem at base of each arch
            DrawSphere(Vector3(wx + cos(angle) * 0.22, wy + 0.56, wz + sin(angle) * 0.22),
                       0.04, gemCol)
        next
        // Cross vertical bar
        DrawCube(Vector3(wx, wy + 0.88, wz), 0.05, 0.26, 0.05, accentCol)
        DrawCubeWires(Vector3(wx, wy + 0.88, wz), 0.05, 0.26, 0.05, wireCol)
        // Cross horizontal bar
        DrawCube(Vector3(wx, wy + 0.94, wz), 0.20, 0.05, 0.05, accentCol)
        DrawCubeWires(Vector3(wx, wy + 0.94, wz), 0.20, 0.05, 0.05, wireCol)
        // Central gem at cross intersection
        DrawSphere(Vector3(wx, wy + 0.94, wz), 0.045, jewelCol)
        // Cross top gem
        DrawSphere(Vector3(wx, wy + 1.02, wz), 0.035,
                   RAYLIBColor(220, 180, 30, 255))
        // Crown glow
        gPulse = 0.6 + sin(animTime * 2.5) * 0.4
        DrawSphere(Vector3(wx, wy + 0.94, wz), 0.10 * gPulse,
                   RAYLIBColor(255, 200, 50, 25))
    off

// ─── HUD ───

func c3_drawHUD
    panelX = SCREEN_W - 260
    DrawRectangle(panelX, 0, 260, SCREEN_H, RAYLIBColor(30, 28, 35, 240))
    DrawRectangle(panelX, 0, 2, SCREEN_H, RAYLIBColor(70, 65, 80, 255))
    DrawText("3D CHESS", panelX + 60, 20, 28, RAYLIBColor(255, 215, 0, 255))
    if currentTurn = SD_WHITE
        DrawText("White's Turn", panelX + 65, 65, 20, RAYLIBColor(240, 240, 240, 255))
    else
        DrawText("Black's Turn", panelX + 65, 65, 20, RAYLIBColor(180, 180, 180, 255))
    ok
    if inCheck and (gameState = ST_PLAYING or gameState = ST_AI_THINK)
        pulse = floor(180 + sin(animTime * 6) * 75)
        DrawText("CHECK!", panelX + 85, 90, 20, RAYLIBColor(235, 60, 50, pulse))
    ok
    diffText = "AI: "
    if aiDepth = AI_EASY diffText += "Easy (1)" ok
    if aiDepth = AI_MEDIUM diffText += "Medium (2)" ok
    if aiDepth = AI_HARD diffText += "Hard (3)" ok
    DrawText(diffText, panelX + 25, 125, 16, RAYLIBColor(160, 160, 170, 255))
    camText = "Camera: "
    if cameraMode = CAM_FRONT camText += "Front" ok
    if cameraMode = CAM_ISO camText += "Isometric" ok
    if cameraMode = CAM_OVERHEAD camText += "Overhead" ok
    DrawText(camText + " (C)", panelX + 25, 150, 16, RAYLIBColor(160, 160, 170, 255))
    DrawText("Score", panelX + 95, 185, 18, RAYLIBColor(200, 200, 210, 255))
    DrawText("White: " + scoreWhite, panelX + 40, 210, 16, RAYLIBColor(240, 240, 240, 255))
    DrawText("Black: " + scoreBlack, panelX + 150, 210, 16, RAYLIBColor(180, 180, 180, 255))
    DrawRectangle(panelX + 20, 240, 220, 1, RAYLIBColor(70, 65, 80, 255))
    DrawText("Captured", panelX + 80, 255, 16, RAYLIBColor(180, 180, 190, 255))
    c3_drawCapturedRow(panelX + 25, 280, whiteCaptured, RAYLIBColor(220, 220, 220, 255))
    c3_drawCapturedRow(panelX + 25, 310, blackCaptured, RAYLIBColor(100, 100, 100, 255))
    DrawRectangle(panelX + 20, 345, 220, 1, RAYLIBColor(70, 65, 80, 255))
    DrawText("Controls:", panelX + 25, 360, 16, RAYLIBColor(200, 195, 180, 255))
    DrawText("Click  - Select/Move", panelX + 30, 385, 14, RAYLIBColor(150, 150, 160, 255))
    DrawText("C      - Camera view", panelX + 30, 405, 14, RAYLIBColor(150, 150, 160, 255))
    DrawText("U      - Undo move", panelX + 30, 425, 14, RAYLIBColor(150, 150, 160, 255))
    DrawText("R      - Restart", panelX + 30, 445, 14, RAYLIBColor(150, 150, 160, 255))
    DrawText("1/2/3  - AI level", panelX + 30, 465, 14, RAYLIBColor(150, 150, 160, 255))
    if gameState = ST_AI_THINK
        DrawText("Thinking" + copy(".", thinkDots), panelX + 70, 510, 20, RAYLIBColor(255, 200, 50, 255))
    ok
    if gameState = ST_CHECKMATE
        DrawRectangle(0, 0, SCREEN_W - 260, SCREEN_H, RAYLIBColor(0, 0, 0, 150))
        if currentTurn = SD_WHITE
            DrawText("BLACK WINS!", 200, 300, 50, RAYLIBColor(180, 180, 180, 255))
        else
            DrawText("WHITE WINS!", 200, 300, 50, RAYLIBColor(255, 255, 240, 255))
        ok
        DrawText("CHECKMATE", 235, 360, 30, RAYLIBColor(235, 60, 50, 255))
        DrawText("Press ENTER to continue", 230, 420, 20, RAYLIBColor(200, 200, 200, 200))
    ok
    if gameState = ST_STALEMATE
        DrawRectangle(0, 0, SCREEN_W - 260, SCREEN_H, RAYLIBColor(0, 0, 0, 150))
        DrawText("STALEMATE", 230, 300, 50, RAYLIBColor(200, 200, 100, 255))
        DrawText("DRAW", 330, 360, 30, RAYLIBColor(200, 200, 200, 255))
        DrawText("Press ENTER to continue", 230, 420, 20, RAYLIBColor(200, 200, 200, 200))
    ok
    DrawFPS(10, SCREEN_H - 25)

func c3_drawCapturedRow px, py, captList, col
    capLen = len(captList)
    for ci = 1 to capLen
        x = px + (ci - 1) * 22
        if x > SCREEN_W - 40 exit ok
        DrawText(c3_pieceSymbol(captList[ci]), x, py, 18, col)
    next

func c3_pieceSymbol piece
    switch piece
    on PC_PAWN return "P"  on PC_KNIGHT return "N"  on PC_BISHOP return "B"
    on PC_ROOK return "R"  on PC_QUEEN return "Q"  on PC_KING return "K"
    off
    return "?"

func c3_drawTitle
    DrawText("3D CHESS", 340, 180, 70, RAYLIBColor(255, 215, 0, 255))
    DrawText("Ring + RayLib", 400, 260, 24, RAYLIBColor(180, 175, 165, 255))
    pulse = floor(180 + sin(animTime * 3) * 75)
    DrawText("Click or Press ENTER to Start", 310, 380, 22, RAYLIBColor(240, 240, 240, pulse))
    DrawText("Controls:", 420, 460, 18, RAYLIBColor(170, 170, 180, 255))
    DrawText("Mouse Click - Select & Move pieces", 340, 490, 16, RAYLIBColor(150, 150, 160, 255))
    DrawText("C - Cycle Camera   |   R - Restart", 340, 515, 16, RAYLIBColor(150, 150, 160, 255))
    DrawText("U - Undo Move   |   1/2/3 - AI Level", 330, 540, 16, RAYLIBColor(150, 150, 160, 255))
    DrawText("You play White (front) vs Computer (back)", 305, 590, 16, RAYLIBColor(130, 130, 140, 255))
