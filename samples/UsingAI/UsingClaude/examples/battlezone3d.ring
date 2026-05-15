/*
**  Battlezone 3D - Using RingRayLib
**  ==========================================
**  First-person tank combat in a 3D arena!
**  Classic arcade-inspired Battlezone action
**  with geometric obstacles, waves of enemies,
**  and intense tank warfare!
**
**  Controls:
**    W / Up Arrow     -  Move forward
**    S / Down Arrow   -  Move backward
**    A / Left Arrow   -  Rotate left
**    D / Right Arrow  -  Rotate right
**    Space / Enter    -  Fire cannon
**    Tab              -  Toggle radar zoom
**    F               -  Toggle fullscreen
**    P               -  Pause
**    ESC             -  Exit
**
**  Features:
**    - First-person tank cockpit view
**    - Endless waves of enemy tanks
**    - 5 enemy types with unique behaviors
**    - Geometric arena with obstacles
**    - Radar/minimap system
**    - Combo scoring & multipliers
**    - Power-up drops (repair, speed, shield, nuke)
**    - Screen shake on hits & explosions
**    - Cockpit HUD overlay
**    - High score tracking
**
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W        = 1024
SCREEN_H        = 768

ARENA_SIZE      = 120.0
ARENA_HALF      = 60.0

PI              = 3.14159265
DEG2RAD         = PI / 180.0

PLAYER_SPEED    = 8.0
PLAYER_ROT_SPD  = 2.5
PLAYER_MAX_HP   = 100
BULLET_SPEED    = 35.0
BULLET_LIFETIME = 3.0

MAX_PBULLETS    = 10
MAX_EBULLETS    = 50

ST_TITLE        = 0
ST_PLAYING      = 1
ST_PAUSED       = 2
ST_GAMEOVER     = 3
ST_WAVEINTRO    = 4

// =============================================================
// Game State
// =============================================================

gameState       = ST_TITLE
score           = 0
highScore       = 0
lives           = 3
wave            = 1
waveTimer       = 0.0
animTime        = 0.0
gameOverTimer   = 0.0

// =============================================================
// Player
// =============================================================

px              = 0.0
pz              = 0.0
pAngle          = 0.0
pHP             = 100
pSpeed          = 0.0
pFireCooldown   = 0.0
pShield         = 0.0
pSpeedBoost     = 0.0
pAlive          = true

// Camera
cam             = NULL
camHeight       = 1.8
camBob          = 0.0

// =============================================================
// Bullets
// =============================================================

pbullets        = []
ebullets        = []

// =============================================================
// Enemies
// enemy: [x, z, angle, speed, hp, maxHp, type, alive, fireTimer, animTime, targetAngle]
// =============================================================

enemies         = []
enemiesAlive    = 0
waveEnemyCount  = 0
enemiesSpawned  = 0
spawnTimer      = 0.0

// =============================================================
// Obstacles
// obstacle: [x, z, type, sizeX, sizeY, sizeZ, colorR, colorG, colorB]
// type: 1=cube, 2=pyramid, 3=obelisk, 4=wall
// =============================================================

obstacles       = []

// =============================================================
// Power-ups
// powerup: [x, z, type, timer, active, bobOffset]
// type: 1=repair, 2=speed, 3=shield, 4=nuke
// =============================================================

powerups        = []

// =============================================================
// Explosions & Particles
// explosion: [x, z, timer, maxTime, size]
// particle: [x, y, z, vx, vy, vz, life, maxLife, r, g, b, size]
// =============================================================

explosions      = []
particles       = []

// =============================================================
// Effects
// =============================================================

shakeIntensity  = 0.0
shakeDuration   = 0.0
shakeTimer      = 0.0

comboCount      = 0
comboTimer      = 0.0
comboDuration   = 3.0
lastComboText   = ""
comboDisplayTimer = 0.0

hitFlashTimer   = 0.0

// =============================================================
// Radar
// =============================================================

radarZoom       = 1

// =============================================================
// Stats
// =============================================================

totalKills      = 0
totalShots      = 0
totalHits       = 0
maxCombo        = 0
wavesBeat       = 0

// =============================================================
// Main Program
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Battlezone 3D - Ring RayLib")
SetTargetFPS(60)

cam = Camera3D(0, 0, 0, 0, 0, 0, 0, 1, 0, 60, CAMERA_PERSPECTIVE)

bz_generateObstacles()

while !WindowShouldClose()
    dt = GetFrameTime()
    if dt > 0.05 dt = 0.05 ok
    animTime += dt

    bz_handleInput(dt)
    bz_update(dt)

    // Update shake
    if shakeTimer > 0
        shakeTimer -= dt
        if shakeTimer < 0 shakeTimer = 0 ok
    ok

    BeginDrawing()
        ClearBackground(RAYLIBColor(5, 5, 10, 255))

        bz_updateCamera()
        BeginMode3D(cam)
            bz_drawGround()
            bz_drawArenaWalls()
            bz_drawObstacles()
            bz_drawEnemies3D()
            bz_drawBullets3D()
            bz_drawPowerups3D()
            bz_drawExplosions3D()
            bz_drawParticles3D()
        EndMode3D()

        bz_drawHUD()
        bz_drawCockpit()
        bz_drawRadar()

    EndDrawing()
end

// Cleanup
CloseWindow()

// =============================================================
// Arena Generation
// =============================================================

func bz_generateObstacles
    obstacles = []

    // Large cubes scattered around
    for i = 1 to 18
        ox = GetRandomValue(-50, 50) * 1.0
        oz = GetRandomValue(-50, 50) * 1.0
        // Keep away from center spawn
        if bz_fabs(ox) < 8 and bz_fabs(oz) < 8 loop ok
        sw = GetRandomValue(20, 45) / 10.0
        sh = GetRandomValue(15, 40) / 10.0
        sd = GetRandomValue(20, 45) / 10.0
        cr = GetRandomValue(30, 70)
        cg = GetRandomValue(60, 100)
        cb = GetRandomValue(30, 70)
        add(obstacles, [ox, oz, 1, sw, sh, sd, cr, cg, cb])
    next

    // Tall obelisks
    for i = 1 to 10
        ox = GetRandomValue(-48, 48) * 1.0
        oz = GetRandomValue(-48, 48) * 1.0
        if bz_fabs(ox) < 8 and bz_fabs(oz) < 8 loop ok
        sw = GetRandomValue(8, 15) / 10.0
        sh = GetRandomValue(40, 80) / 10.0
        cr = GetRandomValue(40, 80)
        cg = GetRandomValue(80, 130)
        cb = GetRandomValue(40, 80)
        add(obstacles, [ox, oz, 3, sw, sh, sw, cr, cg, cb])
    next

    // Low walls
    for i = 1 to 12
        ox = GetRandomValue(-45, 45) * 1.0
        oz = GetRandomValue(-45, 45) * 1.0
        if bz_fabs(ox) < 8 and bz_fabs(oz) < 8 loop ok
        sw = GetRandomValue(40, 80) / 10.0
        sh = GetRandomValue(10, 20) / 10.0
        sd = GetRandomValue(5, 12) / 10.0
        // Randomly orient
        if GetRandomValue(0, 1) = 1
            temp = sw
            sw = sd
            sd = temp
        ok
        cr = GetRandomValue(50, 90)
        cg = GetRandomValue(50, 90)
        cb = GetRandomValue(60, 100)
        add(obstacles, [ox, oz, 4, sw, sh, sd, cr, cg, cb])
    next

    // Pyramids
    for i = 1 to 8
        ox = GetRandomValue(-45, 45) * 1.0
        oz = GetRandomValue(-45, 45) * 1.0
        if bz_fabs(ox) < 10 and bz_fabs(oz) < 10 loop ok
        sw = GetRandomValue(25, 50) / 10.0
        sh = GetRandomValue(20, 50) / 10.0
        cr = GetRandomValue(60, 100)
        cg = GetRandomValue(80, 120)
        cb = GetRandomValue(30, 60)
        add(obstacles, [ox, oz, 2, sw, sh, sw, cr, cg, cb])
    next

// =============================================================
// Wave System
// =============================================================

func bz_startWave
    waveEnemyCount = 3 + wave * 2
    if waveEnemyCount > 30 waveEnemyCount = 30 ok
    enemiesSpawned = 0
    spawnTimer = 0.5
    gameState = ST_WAVEINTRO
    waveTimer = 2.5

func bz_spawnEnemy
    // Pick spawn position at arena edge
    side = GetRandomValue(1, 4)
    sx = 0.0
    sz = 0.0
    if side = 1    // North
        sx = GetRandomValue(-50, 50) * 1.0
        sz = -ARENA_HALF + 2
    ok
    if side = 2    // South
        sx = GetRandomValue(-50, 50) * 1.0
        sz = ARENA_HALF - 2
    ok
    if side = 3    // East
        sx = ARENA_HALF - 2
        sz = GetRandomValue(-50, 50) * 1.0
    ok
    if side = 4    // West
        sx = -ARENA_HALF + 2
        sz = GetRandomValue(-50, 50) * 1.0
    ok

    // Pick type based on wave
    eType = 1
    roll = GetRandomValue(1, 100)
    if wave >= 2 and roll > 70 eType = 2 ok
    if wave >= 4 and roll > 80 eType = 3 ok
    if wave >= 6 and roll > 88 eType = 4 ok
    if wave >= 8 and roll > 93 eType = 5 ok

    espd = 3.0
    ehp = 1
    if eType = 1 espd = 2.5 ehp = 1 ok   // Scout - slow, weak
    if eType = 2 espd = 3.5 ehp = 2 ok   // Standard
    if eType = 3 espd = 5.0 ehp = 1 ok   // Fast
    if eType = 4 espd = 2.0 ehp = 5 ok   // Heavy
    if eType = 5 espd = 4.0 ehp = 3 ok   // Elite

    // Face toward center roughly
    eAngle = bz_atan2(0 - sx, 0 - sz)

    // enemy: [x, z, angle, speed, hp, maxHp, type, alive, fireTimer, animTime, targetAngle]
    add(enemies, [sx, sz, eAngle, espd, ehp, ehp, eType, true,
                  GetRandomValue(200, 400) / 100.0, 0.0, eAngle])

    enemiesSpawned += 1

// =============================================================
// Input
// =============================================================

func bz_handleInput dt
    if gameState = ST_TITLE
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            gameState = ST_PLAYING
            score = 0
            lives = 3
            wave = 1
            totalKills = 0
            totalShots = 0
            totalHits = 0
            maxCombo = 0
            wavesBeat = 0
            px = 0.0
            pz = 0.0
            pAngle = 0.0
            pHP = PLAYER_MAX_HP
            pAlive = true
            pShield = 0.0
            pSpeedBoost = 0.0
            pbullets = []
            ebullets = []
            enemies = []
            powerups = []
            explosions = []
            particles = []
            bz_generateObstacles()
            bz_startWave()
        ok
        return
    ok

    if gameState = ST_GAMEOVER
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            gameState = ST_TITLE
        ok
        return
    ok

    if gameState = ST_PAUSED
        if IsKeyPressed(KEY_P)
            gameState = ST_PLAYING
        ok
        return
    ok

    if gameState = ST_WAVEINTRO
        return
    ok

    // Playing state
    if IsKeyPressed(KEY_P)
        gameState = ST_PAUSED
        return
    ok

    if IsKeyPressed(KEY_TAB)
        radarZoom = (radarZoom % 3) + 1
    ok

    if !pAlive return ok

    // Rotation
    rotSpd = PLAYER_ROT_SPD
    if pSpeedBoost > 0 rotSpd = rotSpd * 1.3 ok
    if IsKeyDown(KEY_A) or IsKeyDown(KEY_LEFT)
        pAngle += rotSpd * dt
    ok
    if IsKeyDown(KEY_D) or IsKeyDown(KEY_RIGHT)
        pAngle -= rotSpd * dt
    ok

    // Keep angle in range
    while pAngle > PI  pAngle -= 2 * PI end
    while pAngle < -PI pAngle += 2 * PI end

    // Movement
    moveSpd = PLAYER_SPEED
    if pSpeedBoost > 0 moveSpd = moveSpd * 1.5 ok
    moving = false

    fdx = sin(pAngle)
    fdz = cos(pAngle)

    newX = px
    newZ = pz

    if IsKeyDown(KEY_W) or IsKeyDown(KEY_UP)
        newX = px + fdx * moveSpd * dt
        newZ = pz + fdz * moveSpd * dt
        moving = true
    ok
    if IsKeyDown(KEY_S) or IsKeyDown(KEY_DOWN)
        newX = px - fdx * moveSpd * dt * 0.6
        newZ = pz - fdz * moveSpd * dt * 0.6
        moving = true
    ok

    // Collision with obstacles
    canMove = true
    nObs = len(obstacles)
    for i = 1 to nObs
        ob = obstacles[i]
        ohw = ob[4] / 2.0 + 0.8
        ohd = ob[6] / 2.0 + 0.8
        ddx = bz_fabs(newX - ob[1])
        ddz = bz_fabs(newZ - ob[2])
        if ddx < ohw and ddz < ohd
            canMove = false
        ok
    next

    // Arena bounds
    if bz_fabs(newX) > ARENA_HALF - 1.5 canMove = false ok
    if bz_fabs(newZ) > ARENA_HALF - 1.5 canMove = false ok

    if canMove
        px = newX
        pz = newZ
    ok

    // Camera bob while moving
    if moving
        camBob += dt * 8.0
    else
        camBob = camBob * 0.9
    ok

    // Fire
    pFireCooldown -= dt
    if pFireCooldown < 0 pFireCooldown = 0 ok
    if IsKeyPressed(KEY_SPACE) or IsKeyPressed(KEY_ENTER)
        if len(pbullets) < MAX_PBULLETS and pFireCooldown <= 0
            bdx = sin(pAngle) * BULLET_SPEED
            bdz = cos(pAngle) * BULLET_SPEED
            bx = px + sin(pAngle) * 1.5
            bz2 = pz + cos(pAngle) * 1.5
            add(pbullets, [bx, bz2, bdx, bdz, true, 0.0])
            pFireCooldown = 0.35
            totalShots += 1
        ok
    ok

// =============================================================
// Update
// =============================================================

func bz_update dt
    if gameState = ST_WAVEINTRO
        waveTimer -= dt
        if waveTimer <= 0
            gameState = ST_PLAYING
        ok
        return
    ok

    if gameState = ST_GAMEOVER
        gameOverTimer -= dt
        bz_updateParticles(dt)
        bz_updateExplosions(dt)
        return
    ok

    if gameState != ST_PLAYING return ok

    // Update timers
    if comboTimer > 0
        comboTimer -= dt
        if comboTimer <= 0 comboCount = 0 ok
    ok
    if comboDisplayTimer > 0 comboDisplayTimer -= dt ok
    if pShield > 0 pShield -= dt ok
    if pSpeedBoost > 0 pSpeedBoost -= dt ok
    if hitFlashTimer > 0 hitFlashTimer -= dt ok

    // Spawn enemies
    if enemiesSpawned < waveEnemyCount
        spawnTimer -= dt
        if spawnTimer <= 0
            bz_spawnEnemy()
            spawnDelay = 2.0 - wave * 0.1
            if spawnDelay < 0.5 spawnDelay = 0.5 ok
            spawnTimer = spawnDelay
        ok
    ok

    // Update player bullets
    bz_updatePBullets(dt)

    // Update enemy bullets
    bz_updateEBullets(dt)

    // Update enemies
    bz_updateEnemies(dt)

    // Update powerups
    bz_updatePowerups(dt)

    // Update explosions
    bz_updateExplosions(dt)

    // Update particles
    bz_updateParticles(dt)

    // Check wave complete
    enemiesAlive = 0
    nEnemies = len(enemies)
    for e = 1 to nEnemies
        if enemies[e][8] enemiesAlive += 1 ok
    next
    if enemiesSpawned >= waveEnemyCount and enemiesAlive = 0
        // Wave cleared!
        waveBonus = wave * 200
        score += waveBonus
        wavesBeat += 1
        wave += 1
        // Celebration particles
        for p = 1 to 40
            vx = (GetRandomValue(-100, 100) / 40.0)
            vy = (GetRandomValue(50, 200) / 40.0)
            vz = (GetRandomValue(-100, 100) / 40.0)
            cr = GetRandomValue(150, 255)
            cg = GetRandomValue(150, 255)
            cb = GetRandomValue(50, 255)
            add(particles, [px, 2.0, pz, vx, vy, vz, 2.5, 2.5, cr, cg, cb, 0.2])
        next
        // Clear dead enemies
        enemies = []
        ebullets = []
        bz_startWave()
    ok

    // Respawn player if dead
    if !pAlive and lives > 0
        pShield += dt
        if pShield >= 0
            pAlive = true
            px = 0.0
            pz = 0.0
            pAngle = 0.0
            pHP = PLAYER_MAX_HP
            pShield = 3.0
        ok
    ok

// =============================================================
// Player Bullets
// =============================================================

func bz_updatePBullets dt
    i = 1
    while i <= len(pbullets)
        if !pbullets[i][5]
            del(pbullets, i)
            loop
        ok

        // Move
        pbullets[i][1] += pbullets[i][3] * dt
        pbullets[i][2] += pbullets[i][4] * dt
        pbullets[i][6] += dt

        bx = pbullets[i][1]
        bz2 = pbullets[i][2]

        // Lifetime
        if pbullets[i][6] > BULLET_LIFETIME
            pbullets[i][5] = false
            i += 1
            loop
        ok

        // Arena bounds
        if bz_fabs(bx) > ARENA_HALF or bz_fabs(bz2) > ARENA_HALF
            pbullets[i][5] = false
            bz_spawnSmallExplosion(bx, bz2)
            i += 1
            loop
        ok

        // Hit obstacles
        hitObs = false
        nObs = len(obstacles)
        for j = 1 to nObs
            ob = obstacles[j]
            ohw = ob[4] / 2.0
            ohd = ob[6] / 2.0
            if bz_fabs(bx - ob[1]) < ohw and bz_fabs(bz2 - ob[2]) < ohd
                hitObs = true
            ok
        next
        if hitObs
            pbullets[i][5] = false
            bz_spawnSmallExplosion(bx, bz2)
            i += 1
            loop
        ok

        // Hit enemies
        hitEnemy = false
        nEnemies = len(enemies)
        for e = 1 to nEnemies
            if !enemies[e][8] loop ok
            ddx = bx - enemies[e][1]
            ddz = bz2 - enemies[e][2]
            dist = ddx * ddx + ddz * ddz
            hitRad = 1.2
            if enemies[e][7] = 4 hitRad = 1.5 ok  // Heavy is bigger
            if dist < hitRad * hitRad
                // Hit!
                enemies[e][5] -= 1
                totalHits += 1
                if enemies[e][5] <= 0
                    enemies[e][8] = false
                    bz_spawnBigExplosion(enemies[e][1], enemies[e][2])
                    bz_triggerShake(0.25, 0.3)
                    totalKills += 1
                    // Score
                    eType = enemies[e][7]
                    baseScore = 100
                    if eType = 2 baseScore = 200 ok
                    if eType = 3 baseScore = 150 ok
                    if eType = 4 baseScore = 500 ok
                    if eType = 5 baseScore = 400 ok
                    // Combo
                    comboCount += 1
                    comboTimer = comboDuration
                    comboMult = 1.0
                    if comboCount = 2 comboMult = 1.5 ok
                    if comboCount = 3 comboMult = 2.0 ok
                    if comboCount = 4 comboMult = 3.0 ok
                    if comboCount >= 5 comboMult = 5.0 ok
                    if comboCount > maxCombo maxCombo = comboCount ok
                    finalScore = floor(baseScore * comboMult)
                    score += finalScore
                    if comboCount >= 2
                        lastComboText = "x" + comboCount + " COMBO! +" + finalScore
                        comboDisplayTimer = 2.0
                    ok
                    // Power-up drop
                    dropChance = 15 + eType * 5
                    if GetRandomValue(1, 100) <= dropChance
                        ptype = GetRandomValue(1, 4)
                        if ptype = 4 and GetRandomValue(1, 100) > 20
                            ptype = GetRandomValue(1, 3)
                        ok
                        add(powerups, [enemies[e][1], enemies[e][2], ptype, 12.0, true, GetRandomValue(0, 628) / 100.0])
                    ok
                else
                    bz_spawnSmallExplosion(bx, bz2)
                ok
                hitEnemy = true
                exit
            ok
        next
        if hitEnemy
            pbullets[i][5] = false
            i += 1
            loop
        ok

        i += 1
    end

// =============================================================
// Enemy Bullets
// =============================================================

func bz_updateEBullets dt
    i = 1
    while i <= len(ebullets)
        if !ebullets[i][5]
            del(ebullets, i)
            loop
        ok

        ebullets[i][1] += ebullets[i][3] * dt
        ebullets[i][2] += ebullets[i][4] * dt
        ebullets[i][6] += dt

        bx = ebullets[i][1]
        bz2 = ebullets[i][2]

        // Lifetime
        if ebullets[i][6] > BULLET_LIFETIME
            ebullets[i][5] = false
            i += 1
            loop
        ok

        // Arena bounds
        if bz_fabs(bx) > ARENA_HALF or bz_fabs(bz2) > ARENA_HALF
            ebullets[i][5] = false
            i += 1
            loop
        ok

        // Hit obstacles
        hitObs = false
        nObs = len(obstacles)
        for j = 1 to nObs
            ob = obstacles[j]
            ohw = ob[4] / 2.0
            ohd = ob[6] / 2.0
            if bz_fabs(bx - ob[1]) < ohw and bz_fabs(bz2 - ob[2]) < ohd
                hitObs = true
            ok
        next
        if hitObs
            ebullets[i][5] = false
            i += 1
            loop
        ok

        // Hit player
        if pAlive
            ddx = bx - px
            ddz = bz2 - pz
            dist = ddx * ddx + ddz * ddz
            if dist < 1.3 * 1.3
                ebullets[i][5] = false
                if pShield <= 0
                    dmg = 20
                    pHP -= dmg
                    hitFlashTimer = 0.3
                    bz_triggerShake(0.3, 0.4)
                    if pHP <= 0
                        pAlive = false
                        lives -= 1
                        bz_spawnBigExplosion(px, pz)
                        bz_triggerShake(0.5, 0.6)
                        if lives <= 0
                            gameState = ST_GAMEOVER
                            gameOverTimer = 4.0
                            if score > highScore highScore = score ok
                        else
                            pShield = -2.0  // Respawn timer
                        ok
                    ok
                ok
                i += 1
                loop
            ok
        ok

        i += 1
    end

// =============================================================
// Enemy AI
// =============================================================

func bz_updateEnemies dt
    nEnemies = len(enemies)
    for e = 1 to nEnemies
        if !enemies[e][8] loop ok

        enemies[e][10] += dt  // animTime
        enemies[e][9] -= dt   // fireTimer

        ex = enemies[e][1]
        ez2 = enemies[e][2]
        eAngle = enemies[e][3]
        espd = enemies[e][4]
        eType = enemies[e][7]

        // Calculate angle to player
        if pAlive
            targetAngle = bz_atan2(px - ex, pz - ez2)
            enemies[e][11] = targetAngle
        ok

        // Rotate toward target
        angleDiff = enemies[e][11] - eAngle
        while angleDiff > PI  angleDiff -= 2 * PI end
        while angleDiff < -PI angleDiff += 2 * PI end

        rotSpeed = 1.5
        if eType = 3 rotSpeed = 2.5 ok  // Fast type turns faster
        if eType = 5 rotSpeed = 2.0 ok  // Elite turns well

        if angleDiff > 0.05
            enemies[e][3] += rotSpeed * dt
        but angleDiff < -0.05
            enemies[e][3] -= rotSpeed * dt
        ok

        // Keep angle in range
        while enemies[e][3] > PI  enemies[e][3] -= 2 * PI end
        while enemies[e][3] < -PI enemies[e][3] += 2 * PI end

        // Move forward
        fdx = sin(enemies[e][3])
        fdz = cos(enemies[e][3])

        // Don't get too close to player
        distToPlayer = bz_dist(ex, ez2, px, pz)
        moveForward = true
        if eType = 4
            // Heavy: stop and fire at medium range
            if distToPlayer < 15 moveForward = false ok
        but eType = 3
            // Fast: keep moving, circle
            if distToPlayer < 8
                // Strafe sideways
                fdx = cos(enemies[e][3])
                fdz = -sin(enemies[e][3])
            ok
        else
            if distToPlayer < 10 moveForward = false ok
        ok

        if moveForward
            newEX = ex + fdx * espd * dt
            newEZ = ez2 + fdz * espd * dt

            // Check obstacle collision
            canGo = true
            nObs = len(obstacles)
            for j = 1 to nObs
                ob = obstacles[j]
                ohw = ob[4] / 2.0 + 0.7
                ohd = ob[6] / 2.0 + 0.7
                if bz_fabs(newEX - ob[1]) < ohw and bz_fabs(newEZ - ob[2]) < ohd
                    canGo = false
                ok
            next

            // Arena bounds
            if bz_fabs(newEX) > ARENA_HALF - 2 canGo = false ok
            if bz_fabs(newEZ) > ARENA_HALF - 2 canGo = false ok

            // Don't stack on other enemies
            for j = 1 to nEnemies
                if j = e loop ok
                if !enemies[j][8] loop ok
                ddx = newEX - enemies[j][1]
                ddz = newEZ - enemies[j][2]
                if ddx > -1.8 and ddx < 1.8 and ddz > -1.8 and ddz < 1.8
                    canGo = false
                ok
            next

            if canGo
                enemies[e][1] = newEX
                enemies[e][2] = newEZ
            else
                // Try to go around
                enemies[e][11] += 0.8
            ok
        ok

        // Fire at player
        if enemies[e][9] <= 0 and pAlive
            // Check if roughly facing player
            if bz_fabs(angleDiff) < 0.4
                enemies[e][9] = GetRandomValue(150, 350) / 100.0
                if eType = 5 enemies[e][9] = GetRandomValue(100, 200) / 100.0 ok  // Elite fires faster
                if len(ebullets) < MAX_EBULLETS
                    bspd = BULLET_SPEED * 0.65
                    if eType = 5 bspd = BULLET_SPEED * 0.75 ok
                    ebdx = sin(enemies[e][3]) * bspd
                    ebdz = cos(enemies[e][3]) * bspd
                    ebx = enemies[e][1] + sin(enemies[e][3]) * 1.2
                    ebz = enemies[e][2] + cos(enemies[e][3]) * 1.2
                    add(ebullets, [ebx, ebz, ebdx, ebdz, true, 0.0])
                ok
            ok
        ok

        // Collision with player (ramming)
        if pAlive and distToPlayer < 1.5
            if pShield <= 0
                pHP -= 1  // Small ram damage
                if pHP <= 0
                    pAlive = false
                    lives -= 1
                    bz_spawnBigExplosion(px, pz)
                    bz_triggerShake(0.5, 0.6)
                    if lives <= 0
                        gameState = ST_GAMEOVER
                        gameOverTimer = 4.0
                        if score > highScore highScore = score ok
                    else
                        pShield = -2.0
                    ok
                ok
            ok
        ok
    next

// =============================================================
// Power-ups
// =============================================================

func bz_updatePowerups dt
    i = 1
    while i <= len(powerups)
        if !powerups[i][5]
            del(powerups, i)
            loop
        ok
        powerups[i][4] -= dt
        if powerups[i][4] <= 0
            del(powerups, i)
            loop
        ok

        // Check player pickup
        if pAlive
            ddx = px - powerups[i][1]
            ddz = pz - powerups[i][2]
            dist = ddx * ddx + ddz * ddz
            if dist < 2.5 * 2.5
                ptype = powerups[i][3]
                if ptype = 1
                    // Repair
                    pHP += 40
                    if pHP > PLAYER_MAX_HP pHP = PLAYER_MAX_HP ok
                    score += 100
                ok
                if ptype = 2
                    // Speed boost
                    pSpeedBoost = 10.0
                    score += 100
                ok
                if ptype = 3
                    // Shield
                    pShield = 8.0
                    score += 100
                ok
                if ptype = 4
                    // Nuke - destroy all enemies
                    nEnemies = len(enemies)
                    for e = 1 to nEnemies
                        if enemies[e][8]
                            enemies[e][8] = false
                            totalKills += 1
                            score += 50
                            bz_spawnBigExplosion(enemies[e][1], enemies[e][2])
                        ok
                    next
                    bz_triggerShake(0.6, 0.8)
                    score += 300
                ok
                del(powerups, i)
                loop
            ok
        ok
        i += 1
    end

// =============================================================
// Explosions & Particles
// =============================================================

func bz_spawnSmallExplosion bx, bz2
    add(explosions, [bx, bz2, 0.4, 0.4, 1.0])
    for i = 1 to 5
        ang = GetRandomValue(0, 628) / 100.0
        spd = GetRandomValue(100, 300) / 100.0
        add(particles, [bx, 1.0, bz2,
                        cos(ang) * spd, GetRandomValue(100, 300) / 100.0, sin(ang) * spd,
                        0.5, 0.5, 255, GetRandomValue(100, 200), 30, 0.08])
    next

func bz_spawnBigExplosion bx, bz2
    add(explosions, [bx, bz2, 0.8, 0.8, 2.5])
    for i = 1 to 15
        ang = GetRandomValue(0, 628) / 100.0
        spd = GetRandomValue(200, 600) / 100.0
        add(particles, [bx, 1.0, bz2,
                        cos(ang) * spd, GetRandomValue(200, 500) / 100.0, sin(ang) * spd,
                        1.0, 1.0, 255, GetRandomValue(80, 200), GetRandomValue(10, 80), 0.15])
    next

func bz_updateExplosions dt
    i = 1
    while i <= len(explosions)
        explosions[i][3] -= dt
        if explosions[i][3] <= 0
            del(explosions, i)
        else
            i += 1
        ok
    end

func bz_updateParticles dt
    i = 1
    while i <= len(particles)
        particles[i][1] += particles[i][4] * dt
        particles[i][2] += particles[i][5] * dt
        particles[i][3] += particles[i][6] * dt
        particles[i][5] -= 6.0 * dt  // Gravity
        particles[i][7] -= dt
        if particles[i][7] <= 0 or particles[i][2] < -1
            del(particles, i)
        else
            i += 1
        ok
    end

func bz_triggerShake intensity, duration
    shakeIntensity = intensity
    shakeDuration = duration
    shakeTimer = duration

// =============================================================
// Camera
// =============================================================

func bz_updateCamera
    bobOffset = sin(camBob) * 0.06
    eyeY = camHeight + bobOffset

    // Position at player
    cam.position.x = px
    cam.position.y = eyeY
    cam.position.z = pz

    // Look forward
    lookDist = 10.0
    cam.target.x = px + sin(pAngle) * lookDist
    cam.target.y = eyeY - 0.3
    cam.target.z = pz + cos(pAngle) * lookDist

    cam.up.x = 0
    cam.up.y = 1
    cam.up.z = 0
    cam.fovy = 65

    // Screen shake
    if shakeTimer > 0
        shakeFactor = shakeTimer / shakeDuration
        shakeAmt = shakeIntensity * shakeFactor
        cam.position.x += (GetRandomValue(-100, 100) / 100.0) * shakeAmt
        cam.position.y += (GetRandomValue(-100, 100) / 100.0) * shakeAmt * 0.5
        cam.position.z += (GetRandomValue(-100, 100) / 100.0) * shakeAmt
    ok

// =============================================================
// 3D Drawing: Ground
// =============================================================

func bz_drawGround
    // Main ground plane
    DrawPlane(Vector3(0, 0, 0), Vector2(ARENA_SIZE + 20, ARENA_SIZE + 20),
              RAYLIBColor(15, 25, 15, 255))

    // Grid lines for depth perception (classic Battlezone look)
    gridSpacing = 10.0
    gridCount = floor(ARENA_SIZE / gridSpacing)
    for i = -gridCount to gridCount
        gp = i * gridSpacing
        // X lines
        DrawLine3D(Vector3(-ARENA_HALF, 0.01, gp),
                   Vector3(ARENA_HALF, 0.01, gp),
                   RAYLIBColor(0, 50, 0, 80))
        // Z lines
        DrawLine3D(Vector3(gp, 0.01, -ARENA_HALF),
                   Vector3(gp, 0.01, ARENA_HALF),
                   RAYLIBColor(0, 50, 0, 80))
    next

// =============================================================
// 3D Drawing: Arena Walls
// =============================================================

func bz_drawArenaWalls
    wallH = 4.0
    wallThick = 1.0
    wClr = RAYLIBColor(40, 70, 40, 200)

    // North
    DrawCube(Vector3(0, wallH/2, -ARENA_HALF), ARENA_SIZE, wallH, wallThick, wClr)
    // South
    DrawCube(Vector3(0, wallH/2, ARENA_HALF), ARENA_SIZE, wallH, wallThick, wClr)
    // East
    DrawCube(Vector3(ARENA_HALF, wallH/2, 0), wallThick, wallH, ARENA_SIZE, wClr)
    // West
    DrawCube(Vector3(-ARENA_HALF, wallH/2, 0), wallThick, wallH, ARENA_SIZE, wClr)

    // Glowing top edge
    edgeClr = RAYLIBColor(0, 180, 0, 150)
    DrawCube(Vector3(0, wallH, -ARENA_HALF), ARENA_SIZE, 0.15, wallThick + 0.1, edgeClr)
    DrawCube(Vector3(0, wallH, ARENA_HALF), ARENA_SIZE, 0.15, wallThick + 0.1, edgeClr)
    DrawCube(Vector3(ARENA_HALF, wallH, 0), wallThick + 0.1, 0.15, ARENA_SIZE, edgeClr)
    DrawCube(Vector3(-ARENA_HALF, wallH, 0), wallThick + 0.1, 0.15, ARENA_SIZE, edgeClr)

    // Distant mountains (decoration outside arena)
    for i = 1 to 20
        ang = i * (2 * PI / 20)
        mDist = ARENA_HALF + 30
        mx = sin(ang) * mDist
        mz = cos(ang) * mDist
        mh = 8 + sin(i * 3.7) * 5
        mw = 10 + sin(i * 2.3) * 5
        DrawCube(Vector3(mx, mh/2, mz), mw, mh, mw * 0.6,
                 RAYLIBColor(20, 35, 20, 150))
    next

// =============================================================
// 3D Drawing: Obstacles
// =============================================================

func bz_drawObstacles
    nObs = len(obstacles)
    for i = 1 to nObs
        ob = obstacles[i]
        ox = ob[1]
        oz2 = ob[2]
        oType = ob[3]
        sw = ob[4]
        sh = ob[5]
        sd = ob[6]
        cr = ob[7]
        cg = ob[8]
        cb = ob[9]

        if oType = 1
            // Cube
            DrawCube(Vector3(ox, sh/2, oz2), sw, sh, sd,
                     RAYLIBColor(cr, cg, cb, 255))
            DrawCubeWires(Vector3(ox, sh/2, oz2), sw + 0.02, sh + 0.02, sd + 0.02,
                          RAYLIBColor(cr + 30, cg + 40, cb + 30, 120))
        ok
        if oType = 2
            // Pyramid (approximated with stacked shrinking cubes)
            layers = 5
            for l = 1 to layers
                frac = 1.0 - (l - 1.0) / layers
                lh = sh / layers
                ly = (l - 1) * lh + lh / 2
                lw = sw * frac
                ld = sd * frac
                DrawCube(Vector3(ox, ly, oz2), lw, lh * 0.95, ld,
                         RAYLIBColor(cr + l * 5, cg + l * 5, cb, 255))
            next
            DrawCubeWires(Vector3(ox, sh/2, oz2), sw + 0.02, sh + 0.02, sd + 0.02,
                          RAYLIBColor(cr + 40, cg + 50, cb + 20, 80))
        ok
        if oType = 3
            // Obelisk (tall thin column)
            DrawCube(Vector3(ox, sh/2, oz2), sw, sh, sd,
                     RAYLIBColor(cr, cg, cb, 255))
            DrawCubeWires(Vector3(ox, sh/2, oz2), sw + 0.02, sh + 0.02, sd + 0.02,
                          RAYLIBColor(cr + 30, cg + 40, cb + 30, 150))
            // Cap
            DrawCube(Vector3(ox, sh + 0.15, oz2), sw + 0.3, 0.3, sd + 0.3,
                     RAYLIBColor(cr + 20, cg + 30, cb + 20, 255))
        ok
        if oType = 4
            // Low wall
            DrawCube(Vector3(ox, sh/2, oz2), sw, sh, sd,
                     RAYLIBColor(cr, cg, cb, 255))
            DrawCubeWires(Vector3(ox, sh/2, oz2), sw + 0.02, sh + 0.02, sd + 0.02,
                          RAYLIBColor(cr + 20, cg + 20, cb + 30, 100))
        ok
    next

// =============================================================
// 3D Drawing: Enemies
// =============================================================

func bz_drawEnemies3D
    nEnemies = len(enemies)
    for e = 1 to nEnemies
        if !enemies[e][8] loop ok

        ex = enemies[e][1]
        ez2 = enemies[e][2]
        eAngle = enemies[e][3]
        eType = enemies[e][7]
        eAnim = enemies[e][10]

        // Direction vectors
        fdx = sin(eAngle)
        fdz = cos(eAngle)
        perpX = cos(eAngle)
        perpZ = -sin(eAngle)

        // Color by type
        hR = 180  hG = 60  hB = 60
        if eType = 1 hR = 160 hG = 160 hB = 160 ok  // Scout - gray
        if eType = 2 hR = 180 hG = 140 hB = 60 ok   // Standard - tan
        if eType = 3 hR = 60 hG = 180 hB = 60 ok     // Fast - green
        if eType = 4 hR = 180 hG = 60 hB = 60 ok     // Heavy - red
        if eType = 5 hR = 100 hG = 60 hB = 200 ok    // Elite - purple

        tankScale = 1.0
        if eType = 4 tankScale = 1.3 ok
        if eType = 3 tankScale = 0.8 ok

        // Shadow
        DrawCylinder(Vector3(ex, 0.02, ez2), 0.8 * tankScale, 0.9 * tankScale, 0.01, 8,
                     RAYLIBColor(0, 0, 0, 40))

        treadBob = sin(eAnim * 8.0) * 0.02

        // Treads
        tw = 0.55 * tankScale
        DrawCube(Vector3(ex + perpX * tw, 0.15 + treadBob, ez2 + perpZ * tw),
                 0.2 * tankScale + bz_fabs(fdx) * 0.6 * tankScale,
                 0.2 * tankScale,
                 0.2 * tankScale + bz_fabs(fdz) * 0.6 * tankScale,
                 RAYLIBColor(40, 40, 40, 255))
        DrawCube(Vector3(ex - perpX * tw, 0.15 - treadBob, ez2 - perpZ * tw),
                 0.2 * tankScale + bz_fabs(fdx) * 0.6 * tankScale,
                 0.2 * tankScale,
                 0.2 * tankScale + bz_fabs(fdz) * 0.6 * tankScale,
                 RAYLIBColor(40, 40, 40, 255))

        // Hull
        DrawCube(Vector3(ex, 0.35 * tankScale, ez2),
                 0.9 * tankScale, 0.25 * tankScale, 0.9 * tankScale,
                 RAYLIBColor(hR, hG, hB, 255))

        // Turret
        DrawCylinder(Vector3(ex, 0.45 * tankScale, ez2),
                     0.35 * tankScale, 0.30 * tankScale, 0.2 * tankScale, 8,
                     RAYLIBColor(floor(hR * 0.8), floor(hG * 0.8), floor(hB * 0.8), 255))

        // Cannon barrel
        bLen = 0.9 * tankScale
        if eType = 4 bLen = 1.1 * tankScale ok
        cbx = ex + fdx * 0.2
        cbz = ez2 + fdz * 0.2
        DrawCylinder(Vector3(cbx + fdx * bLen * 0.5, 0.50 * tankScale, cbz + fdz * bLen * 0.5),
                     0.06 * tankScale, 0.05 * tankScale, bLen, 8,
                     RAYLIBColor(floor(hR * 0.6), floor(hG * 0.6), floor(hB * 0.6), 255))

        // HP bar for damaged enemies
        if enemies[e][5] < enemies[e][6]
            hpFrac = enemies[e][5] * 1.0 / enemies[e][6]
            barW = 1.2 * tankScale
            DrawCube(Vector3(ex, 1.2 * tankScale, ez2), barW, 0.08, 0.08,
                     RAYLIBColor(60, 60, 60, 200))
            DrawCube(Vector3(ex - (barW * (1 - hpFrac)) / 2, 1.2 * tankScale, ez2),
                     barW * hpFrac, 0.10, 0.10,
                     RAYLIBColor(floor(255 * (1 - hpFrac)), floor(255 * hpFrac), 30, 255))
        ok

        // Wireframe outline (classic Battlezone look)
        DrawCubeWires(Vector3(ex, 0.35 * tankScale, ez2),
                      0.92 * tankScale, 0.27 * tankScale, 0.92 * tankScale,
                      RAYLIBColor(0, 255, 0, 50))
    next

// =============================================================
// 3D Drawing: Bullets
// =============================================================

func bz_drawBullets3D
    // Player bullets - bright green
    nPB = len(pbullets)
    for i = 1 to nPB
        if !pbullets[i][5] loop ok
        bx = pbullets[i][1]
        bz2 = pbullets[i][2]
        DrawSphere(Vector3(bx, 1.0, bz2), 0.12,
                   RAYLIBColor(100, 255, 100, 255))
        DrawSphere(Vector3(bx, 1.0, bz2), 0.25,
                   RAYLIBColor(50, 255, 50, 40))
    next

    // Enemy bullets - red/orange
    nEB = len(ebullets)
    for i = 1 to nEB
        if !ebullets[i][5] loop ok
        bx = ebullets[i][1]
        bz2 = ebullets[i][2]
        DrawSphere(Vector3(bx, 1.0, bz2), 0.10,
                   RAYLIBColor(255, 100, 50, 255))
        DrawSphere(Vector3(bx, 1.0, bz2), 0.22,
                   RAYLIBColor(255, 50, 20, 40))
    next

// =============================================================
// 3D Drawing: Power-ups
// =============================================================

func bz_drawPowerups3D
    nPU = len(powerups)
    for i = 1 to nPU
        if !powerups[i][5] loop ok
        pwx = powerups[i][1]
        pwz = powerups[i][2]
        ptype = powerups[i][3]
        bob = sin(animTime * 3.0 + powerups[i][6]) * 0.3 + 1.2
        spin = animTime * 2.0 + powerups[i][6]

        flash = floor(sin(animTime * 5.0) * 40 + 215)

        if ptype = 1
            // Repair - green cross
            DrawCube(Vector3(pwx, bob, pwz), 0.6, 0.15, 0.2,
                     RAYLIBColor(50, 255, 50, flash))
            DrawCube(Vector3(pwx, bob, pwz), 0.2, 0.15, 0.6,
                     RAYLIBColor(50, 255, 50, flash))
            DrawSphere(Vector3(pwx, bob, pwz), 0.5,
                       RAYLIBColor(50, 255, 50, 30))
        ok
        if ptype = 2
            // Speed - yellow arrow
            DrawSphere(Vector3(pwx, bob, pwz), 0.3,
                       RAYLIBColor(255, 220, 50, flash))
            DrawSphere(Vector3(pwx, bob, pwz), 0.5,
                       RAYLIBColor(255, 200, 0, 30))
        ok
        if ptype = 3
            // Shield - blue sphere
            DrawSphere(Vector3(pwx, bob, pwz), 0.3,
                       RAYLIBColor(80, 150, 255, flash))
            DrawSphere(Vector3(pwx, bob, pwz), 0.55,
                       RAYLIBColor(50, 100, 255, 30))
        ok
        if ptype = 4
            // Nuke - red pulsing
            pulse = sin(animTime * 6.0) * 0.1
            DrawSphere(Vector3(pwx, bob, pwz), 0.3 + pulse,
                       RAYLIBColor(255, 40, 30, flash))
            DrawSphere(Vector3(pwx, bob, pwz), 0.6 + pulse,
                       RAYLIBColor(255, 20, 10, 25))
        ok
    next

// =============================================================
// 3D Drawing: Explosions & Particles
// =============================================================

func bz_drawExplosions3D
    nExp = len(explosions)
    for i = 1 to nExp
        ex = explosions[i][1]
        ez2 = explosions[i][2]
        life = explosions[i][3] / explosions[i][4]
        sz = explosions[i][5] * (1.0 - life * 0.3)
        alpha = floor(life * 200)
        if alpha > 255 alpha = 255 ok
        if alpha < 0 alpha = 0 ok
        DrawSphere(Vector3(ex, 1.0, ez2), sz,
                   RAYLIBColor(255, 150 + floor(life * 100), 30, alpha))
        DrawSphere(Vector3(ex, 1.0, ez2), sz * 1.5,
                   RAYLIBColor(255, 100, 10, floor(alpha * 0.3)))
    next

func bz_drawParticles3D
    nPart = len(particles)
    for i = 1 to nPart
        life = particles[i][7] / particles[i][8]
        if life < 0 life = 0 ok
        alpha = floor(life * 255)
        if alpha < 0 alpha = 0 ok
        if alpha > 255 alpha = 255 ok
        sz = particles[i][12] * life
        if sz < 0.01 sz = 0.01 ok
        DrawSphere(Vector3(particles[i][1], particles[i][2], particles[i][3]),
                   sz, RAYLIBColor(particles[i][9], particles[i][10],
                                   particles[i][11], alpha))
    next

// =============================================================
// HUD Drawing
// =============================================================

func bz_drawHUD
    // Hit flash
    if hitFlashTimer > 0
        fAlpha = floor((hitFlashTimer / 0.3) * 80)
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(255, 0, 0, fAlpha))
    ok

    // Crosshair
    if gameState = ST_PLAYING and pAlive
        cx = SCREEN_W / 2
        cy = SCREEN_H / 2
        DrawLine(cx - 20, cy, cx - 6, cy, RAYLIBColor(0, 255, 0, 180))
        DrawLine(cx + 6, cy, cx + 20, cy, RAYLIBColor(0, 255, 0, 180))
        DrawLine(cx, cy - 20, cx, cy - 6, RAYLIBColor(0, 255, 0, 180))
        DrawLine(cx, cy + 6, cx, cy + 20, RAYLIBColor(0, 255, 0, 180))
        DrawCircleLines(cx, cy, 3, RAYLIBColor(0, 255, 0, 120))
    ok

    // Top HUD bar
    DrawRectangle(0, 0, SCREEN_W, 45, RAYLIBColor(0, 0, 0, 200))
    DrawRectangle(0, 45, SCREEN_W, 2, RAYLIBColor(0, 200, 0, 200))

    // Score
    DrawText("SCORE", 15, 4, 12, RAYLIBColor(0, 180, 0, 200))
    DrawText(string(score), 15, 18, 22, RAYLIBColor(0, 255, 0, 255))

    // Wave
    wTxt = "WAVE " + string(wave)
    wW = MeasureText(wTxt, 24)
    DrawText(wTxt, floor(SCREEN_W/2 - wW/2), 10, 24,
             RAYLIBColor(0, 255, 0, 255))

    // Lives
    DrawText("LIVES", SCREEN_W - 160, 4, 12, RAYLIBColor(0, 180, 0, 200))
    for i = 1 to lives
        lx = SCREEN_W - 160 + (i - 1) * 25
        DrawRectangle(lx, 22, 16, 10, RAYLIBColor(0, 200, 0, 255))
        DrawRectangle(lx + 5, 18, 6, 6, RAYLIBColor(0, 160, 0, 255))
    next

    // HP bar (bottom left)
    if pAlive
        barX = 20
        barY = SCREEN_H - 45
        barW = 180
        barH = 16
        hpFrac = pHP * 1.0 / PLAYER_MAX_HP
        DrawRectangle(barX - 1, barY - 1, barW + 2, barH + 2, RAYLIBColor(0, 100, 0, 200))
        DrawRectangle(barX, barY, barW, barH, RAYLIBColor(30, 30, 30, 200))
        hpR = floor(255 * (1 - hpFrac))
        hpG = floor(255 * hpFrac)
        DrawRectangle(barX, barY, floor(barW * hpFrac), barH,
                      RAYLIBColor(hpR, hpG, 30, 255))
        DrawText("HP " + string(pHP), barX + 5, barY + 1, 14,
                 RAYLIBColor(255, 255, 255, 220))
    ok

    // Power-up indicators
    indY = SCREEN_H - 70
    if pShield > 0
        DrawText("[SHIELD " + string(floor(pShield)) + "s]", 20, indY, 16,
                 RAYLIBColor(80, 150, 255, 255))
        indY -= 20
    ok
    if pSpeedBoost > 0
        DrawText("[SPEED " + string(floor(pSpeedBoost)) + "s]", 20, indY, 16,
                 RAYLIBColor(255, 220, 50, 255))
    ok

    // Combo display
    if comboDisplayTimer > 0
        cAlpha = floor((comboDisplayTimer / 2.0) * 255)
        if cAlpha > 255 cAlpha = 255 ok
        cW = MeasureText(lastComboText, 28)
        DrawText(lastComboText, floor(SCREEN_W/2 - cW/2), 80, 28,
                 RAYLIBColor(0, 255, 0, cAlpha))
    ok

    // Enemies remaining
    if gameState = ST_PLAYING
        remaining = waveEnemyCount - enemiesSpawned
        nEn = len(enemies)
        for e = 1 to nEn
            if enemies[e][8] remaining += 1 ok
        next
        enTxt = "Tanks: " + string(remaining)
        enW = MeasureText(enTxt, 14)
        DrawText(enTxt, floor(SCREEN_W/2 - enW/2), 35, 14,
                 RAYLIBColor(0, 200, 0, 180))
    ok

    // State overlays
    if gameState = ST_TITLE
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 220))
        title = "BATTLEZONE 3D"
        DrawText(title, floor(SCREEN_W/2 - MeasureText(title, 56) / 2),
                 floor(SCREEN_H/2 - 120), 56, RAYLIBColor(0, 255, 0, 255))
        sub = "First-Person Tank Combat Arena"
        DrawText(sub, floor(SCREEN_W/2 - MeasureText(sub, 20) / 2),
                 floor(SCREEN_H/2 - 55), 20, RAYLIBColor(0, 200, 0, 220))
        start = "Press ENTER or SPACE to Deploy"
        pulse = floor(sin(animTime * 3.0) * 60 + 195)
        DrawText(start, floor(SCREEN_W/2 - MeasureText(start, 22) / 2),
                 floor(SCREEN_H/2 + 5), 22, RAYLIBColor(0, 255, 0, pulse))
        ctrl1 = "WASD/Arrows: Move & Rotate | SPACE: Fire | TAB: Radar | P: Pause"
        DrawText(ctrl1, floor(SCREEN_W/2 - MeasureText(ctrl1, 14) / 2),
                 floor(SCREEN_H/2 + 50), 14, RAYLIBColor(0, 150, 0, 180))
        ctrl2 = "Power-ups: Green=Repair  Yellow=Speed  Blue=Shield  Red=Nuke"
        DrawText(ctrl2, floor(SCREEN_W/2 - MeasureText(ctrl2, 14) / 2),
                 floor(SCREEN_H/2 + 72), 14, RAYLIBColor(0, 150, 0, 180))
        if highScore > 0
            hsTxt = "High Score: " + string(highScore)
            DrawText(hsTxt, floor(SCREEN_W/2 - MeasureText(hsTxt, 18) / 2),
                     floor(SCREEN_H/2 + 110), 18, RAYLIBColor(0, 200, 0, 200))
        ok
    ok

    if gameState = ST_PAUSED
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 160))
        pTxt = "PAUSED"
        DrawText(pTxt, floor(SCREEN_W/2 - MeasureText(pTxt, 48) / 2),
                 floor(SCREEN_H/2 - 24), 48, RAYLIBColor(0, 255, 0, 255))
    ok

    if gameState = ST_GAMEOVER
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 210))
        goTxt = "DESTROYED"
        DrawText(goTxt, floor(SCREEN_W/2 - MeasureText(goTxt, 52) / 2),
                 floor(SCREEN_H/2 - 90), 52, RAYLIBColor(255, 40, 40, 255))
        sTxt = "Score: " + string(score)
        DrawText(sTxt, floor(SCREEN_W/2 - MeasureText(sTxt, 26) / 2),
                 floor(SCREEN_H/2 - 30), 26, RAYLIBColor(0, 255, 0, 255))
        wvTxt = "Waves Survived: " + string(wavesBeat) + "  |  Kills: " + string(totalKills)
        DrawText(wvTxt, floor(SCREEN_W/2 - MeasureText(wvTxt, 16) / 2),
                 floor(SCREEN_H/2 + 5), 16, RAYLIBColor(0, 200, 0, 200))
        if totalShots > 0
            acc = floor((totalHits * 100) / totalShots)
            accTxt = "Accuracy: " + string(acc) + "%  |  Best Combo: " + string(maxCombo) + "x"
            DrawText(accTxt, floor(SCREEN_W/2 - MeasureText(accTxt, 16) / 2),
                     floor(SCREEN_H/2 + 28), 16, RAYLIBColor(0, 200, 0, 200))
        ok
        DrawText("Press ENTER to Return",
                 floor(SCREEN_W/2 - 110), floor(SCREEN_H/2 + 65), 20,
                 RAYLIBColor(0, 200, 0, 180))
    ok

    if gameState = ST_WAVEINTRO
        wIntro = "WAVE " + string(wave)
        DrawText(wIntro, floor(SCREEN_W/2 - MeasureText(wIntro, 60) / 2),
                 floor(SCREEN_H/2 - 40), 60, RAYLIBColor(0, 255, 0, 255))
        incoming = "INCOMING!"
        pulse = floor(sin(animTime * 5.0) * 80 + 175)
        DrawText(incoming, floor(SCREEN_W/2 - MeasureText(incoming, 24) / 2),
                 floor(SCREEN_H/2 + 30), 24, RAYLIBColor(255, 50, 50, pulse))
        eCnt = string(waveEnemyCount) + " enemy tanks approaching"
        DrawText(eCnt, floor(SCREEN_W/2 - MeasureText(eCnt, 16) / 2),
                 floor(SCREEN_H/2 + 60), 16, RAYLIBColor(0, 200, 0, 180))
    ok

// =============================================================
// Cockpit Overlay
// =============================================================

func bz_drawCockpit
    if gameState != ST_PLAYING and gameState != ST_WAVEINTRO return ok

    // Bottom cockpit frame
    DrawRectangle(0, SCREEN_H - 30, SCREEN_W, 30, RAYLIBColor(20, 30, 20, 200))
    DrawRectangle(0, SCREEN_H - 32, SCREEN_W, 2, RAYLIBColor(0, 150, 0, 150))

    // Side frames
    DrawRectangle(0, 45, 3, SCREEN_H - 75, RAYLIBColor(0, 100, 0, 100))
    DrawRectangle(SCREEN_W - 3, 45, 3, SCREEN_H - 75, RAYLIBColor(0, 100, 0, 100))

    // Corner details
    DrawLine(0, 45, 40, 80, RAYLIBColor(0, 120, 0, 100))
    DrawLine(SCREEN_W, 45, SCREEN_W - 40, 80, RAYLIBColor(0, 120, 0, 100))
    DrawLine(0, SCREEN_H - 32, 40, SCREEN_H - 60, RAYLIBColor(0, 120, 0, 100))
    DrawLine(SCREEN_W, SCREEN_H - 32, SCREEN_W - 40, SCREEN_H - 60, RAYLIBColor(0, 120, 0, 100))

    // Speed indicator
    spdTxt = "SPD: " + string(floor(pSpeed))
    DrawText(spdTxt, 20, SCREEN_H - 24, 14, RAYLIBColor(0, 200, 0, 200))

    // Heading
    headDeg = floor(pAngle * 180 / PI)
    while headDeg < 0 headDeg += 360 end
    while headDeg >= 360 headDeg -= 360 end
    hTxt = "HDG: " + string(headDeg)
    DrawText(hTxt, 120, SCREEN_H - 24, 14, RAYLIBColor(0, 200, 0, 200))

    // Controls reminder
    DrawText("W/S:Move  A/D:Turn  SPACE:Fire  TAB:Radar",
             floor(SCREEN_W/2 - 180), SCREEN_H - 22, 12,
             RAYLIBColor(0, 130, 0, 120))

// =============================================================
// Radar
// =============================================================

func bz_drawRadar
    if gameState != ST_PLAYING and gameState != ST_WAVEINTRO return ok

    // Radar position (bottom right)
    radarSize = 80
    radarX = SCREEN_W - radarSize - 20
    radarY = SCREEN_H - radarSize - 40
    radarScale = radarSize / (ARENA_SIZE * 0.5)
    if radarZoom = 2 radarScale = radarScale * 2 ok
    if radarZoom = 3 radarScale = radarScale * 4 ok

    // Background
    DrawRectangle(radarX - 2, radarY - 2, radarSize + 4, radarSize + 4,
                  RAYLIBColor(0, 150, 0, 180))
    DrawRectangle(radarX, radarY, radarSize, radarSize,
                  RAYLIBColor(0, 20, 0, 220))

    // Center = player
    rcx = radarX + radarSize / 2
    rcy = radarY + radarSize / 2

    // Sweep line
    sweepAngle = animTime * 3.0
    sweepEndX = rcx + cos(sweepAngle) * radarSize / 2
    sweepEndY = rcy + sin(sweepAngle) * radarSize / 2
    DrawLine(rcx, rcy, floor(sweepEndX), floor(sweepEndY),
             RAYLIBColor(0, 100, 0, 80))

    // Obstacles on radar
    nObs = len(obstacles)
    for i = 1 to nObs
        ob = obstacles[i]
        orx = rcx + floor((ob[1] - px) * radarScale)
        ory = rcy + floor((ob[2] - pz) * radarScale)
        if orx > radarX and orx < radarX + radarSize and ory > radarY and ory < radarY + radarSize
            DrawRectangle(orx - 1, ory - 1, 3, 3, RAYLIBColor(0, 80, 0, 150))
        ok
    next

    // Enemies on radar
    nEnemies = len(enemies)
    for e = 1 to nEnemies
        if !enemies[e][8] loop ok
        erx = rcx + floor((enemies[e][1] - px) * radarScale)
        ery = rcy + floor((enemies[e][2] - pz) * radarScale)
        if erx > radarX and erx < radarX + radarSize and ery > radarY and ery < radarY + radarSize
            eClr = RAYLIBColor(255, 50, 50, 255)
            DrawRectangle(erx - 2, ery - 2, 4, 4, eClr)
        ok
    next

    // Power-ups on radar
    nPU = len(powerups)
    for i = 1 to nPU
        if !powerups[i][5] loop ok
        prx = rcx + floor((powerups[i][1] - px) * radarScale)
        pry = rcy + floor((powerups[i][2] - pz) * radarScale)
        if prx > radarX and prx < radarX + radarSize and pry > radarY and pry < radarY + radarSize
            DrawRectangle(prx - 1, pry - 1, 3, 3, RAYLIBColor(0, 255, 100, 200))
        ok
    next

    // Player dot (center)
    DrawRectangle(rcx - 2, rcy - 2, 4, 4, RAYLIBColor(0, 255, 0, 255))
    // Player direction line
    pdx = sin(pAngle) * 6
    pdz = cos(pAngle) * 6
    DrawLine(rcx, rcy, rcx + floor(pdx), rcy + floor(pdz),
             RAYLIBColor(0, 255, 0, 200))

    // Radar label
    zoomTxt = "x1"
    if radarZoom = 2 zoomTxt = "x2" ok
    if radarZoom = 3 zoomTxt = "x4" ok
    DrawText("RADAR " + zoomTxt, radarX, radarY - 14, 12,
             RAYLIBColor(0, 200, 0, 200))

// =============================================================
// Utility Functions
// =============================================================

func bz_fabs n
    if n < 0 return -n ok
    return n

func bz_atan2 dx, dz
    // Simple atan2 approximation
    if dz = 0 and dx = 0 return 0 ok
    dist = sqrt(dx * dx + dz * dz)
    if dist = 0 return 0 ok

    // Use asin for the angle
    angle = asin(dx / dist)
    if dz < 0
        angle = PI - angle
    ok
    return angle

func bz_dist x1, z1, x2, z2
    ddx = x2 - x1
    ddz = z2 - z1
    return sqrt(ddx * ddx + ddz * ddz)

func fexists path
    try
        fp = fopen(path, "r")
        fclose(fp)
        return true
    catch
        return false
    done
