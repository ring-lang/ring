/*
**  3D Minesweeper Game - Using RingRayLib
**  ========================================
**  Classic Minesweeper in stunning 3D! Reveal cells, flag mines,
**  and clear the board without triggering any explosions!
**
**  Controls:
**    Arrow Keys / WASD  - Move cursor on the grid
**    ENTER / SPACE      - Reveal cell under cursor
**    F / Right Click    - Toggle flag on cell
**    Mouse Left Click   - Reveal cell
**    Mouse Right Click  - Toggle flag
**    C                  - Cycle camera views
**    R                  - Restart (same difficulty)
**    1                  - Easy   (9x9, 10 mines)
**    2                  - Medium (12x12, 25 mines)
**    3                  - Hard   (16x16, 50 mines)
**    ESC                - Exit
**
**  Features:
**    - Full 3D rendered grid with raised hidden cells
**    - Smooth reveal animation (cells sink to reveal content)
**    - Flag planting with 3D flag model
**    - Numbered cells with colored 3D numbers
**    - Mine explosion chain animation on game over
**    - Three difficulty levels
**    - Three camera modes
**    - Timer and mine counter
**    - First click is always safe (mines placed after)
**    - Flood-fill auto-reveal for empty cells
**    - Mini-map overlay
**    - Particle effects
**    - Mouse + keyboard support
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W        = 1024
SCREEN_H        = 768
CELL_SZ         = 1.3
CELL_H          = 0.5        // Height of hidden cell block
CELL_PAD        = 0.06

// Cell states (what's underneath)
MINE            = -1

// Cell visibility
VIS_HIDDEN      = 0
VIS_REVEALED    = 1
VIS_FLAGGED     = 2

// Game states
ST_START        = 1
ST_PLAYING      = 2
ST_WON          = 3
ST_LOST         = 4

// Camera modes
CAM_ANGLE       = 1
CAM_ISOMETRIC   = 2
CAM_OVERHEAD    = 3
CAM_COUNT       = 3

// Difficulty presets
DIFF_EASY       = 1
DIFF_MEDIUM     = 2
DIFF_HARD       = 3

// =============================================================
// Global Variables
// =============================================================

// Grid data
gridRows        = 9
gridCols        = 9
mineCount       = 10
grid            = []        // Cell values: -1=mine, 0-8=adjacent mine count
visible         = []        // VIS_HIDDEN, VIS_REVEALED, VIS_FLAGGED
revealAnim      = []        // Animation progress (0=hidden, 1=fully revealed)
revealDelay     = []        // Delay before animation starts (for cascade effect)

// Game state
gameState       = ST_START
difficulty      = DIFF_EASY
firstClick      = true
flagsPlaced     = 0
cellsRevealed   = 0
totalSafe       = 0
animTime        = 0.0

// Timer
gameTimer       = 0.0
timerRunning    = false

// Cursor
cursorR         = 1
cursorC         = 1

// Camera
cameraMode      = CAM_ANGLE
camPosX = 0.0   camPosY = 14.0  camPosZ = 14.0
camTgtX = 0.0   camTgtY = 0.0   camTgtZ = 0.0

// Mouse
mouseHoverR     = 0
mouseHoverC     = 0
projScreenX     = 0.0
projScreenY     = 0.0

// Explosion animation
explodeList     = []    // [[r, c, delay, progress], ...]
explodeActive   = false
explodeTimer    = 0.0

// Particles
particles       = []

// Number colors for 1-8
numColors       = []

// =============================================================
// Initialize
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Ring 3D Minesweeper - RingRayLib")
SetTargetFPS(60)

// Number colors: 1=blue, 2=green, 3=red, 4=darkblue, 5=maroon, 6=teal, 7=black, 8=gray
numColors = [
    [40, 80, 255],
    [40, 180, 40],
    [230, 40, 40],
    [20, 20, 140],
    [140, 30, 30],
    [30, 140, 140],
    [40, 40, 40],
    [130, 130, 130]
]

ms_resetGame()

// =============================================================
// Main Game Loop
// =============================================================

while !WindowShouldClose()

    dt = GetFrameTime()
    animTime += dt

    // --- Global input ---
    if IsKeyPressed(KEY_C)
        cameraMode += 1
        if cameraMode > CAM_COUNT cameraMode = CAM_ANGLE ok
    ok

    if IsKeyPressed(KEY_R)
        ms_resetGame()
        gameState = ST_PLAYING
    ok

    if IsKeyPressed(KEY_ONE)
        difficulty = DIFF_EASY
        ms_resetGame()
        gameState = ST_PLAYING
    ok
    if IsKeyPressed(KEY_TWO)
        difficulty = DIFF_MEDIUM
        ms_resetGame()
        gameState = ST_PLAYING
    ok
    if IsKeyPressed(KEY_THREE)
        difficulty = DIFF_HARD
        ms_resetGame()
        gameState = ST_PLAYING
    ok

    // --- State updates ---
    if gameState = ST_START
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(0)
            ms_resetGame()
            gameState = ST_PLAYING
        ok
        if IsKeyPressed(KEY_ONE)
            difficulty = DIFF_EASY
            ms_resetGame()
            gameState = ST_PLAYING
        ok
        if IsKeyPressed(KEY_TWO)
            difficulty = DIFF_MEDIUM
            ms_resetGame()
            gameState = ST_PLAYING
        ok
        if IsKeyPressed(KEY_THREE)
            difficulty = DIFF_HARD
            ms_resetGame()
            gameState = ST_PLAYING
        ok
    ok

    if gameState = ST_PLAYING
        if timerRunning
            gameTimer += dt
        ok
        ms_updateMouseHover()
        ms_handleInput()
        ms_handleMouse()
    ok

    if gameState = ST_WON
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(0)
            ms_resetGame()
            gameState = ST_PLAYING
        ok
    ok

    if gameState = ST_LOST
        if !explodeActive
            if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(0)
                ms_resetGame()
                gameState = ST_PLAYING
            ok
        ok
    ok

    ms_updateRevealAnims(dt)
    ms_updateExplosion(dt)
    ms_updateParticles(dt)
    ms_positionCamera()

    // --- Drawing ---
    BeginDrawing()
        ClearBackground(RAYLIBColor(22, 26, 34, 255))

        if gameState = ST_START
            ms_drawTitleScreen()
        else
            BeginMode3D(
                Camera3D(
                    camPosX, camPosY, camPosZ,
                    camTgtX, camTgtY, camTgtZ,
                    0, 1, 0, 45.0, 0
                )
            )
                ms_drawGrid3D()
                ms_drawCursor3D()
                ms_drawExplosions3D()
                ms_drawParticles3D()
            EndMode3D()

            ms_drawHUD()
            ms_drawMiniMap()

            if gameState = ST_WON
                ms_drawWinOverlay()
            ok
            if gameState = ST_LOST
                ms_drawLoseOverlay()
            ok
        ok

        DrawFPS(10, 10)
    EndDrawing()

end

CloseWindow()

// =============================================================
// Reset Game
// =============================================================

func ms_resetGame
    if difficulty = DIFF_EASY
        gridRows = 9
        gridCols = 9
        mineCount = 10
    ok
    if difficulty = DIFF_MEDIUM
        gridRows = 12
        gridCols = 12
        mineCount = 25
    ok
    if difficulty = DIFF_HARD
        gridRows = 16
        gridCols = 16
        mineCount = 50
    ok

    totalSafe = gridRows * gridCols - mineCount

    grid = list(gridRows)
    visible = list(gridRows)
    revealAnim = list(gridRows)
    revealDelay = list(gridRows)
    for r = 1 to gridRows
        grid[r] = list(gridCols)
        visible[r] = list(gridCols)
        revealAnim[r] = list(gridCols)
        revealDelay[r] = list(gridCols)
        for c = 1 to gridCols
            grid[r][c] = 0
            visible[r][c] = VIS_HIDDEN
            revealAnim[r][c] = 0.0
            revealDelay[r][c] = 0.0
        next
    next

    firstClick = true
    flagsPlaced = 0
    cellsRevealed = 0
    gameTimer = 0.0
    timerRunning = false
    explodeList = []
    explodeActive = false
    explodeTimer = 0.0
    particles = []
    cursorR = floor(gridRows / 2) + 1
    cursorC = floor(gridCols / 2) + 1

// =============================================================
// Mine Placement (after first click)
// =============================================================

func ms_placeMines safeR, safeC
    placed = 0
    while placed < mineCount
        r = GetRandomValue(1, gridRows)
        c = GetRandomValue(1, gridCols)

        // Keep safe zone around first click
        dr = r - safeR
        dc = c - safeC
        if dr < 0 dr = -dr ok
        if dc < 0 dc = -dc ok
        if dr <= 1 and dc <= 1 loop ok    // 3x3 safe zone

        if grid[r][c] != MINE
            grid[r][c] = MINE
            placed += 1
        ok
    end

    // Calculate adjacency numbers
    for r = 1 to gridRows
        for c = 1 to gridCols
            if grid[r][c] = MINE loop ok
            count = 0
            for dr = -1 to 1
                for dc = -1 to 1
                    if dr = 0 and dc = 0 loop ok
                    nr = r + dr
                    nc = c + dc
                    if nr >= 1 and nr <= gridRows and nc >= 1 and nc <= gridCols
                        if grid[nr][nc] = MINE
                            count += 1
                        ok
                    ok
                next
            next
            grid[r][c] = count
        next
    next

// =============================================================
// Reveal Logic
// =============================================================

func ms_revealCell r, c
    if r < 1 or r > gridRows or c < 1 or c > gridCols return ok
    if visible[r][c] != VIS_HIDDEN return ok

    // First click: place mines
    if firstClick
        ms_placeMines(r, c)
        firstClick = false
        timerRunning = true
    ok

    // Reveal this cell
    visible[r][c] = VIS_REVEALED
    cellsRevealed += 1

    // Calculate cascade delay based on distance from click
    revealDelay[r][c] = 0.0

    // Hit a mine?
    if grid[r][c] = MINE
        ms_triggerExplosion(r, c)
        return
    ok

    // Spawn small particles
    ms_spawnRevealParticles(r, c)

    // If empty cell (0), flood fill reveal neighbors
    if grid[r][c] = 0
        ms_floodReveal(r, c, 0.0)
    ok

    // Check win
    if cellsRevealed >= totalSafe
        gameState = ST_WON
        timerRunning = false
        ms_spawnWinParticles()
    ok

func ms_floodReveal r, c, baseDelay
    for dr = -1 to 1
        for dc = -1 to 1
            if dr = 0 and dc = 0 loop ok
            nr = r + dr
            nc = c + dc
            if nr >= 1 and nr <= gridRows and nc >= 1 and nc <= gridCols
                if visible[nr][nc] = VIS_HIDDEN
                    visible[nr][nc] = VIS_REVEALED
                    cellsRevealed += 1

                    // Cascade delay for visual effect
                    dist = sqrt((nr - r) * (nr - r) + (nc - c) * (nc - c))
                    revealDelay[nr][nc] = baseDelay + dist * 0.04

                    // If also empty, continue flood
                    if grid[nr][nc] = 0
                        ms_floodReveal(nr, nc, baseDelay + 0.06)
                    ok
                ok
            ok
        next
    next

// =============================================================
// Flag Logic
// =============================================================

func ms_toggleFlag r, c
    if r < 1 or r > gridRows or c < 1 or c > gridCols return ok
    if visible[r][c] = VIS_REVEALED return ok

    if visible[r][c] = VIS_FLAGGED
        visible[r][c] = VIS_HIDDEN
        flagsPlaced -= 1
    else
        visible[r][c] = VIS_FLAGGED
        flagsPlaced += 1
    ok

// =============================================================
// Explosion (Game Over)
// =============================================================

func ms_triggerExplosion hitR, hitC
    gameState = ST_LOST
    timerRunning = false
    explodeActive = true
    explodeTimer = 0.0
    explodeList = []

    // Reveal all mines and queue explosions
    for r = 1 to gridRows
        for c = 1 to gridCols
            if grid[r][c] = MINE
                visible[r][c] = VIS_REVEALED
                revealAnim[r][c] = 1.0
                revealDelay[r][c] = 0.0
                dist = sqrt((r - hitR) * (r - hitR) + (c - hitC) * (c - hitC))
                delay = dist * 0.12
                if r = hitR and c = hitC delay = 0.0 ok
                add(explodeList, [r, c, delay, 0.0])
            ok
        next
    next

    // Also reveal wrongly flagged cells
    for r = 1 to gridRows
        for c = 1 to gridCols
            if visible[r][c] = VIS_FLAGGED and grid[r][c] != MINE
                visible[r][c] = VIS_REVEALED
                revealAnim[r][c] = 1.0
            ok
        next
    next

func ms_updateExplosion dt
    if !explodeActive return ok
    explodeTimer += dt

    allDone = true
    for i = 1 to len(explodeList)
        if explodeTimer >= explodeList[i][3]
            explodeList[i][4] += dt * 2.5
            if explodeList[i][4] < 1.0
                allDone = false
            ok
            // Spawn particles at start of explosion
            if explodeList[i][4] > 0.0 and explodeList[i][4] < dt * 3
                ms_spawnExplosionParticles(explodeList[i][1], explodeList[i][2])
            ok
        else
            allDone = false
        ok
    next

    if allDone
        explodeActive = false
    ok

// =============================================================
// Input Handling
// =============================================================

func ms_handleInput
    if IsKeyPressed(KEY_UP) or IsKeyPressed(KEY_W)
        cursorR -= 1
        if cursorR < 1 cursorR = 1 ok
    ok
    if IsKeyPressed(KEY_DOWN) or IsKeyPressed(KEY_S)
        cursorR += 1
        if cursorR > gridRows cursorR = gridRows ok
    ok
    if IsKeyPressed(KEY_LEFT) or IsKeyPressed(KEY_A)
        cursorC -= 1
        if cursorC < 1 cursorC = 1 ok
    ok
    if IsKeyPressed(KEY_RIGHT) or IsKeyPressed(KEY_D)
        cursorC += 1
        if cursorC > gridCols cursorC = gridCols ok
    ok

    if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
        ms_revealCell(cursorR, cursorC)
    ok

    if IsKeyPressed(KEY_F)
        ms_toggleFlag(cursorR, cursorC)
    ok

// =============================================================
// Mouse Handling
// =============================================================

func ms_updateMouseHover
    mx = GetMouseX()
    my = GetMouseY()

    bestDist = 999999.0
    bestR = 0
    bestC = 0

    for r = 1 to gridRows
        for c = 1 to gridCols
            wx = ms_cellToX(c)
            wz = ms_cellToZ(r)
            ms_projectToScreen(wx, 0.1, wz)
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

    if bestDist < 2500 and bestR >= 1 and bestR <= gridRows
        mouseHoverR = bestR
        mouseHoverC = bestC
        cursorR = bestR
        cursorC = bestC
    else
        mouseHoverR = 0
        mouseHoverC = 0
    ok

func ms_handleMouse
    if IsMouseButtonPressed(0)
        if mouseHoverR >= 1 and mouseHoverR <= gridRows and
           mouseHoverC >= 1 and mouseHoverC <= gridCols
            ms_revealCell(mouseHoverR, mouseHoverC)
        ok
    ok
    if IsMouseButtonPressed(1)
        if mouseHoverR >= 1 and mouseHoverR <= gridRows and
           mouseHoverC >= 1 and mouseHoverC <= gridCols
            ms_toggleFlag(mouseHoverR, mouseHoverC)
        ok
    ok

// =============================================================
// Animation Updates
// =============================================================

func ms_updateRevealAnims dt
    for r = 1 to gridRows
        for c = 1 to gridCols
            if visible[r][c] = VIS_REVEALED
                if revealDelay[r][c] > 0.0
                    revealDelay[r][c] -= dt
                else
                    if revealAnim[r][c] < 1.0
                        revealAnim[r][c] += dt * 5.0
                        if revealAnim[r][c] > 1.0
                            revealAnim[r][c] = 1.0
                        ok
                    ok
                ok
            ok
        next
    next

// =============================================================
// Coordinate Helpers
// =============================================================

func ms_cellToX c
    return (c - 1) * CELL_SZ - (gridCols - 1) * CELL_SZ / 2

func ms_cellToZ r
    return (r - 1) * CELL_SZ - (gridRows - 1) * CELL_SZ / 2

// =============================================================
// Manual 3D to Screen Projection
// =============================================================

func ms_projectToScreen wx, wy, wz
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

func ms_spawnRevealParticles r, c
    wx = ms_cellToX(c)
    wz = ms_cellToZ(r)
    for i = 1 to 5
        vx = (GetRandomValue(-100, 100) / 100.0) * 0.8
        vy = (GetRandomValue(80, 250) / 100.0) * 0.6
        vz = (GetRandomValue(-100, 100) / 100.0) * 0.8
        add(particles, [wx, 0.3, wz, vx, vy, vz, 0.7,
                        140, 160, 180])
    next

func ms_spawnExplosionParticles r, c
    wx = ms_cellToX(c)
    wz = ms_cellToZ(r)
    for i = 1 to 12
        vx = (GetRandomValue(-100, 100) / 100.0) * 2.5
        vy = (GetRandomValue(150, 450) / 100.0) * 2.0
        vz = (GetRandomValue(-100, 100) / 100.0) * 2.5
        cr = 255
        cg = GetRandomValue(60, 200)
        cb = GetRandomValue(0, 40)
        add(particles, [wx, 0.4, wz, vx, vy, vz, 1.5, cr, cg, cb])
    next

func ms_spawnWinParticles
    for i = 1 to 50
        wx = (GetRandomValue(-50, 50) / 10.0)
        wz = (GetRandomValue(-50, 50) / 10.0)
        vx = (GetRandomValue(-100, 100) / 100.0) * 1.5
        vy = (GetRandomValue(200, 500) / 100.0) * 2.0
        vz = (GetRandomValue(-100, 100) / 100.0) * 1.5
        cr = GetRandomValue(100, 255)
        cg = GetRandomValue(180, 255)
        cb = GetRandomValue(30, 100)
        add(particles, [wx, 0.5, wz, vx, vy, vz, 3.0, cr, cg, cb])
    next

func ms_updateParticles dt
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

func ms_drawParticles3D
    for i = 1 to len(particles)
        px = particles[i][1]
        py = particles[i][2]
        pz = particles[i][3]
        life = particles[i][7]
        pr = particles[i][8]
        pg = particles[i][9]
        pb = particles[i][10]
        alpha = floor(life * 200)
        if alpha > 255 alpha = 255 ok
        if alpha < 0 alpha = 0 ok
        sz = 0.05 + life * 0.04
        DrawSphere(Vector3(px, py, pz), sz,
                   RAYLIBColor(pr, pg, pb, alpha))
    next

// =============================================================
// Camera
// =============================================================

func ms_positionCamera
    boardW = gridCols * CELL_SZ
    boardH = gridRows * CELL_SZ
    maxDim = boardW
    if boardH > maxDim maxDim = boardH ok

    if cameraMode = CAM_ANGLE
        goalPX = 0.0
        goalPY = maxDim * 0.9
        goalPZ = maxDim * 1.1
        goalTX = 0.0
        goalTY = 0.0
        goalTZ = -maxDim * 0.05
    ok

    if cameraMode = CAM_ISOMETRIC
        goalPX = maxDim * 0.8
        goalPY = maxDim * 0.9
        goalPZ = maxDim * 0.8
        goalTX = 0.0
        goalTY = 0.0
        goalTZ = 0.0
    ok

    if cameraMode = CAM_OVERHEAD
        goalPX = 0.0
        goalPY = maxDim * 1.6
        goalPZ = 0.8
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
// 3D Drawing: Grid
// =============================================================

func ms_drawGrid3D
    boardW = gridCols * CELL_SZ
    boardH = gridRows * CELL_SZ

    // Base platform
    DrawCube(Vector3(0, -0.25, 0), boardW + 0.6, 0.2, boardH + 0.6,
             RAYLIBColor(50, 55, 65, 255))

    // Border frame
    bThick = 0.3
    bH = 0.3
    halfW = boardW / 2 + bThick / 2 + 0.15
    halfH = boardH / 2 + bThick / 2 + 0.15
    borderCol = RAYLIBColor(70, 75, 85, 255)

    DrawCube(Vector3(0, bH/2 - 0.15, -halfH), boardW + bThick*2 + 0.3, bH, bThick, borderCol)
    DrawCube(Vector3(0, bH/2 - 0.15, halfH), boardW + bThick*2 + 0.3, bH, bThick, borderCol)
    DrawCube(Vector3(-halfW, bH/2 - 0.15, 0), bThick, bH, boardH + 0.3, borderCol)
    DrawCube(Vector3(halfW, bH/2 - 0.15, 0), bThick, bH, boardH + 0.3, borderCol)

    // Draw each cell
    for r = 1 to gridRows
        for c = 1 to gridCols
            wx = ms_cellToX(c)
            wz = ms_cellToZ(r)
            vis = visible[r][c]
            anim = revealAnim[r][c]

            cellW = CELL_SZ - CELL_PAD * 2

            if vis = VIS_HIDDEN
                // Raised hidden cell block
                DrawCube(Vector3(wx, CELL_H / 2, wz), cellW, CELL_H, cellW,
                         RAYLIBColor(90, 100, 120, 255))
                // Slight top highlight
                DrawCube(Vector3(wx, CELL_H + 0.01, wz), cellW - 0.04, 0.02, cellW - 0.04,
                         RAYLIBColor(110, 120, 140, 255))

            ok

            if vis = VIS_FLAGGED
                // Flagged cell (still raised)
                DrawCube(Vector3(wx, CELL_H / 2, wz), cellW, CELL_H, cellW,
                         RAYLIBColor(90, 100, 120, 255))
                DrawCube(Vector3(wx, CELL_H + 0.01, wz), cellW - 0.04, 0.02, cellW - 0.04,
                         RAYLIBColor(110, 120, 140, 255))

                // 3D Flag
                ms_drawFlag(wx, wz)
            ok

            if vis = VIS_REVEALED
                // Animated reveal: cell sinks from CELL_H to flat
                h = CELL_H * (1.0 - anim)

                // Base flat cell
                val = grid[r][c]
                if val = MINE
                    baseCol = RAYLIBColor(180, 40, 30, 255)
                else
                    if (r + c) % 2 = 0
                        baseCol = RAYLIBColor(175, 185, 170, 255)
                    else
                        baseCol = RAYLIBColor(155, 165, 150, 255)
                    ok
                ok

                DrawCube(Vector3(wx, 0.03, wz), cellW, 0.06, cellW, baseCol)

                // If still sinking, draw shrinking block
                if h > 0.02
                    DrawCube(Vector3(wx, h / 2, wz), cellW * (1.0 - anim * 0.3),
                             h, cellW * (1.0 - anim * 0.3),
                             RAYLIBColor(90, 100, 120, floor(200 * (1.0 - anim))))
                ok

                // Draw cell content (number or mine) when mostly revealed
                if anim > 0.5
                    if val >= 1 and val <= 8
                        ms_drawNumber3D(wx, wz, val)
                    ok
                    if val = MINE and gameState = ST_LOST
                        ms_drawMine3D(wx, wz)
                    ok
                ok
            ok
        next
    next

// =============================================================
// 3D Drawing: Flag
// =============================================================

func ms_drawFlag wx, wz
    poleH = 0.65
    poleBase = CELL_H + 0.02

    // Pole
    DrawCylinder(Vector3(wx, poleBase, wz), 0.03, 0.03, poleH, 8,
                 RAYLIBColor(120, 90, 50, 255))

    // Flag triangle (two triangles to form a flag shape)
    flagY = poleBase + poleH
    flagW = 0.3
    flagH = 0.22

    DrawCube(Vector3(wx + flagW/2, flagY - flagH/2, wz),
             flagW, flagH, 0.03,
             RAYLIBColor(230, 50, 40, 255))

    // Flag tip
    DrawSphere(Vector3(wx, poleBase + poleH + 0.04, wz), 0.04,
               RAYLIBColor(255, 220, 40, 255))

// =============================================================
// 3D Drawing: Number on cell
// =============================================================

func ms_drawNumber3D wx, wz, val
    // Draw colored sphere with height based on number
    cr = numColors[val][1]
    cg = numColors[val][2]
    cb = numColors[val][3]

    // Number representation: stack of small cubes/spheres
    baseY = 0.12

    // Central sphere
    sz = 0.15 + val * 0.02
    DrawSphere(Vector3(wx, baseY, wz), sz,
               RAYLIBColor(cr, cg, cb, 255))

    // Surrounding dots for the count
    if val <= 4
        for i = 1 to val
            angle = (i - 1) * (360.0 / val) * 3.14159265 / 180.0
            dx = cos(angle) * 0.32
            dz = sin(angle) * 0.32
            DrawSphere(Vector3(wx + dx, 0.08, wz + dz), 0.06,
                       RAYLIBColor(cr, cg, cb, 200))
        next
    else
        for i = 1 to val
            angle = (i - 1) * (360.0 / val) * 3.14159265 / 180.0
            dx = cos(angle) * 0.35
            dz = sin(angle) * 0.35
            DrawSphere(Vector3(wx + dx, 0.08, wz + dz), 0.05,
                       RAYLIBColor(cr, cg, cb, 200))
        next
    ok

    // Glow
    DrawSphere(Vector3(wx, baseY, wz), sz + 0.06,
               RAYLIBColor(cr, cg, cb, 35))

// =============================================================
// 3D Drawing: Mine
// =============================================================

func ms_drawMine3D wx, wz
    baseY = 0.15

    // Central black sphere
    DrawSphere(Vector3(wx, baseY, wz), 0.22,
               RAYLIBColor(30, 25, 20, 255))

    // Spikes (6 directions)
    spikeLen = 0.18
    for i = 0 to 5
        angle = i * 60.0 * 3.14159265 / 180.0
        dx = cos(angle) * spikeLen
        dz = sin(angle) * spikeLen
        DrawCylinder(Vector3(wx, baseY, wz), 0.04, 0.01, 0.22, 4,
                     RAYLIBColor(30, 25, 20, 255))
        DrawSphere(Vector3(wx + dx, baseY, wz + dz), 0.06,
                   RAYLIBColor(50, 40, 30, 255))
    next

    // Top spike
    DrawSphere(Vector3(wx, baseY + 0.22, wz), 0.06,
               RAYLIBColor(50, 40, 30, 255))

    // Red glow
    pulse = 0.7 + sin(animTime * 8.0) * 0.3
    DrawSphere(Vector3(wx, baseY, wz), 0.28 * pulse,
               RAYLIBColor(255, 40, 20, 40))

// =============================================================
// 3D Drawing: Explosions
// =============================================================

func ms_drawExplosions3D
    if !explodeActive return ok

    for i = 1 to len(explodeList)
        if explodeTimer >= explodeList[i][3]
            prog = explodeList[i][4]
            if prog > 1.0 prog = 1.0 ok
            if prog <= 0.0 loop ok

            r = explodeList[i][1]
            c = explodeList[i][2]
            wx = ms_cellToX(c)
            wz = ms_cellToZ(r)

            // Expanding fireball
            sz = prog * 0.8
            alpha = floor(255 * (1.0 - prog))
            if alpha < 0 alpha = 0 ok

            DrawSphere(Vector3(wx, 0.3 + prog * 0.5, wz), sz,
                       RAYLIBColor(255, floor(120 * (1.0 - prog)),
                                   floor(20 * (1.0 - prog)), alpha))

            // Secondary flash
            if prog < 0.4
                DrawSphere(Vector3(wx, 0.3, wz), 0.5 - prog,
                           RAYLIBColor(255, 255, 200, floor(200 * (1.0 - prog * 2.5))))
            ok
        ok
    next

// =============================================================
// 3D Drawing: Cursor
// =============================================================

func ms_drawCursor3D
    if gameState != ST_PLAYING return ok

    wx = ms_cellToX(cursorC)
    wz = ms_cellToZ(cursorR)

    pulse = 0.7 + sin(animTime * 5.0) * 0.3
    vis = visible[cursorR][cursorC]

    if vis = VIS_HIDDEN
        curCol = RAYLIBColor(80, 255, 120, floor(pulse * 180))
        cy = CELL_H + 0.03
    ok
    if vis = VIS_FLAGGED
        curCol = RAYLIBColor(255, 200, 60, floor(pulse * 180))
        cy = CELL_H + 0.03
    ok
    if vis = VIS_REVEALED
        curCol = RAYLIBColor(120, 150, 200, floor(pulse * 100))
        cy = 0.08
    ok

    // Corner brackets
    hs = CELL_SZ * 0.46
    bLen = 0.25

    DrawLine3D(Vector3(wx - hs, cy, wz - hs), Vector3(wx - hs + bLen, cy, wz - hs), curCol)
    DrawLine3D(Vector3(wx - hs, cy, wz - hs), Vector3(wx - hs, cy, wz - hs + bLen), curCol)
    DrawLine3D(Vector3(wx + hs, cy, wz - hs), Vector3(wx + hs - bLen, cy, wz - hs), curCol)
    DrawLine3D(Vector3(wx + hs, cy, wz - hs), Vector3(wx + hs, cy, wz - hs + bLen), curCol)
    DrawLine3D(Vector3(wx - hs, cy, wz + hs), Vector3(wx - hs + bLen, cy, wz + hs), curCol)
    DrawLine3D(Vector3(wx - hs, cy, wz + hs), Vector3(wx - hs, cy, wz + hs - bLen), curCol)
    DrawLine3D(Vector3(wx + hs, cy, wz + hs), Vector3(wx + hs - bLen, cy, wz + hs), curCol)
    DrawLine3D(Vector3(wx + hs, cy, wz + hs), Vector3(wx + hs, cy, wz + hs - bLen), curCol)

// =============================================================
// HUD
// =============================================================

func ms_drawHUD
    panelW = 250
    panelH = 135
    DrawRectangle(10, 30, panelW, panelH, RAYLIBColor(0, 0, 0, 190))
    DrawRectangleLines(10, 30, panelW, panelH, RAYLIBColor(100, 120, 160, 200))

    DrawText("3D MINESWEEPER", 20, 38, 16, RAYLIBColor(100, 180, 255, 255))

    // Difficulty
    diffName = "EASY"
    if difficulty = DIFF_MEDIUM diffName = "MEDIUM" ok
    if difficulty = DIFF_HARD diffName = "HARD" ok
    DrawText(diffName + " (" + string(gridRows) + "x" + string(gridCols) + ")", 20, 58, 14,
             RAYLIBColor(180, 200, 140, 220))

    // Mine counter
    remaining = mineCount - flagsPlaced
    DrawText("Mines: " + string(remaining), 20, 78, 16,
             RAYLIBColor(255, 80, 50, 255))

    // Timer
    mins = floor(gameTimer / 60)
    secs = floor(gameTimer) % 60
    timeStr = "" + string(mins) + ":"
    if secs < 10 timeStr += "0" ok
    timeStr += string(secs)
    DrawText("Time: " + timeStr, 140, 78, 16,
             RAYLIBColor(200, 200, 100, 255))

    // Progress
    if totalSafe > 0
        pct = floor(cellsRevealed * 100.0 / totalSafe)
    else
        pct = 0
    ok
    DrawText("Revealed: " + string(pct) + "%", 20, 100, 14,
             RAYLIBColor(140, 180, 200, 200))

    // Cells remaining
    cellsLeft = totalSafe - cellsRevealed
    DrawText("Left: " + string(cellsLeft), 155, 100, 14,
             RAYLIBColor(140, 180, 200, 200))

    // Camera mode
    camName = "ANGLE"
    if cameraMode = CAM_ISOMETRIC camName = "ISOMETRIC" ok
    if cameraMode = CAM_OVERHEAD  camName = "OVERHEAD"  ok
    DrawText("Cam: " + camName + "  [C]", 20, 122, 13,
             RAYLIBColor(120, 140, 170, 180))

    // Difficulty selector
    DrawRectangle(10, SCREEN_H - 60, 300, 25, RAYLIBColor(0, 0, 0, 153))
    DrawText("[1] Easy  [2] Medium  [3] Hard  |  [R] Restart", 16, SCREEN_H - 56, 13,
             RAYLIBColor(150, 170, 200, 220))

    // Controls
    DrawRectangle(SCREEN_W - 460, SCREEN_H - 35, 450, 25, RAYLIBColor(0, 0, 0, 153))
    DrawText("LClick/Space: Reveal | RClick/F: Flag | R: Reset | C: Camera",
             SCREEN_W - 455, SCREEN_H - 30, 12, RAYLIBColor(150, 160, 180, 200))

// =============================================================
// Mini Map
// =============================================================

func ms_drawMiniMap
    maxCellW = 10
    if gridCols > 12 maxCellW = 7 ok
    if gridCols > 16 maxCellW = 5 ok
    cellW = maxCellW
    cellH = maxCellW
    mapW = gridCols * cellW
    mapH = gridRows * cellH
    mapX = SCREEN_W - mapW - 20
    mapY = 30

    DrawRectangle(mapX - 3, mapY - 3, mapW + 6, mapH + 6, RAYLIBColor(0, 0, 0, 204))
    DrawRectangleLines(mapX - 3, mapY - 3, mapW + 6, mapH + 6,
                       RAYLIBColor(100, 120, 160, 200))

    for r = 1 to gridRows
        for c = 1 to gridCols
            sx = mapX + (c - 1) * cellW
            sy = mapY + (r - 1) * cellH
            vis = visible[r][c]

            if vis = VIS_HIDDEN
                DrawRectangle(sx, sy, cellW - 1, cellH - 1,
                              RAYLIBColor(80, 90, 110, 220))
            ok
            if vis = VIS_FLAGGED
                DrawRectangle(sx, sy, cellW - 1, cellH - 1,
                              RAYLIBColor(230, 60, 40, 220))
            ok
            if vis = VIS_REVEALED
                val = grid[r][c]
                if val = MINE
                    DrawRectangle(sx, sy, cellW - 1, cellH - 1,
                                  RAYLIBColor(180, 30, 20, 220))
                else
                    if val = 0
                        DrawRectangle(sx, sy, cellW - 1, cellH - 1,
                                      RAYLIBColor(160, 170, 155, 220))
                    else
                        cr = numColors[val][1]
                        cg = numColors[val][2]
                        cb = numColors[val][3]
                        DrawRectangle(sx, sy, cellW - 1, cellH - 1,
                                      RAYLIBColor(cr, cg, cb, 180))
                    ok
                ok
            ok
        next
    next

    // Cursor
    cx = mapX + (cursorC - 1) * cellW
    cy = mapY + (cursorR - 1) * cellH
    DrawRectangleLines(cx, cy, cellW, cellH, RAYLIBColor(255, 255, 100, 220))

    DrawText("MAP", mapX + floor(mapW / 2) - 15, mapY - 16, 12,
             RAYLIBColor(100, 130, 180, 200))

// =============================================================
// Title Screen
// =============================================================

func ms_drawTitleScreen
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(22, 26, 34, 255))

    t1 = "3D MINESWEEPER"
    t1w = MeasureText(t1, 46)
    t1x = floor((SCREEN_W - t1w) / 2)
    DrawText(t1, t1x + 3, 43, 46, RAYLIBColor(30, 50, 80, 200))
    DrawText(t1, t1x, 40, 46, RAYLIBColor(100, 180, 255, 255))

    t2 = "~ Classic puzzle game in full 3D! ~"
    t2w = MeasureText(t2, 16)
    DrawText(t2, floor((SCREEN_W - t2w) / 2), 95, 16, RAYLIBColor(140, 160, 120, 220))

    cy = 130
    cLines = [
        "Left Click / SPACE     -   Reveal cell",
        "Right Click / F        -   Toggle flag",
        "Arrow Keys / WASD      -   Move cursor",
        "R                      -   Restart game",
        "C                      -   Cycle camera view",
        "",
        "Rules:",
        "  Click cells to reveal what is underneath",
        "  Numbers show how many adjacent mines exist",
        "  Flag cells you think contain mines",
        "  Reveal all safe cells to WIN!",
        "  Click a mine and it is GAME OVER!"
    ]
    for i = 1 to len(cLines)
        lw = MeasureText(cLines[i], 14)
        if i >= 7
            col = RAYLIBColor(255, 200, 100, 210)
        else
            col = RAYLIBColor(150, 170, 200, 230)
        ok
        DrawText(cLines[i], floor((SCREEN_W - lw) / 2), cy + (i - 1) * 22, 14, col)
    next

    // Difficulty selection box
    boxW = 420
    boxH = 90
    boxX = floor((SCREEN_W - boxW) / 2)
    boxY = 405
    DrawRectangle(boxX, boxY, boxW, boxH, RAYLIBColor(30, 40, 60, 220))
    DrawRectangleLines(boxX, boxY, boxW, boxH, RAYLIBColor(100, 150, 255, 180))

    dTitle = "SELECT DIFFICULTY:"
    dtw = MeasureText(dTitle, 16)
    DrawText(dTitle, floor((SCREEN_W - dtw) / 2), boxY + 10, 16, RAYLIBColor(100, 180, 255, 255))

    easyCol = RAYLIBColor(120, 130, 150, 200)
    medCol  = RAYLIBColor(120, 130, 150, 200)
    hardCol = RAYLIBColor(120, 130, 150, 200)
    if difficulty = DIFF_EASY   easyCol = RAYLIBColor(80, 255, 80, 255) ok
    if difficulty = DIFF_MEDIUM medCol  = RAYLIBColor(255, 220, 50, 255) ok
    if difficulty = DIFF_HARD   hardCol = RAYLIBColor(255, 80, 50, 255) ok

    opt1 = "[1] Easy 9x9"
    opt2 = "[2] Medium 12x12"
    opt3 = "[3] Hard 16x16"
    o1w = MeasureText(opt1, 17)
    DrawText(opt1, boxX + 25, boxY + 40, 17, easyCol)
    DrawText(opt2, boxX + 25 + o1w + 20, boxY + 40, 17, medCol)
    o2w = MeasureText(opt2, 17)
    DrawText(opt3, boxX + 25 + o1w + 20 + o2w + 20, boxY + 40, 17, hardCol)

    // Mines info
    mineInfo = "10 mines"
    if difficulty = DIFF_MEDIUM mineInfo = "25 mines" ok
    if difficulty = DIFF_HARD   mineInfo = "50 mines" ok
    miw = MeasureText(mineInfo, 14)
    DrawText(mineInfo, floor((SCREEN_W - miw) / 2), boxY + 68, 14,
             RAYLIBColor(180, 160, 120, 200))

    if floor(animTime * 2) % 2 = 0
        st = "Click or Press ENTER / SPACE to Start"
        stw = MeasureText(st, 24)
        DrawText(st, floor((SCREEN_W - stw) / 2), 520, 24,
                 RAYLIBColor(255, 255, 255, 255))
    ok

    cr = "Developed using Ring Language + RingRayLib"
    crw = MeasureText(cr, 14)
    DrawText(cr, floor((SCREEN_W - crw) / 2), SCREEN_H - 35, 14,
             RAYLIBColor(60, 70, 50, 180))

// =============================================================
// Win Overlay
// =============================================================

func ms_drawWinOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 150))

    wText = "YOU WIN!"
    tw = MeasureText(wText, 60)
    tx = floor((SCREEN_W - tw) / 2)
    DrawText(wText, tx + 3, 223, 60, RAYLIBColor(0, 0, 0, 130))
    DrawText(wText, tx, 220, 60, RAYLIBColor(80, 255, 120, 255))

    // Time
    mins = floor(gameTimer / 60)
    secs = floor(gameTimer) % 60
    timeStr = "Time: " + string(mins) + ":"
    if secs < 10 timeStr += "0" ok
    timeStr += string(secs)
    ttw = MeasureText(timeStr, 24)
    DrawText(timeStr, floor((SCREEN_W - ttw) / 2), 295, 24,
             RAYLIBColor(200, 220, 100, 240))

    // Rating
    rating = "* "
    if gameTimer < 120 rating = "* * " ok
    if gameTimer < 60  rating = "* * * " ok
    rw = MeasureText(rating, 40)
    DrawText(rating, floor((SCREEN_W - rw) / 2), 335, 40,
             RAYLIBColor(255, 220, 50, 255))

    hint = "Click or Press ENTER to Play Again"
    hw = MeasureText(hint, 20)
    DrawText(hint, floor((SCREEN_W - hw) / 2), 395, 20,
             RAYLIBColor(180, 190, 210, 220))

// =============================================================
// Lose Overlay
// =============================================================

func ms_drawLoseOverlay
    if explodeActive return ok  // Wait for explosions to finish

    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 160))

    lText = "BOOM! GAME OVER"
    tw = MeasureText(lText, 52)
    tx = floor((SCREEN_W - tw) / 2)
    DrawText(lText, tx + 3, 233, 52, RAYLIBColor(0, 0, 0, 130))
    DrawText(lText, tx, 230, 52, RAYLIBColor(255, 60, 40, 255))

    // Stats
    pct = 0
    if totalSafe > 0
        pct = floor(cellsRevealed * 100.0 / totalSafe)
    ok
    stat = "Revealed: " + string(pct) + "% of safe cells"
    stw = MeasureText(stat, 20)
    DrawText(stat, floor((SCREEN_W - stw) / 2), 300, 20,
             RAYLIBColor(200, 200, 220, 230))

    // Time
    mins = floor(gameTimer / 60)
    secs = floor(gameTimer) % 60
    timeStr = "Time: " + string(mins) + ":"
    if secs < 10 timeStr += "0" ok
    timeStr += string(secs)
    ttw = MeasureText(timeStr, 20)
    DrawText(timeStr, floor((SCREEN_W - ttw) / 2), 330, 20,
             RAYLIBColor(200, 180, 100, 220))

    hint = "Click or Press ENTER to Try Again"
    hw = MeasureText(hint, 20)
    DrawText(hint, floor((SCREEN_W - hw) / 2), 380, 20,
             RAYLIBColor(180, 190, 210, 220))
