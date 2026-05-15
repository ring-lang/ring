/*
**  THE SWORD GAME - Classic Platformer
**  ====================================
**  A 3D platformer with sword combat and dungeon traps
**  Written in Ring Language using RayLib
**
**  Controls:
**    Left/Right or A/D  -  Run left/right
**    Up or W             -  Jump / Climb up (when hanging)
**    Down or S            -  Crouch / Climb down / Careful step
**    Shift (hold)         -  Walk carefully (for edges)
**    Q                    -  Grab ledge / Climb up
**    Space                -  Draw/Sheathe sword
**    Left Click or F      -  Sword attack / Strike
**    E                    -  Interact (drink potion, pull lever)
**    R                    -  Restart level
**    ESC                  -  Exit
**
**  Gameplay:
**    - Navigate dungeon rooms
**    - Avoid spike traps and loose floors
**    - Fight guards with sword combat
**    - Drink potions to restore/boost health
**    - Reach the exit door to complete each level
**    - Timer counts down - escape the dungeon!
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W = 1024
SCREEN_H = 700

// Tile size in world units
TILE_W = 1.0
TILE_H = 1.0

// Tile types
T_EMPTY      = 0
T_FLOOR      = 1
T_WALL       = 2
T_PILLAR     = 3
T_SPIKES     = 4   // spike trap
T_LOOSE      = 5   // loose floor (falls when stepped on)
T_GATE       = 6   // gate (opens with lever)
T_LEVER      = 7   // floor with lever
T_EXIT_DOOR  = 8   // exit door
T_TORCH      = 9   // wall with torch
T_EDGE       = 10  // floor edge (can hang from)
T_POTION     = 11  // floor with potion
T_BRICKS     = 12  // decorative brick wall
T_CHOMPER    = 13  // chomper trap
T_PLATE      = 14  // pressure plate

// Player states
PS_IDLE       = 0
PS_RUN        = 1
PS_JUMP       = 2
PS_FALL       = 3
PS_HANG       = 4
PS_CLIMB      = 5
PS_CROUCH     = 6
PS_CAREFUL    = 7
PS_TURN       = 8
PS_SWORD_IDLE = 9
PS_SWORD_ATK  = 10
PS_SWORD_BLK  = 11
PS_HIT        = 12
PS_DYING      = 13
PS_DEAD       = 14

// Guard states
GS_IDLE       = 0
GS_ADVANCE    = 1
GS_ATTACK     = 2
GS_BLOCK      = 3
GS_HIT        = 4
GS_DYING      = 5
GS_DEAD       = 6

// Game states
GM_TITLE      = 0
GM_PLAYING    = 1
GM_DEAD       = 2
GM_WON        = 3
GM_COMPLETE   = 4

// =============================================================
// Level Data Structures
// =============================================================

// Room dimensions
ROOM_W = 10
ROOM_H = 4
MAX_ROOMS = 24   // max rooms in a level

// Level structure: rooms arranged in a grid
// Each level has rooms_cols x rooms_rows rooms
rooms = []          // 2D array of room data
roomsCols = 0
roomsRows = 0
currentRoom = 1     // current room index (1-based)

// Player
plX = 2.5           // position in world coords
plY = 2.0
plVX = 0.0          // velocity
plVY = 0.0
plDir = 1           // 1=right, -1=left
plState = PS_IDLE
plStateTimer = 0.0
plHealth = 3
plMaxHealth = 3
plSword = false     // sword drawn
plAlive = true
plOnGround = false
plHangTile = 0      // column hanging from
plHangRow = 0       // row hanging from
plAnimTime = 0.0
plRunFrame = 0.0

// Guards
guards = []         // [x, y, dir, health, maxHealth, state, stateTimer, attackCooldown, room, alertRange]

// Game
gameState = GM_TITLE
levelNum = 1
maxLevels = 3
gameTimer = 3600.0  // 60 minutes (classic!)
animTime = 0.0
deathTimer = 0.0
msgText = ""
msgTimer = 0.0

// Camera
camX = 0.0
camY = 0.0
camTargetX = 0.0
camTargetY = 0.0
cam = NULL

// Loose floors that are falling: [worldX, worldY, velY, timer]
fallingFloors = []

// Gates: [room, row, col, open, targetOpen, speed]
gates = []

// Spikes state: [room, row, col, extended, timer]
spikesState = []

// Chompers: [room, row, col, timer, closing]
chompers = []

// Potions: [room, row, col, type, collected]  type: 1=health, 2=maxHealth
potions = []

// =============================================================
// Main
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "The Sword Game - Ring + RayLib")
ToggleFullScreen()
SetTargetFPS(60)

cam = Camera3D(
    5.0, 3.0, 12.0,
    5.0, 2.0, 0.0,
    0, 1, 0,
    45,
    0
)

pop_loadLevel(1)

while !WindowShouldClose()
    dt = GetFrameTime()
    if dt > 0.05 dt = 0.05 ok

    animTime += dt

    switch gameState
    on GM_TITLE
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            gameState = GM_PLAYING
        ok
    on GM_PLAYING
        gameTimer -= dt
        pop_handleInput(dt)
        pop_updatePlayer(dt)
        pop_updateGuards(dt)
        pop_updateTraps(dt)
        pop_updateFallingFloors(dt)
        pop_updateCamera(dt)
        pop_checkDeath()
    on GM_DEAD
        deathTimer -= dt
        if deathTimer <= 0
            if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
                pop_loadLevel(levelNum)
                gameState = GM_PLAYING
            ok
        ok
    on GM_WON
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            if levelNum < maxLevels
                levelNum += 1
                pop_loadLevel(levelNum)
                gameState = GM_PLAYING
            else
                gameState = GM_COMPLETE
            ok
        ok
    on GM_COMPLETE
        if IsKeyPressed(KEY_ENTER)
            levelNum = 1
            gameTimer = 3600
            pop_loadLevel(1)
            gameState = GM_TITLE
        ok
    off

    if msgTimer > 0 msgTimer -= dt ok

    BeginDrawing()
        ClearBackground(RAYLIBColor(0, 0, 0, 255))

        if gameState = GM_PLAYING or gameState = GM_DEAD or gameState = GM_WON
            BeginMode3D(cam)
                pop_drawRoom()
                pop_drawPlayer()
                pop_drawGuards()
                pop_drawTraps()
                pop_drawFallingFloors()
            EndMode3D()
            pop_drawHUD()
        ok

        if gameState = GM_TITLE
            pop_drawTitle()
        ok
        if gameState = GM_DEAD
            pop_drawDeathOverlay()
        ok
        if gameState = GM_WON
            pop_drawWinOverlay()
        ok
        if gameState = GM_COMPLETE
            pop_drawCompleteScreen()
        ok

        if msgTimer > 0
            mA = 255
            if msgTimer < 0.5 mA = floor(msgTimer * 510) ok
            mW = MeasureText(msgText, 22)
            DrawText(msgText, floor(SCREEN_W/2 - mW/2), 80, 22,
                     RAYLIBColor(255, 255, 100, mA))
        ok

    EndDrawing()
end

CloseWindow()

// =============================================================
// Level Loading
// =============================================================

func pop_loadLevel num
    rooms = []
    guards = []
    fallingFloors = []
    gates = []
    spikesState = []
    chompers = []
    potions = []
    plHealth = 3
    plMaxHealth = 3
    plSword = false
    plAlive = true
    plState = PS_IDLE
    plVX = 0
    plVY = 0
    deathTimer = 0

    if num = 1 pop_level1() ok
    if num = 2 pop_level2() ok
    if num = 3 pop_level3() ok

    // Register special tiles
    for rm = 1 to len(rooms)
        for r = 1 to ROOM_H
            for c = 1 to ROOM_W
                t = rooms[rm][r][c]
                if t = T_SPIKES
                    add(spikesState, [rm, r, c, false, 1.0 + random(200)/100.0])
                ok
                if t = T_CHOMPER
                    add(chompers, [rm, r, c, 1.5 + random(150)/100.0, false])
                ok
                if t = T_POTION
                    add(potions, [rm, r, c, 1, false])
                ok
            next
        next
    next

// Create an empty room
func pop_makeRoom
    room = list(ROOM_H, ROOM_W)
    for r = 1 to ROOM_H
        for c = 1 to ROOM_W
            room[r][c] = T_EMPTY
        next
    next
    return room

// =============================================================
// Level 1 - The Dungeon
// =============================================================

func pop_level1
    roomsCols = 4
    roomsRows = 2

    // Create 8 rooms (4 cols x 2 rows)
    for i = 1 to 8
        add(rooms, pop_makeRoom())
    next

    // Room 1 (start) - top left
    r = rooms[1]
    for c = 1 to ROOM_W r[4][c] = T_FLOOR next    // floor at bottom
    r[3][1] = T_WALL  r[2][1] = T_WALL  r[1][1] = T_WALL   // left wall
    r[1][1] = T_TORCH
    r[4][8] = T_LOOSE  r[4][9] = T_LOOSE
    rooms[1] = r

    // Room 2 - top
    r = rooms[2]
    for c = 1 to ROOM_W r[4][c] = T_FLOOR next
    r[4][4] = T_SPIKES
    r[4][5] = T_SPIKES
    r[4][7] = T_POTION
    r[1][3] = T_TORCH
    rooms[2] = r

    // Room 3 - top
    r = rooms[3]
    for c = 1 to ROOM_W r[4][c] = T_FLOOR next
    for c = 4 to 6 r[4][c] = T_EMPTY next   // gap!
    r[2][2] = T_FLOOR  r[2][3] = T_FLOOR    // upper platform
    r[4][8] = T_CHOMPER
    r[1][9] = T_TORCH
    rooms[3] = r

    // Room 4 - top right
    r = rooms[4]
    for c = 1 to ROOM_W r[4][c] = T_FLOOR next
    r[4][3] = T_PLATE
    r[3][1] = T_WALL  r[2][1] = T_WALL
    r[1][6] = T_TORCH
    // Gate blocking path down
    r[4][9] = T_GATE
    rooms[4] = r
    add(gates, [4, 4, 9, false, false, 2.0])   // room4, row4, col9

    // Room 5 - bottom left
    r = rooms[5]
    for c = 1 to ROOM_W r[4][c] = T_FLOOR next
    r[3][1] = T_WALL  r[2][1] = T_WALL r[1][1] = T_WALL
    r[1][1] = T_BRICKS
    r[4][5] = T_LEVER
    r[4][3] = T_SPIKES
    rooms[5] = r

    // Room 6 - bottom
    r = rooms[6]
    for c = 1 to ROOM_W r[4][c] = T_FLOOR next
    r[4][6] = T_SPIKES
    r[4][7] = T_SPIKES
    r[2][8] = T_FLOOR r[2][9] = T_FLOOR r[2][10] = T_FLOOR
    r[1][2] = T_TORCH
    rooms[6] = r

    // Room 7 - bottom
    r = rooms[7]
    for c = 1 to ROOM_W r[4][c] = T_FLOOR next
    r[4][4] = T_CHOMPER
    r[4][7] = T_LOOSE r[4][8] = T_LOOSE
    rooms[7] = r

    // Room 8 - bottom right (exit)
    r = rooms[8]
    for c = 1 to ROOM_W r[4][c] = T_FLOOR next
    r[4][8] = T_EXIT_DOOR
    r[1][5] = T_TORCH
    r[3][10] = T_WALL  r[2][10] = T_WALL  r[1][10] = T_WALL
    rooms[8] = r

    // Player start: room 1, standing on floor
    currentRoom = 1
    plX = 2.5
    plY = 3.0
    plDir = 1

    // Guards
    pop_addGuard(2, 8.0, 3.0, -1, 3)   // guard in room 2
    pop_addGuard(6, 4.0, 3.0, 1, 3)    // guard in room 6
    pop_addGuard(7, 6.0, 3.0, -1, 4)   // guard in room 7

// =============================================================
// Level 2 - Deeper Dungeon
// =============================================================

func pop_level2
    roomsCols = 4
    roomsRows = 3

    for i = 1 to 12
        add(rooms, pop_makeRoom())
    next

    // Row 1 (top)
    // Room 1 - start
    r = rooms[1]
    for c = 1 to ROOM_W r[4][c] = T_FLOOR next
    r[3][1] = T_WALL r[2][1] = T_WALL r[1][1] = T_WALL
    r[1][1] = T_TORCH
    r[4][6] = T_POTION
    rooms[1] = r

    // Room 2
    r = rooms[2]
    for c = 1 to ROOM_W r[4][c] = T_FLOOR next
    r[4][3] = T_SPIKES r[4][4] = T_SPIKES
    r[4][7] = T_CHOMPER
    r[2][5] = T_FLOOR r[2][6] = T_FLOOR
    r[1][8] = T_TORCH
    rooms[2] = r

    // Room 3
    r = rooms[3]
    for c = 1 to ROOM_W r[4][c] = T_FLOOR next
    r[4][5] = T_LOOSE r[4][6] = T_LOOSE r[4][7] = T_LOOSE
    r[4][9] = T_PLATE
    r[1][2] = T_TORCH
    rooms[3] = r

    // Room 4
    r = rooms[4]
    for c = 1 to ROOM_W r[4][c] = T_FLOOR next
    r[4][2] = T_GATE
    r[3][10] = T_WALL r[2][10] = T_WALL r[1][10] = T_WALL
    rooms[4] = r
    add(gates, [4, 4, 2, false, false, 2.0])

    // Row 2 (middle)
    // Room 5
    r = rooms[5]
    for c = 1 to ROOM_W r[4][c] = T_FLOOR next
    r[3][1] = T_WALL r[2][1] = T_WALL
    r[4][4] = T_SPIKES r[4][5] = T_SPIKES r[4][6] = T_SPIKES
    r[1][7] = T_TORCH
    rooms[5] = r

    // Room 6
    r = rooms[6]
    for c = 1 to ROOM_W r[4][c] = T_FLOOR next
    r[4][3] = T_CHOMPER r[4][7] = T_CHOMPER
    r[4][5] = T_POTION
    rooms[6] = r

    // Room 7
    r = rooms[7]
    for c = 1 to ROOM_W r[4][c] = T_FLOOR next
    r[4][4] = T_LEVER
    for c = 6 to 8 r[4][c] = T_EMPTY next  // gap
    r[2][9] = T_FLOOR r[2][10] = T_FLOOR
    rooms[7] = r

    // Room 8
    r = rooms[8]
    for c = 1 to ROOM_W r[4][c] = T_FLOOR next
    r[4][6] = T_SPIKES
    r[3][10] = T_WALL r[2][10] = T_WALL r[1][10] = T_WALL
    r[1][3] = T_TORCH
    rooms[8] = r

    // Row 3 (bottom)
    // Room 9
    r = rooms[9]
    for c = 1 to ROOM_W r[4][c] = T_FLOOR next
    r[3][1] = T_WALL r[2][1] = T_WALL r[1][1] = T_WALL
    r[1][1] = T_BRICKS
    rooms[9] = r

    // Room 10
    r = rooms[10]
    for c = 1 to ROOM_W r[4][c] = T_FLOOR next
    r[4][4] = T_LOOSE r[4][5] = T_LOOSE
    r[4][8] = T_CHOMPER
    rooms[10] = r

    // Room 11
    r = rooms[11]
    for c = 1 to ROOM_W r[4][c] = T_FLOOR next
    r[4][3] = T_SPIKES r[4][4] = T_SPIKES
    r[2][7] = T_FLOOR r[2][8] = T_FLOOR
    r[4][9] = T_POTION
    r[1][6] = T_TORCH
    rooms[11] = r

    // Room 12 - exit
    r = rooms[12]
    for c = 1 to ROOM_W r[4][c] = T_FLOOR next
    r[4][8] = T_EXIT_DOOR
    r[3][10] = T_WALL r[2][10] = T_WALL r[1][10] = T_WALL
    r[1][2] = T_TORCH
    rooms[12] = r

    currentRoom = 1
    plX = 2.5
    plY = 3.0
    plDir = 1

    pop_addGuard(2, 6.0, 3.0, -1, 3)
    pop_addGuard(3, 3.0, 3.0, 1, 3)
    pop_addGuard(6, 5.0, 3.0, -1, 4)
    pop_addGuard(8, 4.0, 3.0, 1, 3)
    pop_addGuard(10, 7.0, 3.0, -1, 4)
    pop_addGuard(11, 5.0, 3.0, 1, 5)

// =============================================================
// Level 3 - The Tower (Boss)
// =============================================================

func pop_level3
    roomsCols = 3
    roomsRows = 3

    for i = 1 to 9
        add(rooms, pop_makeRoom())
    next

    // Room 1 start
    r = rooms[1]
    for c = 1 to ROOM_W r[4][c] = T_FLOOR next
    r[3][1] = T_WALL r[2][1] = T_WALL r[1][1] = T_WALL
    r[1][1] = T_TORCH
    r[4][8] = T_POTION
    rooms[1] = r

    // Room 2
    r = rooms[2]
    for c = 1 to ROOM_W r[4][c] = T_FLOOR next
    r[4][3] = T_SPIKES r[4][4] = T_CHOMPER r[4][6] = T_SPIKES
    r[2][8] = T_FLOOR r[2][9] = T_FLOOR
    rooms[2] = r

    // Room 3
    r = rooms[3]
    for c = 1 to ROOM_W r[4][c] = T_FLOOR next
    r[3][10] = T_WALL r[2][10] = T_WALL r[1][10] = T_WALL
    r[4][5] = T_LEVER
    r[4][2] = T_LOOSE r[4][3] = T_LOOSE
    r[1][7] = T_TORCH
    rooms[3] = r

    // Room 4
    r = rooms[4]
    for c = 1 to ROOM_W r[4][c] = T_FLOOR next
    r[3][1] = T_WALL r[2][1] = T_WALL
    r[4][4] = T_CHOMPER r[4][7] = T_SPIKES
    rooms[4] = r

    // Room 5 - central
    r = rooms[5]
    for c = 1 to ROOM_W r[4][c] = T_FLOOR next
    r[4][5] = T_PLATE
    for c = 7 to 9 r[4][c] = T_EMPTY next
    r[2][3] = T_FLOOR r[2][4] = T_FLOOR
    r[4][2] = T_POTION
    rooms[5] = r

    // Room 6
    r = rooms[6]
    for c = 1 to ROOM_W r[4][c] = T_FLOOR next
    r[4][3] = T_GATE
    r[3][10] = T_WALL r[2][10] = T_WALL r[1][10] = T_WALL
    r[1][6] = T_TORCH
    rooms[6] = r
    add(gates, [6, 4, 3, false, false, 2.0])

    // Room 7
    r = rooms[7]
    for c = 1 to ROOM_W r[4][c] = T_FLOOR next
    r[3][1] = T_WALL r[2][1] = T_WALL r[1][1] = T_WALL
    r[4][5] = T_SPIKES r[4][6] = T_SPIKES
    rooms[7] = r

    // Room 8
    r = rooms[8]
    for c = 1 to ROOM_W r[4][c] = T_FLOOR next
    r[4][4] = T_CHOMPER r[4][7] = T_CHOMPER
    r[4][5] = T_LOOSE r[4][6] = T_LOOSE
    r[1][9] = T_TORCH
    rooms[8] = r

    // Room 9 - exit
    r = rooms[9]
    for c = 1 to ROOM_W r[4][c] = T_FLOOR next
    r[4][7] = T_EXIT_DOOR
    r[3][10] = T_WALL r[2][10] = T_WALL r[1][10] = T_WALL
    r[1][3] = T_TORCH
    rooms[9] = r

    currentRoom = 1
    plX = 2.5
    plY = 3.0
    plDir = 1

    pop_addGuard(2, 8.0, 3.0, -1, 4)
    pop_addGuard(4, 6.0, 3.0, 1, 4)
    pop_addGuard(5, 8.0, 3.0, -1, 5)
    pop_addGuard(7, 4.0, 3.0, 1, 4)
    pop_addGuard(8, 5.0, 3.0, -1, 5)
    // Boss guard
    pop_addGuard(9, 4.0, 3.0, -1, 8)

func pop_addGuard rm, gx, gy, gdir, hp
    // [x, y, dir, health, maxHealth, state, stateTimer, attackCooldown, room, alertRange]
    add(guards, [gx, gy, gdir, hp, hp, GS_IDLE, 1.0 + random(100)/100.0, 0.0, rm, 6.0])

// =============================================================
// Input Handling
// =============================================================

func pop_handleInput dt
    if !plAlive return ok
    if plState = PS_DYING or plState = PS_DEAD return ok

    // Restart
    if IsKeyPressed(KEY_R)
        pop_loadLevel(levelNum)
        gameState = GM_PLAYING
        return
    ok

    // Draw/sheathe sword
    if IsKeyPressed(KEY_SPACE)
        if plSword
            plSword = false
            plState = PS_IDLE
        else
            plSword = true
            plState = PS_SWORD_IDLE
        ok
    ok

    careful = IsKeyDown(KEY_LEFT_SHIFT) or IsKeyDown(KEY_RIGHT_SHIFT)

    if plSword
        pop_handleSwordInput(dt)
    else
        pop_handleMoveInput(dt, careful)
    ok

func pop_handleMoveInput dt, careful
    if plState = PS_HANG
        // Hang controls
        if IsKeyPressed(KEY_UP) or IsKeyPressed(KEY_W)
            // Climb up
            plState = PS_CLIMB
            plStateTimer = 0.4
        ok
        if IsKeyPressed(KEY_DOWN) or IsKeyPressed(KEY_S)
            // Let go
            plState = PS_FALL
            plVY = 0
        ok
        return
    ok

    if plState = PS_CLIMB return ok

    if plState = PS_JUMP or plState = PS_FALL
        // Air control (limited)
        if IsKeyDown(KEY_RIGHT) or IsKeyDown(KEY_D)
            plVX = 3.5
            plDir = 1
        ok
        if IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_A)
            plVX = -3.5
            plDir = -1
        ok
        // Q to grab edge while in air
        if IsKeyPressed(KEY_Q)
            hangResult = pop_checkHang(plX, plY)
            if hangResult > 0
                plState = PS_HANG
                plVY = 0
                plVX = 0
                return
            ok
            // Also check one tile in facing direction
            checkX = plX + plDir * 0.5
            hangResult = pop_checkHang(checkX, plY)
            if hangResult > 0
                plState = PS_HANG
                plVY = 0
                plVX = 0
                return
            ok
        ok
        return
    ok

    // Ground movement
    if IsKeyDown(KEY_RIGHT) or IsKeyDown(KEY_D)
        plDir = 1
        if careful
            plState = PS_CAREFUL
            plVX = 1.2
        else
            plState = PS_RUN
            plVX = 4.0
        ok
    ok
    if IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_A)
        plDir = -1
        if careful
            plState = PS_CAREFUL
            plVX = -1.2
        else
            plState = PS_RUN
            plVX = -4.0
        ok
    ok
    if !IsKeyDown(KEY_RIGHT) and !IsKeyDown(KEY_D) and !IsKeyDown(KEY_LEFT) and !IsKeyDown(KEY_A)
        if plState = PS_RUN or plState = PS_CAREFUL
            plState = PS_IDLE
            plVX = 0
        ok
    ok

    if IsKeyDown(KEY_DOWN) or IsKeyDown(KEY_S)
        if plOnGround
            plState = PS_CROUCH
            plVX = 0
        ok
    else
        if plState = PS_CROUCH
            plState = PS_IDLE
        ok
    ok

    // Jump
    if IsKeyPressed(KEY_UP) or IsKeyPressed(KEY_W)
        if plOnGround
            plState = PS_JUMP
            plVY = -5.8
            if IsKeyDown(KEY_RIGHT) or IsKeyDown(KEY_D)
                plVX = 3.5
                plDir = 1
            ok
            if IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_A)
                plVX = -3.5
                plDir = -1
            ok
        ok
    ok

    // Q to grab edge from ground (jump up and grab)
    if IsKeyPressed(KEY_Q)
        if plOnGround
            // Check above current position for a hangable edge
            checkRow = floor(plY / TILE_H)   // one row up
            if checkRow >= 1 and checkRow <= ROOM_H
                col = floor(plX / TILE_W) + 1
                if col >= 1 and col <= ROOM_W
                    tUp = rooms[currentRoom][checkRow][col]
                    if tUp = T_EMPTY or tUp = T_TORCH
                        if checkRow >= 2
                            tAbove = rooms[currentRoom][checkRow - 1][col]
                            if tAbove = T_FLOOR or tAbove = T_EDGE or tAbove = T_LOOSE or tAbove = T_POTION or tAbove = T_LEVER or tAbove = T_PLATE
                                plState = PS_HANG
                                plHangTile = col
                                plHangRow = checkRow - 1
                                plY = (checkRow - 1) * TILE_H
                                plVY = 0
                                plVX = 0
                                return
                            ok
                        ok
                    ok
                ok
            ok
        ok
    ok

    // Interact
    if IsKeyPressed(KEY_E)
        pop_interact()
    ok

func pop_handleSwordInput dt
    if plState = PS_SWORD_ATK or plState = PS_HIT return ok

    // Move in sword mode (slower)
    if IsKeyDown(KEY_RIGHT) or IsKeyDown(KEY_D)
        plDir = 1
        plVX = 1.5
    ok
    if IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_A)
        plDir = -1
        plVX = -1.5
    ok
    if !IsKeyDown(KEY_RIGHT) and !IsKeyDown(KEY_D) and !IsKeyDown(KEY_LEFT) and !IsKeyDown(KEY_A)
        plVX = 0
    ok

    // Attack
    if IsKeyPressed(KEY_F) or IsMouseButtonPressed(0)
        plState = PS_SWORD_ATK
        plStateTimer = 0.3
        // Check hit on guards
        pop_playerSwordHit()
    ok

    // Block (hold down)
    if IsKeyDown(KEY_DOWN) or IsKeyDown(KEY_S)
        plState = PS_SWORD_BLK
    else
        if plState = PS_SWORD_BLK
            plState = PS_SWORD_IDLE
        ok
    ok

// =============================================================
// Player Update
// =============================================================

func pop_updatePlayer dt
    if !plAlive return ok

    plAnimTime += dt

    // State timer
    if plStateTimer > 0
        plStateTimer -= dt
        if plStateTimer <= 0
            if plState = PS_SWORD_ATK plState = PS_SWORD_IDLE ok
            if plState = PS_HIT plState = PS_SWORD_IDLE ok
            if plState = PS_CLIMB
                // Finished climbing - move to top
                plY = plHangRow - 1.0
                plState = PS_IDLE
                plSword = false
            ok
            if plState = PS_DYING
                plState = PS_DEAD
                plAlive = false
                gameState = GM_DEAD
                deathTimer = 1.5
            ok
        ok
    ok

    // Running animation
    if plState = PS_RUN
        plRunFrame += dt * 10.0
    else
        plRunFrame = 0
    ok

    // Gravity
    if plState != PS_HANG and plState != PS_CLIMB
        plVY += 15.0 * dt   // gravity
        if plVY > 12.0 plVY = 12.0 ok
    ok

    // Apply velocity
    newX = plX + plVX * dt
    newY = plY + plVY * dt

    // Collision detection
    if plState != PS_HANG and plState != PS_CLIMB
        // Floor collision
        plOnGround = false
        floorY = pop_getFloorBelow(newX, newY)
        if floorY > 0
            if newY >= floorY - 0.01
                // Check fall damage
                if plVY > 8.0 and plState = PS_FALL
                    pop_playerDie()
                    return
                ok
                newY = floorY - 0.01
                plVY = 0
                plOnGround = true
                if plState = PS_FALL or plState = PS_JUMP
                    plState = PS_IDLE
                ok
            ok
        else
            // No floor - falling
            if plState != PS_JUMP and plState != PS_FALL
                // Check for edge to grab
                if plVY >= 0
                    hangResult = pop_checkHang(newX, plY)
                    if hangResult > 0
                        plState = PS_HANG
                        plVY = 0
                        plVX = 0
                        return
                    ok
                ok
                plState = PS_FALL
            ok
        ok

        // Wall collision - check left and right edges of player
        playerW = 0.15  // half-width
        if plVX > 0
            // Moving right - check right edge
            if pop_checkWall(newX + playerW, plY)
                newX = plX
                plVX = 0
            ok
        ok
        if plVX < 0
            // Moving left - check left edge
            if pop_checkWall(newX - playerW, plY)
                newX = plX
                plVX = 0
            ok
        ok

        // Fall into void
        if newY > (ROOM_H) * TILE_H + 0.5
            // Check if there's a room below
            roomBelow = pop_getRoomBelow()
            if roomBelow > 0
                currentRoom = roomBelow
                plY = 0.1
                newY = 0.1
                // Keep falling velocity
            else
                pop_playerDie()
                return
            ok
        ok

        plX = newX
        plY = newY
    ok

    // Room transitions (left/right)
    if plX < 0.0
        roomLeft = pop_getRoomLeft()
        if roomLeft > 0
            currentRoom = roomLeft
            plX = ROOM_W * TILE_W - 0.3
        else
            plX = 0.0
            plVX = 0
        ok
    ok
    if plX > ROOM_W * TILE_W
        roomRight = pop_getRoomRight()
        if roomRight > 0
            currentRoom = roomRight
            // Find first clear column from left
            plX = 0.5
            prow = floor(plY / TILE_H) + 1
            if prow < 1 prow = 1 ok
            if prow > ROOM_H prow = ROOM_H ok
            for cc = 1 to ROOM_W
                t = rooms[currentRoom][prow][cc]
                if t != T_WALL and t != T_BRICKS and t != T_PILLAR
                    plX = (cc - 1) * TILE_W + 0.5
                    exit
                ok
            next
        else
            plX = ROOM_W * TILE_W
            plVX = 0
        ok
    ok

    // Check exit
    col = floor(plX / TILE_W) + 1
    row = pop_getPlayerFloorRow()
    if col >= 1 and col <= ROOM_W and row >= 1 and row <= ROOM_H
        if rooms[currentRoom][row][col] = T_EXIT_DOOR
            if plOnGround
                gameState = GM_WON
            ok
        ok
    ok

    // Friction when stopped
    if plState = PS_IDLE or plState = PS_SWORD_IDLE or plState = PS_CROUCH
        plVX = plVX * 0.8
        if fabs(plVX) < 0.1 plVX = 0 ok
    ok

// =============================================================
// Physics helpers
// =============================================================

func pop_getFloorBelow x, y
    col = floor(x / TILE_W) + 1
    if col < 1 col = 1 ok
    if col > ROOM_W col = ROOM_W ok

    for row = 1 to ROOM_H
        t = T_EMPTY
        if currentRoom >= 1 and currentRoom <= len(rooms)
            t = rooms[currentRoom][row][col]
        ok
        if t = T_FLOOR or t = T_SPIKES or t = T_LOOSE or t = T_LEVER or t = T_EXIT_DOOR or t = T_EDGE or t = T_POTION or t = T_CHOMPER or t = T_PLATE
            floorTop = (row - 1) * TILE_H
            if y <= floorTop + 0.2
                return floorTop
            ok
        ok
        if t = T_GATE
            // Check if gate is closed
            if !pop_isGateOpen(currentRoom, row, col)
                floorTop = (row - 1) * TILE_H
                if y <= floorTop + 0.2
                    return floorTop
                ok
            ok
        ok
    next
    return -1

func pop_checkWall x, y
    col = floor(x / TILE_W) + 1
    if col < 1 or col > ROOM_W return false ok

    // Check the row the player is in
    row = floor(y / TILE_H) + 1

    // Check current row, floor row below, and torso row above
    for checkRow = row - 1 to row + 1
        if checkRow < 1 or checkRow > ROOM_H loop ok
        t = rooms[currentRoom][checkRow][col]

        // Gates block regardless of position
        if t = T_GATE
            if !pop_isGateOpen(currentRoom, checkRow, col)
                return true
            ok
        ok

        // Walls/bricks block at player row and floor row
        if t = T_WALL or t = T_BRICKS or t = T_PILLAR
            if checkRow = row or checkRow = row + 1
                // Same row or floor row - always block
                return true
            ok
            if checkRow = row - 1
                // Row above - only block if it's a side wall (has floor below)
                tBelow = rooms[currentRoom][row][col]
                if tBelow = T_FLOOR or tBelow = T_LEVER or tBelow = T_POTION or tBelow = T_PLATE or tBelow = T_SPIKES or tBelow = T_CHOMPER or tBelow = T_LOOSE or tBelow = T_EXIT_DOOR or tBelow = T_EDGE
                    return true
                ok
            ok
        ok
    next

    return false

func pop_checkHang x, y
    // Check if there's an edge to grab above
    col = floor(x / TILE_W) + 1
    row = floor(y / TILE_H) + 1
    if col < 1 or col > ROOM_W return 0 ok
    if row < 1 return 0 ok
    if row > ROOM_H return 0 ok

    // Check tile at player's level - is it empty?
    // Check tile above has a floor edge
    if row >= 2
        tAbove = rooms[currentRoom][row-1][col]
        tHere = rooms[currentRoom][row][col]
        if tHere = T_EMPTY or tHere = T_TORCH
            if tAbove = T_FLOOR or tAbove = T_EDGE or tAbove = T_LOOSE or tAbove = T_POTION or tAbove = T_LEVER or tAbove = T_PLATE
                plHangTile = col
                plHangRow = row - 1
                plY = (row - 1) * TILE_H
                return col
            ok
        ok
    ok
    return 0

func pop_isGateOpen rm, row, col
    for i = 1 to len(gates)
        if gates[i][1] = rm and gates[i][2] = row and gates[i][3] = col
            return gates[i][4]
        ok
    next
    return false

// =============================================================
// Room Navigation
// =============================================================

func pop_getRoomRight
    // Current room position in grid
    cx = ((currentRoom - 1) % roomsCols) + 1
    cy = floor((currentRoom - 1) / roomsCols) + 1
    if cx < roomsCols
        return (cy - 1) * roomsCols + cx + 1
    ok
    return 0

func pop_getRoomLeft
    cx = ((currentRoom - 1) % roomsCols) + 1
    cy = floor((currentRoom - 1) / roomsCols) + 1
    if cx > 1
        return (cy - 1) * roomsCols + cx - 1
    ok
    return 0

func pop_getRoomBelow
    cx = ((currentRoom - 1) % roomsCols) + 1
    cy = floor((currentRoom - 1) / roomsCols) + 1
    if cy < roomsRows
        return cy * roomsCols + cx
    ok
    return 0

func pop_getRoomAbove
    cx = ((currentRoom - 1) % roomsCols) + 1
    cy = floor((currentRoom - 1) / roomsCols) + 1
    if cy > 1
        return (cy - 2) * roomsCols + cx
    ok
    return 0

// =============================================================
// Interaction (potions, levers)
// =============================================================

func pop_interact
    col = floor(plX / TILE_W) + 1
    row = floor(plY / TILE_H) + 1
    if col < 1 col = 1 ok
    if col > ROOM_W col = ROOM_W ok
    if row < 1 row = 1 ok
    if row > ROOM_H row = ROOM_H ok

    // Check current tile, tile below (floor), and tile in facing direction
    tilesToCheck = []
    add(tilesToCheck, [row, col])
    if row + 1 <= ROOM_H add(tilesToCheck, [row + 1, col]) ok
    if row - 1 >= 1 add(tilesToCheck, [row - 1, col]) ok
    faceCol = col + plDir
    if faceCol >= 1 and faceCol <= ROOM_W
        add(tilesToCheck, [row, faceCol])
        if row + 1 <= ROOM_H add(tilesToCheck, [row + 1, faceCol]) ok
    ok

    for ti = 1 to len(tilesToCheck)
        cr = tilesToCheck[ti][1]
        cc = tilesToCheck[ti][2]
        t = rooms[currentRoom][cr][cc]

        // Lever
        if t = T_LEVER
            for i = 1 to len(gates)
                gates[i][5] = !gates[i][5]
            next
            pop_showMsg("Lever pulled!")
            return
        ok

        // Potion
        if t = T_POTION
            for i = 1 to len(potions)
                if potions[i][1] = currentRoom and potions[i][3] = cc and !potions[i][5]
                    potions[i][5] = true
                    if potions[i][4] = 1
                        plHealth += 1
                        if plHealth > plMaxHealth plHealth = plMaxHealth ok
                        pop_showMsg("Health restored!")
                    else
                        plMaxHealth += 1
                        plHealth = plMaxHealth
                        pop_showMsg("Max health increased!")
                    ok
                    rooms[currentRoom][cr][cc] = T_FLOOR
                    return
                ok
            next
        ok

        // Pressure plate
        if t = T_PLATE
            for i = 1 to len(gates)
                gates[i][5] = true
            next
            pop_showMsg("Gate opened!")
            return
        ok
    next

// =============================================================
// Player Combat
// =============================================================

func pop_playerSwordHit
    // Check if any guard in current room is in range
    for i = 1 to len(guards)
        if guards[i][9] != currentRoom loop ok
        if guards[i][6] = GS_DEAD or guards[i][6] = GS_DYING loop ok

        gx = guards[i][1]
        dx = gx - plX
        dist = fabs(dx)

        // Check direction and range
        if dist < 1.5
            if (plDir = 1 and dx > 0) or (plDir = -1 and dx < 0)
                // Hit! But guard might block
                if guards[i][6] = GS_BLOCK
                    // Blocked!
                    pop_showMsg("Blocked!")
                else
                    guards[i][4] -= 1
                    guards[i][6] = GS_HIT
                    guards[i][7] = 0.3
                    if guards[i][4] <= 0
                        guards[i][6] = GS_DYING
                        guards[i][7] = 0.8
                        pop_showMsg("Enemy defeated!")
                    ok
                ok
            ok
        ok
    next

// =============================================================
// Guard AI
// =============================================================

func pop_updateGuards dt
    for i = 1 to len(guards)
        if guards[i][9] != currentRoom loop ok
        if guards[i][6] = GS_DEAD loop ok

        gx = guards[i][1]
        gy = guards[i][2]
        gstate = guards[i][6]

        dx = plX - gx
        dist = fabs(dx)

        guards[i][7] -= dt
        if guards[i][8] > 0 guards[i][8] -= dt ok

        switch gstate
        on GS_DYING
            if guards[i][7] <= 0
                guards[i][6] = GS_DEAD
            ok
        on GS_HIT
            if guards[i][7] <= 0
                // Push back
                guards[i][1] += guards[i][3] * -0.5
                guards[i][6] = GS_ADVANCE
                guards[i][7] = 0.3
            ok
        on GS_IDLE
            // Face player if nearby
            if dist < guards[i][10]
                if dx > 0 guards[i][3] = 1 else guards[i][3] = -1 ok
                guards[i][6] = GS_ADVANCE
                guards[i][7] = 0.5
            else
                // Patrol
                guards[i][1] += guards[i][3] * 1.0 * dt
                // Turn at edges
                gcol = floor(guards[i][1] / TILE_W) + 1
                if gcol < 2 or gcol > ROOM_W - 1
                    guards[i][3] = -guards[i][3]
                ok
                // Check floor ahead
                checkCol = floor((guards[i][1] + guards[i][3] * 0.8) / TILE_W) + 1
                if checkCol >= 1 and checkCol <= ROOM_W
                    if rooms[guards[i][9]][4][checkCol] = T_EMPTY
                        guards[i][3] = -guards[i][3]
                    ok
                ok
            ok
        on GS_ADVANCE
            if dx > 0 guards[i][3] = 1 else guards[i][3] = -1 ok
            if dist > 1.2
                // Move toward player
                guards[i][1] += guards[i][3] * 2.5 * dt
            else
                // In attack range
                if guards[i][8] <= 0
                    // Decide: attack or block
                    if random(100) < 60
                        guards[i][6] = GS_ATTACK
                        guards[i][7] = 0.35
                    else
                        guards[i][6] = GS_BLOCK
                        guards[i][7] = 0.5 + random(50)/100.0
                    ok
                ok
            ok
            if dist > guards[i][10] + 2
                guards[i][6] = GS_IDLE
                guards[i][7] = 1.0
            ok
        on GS_ATTACK
            if guards[i][7] <= 0
                // Strike!
                if dist < 1.5
                    if plState = PS_SWORD_BLK
                        pop_showMsg("You blocked!")
                    else
                        plHealth -= 1
                        plState = PS_HIT
                        plStateTimer = 0.3
                        if plHealth <= 0
                            pop_playerDie()
                        ok
                    ok
                ok
                guards[i][6] = GS_ADVANCE
                guards[i][7] = 0.3
                guards[i][8] = 0.5 + random(50)/100.0
            ok
        on GS_BLOCK
            if guards[i][7] <= 0
                guards[i][6] = GS_ADVANCE
                guards[i][7] = 0.3
            ok
        off
    next

// =============================================================
// Trap Updates
// =============================================================

func pop_updateTraps dt
    // Spikes
    for i = 1 to len(spikesState)
        spikesState[i][5] -= dt
        if spikesState[i][5] <= 0
            spikesState[i][4] = !spikesState[i][4]
            if spikesState[i][4]
                spikesState[i][5] = 0.8   // extended time
            else
                spikesState[i][5] = 2.0 + random(200)/100.0  // retracted time
            ok

            // Damage player if extended and on same tile
            if spikesState[i][4] and spikesState[i][1] = currentRoom
                sc = spikesState[i][3]
                sr = spikesState[i][2]
                pcol = floor(plX / TILE_W) + 1
                prow = pop_getPlayerFloorRow()
                if pcol = sc and prow = sr and plOnGround
                    pop_playerDie()
                ok
            ok
        ok
    next

    // Chompers
    for i = 1 to len(chompers)
        chompers[i][4] -= dt
        if chompers[i][4] <= 0
            chompers[i][5] = !chompers[i][5]
            if chompers[i][5]
                chompers[i][4] = 0.3   // closing time
                // Check player
                if chompers[i][1] = currentRoom
                    cc = chompers[i][3]
                    pcol = floor(plX / TILE_W) + 1
                    if pcol = cc and plOnGround
                        pop_playerDie()
                    ok
                ok
            else
                chompers[i][4] = 1.5 + random(150)/100.0
            ok
        ok
    next

    // Gates
    for i = 1 to len(gates)
        if gates[i][5]  // should be open
            if !gates[i][4]
                gates[i][4] = true
            ok
        else
            gates[i][4] = false
        ok
    next

    // Loose floors
    if plOnGround
        col = floor(plX / TILE_W) + 1
        row = pop_getPlayerFloorRow()
        if col >= 1 and col <= ROOM_W and row >= 1 and row <= ROOM_H
            if rooms[currentRoom][row][col] = T_LOOSE
                wx = (col - 1) * TILE_W + TILE_W/2
                wy = (row - 1) * TILE_H + TILE_H/2
                add(fallingFloors, [wx, wy, 0.0, 0.5, currentRoom])
                rooms[currentRoom][row][col] = T_EMPTY
            ok
        ok
    ok

    // Pressure plates - auto-trigger on step
    if plOnGround
        col = floor(plX / TILE_W) + 1
        row = pop_getPlayerFloorRow()
        // Check current row and floor row below
        for checkR = row to row + 1
            if col >= 1 and col <= ROOM_W and checkR >= 1 and checkR <= ROOM_H
                if rooms[currentRoom][checkR][col] = T_PLATE
                    for i = 1 to len(gates)
                        gates[i][5] = true
                    next
                ok
            ok
        next
    ok

func pop_updateFallingFloors dt
    i = 1
    while i <= len(fallingFloors)
        fallingFloors[i][4] -= dt
        if fallingFloors[i][4] <= 0
            fallingFloors[i][3] += 10.0 * dt
            fallingFloors[i][2] += fallingFloors[i][3] * dt
        ok
        if fallingFloors[i][2] > 20
            del(fallingFloors, i)
        else
            i += 1
        ok
    end

// =============================================================
// Death
// =============================================================

func pop_playerDie
    if plState = PS_DYING or plState = PS_DEAD return ok
    plState = PS_DYING
    plStateTimer = 1.0
    plVX = 0
    plVY = 0

func pop_checkDeath
    if plHealth <= 0 and plAlive and plState != PS_DYING and plState != PS_DEAD
        pop_playerDie()
    ok

// =============================================================
// Camera
// =============================================================

func pop_updateCamera dt
    camTargetX = plX
    camTargetY = flipY(ROOM_H * TILE_H / 2.0)

    // Smooth follow
    camX += (camTargetX - camX) * dt * 4.0
    camY += (camTargetY - camY) * dt * 4.0

    cam.position.x = camX
    cam.position.y = camY + 1.0
    cam.position.z = 10.0

    cam.target.x = camX
    cam.target.y = camY + 0.3
    cam.target.z = 0.0

// =============================================================
// Drawing - Room
// =============================================================

func pop_drawRoom
    rm = currentRoom
    if rm < 1 or rm > len(rooms) return ok

    // Draw background (dark dungeon wall)
    bgX = ROOM_W * TILE_W / 2.0
    bgY = flipY(ROOM_H * TILE_H / 2.0)
    DrawCube(Vector3(bgX, bgY, -0.5), ROOM_W * TILE_W + 2, ROOM_H * TILE_H + 2, 0.1,
             RAYLIBColor(25, 22, 30, 255))

    // Draw each tile
    for row = 1 to ROOM_H
        for col = 1 to ROOM_W
            t = rooms[rm][row][col]
            wx = (col - 1) * TILE_W + TILE_W / 2.0
            wy = flipY((row - 1) * TILE_H + TILE_H / 2.0)

            pop_drawTile(t, wx, wy, row, col)
        next
    next

func pop_drawTile t, wx, wy, row, col
    if t = T_EMPTY return ok

    if t = T_FLOOR or t = T_LEVER or t = T_POTION or t = T_PLATE
        pop_drawFloorTile(wx, wy)
        if t = T_LEVER pop_drawLever(wx, wy) ok
        if t = T_POTION pop_drawPotion(wx, wy) ok
        if t = T_PLATE pop_drawPlate(wx, wy) ok
    ok

    if t = T_WALL or t = T_BRICKS
        pop_drawWallTile(wx, wy, t)
    ok

    if t = T_PILLAR
        pop_drawPillar(wx, wy)
    ok

    if t = T_SPIKES
        pop_drawFloorTile(wx, wy)
        pop_drawSpikes(wx, wy, row, col)
    ok

    if t = T_LOOSE
        pop_drawLooseFloor(wx, wy)
    ok

    if t = T_GATE
        pop_drawGate(wx, wy, currentRoom, row, col)
    ok

    if t = T_EXIT_DOOR
        pop_drawFloorTile(wx, wy)
        pop_drawExitDoor(wx, wy)
    ok

    if t = T_TORCH
        pop_drawWallTile(wx, wy, T_WALL)
        pop_drawTorch(wx, wy)
    ok

    if t = T_EDGE
        pop_drawFloorTile(wx, wy)
    ok

    if t = T_CHOMPER
        pop_drawFloorTile(wx, wy)
        pop_drawChomper(wx, wy, row, col)
    ok

// =============================================================
// Tile Drawing Functions
// =============================================================

func pop_drawFloorTile wx, wy
    // Stone floor - at bottom of tile cell
    DrawCube(Vector3(wx, wy - 0.4, 0), TILE_W, 0.2, 1.0,
             RAYLIBColor(120, 115, 130, 255))
    // Top surface highlight
    DrawCube(Vector3(wx, wy - 0.29, 0), TILE_W * 0.98, 0.02, 0.98,
             RAYLIBColor(140, 135, 148, 255))
    // Front face
    DrawCube(Vector3(wx, wy - 0.4, 0.505), TILE_W, 0.2, 0.01,
             RAYLIBColor(100, 95, 110, 255))
    // Mortar line
    DrawCube(Vector3(wx, wy - 0.5, 0), TILE_W, 0.01, 1.0,
             RAYLIBColor(80, 75, 88, 255))

func pop_drawWallTile wx, wy, style
    // Main wall block
    baseR = 90  baseG = 85  baseB = 110
    if style = T_BRICKS
        baseR = 80  baseG = 78  baseB = 95
    ok
    DrawCube(Vector3(wx, wy, 0), TILE_W, TILE_H, 1.0,
             RAYLIBColor(baseR, baseG, baseB, 255))

    // Brick mortar lines - front face
    for brickRow = 0 to 3
        by = wy - TILE_H/2 + brickRow * 0.25 + 0.125
        DrawCube(Vector3(wx, by, 0.505), TILE_W * 0.98, 0.01, 0.005,
                 RAYLIBColor(baseR-25, baseG-25, baseB-25, 255))
    next
    // Vertical mortar (offset pattern)
    DrawCube(Vector3(wx - 0.2, wy - 0.125, 0.505), 0.01, 0.24, 0.005,
             RAYLIBColor(baseR-25, baseG-25, baseB-25, 255))
    DrawCube(Vector3(wx + 0.15, wy + 0.125, 0.505), 0.01, 0.24, 0.005,
             RAYLIBColor(baseR-25, baseG-25, baseB-25, 255))
    DrawCube(Vector3(wx - 0.35, wy + 0.125, 0.505), 0.01, 0.24, 0.005,
             RAYLIBColor(baseR-25, baseG-25, baseB-25, 255))
    DrawCube(Vector3(wx + 0.35, wy - 0.125, 0.505), 0.01, 0.24, 0.005,
             RAYLIBColor(baseR-25, baseG-25, baseB-25, 255))

    // Dark cracks for detail
    if style = T_BRICKS
        DrawCube(Vector3(wx - 0.1, wy + 0.2, 0.506), 0.25, 0.01, 0.003,
                 RAYLIBColor(40, 38, 50, 255))
        DrawCube(Vector3(wx + 0.2, wy - 0.15, 0.506), 0.01, 0.2, 0.003,
                 RAYLIBColor(40, 38, 50, 255))
    ok

    // Top edge highlight
    DrawCube(Vector3(wx, wy + TILE_H/2, 0), TILE_W, 0.02, 1.0,
             RAYLIBColor(baseR+15, baseG+15, baseB+15, 255))

func pop_drawPillar wx, wy
    DrawCylinder(Vector3(wx, wy - TILE_H/2, 0), 0.15, 0.18, TILE_H, 8,
                 RAYLIBColor(110, 105, 120, 255))
    // Capital (top)
    DrawCube(Vector3(wx, wy + TILE_H/2 - 0.05, 0), 0.4, 0.1, 0.4,
             RAYLIBColor(125, 120, 135, 255))
    // Base (bottom)
    DrawCube(Vector3(wx, wy - TILE_H/2 + 0.05, 0), 0.4, 0.1, 0.4,
             RAYLIBColor(100, 95, 110, 255))

func pop_drawSpikes wx, wy, row, col
    // Check spike state
    extended = false
    for i = 1 to len(spikesState)
        if spikesState[i][1] = currentRoom and spikesState[i][2] = row and spikesState[i][3] = col
            extended = spikesState[i][4]
        ok
    next

    if extended
        // Draw spike blades coming up from floor
        spikeH = 0.35
        for s = -3 to 3
            sx = wx + s * 0.12
            DrawCube(Vector3(sx, wy - 0.3 + spikeH/2, 0), 0.04, spikeH, 0.04,
                     RAYLIBColor(180, 180, 190, 255))
            // Spike tip
            DrawCube(Vector3(sx, wy - 0.3 + spikeH + 0.03, 0), 0.02, 0.06, 0.02,
                     RAYLIBColor(200, 200, 210, 255))
        next
    else
        // Holes in floor
        for s = -3 to 3
            sx = wx + s * 0.12
            DrawCube(Vector3(sx, wy - 0.3, 0.505), 0.05, 0.05, 0.005,
                     RAYLIBColor(30, 28, 35, 255))
        next
    ok

func pop_drawLooseFloor wx, wy
    DrawCube(Vector3(wx, wy - 0.4, 0), TILE_W, 0.2, 1.0,
             RAYLIBColor(110, 100, 115, 255))
    DrawCube(Vector3(wx, wy - 0.29, 0), TILE_W * 0.96, 0.02, 0.96,
             RAYLIBColor(125, 115, 128, 255))
    // Crack lines
    DrawCube(Vector3(wx - 0.15, wy - 0.3, 0.506), 0.3, 0.01, 0.003,
             RAYLIBColor(60, 55, 68, 255))
    DrawCube(Vector3(wx + 0.1, wy - 0.32, 0.506), 0.2, 0.01, 0.003,
             RAYLIBColor(60, 55, 68, 255))
    // Front face
    DrawCube(Vector3(wx, wy - 0.4, 0.505), TILE_W, 0.2, 0.01,
             RAYLIBColor(90, 82, 95, 255))

func pop_drawGate wx, wy, rm, row, col
    isOpen = pop_isGateOpen(rm, row, col)
    if isOpen
        // Gate frame only
        DrawCube(Vector3(wx - TILE_W/2 + 0.03, wy, 0), 0.06, TILE_H, 0.3,
                 RAYLIBColor(70, 70, 80, 255))
        DrawCube(Vector3(wx + TILE_W/2 - 0.03, wy, 0), 0.06, TILE_H, 0.3,
                 RAYLIBColor(70, 70, 80, 255))
        DrawCube(Vector3(wx, wy + TILE_H/2 - 0.03, 0), TILE_W, 0.06, 0.3,
                 RAYLIBColor(70, 70, 80, 255))
    else
        // Closed gate - metal bars
        pop_drawFloorTile(wx, wy)
        DrawCube(Vector3(wx, wy, 0), TILE_W, TILE_H, 0.08,
                 RAYLIBColor(70, 70, 80, 200))
        // Bars
        for b = -3 to 3
            bx = wx + b * 0.12
            DrawCube(Vector3(bx, wy, 0.05), 0.03, TILE_H, 0.03,
                     RAYLIBColor(90, 90, 100, 255))
        next
        // Cross bar
        DrawCube(Vector3(wx, wy, 0.05), TILE_W, 0.04, 0.04,
                 RAYLIBColor(85, 85, 95, 255))
    ok

func pop_drawExitDoor wx, wy
    // Door frame
    DrawCube(Vector3(wx, wy + 0.1, -0.2), 0.7, 0.8, 0.1,
             RAYLIBColor(100, 60, 30, 255))
    // Door arch
    DrawCube(Vector3(wx, wy + 0.5, -0.2), 0.8, 0.1, 0.12,
             RAYLIBColor(80, 48, 25, 255))
    // Door surface
    DrawCube(Vector3(wx, wy + 0.1, -0.14), 0.6, 0.75, 0.02,
             RAYLIBColor(120, 75, 35, 255))
    // Handle
    DrawSphere(Vector3(wx + 0.15, wy + 0.1, -0.04), 0.04,
               RAYLIBColor(200, 180, 50, 255))
    // Glow
    pulse = sin(animTime * 3.0) * 0.3 + 0.7
    DrawCube(Vector3(wx, wy + 0.1, -0.08), 0.65, 0.78, 0.01,
             RAYLIBColor(255, 220, 100, floor(pulse * 40)))

func pop_drawTorch wx, wy
    // Bracket
    DrawCube(Vector3(wx, wy + 0.1, 0.45), 0.06, 0.3, 0.06,
             RAYLIBColor(80, 60, 30, 255))
    // Cup
    DrawCube(Vector3(wx, wy + 0.3, 0.45), 0.12, 0.08, 0.12,
             RAYLIBColor(90, 70, 35, 255))
    // Flames (animated)
    fh = 0.15 + sin(animTime * 8.0) * 0.05
    DrawCube(Vector3(wx, wy + 0.38 + fh/2, 0.45), 0.08, fh, 0.08,
             RAYLIBColor(255, 150, 30, 220))
    DrawCube(Vector3(wx, wy + 0.42 + fh/2, 0.45), 0.05, fh * 0.7, 0.05,
             RAYLIBColor(255, 220, 50, 180))
    // Glow on wall
    glowSize = 0.4 + sin(animTime * 6.0) * 0.1
    DrawCube(Vector3(wx, wy + 0.2, 0.50), glowSize, glowSize, 0.005,
             RAYLIBColor(255, 180, 60, 40))

func pop_drawLever wx, wy
    // Base on floor
    DrawCube(Vector3(wx, wy - 0.2, 0.4), 0.15, 0.1, 0.1,
             RAYLIBColor(80, 80, 90, 255))
    // Handle going up
    DrawCube(Vector3(wx, wy, 0.4), 0.04, 0.35, 0.04,
             RAYLIBColor(100, 100, 110, 255))
    // Knob
    DrawSphere(Vector3(wx, wy + 0.18, 0.4), 0.05,
               RAYLIBColor(180, 50, 50, 255))

func pop_drawPotion wx, wy
    bob = sin(animTime * 3.0) * 0.03
    // Bottle on floor
    DrawCylinder(Vector3(wx, wy - 0.18 + bob, 0.3), 0.06, 0.06, 0.15, 6,
                 RAYLIBColor(200, 50, 50, 200))
    // Neck
    DrawCylinder(Vector3(wx, wy - 0.05 + bob, 0.3), 0.03, 0.03, 0.06, 6,
                 RAYLIBColor(200, 50, 50, 180))
    // Glow
    DrawSphere(Vector3(wx, wy - 0.12 + bob, 0.3), 0.12,
               RAYLIBColor(255, 80, 80, floor(sin(animTime*4)*30+40)))

func pop_drawPlate wx, wy
    DrawCube(Vector3(wx, wy - 0.42, 0), TILE_W * 0.7, 0.04, 0.7,
             RAYLIBColor(100, 95, 85, 255))
    DrawCube(Vector3(wx, wy - 0.44, 0), TILE_W * 0.6, 0.02, 0.6,
             RAYLIBColor(110, 105, 95, 255))

func pop_drawChomper wx, wy, row, col
    // Check chomper state
    closing = false
    for i = 1 to len(chompers)
        if chompers[i][1] = currentRoom and chompers[i][2] = row and chompers[i][3] = col
            closing = chompers[i][5]
        ok
    next

    if closing
        DrawCube(Vector3(wx - 0.15, wy + 0.1, 0), 0.3, 0.6, 0.15,
                 RAYLIBColor(160, 160, 170, 255))
        DrawCube(Vector3(wx + 0.15, wy + 0.1, 0), 0.3, 0.6, 0.15,
                 RAYLIBColor(160, 160, 170, 255))
        for tt = 0 to 4
            ty = wy + 0.35 - tt * 0.14
            DrawCube(Vector3(wx, ty, 0.08), 0.06, 0.08, 0.02,
                     RAYLIBColor(200, 200, 210, 255))
        next
    else
        DrawCube(Vector3(wx - 0.35, wy + 0.1, 0), 0.15, 0.6, 0.15,
                 RAYLIBColor(80, 80, 90, 255))
        DrawCube(Vector3(wx + 0.35, wy + 0.1, 0), 0.15, 0.6, 0.15,
                 RAYLIBColor(80, 80, 90, 255))
    ok

// =============================================================
// Draw Player
// =============================================================

func pop_drawPlayer
    if !plAlive and plState = PS_DEAD return ok

    px = plX
    py = flipY(plY) - 0.5   // Offset down so feet align with floor surface
    dir = plDir

    // Death animation
    if plState = PS_DYING
        deathProg = 1.0 - (plStateTimer / 1.0)
        if deathProg > 1 deathProg = 1 ok
        py -= deathProg * 0.3
    ok

    // Colors (white outfit - the hero)
    shirtR = 235  shirtG = 230  shirtB = 220
    pantR = 230   pantG = 225   pantB = 215
    skinR = 220   skinG = 185   skinB = 145
    hairR = 40    hairG = 30    hairB = 25

    // Scale
    bodyH = 0.35
    legH = 0.25

    // Run animation offset
    legSwing = 0
    armSwing = 0
    if plState = PS_RUN
        legSwing = sin(plRunFrame) * 0.12
        armSwing = sin(plRunFrame) * 0.1
    ok

    // Crouch
    crouchOffset = 0
    if plState = PS_CROUCH
        crouchOffset = 0.15
    ok

    // Shadow
    DrawCube(Vector3(px, py - 0.28, 0.01), 0.3, 0.02, 0.3,
             RAYLIBColor(0, 0, 0, 30))

    // Legs (below torso)
    DrawCube(Vector3(px - dir * 0.06, py - 0.1 + legSwing - crouchOffset, 0.0),
             0.08, legH - crouchOffset * 0.5, 0.08,
             RAYLIBColor(pantR, pantG, pantB, 255))
    DrawCube(Vector3(px + dir * 0.06, py - 0.1 - legSwing - crouchOffset, 0.0),
             0.08, legH - crouchOffset * 0.5, 0.08,
             RAYLIBColor(pantR, pantG, pantB, 255))

    // Feet
    DrawCube(Vector3(px - dir * 0.06, py - 0.24 + legSwing, 0.02),
             0.09, 0.04, 0.12,
             RAYLIBColor(80, 50, 30, 255))
    DrawCube(Vector3(px + dir * 0.06, py - 0.24 - legSwing, 0.02),
             0.09, 0.04, 0.12,
             RAYLIBColor(80, 50, 30, 255))

    // Torso (center)
    DrawCube(Vector3(px, py + 0.1 - crouchOffset, 0.0),
             0.22, bodyH, 0.14,
             RAYLIBColor(shirtR, shirtG, shirtB, 255))
    // Sash/belt
    DrawCube(Vector3(px, py - 0.02 - crouchOffset, 0.07),
             0.24, 0.04, 0.005,
             RAYLIBColor(150, 50, 30, 255))

    // Arms
    armY = py + 0.08 - crouchOffset
    if plSword
        // Sword arm extended forward
        DrawCube(Vector3(px + dir * 0.18, armY, 0.0),
                 0.07, 0.20, 0.07,
                 RAYLIBColor(skinR, skinG, skinB, 255))
        // Sword
        swordLen = 0.4
        swordAngle = 0
        if plState = PS_SWORD_ATK
            swordAngle = plStateTimer * 3.0
        ok
        swordX = px + dir * 0.25
        swordY = armY + 0.1 + swordAngle * 0.1
        // Blade
        DrawCube(Vector3(swordX + dir * swordLen/2, swordY, 0.0),
                 swordLen, 0.03, 0.01,
                 RAYLIBColor(200, 200, 210, 255))
        // Guard
        DrawCube(Vector3(swordX, swordY, 0.0),
                 0.03, 0.08, 0.03,
                 RAYLIBColor(180, 160, 50, 255))
        // Handle
        DrawCube(Vector3(swordX - dir * 0.05, swordY, 0.0),
                 0.08, 0.03, 0.03,
                 RAYLIBColor(80, 50, 30, 255))

        // Other arm
        DrawCube(Vector3(px - dir * 0.15, armY - 0.05, 0.0),
                 0.07, 0.18, 0.07,
                 RAYLIBColor(skinR, skinG, skinB, 255))
    else
        // Normal arms
        DrawCube(Vector3(px + dir * 0.14, armY + armSwing, 0.0),
                 0.07, 0.20, 0.07,
                 RAYLIBColor(skinR, skinG, skinB, 255))
        DrawCube(Vector3(px - dir * 0.14, armY - armSwing, 0.0),
                 0.07, 0.20, 0.07,
                 RAYLIBColor(skinR, skinG, skinB, 255))
    ok

    // Head (above torso)
    headY = py + 0.30 - crouchOffset
    DrawSphere(Vector3(px, headY, 0.0), 0.09,
               RAYLIBColor(skinR, skinG, skinB, 255))
    // Hair
    DrawCube(Vector3(px, headY + 0.06, -0.02), 0.16, 0.06, 0.12,
             RAYLIBColor(hairR, hairG, hairB, 255))
    // Turban/headband
    DrawCube(Vector3(px, headY + 0.04, 0.0), 0.19, 0.04, 0.13,
             RAYLIBColor(230, 220, 200, 255))
    // Eye
    DrawCube(Vector3(px + dir * 0.06, headY + 0.01, 0.08),
             0.03, 0.02, 0.01,
             RAYLIBColor(30, 25, 20, 255))

    // Hang state - show arms reaching up
    if plState = PS_HANG
        DrawCube(Vector3(px - 0.08, py + 0.45, 0.0), 0.06, 0.2, 0.06,
                 RAYLIBColor(skinR, skinG, skinB, 255))
        DrawCube(Vector3(px + 0.08, py + 0.45, 0.0), 0.06, 0.2, 0.06,
                 RAYLIBColor(skinR, skinG, skinB, 255))
    ok

    // Block stance indicator
    if plState = PS_SWORD_BLK
        DrawCube(Vector3(px + dir * 0.15, py + 0.2, 0.08),
                 swordLen * 0.6, 0.03, 0.01,
                 RAYLIBColor(200, 200, 210, 200))
    ok

// =============================================================
// Draw Guards
// =============================================================

func pop_drawGuards
    for i = 1 to len(guards)
        if guards[i][9] != currentRoom loop ok
        if guards[i][6] = GS_DEAD loop ok
        pop_drawGuard(i)
    next

func pop_drawGuard idx
    gx = guards[idx][1]
    gy = flipY(guards[idx][2]) - 0.5   // Offset to align feet with floor
    gdir = guards[idx][3]
    gstate = guards[idx][6]

    // Death animation
    deathOff = 0
    if gstate = GS_DYING
        deathOff = (1.0 - guards[idx][7] / 0.8) * -0.4
    ok

    // Guard colors (blue outfit like the original)
    shirtR = 60   shirtG = 80   shirtB = 160
    pantR = 50    pantG = 60    pantB = 130
    skinR = 180   skinG = 140   skinB = 100
    if guards[idx][5] >= 6  // Boss - different color
        shirtR = 120  shirtG = 30  shirtB = 30
        pantR = 100   pantG = 25   pantB = 25
    ok

    bodyH = 0.32
    // Shadow
    DrawCube(Vector3(gx, gy - 0.28, 0.01), 0.3, 0.02, 0.3,
             RAYLIBColor(0, 0, 0, 30))

    // Legs (below)
    legAnim = 0
    if gstate = GS_ADVANCE legAnim = sin(animTime * 8) * 0.1 ok
    DrawCube(Vector3(gx - gdir * 0.06, gy - 0.1 + legAnim + deathOff, 0.0),
             0.08, 0.24, 0.08,
             RAYLIBColor(pantR, pantG, pantB, 255))
    DrawCube(Vector3(gx + gdir * 0.06, gy - 0.1 - legAnim + deathOff, 0.0),
             0.08, 0.24, 0.08,
             RAYLIBColor(pantR, pantG, pantB, 255))

    // Boots
    DrawCube(Vector3(gx - gdir * 0.06, gy - 0.24 + legAnim, 0.02),
             0.09, 0.04, 0.12,
             RAYLIBColor(50, 35, 20, 255))
    DrawCube(Vector3(gx + gdir * 0.06, gy - 0.24 - legAnim, 0.02),
             0.09, 0.04, 0.12,
             RAYLIBColor(50, 35, 20, 255))

    // Torso
    DrawCube(Vector3(gx, gy + 0.08 + deathOff, 0.0),
             0.22, bodyH, 0.14,
             RAYLIBColor(shirtR, shirtG, shirtB, 255))
    // Belt
    DrawCube(Vector3(gx, gy - 0.04 + deathOff, 0.07),
             0.24, 0.04, 0.005,
             RAYLIBColor(60, 40, 20, 255))

    // Arms + sword
    armY = gy + 0.06 + deathOff
    // Sword arm
    swordX = gx + gdir * 0.20
    DrawCube(Vector3(swordX, armY, 0.0),
             0.07, 0.18, 0.07,
             RAYLIBColor(skinR, skinG, skinB, 255))
    // Sword
    sLen = 0.35
    if gstate = GS_ATTACK
        DrawCube(Vector3(swordX + gdir * sLen/2, armY + 0.15, 0.0),
                 sLen, 0.03, 0.01,
                 RAYLIBColor(200, 200, 210, 255))
    ok
    if gstate = GS_BLOCK
        DrawCube(Vector3(swordX, armY + 0.15, 0.0),
                 0.03, sLen, 0.01,
                 RAYLIBColor(200, 200, 210, 255))
    ok
    if gstate != GS_ATTACK and gstate != GS_BLOCK
        DrawCube(Vector3(swordX + gdir * sLen/2, armY + 0.05, 0.0),
                 sLen, 0.03, 0.01,
                 RAYLIBColor(200, 200, 210, 255))
    ok
    // Other arm
    DrawCube(Vector3(gx - gdir * 0.15, armY - 0.04, 0.0),
             0.07, 0.16, 0.07,
             RAYLIBColor(skinR, skinG, skinB, 255))

    // Head (above torso)
    headY = gy + 0.28 + deathOff
    DrawSphere(Vector3(gx, headY, 0.0), 0.09,
               RAYLIBColor(skinR, skinG, skinB, 255))
    // Turban
    DrawCube(Vector3(gx, headY + 0.05, 0.0), 0.18, 0.08, 0.14,
             RAYLIBColor(shirtR + 30, shirtG + 30, shirtB + 30, 255))
    // Eye
    DrawCube(Vector3(gx + gdir * 0.06, headY + 0.01, 0.08),
             0.03, 0.02, 0.01,
             RAYLIBColor(30, 25, 20, 255))

    // Hit flash
    if gstate = GS_HIT
        DrawCube(Vector3(gx, gy, 0.05), 0.5, 0.6, 0.01,
                 RAYLIBColor(255, 100, 100, 80))
    ok

    // Health bar above head
    if guards[idx][4] < guards[idx][5]
        barW = 0.5
        barH = 0.04
        hpFrac = guards[idx][4] * 1.0 / guards[idx][5]
        DrawCube(Vector3(gx, headY + 0.18, 0.1), barW, barH, 0.01,
                 RAYLIBColor(60, 20, 20, 200))
        DrawCube(Vector3(gx - barW/2 + barW*hpFrac/2, headY + 0.18, 0.11),
                 barW * hpFrac, barH, 0.01,
                 RAYLIBColor(220, 40, 40, 200))
    ok

// =============================================================
// Draw Traps
// =============================================================

func pop_drawTraps
    // Spikes and chompers are drawn in pop_drawTile
    // This is for additional visual effects
    return

// =============================================================
// Draw Falling Floors
// =============================================================

func pop_drawFallingFloors
    for i = 1 to len(fallingFloors)
        fx = fallingFloors[i][1]
        fy = flipY(fallingFloors[i][2])
        DrawCube(Vector3(fx, fy, 0), TILE_W * 0.95, 0.18, 0.95,
                 RAYLIBColor(110, 100, 115, 255))
        DrawCube(Vector3(fx, fy + 0.08, 0.48), 0.3, 0.01, 0.003,
                 RAYLIBColor(60, 55, 68, 255))
    next

// =============================================================
// HUD
// =============================================================

func pop_drawHUD
    hudH = 60
    hudY = SCREEN_H - hudH

    // Background
    DrawRectangle(0, hudY, SCREEN_W, hudH, RAYLIBColor(20, 18, 25, 230))
    DrawRectangle(0, hudY, SCREEN_W, 2, RAYLIBColor(100, 90, 120, 255))

    // Health (hearts)
    DrawText("HEALTH", 20, hudY + 8, 14, RAYLIBColor(160, 150, 170, 255))
    for i = 1 to plMaxHealth
        hx = 20 + (i - 1) * 28
        hy = hudY + 28
        if i <= plHealth
            DrawRectangle(hx, hy, 20, 18, RAYLIBColor(200, 40, 40, 255))
            DrawRectangle(hx + 2, hy + 2, 16, 14, RAYLIBColor(230, 60, 60, 255))
        else
            DrawRectangle(hx, hy, 20, 18, RAYLIBColor(60, 30, 30, 255))
        ok
    next

    // Level
    lvTxt = "LEVEL " + levelNum
    DrawText(lvTxt, floor(SCREEN_W/2 - MeasureText(lvTxt, 20)/2), hudY + 8, 20,
             RAYLIBColor(200, 190, 210, 255))

    // Room
    rmTxt = "Room " + currentRoom
    DrawText(rmTxt, floor(SCREEN_W/2 - MeasureText(rmTxt, 14)/2), hudY + 34, 14,
             RAYLIBColor(140, 130, 155, 255))

    // Timer
    minutes = floor(gameTimer / 60)
    seconds = floor(gameTimer % 60)
    timeTxt = "" + minutes + ":"
    if seconds < 10 timeTxt += "0" ok
    timeTxt += "" + seconds
    tCol = RAYLIBColor(200, 200, 200, 255)
    if gameTimer < 300 tCol = RAYLIBColor(255, 80, 50, 255) ok
    DrawText(timeTxt, SCREEN_W - MeasureText(timeTxt, 24) - 20, hudY + 8, 24, tCol)
    DrawText("TIME", SCREEN_W - MeasureText("TIME", 12) - 20, hudY + 36, 12,
             RAYLIBColor(140, 130, 155, 255))

    // Sword indicator
    if plSword
        DrawText("SWORD", SCREEN_W/2 + 120, hudY + 34, 14,
                 RAYLIBColor(200, 200, 100, 255))
    ok

    // Controls hint (brief)
    DrawText("WASD:Move  W:Jump  Q:Grab Ledge  Shift:Careful  Space:Sword  F:Attack  E:Interact",
             10, 10, 12, RAYLIBColor(100, 100, 110, 200))

// =============================================================
// Title Screen
// =============================================================

func pop_drawTitle
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(10, 8, 15, 255))

    // Dungeon background stripes
    for i = 0 to 20
        bx = i * 50
        by = 100 + i * 8
        DrawRectangle(bx, by, 48, SCREEN_H - by, RAYLIBColor(25 + i, 22 + i, 30 + i, 255))
    next

    // Title
    title = "THE SWORD GAME"
    tW = MeasureText(title, 52)
    DrawText(title, floor(SCREEN_W/2 - tW/2) + 3, 103, 52,
             RAYLIBColor(80, 30, 10, 255))
    DrawText(title, floor(SCREEN_W/2 - tW/2), 100, 52,
             RAYLIBColor(230, 180, 80, 255))

    sub = "A Classic Platformer in Ring Language"
    sW = MeasureText(sub, 18)
    DrawText(sub, floor(SCREEN_W/2 - sW/2), 165, 18,
             RAYLIBColor(160, 140, 120, 255))

    // Instructions
    yy = 220
    inst = [
        "Arrow Keys / WASD  -  Move & Jump",
        "Shift (hold)  -  Walk Carefully",
        "Q  -  Grab Ledge / Climb Up",
        "Space  -  Draw / Sheathe Sword",
        "F / Left Click  -  Sword Attack",
        "Down  -  Block (with sword) / Crouch",
        "E  -  Interact (potions, levers)",
        "W at ledge  -  Climb Up (when hanging)",
        "R  -  Restart Level"
    ]
    for i = 1 to len(inst)
        iW = MeasureText(inst[i], 16)
        DrawText(inst[i], floor(SCREEN_W/2 - iW/2), yy + (i-1) * 25, 16,
                 RAYLIBColor(140, 130, 120, 255))
    next

    // Start prompt
    pulse = floor(sin(animTime * 3.0) * 60 + 195)
    start = "Press ENTER or SPACE to Begin"
    startW = MeasureText(start, 22)
    DrawText(start, floor(SCREEN_W/2 - startW/2), 480, 22,
             RAYLIBColor(230, 200, 100, pulse))

    DrawText("Ring + RayLib", 10, SCREEN_H - 25, 14,
             RAYLIBColor(60, 55, 50, 255))

// =============================================================
// Death/Win Overlays
// =============================================================

func pop_drawDeathOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(80, 0, 0, 150))
    dTxt = "YOU HAVE PERISHED"
    dW = MeasureText(dTxt, 42)
    DrawText(dTxt, floor(SCREEN_W/2 - dW/2), SCREEN_H/2 - 40, 42,
             RAYLIBColor(220, 40, 30, 255))
    if deathTimer <= 0
        rTxt = "Press ENTER to Try Again"
        rW = MeasureText(rTxt, 20)
        DrawText(rTxt, floor(SCREEN_W/2 - rW/2), SCREEN_H/2 + 20, 20,
                 RAYLIBColor(200, 180, 160, 255))
    ok

func pop_drawWinOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 40, 0, 150))
    wTxt = "LEVEL COMPLETE!"
    wW = MeasureText(wTxt, 42)
    DrawText(wTxt, floor(SCREEN_W/2 - wW/2), SCREEN_H/2 - 40, 42,
             RAYLIBColor(80, 230, 100, 255))
    nTxt = "Press ENTER to Continue"
    nW = MeasureText(nTxt, 20)
    DrawText(nTxt, floor(SCREEN_W/2 - nW/2), SCREEN_H/2 + 20, 20,
             RAYLIBColor(200, 200, 180, 255))

func pop_drawCompleteScreen
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(10, 5, 20, 255))
    cTxt = "THE HERO HAS ESCAPED THE DUNGEON!"
    cW = MeasureText(cTxt, 36)
    DrawText(cTxt, floor(SCREEN_W/2 - cW/2), SCREEN_H/2 - 60, 36,
             RAYLIBColor(230, 200, 80, 255))
    tTxt = "Congratulations!"
    tW = MeasureText(tTxt, 28)
    DrawText(tTxt, floor(SCREEN_W/2 - tW/2), SCREEN_H/2, 28,
             RAYLIBColor(200, 180, 140, 255))
    eTxt = "Press ENTER"
    eW = MeasureText(eTxt, 18)
    DrawText(eTxt, floor(SCREEN_W/2 - eW/2), SCREEN_H/2 + 50, 18,
             RAYLIBColor(150, 140, 130, 255))

// =============================================================
// Helpers
// =============================================================

func pop_showMsg txt
    msgText = txt
    msgTimer = 2.0

// Convert game Y (row-based, top=0 is row1) to 3D Y (up-positive, floor at bottom)
func flipY gy
    return (ROOM_H * TILE_H) - gy

// Get the floor row the player is on (checks current row and one below)
func pop_getPlayerFloorRow
    row = floor(plY / TILE_H) + 1
    if row >= 1 and row <= ROOM_H
        col = floor(plX / TILE_W) + 1
        if col < 1 col = 1 ok
        if col > ROOM_W col = ROOM_W ok
        t = rooms[currentRoom][row][col]
        if t = T_FLOOR or t = T_SPIKES or t = T_LOOSE or t = T_LEVER or t = T_EXIT_DOOR or t = T_EDGE or t = T_POTION or t = T_CHOMPER or t = T_PLATE or t = T_GATE
            return row
        ok
    ok
    // Check row below
    if row + 1 >= 1 and row + 1 <= ROOM_H
        return row + 1
    ok
    return row

func fabs n
    if n < 0 return -n ok
    return n
