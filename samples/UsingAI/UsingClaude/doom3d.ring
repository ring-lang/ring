/*
**  RING DOOM 3D - Wolfenstein/DOOM Style FPS
**  ==========================================
**  A retro first-person shooter using RingRayLib
**
**  Controls:
**    W/S or Up/Down    -  Move forward/backward
**    A/D or Left/Right -  Strafe left/right
**    Mouse             -  Look around
**    Left Click / Space -  Shoot
**    E                 -  Open doors / interact
**    R                 -  Reload (not needed, infinite ammo for pistol)
**    TAB               -  Toggle map
**    ESC               -  Exit
**
**  Features:
**    - First-person 3D movement
**    - Textured walls (procedural blue stone)
**    - Doors that open/close
**    - Multiple enemy types (guards)
**    - Shooting with hit detection
**    - Health, ammo, score tracking
**    - Retro DOOM-style HUD
**    - Multiple levels
**    - Pickups (health, ammo)
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W = 1024
SCREEN_H = 768

// Map tile types
T_EMPTY     = 0
T_WALL1     = 1    // Blue stone wall
T_WALL2     = 2    // Dark blue stone wall
T_WALL3     = 3    // Gray stone wall
T_DOOR      = 4    // Door (opens/closes)
T_DOOR_OPEN = 5    // Open door
T_SECRET    = 6    // Secret wall (push to open)
T_EXIT      = 7    // Level exit trigger

// Game states
ST_TITLE    = 0
ST_PLAYING  = 1
ST_DEAD     = 2
ST_WON      = 3
ST_INTERMISSION = 4

// Enemy states
EN_IDLE     = 0
EN_ALERT    = 1
EN_CHASE    = 2
EN_ATTACK   = 3
EN_PAIN     = 4
EN_DYING    = 5
EN_DEAD     = 6

// Enemy types
ET_GUARD    = 1
ET_OFFICER  = 2
ET_BOSS     = 3

// Pickup types
PK_HEALTH   = 1
PK_AMMO     = 2
PK_KEY_GOLD = 3
PK_KEY_SILVER = 4

// =============================================================
// Map (32x32 grid)
// =============================================================

MAP_W = 32
MAP_H = 32

map = list(MAP_H, MAP_W)

// Player state
pX = 3.5       // Player position
pZ = 3.5
pAngle = 0.0   // Player facing angle (radians)
pHealth = 100
pMaxHealth = 100
pAmmo = 50
pScore = 0
pLives = 3
pAlive = true
pFloor = 1

// Weapon
wCurrent = 1   // 1=pistol, 2=machinegun
wFireTimer = 0.0
wFireRate = 0.3 // seconds between shots
wBobTimer = 0.0
wFlashTimer = 0.0
wShooting = false

// Camera
cam = NULL
camYaw = 0.0
camPitch = 0.0
mouseSens = 0.003
prevMouseX = 0
prevMouseY = 0
centerX = SCREEN_W / 2
centerY = SCREEN_H / 2

// Game
gameState = ST_TITLE
levelNum = 1
maxLevels = 3
deathTimer = 0.0
animTime = 0.0
showMap = true
msgText = ""
msgTimer = 0.0

// Enemies list: [x, z, type, health, state, stateTimer, angle, speed, alertRange, attackRange, damage, maxHealth]
enemies = []

// Pickups list: [x, z, type, active]
pickups = []

// Doors list: [row, col, openAmount, opening, closeTimer]
doors = []

// Projectiles (enemy bullets): [x, y, z, dx, dy, dz, speed, damage, life]
projectiles = []

// Has keys
hasGoldKey = false
hasSilverKey = false

// =============================================================
// Main
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Ring DOOM 3D - RingRayLib FPS")
SetTargetFPS(60)
HideCursor()
SetMousePosition(centerX, centerY)
prevMouseX = centerX
prevMouseY = centerY

cam = Camera3D(
    3.5, 0.5, 3.5,
    4.5, 0.5, 3.5,
    0, 1, 0,
    60,
    0
)

doom_loadLevel(levelNum)

while !WindowShouldClose()
    dt = GetFrameTime()
    if dt > 0.05 dt = 0.05 ok

    animTime += dt

    switch gameState
    on ST_TITLE
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(0)
            gameState = ST_PLAYING
        ok
    on ST_PLAYING
        doom_handleInput(dt)
        doom_updateEnemies(dt)
        doom_updateProjectiles(dt)
        doom_updateDoors(dt)
        doom_updatePickups()
        doom_checkDeath()
    on ST_DEAD
        deathTimer -= dt
        if deathTimer <= 0
            if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
                pLives -= 1
                if pLives <= 0
                    gameState = ST_TITLE
                    pLives = 3
                    pScore = 0
                    levelNum = 1
                else
                    doom_loadLevel(levelNum)
                    gameState = ST_PLAYING
                ok
            ok
        ok
    on ST_WON
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            if levelNum < maxLevels
                levelNum += 1
                doom_loadLevel(levelNum)
                gameState = ST_PLAYING
            else
                gameState = ST_TITLE
                levelNum = 1
                pScore = 0
                pLives = 3
            ok
        ok
    off

    if msgTimer > 0
        msgTimer -= dt
    ok

    BeginDrawing()
        ClearBackground(RAYLIBColor(0, 0, 0, 255))

        if gameState = ST_PLAYING or gameState = ST_DEAD or gameState = ST_WON
            // Draw ceiling and floor as background
            DrawRectangle(0, 0, SCREEN_W, SCREEN_H/2, RAYLIBColor(40, 40, 50, 255))
            DrawRectangleGradientV(0, SCREEN_H/2, SCREEN_W, SCREEN_H/2,
                                   RAYLIBColor(60, 55, 50, 255),
                                   RAYLIBColor(35, 32, 28, 255))

            doom_updateCamera()
            BeginMode3D(cam)
                doom_drawMap()
                doom_drawDoors()
                doom_drawEnemies()
                doom_drawPickups()
                doom_drawProjectiles()
            EndMode3D()

            doom_drawWeapon()
            doom_drawHUD()

            if showMap
                doom_drawMinimap()
            ok

            doom_drawDoorPrompt()
        ok

        if gameState = ST_TITLE
            doom_drawTitle()
        ok

        if gameState = ST_DEAD
            doom_drawDeathScreen()
        ok

        if gameState = ST_WON
            doom_drawWinScreen()
        ok

        if msgTimer > 0
            mA = 255
            if msgTimer < 0.5 mA = floor(msgTimer * 510) ok
            mW = MeasureText(msgText, 24)
            DrawText(msgText, floor(SCREEN_W/2 - mW/2), SCREEN_H/2 + 60, 24,
                     RAYLIBColor(255, 255, 100, mA))
        ok

    EndDrawing()
end

ShowCursor()
CloseWindow()

// =============================================================
// Level Loading
// =============================================================

func doom_loadLevel num
    // Clear
    enemies = []
    pickups = []
    doors = []
    projectiles = []
    hasGoldKey = false
    hasSilverKey = false
    pHealth = 100
    pAmmo = 50
    pAlive = true
    wFireTimer = 0
    wFlashTimer = 0
    wCurrent = 1

    // Init empty map
    for r = 1 to MAP_H
        for c = 1 to MAP_W
            map[r][c] = T_EMPTY
        next
    next

    // Border walls
    for i = 1 to MAP_W
        map[1][i] = T_WALL1
        map[MAP_H][i] = T_WALL1
    next
    for i = 1 to MAP_H
        map[i][1] = T_WALL1
        map[i][MAP_W] = T_WALL1
    next

    if num = 1
        doom_level1()
    ok
    if num = 2
        doom_level2()
    ok
    if num = 3
        doom_level3()
    ok

    // Register doors
    for r = 1 to MAP_H
        for c = 1 to MAP_W
            if map[r][c] = T_DOOR
                add(doors, [r, c, 0.0, false, 0.0])
            ok
        next
    next

func doom_level1
    // Starting room
    for c = 1 to 10
        map[1][c] = T_WALL2
        map[8][c] = T_WALL2
    next
    for r = 1 to 8
        map[r][1] = T_WALL2
        map[r][10] = T_WALL2
    next

    // Corridor east
    for c = 10 to 20
        map[3][c] = T_WALL1
        map[6][c] = T_WALL1
    next
    // Door to corridor
    map[4][10] = T_DOOR
    map[5][10] = T_DOOR

    // Room 2 (east)
    for c = 18 to 28
        map[1][c] = T_WALL3
        map[10][c] = T_WALL3
    next
    for r = 1 to 10
        map[r][18] = T_WALL3
        map[r][28] = T_WALL3
    next
    map[4][18] = T_DOOR
    map[5][18] = T_DOOR

    // South area
    for c = 1 to 16
        map[15][c] = T_WALL1
    next
    for r = 8 to 15
        map[r][16] = T_WALL1
    next
    map[8][5] = T_DOOR
    map[8][6] = T_DOOR

    // Interior walls in room 2
    for r = 3 to 5
        map[r][22] = T_WALL2
    next
    for r = 6 to 8
        map[r][25] = T_WALL2
    next

    // South room
    for c = 1 to 10
        map[20][c] = T_WALL2
    next
    for r = 15 to 20
        map[r][10] = T_WALL2
    next
    map[15][4] = T_DOOR

    // Exit
    map[18][8] = T_EXIT

    // Player start
    pX = 5.5
    pZ = 4.5
    pAngle = 0.0

    // Enemies
    // Guard in corridor
    doom_addEnemy(14.5, 4.5, ET_GUARD)
    doom_addEnemy(16.5, 5.0, ET_GUARD)
    // Guards in room 2
    doom_addEnemy(22.5, 4.5, ET_GUARD)
    doom_addEnemy(25.5, 7.5, ET_OFFICER)
    doom_addEnemy(20.5, 8.5, ET_GUARD)
    // Guards in south
    doom_addEnemy(4.5, 10.5, ET_GUARD)
    doom_addEnemy(7.5, 12.5, ET_GUARD)
    doom_addEnemy(3.5, 17.5, ET_OFFICER)

    // Pickups
    doom_addPickup(8.5, 4.5, PK_AMMO)
    doom_addPickup(14.5, 5.5, PK_HEALTH)
    doom_addPickup(24.5, 2.5, PK_AMMO)
    doom_addPickup(22.5, 8.5, PK_HEALTH)
    doom_addPickup(5.5, 18.5, PK_HEALTH)
    doom_addPickup(2.5, 12.5, PK_AMMO)

func doom_level2
    // Larger maze-like level
    // Outer walls
    for c = 1 to 30
        map[1][c] = T_WALL1
        map[25][c] = T_WALL1
    next
    for r = 1 to 25
        map[r][1] = T_WALL1
        map[r][30] = T_WALL1
    next

    // Room partitions
    for c = 1 to 12
        map[8][c] = T_WALL2
    next
    map[8][6] = T_DOOR

    for r = 1 to 8
        map[r][14] = T_WALL2
    next
    map[4][14] = T_DOOR

    for c = 14 to 30
        map[12][c] = T_WALL3
    next
    map[12][20] = T_DOOR

    for r = 12 to 25
        map[r][15] = T_WALL1
    next
    map[18][15] = T_DOOR

    for c = 1 to 15
        map[18][c] = T_WALL2
    next
    map[18][8] = T_DOOR

    // Interior pillars
    for r = 3 to 5
        map[r][5] = T_WALL3
        map[r][9] = T_WALL3
    next

    // Room 2 pillars
    for r = 3 to 6
        map[r][18] = T_WALL2
        map[r][24] = T_WALL2
    next

    // South section walls
    for c = 20 to 28
        map[18][c] = T_WALL3
    next
    map[18][24] = T_DOOR

    // Exit room
    for c = 22 to 28
        map[22][c] = T_WALL1
    next
    for r = 18 to 22
        map[r][22] = T_WALL1
    next
    map[22][25] = T_EXIT

    pX = 3.5
    pZ = 3.5
    pAngle = 0.0

    // Many enemies
    doom_addEnemy(8.5, 4.5, ET_GUARD)
    doom_addEnemy(3.5, 6.5, ET_GUARD)
    doom_addEnemy(10.5, 5.5, ET_GUARD)
    doom_addEnemy(18.5, 4.5, ET_OFFICER)
    doom_addEnemy(22.5, 3.5, ET_GUARD)
    doom_addEnemy(26.5, 6.5, ET_GUARD)
    doom_addEnemy(20.5, 8.5, ET_OFFICER)
    doom_addEnemy(5.5, 10.5, ET_GUARD)
    doom_addEnemy(10.5, 12.5, ET_GUARD)
    doom_addEnemy(20.5, 14.5, ET_GUARD)
    doom_addEnemy(25.5, 14.5, ET_OFFICER)
    doom_addEnemy(8.5, 20.5, ET_GUARD)
    doom_addEnemy(4.5, 22.5, ET_GUARD)
    doom_addEnemy(12.5, 22.5, ET_OFFICER)
    doom_addEnemy(24.5, 20.5, ET_BOSS)

    // Pickups
    doom_addPickup(6.5, 2.5, PK_AMMO)
    doom_addPickup(12.5, 4.5, PK_HEALTH)
    doom_addPickup(20.5, 2.5, PK_AMMO)
    doom_addPickup(28.5, 4.5, PK_HEALTH)
    doom_addPickup(3.5, 14.5, PK_HEALTH)
    doom_addPickup(8.5, 16.5, PK_AMMO)
    doom_addPickup(18.5, 16.5, PK_HEALTH)
    doom_addPickup(26.5, 16.5, PK_AMMO)
    doom_addPickup(6.5, 22.5, PK_HEALTH)
    doom_addPickup(24.5, 22.5, PK_AMMO)

func doom_level3
    // Boss level - open arena with pillars
    for c = 1 to 28
        map[1][c] = T_WALL3
        map[22][c] = T_WALL3
    next
    for r = 1 to 22
        map[r][1] = T_WALL3
        map[r][28] = T_WALL3
    next

    // Entry corridor
    for c = 1 to 8
        map[8][c] = T_WALL1
        map[12][c] = T_WALL1
    next
    map[8][8] = T_EMPTY
    map[12][8] = T_EMPTY

    // Arena pillars
    for dr = -1 to 1
        for dc = -1 to 1
            map[10 + dr][14 + dc] = T_WALL2
        next
    next
    for dr = -1 to 1
        for dc = -1 to 1
            map[5 + dr][20 + dc] = T_WALL2
        next
    next
    for dr = -1 to 1
        for dc = -1 to 1
            map[16 + dr][20 + dc] = T_WALL2
        next
    next

    // Corner pillars
    map[4][4] = T_WALL3
    map[4][10] = T_WALL3
    map[18][4] = T_WALL3
    map[18][10] = T_WALL3

    // Boss room door
    for r = 8 to 14
        map[r][24] = T_WALL1
    next
    map[10][24] = T_DOOR
    map[11][24] = T_DOOR

    // Exit
    map[11][27] = T_EXIT

    pX = 3.5
    pZ = 10.5
    pAngle = 0.0

    // Arena enemies
    doom_addEnemy(10.5, 4.5, ET_GUARD)
    doom_addEnemy(6.5, 6.5, ET_GUARD)
    doom_addEnemy(14.5, 6.5, ET_GUARD)
    doom_addEnemy(12.5, 8.5, ET_OFFICER)
    doom_addEnemy(8.5, 14.5, ET_OFFICER)
    doom_addEnemy(18.5, 8.5, ET_GUARD)
    doom_addEnemy(18.5, 14.5, ET_GUARD)
    doom_addEnemy(22.5, 4.5, ET_OFFICER)
    doom_addEnemy(22.5, 18.5, ET_OFFICER)
    doom_addEnemy(14.5, 18.5, ET_GUARD)
    doom_addEnemy(6.5, 18.5, ET_GUARD)
    // Boss
    doom_addEnemy(26.5, 10.5, ET_BOSS)
    doom_addEnemy(26.5, 12.5, ET_BOSS)

    // Pickups
    doom_addPickup(4.5, 2.5, PK_HEALTH)
    doom_addPickup(10.5, 2.5, PK_AMMO)
    doom_addPickup(2.5, 14.5, PK_HEALTH)
    doom_addPickup(2.5, 18.5, PK_AMMO)
    doom_addPickup(14.5, 2.5, PK_HEALTH)
    doom_addPickup(14.5, 20.5, PK_AMMO)
    doom_addPickup(20.5, 10.5, PK_HEALTH)
    doom_addPickup(10.5, 16.5, PK_HEALTH)

// =============================================================
// Add enemy helper
// =============================================================

func doom_addEnemy x, z, etype
    hp = 30
    spd = 2.0
    alertR = 10.0
    atkR = 8.0
    dmg = 8

    if etype = ET_OFFICER
        hp = 50
        spd = 2.5
        alertR = 12.0
        atkR = 10.0
        dmg = 12
    ok
    if etype = ET_BOSS
        hp = 150
        spd = 1.8
        alertR = 15.0
        atkR = 12.0
        dmg = 20
    ok

    // Validate position - ensure enemy is not inside a wall
    gr = floor(z) + 1
    gc = floor(x) + 1
    if gr >= 1 and gr <= MAP_H and gc >= 1 and gc <= MAP_W
        t = map[gr][gc]
        if t = T_WALL1 or t = T_WALL2 or t = T_WALL3 or t = T_DOOR or t = T_SECRET
            // Find nearest open tile by searching in expanding radius
            found = false
            for radius = 1 to 5
                for dr = -radius to radius
                    for dc = -radius to radius
                        if fabs(dr) != radius and fabs(dc) != radius loop ok
                        nr = gr + dr
                        nc = gc + dc
                        if nr >= 2 and nr <= MAP_H-1 and nc >= 2 and nc <= MAP_W-1
                            nt = map[nr][nc]
                            if nt = T_EMPTY or nt = T_EXIT
                                x = nc - 0.5
                                z = nr - 0.5
                                found = true
                                exit
                            ok
                        ok
                    next
                    if found exit ok
                next
                if found exit ok
            next
            if !found return ok   // Skip enemy if no valid spot found
        ok
    ok

    // [x, z, type, health, state, stateTimer, angle, speed, alertRange, attackRange, damage, maxHealth, patrolDir, muzzleFlash]
    add(enemies, [x, z, etype, hp, EN_IDLE, 2.0 + random(200)/100.0, random(628)/100.0, spd, alertR, atkR, dmg, hp, random(628)/100.0, 0.0])

func doom_addPickup x, z, ptype
    // Validate position - ensure pickup is not inside a wall
    gr = floor(z) + 1
    gc = floor(x) + 1
    if gr >= 1 and gr <= MAP_H and gc >= 1 and gc <= MAP_W
        t = map[gr][gc]
        if t = T_WALL1 or t = T_WALL2 or t = T_WALL3 or t = T_DOOR or t = T_SECRET
            // Find nearest open tile
            found = false
            for radius = 1 to 5
                for dr = -radius to radius
                    for dc = -radius to radius
                        if fabs(dr) != radius and fabs(dc) != radius loop ok
                        nr = gr + dr
                        nc = gc + dc
                        if nr >= 2 and nr <= MAP_H-1 and nc >= 2 and nc <= MAP_W-1
                            nt = map[nr][nc]
                            if nt = T_EMPTY or nt = T_EXIT
                                x = nc - 0.5
                                z = nr - 0.5
                                found = true
                                exit
                            ok
                        ok
                    next
                    if found exit ok
                next
                if found exit ok
            next
            if !found return ok
        ok
    ok
    add(pickups, [x, z, ptype, true])

// =============================================================
// Input handling
// =============================================================

func doom_handleInput dt
    // Mouse look (manual delta tracking)
    curMX = GetMouseX()
    curMY = GetMouseY()
    mdx = curMX - centerX
    mdy = curMY - centerY
    camYaw += mdx * mouseSens
    camPitch -= mdy * mouseSens
    if camPitch > 0.8 camPitch = 0.8 ok
    if camPitch < -0.8 camPitch = -0.8 ok
    SetMousePosition(centerX, centerY)

    // Movement
    moveSpeed = 4.0 * dt
    strafeSpeed = 3.5 * dt

    forwardX = cos(camYaw)
    forwardZ = sin(camYaw)
    strafeX = cos(camYaw + 3.14159/2)
    strafeZ = sin(camYaw + 3.14159/2)

    dx = 0.0
    dz = 0.0

    if IsKeyDown(KEY_W) or IsKeyDown(KEY_UP)
        dx += forwardX * moveSpeed
        dz += forwardZ * moveSpeed
    ok
    if IsKeyDown(KEY_S) or IsKeyDown(KEY_DOWN)
        dx -= forwardX * moveSpeed
        dz -= forwardZ * moveSpeed
    ok
    if IsKeyDown(KEY_A) or IsKeyDown(KEY_LEFT)
        dx -= strafeX * strafeSpeed
        dz -= strafeZ * strafeSpeed
    ok
    if IsKeyDown(KEY_D) or IsKeyDown(KEY_RIGHT)
        dx += strafeX * strafeSpeed
        dz += strafeZ * strafeSpeed
    ok

    // Collision detection - try X and Z separately
    newX = pX + dx
    newZ = pZ + dz
    colRadius = 0.25

    // Check X movement
    if doom_canMove(newX, pZ, colRadius)
        pX = newX
    ok
    // Check Z movement
    if doom_canMove(pX, newZ, colRadius)
        pZ = newZ
    ok

    // Weapon bob
    if fabs(dx) > 0.001 or fabs(dz) > 0.001
        wBobTimer += dt * 8.0
    else
        wBobTimer = wBobTimer * 0.9
    ok

    // Shooting
    wFireTimer -= dt
    if wFireTimer < 0 wFireTimer = 0 ok

    if (IsMouseButtonDown(0) or IsKeyDown(KEY_SPACE)) and wFireTimer <= 0
        if pAmmo > 0
            pAmmo -= 1
            wFireTimer = wFireRate
            wFlashTimer = 0.08
            wShooting = true
            doom_playerShoot()
        ok
    else
        wShooting = false
    ok

    if wFlashTimer > 0
        wFlashTimer -= dt
    ok

    // Interact (open doors)
    if IsKeyPressed(KEY_E)
        doom_interact()
    ok

    // Toggle map
    if IsKeyPressed(KEY_TAB)
        showMap = !showMap
    ok

// =============================================================
// Collision detection
// =============================================================

func doom_canMove x, z, radius
    // Check 4 corners of bounding box
    for dr = -1 to 1 step 2
        for dc = -1 to 1 step 2
            cx = x + dc * radius
            cz = z + dr * radius
            gr = floor(cz) + 1
            gc = floor(cx) + 1
            if gr < 1 or gr > MAP_H or gc < 1 or gc > MAP_W
                return false
            ok
            t = map[gr][gc]
            if t = T_WALL1 or t = T_WALL2 or t = T_WALL3 or t = T_SECRET
                return false
            ok
            if t = T_DOOR
                // Check if door is open enough
                if !doom_isDoorOpen(gr, gc)
                    return false
                ok
            ok
        next
    next
    return true

func doom_isDoorOpen r, c
    for i = 1 to len(doors)
        if doors[i][1] = r and doors[i][2] = c
            if doors[i][3] > 0.5
                return true
            ok
            return false
        ok
    next
    // Door tile not in doors list - treat as passable
    return true

// =============================================================
// Door interaction
// =============================================================

func doom_interact
    // Open all doors within interaction range
    for i = 1 to len(doors)
        dr = doors[i][1]
        dc = doors[i][2]
        doorX = dc - 0.5
        doorZ = dr - 0.5
        ddx = doorX - pX
        ddz = doorZ - pZ
        dist = sqrt(ddx*ddx + ddz*ddz)
        if dist < 2.5
            doors[i][4] = true  // Start opening
            doors[i][5] = 4.0   // Auto-close timer
        ok
    next

func doom_toggleDoor r, c
    for i = 1 to len(doors)
        if doors[i][1] = r and doors[i][2] = c
            doors[i][4] = true  // Start opening
            doors[i][5] = 3.0   // Auto-close timer
            return
        ok
    next

// =============================================================
// Door update
// =============================================================

func doom_updateDoors dt
    for i = 1 to len(doors)
        if doors[i][4]  // Opening
            doors[i][3] += dt * 2.0
            if doors[i][3] >= 1.0
                doors[i][3] = 1.0
            ok
            // Auto close timer
            if doors[i][3] >= 1.0
                doors[i][5] -= dt
                if doors[i][5] <= 0
                    doors[i][4] = false
                ok
            ok
        else
            // Closing
            if doors[i][3] > 0
                // Check if player is in door tile
                gr = doors[i][1]
                gc = doors[i][2]
                pgr = floor(pZ) + 1
                pgc = floor(pX) + 1
                if pgr = gr and pgc = gc
                    // Don't close on player
                else
                    doors[i][3] -= dt * 1.5
                    if doors[i][3] < 0
                        doors[i][3] = 0
                    ok
                ok
            ok
        ok
    next

// =============================================================
// Shooting
// =============================================================

func doom_playerShoot
    // Ray from player in look direction
    rayX = cos(camYaw)
    rayZ = sin(camYaw)
    rayY = sin(camPitch)

    // Normalize
    rLen = sqrt(rayX*rayX + rayY*rayY + rayZ*rayZ)
    if rLen > 0
        rayX = rayX / rLen
        rayY = rayY / rLen
        rayZ = rayZ / rLen
    ok

    // Check enemies (find closest hit)
    bestDist = 999.0
    bestIdx = 0

    for i = 1 to len(enemies)
        if enemies[i][5] = EN_DEAD or enemies[i][5] = EN_DYING
            loop
        ok
        ex = enemies[i][1]
        ez = enemies[i][2]

        // Vector from player to enemy
        toX = ex - pX
        toZ = ez - pZ
        dist = sqrt(toX*toX + toZ*toZ)

        if dist > 20 loop ok
        if dist < 0.1 loop ok

        // Project onto ray direction (2D check - horizontal plane)
        dot = toX * rayX + toZ * rayZ
        if dot < 0 loop ok  // Behind player

        // Perpendicular distance
        perpX = pX + rayX * dot - ex
        perpZ = pZ + rayZ * dot - ez
        perpDist = sqrt(perpX*perpX + perpZ*perpZ)

        hitRadius = 0.4
        if enemies[i][3] = ET_BOSS hitRadius = 0.6 ok

        if perpDist < hitRadius
            // Line of sight check
            if doom_hasLineOfSight(pX, pZ, ex, ez)
                if dot < bestDist
                    bestDist = dot
                    bestIdx = i
                ok
            ok
        ok
    next

    // Hit!
    if bestIdx > 0
        damage = 15
        if wCurrent = 2 damage = 10 ok

        // Reduce accuracy with distance
        if bestDist > 10
            hitChance = 0.5
            if random(100) > hitChance * 100
                return
            ok
        ok

        enemies[bestIdx][4] -= damage
        enemies[bestIdx][5] = EN_PAIN
        enemies[bestIdx][6] = 0.2

        if enemies[bestIdx][4] <= 0
            enemies[bestIdx][5] = EN_DYING
            enemies[bestIdx][6] = 0.5
            // Score
            et = enemies[bestIdx][3]
            if et = ET_GUARD pScore += 100 ok
            if et = ET_OFFICER pScore += 300 ok
            if et = ET_BOSS pScore += 1000 ok
        ok
    ok

// =============================================================
// Line of sight (simple raycast)
// =============================================================

func doom_hasLineOfSight x1, z1, x2, z2
    dx = x2 - x1
    dz = z2 - z1
    dist = sqrt(dx*dx + dz*dz)
    if dist < 0.1
        return true
    ok

    steps = floor(dist * 4)
    if steps < 2 steps = 2 ok

    for i = 1 to steps
        t = i * 1.0 / steps
        cx = x1 + dx * t
        cz = z1 + dz * t
        gr = floor(cz) + 1
        gc = floor(cx) + 1
        if gr < 1 or gr > MAP_H or gc < 1 or gc > MAP_W
            return false
        ok
        tile = map[gr][gc]
        if tile = T_WALL1 or tile = T_WALL2 or tile = T_WALL3
            return false
        ok
        if tile = T_DOOR
            if !doom_isDoorOpen(gr, gc)
                return false
            ok
        ok
    next
    return true

// =============================================================
// Enemy AI
// =============================================================

func doom_updateEnemies dt
    for i = 1 to len(enemies)
        if enemies[i][5] = EN_DEAD
            loop
        ok

        ex = enemies[i][1]
        ez = enemies[i][2]
        estate = enemies[i][5]

        // Distance to player
        toX = pX - ex
        toZ = pZ - ez
        dist = sqrt(toX*toX + toZ*toZ)

        // Angle to player
        angleToPlayer = myAtan2(toZ, toX)

        // State timer
        enemies[i][6] -= dt

        // Muzzle flash timer (stored in index 13 if exists)
        if len(enemies[i]) >= 14
            if enemies[i][14] > 0
                enemies[i][14] = enemies[i][14] - dt
            ok
        ok

        // State machine
        switch estate
        on EN_DYING
            if enemies[i][6] <= 0
                enemies[i][5] = EN_DEAD
            ok
        on EN_PAIN
            if enemies[i][6] <= 0
                enemies[i][5] = EN_CHASE
                enemies[i][6] = 0.3
            ok
        on EN_IDLE
            // Patrol behavior - wander around the room
            doom_enemyPatrol(i, dt)

            // Check if player is in range and has LOS
            if dist < enemies[i][9]
                if doom_hasLineOfSight(ex, ez, pX, pZ)
                    enemies[i][5] = EN_ALERT
                    enemies[i][6] = 0.4
                ok
            ok
            // Also become alert if player is very close (heard footsteps)
            if dist < 5.0
                enemies[i][5] = EN_ALERT
                enemies[i][6] = 0.3
            ok
        on EN_ALERT
            // Turn toward player quickly
            enemies[i][7] = angleToPlayer
            if enemies[i][6] <= 0
                enemies[i][5] = EN_CHASE
                enemies[i][6] = 0.2
            ok
        on EN_CHASE
            // Smoothly turn toward player
            enemies[i][7] = doom_lerpAngle(enemies[i][7], angleToPlayer, dt * 5.0)

            // Smart movement - chase player with wall avoidance
            if dist > 1.5
                doom_enemyChaseMove(i, dt, angleToPlayer)
            ok

            // Open doors if blocked by one
            // Enemies do not open doors

            // Attack if in range
            if enemies[i][6] <= 0
                if doom_hasLineOfSight(ex, ez, pX, pZ)
                    enemies[i][5] = EN_ATTACK
                    // Attack speed varies by type
                    et = enemies[i][3]
                    if et = ET_GUARD
                        enemies[i][6] = 0.6
                    ok
                    if et = ET_OFFICER
                        enemies[i][6] = 0.4
                    ok
                    if et = ET_BOSS
                        enemies[i][6] = 0.3
                    ok
                else
                    // Keep chasing
                    enemies[i][6] = 0.2
                ok
            ok
        on EN_ATTACK
            enemies[i][7] = angleToPlayer
            // Move while attacking (strafe)
            if dist > 3.0
                doom_enemyChaseMove(i, dt * 0.5, angleToPlayer)
            ok
            if enemies[i][6] <= 0
                // Fire at player!
                if doom_hasLineOfSight(enemies[i][1], enemies[i][2], pX, pZ)
                    doom_enemyShoot(i)
                ok
                // Randomly decide: keep attacking or reposition
                if random(100) < 60 and dist < enemies[i][10]
                    // Keep attacking
                    et = enemies[i][3]
                    if et = ET_GUARD enemies[i][6] = 0.7 + random(40) / 100.0 ok
                    if et = ET_OFFICER enemies[i][6] = 0.5 + random(30) / 100.0 ok
                    if et = ET_BOSS enemies[i][6] = 0.3 + random(20) / 100.0 ok
                else
                    // Go back to chase (reposition)
                    enemies[i][5] = EN_CHASE
                    enemies[i][6] = 0.3 + random(30) / 100.0
                ok
            ok
        off

        // Alert nearby enemies when player shoots
        if wShooting
            if dist < 20
                if enemies[i][5] = EN_IDLE
                    enemies[i][5] = EN_ALERT
                    enemies[i][6] = 0.2
                ok
            ok
        ok

        // If enemy took damage and was idle, become alert
        if estate = EN_PAIN
            if dist < 25
                // Alert all other idle enemies nearby
                for j = 1 to len(enemies)
                    if j = i loop ok
                    if enemies[j][5] = EN_IDLE
                        jdx = enemies[j][1] - ex
                        jdz = enemies[j][2] - ez
                        if sqrt(jdx*jdx + jdz*jdz) < 10
                            enemies[j][5] = EN_ALERT
                            enemies[j][6] = 0.3
                        ok
                    ok
                next
            ok
        ok
    next

// =============================================================
// Enemy Patrol (idle wandering)
// =============================================================

func doom_enemyPatrol i, dt
    // Use patrol angle stored in enemy angle field
    // Change direction periodically
    if enemies[i][6] <= 0
        // Pick new random direction
        enemies[i][7] = (random(628) - 314) / 100.0    // -PI to PI
        enemies[i][6] = 1.5 + random(200) / 100.0      // 1.5 to 3.5 seconds
    ok

    // Move slowly in current direction
    patrolSpeed = enemies[i][8] * 0.3   // 30% of chase speed
    moveX = cos(enemies[i][7]) * patrolSpeed * dt
    moveZ = sin(enemies[i][7]) * patrolSpeed * dt
    newX = enemies[i][1] + moveX
    newZ = enemies[i][2] + moveZ
    if doom_canMoveEnemy(newX, newZ, 0.3, i)
        enemies[i][1] = newX
        enemies[i][2] = newZ
    else
        // Hit a wall - pick new direction immediately
        enemies[i][7] = enemies[i][7] + 1.57 + random(157) / 100.0  // Turn 90-180 degrees
        enemies[i][6] = 0.5
    ok

// =============================================================
// Enemy Chase Movement (with wall sliding)
// =============================================================

func doom_enemyChaseMove i, dt, targetAngle
    ex = enemies[i][1]
    ez = enemies[i][2]
    spd = enemies[i][8] * dt

    // Primary: move directly toward player
    moveX = cos(targetAngle) * spd
    moveZ = sin(targetAngle) * spd
    newX = ex + moveX
    newZ = ez + moveZ

    if doom_canMoveEnemy(newX, newZ, 0.3, i)
        enemies[i][1] = newX
        enemies[i][2] = newZ
        return
    ok

    // Wall sliding: try X only
    if doom_canMoveEnemy(ex + moveX, ez, 0.3, i)
        enemies[i][1] = ex + moveX
        return
    ok

    // Wall sliding: try Z only
    if doom_canMoveEnemy(ex, ez + moveZ, 0.3, i)
        enemies[i][2] = ez + moveZ
        return
    ok

    // Try angled alternatives (wall avoidance)
    for offset = 1 to 3
        ang1 = targetAngle + offset * 0.5
        ang2 = targetAngle - offset * 0.5
        mx1 = cos(ang1) * spd
        mz1 = sin(ang1) * spd
        mx2 = cos(ang2) * spd
        mz2 = sin(ang2) * spd

        if doom_canMoveEnemy(ex + mx1, ez + mz1, 0.3, i)
            enemies[i][1] = ex + mx1
            enemies[i][2] = ez + mz1
            return
        ok
        if doom_canMoveEnemy(ex + mx2, ez + mz2, 0.3, i)
            enemies[i][1] = ex + mx2
            enemies[i][2] = ez + mz2
            return
        ok
    next

// =============================================================
// Smooth angle interpolation
// =============================================================

func doom_lerpAngle current, target, factor
    PI = 3.14159265
    diff = target - current
    // Normalize to -PI..PI
    while diff > PI  diff -= 2 * PI end
    while diff < -PI diff += 2 * PI end
    result = current + diff * factor
    return result

func doom_canMoveEnemy x, z, radius, idx
    // Wall collision
    for dr = -1 to 1 step 2
        for dc = -1 to 1 step 2
            cx = x + dc * radius
            cz = z + dr * radius
            gr = floor(cz) + 1
            gc = floor(cx) + 1
            if gr < 1 or gr > MAP_H or gc < 1 or gc > MAP_W
                return false
            ok
            t = map[gr][gc]
            if t = T_WALL1 or t = T_WALL2 or t = T_WALL3 or t = T_SECRET
                return false
            ok
            if t = T_DOOR
                // Enemies can pass through open doors
                if !doom_isDoorOpen(gr, gc)
                    return false
                ok
            ok
        next
    next
    // Other enemy collision
    for j = 1 to len(enemies)
        if j = idx loop ok
        if enemies[j][5] = EN_DEAD loop ok
        ddx = enemies[j][1] - x
        ddz = enemies[j][2] - z
        if sqrt(ddx*ddx + ddz*ddz) < 0.5
            return false
        ok
    next
    return true

func doom_enemyShoot idx
    ex = enemies[idx][1]
    ez = enemies[idx][2]
    dmg = enemies[idx][11]

    // Set muzzle flash
    if len(enemies[idx]) >= 14
        enemies[idx][14] = 0.15
    ok

    // Hitscan - calculate hit probability based on distance
    toX = pX - ex
    toZ = pZ - ez
    dist = sqrt(toX*toX + toZ*toZ)

    // Accuracy drops with distance
    hitChance = 0.85
    if dist > 4 hitChance = 0.65 ok
    if dist > 8 hitChance = 0.40 ok
    if dist > 12 hitChance = 0.20 ok
    if dist > 18 hitChance = 0.10 ok

    // Officers and bosses are more accurate
    et = enemies[idx][3]
    if et = ET_OFFICER hitChance = hitChance + 0.1 ok
    if et = ET_BOSS hitChance = hitChance + 0.15 ok
    if hitChance > 0.95 hitChance = 0.95 ok

    if random(100) < hitChance * 100
        pHealth -= dmg
        if pHealth < 0 pHealth = 0 ok
        doom_showMsg("Hit! -" + dmg + " HP")
    ok

// =============================================================
// Projectile update
// =============================================================

func doom_updateProjectiles dt
    i = 1
    while i <= len(projectiles)
        projectiles[i][1] += projectiles[i][4] * projectiles[i][7] * dt
        projectiles[i][2] += projectiles[i][5] * projectiles[i][7] * dt
        projectiles[i][3] += projectiles[i][6] * projectiles[i][7] * dt
        projectiles[i][9] -= dt

        // Check wall collision
        gr = floor(projectiles[i][3]) + 1
        gc = floor(projectiles[i][1]) + 1
        if gr < 1 or gr > MAP_H or gc < 1 or gc > MAP_W
            del(projectiles, i)
            loop
        ok
        t = map[gr][gc]
        if t = T_WALL1 or t = T_WALL2 or t = T_WALL3
            del(projectiles, i)
            loop
        ok

        // Check life
        if projectiles[i][9] <= 0
            del(projectiles, i)
            loop
        ok

        i += 1
    end

// =============================================================
// Pickup update
// =============================================================

func doom_updatePickups
    for i = 1 to len(pickups)
        if !pickups[i][4] loop ok
        dx = pickups[i][1] - pX
        dz = pickups[i][2] - pZ
        dist = sqrt(dx*dx + dz*dz)
        if dist < 0.6
            pt = pickups[i][3]
            if pt = PK_HEALTH
                if pHealth < pMaxHealth
                    pHealth += 25
                    if pHealth > pMaxHealth pHealth = pMaxHealth ok
                    pickups[i][4] = false
                    doom_showMsg("Health +25")
                ok
            ok
            if pt = PK_AMMO
                pAmmo += 15
                pickups[i][4] = false
                doom_showMsg("Ammo +15")
            ok
            if pt = PK_KEY_GOLD
                hasGoldKey = true
                pickups[i][4] = false
                doom_showMsg("Gold Key!")
            ok
            if pt = PK_KEY_SILVER
                hasSilverKey = true
                pickups[i][4] = false
                doom_showMsg("Silver Key!")
            ok
        ok
    next

    // Check exit
    gr = floor(pZ) + 1
    gc = floor(pX) + 1
    if gr >= 1 and gr <= MAP_H and gc >= 1 and gc <= MAP_W
        if map[gr][gc] = T_EXIT
            gameState = ST_WON
        ok
    ok

// =============================================================
// Death check
// =============================================================

func doom_checkDeath
    if pHealth <= 0
        pAlive = false
        gameState = ST_DEAD
        deathTimer = 1.5
    ok

// =============================================================
// Camera update
// =============================================================

func doom_updateCamera
    cam.position.x = pX
    cam.position.y = 0.5
    cam.position.z = pZ

    lookX = pX + cos(camYaw)
    lookY = 0.5 + sin(camPitch)
    lookZ = pZ + sin(camYaw)

    cam.target.x = lookX
    cam.target.y = lookY
    cam.target.z = lookZ

// =============================================================
// Draw Map (walls)
// =============================================================

func doom_drawMap
    // Draw floor plane
    DrawCube(Vector3(MAP_W/2.0, -0.01, MAP_H/2.0), MAP_W * 1.0, 0.02, MAP_H * 1.0,
              RAYLIBColor(50, 48, 42, 255))

    for r = 1 to MAP_H
        for c = 1 to MAP_W
            t = map[r][c]
            wx = c - 0.5
            wz = r - 0.5

            // Only draw nearby walls for performance
            ddx = wx - pX
            ddz = wz - pZ
            if ddx*ddx + ddz*ddz > 400 loop ok

            if t = T_WALL1
                doom_drawWallBlock(wx, wz, 1)
            ok
            if t = T_WALL2
                doom_drawWallBlock(wx, wz, 2)
            ok
            if t = T_WALL3
                doom_drawWallBlock(wx, wz, 3)
            ok
            if t = T_EXIT
                // Glowing exit marker
                DrawCube(Vector3(wx, 0.01, wz), 0.95, 0.02, 0.95,
                         RAYLIBColor(50, 200, 50, 200))
                pulse = sin(animTime * 4.0) * 0.15 + 0.5
                DrawCube(Vector3(wx, pulse, wz), 0.3, 0.3, 0.3,
                         RAYLIBColor(0, 255, 0, floor(sin(animTime*3)*60+150)))
            ok
        next
    next

// =============================================================
// Draw wall block with style
// =============================================================

func doom_drawWallBlock wx, wz, style
    if style = 1
        // Blue stone wall
        DrawCube(Vector3(wx, 0.5, wz), 1.0, 1.0, 1.0,
                 RAYLIBColor(30, 40, 140, 255))
        // Brick lines (front z+)
        DrawCube(Vector3(wx, 0.25, wz + 0.505), 0.98, 0.01, 0.005,
                 RAYLIBColor(15, 20, 80, 255))
        DrawCube(Vector3(wx, 0.50, wz + 0.505), 0.98, 0.01, 0.005,
                 RAYLIBColor(15, 20, 80, 255))
        DrawCube(Vector3(wx, 0.75, wz + 0.505), 0.98, 0.01, 0.005,
                 RAYLIBColor(15, 20, 80, 255))
        // Vertical mortar
        DrawCube(Vector3(wx - 0.25, 0.375, wz + 0.505), 0.01, 0.24, 0.005,
                 RAYLIBColor(15, 20, 80, 255))
        DrawCube(Vector3(wx + 0.25, 0.625, wz + 0.505), 0.01, 0.24, 0.005,
                 RAYLIBColor(15, 20, 80, 255))
        // Side (x+)
        DrawCube(Vector3(wx + 0.505, 0.25, wz), 0.005, 0.01, 0.98,
                 RAYLIBColor(15, 20, 80, 255))
        DrawCube(Vector3(wx + 0.505, 0.50, wz), 0.005, 0.01, 0.98,
                 RAYLIBColor(15, 20, 80, 255))
        DrawCube(Vector3(wx + 0.505, 0.75, wz), 0.005, 0.01, 0.98,
                 RAYLIBColor(15, 20, 80, 255))
        // Highlight top
        DrawCube(Vector3(wx, 1.0, wz), 0.98, 0.01, 0.98,
                 RAYLIBColor(40, 55, 170, 200))
    ok

    if style = 2
        // Dark blue wall
        DrawCube(Vector3(wx, 0.5, wz), 1.0, 1.0, 1.0,
                 RAYLIBColor(20, 25, 100, 255))
        // Large brick pattern
        DrawCube(Vector3(wx, 0.33, wz + 0.505), 0.96, 0.01, 0.005,
                 RAYLIBColor(10, 12, 60, 255))
        DrawCube(Vector3(wx, 0.66, wz + 0.505), 0.96, 0.01, 0.005,
                 RAYLIBColor(10, 12, 60, 255))
        DrawCube(Vector3(wx, 0.50, wz + 0.505), 0.01, 0.32, 0.005,
                 RAYLIBColor(10, 12, 60, 255))
        // Side
        DrawCube(Vector3(wx + 0.505, 0.33, wz), 0.005, 0.01, 0.96,
                 RAYLIBColor(10, 12, 60, 255))
        DrawCube(Vector3(wx + 0.505, 0.66, wz), 0.005, 0.01, 0.96,
                 RAYLIBColor(10, 12, 60, 255))
        // Top edge
        DrawCube(Vector3(wx, 1.0, wz), 0.98, 0.01, 0.98,
                 RAYLIBColor(30, 38, 130, 200))
    ok

    if style = 3
        // Gray stone wall
        DrawCube(Vector3(wx, 0.5, wz), 1.0, 1.0, 1.0,
                 RAYLIBColor(80, 78, 85, 255))
        // Stone cracks
        DrawCube(Vector3(wx - 0.15, 0.40, wz + 0.505), 0.30, 0.01, 0.005,
                 RAYLIBColor(50, 48, 55, 255))
        DrawCube(Vector3(wx + 0.20, 0.65, wz + 0.505), 0.01, 0.25, 0.005,
                 RAYLIBColor(50, 48, 55, 255))
        DrawCube(Vector3(wx + 0.505, 0.35, wz + 0.10), 0.005, 0.01, 0.35,
                 RAYLIBColor(50, 48, 55, 255))
        // Top
        DrawCube(Vector3(wx, 1.0, wz), 0.98, 0.01, 0.98,
                 RAYLIBColor(95, 92, 100, 200))
    ok

// =============================================================
// Draw Doors
// =============================================================

func doom_drawDoors
    for i = 1 to len(doors)
        r = doors[i][1]
        c = doors[i][2]
        openAmt = doors[i][3]
        wx = c - 0.5
        wz = r - 0.5

        ddx = wx - pX
        ddz = wz - pZ
        if ddx*ddx + ddz*ddz > 400 loop ok

        // Detect door orientation by checking neighboring walls
        // If walls are to the left/right (east/west) -> door spans X, thin on Z (horizontal door)
        // If walls are above/below (north/south) -> door spans Z, thin on X (vertical door)
        wallEast = false
        wallWest = false
        wallNorth = false
        wallSouth = false
        if c+1 <= MAP_W
            tw = map[r][c+1]
            if tw = T_WALL1 or tw = T_WALL2 or tw = T_WALL3 wallEast = true ok
        ok
        if c-1 >= 1
            tw = map[r][c-1]
            if tw = T_WALL1 or tw = T_WALL2 or tw = T_WALL3 wallWest = true ok
        ok
        if r-1 >= 1
            tw = map[r-1][c]
            if tw = T_WALL1 or tw = T_WALL2 or tw = T_WALL3 wallNorth = true ok
        ok
        if r+1 <= MAP_H
            tw = map[r+1][c]
            if tw = T_WALL1 or tw = T_WALL2 or tw = T_WALL3 wallSouth = true ok
        ok

        // Vertical door (in a wall running north-south, walls to N/S)
        isVertical = (wallNorth or wallSouth) and (!wallEast and !wallWest)

        slideOffset = openAmt * 0.9

        if isVertical
            // Door panel slides along Z
            DrawCube(Vector3(wx, 0.5, wz - slideOffset), 0.12, 1.0, 1.0 - openAmt * 0.9,
                     RAYLIBColor(40, 140, 130, 255))
            // Door frame (top + two side pillars along Z)
            DrawCube(Vector3(wx, 0.98, wz), 0.18, 0.04, 1.0,
                     RAYLIBColor(80, 80, 90, 255))
            DrawCube(Vector3(wx, 0.5, wz - 0.48), 0.18, 1.0, 0.04,
                     RAYLIBColor(80, 80, 90, 255))
            DrawCube(Vector3(wx, 0.5, wz + 0.48), 0.18, 1.0, 0.04,
                     RAYLIBColor(80, 80, 90, 255))
            // Details
            if openAmt < 0.8
                // Lock/handle
                DrawCube(Vector3(wx + 0.065, 0.5, wz + 0.15 - slideOffset),
                         0.005, 0.08, 0.08,
                         RAYLIBColor(200, 180, 50, 255))
                // Keyhole
                DrawCube(Vector3(wx + 0.07, 0.48, wz + 0.15 - slideOffset),
                         0.005, 0.04, 0.02,
                         RAYLIBColor(30, 25, 15, 255))
                // Panel lines
                DrawCube(Vector3(wx + 0.065, 0.3, wz - slideOffset), 0.005, 0.01, 0.8,
                         RAYLIBColor(25, 100, 95, 255))
                DrawCube(Vector3(wx + 0.065, 0.7, wz - slideOffset), 0.005, 0.01, 0.8,
                         RAYLIBColor(25, 100, 95, 255))
            ok
        else
            // Horizontal door (default) - panel slides along X
            DrawCube(Vector3(wx - slideOffset, 0.5, wz), 1.0 - openAmt * 0.9, 1.0, 0.12,
                     RAYLIBColor(40, 140, 130, 255))
            // Door frame (top + two side pillars along X)
            DrawCube(Vector3(wx, 0.98, wz), 1.0, 0.04, 0.18,
                     RAYLIBColor(80, 80, 90, 255))
            DrawCube(Vector3(wx - 0.48, 0.5, wz), 0.04, 1.0, 0.18,
                     RAYLIBColor(80, 80, 90, 255))
            DrawCube(Vector3(wx + 0.48, 0.5, wz), 0.04, 1.0, 0.18,
                     RAYLIBColor(80, 80, 90, 255))
            // Details
            if openAmt < 0.8
                // Lock/handle
                DrawCube(Vector3(wx + 0.15 - slideOffset, 0.5, wz + 0.065),
                         0.08, 0.08, 0.005,
                         RAYLIBColor(200, 180, 50, 255))
                // Keyhole
                DrawCube(Vector3(wx + 0.15 - slideOffset, 0.48, wz + 0.07),
                         0.02, 0.04, 0.005,
                         RAYLIBColor(30, 25, 15, 255))
                // Panel lines
                DrawCube(Vector3(wx - slideOffset, 0.3, wz + 0.065), 0.8, 0.01, 0.005,
                         RAYLIBColor(25, 100, 95, 255))
                DrawCube(Vector3(wx - slideOffset, 0.7, wz + 0.065), 0.8, 0.01, 0.005,
                         RAYLIBColor(25, 100, 95, 255))
            ok
        ok
    next

// =============================================================
// Draw Enemies
// =============================================================

func doom_drawEnemies
    for i = 1 to len(enemies)
        estate = enemies[i][5]
        if estate = EN_DEAD loop ok

        ex = enemies[i][1]
        ez = enemies[i][2]
        et = enemies[i][3]

        // Distance cull
        ddx = ex - pX
        ddz = ez - pZ
        if ddx*ddx + ddz*ddz > 400 loop ok

        if estate = EN_DYING
            // Death animation - collapse
            deathProgress = 1.0 - (enemies[i][6] / 0.5)
            if deathProgress > 1 deathProgress = 1 ok
            doom_drawEnemyModel(ex, ez, et, enemies[i][7], deathProgress, true)
        else
            flash = false
            if estate = EN_PAIN flash = true ok
            if estate = EN_ATTACK and enemies[i][6] > 0.6 flash = true ok
            doom_drawEnemyModel(ex, ez, et, enemies[i][7], 0, flash)
        ok

        // Muzzle flash from enemy weapon
        if len(enemies[i]) >= 14
            if enemies[i][14] > 0
                gunDx = cos(enemies[i][7])
                gunDz = sin(enemies[i][7])
                mfX = ex + gunDx * 0.35
                mfZ = ez + gunDz * 0.35
                mfY = 0.30
                flashAlpha = floor(enemies[i][14] / 0.15 * 255)
                if flashAlpha > 255 flashAlpha = 255 ok
                DrawSphere(Vector3(mfX, mfY, mfZ), 0.08,
                           RAYLIBColor(255, 255, 100, flashAlpha))
                DrawSphere(Vector3(mfX, mfY, mfZ), 0.15,
                           RAYLIBColor(255, 150, 30, floor(flashAlpha * 0.5)))
            ok
        ok
    next

func doom_drawEnemyModel ex, ez, etype, angle, deathProg, flash
    hy = 0.0

    // Colors based on type
    bodyR = 100  bodyG = 100  bodyB = 100
    headR = 220  headG = 180  headB = 140

    if etype = ET_GUARD
        bodyR = 110  bodyG = 95  bodyB = 70    // Brown uniform
    ok
    if etype = ET_OFFICER
        bodyR = 180  bodyG = 180  bodyB = 185  // White uniform
    ok
    if etype = ET_BOSS
        bodyR = 60   bodyG = 60   bodyB = 65   // Dark armor
    ok

    if flash
        bodyR = 255  bodyG = 200  bodyB = 200
        headR = 255  headG = 220  headB = 220
    ok

    // Death collapse
    collapseY = deathProg * 0.4
    scaleY = 1.0 - deathProg * 0.7
    if scaleY < 0.1 scaleY = 0.1 ok

    bdyH = 0.35 * scaleY
    bdyY = hy + 0.10 + bdyH/2 - collapseY

    // Shadow
    DrawCylinder(Vector3(ex, 0.005, ez), 0.25, 0.28, 0.003, 8,
                 RAYLIBColor(0, 0, 0, 40))

    // Legs
    if deathProg < 0.5
        fdx = cos(angle)
        fdz = sin(angle)
        DrawCylinder(Vector3(ex - fdz * 0.08, hy, ez + fdx * 0.08),
                     0.05, 0.04, 0.18 * scaleY, 6,
                     RAYLIBColor(bodyR-20, bodyG-20, bodyB-20, 255))
        DrawCylinder(Vector3(ex + fdz * 0.08, hy, ez - fdx * 0.08),
                     0.05, 0.04, 0.18 * scaleY, 6,
                     RAYLIBColor(bodyR-20, bodyG-20, bodyB-20, 255))
    ok

    // Body
    DrawCube(Vector3(ex, bdyY, ez), 0.30, bdyH, 0.22,
             RAYLIBColor(bodyR, bodyG, bodyB, 255))

    // Belt
    if deathProg < 0.3
        DrawCube(Vector3(ex, hy + 0.18 - collapseY, ez), 0.32, 0.03, 0.24,
                 RAYLIBColor(bodyR-40, bodyG-40, bodyB-40, 255))
    ok

    // Head
    if deathProg < 0.8
        headY = hy + 0.42 * scaleY - collapseY
        if headY < 0.05 headY = 0.05 ok
        headSz = 0.10 * (1.0 - deathProg * 0.3)
        DrawSphere(Vector3(ex, headY, ez), headSz,
                   RAYLIBColor(headR, headG, headB, 255))

        // Helmet/hat
        if etype = ET_GUARD
            DrawCube(Vector3(ex, headY + 0.06, ez), 0.16, 0.04, 0.16,
                     RAYLIBColor(55, 80, 55, 255))
        ok
        if etype = ET_OFFICER
            DrawCube(Vector3(ex, headY + 0.06, ez), 0.14, 0.06, 0.14,
                     RAYLIBColor(40, 40, 45, 255))
            DrawCube(Vector3(ex + cos(angle)*0.06, headY + 0.04, ez + sin(angle)*0.06),
                     0.16, 0.02, 0.16,
                     RAYLIBColor(40, 40, 45, 255))
        ok
        if etype = ET_BOSS
            DrawCube(Vector3(ex, headY + 0.05, ez), 0.18, 0.08, 0.18,
                     RAYLIBColor(40, 40, 42, 255))
            // Red visor
            DrawCube(Vector3(ex + cos(angle)*0.09, headY, ez + sin(angle)*0.09),
                     0.14, 0.03, 0.04,
                     RAYLIBColor(255, 30, 20, 200))
        ok
    ok

    // Arms / weapon
    if deathProg < 0.4
        armDx = cos(angle)
        armDz = sin(angle)
        // Right arm with gun
        DrawCylinder(Vector3(ex + armDx * 0.18, hy + 0.28 * scaleY - collapseY, ez + armDz * 0.18),
                     0.04, 0.03, 0.14 * scaleY, 5,
                     RAYLIBColor(headR, headG, headB, 255))
        // Gun
        DrawCube(Vector3(ex + armDx * 0.28, hy + 0.28 * scaleY - collapseY, ez + armDz * 0.28),
                 0.06, 0.04, 0.04,
                 RAYLIBColor(35, 35, 38, 255))
    ok

    // Boss extra - armor plates
    if etype = ET_BOSS and deathProg < 0.3
        DrawCube(Vector3(ex, bdyY + 0.05, ez), 0.34, 0.12, 0.08,
                 RAYLIBColor(50, 50, 55, 255))
        // Shoulder pads
        DrawSphere(Vector3(ex - 0.18, bdyY + 0.10, ez), 0.06,
                   RAYLIBColor(45, 45, 50, 255))
        DrawSphere(Vector3(ex + 0.18, bdyY + 0.10, ez), 0.06,
                   RAYLIBColor(45, 45, 50, 255))
    ok

// =============================================================
// Draw Pickups
// =============================================================

func doom_drawPickups
    for i = 1 to len(pickups)
        if !pickups[i][4] loop ok
        px_ = pickups[i][1]
        pz_ = pickups[i][2]
        pt = pickups[i][3]

        ddx = px_ - pX
        ddz = pz_ - pZ
        if ddx*ddx + ddz*ddz > 225 loop ok

        bob = sin(animTime * 3.0 + px_ + pz_) * 0.05

        if pt = PK_HEALTH
            // Health pack - white box with red cross
            DrawCube(Vector3(px_, 0.12 + bob, pz_), 0.22, 0.22, 0.22,
                     RAYLIBColor(220, 220, 220, 255))
            DrawCube(Vector3(px_, 0.12 + bob, pz_ + 0.115), 0.14, 0.06, 0.005,
                     RAYLIBColor(200, 30, 30, 255))
            DrawCube(Vector3(px_, 0.12 + bob, pz_ + 0.115), 0.06, 0.14, 0.005,
                     RAYLIBColor(200, 30, 30, 255))
        ok

        if pt = PK_AMMO
            // Ammo box - olive green
            DrawCube(Vector3(px_, 0.10 + bob, pz_), 0.24, 0.16, 0.16,
                     RAYLIBColor(70, 85, 40, 255))
            DrawCube(Vector3(px_, 0.18 + bob, pz_), 0.22, 0.02, 0.14,
                     RAYLIBColor(85, 100, 50, 255))
            // Bullet shapes on top
            DrawCylinder(Vector3(px_ - 0.05, 0.18 + bob, pz_), 0.02, 0.02, 0.06, 6,
                         RAYLIBColor(200, 180, 50, 255))
            DrawCylinder(Vector3(px_ + 0.05, 0.18 + bob, pz_), 0.02, 0.02, 0.06, 6,
                         RAYLIBColor(200, 180, 50, 255))
        ok

        if pt = PK_KEY_GOLD
            DrawCylinder(Vector3(px_, 0.18 + bob, pz_), 0.08, 0.08, 0.03, 8,
                         RAYLIBColor(255, 215, 50, 255))
            DrawCube(Vector3(px_, 0.10 + bob, pz_), 0.03, 0.12, 0.03,
                     RAYLIBColor(235, 195, 40, 255))
            // Glow
            DrawSphere(Vector3(px_, 0.15 + bob, pz_), 0.18,
                       RAYLIBColor(255, 230, 50, floor(sin(animTime*3)*30+40)))
        ok
    next

// =============================================================
// Draw Projectiles
// =============================================================

func doom_drawProjectiles
    for i = 1 to len(projectiles)
        DrawSphere(Vector3(projectiles[i][1], projectiles[i][2], projectiles[i][3]),
                   0.05, RAYLIBColor(255, 200, 50, 255))
        DrawSphere(Vector3(projectiles[i][1], projectiles[i][2], projectiles[i][3]),
                   0.10, RAYLIBColor(255, 150, 30, 100))
    next

// =============================================================
// Draw Weapon (2D overlay)
// =============================================================

func doom_drawWeapon
    // Weapon bob
    bobX = sin(wBobTimer) * 8
    bobY = fabs(cos(wBobTimer)) * 6

    // Base position
    wpnX = SCREEN_W / 2 - 50 + floor(bobX)
    wpnY = SCREEN_H - 200 + floor(bobY)

    // Muzzle flash
    if wFlashTimer > 0
        flashSize = floor(40 + wFlashTimer * 200)
        fX = wpnX + 50
        fY = wpnY - 20
        fA1 = floor(wFlashTimer * 2000)
        if fA1 > 255 fA1 = 255 ok
        fA2 = floor(wFlashTimer * 3000)
        if fA2 > 255 fA2 = 255 ok
        DrawRectangle(fX - flashSize, fY - flashSize, flashSize*2, flashSize*2,
                      RAYLIBColor(255, 255, 150, fA1))
        fs2 = floor(flashSize * 0.6)
        DrawRectangle(fX - fs2, fY - fs2, fs2*2, fs2*2,
                      RAYLIBColor(255, 200, 50, fA2))
    ok

    // Gun barrel
    DrawRectangle(wpnX + 42, wpnY - 30, 16, 40, RAYLIBColor(55, 55, 60, 255))
    DrawRectangle(wpnX + 44, wpnY - 28, 12, 36, RAYLIBColor(45, 45, 50, 255))

    // Gun body / slide
    DrawRectangle(wpnX + 25, wpnY + 8, 60, 30, RAYLIBColor(50, 50, 55, 255))
    DrawRectangle(wpnX + 27, wpnY + 10, 56, 26, RAYLIBColor(60, 60, 65, 255))
    // Slide serrations
    DrawRectangle(wpnX + 30, wpnY + 12, 2, 6, RAYLIBColor(40, 40, 45, 255))
    DrawRectangle(wpnX + 34, wpnY + 12, 2, 6, RAYLIBColor(40, 40, 45, 255))
    DrawRectangle(wpnX + 38, wpnY + 12, 2, 6, RAYLIBColor(40, 40, 45, 255))

    // Grip
    DrawRectangle(wpnX + 35, wpnY + 36, 30, 50, RAYLIBColor(45, 42, 38, 255))
    DrawRectangle(wpnX + 37, wpnY + 38, 26, 46, RAYLIBColor(55, 50, 42, 255))
    // Grip texture
    for gy = 0 to 8
        DrawRectangle(wpnX + 39, wpnY + 42 + gy * 5, 22, 1,
                      RAYLIBColor(40, 38, 32, 255))
    next

    // Trigger guard
    DrawRectangle(wpnX + 30, wpnY + 34, 12, 3, RAYLIBColor(50, 50, 55, 255))
    DrawRectangle(wpnX + 32, wpnY + 37, 2, 10, RAYLIBColor(50, 50, 55, 255))

    // Hand
    DrawRectangle(wpnX + 30, wpnY + 60, 45, 35, RAYLIBColor(220, 175, 130, 255))
    DrawRectangle(wpnX + 30, wpnY + 55, 40, 12, RAYLIBColor(215, 170, 125, 255))
    // Fingers wrapping around grip
    DrawRectangle(wpnX + 28, wpnY + 42, 8, 20, RAYLIBColor(218, 172, 128, 255))
    DrawRectangle(wpnX + 65, wpnY + 45, 10, 15, RAYLIBColor(218, 172, 128, 255))
    // Thumb
    DrawRectangle(wpnX + 66, wpnY + 30, 8, 18, RAYLIBColor(222, 178, 132, 255))

    // Wrist / sleeve
    DrawRectangle(wpnX + 15, wpnY + 80, 65, 130, RAYLIBColor(215, 170, 125, 255))

    // Crosshair
    cX = SCREEN_W / 2
    cY = SCREEN_H / 2
    DrawRectangle(cX - 10, cY, 6, 2, RAYLIBColor(0, 255, 0, 200))
    DrawRectangle(cX + 4, cY, 6, 2, RAYLIBColor(0, 255, 0, 200))
    DrawRectangle(cX, cY - 10, 2, 6, RAYLIBColor(0, 255, 0, 200))
    DrawRectangle(cX, cY + 4, 2, 6, RAYLIBColor(0, 255, 0, 200))

// =============================================================
// HUD (DOOM style)
// =============================================================

func doom_drawHUD
    hudH = 80
    hudY = SCREEN_H - hudH

    // Background bar
    DrawRectangle(0, hudY, SCREEN_W, hudH, RAYLIBColor(60, 60, 65, 255))
    DrawRectangle(0, hudY, SCREEN_W, 3, RAYLIBColor(100, 100, 110, 255))

    // Section dividers
    secW = SCREEN_W / 5

    // FLOOR
    DrawRectangle(2, hudY + 4, secW - 4, hudH - 8, RAYLIBColor(25, 25, 120, 255))
    DrawRectangle(4, hudY + 6, secW - 8, hudH - 12, RAYLIBColor(15, 15, 90, 255))
    DrawText("FLOOR", floor(secW/2 - MeasureText("FLOOR", 14)/2), hudY + 8, 14,
             RAYLIBColor(200, 200, 200, 255))
    flTxt = "" + levelNum
    DrawText(flTxt, floor(secW/2 - MeasureText(flTxt, 36)/2), hudY + 28, 36,
             RAYLIBColor(255, 255, 255, 255))

    // SCORE
    DrawRectangle(secW + 2, hudY + 4, secW - 4, hudH - 8, RAYLIBColor(25, 25, 120, 255))
    DrawRectangle(secW + 4, hudY + 6, secW - 8, hudH - 12, RAYLIBColor(15, 15, 90, 255))
    DrawText("SCORE", floor(secW*1.5 - MeasureText("SCORE", 14)/2), hudY + 8, 14,
             RAYLIBColor(200, 200, 200, 255))
    scTxt = "" + pScore
    DrawText(scTxt, floor(secW*1.5 - MeasureText(scTxt, 28)/2), hudY + 30, 28,
             RAYLIBColor(255, 255, 255, 255))

    // LIVES (center with face)
    DrawRectangle(secW*2 + 2, hudY + 4, secW - 4, hudH - 8, RAYLIBColor(25, 25, 120, 255))
    DrawRectangle(secW*2 + 4, hudY + 6, secW - 8, hudH - 12, RAYLIBColor(15, 15, 90, 255))
    DrawText("LIVES", floor(secW*2.5 - MeasureText("LIVES", 14)/2), hudY + 8, 14,
             RAYLIBColor(200, 200, 200, 255))
    // Face (like DOOM guy)
    faceX = floor(secW * 2.5)
    faceY = hudY + 48
    // Face background
    DrawRectangle(faceX - 18, faceY - 14, 36, 30, RAYLIBColor(200, 160, 120, 255))
    // Eyes
    eyeState = floor(animTime * 2) % 3
    eyeOff = 0
    if eyeState = 0 eyeOff = -2 ok
    if eyeState = 2 eyeOff = 2 ok
    DrawRectangle(faceX - 10 + eyeOff, faceY - 8, 6, 6, RAYLIBColor(255, 255, 255, 255))
    DrawRectangle(faceX + 4 + eyeOff, faceY - 8, 6, 6, RAYLIBColor(255, 255, 255, 255))
    DrawRectangle(faceX - 8 + eyeOff, faceY - 6, 3, 3, RAYLIBColor(20, 20, 20, 255))
    DrawRectangle(faceX + 6 + eyeOff, faceY - 6, 3, 3, RAYLIBColor(20, 20, 20, 255))
    // Mouth
    DrawRectangle(faceX - 5, faceY + 4, 10, 4, RAYLIBColor(160, 80, 60, 255))
    // Hair
    DrawRectangle(faceX - 18, faceY - 18, 36, 6, RAYLIBColor(80, 55, 30, 255))
    // Damage indicator
    if pHealth < 60
        DrawRectangle(faceX + 10, faceY - 2, 5, 8, RAYLIBColor(180, 30, 20, 255))
    ok
    if pHealth < 30
        DrawRectangle(faceX - 14, faceY + 2, 4, 6, RAYLIBColor(180, 30, 20, 255))
    ok
    // Lives count
    lvTxt = "" + pLives
    DrawText(lvTxt, faceX + 22, faceY - 4, 20, RAYLIBColor(255, 255, 255, 255))

    // HEALTH
    DrawRectangle(secW*3 + 2, hudY + 4, secW - 4, hudH - 8, RAYLIBColor(25, 25, 120, 255))
    DrawRectangle(secW*3 + 4, hudY + 6, secW - 8, hudH - 12, RAYLIBColor(15, 15, 90, 255))
    DrawText("HEALTH", floor(secW*3.5 - MeasureText("HEALTH", 14)/2), hudY + 8, 14,
             RAYLIBColor(200, 200, 200, 255))
    hpTxt = "" + pHealth + "%"
    hpCol = RAYLIBColor(255, 255, 255, 255)
    if pHealth < 30
        hpCol = RAYLIBColor(255, 50, 50, 255)
    ok
    DrawText(hpTxt, floor(secW*3.5 - MeasureText(hpTxt, 32)/2), hudY + 28, 32, hpCol)

    // AMMO
    DrawRectangle(secW*4 + 2, hudY + 4, secW - 4, hudH - 8, RAYLIBColor(25, 25, 120, 255))
    DrawRectangle(secW*4 + 4, hudY + 6, secW - 8, hudH - 12, RAYLIBColor(15, 15, 90, 255))
    DrawText("AMMO", floor(secW*4.5 - MeasureText("AMMO", 14)/2), hudY + 8, 14,
             RAYLIBColor(200, 200, 200, 255))
    amTxt = "" + pAmmo
    amCol = RAYLIBColor(255, 255, 255, 255)
    if pAmmo < 10
        amCol = RAYLIBColor(255, 80, 50, 255)
    ok
    DrawText(amTxt, floor(secW*4.5 - MeasureText(amTxt, 36)/2), hudY + 28, 36, amCol)

    // Gun icon in AMMO section
    gX = floor(secW * 4.5 - 20)
    gY = hudY + 60
    DrawRectangle(gX, gY, 30, 8, RAYLIBColor(120, 120, 130, 255))
    DrawRectangle(gX + 8, gY + 6, 12, 10, RAYLIBColor(100, 100, 110, 255))

    // Damage flash
    if pHealth < 100
        dmgFlash = (100 - pHealth) / 200.0
        if dmgFlash > 0.3 dmgFlash = 0.3 ok
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H - hudH,
                      RAYLIBColor(255, 0, 0, floor(dmgFlash * 80)))
    ok

// =============================================================
// Minimap
// =============================================================

func doom_drawMinimap
    mapScale = 6
    mapX = SCREEN_W - MAP_W * mapScale - 15
    mapY = 15

    // Background
    DrawRectangle(mapX - 2, mapY - 2, MAP_W * mapScale + 4, MAP_H * mapScale + 4,
                  RAYLIBColor(0, 0, 0, 200))

    for r = 1 to MAP_H
        for c = 1 to MAP_W
            t = map[r][c]
            sx = mapX + (c-1) * mapScale
            sy = mapY + (r-1) * mapScale
            if t = T_WALL1
                DrawRectangle(sx, sy, mapScale, mapScale, RAYLIBColor(30, 40, 140, 255))
            ok
            if t = T_WALL2
                DrawRectangle(sx, sy, mapScale, mapScale, RAYLIBColor(20, 25, 100, 255))
            ok
            if t = T_WALL3
                DrawRectangle(sx, sy, mapScale, mapScale, RAYLIBColor(80, 78, 85, 255))
            ok
            if t = T_DOOR
                DrawRectangle(sx, sy, mapScale, mapScale, RAYLIBColor(40, 140, 130, 255))
            ok
            if t = T_EXIT
                DrawRectangle(sx, sy, mapScale, mapScale, RAYLIBColor(0, 255, 0, 255))
            ok
        next
    next

    // Enemies
    for i = 1 to len(enemies)
        if enemies[i][5] = EN_DEAD loop ok
        esx = mapX + floor(enemies[i][1]) * mapScale
        esy = mapY + floor(enemies[i][2]) * mapScale
        DrawRectangle(esx, esy, mapScale-1, mapScale-1, RAYLIBColor(255, 50, 50, 255))
    next

    // Pickups
    for i = 1 to len(pickups)
        if !pickups[i][4] loop ok
        psx = mapX + floor(pickups[i][1]) * mapScale
        psy = mapY + floor(pickups[i][2]) * mapScale
        DrawRectangle(psx+1, psy+1, mapScale-2, mapScale-2, RAYLIBColor(255, 255, 50, 255))
    next

    // Player
    plx = mapX + floor(pX) * mapScale
    ply = mapY + floor(pZ) * mapScale
    DrawRectangle(plx, ply, mapScale, mapScale, RAYLIBColor(0, 255, 0, 255))
    // Direction indicator (small rectangles)
    dirEndX = plx + mapScale/2 + floor(cos(camYaw) * mapScale * 2)
    dirEndY = ply + mapScale/2 + floor(sin(camYaw) * mapScale * 2)
    DrawRectangle(dirEndX - 1, dirEndY - 1, 3, 3, RAYLIBColor(0, 255, 0, 255))

// =============================================================
// Door Prompt (Press E to Open)
// =============================================================

func doom_drawDoorPrompt
    if gameState != ST_PLAYING return ok
    // Check if any closed door is nearby
    nearDoor = false
    for i = 1 to len(doors)
        if doors[i][3] > 0.5 loop ok   // Already open
        dr = doors[i][1]
        dc = doors[i][2]
        doorX = dc - 0.5
        doorZ = dr - 0.5
        ddx = doorX - pX
        ddz = doorZ - pZ
        dist = sqrt(ddx*ddx + ddz*ddz)
        if dist < 2.5
            nearDoor = true
        ok
    next
    if nearDoor
        promptTxt = "[ Press E to Open ]"
        pw = MeasureText(promptTxt, 24)
        px_ = floor(SCREEN_W/2 - pw/2)
        py_ = SCREEN_H/2 + 100
        // Pulsing alpha
        pAlpha = floor(sin(animTime * 4.0) * 50 + 205)
        // Background
        DrawRectangle(px_ - 12, py_ - 4, pw + 24, 32,
                      RAYLIBColor(0, 0, 0, floor(pAlpha * 0.5)))
        // Text
        DrawText(promptTxt, px_, py_, 24,
                 RAYLIBColor(255, 255, 100, pAlpha))
    ok

// =============================================================
// Title Screen
// =============================================================

func doom_drawTitle
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 255))

    // Title
    title = "RING DOOM 3D"
    tW = MeasureText(title, 64)
    // Shadow
    DrawText(title, floor(SCREEN_W/2 - tW/2) + 3, 103, 64,
             RAYLIBColor(80, 0, 0, 255))
    DrawText(title, floor(SCREEN_W/2 - tW/2), 100, 64,
             RAYLIBColor(255, 40, 30, 255))

    // Subtitle
    sub = "A Retro FPS in Ring Language"
    sW = MeasureText(sub, 20)
    DrawText(sub, floor(SCREEN_W/2 - sW/2), 180, 20,
             RAYLIBColor(180, 180, 180, 255))

    // Instructions
    yy = 260
    inst = [
        "WASD / Arrows  -  Move & Strafe",
        "Mouse  -  Look Around",
        "Left Click / Space  -  Shoot",
        "E  -  Open Doors",
        "TAB  -  Toggle Map",
        "ESC  -  Exit"
    ]
    for i = 1 to len(inst)
        iW = MeasureText(inst[i], 18)
        DrawText(inst[i], floor(SCREEN_W/2 - iW/2), yy + (i-1) * 28, 18,
                 RAYLIBColor(150, 150, 150, 255))
    next

    // Start prompt
    pulse = floor(sin(animTime * 3.0) * 60 + 195)
    start = "Press ENTER or SPACE to Begin"
    startW = MeasureText(start, 24)
    DrawText(start, floor(SCREEN_W/2 - startW/2), 500, 24,
             RAYLIBColor(255, 255, 255, pulse))

    // Version
    DrawText("Ring + RayLib", 10, SCREEN_H - 25, 14,
             RAYLIBColor(80, 80, 80, 255))

// =============================================================
// Death Screen
// =============================================================

func doom_drawDeathScreen
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H - 80, RAYLIBColor(120, 0, 0, 150))
    dTxt = "YOU DIED!"
    dW = MeasureText(dTxt, 56)
    DrawText(dTxt, floor(SCREEN_W/2 - dW/2), SCREEN_H/2 - 60, 56,
             RAYLIBColor(255, 40, 30, 255))
    if deathTimer <= 0
        rTxt = "Press ENTER to Continue"
        rW = MeasureText(rTxt, 22)
        DrawText(rTxt, floor(SCREEN_W/2 - rW/2), SCREEN_H/2 + 20, 22,
                 RAYLIBColor(200, 200, 200, 255))
        lvTxt = "Lives: " + pLives
        lW = MeasureText(lvTxt, 20)
        DrawText(lvTxt, floor(SCREEN_W/2 - lW/2), SCREEN_H/2 + 55, 20,
                 RAYLIBColor(200, 200, 200, 200))
    ok

// =============================================================
// Win Screen
// =============================================================

func doom_drawWinScreen
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H - 80, RAYLIBColor(0, 40, 0, 180))
    wTxt = "FLOOR COMPLETE!"
    wW = MeasureText(wTxt, 48)
    DrawText(wTxt, floor(SCREEN_W/2 - wW/2), SCREEN_H/2 - 80, 48,
             RAYLIBColor(50, 255, 80, 255))
    sTxt = "Score: " + pScore
    sW = MeasureText(sTxt, 28)
    DrawText(sTxt, floor(SCREEN_W/2 - sW/2), SCREEN_H/2 - 20, 28,
             RAYLIBColor(255, 255, 200, 255))
    if levelNum < maxLevels
        nTxt = "Press ENTER for Next Floor"
    else
        nTxt = "All Floors Complete! Press ENTER"
    ok
    nW = MeasureText(nTxt, 22)
    DrawText(nTxt, floor(SCREEN_W/2 - nW/2), SCREEN_H/2 + 30, 22,
             RAYLIBColor(200, 200, 200, 255))

// =============================================================
// Show message
// =============================================================

func doom_showMsg txt
    msgText = txt
    msgTimer = 2.0

// =============================================================
// Helper
// =============================================================

func fabs n
    if n < 0 return -n ok
    return n

func myAtan2 y, x
    // Safe atan2 implementation
    PI = 3.14159265
    if fabs(x) < 0.0001
        if y > 0 return PI / 2 ok
        if y < 0 return -PI / 2 ok
        return 0
    ok
    a = atan(y / x)
    if x < 0
        if y >= 0
            a = a + PI
        else
            a = a - PI
        ok
    ok
    return a
