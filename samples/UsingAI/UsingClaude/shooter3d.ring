/*
**  Space Shooter 3D - Using RingRayLib
**  ======================================
**  Fly your ship through asteroid fields and enemy waves!
**
**  Controls:
**    W/S or Up/Down     -  Move up / down
**    A/D or Left/Right  -  Move left / right
**    SPACE or Left Click-  Shoot
**    P                  -  Pause
**    R                  -  Restart game
**    ESC                -  Exit
**
**  Enemies:
**    Brown   Asteroid   -  Drifts toward you, takes 1-3 hits
**    Red     Fighter    -  Flies at you, shoots back
**    Blue    Drone      -  Weaves side to side, fast
**    Green   Bomber     -  Slow, tanky, drops spread shots
**    Gold    BOSS       -  Appears every 5 waves, huge HP
**
**  Power-Ups (colored orbs):
**    Blue    -  Rapid Fire (faster shooting)
**    Green   -  Spread Shot (3-way)
**    Red     -  Shield (absorbs 1 hit)
**    Yellow  -  Bomb (destroys all enemies on screen)
**
**  Features:
**    - 3D starfield parallax background
**    - Progressive wave difficulty
**    - Boss fights every 5 waves
**    - Combo scoring multiplier
**    - Particle explosions
**    - Ship banking on movement
**    - Lives and shield system
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W    = 1024
SCREEN_H    = 768

// Play area bounds (world coords)
AREA_LEFT   = -12.0
AREA_RIGHT  = 12.0
AREA_TOP    = 8.0
AREA_BOT    = -8.0
AREA_DEPTH  = -30.0

// Player
PL_SPEED    = 15.0
PL_RAD      = 0.5
SHOOT_CD    = 0.18
RAPID_CD    = 0.08

// Bullets
BUL_SPEED   = 35.0
BUL_RAD     = 0.15
EN_BUL_SPD  = 12.0

// Enemy types
ET_ASTER    = 1
ET_FIGHTER  = 2
ET_DRONE    = 3
ET_BOMBER   = 4
ET_BOSS     = 5

// Powerup types
PU_RAPID    = 1
PU_SPREAD   = 2
PU_SHIELD   = 3
PU_BOMB     = 4

// Game states
GS_TITLE    = 1
GS_PLAY     = 2
GS_PAUSE    = 3
GS_DEAD     = 4
GS_GAMEOVER = 5

// =============================================================
// Globals
// =============================================================

gameState  = GS_TITLE
animTime   = 0.0
dt         = 0.0

// Player
plX = 0.0   plY = 0.0   plZ = 0.0
plBank = 0.0
plLives = 3
plScore = 0
plShield = false
shieldTimer = 0.0
invTimer = 0.0

// Shooting
shootTimer = 0.0
rapidTimer = 0.0
spreadTimer = 0.0

// Combo
comboCount = 0
comboTimer = 0.0
comboMult = 1

// Waves
curWave = 0
waveTimer = 0.0
waveActive = false
spawnTimer = 0.0
spawnIdx = 0
spawnMax = 0
waveDelay = 3.0
bossWave = false

// Lists (flat: each entity = fixed fields in list)
// Bullets: [x, y, z, vx, vy, vz, alive, isEnemy]
bullets = []

// Enemies: [x, y, z, vx, vy, vz, alive, hp, maxhp, type, timer, shootT]
enemies = []

// Particles: [x, y, z, vx, vy, vz, life, r, g, b]
parts = []

// Powerups: [x, y, z, vx, vy, vz, alive, type]
pups = []

// Stars: [x, y, z, speed]
stars = []
STAR_COUNT = 200

// Camera
camera = 0

// Score display
hiScore = 0
screenShake = 0.0

// Death
deathTimer = 0.0

// =============================================================
// Main
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Space Shooter 3D - RingRayLib")
SetTargetFPS(60)

camera = Camera3D(
    0, 0, 20,
    0, 0, 0,
    0, 1, 0,
    50.0,
    CAMERA_PERSPECTIVE
)

ss_initStars()

while !WindowShouldClose()
    dt = GetFrameTime()
    if dt > 0.033 dt = 0.033 ok
    animTime += dt

    if gameState = GS_TITLE
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            ss_newGame()
            gameState = GS_PLAY
        ok
        ss_updateStars()
    but gameState = GS_PLAY
        if IsKeyPressed(KEY_P) gameState = GS_PAUSE ok
        if IsKeyPressed(KEY_R) ss_newGame() ok
        ss_updatePlayer()
        ss_updateShooting()
        ss_updateBullets()
        ss_updateEnemies()
        ss_updateWaves()
        ss_updatePowerups()
        ss_updateParts()
        ss_updateStars()
        ss_checkCollisions()
        if screenShake > 0 screenShake -= dt * 4 ok
        if screenShake < 0 screenShake = 0 ok
    but gameState = GS_PAUSE
        if IsKeyPressed(KEY_P) or IsKeyPressed(KEY_SPACE)
            gameState = GS_PLAY
        ok
    but gameState = GS_DEAD
        deathTimer -= dt
        ss_updateParts()
        ss_updateStars()
        if deathTimer <= 0
            plLives -= 1
            if plLives <= 0
                gameState = GS_GAMEOVER
            else
                ss_respawn()
                gameState = GS_PLAY
            ok
        ok
    but gameState = GS_GAMEOVER
        ss_updateParts()
        ss_updateStars()
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            ss_newGame()
            gameState = GS_PLAY
        ok
    ok

    ss_updateCamera()

    BeginDrawing()
        ClearBackground(RAYLIBColor(5, 5, 15, 255))

        BeginMode3D(camera)
            ss_drawStars()
            if gameState = GS_PLAY or gameState = GS_PAUSE
                ss_drawPlayer()
            ok
            ss_drawEnemies()
            ss_drawBullets()
            ss_drawPowerups()
            ss_drawParts()
        EndMode3D()

        ss_drawHUD()
        if gameState = GS_TITLE ss_drawTitle() ok
        if gameState = GS_PAUSE ss_drawPause() ok
        if gameState = GS_DEAD ss_drawDead() ok
        if gameState = GS_GAMEOVER ss_drawGameOver() ok

        DrawFPS(SCREEN_W - 90, SCREEN_H - 25)
    EndDrawing()
end

CloseWindow()

// =============================================================
// Init Stars (3D parallax)
// =============================================================

func ss_initStars
    stars = []
    for i = 1 to STAR_COUNT
        sx = GetRandomValue(-250, 250) / 10.0
        sy = GetRandomValue(-180, 180) / 10.0
        sz = GetRandomValue(-400, -20) / 10.0
        spd = GetRandomValue(20, 80) / 10.0
        add(stars, [sx, sy, sz, spd])
    next

// =============================================================
// New Game
// =============================================================

func ss_newGame
    plX = 0.0  plY = 0.0  plZ = 0.0
    plBank = 0.0
    plLives = 3
    plScore = 0
    plShield = false
    shieldTimer = 0.0
    invTimer = 0.0
    shootTimer = 0.0
    rapidTimer = 0.0
    spreadTimer = 0.0
    comboCount = 0
    comboTimer = 0.0
    comboMult = 1
    curWave = 0
    waveTimer = 0.0
    waveActive = false
    spawnTimer = 0.0
    spawnIdx = 0
    spawnMax = 0
    bossWave = false
    bullets = []
    enemies = []
    parts = []
    pups = []
    screenShake = 0.0
    deathTimer = 0.0
    waveDelay = 3.0
    ss_launchWave()

func ss_respawn
    plX = 0.0
    plY = 0.0
    plZ = 0.0
    plBank = 0.0
    invTimer = 2.0
    plShield = false
    shieldTimer = 0.0
    bullets = []

// =============================================================
// Player Movement
// =============================================================

func ss_updatePlayer
    // Movement
    mx = 0.0
    my = 0.0
    if IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_A)   mx -= 1.0 ok
    if IsKeyDown(KEY_RIGHT) or IsKeyDown(KEY_D)  mx += 1.0 ok
    if IsKeyDown(KEY_UP) or IsKeyDown(KEY_W)     my += 1.0 ok
    if IsKeyDown(KEY_DOWN) or IsKeyDown(KEY_S)   my -= 1.0 ok

    plX += mx * PL_SPEED * dt
    plY += my * PL_SPEED * dt

    // Clamp to area
    if plX < AREA_LEFT plX = AREA_LEFT ok
    if plX > AREA_RIGHT plX = AREA_RIGHT ok
    if plY < AREA_BOT plY = AREA_BOT ok
    if plY > AREA_TOP plY = AREA_TOP ok

    // Banking
    targetBank = -mx * 0.4
    plBank += (targetBank - plBank) * 8.0 * dt

    // Timers
    if invTimer > 0 invTimer -= dt ok
    if rapidTimer > 0 rapidTimer -= dt ok
    if spreadTimer > 0 spreadTimer -= dt ok
    if shieldTimer > 0
        shieldTimer -= dt
        if shieldTimer <= 0 plShield = false ok
    ok

    // Combo timer
    if comboTimer > 0
        comboTimer -= dt
        if comboTimer <= 0
            comboCount = 0
            comboMult = 1
        ok
    ok

// =============================================================
// Shooting
// =============================================================

func ss_updateShooting
    shootTimer -= dt
    shooting = false
    if IsKeyDown(KEY_SPACE) or IsMouseButtonDown(MOUSE_LEFT_BUTTON)
        shooting = true
    ok

    if shooting and shootTimer <= 0
        cd = SHOOT_CD
        if rapidTimer > 0 cd = RAPID_CD ok

        shootTimer = cd

        if spreadTimer > 0
            // 3-way spread
            add(bullets, [plX, plY, plZ, 0, 0, -BUL_SPEED, true, false])
            add(bullets, [plX, plY, plZ, -BUL_SPEED * 0.15, 0, -BUL_SPEED * 0.98, true, false])
            add(bullets, [plX, plY, plZ, BUL_SPEED * 0.15, 0, -BUL_SPEED * 0.98, true, false])
        else
            add(bullets, [plX, plY, plZ, 0, 0, -BUL_SPEED, true, false])
        ok
    ok

// =============================================================
// Bullets
// =============================================================

func ss_updateBullets
    i = 1
    nB = len(bullets)
    while i <= nB
        b = bullets[i]
        if !b[7]
            del(bullets, i)
            nB -= 1
            loop
        ok
        b[1] += b[4] * dt
        b[2] += b[5] * dt
        b[3] += b[6] * dt
        // Out of bounds
        if b[3] < AREA_DEPTH or b[3] > 25
            del(bullets, i)
            nB -= 1
            loop
        ok
        if b[1] < AREA_LEFT - 3 or b[1] > AREA_RIGHT + 3
            del(bullets, i)
            nB -= 1
            loop
        ok
        if b[2] < AREA_BOT - 3 or b[2] > AREA_TOP + 3
            del(bullets, i)
            nB -= 1
            loop
        ok
        bullets[i] = b
        i += 1
    end

// =============================================================
// Waves
// =============================================================

func ss_updateWaves
    if !waveActive
        waveTimer += dt
        if waveTimer >= waveDelay
            ss_launchWave()
        ok
        return
    ok

    // Spawn enemies in wave
    spawnTimer += dt
    gap = 0.7 - curWave * 0.02
    if gap < 0.2 gap = 0.2 ok
    if bossWave gap = 99.0 ok

    if spawnTimer >= gap and spawnIdx < spawnMax
        spawnTimer -= gap
        spawnIdx += 1
        ss_spawnEnemy()
    ok

    // Check wave done
    if spawnIdx >= spawnMax
        allDead = true
        nE = len(enemies)
        eIdx = 1
        while eIdx <= nE
            if enemies[eIdx][7]
                allDead = false
                eIdx = nE + 1
            ok
            eIdx += 1
        end
        if allDead
            waveActive = false
            waveTimer = 0.0
            plScore += curWave * 50
        ok
    ok

func ss_launchWave
    curWave += 1
    waveActive = true
    waveTimer = 0.0
    spawnTimer = 0.0
    spawnIdx = 0

    // Boss every 5 waves
    remainder = curWave
    while remainder > 5
        remainder -= 5
    end
    if remainder = 0
        bossWave = true
        spawnMax = 1
    else
        bossWave = false
        spawnMax = 4 + curWave * 2
        if spawnMax > 30 spawnMax = 30 ok
    ok

// =============================================================
// Spawn Enemy
// =============================================================

func ss_spawnEnemy
    ex = GetRandomValue(-100, 100) / 10.0
    ey = GetRandomValue(-60, 60) / 10.0
    ez = -25.0 - GetRandomValue(0, 80) / 10.0

    if bossWave
        // Boss
        hp = 80 + curWave * 20
        add(enemies, [0.0, 2.0, -22.0, 0, 0, 3.0, true, hp, hp, ET_BOSS, 0.0, 0.0])
        return
    ok

    // Choose type based on wave
    roll = GetRandomValue(1, 100)
    etype = ET_ASTER
    hp = 1

    if curWave >= 2 and roll <= 30
        etype = ET_FIGHTER
        hp = 2
    ok
    if curWave >= 4 and roll <= 15
        etype = ET_DRONE
        hp = 1
    ok
    if curWave >= 6 and roll <= 10
        etype = ET_BOMBER
        hp = 4
    ok

    if etype = ET_ASTER
        hp = 1 + GetRandomValue(0, 2)
        if curWave > 8 hp += 1 ok
    ok

    // Speed toward player
    spd = 4.0 + curWave * 0.3
    if etype = ET_FIGHTER spd = 6.0 + curWave * 0.2 ok
    if etype = ET_DRONE   spd = 8.0 ok
    if etype = ET_BOMBER  spd = 3.0 ok

    add(enemies, [ex, ey, ez, 0, 0, spd, true, hp, hp, etype, 0.0, 0.0])

// =============================================================
// Update Enemies
// =============================================================

func ss_updateEnemies
    i = 1
    nE = len(enemies)
    while i <= nE
        e = enemies[i]
        if !e[7]
            del(enemies, i)
            nE -= 1
            loop
        ok

        eType = e[10]
        e[11] += dt

        // Movement by type
        if eType = ET_ASTER
            e[3] += e[6] * dt
            // Slight wobble
            e[1] += sin(e[11] * 2 + i) * 2.0 * dt
        ok

        if eType = ET_FIGHTER
            // Move toward player on Z, track player X/Y slowly
            e[3] += e[6] * dt
            dx = plX - e[1]
            dy = plY - e[2]
            e[1] += dx * 1.5 * dt
            e[2] += dy * 1.0 * dt
            // Shoot
            e[12] += dt
            if e[12] > 1.5
                e[12] = 0.0
                bvz = EN_BUL_SPD
                add(bullets, [e[1], e[2], e[3], 0, 0, bvz, true, true])
            ok
        ok

        if eType = ET_DRONE
            e[3] += e[6] * dt
            e[1] += sin(e[11] * 4) * 8.0 * dt
            e[2] += cos(e[11] * 3) * 3.0 * dt
        ok

        if eType = ET_BOMBER
            e[3] += e[6] * dt
            // Spread shot periodically
            e[12] += dt
            if e[12] > 2.5
                e[12] = 0.0
                for a = -2 to 2
                    bvx = a * 2.5
                    add(bullets, [e[1], e[2], e[3], bvx, 0, EN_BUL_SPD, true, true])
                next
            ok
        ok

        if eType = ET_BOSS
            // Boss movement: slow advance then hover
            if e[3] < -10
                e[3] += e[6] * dt
            else
                e[3] = -10.0
            ok
            e[1] += sin(e[11] * 1.5) * 4.0 * dt
            e[2] += cos(e[11] * 1.0) * 2.0 * dt
            // Multi-pattern shooting
            e[12] += dt
            if e[12] > 0.6
                e[12] = 0.0
                pattern = GetRandomValue(1, 3)
                if pattern = 1
                    // Aimed shot
                    add(bullets, [e[1], e[2], e[3], 0, 0, EN_BUL_SPD, true, true])
                ok
                if pattern = 2
                    // Spread
                    for a = -3 to 3
                        add(bullets, [e[1], e[2], e[3], a * 2.0, 0, EN_BUL_SPD, true, true])
                    next
                ok
                if pattern = 3
                    // Diagonal
                    add(bullets, [e[1], e[2], e[3], -4.0, 2.0, EN_BUL_SPD, true, true])
                    add(bullets, [e[1], e[2], e[3], 4.0, 2.0, EN_BUL_SPD, true, true])
                    add(bullets, [e[1], e[2], e[3], -4.0, -2.0, EN_BUL_SPD, true, true])
                    add(bullets, [e[1], e[2], e[3], 4.0, -2.0, EN_BUL_SPD, true, true])
                ok
            ok
        ok

        // Off screen (passed player)
        if e[3] > 22
            del(enemies, i)
            nE -= 1
            loop
        ok

        enemies[i] = e
        i += 1
    end

// =============================================================
// Powerups
// =============================================================

func ss_updatePowerups
    i = 1
    nP = len(pups)
    while i <= nP
        p = pups[i]
        if !p[7]
            del(pups, i)
            nP -= 1
            loop
        ok
        p[1] += p[4] * dt
        p[2] += p[5] * dt
        p[3] += p[6] * dt
        if p[3] > 22
            del(pups, i)
            nP -= 1
            loop
        ok
        pups[i] = p
        i += 1
    end

func ss_spawnPowerup ex, ey, ez
    roll = GetRandomValue(1, 100)
    if roll > 25 return ok
    pt = PU_RAPID
    pr = GetRandomValue(1, 4)
    if pr = 1 pt = PU_RAPID ok
    if pr = 2 pt = PU_SPREAD ok
    if pr = 3 pt = PU_SHIELD ok
    if pr = 4 pt = PU_BOMB ok
    add(pups, [ex, ey, ez, 0, 0, 5.0, true, pt])

// =============================================================
// Collisions
// =============================================================

func ss_checkCollisions
    // Player bullets vs enemies
    nB = len(bullets)
    nE = len(enemies)
    bi = 1
    while bi <= nB
        b = bullets[bi]
        if b[8]
            bi += 1
            loop
        ok
        if !b[7]
            bi += 1
            loop
        ok
        ei = 1
        while ei <= nE
            e = enemies[ei]
            if !e[7]
                ei += 1
                loop
            ok
            eRad = 0.6
            eType = e[10]
            if eType = ET_BOSS eRad = 2.0 ok
            if eType = ET_BOMBER eRad = 0.8 ok
            dx = b[1] - e[1]
            dy = b[2] - e[2]
            dz = b[3] - e[3]
            dist = dx * dx + dy * dy + dz * dz
            hitR = BUL_RAD + eRad
            if dist < hitR * hitR
                b[7] = false
                bullets[bi] = b
                e[8] -= 1
                if e[8] <= 0
                    e[7] = false
                    ss_enemyDeath(e)
                ok
                enemies[ei] = e
                ei = nE + 1
            ok
            ei += 1
        end
        bi += 1
    end

    // Enemy bullets vs player
    if invTimer <= 0
        bi = 1
        nB2 = len(bullets)
        while bi <= nB2
            b = bullets[bi]
            if !b[8] or !b[7]
                bi += 1
                loop
            ok
            dx = b[1] - plX
            dy = b[2] - plY
            dz = b[3] - plZ
            dist = dx * dx + dy * dy + dz * dz
            if dist < (PL_RAD + BUL_RAD) * (PL_RAD + BUL_RAD)
                b[7] = false
                bullets[bi] = b
                ss_playerHit()
                bi = nB2 + 1
                loop
            ok
            bi += 1
        end
    ok

    // Enemies vs player (collision)
    if invTimer <= 0
        nE2 = len(enemies)
        ei = 1
        while ei <= nE2
            e = enemies[ei]
            if !e[7]
                ei += 1
                loop
            ok
            eRad = 0.6
            if e[10] = ET_BOSS eRad = 2.0 ok
            dx = e[1] - plX
            dy = e[2] - plY
            dz = e[3] - plZ
            dist = dx * dx + dy * dy + dz * dz
            if dist < (PL_RAD + eRad) * (PL_RAD + eRad)
                ss_playerHit()
                ei = nE2 + 1
                loop
            ok
            ei += 1
        end
    ok

    // Player vs powerups
    nPu = len(pups)
    pi = 1
    while pi <= nPu
        p = pups[pi]
        if !p[7]
            pi += 1
            loop
        ok
        dx = p[1] - plX
        dy = p[2] - plY
        dz = p[3] - plZ
        dist = dx * dx + dy * dy + dz * dz
        if dist < (PL_RAD + 0.4) * (PL_RAD + 0.4)
            p[7] = false
            pups[pi] = p
            ss_collectPowerup(p[8])
        ok
        pi += 1
    end

// =============================================================
// Enemy Death
// =============================================================

func ss_enemyDeath e
    // Particles
    eType = e[10]
    pcount = 15
    if eType = ET_BOSS pcount = 50 ok
    for k = 1 to pcount
        vx = GetRandomValue(-300, 300) / 100.0
        vy = GetRandomValue(-300, 300) / 100.0
        vz = GetRandomValue(-300, 300) / 100.0
        pr = 255  pg = 150  pb = 30
        if eType = ET_FIGHTER pr = 255 pg = 60  pb = 60 ok
        if eType = ET_DRONE   pr = 60  pg = 150 pb = 255 ok
        if eType = ET_BOMBER  pr = 60  pg = 255 pb = 80 ok
        if eType = ET_BOSS    pr = 255 pg = 215 pb = 0 ok
        add(parts, [e[1], e[2], e[3], vx, vy, vz, 1.0, pr, pg, pb])
    next

    // Score
    pts = 100
    if eType = ET_FIGHTER pts = 200 ok
    if eType = ET_DRONE   pts = 150 ok
    if eType = ET_BOMBER  pts = 300 ok
    if eType = ET_BOSS    pts = 2000 ok
    comboCount += 1
    comboTimer = 2.0
    comboMult = 1 + comboCount / 5
    if comboMult > 8 comboMult = 8 ok
    plScore += pts * comboMult

    // Screen shake
    screenShake = 0.3
    if eType = ET_BOSS screenShake = 1.0 ok

    // Powerup drop
    ss_spawnPowerup(e[1], e[2], e[3])

    // Update hi score
    if plScore > hiScore hiScore = plScore ok

// =============================================================
// Player Hit
// =============================================================

func ss_playerHit
    if plShield
        plShield = false
        shieldTimer = 0.0
        invTimer = 0.5
        screenShake = 0.2
        ss_spawnShieldParts()
        return
    ok
    // Die
    for k = 1 to 30
        vx = GetRandomValue(-400, 400) / 100.0
        vy = GetRandomValue(-400, 400) / 100.0
        vz = GetRandomValue(-400, 400) / 100.0
        add(parts, [plX, plY, plZ, vx, vy, vz, 1.2, 100, 200, 255])
    next
    screenShake = 0.8
    gameState = GS_DEAD
    deathTimer = 1.5
    comboCount = 0
    comboMult = 1

func ss_spawnShieldParts
    for k = 1 to 15
        vx = GetRandomValue(-300, 300) / 100.0
        vy = GetRandomValue(-300, 300) / 100.0
        vz = GetRandomValue(-200, 200) / 100.0
        add(parts, [plX, plY, plZ, vx, vy, vz, 0.8, 80, 200, 255])
    next

// =============================================================
// Collect Powerup
// =============================================================

func ss_collectPowerup pType
    if pType = PU_RAPID
        rapidTimer = 6.0
    ok
    if pType = PU_SPREAD
        spreadTimer = 8.0
    ok
    if pType = PU_SHIELD
        plShield = true
        shieldTimer = 15.0
    ok
    if pType = PU_BOMB
        // Destroy all enemies
        nE = len(enemies)
        for ei = 1 to nE
            if enemies[ei][7]
                enemies[ei][7] = false
                ss_enemyDeath(enemies[ei])
            ok
        next
        screenShake = 1.0
    ok
    plScore += 50

// =============================================================
// Particles
// =============================================================

func ss_updateParts
    i = 1
    nP = len(parts)
    while i <= nP
        p = parts[i]
        p[1] += p[4] * dt
        p[2] += p[5] * dt
        p[3] += p[6] * dt
        p[7] -= dt
        if p[7] <= 0
            del(parts, i)
            nP -= 1
        else
            parts[i] = p
            i += 1
        ok
    end

// =============================================================
// Stars
// =============================================================

func ss_updateStars
    nS = len(stars)
    for i = 1 to nS
        s = stars[i]
        s[3] += s[4] * dt
        if s[3] > 5
            s[1] = GetRandomValue(-250, 250) / 10.0
            s[2] = GetRandomValue(-180, 180) / 10.0
            s[3] = -40.0
            s[4] = GetRandomValue(20, 80) / 10.0
        ok
        stars[i] = s
    next

// =============================================================
// Camera
// =============================================================

func ss_updateCamera
    shX = 0.0
    shY = 0.0
    if screenShake > 0
        shX = GetRandomValue(-100, 100) / 100.0 * screenShake
        shY = GetRandomValue(-100, 100) / 100.0 * screenShake
    ok
    camera.position.x = 0 + shX
    camera.position.y = 2 + shY
    camera.position.z = 20
    camera.target.x = 0 + shX * 0.3
    camera.target.y = 0 + shY * 0.3
    camera.target.z = -10

// =============================================================
// Draw Stars
// =============================================================

func ss_drawStars
    nS = len(stars)
    for i = 1 to nS
        s = stars[i]
        bright = 100 + floor(s[4] * 20)
        if bright > 255 bright = 255 ok
        sz = 0.03 + s[4] * 0.008
        DrawSphereEx(Vector3(s[1], s[2], s[3]), sz, 3, 3,
            RAYLIBColor(bright, bright, floor(bright * 0.9), 255))
    next

// =============================================================
// Draw Player
// =============================================================

func ss_drawPlayer
    // Flicker when invincible
    if invTimer > 0
        if floor(invTimer * 10) % 2 = 0 return ok
    ok

    // Ship body (elongated cone shape using cubes)
    DrawCube(Vector3(plX, plY, plZ), 0.6, 0.2, 1.4,
        RAYLIBColor(80, 140, 240, 255))
    DrawCubeWires(Vector3(plX, plY, plZ), 0.6, 0.2, 1.4,
        RAYLIBColor(120, 180, 255, 150))

    // Wings
    wingTilt = plBank * 2.0
    DrawCube(Vector3(plX - 0.7, plY + wingTilt, plZ + 0.2), 0.8, 0.08, 0.6,
        RAYLIBColor(60, 120, 220, 255))
    DrawCube(Vector3(plX + 0.7, plY - wingTilt, plZ + 0.2), 0.8, 0.08, 0.6,
        RAYLIBColor(60, 120, 220, 255))

    // Cockpit
    DrawSphereEx(Vector3(plX, plY + 0.12, plZ - 0.2), 0.2, 6, 6,
        RAYLIBColor(150, 220, 255, 200))

    // Engine glow
    pulse = 0.15 + sin(animTime * 15) * 0.05
    DrawSphereEx(Vector3(plX - 0.2, plY, plZ + 0.8), pulse, 4, 4,
        RAYLIBColor(255, 150, 50, 200))
    DrawSphereEx(Vector3(plX + 0.2, plY, plZ + 0.8), pulse, 4, 4,
        RAYLIBColor(255, 150, 50, 200))

    // Shield bubble
    if plShield
        shAlpha = 60 + floor(sin(animTime * 5) * 30)
        DrawSphereEx(Vector3(plX, plY, plZ), PL_RAD + 0.4, 10, 10,
            RAYLIBColor(60, 180, 255, shAlpha))
    ok

// =============================================================
// Draw Enemies
// =============================================================

func ss_drawEnemies
    nE = len(enemies)
    for i = 1 to nE
        e = enemies[i]
        if !e[7] loop ok
        ex = e[1]
        ey = e[2]
        ez = e[3]
        eType = e[10]

        if eType = ET_ASTER
            sz = 0.4 + (e[9] - 1) * 0.15
            DrawSphereEx(Vector3(ex, ey, ez), sz, 6, 6,
                RAYLIBColor(160, 120, 80, 255))
            DrawSphereEx(Vector3(ex, ey, ez), sz + 0.05, 4, 4,
                RAYLIBColor(130, 100, 65, 100))
        ok

        if eType = ET_FIGHTER
            DrawCube(Vector3(ex, ey, ez), 0.5, 0.15, 0.8,
                RAYLIBColor(220, 60, 60, 255))
            DrawCube(Vector3(ex - 0.4, ey, ez), 0.3, 0.06, 0.4,
                RAYLIBColor(180, 40, 40, 255))
            DrawCube(Vector3(ex + 0.4, ey, ez), 0.3, 0.06, 0.4,
                RAYLIBColor(180, 40, 40, 255))
            // HP flash
            hpPct = e[8] / e[9]
            if hpPct < 0.5
                flash = floor(sin(animTime * 8) * 40)
                DrawSphereEx(Vector3(ex, ey, ez), 0.3, 4, 4,
                    RAYLIBColor(255, 100 + flash, 50, 80))
            ok
        ok

        if eType = ET_DRONE
            DrawSphereEx(Vector3(ex, ey, ez), 0.35, 8, 8,
                RAYLIBColor(60, 140, 255, 255))
            pulse = 0.3 + sin(animTime * 6 + i) * 0.1
            DrawSphereEx(Vector3(ex, ey, ez), pulse, 6, 6,
                RAYLIBColor(100, 180, 255, 80))
        ok

        if eType = ET_BOMBER
            DrawCube(Vector3(ex, ey, ez), 0.9, 0.4, 1.0,
                RAYLIBColor(60, 180, 60, 255))
            DrawCubeWires(Vector3(ex, ey, ez), 0.9, 0.4, 1.0,
                RAYLIBColor(80, 220, 80, 120))
            DrawCube(Vector3(ex, ey + 0.2, ez), 0.3, 0.3, 0.5,
                RAYLIBColor(40, 140, 40, 255))
        ok

        if eType = ET_BOSS
            // Big boss ship
            bpulse = sin(animTime * 2) * 0.2
            DrawCube(Vector3(ex, ey, ez), 3.0, 0.6, 2.5,
                RAYLIBColor(200, 170, 40, 255))
            DrawCubeWires(Vector3(ex, ey, ez), 3.0, 0.6, 2.5,
                RAYLIBColor(255, 220, 80, 150))
            DrawCube(Vector3(ex, ey + 0.3, ez), 1.5, 0.5, 1.2,
                RAYLIBColor(220, 190, 60, 255))
            // Side cannons
            DrawCylinder(Vector3(ex - 1.2, ey - 0.1, ez - 0.8), 0.2, 0.15, 0.8, 6,
                RAYLIBColor(180, 150, 30, 255))
            DrawCylinder(Vector3(ex + 1.2, ey - 0.1, ez - 0.8), 0.2, 0.15, 0.8, 6,
                RAYLIBColor(180, 150, 30, 255))
            // HP bar
            hpPct = e[8] / e[9]
            barW = 3.0
            DrawCube(Vector3(ex, ey + 1.2, ez), barW, 0.1, 0.1,
                RAYLIBColor(60, 60, 60, 200))
            DrawCube(Vector3(ex - barW * (1 - hpPct) / 2, ey + 1.2, ez), barW * hpPct, 0.12, 0.12,
                RAYLIBColor(255, floor(hpPct * 200), 30, 230))
            // Glow
            DrawSphereEx(Vector3(ex, ey, ez - 1.0), 0.4 + bpulse, 6, 6,
                RAYLIBColor(255, 200, 50, 80))
        ok
    next

// =============================================================
// Draw Bullets
// =============================================================

func ss_drawBullets
    nB = len(bullets)
    for i = 1 to nB
        b = bullets[i]
        if !b[7] loop ok
        if b[8]
            // Enemy bullet (red)
            DrawSphereEx(Vector3(b[1], b[2], b[3]), BUL_RAD, 4, 4,
                RAYLIBColor(255, 80, 50, 255))
            DrawSphereEx(Vector3(b[1], b[2], b[3]), BUL_RAD + 0.05, 3, 3,
                RAYLIBColor(255, 120, 80, 80))
        else
            // Player bullet (cyan)
            DrawSphereEx(Vector3(b[1], b[2], b[3]), BUL_RAD, 4, 4,
                RAYLIBColor(100, 220, 255, 255))
            DrawSphereEx(Vector3(b[1], b[2], b[3]), BUL_RAD + 0.06, 3, 3,
                RAYLIBColor(150, 240, 255, 80))
        ok
    next

// =============================================================
// Draw Powerups
// =============================================================

func ss_drawPowerups
    nP = len(pups)
    for i = 1 to nP
        p = pups[i]
        if !p[7] loop ok
        pType = p[8]
        pr = 100  pg = 200  pb = 255
        if pType = PU_RAPID  pr = 80   pg = 180  pb = 255 ok
        if pType = PU_SPREAD pr = 80   pg = 255  pb = 100 ok
        if pType = PU_SHIELD pr = 255  pg = 60   pb = 60  ok
        if pType = PU_BOMB   pr = 255  pg = 220  pb = 50  ok
        pulse = 0.3 + sin(animTime * 4 + i) * 0.08
        DrawSphereEx(Vector3(p[1], p[2], p[3]), pulse, 8, 8,
            RAYLIBColor(pr, pg, pb, 255))
        DrawSphereEx(Vector3(p[1], p[2], p[3]), pulse + 0.12, 6, 6,
            RAYLIBColor(pr, pg, pb, 60))
    next

// =============================================================
// Draw Particles
// =============================================================

func ss_drawParts
    nP = len(parts)
    for i = 1 to nP
        p = parts[i]
        alpha = floor(p[7] / 1.2 * 255)
        if alpha > 255 alpha = 255 ok
        if alpha < 0 alpha = 0 ok
        sz = 0.05 + p[7] * 0.08
        DrawSphereEx(Vector3(p[1], p[2], p[3]), sz, 3, 3,
            RAYLIBColor(p[8], p[9], p[10], alpha))
    next

// =============================================================
// HUD
// =============================================================

func ss_drawHUD
    // Top bar
    DrawRectangle(0, 0, SCREEN_W, 50, RAYLIBColor(0, 0, 0, 160))

    // Score
    DrawText("SCORE: " + plScore, 15, 8, 22, RAYLIBColor(255, 220, 100, 255))

    // Hi Score
    DrawText("HI: " + hiScore, 15, 30, 14, RAYLIBColor(180, 180, 200, 180))

    // Wave
    waveTxt = "WAVE " + curWave
    if bossWave and waveActive waveTxt = "BOSS WAVE " + curWave ok
    ww = MeasureText(waveTxt, 20)
    DrawText(waveTxt, (SCREEN_W - ww) / 2, 12, 20,
        RAYLIBColor(200, 210, 230, 230))

    // Lives
    for lf = 1 to plLives
        lx = SCREEN_W - 30 * lf
        DrawRectangle(lx, 10, 20, 8, RAYLIBColor(80, 160, 255, 230))
        DrawRectangle(lx + 2, 20, 16, 4, RAYLIBColor(60, 130, 220, 200))
    next
    DrawText("LIVES", SCREEN_W - 30 * plLives - 50, 12, 14,
        RAYLIBColor(180, 190, 200, 200))

    // Combo
    if comboMult > 1
        comTxt = "x" + comboMult + " COMBO"
        comW = MeasureText(comTxt, 18)
        DrawText(comTxt, (SCREEN_W - comW) / 2, 38, 18,
            RAYLIBColor(255, 200, 50, 230))
    ok

    // Power-up indicators
    puY = 60
    if rapidTimer > 0
        DrawRectangle(10, puY, 130, 18, RAYLIBColor(0, 0, 0, 150))
        fillW = floor(120 * rapidTimer / 6.0)
        DrawRectangle(15, puY + 2, fillW, 14, RAYLIBColor(80, 180, 255, 200))
        DrawText("RAPID", 18, puY + 3, 12, WHITE)
        puY += 22
    ok
    if spreadTimer > 0
        DrawRectangle(10, puY, 130, 18, RAYLIBColor(0, 0, 0, 150))
        fillW = floor(120 * spreadTimer / 8.0)
        DrawRectangle(15, puY + 2, fillW, 14, RAYLIBColor(80, 255, 120, 200))
        DrawText("SPREAD", 18, puY + 3, 12, WHITE)
        puY += 22
    ok
    if plShield
        DrawRectangle(10, puY, 130, 18, RAYLIBColor(0, 0, 0, 150))
        fillW = floor(120 * shieldTimer / 15.0)
        DrawRectangle(15, puY + 2, fillW, 14, RAYLIBColor(255, 80, 80, 200))
        DrawText("SHIELD", 18, puY + 3, 12, WHITE)
    ok

    // Bottom bar
    DrawRectangle(0, SCREEN_H - 28, SCREEN_W, 28, RAYLIBColor(0, 0, 0, 120))
    DrawText("WASD/Arrows=Move  SPACE/Click=Shoot  P=Pause  R=Restart", 15, SCREEN_H - 20, 13,
        RAYLIBColor(140, 150, 160, 180))

// =============================================================
// Title Screen
// =============================================================

func ss_drawTitle
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 160))

    t1 = "SPACE SHOOTER 3D"
    t1w = MeasureText(t1, 52)
    pulse = sin(animTime * 3) * 5
    DrawText(t1, (SCREEN_W - t1w)/2, 150 + floor(pulse), 52,
        RAYLIBColor(80, 200, 255, 255))

    t2 = "Survive the asteroid fields and enemy waves!"
    t2w = MeasureText(t2, 20)
    DrawText(t2, (SCREEN_W - t2w)/2, 230, 20,
        RAYLIBColor(200, 210, 220, 220))

    ty = 280
    DrawText("WASD / Arrows  -  Move your ship", 320, ty, 16,
        RAYLIBColor(180, 190, 200, 200))
    DrawText("SPACE / Click  -  Shoot", 320, ty + 24, 16,
        RAYLIBColor(180, 190, 200, 200))
    DrawText("P              -  Pause", 320, ty + 48, 16,
        RAYLIBColor(180, 190, 200, 200))
    DrawText("R              -  Restart", 320, ty + 72, 16,
        RAYLIBColor(180, 190, 200, 200))

    ty2 = 400
    DrawText("Enemies:", 280, ty2, 18, RAYLIBColor(220, 220, 230, 230))
    DrawRectangle(280, ty2 + 25, 14, 14, RAYLIBColor(160, 120, 80, 255))
    DrawText("Asteroid - drifts, 1-3 hits", 302, ty2 + 25, 14,
        RAYLIBColor(180, 180, 190, 200))
    DrawRectangle(280, ty2 + 44, 14, 14, RAYLIBColor(220, 60, 60, 255))
    DrawText("Fighter - tracks you, shoots back", 302, ty2 + 44, 14,
        RAYLIBColor(180, 180, 190, 200))
    DrawRectangle(280, ty2 + 63, 14, 14, RAYLIBColor(60, 140, 255, 255))
    DrawText("Drone - fast, weaves around", 302, ty2 + 63, 14,
        RAYLIBColor(180, 180, 190, 200))
    DrawRectangle(280, ty2 + 82, 14, 14, RAYLIBColor(60, 180, 60, 255))
    DrawText("Bomber - tanky, fires spread shots", 302, ty2 + 82, 14,
        RAYLIBColor(180, 180, 190, 200))
    DrawRectangle(280, ty2 + 101, 14, 14, RAYLIBColor(200, 170, 40, 255))
    DrawText("BOSS - every 5 waves, massive HP", 302, ty2 + 101, 14,
        RAYLIBColor(180, 180, 190, 200))

    ty3 = 550
    DrawText("Power-Ups:", 280, ty3, 16, RAYLIBColor(220, 220, 230, 230))
    DrawCircle(290, ty3 + 22, 6, RAYLIBColor(80, 180, 255, 255))
    DrawText("Rapid Fire", 304, ty3 + 16, 14, RAYLIBColor(180, 190, 200, 200))
    DrawCircle(430, ty3 + 22, 6, RAYLIBColor(80, 255, 100, 255))
    DrawText("Spread Shot", 444, ty3 + 16, 14, RAYLIBColor(180, 190, 200, 200))
    DrawCircle(580, ty3 + 22, 6, RAYLIBColor(255, 60, 60, 255))
    DrawText("Shield", 594, ty3 + 16, 14, RAYLIBColor(180, 190, 200, 200))
    DrawCircle(680, ty3 + 22, 6, RAYLIBColor(255, 220, 50, 255))
    DrawText("Bomb", 694, ty3 + 16, 14, RAYLIBColor(180, 190, 200, 200))

    if floor(animTime * 2) % 2 = 0
        t3 = "Press ENTER or SPACE to Start"
        t3w = MeasureText(t3, 24)
        DrawText(t3, (SCREEN_W - t3w)/2, 620, 24,
            RAYLIBColor(255, 255, 200, 255))
    ok

// =============================================================
// Pause
// =============================================================

func ss_drawPause
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 150))
    t1 = "PAUSED"
    t1w = MeasureText(t1, 48)
    DrawText(t1, (SCREEN_W - t1w)/2, SCREEN_H/2 - 40, 48,
        RAYLIBColor(200, 210, 230, 255))
    t2 = "Press P or SPACE to Resume"
    t2w = MeasureText(t2, 20)
    DrawText(t2, (SCREEN_W - t2w)/2, SCREEN_H/2 + 20, 20,
        RAYLIBColor(160, 170, 180, 200))

// =============================================================
// Death
// =============================================================

func ss_drawDead
    DrawRectangle(SCREEN_W/3, SCREEN_H/2 - 30, SCREEN_W/3, 60,
        RAYLIBColor(200, 30, 20, 200))
    t1 = "SHIP DESTROYED!"
    t1w = MeasureText(t1, 28)
    DrawText(t1, (SCREEN_W - t1w)/2, SCREEN_H/2 - 14, 28, WHITE)

// =============================================================
// Game Over
// =============================================================

func ss_drawGameOver
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 200))

    t1 = "GAME OVER"
    t1w = MeasureText(t1, 52)
    pulse = sin(animTime * 3) * 4
    DrawText(t1, (SCREEN_W - t1w)/2, 220 + floor(pulse), 52,
        RAYLIBColor(255, 80, 60, 255))

    t2 = "Final Score: " + plScore
    t2w = MeasureText(t2, 28)
    DrawText(t2, (SCREEN_W - t2w)/2, 300, 28,
        RAYLIBColor(255, 220, 100, 255))

    t3 = "Waves Survived: " + curWave
    t3w = MeasureText(t3, 22)
    DrawText(t3, (SCREEN_W - t3w)/2, 345, 22, WHITE)

    t4 = "High Score: " + hiScore
    t4w = MeasureText(t4, 22)
    DrawText(t4, (SCREEN_W - t4w)/2, 385, 22,
        RAYLIBColor(180, 200, 255, 220))

    if floor(animTime * 2) % 2 = 0
        t5 = "Press ENTER or SPACE to Play Again"
        t5w = MeasureText(t5, 22)
        DrawText(t5, (SCREEN_W - t5w)/2, 440, 22,
            RAYLIBColor(255, 255, 200, 255))
    ok
