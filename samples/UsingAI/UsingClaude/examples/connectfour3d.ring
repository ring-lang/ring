/*
**  3D Connect Four Game - Using RingRayLib
**  ==========================================
**  Drop discs into a 7-column, 6-row board and connect four
**  in a row horizontally, vertically, or diagonally to win!
**  A classic two-player strategy game rendered in full 3D
**  with smooth animations and visual effects.
**
**  Controls:
**    Left/Right Arrows or A/D  - Move column selector
**    ENTER / SPACE             - Drop disc in selected column
**    U                         - Undo last move
**    R                         - Restart game
**    C                         - Cycle camera views
**    1                         - Player vs Player mode
**    2                         - Player vs AI mode
**    ESC                       - Exit
**
**  Features:
**    - Full 3D rendered board with transparent frame
**    - Smooth disc drop animation with bounce
**    - Four winning directions: horizontal, vertical, 2 diagonals
**    - Winning line highlight with glow effect
**    - Simple AI opponent (blocks wins, seeks wins, plays center)
**    - Three camera modes: Front / Isometric / Overhead
**    - Undo system (unlimited steps)
**    - Particle effects on disc placement and wins
**    - Column hover preview
**    - Mini-board overlay (HUD)
**    - Title, playing, and win/draw screens
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W        = 1024
SCREEN_H        = 768

BOARD_COLS      = 7
BOARD_ROWS      = 6
CELL_SZ         = 1.6
DISC_RAD        = 0.65
DISC_HEIGHT     = 0.35
FRAME_THICK     = 0.15

// Cell states
CELL_EMPTY      = 0
CELL_P1         = 1
CELL_P2         = 2

// Game states
ST_START        = 1
ST_PLAYING      = 2
ST_DROPPING     = 3
ST_WON          = 4
ST_DRAW         = 5

// Camera modes
CAM_FRONT       = 1
CAM_ISOMETRIC   = 2
CAM_OVERHEAD    = 3
CAM_COUNT       = 3

// Animation
DROP_SPEED      = 12.0
BOUNCE_DAMPING  = 0.55
GRAVITY         = 28.0

// Game modes
MODE_PVP        = 1
MODE_PVA        = 2

// =============================================================
// Global Variables
// =============================================================

board           = []
currentPlayer   = CELL_P1
selectedCol     = 4         // 1-based, center column
gameState       = ST_START
gameMode        = MODE_PVP
animTime        = 0.0
turnCount       = 0

// Undo stack: list of [col, row, player]
undoStack       = []

// Drop animation
dropCol         = 0
dropRow         = 0
dropPlayer      = 0
dropY           = 0.0
dropVelocity    = 0.0
dropTargetY     = 0.0
dropBounces     = 0

// Winning line: list of [row, col] (4 cells)
winLine         = []
winPlayer       = 0

// Particles: [x, y, z, vx, vy, vz, life, r, g, b]
particles       = []

// Camera smoothing
cameraMode      = CAM_FRONT
camPosX = 0.0   camPosY = 8.0   camPosZ = 18.0
camTgtX = 0.0   camTgtY = 4.0   camTgtZ = 0.0

// AI thinking delay
aiTimer         = 0.0
aiDelay         = 0.45

// =============================================================
// Initialize board (statements before functions)
// =============================================================

c4_initBoard()

// =============================================================
// Main Program
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Ring 3D Connect Four - RingRayLib")
SetTargetFPS(60)

camera = Camera3D(
    0, 8, 18,
    0, 4,  0,
    0, 1,  0,
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
        c4_initBoard()
        gameState = ST_PLAYING
    ok

    // --- State-specific updates ---
    if gameState = ST_START
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            c4_initBoard()
            gameState = ST_PLAYING
        ok
        if IsKeyPressed(KEY_ONE)
            gameMode = MODE_PVP
            c4_initBoard()
            gameState = ST_PLAYING
        ok
        if IsKeyPressed(KEY_TWO)
            gameMode = MODE_PVA
            c4_initBoard()
            gameState = ST_PLAYING
        ok
    ok

    if gameState = ST_PLAYING
        if gameMode = MODE_PVA and currentPlayer = CELL_P2
            aiTimer += dt
            if aiTimer >= aiDelay
                aiTimer = 0
                aiCol = c4_aiChooseColumn()
                if aiCol > 0
                    c4_dropDisc(aiCol)
                ok
            ok
        else
            c4_handleInput()
        ok
        c4_updateParticles(dt)
    ok

    if gameState = ST_DROPPING
        c4_updateDropAnimation(dt)
        c4_updateParticles(dt)
    ok

    if gameState = ST_WON
        c4_updateParticles(dt)
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            c4_initBoard()
            gameState = ST_PLAYING
        ok
    ok

    if gameState = ST_DRAW
        c4_updateParticles(dt)
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            c4_initBoard()
            gameState = ST_PLAYING
        ok
    ok

    c4_positionCamera()

    // --- Drawing ---
    BeginDrawing()
        ClearBackground(RAYLIBColor(14, 16, 26, 255))

        if gameState = ST_START
            c4_drawTitleScreen()
        else
            BeginMode3D(camera)
                c4_drawBoard()
                c4_drawDiscs()
                c4_drawHoverPreview()
                c4_drawWinHighlight()
                c4_drawParticles3D()
            EndMode3D()

            c4_drawHUD()
            c4_drawMiniBoard()

            if gameState = ST_WON
                c4_drawWinOverlay()
            ok
            if gameState = ST_DRAW
                c4_drawDrawOverlay()
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

func c4_initBoard
    board = list(BOARD_ROWS)
    for r = 1 to BOARD_ROWS
        board[r] = list(BOARD_COLS)
        for c = 1 to BOARD_COLS
            board[r][c] = CELL_EMPTY
        next
    next
    currentPlayer = CELL_P1
    selectedCol   = 4
    turnCount     = 0
    undoStack     = []
    winLine       = []
    winPlayer     = 0
    particles     = []
    dropCol       = 0
    dropRow       = 0
    aiTimer       = 0

// =============================================================
// Input Handling
// =============================================================

func c4_handleInput
    if IsKeyPressed(KEY_LEFT) or IsKeyPressed(KEY_A)
        selectedCol -= 1
        if selectedCol < 1 selectedCol = 1 ok
    ok
    if IsKeyPressed(KEY_RIGHT) or IsKeyPressed(KEY_D)
        selectedCol += 1
        if selectedCol > BOARD_COLS selectedCol = BOARD_COLS ok
    ok

    if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
        c4_dropDisc(selectedCol)
    ok

    if IsKeyPressed(KEY_U)
        c4_undo()
    ok

    if IsKeyPressed(KEY_ONE)
        gameMode = MODE_PVP
    ok
    if IsKeyPressed(KEY_TWO)
        gameMode = MODE_PVA
    ok

// =============================================================
// Drop Disc
// =============================================================

func c4_dropDisc col
    row = c4_findEmptyRow(col)
    if row = 0 return ok   // Column full

    // Save undo state
    add(undoStack, [col, row, currentPlayer])

    // Place in logical board immediately (for AI/win check after anim)
    board[row][col] = currentPlayer
    turnCount += 1

    // Start drop animation
    dropCol      = col
    dropRow      = row
    dropPlayer   = currentPlayer
    dropY        = c4_rowToY(BOARD_ROWS) + 3.0   // Start above the board
    dropTargetY  = c4_rowToY(row)
    dropVelocity = 0.0
    dropBounces  = 0
    gameState    = ST_DROPPING

func c4_findEmptyRow col
    // Returns the lowest empty row in the column (1=bottom, 6=top), or 0
    for r = 1 to BOARD_ROWS
        if board[r][col] = CELL_EMPTY
            return r
        ok
    next
    return 0

// =============================================================
// Drop Animation
// =============================================================

func c4_updateDropAnimation dt
    // Apply gravity
    dropVelocity -= GRAVITY * dt
    dropY += dropVelocity * dt

    // Check if disc reached target
    if dropY <= dropTargetY
        dropY = dropTargetY
        if dropBounces < 2
            dropVelocity = (-dropVelocity) * BOUNCE_DAMPING
            dropBounces += 1
            // Spawn small particles on bounce
            c4_spawnDiscParticles(dropCol, dropRow, dropPlayer, 6)
        else
            // Animation complete
            dropVelocity = 0
            c4_spawnDiscParticles(dropCol, dropRow, dropPlayer, 12)
            c4_onDropComplete()
        ok
    ok

func c4_onDropComplete
    // Check for win
    if c4_checkWin(dropPlayer)
        gameState = ST_WON
        winPlayer = dropPlayer
        // Spawn celebration particles along win line
        for i = 1 to len(winLine)
            wr = winLine[i][1]
            wc = winLine[i][2]
            if dropPlayer = CELL_P1
                c4_spawnDiscParticles(wc, wr, dropPlayer, 20)
            else
                c4_spawnDiscParticles(wc, wr, dropPlayer, 20)
            ok
        next
        return
    ok

    // Check for draw
    if turnCount >= BOARD_ROWS * BOARD_COLS
        gameState = ST_DRAW
        return
    ok

    // Switch player
    if currentPlayer = CELL_P1
        currentPlayer = CELL_P2
    else
        currentPlayer = CELL_P1
    ok
    gameState = ST_PLAYING

// =============================================================
// Undo System
// =============================================================

func c4_undo
    if len(undoStack) = 0 return ok
    if gameState = ST_DROPPING return ok  // Can't undo during animation

    last = undoStack[len(undoStack)]
    del(undoStack, len(undoStack))

    uCol = last[1]
    uRow = last[2]
    uPlayer = last[3]

    board[uRow][uCol] = CELL_EMPTY
    turnCount -= 1
    currentPlayer = uPlayer
    winLine = []
    winPlayer = 0
    gameState = ST_PLAYING

// =============================================================
// Win Detection
// =============================================================

func c4_checkWin player
    // Check all possible 4-in-a-row lines
    // Horizontal
    for r = 1 to BOARD_ROWS
        for c = 1 to BOARD_COLS - 3
            if board[r][c] = player and
               board[r][c+1] = player and
               board[r][c+2] = player and
               board[r][c+3] = player
                winLine = [ [r,c], [r,c+1], [r,c+2], [r,c+3] ]
                return true
            ok
        next
    next

    // Vertical
    for r = 1 to BOARD_ROWS - 3
        for c = 1 to BOARD_COLS
            if board[r][c] = player and
               board[r+1][c] = player and
               board[r+2][c] = player and
               board[r+3][c] = player
                winLine = [ [r,c], [r+1,c], [r+2,c], [r+3,c] ]
                return true
            ok
        next
    next

    // Diagonal up-right
    for r = 1 to BOARD_ROWS - 3
        for c = 1 to BOARD_COLS - 3
            if board[r][c] = player and
               board[r+1][c+1] = player and
               board[r+2][c+2] = player and
               board[r+3][c+3] = player
                winLine = [ [r,c], [r+1,c+1], [r+2,c+2], [r+3,c+3] ]
                return true
            ok
        next
    next

    // Diagonal up-left
    for r = 1 to BOARD_ROWS - 3
        for c = 4 to BOARD_COLS
            if board[r][c] = player and
               board[r+1][c-1] = player and
               board[r+2][c-2] = player and
               board[r+3][c-3] = player
                winLine = [ [r,c], [r+1,c-1], [r+2,c-2], [r+3,c-3] ]
                return true
            ok
        next
    next

    return false

// =============================================================
// AI (Simple heuristic)
// =============================================================

func c4_aiChooseColumn
    // Priority 1: Win if possible
    for c = 1 to BOARD_COLS
        r = c4_findEmptyRow(c)
        if r > 0
            board[r][c] = CELL_P2
            if c4_checkWinNoStore(CELL_P2)
                board[r][c] = CELL_EMPTY
                return c
            ok
            board[r][c] = CELL_EMPTY
        ok
    next

    // Priority 2: Block opponent's win
    for c = 1 to BOARD_COLS
        r = c4_findEmptyRow(c)
        if r > 0
            board[r][c] = CELL_P1
            if c4_checkWinNoStore(CELL_P1)
                board[r][c] = CELL_EMPTY
                return c
            ok
            board[r][c] = CELL_EMPTY
        ok
    next

    // Priority 3: Prefer center columns
    centerOrder = [4, 3, 5, 2, 6, 1, 7]
    for i = 1 to len(centerOrder)
        c = centerOrder[i]
        r = c4_findEmptyRow(c)
        if r > 0
            // Avoid moves that let opponent win next turn
            board[r][c] = CELL_P2
            safe = true
            if r < BOARD_ROWS
                board[r+1][c] = CELL_P1
                if c4_checkWinNoStore(CELL_P1)
                    safe = false
                ok
                board[r+1][c] = CELL_EMPTY
            ok
            board[r][c] = CELL_EMPTY
            if safe
                return c
            ok
        ok
    next

    // Fallback: any valid column
    for c = 1 to BOARD_COLS
        if c4_findEmptyRow(c) > 0
            return c
        ok
    next
    return 0

func c4_checkWinNoStore player
    // Same as c4_checkWin but doesn't store winLine
    for r = 1 to BOARD_ROWS
        for c = 1 to BOARD_COLS - 3
            if board[r][c] = player and board[r][c+1] = player and
               board[r][c+2] = player and board[r][c+3] = player
                return true
            ok
        next
    next
    for r = 1 to BOARD_ROWS - 3
        for c = 1 to BOARD_COLS
            if board[r][c] = player and board[r+1][c] = player and
               board[r+2][c] = player and board[r+3][c] = player
                return true
            ok
        next
    next
    for r = 1 to BOARD_ROWS - 3
        for c = 1 to BOARD_COLS - 3
            if board[r][c] = player and board[r+1][c+1] = player and
               board[r+2][c+2] = player and board[r+3][c+3] = player
                return true
            ok
        next
    next
    for r = 1 to BOARD_ROWS - 3
        for c = 4 to BOARD_COLS
            if board[r][c] = player and board[r+1][c-1] = player and
               board[r+2][c-2] = player and board[r+3][c-3] = player
                return true
            ok
        next
    next
    return false

// =============================================================
// Coordinate Helpers
// =============================================================

func c4_colToX col
    // Center the board horizontally. Col 1..7 maps to X positions
    return (col - 1) * CELL_SZ - (BOARD_COLS - 1) * CELL_SZ / 2

func c4_rowToY row
    // Row 1 = bottom, Row 6 = top
    return (row - 1) * CELL_SZ + CELL_SZ / 2 + 0.2

// =============================================================
// Particles
// =============================================================

func c4_spawnDiscParticles col, row, player, count
    wx = c4_colToX(col)
    wy = c4_rowToY(row)
    wz = 0.0

    if player = CELL_P1
        pr = 255  pg = 60  pb = 60
    else
        pr = 60  pg = 100  pb = 255
    ok

    for i = 1 to count
        vx = (GetRandomValue(-100, 100) / 100.0) * 2.5
        vy = (GetRandomValue(50, 300) / 100.0) * 1.8
        vz = (GetRandomValue(-100, 100) / 100.0) * 2.5
        cr = pr + GetRandomValue(-30, 30)
        cg = pg + GetRandomValue(-30, 30)
        cb = pb + GetRandomValue(-30, 30)
        if cr < 0 cr = 0 ok    if cr > 255 cr = 255 ok
        if cg < 0 cg = 0 ok    if cg > 255 cg = 255 ok
        if cb < 0 cb = 0 ok    if cb > 255 cb = 255 ok
        add(particles, [wx, wy, wz, vx, vy, vz, 1.4, cr, cg, cb])
    next

func c4_updateParticles dt
    i = 1
    while i <= len(particles)
        particles[i][1] += particles[i][4] * dt
        particles[i][2] += particles[i][5] * dt
        particles[i][3] += particles[i][6] * dt
        particles[i][5] -= 6.0 * dt    // gravity
        particles[i][7] -= dt           // life
        if particles[i][7] <= 0
            del(particles, i)
        else
            i += 1
        ok
    end

func c4_drawParticles3D
    for i = 1 to len(particles)
        p = particles[i]
        alpha = floor((p[7] / 1.4) * 255)
        if alpha > 255 alpha = 255 ok
        if alpha < 0 alpha = 0 ok
        sz = 0.05 + p[7] * 0.08
        DrawSphereEx(
            Vector3(p[1], p[2], p[3]),
            sz, 4, 4,
            RAYLIBColor(p[8], p[9], p[10], alpha)
        )
    next

// =============================================================
// Camera
// =============================================================

func c4_positionCamera
    boardW = BOARD_COLS * CELL_SZ
    boardH = BOARD_ROWS * CELL_SZ
    centerX = 0
    centerY = boardH / 2 + 0.5

    goalX = 0  goalY = 0  goalZ = 0
    tgtX = 0   tgtY = 0   tgtZ = 0
    lerpSpd = 0.06

    if cameraMode = CAM_FRONT
        goalX = 0
        goalY = centerY + 1.0
        goalZ = 16.0
        tgtX = 0
        tgtY = centerY - 0.5
        tgtZ = 0
        lerpSpd = 0.08
    ok

    if cameraMode = CAM_ISOMETRIC
        goalX = boardW * 0.6
        goalY = centerY + 5.0
        goalZ = boardW * 0.6
        tgtX = 0
        tgtY = centerY - 1.0
        tgtZ = 0
        lerpSpd = 0.06
    ok

    if cameraMode = CAM_OVERHEAD
        goalX = 0.0
        goalY = boardH + 10.0
        goalZ = 0.1
        tgtX = 0
        tgtY = centerY
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
// 3D Drawing: Board Frame
// =============================================================

func c4_drawBoard
    boardW = BOARD_COLS * CELL_SZ
    boardH = BOARD_ROWS * CELL_SZ

    // Board back panel
    DrawCube(
        Vector3(0, boardH / 2 + 0.2, -0.5),
        boardW + 1.0, boardH + 1.0, 0.3,
        RAYLIBColor(20, 40, 100, 255)
    )
    DrawCubeWires(
        Vector3(0, boardH / 2 + 0.2, -0.5),
        boardW + 1.0, boardH + 1.0, 0.3,
        RAYLIBColor(40, 70, 160, 200)
    )

    // Board frame - vertical dividers and horizontal shelves
    // The "grid" structure that holds the discs
    frameCol = RAYLIBColor(25, 50, 120, 230)
    frameWire = RAYLIBColor(50, 80, 170, 180)

    // Vertical columns (7+1 = 8 dividers)
    for c = 0 to BOARD_COLS
        vx = c4_colToX(1) - CELL_SZ / 2 + c * CELL_SZ
        vy = boardH / 2 + 0.2
        DrawCube(
            Vector3(vx, vy, 0),
            FRAME_THICK, boardH + 0.6, CELL_SZ * 0.85,
            frameCol
        )
        DrawCubeWires(
            Vector3(vx, vy, 0),
            FRAME_THICK, boardH + 0.6, CELL_SZ * 0.85,
            frameWire
        )
    next

    // Horizontal shelves (bottom + 6 rows = 7 shelves, but only bottom
    // needs to be solid, the rest are thin lines for visual effect)
    // Bottom solid base
    baseY = 0.0
    DrawCube(
        Vector3(0, baseY, 0),
        boardW + 1.0, 0.4, CELL_SZ * 0.85,
        RAYLIBColor(18, 35, 85, 255)
    )
    DrawCubeWires(
        Vector3(0, baseY, 0),
        boardW + 1.0, 0.4, CELL_SZ * 0.85,
        RAYLIBColor(40, 70, 160, 200)
    )

    // Top cap
    topY = boardH + 0.5
    DrawCube(
        Vector3(0, topY, 0),
        boardW + 1.0, 0.3, CELL_SZ * 0.85,
        RAYLIBColor(30, 55, 130, 230)
    )
    DrawCubeWires(
        Vector3(0, topY, 0),
        boardW + 1.0, 0.3, CELL_SZ * 0.85,
        frameWire
    )

    // Thin horizontal grid lines between rows
    for r = 1 to BOARD_ROWS - 1
        lineY = r * CELL_SZ + 0.2
        DrawCube(
            Vector3(0, lineY, 0),
            boardW + 0.5, 0.06, CELL_SZ * 0.7,
            RAYLIBColor(30, 60, 140, 150)
        )
    next

    // Floor / ground plane
    DrawPlane(
        Vector3(0, -0.2, 0),
        Vector2(30, 30),
        RAYLIBColor(18, 20, 32, 255)
    )

    // Subtle ground grid
    for i = -15 to 15
        gridCol = RAYLIBColor(30, 35, 50, 100)
        fi = i * 1.0
        DrawLine3D(Vector3(-15, -0.19, fi), Vector3(15, -0.19, fi), gridCol)
        DrawLine3D(Vector3(fi, -0.19, -15), Vector3(fi, -0.19, 15), gridCol)
    next

    // Cell slot circles (empty holes visual)
    for r = 1 to BOARD_ROWS
        for c = 1 to BOARD_COLS
            if board[r][c] = CELL_EMPTY
                // Don't draw hole if disc being animated to here
                if gameState = ST_DROPPING and dropRow = r and dropCol = c
                    // skip - disc animation in progress
                else
                    wx = c4_colToX(c)
                    wy = c4_rowToY(r)
                    DrawCircle3D(
                        Vector3(wx, wy, 0.55),
                        DISC_RAD * 0.7,
                        Vector3(0, 0, 1), 0.0,
                        RAYLIBColor(15, 30, 70, 150)
                    )
                ok
            ok
        next
    next

// =============================================================
// 3D Drawing: Discs
// =============================================================

func c4_drawDiscs
    for r = 1 to BOARD_ROWS
        for c = 1 to BOARD_COLS
            player = board[r][c]
            if player = CELL_EMPTY loop ok

            // If this cell is the dropping disc, draw at animated position
            if gameState = ST_DROPPING and r = dropRow and c = dropCol
                wx = c4_colToX(c)
                wy = dropY
                c4_drawOneDisc(wx, wy, player, false)
                loop
            ok

            wx = c4_colToX(c)
            wy = c4_rowToY(r)

            // Check if on win line
            onWin = false
            if gameState = ST_WON
                for w = 1 to len(winLine)
                    if winLine[w][1] = r and winLine[w][2] = c
                        onWin = true
                    ok
                next
            ok

            c4_drawOneDisc(wx, wy, player, onWin)
        next
    next

func c4_drawOneDisc wx, wy, player, onWin
    if player = CELL_P1
        discCol  = RAYLIBColor(220, 40, 40, 255)
        wireCol  = RAYLIBColor(255, 80, 80, 200)
        glowCol  = RAYLIBColor(255, 60, 60, 50)
        innerCol = RAYLIBColor(255, 100, 80, 255)
    else
        discCol  = RAYLIBColor(40, 80, 220, 255)
        wireCol  = RAYLIBColor(80, 120, 255, 200)
        glowCol  = RAYLIBColor(60, 100, 255, 50)
        innerCol = RAYLIBColor(100, 140, 255, 255)
    ok

    // Main disc body (cylinder approximated with flat cube)
    DrawCylinder(
        Vector3(wx, wy - DISC_HEIGHT/2, 0),
        DISC_RAD, DISC_RAD, DISC_HEIGHT, 20,
        discCol
    )
    DrawCylinderWires(
        Vector3(wx, wy - DISC_HEIGHT/2, 0),
        DISC_RAD, DISC_RAD, DISC_HEIGHT, 20,
        wireCol
    )

    // Inner ring detail
    DrawCircle3D(
        Vector3(wx, wy, 0.01 + DISC_HEIGHT/2),
        DISC_RAD * 0.55,
        Vector3(0, 0, 1), 0.0,
        innerCol
    )

    // Shine dot
    DrawSphere(
        Vector3(wx + 0.15, wy + 0.1, DISC_HEIGHT/2 + 0.02),
        0.08,
        RAYLIBColor(255, 255, 255, 120)
    )

    if onWin
        // Pulsing glow for winning discs
        pulse = 0.8 + sin(animTime * 5.0) * 0.3
        DrawSphereEx(
            Vector3(wx, wy, 0),
            DISC_RAD * 1.2 * pulse, 8, 8,
            glowCol
        )
        DrawCircle3D(
            Vector3(wx, wy, 0.02 + DISC_HEIGHT/2),
            DISC_RAD * 1.1 * pulse,
            Vector3(0, 0, 1), animTime * 60,
            wireCol
        )
    ok

// =============================================================
// 3D Drawing: Hover Preview
// =============================================================

func c4_drawHoverPreview
    if gameState != ST_PLAYING return ok

    // Don't show preview for AI's turn
    if gameMode = MODE_PVA and currentPlayer = CELL_P2 return ok

    col = selectedCol
    row = c4_findEmptyRow(col)
    if row = 0 return ok

    wx = c4_colToX(col)
    wy = c4_rowToY(BOARD_ROWS) + 2.5

    if currentPlayer = CELL_P1
        prevCol = RAYLIBColor(255, 60, 60, 100 + floor(sin(animTime * 4.0) * 40))
    else
        prevCol = RAYLIBColor(60, 100, 255, 100 + floor(sin(animTime * 4.0) * 40))
    ok

    // Floating disc preview above the board
    DrawCylinder(
        Vector3(wx, wy - DISC_HEIGHT/2, 0),
        DISC_RAD * 0.9, DISC_RAD * 0.9, DISC_HEIGHT, 16,
        prevCol
    )

    // Arrow pointing down
    arrowY = wy - 1.0
    for a = 0 to 3
        ay = arrowY - a * 0.4
        aAlpha = 180 - a * 40
        if aAlpha < 0 aAlpha = 0 ok
        DrawSphere(
            Vector3(wx, ay, 0.1),
            0.06,
            prevCol
        )
    next

    // Column highlight line
    targetY = c4_rowToY(row)
    DrawLine3D(
        Vector3(wx, wy - 1.5, 0.3),
        Vector3(wx, targetY, 0.3),
        prevCol
    )

// =============================================================
// 3D Drawing: Win Highlight
// =============================================================

func c4_drawWinHighlight
    if gameState != ST_WON return ok
    if len(winLine) < 4 return ok

    // Draw connecting line between winning discs
    if winPlayer = CELL_P1
        lineCol = RAYLIBColor(255, 220, 50, 200)
    else
        lineCol = RAYLIBColor(50, 220, 255, 200)
    ok

    for i = 1 to len(winLine) - 1
        x1 = c4_colToX(winLine[i][2])
        y1 = c4_rowToY(winLine[i][1])
        x2 = c4_colToX(winLine[i+1][2])
        y2 = c4_rowToY(winLine[i+1][1])

        DrawLine3D(
            Vector3(x1, y1, 0.8),
            Vector3(x2, y2, 0.8),
            lineCol
        )
        // Thick line effect
        DrawCylinder(
            Vector3(x1, y1, 0.8),
            0.05, 0.05, 0.01, 6,
            lineCol
        )
    next

    // Spheres at endpoints
    for i = 1 to len(winLine)
        wx = c4_colToX(winLine[i][2])
        wy = c4_rowToY(winLine[i][1])
        pulse = 0.9 + sin(animTime * 6.0 + i) * 0.15
        DrawSphereEx(
            Vector3(wx, wy, 0.85),
            0.12 * pulse, 6, 6,
            lineCol
        )
    next

// =============================================================
// HUD
// =============================================================

func c4_drawHUD
    panelW = 250
    panelH = 120
    DrawRectangle(10, 30, panelW, panelH, Fade(BLACK, 0.75))
    DrawRectangleLines(10, 30, panelW, panelH, RAYLIBColor(80, 120, 200, 200))

    DrawText("3D CONNECT FOUR", 20, 38, 18, RAYLIBColor(100, 160, 255, 255))

    // Current player indicator
    if gameState = ST_PLAYING or gameState = ST_DROPPING
        if currentPlayer = CELL_P1
            pName = "RED"
            pCol = RAYLIBColor(255, 80, 80, 255)
        else
            pName = "BLUE"
            pCol = RAYLIBColor(80, 120, 255, 255)
        ok
        if gameMode = MODE_PVA and currentPlayer = CELL_P2
            pName = "AI (BLUE)"
        ok
        DrawText("Turn: " + pName, 20, 62, 16, pCol)
    ok

    DrawText("Moves: " + turnCount, 20, 84, 16, RAYLIBColor(180, 200, 220, 220))

    modeName = "Player vs Player"
    if gameMode = MODE_PVA modeName = "Player vs AI" ok
    DrawText("Mode: " + modeName, 20, 106, 14, RAYLIBColor(150, 170, 200, 200))

    DrawText("Undo: " + len(undoStack), 20, 128, 14, RAYLIBColor(140, 155, 175, 180))

    // Camera mode
    camName = "FRONT"
    if cameraMode = CAM_ISOMETRIC camName = "ISOMETRIC" ok
    if cameraMode = CAM_OVERHEAD  camName = "OVERHEAD"  ok
    DrawRectangle(10, SCREEN_H - 60, 210, 25, Fade(BLACK, 0.6))
    DrawText("Cam: " + camName + "  [C] switch", 16, SCREEN_H - 56, 14,
             RAYLIBColor(150, 180, 210, 220))

    // Controls
    DrawRectangle(SCREEN_W - 380, SCREEN_H - 35, 370, 25, Fade(BLACK, 0.6))
    DrawText("Arrows/AD | Space: Drop | U: Undo | R: Reset | 1/2: Mode",
             SCREEN_W - 375, SCREEN_H - 30, 13, RAYLIBColor(150, 160, 180, 200))

// =============================================================
// Mini Board (2D overlay)
// =============================================================

func c4_drawMiniBoard
    cellW = 16
    cellH = 16
    mapW = BOARD_COLS * cellW
    mapH = BOARD_ROWS * cellH
    mapX = SCREEN_W - mapW - 20
    mapY = 30

    DrawRectangle(mapX - 3, mapY - 3, mapW + 6, mapH + 6, Fade(BLACK, 0.8))
    DrawRectangleLines(mapX - 3, mapY - 3, mapW + 6, mapH + 6,
                       RAYLIBColor(80, 120, 200, 200))

    // Draw cells (top to bottom visually = row 6 down to row 1)
    for r = 1 to BOARD_ROWS
        for c = 1 to BOARD_COLS
            // Display row: row 6 at top, row 1 at bottom
            displayR = BOARD_ROWS - r
            sx = mapX + (c - 1) * cellW
            sy = mapY + displayR * cellH

            DrawRectangle(sx, sy, cellW, cellH, RAYLIBColor(20, 35, 80, 200))
            DrawRectangleLines(sx, sy, cellW, cellH, RAYLIBColor(40, 60, 120, 150))

            if board[r][c] = CELL_P1
                DrawCircle(sx + cellW/2, sy + cellH/2, 6, RAYLIBColor(220, 50, 50, 255))
            ok
            if board[r][c] = CELL_P2
                DrawCircle(sx + cellW/2, sy + cellH/2, 6, RAYLIBColor(50, 80, 220, 255))
            ok
        next
    next

    // Selected column indicator
    scx = mapX + (selectedCol - 1) * cellW
    DrawRectangle(scx, mapY - 8, cellW, 5, RAYLIBColor(255, 255, 100, 200))

    // Win line highlight on minimap
    if gameState = ST_WON
        for i = 1 to len(winLine)
            wr = winLine[i][1]
            wc = winLine[i][2]
            displayR = BOARD_ROWS - wr
            sx = mapX + (wc - 1) * cellW
            sy = mapY + displayR * cellH
            DrawRectangleLines(sx, sy, cellW, cellH, RAYLIBColor(255, 220, 50, 255))
        next
    ok

    DrawText("BOARD", mapX + mapW/2 - 22, mapY - 20, 12,
             RAYLIBColor(150, 180, 220, 200))

// =============================================================
// Title Screen
// =============================================================

func c4_drawTitleScreen
    DrawRectangleGradientV(0, 0, SCREEN_W, SCREEN_H,
        RAYLIBColor(10, 12, 25, 255), RAYLIBColor(15, 20, 40, 255))

    // Title
    t1 = "3D CONNECT FOUR"
    t1w = MeasureText(t1, 55)
    DrawText(t1, (SCREEN_W - t1w)/2, 100, 55, RAYLIBColor(100, 160, 255, 255))

    // Subtitle
    t2 = "~ Drop discs to connect four in a row! ~"
    t2w = MeasureText(t2, 18)
    DrawText(t2, (SCREEN_W - t2w)/2, 170, 18, RAYLIBColor(140, 180, 220, 230))

    // Draw decorative discs
    c4_drawTitleDisc(280, 300, true)
    c4_drawTitleDisc(SCREEN_W - 280, 300, false)

    // Controls
    cy = 230
    cLines = [
        "Left / Right or A / D   -   Select column",
        "ENTER / SPACE           -   Drop disc",
        "U                       -   Undo last move",
        "R                       -   Restart game",
        "C                       -   Cycle camera view",
        "",
        "Game Modes:",
        "  1  -  Player vs Player",
        "  2  -  Player vs AI",
        "",
        "Connect 4 discs in any direction to win!",
        "Horizontal / Vertical / Diagonal"
    ]
    for i = 1 to len(cLines)
        lw = MeasureText(cLines[i], 15)
        if i >= 7
            col = RAYLIBColor(255, 200, 100, 220)
        else
            col = RAYLIBColor(160, 190, 210, 230)
        ok
        DrawText(cLines[i], (SCREEN_W - lw)/2, cy + (i - 1) * 24, 15, col)
    next

    if floor(animTime * 2) % 2 = 0
        st = "Press ENTER or SPACE to Start"
        stw = MeasureText(st, 26)
        DrawText(st, (SCREEN_W - stw)/2, 550, 26, WHITE)
    ok

    // Mode quick select
    m1 = "Press 1 for PvP  |  Press 2 for PvAI"
    m1w = MeasureText(m1, 18)
    DrawText(m1, (SCREEN_W - m1w)/2, 590, 18, RAYLIBColor(180, 200, 100, 220))

    cr = "Developed using Ring Language + RingRayLib"
    crw = MeasureText(cr, 14)
    DrawText(cr, (SCREEN_W - crw)/2, SCREEN_H - 40, 14,
             RAYLIBColor(100, 120, 100, 180))

func c4_drawTitleDisc dx, dy, isRed
    if isRed
        c1 = RAYLIBColor(220, 50, 50, 255)
        c2 = RAYLIBColor(255, 100, 80, 150)
    else
        c1 = RAYLIBColor(50, 80, 220, 255)
        c2 = RAYLIBColor(80, 130, 255, 150)
    ok
    sz = 30 + floor(sin(animTime * 2.0) * 4)
    DrawCircle(dx, dy, sz, c1)
    DrawCircle(dx, dy, sz - 8, c2)
    DrawCircleLines(dx, dy, sz, RAYLIBColor(255, 255, 255, 100))

// =============================================================
// Win Overlay
// =============================================================

func c4_drawWinOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.45))

    if winPlayer = CELL_P1
        wName = "RED WINS!"
        wCol = RAYLIBColor(255, 80, 80, 255)
        if gameMode = MODE_PVP
            wName = "RED PLAYER WINS!"
        else
            wName = "YOU WIN!"
        ok
    else
        wName = "BLUE WINS!"
        wCol = RAYLIBColor(80, 130, 255, 255)
        if gameMode = MODE_PVA
            wName = "AI WINS!"
        ok
    ok

    g1w = MeasureText(wName, 50)
    DrawText(wName, (SCREEN_W - g1w)/2, 240, 50, wCol)

    s1 = "Total Moves: " + turnCount
    s1w = MeasureText(s1, 22)
    DrawText(s1, (SCREEN_W - s1w)/2, 310, 22, RAYLIBColor(200, 220, 255, 255))

    // Stars based on efficiency
    starCount = 3
    if turnCount > 15 starCount = 2 ok
    if turnCount > 25 starCount = 1 ok
    starsText = ""
    for i = 1 to starCount
        starsText += "* "
    next
    stw = MeasureText(starsText, 40)
    DrawText(starsText, (SCREEN_W - stw)/2, 350, 40, RAYLIBColor(255, 215, 0, 255))

    if floor(animTime * 2) % 2 = 0
        rt = "Press ENTER or SPACE to play again"
        rtw = MeasureText(rt, 20)
        DrawText(rt, (SCREEN_W - rtw)/2, 420, 20, WHITE)
    ok

// =============================================================
// Draw Overlay
// =============================================================

func c4_drawDrawOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.5))

    g1 = "IT'S A DRAW!"
    g1w = MeasureText(g1, 50)
    DrawText(g1, (SCREEN_W - g1w)/2, 260, 50, RAYLIBColor(200, 200, 100, 255))

    s1 = "The board is full - no winner this time."
    s1w = MeasureText(s1, 20)
    DrawText(s1, (SCREEN_W - s1w)/2, 330, 20, RAYLIBColor(200, 220, 255, 230))

    if floor(animTime * 2) % 2 = 0
        rt = "Press ENTER or SPACE to play again"
        rtw = MeasureText(rt, 20)
        DrawText(rt, (SCREEN_W - rtw)/2, 390, 20, WHITE)
    ok
