/*
**  3D Laser Puzzle Game - Using RingRayLib
**  ==========================================
**  Redirect a laser beam from the emitter to the target
**  by placing and rotating mirrors on the grid!
**  A laser-reflection puzzle game rendered in full 3D
**  with beam tracing, animations, and visual effects.
**
**  Controls:
**    Arrow Keys / WASD  - Move cursor on the grid
**    Mouse              - Hover and click to select / rotate
**    ENTER / SPACE      - Rotate selected mirror clockwise
**    Q                  - Rotate selected mirror counter-clockwise
**    U                  - Undo last action
**    N                  - Next level
**    B                  - Previous level
**    R                  - Restart current level
**    C                  - Cycle camera views
**    ESC                - Exit
**
**  Piece Types:
**    Emitter (E)        - Fires the laser beam (fixed)
**    Target  (T)        - Must be hit by the beam (fixed)
**    Mirror  (/)        - Reflects beam 90 degrees (rotatable)
**    Wall    (#)        - Blocks the beam (fixed)
**    Empty   (.)        - Open cell for placing mirrors
**
**  Features:
**    - 10 hand-crafted puzzle levels
**    - Real-time laser beam tracing with glow
**    - Smooth mirror rotation animation
**    - Three camera modes: Front-Angle / Isometric / Overhead
**    - Undo system (full state snapshots)
**    - Particle effects on beam hit and level complete
**    - Score tracking (moves, stars)
**    - Mini-board overlay (HUD)
**    - Mouse + keyboard support
**    - Title, playing, and win screens
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W        = 1024
SCREEN_H        = 768

MAX_GRID        = 8
CELL_SZ         = 1.5

// Cell types
CELL_EMPTY      = 0
CELL_WALL       = 1
CELL_EMITTER    = 2
CELL_TARGET     = 3
CELL_MIRROR     = 4

// Directions (for laser beam and emitter facing)
DIR_UP          = 1    // row - 1
DIR_RIGHT       = 2    // col + 1
DIR_DOWN        = 3    // row + 1
DIR_LEFT        = 4    // col - 1

// Mirror orientations (which way the mirror faces)
// MIR_NE: reflects UP<->RIGHT, LEFT<->DOWN  (like / mirror)
// MIR_NW: reflects UP<->LEFT, RIGHT<->DOWN  (like \ mirror)
// MIR_SE: same as NW (reflects UP<->LEFT)
// MIR_SW: same as NE (reflects UP<->RIGHT)
// Simplify to 2 orientations that cycle on rotation:
MIR_SLASH       = 1    // /  - reflects: UP->RIGHT, RIGHT->UP, DOWN->LEFT, LEFT->DOWN
MIR_BACKSLASH   = 2    // \  - reflects: UP->LEFT, LEFT->UP, DOWN->RIGHT, RIGHT->DOWN

// Game states
ST_START        = 1
ST_PLAYING      = 2
ST_ANIMATING    = 3
ST_WON          = 4

// Camera modes
CAM_FRONT       = 1
CAM_ISOMETRIC   = 2
CAM_OVERHEAD    = 3
CAM_COUNT       = 3

// =============================================================
// Level Data
// =============================================================
// Format: [gridRows, gridCols, emitterR, emitterC, emitterDir,
//          targetR, targetC,
//          [[wallR, wallC], ...],
//          [[mirrorR, mirrorC, orientation, fixed], ...]]

LEVELS = []
laser_buildLevels()

// =============================================================
// Global Variables
// =============================================================

grid            = []       // 2D: grid[r][c] = CELL type
gridRows        = 0
gridCols        = 0
mirrors         = []       // [[r, c, orientation, fixed], ...]
emitterR        = 0
emitterC        = 0
emitterDir      = DIR_RIGHT
targetR         = 0
targetC         = 0

cursorR         = 1
cursorC         = 1
currentLevel    = 1
gameState       = ST_START
animTime        = 0.0
moveCount       = 0

// Laser beam path: [[r, c, fromDir, toDir], ...]
beamPath        = []
beamHitTarget   = false

// Undo stack: full state snapshots
undoStack       = []

// Particles: [x, y, z, vx, vy, vz, life, r, g, b]
particles       = []

// Camera smoothing
cameraMode      = CAM_FRONT
camPosX = 0.0   camPosY = 12.0  camPosZ = 12.0
camTgtX = 0.0   camTgtY = 0.0   camTgtZ = 0.0

// Mouse hover
mouseHoverR     = 0
mouseHoverC     = 0
projScreenX     = 0.0
projScreenY     = 0.0

// Rotation animation
rotAnimActive   = false
rotAnimR        = 0
rotAnimC        = 0
rotAnimFrom     = 0.0
rotAnimTo       = 0.0
rotAnimProgress = 0.0
rotAnimSpeed    = 5.0

// Win celebration timer
winTimer        = 0.0

// Mirror selection/grab for moving
selectedMirror  = 0      // Index of selected mirror (0 = none)
grabMode        = false  // True when a mirror is picked up and being moved

// Move animation
moveAnimActive  = false
moveAnimIdx     = 0
moveAnimFromX   = 0.0
moveAnimFromZ   = 0.0
moveAnimToX     = 0.0
moveAnimToZ     = 0.0
moveAnimProgress = 0.0
moveAnimSpeed   = 5.0

// =============================================================
// Initialize (statements before functions)
// =============================================================

laser_loadLevel(currentLevel)

// =============================================================
// Main Program
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Ring 3D Laser Puzzle - RingRayLib")
SetTargetFPS(60)

camera = Camera3D(
    0, 12, 12,
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
        if cameraMode > CAM_COUNT cameraMode = CAM_FRONT ok
    ok

    if IsKeyPressed(KEY_R)
        laser_loadLevel(currentLevel)
        gameState = ST_PLAYING
    ok

    // --- State updates ---
    if gameState = ST_START
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(0)
            laser_loadLevel(currentLevel)
            gameState = ST_PLAYING
        ok
    ok

    if gameState = ST_PLAYING
        laser_updateMouseHover()
        laser_handleInput()
        laser_handleMouse()
        laser_traceBeam()
        laser_updateParticles(dt)

        if rotAnimActive
            rotAnimProgress += rotAnimSpeed * dt
            if rotAnimProgress >= 1.0
                rotAnimProgress = 1.0
                rotAnimActive = false
            ok
        ok

        if moveAnimActive
            moveAnimProgress += moveAnimSpeed * dt
            if moveAnimProgress >= 1.0
                moveAnimProgress = 1.0
                moveAnimActive = false
            ok
        ok

        // Check win (only after animations finish so player sees the final move)
        if beamHitTarget and !moveAnimActive and !rotAnimActive
            gameState = ST_WON
            winTimer = 0
            laser_spawnWinParticles()
        ok
    ok

    if gameState = ST_WON
        winTimer += dt
        laser_updateParticles(dt)
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(0)
            if winTimer > 0.5
                if currentLevel < len(LEVELS)
                    currentLevel += 1
                ok
                laser_loadLevel(currentLevel)
                gameState = ST_PLAYING
            ok
        ok
        if IsKeyPressed(KEY_N)
            if currentLevel < len(LEVELS)
                currentLevel += 1
            ok
            laser_loadLevel(currentLevel)
            gameState = ST_PLAYING
        ok
    ok

    // Level navigation (any state except title and won)
    if gameState = ST_PLAYING
        if IsKeyPressed(KEY_N)
            if currentLevel < len(LEVELS)
                currentLevel += 1
                laser_loadLevel(currentLevel)
                gameState = ST_PLAYING
            ok
        ok
        if IsKeyPressed(KEY_B)
            if currentLevel > 1
                currentLevel -= 1
                laser_loadLevel(currentLevel)
                gameState = ST_PLAYING
            ok
        ok
    ok

    laser_positionCamera()

    // --- Drawing ---
    BeginDrawing()
        ClearBackground(RAYLIBColor(10, 12, 20, 255))

        if gameState = ST_START
            laser_drawTitleScreen()
        else
            BeginMode3D(camera)
                laser_drawBoard3D()
                laser_drawPieces3D()
                laser_drawBeam3D()
                laser_drawCursor3D()
                laser_drawParticles3D()
            EndMode3D()

            laser_drawHUD()
            laser_drawMiniBoard()

            if gameState = ST_WON
                laser_drawWinOverlay()
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
// Level Builder
// =============================================================

func laser_buildLevels
    // Level format: [rows, cols, eR, eC, eDir, tR, tC, walls, mirrors]
    // walls: [[r,c], ...]
    // mirrors: [[r,c,orient,fixed(0/1)], ...]  fixed=1 means pre-placed, immovable
    // Mirrors now start displaced from their solution positions!
    // Players must MOVE mirrors to correct cells AND ROTATE them.

    // Level 1: Tutorial - one mirror, needs to be moved right and rotated
    // Solution: mirror at (3,3) as /   Start: mirror at (3,5) as \
    add(LEVELS, [5, 5, 3, 1, DIR_RIGHT, 1, 3,
        [],
        [[3, 5, MIR_BACKSLASH, 0]]
    ])

    // Level 2: Two mirrors, both displaced
    // Solution: (5,3)/ and (1,3)\    Start: (5,5)\ and (1,1)/
    add(LEVELS, [5, 5, 5, 1, DIR_RIGHT, 1, 5,
        [],
        [[5, 5, MIR_BACKSLASH, 0], [1, 1, MIR_SLASH, 0]]
    ])

    // Level 3: Three mirrors, walls block direct path
    // Emitter (3,1) RIGHT, Target (3,6). Walls block (3,3)(3,4)(3,5).
    // Solution: (3,2)/ (1,2)/ (1,6)\
    //   beam RIGHT->(3,2)/ UP->(1,2)/ RIGHT->(1,6)\ DOWN->(3,6) TARGET
    // Start: mirrors at bottom row, wrong orientations
    add(LEVELS, [6, 6, 3, 1, DIR_RIGHT, 3, 6,
        [[3, 3, 0, 0], [3, 4, 0, 0], [3, 5, 0, 0]],
        [[6, 2, MIR_BACKSLASH, 0], [6, 4, MIR_BACKSLASH, 0], [5, 6, MIR_SLASH, 0]]
    ])

    // Level 4: Around wall block - mirrors displaced to wrong side
    // Solution: (6,1)\ (6,5)/ (1,5)\
    add(LEVELS, [6, 6, 1, 1, DIR_DOWN, 1, 6,
        [[2, 3, 0, 0], [3, 3, 0, 0], [4, 3, 0, 0]],
        [[6, 6, MIR_SLASH, 0], [4, 5, MIR_BACKSLASH, 0], [1, 2, MIR_SLASH, 0]]
    ])

    // Level 5: One fixed mirror, two movable
    // Fixed: (3,4)/ stays     Movable sol: (6,2)/ (5,4)\  Start: displaced
    add(LEVELS, [6, 6, 3, 1, DIR_RIGHT, 6, 2,
        [[4, 3, 0, 0]],
        [[3, 4, MIR_SLASH, 1], [5, 5, MIR_BACKSLASH, 0], [6, 4, MIR_SLASH, 0]]
    ])

    // Level 6: 7x7 grid, four mirrors all displaced
    // Solution: (1,4)/ (4,7)/ (7,4)\ (4,1)\
    add(LEVELS, [7, 7, 1, 1, DIR_RIGHT, 7, 7,
        [[4, 4, 0, 0]],
        [[2, 2, MIR_BACKSLASH, 0], [3, 7, MIR_BACKSLASH, 0],
         [7, 2, MIR_SLASH, 0], [5, 1, MIR_SLASH, 0]]
    ])

    // Level 7: Spiral path - five mirrors, heavily displaced
    // Solution: (7,1)\ (7,6)/ (1,6)/ (1,4)/ (4,4)\
    add(LEVELS, [7, 7, 1, 1, DIR_DOWN, 4, 4,
        [[3, 2, 0, 0], [3, 3, 0, 0], [5, 5, 0, 0], [5, 6, 0, 0]],
        [[6, 2, MIR_SLASH, 0], [7, 7, MIR_BACKSLASH, 0], [2, 6, MIR_BACKSLASH, 0],
         [1, 2, MIR_BACKSLASH, 0], [4, 6, MIR_SLASH, 0]]
    ])

    // Level 8: 8x8 tight corridors - five mirrors displaced
    // Solution: (1,6)/ (4,6)\ (4,2)/ (8,2)\ (8,7)/
    add(LEVELS, [8, 8, 1, 1, DIR_RIGHT, 8, 8,
        [[2, 4, 0, 0], [3, 4, 0, 0], [6, 5, 0, 0], [7, 5, 0, 0]],
        [[1, 3, MIR_BACKSLASH, 0], [5, 6, MIR_SLASH, 0], [4, 1, MIR_BACKSLASH, 0],
         [8, 4, MIR_SLASH, 0], [7, 7, MIR_BACKSLASH, 0]]
    ])

    // Level 9: Multi-bounce - six mirrors, all scrambled
    // Solution: (4,4)/ (1,4)\ (1,7)/ (7,7)\ (7,5)/ (4,5)\
    add(LEVELS, [8, 8, 4, 1, DIR_RIGHT, 4, 8,
        [[2, 3, 0, 0], [6, 6, 0, 0]],
        [[3, 2, MIR_BACKSLASH, 0], [2, 4, MIR_SLASH, 0], [1, 8, MIR_BACKSLASH, 0],
         [8, 7, MIR_SLASH, 0], [8, 5, MIR_BACKSLASH, 0], [5, 5, MIR_SLASH, 0]]
    ])

    // Level 10: Grand finale - seven mirrors, all displaced and wrong orient
    // Solution: (8,1)\ (8,4)/ (5,4)\ (5,7)/ (2,7)\ (2,5)/ (1,5)\
    add(LEVELS, [8, 8, 1, 1, DIR_DOWN, 1, 8,
        [[3, 3, 0, 0], [3, 4, 0, 0], [6, 5, 0, 0], [6, 6, 0, 0]],
        [[7, 1, MIR_SLASH, 0], [8, 6, MIR_BACKSLASH, 0], [4, 4, MIR_SLASH, 0],
         [4, 7, MIR_BACKSLASH, 0], [2, 8, MIR_SLASH, 0], [1, 5, MIR_BACKSLASH, 0],
         [2, 2, MIR_SLASH, 0]]
    ])

// =============================================================
// Level Loading
// =============================================================

func laser_loadLevel levelNum
    if levelNum < 1 or levelNum > len(LEVELS) return ok

    lvl = LEVELS[levelNum]

    gridRows   = lvl[1]
    gridCols   = lvl[2]
    emitterR   = lvl[3]
    emitterC   = lvl[4]
    emitterDir = lvl[5]
    targetR    = lvl[6]
    targetC    = lvl[7]

    // Build grid
    grid = list(gridRows)
    for r = 1 to gridRows
        grid[r] = list(gridCols)
        for c = 1 to gridCols
            grid[r][c] = CELL_EMPTY
        next
    next

    // Place walls
    walls = lvl[8]
    for i = 1 to len(walls)
        wr = walls[i][1]
        wc = walls[i][2]
        if wr >= 1 and wr <= gridRows and wc >= 1 and wc <= gridCols
            grid[wr][wc] = CELL_WALL
        ok
    next

    // Place emitter and target
    grid[emitterR][emitterC] = CELL_EMITTER
    grid[targetR][targetC]   = CELL_TARGET

    // Place mirrors
    mirrors = []
    mirData = lvl[9]
    for i = 1 to len(mirData)
        mr = mirData[i][1]
        mc = mirData[i][2]
        mo = mirData[i][3]
        mf = mirData[i][4]
        add(mirrors, [mr, mc, mo, mf])
        grid[mr][mc] = CELL_MIRROR
    next

    cursorR     = emitterR
    cursorC     = emitterC
    moveCount   = 0
    undoStack   = []
    beamPath    = []
    beamHitTarget = false
    particles   = []
    rotAnimActive = false
    selectedMirror = 0
    grabMode    = false
    moveAnimActive = false
    winTimer    = 0

    laser_traceBeam()

// =============================================================
// Input Handling
// =============================================================

func laser_handleInput
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

    // G = Grab / Drop mirror (toggle)
    if IsKeyPressed(KEY_G)
        laser_handleGrabDrop(cursorR, cursorC)
    ok

    // Rotate clockwise (only if not in grab mode)
    if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
        if grabMode
            laser_handleGrabDrop(cursorR, cursorC)
        else
            laser_rotateMirrorAt(cursorR, cursorC, 1)
        ok
    ok

    // Rotate counter-clockwise
    if IsKeyPressed(KEY_Q)
        if !grabMode
            laser_rotateMirrorAt(cursorR, cursorC, -1)
        ok
    ok

    // Undo
    if IsKeyPressed(KEY_U)
        laser_undo()
    ok

    // Right-click or pressing G again cancels grab mode

// =============================================================
// Mouse Handling
// =============================================================

func laser_updateMouseHover
    mx = GetMouseX()
    my = GetMouseY()

    bestDist = 999999.0
    bestR = 0
    bestC = 0

    for r = 1 to gridRows
        for c = 1 to gridCols
            wx = laser_cellToX(c)
            wz = laser_cellToZ(r)
            laser_projectToScreen(wx, 0.1, wz)
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

func laser_handleMouse
    if IsMouseButtonPressed(0)
        if mouseHoverR >= 1 and mouseHoverR <= gridRows and
           mouseHoverC >= 1 and mouseHoverC <= gridCols
            if grabMode
                // Drop grabbed mirror at this location
                laser_handleGrabDrop(mouseHoverR, mouseHoverC)
            else
                // Check if clicking a movable mirror -> select it
                idx = laser_findMirror(mouseHoverR, mouseHoverC)
                if idx > 0 and mirrors[idx][4] = 0
                    // Select and grab this mirror
                    selectedMirror = idx
                    grabMode = true
                else
                    // Click on empty or non-mirror: try rotate if mirror at cursor
                    laser_rotateMirrorAt(mouseHoverR, mouseHoverC, 1)
                ok
            ok
        ok
    ok
    if IsMouseButtonPressed(1)  // Right click = rotate or cancel grab
        if grabMode
            grabMode = false
            selectedMirror = 0
        else
            if mouseHoverR >= 1 and mouseHoverR <= gridRows and
               mouseHoverC >= 1 and mouseHoverC <= gridCols
                laser_rotateMirrorAt(mouseHoverR, mouseHoverC, -1)
            ok
        ok
    ok

// =============================================================
// Mirror Rotation
// =============================================================

func laser_rotateMirrorAt r, c, direction
    idx = laser_findMirror(r, c)
    if idx = 0 return ok
    if mirrors[idx][4] = 1 return ok  // Fixed mirror

    // Save undo state
    laser_saveUndoState()
    moveCount += 1

    // Toggle orientation
    if mirrors[idx][3] = MIR_SLASH
        mirrors[idx][3] = MIR_BACKSLASH
    else
        mirrors[idx][3] = MIR_SLASH
    ok

    // Start rotation animation
    rotAnimActive = true
    rotAnimR = r
    rotAnimC = c
    rotAnimProgress = 0.0

    // Spawn particles
    wx = laser_cellToX(c)
    wz = laser_cellToZ(r)
    laser_spawnRotateParticles(wx, wz)

func laser_findMirror r, c
    for i = 1 to len(mirrors)
        if mirrors[i][1] = r and mirrors[i][2] = c
            return i
        ok
    next
    return 0

// =============================================================
// Mirror Grab / Drop / Move
// =============================================================

func laser_handleGrabDrop r, c
    if grabMode
        // Trying to drop the grabbed mirror at (r, c)
        if selectedMirror < 1 or selectedMirror > len(mirrors)
            grabMode = false
            selectedMirror = 0
            return
        ok

        // Check target cell is valid (empty, not wall/emitter/target/another mirror)
        srcR = mirrors[selectedMirror][1]
        srcC = mirrors[selectedMirror][2]

        // Dropping on same cell = deselect
        if r = srcR and c = srcC
            grabMode = false
            selectedMirror = 0
            return
        ok

        // Must be an empty cell
        if grid[r][c] != CELL_EMPTY
            return  // Can't drop here
        ok

        // Save undo state before moving
        laser_saveUndoState()
        moveCount += 1

        // Start move animation
        moveAnimActive   = true
        moveAnimIdx      = selectedMirror
        moveAnimFromX    = laser_cellToX(srcC)
        moveAnimFromZ    = laser_cellToZ(srcR)
        moveAnimToX      = laser_cellToX(c)
        moveAnimToZ      = laser_cellToZ(r)
        moveAnimProgress = 0.0

        // Update grid
        grid[srcR][srcC] = CELL_EMPTY
        grid[r][c]       = CELL_MIRROR

        // Update mirror position
        mirrors[selectedMirror][1] = r
        mirrors[selectedMirror][2] = c

        // Deselect
        grabMode = false
        selectedMirror = 0

        // Spawn particles at both positions
        laser_spawnRotateParticles(moveAnimFromX, moveAnimFromZ)
        laser_spawnRotateParticles(moveAnimToX, moveAnimToZ)

    else
        // Not in grab mode: try to grab a mirror at (r, c)
        idx = laser_findMirror(r, c)
        if idx > 0 and mirrors[idx][4] = 0
            selectedMirror = idx
            grabMode = true
        ok
    ok

func laser_saveUndoState
    mirCopy = []
    for i = 1 to len(mirrors)
        add(mirCopy, [mirrors[i][1], mirrors[i][2], mirrors[i][3], mirrors[i][4]])
    next
    add(undoStack, mirCopy)

// =============================================================
// Undo System
// =============================================================

func laser_undo
    if len(undoStack) = 0 return ok
    state = undoStack[len(undoStack)]
    del(undoStack, len(undoStack))

    // Clear all mirror cells from current grid
    for i = 1 to len(mirrors)
        mr = mirrors[i][1]
        mc = mirrors[i][2]
        if mr >= 1 and mr <= gridRows and mc >= 1 and mc <= gridCols
            grid[mr][mc] = CELL_EMPTY
        ok
    next

    // Restore mirror state
    mirrors = []
    for i = 1 to len(state)
        add(mirrors, [state[i][1], state[i][2], state[i][3], state[i][4]])
    next

    // Rebuild mirror cells on grid
    for i = 1 to len(mirrors)
        mr = mirrors[i][1]
        mc = mirrors[i][2]
        if mr >= 1 and mr <= gridRows and mc >= 1 and mc <= gridCols
            grid[mr][mc] = CELL_MIRROR
        ok
    next

    moveCount -= 1
    if moveCount < 0 moveCount = 0 ok
    selectedMirror = 0
    grabMode = false

    laser_traceBeam()

// =============================================================
// Laser Beam Tracing
// =============================================================

func laser_traceBeam
    beamPath = []
    beamHitTarget = false

    // Start from emitter
    r = emitterR
    c = emitterC
    dir = emitterDir

    maxSteps = gridRows * gridCols * 4  // Prevent infinite loops

    for step = 1 to maxSteps
        // Move in current direction
        nr = r
        nc = c
        if dir = DIR_UP    nr = r - 1 ok
        if dir = DIR_DOWN  nr = r + 1 ok
        if dir = DIR_LEFT  nc = c - 1 ok
        if dir = DIR_RIGHT nc = c + 1 ok

        // Check bounds
        if nr < 1 or nr > gridRows or nc < 1 or nc > gridCols
            // Beam exits grid
            add(beamPath, [r, c, nr, nc, dir])
            return
        ok

        // Record beam segment
        add(beamPath, [r, c, nr, nc, dir])

        // Check what's at the new cell
        if grid[nr][nc] = CELL_TARGET
            beamHitTarget = true
            return
        ok

        if grid[nr][nc] = CELL_WALL
            return  // Blocked
        ok

        if grid[nr][nc] = CELL_EMITTER
            return  // Hit emitter (shouldn't happen but safety)
        ok

        if grid[nr][nc] = CELL_MIRROR
            // Find mirror and reflect
            idx = laser_findMirror(nr, nc)
            if idx > 0
                orient = mirrors[idx][3]
                dir = laser_reflect(dir, orient)
                if dir = 0 return ok  // Invalid reflection
            ok
        ok

        // Move to next cell
        r = nr
        c = nc
    next

func laser_reflect inDir, orient
    if orient = MIR_SLASH
        // /  mirror: UP->RIGHT, RIGHT->UP, DOWN->LEFT, LEFT->DOWN
        if inDir = DIR_UP    return DIR_RIGHT ok
        if inDir = DIR_RIGHT return DIR_UP    ok
        if inDir = DIR_DOWN  return DIR_LEFT  ok
        if inDir = DIR_LEFT  return DIR_DOWN  ok
    ok
    if orient = MIR_BACKSLASH
        // \  mirror: UP->LEFT, LEFT->UP, DOWN->RIGHT, RIGHT->DOWN
        if inDir = DIR_UP    return DIR_LEFT  ok
        if inDir = DIR_LEFT  return DIR_UP    ok
        if inDir = DIR_DOWN  return DIR_RIGHT ok
        if inDir = DIR_RIGHT return DIR_DOWN  ok
    ok
    return 0

// =============================================================
// Coordinate Helpers
// =============================================================

func laser_cellToX c
    return (c - 1) * CELL_SZ - (gridCols - 1) * CELL_SZ / 2

func laser_cellToZ r
    return (r - 1) * CELL_SZ - (gridRows - 1) * CELL_SZ / 2

// =============================================================
// Manual 3D to Screen Projection
// =============================================================

func laser_projectToScreen wx, wy, wz
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
// Particles
// =============================================================

func laser_spawnRotateParticles wx, wz
    for i = 1 to 8
        vx = (GetRandomValue(-100, 100) / 100.0) * 1.5
        vy = (GetRandomValue(100, 300) / 100.0) * 1.2
        vz = (GetRandomValue(-100, 100) / 100.0) * 1.5
        cr = 150 + GetRandomValue(0, 105)
        cg = 200 + GetRandomValue(0, 55)
        cb = GetRandomValue(50, 150)
        add(particles, [wx, 0.4, wz, vx, vy, vz, 1.0, cr, cg, cb])
    next

func laser_spawnWinParticles
    // Particles along entire beam path
    for i = 1 to len(beamPath)
        r1 = beamPath[i][1]
        c1 = beamPath[i][2]
        wx = laser_cellToX(c1)
        wz = laser_cellToZ(r1)
        for j = 1 to 4
            vx = (GetRandomValue(-100, 100) / 100.0) * 2.0
            vy = (GetRandomValue(200, 500) / 100.0) * 1.5
            vz = (GetRandomValue(-100, 100) / 100.0) * 2.0
            cr = 255
            cg = GetRandomValue(50, 200)
            cb = GetRandomValue(0, 80)
            add(particles, [wx, 0.5, wz, vx, vy, vz, 1.5, cr, cg, cb])
        next
    next
    // Big burst at target
    wx = laser_cellToX(targetC)
    wz = laser_cellToZ(targetR)
    for j = 1 to 25
        vx = (GetRandomValue(-100, 100) / 100.0) * 3.0
        vy = (GetRandomValue(200, 600) / 100.0) * 2.0
        vz = (GetRandomValue(-100, 100) / 100.0) * 3.0
        cr = GetRandomValue(200, 255)
        cg = GetRandomValue(180, 255)
        cb = GetRandomValue(0, 100)
        add(particles, [wx, 0.5, wz, vx, vy, vz, 2.0, cr, cg, cb])
    next

func laser_updateParticles dt
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

func laser_drawParticles3D
    for i = 1 to len(particles)
        p = particles[i]
        alpha = floor((p[7] / 1.5) * 255)
        if alpha > 255 alpha = 255 ok
        if alpha < 0 alpha = 0 ok
        sz = 0.04 + p[7] * 0.06
        DrawSphereEx(
            Vector3(p[1], p[2], p[3]),
            sz, 4, 4,
            RAYLIBColor(p[8], p[9], p[10], alpha)
        )
    next

// =============================================================
// Camera
// =============================================================

func laser_positionCamera
    boardW = gridCols * CELL_SZ
    boardH = gridRows * CELL_SZ
    maxDim = boardW
    if boardH > maxDim maxDim = boardH ok

    goalX = 0  goalY = 0  goalZ = 0
    tgtX = 0   tgtY = 0   tgtZ = 0

    if cameraMode = CAM_FRONT
        goalX = 0
        goalY = maxDim * 0.8 + 4.0
        goalZ = maxDim * 0.7 + 4.0
        tgtX = 0
        tgtY = 0
        tgtZ = -0.5
    ok
    if cameraMode = CAM_ISOMETRIC
        goalX = maxDim * 0.6 + 2.0
        goalY = maxDim * 0.7 + 3.0
        goalZ = maxDim * 0.6 + 2.0
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

func laser_drawBoard3D
    boardW = gridCols * CELL_SZ
    boardH = gridRows * CELL_SZ

    // Main surface
    DrawCube(
        Vector3(0, -0.15, 0),
        boardW + 0.3, 0.3, boardH + 0.3,
        RAYLIBColor(25, 30, 50, 255)
    )

    // Border frame
    bThick = 0.3
    bH = 0.35
    halfW = boardW / 2 + bThick / 2 + 0.15
    halfH = boardH / 2 + bThick / 2 + 0.15
    borderCol = RAYLIBColor(60, 70, 100, 255)
    borderWire = RAYLIBColor(80, 90, 120, 200)

    DrawCube(Vector3(0, bH/2, -halfH), boardW + bThick*2 + 0.3, bH, bThick, borderCol)
    DrawCubeWires(Vector3(0, bH/2, -halfH), boardW + bThick*2 + 0.3, bH, bThick, borderWire)
    DrawCube(Vector3(0, bH/2, halfH), boardW + bThick*2 + 0.3, bH, bThick, borderCol)
    DrawCubeWires(Vector3(0, bH/2, halfH), boardW + bThick*2 + 0.3, bH, bThick, borderWire)
    DrawCube(Vector3(-halfW, bH/2, 0), bThick, bH, boardH + 0.3, borderCol)
    DrawCubeWires(Vector3(-halfW, bH/2, 0), bThick, bH, boardH + 0.3, borderWire)
    DrawCube(Vector3(halfW, bH/2, 0), bThick, bH, boardH + 0.3, borderCol)
    DrawCubeWires(Vector3(halfW, bH/2, 0), bThick, bH, boardH + 0.3, borderWire)

    // Grid cells
    for r = 1 to gridRows
        for c = 1 to gridCols
            wx = laser_cellToX(c)
            wz = laser_cellToZ(r)
            if (r + c) % 2 = 0
                tileCol = RAYLIBColor(28, 35, 55, 255)
            else
                tileCol = RAYLIBColor(22, 28, 45, 255)
            ok
            DrawCube(Vector3(wx, -0.01, wz), CELL_SZ - 0.04, 0.02, CELL_SZ - 0.04, tileCol)
        next
    next

    // Floor
    DrawPlane(Vector3(0, -0.35, 0), Vector2(30, 30), RAYLIBColor(12, 14, 22, 255))

// =============================================================
// 3D Drawing: Pieces
// =============================================================

func laser_drawPieces3D
    for r = 1 to gridRows
        for c = 1 to gridCols
            wx = laser_cellToX(c)
            wz = laser_cellToZ(r)

            cellType = grid[r][c]

            // Emitter
            if cellType = CELL_EMITTER
                laser_drawEmitter(wx, wz)
            ok

            // Target
            if cellType = CELL_TARGET
                laser_drawTarget(wx, wz)
            ok

            // Wall
            if cellType = CELL_WALL
                DrawCube(Vector3(wx, 0.35, wz), CELL_SZ * 0.85, 0.7, CELL_SZ * 0.85,
                         RAYLIBColor(80, 80, 95, 255))
                DrawCubeWires(Vector3(wx, 0.35, wz), CELL_SZ * 0.85, 0.7, CELL_SZ * 0.85,
                              RAYLIBColor(100, 100, 120, 200))
            ok

            // Mirror
            if cellType = CELL_MIRROR
                idx = laser_findMirror(r, c)
                if idx > 0
                    orient = mirrors[idx][3]
                    fixed  = mirrors[idx][4]

                    // Check if this mirror is currently being move-animated
                    drawX = wx
                    drawZ = wz
                    if moveAnimActive and moveAnimIdx = idx
                        t = moveAnimProgress
                        // Smooth ease-out
                        t = 1.0 - (1.0 - t) * (1.0 - t)
                        drawX = moveAnimFromX + (moveAnimToX - moveAnimFromX) * t
                        drawZ = moveAnimFromZ + (moveAnimToZ - moveAnimFromZ) * t
                    ok

                    laser_drawMirror(drawX, drawZ, orient, fixed, r, c)

                    // Highlight selected mirror with golden glow
                    if grabMode and selectedMirror = idx
                        selPulse = 0.7 + sin(animTime * 8.0) * 0.3
                        DrawSphere(Vector3(drawX, 0.5, drawZ), 0.3 * selPulse,
                                   RAYLIBColor(255, 200, 50, 40))
                    ok
                ok
            ok
        next
    next

func laser_drawEmitter wx, wz
    // Glowing base
    pulse = 0.85 + sin(animTime * 3.0) * 0.15
    DrawCube(Vector3(wx, 0.2, wz), CELL_SZ * 0.6, 0.4, CELL_SZ * 0.6,
             RAYLIBColor(220, 40, 40, 255))
    DrawCubeWires(Vector3(wx, 0.2, wz), CELL_SZ * 0.6, 0.4, CELL_SZ * 0.6,
                  RAYLIBColor(255, 100, 80, 200))
    // Top lens
    DrawCylinder(Vector3(wx, 0.4, wz), 0.25 * pulse, 0.2 * pulse, 0.2, 12,
                 RAYLIBColor(255, 50, 50, 255))
    // Glow
    DrawSphere(Vector3(wx, 0.45, wz), 0.15 * pulse,
               RAYLIBColor(255, 120, 80, 100))
    // Direction indicator arrow
    arrowLen = 0.3
    aX = wx
    aZ = wz
    if emitterDir = DIR_UP    aZ -= arrowLen ok
    if emitterDir = DIR_DOWN  aZ += arrowLen ok
    if emitterDir = DIR_LEFT  aX -= arrowLen ok
    if emitterDir = DIR_RIGHT aX += arrowLen ok
    DrawLine3D(Vector3(wx, 0.5, wz), Vector3(aX, 0.5, aZ),
               RAYLIBColor(255, 100, 100, 200))

func laser_drawTarget wx, wz
    pulse = 0.8 + sin(animTime * 4.0) * 0.2

    if beamHitTarget
        // Lit up!
        baseCol = RAYLIBColor(50, 255, 80, 255)
        wireCol = RAYLIBColor(120, 255, 150, 200)
        glowCol = RAYLIBColor(80, 255, 120, 120)
    else
        baseCol = RAYLIBColor(60, 60, 180, 255)
        wireCol = RAYLIBColor(100, 100, 220, 200)
        glowCol = RAYLIBColor(80, 80, 200, 60)
    ok

    DrawCube(Vector3(wx, 0.2, wz), CELL_SZ * 0.55, 0.4, CELL_SZ * 0.55, baseCol)
    DrawCubeWires(Vector3(wx, 0.2, wz), CELL_SZ * 0.55, 0.4, CELL_SZ * 0.55, wireCol)
    // Bullseye rings
    DrawCircle3D(Vector3(wx, 0.41, wz), 0.3 * pulse,
                 Vector3(1, 0, 0), 90.0, wireCol)
    DrawCircle3D(Vector3(wx, 0.42, wz), 0.15 * pulse,
                 Vector3(1, 0, 0), 90.0, baseCol)
    // Glow
    DrawSphere(Vector3(wx, 0.3, wz), 0.18 * pulse, glowCol)

func laser_drawMirror wx, wz, orient, fixed, r, c
    // Base platform
    if fixed = 1
        platCol = RAYLIBColor(100, 90, 70, 255)
        mirCol  = RAYLIBColor(180, 200, 220, 255)
        mirWire = RAYLIBColor(200, 220, 240, 200)
    else
        platCol = RAYLIBColor(70, 80, 100, 255)
        mirCol  = RAYLIBColor(200, 230, 255, 255)
        mirWire = RAYLIBColor(220, 240, 255, 200)
    ok

    // Platform base
    DrawCylinder(Vector3(wx, 0.0, wz), 0.35, 0.35, 0.08, 16, platCol)

    // Mirror surface (a thin tall rectangle rotated based on orientation)
    mirH = 0.65
    mirW = CELL_SZ * 0.75
    mirT = 0.06

    // Rotation animation
    isAnimating = false
    if rotAnimActive and rotAnimR = r and rotAnimC = c
        isAnimating = true
    ok

    // Calculate rotation angle
    // In X-Z plane: X increases right (col), Z increases down (row)
    // / mirror visually goes bottom-left to top-right = -45 degrees in X-Z
    // \ mirror visually goes top-left to bottom-right = +45 degrees in X-Z
    if orient = MIR_SLASH
        baseAngle = -45.0
    else
        baseAngle = 45.0
    ok

    if isAnimating
        // Animate from opposite angle
        if orient = MIR_SLASH
            fromAngle = 45.0
        else
            fromAngle = -45.0
        ok
        angle = fromAngle + (baseAngle - fromAngle) * rotAnimProgress
    else
        angle = baseAngle
    ok

    // Draw mirror as a thin cube rotated around Y axis
    // We approximate rotation by drawing at an angle using manual positioning
    rad = angle * 3.14159265 / 180.0
    cosA = cos(rad)
    sinA = sin(rad)

    // Four corners of the mirror surface
    hw = mirW / 2
    // Corner offsets rotated
    x1 = wx + cosA * (-hw)
    z1 = wz + sinA * (-hw)
    x2 = wx + cosA * hw
    z2 = wz + sinA * hw

    // Draw mirror as a line of cylinders (approximation for thin surface)
    nSegs = 6
    for seg = 0 to nSegs
        t = seg * 1.0 / nSegs
        sx = x1 + (x2 - x1) * t
        sz = z1 + (z2 - z1) * t
        DrawCylinder(Vector3(sx, 0.08, sz), 0.04, 0.04, mirH, 6, mirCol)
    next

    // Draw a connecting line at top
    DrawLine3D(Vector3(x1, mirH + 0.08, z1), Vector3(x2, mirH + 0.08, z2), mirWire)
    DrawLine3D(Vector3(x1, 0.08, z1), Vector3(x2, 0.08, z2), mirWire)

    // Reflective shine
    midX = (x1 + x2) / 2
    midZ = (z1 + z2) / 2
    DrawSphere(Vector3(midX, mirH * 0.6 + 0.08, midZ), 0.06,
               RAYLIBColor(255, 255, 255, 80))

// =============================================================
// 3D Drawing: Laser Beam
// =============================================================

func laser_drawBeam3D
    if len(beamPath) = 0 return ok

    beamY = 0.35
    beamCol  = RAYLIBColor(255, 30, 20, 240)
    glowCol  = RAYLIBColor(255, 80, 60, 80)
    coreCol  = RAYLIBColor(255, 200, 180, 255)

    pulse = 0.9 + sin(animTime * 8.0) * 0.1

    for i = 1 to len(beamPath)
        r1 = beamPath[i][1]
        c1 = beamPath[i][2]
        r2 = beamPath[i][3]
        c2 = beamPath[i][4]

        x1 = laser_cellToX(c1)
        z1 = laser_cellToZ(r1)

        // Clamp r2, c2 to grid for drawing
        if r2 < 1 or r2 > gridRows or c2 < 1 or c2 > gridCols
            x2 = laser_cellToX(c2)
            z2 = laser_cellToZ(r2)
        else
            x2 = laser_cellToX(c2)
            z2 = laser_cellToZ(r2)
        ok

        // Glow cylinder (thick, transparent)
        DrawCylinder(Vector3(x1, beamY, z1), 0.12 * pulse, 0.12 * pulse, 0.01, 8, glowCol)

        // Core beam line
        DrawLine3D(Vector3(x1, beamY, z1), Vector3(x2, beamY, z2), beamCol)

        // Thicker beam using cylinder along segment
        segLen = sqrt((x2 - x1) * (x2 - x1) + (z2 - z1) * (z2 - z1))
        if segLen > 0.01
            midX = (x1 + x2) / 2
            midZ = (z1 + z2) / 2
            // Draw small spheres along the beam for glow
            nDots = 3
            for d = 1 to nDots
                t = d * 1.0 / (nDots + 1)
                px = x1 + (x2 - x1) * t
                pz = z1 + (z2 - z1) * t
                DrawSphere(Vector3(px, beamY, pz), 0.04 * pulse, coreCol)
            next
        ok
    next

    // Bright dot at last beam position
    if len(beamPath) > 0
        lastSeg = beamPath[len(beamPath)]
        lr2 = lastSeg[3]
        lc2 = lastSeg[4]
        if lr2 >= 1 and lr2 <= gridRows and lc2 >= 1 and lc2 <= gridCols
            lx = laser_cellToX(lc2)
            lz = laser_cellToZ(lr2)
            DrawSphere(Vector3(lx, beamY, lz), 0.1 * pulse, beamCol)
        ok
    ok

// =============================================================
// 3D Drawing: Cursor
// =============================================================

func laser_drawCursor3D
    if gameState != ST_PLAYING return ok

    wx = laser_cellToX(cursorC)
    wz = laser_cellToZ(cursorR)
    cy = 0.03

    // Check if it's a rotatable mirror
    isMirror = false
    idx = laser_findMirror(cursorR, cursorC)
    if idx > 0 and mirrors[idx][4] = 0
        isMirror = true
    ok

    // Determine cursor color based on state
    if grabMode
        // In grab mode: show where the mirror will be dropped
        if grid[cursorR][cursorC] = CELL_EMPTY
            curCol = RAYLIBColor(80, 200, 255, 200)  // Blue = valid drop
        else
            curCol = RAYLIBColor(255, 80, 60, 180)   // Red = invalid drop
        ok
        pulse = 0.8 + sin(animTime * 6.0) * 0.2
    else
        if isMirror
            pulse = 0.85 + sin(animTime * 5.0) * 0.15
            curCol = RAYLIBColor(80, 255, 120, 180)
        else
            pulse = 1.0
            curCol = RAYLIBColor(150, 150, 180, 120)
        ok
    ok

    // Corner brackets
    hs = CELL_SZ * 0.48
    bracketLen = 0.25
    by = 0.04

    DrawLine3D(Vector3(wx - hs, by, wz - hs), Vector3(wx - hs + bracketLen, by, wz - hs), curCol)
    DrawLine3D(Vector3(wx - hs, by, wz - hs), Vector3(wx - hs, by, wz - hs + bracketLen), curCol)
    DrawLine3D(Vector3(wx + hs, by, wz - hs), Vector3(wx + hs - bracketLen, by, wz - hs), curCol)
    DrawLine3D(Vector3(wx + hs, by, wz - hs), Vector3(wx + hs, by, wz - hs + bracketLen), curCol)
    DrawLine3D(Vector3(wx - hs, by, wz + hs), Vector3(wx - hs + bracketLen, by, wz + hs), curCol)
    DrawLine3D(Vector3(wx - hs, by, wz + hs), Vector3(wx - hs, by, wz + hs - bracketLen), curCol)
    DrawLine3D(Vector3(wx + hs, by, wz + hs), Vector3(wx + hs - bracketLen, by, wz + hs), curCol)
    DrawLine3D(Vector3(wx + hs, by, wz + hs), Vector3(wx + hs, by, wz + hs - bracketLen), curCol)

    // Grab mode: ghost mirror preview at cursor
    if grabMode and grid[cursorR][cursorC] = CELL_EMPTY and selectedMirror >= 1 and selectedMirror <= len(mirrors)
        orient = mirrors[selectedMirror][3]
        ghostCol = RAYLIBColor(100, 200, 255, 80)
        rad = 0.0
        if orient = MIR_SLASH
            rad = -45.0 * 3.14159265 / 180.0
        else
            rad = 45.0 * 3.14159265 / 180.0
        ok
        cosA = cos(rad)
        sinA = sin(rad)
        hw = CELL_SZ * 0.35
        gx1 = wx + cosA * (-hw)
        gz1 = wz + sinA * (-hw)
        gx2 = wx + cosA * hw
        gz2 = wz + sinA * hw
        DrawLine3D(Vector3(gx1, 0.1, gz1), Vector3(gx2, 0.7, gz2), ghostCol)
        DrawLine3D(Vector3(gx1, 0.7, gz1), Vector3(gx2, 0.1, gz2), ghostCol)
        DrawCircle3D(Vector3(wx, 0.05, wz), 0.45 * pulse,
                     Vector3(1, 0, 0), 90.0, ghostCol)
    ok

    // Non-grab: rotation hint ring on mirror
    if !grabMode and isMirror
        DrawCircle3D(Vector3(wx, cy + 0.01, wz), 0.4 * pulse,
                     Vector3(1, 0, 0), 90.0, curCol)
    ok

    // Draw selected mirror highlight (pulsing glow on the selected mirror)
    if grabMode and selectedMirror >= 1 and selectedMirror <= len(mirrors)
        sr = mirrors[selectedMirror][1]
        sc = mirrors[selectedMirror][2]
        sx = laser_cellToX(sc)
        sz = laser_cellToZ(sr)
        selPulse = 0.7 + sin(animTime * 8.0) * 0.3
        DrawCircle3D(Vector3(sx, 0.8, sz), 0.5 * selPulse,
                     Vector3(1, 0, 0), 90.0, RAYLIBColor(255, 200, 50, 150))
        DrawSphere(Vector3(sx, 0.9, sz), 0.1 * selPulse,
                   RAYLIBColor(255, 200, 50, 80))
    ok

// =============================================================
// HUD
// =============================================================

func laser_drawHUD
    panelW = 250
    panelH = 145
    DrawRectangle(10, 30, panelW, panelH, Fade(BLACK, 0.75))
    DrawRectangleLines(10, 30, panelW, panelH, RAYLIBColor(200, 60, 60, 200))

    DrawText("3D LASER PUZZLE", 20, 38, 18, RAYLIBColor(255, 80, 60, 255))

    DrawText("Level: " + currentLevel + " / " + len(LEVELS), 20, 62, 16,
             RAYLIBColor(200, 200, 220, 255))

    DrawText("Moves: " + moveCount, 20, 84, 14, RAYLIBColor(160, 180, 200, 200))

    // Beam status
    if beamHitTarget
        DrawText("Beam: HIT TARGET!", 20, 104, 14, RAYLIBColor(50, 255, 80, 255))
    else
        DrawText("Beam: Searching...", 20, 104, 14, RAYLIBColor(255, 100, 80, 200))
    ok

    DrawText("Grid: " + gridRows + "x" + gridCols, 20, 124, 14,
             RAYLIBColor(140, 155, 175, 180))

    DrawText("Mirrors: " + len(mirrors), 20, 142, 14,
             RAYLIBColor(140, 155, 175, 180))

    // Camera
    camName = "FRONT"
    if cameraMode = CAM_ISOMETRIC camName = "ISOMETRIC" ok
    if cameraMode = CAM_OVERHEAD  camName = "OVERHEAD"  ok
    DrawRectangle(10, SCREEN_H - 60, 210, 25, Fade(BLACK, 0.6))
    DrawText("Cam: " + camName + "  [C] switch", 16, SCREEN_H - 56, 14,
             RAYLIBColor(150, 180, 210, 220))

    // Controls
    DrawRectangle(SCREEN_W - 560, SCREEN_H - 35, 550, 25, Fade(BLACK, 0.6))
    DrawText("Click: Grab/Move | RClick/Q: Rotate CCW | Space: Rotate CW | G: Grab | U: Undo | R: Reset",
             SCREEN_W - 555, SCREEN_H - 30, 12, RAYLIBColor(150, 160, 180, 200))

    // Grab mode indicator
    if grabMode
        DrawRectangle(10, SCREEN_H - 90, 200, 22, Fade(RAYLIBColor(255, 200, 50, 255), 0.8))
        DrawText("MIRROR GRABBED - Click to place", 16, SCREEN_H - 87, 13,
                 RAYLIBColor(30, 20, 0, 255))
    ok

// =============================================================
// Mini Board (2D overlay)
// =============================================================

func laser_drawMiniBoard
    cellW = 16
    cellH = 16
    mapW = gridCols * cellW
    mapH = gridRows * cellH
    mapX = SCREEN_W - mapW - 20
    mapY = 30

    DrawRectangle(mapX - 3, mapY - 3, mapW + 6, mapH + 6, Fade(BLACK, 0.8))
    DrawRectangleLines(mapX - 3, mapY - 3, mapW + 6, mapH + 6,
                       RAYLIBColor(200, 60, 60, 200))

    for r = 1 to gridRows
        for c = 1 to gridCols
            sx = mapX + (c - 1) * cellW
            sy = mapY + (r - 1) * cellH
            bg = RAYLIBColor(20, 25, 40, 220)
            DrawRectangle(sx, sy, cellW, cellH, bg)
            DrawRectangleLines(sx, sy, cellW, cellH, RAYLIBColor(35, 40, 60, 150))

            if grid[r][c] = CELL_WALL
                DrawRectangle(sx + 2, sy + 2, cellW - 4, cellH - 4,
                              RAYLIBColor(80, 80, 95, 255))
            ok
            if grid[r][c] = CELL_EMITTER
                DrawRectangle(sx + 2, sy + 2, cellW - 4, cellH - 4,
                              RAYLIBColor(220, 40, 40, 255))
            ok
            if grid[r][c] = CELL_TARGET
                if beamHitTarget
                    DrawRectangle(sx + 2, sy + 2, cellW - 4, cellH - 4,
                                  RAYLIBColor(50, 255, 80, 255))
                else
                    DrawRectangle(sx + 2, sy + 2, cellW - 4, cellH - 4,
                                  RAYLIBColor(60, 60, 180, 255))
                ok
            ok
            if grid[r][c] = CELL_MIRROR
                DrawCircle(sx + cellW/2, sy + cellH/2, 5,
                           RAYLIBColor(200, 230, 255, 255))
            ok
        next
    next

    // Draw beam on minimap
    for i = 1 to len(beamPath)
        br1 = beamPath[i][1]
        bc1 = beamPath[i][2]
        br2 = beamPath[i][3]
        bc2 = beamPath[i][4]
        if br1 >= 1 and br1 <= gridRows and bc1 >= 1 and bc1 <= gridCols and
           br2 >= 1 and br2 <= gridRows and bc2 >= 1 and bc2 <= gridCols
            lx1 = mapX + (bc1 - 1) * cellW + cellW/2
            ly1 = mapY + (br1 - 1) * cellH + cellH/2
            lx2 = mapX + (bc2 - 1) * cellW + cellW/2
            ly2 = mapY + (br2 - 1) * cellH + cellH/2
            DrawLine(lx1, ly1, lx2, ly2, RAYLIBColor(255, 50, 30, 200))
        ok
    next

    // Cursor
    cx = mapX + (cursorC - 1) * cellW
    cy = mapY + (cursorR - 1) * cellH
    DrawRectangleLines(cx, cy, cellW, cellH, RAYLIBColor(255, 255, 100, 220))

    DrawText("MAP", mapX + mapW/2 - 15, mapY - 16, 12,
             RAYLIBColor(200, 100, 100, 200))

// =============================================================
// Title Screen
// =============================================================

func laser_drawTitleScreen
    DrawRectangleGradientV(0, 0, SCREEN_W, SCREEN_H,
        RAYLIBColor(10, 8, 18, 255), RAYLIBColor(20, 12, 28, 255))

    t1 = "3D LASER PUZZLE"
    t1w = MeasureText(t1, 55)
    DrawText(t1, (SCREEN_W - t1w)/2, 80, 55, RAYLIBColor(255, 80, 60, 255))

    t2 = "~ Move and rotate mirrors to redirect the laser beam! ~"
    t2w = MeasureText(t2, 17)
    DrawText(t2, (SCREEN_W - t2w)/2, 145, 17, RAYLIBColor(200, 150, 140, 230))

    // Decorative laser line
    lx1 = 150
    lx2 = SCREEN_W - 150
    ly = 175
    DrawLine(lx1, ly, lx2, ly, RAYLIBColor(255, 30, 20, 180))
    DrawCircle(lx1, ly, 4, RAYLIBColor(255, 50, 30, 255))
    DrawCircle(lx2, ly, 4, RAYLIBColor(50, 255, 80, 255))

    cy = 195
    cLines = [
        "Left Click             -   Grab mirror / Place mirror / Rotate CW",
        "Right Click            -   Rotate mirror CCW / Cancel grab",
        "G / SPACE / ENTER      -   Grab or drop mirror at cursor",
        "SPACE (on mirror)      -   Rotate mirror clockwise",
        "Q                      -   Rotate mirror counter-clockwise",
        "Arrow Keys / WASD      -   Move cursor",
        "U                      -   Undo last move",
        "N / B                  -   Next / Previous level",
        "R                      -   Restart level",
        "C                      -   Cycle camera view",
        "",
        "Pieces:",
        "  RED block   = Laser emitter (fires beam, fixed)",
        "  BLUE block  = Target receiver (must be hit, fixed)",
        "  GRAY block  = Wall (blocks the beam)",
        "  MIRROR      = Movable & rotatable reflector",
        "",
        "Goal: Move and rotate mirrors so the laser hits the target!"
    ]
    for i = 1 to len(cLines)
        lw = MeasureText(cLines[i], 14)
        if i >= 9
            col = RAYLIBColor(255, 200, 100, 210)
        else
            col = RAYLIBColor(150, 170, 200, 230)
        ok
        DrawText(cLines[i], (SCREEN_W - lw)/2, cy + (i - 1) * 22, 14, col)
    next

    if floor(animTime * 2) % 2 = 0
        st = "Click or Press ENTER / SPACE to Start"
        stw = MeasureText(st, 26)
        DrawText(st, (SCREEN_W - stw)/2, 580, 26, WHITE)
    ok

    lv = "" + len(LEVELS) + " puzzle levels!"
    lvw = MeasureText(lv, 18)
    DrawText(lv, (SCREEN_W - lvw)/2, 620, 18, RAYLIBColor(180, 200, 100, 220))

    cr = "Developed using Ring Language + RingRayLib"
    crw = MeasureText(cr, 14)
    DrawText(cr, (SCREEN_W - crw)/2, SCREEN_H - 35, 14,
             RAYLIBColor(80, 100, 80, 180))

// =============================================================
// Win Overlay
// =============================================================

func laser_drawWinOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.5))

    g1 = "LEVEL COMPLETE!"
    g1w = MeasureText(g1, 48)
    DrawText(g1, (SCREEN_W - g1w)/2, 220, 48, RAYLIBColor(50, 255, 100, 255))

    s1 = "Moves: " + moveCount
    s1w = MeasureText(s1, 22)
    DrawText(s1, (SCREEN_W - s1w)/2, 290, 22, RAYLIBColor(200, 220, 255, 255))

    // Stars
    starCount = 3
    if moveCount > len(mirrors) * 2   starCount = 2 ok
    if moveCount > len(mirrors) * 4   starCount = 1 ok
    starsText = ""
    for i = 1 to starCount
        starsText += "* "
    next
    stw = MeasureText(starsText, 40)
    DrawText(starsText, (SCREEN_W - stw)/2, 330, 40, RAYLIBColor(255, 215, 0, 255))

    if currentLevel < len(LEVELS)
        nextTxt = "Click or ENTER for Level " + (currentLevel + 1) + "  |  N: Next  |  B: Back"
    else
        nextTxt = "All levels complete! Press R to replay"
    ok

    if floor(animTime * 2) % 2 = 0
        ntw = MeasureText(nextTxt, 18)
        DrawText(nextTxt, (SCREEN_W - ntw)/2, 400, 18, WHITE)
    ok
