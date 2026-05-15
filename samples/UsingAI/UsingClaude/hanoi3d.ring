/*
**  3D Tower of Hanoi Game - Using RingRayLib
**  ============================================
**  Classic Tower of Hanoi puzzle in full 3D! Move discs between
**  three pegs to transfer the entire stack from left to right.
**
**  Controls:
**    1 / 2 / 3          -   Select peg (source), then destination
**    Left / Right        -   Move cursor between pegs
**    ENTER / SPACE       -   Select peg / Confirm move
**    Mouse Click         -   Select peg / Confirm move
**    U                   -   Undo last move
**    A                   -   Auto-solve (watch the solution!)
**    C                   -   Cycle camera views
**    R                   -   Restart (same disc count)
**    +  / =              -   Increase disc count (3-10)
**    -                   -   Decrease disc count (3-10)
**    ESC                 -   Exit
**
**  Rules:
**    - Move one disc at a time from the top of a peg
**    - A larger disc can NEVER be placed on a smaller disc
**    - Move ALL discs from peg 1 (left) to peg 3 (right)
**    - Minimum moves needed = 2^n - 1 (where n = number of discs)
**
**  Features:
**    - Colorful 3D discs with smooth pick-up and drop animations
**    - Arc movement animation between pegs
**    - 3D pegs on a wooden-style platform
**    - Move counter vs optimal solution
**    - Undo system (unlimited)
**    - Auto-solve with animated playback
**    - Three camera modes
**    - Adjustable disc count (3-10)
**    - Timer
**    - Particle effects
**    - Mouse + keyboard support
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W        = 1024
SCREEN_H        = 768

NUM_PEGS        = 3
MAX_DISCS       = 10
MIN_DISCS       = 3

// Sizing
PEG_SPACING     = 5.0
PEG_RADIUS      = 0.15
DISC_H          = 0.45
MIN_DISC_RAD    = 0.5
MAX_DISC_RAD    = 1.8
PLATFORM_Y      = -0.2

// Game states
ST_START        = 1
ST_PLAYING      = 2
ST_ANIMATING    = 3
ST_AUTOSOLVE    = 4
ST_WON          = 5

// Camera modes
CAM_FRONT       = 1
CAM_ANGLE       = 2
CAM_TOP         = 3
CAM_COUNT       = 3

// Animation phases
ANIM_LIFT       = 1
ANIM_MOVE       = 2
ANIM_DROP       = 3

// =============================================================
// Global Variables
// =============================================================

// Pegs: each peg is a list of disc sizes (bottom to top)
// Disc size = 1 (smallest) to numDiscs (largest)
pegs            = []

// Game settings
numDiscs        = 5
gameState       = ST_START
animTime        = 0.0

// Selection
selectedPeg     = 0      // 0 = none selected
cursorPeg       = 1      // Current cursor position (1-3)

// Move tracking
moveCount       = 0
optimalMoves    = 0

// Timer
gameTimer       = 0.0
timerRunning    = false

// Undo stack: [[fromPeg, toPeg, discSize], ...]
undoStack       = []

// Animation state
animPhase       = 0
animFromPeg     = 0
animToPeg       = 0
animDiscSize    = 0
animProgress    = 0.0
animSpeed       = 3.5      // Animation speed multiplier
animDiscX       = 0.0
animDiscY       = 0.0
animDiscZ       = 0.0
animLiftY       = 0.0      // Target Y for lift

// Auto-solve
autoMoves       = []       // List of [from, to] moves
autoIndex       = 0
autoDelay       = 0.0
autoWait        = 0.3      // Delay between auto moves

// Camera
cameraMode      = CAM_FRONT
camPosX = 0.0   camPosY = 8.0   camPosZ = 14.0
camTgtX = 0.0   camTgtY = 2.0   camTgtZ = 0.0

// Mouse hover
mouseHoverPeg   = 0
projScreenX     = 0.0
projScreenY     = 0.0

// Particles
particles       = []

// Disc colors (up to 10 discs, gradient from warm to cool)
discColors      = []

// =============================================================
// Initialize
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Ring 3D Tower of Hanoi - RingRayLib")
SetTargetFPS(60)

discColors = [
    [230, 50, 40],      // 1  red
    [240, 120, 30],     // 2  orange
    [240, 200, 30],     // 3  yellow
    [80, 200, 40],      // 4  green
    [30, 180, 180],     // 5  teal
    [40, 100, 230],     // 6  blue
    [100, 50, 220],     // 7  indigo
    [180, 40, 200],     // 8  purple
    [220, 60, 150],     // 9  pink
    [160, 100, 60]      // 10 brown
]

han_resetGame()

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
        han_resetGame()
        gameState = ST_PLAYING
    ok

    if IsKeyPressed(KEY_EQUAL) or IsKeyPressed(KEY_KP_ADD)
        if numDiscs < MAX_DISCS
            numDiscs += 1
            han_resetGame()
            gameState = ST_PLAYING
        ok
    ok
    if IsKeyPressed(KEY_MINUS) or IsKeyPressed(KEY_KP_SUBTRACT)
        if numDiscs > MIN_DISCS
            numDiscs -= 1
            han_resetGame()
            gameState = ST_PLAYING
        ok
    ok

    // --- State updates ---
    if gameState = ST_START
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(0)
            han_resetGame()
            gameState = ST_PLAYING
        ok
    but gameState = ST_PLAYING
        han_updateMouseHover()
        han_handleInput()
        han_handleMouse()

        if timerRunning
            gameTimer += dt
        ok
    but gameState = ST_ANIMATING
        han_updateAnimation(dt)
        if timerRunning
            gameTimer += dt
        ok
    but gameState = ST_AUTOSOLVE
        han_updateAutoSolve(dt)
        han_updateAnimation(dt)
        if timerRunning
            gameTimer += dt
        ok
    but gameState = ST_WON
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(0)
            han_resetGame()
            gameState = ST_PLAYING
        ok
    ok

    han_updateParticles(dt)
    han_positionCamera()

    // --- Drawing ---
    BeginDrawing()
        ClearBackground(RAYLIBColor(18, 22, 32, 255))

        if gameState = ST_START
            han_drawTitleScreen()
        else
            BeginMode3D(
                Camera3D(
                    camPosX, camPosY, camPosZ,
                    camTgtX, camTgtY, camTgtZ,
                    0, 1, 0, 45.0, 0
                )
            )
                han_drawPlatform3D()
                han_drawPegs3D()
                han_drawDiscs3D()
                han_drawAnimDisc3D()
                han_drawSelection3D()
                han_drawParticles3D()
            EndMode3D()

            han_drawHUD()

            if gameState = ST_WON
                han_drawWinOverlay()
            ok
        ok

        DrawFPS(10, 10)
    EndDrawing()

end

CloseWindow()

// =============================================================
// Reset Game
// =============================================================

func han_resetGame
    pegs = list(NUM_PEGS)
    for i = 1 to NUM_PEGS
        pegs[i] = []
    next

    // All discs on peg 1, largest (numDiscs) at bottom
    for d = numDiscs to 1 step -1
        add(pegs[1], d)
    next

    optimalMoves = 1
    for _i = 1 to numDiscs
        optimalMoves = optimalMoves * 2
    next
    optimalMoves = optimalMoves - 1
    moveCount = 0
    selectedPeg = 0
    cursorPeg = 1
    gameTimer = 0.0
    timerRunning = false
    undoStack = []
    autoMoves = []
    autoIndex = 0
    autoDelay = 0.0
    animPhase = 0
    particles = []

// =============================================================
// Input Handling
// =============================================================

func han_handleInput
    if animPhase != 0 return ok

    // Cursor movement
    if IsKeyPressed(KEY_LEFT) or IsKeyPressed(KEY_A)
        cursorPeg -= 1
        if cursorPeg < 1 cursorPeg = 1 ok
    ok
    if IsKeyPressed(KEY_RIGHT) or IsKeyPressed(KEY_D)
        cursorPeg += 1
        if cursorPeg > NUM_PEGS cursorPeg = NUM_PEGS ok
    ok

    // Direct peg selection
    if IsKeyPressed(KEY_ONE)   han_selectPeg(1) ok
    if IsKeyPressed(KEY_TWO)   han_selectPeg(2) ok
    if IsKeyPressed(KEY_THREE) han_selectPeg(3) ok

    // Confirm with Enter/Space
    if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
        han_selectPeg(cursorPeg)
    ok

    // Undo
    if IsKeyPressed(KEY_U)
        han_undoMove()
    ok

    // Auto-solve
    if IsKeyPressed(KEY_A)
        han_startAutoSolve()
    ok

func han_selectPeg pegNum
    if selectedPeg = 0
        // Selecting source peg
        if len(pegs[pegNum]) > 0
            selectedPeg = pegNum
        ok
    else
        if pegNum = selectedPeg
            // Deselect
            selectedPeg = 0
        else
            // Try to move from selectedPeg to pegNum
            han_tryMove(selectedPeg, pegNum)
            selectedPeg = 0
        ok
    ok

func han_tryMove fromPeg, toPeg
    if len(pegs[fromPeg]) = 0 return ok

    disc = pegs[fromPeg][len(pegs[fromPeg])]

    // Check if valid move
    if len(pegs[toPeg]) > 0
        topDisc = pegs[toPeg][len(pegs[toPeg])]
        if disc > topDisc
            // Invalid move - disc too large
            han_spawnErrorParticles(toPeg)
            return
        ok
    ok

    // Start animation (preserve ST_AUTOSOLVE if active)
    animFromPeg = fromPeg
    animToPeg = toPeg
    animDiscSize = disc
    animPhase = ANIM_LIFT
    animProgress = 0.0

    // Remove disc from source (it's now "in the air")
    del(pegs[fromPeg], len(pegs[fromPeg]))

    // Set initial position
    animDiscX = han_pegX(fromPeg)
    animDiscY = PLATFORM_Y + len(pegs[fromPeg]) * DISC_H + DISC_H / 2
    animDiscZ = 0.0

    // Calculate lift height
    maxStack = len(pegs[fromPeg])
    maxStack2 = len(pegs[toPeg])
    if maxStack2 > maxStack maxStack = maxStack2 ok
    animLiftY = PLATFORM_Y + (maxStack + 2) * DISC_H + 2.0

    if gameState != ST_AUTOSOLVE
        gameState = ST_ANIMATING
    ok
    if !timerRunning timerRunning = true ok

    // Record move for undo
    add(undoStack, [fromPeg, toPeg, disc])
    moveCount += 1

// =============================================================
// Animation
// =============================================================

func han_updateAnimation dt
    if animPhase = 0 return ok

    animProgress += dt * animSpeed

    if animPhase = ANIM_LIFT
        // Lift disc up
        startY = PLATFORM_Y + len(pegs[animFromPeg]) * DISC_H + DISC_H / 2
        t = animProgress
        if t > 1.0 t = 1.0 ok
        // Smooth ease-out
        et = 1.0 - (1.0 - t) * (1.0 - t)
        animDiscY = startY + (animLiftY - startY) * et

        if animProgress >= 1.0
            animPhase = ANIM_MOVE
            animProgress = 0.0
            animDiscY = animLiftY
        ok
    ok

    if animPhase = ANIM_MOVE
        // Move horizontally
        fromX = han_pegX(animFromPeg)
        toX = han_pegX(animToPeg)
        t = animProgress
        if t > 1.0 t = 1.0 ok
        // Smooth ease-in-out
        et = t * t * (3.0 - 2.0 * t)
        animDiscX = fromX + (toX - fromX) * et

        // Slight arc upward during horizontal movement
        arcH = sin(t * 3.14159265) * 1.0
        animDiscY = animLiftY + arcH

        if animProgress >= 1.0
            animPhase = ANIM_DROP
            animProgress = 0.0
            animDiscX = toX
        ok
    ok

    if animPhase = ANIM_DROP
        // Drop disc onto target
        targetY = PLATFORM_Y + len(pegs[animToPeg]) * DISC_H + DISC_H / 2
        t = animProgress
        if t > 1.0 t = 1.0 ok
        // Ease-in (accelerate like gravity)
        et = t * t
        animDiscY = animLiftY + (targetY - animLiftY) * et

        if animProgress >= 1.0
            // Place disc on target peg
            add(pegs[animToPeg], animDiscSize)
            animPhase = 0
            han_spawnDropParticles(animToPeg, animDiscSize)

            // Check win condition
            if han_checkWin()
                gameState = ST_WON
                timerRunning = false
                han_spawnWinParticles()
            else
                if gameState = ST_AUTOSOLVE
                    // Continue auto-solving
                    autoDelay = autoWait
                else
                    gameState = ST_PLAYING
                ok
            ok
        ok
    ok

// =============================================================
// Auto-Solve
// =============================================================

func han_startAutoSolve
    // Reset to initial state
    han_resetGame()
    gameState = ST_AUTOSOLVE
    timerRunning = true

    // Generate solution moves
    autoMoves = []
    han_solveHanoi(numDiscs, 1, 3, 2)
    autoIndex = 1
    autoDelay = 0.5

func han_solveHanoi n, from, to, aux
    if n = 0 return ok
    han_solveHanoi(n - 1, from, aux, to)
    add(autoMoves, [from, to])
    han_solveHanoi(n - 1, aux, to, from)

func han_updateAutoSolve dt
    if animPhase != 0 return ok  // Wait for current animation

    autoDelay -= dt
    if autoDelay > 0 return ok

    if autoIndex > len(autoMoves)
        // All moves done, should be won already
        return
    ok

    fromPeg = autoMoves[autoIndex][1]
    toPeg = autoMoves[autoIndex][2]
    autoIndex += 1
    han_tryMove(fromPeg, toPeg)

// =============================================================
// Undo
// =============================================================

func han_undoMove
    if animPhase != 0 return ok
    if len(undoStack) = 0 return ok

    lastMove = undoStack[len(undoStack)]
    del(undoStack, len(undoStack))

    fromPeg = lastMove[1]
    toPeg = lastMove[2]
    disc = lastMove[3]

    // Move disc back (reverse: from toPeg to fromPeg)
    if len(pegs[toPeg]) > 0
        if pegs[toPeg][len(pegs[toPeg])] = disc
            del(pegs[toPeg], len(pegs[toPeg]))
            add(pegs[fromPeg], disc)
            moveCount -= 1
            if moveCount < 0 moveCount = 0 ok
        ok
    ok

// =============================================================
// Win Check
// =============================================================

func han_checkWin
    // All discs on peg 3
    if len(pegs[NUM_PEGS]) = numDiscs
        return true
    ok
    return false

// =============================================================
// Coordinate Helpers
// =============================================================

func han_pegX pegNum
    return (pegNum - 2) * PEG_SPACING   // Peg 1=-5, 2=0, 3=5

func han_discRadius discSize
    // Map disc size (1..numDiscs) to radius (MIN_DISC_RAD..MAX_DISC_RAD)
    if numDiscs <= 1 return MAX_DISC_RAD ok
    t = (discSize - 1.0) / (numDiscs - 1.0)
    return MIN_DISC_RAD + t * (MAX_DISC_RAD - MIN_DISC_RAD)

// =============================================================
// Manual 3D to Screen Projection
// =============================================================

func han_projectToScreen wx, wy, wz
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
// Mouse Handling
// =============================================================

func han_updateMouseHover
    if animPhase != 0 return ok

    mx = GetMouseX()
    my = GetMouseY()

    bestDist = 999999.0
    bestPeg = 0

    for p = 1 to NUM_PEGS
        wx = han_pegX(p)
        han_projectToScreen(wx, 2.0, 0.0)
        dx = projScreenX - mx
        dy = projScreenY - my
        dist = dx * dx + dy * dy
        if dist < bestDist
            bestDist = dist
            bestPeg = p
        ok
    next

    if bestDist < 25000
        mouseHoverPeg = bestPeg
        cursorPeg = bestPeg
    else
        mouseHoverPeg = 0
    ok

func han_handleMouse
    if animPhase != 0 return ok

    if IsMouseButtonPressed(0)
        if mouseHoverPeg >= 1 and mouseHoverPeg <= NUM_PEGS
            han_selectPeg(mouseHoverPeg)
        ok
    ok
    if IsMouseButtonPressed(1)
        selectedPeg = 0   // Right click deselects
    ok

// =============================================================
// Particles
// =============================================================

func han_spawnDropParticles pegNum, discSize
    wx = han_pegX(pegNum)
    rad = han_discRadius(discSize)
    ci = discSize
    if ci < 1 ci = 1 ok
    if ci > 10 ci = 10 ok
    cr = discColors[ci][1]
    cg = discColors[ci][2]
    cb = discColors[ci][3]
    for i = 1 to 8
        angle = (i / 8.0) * 3.14159265 * 2.0
        vx = cos(angle) * rad * 1.5
        vy = (GetRandomValue(80, 200) / 100.0)
        vz = sin(angle) * rad * 1.5
        add(particles, [wx + cos(angle) * rad * 0.5, PLATFORM_Y + 0.3,
                        sin(angle) * rad * 0.5,
                        vx, vy, vz, 0.8, cr, cg, cb])
    next

func han_spawnErrorParticles pegNum
    wx = han_pegX(pegNum)
    for i = 1 to 10
        vx = (GetRandomValue(-100, 100) / 100.0) * 1.5
        vy = (GetRandomValue(50, 250) / 100.0)
        vz = (GetRandomValue(-100, 100) / 100.0) * 1.5
        add(particles, [wx, 1.0, 0.0, vx, vy, vz, 0.6, 255, 50, 30])
    next

func han_spawnWinParticles
    for i = 1 to 60
        wx = (GetRandomValue(-80, 80) / 10.0)
        wy = (GetRandomValue(0, 40) / 10.0)
        vx = (GetRandomValue(-100, 100) / 100.0) * 2.0
        vy = (GetRandomValue(150, 500) / 100.0) * 2.0
        vz = (GetRandomValue(-100, 100) / 100.0) * 2.0
        cr = GetRandomValue(100, 255)
        cg = GetRandomValue(150, 255)
        cb = GetRandomValue(30, 150)
        add(particles, [wx, wy, 0.0, vx, vy, vz, 3.0, cr, cg, cb])
    next

func han_updateParticles dt
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

func han_drawParticles3D
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
        sz = 0.04 + life * 0.03
        DrawSphere(Vector3(px, py, pz), sz,
                   RAYLIBColor(pr, pg, pb, alpha))
    next

// =============================================================
// Camera
// =============================================================

func han_positionCamera
    if cameraMode = CAM_FRONT
        goalPX = 0.0
        goalPY = 4.5
        goalPZ = 16.0
        goalTX = 0.0
        goalTY = 2.5
        goalTZ = 0.0
    ok

    if cameraMode = CAM_ANGLE
        goalPX = 8.0
        goalPY = 7.0
        goalPZ = 12.0
        goalTX = 0.0
        goalTY = 2.0
        goalTZ = 0.0
    ok

    if cameraMode = CAM_TOP
        goalPX = 0.0
        goalPY = 18.0
        goalPZ = 3.0
        goalTX = 0.0
        goalTY = 0.0
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
// 3D Drawing: Platform
// =============================================================

func han_drawPlatform3D
    // Main platform
    platW = PEG_SPACING * 2 + MAX_DISC_RAD * 2 + 2.0
    platD = MAX_DISC_RAD * 2 + 1.5
    platH = 0.35

    DrawCube(Vector3(0, PLATFORM_Y - platH / 2, 0), platW, platH, platD,
             RAYLIBColor(90, 65, 40, 255))

    // Top surface (lighter wood)
    DrawCube(Vector3(0, PLATFORM_Y + 0.01, 0), platW - 0.1, 0.02, platD - 0.1,
             RAYLIBColor(120, 90, 55, 255))

    // Peg labels on platform
    for p = 1 to NUM_PEGS
        px = han_pegX(p)
        // Small circle marker at base of each peg
        DrawCylinder(Vector3(px, PLATFORM_Y + 0.02, 0), 0.4, 0.4, 0.02, 16,
                     RAYLIBColor(70, 55, 35, 255))
    next

// =============================================================
// 3D Drawing: Pegs
// =============================================================

func han_drawPegs3D
    pegHeight = (numDiscs + 1.5) * DISC_H + 1.0

    for p = 1 to NUM_PEGS
        px = han_pegX(p)

        // Peg body (dark brown cylinder)
        DrawCylinder(Vector3(px, PLATFORM_Y, 0), PEG_RADIUS, PEG_RADIUS * 0.8,
                     pegHeight, 12,
                     RAYLIBColor(80, 55, 30, 255))

        // Peg cap (rounded top)
        DrawSphere(Vector3(px, PLATFORM_Y + pegHeight, 0), PEG_RADIUS * 1.3,
                   RAYLIBColor(100, 70, 40, 255))

        // Peg base ring
        DrawCylinder(Vector3(px, PLATFORM_Y + 0.02, 0), PEG_RADIUS * 2.5,
                     PEG_RADIUS * 2.0, 0.08, 16,
                     RAYLIBColor(100, 75, 45, 255))
    next

// =============================================================
// 3D Drawing: Discs on Pegs
// =============================================================

func han_drawDiscs3D
    for p = 1 to NUM_PEGS
        for d = 1 to len(pegs[p])
            discSize = pegs[p][d]
            px = han_pegX(p)
            py = PLATFORM_Y + (d - 1) * DISC_H + DISC_H / 2
            rad = han_discRadius(discSize)

            ci = discSize
            if ci < 1 ci = 1 ok
            if ci > 10 ci = 10 ok
            cr = discColors[ci][1]
            cg = discColors[ci][2]
            cb = discColors[ci][3]

            han_drawDisc3DAt(px, py, 0.0, rad, cr, cg, cb, 255)
        next
    next

func han_drawDisc3DAt px, py, pz, rad, cr, cg, cb, alpha
    // Main disc body
    DrawCylinder(Vector3(px, py - DISC_H / 2 + 0.02, pz),
                 rad, rad, DISC_H - 0.04, 20,
                 RAYLIBColor(cr, cg, cb, alpha))

    // Top bevel (lighter)
    hr = cr + 50   if hr > 255 hr = 255 ok
    hg = cg + 50   if hg > 255 hg = 255 ok
    hb = cb + 50   if hb > 255 hb = 255 ok
    DrawCylinder(Vector3(px, py + DISC_H / 2 - 0.06, pz),
                 rad - 0.02, rad - 0.06, 0.06, 20,
                 RAYLIBColor(hr, hg, hb, alpha))

    // Bottom bevel (darker)
    dr = floor(cr * 0.6)
    dg = floor(cg * 0.6)
    db = floor(cb * 0.6)
    DrawCylinder(Vector3(px, py - DISC_H / 2, pz),
                 rad - 0.06, rad - 0.02, 0.06, 20,
                 RAYLIBColor(dr, dg, db, alpha))

    // Center hole (dark cylinder)
    DrawCylinder(Vector3(px, py - DISC_H / 2 + 0.01, pz),
                 PEG_RADIUS + 0.04, PEG_RADIUS + 0.04, DISC_H - 0.02, 10,
                 RAYLIBColor(40, 30, 20, alpha))

// =============================================================
// 3D Drawing: Animated Disc
// =============================================================

func han_drawAnimDisc3D
    if animPhase = 0 return ok

    rad = han_discRadius(animDiscSize)
    ci = animDiscSize
    if ci < 1 ci = 1 ok
    if ci > 10 ci = 10 ok
    cr = discColors[ci][1]
    cg = discColors[ci][2]
    cb = discColors[ci][3]

    han_drawDisc3DAt(animDiscX, animDiscY, animDiscZ, rad, cr, cg, cb, 255)

    // Subtle glow
    DrawSphere(Vector3(animDiscX, animDiscY, animDiscZ), rad * 0.3,
               RAYLIBColor(cr, cg, cb, 30))

// =============================================================
// 3D Drawing: Selection Highlight
// =============================================================

func han_drawSelection3D
    if gameState != ST_PLAYING return ok

    // Cursor indicator
    px = han_pegX(cursorPeg)
    pegHeight = (numDiscs + 1.5) * DISC_H + 1.0
    pulse = 0.6 + sin(animTime * 4.0) * 0.4

    if selectedPeg = 0
        // Show cursor: green ring around peg base
        DrawCylinder(Vector3(px, PLATFORM_Y + 0.03, 0), MAX_DISC_RAD + 0.3,
                     MAX_DISC_RAD + 0.3, 0.03, 20,
                     RAYLIBColor(80, 255, 100, floor(pulse * 80)))
    else
        // Selected peg: yellow glow
        selX = han_pegX(selectedPeg)
        DrawCylinder(Vector3(selX, PLATFORM_Y + 0.03, 0), MAX_DISC_RAD + 0.3,
                     MAX_DISC_RAD + 0.3, 0.03, 20,
                     RAYLIBColor(255, 220, 50, floor(pulse * 100)))

        // Target cursor: green/red depending on validity
        if cursorPeg != selectedPeg
            canMove = true
            if len(pegs[selectedPeg]) > 0
                srcDisc = pegs[selectedPeg][len(pegs[selectedPeg])]
                if len(pegs[cursorPeg]) > 0
                    tgtDisc = pegs[cursorPeg][len(pegs[cursorPeg])]
                    if srcDisc > tgtDisc canMove = false ok
                ok
            else
                canMove = false
            ok

            if canMove
                DrawCylinder(Vector3(px, PLATFORM_Y + 0.03, 0), MAX_DISC_RAD + 0.3,
                             MAX_DISC_RAD + 0.3, 0.03, 20,
                             RAYLIBColor(80, 255, 100, floor(pulse * 80)))
            else
                DrawCylinder(Vector3(px, PLATFORM_Y + 0.03, 0), MAX_DISC_RAD + 0.3,
                             MAX_DISC_RAD + 0.3, 0.03, 20,
                             RAYLIBColor(255, 60, 40, floor(pulse * 80)))
            ok
        ok

        // Arrow above selected peg top disc
        if len(pegs[selectedPeg]) > 0
            topIdx = len(pegs[selectedPeg])
            topY = PLATFORM_Y + topIdx * DISC_H + 0.5
            bob = sin(animTime * 6.0) * 0.15
            DrawSphere(Vector3(selX, topY + bob, 0), 0.12,
                       RAYLIBColor(255, 220, 50, floor(pulse * 255)))
        ok
    ok

// =============================================================
// HUD
// =============================================================

func han_drawHUD
    panelW = 240
    panelH = 150
    DrawRectangle(10, 30, panelW, panelH, RAYLIBColor(0, 0, 0, 190))
    DrawRectangleLines(10, 30, panelW, panelH, RAYLIBColor(80, 100, 160, 200))

    DrawText("TOWER OF HANOI", 20, 38, 16, RAYLIBColor(100, 180, 255, 255))

    DrawText("Discs: " + string(numDiscs) + "  [+/-]", 20, 58, 14,
             RAYLIBColor(180, 200, 140, 220))

    DrawText("Moves: " + string(moveCount), 20, 78, 18,
             RAYLIBColor(255, 255, 100, 255))

    optStr = "Optimal: " + string(floor(optimalMoves))
    DrawText(optStr, 130, 80, 14, RAYLIBColor(140, 180, 160, 200))

    // Efficiency
    if moveCount > 0
        eff = floor(optimalMoves * 100.0 / moveCount)
        if eff > 100 eff = 100 ok
        effCol = RAYLIBColor(100, 255, 100, 255)
        if eff < 80 effCol = RAYLIBColor(255, 200, 50, 255) ok
        if eff < 50 effCol = RAYLIBColor(255, 80, 50, 255) ok
        DrawText("Efficiency: " + string(eff) + "%", 20, 100, 14, effCol)
    ok

    // Timer
    mins = floor(gameTimer / 60)
    secs = floor(gameTimer) % 60
    timeStr = "" + string(mins) + ":"
    if secs < 10 timeStr += "0" ok
    timeStr += string(secs)
    DrawText("Time: " + timeStr, 20, 120, 16,
             RAYLIBColor(200, 200, 100, 255))

    // Camera mode
    camName = "FRONT"
    if cameraMode = CAM_ANGLE camName = "ANGLE" ok
    if cameraMode = CAM_TOP   camName = "TOP"   ok
    DrawText("Cam: " + camName + "  [C]", 20, 142, 13,
             RAYLIBColor(120, 140, 170, 180))

    // Peg labels
    for p = 1 to NUM_PEGS
        px = han_pegX(p)
        han_projectToScreen(px, PLATFORM_Y - 0.3, 0.0)
        lbl = string(p)
        lw = MeasureText(lbl, 20)
        sx = floor(projScreenX) - floor(lw / 2)
        sy = floor(projScreenY)
        if sy > 0 and sy < SCREEN_H
            DrawText(lbl, sx, sy, 20, RAYLIBColor(180, 200, 220, 200))
        ok
    next

    // Auto-solve indicator
    if gameState = ST_AUTOSOLVE
        DrawRectangle(floor(SCREEN_W / 2) - 80, 35, 160, 28, RAYLIBColor(0, 0, 0, 200))
        aText = "AUTO-SOLVING..."
        aw = MeasureText(aText, 18)
        DrawText(aText, floor((SCREEN_W - aw) / 2), 40, 18,
                 RAYLIBColor(255, 200, 50, 255))
    ok

    // Bottom controls
    DrawRectangle(10, SCREEN_H - 60, 350, 25, RAYLIBColor(0, 0, 0, 153))
    DrawText("[1/2/3] Select Peg | [U] Undo | [A] Auto-Solve | [R] Restart",
             16, SCREEN_H - 56, 12, RAYLIBColor(150, 170, 200, 220))

    DrawRectangle(SCREEN_W - 420, SCREEN_H - 35, 410, 25, RAYLIBColor(0, 0, 0, 153))
    DrawText("Arrows: Move Cursor | Space: Select | +/-: Discs | C: Camera",
             SCREEN_W - 415, SCREEN_H - 30, 12, RAYLIBColor(150, 160, 180, 200))

// =============================================================
// Title Screen
// =============================================================

func han_drawTitleScreen
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(18, 22, 32, 255))

    t1 = "3D TOWER OF HANOI"
    t1w = MeasureText(t1, 44)
    t1x = floor((SCREEN_W - t1w) / 2)
    DrawText(t1, t1x + 3, 43, 44, RAYLIBColor(40, 30, 15, 200))
    DrawText(t1, t1x, 40, 44, RAYLIBColor(230, 180, 80, 255))

    t2 = "~ The classic mathematical puzzle in 3D! ~"
    t2w = MeasureText(t2, 16)
    DrawText(t2, floor((SCREEN_W - t2w) / 2), 92, 16, RAYLIBColor(160, 140, 100, 220))

    cy = 130
    cLines = [
        "1 / 2 / 3              -   Select peg directly",
        "Left / Right           -   Move cursor between pegs",
        "ENTER / SPACE          -   Select peg / Confirm move",
        "Mouse Left Click       -   Select peg / Confirm move",
        "Mouse Right Click      -   Deselect",
        "U                      -   Undo last move",
        "A                      -   Auto-solve (watch solution!)",
        "R                      -   Restart game",
        "+  /  -                -   Change disc count (3-10)",
        "C                      -   Cycle camera view",
        "",
        "Rules:",
        "  Move ALL discs from Peg 1 (left) to Peg 3 (right)",
        "  Move only ONE disc at a time (from top of a peg)",
        "  A larger disc can NEVER go on top of a smaller one",
        "  Minimum moves needed = 2^n - 1"
    ]
    for i = 1 to len(cLines)
        lw = MeasureText(cLines[i], 14)
        if i >= 12
            col = RAYLIBColor(255, 200, 100, 210)
        else
            col = RAYLIBColor(150, 170, 200, 230)
        ok
        DrawText(cLines[i], floor((SCREEN_W - lw) / 2), cy + (i - 1) * 21, 14, col)
    next

    // Disc count selector
    boxW = 300
    boxH = 60
    boxX = floor((SCREEN_W - boxW) / 2)
    boxY = 490
    DrawRectangle(boxX, boxY, boxW, boxH, RAYLIBColor(30, 40, 60, 220))
    DrawRectangleLines(boxX, boxY, boxW, boxH, RAYLIBColor(120, 150, 200, 180))

    dTitle = "DISCS: " + string(numDiscs)
    dtw = MeasureText(dTitle, 22)
    DrawText(dTitle, floor((SCREEN_W - dtw) / 2), boxY + 8, 22,
             RAYLIBColor(230, 180, 80, 255))

    optVal = 1
    for _i = 1 to numDiscs
        optVal = optVal * 2
    next
    optVal = optVal - 1
    optText = "(Optimal: " + string(optVal) + " moves)"
    otw = MeasureText(optText, 14)
    DrawText(optText, floor((SCREEN_W - otw) / 2), boxY + 36, 14,
             RAYLIBColor(140, 160, 180, 200))

    // Disc preview
    previewY = 568
    for d = 1 to numDiscs
        ci = d
        if ci > 10 ci = 10 ok
        cr = discColors[ci][1]
        cg = discColors[ci][2]
        cb = discColors[ci][3]
        w = 12 + d * 6
        bx = floor(SCREEN_W / 2) - floor(w / 2)
        by = previewY + (numDiscs - d) * 10
        DrawRectangle(bx, by, w, 8, RAYLIBColor(cr, cg, cb, 255))
    next

    if floor(animTime * 2) % 2 = 0
        st = "Click or Press ENTER / SPACE to Start"
        stw = MeasureText(st, 24)
        DrawText(st, floor((SCREEN_W - stw) / 2), SCREEN_H - 80, 24,
                 RAYLIBColor(255, 255, 255, 255))
    ok

    cr = "Developed using Ring Language + RingRayLib"
    crw = MeasureText(cr, 14)
    DrawText(cr, floor((SCREEN_W - crw) / 2), SCREEN_H - 35, 14,
             RAYLIBColor(60, 70, 50, 180))

// =============================================================
// Win Overlay
// =============================================================

func han_drawWinOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 150))

    wText = "CONGRATULATIONS!"
    tw = MeasureText(wText, 50)
    tx = floor((SCREEN_W - tw) / 2)
    DrawText(wText, tx + 3, 183, 50, RAYLIBColor(0, 0, 0, 130))
    DrawText(wText, tx, 180, 50, RAYLIBColor(255, 220, 50, 255))

    // Subtitle
    sub = "Tower of Hanoi Solved!"
    sw = MeasureText(sub, 22)
    DrawText(sub, floor((SCREEN_W - sw) / 2), 240, 22,
             RAYLIBColor(200, 220, 255, 240))

    // Stats
    stat1 = "Moves: " + string(moveCount) + " / " + string(floor(optimalMoves)) + " optimal"
    s1w = MeasureText(stat1, 20)
    DrawText(stat1, floor((SCREEN_W - s1w) / 2), 280, 20,
             RAYLIBColor(255, 255, 100, 240))

    // Efficiency
    eff = floor(optimalMoves * 100.0 / moveCount)
    if eff > 100 eff = 100 ok
    stat2 = "Efficiency: " + string(eff) + "%"
    s2w = MeasureText(stat2, 20)
    effCol = RAYLIBColor(100, 255, 100, 255)
    if eff < 80 effCol = RAYLIBColor(255, 200, 50, 255) ok
    if eff < 50 effCol = RAYLIBColor(255, 80, 50, 255) ok
    DrawText(stat2, floor((SCREEN_W - s2w) / 2), 310, 20, effCol)

    // Time
    mins = floor(gameTimer / 60)
    secs = floor(gameTimer) % 60
    timeStr = "Time: " + string(mins) + ":"
    if secs < 10 timeStr += "0" ok
    timeStr += string(secs)
    ttw = MeasureText(timeStr, 20)
    DrawText(timeStr, floor((SCREEN_W - ttw) / 2), 340, 20,
             RAYLIBColor(200, 200, 100, 230))

    // Stars
    stars = 1
    if eff >= 80 stars = 2 ok
    if eff >= 100 stars = 3 ok
    starStr = ""
    for i = 1 to stars
        starStr += "* "
    next
    ssw = MeasureText(starStr, 40)
    DrawText(starStr, floor((SCREEN_W - ssw) / 2), 375, 40,
             RAYLIBColor(255, 220, 50, 255))

    hint = "Click or Press ENTER to Play Again"
    hw = MeasureText(hint, 20)
    DrawText(hint, floor((SCREEN_W - hw) / 2), 430, 20,
             RAYLIBColor(180, 190, 210, 220))
