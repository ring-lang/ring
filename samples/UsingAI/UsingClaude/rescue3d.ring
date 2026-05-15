/*
**  3D Rescue Rover - Using RingRayLib
**  ==========================================
**  A classic puzzle game in 3D!
**  Push boxes, collect keys, redirect lasers with ice blocks,
**  fill water with crates, rescue your dog, and escape!
**
**  Controls:
**    Arrow Keys / WASD  -  Move
**    Z / U              -  Undo last move
**    R                  -  Restart level
**    C                  -  Cycle camera
**    N                  -  Next level (after winning)
**    ESC                -  Exit
**
**  Tiles:
**    Floor      -  Walk freely
**    Wall       -  Impassable (purple/gray stone)
**    Box        -  Pushable crate (brown wooden)
**    Water      -  Impassable, push box into it to make bridge
**    Ice Block  -  Pushable, reflects/redirects lasers
**    Laser Src  -  Emits deadly laser beam
**    Key        -  Collect to open locked doors
**    Door       -  Locked until key collected
**    Exit Door  -  Leave with dog to win!
**    Dog        -  Rescue target, follows you once reached
**    Fire/Lava  -  Deadly, instant kill
**
**  Mechanics:
**    - Push boxes/ice by walking into them (Sokoban style)
**    - Boxes fill water tiles (become bridge)
**    - Ice blocks redirect laser beams
**    - Lasers kill player on contact
**    - Collect key before opening locked door
**    - Reach dog, then go to exit door to win
**    - Full undo system
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W        = 1024
SCREEN_H        = 768
CELL_SZ         = 1.0

// Tile types
T_FLOOR         = 0
T_WALL          = 1
T_BOX           = 2
T_WATER         = 3
T_ICE           = 4    // Pushable, redirects laser
T_LASER_U       = 5    // Laser source pointing up
T_LASER_D       = 6    // Laser source pointing down
T_LASER_L       = 7    // Laser source pointing left
T_LASER_R       = 8    // Laser source pointing right
T_KEY           = 9
T_DOOR          = 10   // Locked door
T_EXIT          = 11   // Exit door
T_DOG           = 12
T_FIRE          = 13
T_BRIDGE        = 14   // Box that fell in water
T_FANCYFLOOR   = 15   // Decorative floor tile

// Directions
DIR_UP          = 0
DIR_DOWN        = 1
DIR_LEFT        = 2
DIR_RIGHT       = 3

// Game states
ST_TITLE        = 0
ST_PLAYING      = 1
ST_WON          = 2
ST_DEAD         = 3

// Camera modes
CAM_TOP         = 0
CAM_ANGLE       = 1
CAM_CLOSE       = 2
CAM_COUNT       = 3

// Max
MAX_LEVELS      = 8
GRID_W          = 20
GRID_H          = 16

// =============================================================
// Global Variables
// =============================================================

gameState       = ST_TITLE
level           = 1
moves           = 0

// Grid
tiles           = []

// Player
px = 1
py = 1
pdir = DIR_DOWN
hasKey = false
hasDog = false
palive = true
pAnimTime = 0.0
pMoving = false

// Dog position
dogX = 1
dogY = 1
dogFollowing = false
dogAnimTime = 0.0

// Laser beams: list of [x, y, dir] segments
laserBeams = []

// Undo stack: list of [tiles_copy, px, py, dogX, dogY, hasKey, hasDog, dogFollowing, moves]
undoStack = []
MAX_UNDO = 100

// Particles
particles = []

// Camera
camMode = CAM_CLOSE
cam = NULL

// Animation
animTime = 0.0
deathTimer = 0.0
winTimer = 0.0
msgTimer = 0.0
msgText = ""

// Level dimensions (actual used per level)
lvlW = 20
lvlH = 16

// =============================================================
// Main
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Ring 3D Rescue Rover - RingRayLib")
SetTargetFPS(60)

cam = Camera3D(
    10, 20, 18,
    10, 0, 8,
    0, 1, 0,
    45,
    0
)

rover_loadLevel(level)

while !WindowShouldClose()
    dt = GetFrameTime()
    if dt > 0.05 dt = 0.05 ok

    animTime += dt

    rover_handleInput()
    rover_update(dt)

    BeginDrawing()
        ClearBackground(RAYLIBColor(20, 15, 25, 255))
        rover_updateCamera()
        BeginMode3D(cam)
            rover_drawFloor()
            rover_drawWalls()
            rover_drawObjects()
            rover_drawLasers()
            rover_drawDog()
            rover_drawPlayer()
            rover_drawParticles()
        EndMode3D()
        rover_drawHUD()
    EndDrawing()
end

CloseWindow()

// =============================================================
// Level Loading
// =============================================================

func rover_loadLevel lvl
    palive = true
    hasKey = false
    hasDog = false
    dogFollowing = false
    pdir = DIR_DOWN
    moves = 0
    undoStack = []
    particles = []
    laserBeams = []
    pAnimTime = 0.0
    msgTimer = 0.0

    tiles = list(GRID_H)
    for r = 1 to GRID_H
        tiles[r] = list(GRID_W)
        for c = 1 to GRID_W
            tiles[r][c] = T_WALL
        next
    next

    if lvl = 1 rover_level1()
    but lvl = 2 rover_level2()
    but lvl = 3 rover_level3()
    but lvl = 4 rover_level4()
    but lvl = 5 rover_level5()
    but lvl = 6 rover_level6()
    but lvl = 7 rover_level7()
    but lvl = 8 rover_level8()
    ok

    rover_calcLasers()

// --- Level 1: Tutorial - Simple push, key, door, dog ---
// Solution: Push box UP to clear path to key. Get key (left).
//           Go right, open door. Get dog. Go to exit.
func rover_level1
    lvlW = 10 lvlH = 8
    for r = 2 to 7
        for c = 2 to 9
            tiles[r][c] = T_FLOOR
        next
    next
    // Walls: corridor with rooms
    for c = 2 to 6
        tiles[4][c] = T_WALL
    next
    tiles[4][4] = T_FLOOR  // Gap in wall
    // Box blocking path to key
    tiles[3][4] = T_BOX
    // Key in top-left room
    tiles[2][2] = T_KEY
    // Locked door on right side
    tiles[4][8] = T_DOOR
    // Dog behind door
    tiles[3][9] = T_DOG
    dogX = 9 dogY = 3
    // Exit bottom-right
    tiles[7][9] = T_EXIT
    // Player
    px = 4 py = 6

// --- Level 2: Water crossing ---
// Solution: Push 3 boxes DOWN into water row 6 (cols 5,6,7) to make bridge.
//           Cross bridge, get key. Go open door, get dog, exit.
func rover_level2
    lvlW = 12 lvlH = 10
    for r = 2 to 9
        for c = 2 to 11
            tiles[r][c] = T_FLOOR
        next
    next
    // Water: single row channel across map
    for c = 4 to 9
        tiles[6][c] = T_WATER
    next
    // 3 boxes above water (push down to fill)
    tiles[5][5] = T_BOX
    tiles[5][6] = T_BOX
    tiles[5][7] = T_BOX
    // Key in bottom area
    tiles[8][6] = T_KEY
    // Door in top area
    tiles[3][10] = T_DOOR
    // Dog behind door
    tiles[2][10] = T_DOG
    dogX = 10 dogY = 2
    // Exit
    tiles[9][2] = T_EXIT
    // Player starts top-left
    px = 3 py = 3

// --- Level 3: Laser introduction ---
// Layout: Open room. Laser fires RIGHT from [5][2] across row 5.
//         A box at [5][5] sits in the laser path - it blocks the beam.
//         Player starts at bottom (row 8). Key is at top-right [3][10].
//         Must go above or below the laser. Row 5 is dangerous but box blocks it partially.
//         Player pushes the box RIGHT to extend the blocked section, creating safe crossing.
//         OR: Player navigates around via rows above laser (rows 2-4 are safe).
// Solution: Go up cols 2-4 (safe, left of laser source), cross row 3 to right side,
//           get key at [3][10], go down to door at [7][10], open it, get dog at [8][10], 
//           go back to exit at [8][3].
func rover_level3
    lvlW = 12 lvlH = 10
    for r = 2 to 9
        for c = 2 to 11
            tiles[r][c] = T_FLOOR
        next
    next
    // Laser source shoots RIGHT across row 5
    tiles[5][2] = T_LASER_R
    // Box partially blocks laser (player can push it or go around)
    tiles[5][6] = T_BOX
    // Wall creating obstacle - forces thinking about path
    for c = 4 to 8
        tiles[7][c] = T_WALL
    next
    // Gap in wall at col 9 to pass through
    // Key in top-right area (safe, above laser)
    tiles[3][10] = T_KEY
    // Door in bottom-right (below laser, accessible via right side)
    tiles[8][10] = T_DOOR
    // Dog behind door
    tiles[9][10] = T_DOG
    dogX = 10 dogY = 9
    // Exit bottom-left
    tiles[9][3] = T_EXIT
    // Player starts bottom-left (below laser, below wall)
    px = 3 py = 8

// --- Level 4: Water + box logistics ---
// Solution: Push boxes into water column to build bridge across.
//           Navigate around walls to get key, open door, rescue dog, exit.
func rover_level4
    lvlW = 14 lvlH = 10
    for r = 2 to 9
        for c = 2 to 13
            tiles[r][c] = T_FLOOR
        next
    next
    // Vertical water column dividing map
    for r = 3 to 7
        tiles[r][7] = T_WATER
    next
    // Boxes on left side to push RIGHT into water
    tiles[4][6] = T_BOX
    tiles[5][6] = T_BOX
    tiles[6][6] = T_BOX
    // Walls guiding puzzle
    tiles[3][5] = T_WALL
    tiles[7][5] = T_WALL
    tiles[3][9] = T_WALL
    tiles[7][9] = T_WALL
    // Key on right side
    tiles[5][11] = T_KEY
    // Door on right side
    tiles[3][12] = T_DOOR
    // Dog
    tiles[2][12] = T_DOG
    dogX = 12 dogY = 2
    // Exit on left
    tiles[9][2] = T_EXIT
    // Player starts bottom-left
    px = 3 py = 8

// --- Level 5: Laser + blocking ---
// Layout: Two lasers. Laser 1 RIGHT from [4][2] across row 4.
//         Laser 2 RIGHT from [8][2] across row 8.
//         Two boxes near each laser to push into beam and block.
//         Player starts at bottom-left, must block lasers to cross safely.
// Solution: Push box at [4][5] LEFT into [4][4] doesn't help (further from player).
//           Push box at [6][5] UP to [5][5] then UP to [4][5] - box blocks laser at col 5.
//           Row 4 cols 6+ are safe. Cross row 4.
//           Push box at [6][9] DOWN to [7][9] then DOWN to [8][9] - blocks laser 2 at col 9.
//           Row 8 cols 10+ are safe. Navigate to key, door, dog, exit.
func rover_level5
    lvlW = 14 lvlH = 12
    for r = 2 to 11
        for c = 2 to 13
            tiles[r][c] = T_FLOOR
        next
    next
    // Laser 1: fires RIGHT across row 4
    tiles[4][2] = T_LASER_R
    // Laser 2: fires RIGHT across row 8
    tiles[8][2] = T_LASER_R
    // Box to block laser 1 - push UP into row 4
    tiles[6][5] = T_BOX
    // Box to block laser 2 - push DOWN into row 8
    tiles[6][9] = T_BOX
    // Walls creating zones
    for r = 5 to 7
        tiles[r][3] = T_WALL   // Left barrier
    next
    tiles[3][7] = T_WALL
    tiles[9][7] = T_WALL
    tiles[10][7] = T_WALL
    // Key in top-right (above laser 1 - safe zone)
    tiles[3][12] = T_KEY
    // Door in bottom area
    tiles[10][12] = T_DOOR
    // Dog behind door
    tiles[11][12] = T_DOG
    dogX = 12 dogY = 11
    // Exit bottom-left
    tiles[11][3] = T_EXIT
    // Player starts middle-left (between the two lasers)
    px = 4 py = 6

// --- Level 6: Water + fire gauntlet ---
// Layout: Water row across middle. Fire patches to avoid. Boxes to bridge.
// Solution: Push boxes DOWN into water at row 6 (cols 6,7,8). Cross bridge.
//           Navigate around fire. Get key bottom-right. Door top-right. Dog. Exit.
func rover_level6
    lvlW = 14 lvlH = 12
    for r = 2 to 11
        for c = 2 to 13
            tiles[r][c] = T_FLOOR
        next
    next
    // Water row across middle
    for c = 5 to 9
        tiles[6][c] = T_WATER
    next
    // Fire hazards (avoid!)
    tiles[5][3] = T_FIRE
    tiles[5][4] = T_FIRE
    tiles[8][11] = T_FIRE
    tiles[8][12] = T_FIRE
    // Boxes above water - push DOWN to bridge
    tiles[5][6] = T_BOX
    tiles[5][7] = T_BOX
    tiles[5][8] = T_BOX
    // Walls
    tiles[4][5] = T_WALL
    tiles[4][9] = T_WALL
    tiles[8][5] = T_WALL
    tiles[8][9] = T_WALL
    // Key bottom-right
    tiles[10][12] = T_KEY
    // Door top-right
    tiles[3][12] = T_DOOR
    // Dog
    tiles[2][12] = T_DOG
    dogX = 12 dogY = 2
    // Exit bottom-left
    tiles[10][2] = T_EXIT
    // Player starts top-left
    px = 3 py = 3

// --- Level 7: Double laser + water bridge ---
// Layout: Two lasers firing RIGHT from rows 4 and 9.
//         Boxes to push into laser paths. Water gap to bridge.
// Solution: Push box [6][5] UP UP to [4][5] - blocks laser 1 at col 5.
//           Cross row 4 at col 6+. Push box [6][10] DOWN DOWN DOWN to [9][10] - blocks laser 2.
//           Cross row 9. Push boxes [8][12] and [8][13] DOWN into water [9][12],[9][13]... 
//           Wait, laser 2 is on row 9 - need to block it first. Then bridge water at row 10.
// Revised: Water at row 10 cols 12-13. Push boxes down to bridge.
func rover_level7
    lvlW = 16 lvlH = 12
    for r = 2 to 11
        for c = 2 to 15
            tiles[r][c] = T_FLOOR
        next
    next
    // Laser 1: RIGHT across row 4
    tiles[4][2] = T_LASER_R
    // Laser 2: RIGHT across row 9
    tiles[9][2] = T_LASER_R
    // Box to block laser 1 - push UP from row 6 to row 4
    tiles[6][6] = T_BOX
    // Box to block laser 2 - push DOWN from row 7 to row 9
    tiles[7][8] = T_BOX
    // Water gap in bottom area
    tiles[10][12] = T_WATER
    tiles[10][13] = T_WATER
    // Boxes for bridge - push DOWN into water
    tiles[9][12] = T_BOX
    tiles[9][13] = T_BOX
    // Walls
    for r = 5 to 7
        tiles[r][4] = T_WALL
    next
    tiles[3][10] = T_WALL
    tiles[5][10] = T_WALL
    // Key far right past water
    tiles[11][14] = T_KEY
    // Door top-right
    tiles[3][14] = T_DOOR
    // Dog
    tiles[2][14] = T_DOG
    dogX = 14 dogY = 2
    // Exit
    tiles[11][2] = T_EXIT
    // Player
    px = 3 py = 6

// --- Level 8: Grand finale ---
// All mechanics: walls, water, fire, lasers, boxes.
// Layout: Maze with laser RIGHT row 5, water gap, fire patches.
// Solution: Push box into laser to block. Bridge water. Avoid fire.
//           Get key, open door, rescue dog, exit.
func rover_level8
    lvlW = 16 lvlH = 14
    for r = 2 to 13
        for c = 2 to 15
            tiles[r][c] = T_FLOOR
        next
    next
    // === Wall maze ===
    for r = 3 to 5
        tiles[r][6] = T_WALL
    next
    for c = 8 to 10
        tiles[6][c] = T_WALL
    next
    for r = 8 to 10
        tiles[r][8] = T_WALL
    next

    // === Laser: RIGHT from [5][2] ===
    tiles[5][2] = T_LASER_R
    // Box to block laser - push UP from [7][4] to [5][4]
    tiles[7][4] = T_BOX

    // === Water gap ===
    for c = 11 to 13
        tiles[8][c] = T_WATER
    next
    // Boxes to bridge water - push DOWN
    tiles[7][11] = T_BOX
    tiles[7][12] = T_BOX
    tiles[7][13] = T_BOX

    // === Fire hazards ===
    tiles[10][5] = T_FIRE
    tiles[10][6] = T_FIRE
    tiles[4][13] = T_FIRE

    // === Key in bottom-right ===
    tiles[12][14] = T_KEY

    // === Door in top-right ===
    tiles[3][14] = T_DOOR

    // === Dog ===
    tiles[2][14] = T_DOG
    dogX = 14 dogY = 2

    // === Exit bottom-left ===
    tiles[12][2] = T_EXIT

    // Player start
    px = 3 py = 12

// =============================================================
// Laser Calculation
// =============================================================

func rover_calcLasers
    laserBeams = []
    for r = 1 to GRID_H
        for c = 1 to GRID_W
            t = tiles[r][c]
            dr = 0 dc = 0
            if t = T_LASER_U dr = -1 dc = 0 ok
            if t = T_LASER_D dr = 1 dc = 0 ok
            if t = T_LASER_L dr = 0 dc = -1 ok
            if t = T_LASER_R dr = 0 dc = 1 ok
            if dr = 0 and dc = 0 loop ok
            // Trace beam
            br = r + dr
            bc = c + dc
            maxSteps = 50
            steps = 0
            while br >= 1 and br <= GRID_H and bc >= 1 and bc <= GRID_W and steps < maxSteps
                steps += 1
                bt = tiles[br][bc]
                if bt = T_WALL or bt = T_BOX or bt = T_DOOR or bt = T_BRIDGE
                    exit
                ok
                if bt = T_ICE
                    // Redirect: ice reflects the beam 90 degrees
                    add(laserBeams, [bc, br, dr, dc])
                    if dr != 0
                        // Vertical beam hits ice -> redirect right
                        // Check: if coming from left side, go right, else go left
                        // Simple: always turn clockwise
                        oldDr = dr
                        dr = 0
                        dc = oldDr   // down->right, up->left
                    else
                        oldDc = dc
                        dc = 0
                        dr = oldDc   // right->down, left->up
                    ok
                    br += dr
                    bc += dc
                    loop
                ok
                add(laserBeams, [bc, br, dr, dc])
                br += dr
                bc += dc
            end
        next
    next

// =============================================================
// Input Handling
// =============================================================

func rover_handleInput
    if gameState = ST_TITLE
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            gameState = ST_PLAYING
            level = 1
            rover_loadLevel(level)
        ok
        return
    ok

    if gameState = ST_WON
        if IsKeyPressed(KEY_N) or IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            level += 1
            if level > MAX_LEVELS
                level = 1
                gameState = ST_TITLE
            else
                rover_loadLevel(level)
                gameState = ST_PLAYING
            ok
        ok
        return
    ok

    if gameState = ST_DEAD
        if IsKeyPressed(KEY_R) or IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            rover_loadLevel(level)
            gameState = ST_PLAYING
        ok
        return
    ok

    if gameState != ST_PLAYING
        return
    ok

    if IsKeyPressed(KEY_C)
        camMode = (camMode + 1) % CAM_COUNT
    ok

    if IsKeyPressed(KEY_R)
        rover_loadLevel(level)
        return
    ok

    // Undo
    if IsKeyPressed(KEY_Z) or IsKeyPressed(KEY_U)
        rover_undo()
        return
    ok

    // Movement
    dr = 0 dc = 0
    if IsKeyPressed(KEY_UP) or IsKeyPressed(KEY_W)
        dr = -1 pdir = DIR_UP
    ok
    if IsKeyPressed(KEY_DOWN) or IsKeyPressed(KEY_S)
        dr = 1 pdir = DIR_DOWN
    ok
    if IsKeyPressed(KEY_LEFT) or IsKeyPressed(KEY_A)
        dc = -1 pdir = DIR_LEFT
    ok
    if IsKeyPressed(KEY_RIGHT) or IsKeyPressed(KEY_D)
        dc = 1 pdir = DIR_RIGHT
    ok

    if dr = 0 and dc = 0
        return
    ok

    rover_tryMove(dr, dc)

// =============================================================
// Movement Logic
// =============================================================

func rover_tryMove dr, dc
    nr = py + dr
    nc = px + dc

    if nr < 1 or nr > GRID_H or nc < 1 or nc > GRID_W
        return
    ok

    t = tiles[nr][nc]

    // Wall - blocked
    if t = T_WALL
        return
    ok

    // Water - blocked (player can't walk on water)
    if t = T_WATER
        return
    ok

    // Fire - death
    if t = T_FIRE
        rover_saveUndo()
        py = nr
        px = nc
        palive = false
        gameState = ST_DEAD
        deathTimer = 2.0
        rover_showMsg("Burned alive!")
        rover_spawnDeathParticles(px, py)
        return
    ok

    // Door - need key
    if t = T_DOOR
        if hasKey
            rover_saveUndo()
            tiles[nr][nc] = T_FLOOR
            hasKey = false
            rover_showMsg("Door opened!")
            rover_spawnDoorParticles(nc, nr)
            // Don't move into door tile this turn
            return
        else
            rover_showMsg("Need a key!")
            return
        ok
    ok

    // Box or Ice - try to push
    if t = T_BOX or t = T_ICE
        // Check what's behind the box
        br = nr + dr
        bc = nc + dc
        if br < 1 or br > GRID_H or bc < 1 or bc > GRID_W
            return
        ok
        bt = tiles[br][bc]

        if t = T_BOX
            if bt = T_FLOOR or bt = T_FANCYFLOOR
                rover_saveUndo()
                tiles[br][bc] = T_BOX
                tiles[nr][nc] = T_FLOOR
            but bt = T_WATER
                rover_saveUndo()
                tiles[br][bc] = T_BRIDGE
                tiles[nr][nc] = T_FLOOR
                rover_spawnSplashParticles(bc, br)
                rover_showMsg("Box fills the water!")
            else
                return  // Can't push
            ok
        ok

        if t = T_ICE
            if bt = T_FLOOR or bt = T_FANCYFLOOR
                if len(undoStack) = 0 or tiles[nr][nc] != T_FLOOR
                    rover_saveUndo()
                ok
                tiles[br][bc] = T_ICE
                tiles[nr][nc] = T_FLOOR
            but bt = T_WATER
                if len(undoStack) = 0 or tiles[nr][nc] != T_FLOOR
                    rover_saveUndo()
                ok
                tiles[br][bc] = T_BRIDGE
                tiles[nr][nc] = T_FLOOR
                rover_spawnSplashParticles(bc, br)
            else
                return  // Can't push
            ok
        ok

        // Move player into the space
        if tiles[nr][nc] = T_FLOOR or tiles[nr][nc] = T_FANCYFLOOR
            py = nr
            px = nc
            moves += 1
            pMoving = true
            pAnimTime = 0
        ok

        rover_calcLasers()
        rover_checkLaserDeath()
        return
    ok

    // Exit door
    if t = T_EXIT
        if hasDog
            rover_saveUndo()
            py = nr
            px = nc
            gameState = ST_WON
            winTimer = 3.0
            rover_showMsg("Level Complete!")
            return
        else
            rover_showMsg("Rescue your dog first!")
            return
        ok
    ok

    // Dog - rescue!
    if t = T_DOG
        rover_saveUndo()
        tiles[nr][nc] = T_FLOOR
        hasDog = true
        dogFollowing = true
        dogX = px
        dogY = py
        py = nr
        px = nc
        moves += 1
        pMoving = true
        pAnimTime = 0
        rover_showMsg("Dog rescued! Find the exit!")
        return
    ok

    // Key - collect
    if t = T_KEY
        rover_saveUndo()
        tiles[nr][nc] = T_FLOOR
        hasKey = true
        rover_showMsg("Got the key!")
        // Move player
        if dogFollowing
            dogX = px
            dogY = py
        ok
        py = nr
        px = nc
        moves += 1
        pMoving = true
        pAnimTime = 0
        rover_checkLaserDeath()
        return
    ok

    // Floor / Bridge / FancyFloor - just walk
    if t = T_FLOOR or t = T_BRIDGE or t = T_FANCYFLOOR
        rover_saveUndo()
        if dogFollowing
            dogX = px
            dogY = py
        ok
        py = nr
        px = nc
        moves += 1
        pMoving = true
        pAnimTime = 0
        rover_checkLaserDeath()
        return
    ok

    // Laser sources - blocked
    if t >= T_LASER_U and t <= T_LASER_R
        return
    ok

// =============================================================
// Laser Death Check
// =============================================================

func rover_checkLaserDeath
    for i = 1 to len(laserBeams)
        lx = laserBeams[i][1]
        ly = laserBeams[i][2]
        if lx = px and ly = py
            palive = false
            gameState = ST_DEAD
            deathTimer = 2.0
            rover_showMsg("Zapped by laser!")
            rover_spawnDeathParticles(px, py)
            return
        ok
    next

// =============================================================
// Undo System
// =============================================================

func rover_saveUndo
    // Deep copy tiles
    tc = list(GRID_H)
    for r = 1 to GRID_H
        tc[r] = list(GRID_W)
        for c = 1 to GRID_W
            tc[r][c] = tiles[r][c]
        next
    next
    add(undoStack, [tc, px, py, dogX, dogY, hasKey, hasDog, dogFollowing, moves])
    if len(undoStack) > MAX_UNDO
        del(undoStack, 1)
    ok

func rover_undo
    if len(undoStack) = 0
        rover_showMsg("Nothing to undo!")
        return
    ok
    state = undoStack[len(undoStack)]
    del(undoStack, len(undoStack))
    tiles = state[1]
    px = state[2]
    py = state[3]
    dogX = state[4]
    dogY = state[5]
    hasKey = state[6]
    hasDog = state[7]
    dogFollowing = state[8]
    moves = state[9]
    rover_calcLasers()

// =============================================================
// Update
// =============================================================

func rover_update dt
    animTime += dt
    pAnimTime += dt

    if gameState = ST_DEAD
        deathTimer -= dt
    ok

    if msgTimer > 0
        msgTimer -= dt
    ok

    rover_updateParticles(dt)

// =============================================================
// Particles
// =============================================================

func rover_spawnDeathParticles bx, by
    for i = 1 to 20
        ang = GetRandomValue(0, 628) / 100.0
        spd = GetRandomValue(100, 400) / 100.0
        add(particles, [bx * 1.0, 0.5, by * 1.0,
                        cos(ang) * spd, GetRandomValue(200, 500)/100.0, sin(ang) * spd,
                        1.0, 1.0,
                        255, GetRandomValue(50, 150), 30,
                        0.08])
    next

func rover_spawnDoorParticles bx, by
    for i = 1 to 12
        ang = GetRandomValue(0, 628) / 100.0
        spd = GetRandomValue(50, 200) / 100.0
        add(particles, [bx * 1.0, 0.5, by * 1.0,
                        cos(ang) * spd, GetRandomValue(100, 300)/100.0, sin(ang) * spd,
                        0.7, 0.7,
                        255, 220, 50,
                        0.06])
    next

func rover_spawnSplashParticles bx, by
    for i = 1 to 10
        ang = GetRandomValue(0, 628) / 100.0
        spd = GetRandomValue(50, 250) / 100.0
        add(particles, [bx * 1.0, 0.1, by * 1.0,
                        cos(ang) * spd, GetRandomValue(200, 500)/100.0, sin(ang) * spd,
                        0.6, 0.6,
                        50, 120, 255,
                        0.06])
    next

func rover_updateParticles dt
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

func rover_showMsg txt
    msgText = txt
    msgTimer = 2.5

// =============================================================
// Camera
// =============================================================

func rover_updateCamera
    cx = lvlW / 2.0 + 0.5
    cz = lvlH / 2.0 + 0.5

    if camMode = CAM_TOP
        cam.position.x = cx
        cam.position.y = 18.0
        cam.position.z = cz + 1.0
        cam.target.x = cx
        cam.target.y = 0
        cam.target.z = cz
        cam.fovy = 50
    ok
    if camMode = CAM_ANGLE
        cam.position.x = cx
        cam.position.y = 14.0
        cam.position.z = cz + 10.0
        cam.target.x = cx
        cam.target.y = 0
        cam.target.z = cz
        cam.fovy = 50
    ok
    if camMode = CAM_CLOSE
        cam.position.x = px * 1.0
        cam.position.y = 12.0
        cam.position.z = py + 8.0
        cam.target.x = px * 1.0
        cam.target.y = 0
        cam.target.z = py * 1.0
        cam.fovy = 50
    ok

// =============================================================
// 3D Drawing: Floor (enhanced procedural)
// =============================================================

func rover_drawFloor
    // Ground plane (dark void)
    DrawCube(Vector3(lvlW/2.0 + 0.5, -0.06, lvlH/2.0 + 0.5),
             lvlW + 4.0, 0.08, lvlH + 4.0,
             RAYLIBColor(12, 8, 18, 255))

    for r = 1 to GRID_H
        for c = 1 to GRID_W
            t = tiles[r][c]
            wx = c * CELL_SZ
            wz = r * CELL_SZ

            // Floor tiles - checkered with edge detail
            if t = T_FLOOR or t = T_KEY or t = T_DOG or t = T_EXIT
                if (r + c) % 2 = 0
                    DrawCube(Vector3(wx, 0.0, wz), 0.98, 0.05, 0.98,
                             RAYLIBColor(100, 95, 108, 255))
                else
                    DrawCube(Vector3(wx, 0.0, wz), 0.98, 0.05, 0.98,
                             RAYLIBColor(85, 80, 92, 255))
                ok
                // Top highlight edge
                DrawCube(Vector3(wx, 0.026, wz - 0.48), 0.96, 0.005, 0.02,
                         RAYLIBColor(115, 110, 125, 120))
                DrawCube(Vector3(wx - 0.48, 0.026, wz), 0.02, 0.005, 0.96,
                         RAYLIBColor(115, 110, 125, 120))
                // Ambient occlusion (dark edges)
                DrawCube(Vector3(wx, 0.026, wz + 0.48), 0.96, 0.005, 0.02,
                         RAYLIBColor(55, 50, 62, 100))
                DrawCube(Vector3(wx + 0.48, 0.026, wz), 0.02, 0.005, 0.96,
                         RAYLIBColor(55, 50, 62, 100))
                // Tile mortar cross
                DrawCube(Vector3(wx, 0.027, wz), 0.02, 0.003, 0.98,
                         RAYLIBColor(65, 60, 72, 80))
                DrawCube(Vector3(wx, 0.027, wz), 0.98, 0.003, 0.02,
                         RAYLIBColor(65, 60, 72, 80))
            ok

            if t = T_FANCYFLOOR
                DrawCube(Vector3(wx, 0.0, wz), 0.98, 0.05, 0.98,
                         RAYLIBColor(118, 98, 128, 255))
                DrawCube(Vector3(wx, 0.027, wz), 0.70, 0.003, 0.70,
                         RAYLIBColor(138, 115, 148, 60))
            ok

            if t = T_BRIDGE
                // Wooden planks over water
                DrawCube(Vector3(wx, 0.01, wz), 0.96, 0.05, 0.96,
                         RAYLIBColor(140, 100, 40, 255))
                // Plank lines
                DrawCube(Vector3(wx, 0.04, wz - 0.15), 0.88, 0.01, 0.22,
                         RAYLIBColor(160, 118, 52, 255))
                DrawCube(Vector3(wx, 0.04, wz + 0.15), 0.88, 0.01, 0.22,
                         RAYLIBColor(155, 112, 48, 255))
                // Side rails
                DrawCube(Vector3(wx - 0.45, 0.04, wz), 0.06, 0.04, 0.94,
                         RAYLIBColor(110, 75, 28, 255))
                DrawCube(Vector3(wx + 0.45, 0.04, wz), 0.06, 0.04, 0.94,
                         RAYLIBColor(110, 75, 28, 255))
                // Nail dots
                DrawCube(Vector3(wx - 0.45, 0.065, wz - 0.30), 0.04, 0.01, 0.04,
                         RAYLIBColor(80, 60, 20, 255))
                DrawCube(Vector3(wx - 0.45, 0.065, wz + 0.30), 0.04, 0.01, 0.04,
                         RAYLIBColor(80, 60, 20, 255))
                DrawCube(Vector3(wx + 0.45, 0.065, wz - 0.30), 0.04, 0.01, 0.04,
                         RAYLIBColor(80, 60, 20, 255))
                DrawCube(Vector3(wx + 0.45, 0.065, wz + 0.30), 0.04, 0.01, 0.04,
                         RAYLIBColor(80, 60, 20, 255))
            ok

            if t = T_WATER
                wh = sin(animTime * 2.5 + wx + wz) * 0.02
                wh2 = sin(animTime * 3.2 + wx * 2.0) * 0.01
                // Deep water base
                DrawCube(Vector3(wx, -0.04 + wh, wz), 0.98, 0.05, 0.98,
                         RAYLIBColor(10, 30, 100, 255))
                // Mid water layer
                DrawCube(Vector3(wx, -0.01 + wh, wz), 0.96, 0.03, 0.96,
                         RAYLIBColor(20, 55, 145, 220))
                // Surface shimmer
                DrawCube(Vector3(wx + wh2 * 2, 0.02 + wh, wz), 0.50, 0.005, 0.50,
                         RAYLIBColor(60, 110, 200, 120))
                // Caustic highlights
                DrawCube(Vector3(wx - 0.15, 0.025 + wh, wz + 0.10), 0.22, 0.003, 0.18,
                         RAYLIBColor(80, 140, 220, 80))
                DrawCube(Vector3(wx + 0.20, 0.025 + wh, wz - 0.15), 0.18, 0.003, 0.14,
                         RAYLIBColor(70, 130, 210, 70))
            ok

            if t = T_FIRE
                fh = sin(animTime * 5.0 + wx * 3.0) * 0.08
                fh2 = sin(animTime * 7.0 + wz * 2.5) * 0.05
                // Scorched ground
                DrawCube(Vector3(wx, 0.0, wz), 0.96, 0.04, 0.96,
                         RAYLIBColor(45, 12, 5, 255))
                // Lava crack detail
                DrawCube(Vector3(wx - 0.12, 0.022, wz + 0.08), 0.30, 0.005, 0.04,
                         RAYLIBColor(200, 80, 10, 180))
                DrawCube(Vector3(wx + 0.10, 0.022, wz - 0.15), 0.04, 0.005, 0.25,
                         RAYLIBColor(220, 90, 15, 160))
                // Core flame (red-orange)
                DrawCube(Vector3(wx, 0.15 + fh, wz), 0.55, 0.25, 0.55,
                         RAYLIBColor(255, 80, 15, 200))
                // Mid flame (orange-yellow)
                DrawCube(Vector3(wx + fh2, 0.30 + fh * 1.3, wz), 0.35, 0.20, 0.35,
                         RAYLIBColor(255, 180, 40, 170))
                // Tip flame (yellow-white)
                DrawCube(Vector3(wx - fh2 * 0.5, 0.42 + fh * 1.8, wz), 0.18, 0.14, 0.18,
                         RAYLIBColor(255, 240, 120, 120))
                // Spark
                DrawCube(Vector3(wx + fh2 * 2, 0.52 + fh * 2.2, wz + fh * 0.5),
                         0.06, 0.06, 0.06,
                         RAYLIBColor(255, 255, 200, 80))
                // Ground glow
                DrawCube(Vector3(wx, 0.03, wz), 0.80, 0.005, 0.80,
                         RAYLIBColor(255, 60, 10, 60))
            ok
        next
    next

// =============================================================
// 3D Drawing: Walls (enhanced with brick detail)
// =============================================================

func rover_drawWalls
    for r = 1 to GRID_H
        for c = 1 to GRID_W
            if tiles[r][c] = T_WALL
                wx = c * CELL_SZ
                wz = r * CELL_SZ

                // Main wall body
                DrawCube(Vector3(wx, 0.35, wz), 0.98, 0.70, 0.98,
                         RAYLIBColor(125, 62, 145, 255))
                // Top cap (lighter)
                DrawCube(Vector3(wx, 0.70, wz), 0.96, 0.02, 0.96,
                         RAYLIBColor(165, 105, 185, 255))
                // Top edge highlight
                DrawCube(Vector3(wx, 0.715, wz), 0.94, 0.005, 0.94,
                         RAYLIBColor(185, 125, 205, 180))

                // Brick mortar lines (front face z+)
                DrawCube(Vector3(wx, 0.20, wz + 0.495), 0.96, 0.01, 0.005,
                         RAYLIBColor(85, 38, 100, 255))
                DrawCube(Vector3(wx, 0.38, wz + 0.495), 0.96, 0.01, 0.005,
                         RAYLIBColor(85, 38, 100, 255))
                DrawCube(Vector3(wx, 0.56, wz + 0.495), 0.96, 0.01, 0.005,
                         RAYLIBColor(85, 38, 100, 255))
                // Vertical mortar
                DrawCube(Vector3(wx, 0.29, wz + 0.495), 0.01, 0.16, 0.005,
                         RAYLIBColor(85, 38, 100, 255))
                DrawCube(Vector3(wx - 0.24, 0.47, wz + 0.495), 0.01, 0.16, 0.005,
                         RAYLIBColor(85, 38, 100, 255))
                DrawCube(Vector3(wx + 0.24, 0.47, wz + 0.495), 0.01, 0.16, 0.005,
                         RAYLIBColor(85, 38, 100, 255))
                // Front face highlight (right side of bricks)
                DrawCube(Vector3(wx, 0.21, wz + 0.496), 0.96, 0.008, 0.002,
                         RAYLIBColor(150, 85, 170, 140))
                DrawCube(Vector3(wx, 0.39, wz + 0.496), 0.96, 0.008, 0.002,
                         RAYLIBColor(150, 85, 170, 140))

                // Side face (x+) mortar
                DrawCube(Vector3(wx + 0.495, 0.20, wz), 0.005, 0.01, 0.96,
                         RAYLIBColor(85, 38, 100, 255))
                DrawCube(Vector3(wx + 0.495, 0.38, wz), 0.005, 0.01, 0.96,
                         RAYLIBColor(85, 38, 100, 255))
                DrawCube(Vector3(wx + 0.495, 0.56, wz), 0.005, 0.01, 0.96,
                         RAYLIBColor(85, 38, 100, 255))
                DrawCube(Vector3(wx + 0.495, 0.29, wz), 0.005, 0.16, 0.01,
                         RAYLIBColor(85, 38, 100, 255))

                // Ambient occlusion at base
                DrawCube(Vector3(wx, 0.01, wz + 0.495), 0.98, 0.01, 0.005,
                         RAYLIBColor(50, 22, 60, 120))
                DrawCube(Vector3(wx + 0.495, 0.01, wz), 0.005, 0.01, 0.98,
                         RAYLIBColor(50, 22, 60, 120))
            ok
        next
    next

// =============================================================
// 3D Drawing: Objects (enhanced with rich detail)
// =============================================================

func rover_drawObjects
    for r = 1 to GRID_H
        for c = 1 to GRID_W
            t = tiles[r][c]
            wx = c * CELL_SZ
            wz = r * CELL_SZ

            // ========== BOX (wooden crate) ==========
            if t = T_BOX
                // Main body
                DrawCube(Vector3(wx, 0.28, wz), 0.80, 0.54, 0.80,
                         RAYLIBColor(158, 108, 38, 255))
                // Front face panel
                DrawCube(Vector3(wx, 0.28, wz + 0.405), 0.74, 0.48, 0.01,
                         RAYLIBColor(172, 122, 48, 255))
                // Cross braces (front)
                DrawCube(Vector3(wx, 0.28, wz + 0.41), 0.60, 0.04, 0.005,
                         RAYLIBColor(118, 78, 24, 255))
                DrawCube(Vector3(wx, 0.28, wz + 0.41), 0.04, 0.40, 0.005,
                         RAYLIBColor(118, 78, 24, 255))
                // Side face panel
                DrawCube(Vector3(wx + 0.405, 0.28, wz), 0.01, 0.48, 0.74,
                         RAYLIBColor(148, 102, 35, 255))
                // Cross braces (side)
                DrawCube(Vector3(wx + 0.41, 0.28, wz), 0.005, 0.04, 0.60,
                         RAYLIBColor(118, 78, 24, 255))
                DrawCube(Vector3(wx + 0.41, 0.28, wz), 0.005, 0.40, 0.04,
                         RAYLIBColor(118, 78, 24, 255))
                // Frame edges
                DrawCube(Vector3(wx, 0.01, wz), 0.82, 0.02, 0.82,
                         RAYLIBColor(100, 65, 18, 255))
                DrawCube(Vector3(wx, 0.55, wz), 0.82, 0.02, 0.82,
                         RAYLIBColor(100, 65, 18, 255))
                // Top surface (lighter wood)
                DrawCube(Vector3(wx, 0.56, wz), 0.78, 0.005, 0.78,
                         RAYLIBColor(185, 135, 58, 220))
                // Top plank lines
                DrawCube(Vector3(wx - 0.20, 0.565, wz), 0.02, 0.003, 0.76,
                         RAYLIBColor(140, 98, 32, 120))
                DrawCube(Vector3(wx + 0.20, 0.565, wz), 0.02, 0.003, 0.76,
                         RAYLIBColor(140, 98, 32, 120))
                // Center metal plate (front)
                DrawCube(Vector3(wx, 0.28, wz + 0.415), 0.14, 0.14, 0.005,
                         RAYLIBColor(145, 135, 105, 255))
                DrawCube(Vector3(wx, 0.28, wz + 0.42), 0.10, 0.10, 0.003,
                         RAYLIBColor(115, 105, 80, 255))
                // Corner nails (front)
                DrawSphere(Vector3(wx - 0.32, 0.48, wz + 0.42), 0.025,
                           RAYLIBColor(90, 75, 50, 255))
                DrawSphere(Vector3(wx + 0.32, 0.48, wz + 0.42), 0.025,
                           RAYLIBColor(90, 75, 50, 255))
                DrawSphere(Vector3(wx - 0.32, 0.08, wz + 0.42), 0.025,
                           RAYLIBColor(90, 75, 50, 255))
                DrawSphere(Vector3(wx + 0.32, 0.08, wz + 0.42), 0.025,
                           RAYLIBColor(90, 75, 50, 255))
                // Shadow beneath
                DrawCube(Vector3(wx, 0.005, wz), 0.85, 0.003, 0.85,
                         RAYLIBColor(0, 0, 0, 35))
            ok

            // ========== ICE BLOCK ==========
            if t = T_ICE
                // Outer shell (translucent)
                DrawCube(Vector3(wx, 0.28, wz), 0.78, 0.54, 0.78,
                         RAYLIBColor(130, 195, 235, 180))
                // Inner core (brighter)
                DrawCube(Vector3(wx, 0.28, wz), 0.68, 0.46, 0.68,
                         RAYLIBColor(170, 215, 248, 120))
                // Crystal facets (front)
                DrawCube(Vector3(wx - 0.10, 0.35, wz + 0.395), 0.18, 0.14, 0.005,
                         RAYLIBColor(200, 230, 255, 80))
                DrawCube(Vector3(wx + 0.12, 0.22, wz + 0.395), 0.14, 0.18, 0.005,
                         RAYLIBColor(195, 225, 250, 70))
                // Crystal facets (side)
                DrawCube(Vector3(wx + 0.395, 0.32, wz - 0.08), 0.005, 0.16, 0.20,
                         RAYLIBColor(200, 230, 255, 70))
                // Shine highlight (top-front corner)
                DrawCube(Vector3(wx - 0.22, 0.48, wz + 0.395), 0.20, 0.08, 0.005,
                         RAYLIBColor(255, 255, 255, 60))
                // Top surface
                DrawCube(Vector3(wx, 0.555, wz), 0.76, 0.005, 0.76,
                         RAYLIBColor(195, 228, 252, 150))
                // Top highlight
                DrawCube(Vector3(wx - 0.15, 0.558, wz - 0.15), 0.25, 0.003, 0.25,
                         RAYLIBColor(255, 255, 255, 50))
                // Edge outlines
                DrawCubeWires(Vector3(wx, 0.28, wz), 0.79, 0.55, 0.79,
                              RAYLIBColor(100, 170, 210, 100))
            ok

            // ========== KEY ==========
            if t = T_KEY
                bob = sin(animTime * 3.5) * 0.08
                // Ring (torus approximated with cylinders)
                DrawCylinder(Vector3(wx, 0.28 + bob, wz), 0.14, 0.14, 0.04, 12,
                             RAYLIBColor(255, 215, 55, 255))
                DrawCylinder(Vector3(wx, 0.285 + bob, wz), 0.08, 0.08, 0.05, 12,
                             RAYLIBColor(90, 85, 95, 255))
                // Shaft
                DrawCube(Vector3(wx, 0.16 + bob, wz + 0.05), 0.05, 0.20, 0.05,
                         RAYLIBColor(245, 205, 45, 255))
                // Teeth
                DrawCube(Vector3(wx + 0.06, 0.09 + bob, wz + 0.05), 0.08, 0.04, 0.05,
                         RAYLIBColor(225, 185, 35, 255))
                DrawCube(Vector3(wx + 0.04, 0.14 + bob, wz + 0.05), 0.06, 0.03, 0.05,
                         RAYLIBColor(225, 185, 35, 255))
                // Shine highlight on ring
                DrawCylinder(Vector3(wx - 0.04, 0.30 + bob, wz - 0.04), 0.03, 0.02, 0.02, 6,
                             RAYLIBColor(255, 255, 200, 150))
                // Glow pulse
                glA = floor((sin(animTime * 4.0) * 0.3 + 0.5) * 80)
                DrawSphere(Vector3(wx, 0.22 + bob, wz), 0.24,
                           RAYLIBColor(255, 230, 50, glA))
            ok

            // ========== LOCKED DOOR ==========
            if t = T_DOOR
                // Door body
                DrawCube(Vector3(wx, 0.35, wz), 0.88, 0.68, 0.14,
                         RAYLIBColor(118, 68, 28, 255))
                // Frame
                DrawCube(Vector3(wx - 0.44, 0.35, wz), 0.08, 0.72, 0.20,
                         RAYLIBColor(82, 48, 18, 255))
                DrawCube(Vector3(wx + 0.44, 0.35, wz), 0.08, 0.72, 0.20,
                         RAYLIBColor(82, 48, 18, 255))
                DrawCube(Vector3(wx, 0.71, wz), 0.96, 0.06, 0.20,
                         RAYLIBColor(82, 48, 18, 255))
                // Panels (recessed)
                DrawCube(Vector3(wx - 0.15, 0.50, wz + 0.075), 0.28, 0.28, 0.005,
                         RAYLIBColor(105, 60, 22, 255))
                DrawCube(Vector3(wx + 0.15, 0.50, wz + 0.075), 0.28, 0.28, 0.005,
                         RAYLIBColor(105, 60, 22, 255))
                DrawCube(Vector3(wx - 0.15, 0.20, wz + 0.075), 0.28, 0.28, 0.005,
                         RAYLIBColor(105, 60, 22, 255))
                DrawCube(Vector3(wx + 0.15, 0.20, wz + 0.075), 0.28, 0.28, 0.005,
                         RAYLIBColor(105, 60, 22, 255))
                // Lock plate
                DrawSphere(Vector3(wx + 0.22, 0.32, wz + 0.08), 0.06,
                           RAYLIBColor(200, 180, 50, 255))
                DrawSphere(Vector3(wx + 0.22, 0.32, wz + 0.09), 0.04,
                           RAYLIBColor(170, 150, 35, 255))
                // Keyhole
                DrawCube(Vector3(wx + 0.22, 0.28, wz + 0.09), 0.015, 0.05, 0.01,
                         RAYLIBColor(25, 15, 8, 255))
                DrawSphere(Vector3(wx + 0.22, 0.32, wz + 0.095), 0.015,
                           RAYLIBColor(25, 15, 8, 255))
                // Glow when key held
                if hasKey
                    glA2 = floor((sin(animTime * 5.0) * 0.3 + 0.6) * 100)
                    DrawSphere(Vector3(wx, 0.35, wz), 0.55,
                               RAYLIBColor(255, 220, 50, glA2))
                ok
            ok

            // ========== EXIT DOOR ==========
            if t = T_EXIT
                // Green door body
                DrawCube(Vector3(wx, 0.35, wz), 0.88, 0.68, 0.14,
                         RAYLIBColor(28, 115, 48, 255))
                // Frame
                DrawCube(Vector3(wx - 0.44, 0.35, wz), 0.08, 0.72, 0.20,
                         RAYLIBColor(18, 72, 28, 255))
                DrawCube(Vector3(wx + 0.44, 0.35, wz), 0.08, 0.72, 0.20,
                         RAYLIBColor(18, 72, 28, 255))
                DrawCube(Vector3(wx, 0.71, wz), 0.96, 0.06, 0.20,
                         RAYLIBColor(18, 72, 28, 255))
                // EXIT sign (green bar on top)
                DrawCube(Vector3(wx, 0.58, wz + 0.075), 0.42, 0.10, 0.005,
                         RAYLIBColor(50, 200, 80, 255))
                DrawCube(Vector3(wx, 0.58, wz + 0.08), 0.38, 0.08, 0.005,
                         RAYLIBColor(35, 160, 60, 255))
                // Arrow on sign
                DrawCube(Vector3(wx + 0.08, 0.58, wz + 0.082), 0.10, 0.03, 0.003,
                         RAYLIBColor(200, 255, 200, 255))
                // Door panels
                DrawCube(Vector3(wx - 0.15, 0.30, wz + 0.075), 0.28, 0.38, 0.005,
                         RAYLIBColor(22, 95, 38, 255))
                DrawCube(Vector3(wx + 0.15, 0.30, wz + 0.075), 0.28, 0.38, 0.005,
                         RAYLIBColor(22, 95, 38, 255))
                // Handle
                DrawSphere(Vector3(wx + 0.22, 0.35, wz + 0.085), 0.04,
                           RAYLIBColor(150, 200, 155, 255))
                // Glow when dog rescued
                if hasDog
                    glA3 = floor((sin(animTime * 4.0) * 0.3 + 0.6) * 80)
                    DrawSphere(Vector3(wx, 0.35, wz), 0.55,
                               RAYLIBColor(50, 255, 80, glA3))
                ok
            ok

            // ========== LASER SOURCES ==========
            if t >= T_LASER_U and t <= T_LASER_R
                // Metal housing
                DrawCube(Vector3(wx, 0.25, wz), 0.82, 0.48, 0.82,
                         RAYLIBColor(75, 75, 85, 255))
                // Top plate
                DrawCube(Vector3(wx, 0.49, wz), 0.80, 0.01, 0.80,
                         RAYLIBColor(95, 95, 108, 255))
                // Corner rivets
                DrawSphere(Vector3(wx - 0.32, 0.42, wz + 0.32), 0.03,
                           RAYLIBColor(105, 105, 115, 255))
                DrawSphere(Vector3(wx + 0.32, 0.42, wz + 0.32), 0.03,
                           RAYLIBColor(105, 105, 115, 255))
                DrawSphere(Vector3(wx - 0.32, 0.42, wz - 0.32), 0.03,
                           RAYLIBColor(105, 105, 115, 255))
                DrawSphere(Vector3(wx + 0.32, 0.42, wz - 0.32), 0.03,
                           RAYLIBColor(105, 105, 115, 255))
                // Emitter glow (pulsing red)
                pulse = sin(animTime * 6.0) * 0.2 + 0.8
                DrawSphere(Vector3(wx, 0.35, wz), 0.20,
                           RAYLIBColor(255, 40, 40, floor(pulse * 200)))
                DrawSphere(Vector3(wx, 0.35, wz), 0.12,
                           RAYLIBColor(255, 120, 100, floor(pulse * 150)))
                // Direction emitter nozzle
                ldx = 0.0 ldz = 0.0
                if t = T_LASER_U ldz = -0.35 ok
                if t = T_LASER_D ldz = 0.35 ok
                if t = T_LASER_L ldx = -0.35 ok
                if t = T_LASER_R ldx = 0.35 ok
                DrawCube(Vector3(wx + ldx, 0.35, wz + ldz), 0.14, 0.12, 0.14,
                         RAYLIBColor(255, 80, 40, floor(pulse * 255)))
                DrawCube(Vector3(wx + ldx * 0.8, 0.35, wz + ldz * 0.8), 0.18, 0.08, 0.18,
                         RAYLIBColor(60, 58, 68, 255))
            ok
        next
    next

// =============================================================
// 3D Drawing: Lasers (enhanced glow)
// =============================================================

func rover_drawLasers
    for i = 1 to len(laserBeams)
        lx = laserBeams[i][1] * CELL_SZ
        lz = laserBeams[i][2] * CELL_SZ
        ldr = laserBeams[i][3]
        ldc = laserBeams[i][4]

        pulse = sin(animTime * 8.0 + i * 0.5) * 0.3 + 0.7
        alpha = floor(pulse * 200)

        if ldc != 0
            // Horizontal beam - core + glow layers
            DrawCube(Vector3(lx, 0.35, lz), 1.02, 0.03, 0.03,
                     RAYLIBColor(255, 220, 200, alpha))
            DrawCube(Vector3(lx, 0.35, lz), 1.01, 0.06, 0.06,
                     RAYLIBColor(255, 50, 30, floor(alpha * 0.7)))
            DrawCube(Vector3(lx, 0.35, lz), 1.0, 0.12, 0.12,
                     RAYLIBColor(255, 30, 15, floor(alpha * 0.25)))
            DrawCube(Vector3(lx, 0.35, lz), 0.98, 0.20, 0.20,
                     RAYLIBColor(255, 20, 10, floor(alpha * 0.08)))
        else
            // Vertical beam
            DrawCube(Vector3(lx, 0.35, lz), 0.03, 0.03, 1.02,
                     RAYLIBColor(255, 220, 200, alpha))
            DrawCube(Vector3(lx, 0.35, lz), 0.06, 0.06, 1.01,
                     RAYLIBColor(255, 50, 30, floor(alpha * 0.7)))
            DrawCube(Vector3(lx, 0.35, lz), 0.12, 0.12, 1.0,
                     RAYLIBColor(255, 30, 15, floor(alpha * 0.25)))
            DrawCube(Vector3(lx, 0.35, lz), 0.20, 0.20, 0.98,
                     RAYLIBColor(255, 20, 10, floor(alpha * 0.08)))
        ok
    next

// =============================================================
// 3D Drawing: Dog (enhanced model)
// =============================================================

func rover_drawDog
    if !dogFollowing
        for r = 1 to GRID_H
            for c = 1 to GRID_W
                if tiles[r][c] = T_DOG
                    rover_drawDogModel(c * 1.0, r * 1.0, DIR_DOWN)
                ok
            next
        next
    else
        rover_drawDogModel(dogX * 1.0, dogY * 1.0, pdir)
    ok

func rover_drawDogModel dx, dz, dir
    bob = sin(animTime * 4.0) * 0.02
    hy = 0.01

    // Shadow
    DrawCylinder(Vector3(dx, 0.005, dz), 0.22, 0.25, 0.003, 10,
                 RAYLIBColor(0, 0, 0, 35))

    // Body
    DrawCube(Vector3(dx, hy + 0.18 + bob, dz), 0.34, 0.20, 0.48,
             RAYLIBColor(162, 118, 58, 255))
    // Belly (lighter)
    DrawCube(Vector3(dx, hy + 0.12 + bob, dz), 0.28, 0.06, 0.40,
             RAYLIBColor(185, 148, 85, 255))
    // Head
    fdx = 0.0 fdz = 0.0
    if dir = DIR_UP fdz = -0.22 ok
    if dir = DIR_DOWN fdz = 0.22 ok
    if dir = DIR_LEFT fdx = -0.22 ok
    if dir = DIR_RIGHT fdx = 0.22 ok
    DrawCube(Vector3(dx + fdx, hy + 0.26 + bob, dz + fdz), 0.22, 0.20, 0.22,
             RAYLIBColor(155, 112, 55, 255))
    // Snout
    DrawCube(Vector3(dx + fdx * 1.3, hy + 0.22 + bob, dz + fdz * 1.3), 0.12, 0.10, 0.12,
             RAYLIBColor(165, 122, 62, 255))
    // Ears
    DrawCube(Vector3(dx + fdx - 0.12, hy + 0.34 + bob, dz + fdz), 0.06, 0.12, 0.05,
             RAYLIBColor(132, 88, 38, 255))
    DrawCube(Vector3(dx + fdx + 0.12, hy + 0.34 + bob, dz + fdz), 0.06, 0.12, 0.05,
             RAYLIBColor(132, 88, 38, 255))
    // Eyes
    DrawSphere(Vector3(dx + fdx - 0.06, hy + 0.28 + bob, dz + fdz + 0.08), 0.035,
               RAYLIBColor(25, 20, 15, 255))
    DrawSphere(Vector3(dx + fdx + 0.06, hy + 0.28 + bob, dz + fdz + 0.08), 0.035,
               RAYLIBColor(25, 20, 15, 255))
    // Eye shine
    DrawSphere(Vector3(dx + fdx - 0.05, hy + 0.29 + bob, dz + fdz + 0.10), 0.012,
               RAYLIBColor(255, 255, 255, 200))
    DrawSphere(Vector3(dx + fdx + 0.07, hy + 0.29 + bob, dz + fdz + 0.10), 0.012,
               RAYLIBColor(255, 255, 255, 200))
    // Nose
    DrawSphere(Vector3(dx + fdx * 1.5, hy + 0.24 + bob, dz + fdz * 1.5), 0.035,
               RAYLIBColor(32, 22, 15, 255))
    // Tongue
    DrawCube(Vector3(dx + fdx * 1.4, hy + 0.18 + bob, dz + fdz * 1.4), 0.06, 0.02, 0.04,
             RAYLIBColor(225, 100, 100, 220))
    // Legs
    legAnim = sin(animTime * 6.0) * 0.02
    for lx = -1 to 1 step 2
        for lz = -1 to 1 step 2
            la = legAnim * lx * lz
            DrawCylinder(Vector3(dx + lx * 0.12, hy, dz + lz * 0.18 + la),
                         0.04, 0.04, 0.10, 6,
                         RAYLIBColor(142, 100, 48, 255))
            // Paws
            DrawCylinder(Vector3(dx + lx * 0.12, hy, dz + lz * 0.18 + la),
                         0.05, 0.04, 0.02, 6,
                         RAYLIBColor(132, 92, 42, 255))
        next
    next
    // Tail (wagging)
    tailWag = sin(animTime * 8.0) * 0.14
    DrawCube(Vector3(dx - fdx * 0.8 + tailWag, hy + 0.30 + bob, dz - fdz * 0.8),
             0.04, 0.06, 0.14,
             RAYLIBColor(152, 112, 55, 255))

    // Heart when following
    if dogFollowing
        hartBob = sin(animTime * 3.0) * 0.05
        hA = floor(sin(animTime * 2.0) * 60 + 195)
        DrawSphere(Vector3(dx - 0.04, hy + 0.52 + hartBob, dz), 0.05,
                   RAYLIBColor(255, 50, 70, hA))
        DrawSphere(Vector3(dx + 0.04, hy + 0.52 + hartBob, dz), 0.05,
                   RAYLIBColor(255, 50, 70, hA))
        DrawCube(Vector3(dx, hy + 0.48 + hartBob, dz), 0.10, 0.06, 0.05,
                 RAYLIBColor(255, 50, 70, hA))
    ok

// =============================================================
// 3D Drawing: Player (enhanced character model)
// =============================================================

func rover_drawPlayer
    if !palive
        return
    ok
    wx = px * CELL_SZ
    wz = py * CELL_SZ
    bob = sin(animTime * 5.0) * 0.01
    hy = 0.01

    fdx = 0.0 fdz = 0.0
    if pdir = DIR_UP fdz = -1.0 ok
    if pdir = DIR_DOWN fdz = 1.0 ok
    if pdir = DIR_LEFT fdx = -1.0 ok
    if pdir = DIR_RIGHT fdx = 1.0 ok

    // Shadow
    DrawCylinder(Vector3(wx, 0.005, wz), 0.22, 0.26, 0.003, 12,
                 RAYLIBColor(0, 0, 0, 40))

    // Legs (walking animation)
    walkPhase = sin(pAnimTime * 10.0) * 0.06
    DrawCylinder(Vector3(wx - fdz * 0.08, hy, wz + fdx * 0.08 + walkPhase * 0.3),
                 0.05, 0.04, 0.22, 6,
                 RAYLIBColor(38, 38, 118, 255))
    DrawCylinder(Vector3(wx + fdz * 0.08, hy, wz - fdx * 0.08 - walkPhase * 0.3),
                 0.05, 0.04, 0.22, 6,
                 RAYLIBColor(38, 38, 118, 255))
    // Shoes
    DrawCube(Vector3(wx - fdz * 0.08, hy + 0.02, wz + fdx * 0.08),
             0.09, 0.04, 0.11, RAYLIBColor(82, 50, 18, 255))
    DrawCube(Vector3(wx + fdz * 0.08, hy + 0.02, wz - fdx * 0.08),
             0.09, 0.04, 0.11, RAYLIBColor(82, 50, 18, 255))

    // Belt
    DrawCube(Vector3(wx, hy + 0.23 + bob, wz), 0.26, 0.03, 0.20,
             RAYLIBColor(75, 50, 18, 255))
    // Belt buckle
    DrawCube(Vector3(wx + fdx * 0.10, hy + 0.23 + bob, wz + fdz * 0.10),
             0.04, 0.03, 0.04, RAYLIBColor(200, 180, 50, 255))

    // Body (torso)
    DrawCube(Vector3(wx, hy + 0.33 + bob, wz), 0.25, 0.22, 0.18,
             RAYLIBColor(55, 55, 175, 255))
    // Shirt collar
    DrawCube(Vector3(wx, hy + 0.44 + bob, wz), 0.18, 0.02, 0.14,
             RAYLIBColor(72, 72, 195, 255))

    // Arms (walking animation)
    armSwing = sin(pAnimTime * 10.0) * 0.05
    DrawCylinder(Vector3(wx - fdz * 0.16 - 0.01, hy + 0.28 + bob,
                         wz + fdx * 0.16 + armSwing),
                 0.04, 0.03, 0.18, 6,
                 RAYLIBColor(222, 178, 132, 255))
    DrawCylinder(Vector3(wx + fdz * 0.16 + 0.01, hy + 0.28 + bob,
                         wz - fdx * 0.16 - armSwing),
                 0.04, 0.03, 0.18, 6,
                 RAYLIBColor(222, 178, 132, 255))
    // Hands
    DrawSphere(Vector3(wx - fdz * 0.16, hy + 0.26 + bob,
                       wz + fdx * 0.16 + armSwing), 0.035,
               RAYLIBColor(228, 185, 138, 255))
    DrawSphere(Vector3(wx + fdz * 0.16, hy + 0.26 + bob,
                       wz - fdx * 0.16 - armSwing), 0.035,
               RAYLIBColor(228, 185, 138, 255))

    // Head
    DrawSphere(Vector3(wx, hy + 0.52 + bob, wz), 0.12,
               RAYLIBColor(232, 188, 142, 255))
    // Cap
    DrawCube(Vector3(wx, hy + 0.58 + bob, wz), 0.23, 0.08, 0.23,
             RAYLIBColor(215, 215, 215, 255))
    // Cap brim
    DrawCube(Vector3(wx + fdx * 0.09, hy + 0.55 + bob, wz + fdz * 0.09),
             0.26, 0.025, 0.26,
             RAYLIBColor(205, 205, 205, 255))
    // Cap band
    DrawCube(Vector3(wx, hy + 0.555 + bob, wz), 0.235, 0.015, 0.235,
             RAYLIBColor(55, 55, 175, 255))

    // Eyes
    DrawSphere(Vector3(wx + fdx * 0.10 - fdz * 0.045, hy + 0.52 + bob,
                       wz + fdz * 0.10 + fdx * 0.045), 0.022,
               RAYLIBColor(20, 20, 20, 255))
    DrawSphere(Vector3(wx + fdx * 0.10 + fdz * 0.045, hy + 0.52 + bob,
                       wz + fdz * 0.10 - fdx * 0.045), 0.022,
               RAYLIBColor(20, 20, 20, 255))
    // Eye shine
    DrawSphere(Vector3(wx + fdx * 0.10 - fdz * 0.04, hy + 0.525 + bob,
                       wz + fdz * 0.10 + fdx * 0.04 + 0.01), 0.008,
               RAYLIBColor(255, 255, 255, 200))
    DrawSphere(Vector3(wx + fdx * 0.10 + fdz * 0.04, hy + 0.525 + bob,
                       wz + fdz * 0.10 - fdx * 0.04 + 0.01), 0.008,
               RAYLIBColor(255, 255, 255, 200))

    // Key on belt
    if hasKey
        keyBob = sin(animTime * 4.0) * 0.02
        DrawCylinder(Vector3(wx + 0.16, hy + 0.25 + bob + keyBob, wz),
                     0.04, 0.04, 0.02, 6,
                     RAYLIBColor(255, 210, 50, 255))
        DrawCube(Vector3(wx + 0.16, hy + 0.20 + bob + keyBob, wz),
                 0.02, 0.08, 0.02,
                 RAYLIBColor(220, 180, 30, 255))
    ok

    // Dog following heart above head
    if hasDog
        hBob = sin(animTime * 3.0) * 0.04
        hA = floor(sin(animTime * 2.0) * 60 + 180)
        DrawSphere(Vector3(wx - 0.03, hy + 0.72 + bob + hBob, wz), 0.03,
                   RAYLIBColor(255, 50, 75, hA))
        DrawSphere(Vector3(wx + 0.03, hy + 0.72 + bob + hBob, wz), 0.03,
                   RAYLIBColor(255, 50, 75, hA))
    ok

// =============================================================
// 3D Drawing: Particles
// =============================================================

func rover_drawParticles
    for i = 1 to len(particles)
        life = particles[i][7] / particles[i][8]
        if life < 0 life = 0 ok
        alpha = floor(life * 255)
        if alpha > 255 alpha = 255 ok
        if alpha < 0 alpha = 0 ok
        sz = particles[i][12] * life
        if sz < 0.005 sz = 0.005 ok
        DrawSphere(Vector3(particles[i][1], particles[i][2], particles[i][3]),
                   sz, RAYLIBColor(particles[i][9], particles[i][10],
                                   particles[i][11], alpha))
    next

// =============================================================
// HUD
// =============================================================

func rover_drawHUD
    // Top bar
    DrawRectangle(0, 0, SCREEN_W, 50, RAYLIBColor(0, 0, 0, 200))
    DrawRectangle(0, 50, SCREEN_W, 2, RAYLIBColor(130, 70, 160, 255))

    // Level
    lvlTxt = "LEVEL " + string(level)
    DrawText(lvlTxt, 15, 6, 14, RAYLIBColor(160, 160, 160, 200))

    // Level name
    lname = rover_levelName(level)
    DrawText(lname, 15, 22, 20, RAYLIBColor(220, 180, 255, 255))

    // Moves counter (center)
    mvTxt = "MOVES: " + string(moves)
    mvW = MeasureText(mvTxt, 22)
    DrawText(mvTxt, floor(SCREEN_W/2 - mvW/2), 14, 22,
             RAYLIBColor(255, 255, 255, 255))

    // Status icons (right)
    statusX = SCREEN_W - 200
    if hasKey
        DrawText("KEY", statusX, 6, 14, RAYLIBColor(160, 160, 160, 200))
        DrawRectangle(statusX, 22, 20, 14, RAYLIBColor(255, 210, 50, 255))
        DrawRectangle(statusX + 6, 18, 8, 6, RAYLIBColor(220, 180, 30, 255))
    else
        DrawText("KEY", statusX, 6, 14, RAYLIBColor(80, 80, 80, 150))
        DrawText("--", statusX + 4, 24, 14, RAYLIBColor(80, 80, 80, 150))
    ok

    if hasDog
        DrawText("DOG", statusX + 60, 6, 14, RAYLIBColor(160, 160, 160, 200))
        DrawRectangle(statusX + 60, 24, 16, 10, RAYLIBColor(160, 120, 60, 255))
        DrawRectangle(statusX + 66, 20, 8, 8, RAYLIBColor(150, 110, 55, 255))
    else
        DrawText("DOG", statusX + 60, 6, 14, RAYLIBColor(80, 80, 80, 150))
        DrawText("--", statusX + 64, 24, 14, RAYLIBColor(80, 80, 80, 150))
    ok

    // Camera indicator
    camNames = ["Top", "Angle", "Close"]
    DrawText("Cam: " + camNames[camMode + 1] + " [C]",
             SCREEN_W - 140, SCREEN_H - 25, 14,
             RAYLIBColor(140, 140, 140, 150))

    // Controls
    DrawText("Arrows: Move | Z: Undo | R: Restart | C: Camera",
             floor(SCREEN_W/2 - 200), SCREEN_H - 25, 13,
             RAYLIBColor(120, 120, 120, 130))

    // Message popup
    if msgTimer > 0
        msgA = 255
        if msgTimer < 0.5 msgA = floor(msgTimer * 510) ok
        mW = MeasureText(msgText, 24)
        DrawRectangle(floor(SCREEN_W/2 - mW/2 - 15), floor(SCREEN_H/2 + 80),
                      mW + 30, 36, RAYLIBColor(0, 0, 0, floor(msgA * 0.7)))
        DrawText(msgText, floor(SCREEN_W/2 - mW/2), floor(SCREEN_H/2 + 86), 24,
                 RAYLIBColor(255, 255, 200, msgA))
    ok

    // State overlays
    if gameState = ST_TITLE
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 220))
        title = "3D RESCUE ROVER"
        tW = MeasureText(title, 48)
        DrawText(title, floor(SCREEN_W/2 - tW/2), floor(SCREEN_H/2 - 100), 48,
                 RAYLIBColor(130, 80, 180, 255))
        sub = "Rescue your dog from the puzzle maze!"
        sW = MeasureText(sub, 20)
        DrawText(sub, floor(SCREEN_W/2 - sW/2), floor(SCREEN_H/2 - 40), 20,
                 RAYLIBColor(200, 200, 200, 255))

        info1 = "Push boxes into water to make bridges"
        info2 = "Collect keys to open locked doors"
        info3 = "Avoid lasers - redirect them with ice blocks"
        info4 = "Rescue your dog then reach the exit!"
        DrawText(info1, floor(SCREEN_W/2 - MeasureText(info1, 16)/2),
                 floor(SCREEN_H/2 + 10), 16, RAYLIBColor(160, 160, 160, 200))
        DrawText(info2, floor(SCREEN_W/2 - MeasureText(info2, 16)/2),
                 floor(SCREEN_H/2 + 32), 16, RAYLIBColor(160, 160, 160, 200))
        DrawText(info3, floor(SCREEN_W/2 - MeasureText(info3, 16)/2),
                 floor(SCREEN_H/2 + 54), 16, RAYLIBColor(160, 160, 160, 200))
        DrawText(info4, floor(SCREEN_W/2 - MeasureText(info4, 16)/2),
                 floor(SCREEN_H/2 + 76), 16, RAYLIBColor(160, 160, 160, 200))

        pulse = floor(sin(animTime * 3.0) * 60 + 195)
        start = "Press ENTER or SPACE to Start"
        DrawText(start, floor(SCREEN_W/2 - MeasureText(start, 22)/2),
                 floor(SCREEN_H/2 + 120), 22, RAYLIBColor(255, 255, 255, pulse))
    ok

    if gameState = ST_DEAD
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(100, 0, 0, 150))
        dTxt = "YOU DIED!"
        dW = MeasureText(dTxt, 48)
        DrawText(dTxt, floor(SCREEN_W/2 - dW/2), floor(SCREEN_H/2 - 40), 48,
                 RAYLIBColor(255, 60, 40, 255))
        rTxt = "Press R or ENTER to Retry"
        rW = MeasureText(rTxt, 20)
        DrawText(rTxt, floor(SCREEN_W/2 - rW/2), floor(SCREEN_H/2 + 20), 20,
                 RAYLIBColor(200, 200, 200, 220))
    ok

    if gameState = ST_WON
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 50, 0, 150))
        wTxt = "LEVEL COMPLETE!"
        wW = MeasureText(wTxt, 44)
        DrawText(wTxt, floor(SCREEN_W/2 - wW/2), floor(SCREEN_H/2 - 50), 44,
                 RAYLIBColor(50, 255, 80, 255))
        mTxt = "Moves: " + string(moves)
        mW2 = MeasureText(mTxt, 24)
        DrawText(mTxt, floor(SCREEN_W/2 - mW2/2), floor(SCREEN_H/2 + 5), 24,
                 RAYLIBColor(255, 255, 200, 255))
        if level < MAX_LEVELS
            nTxt = "Press N or ENTER for Next Level"
        else
            nTxt = "All Levels Complete! Press ENTER"
        ok
        nW = MeasureText(nTxt, 20)
        DrawText(nTxt, floor(SCREEN_W/2 - nW/2), floor(SCREEN_H/2 + 40), 20,
                 RAYLIBColor(200, 200, 200, 220))
    ok

    // FPS
    DrawFPS(SCREEN_W - 80, 56)

// =============================================================
// Level Names
// =============================================================

func rover_levelName lvl
    if lvl = 1 return "First Steps" ok
    if lvl = 2 return "Bridge Builder" ok
    if lvl = 3 return "Laser Dodge" ok
    if lvl = 4 return "Deep Water" ok
    if lvl = 5 return "Laser Maze" ok
    if lvl = 6 return "Fire and Ice" ok
    if lvl = 7 return "Redirect Chain" ok
    if lvl = 8 return "The Final Rescue" ok
    return "Unknown"

// =============================================================
// Helper
// =============================================================

func fabs n
    if n < 0 return -n ok
    return n
