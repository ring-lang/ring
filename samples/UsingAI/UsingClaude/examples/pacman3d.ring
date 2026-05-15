/*
**  3D Pac-Man Game - Using RingRayLib
**  ======================================
**  Classic Pac-Man in full 3D! Navigate the maze, eat all pellets,
**  avoid ghosts, and grab power pellets to turn the tables!
**
**  Controls:
**    Arrow Keys / WASD  -   Move Pac-Man
**    C                  -   Cycle camera views
**    P                  -   Pause / Unpause
**    R                  -   Restart game
**    ESC                -   Exit
**
**  Rules:
**    - Eat all pellets to clear the level
**    - Avoid ghosts or lose a life!
**    - Eat a Power Pellet to turn ghosts blue (vulnerable)
**    - Eat blue ghosts for bonus points
**    - 3 lives to start
**
**  Features:
**    - Classic maze layout in 3D
**    - 4 ghosts with unique chase behaviors
**    - Power pellets with ghost frightened mode
**    - Smooth movement and mouth animation
**    - Tunnel wrap-around
**    - Three camera modes
**    - Score, lives, level display
**    - Particle effects
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W        = 1024
SCREEN_H        = 768

// Maze dimensions (classic-inspired)
MAZE_W          = 21     // columns (odd for symmetry)
MAZE_H          = 21     // rows
CELL_SZ         = 1.0    // 3D cell size

// Cell types
C_WALL          = 1
C_EMPTY         = 0
C_PELLET        = 2
C_POWER         = 3
C_DOOR          = 4      // Ghost house door

// Directions
DIR_NONE        = 0
DIR_UP          = 1
DIR_DOWN        = 2
DIR_LEFT        = 3
DIR_RIGHT       = 4

// Game states
ST_START        = 1
ST_PLAYING      = 2
ST_PAUSED       = 3
ST_DYING        = 4
ST_GAMEOVER     = 5
ST_LEVELUP      = 6
ST_READY        = 7

// Ghost states
GH_CHASE        = 1
GH_FRIGHTENED   = 2
GH_EATEN        = 3
GH_HOME         = 4

// Camera modes
CAM_TOP         = 1
CAM_ANGLE       = 2
CAM_FOLLOW      = 3
CAM_COUNT       = 3

// Ghost indices
GH_RED          = 1
GH_PINK         = 2
GH_CYAN         = 3
GH_ORANGE       = 4
NUM_GHOSTS      = 4

// =============================================================
// Global Variables
// =============================================================

// Maze grid
maze            = []

// Pac-Man
pmRow           = 0.0     // Float for smooth movement
pmCol           = 0.0
pmDir           = DIR_NONE
pmNextDir       = DIR_NONE
pmSpeed         = 4.5
pmMouthAngle    = 0.0     // For mouth animation
pmMouthOpen     = true

// Ghost data: [row, col, dir, state, homeTimer, targetR, targetC, startDelay]
ghosts          = []
ghostColors     = []
frightTimer     = 0.0
frightDuration  = 7.0
ghostEatCount   = 0       // Combo counter for eating ghosts
ghostLastR      = [0,0,0,0]   // Last grid row where direction was chosen
ghostLastC      = [0,0,0,0]   // Last grid col where direction was chosen

// Ghost home position
ghostHomeR      = 10
ghostHomeC      = 11

// Game state
gameState       = ST_START
animTime        = 0.0
score           = 0
lives           = 3
level           = 1
pelletsLeft     = 0
totalPellets    = 0
readyTimer      = 0.0
dyingTimer      = 0.0
levelUpTimer    = 0.0

// Camera
cameraMode      = CAM_TOP
camPosX = 0.0   camPosY = 25.0  camPosZ = 5.0
camTgtX = 0.0   camTgtY = 0.0   camTgtZ = 0.0

// Particles
particles       = []

// Score popup
popups          = []     // [[x, y, z, text, timer], ...]

// =============================================================
// Initialize
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Ring 3D Pac-Man - RingRayLib")
toggleFullScreen()
SetTargetFPS(60)

ghostColors = [
    [255, 0, 0],        // Red (Blinky)
    [255, 184, 222],    // Pink (Pinky)
    [0, 255, 255],      // Cyan (Inky)
    [255, 184, 82]      // Orange (Clyde)
]

pac_buildMaze()
pac_resetLevel()

// =============================================================
// Main Game Loop
// =============================================================

while !WindowShouldClose()

    dt = GetFrameTime()
    if dt > 0.05 dt = 0.05 ok   // Cap delta time
    animTime += dt

    // --- Global input ---
    if IsKeyPressed(KEY_C)
        cameraMode += 1
        if cameraMode > CAM_COUNT cameraMode = CAM_TOP ok
    ok

    if IsKeyPressed(KEY_R)
        score = 0
        lives = 3
        level = 1
        pac_buildMaze()
        pac_resetLevel()
        gameState = ST_READY
        readyTimer = 2.0
    ok

    // --- State updates ---
    if gameState = ST_START
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            score = 0
            lives = 3
            level = 1
            pac_buildMaze()
            pac_resetLevel()
            gameState = ST_READY
            readyTimer = 2.0
        ok
    but gameState = ST_READY
        readyTimer -= dt
        if readyTimer <= 0
            gameState = ST_PLAYING
        ok
    but gameState = ST_PLAYING
        if IsKeyPressed(KEY_P)
            gameState = ST_PAUSED
        else
            pac_handleInput()
            pac_movePacman(dt)
            pac_moveGhosts(dt)
            pac_checkCollisions()
            pac_updateFrightened(dt)
        ok
    but gameState = ST_PAUSED
        if IsKeyPressed(KEY_P) or IsKeyPressed(KEY_SPACE)
            gameState = ST_PLAYING
        ok
    but gameState = ST_DYING
        dyingTimer -= dt
        if dyingTimer <= 0
            lives -= 1
            if lives <= 0
                gameState = ST_GAMEOVER
            else
                pac_resetPositions()
                gameState = ST_READY
                readyTimer = 2.0
            ok
        ok
    but gameState = ST_LEVELUP
        levelUpTimer -= dt
        if levelUpTimer <= 0
            level += 1
            pac_buildMaze()
            pac_resetLevel()
            gameState = ST_READY
            readyTimer = 2.0
        ok
    but gameState = ST_GAMEOVER
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            score = 0
            lives = 3
            level = 1
            pac_buildMaze()
            pac_resetLevel()
            gameState = ST_READY
            readyTimer = 2.0
        ok
    ok

    pac_updateParticles(dt)
    pac_updatePopups(dt)
    pac_positionCamera()

    // --- Drawing ---
    BeginDrawing()
        ClearBackground(RAYLIBColor(5, 5, 15, 255))

        if gameState = ST_START
            pac_drawTitleScreen()
        else
            BeginMode3D(
                Camera3D(
                    camPosX, camPosY, camPosZ,
                    camTgtX, camTgtY, camTgtZ,
                    0, 1, 0, 45.0, 0
                )
            )
                pac_drawMaze3D()
                pac_drawPellets3D()
                pac_drawPacman3D()
                pac_drawGhosts3D()
                pac_drawParticles3D()
            EndMode3D()

            pac_drawHUD()
            pac_drawPopups2D()

            if gameState = ST_READY
                pac_drawReadyOverlay()
            ok
            if gameState = ST_PAUSED
                pac_drawPauseOverlay()
            ok
            if gameState = ST_GAMEOVER
                pac_drawGameOverOverlay()
            ok
            if gameState = ST_LEVELUP
                pac_drawLevelUpOverlay()
            ok
        ok

        DrawFPS(10, 10)
    EndDrawing()

end

CloseWindow()

// =============================================================
// Maze Building
// =============================================================

func pac_buildMaze
    // Classic Pac-Man inspired maze (21 x 21)
    // 1=wall, 0=empty(pellet), 3=power pellet, 4=ghost door
    // Ghost house: rows 10-12, cols 9-13 have open interior

    maze = [
        [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1],
        [1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1],
        [1,0,1,1,0,1,1,1,0,0,1,0,0,1,1,1,0,1,1,0,1],
        [1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1],
        [1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1],
        [1,0,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,0,1],
        [1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1],
        [1,1,1,1,0,1,1,1,0,0,0,0,0,1,1,1,0,1,1,1,1],
        [1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1],
        [0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0],
        [1,1,1,1,0,1,0,1,1,4,4,4,1,1,0,1,0,1,1,1,1],
        [1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,1,1],
        [1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1],
        [1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1],
        [0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0],
        [1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1],
        [1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1],
        [1,0,1,1,0,1,1,1,0,0,1,0,0,1,1,1,0,1,1,0,1],
        [1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1],
        [1,0,0,0,0,1,0,1,1,1,1,1,1,1,0,1,0,0,0,0,1],
        [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
    ]

    // Count pellets
    pelletsLeft = 0
    for r = 1 to MAZE_H
        for c = 1 to MAZE_W
            if maze[r][c] = C_EMPTY
                maze[r][c] = C_PELLET
                pelletsLeft += 1
            ok
            if maze[r][c] = C_POWER
                pelletsLeft += 1
            ok
        next
    next
    totalPellets = pelletsLeft

// =============================================================
// Reset Level / Positions
// =============================================================

func pac_resetLevel
    pac_resetPositions()
    frightTimer = 0.0
    ghostEatCount = 0

func pac_resetPositions
    // Pac-Man start position (row 19, center - open corridor)
    pmRow = 19.0
    pmCol = 11.0
    pmDir = DIR_NONE
    pmNextDir = DIR_NONE

    // Ghost start positions (in/near ghost house)
    ghosts = []
    // [row, col, dir, state, homeTimer, targetR, targetC, startDelay]
    // Row 9 col 11 = open corridor above ghost door
    // Row 12 cols 9-13 = ghost house interior (open cells)
    add(ghosts, [9.0, 11.0, DIR_LEFT, GH_CHASE, 0.0, 1, 1, 0.0])      // Red - above door
    add(ghosts, [12.0, 11.0, DIR_UP, GH_HOME, 0.0, 1, 11, 3.0])       // Pink - center
    add(ghosts, [12.0, 10.0, DIR_UP, GH_HOME, 0.0, 21, 21, 6.0])      // Cyan - left
    add(ghosts, [12.0, 12.0, DIR_UP, GH_HOME, 0.0, 21, 1, 9.0])       // Orange - right

    ghostHomeR = 12
    ghostHomeC = 11
    ghostLastR = [0,0,0,0]
    ghostLastC = [0,0,0,0]

// =============================================================
// Input
// =============================================================

func pac_handleInput
    if IsKeyDown(KEY_UP) or IsKeyDown(KEY_W)
        pmNextDir = DIR_UP
    ok
    if IsKeyDown(KEY_DOWN) or IsKeyDown(KEY_S)
        pmNextDir = DIR_DOWN
    ok
    if IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_A)
        pmNextDir = DIR_LEFT
    ok
    if IsKeyDown(KEY_RIGHT) or IsKeyDown(KEY_D)
        pmNextDir = DIR_RIGHT
    ok

// =============================================================
// Pac-Man Movement
// =============================================================

func pac_movePacman dt
    speed = pmSpeed + level * 0.15

    // Try to change direction at grid alignment
    if pac_isAligned()
        gr = pac_gridR()
        gc = pac_gridC()

        // Try queued direction first
        if pmNextDir != DIR_NONE
            nr = gr
            nc = gc
            if pmNextDir = DIR_UP    nr = gr - 1 ok
            if pmNextDir = DIR_DOWN  nr = gr + 1 ok
            if pmNextDir = DIR_LEFT  nc = gc - 1 ok
            if pmNextDir = DIR_RIGHT nc = gc + 1 ok

            // Handle tunnel wrap
            nr = pac_wrapR(nr)
            nc = pac_wrapC(nc)

            if pac_canMove(nr, nc)
                pmDir = pmNextDir
            ok
        ok

        // Check if current direction is blocked
        nr2 = gr
        nc2 = gc
        if pmDir = DIR_UP    nr2 = gr - 1 ok
        if pmDir = DIR_DOWN  nr2 = gr + 1 ok
        if pmDir = DIR_LEFT  nc2 = gc - 1 ok
        if pmDir = DIR_RIGHT nc2 = gc + 1 ok
        nr2 = pac_wrapR(nr2)
        nc2 = pac_wrapC(nc2)
        if !pac_canMove(nr2, nc2)
            pmDir = DIR_NONE
        ok
    ok

    // Apply movement
    if pmDir = DIR_UP    pmRow -= speed * dt ok
    if pmDir = DIR_DOWN  pmRow += speed * dt ok
    if pmDir = DIR_LEFT  pmCol -= speed * dt ok
    if pmDir = DIR_RIGHT pmCol += speed * dt ok

    // Tunnel wrapping
    if pmCol < 0.5 pmCol = MAZE_W + 0.5 ok
    if pmCol > MAZE_W + 0.5 pmCol = 0.5 ok
    if pmRow < 0.5 pmRow = MAZE_H + 0.5 ok
    if pmRow > MAZE_H + 0.5 pmRow = 0.5 ok

    // Eat pellets
    gr = pac_gridR()
    gc = pac_gridC()
    if gr >= 1 and gr <= MAZE_H and gc >= 1 and gc <= MAZE_W
        if maze[gr][gc] = C_PELLET
            maze[gr][gc] = C_EMPTY
            pelletsLeft -= 1
            score += 10
            pac_spawnEatParticles(gr, gc)
        ok
        if maze[gr][gc] = C_POWER
            maze[gr][gc] = C_EMPTY
            pelletsLeft -= 1
            score += 50
            pac_activateFrightened()
            pac_spawnPowerParticles(gr, gc)
        ok
    ok

    // Mouth animation
    if pmDir != DIR_NONE
        pmMouthAngle += dt * 12.0
    ok

    // Check level complete
    if pelletsLeft <= 0
        gameState = ST_LEVELUP
        levelUpTimer = 2.0
    ok

// =============================================================
// Ghost Movement
// =============================================================

func pac_moveGhosts dt
    for g = 1 to NUM_GHOSTS
        gState = ghosts[g][4]

        // Start delay
        if ghosts[g][8] > 0
            ghosts[g][8] -= dt
            loop
        ok

        // Home state: release from ghost house
        if gState = GH_HOME
            // First move to door center (row 11, col 11) then up through door to row 9
            exitR = 9.0
            exitC = 11.0
            // Move toward exit point (lerp through door)
            ghosts[g][1] += (exitR - ghosts[g][1]) * dt * 3.0
            ghosts[g][2] += (exitC - ghosts[g][2]) * dt * 3.0
            dr = exitR - ghosts[g][1]
            dc = exitC - ghosts[g][2]
            if dr < 0 dr = -dr ok
            if dc < 0 dc = -dc ok
            if dr < 0.3 and dc < 0.3
                ghosts[g][1] = exitR
                ghosts[g][2] = exitC
                ghosts[g][4] = GH_CHASE
                ghosts[g][3] = DIR_LEFT
            ok
            loop
        ok

        // Speed based on state
        gSpeed = 3.5 + level * 0.1
        if gState = GH_FRIGHTENED gSpeed = 2.2 ok
        if gState = GH_EATEN gSpeed = 8.0 ok

        gr = floor(ghosts[g][1] + 0.5)
        gc = floor(ghosts[g][2] + 0.5)

        // Check if aligned to grid
        dr = ghosts[g][1] - gr
        dc = ghosts[g][2] - gc
        if dr < 0 dr = -dr ok
        if dc < 0 dc = -dc ok
        aligned = (dr < 0.12 and dc < 0.12)

        if aligned
            // Only choose a new direction if we arrived at a NEW cell
            newCell = (gr != ghostLastR[g] or gc != ghostLastC[g])

            if newCell
                ghostLastR[g] = gr
                ghostLastC[g] = gc

                // Snap to exact grid
                ghosts[g][1] = gr * 1.0
                ghosts[g][2] = gc * 1.0

                // Choose next direction
                if gState = GH_EATEN
                    ghosts[g][6] = ghostHomeR
                    ghosts[g][7] = ghostHomeC
                    er = gr - ghostHomeR
                    ec = gc - ghostHomeC
                    if er < 0 er = -er ok
                    if ec < 0 ec = -ec ok
                    if er <= 1 and ec <= 1
                        ghosts[g][4] = GH_HOME
                        ghosts[g][1] = ghostHomeR * 1.0
                        ghosts[g][2] = ghostHomeC * 1.0
                        loop
                    ok
                ok

                if gState = GH_CHASE
                    pac_setGhostTarget(g)
                ok

                if gState = GH_FRIGHTENED
                    ghosts[g][6] = GetRandomValue(1, MAZE_H)
                    ghosts[g][7] = GetRandomValue(1, MAZE_W)
                ok

                pac_chooseGhostDir(g)
            ok

            // Check if chosen direction is passable before moving
            gDir = ghosts[g][3]
            nr = gr
            nc = gc
            if gDir = DIR_UP    nr = gr - 1 ok
            if gDir = DIR_DOWN  nr = gr + 1 ok
            if gDir = DIR_LEFT  nc = gc - 1 ok
            if gDir = DIR_RIGHT nc = gc + 1 ok
            nr = pac_wrapR(nr)
            nc = pac_wrapC(nc)
            if !pac_ghostCanMove(nr, nc, ghosts[g][4])
                // Direction is blocked, try re-choosing
                pac_chooseGhostDir(g)
                // Still check again
                gDir = ghosts[g][3]
                nr = gr
                nc = gc
                if gDir = DIR_UP    nr = gr - 1 ok
                if gDir = DIR_DOWN  nr = gr + 1 ok
                if gDir = DIR_LEFT  nc = gc - 1 ok
                if gDir = DIR_RIGHT nc = gc + 1 ok
                nr = pac_wrapR(nr)
                nc = pac_wrapC(nc)
                if !pac_ghostCanMove(nr, nc, ghosts[g][4])
                    // Truly stuck - skip movement
                    loop
                ok
            ok
        ok

        // Move in current direction
        gDir = ghosts[g][3]
        if gDir = DIR_UP    ghosts[g][1] -= gSpeed * dt ok
        if gDir = DIR_DOWN  ghosts[g][1] += gSpeed * dt ok
        if gDir = DIR_LEFT  ghosts[g][2] -= gSpeed * dt ok
        if gDir = DIR_RIGHT ghosts[g][2] += gSpeed * dt ok

        // Tunnel wrap
        if ghosts[g][2] < 0.5 ghosts[g][2] = MAZE_W + 0.5 ok
        if ghosts[g][2] > MAZE_W + 0.5 ghosts[g][2] = 0.5 ok
        if ghosts[g][1] < 0.5 ghosts[g][1] = MAZE_H + 0.5 ok
        if ghosts[g][1] > MAZE_H + 0.5 ghosts[g][1] = 0.5 ok
    next

// =============================================================
// Ghost AI: Target Selection
// =============================================================

func pac_setGhostTarget g
    pgr = pac_gridR()
    pgc = pac_gridC()

    if g = GH_RED
        // Blinky: directly chase Pac-Man
        ghosts[g][6] = pgr
        ghosts[g][7] = pgc
    ok

    if g = GH_PINK
        // Pinky: target 4 tiles ahead of Pac-Man
        tr = pgr
        tc = pgc
        if pmDir = DIR_UP    tr = pgr - 4 ok
        if pmDir = DIR_DOWN  tr = pgr + 4 ok
        if pmDir = DIR_LEFT  tc = pgc - 4 ok
        if pmDir = DIR_RIGHT tc = pgc + 4 ok
        ghosts[g][6] = tr
        ghosts[g][7] = tc
    ok

    if g = GH_CYAN
        // Inky: complex targeting (uses Blinky position)
        tr = pgr
        tc = pgc
        if pmDir = DIR_UP    tr = pgr - 2 ok
        if pmDir = DIR_DOWN  tr = pgr + 2 ok
        if pmDir = DIR_LEFT  tc = pgc - 2 ok
        if pmDir = DIR_RIGHT tc = pgc + 2 ok
        // Double the vector from Blinky to this point
        blinkyR = floor(ghosts[GH_RED][1] + 0.5)
        blinkyC = floor(ghosts[GH_RED][2] + 0.5)
        ghosts[g][6] = tr + (tr - blinkyR)
        ghosts[g][7] = tc + (tc - blinkyC)
    ok

    if g = GH_ORANGE
        // Clyde: chase if far, scatter if close
        dist = (pgr - ghosts[g][1]) * (pgr - ghosts[g][1]) +
               (pgc - ghosts[g][2]) * (pgc - ghosts[g][2])
        if dist > 64
            ghosts[g][6] = pgr
            ghosts[g][7] = pgc
        else
            ghosts[g][6] = MAZE_H
            ghosts[g][7] = 1
        ok
    ok

// =============================================================
// Ghost Direction Choice
// =============================================================

func pac_chooseGhostDir g
    gr = floor(ghosts[g][1] + 0.5)
    gc = floor(ghosts[g][2] + 0.5)
    curDir = ghosts[g][3]
    tgtR = ghosts[g][6]
    tgtC = ghosts[g][7]

    // Possible directions (prefer not reversing)
    dirs = [DIR_UP, DIR_DOWN, DIR_LEFT, DIR_RIGHT]
    reverse = DIR_NONE
    if curDir = DIR_UP reverse = DIR_DOWN ok
    if curDir = DIR_DOWN reverse = DIR_UP ok
    if curDir = DIR_LEFT reverse = DIR_RIGHT ok
    if curDir = DIR_RIGHT reverse = DIR_LEFT ok

    bestDir = DIR_NONE
    bestDist = 999999.0
    fallbackDir = DIR_NONE

    for d = 1 to 4
        dd = dirs[d]

        nr = gr
        nc = gc
        if dd = DIR_UP    nr = gr - 1 ok
        if dd = DIR_DOWN  nr = gr + 1 ok
        if dd = DIR_LEFT  nc = gc - 1 ok
        if dd = DIR_RIGHT nc = gc + 1 ok
        nr = pac_wrapR(nr)
        nc = pac_wrapC(nc)

        if pac_ghostCanMove(nr, nc, ghosts[g][4])
            dist = (nr - tgtR) * (nr - tgtR) + (nc - tgtC) * (nc - tgtC)
            if dd = reverse
                // Remember reverse as fallback
                fallbackDir = dd
            else
                if dist < bestDist
                    bestDist = dist
                    bestDir = dd
                ok
            ok
        ok
    next

    // Use best non-reverse direction, or fallback to reverse if stuck
    if bestDir != DIR_NONE
        ghosts[g][3] = bestDir
    but fallbackDir != DIR_NONE
        ghosts[g][3] = fallbackDir
    ok

// =============================================================
// Frightened Mode
// =============================================================

func pac_activateFrightened
    frightTimer = frightDuration
    ghostEatCount = 0
    for g = 1 to NUM_GHOSTS
        if ghosts[g][4] = GH_CHASE
            ghosts[g][4] = GH_FRIGHTENED
            // Reverse direction
            if ghosts[g][3] = DIR_UP ghosts[g][3] = DIR_DOWN
            but ghosts[g][3] = DIR_DOWN ghosts[g][3] = DIR_UP
            but ghosts[g][3] = DIR_LEFT ghosts[g][3] = DIR_RIGHT
            but ghosts[g][3] = DIR_RIGHT ghosts[g][3] = DIR_LEFT
            ok
        ok
    next

func pac_updateFrightened dt
    if frightTimer > 0
        frightTimer -= dt
        if frightTimer <= 0
            frightTimer = 0.0
            for g = 1 to NUM_GHOSTS
                if ghosts[g][4] = GH_FRIGHTENED
                    ghosts[g][4] = GH_CHASE
                ok
            next
        ok
    ok

// =============================================================
// Collision Detection
// =============================================================

func pac_checkCollisions
    for g = 1 to NUM_GHOSTS
        dr = pmRow - ghosts[g][1]
        dc = pmCol - ghosts[g][2]
        dist = dr * dr + dc * dc

        if dist < 0.65
            gState = ghosts[g][4]
            if gState = GH_FRIGHTENED
                // Eat ghost!
                ghosts[g][4] = GH_EATEN
                ghostEatCount += 1
                bonus = 200
                for _i = 1 to ghostEatCount - 1
                    bonus = bonus * 2
                next
                if bonus > 3200 bonus = 3200 ok
                score += bonus

                wx = pac_cellToX(ghosts[g][2])
                wy = 1.0
                wz = pac_cellToZ(ghosts[g][1])
                add(popups, [wx, wy, wz, string(bonus), 1.5])
                pac_spawnGhostEatParticles(g)
            ok
            if gState = GH_CHASE
                // Pac-Man dies
                gameState = ST_DYING
                dyingTimer = 1.5
                pac_spawnDeathParticles()
            ok
        ok
    next

// =============================================================
// Grid Helpers
// =============================================================

func pac_gridR
    return floor(pmRow + 0.5)

func pac_gridC
    return floor(pmCol + 0.5)

func pac_isAligned
    gr = pac_gridR()
    gc = pac_gridC()
    dr = pmRow - gr
    dc = pmCol - gc
    if dr < 0 dr = -dr ok
    if dc < 0 dc = -dc ok
    return dr < 0.15 and dc < 0.15

func pac_canMove r, c
    if r < 1 or r > MAZE_H return true ok  // Tunnel
    if c < 1 or c > MAZE_W return true ok  // Tunnel
    return maze[r][c] != C_WALL

func pac_ghostCanMove r, c, gState
    if r < 1 or r > MAZE_H return true ok
    if c < 1 or c > MAZE_W return true ok
    if maze[r][c] = C_WALL return false ok
    if maze[r][c] = C_DOOR
        if gState = GH_EATEN or gState = GH_HOME return true ok
        return false
    ok
    return true

func pac_wrapR r
    if r < 1 r = MAZE_H ok
    if r > MAZE_H r = 1 ok
    return r

func pac_wrapC c
    if c < 1 c = MAZE_W ok
    if c > MAZE_W c = 1 ok
    return c

// =============================================================
// Coordinate Helpers
// =============================================================

func pac_cellToX c
    return (c - 1) * CELL_SZ - (MAZE_W - 1) * CELL_SZ / 2

func pac_cellToZ r
    return (r - 1) * CELL_SZ - (MAZE_H - 1) * CELL_SZ / 2

// =============================================================
// Particles
// =============================================================

func pac_spawnEatParticles r, c
    wx = pac_cellToX(c)
    wz = pac_cellToZ(r)
    for i = 1 to 3
        vx = (GetRandomValue(-100, 100) / 100.0) * 0.5
        vy = (GetRandomValue(80, 200) / 100.0) * 0.5
        vz = (GetRandomValue(-100, 100) / 100.0) * 0.5
        add(particles, [wx, 0.3, wz, vx, vy, vz, 0.4, 255, 255, 180])
    next

func pac_spawnPowerParticles r, c
    wx = pac_cellToX(c)
    wz = pac_cellToZ(r)
    for i = 1 to 12
        vx = (GetRandomValue(-100, 100) / 100.0) * 1.5
        vy = (GetRandomValue(100, 350) / 100.0) * 1.0
        vz = (GetRandomValue(-100, 100) / 100.0) * 1.5
        add(particles, [wx, 0.5, wz, vx, vy, vz, 1.0, 255, 200, 50])
    next

func pac_spawnGhostEatParticles g
    wx = pac_cellToX(ghosts[g][2])
    wz = pac_cellToZ(ghosts[g][1])
    cr = ghostColors[g][1]
    cg = ghostColors[g][2]
    cb = ghostColors[g][3]
    for i = 1 to 10
        vx = (GetRandomValue(-100, 100) / 100.0) * 2.0
        vy = (GetRandomValue(100, 300) / 100.0)
        vz = (GetRandomValue(-100, 100) / 100.0) * 2.0
        add(particles, [wx, 0.5, wz, vx, vy, vz, 0.8, cr, cg, cb])
    next

func pac_spawnDeathParticles
    wx = pac_cellToX(pmCol)
    wz = pac_cellToZ(pmRow)
    for i = 1 to 20
        angle = (i / 20.0) * 3.14159265 * 2.0
        vx = cos(angle) * 2.5
        vy = (GetRandomValue(100, 400) / 100.0)
        vz = sin(angle) * 2.5
        add(particles, [wx, 0.5, wz, vx, vy, vz, 1.5, 255, 255, 0])
    next

func pac_updateParticles dt
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

func pac_drawParticles3D
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

// Score popups
func pac_updatePopups dt
    i = 1
    while i <= len(popups)
        popups[i][2] += dt * 1.5
        popups[i][5] -= dt
        if popups[i][5] <= 0
            del(popups, i)
        else
            i += 1
        ok
    end

func pac_drawPopups2D
    for i = 1 to len(popups)
        // Simple: draw at fixed screen position based on index
        alpha = floor(popups[i][5] * 200)
        if alpha > 255 alpha = 255 ok
        if alpha < 0 alpha = 0 ok
        pw = MeasureText(popups[i][4], 22)
        px = floor(SCREEN_W / 2) - floor(pw / 2)
        py = floor(SCREEN_H / 2) - 80 - i * 30
        DrawText(popups[i][4], px + 1, py + 1, 22, RAYLIBColor(0, 0, 0, alpha))
        DrawText(popups[i][4], px, py, 22, RAYLIBColor(255, 255, 100, alpha))
    next

// =============================================================
// Camera
// =============================================================

func pac_positionCamera
    mazeExtent = MAZE_W * CELL_SZ

    if cameraMode = CAM_TOP
        goalPX = 0.0
        goalPY = mazeExtent * 1.1
        goalPZ = mazeExtent * 0.15
        goalTX = 0.0
        goalTY = 0.0
        goalTZ = 0.0
    ok

    if cameraMode = CAM_ANGLE
        goalPX = mazeExtent * 0.4
        goalPY = mazeExtent * 0.8
        goalPZ = mazeExtent * 0.6
        goalTX = 0.0
        goalTY = 0.0
        goalTZ = 0.0
    ok

    if cameraMode = CAM_FOLLOW
        px = pac_cellToX(pmCol)
        pz = pac_cellToZ(pmRow)
        behindX = 0.0
        behindZ = 0.0
        if pmDir = DIR_UP    behindZ = 5.0 ok
        if pmDir = DIR_DOWN  behindZ = -5.0 ok
        if pmDir = DIR_LEFT  behindX = 5.0 ok
        if pmDir = DIR_RIGHT behindX = -5.0 ok
        if pmDir = DIR_NONE  behindZ = 5.0 ok

        goalPX = px + behindX
        goalPY = 8.0
        goalPZ = pz + behindZ
        goalTX = px
        goalTY = 0.3
        goalTZ = pz
    ok

    lerp = 0.06
    camPosX += (goalPX - camPosX) * lerp
    camPosY += (goalPY - camPosY) * lerp
    camPosZ += (goalPZ - camPosZ) * lerp
    camTgtX += (goalTX - camTgtX) * lerp
    camTgtY += (goalTY - camTgtY) * lerp
    camTgtZ += (goalTZ - camTgtZ) * lerp

// =============================================================
// 3D Drawing: Maze
// =============================================================

func pac_drawMaze3D
    wallH = 0.7

    // Floor with subtle grid
    floorW = MAZE_W * CELL_SZ + 0.5
    floorH = MAZE_H * CELL_SZ + 0.5
    DrawCube(Vector3(0, -0.15, 0), floorW, 0.1, floorH,
             RAYLIBColor(6, 6, 16, 255))
    // Subtle floor reflection layer
    DrawCube(Vector3(0, -0.09, 0), floorW - 0.1, 0.01, floorH - 0.1,
             RAYLIBColor(12, 12, 28, 200))

    // Walls with neon edge glow
    for r = 1 to MAZE_H
        for c = 1 to MAZE_W
            if maze[r][c] = C_WALL
                wx = pac_cellToX(c)
                wz = pac_cellToZ(r)

                // Main wall body (dark blue)
                DrawCube(Vector3(wx, wallH / 2, wz), CELL_SZ - 0.04, wallH,
                         CELL_SZ - 0.04, RAYLIBColor(15, 15, 80, 255))

                // Check exposed edges and add neon glow strips
                // Top face (lighter)
                DrawCube(Vector3(wx, wallH + 0.005, wz), CELL_SZ - 0.08, 0.01,
                         CELL_SZ - 0.08, RAYLIBColor(30, 30, 140, 255))

                // Edge glow on exposed sides (where adjacent cell is not wall)
                // Check north
                if r > 1
                    if maze[r-1][c] != C_WALL
                        DrawCube(Vector3(wx, wallH * 0.5, wz - CELL_SZ / 2 + 0.02),
                                 CELL_SZ - 0.06, wallH - 0.05, 0.03,
                                 RAYLIBColor(50, 50, 220, 180))
                    ok
                ok
                // Check south
                if r < MAZE_H
                    if maze[r+1][c] != C_WALL
                        DrawCube(Vector3(wx, wallH * 0.5, wz + CELL_SZ / 2 - 0.02),
                                 CELL_SZ - 0.06, wallH - 0.05, 0.03,
                                 RAYLIBColor(50, 50, 220, 180))
                    ok
                ok
                // Check west
                if c > 1
                    if maze[r][c-1] != C_WALL
                        DrawCube(Vector3(wx - CELL_SZ / 2 + 0.02, wallH * 0.5, wz),
                                 0.03, wallH - 0.05, CELL_SZ - 0.06,
                                 RAYLIBColor(50, 50, 220, 180))
                    ok
                ok
                // Check east
                if c < MAZE_W
                    if maze[r][c+1] != C_WALL
                        DrawCube(Vector3(wx + CELL_SZ / 2 - 0.02, wallH * 0.5, wz),
                                 0.03, wallH - 0.05, CELL_SZ - 0.06,
                                 RAYLIBColor(50, 50, 220, 180))
                    ok
                ok
            ok

            if maze[r][c] = C_DOOR
                wx = pac_cellToX(c)
                wz = pac_cellToZ(r)
                // Pink glowing door bar
                DrawCube(Vector3(wx, 0.22, wz), CELL_SZ - 0.08, 0.08,
                         0.12, RAYLIBColor(255, 140, 200, 255))
                // Glow
                DrawCube(Vector3(wx, 0.22, wz), CELL_SZ - 0.02, 0.14,
                         0.18, RAYLIBColor(255, 100, 180, 40))
            ok
        next
    next

// =============================================================
// 3D Drawing: Pellets
// =============================================================

func pac_drawPellets3D
    for r = 1 to MAZE_H
        for c = 1 to MAZE_W
            wx = pac_cellToX(c)
            wz = pac_cellToZ(r)

            if maze[r][c] = C_PELLET
                // Small glowing dot
                DrawSphere(Vector3(wx, 0.22, wz), 0.08,
                           RAYLIBColor(255, 230, 160, 255))
                // Soft glow halo
                DrawSphere(Vector3(wx, 0.22, wz), 0.14,
                           RAYLIBColor(255, 200, 100, 30))
            ok

            if maze[r][c] = C_POWER
                // Pulsing power pellet
                pulse = 0.7 + sin(animTime * 4.0) * 0.3
                sz = 0.20 * pulse + 0.06

                // Core orb
                DrawSphere(Vector3(wx, 0.32, wz), sz,
                           RAYLIBColor(255, 220, 60, 255))
                // Bright inner core
                DrawSphere(Vector3(wx, 0.32, wz), sz * 0.5,
                           RAYLIBColor(255, 255, 200, 255))
                // Outer glow layers
                DrawSphere(Vector3(wx, 0.32, wz), sz + 0.08,
                           RAYLIBColor(255, 200, 50, 50))
                DrawSphere(Vector3(wx, 0.32, wz), sz + 0.18,
                           RAYLIBColor(255, 180, 30, 20))

                // Orbiting sparkles
                for k = 0 to 2
                    oa = animTime * 3.0 + k * 2.094
                    ox = wx + cos(oa) * 0.3
                    oz = wz + sin(oa) * 0.3
                    oy = 0.32 + sin(animTime * 5.0 + k) * 0.08
                    DrawSphere(Vector3(ox, oy, oz), 0.04,
                               RAYLIBColor(255, 255, 180, 200))
                next
            ok
        next
    next

// =============================================================
// 3D Drawing: Pac-Man
// =============================================================

func pac_drawPacman3D
    if gameState = ST_DYING
        // Death animation: Pac-Man deflates and spins apart
        prog = 1.0 - (dyingTimer / 1.5)
        if prog < 0 prog = 0 ok
        if prog > 1 prog = 1 ok
        wx = pac_cellToX(pmCol)
        wz = pac_cellToZ(pmRow)
        spinAngle = prog * 12.0

        // Segments flying apart
        for seg = 0 to 5
            sa = seg * 1.047 + spinAngle
            dist = prog * 1.5
            sx = wx + cos(sa) * dist
            sz2 = wz + sin(sa) * dist
            sy = 0.4 + prog * 1.5 - prog * prog * 2.0
            segSz = 0.15 * (1.0 - prog * 0.8)
            alpha = floor(255 * (1.0 - prog))
            if alpha < 0 alpha = 0 ok
            DrawSphere(Vector3(sx, sy, sz2), segSz,
                       RAYLIBColor(255, 255, 0, alpha))
        next
        // Fading center
        cAlpha = floor(200 * (1.0 - prog))
        if cAlpha < 0 cAlpha = 0 ok
        DrawSphere(Vector3(wx, 0.4, wz), 0.3 * (1.0 - prog),
                   RAYLIBColor(255, 200, 0, cAlpha))
        return
    ok

    if gameState != ST_PLAYING and gameState != ST_READY and gameState != ST_PAUSED return ok

    wx = pac_cellToX(pmCol)
    wz = pac_cellToZ(pmRow)
    baseY = 0.42

    // Gentle bob while moving
    bob = 0.0
    if pmDir != DIR_NONE
        bob = sin(animTime * 10.0) * 0.03
    ok

    // Mouth open/close
    mouth = sin(pmMouthAngle) * 0.5 + 0.5  // 0 to 1
    if pmDir = DIR_NONE mouth = 0.25 ok

    // Direction vectors for mouth/eyes
    faceDX = 0.0
    faceDZ = 0.0
    if pmDir = DIR_UP    faceDZ = -1.0 ok
    if pmDir = DIR_DOWN  faceDZ = 1.0 ok
    if pmDir = DIR_LEFT  faceDX = -1.0 ok
    if pmDir = DIR_RIGHT faceDX = 1.0 ok
    if pmDir = DIR_NONE  faceDZ = -1.0 ok

    // Perpendicular direction (for eye placement)
    perpDX = -faceDZ
    perpDZ = faceDX

    // === BODY: layered golden sphere ===
    bodyR = 0.40

    // Shadow on floor
    DrawCylinder(Vector3(wx, -0.08, wz), bodyR * 0.8, bodyR * 0.9, 0.01, 16,
                 RAYLIBColor(0, 0, 0, 60))

    // Main body
    DrawSphere(Vector3(wx, baseY + bob, wz), bodyR,
               RAYLIBColor(255, 230, 0, 255))

    // Top highlight (lighter yellow for gloss)
    DrawSphere(Vector3(wx + faceDX * 0.05, baseY + bob + 0.12, wz + faceDZ * 0.05),
               bodyR * 0.55, RAYLIBColor(255, 255, 80, 100))

    // Top specular dot
    DrawSphere(Vector3(wx - faceDX * 0.08, baseY + bob + 0.22, wz - faceDZ * 0.08),
               0.08, RAYLIBColor(255, 255, 220, 140))

    // Bottom shadow (darker underside)
    DrawSphere(Vector3(wx, baseY + bob - 0.15, wz), bodyR * 0.6,
               RAYLIBColor(200, 160, 0, 80))

    // === MOUTH: wedge-shaped dark cut ===
    mouthDepth = 0.18 + mouth * 0.22
    mouthSz = 0.12 + mouth * 0.18
    // Main mouth hole
    DrawSphere(Vector3(wx + faceDX * mouthDepth, baseY + bob,
                       wz + faceDZ * mouthDepth), mouthSz,
               RAYLIBColor(5, 5, 15, 255))
    // Upper lip cut (slightly above)
    DrawSphere(Vector3(wx + faceDX * (mouthDepth - 0.03), baseY + bob + 0.08,
                       wz + faceDZ * (mouthDepth - 0.03)), mouthSz * 0.7,
               RAYLIBColor(5, 5, 15, 255))
    // Lower lip cut (slightly below)
    DrawSphere(Vector3(wx + faceDX * (mouthDepth - 0.03), baseY + bob - 0.08,
                       wz + faceDZ * (mouthDepth - 0.03)), mouthSz * 0.7,
               RAYLIBColor(5, 5, 15, 255))

    // === EYES: white sclera + colored iris + black pupil + specular ===
    eyeH = baseY + bob + 0.12
    eyeForward = 0.22
    eyeSide = 0.15

    for side = -1 to 1 step 2
        ex = wx + faceDX * eyeForward + perpDX * eyeSide * side
        ez = wz + faceDZ * eyeForward + perpDZ * eyeSide * side

        // White sclera
        DrawSphere(Vector3(ex, eyeH, ez), 0.10,
                   RAYLIBColor(255, 255, 255, 255))
        // Dark brown iris
        DrawSphere(Vector3(ex + faceDX * 0.04, eyeH - 0.01, ez + faceDZ * 0.04),
                   0.06, RAYLIBColor(40, 25, 10, 255))
        // Black pupil
        DrawSphere(Vector3(ex + faceDX * 0.06, eyeH - 0.01, ez + faceDZ * 0.06),
                   0.035, RAYLIBColor(0, 0, 0, 255))
        // Specular highlight
        DrawSphere(Vector3(ex + faceDX * 0.02 + 0.02, eyeH + 0.03,
                           ez + faceDZ * 0.02), 0.025,
                   RAYLIBColor(255, 255, 255, 200))
    next

// =============================================================
// 3D Drawing: Ghosts
// =============================================================

func pac_drawGhosts3D
    for g = 1 to NUM_GHOSTS
        if ghosts[g][8] > 0 loop ok  // Not yet released

        gState = ghosts[g][4]
        wx = pac_cellToX(ghosts[g][2])
        wz = pac_cellToZ(ghosts[g][1])
        gDir = ghosts[g][3]

        // Direction the ghost faces
        gfDX = 0.0
        gfDZ = -1.0
        if gDir = DIR_UP    gfDZ = -1.0 ok
        if gDir = DIR_DOWN  gfDZ = 1.0 ok
        if gDir = DIR_LEFT  gfDX = -1.0  gfDZ = 0.0 ok
        if gDir = DIR_RIGHT gfDX = 1.0   gfDZ = 0.0 ok
        gpDX = -gfDZ
        gpDZ = gfDX

        baseY = 0.0
        ghostBob = sin(animTime * 6.0 + g * 1.5) * 0.04

        if gState = GH_EATEN
            // === EATEN: Just eyes floating back ===
            eBaseY = 0.45 + ghostBob
            for side = -1 to 1 step 2
                ex = wx + gpDX * 0.14 * side
                ez = wz + gpDZ * 0.14 * side
                // White sclera
                DrawSphere(Vector3(ex, eBaseY, ez), 0.11,
                           RAYLIBColor(255, 255, 255, 255))
                // Blue iris (direction-facing)
                DrawSphere(Vector3(ex + gfDX * 0.05, eBaseY - 0.01, ez + gfDZ * 0.05),
                           0.06, RAYLIBColor(30, 60, 220, 255))
                // Black pupil
                DrawSphere(Vector3(ex + gfDX * 0.07, eBaseY - 0.01, ez + gfDZ * 0.07),
                           0.035, RAYLIBColor(0, 0, 0, 255))
            next
            // Faint trail
            DrawSphere(Vector3(wx - gfDX * 0.3, 0.4, wz - gfDZ * 0.3), 0.06,
                       RAYLIBColor(200, 200, 255, 40))
            loop
        ok

        // === Body color ===
        cr = ghostColors[g][1]
        cg2 = ghostColors[g][2]
        cb = ghostColors[g][3]
        // Darker shade for body bottom
        dr2 = floor(cr * 0.6)
        dg2 = floor(cg2 * 0.6)
        db2 = floor(cb * 0.6)
        // Lighter shade for highlight
        hr = cr + 60   if hr > 255 hr = 255 ok
        hg = cg2 + 60  if hg > 255 hg = 255 ok
        hb = cb + 60   if hb > 255 hb = 255 ok

        if gState = GH_FRIGHTENED
            if frightTimer < 2.0
                if floor(animTime * 6) % 2 = 0
                    cr = 30  cg2 = 30  cb = 220
                    dr2 = 15  dg2 = 15  db2 = 140
                    hr = 80   hg = 80   hb = 255
                else
                    cr = 230  cg2 = 230  cb = 255
                    dr2 = 160  dg2 = 160  db2 = 200
                    hr = 255   hg = 255   hb = 255
                ok
            else
                cr = 30  cg2 = 30  cb = 220
                dr2 = 15  dg2 = 15  db2 = 140
                hr = 80   hg = 80   hb = 255
            ok
        ok

        // Shadow on floor
        DrawCylinder(Vector3(wx, -0.08, wz), 0.35, 0.40, 0.01, 14,
                     RAYLIBColor(0, 0, 0, 50))

        // === BODY: Dome top + cylinder body ===
        domeY = baseY + 0.30 + ghostBob

        // Main body cylinder (slightly tapered)
        DrawCylinder(Vector3(wx, baseY + 0.02, wz), 0.38, 0.36, 0.32 + ghostBob, 14,
                     RAYLIBColor(cr, cg2, cb, 255))

        // Dome head (hemisphere - upper sphere)
        DrawSphere(Vector3(wx, domeY + 0.05, wz), 0.38,
                   RAYLIBColor(cr, cg2, cb, 255))

        // Top highlight (shiny spot)
        DrawSphere(Vector3(wx - gfDX * 0.06, domeY + 0.22, wz - gfDZ * 0.06),
                   0.14, RAYLIBColor(hr, hg, hb, 120))
        // Specular dot
        DrawSphere(Vector3(wx - gfDX * 0.10, domeY + 0.28, wz - gfDZ * 0.10),
                   0.06, RAYLIBColor(255, 255, 255, 80))

        // === SKIRT: Wavy tentacles at bottom ===
        numTent = 6
        for t = 0 to numTent - 1
            angle = (t * 1.0 / numTent) * 3.14159265 * 2.0
            wave = sin(animTime * 8.0 + t * 1.2 + g * 2.0) * 0.06
            tentR = 0.32
            tx = wx + cos(angle) * tentR
            tz = wz + sin(angle) * tentR
            ty = baseY + 0.02 + wave

            // Tentacle blob
            DrawSphere(Vector3(tx, ty, tz), 0.10,
                       RAYLIBColor(cr, cg2, cb, 255))
            // Darker underside of tentacle
            DrawSphere(Vector3(tx, ty - 0.04, tz), 0.07,
                       RAYLIBColor(dr2, dg2, db2, 200))
        next

        // === EYES ===
        eyeY = domeY + 0.10

        if gState != GH_FRIGHTENED
            // Normal eyes: white sclera + iris + pupil + specular
            for side = -1 to 1 step 2
                ex = wx + gpDX * 0.16 * side + gfDX * 0.18
                ez = wz + gpDZ * 0.16 * side + gfDZ * 0.18

                // White sclera (slight oval - use 2 spheres)
                DrawSphere(Vector3(ex, eyeY, ez), 0.12,
                           RAYLIBColor(255, 255, 255, 255))
                // Blue iris (looks in movement direction)
                DrawSphere(Vector3(ex + gfDX * 0.05, eyeY - 0.01, ez + gfDZ * 0.05),
                           0.07, RAYLIBColor(30, 60, 220, 255))
                // Black pupil
                DrawSphere(Vector3(ex + gfDX * 0.07, eyeY - 0.02, ez + gfDZ * 0.07),
                           0.04, RAYLIBColor(0, 0, 0, 255))
                // Specular highlight
                DrawSphere(Vector3(ex + gfDX * 0.01 + 0.02, eyeY + 0.04,
                                   ez + gfDZ * 0.01), 0.03,
                           RAYLIBColor(255, 255, 255, 180))
            next
        else
            // Frightened face: squiggly eyes + wavy mouth
            for side = -1 to 1 step 2
                ex = wx + gpDX * 0.14 * side + gfDX * 0.20
                ez = wz + gpDZ * 0.14 * side + gfDZ * 0.20

                // Small worried eyes
                DrawSphere(Vector3(ex, eyeY + 0.02, ez), 0.06,
                           RAYLIBColor(255, 200, 180, 255))
                DrawSphere(Vector3(ex, eyeY + 0.02, ez), 0.03,
                           RAYLIBColor(200, 80, 80, 255))
            next

            // Zigzag mouth
            mouthY = domeY - 0.02
            for m = -2 to 2
                mx = wx + gpDX * m * 0.08 + gfDX * 0.30
                mz = wz + gpDZ * m * 0.08 + gfDZ * 0.30
                mUp = 0.0
                if m % 2 = 0 mUp = 0.04
                else mUp = -0.04
                ok
                DrawSphere(Vector3(mx, mouthY + mUp, mz), 0.03,
                           RAYLIBColor(255, 200, 180, 255))
            next
        ok
    next

// =============================================================
// HUD
// =============================================================

func pac_drawHUD
    panelW = 200
    panelH = 100
    DrawRectangle(10, 30, panelW, panelH, RAYLIBColor(0, 0, 0, 190))
    DrawRectangleLines(10, 30, panelW, panelH, RAYLIBColor(80, 100, 160, 200))

    DrawText("PAC-MAN 3D", 20, 38, 16, RAYLIBColor(255, 255, 50, 255))

    DrawText("Score: " + string(score), 20, 58, 18,
             RAYLIBColor(255, 255, 255, 255))

    DrawText("Level: " + string(level), 20, 80, 14,
             RAYLIBColor(100, 200, 255, 220))

    // Lives
    livesStr = "Lives: "
    for i = 1 to lives
        livesStr += "O "
    next
    DrawText(livesStr, 20, 98, 14, RAYLIBColor(255, 255, 0, 255))

    // Pellets remaining
    pctLeft = 0
    if totalPellets > 0
        pctLeft = floor((totalPellets - pelletsLeft) * 100 / totalPellets)
    ok
    DrawRectangle(10, 135, panelW, 20, RAYLIBColor(0, 0, 0, 153))
    barW = floor(panelW * pctLeft / 100)
    DrawRectangle(10, 135, barW, 20, RAYLIBColor(50, 200, 50, 200))
    DrawText(string(pctLeft) + "% cleared", 20, 138, 13,
             RAYLIBColor(255, 255, 255, 220))

    // Camera
    camName = "TOP"
    if cameraMode = CAM_ANGLE  camName = "ANGLE"  ok
    if cameraMode = CAM_FOLLOW camName = "FOLLOW" ok
    DrawRectangle(10, SCREEN_H - 60, 200, 25, RAYLIBColor(0, 0, 0, 153))
    DrawText("Cam: " + camName + "  [C]  |  [P] Pause", 16, SCREEN_H - 56, 13,
             RAYLIBColor(150, 170, 200, 220))

    // Controls
    DrawRectangle(SCREEN_W - 340, SCREEN_H - 35, 330, 25, RAYLIBColor(0, 0, 0, 153))
    DrawText("Arrows/WASD: Move | C: Camera | P: Pause | R: Restart",
             SCREEN_W - 335, SCREEN_H - 30, 11, RAYLIBColor(150, 160, 180, 200))

// =============================================================
// Overlays
// =============================================================

func pac_drawReadyOverlay
    rText = "READY!"
    tw = MeasureText(rText, 48)
    pulse = floor(200 + sin(animTime * 6) * 55)
    DrawText(rText, floor((SCREEN_W - tw) / 2) + 2, floor(SCREEN_H / 2) - 28, 48,
             RAYLIBColor(0, 0, 0, 150))
    DrawText(rText, floor((SCREEN_W - tw) / 2), floor(SCREEN_H / 2) - 30, 48,
             RAYLIBColor(255, 255, 50, pulse))

func pac_drawPauseOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 160))
    pText = "PAUSED"
    tw = MeasureText(pText, 56)
    DrawText(pText, floor((SCREEN_W - tw) / 2), floor(SCREEN_H / 2) - 50, 56,
             RAYLIBColor(200, 220, 255, 255))
    hint = "Press P or SPACE to Resume"
    hw = MeasureText(hint, 20)
    DrawText(hint, floor((SCREEN_W - hw) / 2), floor(SCREEN_H / 2) + 20, 20,
             RAYLIBColor(160, 180, 200, 220))

func pac_drawGameOverOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 180))

    goText = "GAME OVER"
    tw = MeasureText(goText, 56)
    tx = floor((SCREEN_W - tw) / 2)
    DrawText(goText, tx + 3, 203, 56, RAYLIBColor(0, 0, 0, 130))
    DrawText(goText, tx, 200, 56, RAYLIBColor(255, 60, 40, 255))

    sText = "Score: " + string(score)
    sw = MeasureText(sText, 28)
    DrawText(sText, floor((SCREEN_W - sw) / 2), 275, 28,
             RAYLIBColor(255, 255, 100, 255))

    lText = "Level: " + string(level)
    lw = MeasureText(lText, 22)
    DrawText(lText, floor((SCREEN_W - lw) / 2), 315, 22,
             RAYLIBColor(200, 200, 255, 240))

    hint = "Press ENTER or SPACE to Try Again"
    hw = MeasureText(hint, 20)
    DrawText(hint, floor((SCREEN_W - hw) / 2), 370, 20,
             RAYLIBColor(180, 190, 210, 220))

func pac_drawLevelUpOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 140))

    luText = "LEVEL COMPLETE!"
    tw = MeasureText(luText, 44)
    tx = floor((SCREEN_W - tw) / 2)
    DrawText(luText, tx + 2, 252, 44, RAYLIBColor(0, 0, 0, 130))
    DrawText(luText, tx, 250, 44, RAYLIBColor(100, 255, 100, 255))

    nText = "Next: Level " + string(level + 1)
    nw = MeasureText(nText, 24)
    DrawText(nText, floor((SCREEN_W - nw) / 2), 310, 24,
             RAYLIBColor(255, 255, 200, 240))

// =============================================================
// Title Screen
// =============================================================

func pac_drawTitleScreen
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(5, 5, 15, 255))

    t1 = "3D PAC-MAN"
    t1w = MeasureText(t1, 52)
    t1x = floor((SCREEN_W - t1w) / 2)
    DrawText(t1, t1x + 3, 53, 52, RAYLIBColor(80, 60, 0, 200))
    DrawText(t1, t1x, 50, 52, RAYLIBColor(255, 255, 50, 255))

    t2 = "~ Navigate the maze and eat all the pellets! ~"
    t2w = MeasureText(t2, 16)
    DrawText(t2, floor((SCREEN_W - t2w) / 2), 115, 16,
             RAYLIBColor(180, 150, 100, 220))

    cy = 155
    cLines = [
        "Arrow Keys / WASD      -   Move Pac-Man",
        "C                      -   Cycle camera view",
        "P                      -   Pause / Unpause",
        "R                      -   Restart game",
        "",
        "Rules:",
        "  Eat ALL pellets to complete the level",
        "  Avoid ghosts - they will chase you!",
        "  Eat a POWER PELLET to turn ghosts blue",
        "  Blue ghosts can be eaten for bonus points!",
        "  200, 400, 800, 1600 points per ghost combo",
        "  You have 3 lives - don't lose them all!"
    ]
    for i = 1 to len(cLines)
        lw = MeasureText(cLines[i], 15)
        if i >= 6
            col = RAYLIBColor(255, 200, 100, 210)
        else
            col = RAYLIBColor(150, 170, 200, 230)
        ok
        DrawText(cLines[i], floor((SCREEN_W - lw) / 2), cy + (i - 1) * 22, 15, col)
    next

    // Character showcase
    showY = 440
    // Pac-Man
    DrawCircle(floor(SCREEN_W / 2) - 120, showY, 18, RAYLIBColor(255, 255, 0, 255))
    DrawText("PAC-MAN", floor(SCREEN_W / 2) - 150, showY + 25, 13,
             RAYLIBColor(255, 255, 0, 200))

    // Ghosts
    gNames = ["BLINKY", "PINKY", "INKY", "CLYDE"]
    for g = 1 to 4
        gx = floor(SCREEN_W / 2) - 30 + (g - 1) * 70
        DrawCircle(gx, showY, 16, RAYLIBColor(ghostColors[g][1], ghostColors[g][2],
                   ghostColors[g][3], 255))
        nw = MeasureText(gNames[g], 10)
        DrawText(gNames[g], gx - floor(nw / 2), showY + 25, 10,
                 RAYLIBColor(ghostColors[g][1], ghostColors[g][2],
                 ghostColors[g][3], 200))
    next

    if floor(animTime * 2) % 2 = 0
        st = "Press ENTER or SPACE to Start"
        stw = MeasureText(st, 26)
        DrawText(st, floor((SCREEN_W - stw) / 2), 520, 26,
                 RAYLIBColor(255, 255, 255, 255))
    ok

    cr = "Developed using Ring Language + RingRayLib"
    crw = MeasureText(cr, 14)
    DrawText(cr, floor((SCREEN_W - crw) / 2), SCREEN_H - 35, 14,
             RAYLIBColor(60, 70, 50, 180))
