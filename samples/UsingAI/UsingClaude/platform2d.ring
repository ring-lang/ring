/*
**  2D Platformer - Using RingRayLib
**  ====================================
**  Controls:
**    Left / Right  or  A / D    -  Move
**    W / Up / SPACE             -  Jump (hold for higher)
**    P                          -  Pause
**    R                          -  Restart level
**    ESC                        -  Exit
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W     = 1024
SCREEN_H     = 768

TILE         = 32
MAP_ROWS     = 22
MAP_COLS     = 80

GRAV         = 980.0
PL_SPEED     = 200.0
PL_JUMP      = -420.0
PL_JUMP_CUT  = -100.0
PL_MAX_FALL  = 600.0
PL_W         = 20
PL_H         = 28
COYOTE_T     = 0.08
JUMP_BUF_T   = 0.10

EN_SLIME     = 1
EN_BAT       = 2
EN_JUMPER    = 3

T_EMPTY      = 0
T_SOLID      = 1
T_SPIKE      = 2
T_BRIDGE     = 10

ST_TITLE     = 1
ST_PLAY      = 2
ST_PAUSE     = 3
ST_DEAD      = 4
ST_CLEAR     = 5
ST_WIN       = 6
ST_GAMEOVER  = 7

// =============================================================
// Level Data — exact same pattern as sokoban: add(levels, [...])
// =============================================================

levels = []

add(levels, [
    "................................................................................",
    "................................................................................",
    "................................................................................",
    "................................................................................",
    "...........CCC..................................................................",
    "..........#####............C...C...C.......CC..CC.............................",
    "......C................C...............................C.C.C..........F.........",
    ".....###.......C....#####..............C..........C...........C......###........",
    "..P.........#####..................######.....#####...####..#####..##...##......",
    "####..............####....C.C..####....................1.........1.........####.",
    "...........1...............######............................................#..",
    "######..######..####................................................####...#....",
    "....................................................................#..#...#....",
    "...........................................................1........#..#...#....",
    "..................................................####...######..####..#####....",
    ".........................................####...................................",
    "..................................####.........................................",
    "............................####................................................",
    ".......................####.....................................................",
    "................####............................................................",
    "............####................................................................",
    "################################################################################"
])

add(levels, [
    "................................................................................",
    "................................................................................",
    "....................C.C.C.......................................................",
    "...................#######.............................................F........",
    "...............C..........C.............................................###.....",
    "..............####..####.......C.C.C.............................CCC.......##...",
    "..........C......................####............C...C.C........#####...##......",
    ".........####..........C..2............C......########.....C..........##...##...",
    "......C.............#####.......####..####.............#####.......##.........#.",
    "....####....C.C.1...........1..............1..####.............##............#..",
    "..P.......########..####..####..####..####..........####....##...............#..",
    "####.......................................................................####.",
    "......^^^^...................^^^^.........^^^^......^^^^........................",
    "####..####..####..####..####..####..####..####..####..####..####..####..####..#.",
    "................................................................................",
    "................................................................................",
    "................................................................................",
    "................................................................................",
    "................................................................................",
    "................................................................................",
    "................................................................................",
    "################################################################################"
])

add(levels, [
    "................................................................................",
    "................................................................................",
    "................................................................................",
    "....................2...........2...........2...........2.......................",
    "...........CCC..........CCC..........CCC..........CCC...........................",
    "..........-----..............-----..............-----.......CCC.................",
    "......C..............C..............C..............C........------...F..........",
    ".....----.....C....-----.....C....-----.....C....-----..C.........####..........",
    "..P.........-----..........-----..........-----..........-----.........####.....",
    "####...........................................................1...........####.",
    "......2...........2...........2...........2...........2.........................",
    "...####..####..####..####..####..####..####..####..####..####..####..####..####.",
    "................................................................................",
    "..CCC....CCC....CCC....CCC....CCC....CCC....CCC....CCC....CCC...................",
    ".#####..#####..#####..#####..#####..#####..#####..#####..#####..................",
    "................................................................................",
    "................................................................................",
    "................................................................................",
    "................................................................................",
    "................................................................................",
    "................................................................................",
    "################################################################################"
])

add(levels, [
    "................................................................................",
    "................................................................................",
    "................................................................................",
    "................................................................................",
    ".............................................................C.C.C.C............",
    "............................................................##########..........",
    "..........CCC......C...C...C...C......CCC.......S.....C.C................F......",
    ".........#####...................................###..####...............###....",
    "..P...C........####..C..####..C..####.......####........3.......####..##..##....",
    "####.####..^^..........^^..........^^..####.......^^^^.....####...........####..",
    "..........####......####......####.........####..####..####.....................",
    "..3...........................................................................3.",
    "####..................................................................####..####",
    ".......^^^^..........^^^^..........^^^^..........^^^^..........^^^^.............",
    "####..####..####..####..####..####..####..####..####..####..####..####..####..#.",
    "................................................................................",
    "................................................................................",
    "................................................................................",
    "................................................................................",
    "................................................................................",
    "................................................................................",
    "################################################################################"
])

add(levels, [
    "................................................................................",
    "................................................................................",
    "..........................C.C.C.C.C.............................................",
    ".........................###########............................................",
    "...............C..C..................C..C.....................CCC................",
    "..............######.................######.................#####...F...........",
    "..........C.............2.......2.............C..........C.........###..........",
    ".........####...................................####...####..............####...",
    "......C..........3.................3............................................",
    ".....####..####.......####..####.......####..####......####..####........####...",
    "..P........................................................1............1.......",
    "####..^^^^.....^^^^..^^^^.....^^^^..^^^^.....^^^^..####..####..####..####..####.",
    ".....#####...#####..#####...#####..#####...#####................................",
    "..2...........2..........2...........2..........2...........2...................",
    "................................................................................",
    "####..####..####..####..####..####..####..####..####..####..####..####..####..#.",
    "................................................................................",
    "................................................................................",
    "................................................................................",
    "................................................................................",
    "................................................................................",
    "################################################################################"
])

maxLevels = len(levels)

// =============================================================
// Global Variables
// =============================================================

gameState    = ST_TITLE
animTime     = 0.0
dt           = 0.0

plX = 0.0
plY = 0.0
plVX = 0.0
plVY = 0.0
plOnGround = false
plFacing = 1
plAlive = true
coyoteTimer   = 0.0
jumpBufTimer  = 0.0
invincTimer   = 0.0
invincBlink   = 0.0

tileMap  = []
coins    = []
enemies  = []
hearts   = []
stars    = []
partList = []
movPlats = []

level    = 1
lives    = 3
score    = 0
totalCoins = 0

camX = 0.0
camY = 0.0

deathTimer = 0.0
clearTimer = 0.0

mapW = 0
mapH = 0

flagX = 0.0
flagY = 0.0

newX = 0.0
newY = 0.0

// =============================================================
// Main Program
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Ring 2D Platformer - RingRayLib")
toggleFullScreen()
SetTargetFPS(60)

while !WindowShouldClose()

    dt = GetFrameTime()
    if dt > 0.033 dt = 0.033 ok
    animTime += dt

    if IsKeyPressed(KEY_R) and gameState = ST_PLAY
        pl_loadLevel(level)
        gameState = ST_PLAY
    ok

    stateHandled = false

    if gameState = ST_TITLE and !stateHandled
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            pl_fullReset()
            stateHandled = true
        ok
    ok

    if gameState = ST_PLAY and !stateHandled
        if IsKeyPressed(KEY_P)
            gameState = ST_PAUSE
            stateHandled = true
        else
            pl_updatePlayer(dt)
            pl_updateEnemies(dt)
            pl_updateParts(dt)
            pl_updateCamera(dt)
        ok
    ok

    if gameState = ST_PAUSE and !stateHandled
        if IsKeyPressed(KEY_P) or IsKeyPressed(KEY_SPACE)
            gameState = ST_PLAY
            stateHandled = true
        ok
    ok

    if gameState = ST_DEAD and !stateHandled
        pl_updateParts(dt)
        deathTimer -= dt
        if deathTimer <= 0
            lives -= 1
            if lives <= 0
                gameState = ST_GAMEOVER
            else
                pl_loadLevel(level)
                gameState = ST_PLAY
            ok
            stateHandled = true
        ok
    ok

    if gameState = ST_CLEAR and !stateHandled
        pl_updateParts(dt)
        clearTimer -= dt
        if clearTimer <= 0
            level += 1
            if level > maxLevels
                gameState = ST_WIN
            else
                pl_loadLevel(level)
                gameState = ST_PLAY
            ok
            stateHandled = true
        ok
    ok

    if gameState = ST_GAMEOVER and !stateHandled
        pl_updateParts(dt)
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            pl_fullReset()
            stateHandled = true
        ok
    ok

    if gameState = ST_WIN and !stateHandled
        pl_updateParts(dt)
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            pl_fullReset()
            stateHandled = true
        ok
    ok

    BeginDrawing()
        ClearBackground(RAYLIBColor(16, 16, 32, 255))

        if gameState = ST_TITLE
            pl_drawTitle()
        else
            pl_drawParallax()
            pl_drawTiles()
            pl_drawCoins()
            pl_drawHearts()
            pl_drawStars()
            pl_drawEnemies()
            pl_drawFlag()
            pl_drawPlayer()
            pl_drawParts()
            pl_drawHUD()

            if gameState = ST_PAUSE    pl_drawPause()    ok
            if gameState = ST_DEAD     pl_drawDead()     ok
            if gameState = ST_CLEAR    pl_drawClearScr() ok
            if gameState = ST_GAMEOVER pl_drawGameOver()  ok
            if gameState = ST_WIN      pl_drawWinScr()    ok
        ok

        DrawFPS(10, 10)
    EndDrawing()

end

CloseWindow()

// =============================================================
// ALL FUNCTIONS BELOW
// =============================================================

func pl_fullReset
    level = 1
    lives = 3
    score = 0
    totalCoins = 0
    pl_loadLevel(level)
    gameState = ST_PLAY

// Load level — follows EXACT same pattern as soko_loadLevel
func pl_loadLevel num
    tileMap  = []
    coins    = []
    enemies  = []
    hearts   = []
    stars    = []
    partList = []
    movPlats = []
    plVX = 0.0
    plVY = 0.0
    plOnGround = false
    plFacing = 1
    plAlive = true
    coyoteTimer  = 0.0
    jumpBufTimer = 0.0
    invincTimer  = 0.0
    flagX = 0.0
    flagY = 0.0

    if num < 1 or num > len(levels) return ok

    lvl = levels[num]
    mapH = len(lvl)
    mapW = MAP_COLS

    // Build tileMap — exact same pattern as sokoban's grid building
    tileMap = list(mapH)
    for r = 1 to mapH
        tileMap[r] = list(MAP_COLS)
        for c = 1 to MAP_COLS
            tileMap[r][c] = T_EMPTY
        next
    next

    // Parse each row — exact same pattern as sokoban's character parsing
    for r = 1 to mapH
        row = lvl[r]
        for c = 1 to len(row)
            ch = substr(row, c, 1)

            if ch = "#"
                tileMap[r][c] = T_SOLID
            ok
            if ch = "-"
                tileMap[r][c] = T_BRIDGE
            ok
            if ch = "^"
                tileMap[r][c] = T_SPIKE
            ok
            if ch = "C"
                add(coins, [(c-1)*TILE + TILE/2, (r-1)*TILE + TILE/2, true])
            ok
            if ch = "H"
                add(hearts, [(c-1)*TILE + TILE/2, (r-1)*TILE + TILE/2, true])
            ok
            if ch = "S"
                add(stars, [(c-1)*TILE + TILE/2, (r-1)*TILE + TILE/2, true])
            ok
            if ch = "F"
                flagX = (c-1)*TILE + TILE/2
                flagY = (r-1)*TILE + TILE
            ok
            if ch = "P"
                plX = (c-1)*TILE + TILE/2
                plY = (r-1)*TILE + TILE - PL_H/2
            ok
            if ch = "1"
                ex = (c-1)*TILE + TILE/2
                ey = (r-1)*TILE + TILE - 10
                add(enemies, [ex, ey, EN_SLIME, 40.0, true, ex, 80.0, 0.0])
            ok
            if ch = "2"
                ex = (c-1)*TILE + TILE/2
                ey = (r-1)*TILE + TILE/2
                add(enemies, [ex, ey, EN_BAT, 30.0, true, ex, 60.0, 0.0])
            ok
            if ch = "3"
                ex = (c-1)*TILE + TILE/2
                ey = (r-1)*TILE + TILE - 10
                add(enemies, [ex, ey, EN_JUMPER, 0.0, true, ex, 100.0, 0.0])
            ok
        next
    next

    camX = plX - SCREEN_W / 2
    camY = plY - SCREEN_H / 2
    pl_clampCamera()

// =============================================================
// Player Update
// =============================================================

func pl_updatePlayer frameDt
    if !plAlive return ok

    // Horizontal input
    moveDir = 0
    if IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_A) moveDir = -1 ok
    if IsKeyDown(KEY_RIGHT) or IsKeyDown(KEY_D) moveDir = 1 ok

    if moveDir != 0
        plVX = moveDir * PL_SPEED
        plFacing = moveDir
    else
        plVX = plVX * 0.7
        if fabs(plVX) < 5.0 plVX = 0.0 ok
    ok

    // Jump buffer
    wantJump = IsKeyPressed(KEY_SPACE) or IsKeyPressed(KEY_W) or IsKeyPressed(KEY_UP)
    if wantJump jumpBufTimer = JUMP_BUF_T ok
    if jumpBufTimer > 0 jumpBufTimer -= frameDt ok

    // Coyote time
    if plOnGround
        coyoteTimer = COYOTE_T
    else
        if coyoteTimer > 0 coyoteTimer -= frameDt ok
    ok

    // Execute jump
    canJump = (coyoteTimer > 0) and (jumpBufTimer > 0)
    if canJump
        plVY = PL_JUMP
        coyoteTimer = 0.0
        jumpBufTimer = 0.0
        plOnGround = false
        pl_spawnBurst(plX, plY + PL_H/2, 180, 200, 220, 5)
    ok

    // Variable jump height
    jumpHeld = IsKeyDown(KEY_SPACE) or IsKeyDown(KEY_W) or IsKeyDown(KEY_UP)
    if !jumpHeld and plVY < PL_JUMP_CUT
        plVY = PL_JUMP_CUT
    ok

    // Gravity
    plVY += GRAV * frameDt
    if plVY > PL_MAX_FALL plVY = PL_MAX_FALL ok

    // Invincibility timer
    if invincTimer > 0
        invincTimer -= frameDt
        invincBlink += frameDt * 15.0
    ok

    // Move X
    newX = plX + plVX * frameDt
    pl_resolveX()

    // Move Y
    newY = plY + plVY * frameDt
    pl_resolveY()

    // Check hazards
    pl_checkSpikes()
    pl_checkEnemyCollision()
    pl_checkPickups()
    pl_checkFlag()

    // Fall out of map
    if plY > mapH * TILE + 100
        pl_die()
    ok

// =============================================================
// Collision Resolution
// =============================================================

func pl_resolveX
    hw = PL_W / 2
    hh = PL_H / 2
    // Check left
    if plVX < 0
        leftX = newX - hw
        topTile  = floor((plY - hh + 2) / TILE) + 1
        botTile  = floor((plY + hh - 2) / TILE) + 1
        colTile  = floor(leftX / TILE) + 1
        blocked = false
        for r = topTile to botTile
            if pl_isSolid(r, colTile) blocked = true ok
        next
        if blocked
            newX = colTile * TILE + hw
            plVX = 0.0
        ok
    ok
    // Check right
    if plVX > 0
        rightX = newX + hw
        topTile  = floor((plY - hh + 2) / TILE) + 1
        botTile  = floor((plY + hh - 2) / TILE) + 1
        colTile  = floor(rightX / TILE) + 1
        blocked = false
        for r = topTile to botTile
            if pl_isSolid(r, colTile) blocked = true ok
        next
        if blocked
            newX = (colTile - 1) * TILE - hw
            plVX = 0.0
        ok
    ok
    plX = newX

func pl_resolveY
    hw = PL_W / 2
    hh = PL_H / 2
    plOnGround = false

    // Moving down
    if plVY >= 0
        botY = newY + hh
        rowTile = floor(botY / TILE) + 1
        leftTile  = floor((plX - hw + 2) / TILE) + 1
        rightTile = floor((plX + hw - 2) / TILE) + 1
        landed = false
        for c = leftTile to rightTile
            if pl_isSolid(rowTile, c) landed = true ok
            if pl_isBridge(rowTile, c)
                oldBot = plY + hh
                tileTopY = (rowTile - 1) * TILE
                if oldBot <= tileTopY + 4 landed = true ok
            ok
        next
        if landed
            newY = (rowTile - 1) * TILE - hh
            plVY = 0.0
            plOnGround = true
        ok
    ok

    // Moving up
    if plVY < 0
        topY = newY - hh
        rowTile = floor(topY / TILE) + 1
        leftTile  = floor((plX - hw + 2) / TILE) + 1
        rightTile = floor((plX + hw - 2) / TILE) + 1
        blocked = false
        for c = leftTile to rightTile
            if pl_isSolid(rowTile, c) blocked = true ok
        next
        if blocked
            newY = rowTile * TILE + hh
            plVY = 0.0
        ok
    ok

    plY = newY

func pl_isSolid r, c
    if r < 1 or r > mapH return false ok
    if c < 1 or c > MAP_COLS return false ok
    return tileMap[r][c] = T_SOLID

func pl_isBridge r, c
    if r < 1 or r > mapH return false ok
    if c < 1 or c > MAP_COLS return false ok
    return tileMap[r][c] = T_BRIDGE

func pl_isSpike r, c
    if r < 1 or r > mapH return false ok
    if c < 1 or c > MAP_COLS return false ok
    return tileMap[r][c] = T_SPIKE

// =============================================================
// Hazard & Pickup Checks
// =============================================================

func pl_checkSpikes
    hw = PL_W / 2 - 4
    hh = PL_H / 2 - 4
    r1 = floor((plY - hh) / TILE) + 1
    r2 = floor((plY + hh) / TILE) + 1
    c1 = floor((plX - hw) / TILE) + 1
    c2 = floor((plX + hw) / TILE) + 1
    for r = r1 to r2
        for c = c1 to c2
            if pl_isSpike(r, c)
                if invincTimer <= 0
                    pl_die()
                    return
                ok
            ok
        next
    next

func pl_checkEnemyCollision
    eCnt = len(enemies)
    for i = 1 to eCnt
        if !enemies[i][5] loop ok
        ex = enemies[i][1]
        ey = enemies[i][2]
        et = enemies[i][3]
        ew = 18
        eh = 18
        if et = EN_BAT
            ew = 16
            eh = 12
        ok

        // AABB overlap
        if fabs(plX - ex) < (PL_W/2 + ew/2) and fabs(plY - ey) < (PL_H/2 + eh/2)
            // Stomp check: player falling and hitting top of enemy
            if plVY > 0 and plY + PL_H/2 < ey
                // Stomp!
                enemies[i][5] = false
                plVY = PL_JUMP * 0.6
                score += 200
                pr2 = 80
                pg2 = 200
                pb2 = 80
                if et = EN_BAT
                    pr2 = 160
                    pg2 = 80
                    pb2 = 200
                ok
                if et = EN_JUMPER
                    pr2 = 220
                    pg2 = 60
                    pb2 = 60
                ok
                pl_spawnBurst(ex, ey, pr2, pg2, pb2, 8)
            else
                // Player hit
                if invincTimer <= 0
                    pl_die()
                    return
                ok
            ok
        ok
    next

func pl_checkPickups
    // Coins
    coinCnt = len(coins)
    for i = 1 to coinCnt
        if !coins[i][3] loop ok
        cx = coins[i][1]
        cy = coins[i][2]
        if fabs(plX - cx) < 18 and fabs(plY - cy) < 18
            coins[i][3] = false
            score += 100
            totalCoins += 1
            pl_spawnBurst(cx, cy, 255, 215, 0, 6)
        ok
    next
    // Hearts
    hCnt = len(hearts)
    for i = 1 to hCnt
        if !hearts[i][3] loop ok
        cx = hearts[i][1]
        cy = hearts[i][2]
        if fabs(plX - cx) < 18 and fabs(plY - cy) < 18
            hearts[i][3] = false
            lives += 1
            pl_spawnBurst(cx, cy, 255, 80, 80, 8)
        ok
    next
    // Stars
    sCnt = len(stars)
    for i = 1 to sCnt
        if !stars[i][3] loop ok
        cx = stars[i][1]
        cy = stars[i][2]
        if fabs(plX - cx) < 18 and fabs(plY - cy) < 18
            stars[i][3] = false
            invincTimer = 5.0
            pl_spawnBurst(cx, cy, 255, 255, 200, 10)
        ok
    next

func pl_checkFlag
    if flagX < 1 and flagY < 1 return ok
    if fabs(plX - flagX) < 20 and fabs(plY - (flagY - TILE/2)) < 28
        clearTimer = 2.0
        gameState = ST_CLEAR
        score += 1000 + level * 500
        pl_celebration()
    ok

func pl_die
    if !plAlive return ok
    plAlive = false
    deathTimer = 1.2
    gameState = ST_DEAD
    pl_spawnBurst(plX, plY, 255, 60, 40, 15)

// =============================================================
// Enemy Update
// =============================================================

func pl_updateEnemies frameDt
    eCnt = len(enemies)
    for i = 1 to eCnt
        if !enemies[i][5] loop ok
        et = enemies[i][3]

        if et = EN_SLIME
            enemies[i][1] += enemies[i][4] * frameDt
            dist = enemies[i][1] - enemies[i][6]
            if fabs(dist) > enemies[i][7]
                enemies[i][4] = -enemies[i][4]
            ok
            // Simple ground check
            footR = floor((enemies[i][2] + 12) / TILE) + 1
            footC = floor(enemies[i][1] / TILE) + 1
            if !pl_isSolid(footR, footC) and !pl_isBridge(footR, footC)
                enemies[i][4] = -enemies[i][4]
                enemies[i][1] += enemies[i][4] * frameDt * 2
            ok
        ok

        if et = EN_BAT
            enemies[i][8] += frameDt
            enemies[i][1] += enemies[i][4] * frameDt
            enemies[i][2] = enemies[i][2] + sin(enemies[i][8] * 3.0) * 0.8
            dist = enemies[i][1] - enemies[i][6]
            if fabs(dist) > enemies[i][7]
                enemies[i][4] = -enemies[i][4]
            ok
        ok

        if et = EN_JUMPER
            enemies[i][8] += frameDt
            if enemies[i][8] > 1.5
                enemies[i][8] = 0.0
                if plX > enemies[i][1]
                    enemies[i][4] = 60.0
                else
                    enemies[i][4] = -60.0
                ok
            ok
            enemies[i][1] += enemies[i][4] * frameDt
            enemies[i][4] = enemies[i][4] * 0.98
        ok
    next

// =============================================================
// Particles
// =============================================================

func pl_spawnBurst wx, wy, pr, pg, pb, cnt
    for k = 1 to cnt
        vx = (GetRandomValue(-100, 100) / 100.0) * 120.0
        vy = (GetRandomValue(-180, -30) / 100.0) * 100.0
        life = 0.3 + GetRandomValue(0, 50) / 100.0
        cr = pr + GetRandomValue(-20, 20)
        cg = pg + GetRandomValue(-20, 20)
        cb = pb + GetRandomValue(-20, 20)
        if cr < 0 cr = 0 ok
        if cr > 255 cr = 255 ok
        if cg < 0 cg = 0 ok
        if cg > 255 cg = 255 ok
        if cb < 0 cb = 0 ok
        if cb > 255 cb = 255 ok
        add(partList, [wx, wy, vx, vy, life, cr, cg, cb])
    next

func pl_celebration
    for k = 1 to 25
        px = flagX + GetRandomValue(-40, 40)
        py = flagY - GetRandomValue(0, 60)
        vx = (GetRandomValue(-100, 100) / 100.0) * 80.0
        vy = (GetRandomValue(-200, -50) / 100.0) * 80.0
        cr = GetRandomValue(100, 255)
        cg = GetRandomValue(100, 255)
        cb = GetRandomValue(100, 255)
        add(partList, [px, py, vx, vy, 1.5, cr, cg, cb])
    next

func pl_updateParts frameDt
    i = 1
    while i <= len(partList)
        partList[i][1] += partList[i][3] * frameDt
        partList[i][2] += partList[i][4] * frameDt
        partList[i][4] += 300.0 * frameDt
        partList[i][5] -= frameDt
        if partList[i][5] <= 0
            del(partList, i)
        else
            i += 1
        ok
    end

// =============================================================
// Camera
// =============================================================

func pl_updateCamera frameDt
    lookAhead = plFacing * 60.0
    targX = plX - SCREEN_W / 2 + lookAhead
    targY = plY - SCREEN_H / 2 - 40
    sp = 4.0 * frameDt
    camX += (targX - camX) * sp
    camY += (targY - camY) * sp
    pl_clampCamera()

func pl_clampCamera
    maxCamX = mapW * TILE - SCREEN_W
    maxCamY = mapH * TILE - SCREEN_H
    if maxCamX < 0 maxCamX = 0 ok
    if maxCamY < 0 maxCamY = 0 ok
    if camX < 0 camX = 0 ok
    if camX > maxCamX camX = maxCamX ok
    if camY < 0 camY = 0 ok
    if camY > maxCamY camY = maxCamY ok

// =============================================================
// Drawing: Parallax Background
// =============================================================

func pl_drawParallax
    off1 = -camX * 0.1
    DrawRectangleGradientV(0, 0, SCREEN_W, SCREEN_H / 2,
        RAYLIBColor(20, 20, 50, 255), RAYLIBColor(40, 35, 70, 255))
    DrawRectangleGradientV(0, SCREEN_H / 2, SCREEN_W, SCREEN_H / 2,
        RAYLIBColor(40, 35, 70, 255), RAYLIBColor(16, 16, 32, 255))

    for i = 0 to 12
        mx = i * 120 + off1
        totalW1 = 120 * 13
        while mx < -120
            mx += totalW1
        end
        while mx > SCREEN_W + 120
            mx -= totalW1
        end
        mh = 80 + sin(i * 1.7) * 40
        baseY = SCREEN_H / 2 + 60
        DrawTriangle(
            Vector2(mx, baseY),
            Vector2(mx + 60, baseY - mh),
            Vector2(mx + 120, baseY),
            RAYLIBColor(30, 28, 55, 255))
    next

    off2 = -camX * 0.3
    for i = 0 to 16
        hx = i * 90 + off2
        totalW2 = 90 * 17
        while hx < -90
            hx += totalW2
        end
        while hx > SCREEN_W + 90
            hx -= totalW2
        end
        hh2 = 40 + sin(i * 2.3 + 1.0) * 25
        baseY2 = SCREEN_H / 2 + 120
        DrawTriangle(
            Vector2(hx, baseY2),
            Vector2(hx + 45, baseY2 - hh2),
            Vector2(hx + 90, baseY2),
            RAYLIBColor(25, 35, 50, 255))
    next

    off3 = -camX * 0.5
    for i = 0 to 24
        tx = i * 60 + off3
        totalW3 = 60 * 25
        while tx < -60
            tx += totalW3
        end
        while tx > SCREEN_W + 60
            tx -= totalW3
        end
        th = 25 + sin(i * 3.1) * 12
        baseY3 = SCREEN_H / 2 + 160
        DrawRectangle(floor(tx + 25), floor(baseY3 - th), 6, floor(th),
            RAYLIBColor(35, 30, 20, 255))
        DrawCircle(floor(tx + 28), floor(baseY3 - th - 5), 14,
            RAYLIBColor(20, 45, 30, 255))
    next

// =============================================================
// Drawing: Tiles
// =============================================================

func pl_drawTiles
    if mapH < 1 return ok
    startC = floor(camX / TILE)
    endC = startC + SCREEN_W / TILE + 2
    startR = floor(camY / TILE)
    endR = startR + SCREEN_H / TILE + 2

    for r = startR to endR
        for c = startC to endC
            ri = r + 1
            ci = c + 1
            if ri < 1 or ri > mapH loop ok
            if ci < 1 or ci > MAP_COLS loop ok
            t = tileMap[ri][ci]
            if t = T_EMPTY loop ok

            sx = c * TILE - floor(camX)
            sy = r * TILE - floor(camY)

            if t = T_SOLID
                shade = 60 + ((ri + ci) % 3) * 15
                DrawRectangle(sx, sy, TILE, TILE,
                    RAYLIBColor(shade, shade - 10, shade - 20, 255))
                DrawRectangleLines(sx, sy, TILE, TILE,
                    RAYLIBColor(shade + 30, shade + 20, shade + 10, 100))
                if ri > 1
                    if tileMap[ri - 1][ci] != T_SOLID
                        DrawRectangle(sx, sy, TILE, 4,
                            RAYLIBColor(50, 140, 50, 255))
                    ok
                else
                    DrawRectangle(sx, sy, TILE, 4,
                        RAYLIBColor(50, 140, 50, 255))
                ok
            ok

            if t = T_BRIDGE
                DrawRectangle(sx, sy, TILE, 6,
                    RAYLIBColor(140, 100, 60, 255))
                DrawRectangle(sx + 2, sy + 6, 4, TILE - 6,
                    RAYLIBColor(100, 70, 40, 180))
                DrawRectangle(sx + TILE - 6, sy + 6, 4, TILE - 6,
                    RAYLIBColor(100, 70, 40, 180))
            ok

            if t = T_SPIKE
                mid = sx + TILE / 2
                DrawTriangle(
                    Vector2(sx + 2, sy + TILE),
                    Vector2(mid, sy + 4),
                    Vector2(sx + TILE - 2, sy + TILE),
                    RAYLIBColor(200, 50, 50, 255))
                DrawTriangle(
                    Vector2(sx + 2, sy + TILE),
                    Vector2(mid, sy + 4),
                    Vector2(mid, sy + TILE),
                    RAYLIBColor(230, 80, 70, 255))
            ok
        next
    next

// =============================================================
// Drawing: Coins, Hearts, Stars
// =============================================================

func pl_drawCoins
    coinCnt = len(coins)
    for i = 1 to coinCnt
        if !coins[i][3] loop ok
        sx = coins[i][1] - floor(camX)
        sy = coins[i][2] - floor(camY)
        if sx < -20 or sx > SCREEN_W + 20 loop ok
        if sy < -20 or sy > SCREEN_H + 20 loop ok
        cw = fabs(sin(animTime * 4.0 + i * 0.5)) * 6 + 3
        DrawCircle(floor(sx), floor(sy), floor(cw),
            RAYLIBColor(255, 215, 0, 255))
        DrawCircle(floor(sx), floor(sy), floor(cw - 2),
            RAYLIBColor(255, 240, 100, 255))
    next

func pl_drawHearts
    hCnt = len(hearts)
    for i = 1 to hCnt
        if !hearts[i][3] loop ok
        sx = hearts[i][1] - floor(camX)
        sy = hearts[i][2] - floor(camY)
        if sx < -20 or sx > SCREEN_W + 20 loop ok
        bobY = sy + sin(animTime * 3.0 + i) * 3
        DrawCircle(floor(sx - 4), floor(bobY - 2), 5, RAYLIBColor(255, 60, 70, 255))
        DrawCircle(floor(sx + 4), floor(bobY - 2), 5, RAYLIBColor(255, 60, 70, 255))
        DrawTriangle(
            Vector2(sx - 9, bobY),
            Vector2(sx, bobY + 10),
            Vector2(sx + 9, bobY),
            RAYLIBColor(255, 60, 70, 255))
    next

func pl_drawStars
    sCnt = len(stars)
    for i = 1 to sCnt
        if !stars[i][3] loop ok
        sx = stars[i][1] - floor(camX)
        sy = stars[i][2] - floor(camY)
        if sx < -20 or sx > SCREEN_W + 20 loop ok
        bobY = sy + sin(animTime * 2.0 + i * 0.7) * 4
        pulse = 8 + sin(animTime * 5.0) * 2
        DrawCircle(floor(sx), floor(bobY), floor(pulse),
            RAYLIBColor(255, 255, 180, 255))
        DrawCircle(floor(sx), floor(bobY), floor(pulse - 3),
            RAYLIBColor(255, 255, 240, 200))
    next

// =============================================================
// Drawing: Flag
// =============================================================

func pl_drawFlag
    sx = flagX - floor(camX)
    sy = flagY - floor(camY)
    if sx < -40 or sx > SCREEN_W + 40 return ok

    DrawRectangle(floor(sx - 2), floor(sy - 48), 4, 50,
        RAYLIBColor(180, 180, 180, 255))
    wave = sin(animTime * 4.0) * 3
    fx = sx + 2
    fy = sy - 48
    DrawTriangle(
        Vector2(fx, fy),
        Vector2(fx, fy + 16),
        Vector2(fx + 18 + wave, fy + 8),
        RAYLIBColor(220, 50, 50, 255))
    DrawCircle(floor(fx + 8 + wave/2), floor(fy + 8), 4,
        RAYLIBColor(255, 255, 100, 255))

// =============================================================
// Drawing: Enemies
// =============================================================

func pl_drawEnemies
    eCnt = len(enemies)
    for i = 1 to eCnt
        if !enemies[i][5] loop ok
        sx = enemies[i][1] - floor(camX)
        sy = enemies[i][2] - floor(camY)
        if sx < -40 or sx > SCREEN_W + 40 loop ok
        if sy < -40 or sy > SCREEN_H + 40 loop ok
        et = enemies[i][3]

        if et = EN_SLIME
            DrawCircle(floor(sx), floor(sy), 10,
                RAYLIBColor(50, 180, 50, 255))
            DrawCircle(floor(sx), floor(sy + 2), 11,
                RAYLIBColor(40, 150, 40, 255))
            DrawCircle(floor(sx - 4), floor(sy - 3), 3, WHITE)
            DrawCircle(floor(sx + 4), floor(sy - 3), 3, WHITE)
            DrawCircle(floor(sx - 3), floor(sy - 2), 1,
                RAYLIBColor(20, 20, 20, 255))
            DrawCircle(floor(sx + 5), floor(sy - 2), 1,
                RAYLIBColor(20, 20, 20, 255))
        ok

        if et = EN_BAT
            wingOff = sin(animTime * 12.0 + i) * 6
            DrawTriangle(
                Vector2(sx - 16, sy - wingOff),
                Vector2(sx - 4, sy),
                Vector2(sx - 8, sy + 4),
                RAYLIBColor(100, 50, 140, 255))
            DrawTriangle(
                Vector2(sx + 16, sy + wingOff),
                Vector2(sx + 4, sy),
                Vector2(sx + 8, sy + 4),
                RAYLIBColor(100, 50, 140, 255))
            DrawCircle(floor(sx), floor(sy), 6,
                RAYLIBColor(120, 60, 160, 255))
            DrawCircle(floor(sx - 3), floor(sy - 2), 2, RAYLIBColor(255, 50, 50, 255))
            DrawCircle(floor(sx + 3), floor(sy - 2), 2, RAYLIBColor(255, 50, 50, 255))
        ok

        if et = EN_JUMPER
            bounce = fabs(sin(animTime * 4.0 + i * 0.7)) * 4
            DrawRectangle(floor(sx - 8), floor(sy + 4), 16, 4,
                RAYLIBColor(200, 50, 50, 255))
            DrawRectangle(floor(sx - 6), floor(sy - 8 - bounce), 12, 16,
                RAYLIBColor(230, 80, 70, 255))
            DrawCircle(floor(sx - 3), floor(sy - 5 - bounce), 2, WHITE)
            DrawCircle(floor(sx + 3), floor(sy - 5 - bounce), 2, WHITE)
            DrawLine(floor(sx - 5), floor(sy - 8 - bounce),
                floor(sx - 1), floor(sy - 6 - bounce),
                RAYLIBColor(40, 20, 20, 255))
            DrawLine(floor(sx + 5), floor(sy - 8 - bounce),
                floor(sx + 1), floor(sy - 6 - bounce),
                RAYLIBColor(40, 20, 20, 255))
        ok
    next

// =============================================================
// Drawing: Player
// =============================================================

func pl_drawPlayer
    if !plAlive return ok
    sx = plX - floor(camX)
    sy = plY - floor(camY)

    if invincTimer > 0
        if floor(invincBlink) % 2 = 0 return ok
    ok

    bc = RAYLIBColor(60, 130, 220, 255)
    hc = RAYLIBColor(240, 200, 160, 255)

    DrawRectangle(floor(sx - PL_W/2), floor(sy - PL_H/2 + 8), PL_W, PL_H - 8, bc)
    DrawCircle(floor(sx), floor(sy - PL_H/2 + 6), 10, hc)
    eyeX = sx + plFacing * 3
    DrawCircle(floor(eyeX), floor(sy - PL_H/2 + 4), 2, WHITE)
    DrawCircle(floor(eyeX + plFacing), floor(sy - PL_H/2 + 5), 1,
        RAYLIBColor(20, 20, 40, 255))

    if fabs(plVX) > 10 and plOnGround
        legOff = sin(animTime * 14.0) * 4
        DrawRectangle(floor(sx - 5 + legOff), floor(sy + PL_H/2 - 2), 4, 6, bc)
        DrawRectangle(floor(sx + 1 - legOff), floor(sy + PL_H/2 - 2), 4, 6, bc)
    else
        DrawRectangle(floor(sx - 5), floor(sy + PL_H/2 - 2), 4, 4, bc)
        DrawRectangle(floor(sx + 1), floor(sy + PL_H/2 - 2), 4, 4, bc)
    ok

    if invincTimer > 0
        pulse = 16 + sin(animTime * 8.0) * 4
        DrawCircle(floor(sx), floor(sy), floor(pulse),
            RAYLIBColor(255, 255, 100, 30))
    ok

// =============================================================
// Drawing: Particles
// =============================================================

func pl_drawParts
    pCnt = len(partList)
    for i = 1 to pCnt
        px = partList[i][1] - floor(camX)
        py = partList[i][2] - floor(camY)
        alpha = floor(partList[i][5] / 1.0 * 255)
        if alpha > 255 alpha = 255 ok
        if alpha < 0   alpha = 0   ok
        sz = 2 + partList[i][5] * 3
        DrawCircle(floor(px), floor(py), floor(sz),
            RAYLIBColor(partList[i][6], partList[i][7], partList[i][8], alpha))
    next

// =============================================================
// Drawing: HUD
// =============================================================

func pl_drawHUD
    DrawRectangle(0, SCREEN_H - 36, SCREEN_W, 36, Fade(BLACK, 0.65))
    DrawText("Score: " + score, 15, SCREEN_H - 30, 18, WHITE)
    DrawText("Coins: " + totalCoins, 200, SCREEN_H - 30, 18,
        RAYLIBColor(255, 215, 0, 255))

    for i = 1 to lives
        hx = 370 + (i - 1) * 22
        hy = SCREEN_H - 24
        DrawCircle(hx - 3, hy - 1, 4, RAYLIBColor(255, 60, 70, 255))
        DrawCircle(hx + 3, hy - 1, 4, RAYLIBColor(255, 60, 70, 255))
        DrawTriangle(
            Vector2(hx - 7, hy + 1),
            Vector2(hx, hy + 8),
            Vector2(hx + 7, hy + 1),
            RAYLIBColor(255, 60, 70, 255))
    next

    DrawText("Level: " + level + "/" + maxLevels, SCREEN_W - 130, SCREEN_H - 30, 18,
        RAYLIBColor(100, 200, 255, 255))

    if invincTimer > 0
        DrawText("STAR: " + floor(invincTimer) + "s", 560, SCREEN_H - 30, 16,
            RAYLIBColor(255, 255, 100, 230))
    ok

// =============================================================
// Title Screen
// =============================================================

func pl_drawTitle
    DrawRectangleGradientV(0, 0, SCREEN_W, SCREEN_H,
        RAYLIBColor(10, 10, 30, 255), RAYLIBColor(20, 15, 40, 255))

    t1 = "PLATFORMER"
    t1w = MeasureText(t1, 56)
    DrawText(t1, (SCREEN_W - t1w)/2, 90, 56, RAYLIBColor(80, 160, 255, 255))

    t2 = "~ Jump, Stomp, Collect! ~"
    t2w = MeasureText(t2, 18)
    DrawText(t2, (SCREEN_W - t2w)/2, 160, 18, RAYLIBColor(120, 180, 240, 220))

    cy = 210
    cLines = [
        "Left / Right  or  A / D    -  Move",
        "W / Up / SPACE             -  Jump (hold for higher)",
        "P                          -  Pause",
        "R                          -  Restart level",
        "",
        "Stomp on enemies to defeat them!",
        "Collect coins for 100 points each.",
        "Hearts give extra lives, Stars give invincibility.",
        "",
        "Watch out for spikes and gaps!",
        "",
        "5 levels of increasing challenge."
    ]
    for i = 1 to len(cLines)
        lw = MeasureText(cLines[i], 15)
        if i >= 6 and i <= 8
            col = RAYLIBColor(255, 210, 90, 220)
        but i >= 10
            col = RAYLIBColor(120, 230, 150, 220)
        else
            col = RAYLIBColor(150, 190, 230, 230)
        ok
        DrawText(cLines[i], (SCREEN_W - lw)/2, cy + (i - 1) * 24, 15, col)
    next

    ppx = SCREEN_W / 2
    ppy = 540 + sin(animTime * 3.0) * 8
    DrawRectangle(floor(ppx - 10), floor(ppy - 6), 20, 20, RAYLIBColor(60, 130, 220, 255))
    DrawCircle(floor(ppx), floor(ppy - 12), 10, RAYLIBColor(240, 200, 160, 255))

    if floor(animTime * 2) % 2 = 0
        st = "Press ENTER or SPACE to Start"
        stw = MeasureText(st, 24)
        DrawText(st, (SCREEN_W - stw)/2, 590, 24, WHITE)
    ok

    cr2 = "Developed using Ring Language + RingRayLib"
    crw = MeasureText(cr2, 14)
    DrawText(cr2, (SCREEN_W - crw)/2, SCREEN_H - 35, 14, RAYLIBColor(60, 80, 130, 175))

// =============================================================
// Overlays
// =============================================================

func pl_drawPause
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.5))
    pt = "PAUSED"
    ptw = MeasureText(pt, 50)
    DrawText(pt, (SCREEN_W - ptw)/2, SCREEN_H/2 - 35, 50, WHITE)
    p2 = "Press P or SPACE to resume"
    p2w = MeasureText(p2, 20)
    DrawText(p2, (SCREEN_W - p2w)/2, SCREEN_H/2 + 25, 20, RAYLIBColor(180, 200, 230, 220))

func pl_drawDead
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.35))
    dt2 = "Oh no!"
    dw2 = MeasureText(dt2, 40)
    DrawText(dt2, (SCREEN_W - dw2)/2, SCREEN_H/2 - 20, 40, RAYLIBColor(255, 80, 80, 230))

func pl_drawClearScr
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.4))
    ct = "LEVEL " + level + " CLEAR!"
    ctw = MeasureText(ct, 46)
    DrawText(ct, (SCREEN_W - ctw)/2, SCREEN_H/2 - 30, 46, RAYLIBColor(50, 255, 100, 255))
    sc2 = "+" + (1000 + level * 500) + " bonus!"
    scw = MeasureText(sc2, 22)
    DrawText(sc2, (SCREEN_W - scw)/2, SCREEN_H/2 + 30, 22, RAYLIBColor(255, 215, 0, 230))

func pl_drawGameOver
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.6))
    g1 = "GAME OVER"
    g1w = MeasureText(g1, 55)
    DrawText(g1, (SCREEN_W - g1w)/2, 260, 55, RAYLIBColor(255, 55, 55, 255))
    DrawText("Final Score: " + score,
        (SCREEN_W - MeasureText("Final Score: " + score, 22))/2, 330, 22, WHITE)
    DrawText("Coins: " + totalCoins,
        (SCREEN_W - MeasureText("Coins: " + totalCoins, 18))/2, 365, 18,
        RAYLIBColor(255, 215, 0, 220))
    if floor(animTime * 2) % 2 = 0
        rt = "Press ENTER or SPACE to retry"
        rtw = MeasureText(rt, 20)
        DrawText(rt, (SCREEN_W - rtw)/2, 410, 20, WHITE)
    ok

func pl_drawWinScr
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, Fade(BLACK, 0.55))
    g1 = "YOU WIN!"
    g1w = MeasureText(g1, 55)
    DrawText(g1, (SCREEN_W - g1w)/2, 240, 55, RAYLIBColor(50, 255, 100, 255))
    DrawText("All " + maxLevels + " levels complete!",
        (SCREEN_W - MeasureText("All " + maxLevels + " levels complete!", 22))/2, 310, 22, WHITE)
    w3 = "Score: " + score + "   Coins: " + totalCoins + "   Lives: " + lives
    DrawText(w3, (SCREEN_W - MeasureText(w3, 18))/2, 350, 18, RAYLIBColor(255, 215, 0, 230))
    if floor(animTime * 2) % 2 = 0
        rt = "Press ENTER or SPACE to play again"
        rtw = MeasureText(rt, 20)
        DrawText(rt, (SCREEN_W - rtw)/2, 400, 20, WHITE)
    ok
