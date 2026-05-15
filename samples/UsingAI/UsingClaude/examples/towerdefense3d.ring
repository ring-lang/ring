/*
**  3D Tower Defense - Using RingRayLib
**  =====================================
**  Defend your base by placing towers along the enemy path!
**  Enemies follow a winding path across the grid. Build and
**  upgrade towers to stop them before they reach the exit.
**
**  Controls:
**    Mouse Click         -  Place tower on grass / Select tower
**    1 / 2 / 3 / 4      -  Choose tower type
**    U                   -  Upgrade selected tower
**    S                   -  Sell selected tower (50% refund)
**    N                   -  Send next wave early (+25 gold bonus)
**    P                   -  Pause / Unpause
**    C                   -  Cycle camera angle
**    R                   -  Restart game
**    ESC                 -  Exit
**
**  Tower Types:
**    1 - Arrow  (50g)  - Fast, low damage
**    2 - Cannon (100g) - Slow, high damage
**    3 - Ice    (75g)  - Slows enemies down
**    4 - Tesla  (150g) - Chain lightning to nearby
**
**  Features:
**    - 12x16 grid with winding enemy path
**    - 15 enemy waves of increasing difficulty
**    - 4 tower types with distinct behaviors
**    - 3 upgrade levels per tower
**    - Sell towers for 50% refund
**    - Mouse-based tower placement with preview
**    - Projectile system with homing
**    - 4 enemy types (normal, fast, tank, boss)
**    - Enemy health bars above heads
**    - Particle effects on hit and kill
**    - Gold economy with wave completion bonuses
**    - 20 lives, score tracking
**    - Two camera angles: top-down and angled
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W    = 1024
SCREEN_H    = 768

GRID_ROWS   = 12
GRID_COLS   = 16
CELL        = 2.0

T_GRASS     = 0
T_PATH      = 1
T_TOWER     = 2

TW_ARROW    = 1
TW_CANNON   = 2
TW_ICE      = 3
TW_TESLA    = 4

ST_TITLE    = 1
ST_PLAY     = 2
ST_PAUSE    = 3
ST_WON      = 4
ST_LOST     = 5

CAM_TOP     = 1
CAM_ANGLE   = 2
CAM_MODES   = 2

// =============================================================
// Global Variables
// =============================================================

grid        = []
waypoints   = []
wpCount     = 0

towerList   = []
enemyList   = []
projList    = []
partList    = []

gameState   = ST_TITLE
animTime    = 0.0
camMode     = CAM_TOP

gold        = 200
lives       = 20
score       = 0

curWave     = 0
maxWaves    = 15
waveOn      = false
betweenW    = true
waveTimer   = 0.0
spawnTimer  = 0.0
spawnIdx    = 0
spawnMax    = 0
wavePause   = 4.0

selBuild    = TW_ARROW
selTower    = 0

mRow        = 0
mCol        = 0
mValid      = false

cpX = 0.0  cpY = 0.0  cpZ = 0.0
ctX = 0.0  ctY = 0.0  ctZ = 0.0

// =============================================================
// Map & Path (inline, before functions)
// =============================================================

// Build grid
grid = list(GRID_ROWS)
for r = 1 to GRID_ROWS
    grid[r] = list(GRID_COLS)
    for c = 1 to GRID_COLS
        grid[r][c] = T_GRASS
    next
next

// Enemy path waypoints (hand-traced, entry top to exit bottom-right)
waypoints = [
    [1,5], [2,5],
    [3,5], [3,6], [3,7], [3,8], [3,9],
    [4,9],
    [5,9], [5,10], [5,11], [5,12], [5,13],
    [6,13], [7,13],
    [8,13], [9,13],
    [10,13], [10,12], [10,11], [10,10], [10,9], [10,8], [10,7],
    [11,7],
    [12,7], [12,8], [12,9], [12,10], [12,11], [12,12], [12,13]
]
wpCount = len(waypoints)

// Mark path tiles on grid
for i = 1 to wpCount
    grid[waypoints[i][1]][waypoints[i][2]] = T_PATH
next

// Extra decorative path tiles (inner loops visible but not walked)
decorPath = [
    [3,3], [3,4],
    [4,3], [5,3], [6,3], [7,3], [8,3], [8,4], [8,5],
    [5,5], [5,6], [5,7],
    [6,5], [7,5],
    [6,7], [7,7], [7,8], [7,9], [7,10], [7,11],
    [8,11], [9,11]
]
for i = 1 to len(decorPath)
    grid[decorPath[i][1]][decorPath[i][2]] = T_PATH
next

// =============================================================
// Main Program
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Ring 3D Tower Defense - RingRayLib")
SetTargetFPS(60)

camera = Camera3D(
    0, 30, 5,
    0,  0, 0,
    0,  1, 0,
    45,
    CAMERA_PERSPECTIVE
)

centerX = GRID_COLS * CELL / 2
centerZ = GRID_ROWS * CELL / 2
cpX = centerX   cpY = 30.0   cpZ = centerZ + 6.0
ctX = centerX   ctY = 0.0    ctZ = centerZ

// =============================================================
// Main Game Loop
// =============================================================

while !WindowShouldClose()

    dt = GetFrameTime()
    if dt > 0.05 dt = 0.05 ok
    animTime += dt

    if IsKeyPressed(KEY_R) td_resetGame() ok
    if IsKeyPressed(KEY_C)
        camMode += 1
        if camMode > CAM_MODES camMode = CAM_TOP ok
    ok
    if IsKeyPressed(KEY_ONE)   selBuild = TW_ARROW  ok
    if IsKeyPressed(KEY_TWO)   selBuild = TW_CANNON ok
    if IsKeyPressed(KEY_THREE) selBuild = TW_ICE    ok
    if IsKeyPressed(KEY_FOUR)  selBuild = TW_TESLA  ok

    stateHandled = false

    if gameState = ST_TITLE and !stateHandled
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            td_resetGame()
            gameState = ST_PLAY
            stateHandled = true
        ok
    ok

    if gameState = ST_PLAY and !stateHandled
        if IsKeyPressed(KEY_P)
            gameState = ST_PAUSE
            stateHandled = true
        else
            td_pickMouse()
            td_handleClick()
            td_updateWaves(dt)
            td_updateEnemies(dt)
            td_updateTowers(dt)
            td_updateProj(dt)
            td_updateParts(dt)
            td_checkEnd()
        ok
    ok

    if gameState = ST_PAUSE and !stateHandled
        if IsKeyPressed(KEY_P) or IsKeyPressed(KEY_SPACE)
            gameState = ST_PLAY
            stateHandled = true
        ok
    ok

    if gameState = ST_WON and !stateHandled
        td_updateParts(dt)
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            td_resetGame()
            stateHandled = true
        ok
    ok

    if gameState = ST_LOST and !stateHandled
        td_updateParts(dt)
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            td_resetGame()
            stateHandled = true
        ok
    ok

    td_moveCamera()

    BeginDrawing()
        ClearBackground(RAYLIBColor(12, 18, 12, 255))

        if gameState = ST_TITLE
            td_drawTitle()
        else
            BeginMode3D(camera)
                td_drawGround()
                td_drawPathTiles()
                td_drawTowers3D()
                td_drawEnemies3D()
                td_drawProj3D()
                td_drawParts3D()
                td_drawHover()
            EndMode3D()

            td_drawHUD()
            td_drawPanel()

            if gameState = ST_PAUSE td_drawPause() ok
            if gameState = ST_WON   td_drawWin()   ok
            if gameState = ST_LOST  td_drawLose()  ok
        ok

        DrawFPS(10, 10)
    EndDrawing()

end

CloseWindow()

// =============================================================
// ALL FUNCTIONS BELOW
// =============================================================

func td_resetGame
    for r = 1 to GRID_ROWS
        for c = 1 to GRID_COLS
            if grid[r][c] = T_TOWER grid[r][c] = T_GRASS ok
        next
    next
    towerList  = []
    enemyList  = []
    projList   = []
    partList   = []
    gold       = 200
    lives      = 20
    score      = 0
    curWave    = 0
    waveOn     = false
    betweenW   = true
    waveTimer  = 0.0
    spawnTimer = 0.0
    spawnIdx   = 0
    spawnMax   = 0
    selBuild   = TW_ARROW
    selTower   = 0
    gameState  = ST_PLAY

// =============================================================
// Mouse Picking
// =============================================================

func td_pickMouse
    // Manual screen-to-world projection (avoids GetMouseRay struct issues)
    mx = GetMouseX()
    my = GetMouseY()

    // Compute grid cell from screen coordinates mathematically
    // using the camera's known fixed position

    // Camera looks from (cpX, cpY, cpZ) at (ctX, 0, ctZ)
    // For a top-down camera, the mapping is approximately:
    // worldX = ctX + (mx/SCREEN_W - 0.5) * visibleWidth
    // worldZ = ctZ + (my/SCREEN_H - 0.5) * visibleHeight

    // Visible width/height depend on FOV and camera height
    // FOV = 45 degrees, height = cpY
    // halfH = cpY * tan(FOV/2) -- vertical half-extent at ground
    // halfW = halfH * aspect

    fovRad = 45.0 * 3.14159 / 180.0
    halfH = cpY * tan(fovRad / 2.0)
    aspect = SCREEN_W / SCREEN_H
    halfW = halfH * aspect

    // Normalized screen coords (-1 to 1) from mouse
    ndcX = (mx / SCREEN_W - 0.5) * 2.0
    ndcY = (my / SCREEN_H - 0.5) * 2.0

    mValid = false

    if camMode = CAM_TOP
        // Top-down: camera above center looking straight down
        // offset due to cpZ being slightly south of ctZ
        hx = ctX + ndcX * halfW
        hz = ctZ + ndcY * halfH
        c2 = floor(hx / CELL) + 1
        r2 = floor(hz / CELL) + 1
        if r2 >= 1 and r2 <= GRID_ROWS and c2 >= 1 and c2 <= GRID_COLS
            mRow = r2
            mCol = c2
            mValid = true
        ok
    ok

    if camMode = CAM_ANGLE
        // Angled camera: use approximate projection
        // The camera is offset, so mouse mapping is skewed
        // Use a simpler approximation: cast from camera pos through
        // a virtual screen plane, find intersection with Y=0

        // Forward direction
        fwdX = ctX - cpX
        fwdY = ctY - cpY
        fwdZ = ctZ - cpZ
        fLen = sqrt(fwdX*fwdX + fwdY*fwdY + fwdZ*fwdZ)
        if fLen > 0.001
            fwdX = fwdX / fLen  fwdY = fwdY / fLen  fwdZ = fwdZ / fLen
        ok

        // Right vector (fwd cross up)
        upX = 0  upY = 1  upZ = 0
        rightX = fwdY * upZ - fwdZ * upY
        rightY = fwdZ * upX - fwdX * upZ
        rightZ = fwdX * upY - fwdY * upX
        rLen = sqrt(rightX*rightX + rightY*rightY + rightZ*rightZ)
        if rLen > 0.001
            rightX = rightX / rLen  rightY = rightY / rLen  rightZ = rightZ / rLen
        ok

        // True up vector (right cross fwd)
        trueUpX = rightY * fwdZ - rightZ * fwdY
        trueUpY = rightZ * fwdX - rightX * fwdZ
        trueUpZ = rightX * fwdY - rightY * fwdX

        // Ray direction from camera through screen point
        rayDirX = fwdX + ndcX * halfW / fLen * rightX + ndcY * halfH / fLen * trueUpX
        rayDirY = fwdY + ndcX * halfW / fLen * rightY + ndcY * halfH / fLen * trueUpY
        rayDirZ = fwdZ + ndcX * halfW / fLen * rightZ + ndcY * halfH / fLen * trueUpZ

        // Intersect with Y=0 plane: cpY + t * rayDirY = 0
        if rayDirY != 0
            t = -cpY / rayDirY
            if t > 0
                hx = cpX + t * rayDirX
                hz = cpZ + t * rayDirZ
                c2 = floor(hx / CELL) + 1
                r2 = floor(hz / CELL) + 1
                if r2 >= 1 and r2 <= GRID_ROWS and c2 >= 1 and c2 <= GRID_COLS
                    mRow = r2
                    mCol = c2
                    mValid = true
                ok
            ok
        ok
    ok

// =============================================================
// Click Handling
// =============================================================

func td_handleClick
    if IsMouseButtonPressed(MOUSE_LEFT_BUTTON) and mValid
        idx = td_twAt(mRow, mCol)
        if idx > 0
            selTower = idx
            return
        ok
        if grid[mRow][mCol] = T_GRASS
            cost = td_cost(selBuild, 1)
            if gold >= cost
                gold -= cost
                grid[mRow][mCol] = T_TOWER
                add(towerList, [mRow, mCol, selBuild, 1, 0.0, 0])
                selTower = len(towerList)
            ok
        ok
    ok

    if IsKeyPressed(KEY_U) and selTower > 0 and selTower <= len(towerList)
        tw = towerList[selTower]
        if tw[4] < 3
            uc = td_cost(tw[3], tw[4] + 1)
            if gold >= uc
                gold -= uc
                towerList[selTower][4] += 1
            ok
        ok
    ok

    if IsKeyPressed(KEY_S) and selTower > 0 and selTower <= len(towerList)
        tw = towerList[selTower]
        refund = floor(td_cost(tw[3], tw[4]) * 0.5)
        gold += refund
        grid[tw[1]][tw[2]] = T_GRASS
        del(towerList, selTower)
        selTower = 0
    ok

    if IsKeyPressed(KEY_N) and betweenW and curWave < maxWaves
        gold += 25
        td_launchWave()
    ok

// =============================================================
// Tower Stat Helpers
// =============================================================

func td_cost tp, lv
    base = 50
    if tp = TW_CANNON base = 100 ok
    if tp = TW_ICE    base = 75  ok
    if tp = TW_TESLA  base = 150 ok
    return base + (lv - 1) * floor(base * 0.6)

func td_range tp, lv
    base = 4.5
    if tp = TW_CANNON base = 3.8 ok
    if tp = TW_ICE    base = 4.0 ok
    if tp = TW_TESLA  base = 5.0 ok
    return base + (lv - 1) * 0.7

func td_dmg tp, lv
    base = 10
    if tp = TW_CANNON base = 30 ok
    if tp = TW_ICE    base = 5  ok
    if tp = TW_TESLA  base = 18 ok
    return base + (lv - 1) * floor(base * 0.5)

func td_rate tp, lv
    base = 0.45
    if tp = TW_CANNON base = 1.4 ok
    if tp = TW_ICE    base = 0.7 ok
    if tp = TW_TESLA  base = 1.0 ok
    return base - (lv - 1) * base * 0.12

func td_twName tp
    if tp = TW_ARROW  return "Arrow"  ok
    if tp = TW_CANNON return "Cannon" ok
    if tp = TW_ICE    return "Ice"    ok
    if tp = TW_TESLA  return "Tesla"  ok
    return "?"

func td_twAt r, c
    for i = 1 to len(towerList)
        if towerList[i][1] = r and towerList[i][2] = c return i ok
    next
    return 0

// =============================================================
// Wave System
// =============================================================

func td_updateWaves dt
    if betweenW
        waveTimer += dt
        if waveTimer >= wavePause
            td_launchWave()
        ok
        return
    ok
    if !waveOn return ok

    spawnTimer += dt
    gap = 0.8 - curWave * 0.025
    if gap < 0.25 gap = 0.25 ok

    if spawnTimer >= gap and spawnIdx < spawnMax
        spawnTimer -= gap
        spawnIdx += 1
        td_spawnEnemy()
    ok

    if spawnIdx >= spawnMax
        alive = false
        for i = 1 to len(enemyList)
            if enemyList[i][6] alive = true ok
        next
        if !alive
            waveOn = false
            betweenW = true
            waveTimer = 0.0
            gold += 15 + curWave * 5
        ok
    ok

func td_launchWave
    curWave += 1
    waveOn = true
    betweenW = false
    waveTimer = 0.0
    spawnTimer = 0.0
    spawnIdx = 0
    spawnMax = 5 + curWave * 2
    if spawnMax > 35 spawnMax = 35 ok

func td_spawnEnemy
    et = 1
    if curWave >= 4  and GetRandomValue(1, 100) <= 30 et = 2 ok
    if curWave >= 7  and GetRandomValue(1, 100) <= 20 et = 3 ok
    if curWave >= 11 and GetRandomValue(1, 100) <= 12 et = 4 ok
    hp = 30 + curWave * 15
    spd = 2.2
    rew = 5 + curWave
    if et = 2 hp = floor(hp * 0.6)  spd = 3.8  rew = floor(rew * 0.8) ok
    if et = 3 hp = floor(hp * 2.2)  spd = 1.4  rew = floor(rew * 1.5) ok
    if et = 4 hp = floor(hp * 3.5)  spd = 1.0  rew = floor(rew * 3.0) ok
    add(enemyList, [1.0, hp, hp, spd, rew, true, 0.0, et])

// =============================================================
// Enemy Update
// =============================================================

func td_updateEnemies dt
    for i = 1 to len(enemyList)
        if !enemyList[i][6] loop ok
        mult = 1.0
        if enemyList[i][7] > 0
            enemyList[i][7] -= dt
            mult = 0.35
            if enemyList[i][7] < 0 enemyList[i][7] = 0 ok
        ok
        enemyList[i][1] += enemyList[i][4] * mult * dt
        if enemyList[i][1] >= wpCount
            enemyList[i][6] = false
            lives -= 1
            td_burst(td_eX(i), 0.5, td_eZ(i), 255, 50, 50)
        ok
    next

func td_eX idx
    pi = enemyList[idx][1]
    if pi < 1 pi = 1 ok
    if pi >= wpCount pi = wpCount - 0.01 ok
    i1 = floor(pi)
    i2 = i1 + 1
    if i2 > wpCount i2 = wpCount ok
    t = pi - i1
    x1 = (waypoints[i1][2] - 1) * CELL + CELL / 2
    x2 = (waypoints[i2][2] - 1) * CELL + CELL / 2
    return x1 + (x2 - x1) * t

func td_eZ idx
    pi = enemyList[idx][1]
    if pi < 1 pi = 1 ok
    if pi >= wpCount pi = wpCount - 0.01 ok
    i1 = floor(pi)
    i2 = i1 + 1
    if i2 > wpCount i2 = wpCount ok
    t = pi - i1
    z1 = (waypoints[i1][1] - 1) * CELL + CELL / 2
    z2 = (waypoints[i2][1] - 1) * CELL + CELL / 2
    return z1 + (z2 - z1) * t

// =============================================================
// Tower Targeting & Firing
// =============================================================

func td_updateTowers dt
    for i = 1 to len(towerList)
        towerList[i][5] -= dt
        if towerList[i][5] > 0 loop ok
        tr = towerList[i][1]
        tc = towerList[i][2]
        tp = towerList[i][3]
        lv = towerList[i][4]
        twX = (tc - 1) * CELL + CELL / 2
        twZ = (tr - 1) * CELL + CELL / 2
        rng = td_range(tp, lv)
        dmg = td_dmg(tp, lv)

        bestE = 0
        bestProg = 0
        for e = 1 to len(enemyList)
            if !enemyList[e][6] loop ok
            ex = td_eX(e)
            ez = td_eZ(e)
            dx = ex - twX
            dz = ez - twZ
            d = sqrt(dx * dx + dz * dz)
            if d <= rng and enemyList[e][1] > bestProg
                bestProg = enemyList[e][1]
                bestE = e
            ok
        next

        if bestE > 0
            towerList[i][5] = td_rate(tp, lv)
            towerList[i][6] = bestE
            ex = td_eX(bestE)
            ez = td_eZ(bestE)
            pspd = 16.0
            if tp = TW_CANNON pspd = 11.0 ok
            if tp = TW_TESLA  pspd = 28.0 ok
            add(projList, [twX, 1.8, twZ, pspd, dmg, tp, bestE, true])
        ok
    next

// =============================================================
// Projectile Update
// =============================================================

func td_updateProj dt
    i = 1
    while i <= len(projList)
        if !projList[i][8]
            del(projList, i)
            loop
        ok
        tgt = projList[i][7]
        tgtOk = false
        if tgt >= 1 and tgt <= len(enemyList)
            if enemyList[tgt][6] tgtOk = true ok
        ok
        if !tgtOk
            projList[i][8] = false
            i += 1
            loop
        ok

        ex = td_eX(tgt)
        ez = td_eZ(tgt)
        dx = ex - projList[i][1]
        dy = 0.5 - projList[i][2]
        dz = ez - projList[i][3]
        dist = sqrt(dx*dx + dy*dy + dz*dz)

        if dist < 0.6
            projList[i][8] = false
            dmg = projList[i][5]
            pt = projList[i][6]
            enemyList[tgt][2] -= dmg
            if pt = TW_ICE enemyList[tgt][7] = 2.5 ok

            if pt = TW_TESLA
                chainD = floor(dmg * 0.4)
                for ce = 1 to len(enemyList)
                    if ce = tgt or !enemyList[ce][6] loop ok
                    cex = td_eX(ce)
                    cez = td_eZ(ce)
                    cdx = cex - ex
                    cdz = cez - ez
                    cd = sqrt(cdx*cdx + cdz*cdz)
                    if cd < 3.5
                        enemyList[ce][2] -= chainD
                        td_burst(cex, 0.6, cez, 140, 200, 255)
                        if enemyList[ce][2] <= 0
                            enemyList[ce][6] = false
                            gold += enemyList[ce][5]
                            score += enemyList[ce][5] * 2
                            td_burst(cex, 0.5, cez, 255, 120, 40)
                        ok
                    ok
                next
            ok

            td_burst(ex, 0.6, ez, 255, 200, 60)
            if enemyList[tgt][2] <= 0
                enemyList[tgt][6] = false
                gold += enemyList[tgt][5]
                score += enemyList[tgt][5] * 2
                td_burst(ex, 0.5, ez, 255, 100, 40)
            ok
        else
            spd = projList[i][4] * dt / dist
            if spd > 1.0 spd = 1.0 ok
            projList[i][1] += dx * spd
            projList[i][2] += dy * spd
            projList[i][3] += dz * spd
        ok
        i += 1
    end

// =============================================================
// Win / Lose
// =============================================================

func td_checkEnd
    if lives <= 0
        gameState = ST_LOST
        return
    ok
    if curWave >= maxWaves and !waveOn and betweenW
        anyA = false
        for i = 1 to len(enemyList)
            if enemyList[i][6] anyA = true ok
        next
        if !anyA gameState = ST_WON ok
    ok

// =============================================================
// Particles
// =============================================================

func td_burst wx, wy, wz, pr, pg, pb
    for k = 1 to 6
        vx = (GetRandomValue(-100, 100) / 100.0) * 2.5
        vy = (GetRandomValue(60, 220) / 100.0)
        vz = (GetRandomValue(-100, 100) / 100.0) * 2.5
        cr = pr + GetRandomValue(-25, 25)
        cg = pg + GetRandomValue(-25, 25)
        cb = pb + GetRandomValue(-25, 25)
        if cr < 0 cr = 0 ok  if cr > 255 cr = 255 ok
        if cg < 0 cg = 0 ok  if cg > 255 cg = 255 ok
        if cb < 0 cb = 0 ok  if cb > 255 cb = 255 ok
        add(partList, [wx, wy, wz, vx, vy, vz, 0.9, cr, cg, cb])
    next

func td_updateParts dt
    i = 1
    while i <= len(partList)
        partList[i][1] += partList[i][4] * dt
        partList[i][2] += partList[i][5] * dt
        partList[i][3] += partList[i][6] * dt
        partList[i][5] -= 5.0 * dt
        partList[i][7] -= dt * 1.4
        if partList[i][7] <= 0
            del(partList, i)
        else
            i += 1
        ok
    end

func td_drawParts3D
    for i = 1 to len(partList)
        p = partList[i]
        alpha = floor(p[7] / 0.9 * 255)
        if alpha > 255 alpha = 255 ok
        if alpha < 0   alpha = 0   ok
        sz = 0.05 + p[7] * 0.08
        DrawSphereEx(Vector3(p[1], p[2], p[3]), sz, 4, 4,
            RAYLIBColor(p[8], p[9], p[10], alpha))
    next

// =============================================================
// Camera
// =============================================================

func td_moveCamera
    cx = GRID_COLS * CELL / 2
    cz = GRID_ROWS * CELL / 2
    gX = cx   gY = 30.0   gZ = cz + 5.0   tX = cx   tZ = cz
    if camMode = CAM_ANGLE
        gX = cx + 6.0   gY = 22.0   gZ = cz + 14.0
    ok
    sp = 0.07
    cpX += (gX - cpX) * sp
    cpY += (gY - cpY) * sp
    cpZ += (gZ - cpZ) * sp
    ctX += (tX - ctX) * sp
    ctY = 0.0
    ctZ += (tZ - ctZ) * sp
    camera.position.x = cpX
    camera.position.y = cpY
    camera.position.z = cpZ
    camera.target.x   = ctX
    camera.target.y   = ctY
    camera.target.z   = ctZ

// =============================================================
// Drawing: Ground
// =============================================================

func td_drawGround
    for r = 1 to GRID_ROWS
        for c = 1 to GRID_COLS
            if grid[r][c] != T_PATH
                wx = (c - 1) * CELL + CELL / 2
                wz = (r - 1) * CELL + CELL / 2
                if (r + c) % 2 = 0
                    gc = RAYLIBColor(32, 62, 28, 255)
                else
                    gc = RAYLIBColor(38, 70, 32, 255)
                ok
                DrawCube(Vector3(wx, -0.05, wz), CELL, 0.1, CELL, gc)
            ok
        next
    next

// =============================================================
// Drawing: Path
// =============================================================

func td_drawPathTiles
    // Main waypoint tiles
    for i = 1 to wpCount
        pr = waypoints[i][1]
        pc = waypoints[i][2]
        wx = (pc - 1) * CELL + CELL / 2
        wz = (pr - 1) * CELL + CELL / 2
        pcol = RAYLIBColor(85, 72, 55, 255)
        if i = 1      pcol = RAYLIBColor(50, 200, 50, 255)  ok
        if i = wpCount pcol = RAYLIBColor(220, 50, 50, 255) ok
        DrawCube(Vector3(wx, -0.02, wz), CELL - 0.08, 0.06, CELL - 0.08, pcol)
    next

    // Decorative inner tiles
    for i = 1 to len(decorPath)
        ir = decorPath[i][1]
        ic = decorPath[i][2]
        onWP = false
        for w = 1 to wpCount
            if waypoints[w][1] = ir and waypoints[w][2] = ic onWP = true ok
        next
        if !onWP
            wx = (ic - 1) * CELL + CELL / 2
            wz = (ir - 1) * CELL + CELL / 2
            DrawCube(Vector3(wx, -0.02, wz), CELL - 0.08, 0.06, CELL - 0.08,
                RAYLIBColor(70, 60, 48, 200))
        ok
    next

    // Direction dots
    for i = 1 to wpCount - 1
        x1 = (waypoints[i][2] - 1) * CELL + CELL / 2
        z1 = (waypoints[i][1] - 1) * CELL + CELL / 2
        x2 = (waypoints[i+1][2] - 1) * CELL + CELL / 2
        z2 = (waypoints[i+1][1] - 1) * CELL + CELL / 2
        DrawSphere(Vector3((x1+x2)/2, 0.05, (z1+z2)/2), 0.06,
            RAYLIBColor(120, 105, 75, 100))
    next

// =============================================================
// Drawing: Towers
// =============================================================

func td_drawTowers3D
    for i = 1 to len(towerList)
        tw = towerList[i]
        tp = tw[3]  lv = tw[4]
        wx = (tw[2] - 1) * CELL + CELL / 2
        wz = (tw[1] - 1) * CELL + CELL / 2

        // Platform
        DrawCube(Vector3(wx, 0.15, wz), 1.5, 0.3, 1.5, RAYLIBColor(75, 78, 85, 255))
        DrawCubeWires(Vector3(wx, 0.15, wz), 1.5, 0.3, 1.5, RAYLIBColor(95, 98, 105, 150))

        tH = 1.0 + lv * 0.4
        bc = RAYLIBColor(55, 150, 55, 255)
        wc = RAYLIBColor(75, 190, 75, 180)
        if tp = TW_CANNON bc = RAYLIBColor(170, 85, 40, 255)  wc = RAYLIBColor(210, 120, 60, 180) ok
        if tp = TW_ICE    bc = RAYLIBColor(55, 135, 210, 255) wc = RAYLIBColor(75, 175, 250, 180) ok
        if tp = TW_TESLA  bc = RAYLIBColor(190, 170, 40, 255) wc = RAYLIBColor(230, 210, 60, 180) ok

        DrawCube(Vector3(wx, 0.3 + tH/2, wz), 0.8, tH, 0.8, bc)
        DrawCubeWires(Vector3(wx, 0.3 + tH/2, wz), 0.8, tH, 0.8, wc)

        topY = 0.3 + tH + 0.15
        DrawSphere(Vector3(wx, topY, wz), 0.22 + lv * 0.05, bc)

        // Level stars
        for lvi = 1 to lv
            ang = lvi * 2.094
            DrawSphere(Vector3(wx + cos(ang) * 0.5, 0.35, wz + sin(ang) * 0.5),
                0.07, RAYLIBColor(255, 215, 0, 255))
        next

        // Range ring when selected
        if i = selTower
            DrawCircle3D(Vector3(wx, 0.06, wz), td_range(tp, lv),
                Vector3(1, 0, 0), 90.0, RAYLIBColor(255, 255, 80, 70))
        ok

        // Fire line to target (brief flash)
        if tw[6] > 0 and tw[6] <= len(enemyList)
            if towerList[i][5] > td_rate(tp, lv) * 0.5
                if enemyList[tw[6]][6]
                    DrawLine3D(Vector3(wx, topY, wz),
                        Vector3(td_eX(tw[6]), 0.5, td_eZ(tw[6])),
                        RAYLIBColor(255, 255, 100, 30))
                ok
            ok
        ok
    next

// =============================================================
// Drawing: Enemies
// =============================================================

func td_drawEnemies3D
    for i = 1 to len(enemyList)
        if !enemyList[i][6] loop ok
        ex = td_eX(i)
        ez = td_eZ(i)
        et = enemyList[i][8]

        ec = RAYLIBColor(210, 55, 55, 255)
        er = 0.4
        if et = 2 ec = RAYLIBColor(55, 210, 55, 255)  er = 0.32 ok
        if et = 3 ec = RAYLIBColor(210, 55, 210, 255)  er = 0.55 ok
        if et = 4 ec = RAYLIBColor(210, 170, 40, 255)  er = 0.65 ok

        ey = er + 0.05 + sin(animTime * 3.5 + i * 0.8) * 0.05
        DrawSphereEx(Vector3(ex, ey, ez), er, 10, 10, ec)

        if enemyList[i][7] > 0
            DrawSphereEx(Vector3(ex, ey, ez), er + 0.18, 6, 6,
                RAYLIBColor(60, 160, 255, 35))
        ok

        DrawCircle3D(Vector3(ex, 0.01, ez), er + 0.1,
            Vector3(1, 0, 0), 90.0, RAYLIBColor(0, 0, 0, 50))

        // HP bar
        hpPct = enemyList[i][2] / enemyList[i][3]
        if hpPct < 0 hpPct = 0 ok
        barW = 1.2
        barY = ey + er + 0.35
        DrawCube(Vector3(ex, barY, ez), barW, 0.08, 0.05,
            RAYLIBColor(35, 35, 35, 200))
        fW = barW * hpPct
        fX = ex - (barW - fW) / 2
        rr = floor(255 * (1 - hpPct))
        gg = floor(255 * hpPct)
        if rr > 255 rr = 255 ok
        if gg > 255 gg = 255 ok
        DrawCube(Vector3(fX, barY, ez), fW, 0.08, 0.06,
            RAYLIBColor(rr, gg, 30, 230))
    next

// =============================================================
// Drawing: Projectiles
// =============================================================

func td_drawProj3D
    for i = 1 to len(projList)
        if !projList[i][8] loop ok
        p = projList[i]
        pt = p[6]
        if pt = TW_ARROW
            DrawSphere(Vector3(p[1], p[2], p[3]), 0.1, RAYLIBColor(200, 255, 200, 255))
        ok
        if pt = TW_CANNON
            DrawSphere(Vector3(p[1], p[2], p[3]), 0.2, RAYLIBColor(255, 140, 40, 255))
            DrawSphereEx(Vector3(p[1], p[2], p[3]), 0.32, 4, 4,
                RAYLIBColor(255, 180, 80, 40))
        ok
        if pt = TW_ICE
            DrawSphere(Vector3(p[1], p[2], p[3]), 0.14, RAYLIBColor(100, 200, 255, 255))
        ok
        if pt = TW_TESLA
            DrawSphere(Vector3(p[1], p[2], p[3]), 0.16, RAYLIBColor(255, 255, 80, 255))
            DrawSphereEx(Vector3(p[1], p[2], p[3]), 0.3, 4, 4,
                RAYLIBColor(255, 255, 140, 35))
        ok
    next

// =============================================================
// Drawing: Mouse Hover
// =============================================================

func td_drawHover
    if !mValid return ok
    if gameState != ST_PLAY return ok
    wx = (mCol - 1) * CELL + CELL / 2
    wz = (mRow - 1) * CELL + CELL / 2

    if grid[mRow][mCol] = T_GRASS
        cost = td_cost(selBuild, 1)
        if gold >= cost
            hc = RAYLIBColor(80, 255, 80, 45)
        else
            hc = RAYLIBColor(255, 80, 80, 45)
        ok
        DrawCube(Vector3(wx, 0.25, wz), CELL * 0.85, 0.5, CELL * 0.85, hc)
        DrawCircle3D(Vector3(wx, 0.06, wz), td_range(selBuild, 1),
            Vector3(1, 0, 0), 90.0, RAYLIBColor(200, 200, 80, 35))
    ok
    DrawCubeWires(Vector3(wx, 0.05, wz), CELL, 0.1, CELL,
        RAYLIBColor(255, 255, 255, 60))

// =============================================================
// HUD
// =============================================================

func td_drawHUD
    DrawRectangle(10, 28, SCREEN_W - 20, 28, Fade(BLACK, 0.75))
    DrawText("Gold: " + gold, 20, 32, 17, RAYLIBColor(255, 215, 0, 255))
    DrawText("Lives: " + lives, 150, 32, 17, RAYLIBColor(255, 80, 80, 255))
    DrawText("Score: " + score, 280, 32, 17, WHITE)

    wt = "Wave " + curWave + "/" + maxWaves
    if betweenW and curWave < maxWaves
        rem = floor(wavePause - waveTimer)
        if rem < 0 rem = 0 ok
        wt += "   Next: " + rem + "s  [N=rush +25g]"
    ok
    if waveOn wt += "   Spawning..." ok
    DrawText(wt, 430, 32, 15, RAYLIBColor(180, 200, 255, 230))

    cn = "TOP"
    if camMode = CAM_ANGLE cn = "ANGLE" ok
    DrawText("Cam:" + cn + " [C]", SCREEN_W - 140, 32, 14, RAYLIBColor(130, 150, 170, 200))

// =============================================================
// Tower Panel (bottom)
// =============================================================

func td_drawPanel
    py = SCREEN_H - 78
    DrawRectangle(10, py, SCREEN_W - 20, 68, Fade(BLACK, 0.82))
    DrawRectangleLines(10, py, SCREEN_W - 20, 68, RAYLIBColor(70, 110, 70, 200))

    twT = [TW_ARROW, TW_CANNON, TW_ICE, TW_TESLA]
    twN = ["1:Arrow", "2:Cannon", "3:Ice", "4:Tesla"]
    twC = [50, 100, 75, 150]

    for i = 1 to 4
        bx = 18 + (i - 1) * 135
        by = py + 7
        if twT[i] = selBuild
            DrawRectangle(bx, by, 125, 53, RAYLIBColor(55, 95, 55, 220))
        else
            DrawRectangle(bx, by, 125, 53, RAYLIBColor(35, 48, 35, 180))
        ok
        DrawRectangleLines(bx, by, 125, 53, RAYLIBColor(90, 140, 90, 200))

        dc = RAYLIBColor(55, 180, 55, 255)
        if i = 2 dc = RAYLIBColor(210, 120, 55, 255) ok
        if i = 3 dc = RAYLIBColor(75, 175, 250, 255) ok
        if i = 4 dc = RAYLIBColor(230, 210, 55, 255) ok
        DrawRectangle(bx + 4, by + 4, 11, 11, dc)

        nc = RAYLIBColor(195, 215, 195, 255)
        if twC[i] > gold nc = RAYLIBColor(140, 75, 75, 200) ok
        DrawText(twN[i], bx + 19, by + 3, 14, nc)
        DrawText("Cost:" + twC[i], bx + 19, by + 20, 12, RAYLIBColor(255, 215, 0, 200))
        DrawText("D:" + td_dmg(twT[i], 1) + " R:" + floor(td_range(twT[i], 1)),
            bx + 4, by + 37, 11, RAYLIBColor(150, 175, 150, 175))
    next

    // Selected tower info
    if selTower > 0 and selTower <= len(towerList)
        tw = towerList[selTower]
        ix = 575
        DrawText("Sel: " + td_twName(tw[3]) + " Lv" + tw[4], ix, py + 7, 16,
            RAYLIBColor(200, 255, 200, 255))
        DrawText("DMG:" + td_dmg(tw[3], tw[4]) + " RNG:" + floor(td_range(tw[3], tw[4])),
            ix, py + 26, 13, RAYLIBColor(175, 200, 175, 220))
        if tw[4] < 3
            uc = td_cost(tw[3], tw[4] + 1)
            DrawText("[U]pgrade:" + uc + "g", ix, py + 44, 13, RAYLIBColor(255, 215, 0, 200))
        else
            DrawText("MAX LEVEL", ix, py + 44, 13, RAYLIBColor(80, 255, 80, 200))
        ok
        sv = floor(td_cost(tw[3], tw[4]) * 0.5)
        DrawText("[S]ell:+" + sv + "g", ix + 155, py + 44, 13, RAYLIBColor(255, 150, 90, 200))
    else
        DrawText("Click a tower to select for upgrade/sell", 575, py + 22, 13,
            RAYLIBColor(130, 150, 130, 160))
    ok

// =============================================================
// Title Screen
// =============================================================

func td_drawTitle
    DrawRectangleGradientV(0, 0, SCREEN_W, SCREEN_H,
        RAYLIBColor(8, 16, 8, 255), RAYLIBColor(14, 24, 14, 255))

    t1 = "3D TOWER DEFENSE"
    t1w = MeasureText(t1, 52)
    DrawText(t1, (SCREEN_W - t1w)/2, 90, 52, RAYLIBColor(70, 220, 70, 255))

    t2 = "~ Build towers to stop the enemy waves! ~"
    t2w = MeasureText(t2, 18)
    DrawText(t2, (SCREEN_W - t2w)/2, 155, 18, RAYLIBColor(130, 200, 130, 220))

    cy = 195
    cLines = [
        "Mouse Click on grass  -  Place selected tower",
        "Mouse Click on tower  -  Select for upgrade / sell",
        "1 / 2 / 3 / 4        -  Choose tower type",
        "U                     -  Upgrade selected tower",
        "S                     -  Sell tower (50% refund)",
        "N                     -  Send next wave early (+25 gold)",
        "P                     -  Pause / Unpause",
        "C                     -  Cycle camera angle",
        "R                     -  Restart game",
        "",
        "Arrow (50g)   - Fast fire, low damage",
        "Cannon (100g) - Slow fire, high splash damage",
        "Ice (75g)     - Slows enemies for 2.5 seconds",
        "Tesla (150g)  - Chain lightning hits nearby enemies",
        "",
        "Red = Normal   Green = Fast   Purple = Tank   Gold = Boss"
    ]
    for i = 1 to len(cLines)
        lw = MeasureText(cLines[i], 15)
        if i >= 11
            col = RAYLIBColor(255, 200, 90, 220)
        else
            col = RAYLIBColor(155, 200, 155, 230)
        ok
        DrawText(cLines[i], (SCREEN_W - lw)/2, cy + (i - 1) * 22, 15, col)
    next

    if floor(animTime * 2) % 2 = 0
        st = "Press ENTER or SPACE to Start"
        stw = MeasureText(st, 26)
        DrawText(st, (SCREEN_W - stw)/2, 575, 26, WHITE)
    ok

    cr = "Developed using Ring Language + RingRayLib"
    crw = MeasureText(cr, 14)
    DrawText(cr, (SCREEN_W - crw)/2, SCREEN_H - 35, 14, RAYLIBColor(75, 115, 75, 175))

// =============================================================
// Overlays
// =============================================================

func td_drawPause
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.5))
    pt = "PAUSED"
    ptw = MeasureText(pt, 50)
    DrawText(pt, (SCREEN_W - ptw)/2, SCREEN_H/2 - 40, 50, WHITE)
    p2 = "Press P or SPACE to resume"
    p2w = MeasureText(p2, 20)
    DrawText(p2, (SCREEN_W - p2w)/2, SCREEN_H/2 + 25, 20, RAYLIBColor(195, 215, 195, 220))

func td_drawWin
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.5))
    g1 = "VICTORY!"
    g1w = MeasureText(g1, 55)
    DrawText(g1, (SCREEN_W - g1w)/2, 250, 55, RAYLIBColor(40, 255, 70, 255))

    w2 = "All " + maxWaves + " waves defeated!"
    DrawText(w2, (SCREEN_W - MeasureText(w2, 22))/2, 320, 22, WHITE)

    w3 = "Score: " + score + "   Gold: " + gold + "   Lives: " + lives
    DrawText(w3, (SCREEN_W - MeasureText(w3, 18))/2, 355, 18, RAYLIBColor(255, 215, 0, 230))

    if floor(animTime * 2) % 2 = 0
        rt = "Press ENTER or SPACE to play again"
        rtw = MeasureText(rt, 20)
        DrawText(rt, (SCREEN_W - rtw)/2, 405, 20, WHITE)
    ok

func td_drawLose
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.55))
    g1 = "DEFEAT!"
    g1w = MeasureText(g1, 55)
    DrawText(g1, (SCREEN_W - g1w)/2, 250, 55, RAYLIBColor(255, 55, 55, 255))

    w2 = "Reached Wave " + curWave + " / " + maxWaves
    DrawText(w2, (SCREEN_W - MeasureText(w2, 22))/2, 320, 22, WHITE)

    w3 = "Score: " + score
    DrawText(w3, (SCREEN_W - MeasureText(w3, 18))/2, 355, 18, RAYLIBColor(195, 215, 195, 220))

    if floor(animTime * 2) % 2 = 0
        rt = "Press ENTER or SPACE to try again"
        rtw = MeasureText(rt, 20)
        DrawText(rt, (SCREEN_W - rtw)/2, 405, 20, WHITE)
    ok
