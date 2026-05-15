/*
**  3D Othello (Reversi) Game - Using RingRayLib
**  ================================================
**  Place discs to outflank and flip your opponent's pieces!
**  The classic strategy board game rendered in full 3D with
**  smooth flip animations, valid move highlighting, AI,
**  and polished visual effects.
**
**  Controls:
**    Arrow Keys / WASD  - Move cursor on the board
**    ENTER / SPACE      - Place disc at cursor
**    U                  - Undo last move
**    H                  - Toggle valid move hints
**    R                  - Restart game
**    C                  - Cycle camera views
**    1                  - Player vs Player mode
**    2                  - Player vs AI mode
**    ESC                - Exit
**
**  Features:
**    - Full 3D rendered 8x8 board with wooden texture
**    - Smooth disc flip animations (3D rotation)
**    - Valid move highlighting with pulsing indicators
**    - All 8-direction outflanking logic
**    - Auto-pass when a player has no valid moves
**    - Simple AI opponent (greedy: maximizes flips + corners)
**    - Three camera modes: Front-Angle / Isometric / Overhead
**    - Undo system (full board state snapshots)
**    - Particle effects on disc placement and flips
**    - Score tracking with disc counts
**    - Mini-board overlay (HUD)
**    - Title, playing, and game-over screens
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W        = 1024
SCREEN_H        = 768

BOARD_SZ        = 8
CELL_SZ         = 1.5
DISC_RAD        = 0.58
DISC_THICK      = 0.18

// Cell states
CELL_EMPTY      = 0
CELL_BLACK      = 1
CELL_WHITE      = 2

// Game states
ST_START        = 1
ST_PLAYING      = 2
ST_FLIPPING     = 3
ST_GAMEOVER     = 4

// Camera modes
CAM_FRONT       = 1
CAM_ISOMETRIC   = 2
CAM_OVERHEAD    = 3
CAM_COUNT       = 3

// Animation
FLIP_SPEED      = 4.5
PLACE_DROP_SPD  = 10.0

// Game modes
MODE_PVP        = 1
MODE_PVA        = 2

// 8 directions: [dr, dc]
DIR_N  = [-1,  0]    DIR_S  = [ 1,  0]
DIR_E  = [ 0,  1]    DIR_W  = [ 0, -1]
DIR_NE = [-1,  1]    DIR_NW = [-1, -1]
DIR_SE = [ 1,  1]    DIR_SW = [ 1, -1]

DIRECTIONS = [ [-1,0], [1,0], [0,1], [0,-1], [-1,1], [-1,-1], [1,1], [1,-1] ]

// =============================================================
// Global Variables
// =============================================================

board           = []
currentPlayer   = CELL_BLACK     // Black goes first in Othello
cursorR         = 4
cursorC         = 4
gameState       = ST_START
gameMode        = MODE_PVP
animTime        = 0.0
turnCount       = 0
showHints       = true

// Scores
scoreBlack      = 2
scoreWhite      = 2

// Undo stack: each entry is a full board snapshot + player + scores
undoStack       = []

// Flip animation state
flipCells       = []       // List of [r, c] cells being flipped
flipFromPlayer  = 0        // What they were before
flipToPlayer    = 0        // What they become
flipProgress    = 0.0      // 0.0 to 1.0
placeR          = 0        // The placed disc coordinates
placeC          = 0
placeDropY      = 0.0      // Drop animation Y
placeDropDone   = false

// Valid moves cache: list of [r, c]
validMoves      = []

// Last move highlight
lastMoveR       = 0
lastMoveC       = 0

// Particles: [x, y, z, vx, vy, vz, life, r, g, b]
particles       = []

// Camera smoothing
cameraMode      = CAM_FRONT
camPosX = 0.0   camPosY = 14.0  camPosZ = 12.0
camTgtX = 0.0   camTgtY = 0.0   camTgtZ = 0.0

// AI
aiTimer         = 0.0
aiDelay         = 0.5

// Mouse hover (board cell under mouse, 0 = off-board)
mouseHoverR     = 0
mouseHoverC     = 0
projScreenX     = 0.0
projScreenY     = 0.0

// Pass message timer
passMsg         = ""
passMsgTimer    = 0.0

// =============================================================
// Initialize board (statements before functions)
// =============================================================

oth_initBoard()

// =============================================================
// Main Program
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Ring 3D Othello - RingRayLib")
ToggleFullScreen()
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

    // --- Global input ---
    if IsKeyPressed(KEY_C)
        cameraMode += 1
        if cameraMode > CAM_COUNT
            cameraMode = CAM_FRONT
        ok
    ok

    if IsKeyPressed(KEY_R)
        oth_initBoard()
        gameState = ST_PLAYING
    ok

    if IsKeyPressed(KEY_H)
        showHints = !showHints
    ok

    // --- Pass message timer ---
    if passMsgTimer > 0
        passMsgTimer -= dt
        if passMsgTimer < 0 passMsgTimer = 0 ok
    ok

    // --- State-specific updates ---
    if gameState = ST_START
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(0)
            oth_initBoard()
            gameState = ST_PLAYING
        ok
        if IsKeyPressed(KEY_ONE)
            gameMode = MODE_PVP
            oth_initBoard()
            gameState = ST_PLAYING
        ok
        if IsKeyPressed(KEY_TWO)
            gameMode = MODE_PVA
            oth_initBoard()
            gameState = ST_PLAYING
        ok
    ok

    if gameState = ST_PLAYING
        // Always track mouse hover over board
        oth_updateMouseHover()

        if gameMode = MODE_PVA and currentPlayer = CELL_WHITE
            aiTimer += dt
            if aiTimer >= aiDelay
                aiTimer = 0
                oth_aiMove()
            ok
        else
            oth_handleInput()
            oth_handleMouse()
        ok
        c4_updateParticles(dt)
    ok

    if gameState = ST_FLIPPING
        oth_updateFlipAnimation(dt)
        c4_updateParticles(dt)
    ok

    if gameState = ST_GAMEOVER
        c4_updateParticles(dt)
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(0)
            oth_initBoard()
            gameState = ST_PLAYING
        ok
    ok

    oth_positionCamera()

    // --- Drawing ---
    BeginDrawing()
        ClearBackground(RAYLIBColor(12, 16, 22, 255))

        if gameState = ST_START
            oth_drawTitleScreen()
        else
            BeginMode3D(camera)
                oth_drawBoard3D()
                oth_drawDiscs3D()
                oth_drawCursor3D()
                oth_drawValidMoves3D()
                oth_drawParticles3D()
            EndMode3D()

            oth_drawHUD()
            oth_drawMiniBoard()

            // Pass message overlay
            if passMsgTimer > 0
                oth_drawPassMessage()
            ok

            if gameState = ST_GAMEOVER
                oth_drawGameOverOverlay()
            ok
        ok

        DrawFPS(10, 10)
    EndDrawing()

end

CloseWindow()

// =============================================================
// =============================================================
// ALL FUNCTIONS BELOW THIS LINE
// =============================================================
// =============================================================

// =============================================================
// Board Initialization
// =============================================================

func oth_initBoard
    board = list(BOARD_SZ)
    for r = 1 to BOARD_SZ
        board[r] = list(BOARD_SZ)
        for c = 1 to BOARD_SZ
            board[r][c] = CELL_EMPTY
        next
    next

    // Standard Othello opening: 4 pieces in center
    board[4][4] = CELL_WHITE
    board[4][5] = CELL_BLACK
    board[5][4] = CELL_BLACK
    board[5][5] = CELL_WHITE

    currentPlayer = CELL_BLACK
    cursorR       = 4
    cursorC       = 4
    turnCount     = 0
    scoreBlack    = 2
    scoreWhite    = 2
    undoStack     = []
    flipCells     = []
    flipProgress  = 0.0
    particles     = []
    lastMoveR     = 0
    lastMoveC     = 0
    aiTimer       = 0
    passMsg       = ""
    passMsgTimer  = 0.0

    validMoves = oth_getValidMoves(currentPlayer)

// =============================================================
// Input Handling
// =============================================================

func oth_handleInput
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

    if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
        if oth_isValidMove(cursorR, cursorC, currentPlayer)
            oth_makeMove(cursorR, cursorC, currentPlayer)
        ok
    ok

    if IsKeyPressed(KEY_U)
        oth_undo()
    ok

    if IsKeyPressed(KEY_ONE)
        gameMode = MODE_PVP
    ok
    if IsKeyPressed(KEY_TWO)
        gameMode = MODE_PVA
    ok

// =============================================================
// Mouse Handling
// =============================================================

func oth_updateMouseHover
    // Approach: use known camera parameters to do manual 3D-to-2D projection
    // We know the camera position (camPosX/Y/Z) and target (camTgtX/Y/Z)
    // Instead of complex projection math, use a simpler reverse-mapping:
    // Check each cell center vs mouse via GetWorldToScreen
    mx = GetMouseX()
    my = GetMouseY()

    bestDist = 999999.0
    bestR = 0
    bestC = 0

    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            wx = oth_cellToX(c)
            wz = oth_cellToZ(r)
            oth_projectToScreen(wx, 0, wz)
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

    // Only select if mouse is reasonably close to a cell center
    if bestDist < 2500 and bestR >= 1 and bestR <= BOARD_SZ
        mouseHoverR = bestR
        mouseHoverC = bestC
        cursorR = bestR
        cursorC = bestC
    else
        mouseHoverR = 0
        mouseHoverC = 0
    ok

func oth_handleMouse
    if IsMouseButtonPressed(0)    // Left mouse button
        if mouseHoverR >= 1 and mouseHoverR <= BOARD_SZ and
           mouseHoverC >= 1 and mouseHoverC <= BOARD_SZ
            if oth_isValidMove(mouseHoverR, mouseHoverC, currentPlayer)
                oth_makeMove(mouseHoverR, mouseHoverC, currentPlayer)
            ok
        ok
    ok

// =============================================================
// Move Execution
// =============================================================

func oth_makeMove r, c, player
    // Save full board state for undo (copy by value in Ring)
    boardCopy = list(BOARD_SZ)
    for i = 1 to BOARD_SZ
        boardCopy[i] = list(BOARD_SZ)
        for j = 1 to BOARD_SZ
            boardCopy[i][j] = board[i][j]
        next
    next
    add(undoStack, [boardCopy, currentPlayer, scoreBlack, scoreWhite, lastMoveR, lastMoveC])

    // Place the disc
    board[r][c] = player
    lastMoveR = r
    lastMoveC = c
    turnCount += 1

    // Find all cells to flip
    toFlip = oth_getCellsToFlip(r, c, player)

    if len(toFlip) > 0
        // Start flip animation
        flipCells = toFlip
        if player = CELL_BLACK
            flipFromPlayer = CELL_WHITE
            flipToPlayer   = CELL_BLACK
        else
            flipFromPlayer = CELL_BLACK
            flipToPlayer   = CELL_WHITE
        ok
        flipProgress = 0.0
        placeR       = r
        placeC       = c
        placeDropY   = 3.0
        placeDropDone = false
        gameState    = ST_FLIPPING

        // Immediately flip in logical board (animation is visual only)
        for i = 1 to len(toFlip)
            fr = toFlip[i][1]
            fc = toFlip[i][2]
            board[fr][fc] = player
        next
    ok

    // Update scores
    oth_updateScores()

    // Spawn particles at placed disc
    oth_spawnPlaceParticles(r, c, player)

func oth_getCellsToFlip r, c, player
    flipped = []
    if player = CELL_BLACK
        opponent = CELL_WHITE
    else
        opponent = CELL_BLACK
    ok

    for d = 1 to len(DIRECTIONS)
        dr = DIRECTIONS[d][1]
        dc = DIRECTIONS[d][2]
        lineFlip = []
        nr = r + dr
        nc = c + dc

        while nr >= 1 and nr <= BOARD_SZ and nc >= 1 and nc <= BOARD_SZ
            if board[nr][nc] = opponent
                add(lineFlip, [nr, nc])
            but board[nr][nc] = player
                // Found our own piece - all in between are flipped
                for f = 1 to len(lineFlip)
                    add(flipped, [lineFlip[f][1], lineFlip[f][2]])
                next
                exit
            else
                // Empty cell - no flip in this direction
                exit
            ok
            nr += dr
            nc += dc
        end
    next

    return flipped

// =============================================================
// Flip Animation
// =============================================================

func oth_updateFlipAnimation dt
    // First: drop the placed disc
    if !placeDropDone
        placeDropY -= PLACE_DROP_SPD * dt
        if placeDropY <= DISC_THICK / 2
            placeDropY = DISC_THICK / 2
            placeDropDone = true
            // Particles on landing
            oth_spawnPlaceParticles(placeR, placeC, flipToPlayer)
        ok
        return
    ok

    // Then: flip the captured discs
    flipProgress += FLIP_SPEED * dt
    if flipProgress >= 1.0
        flipProgress = 1.0

        // Spawn flip particles
        for i = 1 to len(flipCells)
            fr = flipCells[i][1]
            fc = flipCells[i][2]
            oth_spawnFlipParticles(fr, fc, flipToPlayer)
        next

        // Animation complete - handle turn transition
        flipCells = []
        oth_afterMove()
    ok

func oth_afterMove
    // Determine next player
    if currentPlayer = CELL_BLACK
        nextP = CELL_WHITE
    else
        nextP = CELL_BLACK
    ok

    nextMoves = oth_getValidMoves(nextP)

    if len(nextMoves) > 0
        // Next player can move
        currentPlayer = nextP
        validMoves = nextMoves
        gameState = ST_PLAYING
        return
    ok

    // Next player has no moves - check if current player can still move
    curMoves = oth_getValidMoves(currentPlayer)

    if len(curMoves) > 0
        // Current player goes again (pass opponent)
        validMoves = curMoves

        if nextP = CELL_BLACK
            passMsg = "Black has no moves - pass!"
        else
            passMsg = "White has no moves - pass!"
        ok
        passMsgTimer = 2.0
        gameState = ST_PLAYING
        return
    ok

    // Neither player can move - game over
    gameState = ST_GAMEOVER

// =============================================================
// Valid Move Logic
// =============================================================

func oth_getValidMoves player
    moves = []
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if oth_isValidMove(r, c, player)
                add(moves, [r, c])
            ok
        next
    next
    return moves

func oth_isValidMove r, c, player
    if board[r][c] != CELL_EMPTY return false ok

    if player = CELL_BLACK
        opponent = CELL_WHITE
    else
        opponent = CELL_BLACK
    ok

    for d = 1 to len(DIRECTIONS)
        dr = DIRECTIONS[d][1]
        dc = DIRECTIONS[d][2]
        nr = r + dr
        nc = c + dc
        foundOpp = false

        while nr >= 1 and nr <= BOARD_SZ and nc >= 1 and nc <= BOARD_SZ
            if board[nr][nc] = opponent
                foundOpp = true
            but board[nr][nc] = player
                if foundOpp return true ok
                exit
            else
                exit
            ok
            nr += dr
            nc += dc
        end
    next

    return false

// =============================================================
// Undo System
// =============================================================

func oth_undo
    if len(undoStack) = 0 return ok
    if gameState = ST_FLIPPING return ok

    state = undoStack[len(undoStack)]
    del(undoStack, len(undoStack))

    // Restore the full board (copy by value)
    savedBoard = state[1]
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            board[r][c] = savedBoard[r][c]
        next
    next

    currentPlayer = state[2]
    scoreBlack    = state[3]
    scoreWhite    = state[4]
    lastMoveR     = state[5]
    lastMoveC     = state[6]
    turnCount -= 1
    if turnCount < 0 turnCount = 0 ok
    flipCells  = []
    gameState  = ST_PLAYING
    validMoves = oth_getValidMoves(currentPlayer)

// =============================================================
// Score Update
// =============================================================

func oth_updateScores
    b = 0
    w = 0
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            if board[r][c] = CELL_BLACK b += 1 ok
            if board[r][c] = CELL_WHITE w += 1 ok
        next
    next
    scoreBlack = b
    scoreWhite = w

// =============================================================
// AI (Greedy with corner/edge preference)
// =============================================================

func oth_aiMove
    moves = oth_getValidMoves(CELL_WHITE)
    if len(moves) = 0 return ok

    bestScore = -9999
    bestR = moves[1][1]
    bestC = moves[1][2]

    for i = 1 to len(moves)
        mr = moves[i][1]
        mc = moves[i][2]

        flips = oth_getCellsToFlipSim(mr, mc, CELL_WHITE)
        sc = len(flips)

        // Huge bonus for corners
        if (mr = 1 or mr = BOARD_SZ) and (mc = 1 or mc = BOARD_SZ)
            sc += 50
        // Bonus for edges
        but mr = 1 or mr = BOARD_SZ or mc = 1 or mc = BOARD_SZ
            sc += 5
        ok

        // Penalty for cells adjacent to corners (gives opponent corner)
        if (mr = 1 or mr = 2) and (mc = 1 or mc = 2)
            if !((mr = 1) and (mc = 1))
                if board[1][1] = CELL_EMPTY
                    sc -= 15
                ok
            ok
        ok
        if (mr = 1 or mr = 2) and (mc = 7 or mc = 8)
            if !((mr = 1) and (mc = 8))
                if board[1][8] = CELL_EMPTY
                    sc -= 15
                ok
            ok
        ok
        if (mr = 7 or mr = 8) and (mc = 1 or mc = 2)
            if !((mr = 8) and (mc = 1))
                if board[8][1] = CELL_EMPTY
                    sc -= 15
                ok
            ok
        ok
        if (mr = 7 or mr = 8) and (mc = 7 or mc = 8)
            if !((mr = 8) and (mc = 8))
                if board[8][8] = CELL_EMPTY
                    sc -= 15
                ok
            ok
        ok

        if sc > bestScore
            bestScore = sc
            bestR = mr
            bestC = mc
        ok
    next

    oth_makeMove(bestR, bestC, CELL_WHITE)

func oth_getCellsToFlipSim r, c, player
    // Same as oth_getCellsToFlip but for simulation (board unmodified)
    flipped = []
    if player = CELL_BLACK
        opponent = CELL_WHITE
    else
        opponent = CELL_BLACK
    ok

    for d = 1 to len(DIRECTIONS)
        dr = DIRECTIONS[d][1]
        dc = DIRECTIONS[d][2]
        lineFlip = []
        nr = r + dr
        nc = c + dc

        while nr >= 1 and nr <= BOARD_SZ and nc >= 1 and nc <= BOARD_SZ
            if board[nr][nc] = opponent
                add(lineFlip, [nr, nc])
            but board[nr][nc] = player
                for f = 1 to len(lineFlip)
                    add(flipped, [lineFlip[f][1], lineFlip[f][2]])
                next
                exit
            else
                exit
            ok
            nr += dr
            nc += dc
        end
    next
    return flipped

// =============================================================
// Coordinate Helpers
// =============================================================

func oth_cellToX c
    return (c - 1) * CELL_SZ - (BOARD_SZ - 1) * CELL_SZ / 2

func oth_cellToZ r
    return (r - 1) * CELL_SZ - (BOARD_SZ - 1) * CELL_SZ / 2

// =============================================================
// Manual 3D to Screen Projection (no struct access needed)
// =============================================================

func oth_projectToScreen wx, wy, wz
    // Manual perspective projection using tracked camera values
    // Build view direction
    fwdX = camTgtX - camPosX
    fwdY = camTgtY - camPosY
    fwdZ = camTgtZ - camPosZ
    // Normalize forward
    fLen = sqrt(fwdX*fwdX + fwdY*fwdY + fwdZ*fwdZ)
    if fLen < 0.0001
        projScreenX = SCREEN_W / 2
        projScreenY = SCREEN_H / 2
        return
    ok
    fwdX = fwdX / fLen
    fwdY = fwdY / fLen
    fwdZ = fwdZ / fLen

    // Up vector (world up = 0,1,0)
    // Right = forward x up
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

    // True up = right x forward
    upX = rightY * fwdZ - rightZ * fwdY
    upY = rightZ * fwdX - rightX * fwdZ
    upZ = rightX * fwdY - rightY * fwdX

    // Vector from camera to point
    dx = wx - camPosX
    dy = wy - camPosY
    dz = wz - camPosZ

    // Project onto camera axes
    dotFwd   = dx * fwdX   + dy * fwdY   + dz * fwdZ
    dotRight = dx * rightX + dy * rightY + dz * rightZ
    dotUp    = dx * upX    + dy * upY    + dz * upZ

    if dotFwd < 0.01
        projScreenX = -9999
        projScreenY = -9999
        return
    ok

    // Perspective divide
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

func oth_spawnPlaceParticles r, c, player
    wx = oth_cellToX(c)
    wz = oth_cellToZ(r)
    if player = CELL_BLACK
        pr = 40  pg = 40  pb = 40
    else
        pr = 240  pg = 240  pb = 240
    ok
    for i = 1 to 10
        vx = (GetRandomValue(-100, 100) / 100.0) * 1.5
        vy = (GetRandomValue(100, 300) / 100.0) * 1.2
        vz = (GetRandomValue(-100, 100) / 100.0) * 1.5
        cr = pr + GetRandomValue(-25, 25)
        cg = pg + GetRandomValue(-25, 25)
        cb = pb + GetRandomValue(-25, 25)
        if cr < 0 cr = 0 ok    if cr > 255 cr = 255 ok
        if cg < 0 cg = 0 ok    if cg > 255 cg = 255 ok
        if cb < 0 cb = 0 ok    if cb > 255 cb = 255 ok
        add(particles, [wx, 0.3, wz, vx, vy, vz, 1.2, cr, cg, cb])
    next

func oth_spawnFlipParticles r, c, player
    wx = oth_cellToX(c)
    wz = oth_cellToZ(r)
    if player = CELL_BLACK
        pr = 80  pg = 220  pb = 80
    else
        pr = 255  pg = 200  pb = 80
    ok
    for i = 1 to 6
        vx = (GetRandomValue(-100, 100) / 100.0) * 1.0
        vy = (GetRandomValue(100, 250) / 100.0) * 1.0
        vz = (GetRandomValue(-100, 100) / 100.0) * 1.0
        cr = pr + GetRandomValue(-20, 20)
        cg = pg + GetRandomValue(-20, 20)
        cb = pb + GetRandomValue(-20, 20)
        if cr < 0 cr = 0 ok    if cr > 255 cr = 255 ok
        if cg < 0 cg = 0 ok    if cg > 255 cg = 255 ok
        if cb < 0 cb = 0 ok    if cb > 255 cb = 255 ok
        add(particles, [wx, 0.4, wz, vx, vy, vz, 1.0, cr, cg, cb])
    next

func c4_updateParticles dt
    i = 1
    while i <= len(particles)
        particles[i][1] += particles[i][4] * dt
        particles[i][2] += particles[i][5] * dt
        particles[i][3] += particles[i][6] * dt
        particles[i][5] -= 5.0 * dt
        particles[i][7] -= dt
        if particles[i][7] <= 0
            del(particles, i)
        else
            i += 1
        ok
    end

func oth_drawParticles3D
    for i = 1 to len(particles)
        p = particles[i]
        alpha = floor((p[7] / 1.2) * 255)
        if alpha > 255 alpha = 255 ok
        if alpha < 0 alpha = 0 ok
        sz = 0.04 + p[7] * 0.07
        DrawSphereEx(
            Vector3(p[1], p[2], p[3]),
            sz, 4, 4,
            RAYLIBColor(p[8], p[9], p[10], alpha)
        )
    next

// =============================================================
// Camera
// =============================================================

func oth_positionCamera
    boardW = BOARD_SZ * CELL_SZ
    goalX = 0  goalY = 0  goalZ = 0
    tgtX = 0   tgtY = 0   tgtZ = 0
    lerpSpd = 0.06

    if cameraMode = CAM_FRONT
        goalX = 0
        goalY = 10.0
        goalZ = 12.0
        tgtX = 0
        tgtY = 0.2
        tgtZ = -1.0
        lerpSpd = 0.07
    ok

    if cameraMode = CAM_ISOMETRIC
        goalX = boardW * 0.65
        goalY = 10.0
        goalZ = boardW * 0.65
        tgtX = 0
        tgtY = 0
        tgtZ = 0
        lerpSpd = 0.06
    ok

    if cameraMode = CAM_OVERHEAD
        goalX = 0
        goalY = boardW + 5.0
        goalZ = 0.1
        tgtX = 0
        tgtY = 0
        tgtZ = 0
        lerpSpd = 0.06
    ok

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

func oth_drawBoard3D
    boardW = BOARD_SZ * CELL_SZ
    halfBoard = (BOARD_SZ - 1) * CELL_SZ / 2

    // Main board surface (green felt)
    DrawCube(
        Vector3(0, -0.15, 0),
        boardW + 0.4, 0.3, boardW + 0.4,
        RAYLIBColor(20, 100, 45, 255)
    )

    // Wooden border frame
    borderThick = 0.4
    borderH     = 0.35
    bHalf       = boardW / 2 + borderThick / 2 + 0.2

    // North border
    DrawCube(Vector3(0, borderH/2 - 0.05, -bHalf), boardW + borderThick * 2 + 0.4, borderH, borderThick,
             RAYLIBColor(100, 60, 30, 255))
    DrawCubeWires(Vector3(0, borderH/2 - 0.05, -bHalf), boardW + borderThick * 2 + 0.4, borderH, borderThick,
                  RAYLIBColor(130, 80, 40, 200))
    // South border
    DrawCube(Vector3(0, borderH/2 - 0.05, bHalf), boardW + borderThick * 2 + 0.4, borderH, borderThick,
             RAYLIBColor(100, 60, 30, 255))
    DrawCubeWires(Vector3(0, borderH/2 - 0.05, bHalf), boardW + borderThick * 2 + 0.4, borderH, borderThick,
                  RAYLIBColor(130, 80, 40, 200))
    // West border
    DrawCube(Vector3(-bHalf, borderH/2 - 0.05, 0), borderThick, borderH, boardW + 0.4,
             RAYLIBColor(90, 55, 28, 255))
    DrawCubeWires(Vector3(-bHalf, borderH/2 - 0.05, 0), borderThick, borderH, boardW + 0.4,
                  RAYLIBColor(120, 75, 38, 200))
    // East border
    DrawCube(Vector3(bHalf, borderH/2 - 0.05, 0), borderThick, borderH, boardW + 0.4,
             RAYLIBColor(90, 55, 28, 255))
    DrawCubeWires(Vector3(bHalf, borderH/2 - 0.05, 0), borderThick, borderH, boardW + 0.4,
                  RAYLIBColor(120, 75, 38, 200))

    // Grid lines
    for i = 0 to BOARD_SZ
        linePos = i * CELL_SZ - halfBoard - CELL_SZ / 2
        DrawLine3D(
            Vector3(-halfBoard - CELL_SZ/2, 0.01, linePos),
            Vector3( halfBoard + CELL_SZ/2, 0.01, linePos),
            RAYLIBColor(10, 70, 30, 220)
        )
        DrawLine3D(
            Vector3(linePos, 0.01, -halfBoard - CELL_SZ/2),
            Vector3(linePos, 0.01,  halfBoard + CELL_SZ/2),
            RAYLIBColor(10, 70, 30, 220)
        )
    next

    // Cell squares (checkerboard subtle pattern)
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            wx = oth_cellToX(c)
            wz = oth_cellToZ(r)
            if (r + c) % 2 = 0
                tileCol = RAYLIBColor(22, 110, 50, 255)
            else
                tileCol = RAYLIBColor(18, 95, 42, 255)
            ok
            DrawCube(
                Vector3(wx, -0.01, wz),
                CELL_SZ - 0.04, 0.02, CELL_SZ - 0.04,
                tileCol
            )
        next
    next

    // Corner dots (traditional Othello board has 4 guide dots)
    dotY = 0.02
    dotRad = 0.06
    dotCol = RAYLIBColor(10, 60, 25, 255)
    // Dots between cells (2,2), (2,6), (6,2), (6,6)
    DrawSphere(Vector3(oth_cellToX(3) - CELL_SZ/2, dotY, oth_cellToZ(3) - CELL_SZ/2), dotRad, dotCol)
    DrawSphere(Vector3(oth_cellToX(7) - CELL_SZ/2, dotY, oth_cellToZ(3) - CELL_SZ/2), dotRad, dotCol)
    DrawSphere(Vector3(oth_cellToX(3) - CELL_SZ/2, dotY, oth_cellToZ(7) - CELL_SZ/2), dotRad, dotCol)
    DrawSphere(Vector3(oth_cellToX(7) - CELL_SZ/2, dotY, oth_cellToZ(7) - CELL_SZ/2), dotRad, dotCol)

    // Floor beneath board
    DrawPlane(
        Vector3(0, -0.35, 0),
        Vector2(30, 30),
        RAYLIBColor(15, 18, 28, 255)
    )

    // Subtle floor grid
    for i = -15 to 15
        gridCol = RAYLIBColor(25, 30, 42, 80)
        fi = i * 1.0
        DrawLine3D(Vector3(-15, -0.34, fi), Vector3(15, -0.34, fi), gridCol)
        DrawLine3D(Vector3(fi, -0.34, -15), Vector3(fi, -0.34, 15), gridCol)
    next

// =============================================================
// 3D Drawing: Discs
// =============================================================

func oth_drawDiscs3D
    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            player = board[r][c]
            if player = CELL_EMPTY loop ok

            wx = oth_cellToX(c)
            wz = oth_cellToZ(r)

            // Check if this disc is the one being placed (dropping)
            if gameState = ST_FLIPPING and r = placeR and c = placeC and !placeDropDone
                oth_drawDisc3D(wx, placeDropY, wz, player, false, 0.0)
                loop
            ok

            // Check if this disc is being flipped
            isFlipping = false
            if gameState = ST_FLIPPING and placeDropDone
                for f = 1 to len(flipCells)
                    if flipCells[f][1] = r and flipCells[f][2] = c
                        isFlipping = true
                    ok
                next
            ok

            if isFlipping
                oth_drawFlippingDisc(wx, wz, flipFromPlayer, flipToPlayer, flipProgress)
            else
                // Highlight last move
                isLast = false
                if r = lastMoveR and c = lastMoveC
                    isLast = true
                ok
                oth_drawDisc3D(wx, DISC_THICK / 2, wz, player, isLast, 0.0)
            ok
        next
    next

func oth_drawDisc3D wx, wy, wz, player, isHighlighted, extraAngle
    if player = CELL_BLACK
        topCol    = RAYLIBColor(30, 30, 35, 255)
        sideCol   = RAYLIBColor(20, 20, 25, 255)
        wireCol   = RAYLIBColor(55, 55, 65, 200)
        ringCol   = RAYLIBColor(50, 50, 60, 255)
    else
        topCol    = RAYLIBColor(235, 235, 230, 255)
        sideCol   = RAYLIBColor(220, 220, 215, 255)
        wireCol   = RAYLIBColor(200, 200, 195, 200)
        ringCol   = RAYLIBColor(210, 210, 205, 255)
    ok

    // Main disc cylinder
    DrawCylinder(
        Vector3(wx, wy - DISC_THICK/2, wz),
        DISC_RAD, DISC_RAD, DISC_THICK, 24,
        sideCol
    )
    DrawCylinderWires(
        Vector3(wx, wy - DISC_THICK/2, wz),
        DISC_RAD, DISC_RAD, DISC_THICK, 24,
        wireCol
    )

    // Top face circle
    DrawCircle3D(
        Vector3(wx, wy + DISC_THICK/2 + 0.005, wz),
        DISC_RAD * 0.7,
        Vector3(1, 0, 0), 90.0,
        ringCol
    )

    // Shine highlight
    DrawSphere(
        Vector3(wx + 0.15, wy + DISC_THICK/2 + 0.02, wz - 0.1),
        0.05,
        RAYLIBColor(255, 255, 255, 80)
    )

    // Shadow on board
    DrawCircle3D(
        Vector3(wx, 0.015, wz),
        DISC_RAD + 0.05,
        Vector3(1, 0, 0), 90.0,
        RAYLIBColor(0, 0, 0, 40)
    )

    // Last move glow ring
    if isHighlighted
        pulse = 0.8 + sin(animTime * 4.0) * 0.2
        DrawCircle3D(
            Vector3(wx, wy + DISC_THICK/2 + 0.01, wz),
            DISC_RAD * 1.1 * pulse,
            Vector3(1, 0, 0), 90.0,
            RAYLIBColor(255, 220, 50, 180)
        )
    ok

func oth_drawFlippingDisc wx, wz, fromPlayer, toPlayer, progress
    // Flip animation: disc rotates 180 degrees around X axis
    // First half (0-0.5): shows fromPlayer side, shrinks to edge
    // Second half (0.5-1): shows toPlayer side, expands from edge
    wy = DISC_THICK / 2

    if progress < 0.5
        // First half: showing old color, "closing"
        showPlayer = fromPlayer
        // Scale Y from 1 down to 0
        scaleY = 1.0 - progress * 2.0
        if scaleY < 0.02 scaleY = 0.02 ok
        // Rise slightly at midpoint
        wy += sin(progress * 3.14159) * 0.5
    else
        // Second half: showing new color, "opening"
        showPlayer = toPlayer
        scaleY = (progress - 0.5) * 2.0
        if scaleY < 0.02 scaleY = 0.02 ok
        wy += sin(progress * 3.14159) * 0.5
    ok

    if showPlayer = CELL_BLACK
        sideCol   = RAYLIBColor(30, 30, 35, 255)
        wireCol   = RAYLIBColor(55, 55, 65, 200)
    else
        sideCol   = RAYLIBColor(235, 235, 230, 255)
        wireCol   = RAYLIBColor(200, 200, 195, 200)
    ok

    drawThick = DISC_THICK * scaleY
    if drawThick < 0.01 drawThick = 0.01 ok

    DrawCylinder(
        Vector3(wx, wy - drawThick/2, wz),
        DISC_RAD, DISC_RAD, drawThick, 20,
        sideCol
    )
    DrawCylinderWires(
        Vector3(wx, wy - drawThick/2, wz),
        DISC_RAD, DISC_RAD, drawThick, 20,
        wireCol
    )

    // Glow during flip
    glowAlpha = floor(sin(progress * 3.14159) * 60)
    if glowAlpha < 0 glowAlpha = 0 ok
    DrawSphereEx(
        Vector3(wx, wy, wz),
        DISC_RAD * 0.9, 8, 8,
        RAYLIBColor(255, 255, 200, glowAlpha)
    )

// =============================================================
// 3D Drawing: Cursor
// =============================================================

func oth_drawCursor3D
    if gameState != ST_PLAYING return ok
    if gameMode = MODE_PVA and currentPlayer = CELL_WHITE return ok

    wx = oth_cellToX(cursorC)
    wz = oth_cellToZ(cursorR)
    cy = 0.03

    // Determine if valid
    isValid = oth_isValidMove(cursorR, cursorC, currentPlayer)

    if isValid
        pulse = 0.85 + sin(animTime * 5.0) * 0.15
        if currentPlayer = CELL_BLACK
            curCol = RAYLIBColor(80, 255, 120, 160)
        else
            curCol = RAYLIBColor(80, 255, 120, 160)
        ok
    else
        pulse = 1.0
        curCol = RAYLIBColor(255, 80, 80, 120)
    ok

    // Cursor ring
    DrawCircle3D(
        Vector3(wx, cy, wz),
        DISC_RAD * pulse,
        Vector3(1, 0, 0), 90.0,
        curCol
    )
    // Inner ring
    DrawCircle3D(
        Vector3(wx, cy + 0.005, wz),
        DISC_RAD * 0.5 * pulse,
        Vector3(1, 0, 0), 90.0,
        curCol
    )

    // If valid, show ghost disc preview
    if isValid and board[cursorR][cursorC] = CELL_EMPTY
        if currentPlayer = CELL_BLACK
            ghostCol = RAYLIBColor(40, 40, 45, 80)
        else
            ghostCol = RAYLIBColor(220, 220, 215, 80)
        ok
        hoverY = 0.4 + sin(animTime * 3.0) * 0.1
        DrawCylinder(
            Vector3(wx, hoverY, wz),
            DISC_RAD * 0.85, DISC_RAD * 0.85, DISC_THICK * 0.8, 16,
            ghostCol
        )
    ok

    // Corner brackets for cursor highlight
    hs = CELL_SZ * 0.48
    bracketLen = 0.25
    bCol = RAYLIBColor(255, 255, 200, 180)
    by = 0.04

    // Top-left
    DrawLine3D(Vector3(wx - hs, by, wz - hs), Vector3(wx - hs + bracketLen, by, wz - hs), bCol)
    DrawLine3D(Vector3(wx - hs, by, wz - hs), Vector3(wx - hs, by, wz - hs + bracketLen), bCol)
    // Top-right
    DrawLine3D(Vector3(wx + hs, by, wz - hs), Vector3(wx + hs - bracketLen, by, wz - hs), bCol)
    DrawLine3D(Vector3(wx + hs, by, wz - hs), Vector3(wx + hs, by, wz - hs + bracketLen), bCol)
    // Bottom-left
    DrawLine3D(Vector3(wx - hs, by, wz + hs), Vector3(wx - hs + bracketLen, by, wz + hs), bCol)
    DrawLine3D(Vector3(wx - hs, by, wz + hs), Vector3(wx - hs, by, wz + hs - bracketLen), bCol)
    // Bottom-right
    DrawLine3D(Vector3(wx + hs, by, wz + hs), Vector3(wx + hs - bracketLen, by, wz + hs), bCol)
    DrawLine3D(Vector3(wx + hs, by, wz + hs), Vector3(wx + hs, by, wz + hs - bracketLen), bCol)

// =============================================================
// 3D Drawing: Valid Move Hints
// =============================================================

func oth_drawValidMoves3D
    if gameState != ST_PLAYING return ok
    if !showHints return ok
    if gameMode = MODE_PVA and currentPlayer = CELL_WHITE return ok

    for i = 1 to len(validMoves)
        vr = validMoves[i][1]
        vc = validMoves[i][2]

        // Don't double-draw at cursor
        if vr = cursorR and vc = cursorC loop ok

        wx = oth_cellToX(vc)
        wz = oth_cellToZ(vr)
        hy = 0.025

        pulse = 0.5 + sin(animTime * 3.0 + i * 0.8) * 0.2

        DrawCircle3D(
            Vector3(wx, hy, wz),
            DISC_RAD * 0.4 * pulse,
            Vector3(1, 0, 0), 90.0,
            RAYLIBColor(120, 255, 150, 100)
        )
        // Tiny dot
        DrawSphere(
            Vector3(wx, hy + 0.02, wz),
            0.04,
            RAYLIBColor(120, 255, 150, 130)
        )
    next

// =============================================================
// HUD
// =============================================================

func oth_drawHUD
    panelW = 255
    panelH = 155
    DrawRectangle(10, 30, panelW, panelH, Fade(BLACK, 0.75))
    DrawRectangleLines(10, 30, panelW, panelH, RAYLIBColor(50, 160, 80, 200))

    DrawText("3D OTHELLO", 20, 38, 20, RAYLIBColor(50, 200, 80, 255))

    // Score display with disc indicators
    DrawCircle(35, 69, 8, RAYLIBColor(30, 30, 35, 255))
    DrawCircleLines(35, 69, 8, RAYLIBColor(60, 60, 70, 255))
    DrawText("Black: " + scoreBlack, 50, 62, 16, RAYLIBColor(200, 200, 210, 255))

    DrawCircle(155, 69, 8, RAYLIBColor(235, 235, 230, 255))
    DrawCircleLines(155, 69, 8, RAYLIBColor(200, 200, 195, 255))
    DrawText("White: " + scoreWhite, 170, 62, 16, RAYLIBColor(200, 200, 210, 255))

    // Current player indicator
    if gameState = ST_PLAYING or gameState = ST_FLIPPING
        if currentPlayer = CELL_BLACK
            pName = "BLACK"
            pCol = RAYLIBColor(180, 180, 190, 255)
        else
            pName = "WHITE"
            pCol = RAYLIBColor(240, 240, 235, 255)
        ok
        if gameMode = MODE_PVA and currentPlayer = CELL_WHITE
            pName = "AI (WHITE)"
        ok
        DrawText("Turn: " + pName, 20, 88, 16, pCol)
    ok

    DrawText("Moves: " + turnCount, 20, 110, 14, RAYLIBColor(160, 180, 200, 200))

    modeName = "Player vs Player"
    if gameMode = MODE_PVA modeName = "Player vs AI" ok
    DrawText("Mode: " + modeName, 20, 128, 14, RAYLIBColor(140, 165, 190, 200))

    hintStatus = "ON"
    if !showHints hintStatus = "OFF" ok
    DrawText("Hints: " + hintStatus + "  [H]", 20, 146, 14, RAYLIBColor(120, 200, 140, 200))

    DrawText("Valid: " + len(validMoves), 20, 164, 14, RAYLIBColor(120, 180, 140, 180))

    // Camera mode
    camName = "FRONT"
    if cameraMode = CAM_ISOMETRIC camName = "ISOMETRIC" ok
    if cameraMode = CAM_OVERHEAD  camName = "OVERHEAD"  ok
    DrawRectangle(10, SCREEN_H - 60, 210, 25, Fade(BLACK, 0.6))
    DrawText("Cam: " + camName + "  [C] switch", 16, SCREEN_H - 56, 14,
             RAYLIBColor(150, 180, 210, 220))

    // Controls
    DrawRectangle(SCREEN_W - 440, SCREEN_H - 35, 430, 25, Fade(BLACK, 0.6))
    DrawText("Mouse/WASD/Arrows | Click/Space: Place | U: Undo | H: Hints | R: Reset",
             SCREEN_W - 435, SCREEN_H - 30, 12, RAYLIBColor(150, 160, 180, 200))

// =============================================================
// Mini Board (2D overlay)
// =============================================================

func oth_drawMiniBoard
    cellW = 16
    cellH = 16
    mapW = BOARD_SZ * cellW
    mapH = BOARD_SZ * cellH
    mapX = SCREEN_W - mapW - 20
    mapY = 30

    DrawRectangle(mapX - 3, mapY - 3, mapW + 6, mapH + 6, Fade(BLACK, 0.8))
    DrawRectangleLines(mapX - 3, mapY - 3, mapW + 6, mapH + 6,
                       RAYLIBColor(50, 160, 80, 200))

    for r = 1 to BOARD_SZ
        for c = 1 to BOARD_SZ
            sx = mapX + (c - 1) * cellW
            sy = mapY + (r - 1) * cellH

            if (r + c) % 2 = 0
                bg = RAYLIBColor(20, 80, 40, 220)
            else
                bg = RAYLIBColor(16, 70, 35, 220)
            ok
            DrawRectangle(sx, sy, cellW, cellH, bg)
            DrawRectangleLines(sx, sy, cellW, cellH, RAYLIBColor(15, 60, 28, 180))

            if board[r][c] = CELL_BLACK
                DrawCircle(sx + cellW/2, sy + cellH/2, 6, RAYLIBColor(30, 30, 35, 255))
                DrawCircleLines(sx + cellW/2, sy + cellH/2, 6, RAYLIBColor(60, 60, 70, 200))
            ok
            if board[r][c] = CELL_WHITE
                DrawCircle(sx + cellW/2, sy + cellH/2, 6, RAYLIBColor(235, 235, 230, 255))
                DrawCircleLines(sx + cellW/2, sy + cellH/2, 6, RAYLIBColor(200, 200, 195, 200))
            ok
        next
    next

    // Cursor indicator on minimap
    cx = mapX + (cursorC - 1) * cellW
    cy = mapY + (cursorR - 1) * cellH
    DrawRectangleLines(cx, cy, cellW, cellH, RAYLIBColor(255, 255, 100, 220))

    // Last move on minimap
    if lastMoveR > 0 and lastMoveC > 0
        lx = mapX + (lastMoveC - 1) * cellW
        ly = mapY + (lastMoveR - 1) * cellH
        DrawRectangleLines(lx + 1, ly + 1, cellW - 2, cellH - 2, RAYLIBColor(255, 150, 50, 200))
    ok

    DrawText("BOARD", mapX + mapW/2 - 22, mapY - 16, 12,
             RAYLIBColor(120, 200, 150, 200))

// =============================================================
// Title Screen
// =============================================================

func oth_drawTitleScreen
    DrawRectangleGradientV(0, 0, SCREEN_W, SCREEN_H,
        RAYLIBColor(8, 18, 12, 255), RAYLIBColor(12, 25, 18, 255))

    // Title
    t1 = "3D OTHELLO"
    t1w = MeasureText(t1, 60)
    DrawText(t1, (SCREEN_W - t1w)/2, 80, 60, RAYLIBColor(50, 220, 80, 255))

    // Subtitle
    t2 = "~ Outflank your opponent to dominate the board! ~"
    t2w = MeasureText(t2, 17)
    DrawText(t2, (SCREEN_W - t2w)/2, 150, 17, RAYLIBColor(120, 200, 160, 230))

    // Decorative discs
    oth_drawTitleDisc(250, 270, true)
    oth_drawTitleDisc(SCREEN_W - 250, 270, false)

    // Controls
    cy = 215
    cLines = [
        "Mouse Click         -   Select cell & place disc",
        "Arrow Keys / WASD   -   Move cursor (keyboard)",
        "ENTER / SPACE       -   Place disc (keyboard)",
        "U                   -   Undo last move",
        "H                   -   Toggle move hints",
        "R                   -   Restart game",
        "C                   -   Cycle camera view",
        "",
        "Game Modes:",
        "  1  -  Player vs Player",
        "  2  -  Player vs AI",
        "",
        "Rules:",
        "  Place a disc to outflank opponent's pieces.",
        "  Outflanked discs flip to your color!",
        "  The player with the most discs wins."
    ]
    for i = 1 to len(cLines)
        lw = MeasureText(cLines[i], 14)
        if i >= 8
            col = RAYLIBColor(255, 200, 100, 210)
        else
            col = RAYLIBColor(150, 190, 200, 230)
        ok
        DrawText(cLines[i], (SCREEN_W - lw)/2, cy + (i - 1) * 22, 14, col)
    next

    if floor(animTime * 2) % 2 = 0
        st = "Click or Press ENTER / SPACE to Start"
        stw = MeasureText(st, 26)
        DrawText(st, (SCREEN_W - stw)/2, 580, 26, WHITE)
    ok

    m1 = "Press 1 for PvP  |  Press 2 for PvAI"
    m1w = MeasureText(m1, 18)
    DrawText(m1, (SCREEN_W - m1w)/2, 620, 18, RAYLIBColor(180, 200, 100, 220))

    cr = "Developed using Ring Language + RingRayLib"
    crw = MeasureText(cr, 14)
    DrawText(cr, (SCREEN_W - crw)/2, SCREEN_H - 35, 14,
             RAYLIBColor(80, 120, 80, 180))

func oth_drawTitleDisc dx, dy, isBlack
    if isBlack
        c1 = RAYLIBColor(35, 35, 40, 255)
        c2 = RAYLIBColor(55, 55, 65, 180)
        c3 = RAYLIBColor(80, 80, 95, 120)
    else
        c1 = RAYLIBColor(230, 230, 225, 255)
        c2 = RAYLIBColor(210, 210, 205, 180)
        c3 = RAYLIBColor(180, 180, 175, 120)
    ok
    sz = 28 + floor(sin(animTime * 2.0) * 3)
    DrawCircle(dx, dy, sz, c1)
    DrawCircle(dx, dy, sz - 7, c2)
    DrawCircleLines(dx, dy, sz, c3)

// =============================================================
// Pass Message Overlay
// =============================================================

func oth_drawPassMessage
    alpha = 255
    if passMsgTimer < 0.5
        alpha = floor(passMsgTimer * 2.0 * 255)
        if alpha > 255 alpha = 255 ok
        if alpha < 0 alpha = 0 ok
    ok

    pw = MeasureText(passMsg, 28) + 40
    px = (SCREEN_W - pw) / 2
    py = SCREEN_H / 2 - 30

    DrawRectangle(px, py, pw, 50, RAYLIBColor(0, 0, 0, floor(alpha * 0.7)))
    DrawRectangleLines(px, py, pw, 50, RAYLIBColor(255, 200, 50, alpha))
    DrawText(passMsg, px + 20, py + 12, 28, RAYLIBColor(255, 220, 80, alpha))

// =============================================================
// Game Over Overlay
// =============================================================

func oth_drawGameOverOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.55))

    // Determine winner
    if scoreBlack > scoreWhite
        wName = "BLACK WINS!"
        wCol = RAYLIBColor(200, 200, 210, 255)
        if gameMode = MODE_PVA
            wName = "YOU WIN!"
            wCol = RAYLIBColor(50, 255, 120, 255)
        ok
    but scoreWhite > scoreBlack
        wName = "WHITE WINS!"
        wCol = RAYLIBColor(240, 240, 235, 255)
        if gameMode = MODE_PVA
            wName = "AI WINS!"
            wCol = RAYLIBColor(255, 100, 80, 255)
        ok
    else
        wName = "IT'S A TIE!"
        wCol = RAYLIBColor(255, 220, 80, 255)
    ok

    g1w = MeasureText(wName, 50)
    DrawText(wName, (SCREEN_W - g1w)/2, 210, 50, wCol)

    // Final scores
    s1 = "Black: " + scoreBlack + "     White: " + scoreWhite
    s1w = MeasureText(s1, 24)
    DrawText(s1, (SCREEN_W - s1w)/2, 290, 24, RAYLIBColor(200, 220, 255, 255))

    // Score bar visualization
    barW = 300
    barH = 30
    barX = (SCREEN_W - barW) / 2
    barY = 330
    total = scoreBlack + scoreWhite
    if total > 0
        blackW = floor((scoreBlack * 1.0 / total) * barW)
    else
        blackW = barW / 2
    ok
    whiteW = barW - blackW

    DrawRectangle(barX, barY, blackW, barH, RAYLIBColor(40, 40, 45, 255))
    DrawRectangle(barX + blackW, barY, whiteW, barH, RAYLIBColor(230, 230, 225, 255))
    DrawRectangleLines(barX, barY, barW, barH, RAYLIBColor(100, 100, 100, 200))

    // Percentage labels
    if total > 0
        bPct = "" + floor(scoreBlack * 100.0 / total) + "%"
        wPct = "" + floor(scoreWhite * 100.0 / total) + "%"
    else
        bPct = "50%"
        wPct = "50%"
    ok
    bPctW = MeasureText(bPct, 16)
    DrawText(bPct, barX + blackW/2 - bPctW/2, barY + 7, 16, RAYLIBColor(200, 200, 210, 255))
    wPctW = MeasureText(wPct, 16)
    DrawText(wPct, barX + blackW + whiteW/2 - wPctW/2, barY + 7, 16, RAYLIBColor(30, 30, 35, 255))

    DrawText("Total Moves: " + turnCount, (SCREEN_W - MeasureText("Total Moves: " + turnCount, 18))/2,
             380, 18, RAYLIBColor(160, 180, 200, 200))

    // Stars
    starCount = 3
    if gameMode = MODE_PVA
        diff = scoreBlack - scoreWhite
        if diff < 10 starCount = 2 ok
        if diff < 0  starCount = 1 ok
    ok
    starsText = ""
    for i = 1 to starCount
        starsText += "* "
    next
    stw = MeasureText(starsText, 40)
    DrawText(starsText, (SCREEN_W - stw)/2, 410, 40, RAYLIBColor(255, 215, 0, 255))

    if floor(animTime * 2) % 2 = 0
        rt = "Click or press ENTER / SPACE to play again"
        rtw = MeasureText(rt, 20)
        DrawText(rt, (SCREEN_W - rtw)/2, 470, 20, WHITE)
    ok
