/*
**  BABA IS YOU 3D - Rule-Pushing Puzzle Game
**  Using RingRayLib
**  ================================================
**  Push word blocks to change the rules of the game!
**  Form sentences like "BABA IS YOU" to control objects.
**
**  Controls:
**    Arrow Keys / WASD  - Move the object that IS YOU
**    Z                  - Undo last move
**    R                  - Reset current level
**    N / B              -  Next / Previous level
**    F                  - Auto-solve level
**    C                  - Cycle camera view
**    ESC                - Exit
**
**  Rule System:
**    NOUN IS PROPERTY   - e.g. BABA IS YOU, WALL IS STOP
**    NOUN IS NOUN       - e.g. BABA IS ROCK (transforms objects)
**    Rules are formed by 3 words in a row (horizontal or vertical)
**    Push words to create new rules and solve puzzles!
**
**  Properties:
**    YOU   - Player controls this object
**    WIN   - Touch this to win the level
**    STOP  - Cannot be walked through
**    PUSH  - Can be pushed by YOU
**    OPEN  - Opens SHUT objects (both vanish)
**    SHUT  - Blocks movement, opened by OPEN
**    SINK  - Anything moving onto this sinks (both vanish)
**    DEFEAT- Touching this destroys YOU objects
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W    = 800
SCREEN_H    = 700

// Tile types - Objects
T_EMPTY     = 0
T_BABA      = 1
T_WALL      = 2
T_ROCK      = 3
T_FLAG      = 4
T_KEY       = 5
T_DOOR      = 6
T_WATER     = 7
T_SKULL     = 8
T_LAVA      = 9

// Tile types - Word blocks (nouns)
W_BABA      = 21
W_WALL      = 22
W_ROCK      = 23
W_FLAG      = 24
W_KEY       = 25
W_DOOR      = 26
W_WATER     = 27
W_SKULL     = 28
W_LAVA      = 29

// Word blocks - IS connector
W_IS        = 40

// Word blocks - Properties
W_YOU       = 51
W_WIN       = 52
W_STOP      = 53
W_PUSH      = 54
W_OPEN      = 55
W_SHUT      = 56
W_SINK      = 57
W_DEFEAT    = 58

// Properties (bitflags)
P_YOU       = 1
P_WIN       = 2
P_STOP      = 4
P_PUSH      = 8
P_OPEN      = 16
P_SHUT      = 32
P_SINK      = 64
P_DEFEAT    = 128

// Game states
ST_TITLE    = 1
ST_PLAYING  = 2
ST_WON      = 3
ST_LOST     = 4

// Camera modes
CAM_FRONT   = 1
CAM_ANGLE   = 2
CAM_TOP     = 3
CAM_COUNT   = 3

// =============================================================
// Globals
// =============================================================

gameState       = ST_TITLE
animTime        = 0.0

// Grid
gridW           = 0
gridH           = 0
grid            = []        // grid[row][col] = list of tile IDs on that cell

// Rules / properties per object type
objProps        = []        // objProps[type] = property bitmask
// Transform rules: objTransform[type] = target type (0 = none)
objTransform    = []

// Level data
levels          = []
levelCount      = 0
currentLevel    = 1
maxUnlocked     = 1

// Undo
undoStack       = []
MAX_UNDO        = 200

// Camera
cameraMode      = CAM_FRONT
camPosX = 0.0   camPosY = 0.0   camPosZ = 10.0
camTgtX = 0.0   camTgtY = 0.0   camTgtZ = 0.0

// Message
msgText         = ""
msgTimer        = 0.0

// Particles
particles       = []

// Win animation
winTimer        = 0.0

// Solver
solverActive    = false
solverMoves     = []
solverStep      = 0
solverDelay     = 0.0
SOLVER_WAIT     = 0.25

// =============================================================
// Level Definitions
// =============================================================
// Format: [width, height, "grid data"]
// Grid data: rows separated by |
// Each cell can have multiple objects separated by +
// Codes: . = empty
//   b=baba w=wall r=rock f=flag k=key d=door
//   a=water s=skull v=lava
//   Bb=word BABA Bw=word WALL Br=word ROCK Bf=word FLAG
//   Bk=word KEY Bd=word DOOR Ba=word WATER Bs=word SKULL Bv=word LAVA
//   Bi=word IS
//   Py=word YOU Pw=word WIN Ps=word STOP Pp=word PUSH
//   Po=word OPEN Ph=word SHUT Pn=word SINK Px=word DEFEAT

bb_defineLevels()

// =============================================================
// Initialization
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "BABA IS YOU 3D - Ring + RayLib")
SetTargetFPS(60)

// Screen projection output
projSX = 0.0
projSY = 0.0
PI = 3.14159265

// Precomputed solutions (UDLR strings)
precomputedSolutions = []
add(precomputedSolutions, "RRRRRR")                  // L1
add(precomputedSolutions, "RRRRRR")                  // L2
add(precomputedSolutions, "URRRRRRRRDRRR")            // L3
add(precomputedSolutions, "DDLDRRRUUUR")              // L4
add(precomputedSolutions, "DDURRRRURR")               // L5
add(precomputedSolutions, "RRRRRRRRR")                // L6
add(precomputedSolutions, "RRRRRR")                  // L7
add(precomputedSolutions, "URRRRRRRDRR")              // L8
add(precomputedSolutions, "URRRRRRRDRR")              // L9
add(precomputedSolutions, "URRRRRDRR")                // L10
add(precomputedSolutions, "URRRRRRDRRR")              // L11
add(precomputedSolutions, "RRRRRRRRRR")               // L12
add(precomputedSolutions, "RRRRRRRR")                // L13
add(precomputedSolutions, "URRRRRRRRRDR")             // L14
add(precomputedSolutions, "DRRRRRRRRURR")             // L15

// =============================================================
// Main Loop
// =============================================================

while WindowShouldClose() = false

    dt = GetFrameTime()
    animTime += dt

    if msgTimer > 0
        msgTimer -= dt
        if msgTimer < 0 msgTimer = 0 ok
    ok

    // Camera toggle
    if IsKeyPressed(KEY_C)
        cameraMode += 1
        if cameraMode > CAM_COUNT cameraMode = CAM_FRONT ok
    ok

    // ========== STATE UPDATES ==========

    if gameState = ST_TITLE
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(0)
            bb_loadLevel(currentLevel)
            gameState = ST_PLAYING
        ok
    ok

    if gameState = ST_PLAYING
        if solverActive
            solverDelay -= dt
            if solverDelay <= 0
                if solverStep <= len(solverMoves)
                    mv = solverMoves[solverStep]
                    bb_doMove(mv[1], mv[2])
                    solverStep += 1
                    solverDelay = SOLVER_WAIT
                    // Check win/lose after move
                    if gameState != ST_PLAYING
                        solverActive = false
                    ok
                else
                    solverActive = false
                ok
            ok
        else
            bb_handleInput()
        ok
        bb_updateParticles(dt)
    ok

    if gameState = ST_WON
        winTimer -= dt
        bb_updateParticles(dt)
        if winTimer <= 0 or IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            if currentLevel < levelCount
                bb_loadLevel(currentLevel + 1)
                gameState = ST_PLAYING
            else
                gameState = ST_PLAYING
            ok
        ok
    ok

    if gameState = ST_LOST
        winTimer -= dt
        bb_updateParticles(dt)
        if winTimer <= 0 or IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsKeyPressed(KEY_R)
            bb_loadLevel(currentLevel)
            gameState = ST_PLAYING
        ok
    ok

    // Level navigation
    if gameState = ST_PLAYING or gameState = ST_WON or gameState = ST_LOST
        if IsKeyPressed(KEY_N)
            nxt = currentLevel + 1
            if nxt > levelCount nxt = levelCount ok
            if nxt <= maxUnlocked
                bb_loadLevel(nxt)
                gameState = ST_PLAYING
            ok
        ok
        if IsKeyPressed(KEY_B)
            if currentLevel > 1
                bb_loadLevel(currentLevel - 1)
                gameState = ST_PLAYING
            ok
        ok
        if IsKeyPressed(KEY_R)
            bb_loadLevel(currentLevel)
            gameState = ST_PLAYING
        ok
    ok

    bb_positionCamera()

    // ========== RENDERING ==========

    BeginDrawing()
    ClearBackground(RAYLIBColor(15, 15, 20, 255))

    if gameState = ST_TITLE
        bb_drawTitle()
    else
        BeginMode3D(Camera3D(
            camPosX, camPosY, camPosZ,
            camTgtX, camTgtY, camTgtZ,
            0, 1, 0,
            45.0, CAMERA_PERSPECTIVE))

        bb_drawGrid3D()
        bb_drawParticles3D()

        EndMode3D()

        bb_drawHUD()

        if gameState = ST_WON
            bb_drawWinOverlay()
        ok
        if gameState = ST_LOST
            bb_drawLoseOverlay()
        ok
    ok

    // Message
    if msgTimer > 0
        alpha = 255
        if msgTimer < 0.5 alpha = floor(msgTimer * 510) ok
        mw = MeasureText(msgText, 18)
        DrawText(msgText, (SCREEN_W - mw)/2, SCREEN_H - 45, 18, RAYLIBColor(255, 255, 200, alpha))
    ok

    EndDrawing()
end

CloseWindow()

// =============================================================
// Level Definitions
// =============================================================

func bb_defineLevels
    levels = []

    // Level 1: BABA IS YOU, FLAG IS WIN (simplest - just walk to flag)
    add(levels, [11, 7,
        "..BbBiPy.....|...........|...........|..b.....f..|...........|...........|..BfBiPw....."])

    // Level 2: Push ROCK out of the way to reach FLAG
    add(levels, [11, 7,
        "BbBiPy.......|...........|...........|..b.r...f..|...........|...........|BfBiPw.BrBiPp"])

    // Level 3: WALL IS STOP blocks your path
    add(levels, [13, 7,
        "BbBiPy..BfBiPw.|...............|b...wwww...f...|...............|...............|BwBiPs.........|..............."])

    // Level 4: Push words to form FLAG IS WIN
    add(levels, [11, 9,
        "...........|.BbBiPy....|...........|...........|.b..www..f.|...........|.BwBiPs....|.Bf.Bi..Pw.|..........."])

    // Level 5: KEY IS OPEN, DOOR IS SHUT
    add(levels, [11, 8,
        "BbBiPy.....|...........|b..k..d..f.|...........|BkBiPo.....|BdBiPh.....|BfBiPw.....|..........."])

    // Level 6: ROCK IS PUSH - push rock onto flag
    add(levels, [11, 7,
        "BbBiPy.BrBiPp|.............|b....r...f...|.............|.............|BfBiPw.......|............."])

    // Level 7: Walls block, push ROCK around them
    add(levels, [11, 9,
        "BbBiPy.....|BfBiPw.....|...........|.b.....f...|...........|.www.......|...........|BrBiPp.....|..........."])

    // Level 8: WATER IS SINK - push rocks to fill water
    add(levels, [11, 8,
        "BbBiPy.....|BfBiPw.....|...........|b..aaaa..f.|...........|BaBiPn.....|BrBiPp.....|..........."])

    // Level 9: SKULL IS DEFEAT - avoid skulls
    add(levels, [11, 8,
        "BbBiPy.....|BfBiPw.....|BsBiPx.....|...........|b...s.s..f.|...........|...........|..........."])

    // Level 10: Push IS to break WALL IS STOP
    add(levels, [11, 9,
        "...........|.BwBiPs....|...........|.b..ww..f..|...........|...........|.BbBiPy....|.BfBiPw....|..........."])

    // Level 11: LAVA IS DEFEAT - push rocks into lava
    add(levels, [12, 8,
        "BbBiPy......|BfBiPw......|BvBiPx......|............|b...vv...f..|............|BrBiPp......|............"])

    // Level 12: Push key into door - KEY IS OPEN+PUSH, DOOR IS SHUT
    add(levels, [12, 9,
        "BbBiPy......|BfBiPw......|BdBiPh......|BkBiPo......|BkBiPp......|............|b...k.d...f.|............|............"])

    // Level 13: Push [YOU] to change what you control
    add(levels, [11, 9,
        "BbBiPy.....|BfBiPw.....|...........|.b..www..f.|...........|.Bw.Bi.....|...........|...........|..........."])

    // Level 14: Break SKULL IS DEFEAT to pass skulls
    add(levels, [12, 8,
        "BbBiPy......|BsBiPx......|BfBiPw......|............|b..ss..ss.f.|............|............|............"])

    // Level 15: Grand finale - push key into door, reach flag
    add(levels, [12, 8,
        "BbBiPy......|BwBiPs......|BrBiPp......|BkBiPo......|BdBiPh......|BfBiPw......|b..wrk.d..f.|............"])

    levelCount = len(levels)

// =============================================================
// Level Loading
// =============================================================

func bb_loadLevel num
    if num < 1 or num > levelCount return ok
    currentLevel = num

    lv = levels[num]
    gridW = lv[1]
    gridH = lv[2]
    data = lv[3]

    // Init grid: each cell is a list of tile IDs
    grid = list(gridH)
    for r = 1 to gridH
        grid[r] = list(gridW)
        for c = 1 to gridW
            grid[r][c] = []
        next
    next

    // Parse grid data
    rows = bb_splitStr(data, "|")
    for r = 1 to len(rows)
        if r > gridH exit ok
        row = rows[r]
        col = 1
        ci = 1
        while ci <= len(row) and col <= gridW
            ch = substr(row, ci, 1)

            if ch = "."
                // Empty
                ci += 1
                col += 1
            but ch = "B" and ci + 1 <= len(row)
                // Word block noun: Bb, Bw, Br, Bf, Bk, Bd, Ba, Bs, Bv, Bi
                ch2 = substr(row, ci + 1, 1)
                tile = 0
                if ch2 = "b" tile = W_BABA ok
                if ch2 = "w" tile = W_WALL ok
                if ch2 = "r" tile = W_ROCK ok
                if ch2 = "f" tile = W_FLAG ok
                if ch2 = "k" tile = W_KEY ok
                if ch2 = "d" tile = W_DOOR ok
                if ch2 = "a" tile = W_WATER ok
                if ch2 = "s" tile = W_SKULL ok
                if ch2 = "v" tile = W_LAVA ok
                if ch2 = "i" tile = W_IS ok
                if tile > 0
                    add(grid[r][col], tile)
                ok
                ci += 2
                col += 1
            but ch = "P" and ci + 1 <= len(row)
                // Property word: Py, Pw, Ps, Pp, Po, Ph, Pn, Px
                ch2 = substr(row, ci + 1, 1)
                tile = 0
                if ch2 = "y" tile = W_YOU ok
                if ch2 = "w" tile = W_WIN ok
                if ch2 = "s" tile = W_STOP ok
                if ch2 = "p" tile = W_PUSH ok
                if ch2 = "o" tile = W_OPEN ok
                if ch2 = "h" tile = W_SHUT ok
                if ch2 = "n" tile = W_SINK ok
                if ch2 = "x" tile = W_DEFEAT ok
                if tile > 0
                    add(grid[r][col], tile)
                ok
                ci += 2
                col += 1
            but ch = "b"
                add(grid[r][col], T_BABA)
                ci += 1
                col += 1
            but ch = "w"
                add(grid[r][col], T_WALL)
                ci += 1
                col += 1
            but ch = "r"
                add(grid[r][col], T_ROCK)
                ci += 1
                col += 1
            but ch = "f"
                add(grid[r][col], T_FLAG)
                ci += 1
                col += 1
            but ch = "k"
                add(grid[r][col], T_KEY)
                ci += 1
                col += 1
            but ch = "d"
                add(grid[r][col], T_DOOR)
                ci += 1
                col += 1
            but ch = "a"
                add(grid[r][col], T_WATER)
                ci += 1
                col += 1
            but ch = "s"
                add(grid[r][col], T_SKULL)
                ci += 1
                col += 1
            but ch = "v"
                add(grid[r][col], T_LAVA)
                ci += 1
                col += 1
            but ch = "+"
                // Multiple objects on same cell (don't advance col)
                ci += 1
            else
                ci += 1
                col += 1
            ok
        end
    next

    // Reset state
    undoStack = []
    solverActive = false
    solverMoves = []
    particles = []
    winTimer = 0

    // Parse rules
    bb_parseRules()

    bb_showMsg("Level " + currentLevel + " / " + levelCount)

// =============================================================
// String Split Helper
// =============================================================

func bb_splitStr str, delim
    result = []
    current = ""
    for i = 1 to len(str)
        ch = substr(str, i, 1)
        if ch = delim
            add(result, current)
            current = ""
        else
            current += ch
        ok
    next
    add(result, current)
    return result

// =============================================================
// Rule Parsing - The Heart of the Game
// =============================================================

func bb_parseRules
    // Reset all properties
    objProps = list(20)
    for i = 1 to 20
        objProps[i] = 0
    next
    objTransform = list(20)
    for i = 1 to 20
        objTransform[i] = 0
    next

    // All word blocks are always pushable
    // (this is handled in movement, not as a property)

    // Scan horizontal: look for NOUN IS PROP or NOUN IS NOUN
    for r = 1 to gridH
        for c = 1 to gridW - 2
            bb_checkRule(r, c, 0, 1)
        next
    next

    // Scan vertical
    for r = 1 to gridH - 2
        for c = 1 to gridW
            bb_checkRule(r, c, 1, 0)
        next
    next

func bb_checkRule r, c, dr, dc
    // Get tiles at three consecutive positions
    r2 = r + dr
    c2 = c + dc
    r3 = r + 2 * dr
    c3 = c + 2 * dc

    // First cell must contain a noun word
    noun = bb_findWordNoun(r, c)
    if noun = 0 return ok

    // Second cell must contain IS
    if bb_cellHasTile(r2, c2, W_IS) = false return ok

    // Third cell: either a property word or a noun word
    prop = bb_findWordProp(r3, c3)
    if prop > 0
        // NOUN IS PROPERTY
        objType = bb_nounToType(noun)
        if objType > 0 and objType <= 20
            objProps[objType] = objProps[objType] | prop
        ok
        return
    ok

    noun2 = bb_findWordNoun(r3, c3)
    if noun2 > 0
        // NOUN IS NOUN (transformation)
        srcType = bb_nounToType(noun)
        tgtType = bb_nounToType(noun2)
        if srcType > 0 and srcType <= 20 and tgtType > 0 and tgtType <= 20
            objTransform[srcType] = tgtType
        ok
    ok

func bb_findWordNoun r, c
    tiles = grid[r][c]
    nTiles = len(tiles)
    for i = 1 to nTiles
        t = tiles[i]
        if t >= 21 and t <= 29 return t ok
    next
    return 0

func bb_findWordProp r, c
    tiles = grid[r][c]
    nTiles = len(tiles)
    for i = 1 to nTiles
        t = tiles[i]
        if t = W_YOU return P_YOU ok
        if t = W_WIN return P_WIN ok
        if t = W_STOP return P_STOP ok
        if t = W_PUSH return P_PUSH ok
        if t = W_OPEN return P_OPEN ok
        if t = W_SHUT return P_SHUT ok
        if t = W_SINK return P_SINK ok
        if t = W_DEFEAT return P_DEFEAT ok
    next
    return 0

func bb_cellHasTile r, c, tileType
    tiles = grid[r][c]
    nTiles = len(tiles)
    for i = 1 to nTiles
        if tiles[i] = tileType return true ok
    next
    return false

func bb_nounToType wordTile
    if wordTile = W_BABA return T_BABA ok
    if wordTile = W_WALL return T_WALL ok
    if wordTile = W_ROCK return T_ROCK ok
    if wordTile = W_FLAG return T_FLAG ok
    if wordTile = W_KEY return T_KEY ok
    if wordTile = W_DOOR return T_DOOR ok
    if wordTile = W_WATER return T_WATER ok
    if wordTile = W_SKULL return T_SKULL ok
    if wordTile = W_LAVA return T_LAVA ok
    return 0

func bb_isWordTile t
    if t >= 21 and t <= 29 return true ok
    if t = W_IS return true ok
    if t >= 51 and t <= 58 return true ok
    return false

func bb_getObjProp objType
    if objType < 1 or objType > 20 return 0 ok
    return objProps[objType]

// =============================================================
// Input Handling
// =============================================================

func bb_handleInput
    dr = 0
    dc = 0

    if IsKeyPressed(KEY_UP) or IsKeyPressed(KEY_W) dr = -1 ok
    if IsKeyPressed(KEY_DOWN) or IsKeyPressed(KEY_S) dr = 1 ok
    if IsKeyPressed(KEY_LEFT) or IsKeyPressed(KEY_A) dc = -1 ok
    if IsKeyPressed(KEY_RIGHT) or IsKeyPressed(KEY_D) dc = 1 ok

    if dr != 0 or dc != 0
        bb_doMove(dr, dc)
    ok

    // Undo
    if IsKeyPressed(KEY_Z)
        bb_undo()
    ok

    // Auto-solve
    if IsKeyPressed(KEY_F)
        bb_autoSolve()
    ok

// =============================================================
// Movement Logic
// =============================================================

func bb_doMove dr, dc
    // Save state for undo
    bb_saveUndo()

    // Find all YOU objects and try to move them
    moved = false
    youList = []

    for r = 1 to gridH
        for c = 1 to gridW
            tiles = grid[r][c]
            nTiles = len(tiles)
            for ti = 1 to nTiles
                t = tiles[ti]
                if t >= 1 and t <= 20
                    props = bb_getObjProp(t)
                    if (props & P_YOU) > 0
                        add(youList, [r, c, t])
                    ok
                ok
            next
        next
    next

    nYou = len(youList)
    if nYou = 0 return ok

    // Move each YOU object
    for yi = 1 to nYou
        yr = youList[yi][1]
        yc = youList[yi][2]
        yt = youList[yi][3]
        if bb_cellHasTile(yr, yc, yt)
            if bb_tryMove(yr, yc, yt, dr, dc)
                moved = true
            ok
        ok
    next

    if moved
        // Apply transformations
        bb_applyTransforms()
        // Re-parse rules (words might have moved)
        bb_parseRules()
        // Check interactions (OPEN+SHUT, SINK, DEFEAT, WIN)
        bb_checkInteractions()
    else
        // Revert undo since nothing happened
        if len(undoStack) > 0
            del(undoStack, len(undoStack))
        ok
    ok

func bb_tryMove r, c, tile, dr, dc
    nr = r + dr
    nc = c + dc

    // Out of bounds
    if nr < 1 or nr > gridH or nc < 1 or nc > gridW return false ok

    // Check what's at the target cell
    targetTiles = grid[nr][nc]
    nTarget = len(targetTiles)

    // Check for STOP/SHUT objects at target
    for i = 1 to nTarget
        tt = targetTiles[i]
        if tt >= 1 and tt <= 20
            props = bb_getObjProp(tt)
            if (props & P_STOP) > 0 return false ok
            if (props & P_SHUT) > 0
                if tile >= 1 and tile <= 20
                    mprops = bb_getObjProp(tile)
                    if (mprops & P_OPEN) = 0 return false ok
                else
                    return false
                ok
            ok
        ok
    next

    // Check for pushable objects at target
    for i = 1 to nTarget
        tt = targetTiles[i]
        canPush = false
        if bb_isWordTile(tt)
            canPush = true
        else
            if tt >= 1 and tt <= 20
                props = bb_getObjProp(tt)
                if (props & P_PUSH) > 0 canPush = true ok
            ok
        ok
        if canPush
            if bb_tryMove(nr, nc, tt, dr, dc) = false
                return false
            ok
        ok
    next

    // Move the tile
    bb_removeTile(r, c, tile)
    add(grid[nr][nc], tile)
    return true

func bb_removeTile r, c, tile
    tiles = grid[r][c]
    nTiles = len(tiles)
    for i = 1 to nTiles
        if tiles[i] = tile
            del(grid[r][c], i)
            return
        ok
    next

// =============================================================
// Interactions (after movement)
// =============================================================

func bb_checkInteractions
    // Check for WIN
    for r = 1 to gridH
        for c = 1 to gridW
            tiles = grid[r][c]
            hasYou = false
            hasWin = false
            nTiles = len(tiles)
            for i = 1 to nTiles
                t = tiles[i]
                if bb_isWordTile(t) = false
                    props = bb_getObjProp(t)
                    if (props & P_YOU) > 0 hasYou = true ok
                    if (props & P_WIN) > 0 hasWin = true ok
                ok
            next
            if hasYou and hasWin
                gameState = ST_WON
                winTimer = 2.0
                if currentLevel + 1 > maxUnlocked
                    maxUnlocked = currentLevel + 1
                    if maxUnlocked > levelCount maxUnlocked = levelCount ok
                ok
                bb_spawnWinParticles()
                bb_showMsg("YOU WIN!")
                return
            ok
        next
    next

    // Check for DEFEAT
    for r = 1 to gridH
        for c = 1 to gridW
            tiles = grid[r][c]
            hasDefeat = false
            nTiles = len(tiles)
            for i = 1 to nTiles
                t = tiles[i]
                if bb_isWordTile(t) = false
                    props = bb_getObjProp(t)
                    if (props & P_DEFEAT) > 0 hasDefeat = true ok
                ok
            next
            if hasDefeat
                ti = 1
                while ti <= len(grid[r][c])
                    t = grid[r][c][ti]
                    if bb_isWordTile(t) = false
                        props = bb_getObjProp(t)
                        if (props & P_YOU) > 0
                            del(grid[r][c], ti)
                            loop
                        ok
                    ok
                    ti += 1
                end
            ok
        next
    next

    // Check for OPEN + SHUT
    for r = 1 to gridH
        for c = 1 to gridW
            tiles = grid[r][c]
            hasOpen = false
            hasShut = false
            nTiles = len(tiles)
            for i = 1 to nTiles
                t = tiles[i]
                if bb_isWordTile(t) = false
                    props = bb_getObjProp(t)
                    if (props & P_OPEN) > 0 hasOpen = true ok
                    if (props & P_SHUT) > 0 hasShut = true ok
                ok
            next
            if hasOpen and hasShut
                removedOpen = false
                removedShut = false
                ti = 1
                while ti <= len(grid[r][c])
                    t = grid[r][c][ti]
                    if bb_isWordTile(t) = false
                        props = bb_getObjProp(t)
                        if (props & P_OPEN) > 0 and removedOpen = false
                            del(grid[r][c], ti)
                            removedOpen = true
                            loop
                        ok
                        if (props & P_SHUT) > 0 and removedShut = false
                            del(grid[r][c], ti)
                            removedShut = true
                            loop
                        ok
                    ok
                    ti += 1
                end
            ok
        next
    next

    // Check for SINK
    for r = 1 to gridH
        for c = 1 to gridW
            tiles = grid[r][c]
            hasSink = false
            hasNonSink = false
            nTiles = len(tiles)
            for i = 1 to nTiles
                t = tiles[i]
                if bb_isWordTile(t) = false
                    props = bb_getObjProp(t)
                    if (props & P_SINK) > 0
                        hasSink = true
                    else
                        hasNonSink = true
                    ok
                ok
            next
            if hasSink and hasNonSink
                removedSink = false
                removedOther = false
                ti = 1
                while ti <= len(grid[r][c])
                    t = grid[r][c][ti]
                    if bb_isWordTile(t) = false
                        props = bb_getObjProp(t)
                        if (props & P_SINK) > 0 and removedSink = false
                            del(grid[r][c], ti)
                            removedSink = true
                            loop
                        ok
                        if (props & P_SINK) = 0 and removedOther = false
                            del(grid[r][c], ti)
                            removedOther = true
                            loop
                        ok
                    ok
                    ti += 1
                end
            ok
        next
    next

    // Check if any YOU objects still exist
    youExists = false
    for r = 1 to gridH
        for c = 1 to gridW
            tiles = grid[r][c]
            nTiles = len(tiles)
            for i = 1 to nTiles
                t = tiles[i]
                if bb_isWordTile(t) = false
                    props = bb_getObjProp(t)
                    if (props & P_YOU) > 0 youExists = true ok
                ok
            next
        next
    next
    if youExists = false and gameState = ST_PLAYING
        gameState = ST_LOST
        winTimer = 2.0
        bb_showMsg("No YOU objects! Press R to restart")
    ok

// =============================================================
// Transformations
// =============================================================

func bb_applyTransforms
    for r = 1 to gridH
        for c = 1 to gridW
            ti = 1
            while ti <= len(grid[r][c])
                t = grid[r][c][ti]
                if bb_isWordTile(t) = false and t >= 1 and t <= 20
                    tgt = objTransform[t]
                    if tgt > 0 and tgt != t
                        grid[r][c][ti] = tgt
                    ok
                ok
                ti += 1
            end
        next
    next

// =============================================================
// Undo System
// =============================================================

func bb_saveUndo
    // Deep copy grid state
    state = list(gridH)
    for r = 1 to gridH
        state[r] = list(gridW)
        for c = 1 to gridW
            state[r][c] = []
            for i = 1 to len(grid[r][c])
                add(state[r][c], grid[r][c][i])
            next
        next
    next
    add(undoStack, state)
    if len(undoStack) > MAX_UNDO
        del(undoStack, 1)
    ok

func bb_undo
    if len(undoStack) = 0
        bb_showMsg("Nothing to undo")
        return
    ok
    state = undoStack[len(undoStack)]
    del(undoStack, len(undoStack))

    grid = list(gridH)
    for r = 1 to gridH
        grid[r] = list(gridW)
        for c = 1 to gridW
            grid[r][c] = []
            for i = 1 to len(state[r][c])
                add(grid[r][c], state[r][c][i])
            next
        next
    next

    bb_parseRules()
    gameState = ST_PLAYING

// =============================================================
// Auto-Solver (precomputed solutions - instant)
// =============================================================

func bb_autoSolve
    solverActive = false
    solverMoves = []

    if currentLevel < 1 or currentLevel > len(precomputedSolutions)
        bb_showMsg("No solution available")
        return
    ok

    solStr = precomputedSolutions[currentLevel]
    if len(solStr) = 0
        bb_showMsg("No solution available")
        return
    ok

    // Reload level to clean state
    bb_loadLevel(currentLevel)

    // Decode move string to move list
    solverMoves = []
    nMoves = len(solStr)
    for mi = 1 to nMoves
        ch = substr(solStr, mi, 1)
        if ch = "U" add(solverMoves, [-1, 0]) ok
        if ch = "D" add(solverMoves, [1, 0]) ok
        if ch = "L" add(solverMoves, [0, -1]) ok
        if ch = "R" add(solverMoves, [0, 1]) ok
    next

    solverActive = true
    solverStep = 1
    solverDelay = 0.3
    bb_showMsg("Auto-solving: " + len(solverMoves) + " moves")

// =============================================================
// Camera
// =============================================================

// =============================================================
// 3D to 2D Projection (manual, no GetWorldToScreen needed)
// =============================================================

func bb_projectToScreen wx, wy, wz
    fwdX = camTgtX - camPosX
    fwdY = camTgtY - camPosY
    fwdZ = camTgtZ - camPosZ
    fLen = sqrt(fwdX*fwdX + fwdY*fwdY + fwdZ*fwdZ)
    if fLen < 0.0001
        projSX = SCREEN_W / 2
        projSY = SCREEN_H / 2
        return
    ok
    fwdX = fwdX / fLen   fwdY = fwdY / fLen   fwdZ = fwdZ / fLen
    rightX = -fwdZ   rightY = 0   rightZ = fwdX
    rLen = sqrt(rightX*rightX + rightY*rightY + rightZ*rightZ)
    if rLen < 0.0001
        projSX = SCREEN_W / 2
        projSY = SCREEN_H / 2
        return
    ok
    rightX = rightX / rLen   rightY = rightY / rLen   rightZ = rightZ / rLen
    upX = rightY * fwdZ - rightZ * fwdY
    upY = rightZ * fwdX - rightX * fwdZ
    upZ = rightX * fwdY - rightY * fwdX
    dx = wx - camPosX   dy = wy - camPosY   dz = wz - camPosZ
    dotFwd   = dx * fwdX   + dy * fwdY   + dz * fwdZ
    dotRight = dx * rightX + dy * rightY + dz * rightZ
    dotUp    = dx * upX    + dy * upY    + dz * upZ
    if dotFwd < 0.01
        projSX = -9999   projSY = -9999
        return
    ok
    fovRad = 45.0 * PI / 180.0
    tanHalf = tan(fovRad / 2.0)
    aspect = SCREEN_W * 1.0 / SCREEN_H
    ndcX = (dotRight / dotFwd) / (tanHalf * aspect)
    ndcY = (dotUp / dotFwd) / tanHalf
    projSX = (ndcX * 0.5 + 0.5) * SCREEN_W
    projSY = (1.0 - (ndcY * 0.5 + 0.5)) * SCREEN_H

// =============================================================
// Camera
// =============================================================

func bb_positionCamera
    cx = gridW / 2.0
    cy = gridH / 2.0

    if cameraMode = CAM_FRONT
        camPosX = cx
        camPosY = cy + 0.5
        camPosZ = gridW + 4.0
        camTgtX = cx
        camTgtY = cy
        camTgtZ = 0.0
    ok
    if cameraMode = CAM_ANGLE
        camPosX = cx + 3.0
        camPosY = cy + 4.0
        camPosZ = gridW + 2.0
        camTgtX = cx
        camTgtY = cy - 1.0
        camTgtZ = 0.0
    ok
    if cameraMode = CAM_TOP
        camPosX = cx
        camPosY = cy + gridH + 5.0
        camPosZ = 2.0
        camTgtX = cx
        camTgtY = cy
        camTgtZ = 0.0
    ok

// =============================================================
// Message Helper
// =============================================================

func bb_showMsg txt
    msgText = txt
    msgTimer = 3.0

// =============================================================
// 3D Rendering
// =============================================================

func bb_drawGrid3D
    // Draw floor
    for r = 1 to gridH
        for c = 1 to gridW
            wx = c - 0.5
            wy = (gridH - r) + 0.5
            // Floor tile
            if (r + c) % 2 = 0
                fc = RAYLIBColor(25, 25, 35, 255)
            else
                fc = RAYLIBColor(30, 30, 40, 255)
            ok
            DrawCube(Vector3(wx, wy, -0.05), 0.95, 0.95, 0.05, fc)
        next
    next

    // Draw objects
    for r = 1 to gridH
        for c = 1 to gridW
            wx = c - 0.5
            wy = (gridH - r) + 0.5
            tiles = grid[r][c]
            for ti = 1 to len(tiles)
                t = tiles[ti]
                bb_drawTile3D(wx, wy, t, r, c)
            next
        next
    next

func bb_drawTile3D wx, wy, tile, row, col
    z = 0.15
    sz = 0.4
    pulse = 0.8 + sin(animTime * 3.0 + row * 0.7 + col * 1.1) * 0.2

    // Objects
    if tile = T_BABA
        // White character with pinkish tint
        props = bb_getObjProp(T_BABA)
        if (props & P_YOU) > 0
            bob = sin(animTime * 4.0) * 0.05
            DrawCube(Vector3(wx, wy + bob, z), sz * 0.8, sz, sz * 0.9,
                     RAYLIBColor(240, 240, 240, 255))
            // Eyes
            DrawSphere(Vector3(wx - 0.08, wy + bob + 0.1, z + 0.2), 0.06,
                       RAYLIBColor(30, 30, 30, 255))
            DrawSphere(Vector3(wx + 0.08, wy + bob + 0.1, z + 0.2), 0.06,
                       RAYLIBColor(30, 30, 30, 255))
        else
            DrawCube(Vector3(wx, wy, z), sz * 0.8, sz, sz * 0.9,
                     RAYLIBColor(200, 200, 200, 255))
        ok
        return
    ok

    if tile = T_WALL
        DrawCube(Vector3(wx, wy, z), 0.85, 0.85, 0.5,
                 RAYLIBColor(80, 80, 90, 255))
        DrawCubeWires(Vector3(wx, wy, z), 0.85, 0.85, 0.5,
                      RAYLIBColor(100, 100, 110, 180))
        return
    ok

    if tile = T_ROCK
        DrawSphere(Vector3(wx, wy, z + 0.05), sz * 0.7,
                   RAYLIBColor(140, 110, 70, 255))
        return
    ok

    if tile = T_FLAG
        // Flag pole
        DrawCube(Vector3(wx, wy, z + 0.2), 0.04, 0.04, 0.5,
                 RAYLIBColor(120, 120, 120, 255))
        // Flag
        wave = sin(animTime * 3.0 + col) * 0.05
        DrawCube(Vector3(wx + 0.15 + wave, wy, z + 0.35), 0.25, 0.04, 0.15,
                 RAYLIBColor(255, 220, 50, 255))
        return
    ok

    if tile = T_KEY
        DrawSphere(Vector3(wx, wy, z), sz * 0.4,
                   RAYLIBColor(220, 180, 50, 255))
        DrawCube(Vector3(wx + 0.15, wy, z), 0.15, 0.05, 0.05,
                 RAYLIBColor(220, 180, 50, 255))
        return
    ok

    if tile = T_DOOR
        DrawCube(Vector3(wx, wy, z + 0.1), 0.6, 0.7, 0.6,
                 RAYLIBColor(160, 60, 60, 255))
        DrawCubeWires(Vector3(wx, wy, z + 0.1), 0.6, 0.7, 0.6,
                      RAYLIBColor(200, 80, 80, 180))
        return
    ok

    if tile = T_WATER
        wh = 0.05 + sin(animTime * 2.0 + row + col) * 0.03
        DrawCube(Vector3(wx, wy, wh), 0.9, 0.9, 0.08,
                 RAYLIBColor(50, 100, 200, floor(180 * pulse)))
        return
    ok

    if tile = T_SKULL
        DrawSphere(Vector3(wx, wy, z), sz * 0.5,
                   RAYLIBColor(200, 190, 170, 255))
        // Eye sockets
        DrawSphere(Vector3(wx - 0.08, wy, z + 0.15), 0.05,
                   RAYLIBColor(30, 10, 10, 255))
        DrawSphere(Vector3(wx + 0.08, wy, z + 0.15), 0.05,
                   RAYLIBColor(30, 10, 10, 255))
        return
    ok

    if tile = T_LAVA
        wh = 0.05 + sin(animTime * 3.0 + row * 2 + col) * 0.03
        lc = floor(200 + sin(animTime * 5.0 + col) * 55)
        DrawCube(Vector3(wx, wy, wh), 0.9, 0.9, 0.08,
                 RAYLIBColor(lc, floor(lc * 0.3), 10, 230))
        return
    ok

    // Word blocks
    if bb_isWordTile(tile)
        bb_drawWordBlock3D(wx, wy, tile, pulse)
        return
    ok

func bb_drawWordBlock3D wx, wy, tile, pulse
    z = 0.2
    bsz = 0.42

    // Determine color and text
    label = ""
    bgR = 60
    bgG = 60
    bgB = 70
    fgR = 255
    fgG = 255
    fgB = 255

    // Noun words - white text on dark bg
    if tile = W_BABA label = "BABA" fgR = 240 fgG = 100 fgB = 120 ok
    if tile = W_WALL label = "WALL" fgR = 120 fgG = 140 fgB = 100 ok
    if tile = W_ROCK label = "ROCK" fgR = 160 fgG = 130 fgB = 80 ok
    if tile = W_FLAG label = "FLAG" fgR = 255 fgG = 220 fgB = 50 ok
    if tile = W_KEY  label = "KEY"  fgR = 220 fgG = 180 fgB = 50 ok
    if tile = W_DOOR label = "DOOR" fgR = 200 fgG = 80 fgB = 80 ok
    if tile = W_WATER label = "WATER" fgR = 80 fgG = 160 fgB = 220 ok
    if tile = W_SKULL label = "SKULL" fgR = 200 fgG = 190 fgB = 170 ok
    if tile = W_LAVA label = "LAVA" fgR = 230 fgG = 100 fgB = 30 ok

    // IS connector - white
    if tile = W_IS label = "IS" fgR = 255 fgG = 255 fgB = 255 ok

    // Property words
    if tile = W_YOU  label = "YOU"  bgR = 180 bgG = 40 bgB = 60 fgR = 255 fgG = 255 fgB = 255 ok
    if tile = W_WIN  label = "WIN"  bgR = 180 bgG = 160 bgB = 30 fgR = 255 fgG = 255 fgB = 255 ok
    if tile = W_STOP label = "STOP" bgR = 60 bgG = 90 bgB = 50 fgR = 200 fgG = 220 fgB = 180 ok
    if tile = W_PUSH label = "PUSH" bgR = 80 bgG = 60 bgB = 40 fgR = 200 fgG = 170 fgB = 120 ok
    if tile = W_OPEN label = "OPEN" bgR = 50 bgG = 100 bgB = 50 fgR = 150 fgG = 255 fgB = 150 ok
    if tile = W_SHUT label = "SHUT" bgR = 100 bgG = 40 bgB = 40 fgR = 255 fgG = 120 fgB = 120 ok
    if tile = W_SINK label = "SINK" bgR = 30 bgG = 60 bgB = 120 fgR = 100 fgG = 180 fgB = 255 ok
    if tile = W_DEFEAT label = "DEFEAT" bgR = 100 bgG = 20 bgB = 20 fgR = 255 fgG = 80 fgB = 80 ok

    // Draw block
    DrawCube(Vector3(wx, wy, z), bsz * 2, bsz * 2, bsz,
             RAYLIBColor(bgR, bgG, bgB, 240))
    DrawCubeWires(Vector3(wx, wy, z), bsz * 2, bsz * 2, bsz,
                  RAYLIBColor(fgR, fgG, fgB, floor(120 * pulse)))

    // Text is drawn in 2D HUD pass (see bb_drawHUD)

// =============================================================
// HUD
// =============================================================

func bb_drawHUD
    // Level info panel
    DrawRectangle(10, 10, 220, 75, Fade(BLACK, 0.7))
    DrawRectangleLines(10, 10, 220, 75, RAYLIBColor(120, 120, 140, 180))

    DrawText("BABA IS YOU 3D", 20, 18, 16, RAYLIBColor(240, 100, 120, 255))
    lStr = "Level: " + currentLevel + " / " + levelCount
    DrawText(lStr, 20, 40, 13, RAYLIBColor(180, 180, 200, 200))
    DrawText("Z=Undo R=Reset F=Solve", 20, 58, 11, RAYLIBColor(140, 140, 160, 180))

    // Draw active rules on right side
    bb_drawActiveRules()

    // Draw word labels on tiles (2D overlay)
    bb_drawWordLabels()

func bb_drawActiveRules
    // Show current active rules
    rx = SCREEN_W - 200
    ry = 10
    DrawRectangle(rx - 5, ry, 195, 20, Fade(BLACK, 0.6))
    DrawText("Active Rules:", rx, ry + 3, 13, RAYLIBColor(200, 200, 220, 220))
    ry += 22

    ruleCount = 0
    for objType = 1 to 9
        props = objProps[objType]
        if props > 0
            name = bb_typeName(objType)
            pstr = ""
            if (props & P_YOU) > 0 pstr += "YOU " ok
            if (props & P_WIN) > 0 pstr += "WIN " ok
            if (props & P_STOP) > 0 pstr += "STOP " ok
            if (props & P_PUSH) > 0 pstr += "PUSH " ok
            if (props & P_OPEN) > 0 pstr += "OPEN " ok
            if (props & P_SHUT) > 0 pstr += "SHUT " ok
            if (props & P_SINK) > 0 pstr += "SINK " ok
            if (props & P_DEFEAT) > 0 pstr += "DEFEAT " ok

            ruleStr = name + " IS " + pstr
            DrawRectangle(rx - 5, ry, 195, 16, Fade(BLACK, 0.5))
            DrawText(ruleStr, rx, ry + 1, 11, RAYLIBColor(180, 200, 180, 220))
            ry += 17
            ruleCount += 1
        ok

        // Show transform rules
        if objTransform[objType] > 0
            name = bb_typeName(objType)
            tgtName = bb_typeName(objTransform[objType])
            ruleStr = name + " IS " + tgtName
            DrawRectangle(rx - 5, ry, 195, 16, Fade(BLACK, 0.5))
            DrawText(ruleStr, rx, ry + 1, 11, RAYLIBColor(200, 160, 160, 220))
            ry += 17
            ruleCount += 1
        ok
    next

func bb_typeName objType
    if objType = T_BABA return "BABA" ok
    if objType = T_WALL return "WALL" ok
    if objType = T_ROCK return "ROCK" ok
    if objType = T_FLAG return "FLAG" ok
    if objType = T_KEY return "KEY" ok
    if objType = T_DOOR return "DOOR" ok
    if objType = T_WATER return "WATER" ok
    if objType = T_SKULL return "SKULL" ok
    if objType = T_LAVA return "LAVA" ok
    return "???"

func bb_drawWordLabels
    // Project each word block to screen and draw its label
    for r = 1 to gridH
        for c = 1 to gridW
            tiles = grid[r][c]
            for ti = 1 to len(tiles)
                t = tiles[ti]
                if bb_isWordTile(t)
                    wx = c - 0.5
                    wy = (gridH - r) + 0.5

                    bb_projectToScreen(wx, wy, 0.45)
                    sx = projSX
                    sy = projSY
                    if sx < -500 or sx > SCREEN_W + 500 loop ok

                    label = bb_tileLabel(t)
                    fontSize = 11
                    if len(label) > 4 fontSize = 9 ok
                    tw = MeasureText(label, fontSize)
                    fc = bb_tileLabelColor(t)

                    DrawText(label, floor(sx - tw/2), floor(sy - 6), fontSize, fc)
                ok
            next
        next
    next

func bb_tileLabel t
    if t = W_BABA return "BABA" ok
    if t = W_WALL return "WALL" ok
    if t = W_ROCK return "ROCK" ok
    if t = W_FLAG return "FLAG" ok
    if t = W_KEY  return "KEY" ok
    if t = W_DOOR return "DOOR" ok
    if t = W_WATER return "WATER" ok
    if t = W_SKULL return "SKULL" ok
    if t = W_LAVA return "LAVA" ok
    if t = W_IS   return "IS" ok
    if t = W_YOU  return "YOU" ok
    if t = W_WIN  return "WIN" ok
    if t = W_STOP return "STOP" ok
    if t = W_PUSH return "PUSH" ok
    if t = W_OPEN return "OPEN" ok
    if t = W_SHUT return "SHUT" ok
    if t = W_SINK return "SINK" ok
    if t = W_DEFEAT return "DEFEAT" ok
    return "?"

func bb_tileLabelColor t
    if t = W_BABA return RAYLIBColor(240, 100, 120, 255) ok
    if t = W_WALL return RAYLIBColor(120, 140, 100, 255) ok
    if t = W_ROCK return RAYLIBColor(160, 130, 80, 255) ok
    if t = W_FLAG return RAYLIBColor(255, 220, 50, 255) ok
    if t = W_KEY  return RAYLIBColor(220, 180, 50, 255) ok
    if t = W_DOOR return RAYLIBColor(200, 80, 80, 255) ok
    if t = W_WATER return RAYLIBColor(80, 160, 220, 255) ok
    if t = W_SKULL return RAYLIBColor(200, 190, 170, 255) ok
    if t = W_LAVA return RAYLIBColor(230, 100, 30, 255) ok
    if t = W_IS   return RAYLIBColor(255, 255, 255, 255) ok
    if t = W_YOU  return RAYLIBColor(255, 255, 255, 255) ok
    if t = W_WIN  return RAYLIBColor(255, 255, 255, 255) ok
    if t = W_STOP return RAYLIBColor(200, 220, 180, 255) ok
    if t = W_PUSH return RAYLIBColor(200, 170, 120, 255) ok
    if t = W_OPEN return RAYLIBColor(150, 255, 150, 255) ok
    if t = W_SHUT return RAYLIBColor(255, 120, 120, 255) ok
    if t = W_SINK return RAYLIBColor(100, 180, 255, 255) ok
    if t = W_DEFEAT return RAYLIBColor(255, 80, 80, 255) ok
    return WHITE

// =============================================================
// Win/Lose Overlays
// =============================================================

func bb_drawWinOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.3))
    pulse = 0.7 + sin(animTime * 4.0) * 0.3
    txt = "LEVEL COMPLETE!"
    tw = MeasureText(txt, 36)
    DrawText(txt, (SCREEN_W - tw)/2, SCREEN_H/2 - 40, 36,
             RAYLIBColor(80, 255, 120, floor(255 * pulse)))
    txt2 = "Press ENTER for next level"
    tw2 = MeasureText(txt2, 18)
    DrawText(txt2, (SCREEN_W - tw2)/2, SCREEN_H/2 + 10, 18,
             RAYLIBColor(200, 200, 200, 200))

func bb_drawLoseOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.3))
    txt = "NO YOU - PRESS R TO RESTART"
    tw = MeasureText(txt, 24)
    DrawText(txt, (SCREEN_W - tw)/2, SCREEN_H/2 - 20, 24,
             RAYLIBColor(255, 80, 60, 255))

// =============================================================
// Particles
// =============================================================

func bb_spawnWinParticles
    for i = 1 to 40
        p = list(8)
        p[1] = SCREEN_W / 2.0 + (GetRandomValue(0, 400) - 200)
        p[2] = SCREEN_H / 2.0 + (GetRandomValue(0, 200) - 100)
        p[3] = (GetRandomValue(0, 200) - 100) / 50.0
        p[4] = (GetRandomValue(0, 200) - 150) / 50.0
        p[5] = GetRandomValue(60, 255)     // R
        p[6] = 255                          // G
        p[7] = GetRandomValue(60, 180)     // B
        p[8] = 1.5                          // life
        add(particles, p)
    next

func bb_updateParticles dt
    i = 1
    while i <= len(particles)
        particles[i][1] += particles[i][3] * dt * 60
        particles[i][2] += particles[i][4] * dt * 60
        particles[i][4] += 0.05
        particles[i][8] -= dt
        if particles[i][8] <= 0
            del(particles, i)
            loop
        ok
        i += 1
    end

func bb_drawParticles3D
    // Particles drawn in 2D pass instead
    return

// =============================================================
// Title Screen
// =============================================================

func bb_drawTitle
    // Background
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(15, 15, 25, 255))

    // Title
    pulse = 0.7 + sin(animTime * 2.0) * 0.3
    t1 = "BABA"
    tw1 = MeasureText(t1, 60)
    DrawText(t1, (SCREEN_W - tw1)/2 - 80, 80, 60, RAYLIBColor(240, 240, 240, floor(255 * pulse)))

    t2 = "IS"
    tw2 = MeasureText(t2, 50)
    DrawText(t2, (SCREEN_W - tw2)/2, 90, 50, RAYLIBColor(255, 255, 255, 220))

    t3 = "YOU"
    tw3 = MeasureText(t3, 60)
    DrawText(t3, (SCREEN_W - tw3)/2 + 80, 80, 60, RAYLIBColor(220, 60, 80, floor(255 * pulse)))

    // 3D subtitle
    sub = "3D Edition"
    sw = MeasureText(sub, 20)
    DrawText(sub, (SCREEN_W - sw)/2, 155, 20, RAYLIBColor(120, 120, 150, 200))

    // Controls
    cy = 220
    cKeys = [
        "Arrows / WASD",
        "Z",
        "R",
        "F",
        "N / B",
        "C"
    ]
    cDescs = [
        "Move (the object that IS YOU)",
        "Undo last move",
        "Reset current level",
        "Auto-solve level",
        "Next / Previous level",
        "Cycle camera view"
    ]
    keyCol = RAYLIBColor(255, 220, 100, 240)
    descCol = RAYLIBColor(180, 170, 140, 230)
    kx = 200
    dx = 400
    for i = 1 to len(cKeys)
        DrawText(cKeys[i], kx, cy + (i - 1) * 22, 14, keyCol)
        DrawText("-   " + cDescs[i], dx, cy + (i - 1) * 22, 13, descCol)
    next

    // Rules explanation
    ry = 380
    ruleCol = RAYLIBColor(200, 200, 220, 200)
    rLines = [
        "HOW TO PLAY:",
        "",
        "Push WORD BLOCKS to form sentences that change the rules!",
        "   NOUN + IS + PROPERTY    (e.g. BABA IS YOU)",
        "   NOUN + IS + NOUN        (transforms objects)",
        "",
        "Properties: YOU  WIN  STOP  PUSH  OPEN  SHUT  SINK  DEFEAT",
        "",
        "15 puzzles of increasing difficulty"
    ]
    for i = 1 to len(rLines)
        lw = MeasureText(rLines[i], 14)
        col = ruleCol
        if i = 1 col = RAYLIBColor(255, 220, 130, 240) ok
        if i = 4 or i = 5 col = RAYLIBColor(160, 180, 200, 200) ok
        DrawText(rLines[i], (SCREEN_W - lw)/2, ry + (i - 1) * 22, 14, col)
    next

    // Start prompt
    if floor(animTime * 2) % 2 = 0
        st = "Press ENTER or Click to Start"
        stw = MeasureText(st, 22)
        DrawText(st, (SCREEN_W - stw)/2, 620, 22, WHITE)
    ok

    // Draw 2D particles
    for i = 1 to len(particles)
        if particles[i][8] > 0
            alpha = floor(255 * particles[i][8] / 1.5)
            if alpha > 255 alpha = 255 ok
            DrawCircle(floor(particles[i][1]), floor(particles[i][2]), 3,
                       RAYLIBColor(particles[i][5], particles[i][6], particles[i][7], alpha))
        ok
    next
