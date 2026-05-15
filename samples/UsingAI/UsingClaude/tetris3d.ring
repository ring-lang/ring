/*
**  3D Tetris Game - Using RingRayLib
**  ====================================
**  Classic Tetris rendered in full 3D! Stack falling tetrominoes,
**  clear lines, and chase high scores across increasing levels!
**
**  Controls:
**    Left / Right       -   Move piece horizontally
**    Down               -   Soft drop (speed up fall)
**    Up / X             -   Rotate clockwise
**    Z                  -   Rotate counter-clockwise
**    SPACE              -   Hard drop (instant placement)
**    Tab / Shift        -   Hold piece
**    C                  -   Cycle camera views
**    P                  -   Pause / Unpause
**    R                  -   Restart game
**    ESC                -   Exit
**
**  Features:
**    - All 7 classic tetrominoes (I, O, T, S, Z, L, J)
**    - 10-wide x 20-tall playfield in 3D
**    - Wall kick rotation system
**    - Ghost piece preview (translucent landing position)
**    - Hold piece system
**    - Next piece preview (3 pieces ahead)
**    - Line clear animation with flash and collapse
**    - Increasing speed across 15 levels
**    - Scoring: single/double/triple/tetris + soft/hard drop
**    - Combo system
**    - Three camera modes
**    - Particle effects
**    - Smooth animations
**    - Mouse-free (pure keyboard game)
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W        = 1024
SCREEN_H        = 768

FIELD_W         = 10
FIELD_H         = 20
FIELD_BUFFER    = 4       // Extra rows above visible area
TOTAL_H         = FIELD_H + FIELD_BUFFER

CELL_SZ         = 0.6     // 3D cell size

// Piece types (1-7)
PC_I = 1    PC_O = 2    PC_T = 3    PC_S = 4
PC_Z = 5    PC_L = 6    PC_J = 7

// Game states
ST_START        = 1
ST_PLAYING      = 2
ST_PAUSED       = 3
ST_CLEARING     = 4      // Line clear animation
ST_GAMEOVER     = 5

// Camera modes
CAM_FRONT       = 1
CAM_ANGLE       = 2
CAM_SIDE        = 3
CAM_COUNT       = 3

// Scoring
SCORE_SINGLE    = 100
SCORE_DOUBLE    = 300
SCORE_TRIPLE    = 500
SCORE_TETRIS    = 800
SCORE_SOFT      = 1
SCORE_HARD      = 2

// DAS (Delayed Auto Shift) for smooth movement
DAS_DELAY       = 0.17
DAS_REPEAT      = 0.05

// =============================================================
// Piece Definitions (4 rotations each, as [row,col] offsets)
// =============================================================

// Each piece has 4 rotation states, each state has 4 blocks
// Blocks are [row, col] offsets from pivot

pieceData = []      // [piece][rotation][block][row/col]
pieceColors = []    // [piece] = [r,g,b]

// Will be populated in init

// =============================================================
// Global Variables
// =============================================================

// Playfield: 0 = empty, 1-7 = piece color index
field       = []

// Current piece
curPiece    = 0
curRot      = 1
curRow      = 0       // Row position (1-based, top is 1)
curCol      = 0       // Col position (1-based, left is 1)

// Ghost piece row
ghostRow    = 0

// Hold piece
holdPiece   = 0
holdUsed    = false

// Next pieces queue
nextPieces  = []

// Bag for random generation
bag         = []

// Game state
gameState   = ST_START
animTime    = 0.0
score       = 0
level       = 1
linesCleared = 0
totalLines  = 0
combo       = 0

// Fall timing
fallTimer   = 0.0
fallSpeed   = 0.0     // Seconds per row

// Soft drop
softDrop    = false

// DAS state (left/right auto-repeat)
dasLeftTimer  = 0.0
dasRightTimer = 0.0
dasLeftActive = false
dasRightActive = false

// Line clear animation
clearLines  = []      // List of row indices being cleared
clearTimer  = 0.0
clearDuration = 0.5

// Lock delay
lockTimer   = 0.0
lockDelay   = 0.5
lockActive  = false

// Camera
cameraMode  = CAM_FRONT
camPosX = 0.0   camPosY = 7.0   camPosZ = 16.0
camTgtX = 0.0   camTgtY = 5.0   camTgtZ = 0.0

// Particles
particles   = []

// Score popup
popupText   = ""
popupTimer  = 0.0
popupY      = 0.0

// Level speeds (seconds per row drop) for levels 1-15
levelSpeeds = []

// =============================================================
// Initialize
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Ring 3D Tetris - RingRayLib")
SetTargetFPS(60)

tet_initPieces()
tet_initSpeeds()
tet_resetGame()

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
        tet_resetGame()
        gameState = ST_PLAYING
    ok

    // --- State updates ---
    if gameState = ST_START
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            tet_resetGame()
            gameState = ST_PLAYING
        ok
    but gameState = ST_PLAYING
        if IsKeyPressed(KEY_P)
            gameState = ST_PAUSED
        else
            tet_handleInput(dt)
            tet_updateFall(dt)
            tet_updateLock(dt)
        ok
    but gameState = ST_PAUSED
        if IsKeyPressed(KEY_P) or IsKeyPressed(KEY_SPACE)
            gameState = ST_PLAYING
        ok
    but gameState = ST_CLEARING
        tet_updateClearAnim(dt)
    but gameState = ST_GAMEOVER
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            tet_resetGame()
            gameState = ST_PLAYING
        ok
    ok

    tet_updateParticles(dt)
    tet_updatePopup(dt)
    tet_positionCamera()

    // --- Drawing ---
    BeginDrawing()
        ClearBackground(RAYLIBColor(14, 16, 24, 255))

        if gameState = ST_START
            tet_drawTitleScreen()
        else
            BeginMode3D(
                Camera3D(
                    camPosX, camPosY, camPosZ,
                    camTgtX, camTgtY, camTgtZ,
                    0, 1, 0, 45.0, 0
                )
            )
                tet_drawWell3D()
                tet_drawField3D()
                tet_drawGhost3D()
                tet_drawCurrentPiece3D()
                tet_drawClearEffect3D()
                tet_drawParticles3D()
            EndMode3D()

            tet_drawHUD()
            tet_drawNextPreview()
            tet_drawHoldPreview()
            tet_drawPopup()

            if gameState = ST_PAUSED
                tet_drawPauseOverlay()
            ok
            if gameState = ST_GAMEOVER
                tet_drawGameOverOverlay()
            ok
        ok

        DrawFPS(10, 10)
    EndDrawing()

end

CloseWindow()

// =============================================================
// Piece Data Initialization
// =============================================================

func tet_initPieces
    // 7 pieces, each with 4 rotations, each rotation has 4 [r,c] blocks
    // Using SRS (Super Rotation System) approximate layouts

    pieceData = list(7)

    // I piece (cyan)
    pieceData[PC_I] = [
        [[1,1],[1,2],[1,3],[1,4]],
        [[1,3],[2,3],[3,3],[4,3]],
        [[3,1],[3,2],[3,3],[3,4]],
        [[1,2],[2,2],[3,2],[4,2]]
    ]

    // O piece (yellow)
    pieceData[PC_O] = [
        [[1,2],[1,3],[2,2],[2,3]],
        [[1,2],[1,3],[2,2],[2,3]],
        [[1,2],[1,3],[2,2],[2,3]],
        [[1,2],[1,3],[2,2],[2,3]]
    ]

    // T piece (purple)
    pieceData[PC_T] = [
        [[1,2],[2,1],[2,2],[2,3]],
        [[1,2],[2,2],[2,3],[3,2]],
        [[2,1],[2,2],[2,3],[3,2]],
        [[1,2],[2,1],[2,2],[3,2]]
    ]

    // S piece (green)
    pieceData[PC_S] = [
        [[1,2],[1,3],[2,1],[2,2]],
        [[1,2],[2,2],[2,3],[3,3]],
        [[2,2],[2,3],[3,1],[3,2]],
        [[1,1],[2,1],[2,2],[3,2]]
    ]

    // Z piece (red)
    pieceData[PC_Z] = [
        [[1,1],[1,2],[2,2],[2,3]],
        [[1,3],[2,2],[2,3],[3,2]],
        [[2,1],[2,2],[3,2],[3,3]],
        [[1,2],[2,1],[2,2],[3,1]]
    ]

    // L piece (orange)
    pieceData[PC_L] = [
        [[1,3],[2,1],[2,2],[2,3]],
        [[1,2],[2,2],[3,2],[3,3]],
        [[2,1],[2,2],[2,3],[3,1]],
        [[1,1],[1,2],[2,2],[3,2]]
    ]

    // J piece (blue)
    pieceData[PC_J] = [
        [[1,1],[2,1],[2,2],[2,3]],
        [[1,2],[1,3],[2,2],[3,2]],
        [[2,1],[2,2],[2,3],[3,3]],
        [[1,2],[2,2],[3,1],[3,2]]
    ]

    // Piece colors [r, g, b]
    pieceColors = [
        [0, 220, 220],     // I - cyan
        [220, 220, 30],    // O - yellow
        [160, 40, 200],    // T - purple
        [40, 200, 40],     // S - green
        [220, 40, 40],     // Z - red
        [230, 140, 30],    // L - orange
        [40, 60, 220]      // J - blue
    ]

func tet_initSpeeds
    levelSpeeds = [
        0.40, 0.36, 0.32, 0.28, 0.24,
        0.20, 0.17, 0.14, 0.11, 0.09,
        0.07, 0.06, 0.05, 0.04, 0.03
    ]

// =============================================================
// Reset Game
// =============================================================

func tet_resetGame
    field = list(TOTAL_H)
    for r = 1 to TOTAL_H
        field[r] = list(FIELD_W)
        for c = 1 to FIELD_W
            field[r][c] = 0
        next
    next

    score = 0
    level = 1
    linesCleared = 0
    totalLines = 0
    combo = 0
    fallTimer = 0.0
    fallSpeed = levelSpeeds[1]
    softDrop = false
    clearLines = []
    clearTimer = 0.0
    lockTimer = 0.0
    lockActive = false
    holdPiece = 0
    holdUsed = false
    particles = []
    popupText = ""
    popupTimer = 0.0
    dasLeftTimer = 0.0
    dasRightTimer = 0.0
    dasLeftActive = false
    dasRightActive = false

    // Fill bag and next queue
    bag = []
    nextPieces = []
    for i = 1 to 4
        add(nextPieces, tet_nextFromBag())
    next

    tet_spawnPiece()

// =============================================================
// Bag Randomizer (7-bag system)
// =============================================================

func tet_nextFromBag
    if len(bag) = 0
        bag = [1, 2, 3, 4, 5, 6, 7]
        // Shuffle
        for i = 7 to 2 step -1
            j = GetRandomValue(1, i)
            temp = bag[i]
            bag[i] = bag[j]
            bag[j] = temp
        next
    ok
    piece = bag[1]
    del(bag, 1)
    return piece

// =============================================================
// Spawn Piece
// =============================================================

func tet_spawnPiece
    curPiece = nextPieces[1]
    del(nextPieces, 1)
    add(nextPieces, tet_nextFromBag())

    curRot = 1
    curRow = FIELD_BUFFER    // Start just above visible area
    curCol = 4               // Center-ish

    holdUsed = false
    lockActive = false
    lockTimer = 0.0
    fallTimer = 0.0

    // Check game over
    if !tet_fits(curPiece, curRot, curRow, curCol)
        gameState = ST_GAMEOVER
        tet_spawnGameOverParticles()
    ok

    tet_updateGhost()

// =============================================================
// Collision Detection
// =============================================================

func tet_fits piece, rot, row, col
    blocks = pieceData[piece][rot]
    for i = 1 to 4
        br = row + blocks[i][1] - 1
        bc = col + blocks[i][2] - 1
        if bc < 1 or bc > FIELD_W return false ok
        if br > TOTAL_H return false ok
        if br < 1 loop ok
        if field[br][bc] != 0 return false ok
    next
    return true

// =============================================================
// Ghost Piece
// =============================================================

func tet_updateGhost
    ghostRow = curRow
    while tet_fits(curPiece, curRot, ghostRow + 1, curCol)
        ghostRow += 1
    end

// =============================================================
// Input Handling
// =============================================================

func tet_handleInput dt
    // --- Left movement with DAS ---
    if IsKeyDown(KEY_LEFT)
        if !dasLeftActive
            dasLeftActive = true
            dasLeftTimer = 0.0
            tet_moveLeft()
        else
            dasLeftTimer += dt
            if dasLeftTimer >= DAS_DELAY
                dasLeftTimer -= DAS_REPEAT
                if dasLeftTimer >= DAS_DELAY
                    dasLeftTimer = DAS_DELAY - DAS_REPEAT
                ok
                tet_moveLeft()
            ok
        ok
    else
        dasLeftActive = false
        dasLeftTimer = 0.0
    ok

    // --- Right movement with DAS ---
    if IsKeyDown(KEY_RIGHT)
        if !dasRightActive
            dasRightActive = true
            dasRightTimer = 0.0
            tet_moveRight()
        else
            dasRightTimer += dt
            if dasRightTimer >= DAS_DELAY
                dasRightTimer -= DAS_REPEAT
                if dasRightTimer >= DAS_DELAY
                    dasRightTimer = DAS_DELAY - DAS_REPEAT
                ok
                tet_moveRight()
            ok
        ok
    else
        dasRightActive = false
        dasRightTimer = 0.0
    ok

    // --- Soft drop ---
    softDrop = IsKeyDown(KEY_DOWN)

    // --- Rotate CW ---
    if IsKeyPressed(KEY_UP) or IsKeyPressed(KEY_X)
        tet_rotateCW()
    ok

    // --- Rotate CCW ---
    if IsKeyPressed(KEY_Z)
        tet_rotateCCW()
    ok

    // --- Hard drop ---
    if IsKeyPressed(KEY_SPACE)
        tet_hardDrop()
    ok

    // --- Hold ---
    if IsKeyPressed(KEY_TAB) or IsKeyPressed(KEY_LEFT_SHIFT) or IsKeyPressed(KEY_RIGHT_SHIFT)
        tet_holdSwap()
    ok

func tet_moveLeft
    if tet_fits(curPiece, curRot, curRow, curCol - 1)
        curCol -= 1
        tet_updateGhost()
        if lockActive lockTimer = 0.0 ok
    ok

func tet_moveRight
    if tet_fits(curPiece, curRot, curRow, curCol + 1)
        curCol += 1
        tet_updateGhost()
        if lockActive lockTimer = 0.0 ok
    ok

func tet_rotateCW
    newRot = curRot + 1
    if newRot > 4 newRot = 1 ok

    // Try basic rotation
    if tet_fits(curPiece, newRot, curRow, curCol)
        curRot = newRot
        tet_updateGhost()
        if lockActive lockTimer = 0.0 ok
        return
    ok

    // Wall kicks: try offsets
    kicks = [[0,-1],[0,1],[0,-2],[0,2],[-1,0],[1,0]]
    for k = 1 to len(kicks)
        tr = curRow + kicks[k][1]
        tc = curCol + kicks[k][2]
        if tet_fits(curPiece, newRot, tr, tc)
            curRow = tr
            curCol = tc
            curRot = newRot
            tet_updateGhost()
            if lockActive lockTimer = 0.0 ok
            return
        ok
    next

func tet_rotateCCW
    newRot = curRot - 1
    if newRot < 1 newRot = 4 ok

    if tet_fits(curPiece, newRot, curRow, curCol)
        curRot = newRot
        tet_updateGhost()
        if lockActive lockTimer = 0.0 ok
        return
    ok

    kicks = [[0,-1],[0,1],[0,-2],[0,2],[-1,0],[1,0]]
    for k = 1 to len(kicks)
        tr = curRow + kicks[k][1]
        tc = curCol + kicks[k][2]
        if tet_fits(curPiece, newRot, tr, tc)
            curRow = tr
            curCol = tc
            curRot = newRot
            tet_updateGhost()
            if lockActive lockTimer = 0.0 ok
            return
        ok
    next

func tet_hardDrop
    dropDist = ghostRow - curRow
    curRow = ghostRow
    score += dropDist * SCORE_HARD
    tet_lockPiece()

func tet_holdSwap
    if holdUsed return ok
    holdUsed = true

    if holdPiece = 0
        holdPiece = curPiece
        tet_spawnPiece()
    else
        temp = curPiece
        curPiece = holdPiece
        holdPiece = temp
        curRot = 1
        curRow = FIELD_BUFFER
        curCol = 4
        lockActive = false
        lockTimer = 0.0
        tet_updateGhost()
    ok

// =============================================================
// Fall & Lock
// =============================================================

func tet_updateFall dt
    speed = fallSpeed
    if softDrop
        speed = speed * 0.1
        if speed < 0.02 speed = 0.02 ok
    ok

    fallTimer += dt
    if fallTimer >= speed
        fallTimer -= speed
        if tet_fits(curPiece, curRot, curRow + 1, curCol)
            curRow += 1
            if softDrop score += SCORE_SOFT ok
            lockActive = false
            lockTimer = 0.0
        else
            // Can't move down: start lock
            if !lockActive
                lockActive = true
                lockTimer = 0.0
            ok
        ok
        tet_updateGhost()
    ok

func tet_updateLock dt
    if !lockActive return ok

    lockTimer += dt
    if lockTimer >= lockDelay
        // Check once more if piece can fall
        if tet_fits(curPiece, curRot, curRow + 1, curCol)
            lockActive = false
            lockTimer = 0.0
            return
        ok
        tet_lockPiece()
    ok

func tet_lockPiece
    // Place piece in field
    blocks = pieceData[curPiece][curRot]
    for i = 1 to 4
        br = curRow + blocks[i][1] - 1
        bc = curCol + blocks[i][2] - 1
        if br >= 1 and br <= TOTAL_H and bc >= 1 and bc <= FIELD_W
            field[br][bc] = curPiece
        ok
    next

    tet_spawnLockParticles()

    // Check for line clears
    clearLines = []
    for r = 1 to TOTAL_H
        full = true
        for c = 1 to FIELD_W
            if field[r][c] = 0
                full = false
            ok
        next
        if full
            add(clearLines, r)
        ok
    next

    if len(clearLines) > 0
        gameState = ST_CLEARING
        clearTimer = 0.0
        // Score
        combo += 1
        lines = len(clearLines)
        lineScore = 0
        if lines = 1 lineScore = SCORE_SINGLE ok
        if lines = 2 lineScore = SCORE_DOUBLE ok
        if lines = 3 lineScore = SCORE_TRIPLE ok
        if lines >= 4 lineScore = SCORE_TETRIS ok
        lineScore = lineScore * level
        if combo > 1
            lineScore = floor(lineScore * (1.0 + (combo - 1) * 0.5))
        ok
        score += lineScore
        totalLines += lines
        linesCleared += lines

        // Show popup
        if lines = 1 popupText = "SINGLE" ok
        if lines = 2 popupText = "DOUBLE" ok
        if lines = 3 popupText = "TRIPLE" ok
        if lines >= 4 popupText = "TETRIS!" ok
        if combo > 1
            popupText = popupText + " x" + string(combo)
        ok
        popupTimer = 2.0
        popupY = 0.0

        // Level up
        newLevel = floor(totalLines / 10) + 1
        if newLevel > 15 newLevel = 15 ok
        if newLevel > level
            level = newLevel
            fallSpeed = levelSpeeds[level]
        ok

        tet_spawnClearParticles()
    else
        combo = 0
        tet_spawnPiece()
    ok

    lockActive = false
    lockTimer = 0.0

// =============================================================
// Line Clear Animation
// =============================================================

func tet_updateClearAnim dt
    clearTimer += dt
    if clearTimer >= clearDuration
        // Remove cleared lines
        for i = len(clearLines) to 1 step -1
            r = clearLines[i]
            // Shift everything above down
            for rr = r to 2 step -1
                for c = 1 to FIELD_W
                    field[rr][c] = field[rr - 1][c]
                next
            next
            // Clear top row
            for c = 1 to FIELD_W
                field[1][c] = 0
            next
        next

        clearLines = []
        gameState = ST_PLAYING
        tet_spawnPiece()
    ok

// =============================================================
// Coordinate Helpers
// =============================================================

func tet_cellToX c
    return (c - 1) * CELL_SZ - (FIELD_W - 1) * CELL_SZ / 2

func tet_cellToY r
    // Row 1+BUFFER = top, row TOTAL_H = bottom
    // Map visible rows (BUFFER+1 to TOTAL_H) to Y coordinates
    // Y goes up, so higher rows = higher Y
    visRow = r - FIELD_BUFFER
    return (FIELD_H - visRow) * CELL_SZ

// =============================================================
// Particles
// =============================================================

func tet_spawnLockParticles
    blocks = pieceData[curPiece][curRot]
    cr = pieceColors[curPiece][1]
    cg = pieceColors[curPiece][2]
    cb = pieceColors[curPiece][3]
    for i = 1 to 4
        br = curRow + blocks[i][1] - 1
        bc = curCol + blocks[i][2] - 1
        wx = tet_cellToX(bc)
        wy = tet_cellToY(br)
        for j = 1 to 3
            vx = (GetRandomValue(-100, 100) / 100.0) * 0.8
            vy = (GetRandomValue(50, 200) / 100.0) * 0.5
            vz = (GetRandomValue(-50, 50) / 100.0) * 0.5
            add(particles, [wx, wy, 0.3, vx, vy, vz, 0.6, cr, cg, cb])
        next
    next

func tet_spawnClearParticles
    for i = 1 to len(clearLines)
        r = clearLines[i]
        wy = tet_cellToY(r)
        for c = 1 to FIELD_W
            wx = tet_cellToX(c)
            pc = field[r][c]
            if pc >= 1 and pc <= 7
                cr = pieceColors[pc][1]
                cg = pieceColors[pc][2]
                cb = pieceColors[pc][3]
            else
                cr = 200  cg = 200  cb = 200
            ok
            for j = 1 to 4
                vx = (GetRandomValue(-100, 100) / 100.0) * 2.0
                vy = (GetRandomValue(50, 300) / 100.0) * 1.5
                vz = (GetRandomValue(-100, 100) / 100.0) * 1.5
                add(particles, [wx, wy, 0.3, vx, vy, vz, 1.2, cr, cg, cb])
            next
        next
    next

func tet_spawnGameOverParticles
    for c = 1 to FIELD_W
        for r = FIELD_BUFFER + 1 to TOTAL_H
            if field[r][c] != 0
                wx = tet_cellToX(c)
                wy = tet_cellToY(r)
                pc = field[r][c]
                cr = pieceColors[pc][1]
                cg = pieceColors[pc][2]
                cb = pieceColors[pc][3]
                vx = (GetRandomValue(-100, 100) / 100.0) * 1.0
                vy = (GetRandomValue(100, 400) / 100.0) * 1.0
                vz = (GetRandomValue(-50, 50) / 100.0) * 1.0
                add(particles, [wx, wy, 0.3, vx, vy, vz, 2.0, cr, cg, cb])
            ok
        next
    next

func tet_updateParticles dt
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

func tet_drawParticles3D
    for i = 1 to len(particles)
        px = particles[i][1]
        py = particles[i][2]
        pz = particles[i][3]
        life = particles[i][7]
        pr = particles[i][8]
        pg = particles[i][9]
        pb = particles[i][10]
        alpha = floor(life * 220)
        if alpha > 255 alpha = 255 ok
        if alpha < 0 alpha = 0 ok
        sz = 0.04 + life * 0.03
        DrawSphere(Vector3(px, py, pz), sz,
                   RAYLIBColor(pr, pg, pb, alpha))
    next

// Score popup
func tet_updatePopup dt
    if popupTimer > 0.0
        popupTimer -= dt
        popupY += dt * 40
    ok

// =============================================================
// Camera
// =============================================================

func tet_positionCamera
    fieldMidY = FIELD_H * CELL_SZ / 2

    if cameraMode = CAM_FRONT
        goalPX = 0.0
        goalPY = fieldMidY + 0.5
        goalPZ = 17.0
        goalTX = 0.0
        goalTY = fieldMidY - 0.5
        goalTZ = 0.0
    ok

    if cameraMode = CAM_ANGLE
        goalPX = 5.0
        goalPY = fieldMidY + 2.0
        goalPZ = 16.0
        goalTX = 0.0
        goalTY = fieldMidY - 1.0
        goalTZ = 0.0
    ok

    if cameraMode = CAM_SIDE
        goalPX = -7.0
        goalPY = fieldMidY + 1.0
        goalPZ = 14.0
        goalTX = 0.0
        goalTY = fieldMidY - 0.5
        goalTZ = 0.0
    ok

    lerp = 0.05
    camPosX += (goalPX - camPosX) * lerp
    camPosY += (goalPY - camPosY) * lerp
    camPosZ += (goalPZ - camPosZ) * lerp
    camTgtX += (goalTX - camTgtX) * lerp
    camTgtY += (goalTY - camTgtY) * lerp
    camTgtZ += (goalTZ - camTgtZ) * lerp

// =============================================================
// 3D Drawing: Well (playfield border)
// =============================================================

func tet_drawWell3D
    wellW = FIELD_W * CELL_SZ
    wellH = FIELD_H * CELL_SZ
    wallThick = 0.15
    wallDepth = CELL_SZ * 1.2

    // Back wall
    DrawCube(Vector3(0, wellH / 2, -wallDepth / 2),
             wellW + wallThick * 2, wellH + wallThick, wallDepth,
             RAYLIBColor(25, 28, 38, 255))

    // Left wall
    DrawCube(Vector3(-wellW / 2 - wallThick / 2, wellH / 2, 0),
             wallThick, wellH + wallThick, wallDepth,
             RAYLIBColor(35, 38, 50, 255))

    // Right wall
    DrawCube(Vector3(wellW / 2 + wallThick / 2, wellH / 2, 0),
             wallThick, wellH + wallThick, wallDepth,
             RAYLIBColor(35, 38, 50, 255))

    // Floor
    DrawCube(Vector3(0, -wallThick / 2, 0),
             wellW + wallThick * 2, wallThick, wallDepth,
             RAYLIBColor(45, 48, 58, 255))

    // Grid lines on back wall
    for c = 0 to FIELD_W
        x = c * CELL_SZ - wellW / 2
        DrawLine3D(Vector3(x, 0, -0.3), Vector3(x, wellH, -0.3),
                   RAYLIBColor(40, 45, 60, 100))
    next
    for r = 0 to FIELD_H
        y = r * CELL_SZ
        DrawLine3D(Vector3(-wellW / 2, y, -0.3), Vector3(wellW / 2, y, -0.3),
                   RAYLIBColor(40, 45, 60, 100))
    next

// =============================================================
// 3D Drawing: Field (locked blocks)
// =============================================================

func tet_drawField3D
    for r = FIELD_BUFFER + 1 to TOTAL_H
        for c = 1 to FIELD_W
            pc = field[r][c]
            if pc = 0 loop ok

            wx = tet_cellToX(c)
            wy = tet_cellToY(r)
            cr = pieceColors[pc][1]
            cg = pieceColors[pc][2]
            cb = pieceColors[pc][3]

            // Check if this row is being cleared
            clearing = false
            if gameState = ST_CLEARING
                for i = 1 to len(clearLines)
                    if clearLines[i] = r
                        clearing = true
                    ok
                next
            ok

            if clearing
                // Flash effect
                prog = clearTimer / clearDuration
                flash = sin(prog * 3.14159265 * 6) * 0.5 + 0.5
                alpha = floor(255 * (1.0 - prog))
                if alpha < 0 alpha = 0 ok
                br = floor(cr + (255 - cr) * flash)
                bg = floor(cg + (255 - cg) * flash)
                bb = floor(cb + (255 - cb) * flash)
                if br > 255 br = 255 ok
                if bg > 255 bg = 255 ok
                if bb > 255 bb = 255 ok
                DrawCube(Vector3(wx, wy, 0), CELL_SZ - 0.04, CELL_SZ - 0.04,
                         CELL_SZ - 0.04, RAYLIBColor(br, bg, bb, alpha))
            else
                tet_drawBlock3D(wx, wy, cr, cg, cb, 255)
            ok
        next
    next

// =============================================================
// 3D Drawing: Single Block
// =============================================================

func tet_drawBlock3D wx, wy, cr, cg, cb, alpha
    sz = CELL_SZ - 0.06

    // Main body
    DrawCube(Vector3(wx, wy, 0), sz, sz, sz,
             RAYLIBColor(cr, cg, cb, alpha))

    // Highlight (top lighter)
    hr = cr + 40    if hr > 255 hr = 255 ok
    hg = cg + 40    if hg > 255 hg = 255 ok
    hb = cb + 40    if hb > 255 hb = 255 ok
    DrawCube(Vector3(wx, wy + sz / 2 + 0.01, 0), sz - 0.08, 0.02, sz - 0.08,
             RAYLIBColor(hr, hg, hb, alpha))

    // Shadow (bottom darker)
    sr = floor(cr * 0.5)
    sg = floor(cg * 0.5)
    sb = floor(cb * 0.5)
    DrawCube(Vector3(wx, wy - sz / 2 - 0.01, 0), sz - 0.08, 0.02, sz - 0.08,
             RAYLIBColor(sr, sg, sb, alpha))

// =============================================================
// 3D Drawing: Current Piece
// =============================================================

func tet_drawCurrentPiece3D
    if gameState != ST_PLAYING and gameState != ST_PAUSED return ok
    if curPiece < 1 or curPiece > 7 return ok

    blocks = pieceData[curPiece][curRot]
    cr = pieceColors[curPiece][1]
    cg = pieceColors[curPiece][2]
    cb = pieceColors[curPiece][3]

    for i = 1 to 4
        br = curRow + blocks[i][1] - 1
        bc = curCol + blocks[i][2] - 1
        if br <= FIELD_BUFFER loop ok
        wx = tet_cellToX(bc)
        wy = tet_cellToY(br)
        tet_drawBlock3D(wx, wy, cr, cg, cb, 255)
    next

// =============================================================
// 3D Drawing: Ghost Piece
// =============================================================

func tet_drawGhost3D
    if gameState != ST_PLAYING return ok
    if curPiece < 1 or curPiece > 7 return ok
    if ghostRow = curRow return ok

    blocks = pieceData[curPiece][curRot]
    cr = pieceColors[curPiece][1]
    cg = pieceColors[curPiece][2]
    cb = pieceColors[curPiece][3]

    for i = 1 to 4
        br = ghostRow + blocks[i][1] - 1
        bc = curCol + blocks[i][2] - 1
        if br <= FIELD_BUFFER loop ok
        wx = tet_cellToX(bc)
        wy = tet_cellToY(br)
        sz = CELL_SZ - 0.08
        DrawCube(Vector3(wx, wy, 0), sz, sz, sz,
                 RAYLIBColor(cr, cg, cb, 50))
    next

// =============================================================
// 3D Drawing: Line Clear Effect
// =============================================================

func tet_drawClearEffect3D
    if gameState != ST_CLEARING return ok

    prog = clearTimer / clearDuration
    for i = 1 to len(clearLines)
        r = clearLines[i]
        wy = tet_cellToY(r)

        // Horizontal flash line
        flash = sin(prog * 3.14159265 * 4) * 0.5 + 0.5
        wellW = FIELD_W * CELL_SZ
        alpha = floor(200 * (1.0 - prog) * flash)
        if alpha < 0 alpha = 0 ok
        if alpha > 255 alpha = 255 ok
        DrawCube(Vector3(0, wy, 0.3), wellW, CELL_SZ * 0.8, 0.1,
                 RAYLIBColor(255, 255, 255, alpha))
    next

// =============================================================
// HUD
// =============================================================

func tet_drawHUD
    panelW = 180
    panelH = 160
    DrawRectangle(10, 30, panelW, panelH, RAYLIBColor(0, 0, 0, 190))
    DrawRectangleLines(10, 30, panelW, panelH, RAYLIBColor(80, 100, 160, 200))

    DrawText("3D TETRIS", 20, 38, 18, RAYLIBColor(100, 180, 255, 255))

    DrawText("Score", 20, 62, 13, RAYLIBColor(140, 160, 180, 200))
    DrawText(string(score), 20, 77, 20, RAYLIBColor(255, 255, 100, 255))

    DrawText("Level", 20, 102, 13, RAYLIBColor(140, 160, 180, 200))
    DrawText(string(level), 20, 117, 20, RAYLIBColor(100, 255, 100, 255))

    DrawText("Lines", 100, 102, 13, RAYLIBColor(140, 160, 180, 200))
    DrawText(string(totalLines), 100, 117, 20, RAYLIBColor(200, 200, 255, 255))

    DrawText("Combo: " + string(combo), 20, 145, 13, RAYLIBColor(255, 180, 80, 200))

    // Camera
    camName = "FRONT"
    if cameraMode = CAM_ANGLE camName = "ANGLE" ok
    if cameraMode = CAM_SIDE  camName = "SIDE"  ok
    DrawRectangle(10, SCREEN_H - 60, 190, 25, RAYLIBColor(0, 0, 0, 153))
    DrawText("Cam: " + camName + "  [C]", 16, SCREEN_H - 56, 13,
             RAYLIBColor(150, 170, 200, 220))

    // Controls
    DrawRectangle(SCREEN_W - 520, SCREEN_H - 35, 510, 25, RAYLIBColor(0, 0, 0, 153))
    DrawText("Arrows: Move | Up/X: RotCW | Z: RotCCW | Space: Drop | Tab: Hold | P: Pause",
             SCREEN_W - 515, SCREEN_H - 30, 11, RAYLIBColor(140, 155, 180, 200))

// =============================================================
// Next Piece Preview
// =============================================================

func tet_drawNextPreview
    panelX = SCREEN_W - 140
    panelY = 30
    panelW = 130
    panelH = 230

    DrawRectangle(panelX, panelY, panelW, panelH, RAYLIBColor(0, 0, 0, 190))
    DrawRectangleLines(panelX, panelY, panelW, panelH, RAYLIBColor(80, 100, 160, 200))
    DrawText("NEXT", panelX + 40, panelY + 8, 16, RAYLIBColor(100, 180, 255, 255))

    for n = 1 to 3
        if n > len(nextPieces) loop ok
        pc = nextPieces[n]
        cr = pieceColors[pc][1]
        cg = pieceColors[pc][2]
        cb = pieceColors[pc][3]
        blocks = pieceData[pc][1]

        baseX = panelX + 22
        baseY = panelY + 30 + (n - 1) * 68

        for i = 1 to 4
            bx = baseX + (blocks[i][2] - 1) * 22
            by = baseY + (blocks[i][1] - 1) * 22
            DrawRectangle(bx, by, 20, 20, RAYLIBColor(cr, cg, cb, 255))
            DrawRectangleLines(bx, by, 20, 20, RAYLIBColor(floor(cr * 0.6), floor(cg * 0.6), floor(cb * 0.6), 200))
        next
    next

// =============================================================
// Hold Piece Preview
// =============================================================

func tet_drawHoldPreview
    panelX = SCREEN_W - 140
    panelY = 275
    panelW = 130
    panelH = 80

    DrawRectangle(panelX, panelY, panelW, panelH, RAYLIBColor(0, 0, 0, 190))
    DrawRectangleLines(panelX, panelY, panelW, panelH, RAYLIBColor(80, 100, 160, 200))

    label = "HOLD"
    if holdUsed label = "HOLD (used)" ok
    DrawText(label, panelX + 10, panelY + 8, 14, RAYLIBColor(100, 180, 255, 255))

    if holdPiece >= 1 and holdPiece <= 7
        pc = holdPiece
        cr = pieceColors[pc][1]
        cg = pieceColors[pc][2]
        cb = pieceColors[pc][3]
        blocks = pieceData[pc][1]

        if holdUsed
            cr = floor(cr * 0.4)
            cg = floor(cg * 0.4)
            cb = floor(cb * 0.4)
        ok

        baseX = panelX + 22
        baseY = panelY + 30

        for i = 1 to 4
            bx = baseX + (blocks[i][2] - 1) * 20
            by = baseY + (blocks[i][1] - 1) * 20
            DrawRectangle(bx, by, 18, 18, RAYLIBColor(cr, cg, cb, 255))
        next
    ok

// =============================================================
// Score Popup
// =============================================================

func tet_drawPopup
    if popupTimer <= 0 return ok

    alpha = floor(popupTimer * 127)
    if alpha > 255 alpha = 255 ok
    if alpha < 0 alpha = 0 ok

    pw = MeasureText(popupText, 30)
    px = floor((SCREEN_W - pw) / 2)
    py = floor(SCREEN_H / 2 - 50 - popupY)

    DrawText(popupText, px + 2, py + 2, 30, RAYLIBColor(0, 0, 0, alpha))
    DrawText(popupText, px, py, 30, RAYLIBColor(255, 255, 80, alpha))

// =============================================================
// Title Screen
// =============================================================

func tet_drawTitleScreen
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(14, 16, 24, 255))

    t1 = "3D TETRIS"
    t1w = MeasureText(t1, 52)
    t1x = floor((SCREEN_W - t1w) / 2)
    DrawText(t1, t1x + 3, 53, 52, RAYLIBColor(30, 50, 80, 200))
    DrawText(t1, t1x, 50, 52, RAYLIBColor(100, 180, 255, 255))

    t2 = "~ Stack, Clear, Score! ~"
    t2w = MeasureText(t2, 18)
    DrawText(t2, floor((SCREEN_W - t2w) / 2), 115, 18, RAYLIBColor(180, 150, 100, 220))

    cy = 160
    cLines = [
        "Left / Right           -   Move piece",
        "Down                   -   Soft drop",
        "Up / X                 -   Rotate clockwise",
        "Z                      -   Rotate counter-clockwise",
        "SPACE                  -   Hard drop (instant)",
        "Tab / Shift            -   Hold piece",
        "P                      -   Pause",
        "C                      -   Cycle camera",
        "R                      -   Restart",
        "",
        "Scoring:",
        "  Single: 100 x Level    Double: 300 x Level",
        "  Triple: 500 x Level    TETRIS: 800 x Level",
        "  Combos increase the multiplier!",
        "",
        "Clear lines to level up! Speed increases each level."
    ]
    for i = 1 to len(cLines)
        lw = MeasureText(cLines[i], 14)
        if i >= 11
            col = RAYLIBColor(255, 200, 100, 210)
        else
            col = RAYLIBColor(150, 170, 200, 230)
        ok
        DrawText(cLines[i], floor((SCREEN_W - lw) / 2), cy + (i - 1) * 21, 14, col)
    next

    // Piece showcase
    showY = 530
    totalW = 7 * 90
    startX = floor((SCREEN_W - totalW) / 2)
    for p = 1 to 7
        cr = pieceColors[p][1]
        cg = pieceColors[p][2]
        cb = pieceColors[p][3]
        blocks = pieceData[p][1]
        for i = 1 to 4
            bx = startX + (p - 1) * 90 + (blocks[i][2] - 1) * 16
            by = showY + (blocks[i][1] - 1) * 16
            DrawRectangle(bx, by, 14, 14, RAYLIBColor(cr, cg, cb, 255))
        next
    next

    if floor(animTime * 2) % 2 = 0
        st = "Press ENTER or SPACE to Start"
        stw = MeasureText(st, 26)
        DrawText(st, floor((SCREEN_W - stw) / 2), 590, 26,
                 RAYLIBColor(255, 255, 255, 255))
    ok

    cr = "Developed using Ring Language + RingRayLib"
    crw = MeasureText(cr, 14)
    DrawText(cr, floor((SCREEN_W - crw) / 2), SCREEN_H - 35, 14,
             RAYLIBColor(60, 70, 50, 180))

// =============================================================
// Pause Overlay
// =============================================================

func tet_drawPauseOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 160))

    pText = "PAUSED"
    tw = MeasureText(pText, 56)
    DrawText(pText, floor((SCREEN_W - tw) / 2), floor(SCREEN_H / 2) - 50, 56,
             RAYLIBColor(200, 220, 255, 255))

    hint = "Press P or SPACE to Resume"
    hw = MeasureText(hint, 20)
    DrawText(hint, floor((SCREEN_W - hw) / 2), floor(SCREEN_H / 2) + 20, 20,
             RAYLIBColor(160, 180, 200, 220))

// =============================================================
// Game Over Overlay
// =============================================================

func tet_drawGameOverOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 170))

    goText = "GAME OVER"
    tw = MeasureText(goText, 56)
    tx = floor((SCREEN_W - tw) / 2)
    DrawText(goText, tx + 3, 203, 56, RAYLIBColor(0, 0, 0, 130))
    DrawText(goText, tx, 200, 56, RAYLIBColor(255, 60, 40, 255))

    sText = "Score: " + string(score)
    sw = MeasureText(sText, 28)
    DrawText(sText, floor((SCREEN_W - sw) / 2), 275, 28,
             RAYLIBColor(255, 255, 100, 255))

    lText = "Level: " + string(level) + "  |  Lines: " + string(totalLines)
    lw = MeasureText(lText, 20)
    DrawText(lText, floor((SCREEN_W - lw) / 2), 315, 20,
             RAYLIBColor(200, 200, 220, 240))

    // Rating
    rating = "* "
    if score >= 5000 rating = "* * " ok
    if score >= 15000 rating = "* * * " ok
    rw = MeasureText(rating, 36)
    DrawText(rating, floor((SCREEN_W - rw) / 2), 350, 36,
             RAYLIBColor(255, 220, 50, 255))

    hint = "Press ENTER or SPACE to Play Again"
    hw = MeasureText(hint, 20)
    DrawText(hint, floor((SCREEN_W - hw) / 2), 400, 20,
             RAYLIBColor(180, 190, 210, 220))
