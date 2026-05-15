/*
**  Roguelike 2D - RingRayLib
**  ===================================
**  Procedural dungeon with turn-based combat!
**  Explore rooms, fight monsters, collect loot, descend deeper.
**
**  Controls:
**    WASD / Arrows    - Move (each step = 1 turn)
**    Space            - Wait a turn (heal slowly)
**    E                - Pick up item / Use stairs
**    I                - Toggle inventory
**    1-4              - Use inventory item (potion/scroll)
**    Tab              - Toggle full map
**    M                - Toggle minimap
**    R                - New game
**    ESC              - Exit
**
**  Features:
**    - BSP procedural dungeon generation
**    - Fog of war with line-of-sight
**    - Turn-based movement and combat
**    - 8 enemy types scaling by floor
**    - Items: potions, scrolls, weapons, armor
**    - XP and leveling system
**    - 10 dungeon floors
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W = 1024
SCREEN_H = 700

PI = 3.14159265

// Map
MAP_W = 60
MAP_H = 40
TILE_SZ = 16

// Viewport (scrolling camera)
VIEW_COLS = floor(SCREEN_W / TILE_SZ)
VIEW_ROWS = floor((SCREEN_H - 80) / TILE_SZ)    // leave room for HUD

// Tiles
T_VOID  = 0
T_WALL  = 1
T_FLOOR = 2
T_DOOR  = 3
T_STAIR = 4
T_CORR  = 5    // corridor

// Fog states
FOG_UNSEEN = 0
FOG_SEEN   = 1
FOG_VISIBLE = 2

// Directions
DIR_N = 1   DIR_S = 2   DIR_E = 3   DIR_W = 4

// Entity types
ENT_PLAYER = 0
ENT_RAT    = 1
ENT_BAT    = 2
ENT_SLIME  = 3
ENT_GOBLIN = 4
ENT_SKEL   = 5
ENT_ORC    = 6
ENT_TROLL  = 7
ENT_DEMON  = 8

enemyNames = ["Player", "Rat", "Bat", "Slime", "Goblin", "Skeleton", "Orc", "Troll", "Demon"]
enemyChars = ["@", "r", "b", "s", "g", "k", "o", "T", "D"]
enemyBaseHP   = [0, 8,  6, 12, 15, 18, 25, 40, 60]
enemyBaseATK  = [0, 2,  3,  2,  4,  5,  6, 8, 12]
enemyBaseDEF  = [0, 0,  0,  1,  1,  2,  3, 4,  5]
enemyBaseXP   = [0, 5,  4,  6, 10, 14, 20, 35, 60]

// Items
ITEM_HPOT   = 1    // health potion
ITEM_MPOT   = 2    // mana/energy potion - restores more
ITEM_SCROLL_FIRE  = 3
ITEM_SCROLL_TELE  = 4
ITEM_WEAPON = 5
ITEM_ARMOR  = 6

itemNames = ["", "Health Potion", "Strong Potion", "Fire Scroll", "Teleport Scroll", "Weapon", "Armor"]
itemChars = ["", "!", "!", "?", "?", "/", "["]

// =============================================================
// Map Data
// =============================================================

map = list(MAP_W * MAP_H)
fog = list(MAP_W * MAP_H)

// Rooms: [x, y, w, h]
rooms = []

// =============================================================
// Player
// =============================================================

px = 5   py = 5     // grid position
pHP = 30   pMaxHP = 30
pATK = 5   pDEF = 2
pXP = 0    pLevel = 1
pXPnext = 20
pFloor = 1
pTurns = 0

// Inventory: list of [itemType, bonusVal]
inventory = []
MAX_INV = 8

pWeaponBonus = 0
pArmorBonus = 0

// =============================================================
// Entities
// =============================================================

// [type, x, y, hp, maxHP, atk, def, xpVal, alive, lastSeen]
entities = []

// Items on ground: [type, x, y, bonusVal, active]
groundItems = []

// =============================================================
// State
// =============================================================

gameState = 1       // 1=playing, 2=dead, 3=won
animTime = 0.0
showInv = false
showFullMap = false
showMinimap = true

msgLog = []
MAX_LOG = 6

// Turn-based: player acts, then all enemies act
turnPhase = 1    // 1=player, 2=enemy

// Combat flash
flashX = 0   flashY = 0   flashTimer = 0.0
flashCol = [255, 0, 0]

// Camera scroll
camX = 0.0   camY = 0.0

// =============================================================
// Main
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Roguelike 2D - RingRayLib")
SetTargetFPS(60)
SetExitKey(0)

rl_newGame()

while !WindowShouldClose()
    rl_update()
    BeginDrawing()
        ClearBackground(RAYLIBColor(15, 12, 18, 255))
        rl_draw()
    EndDrawing()
end

CloseWindow()

// =============================================================
// Map Helpers
// =============================================================

func rl_idx x, y
    if x < 0 or x >= MAP_W or y < 0 or y >= MAP_H return -1 ok
    return y * MAP_W + x + 1

func rl_getMap x, y
    i = rl_idx(x, y)
    if i < 1 return T_VOID ok
    return map[i]

func rl_setMap x, y, val
    i = rl_idx(x, y)
    if i >= 1 and i <= MAP_W * MAP_H
        map[i] = val
    ok

func rl_getFog x, y
    i = rl_idx(x, y)
    if i < 1 return FOG_UNSEEN ok
    return fog[i]

func rl_setFog x, y, val
    i = rl_idx(x, y)
    if i >= 1 and i <= MAP_W * MAP_H
        fog[i] = val
    ok

func rl_isWalkable x, y
    t = rl_getMap(x, y)
    if t = T_FLOOR or t = T_DOOR or t = T_STAIR or t = T_CORR return true ok
    return false

func rl_isBlocking x, y
    t = rl_getMap(x, y)
    if t = T_WALL or t = T_VOID return true ok
    return false

// =============================================================
// New Game
// =============================================================

func rl_newGame
    pHP = 30   pMaxHP = 30
    pATK = 5   pDEF = 2
    pXP = 0    pLevel = 1
    pXPnext = 20
    pFloor = 1
    pTurns = 0
    pWeaponBonus = 0
    pArmorBonus = 0
    inventory = []
    add(inventory, [ITEM_HPOT, 15])
    add(inventory, [ITEM_HPOT, 15])

    msgLog = []
    gameState = 1
    rl_addMsg("Welcome to the dungeon! Reach floor 10 to win.")
    rl_generateFloor(pFloor)

// =============================================================
// Generate Floor
// =============================================================

func rl_generateFloor floorNum
    // Clear map
    for i = 1 to MAP_W * MAP_H
        map[i] = T_VOID
        fog[i] = FOG_UNSEEN
    next

    rooms = []
    entities = []
    groundItems = []

    // Generate rooms
    numRooms = 6 + floorNum
    if numRooms > 14 numRooms = 14 ok

    attempts = 0
    while len(rooms) < numRooms and attempts < 200
        attempts++
        rw = GetRandomValue(5, 10)
        rh = GetRandomValue(4, 8)
        rx = GetRandomValue(1, MAP_W - rw - 2)
        ry = GetRandomValue(1, MAP_H - rh - 2)

        // Check overlap
        overlap = false
        for i = 1 to len(rooms)
            r = rooms[i]
            if rx < r[1] + r[3] + 2 and rx + rw + 2 > r[1] and
               ry < r[2] + r[4] + 2 and ry + rh + 2 > r[2]
                overlap = true
                exit
            ok
        next

        if !overlap
            add(rooms, [rx, ry, rw, rh])
            // Carve room
            for y = ry to ry + rh - 1
                for x = rx to rx + rw - 1
                    rl_setMap(x, y, T_FLOOR)
                next
            next
            // Walls around
            for y = ry - 1 to ry + rh
                for x = rx - 1 to rx + rw
                    if rl_getMap(x, y) = T_VOID
                        rl_setMap(x, y, T_WALL)
                    ok
                next
            next
        ok
    end

    // Connect rooms with corridors
    for i = 2 to len(rooms)
        r1 = rooms[i - 1]
        r2 = rooms[i]
        cx1 = r1[1] + floor(r1[3] / 2)
        cy1 = r1[2] + floor(r1[4] / 2)
        cx2 = r2[1] + floor(r2[3] / 2)
        cy2 = r2[2] + floor(r2[4] / 2)

        // L-shaped corridor
        if GetRandomValue(0, 1) = 0
            rl_carveCorrH(cx1, cx2, cy1)
            rl_carveCorrV(cy1, cy2, cx2)
        else
            rl_carveCorrV(cy1, cy2, cx1)
            rl_carveCorrH(cx1, cx2, cy2)
        ok
    next

    // Add doors at room entrances
    for i = 1 to len(rooms)
        r = rooms[i]
        // Check edges for corridor connections
        for x = r[1] to r[1] + r[3] - 1
            if rl_getMap(x, r[2] - 1) = T_CORR
                rl_setMap(x, r[2], T_DOOR)
            ok
            if rl_getMap(x, r[2] + r[4]) = T_CORR
                rl_setMap(x, r[2] + r[4] - 1, T_DOOR)
            ok
        next
        for y = r[2] to r[2] + r[4] - 1
            if rl_getMap(r[1] - 1, y) = T_CORR
                rl_setMap(r[1], y, T_DOOR)
            ok
            if rl_getMap(r[1] + r[3], y) = T_CORR
                rl_setMap(r[1] + r[3] - 1, y, T_DOOR)
            ok
        next
    next

    // Place player in first room
    r1 = rooms[1]
    px = r1[1] + floor(r1[3] / 2)
    py = r1[2] + floor(r1[4] / 2)

    // Place stairs in last room
    rLast = rooms[len(rooms)]
    sx = rLast[1] + floor(rLast[3] / 2)
    sy = rLast[2] + floor(rLast[4] / 2)
    rl_setMap(sx, sy, T_STAIR)

    // Spawn enemies (not in first room)
    numEnemies = 4 + floorNum * 2
    if numEnemies > 25 numEnemies = 25 ok

    for e = 1 to numEnemies
        // Pick random room (not first)
        ri = GetRandomValue(2, len(rooms))
        r = rooms[ri]
        ex = r[1] + GetRandomValue(0, r[3] - 1)
        ey = r[2] + GetRandomValue(0, r[4] - 1)

        // Choose enemy type based on floor
        etype = rl_randomEnemy(floorNum)
        ehp = floor(enemyBaseHP[etype] * (1 + floorNum * 0.15))
        eatk = floor(enemyBaseATK[etype] * (1 + floorNum * 0.12))
        edef = floor(enemyBaseDEF[etype] * (1 + floorNum * 0.1))
        exp2 = floor(enemyBaseXP[etype] * (1 + floorNum * 0.2))

        add(entities, [etype, ex, ey, ehp, ehp, eatk, edef, exp2, 1, 0])
    next

    // Spawn ground items
    numItems = 3 + floor(floorNum * 0.5)
    for it = 1 to numItems
        ri = GetRandomValue(2, len(rooms))
        r = rooms[ri]
        ix = r[1] + GetRandomValue(0, r[3] - 1)
        iy = r[2] + GetRandomValue(0, r[4] - 1)

        itype = rl_randomItem(floorNum)
        bonus = 0
        if itype = ITEM_HPOT bonus = 12 + floorNum * 2 ok
        if itype = ITEM_MPOT bonus = 25 + floorNum * 3 ok
        if itype = ITEM_SCROLL_FIRE bonus = 15 + floorNum * 5 ok
        if itype = ITEM_SCROLL_TELE bonus = 0 ok
        if itype = ITEM_WEAPON bonus = GetRandomValue(1, 2 + floorNum) ok
        if itype = ITEM_ARMOR bonus = GetRandomValue(1, 1 + floor(floorNum / 2)) ok

        add(groundItems, [itype, ix, iy, bonus, 1])
    next

    // Reveal around player
    rl_computeFOV()
    rl_addMsg("Floor " + string(floorNum) + " — find the stairs to descend.")

func rl_carveCorrH x1, x2, y
    sx = x1  ex = x2
    if x1 > x2  sx = x2  ex = x1  ok
    for x = sx to ex
        t = rl_getMap(x, y)
        if t = T_VOID or t = T_WALL
            rl_setMap(x, y, T_CORR)
        ok
        // Walls beside
        if rl_getMap(x, y - 1) = T_VOID rl_setMap(x, y - 1, T_WALL) ok
        if rl_getMap(x, y + 1) = T_VOID rl_setMap(x, y + 1, T_WALL) ok
    next

func rl_carveCorrV y1, y2, x
    sy = y1  ey = y2
    if y1 > y2  sy = y2  ey = y1  ok
    for y = sy to ey
        t = rl_getMap(x, y)
        if t = T_VOID or t = T_WALL
            rl_setMap(x, y, T_CORR)
        ok
        if rl_getMap(x - 1, y) = T_VOID rl_setMap(x - 1, y, T_WALL) ok
        if rl_getMap(x + 1, y) = T_VOID rl_setMap(x + 1, y, T_WALL) ok
    next

func rl_randomEnemy floorNum
    if floorNum <= 2
        return GetRandomValue(ENT_RAT, ENT_SLIME)
    ok
    if floorNum <= 4
        return GetRandomValue(ENT_RAT, ENT_GOBLIN)
    ok
    if floorNum <= 6
        return GetRandomValue(ENT_SLIME, ENT_ORC)
    ok
    if floorNum <= 8
        return GetRandomValue(ENT_GOBLIN, ENT_TROLL)
    ok
    return GetRandomValue(ENT_ORC, ENT_DEMON)

func rl_randomItem floorNum
    r = GetRandomValue(1, 100)
    if r <= 35 return ITEM_HPOT ok
    if r <= 50 return ITEM_MPOT ok
    if r <= 65 return ITEM_SCROLL_FIRE ok
    if r <= 75 return ITEM_SCROLL_TELE ok
    if r <= 88 return ITEM_WEAPON ok
    return ITEM_ARMOR

// =============================================================
// FOV (Field of View)
// =============================================================

func rl_computeFOV
    // Reset visible to seen
    for i = 1 to MAP_W * MAP_H
        if fog[i] = FOG_VISIBLE fog[i] = FOG_SEEN ok
    next

    // Simple raycasting FOV, radius 8
    radius = 8
    for angle = 0 to 359 step 3
        ax = cos(angle * PI / 180.0)
        ay = sin(angle * PI / 180.0)

        cx = px * 1.0 + 0.5
        cy = py * 1.0 + 0.5

        for step = 0 to radius
            ix = floor(cx)
            iy = floor(cy)
            if ix < 0 or ix >= MAP_W or iy < 0 or iy >= MAP_H exit ok

            rl_setFog(ix, iy, FOG_VISIBLE)

            if rl_isBlocking(ix, iy) and step > 0 exit ok

            cx += ax
            cy += ay
        next
    next

// =============================================================
// Message Log
// =============================================================

func rl_addMsg text
    add(msgLog, text)
    if len(msgLog) > MAX_LOG
        del(msgLog, 1)
    ok

// =============================================================
// Update
// =============================================================

func rl_update
    dt = GetFrameTime()
    if dt > 0.05 dt = 0.05 ok
    animTime += dt

    if IsKeyPressed(KEY_ESCAPE)
        CloseWindow()
        shutdown(0)
    ok

    if IsKeyPressed(KEY_R) rl_newGame() ok
    if IsKeyPressed(KEY_I) showInv = !showInv ok
    if IsKeyPressed(KEY_TAB) showFullMap = !showFullMap ok
    if IsKeyPressed(KEY_M) showMinimap = !showMinimap ok

    // Flash timer
    if flashTimer > 0
        flashTimer -= dt
        if flashTimer < 0 flashTimer = 0 ok
    ok

    if gameState != 1 return ok

    // Player turn
    moved = false
    dx = 0   dy = 0

    if IsKeyPressed(KEY_W) or IsKeyPressed(KEY_UP)    dy = -1 moved = true ok
    if IsKeyPressed(KEY_S) or IsKeyPressed(KEY_DOWN)   dy = 1  moved = true ok
    if IsKeyPressed(KEY_A) or IsKeyPressed(KEY_LEFT)   dx = -1 moved = true ok
    if IsKeyPressed(KEY_D) or IsKeyPressed(KEY_RIGHT)  dx = 1  moved = true ok

    // Wait (rest)
    if IsKeyPressed(KEY_SPACE)
        moved = true
        dx = 0  dy = 0
        if pHP < pMaxHP
            pHP++
        ok
    ok

    // Pick up / interact
    if IsKeyPressed(KEY_E)
        rl_interact()
        moved = true
    ok

    // Use inventory items 1-4
    if IsKeyPressed(KEY_ONE)   rl_useItem(1) moved = true ok
    if IsKeyPressed(KEY_TWO)   rl_useItem(2) moved = true ok
    if IsKeyPressed(KEY_THREE) rl_useItem(3) moved = true ok
    if IsKeyPressed(KEY_FOUR)  rl_useItem(4) moved = true ok

    if moved
        nx = px + dx
        ny = py + dy

        // Check for enemy at target
        enemyIdx = rl_enemyAt(nx, ny)
        if enemyIdx > 0
            rl_attackEnemy(enemyIdx)
        but rl_isWalkable(nx, ny)
            px = nx
            py = ny
        ok

        pTurns++

        // Enemies act
        rl_enemyTurns()

        // Update FOV
        rl_computeFOV()
    ok

    // Camera follow player
    targetCX = px * TILE_SZ - SCREEN_W / 2 + TILE_SZ / 2
    targetCY = py * TILE_SZ - (SCREEN_H - 80) / 2 + TILE_SZ / 2
    camX += (targetCX - camX) * 8 * dt
    camY += (targetCY - camY) * 8 * dt

// =============================================================
// Combat
// =============================================================

func rl_attackEnemy idx
    if idx < 1 or idx > len(entities) return ok
    e = entities[idx]

    // Player attacks
    totalATK = pATK + pWeaponBonus
    dmg = totalATK - e[7] + GetRandomValue(-1, 2)
    if dmg < 1 dmg = 1 ok

    entities[idx][4] -= dmg
    flashX = e[2]  flashY = e[3]  flashTimer = 0.2
    flashCol = [255, 80, 50]

    rl_addMsg("You hit " + enemyNames[e[1]] + " for " + string(dmg) + " damage!")

    if entities[idx][4] <= 0
        entities[idx][9] = 0
        pXP += e[8]
        rl_addMsg(enemyNames[e[1]] + " defeated! +" + string(e[8]) + " XP")
        rl_checkLevelUp()
    ok

func rl_enemyAttack idx
    e = entities[idx]
    totalDEF = pDEF + pArmorBonus
    dmg = e[6] - totalDEF + GetRandomValue(-1, 2)
    if dmg < 1 dmg = 1 ok

    pHP -= dmg
    flashX = px  flashY = py  flashTimer = 0.2
    flashCol = [255, 0, 0]

    rl_addMsg(enemyNames[e[1]] + " hits you for " + string(dmg) + "!")

    if pHP <= 0
        pHP = 0
        gameState = 2
        rl_addMsg("You have been slain on floor " + string(pFloor) + "!")
    ok

// =============================================================
// Enemy Turns
// =============================================================

func rl_enemyTurns
    for i = 1 to len(entities)
        if entities[i][9] = 0 loop ok
        e = entities[i]
        ex = e[2]  ey = e[3]

        // Only act if visible or close
        dist = fabs(ex - px) + fabs(ey - py)    // manhattan
        if dist > 12 loop ok

        // Adjacent? Attack!
        if fabs(ex - px) + fabs(ey - py) = 1
            rl_enemyAttack(i)
            loop
        ok

        // Chase player (simple)
        if dist <= 8
            dx = 0  dy = 0
            if ex < px dx = 1
            but ex > px dx = -1 ok
            if ey < py dy = 1
            but ey > py dy = -1 ok

            // Prefer axis with larger distance
            if fabs(ex - px) >= fabs(ey - py)
                // Try horizontal first
                if rl_isWalkable(ex + dx, ey) and rl_enemyAt(ex + dx, ey) = 0
                    entities[i][2] = ex + dx
                but rl_isWalkable(ex, ey + dy) and rl_enemyAt(ex, ey + dy) = 0
                    entities[i][3] = ey + dy
                ok
            else
                if rl_isWalkable(ex, ey + dy) and rl_enemyAt(ex, ey + dy) = 0
                    entities[i][3] = ey + dy
                but rl_isWalkable(ex + dx, ey) and rl_enemyAt(ex + dx, ey) = 0
                    entities[i][2] = ex + dx
                ok
            ok
        ok
    next

func rl_enemyAt x, y
    for i = 1 to len(entities)
        if entities[i][9] = 0 loop ok
        if entities[i][2] = x and entities[i][3] = y
            return i
        ok
    next
    return 0

// =============================================================
// Interact
// =============================================================

func rl_interact
    // Pick up item
    for i = 1 to len(groundItems)
        if groundItems[i][5] = 0 loop ok
        if groundItems[i][2] = px and groundItems[i][3] = py
            if groundItems[i][1] = ITEM_WEAPON
                if groundItems[i][4] > pWeaponBonus
                    pWeaponBonus = groundItems[i][4]
                    rl_addMsg("Equipped weapon (+" + string(pWeaponBonus) + " ATK)!")
                else
                    rl_addMsg("Weapon is weaker than current. Left it.")
                    return
                ok
            but groundItems[i][1] = ITEM_ARMOR
                if groundItems[i][4] > pArmorBonus
                    pArmorBonus = groundItems[i][4]
                    rl_addMsg("Equipped armor (+" + string(pArmorBonus) + " DEF)!")
                else
                    rl_addMsg("Armor is weaker than current. Left it.")
                    return
                ok
            else
                if len(inventory) < MAX_INV
                    add(inventory, [groundItems[i][1], groundItems[i][4]])
                    rl_addMsg("Picked up " + itemNames[groundItems[i][1]] + "!")
                else
                    rl_addMsg("Inventory full!")
                    return
                ok
            ok
            groundItems[i][5] = 0
            return
        ok
    next

    // Use stairs
    if rl_getMap(px, py) = T_STAIR
        if pFloor >= 10
            gameState = 3
            rl_addMsg("You escaped the dungeon! Victory!")
        else
            pFloor++
            rl_generateFloor(pFloor)
        ok
        return
    ok

// =============================================================
// Use Item
// =============================================================

func rl_useItem slot
    if slot < 1 or slot > len(inventory) return ok
    item = inventory[slot]

    if item[1] = ITEM_HPOT or item[1] = ITEM_MPOT
        heal = item[2]
        pHP += heal
        if pHP > pMaxHP pHP = pMaxHP ok
        rl_addMsg("Used " + itemNames[item[1]] + "! +" + string(heal) + " HP")
    ok

    if item[1] = ITEM_SCROLL_FIRE
        // Damage all visible enemies
        dmg = item[2]
        hit = 0
        for i = 1 to len(entities)
            if entities[i][9] = 0 loop ok
            ex = entities[i][2]  ey = entities[i][3]
            if rl_getFog(ex, ey) = FOG_VISIBLE
                entities[i][4] -= dmg
                flashX = ex  flashY = ey  flashTimer = 0.3
                flashCol = [255, 150, 0]
                hit++
                if entities[i][4] <= 0
                    entities[i][9] = 0
                    pXP += entities[i][8]
                    rl_checkLevelUp()
                ok
            ok
        next
        rl_addMsg("Fire scroll! Hit " + string(hit) + " enemies for " + string(dmg) + " damage!")
    ok

    if item[1] = ITEM_SCROLL_TELE
        // Teleport to random room
        ri = GetRandomValue(1, len(rooms))
        r = rooms[ri]
        px = r[1] + floor(r[3] / 2)
        py = r[2] + floor(r[4] / 2)
        rl_computeFOV()
        rl_addMsg("Teleported to a random room!")
    ok

    del(inventory, slot)

// =============================================================
// Level Up
// =============================================================

func rl_checkLevelUp
    while pXP >= pXPnext
        pXP -= pXPnext
        pLevel++
        pMaxHP += 5
        pHP += 5
        if pHP > pMaxHP pHP = pMaxHP ok
        pATK += 1
        pDEF += 1
        pXPnext = floor(pXPnext * 1.5)
        rl_addMsg("*** LEVEL UP! Level " + string(pLevel) + "! ***")
    end

// =============================================================
// Draw
// =============================================================

func rl_draw
    // Offset for camera
    offX = floor(-camX)
    offY = floor(-camY)

    // Draw map
    startCol = floor(camX / TILE_SZ) - 1
    startRow = floor(camY / TILE_SZ) - 1
    if startCol < 0 startCol = 0 ok
    if startRow < 0 startRow = 0 ok
    endCol = startCol + VIEW_COLS + 3
    endRow = startRow + VIEW_ROWS + 3
    if endCol >= MAP_W endCol = MAP_W - 1 ok
    if endRow >= MAP_H endRow = MAP_H - 1 ok

    for y = startRow to endRow
        for x = startCol to endCol
            f = rl_getFog(x, y)
            if f = FOG_UNSEEN loop ok

            t = rl_getMap(x, y)
            sx = x * TILE_SZ + offX
            sy = y * TILE_SZ + offY

            dim = 1.0
            if f = FOG_SEEN dim = 0.35 ok

            if t = T_WALL
                wr = floor(55 * dim)  wg = floor(50 * dim)  wb = floor(65 * dim)
                DrawRectangle(sx, sy, TILE_SZ, TILE_SZ, RAYLIBColor(wr, wg, wb, 255))
                // Brick pattern
                if (x + y) % 3 = 0
                    DrawRectangle(sx + 2, sy + 2, TILE_SZ - 4, TILE_SZ - 4, RAYLIBColor(wr + 8, wg + 5, wb + 5, 255))
                ok
            ok

            if t = T_FLOOR
                fr = floor(35 * dim)  fg = floor(32 * dim)  fb = floor(28 * dim)
                DrawRectangle(sx, sy, TILE_SZ, TILE_SZ, RAYLIBColor(fr, fg, fb, 255))
                // Floor specks
                if (x * 7 + y * 13) % 5 = 0
                    DrawRectangle(sx + 6, sy + 6, 2, 2, RAYLIBColor(floor(45 * dim), floor(42 * dim), floor(38 * dim), 255))
                ok
            ok

            if t = T_CORR
                DrawRectangle(sx, sy, TILE_SZ, TILE_SZ, RAYLIBColor(floor(30 * dim), floor(28 * dim), floor(25 * dim), 255))
            ok

            if t = T_DOOR
                DrawRectangle(sx, sy, TILE_SZ, TILE_SZ, RAYLIBColor(floor(30 * dim), floor(28 * dim), floor(25 * dim), 255))
                DrawRectangle(sx + 2, sy + 1, TILE_SZ - 4, TILE_SZ - 2, RAYLIBColor(floor(110 * dim), floor(70 * dim), floor(35 * dim), 255))
            ok

            if t = T_STAIR
                DrawRectangle(sx, sy, TILE_SZ, TILE_SZ, RAYLIBColor(floor(35 * dim), floor(32 * dim), floor(28 * dim), 255))
                // Stair symbol
                sc = floor(200 * dim)
                DrawRectangle(sx + 2, sy + 10, 12, 3, RAYLIBColor(sc, sc, floor(100 * dim), 255))
                DrawRectangle(sx + 5, sy + 6, 9, 3, RAYLIBColor(sc, sc, floor(100 * dim), 255))
                DrawRectangle(sx + 8, sy + 2, 6, 3, RAYLIBColor(sc, sc, floor(100 * dim), 255))
            ok
        next
    next

    // Ground items
    for i = 1 to len(groundItems)
        if groundItems[i][5] = 0 loop ok
        ix = groundItems[i][2]  iy = groundItems[i][3]
        if rl_getFog(ix, iy) != FOG_VISIBLE loop ok

        sx = ix * TILE_SZ + offX
        sy = iy * TILE_SZ + offY
        itype = groundItems[i][1]

        if itype = ITEM_HPOT
            DrawCircle(sx + 8, sy + 8, 5, RAYLIBColor(255, 60, 80, 230))
        ok
        if itype = ITEM_MPOT
            DrawCircle(sx + 8, sy + 8, 5, RAYLIBColor(80, 120, 255, 230))
        ok
        if itype = ITEM_SCROLL_FIRE
            DrawRectangle(sx + 4, sy + 3, 8, 10, RAYLIBColor(255, 180, 50, 230))
        ok
        if itype = ITEM_SCROLL_TELE
            DrawRectangle(sx + 4, sy + 3, 8, 10, RAYLIBColor(100, 200, 255, 230))
        ok
        if itype = ITEM_WEAPON
            DrawRectangle(sx + 7, sy + 2, 3, 12, RAYLIBColor(200, 200, 220, 230))
            DrawRectangle(sx + 4, sy + 10, 9, 3, RAYLIBColor(140, 100, 50, 220))
        ok
        if itype = ITEM_ARMOR
            DrawRectangle(sx + 3, sy + 3, 10, 10, RAYLIBColor(100, 130, 180, 230))
            DrawRectangle(sx + 5, sy + 5, 6, 6, RAYLIBColor(80, 110, 160, 200))
        ok
    next

    // Entities
    for i = 1 to len(entities)
        if entities[i][9] = 0 loop ok
        ex = entities[i][2]  ey = entities[i][3]
        if rl_getFog(ex, ey) != FOG_VISIBLE loop ok

        sx = ex * TILE_SZ + offX
        sy = ey * TILE_SZ + offY
        etype = entities[i][1]

        eCol = RAYLIBColor(200, 100, 100, 255)
        if etype = ENT_RAT    eCol = RAYLIBColor(160, 130, 100, 255) ok
        if etype = ENT_BAT    eCol = RAYLIBColor(120, 80, 140, 255) ok
        if etype = ENT_SLIME  eCol = RAYLIBColor(80, 200, 80, 255) ok
        if etype = ENT_GOBLIN eCol = RAYLIBColor(80, 160, 60, 255) ok
        if etype = ENT_SKEL   eCol = RAYLIBColor(220, 220, 200, 255) ok
        if etype = ENT_ORC    eCol = RAYLIBColor(100, 150, 60, 255) ok
        if etype = ENT_TROLL  eCol = RAYLIBColor(80, 120, 80, 255) ok
        if etype = ENT_DEMON  eCol = RAYLIBColor(200, 50, 50, 255) ok

        DrawRectangle(sx + 2, sy + 2, TILE_SZ - 4, TILE_SZ - 4, eCol)

        // Enemy letter
        DrawText(enemyChars[etype], sx + 4, sy + 2, 13, RAYLIBColor(255, 255, 255, 230))

        // HP bar above
        maxhp2 = entities[i][5]
        if maxhp2 < 1 maxhp2 = 1 ok
        hpFrac = entities[i][4] * 1.0 / maxhp2
        DrawRectangle(sx, sy - 3, TILE_SZ, 3, RAYLIBColor(40, 0, 0, 200))
        DrawRectangle(sx, sy - 3, floor(TILE_SZ * hpFrac), 3, RAYLIBColor(255, 50, 50, 220))
    next

    // Player
    psx = px * TILE_SZ + offX
    psy = py * TILE_SZ + offY
    DrawRectangle(psx + 1, psy + 1, TILE_SZ - 2, TILE_SZ - 2, RAYLIBColor(80, 150, 255, 255))
    DrawText("@", psx + 3, psy + 1, 14, RAYLIBColor(255, 255, 255, 255))

    // Combat flash
    if flashTimer > 0
        fx = flashX * TILE_SZ + offX
        fy = flashY * TILE_SZ + offY
        fa = floor(flashTimer * 800)
        if fa > 200 fa = 200 ok
        DrawRectangle(fx - 4, fy - 4, TILE_SZ + 8, TILE_SZ + 8, RAYLIBColor(flashCol[1], flashCol[2], flashCol[3], fa))
    ok

    // HUD
    rl_drawHUD()

    // Inventory overlay
    if showInv
        rl_drawInventory()
    ok

    // Full map overlay
    if showFullMap
        rl_drawFullMap()
    ok

    // Minimap
    if showMinimap and !showFullMap
        rl_drawMinimap()
    ok

    // Game over / Win
    if gameState = 2
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(80, 0, 0, 150))
        DrawText("YOU DIED", SCREEN_W/2 - 90, SCREEN_H/2 - 40, 36, RAYLIBColor(255, 60, 60, 255))
        DrawText("Floor " + string(pFloor) + "  Level " + string(pLevel) + "  Turns " + string(pTurns),
                 SCREEN_W/2 - 120, SCREEN_H/2 + 10, 16, RAYLIBColor(200, 200, 200, 200))
        DrawText("Press R to restart", SCREEN_W/2 - 72, SCREEN_H/2 + 40, 16, RAYLIBColor(200, 200, 200, 180))
    ok

    if gameState = 3
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 40, 60, 140))
        DrawText("VICTORY!", SCREEN_W/2 - 80, SCREEN_H/2 - 40, 36, RAYLIBColor(100, 255, 150, 255))
        DrawText("Escaped on Level " + string(pLevel) + " in " + string(pTurns) + " turns!",
                 SCREEN_W/2 - 140, SCREEN_H/2 + 10, 16, RAYLIBColor(220, 255, 220, 230))
        DrawText("Press R for new game", SCREEN_W/2 - 80, SCREEN_H/2 + 40, 16, RAYLIBColor(200, 220, 200, 180))
    ok

// =============================================================
// HUD
// =============================================================

func rl_drawHUD
    // Bottom bar
    hudY = SCREEN_H - 80
    DrawRectangle(0, hudY, SCREEN_W, 80, RAYLIBColor(10, 8, 14, 240))
    DrawRectangle(0, hudY, SCREEN_W, 2, RAYLIBColor(60, 50, 80, 200))

    // HP bar
    DrawRectangle(10, hudY + 8, 154, 16, RAYLIBColor(30, 10, 10, 255))
    pmhp = pMaxHP
    if pmhp < 1 pmhp = 1 ok
    hpW = floor(pHP * 150.0 / pmhp)
    hpCol = RAYLIBColor(60, 200, 60, 220)
    if pHP < pMaxHP * 0.3 hpCol = RAYLIBColor(255, 60, 60, 220) ok
    if pHP < pMaxHP * 0.6 and pHP >= pMaxHP * 0.3 hpCol = RAYLIBColor(255, 200, 60, 220) ok
    DrawRectangle(12, hudY + 10, hpW, 12, hpCol)
    hpTxt = "HP " + string(pHP) + "/" + string(pMaxHP)
    DrawText(hpTxt, 14, hudY + 10, 12, WHITE)

    // XP bar
    DrawRectangle(10, hudY + 28, 154, 10, RAYLIBColor(10, 10, 30, 255))
    pxpn = pXPnext
    if pxpn < 1 pxpn = 1 ok
    xpW = floor(pXP * 150.0 / pxpn)
    DrawRectangle(12, hudY + 29, xpW, 8, RAYLIBColor(100, 80, 200, 200))
    DrawText("XP " + string(pXP) + "/" + string(pXPnext), 14, hudY + 28, 10, RAYLIBColor(180, 160, 220, 200))

    // Stats
    DrawText("Lv:" + string(pLevel), 180, hudY + 8, 14, RAYLIBColor(255, 215, 0, 220))
    DrawText("ATK:" + string(pATK + pWeaponBonus), 180, hudY + 26, 12, RAYLIBColor(255, 120, 80, 200))
    DrawText("DEF:" + string(pDEF + pArmorBonus), 250, hudY + 26, 12, RAYLIBColor(80, 180, 255, 200))
    DrawText("Floor:" + string(pFloor) + "/10", 320, hudY + 8, 14, RAYLIBColor(200, 200, 220, 200))
    DrawText("Turns:" + string(pTurns), 320, hudY + 26, 12, RAYLIBColor(180, 180, 200, 170))

    // Inventory quick slots
    for i = 1 to 4
        slotX = 430 + (i - 1) * 40
        slotY = hudY + 6
        DrawRectangle(slotX, slotY, 34, 34, RAYLIBColor(25, 20, 35, 255))
        DrawRectangleLines(slotX, slotY, 34, 34, RAYLIBColor(80, 70, 100, 200))
        DrawText(string(i), slotX + 2, slotY + 1, 10, RAYLIBColor(120, 110, 140, 150))

        if i <= len(inventory)
            item = inventory[i]
            if item[1] = ITEM_HPOT
                DrawCircle(slotX + 17, slotY + 20, 8, RAYLIBColor(255, 60, 80, 220))
            ok
            if item[1] = ITEM_MPOT
                DrawCircle(slotX + 17, slotY + 20, 8, RAYLIBColor(80, 120, 255, 220))
            ok
            if item[1] = ITEM_SCROLL_FIRE
                DrawRectangle(slotX + 10, slotY + 8, 14, 18, RAYLIBColor(255, 180, 50, 220))
            ok
            if item[1] = ITEM_SCROLL_TELE
                DrawRectangle(slotX + 10, slotY + 8, 14, 18, RAYLIBColor(100, 200, 255, 220))
            ok
        ok
    next

    // Message log
    logX = 620
    for i = 1 to len(msgLog)
        al = 220
        if i < len(msgLog) al = 100 + (i * 20) ok
        if al > 220 al = 220 ok
        DrawText(msgLog[i], logX, hudY + 5 + (i - 1) * 12, 10, RAYLIBColor(200, 200, 220, al))
    next

    // FPS
    DrawText("" + string(GetFPS()) + " FPS", SCREEN_W - 55, hudY + 65, 10, RAYLIBColor(100, 200, 100, 80))

    // Help
    DrawText("WASD:Move E:Interact I:Inv Tab:Map 1-4:UseItem", 10, hudY + 55, 10, RAYLIBColor(120, 120, 140, 80))

// =============================================================
// Inventory Panel
// =============================================================

func rl_drawInventory
    panelW = 280
    panelH = 250
    panelX = (SCREEN_W - panelW) / 2
    panelY = 100

    DrawRectangle(panelX, panelY, panelW, panelH, RAYLIBColor(15, 12, 22, 240))
    DrawRectangleLines(panelX, panelY, panelW, panelH, RAYLIBColor(100, 80, 140, 200))
    DrawText("INVENTORY", panelX + 90, panelY + 8, 18, RAYLIBColor(255, 215, 0, 220))

    for i = 1 to MAX_INV
        iy = panelY + 35 + (i - 1) * 25
        DrawRectangle(panelX + 10, iy, panelW - 20, 22, RAYLIBColor(25, 20, 35, 200))

        if i <= len(inventory)
            item = inventory[i]
            DrawText("[" + string(i) + "] " + itemNames[item[1]], panelX + 15, iy + 4, 13, RAYLIBColor(200, 200, 220, 220))
            if item[2] > 0
                DrawText("+" + string(item[2]), panelX + panelW - 50, iy + 4, 13, RAYLIBColor(100, 200, 100, 200))
            ok
        else
            DrawText("[" + string(i) + "] ---", panelX + 15, iy + 4, 13, RAYLIBColor(80, 80, 100, 120))
        ok
    next

    // Equipment
    DrawText("Weapon: +" + string(pWeaponBonus) + " ATK", panelX + 15, panelY + panelH - 30, 12, RAYLIBColor(255, 150, 100, 180))
    DrawText("Armor: +" + string(pArmorBonus) + " DEF", panelX + 150, panelY + panelH - 30, 12, RAYLIBColor(100, 150, 255, 180))

// =============================================================
// Full Map
// =============================================================

func rl_drawFullMap
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 200))

    cs = 3    // cell size
    offX = (SCREEN_W - MAP_W * cs) / 2
    offY = (SCREEN_H - MAP_H * cs) / 2

    for y = 0 to MAP_H - 1
        for x = 0 to MAP_W - 1
            f = rl_getFog(x, y)
            if f = FOG_UNSEEN loop ok
            t = rl_getMap(x, y)

            col = RAYLIBColor(0, 0, 0, 0)
            if t = T_WALL  col = RAYLIBColor(80, 70, 90, 200) ok
            if t = T_FLOOR col = RAYLIBColor(50, 45, 40, 180) ok
            if t = T_CORR  col = RAYLIBColor(40, 38, 35, 160) ok
            if t = T_DOOR  col = RAYLIBColor(120, 80, 40, 200) ok
            if t = T_STAIR col = RAYLIBColor(200, 200, 80, 240) ok

            if f = FOG_SEEN
                // Dim
            ok

            DrawRectangle(offX + x * cs, offY + y * cs, cs, cs, col)
        next
    next

    // Entities
    for i = 1 to len(entities)
        if entities[i][9] = 0 loop ok
        if rl_getFog(entities[i][2], entities[i][3]) = FOG_VISIBLE
            DrawRectangle(offX + entities[i][2] * cs, offY + entities[i][3] * cs, cs, cs, RAYLIBColor(255, 80, 60, 240))
        ok
    next

    // Player
    DrawRectangle(offX + px * cs, offY + py * cs, cs, cs, RAYLIBColor(80, 200, 255, 255))

    DrawText("DUNGEON MAP - Floor " + string(pFloor), offX, offY - 20, 16, RAYLIBColor(200, 200, 220, 200))
    DrawText("Tab to close", offX, offY + MAP_H * cs + 5, 12, RAYLIBColor(150, 150, 170, 150))

// =============================================================
// Minimap
// =============================================================

func rl_drawMinimap
    mmX = SCREEN_W - 130
    mmY = 10
    cs = 2

    DrawRectangle(mmX - 2, mmY - 2, MAP_W * cs + 4, MAP_H * cs + 4, RAYLIBColor(0, 0, 0, 180))

    for y = 0 to MAP_H - 1
        for x = 0 to MAP_W - 1
            f = rl_getFog(x, y)
            if f = FOG_UNSEEN loop ok
            t = rl_getMap(x, y)
            if t = T_VOID loop ok

            col = RAYLIBColor(40, 35, 45, 120)
            if t = T_WALL col = RAYLIBColor(60, 55, 70, 150) ok
            if t = T_STAIR col = RAYLIBColor(200, 200, 80, 220) ok

            DrawRectangle(mmX + x * cs, mmY + y * cs, cs, cs, col)
        next
    next

    // Player
    DrawRectangle(mmX + px * cs, mmY + py * cs, cs, cs, RAYLIBColor(80, 200, 255, 255))
