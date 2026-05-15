/*
**  Asteroids 2D - RingRayLib
**  ===================================
**  Classic wrap-around space shooter!
**  Destroy asteroids, survive waves, get high scores.
**
**  Controls:
**    W / Up           - Thrust forward
**    A/D or Left/Right - Rotate ship
**    Space            - Fire
**    Shift            - Hyperspace (random teleport)
**    S / Down         - Brake / reverse thrust
**    Tab              - Shield (uses energy)
**    P                - Pause
**    N                - New game
**    1-3              - Difficulty
**    ESC              - Exit
**
**  Features:
**    - Wrap-around screen edges
**    - Asteroids split into smaller pieces
**    - Progressive wave difficulty
**    - Power-ups: triple shot, rapid fire, shield recharge
**    - Particle engine exhaust and explosion effects
**    - UFO enemies appear periodically
**    - Ship lives and score system
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W = 1024
SCREEN_H = 700

PI = 3.14159265
DEG2RAD = PI / 180.0

// Ship physics
SHIP_ACCEL   = 280.0
SHIP_DRAG    = 0.985
SHIP_ROTATE  = 240.0
SHIP_MAX_SPD = 400.0
SHIP_BRAKE   = 120.0

// Bullets
BULLET_SPEED = 500.0
BULLET_LIFE  = 1.8
MAX_BULLETS  = 30
FIRE_RATE    = 0.18      // seconds between shots
RAPID_RATE   = 0.08

// Asteroids
MAX_ASTEROIDS = 40
AST_LARGE  = 3
AST_MED    = 2
AST_SMALL  = 1
AST_SPEED_BASE = 40.0

// UFO
MAX_UFOS = 3
UFO_SPEED = 100.0
UFO_FIRE_RATE = 2.0

// Particles
MAX_PARTS = 200

// Power-up types
PU_TRISHOT = 1
PU_RAPID   = 2
PU_SHIELD  = 3
PU_LIFE    = 4
MAX_POWERUPS = 5

// Game states
STATE_MENU    = 1
STATE_PLAYING = 2
STATE_DYING   = 3
STATE_DEAD    = 4
STATE_PAUSED  = 5

// =============================================================
// Ship Data
// =============================================================

shipX = 0.0    shipY = 0.0
shipVX = 0.0   shipVY = 0.0
shipAngle = -90.0     // pointing up
shipThrust = false
shipAlive = true
shipInvuln = 0.0      // invulnerability timer after respawn

lives = 3
score = 0
bestScore = 0
wave = 0

fireTimer = 0.0
triShotTimer = 0.0    // power-up duration
rapidFireTimer = 0.0
shieldEnergy = 100.0
shieldActive = false
shieldMax = 100.0

// =============================================================
// Arrays
// =============================================================

// Bullets: [x, y, vx, vy, life, active, isUFO]
bulX = list(MAX_BULLETS)     bulY = list(MAX_BULLETS)
bulVX = list(MAX_BULLETS)    bulVY = list(MAX_BULLETS)
bulLife = list(MAX_BULLETS)  bulActive = list(MAX_BULLETS)
bulUFO = list(MAX_BULLETS)

// Asteroids: [x, y, vx, vy, size, rotAngle, rotSpeed, active, shape]
astX = list(MAX_ASTEROIDS)      astY = list(MAX_ASTEROIDS)
astVX = list(MAX_ASTEROIDS)     astVY = list(MAX_ASTEROIDS)
astSize = list(MAX_ASTEROIDS)   astRot = list(MAX_ASTEROIDS)
astRotSpd = list(MAX_ASTEROIDS) astActive = list(MAX_ASTEROIDS)
astShape = list(MAX_ASTEROIDS)  // random vertex offsets for variety

// UFOs: [x, y, vx, vy, active, hp, fireTimer, size]
ufoX = list(MAX_UFOS)     ufoY = list(MAX_UFOS)
ufoVX = list(MAX_UFOS)    ufoVY = list(MAX_UFOS)
ufoActive = list(MAX_UFOS) ufoHP = list(MAX_UFOS)
ufoFire = list(MAX_UFOS)  ufoSz = list(MAX_UFOS)

// Particles: [x, y, vx, vy, life, maxLife, r, g, b, active]
prtX = list(MAX_PARTS)   prtY = list(MAX_PARTS)
prtVX = list(MAX_PARTS)  prtVY = list(MAX_PARTS)
prtLife = list(MAX_PARTS) prtMaxL = list(MAX_PARTS)
prtR = list(MAX_PARTS)   prtG = list(MAX_PARTS)
prtB = list(MAX_PARTS)   prtAct = list(MAX_PARTS)

// Power-ups: [x, y, type, timer, active]
puX = list(MAX_POWERUPS)    puY = list(MAX_POWERUPS)
puType = list(MAX_POWERUPS) puTime = list(MAX_POWERUPS)
puAct = list(MAX_POWERUPS)

// Star background
MAX_STARS = 120
starX = list(MAX_STARS)   starY = list(MAX_STARS)
starBr = list(MAX_STARS)  starSz = list(MAX_STARS)

// =============================================================
// State
// =============================================================

gameState = STATE_MENU
animTime = 0.0
dieTimer = 0.0
ufoSpawnTimer = 0.0
difficulty = 2       // 1=easy, 2=normal, 3=hard
diffNames = ["Easy", "Normal", "Hard"]
screenFlash = 0.0

// =============================================================
// Main
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Asteroids 2D - RingRayLib")
SetTargetFPS(60)
SetExitKey(0)

ast_initStars()
ast_clearAll()

while !WindowShouldClose()
    ast_update()
    BeginDrawing()
        ClearBackground(RAYLIBColor(4, 4, 12, 255))
        ast_draw()
    EndDrawing()
end

CloseWindow()

// =============================================================
// Init
// =============================================================

func ast_initStars
    for i = 1 to MAX_STARS
        starX[i] = GetRandomValue(0, SCREEN_W)
        starY[i] = GetRandomValue(0, SCREEN_H)
        starBr[i] = GetRandomValue(40, 200)
        starSz[i] = GetRandomValue(1, 2)
    next

func ast_clearAll
    for i = 1 to MAX_BULLETS  bulActive[i] = 0 next
    for i = 1 to MAX_ASTEROIDS astActive[i] = 0 next
    for i = 1 to MAX_UFOS ufoActive[i] = 0 next
    for i = 1 to MAX_PARTS prtAct[i] = 0 next
    for i = 1 to MAX_POWERUPS puAct[i] = 0 next

func ast_newGame
    ast_clearAll()
    shipX = SCREEN_W / 2.0
    shipY = SCREEN_H / 2.0
    shipVX = 0  shipVY = 0
    shipAngle = -90.0
    shipThrust = false
    shipAlive = true
    shipInvuln = 2.0
    lives = 3
    score = 0
    wave = 0
    fireTimer = 0
    triShotTimer = 0
    rapidFireTimer = 0
    shieldEnergy = shieldMax
    shieldActive = false
    ufoSpawnTimer = 15.0
    gameState = STATE_PLAYING
    ast_spawnWave()

// =============================================================
// Spawn Wave
// =============================================================

func ast_spawnWave
    wave++
    count = 3 + wave + (difficulty - 1)
    if count > 12 count = 12 ok

    for i = 1 to count
        ast_spawnAsteroid(AST_LARGE, 0, 0, true)
    next

func ast_spawnAsteroid size, fromX, fromY, randomPos
    for i = 1 to MAX_ASTEROIDS
        if astActive[i] = 1 loop ok

        if randomPos
            // Spawn at edges away from ship
            side = GetRandomValue(1, 4)
            if side = 1 astX[i] = 0.0   astY[i] = GetRandomValue(0, SCREEN_H) * 1.0 ok
            if side = 2 astX[i] = SCREEN_W * 1.0 astY[i] = GetRandomValue(0, SCREEN_H) * 1.0 ok
            if side = 3 astX[i] = GetRandomValue(0, SCREEN_W) * 1.0 astY[i] = 0.0 ok
            if side = 4 astX[i] = GetRandomValue(0, SCREEN_W) * 1.0 astY[i] = SCREEN_H * 1.0 ok
        else
            astX[i] = fromX * 1.0
            astY[i] = fromY * 1.0
        ok

        angle = GetRandomValue(0, 359) * DEG2RAD
        spd = AST_SPEED_BASE + GetRandomValue(10, 50) + (4 - size) * 20
        astVX[i] = cos(angle) * spd
        astVY[i] = sin(angle) * spd
        astSize[i] = size
        astRot[i] = GetRandomValue(0, 359) * 1.0
        astRotSpd[i] = GetRandomValue(-120, 120) * 1.0
        astActive[i] = 1

        // Random shape (8 vertex offset values for polygon variety)
        offsets = ""
        for v = 1 to 8
            offsets += string(GetRandomValue(70, 100)) + ","
        next
        astShape[i] = offsets

        return
    next

// =============================================================
// Update
// =============================================================

func ast_update
    dt = GetFrameTime()
    if dt > 0.03 dt = 0.03 ok
    animTime += dt

    if IsKeyPressed(KEY_ESCAPE)
        CloseWindow()
        shutdown(0)
    ok

    if IsKeyPressed(KEY_N)
        ast_newGame()
        return
    ok

    if IsKeyPressed(KEY_ONE)   difficulty = 1 ok
    if IsKeyPressed(KEY_TWO)   difficulty = 2 ok
    if IsKeyPressed(KEY_THREE) difficulty = 3 ok

    if IsKeyPressed(KEY_P) and gameState = STATE_PLAYING
        gameState = STATE_PAUSED
        return
    ok
    if IsKeyPressed(KEY_P) and gameState = STATE_PAUSED
        gameState = STATE_PLAYING
        return
    ok

    if screenFlash > 0
        screenFlash -= dt * 3
        if screenFlash < 0 screenFlash = 0 ok
    ok

    // Particles always update
    ast_updateParticles(dt)

    if gameState = STATE_MENU
        // Attract mode: spin asteroids
        ast_updateAsteroids(dt)
        if IsKeyPressed(KEY_SPACE) or IsKeyPressed(KEY_ENTER)
            ast_newGame()
        ok
        return
    ok

    if gameState = STATE_PAUSED return ok

    if gameState = STATE_DYING
        dieTimer -= dt
        ast_updateAsteroids(dt)
        ast_updateBullets(dt)
        ast_updateUFOs(dt)
        if dieTimer <= 0
            if lives > 0
                // Respawn
                shipX = SCREEN_W / 2.0
                shipY = SCREEN_H / 2.0
                shipVX = 0  shipVY = 0
                shipAngle = -90.0
                shipAlive = true
                shipInvuln = 2.5
                gameState = STATE_PLAYING
            else
                gameState = STATE_DEAD
                if score > bestScore bestScore = score ok
            ok
        ok
        return
    ok

    if gameState = STATE_DEAD
        ast_updateAsteroids(dt)
        if IsKeyPressed(KEY_SPACE) or IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_R)
            ast_newGame()
        ok
        return
    ok

    // === STATE_PLAYING ===
    if shipInvuln > 0
        shipInvuln -= dt
        if shipInvuln < 0 shipInvuln = 0 ok
    ok

    // Power-up timers
    if triShotTimer > 0 triShotTimer -= dt ok
    if rapidFireTimer > 0 rapidFireTimer -= dt ok

    // Shield
    shieldActive = IsKeyDown(KEY_TAB) and shieldEnergy > 0
    if shieldActive
        shieldEnergy -= 40 * dt
        if shieldEnergy < 0
            shieldEnergy = 0
            shieldActive = false
        ok
    else
        // Recharge slowly
        shieldEnergy += 5 * dt
        if shieldEnergy > shieldMax shieldEnergy = shieldMax ok
    ok

    // Ship rotation
    if IsKeyDown(KEY_A) or IsKeyDown(KEY_LEFT)
        shipAngle -= SHIP_ROTATE * dt
    ok
    if IsKeyDown(KEY_D) or IsKeyDown(KEY_RIGHT)
        shipAngle += SHIP_ROTATE * dt
    ok

    // Thrust
    rad = shipAngle * DEG2RAD
    shipThrust = false
    if IsKeyDown(KEY_W) or IsKeyDown(KEY_UP)
        shipVX += cos(rad) * SHIP_ACCEL * dt
        shipVY += sin(rad) * SHIP_ACCEL * dt
        shipThrust = true
    ok

    // Brake
    if IsKeyDown(KEY_S) or IsKeyDown(KEY_DOWN)
        shipVX -= cos(rad) * SHIP_BRAKE * dt
        shipVY -= sin(rad) * SHIP_BRAKE * dt
    ok

    // Drag
    shipVX *= SHIP_DRAG
    shipVY *= SHIP_DRAG

    // Speed cap
    spd = sqrt(shipVX * shipVX + shipVY * shipVY)
    if spd > SHIP_MAX_SPD
        shipVX = shipVX / spd * SHIP_MAX_SPD
        shipVY = shipVY / spd * SHIP_MAX_SPD
    ok

    // Move
    shipX += shipVX * dt
    shipY += shipVY * dt
    ast_wrap_pos()

    // Fire
    fireTimer -= dt
    rate = FIRE_RATE
    if rapidFireTimer > 0 rate = RAPID_RATE ok

    if IsKeyDown(KEY_SPACE) and fireTimer <= 0
        fireTimer = rate
        ast_fireBullet(shipX, shipY, shipAngle, false)
        if triShotTimer > 0
            ast_fireBullet(shipX, shipY, shipAngle - 12, false)
            ast_fireBullet(shipX, shipY, shipAngle + 12, false)
        ok
    ok

    // Hyperspace
    if IsKeyPressed(KEY_LEFT_SHIFT) or IsKeyPressed(KEY_RIGHT_SHIFT)
        shipX = GetRandomValue(50, SCREEN_W - 50) * 1.0
        shipY = GetRandomValue(50, SCREEN_H - 50) * 1.0
        shipVX = 0  shipVY = 0
        shipInvuln = 0.5
        // Flash effect
        for p = 1 to 15
            ast_spawnPart(shipX, shipY,
                         GetRandomValue(-200, 200), GetRandomValue(-200, 200),
                         0.5, 100, 150, 255)
        next
    ok

    // Engine particles
    if shipThrust
        eRad = (shipAngle + 180) * DEG2RAD
        ex = shipX + cos(eRad) * 14
        ey = shipY + sin(eRad) * 14
        ast_spawnPart(ex, ey,
                     cos(eRad) * GetRandomValue(60, 180) + shipVX * 0.3,
                     sin(eRad) * GetRandomValue(60, 180) + shipVY * 0.3,
                     0.4, 255, GetRandomValue(120, 200), 30)
    ok

    ast_updateBullets(dt)
    ast_updateAsteroids(dt)
    ast_updateUFOs(dt)
    ast_updatePowerups(dt)
    ast_checkCollisions()

    // Check wave clear
    activeAst = 0
    for i = 1 to MAX_ASTEROIDS
        if astActive[i] = 1 activeAst++ ok
    next
    if activeAst = 0
        ast_spawnWave()
    ok

    // UFO spawn timer
    ufoSpawnTimer -= dt
    if ufoSpawnTimer <= 0
        ufoSpawnTimer = 20.0 - wave * 0.5
        if ufoSpawnTimer < 8 ufoSpawnTimer = 8 ok
        ast_spawnUFO()
    ok

// =============================================================
// Wrap position
// =============================================================

func ast_wrap_pos
    if shipX < -20 shipX += SCREEN_W + 40 ok
    if shipX > SCREEN_W + 20 shipX -= SCREEN_W + 40 ok
    if shipY < -20 shipY += SCREEN_H + 40 ok
    if shipY > SCREEN_H + 20 shipY -= SCREEN_H + 40 ok

func ast_wrap x, y
    nx = x  ny = y
    if nx < -40 nx += SCREEN_W + 80 ok
    if nx > SCREEN_W + 40 nx -= SCREEN_W + 80 ok
    if ny < -40 ny += SCREEN_H + 80 ok
    if ny > SCREEN_H + 40 ny -= SCREEN_H + 80 ok
    return [nx, ny]

// =============================================================
// Bullets
// =============================================================

func ast_fireBullet fx, fy, angle, isUFO
    for i = 1 to MAX_BULLETS
        if bulActive[i] = 1 loop ok
        rad = angle * DEG2RAD
        noseDist = 16
        if isUFO noseDist = 0 ok
        bulX[i] = fx + cos(rad) * noseDist
        bulY[i] = fy + sin(rad) * noseDist
        bulVX[i] = cos(rad) * BULLET_SPEED
        bulVY[i] = sin(rad) * BULLET_SPEED
        if !isUFO
            bulVX[i] += shipVX * 0.3
            bulVY[i] += shipVY * 0.3
        ok
        bulLife[i] = BULLET_LIFE
        bulActive[i] = 1
        bulUFO[i] = isUFO
        return
    next

func ast_updateBullets dt
    for i = 1 to MAX_BULLETS
        if bulActive[i] = 0 loop ok
        bulX[i] += bulVX[i] * dt
        bulY[i] += bulVY[i] * dt
        bulLife[i] -= dt

        // Wrap
        if bulX[i] < -10 bulX[i] += SCREEN_W + 20 ok
        if bulX[i] > SCREEN_W + 10 bulX[i] -= SCREEN_W + 20 ok
        if bulY[i] < -10 bulY[i] += SCREEN_H + 20 ok
        if bulY[i] > SCREEN_H + 10 bulY[i] -= SCREEN_H + 20 ok

        if bulLife[i] <= 0 bulActive[i] = 0 ok
    next

// =============================================================
// Asteroids
// =============================================================

func ast_updateAsteroids dt
    for i = 1 to MAX_ASTEROIDS
        if astActive[i] = 0 loop ok
        astX[i] += astVX[i] * dt
        astY[i] += astVY[i] * dt
        astRot[i] += astRotSpd[i] * dt

        // Wrap
        rad = astSize[i] * 15
        if astX[i] < -rad astX[i] += SCREEN_W + rad * 2 ok
        if astX[i] > SCREEN_W + rad astX[i] -= SCREEN_W + rad * 2 ok
        if astY[i] < -rad astY[i] += SCREEN_H + rad * 2 ok
        if astY[i] > SCREEN_H + rad astY[i] -= SCREEN_H + rad * 2 ok
    next

func ast_getRadius size
    if size = AST_LARGE return 38 ok
    if size = AST_MED return 22 ok
    return 12

// =============================================================
// UFOs
// =============================================================

func ast_spawnUFO
    for i = 1 to MAX_UFOS
        if ufoActive[i] = 1 loop ok
        ufoX[i] = -20.0
        ufoY[i] = GetRandomValue(60, SCREEN_H - 60) * 1.0
        ufoVX[i] = UFO_SPEED + wave * 5
        ufoVY[i] = GetRandomValue(-30, 30) * 1.0
        ufoActive[i] = 1
        ufoHP[i] = 2 + floor(wave / 3)
        ufoFire[i] = UFO_FIRE_RATE
        ufoSz[i] = 18
        return
    next

func ast_updateUFOs dt
    for i = 1 to MAX_UFOS
        if ufoActive[i] = 0 loop ok
        ufoX[i] += ufoVX[i] * dt
        ufoY[i] += ufoVY[i] * dt

        // Bounce off top/bottom
        if ufoY[i] < 20 ufoVY[i] = fabs(ufoVY[i]) ok
        if ufoY[i] > SCREEN_H - 20 ufoVY[i] = -fabs(ufoVY[i]) ok

        // Off screen right
        if ufoX[i] > SCREEN_W + 40 ufoActive[i] = 0 loop ok

        // Fire at player
        if gameState = STATE_PLAYING and shipAlive
            ufoFire[i] -= dt
            if ufoFire[i] <= 0
                ufoFire[i] = UFO_FIRE_RATE - wave * 0.05
                if ufoFire[i] < 0.5 ufoFire[i] = 0.5 ok
                // Aim at player with some inaccuracy
                dx = shipX - ufoX[i]
                dy = shipY - ufoY[i]
                aimAngle = 0.0
                if fabs(dx) > 0.01
                    aimAngle = atan(dy / dx) / DEG2RAD
                    if dx < 0 aimAngle += 180 ok
                ok
                aimAngle += GetRandomValue(-15, 15)
                ast_fireBullet(ufoX[i], ufoY[i], aimAngle, true)
            ok
        ok
    next

// =============================================================
// Power-ups
// =============================================================

func ast_spawnPowerup px, py
    if GetRandomValue(1, 100) > 20 return ok    // 20% chance
    for i = 1 to MAX_POWERUPS
        if puAct[i] = 1 loop ok
        puX[i] = px
        puY[i] = py
        puType[i] = GetRandomValue(1, 4)
        puTime[i] = 8.0    // disappear timer
        puAct[i] = 1
        return
    next

func ast_updatePowerups dt
    for i = 1 to MAX_POWERUPS
        if puAct[i] = 0 loop ok
        puTime[i] -= dt
        if puTime[i] <= 0 puAct[i] = 0 loop ok

        // Check player pickup
        dx = puX[i] - shipX
        dy = puY[i] - shipY
        if dx*dx + dy*dy < 400    // 20 radius
            puAct[i] = 0
            if puType[i] = PU_TRISHOT
                triShotTimer = 10.0
                ast_spawnPartBurst(puX[i], puY[i], 8, 255, 200, 50)
            ok
            if puType[i] = PU_RAPID
                rapidFireTimer = 8.0
                ast_spawnPartBurst(puX[i], puY[i], 8, 50, 200, 255)
            ok
            if puType[i] = PU_SHIELD
                shieldEnergy = shieldMax
                ast_spawnPartBurst(puX[i], puY[i], 8, 100, 255, 200)
            ok
            if puType[i] = PU_LIFE
                lives++
                ast_spawnPartBurst(puX[i], puY[i], 8, 255, 100, 100)
            ok
        ok
    next

// =============================================================
// Collisions
// =============================================================

func ast_checkCollisions
    // Bullets vs asteroids
    for b = 1 to MAX_BULLETS
        if bulActive[b] = 0 loop ok
        if bulUFO[b] = 1 loop ok    // UFO bullets don't destroy asteroids

        for a = 1 to MAX_ASTEROIDS
            if astActive[a] = 0 loop ok
            dx = bulX[b] - astX[a]
            dy = bulY[b] - astY[a]
            r = ast_getRadius(astSize[a])
            if dx*dx + dy*dy < r * r
                bulActive[b] = 0
                ast_destroyAsteroid(a)
                exit
            ok
        next
    next

    // Bullets vs UFOs
    for b = 1 to MAX_BULLETS
        if bulActive[b] = 0 loop ok
        if bulUFO[b] = 1 loop ok

        for u = 1 to MAX_UFOS
            if ufoActive[u] = 0 loop ok
            dx = bulX[b] - ufoX[u]
            dy = bulY[b] - ufoY[u]
            if dx*dx + dy*dy < ufoSz[u] * ufoSz[u]
                bulActive[b] = 0
                ufoHP[u]--
                if ufoHP[u] <= 0
                    ufoActive[u] = 0
                    score += 200
                    ast_spawnPartBurst(ufoX[u], ufoY[u], 20, 255, 100, 200)
                    screenFlash = 0.3
                ok
                exit
            ok
        next
    next

    // Ship vs asteroids
    if shipAlive and shipInvuln <= 0
        for a = 1 to MAX_ASTEROIDS
            if astActive[a] = 0 loop ok
            dx = shipX - astX[a]
            dy = shipY - astY[a]
            r = ast_getRadius(astSize[a]) + 10
            if dx*dx + dy*dy < r * r
                if shieldActive
                    // Shield absorbs hit, destroy asteroid
                    shieldEnergy -= 30
                    ast_destroyAsteroid(a)
                    if shieldEnergy < 0 shieldEnergy = 0 ok
                else
                    ast_playerDie()
                ok
                return
            ok
        next
    ok

    // Ship vs UFO bullets
    if shipAlive and shipInvuln <= 0
        for b = 1 to MAX_BULLETS
            if bulActive[b] = 0 loop ok
            if bulUFO[b] = 0 loop ok
            dx = bulX[b] - shipX
            dy = bulY[b] - shipY
            if dx*dx + dy*dy < 144    // 12^2
                bulActive[b] = 0
                if shieldActive
                    shieldEnergy -= 15
                    if shieldEnergy < 0 shieldEnergy = 0 ok
                else
                    ast_playerDie()
                ok
                return
            ok
        next
    ok

    // Ship vs UFO
    if shipAlive and shipInvuln <= 0
        for u = 1 to MAX_UFOS
            if ufoActive[u] = 0 loop ok
            dx = shipX - ufoX[u]
            dy = shipY - ufoY[u]
            if dx*dx + dy*dy < (ufoSz[u] + 10) * (ufoSz[u] + 10)
                if shieldActive
                    shieldEnergy -= 40
                    ufoActive[u] = 0
                    score += 200
                    ast_spawnPartBurst(ufoX[u], ufoY[u], 20, 255, 100, 200)
                else
                    ast_playerDie()
                ok
                return
            ok
        next
    ok

// =============================================================
// Destroy Asteroid
// =============================================================

func ast_destroyAsteroid idx
    ax = astX[idx]
    ay = astY[idx]
    sz = astSize[idx]
    astActive[idx] = 0

    // Score
    if sz = AST_LARGE score += 20 ok
    if sz = AST_MED score += 50 ok
    if sz = AST_SMALL score += 100 ok

    // Explosion particles
    pCount = 8 + (sz - 1) * 6
    for p = 1 to pCount
        ast_spawnPart(ax, ay,
                     GetRandomValue(-150, 150) * 1.0, GetRandomValue(-150, 150) * 1.0,
                     0.5 + sz * 0.2, 200, 180, GetRandomValue(80, 160))
    next

    // Split into smaller
    if sz > AST_SMALL
        newSz = sz - 1
        pieces = 2
        if difficulty = 3 pieces = 3 ok
        for p = 1 to pieces
            ast_spawnAsteroid(newSz, ax, ay, false)
        next
    ok

    // Power-up drop
    if sz = AST_LARGE
        ast_spawnPowerup(ax, ay)
    ok

    screenFlash = 0.15

// =============================================================
// Player Die
// =============================================================

func ast_playerDie
    shipAlive = false
    lives--
    gameState = STATE_DYING
    dieTimer = 2.0
    screenFlash = 0.5

    // Big explosion
    for p = 1 to 30
        ast_spawnPart(shipX, shipY,
                     GetRandomValue(-250, 250) * 1.0, GetRandomValue(-250, 250) * 1.0,
                     0.8, 255, GetRandomValue(150, 255), GetRandomValue(30, 100))
    next

// =============================================================
// Particles
// =============================================================

func ast_spawnPart px, py, vx, vy, life, r, g, b
    for i = 1 to MAX_PARTS
        if prtAct[i] = 1 loop ok
        prtX[i] = px  prtY[i] = py
        prtVX[i] = vx  prtVY[i] = vy
        prtLife[i] = life  prtMaxL[i] = life
        prtR[i] = r  prtG[i] = g  prtB[i] = b
        prtAct[i] = 1
        return
    next

func ast_spawnPartBurst px, py, count, r, g, b
    for p = 1 to count
        ast_spawnPart(px, py,
                     GetRandomValue(-200, 200) * 1.0, GetRandomValue(-200, 200) * 1.0,
                     0.5, r, g, b)
    next

func ast_updateParticles dt
    for i = 1 to MAX_PARTS
        if prtAct[i] = 0 loop ok
        prtX[i] += prtVX[i] * dt
        prtY[i] += prtVY[i] * dt
        prtLife[i] -= dt
        if prtLife[i] <= 0 prtAct[i] = 0 ok
    next

// =============================================================
// Draw
// =============================================================

func ast_draw
    // Stars
    for i = 1 to MAX_STARS
        twk = floor(fabs(sin(animTime * 2 + i * 0.5)) * 60)
        DrawCircle(starX[i], starY[i], starSz[i], RAYLIBColor(starBr[i] + twk, starBr[i] + twk, starBr[i] + twk + 20, 200))
    next

    // Particles
    for i = 1 to MAX_PARTS
        if prtAct[i] = 0 loop ok
        ml = prtMaxL[i]
        if ml < 0.01 ml = 0.01 ok
        frac = prtLife[i] / ml
        al = floor(frac * 255)
        if al > 255 al = 255 ok
        if al < 0 loop ok
        sz = frac * 3 + 0.5
        DrawCircle(floor(prtX[i]), floor(prtY[i]), sz, RAYLIBColor(prtR[i], prtG[i], prtB[i], al))
    next

    // Power-ups
    for i = 1 to MAX_POWERUPS
        if puAct[i] = 0 loop ok
        ppx = floor(puX[i])  ppy = floor(puY[i])
        pulse = sin(animTime * 5) * 3

        if puType[i] = PU_TRISHOT
            DrawCircle(ppx, ppy, 10 + pulse, RAYLIBColor(255, 200, 50, 180))
            DrawText("3", ppx - 4, ppy - 5, 12, RAYLIBColor(40, 20, 0, 255))
        ok
        if puType[i] = PU_RAPID
            DrawCircle(ppx, ppy, 10 + pulse, RAYLIBColor(50, 200, 255, 180))
            DrawText("R", ppx - 4, ppy - 5, 12, RAYLIBColor(0, 20, 40, 255))
        ok
        if puType[i] = PU_SHIELD
            DrawCircle(ppx, ppy, 10 + pulse, RAYLIBColor(100, 255, 200, 180))
            DrawText("S", ppx - 4, ppy - 5, 12, RAYLIBColor(0, 40, 20, 255))
        ok
        if puType[i] = PU_LIFE
            DrawCircle(ppx, ppy, 10 + pulse, RAYLIBColor(255, 100, 100, 180))
            DrawText("+", ppx - 4, ppy - 6, 14, RAYLIBColor(40, 0, 0, 255))
        ok
    next

    // Asteroids
    for i = 1 to MAX_ASTEROIDS
        if astActive[i] = 0 loop ok
        ast_drawAsteroid(i)
    next

    // UFOs
    for i = 1 to MAX_UFOS
        if ufoActive[i] = 0 loop ok
        ast_drawUFO(i)
    next

    // Bullets
    for i = 1 to MAX_BULLETS
        if bulActive[i] = 0 loop ok
        if bulUFO[i] = 1
            DrawCircle(floor(bulX[i]), floor(bulY[i]), 3, RAYLIBColor(255, 80, 80, 230))
        else
            DrawCircle(floor(bulX[i]), floor(bulY[i]), 2, RAYLIBColor(255, 255, 200, 255))
            DrawCircle(floor(bulX[i]), floor(bulY[i]), 4, RAYLIBColor(255, 255, 200, 60))
        ok
    next

    // Ship
    if shipAlive
        ast_drawShip()
    ok

    // Screen flash
    if screenFlash > 0
        fa = floor(screenFlash * 200)
        if fa > 200 fa = 200 ok
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(255, 255, 255, fa))
    ok

    // HUD
    ast_drawHUD()

    // State overlays
    if gameState = STATE_MENU
        ast_drawMenu()
    ok
    if gameState = STATE_PAUSED
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 150))
        DrawText("PAUSED", SCREEN_W/2 - 65, SCREEN_H/2 - 20, 32, RAYLIBColor(200, 200, 255, 220))
        DrawText("P to resume", SCREEN_W/2 - 50, SCREEN_H/2 + 20, 16, RAYLIBColor(180, 180, 200, 180))
    ok
    if gameState = STATE_DEAD
        ast_drawGameOver()
    ok

// =============================================================
// Draw Ship
// =============================================================

func ast_drawShip
    // Blink when invulnerable
    if shipInvuln > 0
        if floor(animTime * 10) % 2 = 0 return ok
    ok

    rad = shipAngle * DEG2RAD
    sx = floor(shipX)  sy = floor(shipY)

    // Ship triangle points
    noseX = sx + floor(cos(rad) * 16)
    noseY = sy + floor(sin(rad) * 16)

    leftRad = (shipAngle + 140) * DEG2RAD
    leftX = sx + floor(cos(leftRad) * 14)
    leftY = sy + floor(sin(leftRad) * 14)

    rightRad = (shipAngle - 140) * DEG2RAD
    rightX = sx + floor(cos(rightRad) * 14)
    rightY = sy + floor(sin(rightRad) * 14)

    // Glow
    DrawCircle(sx, sy, 18, RAYLIBColor(80, 120, 200, 20))

    // Ship body
    DrawTriangle(Vector2(noseX, noseY), Vector2(rightX, rightY), Vector2(leftX, leftY),
                RAYLIBColor(80, 160, 255, 230))
    // Outline
    DrawLine(noseX, noseY, leftX, leftY, RAYLIBColor(150, 200, 255, 255))
    DrawLine(noseX, noseY, rightX, rightY, RAYLIBColor(150, 200, 255, 255))
    DrawLine(leftX, leftY, rightX, rightY, RAYLIBColor(120, 180, 255, 200))

    // Cockpit dot
    DrawCircle(sx + floor(cos(rad) * 5), sy + floor(sin(rad) * 5), 3, RAYLIBColor(200, 220, 255, 200))

    // Engine flame
    if shipThrust
        eRad = (shipAngle + 180) * DEG2RAD
        flameLen = 8 + floor(sin(animTime * 20) * 5)
        fx = sx + floor(cos(eRad) * flameLen)
        fy = sy + floor(sin(eRad) * flameLen)
        DrawTriangle(
            Vector2(leftX, leftY),
            Vector2(fx, fy),
            Vector2(rightX, rightY),
            RAYLIBColor(255, 180, 50, floor(180 + sin(animTime * 25) * 60)))
    ok

    // Shield
    if shieldActive
        sAlpha = floor(40 + sin(animTime * 6) * 20)
        DrawCircleLines(sx, sy, 22, RAYLIBColor(100, 200, 255, sAlpha + 80))
        DrawCircle(sx, sy, 22, RAYLIBColor(80, 180, 255, sAlpha))
    ok

// =============================================================
// Draw Asteroid
// =============================================================

func ast_drawAsteroid idx
    ax = floor(astX[idx])
    ay = floor(astY[idx])
    sz = astSize[idx]
    rad = ast_getRadius(sz)
    rot = astRot[idx] * DEG2RAD

    // Color by size
    cr = 130  cg = 120  cb = 110
    if sz = AST_MED cr = 140  cg = 130  cb = 115 ok
    if sz = AST_SMALL cr = 160  cg = 150  cb = 130 ok

    // Draw as polygon (8 vertices)
    verts = 8
    // Parse shape offsets
    offStr = astShape[idx]
    offs = []
    start = 1
    for v = 1 to verts
        comma = 0
        for c = start to len(offStr)
            if substr(offStr, c, 1) = ","
                comma = c
                exit
            ok
        next
        if comma > 0
            val = number(substr(offStr, start, comma - start))
            add(offs, val)
            start = comma + 1
        else
            add(offs, 85)
        ok
    next

    // Draw filled triangles from center to edges
    for v = 1 to verts
        a1 = rot + (v - 1) * (2 * PI / verts)
        a2 = rot + v * (2 * PI / verts)
        r1 = rad * offs[v] / 100.0
        nv = v + 1
        if nv > verts nv = 1 ok
        r2 = rad * offs[nv] / 100.0

        x1 = ax + floor(cos(a1) * r1)
        y1 = ay + floor(sin(a1) * r1)
        x2 = ax + floor(cos(a2) * r2)
        y2 = ay + floor(sin(a2) * r2)

        DrawTriangle(Vector2(ax, ay), Vector2(x2, y2), Vector2(x1, y1),
                    RAYLIBColor(cr, cg, cb, 200))
    next

    // Outline
    for v = 1 to verts
        a1 = rot + (v - 1) * (2 * PI / verts)
        a2 = rot + v * (2 * PI / verts)
        r1 = rad * offs[v] / 100.0
        nv = v + 1
        if nv > verts nv = 1 ok
        r2 = rad * offs[nv] / 100.0

        x1 = ax + floor(cos(a1) * r1)
        y1 = ay + floor(sin(a1) * r1)
        x2 = ax + floor(cos(a2) * r2)
        y2 = ay + floor(sin(a2) * r2)

        DrawLine(x1, y1, x2, y2, RAYLIBColor(200, 190, 170, 230))
    next

// =============================================================
// Draw UFO
// =============================================================

func ast_drawUFO idx
    ux = floor(ufoX[idx])
    uy = floor(ufoY[idx])
    s = ufoSz[idx]

    // Body ellipse
    DrawCircle(ux, uy, s, RAYLIBColor(200, 60, 200, 200))
    DrawCircle(ux, uy, s - 3, RAYLIBColor(230, 100, 230, 180))

    // Dome
    DrawCircle(ux, uy - 5, s - 8, RAYLIBColor(200, 220, 255, 180))

    // Rim
    DrawRectangle(ux - s - 4, uy - 2, (s + 4) * 2, 4, RAYLIBColor(180, 50, 180, 200))

    // Lights
    for l = 0 to 2
        lx = ux - s + l * s + floor(sin(animTime * 4 + l * 2) * 3)
        bright = floor(fabs(sin(animTime * 6 + l)) * 200) + 55
        DrawCircle(lx, uy + 2, 2, RAYLIBColor(255, 255, bright, 230))
    next

// =============================================================
// HUD
// =============================================================

func ast_drawHUD
    // Score
    sTxt = string(score)
    DrawText(sTxt, SCREEN_W/2 - MeasureText(sTxt, 28)/2, 10, 28, RAYLIBColor(255, 255, 255, 220))

    // Wave
    DrawText("WAVE " + string(wave), 10, 10, 16, RAYLIBColor(150, 200, 255, 180))

    // Lives
    for i = 1 to lives
        lx = SCREEN_W - 35 * i
        ly = 15
        rad = -90 * DEG2RAD
        DrawTriangle(
            Vector2(lx + floor(cos(rad) * 10), ly + floor(sin(rad) * 10)),
            Vector2(lx + floor(cos(rad + 2.5) * 8), ly + floor(sin(rad + 2.5) * 8)),
            Vector2(lx + floor(cos(rad - 2.5) * 8), ly + floor(sin(rad - 2.5) * 8)),
            RAYLIBColor(80, 160, 255, 200))
    next

    // Shield bar
    DrawRectangle(10, SCREEN_H - 22, 102, 12, RAYLIBColor(0, 0, 0, 150))
    shFrac = shieldEnergy / shieldMax
    DrawRectangle(11, SCREEN_H - 21, floor(100 * shFrac), 10, RAYLIBColor(80, 180, 255, 180))
    DrawText("SHIELD", 14, SCREEN_H - 21, 10, RAYLIBColor(200, 220, 255, 150))

    // Active power-ups
    puY2 = SCREEN_H - 40
    if triShotTimer > 0
        DrawText("TRIPLE [" + string(floor(triShotTimer)) + "s]", 10, puY2, 12, RAYLIBColor(255, 200, 50, 200))
        puY2 -= 16
    ok
    if rapidFireTimer > 0
        DrawText("RAPID [" + string(floor(rapidFireTimer)) + "s]", 10, puY2, 12, RAYLIBColor(50, 200, 255, 200))
    ok

    // Difficulty
    DrawText(diffNames[difficulty], SCREEN_W - 60, SCREEN_H - 18, 10, RAYLIBColor(150, 150, 170, 80))

    // FPS
    DrawText("" + string(GetFPS()) + " FPS", SCREEN_W - 55, SCREEN_H - 32, 10, RAYLIBColor(100, 200, 100, 70))

    // Controls
    DrawText("WASD:Move Space:Fire Shift:Hyperspace Tab:Shield P:Pause", 120, SCREEN_H - 15, 10, RAYLIBColor(100, 100, 120, 60))

// =============================================================
// Menu
// =============================================================

func ast_drawMenu
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 100))

    // Title
    ty = 180 + floor(sin(animTime * 1.5) * 10)
    DrawText("ASTEROIDS", SCREEN_W/2 - 140, ty, 48, RAYLIBColor(200, 200, 220, 255))
    DrawText("RingRayLib Edition", SCREEN_W/2 - 80, ty + 55, 16, RAYLIBColor(150, 160, 180, 180))

    flashA = floor(fabs(sin(animTime * 2.5)) * 200) + 55
    DrawText("Press SPACE to Start", SCREEN_W/2 - 95, 380, 20, RAYLIBColor(255, 255, 255, flashA))

    DrawText("1:Easy   2:Normal   3:Hard", SCREEN_W/2 - 100, 420, 14, RAYLIBColor(180, 180, 200, 150))
    DrawText("Current: " + diffNames[difficulty], SCREEN_W/2 - 50, 440, 14, RAYLIBColor(200, 200, 255, 180))

    if bestScore > 0
        DrawText("Best: " + string(bestScore), SCREEN_W/2 - 40, 480, 18, RAYLIBColor(255, 215, 0, 200))
    ok

// =============================================================
// Game Over
// =============================================================

func ast_drawGameOver
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 160))

    DrawText("GAME OVER", SCREEN_W/2 - 110, SCREEN_H/2 - 60, 36, RAYLIBColor(255, 80, 60, 255))

    DrawText("Score: " + string(score), SCREEN_W/2 - 55, SCREEN_H/2 - 10, 22, WHITE)
    DrawText("Wave: " + string(wave), SCREEN_W/2 - 35, SCREEN_H/2 + 20, 18, RAYLIBColor(200, 200, 220, 200))

    if score >= bestScore and score > 0
        DrawText("NEW HIGH SCORE!", SCREEN_W/2 - 80, SCREEN_H/2 + 50, 18, RAYLIBColor(255, 215, 0, floor(fabs(sin(animTime * 4)) * 200 + 55)))
    ok

    flashA = floor(fabs(sin(animTime * 3)) * 200) + 55
    DrawText("Space / R to Restart", SCREEN_W/2 - 85, SCREEN_H/2 + 85, 16, RAYLIBColor(200, 200, 220, flashA))
