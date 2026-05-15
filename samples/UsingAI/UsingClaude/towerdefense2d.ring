/*
**  Tower Defense 2D - RingRayLib
**  ===================================
**  Place turrets to defend against enemy waves!
**
**  Controls:
**    Mouse Left       - Select turret / Place turret
**    Mouse Right      - Cancel placement / Deselect
**    1-6              - Quick-select turret type
**    U                - Upgrade selected turret
**    X                - Sell selected turret (50% refund)
**    Space            - Start next wave / Fast forward
**    Tab              - Toggle grid overlay
**    M                - Cycle maps (1-3)
**    N                - New game
**    P                - Pause
**    ESC              - Exit
**
**  Turrets:
**    1. Arrow   ($10) - Fast single target
**    2. Cannon  ($25) - Slow splash damage
**    3. Frost   ($20) - Slows enemies
**    4. Laser   ($35) - Continuous beam, high DPS
**    5. Sniper  ($40) - Long range, high damage
**    6. Tesla   ($50) - Chain lightning to 3 targets
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W = 1024
SCREEN_H = 700

C_PI = 3.14159265

// Grid
CELL = 32
GRID_W = 28
GRID_H = 18
GRID_OX = 10
GRID_OY = 50

// Tile types
TL_EMPTY = 0
TL_PATH  = 1
TL_TOWER = 2
TL_START = 3
TL_END   = 4

// Turret types
TUR_ARROW  = 1
TUR_CANNON = 2
TUR_FROST  = 3
TUR_LASER  = 4
TUR_SNIPER = 5
TUR_TESLA  = 6

turNames = ["Arrow", "Cannon", "Frost", "Laser", "Sniper", "Tesla"]
turCost  = [10, 25, 20, 35, 40, 50]
turRange = [3.5, 3.0, 3.0, 2.5, 6.0, 3.5]
turRate  = [0.35, 1.2, 0.6, 0.08, 2.0, 1.0]
turDmg   = [8, 30, 3, 5, 60, 20]
turSplR  = [0, 1.8, 0, 0, 0, 0]
turSlow  = [0, 0, 0.5, 0, 0, 0]
turColR  = [180, 200, 100, 255, 220, 150]
turColG  = [160, 100, 180, 80, 180, 100]
turColB  = [80, 40, 255, 80, 60, 255]

// Enemy types
EN_NORMAL = 1
EN_FAST   = 2
EN_TANK   = 3
EN_HEAL   = 4
EN_BOSS   = 5
enBaseHP = [40, 25, 120, 50, 400]
enBaseSpd = [1.6, 2.8, 0.9, 1.4, 0.7]
enBaseRew = [5, 4, 12, 8, 50]

// =============================================================
// Grid
// =============================================================

grid = list(GRID_W * GRID_H)
for gInit = 1 to GRID_W * GRID_H
    grid[gInit] = TL_EMPTY
next

// Path: screen-space positions precomputed
MAX_PATH = 120
pathSX = list(MAX_PATH)
pathSY = list(MAX_PATH)
pathLen = 0

// =============================================================
// Towers (fixed pool)
// =============================================================

MAX_TOWERS = 60
towGX = list(MAX_TOWERS)    towGY = list(MAX_TOWERS)
towType = list(MAX_TOWERS)  towLvl = list(MAX_TOWERS)
towAngle = list(MAX_TOWERS) towTimer = list(MAX_TOWERS)
towKills = list(MAX_TOWERS) towAct = list(MAX_TOWERS)
for tInit = 1 to MAX_TOWERS
    towAct[tInit] = 0
next

// =============================================================
// Enemies (fixed pool with parallel arrays)
// =============================================================

MAX_EN = 80
enType   = list(MAX_EN)
enProg   = list(MAX_EN)
enHP     = list(MAX_EN)
enMaxHP  = list(MAX_EN)
enSpd    = list(MAX_EN)
enSlow   = list(MAX_EN)
enAct    = list(MAX_EN)
enRew    = list(MAX_EN)
for eInit = 1 to MAX_EN
    enAct[eInit] = 0
next

// =============================================================
// Projectiles (fixed pool)
// =============================================================

MAX_PROJ = 100
projX = list(MAX_PROJ)     projY = list(MAX_PROJ)
projTgt = list(MAX_PROJ)   projSpd = list(MAX_PROJ)
projDmg = list(MAX_PROJ)   projSplash = list(MAX_PROJ)
projSlowF = list(MAX_PROJ) projType = list(MAX_PROJ)
projAct = list(MAX_PROJ)
for pInit = 1 to MAX_PROJ
    projAct[pInit] = 0
next

// Beams (laser)
MAX_BEAMS = 20
beamTow = list(MAX_BEAMS)  beamEn = list(MAX_BEAMS)
beamTime = list(MAX_BEAMS)  beamAct = list(MAX_BEAMS)
for bInit = 1 to MAX_BEAMS
    beamAct[bInit] = 0
next

// Chain lightning
MAX_CHAINS = 20
chainX1 = list(MAX_CHAINS) chainY1 = list(MAX_CHAINS)
chainX2 = list(MAX_CHAINS) chainY2 = list(MAX_CHAINS)
chainTime = list(MAX_CHAINS) chainAct = list(MAX_CHAINS)
for cInit = 1 to MAX_CHAINS
    chainAct[cInit] = 0
next

// Particles
MAX_PARTS = 150
partX = list(MAX_PARTS)   partY = list(MAX_PARTS)
partVX = list(MAX_PARTS)  partVY = list(MAX_PARTS)
partLife = list(MAX_PARTS) partR = list(MAX_PARTS)
partG = list(MAX_PARTS)   partB = list(MAX_PARTS)
partAct = list(MAX_PARTS)
for ptInit = 1 to MAX_PARTS
    partAct[ptInit] = 0
next

// =============================================================
// Game State
// =============================================================

gold = 100
lives = 20
waveNum = 0
maxWaves = 20
waveActive = 0
waveSpawnTimer = 0.0
waveSpawnCount = 0
waveSpawnTotal = 0
waveTypes = list(60)

gameState = 1
animTime = 0.0
fastForward = 0
mapNum = 1

selTurType = 0
selTower = 0
showGrid = 1
hoverGX = -1
hoverGY = -1
isPaused = 0

msgText = ""
msgTimer = 0.0

// =============================================================
// Init
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Tower Defense 2D - RingRayLib")
SetTargetFPS(60)

td_loadMap(1)

while !WindowShouldClose()
    td_update()
    BeginDrawing()
        ClearBackground(RAYLIBColor(25, 35, 20, 255))
        td_draw()
    EndDrawing()
end

CloseWindow()

// =============================================================
// Grid Helpers
// =============================================================

func td_gIdx gx, gy
    if gx < 0 or gx >= GRID_W or gy < 0 or gy >= GRID_H return -1 ok
    return gy * GRID_W + gx + 1

func td_getG gx, gy
    idx = td_gIdx(gx, gy)
    if idx < 1 return TL_TOWER ok
    return grid[idx]

func td_setG gx, gy, val
    idx = td_gIdx(gx, gy)
    if idx >= 1 and idx <= GRID_W * GRID_H
        grid[idx] = val
    ok

// =============================================================
// Get enemy screen position by interpolating path progress
// =============================================================

func td_enScreenX ei
    prog = enProg[ei]
    if prog < 1 prog = 1 ok
    if prog >= pathLen prog = pathLen - 0.01 ok
    i1 = floor(prog)
    i2 = i1 + 1
    if i1 < 1 i1 = 1 ok
    if i2 > pathLen i2 = pathLen ok
    frac = prog - floor(prog)
    return pathSX[i1] + (pathSX[i2] - pathSX[i1]) * frac

func td_enScreenY ei
    prog = enProg[ei]
    if prog < 1 prog = 1 ok
    if prog >= pathLen prog = pathLen - 0.01 ok
    i1 = floor(prog)
    i2 = i1 + 1
    if i1 < 1 i1 = 1 ok
    if i2 > pathLen i2 = pathLen ok
    frac = prog - floor(prog)
    return pathSY[i1] + (pathSY[i2] - pathSY[i1]) * frac

// =============================================================
// Load Map
// =============================================================

func td_loadMap num
    mapNum = num
    gold = 100 + (num - 1) * 20
    lives = 20
    waveNum = 0
    waveActive = 0
    gameState = 1
    selTurType = 0
    selTower = 0
    fastForward = 0
    pathLen = 0

    for i = 1 to GRID_W * GRID_H
        grid[i] = TL_EMPTY
    next
    for i = 1 to MAX_TOWERS  towAct[i] = 0 next
    for i = 1 to MAX_EN      enAct[i] = 0 next
    for i = 1 to MAX_PROJ    projAct[i] = 0 next
    for i = 1 to MAX_BEAMS   beamAct[i] = 0 next
    for i = 1 to MAX_CHAINS  chainAct[i] = 0 next
    for i = 1 to MAX_PARTS   partAct[i] = 0 next

    if num = 1 td_buildMap1() ok
    if num = 2 td_buildMap2() ok
    if num = 3 td_buildMap3() ok

    td_msg("Map " + string(num) + " loaded. Press Space!")

func td_addPathNode gx, gy
    pathLen++
    if pathLen > MAX_PATH return ok
    pathSX[pathLen] = GRID_OX + gx * CELL + CELL / 2
    pathSY[pathLen] = GRID_OY + gy * CELL + CELL / 2
    td_setG(gx, gy, TL_PATH)

func td_msg t
    msgText = t
    msgTimer = 3.0

// =============================================================
// Map 1: S-curve
// =============================================================

func td_buildMap1
    td_addPathNode(0,4)   td_addPathNode(1,4)   td_addPathNode(2,4)
    td_addPathNode(3,4)   td_addPathNode(4,4)   td_addPathNode(5,4)
    td_addPathNode(6,4)   td_addPathNode(7,4)   td_addPathNode(8,4)
    td_addPathNode(9,4)   td_addPathNode(10,4)  td_addPathNode(11,4)
    td_addPathNode(11,5)  td_addPathNode(11,6)  td_addPathNode(11,7)
    td_addPathNode(11,8)  td_addPathNode(11,9)  td_addPathNode(11,10)
    td_addPathNode(10,10) td_addPathNode(9,10)  td_addPathNode(8,10)
    td_addPathNode(7,10)  td_addPathNode(6,10)  td_addPathNode(5,10)
    td_addPathNode(4,10)  td_addPathNode(3,10)
    td_addPathNode(3,11)  td_addPathNode(3,12)  td_addPathNode(3,13)  td_addPathNode(3,14)
    td_addPathNode(4,14)  td_addPathNode(5,14)  td_addPathNode(6,14)
    td_addPathNode(7,14)  td_addPathNode(8,14)  td_addPathNode(9,14)
    td_addPathNode(10,14) td_addPathNode(11,14) td_addPathNode(12,14)
    td_addPathNode(13,14) td_addPathNode(14,14) td_addPathNode(15,14)
    td_addPathNode(16,14) td_addPathNode(17,14)
    td_addPathNode(17,13) td_addPathNode(17,12) td_addPathNode(17,11)
    td_addPathNode(17,10) td_addPathNode(17,9)  td_addPathNode(17,8)
    td_addPathNode(18,8)  td_addPathNode(19,8)  td_addPathNode(20,8)
    td_addPathNode(21,8)  td_addPathNode(22,8)  td_addPathNode(23,8)
    td_addPathNode(24,8)  td_addPathNode(25,8)  td_addPathNode(26,8)
    td_addPathNode(27,8)
    td_setG(0, 4, TL_START)
    td_setG(27, 8, TL_END)

// =============================================================
// Map 2: Zigzag
// =============================================================

func td_buildMap2
    td_addPathNode(0,2)   td_addPathNode(1,2)   td_addPathNode(2,2)
    td_addPathNode(3,2)   td_addPathNode(4,2)   td_addPathNode(5,2)
    td_addPathNode(6,2)   td_addPathNode(7,2)   td_addPathNode(8,2)
    td_addPathNode(9,2)   td_addPathNode(10,2)  td_addPathNode(11,2)
    td_addPathNode(12,2)  td_addPathNode(13,2)  td_addPathNode(14,2)
    td_addPathNode(15,2)  td_addPathNode(16,2)  td_addPathNode(17,2)
    td_addPathNode(18,2)  td_addPathNode(19,2)  td_addPathNode(20,2)
    td_addPathNode(21,2)  td_addPathNode(22,2)  td_addPathNode(23,2)
    td_addPathNode(24,2)
    td_addPathNode(24,3)  td_addPathNode(24,4)  td_addPathNode(24,5)  td_addPathNode(24,6)
    td_addPathNode(23,6)  td_addPathNode(22,6)  td_addPathNode(21,6)
    td_addPathNode(20,6)  td_addPathNode(19,6)  td_addPathNode(18,6)
    td_addPathNode(17,6)  td_addPathNode(16,6)  td_addPathNode(15,6)
    td_addPathNode(14,6)  td_addPathNode(13,6)  td_addPathNode(12,6)
    td_addPathNode(11,6)  td_addPathNode(10,6)  td_addPathNode(9,6)
    td_addPathNode(8,6)   td_addPathNode(7,6)   td_addPathNode(6,6)
    td_addPathNode(5,6)   td_addPathNode(4,6)   td_addPathNode(3,6)
    td_addPathNode(3,7)   td_addPathNode(3,8)   td_addPathNode(3,9)   td_addPathNode(3,10)
    td_addPathNode(4,10)  td_addPathNode(5,10)  td_addPathNode(6,10)
    td_addPathNode(7,10)  td_addPathNode(8,10)  td_addPathNode(9,10)
    td_addPathNode(10,10) td_addPathNode(11,10) td_addPathNode(12,10)
    td_addPathNode(13,10) td_addPathNode(14,10) td_addPathNode(15,10)
    td_addPathNode(16,10) td_addPathNode(17,10) td_addPathNode(18,10)
    td_addPathNode(19,10) td_addPathNode(20,10) td_addPathNode(21,10)
    td_addPathNode(22,10) td_addPathNode(23,10) td_addPathNode(24,10)
    td_addPathNode(24,11) td_addPathNode(24,12) td_addPathNode(24,13)
    td_addPathNode(24,14) td_addPathNode(24,15)
    td_addPathNode(23,15) td_addPathNode(22,15) td_addPathNode(21,15)
    td_addPathNode(20,15) td_addPathNode(19,15) td_addPathNode(18,15)
    td_addPathNode(17,15) td_addPathNode(16,15) td_addPathNode(15,15)
    td_addPathNode(14,15) td_addPathNode(13,15) td_addPathNode(12,15)
    td_addPathNode(11,15) td_addPathNode(10,15) td_addPathNode(9,15)
    td_addPathNode(8,15)  td_addPathNode(7,15)  td_addPathNode(6,15)
    td_addPathNode(5,15)  td_addPathNode(4,15)  td_addPathNode(3,15)
    td_addPathNode(2,15)  td_addPathNode(1,15)  td_addPathNode(0,15)
    td_setG(0, 2, TL_START)
    td_setG(0, 15, TL_END)

// =============================================================
// Map 3: Spiral
// =============================================================

func td_buildMap3
    td_addPathNode(0,9)   td_addPathNode(1,9)   td_addPathNode(2,9)
    td_addPathNode(3,9)   td_addPathNode(4,9)   td_addPathNode(5,9)
    td_addPathNode(6,9)   td_addPathNode(7,9)   td_addPathNode(8,9)
    td_addPathNode(8,8)   td_addPathNode(8,7)   td_addPathNode(8,6)
    td_addPathNode(8,5)   td_addPathNode(8,4)   td_addPathNode(8,3)   td_addPathNode(8,2)
    td_addPathNode(9,2)   td_addPathNode(10,2)  td_addPathNode(11,2)
    td_addPathNode(12,2)  td_addPathNode(13,2)  td_addPathNode(14,2)
    td_addPathNode(15,2)  td_addPathNode(16,2)  td_addPathNode(17,2)
    td_addPathNode(18,2)  td_addPathNode(19,2)  td_addPathNode(20,2)
    td_addPathNode(20,3)  td_addPathNode(20,4)  td_addPathNode(20,5)
    td_addPathNode(20,6)  td_addPathNode(20,7)  td_addPathNode(20,8)
    td_addPathNode(20,9)  td_addPathNode(20,10) td_addPathNode(20,11)
    td_addPathNode(20,12) td_addPathNode(20,13) td_addPathNode(20,14) td_addPathNode(20,15)
    td_addPathNode(19,15) td_addPathNode(18,15) td_addPathNode(17,15)
    td_addPathNode(16,15) td_addPathNode(15,15) td_addPathNode(14,15)
    td_addPathNode(13,15) td_addPathNode(12,15) td_addPathNode(11,15)
    td_addPathNode(11,14) td_addPathNode(11,13) td_addPathNode(11,12)
    td_addPathNode(11,11) td_addPathNode(11,10) td_addPathNode(11,9)
    td_addPathNode(12,9)  td_addPathNode(13,9)  td_addPathNode(14,9)
    td_addPathNode(15,9)  td_addPathNode(16,9)  td_addPathNode(17,9)
    td_addPathNode(17,10) td_addPathNode(17,11) td_addPathNode(17,12)
    td_addPathNode(16,12) td_addPathNode(15,12) td_addPathNode(14,12)
    td_addPathNode(14,11) td_addPathNode(14,10)
    td_addPathNode(15,10)
    td_setG(0, 9, TL_START)
    td_setG(15, 10, TL_END)

// =============================================================
// Update
// =============================================================

func td_update
    dt = GetFrameTime()
    if dt > 0.05 dt = 0.05 ok
    animTime += dt

    if IsKeyPressed(KEY_ESCAPE)
        CloseWindow()
        shutdown(0)
    ok

    if IsKeyPressed(KEY_N) td_loadMap(mapNum) ok
    if IsKeyPressed(KEY_TAB) showGrid = !showGrid ok
    if IsKeyPressed(KEY_P) isPaused = !isPaused ok
    if IsKeyPressed(KEY_M)
        mapNum++
        if mapNum > 3 mapNum = 1 ok
        td_loadMap(mapNum)
    ok

    if msgTimer > 0
        msgTimer -= dt
        if msgTimer < 0 msgTimer = 0 ok
    ok

    if isPaused return ok
    if gameState != 1 return ok

    // Space = start wave or toggle fast forward
    if IsKeyPressed(KEY_SPACE)
        if waveActive = 0
            td_startWave()
        else
            if fastForward = 0 fastForward = 1
            else fastForward = 0 ok
        ok
    ok

    simDt = dt
    if fastForward = 1 simDt = dt * 3 ok

    // Mouse grid position
    hoverGX = floor((GetMouseX() - GRID_OX) / CELL)
    hoverGY = floor((GetMouseY() - GRID_OY) / CELL)

    // Quick-select turret
    if IsKeyPressed(KEY_ONE)   selTurType = TUR_ARROW  selTower = 0 ok
    if IsKeyPressed(KEY_TWO)   selTurType = TUR_CANNON selTower = 0 ok
    if IsKeyPressed(KEY_THREE) selTurType = TUR_FROST  selTower = 0 ok
    if IsKeyPressed(KEY_FOUR)  selTurType = TUR_LASER  selTower = 0 ok
    if IsKeyPressed(KEY_FIVE)  selTurType = TUR_SNIPER selTower = 0 ok
    if IsKeyPressed(KEY_SIX)   selTurType = TUR_TESLA  selTower = 0 ok

    if IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)
        selTurType = 0
        selTower = 0
    ok

    if IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
        td_handleClick()
    ok

    if IsKeyPressed(KEY_U) td_upgradeTower() ok
    if IsKeyPressed(KEY_X) td_sellTower() ok

    // Wave spawning
    if waveActive = 1
        td_updateWaveSpawn(simDt)
    ok

    td_updateEnemies(simDt)
    td_updateTowers(simDt)
    td_updateProjectiles(simDt)
    td_updateBeams(simDt)
    td_updateChains(simDt)
    td_updateParticles(simDt)

    // Check wave complete
    if waveActive = 1
        aliveCount = 0
        for ci = 1 to MAX_EN
            if enAct[ci] = 1 aliveCount++ ok
        next
        if aliveCount = 0 and waveSpawnCount >= waveSpawnTotal
            waveActive = 0
            fastForward = 0
            waveBonus = 5 + waveNum * 2
            gold += waveBonus
            if waveNum >= maxWaves
                gameState = 3
                td_msg("Victory! All waves defeated!")
            else
                td_msg("Wave " + string(waveNum) + " cleared! +$" + string(waveBonus))
            ok
        ok
    ok

// =============================================================
// Handle Click
// =============================================================

func td_handleClick
    gx = hoverGX
    gy = hoverGY

    if gx < 0 or gx >= GRID_W or gy < 0 or gy >= GRID_H
        td_handleShopClick()
        return
    ok

    tile = td_getG(gx, gy)

    // Placing turret
    if selTurType > 0
        if tile = TL_EMPTY
            cost = turCost[selTurType]
            if gold >= cost
                gold -= cost
                td_setG(gx, gy, TL_TOWER)
                td_placeTower(gx, gy, selTurType)
                td_msg("Placed " + turNames[selTurType] + "! (-$" + string(cost) + ")")
            else
                td_msg("Not enough gold! Need $" + string(cost))
            ok
        else
            td_msg("Can't build here!")
        ok
        return
    ok

    // Click existing tower
    for ti = 1 to MAX_TOWERS
        if towAct[ti] = 0 loop ok
        if towGX[ti] = gx and towGY[ti] = gy
            selTower = ti
            selTurType = 0
            return
        ok
    next
    selTower = 0

func td_handleShopClick
    shopY = GRID_OY + GRID_H * CELL + 10
    my = GetMouseY()
    mx = GetMouseX()
    if my < shopY or my > shopY + 50 return ok
    for st = 1 to 6
        bx = GRID_OX + (st - 1) * 100
        if mx >= bx and mx <= bx + 90
            selTurType = st
            selTower = 0
            return
        ok
    next

func td_placeTower gx, gy, ttype
    for ti = 1 to MAX_TOWERS
        if towAct[ti] = 1 loop ok
        towGX[ti] = gx
        towGY[ti] = gy
        towType[ti] = ttype
        towLvl[ti] = 1
        towAngle[ti] = 0.0
        towTimer[ti] = 0.0
        towKills[ti] = 0
        towAct[ti] = 1
        return
    next

// =============================================================
// Upgrade / Sell
// =============================================================

func td_upgradeTower
    if selTower < 1 or selTower > MAX_TOWERS return ok
    if towAct[selTower] = 0 return ok
    if towLvl[selTower] >= 3
        td_msg("Already max level!")
        return
    ok
    cost = turCost[towType[selTower]] * towLvl[selTower]
    if gold >= cost
        gold -= cost
        towLvl[selTower]++
        td_msg("Upgraded to Lv" + string(towLvl[selTower]) + "! (-$" + string(cost) + ")")
    else
        td_msg("Need $" + string(cost) + " to upgrade!")
    ok

func td_sellTower
    if selTower < 1 or selTower > MAX_TOWERS return ok
    if towAct[selTower] = 0 return ok
    refund = floor(turCost[towType[selTower]] * towLvl[selTower] * 0.5)
    gold += refund
    td_setG(towGX[selTower], towGY[selTower], TL_EMPTY)
    towAct[selTower] = 0
    td_msg("Sold turret! +$" + string(refund))
    selTower = 0

// =============================================================
// Wave System
// =============================================================

func td_startWave
    waveNum++
    waveActive = 1
    waveSpawnCount = 0
    waveSpawnTimer = 0.5

    waveSpawnTotal = 6 + waveNum * 2
    if waveSpawnTotal > 40 waveSpawnTotal = 40 ok

    for wi = 1 to waveSpawnTotal
        etype = EN_NORMAL
        rVal = GetRandomValue(1, 100)
        if waveNum >= 3 and rVal <= 25 etype = EN_FAST ok
        if waveNum >= 5 and rVal > 25 and rVal <= 40 etype = EN_TANK ok
        if waveNum >= 7 and rVal > 40 and rVal <= 50 etype = EN_HEAL ok
        if waveNum % 5 = 0 and wi = waveSpawnTotal etype = EN_BOSS ok
        waveTypes[wi] = etype
    next

    td_msg("Wave " + string(waveNum) + "/" + string(maxWaves) + " incoming!")

func td_updateWaveSpawn dt
    if waveSpawnCount >= waveSpawnTotal return ok
    waveSpawnTimer -= dt
    if waveSpawnTimer <= 0
        gap = 0.6 - waveNum * 0.01
        if gap < 0.2 gap = 0.2 ok
        waveSpawnTimer += gap

        waveSpawnCount++
        if waveSpawnCount <= waveSpawnTotal
            td_spawnEnemy(waveTypes[waveSpawnCount])
        ok
    ok

// =============================================================
// Enemy Spawn
// =============================================================

func td_spawnEnemy etype
    if pathLen < 2 return ok

    // Find a free slot
    slot = 0
    for si = 1 to MAX_EN
        if enAct[si] = 0
            slot = si
            exit
        ok
    next
    if slot = 0 return ok

    hpScale = 1.0 + waveNum * 0.15
    enType[slot] = etype
    enProg[slot] = 1.0
    enHP[slot] = floor(enBaseHP[etype] * hpScale)
    enMaxHP[slot] = enHP[slot]
    enSpd[slot] = enBaseSpd[etype]
    enSlow[slot] = 0.0
    enRew[slot] = enBaseRew[etype] + floor(waveNum * 0.5)
    enAct[slot] = 1

// =============================================================
// Update Enemies
// =============================================================

func td_updateEnemies dt
    for ei = 1 to MAX_EN
        if enAct[ei] = 0 loop ok

        spd2 = enSpd[ei]
        if enSlow[ei] > 0
            enSlow[ei] -= dt
            spd2 = spd2 * 0.4
        ok

        // Advance progress
        enProg[ei] += spd2 * dt

        // Reached the end?
        if enProg[ei] >= pathLen
            enAct[ei] = 0
            lives -= 1
            td_burstParts(pathSX[pathLen], pathSY[pathLen], 6, 255, 50, 50)
            if lives <= 0
                lives = 0
                gameState = 2
                td_msg("Defeated! Enemies broke through!")
            ok
            loop
        ok

        // Healer aura: heal nearby enemies
        if enType[ei] = EN_HEAL
            hx = td_enScreenX(ei)
            hy = td_enScreenY(ei)
            for hj = 1 to MAX_EN
                if hj = ei loop ok
                if enAct[hj] = 0 loop ok
                ox = td_enScreenX(hj) - hx
                oy = td_enScreenY(hj) - hy
                if ox * ox + oy * oy < 4096
                    enHP[hj] += 2.0 * dt
                    if enHP[hj] > enMaxHP[hj]
                        enHP[hj] = enMaxHP[hj]
                    ok
                ok
            next
        ok
    next

// =============================================================
// Towers Update
// =============================================================

func td_updateTowers dt
    for ti = 1 to MAX_TOWERS
        if towAct[ti] = 0 loop ok

        tx = GRID_OX + towGX[ti] * CELL + CELL / 2
        ty = GRID_OY + towGY[ti] * CELL + CELL / 2
        ttype = towType[ti]
        tlvl = towLvl[ti]

        rng = turRange[ttype] * CELL * (1 + (tlvl - 1) * 0.2)
        rate = turRate[ttype] / (1 + (tlvl - 1) * 0.25)
        dmg = turDmg[ttype] * (1 + (tlvl - 1) * 0.5)

        // Find closest enemy in range
        bestDist = rng * rng
        bestIdx = 0
        for ei = 1 to MAX_EN
            if enAct[ei] = 0 loop ok
            ex3 = td_enScreenX(ei)
            ey3 = td_enScreenY(ei)
            ddx = ex3 - tx
            ddy = ey3 - ty
            dd2 = ddx * ddx + ddy * ddy
            if dd2 < bestDist
                bestDist = dd2
                bestIdx = ei
            ok
        next

        // Aim
        if bestIdx > 0
            ex3 = td_enScreenX(bestIdx)
            ey3 = td_enScreenY(bestIdx)
            adx = ex3 - tx
            ady = ey3 - ty
            if fabs(adx) > 0.01
                tAngle = atan(ady / adx) * 180.0 / C_PI
                if adx < 0 tAngle += 180 ok
            else
                tAngle = 90
                if ady < 0 tAngle = -90 ok
            ok
            towAngle[ti] = tAngle
        ok

        // Fire
        towTimer[ti] -= dt
        if towTimer[ti] <= 0 and bestIdx > 0
            towTimer[ti] = rate

            if ttype = TUR_LASER
                td_addBeam(ti, bestIdx)
                td_damageEnemy(bestIdx, dmg * dt * 60, ti)
            ok
            if ttype = TUR_TESLA
                td_chainLightning(tx, ty, bestIdx, dmg, 3, ti)
            ok
            if ttype != TUR_LASER and ttype != TUR_TESLA
                td_fireProj(tx, ty, bestIdx, 350.0, dmg, turSplR[ttype] * CELL, turSlow[ttype], ttype)
            ok
        ok
    next

// =============================================================
// Damage Enemy
// =============================================================

func td_damageEnemy idx, dmg, towerIdx
    if idx < 1 or idx > MAX_EN return ok
    if enAct[idx] = 0 return ok
    enHP[idx] -= dmg
    if enHP[idx] <= 0
        enAct[idx] = 0
        gold += enRew[idx]
        if towerIdx > 0 and towerIdx <= MAX_TOWERS
            towKills[towerIdx]++
        ok
        td_burstParts(td_enScreenX(idx), td_enScreenY(idx), 8, 200, 150, 50)
    ok

// =============================================================
// Projectiles
// =============================================================

func td_fireProj px, py, tgt, spd3, dmg3, splash3, slow3, ptype3
    for pi2 = 1 to MAX_PROJ
        if projAct[pi2] = 1 loop ok
        projX[pi2] = px
        projY[pi2] = py
        projTgt[pi2] = tgt
        projSpd[pi2] = spd3
        projDmg[pi2] = dmg3
        projSplash[pi2] = splash3
        projSlowF[pi2] = slow3
        projType[pi2] = ptype3
        projAct[pi2] = 1
        return
    next

func td_updateProjectiles dt
    for pi2 = 1 to MAX_PROJ
        if projAct[pi2] = 0 loop ok
        tgt = projTgt[pi2]

        if tgt < 1 or tgt > MAX_EN or enAct[tgt] = 0
            projAct[pi2] = 0
            loop
        ok

        ex5 = td_enScreenX(tgt)
        ey5 = td_enScreenY(tgt)
        ddx = ex5 - projX[pi2]
        ddy = ey5 - projY[pi2]
        dist = sqrt(ddx * ddx + ddy * ddy)

        if dist < 8
            projAct[pi2] = 0

            if projSplash[pi2] > 0
                for se = 1 to MAX_EN
                    if enAct[se] = 0 loop ok
                    sdx = td_enScreenX(se) - projX[pi2]
                    sdy = td_enScreenY(se) - projY[pi2]
                    if sdx * sdx + sdy * sdy < projSplash[pi2] * projSplash[pi2]
                        td_damageEnemy(se, projDmg[pi2], 0)
                    ok
                next
                td_burstParts(projX[pi2], projY[pi2], 12, 255, 150, 50)
            else
                td_damageEnemy(tgt, projDmg[pi2], 0)
            ok

            if projSlowF[pi2] > 0
                enSlow[tgt] = 2.0
            ok
        else
            moveAmt = projSpd[pi2] * dt
            projX[pi2] += (ddx / dist) * moveAmt
            projY[pi2] += (ddy / dist) * moveAmt
        ok
    next

// =============================================================
// Beams (Laser)
// =============================================================

func td_addBeam towIdx, enIdx
    for bi = 1 to MAX_BEAMS
        if beamAct[bi] = 1 loop ok
        beamTow[bi] = towIdx
        beamEn[bi] = enIdx
        beamTime[bi] = 0.08
        beamAct[bi] = 1
        return
    next

func td_updateBeams dt
    for bi = 1 to MAX_BEAMS
        if beamAct[bi] = 0 loop ok
        beamTime[bi] -= dt
        if beamTime[bi] <= 0 beamAct[bi] = 0 ok
    next

// =============================================================
// Chain Lightning (Tesla)
// =============================================================

func td_chainLightning sx, sy, firstEn, dmg6, maxC, towerIdx
    td_damageEnemy(firstEn, dmg6, towerIdx)
    if firstEn < 1 or firstEn > MAX_EN return ok
    enSlow[firstEn] = 0.5

    prevCX = sx   prevCY = sy
    curCX = td_enScreenX(firstEn)
    curCY = td_enScreenY(firstEn)
    td_addChainVis(prevCX, prevCY, curCX, curCY)

    hitArr = list(MAX_EN)
    for hi = 1 to MAX_EN  hitArr[hi] = 0  next
    hitArr[firstEn] = 1

    for chain = 2 to maxC
        bestD = 99999.0
        bestE = 0
        for ce = 1 to MAX_EN
            if enAct[ce] = 0 loop ok
            if hitArr[ce] = 1 loop ok
            cdx = td_enScreenX(ce) - curCX
            cdy = td_enScreenY(ce) - curCY
            cd2 = cdx * cdx + cdy * cdy
            if cd2 < bestD and cd2 < (4 * CELL) * (4 * CELL)
                bestD = cd2
                bestE = ce
            ok
        next

        if bestE = 0 exit ok
        hitArr[bestE] = 1
        prevCX = curCX  prevCY = curCY
        curCX = td_enScreenX(bestE)
        curCY = td_enScreenY(bestE)
        td_addChainVis(prevCX, prevCY, curCX, curCY)
        td_damageEnemy(bestE, dmg6 * 0.7, towerIdx)
    next

func td_addChainVis x1, y1, x2, y2
    for ci = 1 to MAX_CHAINS
        if chainAct[ci] = 1 loop ok
        chainX1[ci] = x1  chainY1[ci] = y1
        chainX2[ci] = x2  chainY2[ci] = y2
        chainTime[ci] = 0.2
        chainAct[ci] = 1
        return
    next

func td_updateChains dt
    for ci = 1 to MAX_CHAINS
        if chainAct[ci] = 0 loop ok
        chainTime[ci] -= dt
        if chainTime[ci] <= 0 chainAct[ci] = 0 ok
    next

// =============================================================
// Particles
// =============================================================

func td_spawnPart px, py, vx7, vy7, life7, r7, g7, b7
    for pi3 = 1 to MAX_PARTS
        if partAct[pi3] = 1 loop ok
        partX[pi3] = px
        partY[pi3] = py
        partVX[pi3] = vx7
        partVY[pi3] = vy7
        partLife[pi3] = life7
        partR[pi3] = r7
        partG[pi3] = g7
        partB[pi3] = b7
        partAct[pi3] = 1
        return
    next

func td_burstParts px, py, count, r8, g8, b8
    for bp = 1 to count
        vx8 = GetRandomValue(-120, 120) * 1.0
        vy8 = GetRandomValue(-120, 120) * 1.0
        td_spawnPart(px, py, vx8, vy8, 0.5, r8, g8, b8)
    next

func td_updateParticles dt
    for pi3 = 1 to MAX_PARTS
        if partAct[pi3] = 0 loop ok
        partX[pi3] += partVX[pi3] * dt
        partY[pi3] += partVY[pi3] * dt
        partLife[pi3] -= dt
        if partLife[pi3] <= 0 partAct[pi3] = 0 ok
    next

// =============================================================
// Draw
// =============================================================

func td_draw
    // Grid tiles
    for gy = 0 to GRID_H - 1
        for gx = 0 to GRID_W - 1
            sx = GRID_OX + gx * CELL
            sy = GRID_OY + gy * CELL
            tl = td_getG(gx, gy)

            if tl = TL_EMPTY
                if (gx + gy) % 2 = 0
                    DrawRectangle(sx, sy, CELL, CELL, RAYLIBColor(35, 55, 30, 255))
                else
                    DrawRectangle(sx, sy, CELL, CELL, RAYLIBColor(38, 58, 33, 255))
                ok
            ok
            if tl = TL_PATH or tl = TL_START or tl = TL_END
                DrawRectangle(sx, sy, CELL, CELL, RAYLIBColor(80, 70, 50, 255))
                DrawRectangle(sx + 1, sy + 1, CELL - 2, CELL - 2, RAYLIBColor(90, 78, 55, 255))
            ok
            if tl = TL_START
                DrawRectangle(sx + 4, sy + 4, CELL - 8, CELL - 8, RAYLIBColor(80, 200, 80, 120))
            ok
            if tl = TL_END
                DrawRectangle(sx + 4, sy + 4, CELL - 8, CELL - 8, RAYLIBColor(200, 60, 60, 120))
            ok
            if tl = TL_TOWER
                DrawRectangle(sx, sy, CELL, CELL, RAYLIBColor(50, 50, 45, 255))
            ok
        next
    next

    // Grid overlay
    if showGrid = 1
        for gx = 0 to GRID_W
            DrawLine(GRID_OX + gx * CELL, GRID_OY, GRID_OX + gx * CELL, GRID_OY + GRID_H * CELL, RAYLIBColor(255, 255, 255, 15))
        next
        for gy = 0 to GRID_H
            DrawLine(GRID_OX, GRID_OY + gy * CELL, GRID_OX + GRID_W * CELL, GRID_OY + gy * CELL, RAYLIBColor(255, 255, 255, 15))
        next
    ok

    // Range preview
    if selTurType > 0 and hoverGX >= 0 and hoverGX < GRID_W and hoverGY >= 0 and hoverGY < GRID_H
        hcx = GRID_OX + hoverGX * CELL + CELL / 2
        hcy = GRID_OY + hoverGY * CELL + CELL / 2
        rng2 = floor(turRange[selTurType] * CELL)
        canP = (td_getG(hoverGX, hoverGY) = TL_EMPTY)
        if canP
            DrawCircleLines(hcx, hcy, rng2, RAYLIBColor(100, 255, 100, 60))
            DrawRectangle(GRID_OX + hoverGX * CELL, GRID_OY + hoverGY * CELL, CELL, CELL, RAYLIBColor(100, 255, 100, 40))
        else
            DrawRectangle(GRID_OX + hoverGX * CELL, GRID_OY + hoverGY * CELL, CELL, CELL, RAYLIBColor(255, 60, 60, 40))
        ok
    ok

    // Selected tower range
    if selTower > 0 and selTower <= MAX_TOWERS and towAct[selTower] = 1
        scx = GRID_OX + towGX[selTower] * CELL + CELL / 2
        scy = GRID_OY + towGY[selTower] * CELL + CELL / 2
        srng = floor(turRange[towType[selTower]] * CELL * (1 + (towLvl[selTower] - 1) * 0.2))
        DrawCircleLines(scx, scy, srng, RAYLIBColor(255, 220, 100, 80))
    ok

    // Beams
    for bi = 1 to MAX_BEAMS
        if beamAct[bi] = 0 loop ok
        bti = beamTow[bi]   bei = beamEn[bi]
        if bti < 1 or bti > MAX_TOWERS or towAct[bti] = 0 loop ok
        if bei < 1 or bei > MAX_EN or enAct[bei] = 0 loop ok
        btx = GRID_OX + towGX[bti] * CELL + CELL / 2
        bty = GRID_OY + towGY[bti] * CELL + CELL / 2
        bex = floor(td_enScreenX(bei))
        bey = floor(td_enScreenY(bei))
        bal = floor(beamTime[bi] / 0.08 * 200)
        if bal > 255 bal = 255 ok
        DrawLine(btx, bty, bex, bey, RAYLIBColor(255, 80, 80, bal))
        DrawLine(btx + 1, bty + 1, bex + 1, bey + 1, RAYLIBColor(255, 150, 100, floor(bal * 0.5)))
    next

    // Chain lightning
    for ci = 1 to MAX_CHAINS
        if chainAct[ci] = 0 loop ok
        cal = floor(chainTime[ci] / 0.2 * 230)
        if cal > 255 cal = 255 ok
        lcx = chainX1[ci]   lcy = chainY1[ci]
        segs = 6
        ldx = (chainX2[ci] - chainX1[ci]) / segs
        ldy = (chainY2[ci] - chainY1[ci]) / segs
        for ls = 1 to segs
            lnx = chainX1[ci] + ldx * ls + GetRandomValue(-5, 5)
            lny = chainY1[ci] + ldy * ls + GetRandomValue(-5, 5)
            if ls = segs lnx = chainX2[ci]  lny = chainY2[ci] ok
            DrawLine(floor(lcx), floor(lcy), floor(lnx), floor(lny), RAYLIBColor(150, 130, 255, cal))
            lcx = lnx   lcy = lny
        next
    next

    // Towers
    for ti = 1 to MAX_TOWERS
        if towAct[ti] = 0 loop ok
        td_drawTower(ti)
    next

    // Projectiles
    for pi2 = 1 to MAX_PROJ
        if projAct[pi2] = 0 loop ok
        pt = projType[pi2]
        DrawCircle(floor(projX[pi2]), floor(projY[pi2]), 3, RAYLIBColor(turColR[pt], turColG[pt], turColB[pt], 240))
        DrawCircle(floor(projX[pi2]), floor(projY[pi2]), 5, RAYLIBColor(turColR[pt], turColG[pt], turColB[pt], 60))
    next

    // Enemies
    for ei = 1 to MAX_EN
        if enAct[ei] = 0 loop ok
        td_drawEnemy(ei)
    next

    // Particles
    for pi3 = 1 to MAX_PARTS
        if partAct[pi3] = 0 loop ok
        pal = floor(partLife[pi3] / 0.5 * 200)
        if pal > 200 pal = 200 ok
        if pal < 0 loop ok
        DrawCircle(floor(partX[pi3]), floor(partY[pi3]), 2, RAYLIBColor(partR[pi3], partG[pi3], partB[pi3], pal))
    next

    // HUD
    td_drawHUD()

    // Game Over / Win
    if gameState = 2
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(80, 0, 0, 150))
        DrawText("DEFEAT!", SCREEN_W / 2 - 70, SCREEN_H / 2 - 30, 36, RAYLIBColor(255, 60, 60, 255))
        DrawText("Wave " + string(waveNum) + "  Press N to restart", SCREEN_W / 2 - 120, SCREEN_H / 2 + 15, 16, RAYLIBColor(200, 200, 200, 200))
    ok
    if gameState = 3
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 50, 30, 140))
        DrawText("VICTORY!", SCREEN_W / 2 - 80, SCREEN_H / 2 - 30, 36, RAYLIBColor(100, 255, 150, 255))
        DrawText("All " + string(maxWaves) + " waves defeated!", SCREEN_W / 2 - 90, SCREEN_H / 2 + 15, 16, RAYLIBColor(200, 255, 200, 220))
        DrawText("Press M for next map or N for new game", SCREEN_W / 2 - 145, SCREEN_H / 2 + 40, 14, RAYLIBColor(180, 220, 180, 180))
    ok

// =============================================================
// Draw Tower
// =============================================================

func td_drawTower idx
    tx = GRID_OX + towGX[idx] * CELL + CELL / 2
    ty = GRID_OY + towGY[idx] * CELL + CELL / 2
    ttype = towType[idx]
    tlvl = towLvl[idx]
    angle = towAngle[idx] * C_PI / 180.0

    cr = turColR[ttype]   cg = turColG[ttype]   cb = turColB[ttype]

    // Base square
    bs = CELL / 2 - 2
    DrawRectangle(tx - bs, ty - bs, bs * 2, bs * 2, RAYLIBColor(60, 60, 55, 255))

    // Body
    if ttype = TUR_ARROW
        DrawCircle(tx, ty, 8, RAYLIBColor(cr, cg, cb, 220))
        bx2 = tx + floor(cos(angle) * 12)
        by2 = ty + floor(sin(angle) * 12)
        DrawLine(tx, ty, bx2, by2, RAYLIBColor(255, 255, 200, 230))
    ok
    if ttype = TUR_CANNON
        DrawCircle(tx, ty, 10, RAYLIBColor(cr, cg, cb, 220))
        bx2 = tx + floor(cos(angle) * 14)
        by2 = ty + floor(sin(angle) * 14)
        DrawLine(tx, ty, bx2, by2, RAYLIBColor(200, 100, 40, 230))
        DrawLine(tx + 1, ty + 1, bx2 + 1, by2 + 1, RAYLIBColor(200, 100, 40, 180))
    ok
    if ttype = TUR_FROST
        DrawCircle(tx, ty, 9, RAYLIBColor(cr, cg, cb, 200))
        DrawCircleLines(tx, ty, 10, RAYLIBColor(180, 220, 255, 150))
    ok
    if ttype = TUR_LASER
        DrawCircle(tx, ty, 7, RAYLIBColor(cr, cg, cb, 220))
        DrawCircle(tx, ty, 4, RAYLIBColor(255, 120, 120, 180))
    ok
    if ttype = TUR_SNIPER
        DrawCircle(tx, ty, 8, RAYLIBColor(cr, cg, cb, 220))
        bx2 = tx + floor(cos(angle) * 16)
        by2 = ty + floor(sin(angle) * 16)
        DrawLine(tx, ty, bx2, by2, RAYLIBColor(255, 220, 100, 240))
    ok
    if ttype = TUR_TESLA
        DrawCircle(tx, ty, 9, RAYLIBColor(cr, cg, cb, 200))
        pulse = floor(fabs(sin(animTime * 5)) * 80) + 40
        DrawCircle(tx, ty, 5, RAYLIBColor(180, 150, 255, pulse))
    ok

    // Level pips
    for lp = 1 to tlvl
        DrawCircle(tx - 8 + (lp - 1) * 8, ty + 10, 2, RAYLIBColor(255, 215, 0, 200))
    next

    // Selection highlight
    if selTower = idx
        DrawRectangleLines(tx - bs - 2, ty - bs - 2, bs * 2 + 4, bs * 2 + 4, RAYLIBColor(255, 255, 100, 200))
    ok

// =============================================================
// Draw Enemy
// =============================================================

func td_drawEnemy idx
    ex = floor(td_enScreenX(idx))
    ey = floor(td_enScreenY(idx))
    etype = enType[idx]
    hp2 = enHP[idx]
    mhp = enMaxHP[idx]
    if mhp < 1 mhp = 1 ok

    sz = 8

    if etype = EN_NORMAL
        DrawCircle(ex, ey, sz, RAYLIBColor(220, 60, 60, 240))
        DrawCircle(ex, ey, sz - 3, RAYLIBColor(240, 90, 90, 180))
    ok
    if etype = EN_FAST
        sz = 6
        DrawCircle(ex, ey, sz, RAYLIBColor(255, 200, 50, 240))
        DrawLine(ex - 8, ey, ex - 13, ey, RAYLIBColor(255, 200, 50, 120))
        DrawLine(ex - 9, ey - 3, ex - 13, ey - 3, RAYLIBColor(255, 200, 50, 80))
    ok
    if etype = EN_TANK
        sz = 12
        DrawCircle(ex, ey, sz, RAYLIBColor(100, 120, 160, 240))
        DrawCircle(ex, ey, sz - 3, RAYLIBColor(80, 100, 140, 200))
    ok
    if etype = EN_HEAL
        sz = 8
        DrawCircle(ex, ey, sz, RAYLIBColor(60, 200, 60, 240))
        DrawRectangle(ex - 1, ey - 4, 3, 9, RAYLIBColor(255, 255, 255, 180))
        DrawRectangle(ex - 4, ey - 1, 9, 3, RAYLIBColor(255, 255, 255, 180))
    ok
    if etype = EN_BOSS
        sz = 16
        DrawCircle(ex, ey, sz, RAYLIBColor(200, 50, 200, 240))
        DrawCircle(ex, ey, sz - 4, RAYLIBColor(230, 80, 230, 180))
        DrawTriangle(Vector2(ex - 6, ey - sz + 2), Vector2(ex, ey - sz - 6), Vector2(ex + 6, ey - sz + 2),
                    RAYLIBColor(255, 215, 0, 220))
    ok

    // Slow ring
    if enSlow[idx] > 0
        DrawCircleLines(ex, ey, sz + 3, RAYLIBColor(100, 180, 255, 120))
    ok

    // HP bar
    hpFrac = hp2 / (mhp * 1.0)
    barW = sz * 2
    DrawRectangle(ex - barW / 2, ey - sz - 6, barW, 3, RAYLIBColor(40, 0, 0, 200))
    DrawRectangle(ex - barW / 2, ey - sz - 6, floor(barW * hpFrac), 3, RAYLIBColor(60, 220, 60, 230))

// =============================================================
// HUD
// =============================================================

func td_drawHUD
    // Top bar
    DrawRectangle(0, 0, SCREEN_W, 46, RAYLIBColor(10, 15, 10, 240))
    DrawText("Tower Defense 2D", 10, 6, 18, RAYLIBColor(255, 215, 0, 220))
    DrawText("Gold: $" + string(gold), 200, 8, 16, RAYLIBColor(255, 220, 50, 230))
    DrawText("Lives: " + string(lives), 350, 8, 16, RAYLIBColor(255, 100, 100, 220))
    DrawText("Wave: " + string(waveNum) + "/" + string(maxWaves), 480, 8, 16, RAYLIBColor(150, 200, 255, 200))

    if waveActive = 1
        if fastForward = 1
            DrawText(">>> FAST >>>", 630, 8, 14, RAYLIBColor(255, 255, 100, 200))
        else
            DrawText("IN PROGRESS", 630, 8, 14, RAYLIBColor(255, 200, 100, 180))
        ok
    else
        if gameState = 1
            DrawText("[Space] Next Wave", 630, 8, 14, RAYLIBColor(100, 255, 100, 180))
        ok
    ok

    DrawText("Map " + string(mapNum), 810, 8, 14, RAYLIBColor(180, 200, 180, 160))
    DrawText("" + string(GetFPS()) + " FPS", SCREEN_W - 55, 8, 10, RAYLIBColor(100, 200, 100, 100))
    DrawText("1-6:Turret U:Upgrade X:Sell Tab:Grid M:Map P:Pause", 200, 30, 10, RAYLIBColor(150, 160, 140, 100))

    if isPaused = 1
        DrawText("PAUSED", SCREEN_W / 2 - 35, 30, 14, RAYLIBColor(255, 255, 100, 200))
    ok

    // Enemy count indicator
    enCount = 0
    for di = 1 to MAX_EN
        if enAct[di] = 1 enCount++ ok
    next
    DrawText("Enemies: " + string(enCount), 810, 30, 10, RAYLIBColor(200, 200, 200, 120))

    // Shop bar
    shopY = GRID_OY + GRID_H * CELL + 8
    DrawRectangle(0, shopY - 4, SCREEN_W, 60, RAYLIBColor(15, 20, 15, 240))

    for st = 1 to 6
        bx = GRID_OX + (st - 1) * 100
        by = shopY

        isSel = (selTurType = st)
        canBuy = (gold >= turCost[st])

        bgR = 40  bgG = 50  bgB = 40
        if isSel bgR = 60  bgG = 80  bgB = 50 ok
        if !canBuy bgR = 35  bgG = 30  bgB = 30 ok

        DrawRectangle(bx, by, 90, 44, RAYLIBColor(bgR, bgG, bgB, 255))
        DrawRectangleLines(bx, by, 90, 44, RAYLIBColor(100, 120, 80, 150))
        if isSel
            DrawRectangleLines(bx - 1, by - 1, 92, 46, RAYLIBColor(255, 220, 50, 200))
        ok

        DrawCircle(bx + 16, by + 22, 8, RAYLIBColor(turColR[st], turColG[st], turColB[st], 220))
        DrawText(turNames[st], bx + 30, by + 6, 11, RAYLIBColor(200, 220, 200, 220))

        costR = 200  costG = 200  costB = 100
        if !canBuy  costR = 160  costG = 80  costB = 80 ok
        DrawText("$" + string(turCost[st]), bx + 30, by + 20, 12, RAYLIBColor(costR, costG, costB, 200))
        DrawText("[" + string(st) + "]", bx + 30, by + 33, 10, RAYLIBColor(150, 150, 150, 100))
    next

    // Selected tower info panel
    if selTower > 0 and selTower <= MAX_TOWERS and towAct[selTower] = 1
        infoX = GRID_OX + 650
        infoY = shopY

        DrawRectangle(infoX, infoY, 220, 44, RAYLIBColor(30, 35, 30, 240))
        DrawRectangleLines(infoX, infoY, 220, 44, RAYLIBColor(100, 120, 80, 150))

        DrawText(turNames[towType[selTower]] + " Lv" + string(towLvl[selTower]), infoX + 8, infoY + 4, 13, RAYLIBColor(255, 220, 100, 230))
        DrawText("Kills: " + string(towKills[selTower]), infoX + 8, infoY + 20, 11, RAYLIBColor(180, 200, 180, 180))

        if towLvl[selTower] < 3
            ucost = turCost[towType[selTower]] * towLvl[selTower]
            DrawText("[U]pgrade $" + string(ucost), infoX + 90, infoY + 4, 11, RAYLIBColor(100, 255, 100, 200))
        ok
        refund2 = floor(turCost[towType[selTower]] * towLvl[selTower] * 0.5)
        DrawText("[X]Sell $" + string(refund2), infoX + 90, infoY + 20, 11, RAYLIBColor(255, 150, 100, 200))
    ok

    // Message
    if msgTimer > 0 and len(msgText) > 0
        mw = MeasureText(msgText, 16) + 20
        ma = 220
        if msgTimer < 0.5 ma = floor(msgTimer * 440) ok
        DrawRectangle((SCREEN_W - mw) / 2, GRID_OY - 22, mw, 22, RAYLIBColor(0, 0, 0, ma))
        DrawText(msgText, (SCREEN_W - mw) / 2 + 10, GRID_OY - 19, 16, RAYLIBColor(255, 255, 200, ma))
    ok
