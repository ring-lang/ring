/*
**  Dungeon Crawler 3D - RingRayLib
**  ===================================
**  First-person 3D dungeon exploration!
**  Find keys, unlock doors, fight enemies, reach the exit.
**
**  Controls:
**    W/S             - Move forward / backward
**    A/D             - Strafe left / right
**    Left/Right      - Turn camera
**    Mouse           - Look around
**    Space           - Attack (when enemy nearby)
**    E               - Interact (pick up key, open door, use exit)
**    M               - Toggle minimap size
**    Tab             - Show inventory
**    1-3             - Select level
**    R               - Restart current level
**    ESC             - Exit
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W = 1024
SCREEN_H = 700

PI = 3.14159265
DEG2RAD = PI / 180.0

// Map dimensions
MAP_W = 24
MAP_H = 24

// Tile types
TILE_EMPTY   = 0
TILE_WALL    = 1
TILE_DOOR    = 2
TILE_LDOOR   = 3   // locked door
TILE_EXIT    = 4
TILE_SPAWN   = 5

// Item types
ITEM_KEY     = 1
ITEM_HEALTH  = 2
ITEM_SWORD   = 3

// Entity types
ENT_ENEMY    = 1
ENT_ITEM     = 2

// =============================================================
// Map Data
// =============================================================

map = list(MAP_W * MAP_H)

// Entities: [type, subtype, x, z, alive, hp, damage, speed, animTime]
entities = []

// Items on ground: [type, x, z, collected]
items = []

// =============================================================
// Player
// =============================================================

playerX = 2.5
playerZ = 2.5
playerAngle = 0.0   // radians, 0 = looking along +X
playerHP = 100
playerMaxHP = 100
playerKeys = 0
playerHasSword = false
playerAttackTimer = 0.0
playerHurtTimer = 0.0
playerLevel = 1
playerScore = 0

// Camera
camPitch = 0.0
mouseSens = 0.003
moveSpeed = 3.5
turnSpeed = 2.5
playerRadius = 0.25

// =============================================================
// Game State
// =============================================================

gameState = 1       // 1=playing, 2=won, 3=dead
animTime = 0.0
msgText = ""
msgTimer = 0.0

minimapSize = 1     // 1=small, 2=large, 3=off
showInventory = false

// Attack animation
attackSwing = 0.0

// Mouse tracking (manual delta)
prevMouseX = SCREEN_W / 2
prevMouseY = SCREEN_H / 2

// =============================================================
// Main
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Dungeon Crawler 3D - RingRayLib")
SetTargetFPS(60)
SetExitKey(0)

camera = Camera3D(
    0, 1.0, 0,
    1, 1.0, 0,
    0, 1, 0,
    60,
    CAMERA_PERSPECTIVE
)

dc_loadLevel(1)
HideCursor()

while !WindowShouldClose()
    dc_update()
    BeginDrawing()
        ClearBackground(RAYLIBColor(10, 10, 15, 255))
        dc_draw3D()
        dc_drawHUD()
    EndDrawing()
end

ShowCursor()
CloseWindow()

// =============================================================
// Math Helpers
// =============================================================

func dc_atan2 y, x
    if fabs(x) < 0.0001
        if y > 0 return PI / 2 ok
        if y < 0 return -PI / 2 ok
        return 0
    ok
    a = atan(y / x)
    if x < 0
        if y >= 0 a += PI else a -= PI ok
    ok
    return a

// =============================================================
// Map Helpers
// =============================================================

func dc_doorOrientation x, y
    // Check neighbors to determine corridor direction
    wallE = (dc_getMap(x + 1, y) = TILE_WALL)
    wallW = (dc_getMap(x - 1, y) = TILE_WALL)
    wallN = (dc_getMap(x, y - 1) = TILE_WALL)
    wallS = (dc_getMap(x, y + 1) = TILE_WALL)

    // Walls East+West = corridor runs N-S = door blocks Z = wide on X => return 1
    if wallE and wallW return 1 ok
    // Walls North+South = corridor runs E-W = door blocks X = wide on Z => return 2
    if wallN and wallS return 2 ok
    if wallE or wallW return 1 ok
    return 2

func dc_mapIdx x, y
    if x < 0 or x >= MAP_W or y < 0 or y >= MAP_H return -1 ok
    return y * MAP_W + x + 1

func dc_getMap x, y
    idx = dc_mapIdx(x, y)
    if idx < 1 or idx > MAP_W * MAP_H return TILE_WALL ok
    return map[idx]

func dc_setMap x, y, val
    idx = dc_mapIdx(x, y)
    if idx >= 1 and idx <= MAP_W * MAP_H
        map[idx] = val
    ok

func dc_isSolid x, y
    t = dc_getMap(x, y)
    if t = TILE_WALL return true ok
    if t = TILE_LDOOR return true ok
    if t = TILE_DOOR return true ok
    return false

// =============================================================
// Level Generation
// =============================================================

func dc_loadLevel lvl
    playerLevel = lvl
    gameState = 1
    playerHP = playerMaxHP
    playerKeys = 0
    playerHasSword = false
    playerAttackTimer = 0.0
    playerHurtTimer = 0.0
    entities = []
    items = []
    msgText = ""
    msgTimer = 0.0
    attackSwing = 0.0

    // Fill map with walls
    for i = 1 to MAP_W * MAP_H
        map[i] = TILE_WALL
    next

    // Generate rooms
    if lvl = 1  dc_genLevel1() ok
    if lvl = 2  dc_genLevel2() ok
    if lvl = 3  dc_genLevel3() ok

func dc_carveRoom x1, y1, x2, y2
    for y = y1 to y2
        for x = x1 to x2
            dc_setMap(x, y, TILE_EMPTY)
        next
    next

func dc_carveHCorridor x1, x2, y
    sx = x1  ex = x2
    if x1 > x2  sx = x2  ex = x1  ok
    for x = sx to ex
        dc_setMap(x, y, TILE_EMPTY)
        dc_setMap(x, y + 1, TILE_EMPTY)
    next

func dc_carveVCorridor y1, y2, x
    sy = y1  ey = y2
    if y1 > y2  sy = y2  ey = y1  ok
    for y = sy to ey
        dc_setMap(x, y, TILE_EMPTY)
        dc_setMap(x + 1, y, TILE_EMPTY)
    next

// --- Level 1: Simple dungeon ---
func dc_genLevel1
    // Rooms
    dc_carveRoom(1, 1, 5, 5)       // Start room
    dc_carveRoom(8, 1, 13, 5)      // Room 2
    dc_carveRoom(16, 1, 21, 6)     // Room 3
    dc_carveRoom(1, 8, 6, 13)      // Room 4
    dc_carveRoom(9, 8, 14, 13)     // Room 5 (center)
    dc_carveRoom(17, 8, 22, 13)    // Room 6
    dc_carveRoom(1, 16, 6, 21)     // Room 7
    dc_carveRoom(9, 16, 14, 21)    // Room 8
    dc_carveRoom(17, 16, 22, 21)   // Exit room

    // Corridors
    dc_carveHCorridor(5, 8, 3)
    dc_carveHCorridor(13, 16, 3)
    dc_carveHCorridor(6, 9, 10)
    dc_carveHCorridor(14, 17, 10)
    dc_carveHCorridor(6, 9, 18)
    dc_carveHCorridor(14, 17, 18)
    dc_carveVCorridor(5, 8, 3)
    dc_carveVCorridor(13, 16, 3)
    dc_carveVCorridor(5, 8, 11)
    dc_carveVCorridor(13, 16, 11)
    dc_carveVCorridor(5, 8, 19)
    dc_carveVCorridor(13, 16, 19)

    // Doors
    dc_setMap(6, 3, TILE_DOOR)
    dc_setMap(14, 3, TILE_DOOR)
    dc_setMap(3, 6, TILE_DOOR)

    // Locked door to exit room
    dc_setMap(15, 18, TILE_LDOOR)

    // Player start
    playerX = 3.5  playerZ = 3.5  playerAngle = 0.0

    // Exit
    dc_setMap(20, 19, TILE_EXIT)

    // Keys
    add(items, [ITEM_KEY, 18.5, 3.5, 0])
    add(items, [ITEM_KEY, 3.5, 11.5, 0])

    // Health
    add(items, [ITEM_HEALTH, 11.5, 3.5, 0])
    add(items, [ITEM_HEALTH, 5.5, 19.5, 0])

    // Sword
    add(items, [ITEM_SWORD, 11.5, 10.5, 0])

    // Enemies
    dc_addEnemy(10.5, 3.5, 25, 10, 1.2)
    dc_addEnemy(19.5, 10.5, 30, 12, 1.0)
    dc_addEnemy(3.5, 18.5, 25, 10, 1.5)
    dc_addEnemy(11.5, 18.5, 35, 15, 1.0)

// --- Level 2: Larger maze ---
func dc_genLevel2
    dc_carveRoom(1, 1, 4, 4)
    dc_carveRoom(7, 1, 11, 5)
    dc_carveRoom(14, 1, 19, 4)
    dc_carveRoom(1, 7, 5, 11)
    dc_carveRoom(8, 7, 12, 11)
    dc_carveRoom(15, 7, 20, 11)
    dc_carveRoom(1, 14, 5, 18)
    dc_carveRoom(8, 14, 12, 18)
    dc_carveRoom(15, 14, 22, 20)
    dc_carveRoom(1, 20, 6, 22)
    dc_carveRoom(8, 20, 13, 22)

    dc_carveHCorridor(4, 7, 3)
    dc_carveHCorridor(11, 14, 3)
    dc_carveHCorridor(5, 8, 9)
    dc_carveHCorridor(12, 15, 9)
    dc_carveHCorridor(5, 8, 16)
    dc_carveHCorridor(12, 15, 16)
    dc_carveHCorridor(6, 8, 21)
    dc_carveVCorridor(4, 7, 3)
    dc_carveVCorridor(11, 14, 3)
    dc_carveVCorridor(4, 7, 10)
    dc_carveVCorridor(11, 14, 10)
    dc_carveVCorridor(18, 20, 3)
    dc_carveVCorridor(18, 14, 18)

    dc_setMap(5, 3, TILE_DOOR)
    dc_setMap(12, 9, TILE_DOOR)
    dc_setMap(13, 16, TILE_LDOOR)
    dc_setMap(5, 9, TILE_DOOR)

    playerX = 2.5  playerZ = 2.5  playerAngle = 0.0
    dc_setMap(20, 18, TILE_EXIT)

    add(items, [ITEM_KEY, 16.5, 3.5, 0])
    add(items, [ITEM_KEY, 3.5, 16.5, 0])
    add(items, [ITEM_KEY, 10.5, 21.5, 0])
    add(items, [ITEM_HEALTH, 9.5, 3.5, 0])
    add(items, [ITEM_HEALTH, 17.5, 9.5, 0])
    add(items, [ITEM_HEALTH, 3.5, 21.5, 0])
    add(items, [ITEM_SWORD, 3.5, 9.5, 0])

    dc_addEnemy(9.5, 3.5, 30, 12, 1.3)
    dc_addEnemy(17.5, 3.5, 35, 14, 1.1)
    dc_addEnemy(10.5, 9.5, 30, 12, 1.4)
    dc_addEnemy(17.5, 9.5, 40, 16, 1.0)
    dc_addEnemy(3.5, 16.5, 30, 12, 1.5)
    dc_addEnemy(10.5, 16.5, 45, 18, 1.0)
    dc_addEnemy(18.5, 16.5, 35, 14, 1.2)

// --- Level 3: Dense dungeon ---
func dc_genLevel3
    dc_carveRoom(1, 1, 4, 3)
    dc_carveRoom(7, 1, 10, 4)
    dc_carveRoom(13, 1, 17, 4)
    dc_carveRoom(20, 1, 22, 4)
    dc_carveRoom(1, 6, 5, 10)
    dc_carveRoom(8, 6, 12, 10)
    dc_carveRoom(15, 6, 19, 10)
    dc_carveRoom(1, 13, 5, 17)
    dc_carveRoom(8, 13, 12, 17)
    dc_carveRoom(15, 13, 22, 17)
    dc_carveRoom(1, 20, 5, 22)
    dc_carveRoom(8, 20, 14, 22)
    dc_carveRoom(17, 20, 22, 22)

    dc_carveHCorridor(4, 7, 2)
    dc_carveHCorridor(10, 13, 3)
    dc_carveHCorridor(17, 20, 3)
    dc_carveHCorridor(5, 8, 8)
    dc_carveHCorridor(12, 15, 8)
    dc_carveHCorridor(5, 8, 15)
    dc_carveHCorridor(12, 15, 15)
    dc_carveHCorridor(5, 8, 21)
    dc_carveHCorridor(14, 17, 21)
    dc_carveVCorridor(3, 6, 3)
    dc_carveVCorridor(10, 13, 3)
    dc_carveVCorridor(10, 13, 10)
    dc_carveVCorridor(17, 20, 10)
    dc_carveVCorridor(3, 6, 17)
    dc_carveVCorridor(10, 13, 17)
    dc_carveVCorridor(17, 13, 20)

    dc_setMap(5, 2, TILE_DOOR)
    dc_setMap(11, 3, TILE_LDOOR)
    dc_setMap(13, 8, TILE_DOOR)
    dc_setMap(5, 15, TILE_LDOOR)
    dc_setMap(13, 15, TILE_DOOR)
    dc_setMap(15, 21, TILE_LDOOR)

    playerX = 2.5  playerZ = 2.5  playerAngle = 0.0
    dc_setMap(21, 21, TILE_EXIT)

    add(items, [ITEM_KEY, 21.5, 2.5, 0])
    add(items, [ITEM_KEY, 17.5, 8.5, 0])
    add(items, [ITEM_KEY, 3.5, 15.5, 0])
    add(items, [ITEM_KEY, 11.5, 21.5, 0])
    add(items, [ITEM_HEALTH, 9.5, 2.5, 0])
    add(items, [ITEM_HEALTH, 3.5, 8.5, 0])
    add(items, [ITEM_HEALTH, 10.5, 15.5, 0])
    add(items, [ITEM_HEALTH, 3.5, 21.5, 0])
    add(items, [ITEM_SWORD, 10.5, 8.5, 0])

    dc_addEnemy(8.5, 2.5, 35, 14, 1.4)
    dc_addEnemy(15.5, 2.5, 40, 16, 1.2)
    dc_addEnemy(3.5, 8.5, 30, 12, 1.5)
    dc_addEnemy(10.5, 8.5, 45, 18, 1.1)
    dc_addEnemy(17.5, 8.5, 35, 14, 1.3)
    dc_addEnemy(3.5, 15.5, 40, 16, 1.4)
    dc_addEnemy(10.5, 15.5, 50, 20, 1.0)
    dc_addEnemy(18.5, 15.5, 45, 18, 1.2)
    dc_addEnemy(3.5, 21.5, 35, 14, 1.5)
    dc_addEnemy(11.5, 21.5, 55, 22, 1.0)

func dc_addEnemy x, z, hp, dmg, spd
    add(entities, [ENT_ENEMY, 0, x, z, 1, hp, dmg, spd, 0.0])

// =============================================================
// Update
// =============================================================

func dc_update
    dt = GetFrameTime()
    if dt > 0.05 dt = 0.05 ok
    animTime += dt

    if IsKeyPressed(KEY_ESCAPE)
        ShowCursor()
        CloseWindow()
        shutdown(0)
    ok

    // Level select
    if IsKeyPressed(KEY_ONE) dc_loadLevel(1) ok
    if IsKeyPressed(KEY_TWO) dc_loadLevel(2) ok
    if IsKeyPressed(KEY_THREE) dc_loadLevel(3) ok
    if IsKeyPressed(KEY_R) dc_loadLevel(playerLevel) ok

    // Minimap
    if IsKeyPressed(KEY_M)
        minimapSize++
        if minimapSize > 3 minimapSize = 1 ok
    ok

    // Inventory
    if IsKeyPressed(KEY_TAB) showInventory = !showInventory ok

    // Message timer
    if msgTimer > 0
        msgTimer -= dt
        if msgTimer < 0 msgTimer = 0 ok
    ok

    if gameState != 1 return ok

    // --- Player movement ---
    // Mouse look via centering
    curMX = GetMouseX()
    curMY = GetMouseY()
    centerX = SCREEN_W / 2
    centerY = SCREEN_H / 2
    mouseDX = curMX - centerX
    mouseDY = curMY - centerY
    if fabs(mouseDX) > 1 or fabs(mouseDY) > 1
        playerAngle += mouseDX * mouseSens
        camPitch -= mouseDY * mouseSens
        if camPitch > 1.2 camPitch = 1.2 ok
        if camPitch < -1.2 camPitch = -1.2 ok
    ok
    SetMousePosition(centerX, centerY)

    // Keyboard turn
    if IsKeyDown(KEY_LEFT)  playerAngle -= turnSpeed * dt ok
    if IsKeyDown(KEY_RIGHT) playerAngle += turnSpeed * dt ok
    if IsKeyDown(KEY_Q)     camPitch += turnSpeed * 0.5 * dt ok
    if IsKeyDown(KEY_Z)     camPitch -= turnSpeed * 0.5 * dt ok

    // Movement
    dirX = cos(playerAngle)
    dirZ = sin(playerAngle)
    strafeX = cos(playerAngle + PI/2)
    strafeZ = sin(playerAngle + PI/2)

    moveX = 0.0  moveZ = 0.0
    if IsKeyDown(KEY_W) or IsKeyDown(KEY_UP)
        moveX += dirX * moveSpeed * dt
        moveZ += dirZ * moveSpeed * dt
    ok
    if IsKeyDown(KEY_S) or IsKeyDown(KEY_DOWN)
        moveX -= dirX * moveSpeed * dt
        moveZ -= dirZ * moveSpeed * dt
    ok
    if IsKeyDown(KEY_A)
        moveX -= strafeX * moveSpeed * dt
        moveZ -= strafeZ * moveSpeed * dt
    ok
    if IsKeyDown(KEY_D)
        moveX += strafeX * moveSpeed * dt
        moveZ += strafeZ * moveSpeed * dt
    ok

    // Collision check and apply
    newX = playerX + moveX
    newZ = playerZ + moveZ

    if !dc_isSolid(floor(newX + playerRadius), floor(playerZ)) and
       !dc_isSolid(floor(newX - playerRadius), floor(playerZ))
        playerX = newX
    ok
    if !dc_isSolid(floor(playerX), floor(newZ + playerRadius)) and
       !dc_isSolid(floor(playerX), floor(newZ - playerRadius))
        playerZ = newZ
    ok

    // --- Interaction (E key) ---
    if IsKeyPressed(KEY_E)
        dc_interact()
    ok

    // --- Attack (Space) ---
    if IsKeyPressed(KEY_SPACE) and playerAttackTimer <= 0
        dc_attack()
    ok

    // Attack cooldown
    if playerAttackTimer > 0
        playerAttackTimer -= dt
    ok

    // Attack swing animation
    if attackSwing > 0
        attackSwing -= dt * 5
        if attackSwing < 0 attackSwing = 0 ok
    ok

    // Hurt flash
    if playerHurtTimer > 0
        playerHurtTimer -= dt
    ok

    // --- Enemy AI ---
    dc_updateEnemies(dt)

    // --- Check items auto-pickup ---
    dc_checkItemPickup()

    // Update camera
    lookX = playerX + cos(playerAngle)
    lookZ = playerZ + sin(playerAngle)
    lookY = 1.0 + sin(camPitch)

    camera.position.x = playerX
    camera.position.y = 1.0
    camera.position.z = playerZ
    camera.target.x = lookX
    camera.target.y = lookY
    camera.target.z = lookZ

// =============================================================
// Interact
// =============================================================

func dc_interact
    // Check what's in front of player
    checkDist = 1.2
    cx = floor(playerX + cos(playerAngle) * checkDist)
    cz = floor(playerZ + sin(playerAngle) * checkDist)

    tile = dc_getMap(cx, cz)

    if tile = TILE_LDOOR
        if playerKeys > 0
            playerKeys--
            dc_setMap(cx, cz, TILE_EMPTY)
            dc_showMsg("Door unlocked!")
        else
            dc_showMsg("Locked! Need a key.")
        ok
        return
    ok

    if tile = TILE_DOOR
        dc_setMap(cx, cz, TILE_EMPTY)
        dc_showMsg("Door opened!")
        return
    ok

    if tile = TILE_EXIT
        if playerLevel < 3
            playerScore += 100
            dc_showMsg("Level complete! Score: " + string(playerScore))
            dc_loadLevel(playerLevel + 1)
        else
            playerScore += 200
            gameState = 2
            dc_showMsg("You escaped the dungeon! Score: " + string(playerScore))
        ok
        return
    ok

// =============================================================
// Attack
// =============================================================

func dc_attack
    playerAttackTimer = 0.5
    attackSwing = 1.0

    dmg = 15
    if playerHasSword dmg = 35 ok

    // Check enemies in attack range
    for i = 1 to len(entities)
        if entities[i][1] != ENT_ENEMY loop ok
        if entities[i][5] = 0 loop ok

        dx = entities[i][3] - playerX
        dz = entities[i][4] - playerZ
        dist = sqrt(dx*dx + dz*dz)

        if dist < 2.0
            // Check facing direction
            angleToEnemy = dc_atan2(dz, dx)
            angleDiff = angleToEnemy - playerAngle
            // Normalize
            while angleDiff > PI  angleDiff -= 2*PI end
            while angleDiff < -PI angleDiff += 2*PI end

            if fabs(angleDiff) < 0.8   // ~45 degrees each side
                entities[i][6] -= dmg
                if entities[i][6] <= 0
                    entities[i][5] = 0
                    playerScore += 25
                    dc_showMsg("Enemy defeated! +25")
                ok
            ok
        ok
    next

// =============================================================
// Enemy AI
// =============================================================

func dc_updateEnemies dt
    for i = 1 to len(entities)
        if entities[i][1] != ENT_ENEMY loop ok
        if entities[i][5] = 0 loop ok

        ex = entities[i][3]
        ez = entities[i][4]
        espd = entities[i][8]
        entities[i][9] += dt

        dx = playerX - ex
        dz = playerZ - ez
        dist = sqrt(dx*dx + dz*dz)

        // Chase if player is close enough
        if dist < 8.0 and dist > 1.0
            ndist = dist + 0.001
            mx = (dx / ndist) * espd * dt
            mz = (dz / ndist) * espd * dt

            nx = ex + mx
            nz = ez + mz
            if !dc_isSolid(floor(nx), floor(ez))
                entities[i][3] = nx
            ok
            if !dc_isSolid(floor(ex), floor(nz))
                entities[i][4] = nz
            ok
        ok

        // Attack player if close
        if dist < 1.3
            if entities[i][9] > 1.0     // attack cooldown
                entities[i][9] = 0.0
                playerHP -= entities[i][7]
                playerHurtTimer = 0.3
                if playerHP <= 0
                    playerHP = 0
                    gameState = 3
                    dc_showMsg("You died! Press R to restart.")
                ok
            ok
        ok
    next

// =============================================================
// Item Pickup
// =============================================================

func dc_checkItemPickup
    for i = 1 to len(items)
        if items[i][4] = 1 loop ok
        dx = items[i][2] - playerX
        dz = items[i][3] - playerZ
        dist = sqrt(dx*dx + dz*dz)

        if dist < 0.8
            items[i][4] = 1
            if items[i][1] = ITEM_KEY
                playerKeys++
                dc_showMsg("Key collected! (Total: " + string(playerKeys) + ")")
            ok
            if items[i][1] = ITEM_HEALTH
                playerHP += 30
                if playerHP > playerMaxHP playerHP = playerMaxHP ok
                dc_showMsg("Health restored! HP: " + string(playerHP))
            ok
            if items[i][1] = ITEM_SWORD
                playerHasSword = true
                dc_showMsg("Sword acquired! Damage increased!")
            ok
        ok
    next

func dc_showMsg text
    msgText = text
    msgTimer = 3.0

// =============================================================
// Draw 3D
// =============================================================

func dc_draw3D
    BeginMode3D(camera)

    // Floor
    DrawPlane(Vector3(MAP_W/2, 0, MAP_H/2), Vector2(MAP_W, MAP_H), RAYLIBColor(30, 35, 25, 255))

    // Ceiling
    for cx = 0 to MAP_W - 1
        for cz = 0 to MAP_H - 1
            t = dc_getMap(cx, cz)
            if t != TILE_WALL
                DrawCube(Vector3(cx + 0.5, 2.0, cz + 0.5), 1.0, 0.05, 1.0, RAYLIBColor(20, 22, 28, 255))
            ok
        next
    next

    // Walls, doors, exit
    for wx = 0 to MAP_W - 1
        for wz = 0 to MAP_H - 1
            t = dc_getMap(wx, wz)

            if t = TILE_WALL
                // Distance cull
                ddx = wx + 0.5 - playerX
                ddz = wz + 0.5 - playerZ
                dist = ddx*ddx + ddz*ddz
                if dist < 144    // 12 units
                    DrawCube(Vector3(wx + 0.5, 1.0, wz + 0.5), 1.0, 2.0, 1.0, RAYLIBColor(60, 55, 70, 255))
                    DrawCubeWires(Vector3(wx + 0.5, 1.0, wz + 0.5), 1.0, 2.0, 1.0, RAYLIBColor(40, 35, 50, 255))
                ok
            ok

            if t = TILE_DOOR
                dori = dc_doorOrientation(wx, wz)
                if dori = 1
                    // Corridor runs N-S: door wide on X, thin on Z
                    DrawCube(Vector3(wx + 0.5, 1.0, wz + 0.5), 3.0, 2.0, 0.25, RAYLIBColor(120, 80, 40, 255))
                    DrawCubeWires(Vector3(wx + 0.5, 1.0, wz + 0.5), 3.02, 2.02, 0.27, RAYLIBColor(90, 60, 30, 255))
                else
                    // Corridor runs E-W: door wide on Z, thin on X
                    DrawCube(Vector3(wx + 0.5, 1.0, wz + 0.5), 0.25, 2.0, 3.0, RAYLIBColor(120, 80, 40, 255))
                    DrawCubeWires(Vector3(wx + 0.5, 1.0, wz + 0.5), 0.27, 2.02, 3.02, RAYLIBColor(90, 60, 30, 255))
                ok
                // Handle
                DrawCube(Vector3(wx + 0.5, 0.9, wz + 0.5), 0.1, 0.1, 0.3, RAYLIBColor(180, 160, 60, 255))
            ok

            if t = TILE_LDOOR
                dori = dc_doorOrientation(wx, wz)
                if dori = 1
                    DrawCube(Vector3(wx + 0.5, 1.0, wz + 0.5), 3.0, 2.0, 0.25, RAYLIBColor(140, 40, 40, 255))
                    DrawCubeWires(Vector3(wx + 0.5, 1.0, wz + 0.5), 3.02, 2.02, 0.27, RAYLIBColor(100, 30, 30, 255))
                else
                    DrawCube(Vector3(wx + 0.5, 1.0, wz + 0.5), 0.25, 2.0, 3.0, RAYLIBColor(140, 40, 40, 255))
                    DrawCubeWires(Vector3(wx + 0.5, 1.0, wz + 0.5), 0.27, 2.02, 3.02, RAYLIBColor(100, 30, 30, 255))
                ok
                // Lock icon
                DrawCube(Vector3(wx + 0.5, 0.9, wz + 0.5), 0.2, 0.2, 0.2, RAYLIBColor(220, 180, 50, 255))
            ok

            if t = TILE_EXIT
                dori = dc_doorOrientation(wx, wz)
                pulse = fabs(sin(animTime * 3)) * 0.3 + 0.7
                er = floor(50 * pulse)  eg = floor(200 * pulse)  eb = floor(50 * pulse)
                if dori = 1
                    DrawCube(Vector3(wx + 0.5, 1.0, wz + 0.5), 3.0, 2.0, 0.25, RAYLIBColor(er, eg, eb, 200))
                    DrawCubeWires(Vector3(wx + 0.5, 1.0, wz + 0.5), 3.05, 2.05, 0.3, RAYLIBColor(100, 255, 100, 100))
                else
                    DrawCube(Vector3(wx + 0.5, 1.0, wz + 0.5), 0.25, 2.0, 3.0, RAYLIBColor(er, eg, eb, 200))
                    DrawCubeWires(Vector3(wx + 0.5, 1.0, wz + 0.5), 0.3, 2.05, 3.05, RAYLIBColor(100, 255, 100, 100))
                ok
            ok
        next
    next

    // Items
    for i = 1 to len(items)
        if items[i][4] = 1 loop ok
        ix = items[i][2]
        iz = items[i][3]
        iy = 0.3 + sin(animTime * 2 + i) * 0.1

        if items[i][1] = ITEM_KEY
            DrawCube(Vector3(ix, iy, iz), 0.2, 0.3, 0.1, RAYLIBColor(255, 220, 50, 240))
            DrawCubeWires(Vector3(ix, iy, iz), 0.22, 0.32, 0.12, RAYLIBColor(200, 180, 40, 200))
        ok
        if items[i][1] = ITEM_HEALTH
            DrawSphere(Vector3(ix, iy, iz), 0.15, RAYLIBColor(255, 60, 60, 220))
            DrawSphere(Vector3(ix, iy + 0.05, iz), 0.08, RAYLIBColor(255, 200, 200, 200))
        ok
        if items[i][1] = ITEM_SWORD
            DrawCube(Vector3(ix, iy + 0.2, iz), 0.06, 0.5, 0.06, RAYLIBColor(180, 180, 200, 240))
            DrawCube(Vector3(ix, iy, iz), 0.25, 0.06, 0.06, RAYLIBColor(120, 80, 40, 220))
        ok
    next

    // Enemies
    for i = 1 to len(entities)
        if entities[i][1] != ENT_ENEMY loop ok
        if entities[i][5] = 0 loop ok

        ex = entities[i][3]
        ez = entities[i][4]
        ehp = entities[i][6]

        // Body
        bob = sin(animTime * 4 + i * 2) * 0.05
        DrawCube(Vector3(ex, 0.7 + bob, ez), 0.5, 1.0, 0.5, RAYLIBColor(180, 50, 50, 230))
        DrawCubeWires(Vector3(ex, 0.7 + bob, ez), 0.52, 1.02, 0.52, RAYLIBColor(120, 30, 30, 200))

        // Eyes
        dx = playerX - ex
        dz = playerZ - ez
        edist = sqrt(dx*dx + dz*dz)
        if edist > 0.01
            enx = dx / edist * 0.2
            enz = dz / edist * 0.2
            DrawSphere(Vector3(ex + enx - 0.08, 1.0 + bob, ez + enz), 0.06, RAYLIBColor(255, 255, 0, 255))
            DrawSphere(Vector3(ex + enx + 0.08, 1.0 + bob, ez + enz), 0.06, RAYLIBColor(255, 255, 0, 255))
        ok

        // HP bar above
        hpFrac = ehp * 1.0 / (entities[i][6] + entities[i][7])
        if hpFrac > 1.0 hpFrac = 1.0 ok
        DrawCube(Vector3(ex, 1.5, ez), 0.5, 0.06, 0.06, RAYLIBColor(40, 40, 40, 180))
        DrawCube(Vector3(ex - 0.25 + hpFrac * 0.25, 1.5, ez), hpFrac * 0.5, 0.06, 0.07, RAYLIBColor(255, 50, 50, 220))
    next

    EndMode3D()

    // Attack swing overlay
    if attackSwing > 0
        swX = SCREEN_W / 2 + floor(attackSwing * 200 - 100)
        swY = SCREEN_H / 2 + 50
        if playerHasSword
            DrawRectangle(swX, swY - 80, 8, 100, RAYLIBColor(180, 180, 200, floor(attackSwing * 200)))
            DrawRectangle(swX - 15, swY + 15, 38, 8, RAYLIBColor(120, 80, 40, floor(attackSwing * 200)))
        else
            DrawCircle(swX, swY, 20, RAYLIBColor(200, 170, 130, floor(attackSwing * 180)))
        ok
    ok

// =============================================================
// HUD
// =============================================================

func dc_drawHUD
    // Health bar
    DrawRectangle(10, SCREEN_H - 40, 204, 24, RAYLIBColor(0, 0, 0, 180))
    hpW = floor(playerHP * 200.0 / playerMaxHP)
    hpCol = RAYLIBColor(60, 200, 60, 220)
    if playerHP < 30 hpCol = RAYLIBColor(255, 60, 60, 220) ok
    if playerHP < 60 and playerHP >= 30 hpCol = RAYLIBColor(255, 200, 60, 220) ok
    DrawRectangle(12, SCREEN_H - 38, hpW, 20, hpCol)
    hpTxt = "HP: " + string(playerHP) + "/" + string(playerMaxHP)
    DrawText(hpTxt, 16, SCREEN_H - 36, 16, RAYLIBColor(255, 255, 255, 230))

    // Keys
    keyTxt = "Keys: " + string(playerKeys)
    DrawText(keyTxt, 230, SCREEN_H - 36, 16, RAYLIBColor(255, 220, 50, 230))
    // Key icon
    DrawRectangle(280, SCREEN_H - 36, 12, 16, RAYLIBColor(255, 220, 50, 200))

    // Sword indicator
    if playerHasSword
        DrawText("SWORD", 310, SCREEN_H - 36, 16, RAYLIBColor(180, 180, 220, 230))
    else
        DrawText("Fists", 310, SCREEN_H - 36, 16, RAYLIBColor(150, 130, 110, 180))
    ok

    // Score
    scoreTxt = "Score: " + string(playerScore)
    DrawText(scoreTxt, 400, SCREEN_H - 36, 16, RAYLIBColor(200, 200, 220, 200))

    // Level
    lvlTxt = "Level " + string(playerLevel)
    DrawText(lvlTxt, 530, SCREEN_H - 36, 16, RAYLIBColor(180, 200, 255, 200))

    // Crosshair
    DrawLine(SCREEN_W/2 - 10, SCREEN_H/2, SCREEN_W/2 + 10, SCREEN_H/2, RAYLIBColor(255, 255, 255, 100))
    DrawLine(SCREEN_W/2, SCREEN_H/2 - 10, SCREEN_W/2, SCREEN_H/2 + 10, RAYLIBColor(255, 255, 255, 100))

    // Hurt flash
    if playerHurtTimer > 0
        ha = floor(playerHurtTimer * 400)
        if ha > 120 ha = 120 ok
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(255, 0, 0, ha))
    ok

    // Message
    if msgTimer > 0 and len(msgText) > 0
        mw = MeasureText(msgText, 20) + 30
        ma = 220
        if msgTimer < 0.5 ma = floor(msgTimer * 440) ok
        DrawRectangle((SCREEN_W - mw) / 2, 60, mw, 36, RAYLIBColor(0, 0, 0, ma))
        DrawText(msgText, (SCREEN_W - mw) / 2 + 15, 68, 20, RAYLIBColor(255, 255, 200, ma))
    ok

    // Interaction hint
    checkX = floor(playerX + cos(playerAngle) * 1.2)
    checkZ = floor(playerZ + sin(playerAngle) * 1.2)
    frontTile = dc_getMap(checkX, checkZ)
    if frontTile = TILE_DOOR
        DrawText("[E] Open Door", SCREEN_W/2 - 60, SCREEN_H/2 + 40, 16, RAYLIBColor(200, 200, 200, 180))
    ok
    if frontTile = TILE_LDOOR
        DrawText("[E] Unlock Door (need key)", SCREEN_W/2 - 100, SCREEN_H/2 + 40, 16, RAYLIBColor(255, 200, 50, 200))
    ok
    if frontTile = TILE_EXIT
        DrawText("[E] EXIT DUNGEON", SCREEN_W/2 - 80, SCREEN_H/2 + 40, 18, RAYLIBColor(100, 255, 100, 230))
    ok

    // Minimap
    if minimapSize < 3
        dc_drawMinimap()
    ok

    // Game over / Win
    if gameState = 2
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 150))
        DrawText("DUNGEON CLEARED!", SCREEN_W/2 - 180, SCREEN_H/2 - 40, 36, RAYLIBColor(100, 255, 100, 255))
        DrawText("Final Score: " + string(playerScore), SCREEN_W/2 - 100, SCREEN_H/2 + 20, 22, RAYLIBColor(255, 255, 200, 230))
        DrawText("Press R to restart or 1-3 for level select", SCREEN_W/2 - 180, SCREEN_H/2 + 60, 16, RAYLIBColor(200, 200, 220, 180))
    ok

    if gameState = 3
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(80, 0, 0, 150))
        DrawText("YOU DIED", SCREEN_W/2 - 100, SCREEN_H/2 - 30, 40, RAYLIBColor(255, 60, 60, 255))
        DrawText("Press R to restart", SCREEN_W/2 - 80, SCREEN_H/2 + 30, 18, RAYLIBColor(200, 200, 200, 200))
    ok

    // FPS
    fpsTxt = "" + string(GetFPS()) + " FPS"
    DrawText(fpsTxt, SCREEN_W - 65, 6, 14, RAYLIBColor(100, 200, 100, 150))

    // Controls hint
    DrawText("WASD:Move  Arrows/Mouse:Look  Q/Z:Pitch  Space:Attack  E:Interact  M:Map", 10, 6, 12, RAYLIBColor(150, 150, 170, 100))

// =============================================================
// Minimap
// =============================================================

func dc_drawMinimap
    cellSz = 4
    if minimapSize = 2 cellSz = 7 ok

    mmW = MAP_W * cellSz
    mmH = MAP_H * cellSz
    mmX = SCREEN_W - mmW - 10
    mmY = SCREEN_H - mmH - 50

    DrawRectangle(mmX - 2, mmY - 2, mmW + 4, mmH + 4, RAYLIBColor(0, 0, 0, 180))

    for my = 0 to MAP_H - 1
        for mx = 0 to MAP_W - 1
            t = dc_getMap(mx, my)
            col = RAYLIBColor(0, 0, 0, 0)

            if t = TILE_WALL    col = RAYLIBColor(60, 55, 70, 200) ok
            if t = TILE_EMPTY   col = RAYLIBColor(30, 35, 25, 150) ok
            if t = TILE_DOOR    col = RAYLIBColor(120, 80, 40, 200) ok
            if t = TILE_LDOOR   col = RAYLIBColor(200, 50, 50, 220) ok
            if t = TILE_EXIT    col = RAYLIBColor(50, 200, 50, 220) ok

            DrawRectangle(mmX + mx * cellSz, mmY + my * cellSz, cellSz, cellSz, col)
        next
    next

    // Items
    for i = 1 to len(items)
        if items[i][4] = 1 loop ok
        ix = mmX + floor(items[i][2]) * cellSz
        iy = mmY + floor(items[i][3]) * cellSz
        if items[i][1] = ITEM_KEY
            DrawRectangle(ix, iy, cellSz, cellSz, RAYLIBColor(255, 220, 50, 200))
        ok
        if items[i][1] = ITEM_HEALTH
            DrawRectangle(ix, iy, cellSz, cellSz, RAYLIBColor(255, 80, 80, 200))
        ok
        if items[i][1] = ITEM_SWORD
            DrawRectangle(ix, iy, cellSz, cellSz, RAYLIBColor(180, 180, 220, 200))
        ok
    next

    // Enemies
    for i = 1 to len(entities)
        if entities[i][1] != ENT_ENEMY loop ok
        if entities[i][5] = 0 loop ok
        ex = mmX + floor(entities[i][3]) * cellSz
        ey = mmY + floor(entities[i][4]) * cellSz
        DrawRectangle(ex, ey, cellSz, cellSz, RAYLIBColor(255, 50, 50, 220))
    next

    // Player
    px = mmX + floor(playerX) * cellSz
    py = mmY + floor(playerZ) * cellSz
    DrawRectangle(px, py, cellSz, cellSz, RAYLIBColor(50, 200, 255, 255))

    // Player direction
    dirLen = cellSz * 2
    dx = px + cellSz/2 + floor(cos(playerAngle) * dirLen)
    dy = py + cellSz/2 + floor(sin(playerAngle) * dirLen)
    DrawLine(px + cellSz/2, py + cellSz/2, dx, dy, RAYLIBColor(50, 200, 255, 180))
