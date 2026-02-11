/*
**  tank3d_update.ring
**  Game update, bullet update, enemy AI, and spawning
*/

// =============================================================
// Main Update
// =============================================================

func tank_update dt
    if gameState = ST_LEVELUP
        levelUpTimer -= dt
        tank_updateParticles(dt)
        if levelUpTimer <= 0
            level += 1
            if level > maxLevel
                gameState = ST_WON
                PlaySound(sndVictory)
            else
                tank_loadLevel(level)
                gameState = ST_PLAYING
            ok
        ok
        return
    ok

    if gameState = ST_GAMEOVER
        gameOverTimer -= dt
        tank_updateParticles(dt)
        return
    ok

    if gameState != ST_PLAYING return ok

    pAnimTime += dt
    if pshield > 0 pshield -= dt ok
    if pspeedBoost > 0 pspeedBoost -= dt ok

    // Update combo timer
    if comboTimer > 0
        comboTimer -= dt
        if comboTimer <= 0 comboCount = 0 ok
    ok
    if comboDisplayTimer > 0 comboDisplayTimer -= dt ok

    // Update global freeze
    if globalFreezeTimer > 0 globalFreezeTimer -= dt ok

    // Lava damage to player
    lavaDamageTimer -= dt
    if lavaDamageTimer < 0 lavaDamageTimer = 0 ok
    if palive
        gr = floor(py) + 1
        gc = floor(px) + 1
        if gr >= 1 and gr <= GRID_H and gc >= 1 and gc <= GRID_W
            if tiles[gr][gc] = T_LAVA and lavaDamageTimer <= 0
                if pshield <= 0
                    palive = false
                    lives -= 1
                    tank_spawnBigExplosion(px, py)
                    tank_triggerShake(0.3, 0.4)
                    PlaySound(sndPlayerDeath)
                    if lives <= 0
                        gameState = ST_GAMEOVER
                        gameOverTimer = 3.0
                        if score > highScore highScore = score ok
                        PlaySound(sndGameOver)
                    else
                        px = 9.0 py = 23.0 pdir = DIR_UP
                        palive = true pshield = 2.0
                    ok
                ok
                lavaDamageTimer = 1.5
            ok
        ok
    ok

    // Update player bullets
    tank_updateBullets(pbullets, true, dt)

    // Update enemy bullets
    tank_updateBullets(ebullets, false, dt)

    // Update enemies
    tank_updateEnemies(dt)

    // Spawn enemies
    tank_spawnEnemies(dt)

    // Update explosions
    tank_updateExplosions(dt)

    // Update particles
    tank_updateParticles(dt)

    // Update powerups
    tank_updatePowerups(dt)

    // Check level complete
    aliveCount = 0
    nEnemies = len(enemies)
    for e = 1 to nEnemies
        if enemies[e][5] aliveCount += 1 ok
    next
    if enemiesLeft <= 0 and aliveCount = 0
        gameState = ST_LEVELUP
        levelUpTimer = 2.5
        score += 500 + (level - 1) * 100  // Scaling level bonus
        PlaySound(sndLevelClear)
        // Celebration particles
        for p = 1 to 30
            vx = (GetRandomValue(-100, 100) / 50.0)
            vy = (GetRandomValue(50, 150) / 50.0)
            vz = (GetRandomValue(-100, 100) / 50.0)
            cr = GetRandomValue(150, 255)
            cg = GetRandomValue(150, 255)
            cb = GetRandomValue(50, 255)
            add(particles, [px, 0.5, py, vx, vy, vz, 2.0, 2.0, cr, cg, cb, 0.15])
        next
    ok

// =============================================================
// Bullet Update
// =============================================================

func tank_updateBullets bulletList, isPlayer, dt
    i = 1
    while i <= len(bulletList)
        b = bulletList[i]
        if !b[1]
            del(bulletList, i)
            loop
        ok

        // Move bullet
        dx = 0 dy = 0
        if b[4] = DIR_UP dy = -1 ok
        if b[4] = DIR_DOWN dy = 1 ok
        if b[4] = DIR_LEFT dx = -1 ok
        if b[4] = DIR_RIGHT dx = 1 ok

        bulletList[i][2] = b[2] + dx * b[5] * dt
        bulletList[i][3] = b[3] + dy * b[5] * dt

        bx = bulletList[i][2]
        by = bulletList[i][3]

        // Out of bounds
        if bx < 0.5 or bx > GRID_W + 0.5 or by < 0.5 or by > GRID_H + 0.5
            bulletList[i][1] = false
            tank_spawnSmallExplosion(bx, by)
            PlaySound(sndHitWall)
            i += 1
            loop
        ok

        // Hit tile
        gc = floor(bx + 0.5)
        gr = floor(by + 0.5)
        if gr >= 1 and gr <= GRID_H and gc >= 1 and gc <= GRID_W
            t = tiles[gr][gc]

            if t = T_BRICK
                tiles[gr][gc] = T_EMPTY
                bulletList[i][1] = false
                tank_spawnBrickExplosion(gc, gr)
                PlaySound(sndBrickBreak)
                score += 5
                i += 1
                loop
            ok

            if t = T_STEEL
                bulletList[i][1] = false
                tank_spawnSmallExplosion(bx, by)
                PlaySound(sndSteelHit)
                i += 1
                loop
            ok

            if t = T_BASE
                // Base destroyed!
                for br = baseR to baseR + 1
                    for bc = baseC to baseC + 1
                        if br >= 1 and br <= GRID_H and bc >= 1 and bc <= GRID_W
                            tiles[br][bc] = T_BASEDEAD
                        ok
                    next
                next
                bulletList[i][1] = false
                tank_spawnBigExplosion(gc * 1.0, gr * 1.0)
                PlaySound(sndExplosion)
                PlaySound(sndGameOver)
                gameState = ST_GAMEOVER
                gameOverTimer = 3.0
                i += 1
                loop
            ok
        ok

        // Hit tanks
        if isPlayer
            // Check hit enemies
            nEnemies = len(enemies)
            for e = 1 to nEnemies
                if enemies[e][5]
                    edx = bx - enemies[e][1]
                    edy = by - enemies[e][2]
                    if edx > -0.5 and edx < 0.5 and edy > -0.5 and edy < 0.5
                        enemies[e][6] -= 1   // Reduce HP
                        accuracyHits += 1
                        if enemies[e][6] <= 0
                            enemies[e][5] = false
                            enemiesKilled += 1
                            totalKills += 1
                            tank_spawnBigExplosion(enemies[e][1], enemies[e][2])
                            tank_triggerShake(0.2, 0.3)
                            PlaySound(sndExplosion)
                            // Score based on type
                            eType = enemies[e][7]
                            baseScore = 0
                            if eType = 1 baseScore = 100 ok
                            if eType = 2 baseScore = 200 ok
                            if eType = 3 baseScore = 300 ok
                            if eType = 4 baseScore = 400 ok
                            if eType = 5 baseScore = 500 ok
                            if eType = 6 baseScore = 1000 ok
                            // Combo multiplier
                            comboCount += 1
                            comboTimer = comboDuration
                            comboMult = 1.0
                            if comboCount = 2 comboMult = 1.5 ok
                            if comboCount = 3 comboMult = 2.0 ok
                            if comboCount = 4 comboMult = 3.0 ok
                            if comboCount >= 5 comboMult = 5.0 ok
                            finalScore = floor(baseScore * comboMult)
                            score += finalScore
                            if comboCount >= 2
                                lastComboText = "x" + comboCount + " COMBO! +" + finalScore
                                comboDisplayTimer = 2.0
                            ok
                            // Chance to spawn powerup (scales with enemy type)
                            dropChance = 20 + eType * 5
                            if GetRandomValue(1, 100) <= dropChance
                                ptype = GetRandomValue(1, 5)
                                // Life powerup is rarer
                                if ptype = 5 and GetRandomValue(1, 100) > 30
                                    ptype = GetRandomValue(1, 4)
                                ok
                                add(powerups, [enemies[e][1], enemies[e][2], ptype, 10.0, true])
                            ok
                        else
                            tank_spawnSmallExplosion(bx, by)
                            PlaySound(sndEnemyHit)
                        ok
                        bulletList[i][1] = false
                        loop
                    ok
                ok
            next
        else
            // Enemy bullet hits player
            if palive
                edx = bx - px
                edy = by - py
                if edx > -0.5 and edx < 0.5 and edy > -0.5 and edy < 0.5
                    if pshield <= 0
                        palive = false
                        tank_spawnBigExplosion(px, py)
                        tank_triggerShake(0.4, 0.5)
                        PlaySound(sndPlayerDeath)
                        lives -= 1
                        if lives <= 0
                            gameState = ST_GAMEOVER
                            PlaySound(sndGameOver)
                            gameOverTimer = 3.0
                            if score > highScore highScore = score ok
                        else
                            // Respawn after delay
                            pshield = -2.0    // Negative = respawn timer
                        ok
                    ok
                    bulletList[i][1] = false
                    i += 1
                    loop
                ok
            ok
        ok

        // Bullet-bullet collision
        if isPlayer
            nEB = len(ebullets)
            for j = 1 to nEB
                if ebullets[j][1]
                    dx2 = bx - ebullets[j][2]
                    dy2 = by - ebullets[j][3]
                    if dx2 > -0.3 and dx2 < 0.3 and dy2 > -0.3 and dy2 < 0.3
                        bulletList[i][1] = false
                        ebullets[j][1] = false
                        tank_spawnSmallExplosion(bx, by)
                    ok
                ok
            next
        ok

        i += 1
    end

// =============================================================
// Enemy AI
// =============================================================

func tank_updateEnemies dt
    nEnemies = len(enemies)
    for e = 1 to nEnemies
        if !enemies[e][5] loop ok

        enemies[e][8] += dt    // animT
        enemies[e][9] -= dt    // fireTimer
        enemies[e][10] -= dt   // moveTimer

        // Stealth toggle (type 5)
        if enemies[e][7] = 5
            enemies[e][12] += dt
            if enemies[e][12] > 2.5
                enemies[e][12] = 0.0
                enemies[e][13] = !enemies[e][13]
            ok
        ok

        // Skip movement/fire if globally frozen
        if globalFreezeTimer > 0 loop ok

        ex = enemies[e][1]
        ey = enemies[e][2]
        edir = enemies[e][3]
        espd = enemies[e][4]

        // Lava damage to enemies
        egr = floor(ey) + 1
        egc = floor(ex) + 1
        if egr >= 1 and egr <= GRID_H and egc >= 1 and egc <= GRID_W
            if tiles[egr][egc] = T_LAVA
                enemies[e][6] -= dt * 0.5  // Slow lava drain
                if enemies[e][6] <= 0
                    enemies[e][5] = false
                    tank_spawnBigExplosion(ex, ey)
                    eType = enemies[e][7]
                    escoreVal = 100 * eType
                    if eType = 6 escoreVal = 1000 ok
                    score += escoreVal
                    totalKills += 1
                    PlaySound(sndExplosion)
                ok
            ok
        ok

        // Movement
        if enemies[e][10] <= 0
            // Occasionally change direction
            if GetRandomValue(1, 100) <= 30
                // Prefer moving toward player or base
                if GetRandomValue(1, 100) <= 50 and palive
                    // Move toward player
                    ddx = px - ex
                    ddy = py - ey
                    if fabs(ddx) > fabs(ddy)
                        if ddx > 0 edir = DIR_RIGHT else edir = DIR_LEFT ok
                    else
                        if ddy > 0 edir = DIR_DOWN else edir = DIR_UP ok
                    ok
                else
                    // Move toward base (base at row 25 = high py)
                    if ey < 22 edir = DIR_DOWN
                    else
                        if ex < 13 edir = DIR_RIGHT else edir = DIR_LEFT ok
                    ok
                ok
            else
                edir = GetRandomValue(0, 3)
            ok
            enemies[e][3] = edir
            enemies[e][10] = GetRandomValue(100, 300) / 100.0
        ok

        // Move
        mdx = 0 mdy = 0
        if edir = DIR_UP mdy = -1 ok
        if edir = DIR_DOWN mdy = 1 ok
        if edir = DIR_LEFT mdx = -1 ok
        if edir = DIR_RIGHT mdx = 1 ok

        newEX = ex + mdx * espd * dt
        newEY = ey + mdy * espd * dt

        // Clamp
        if newEX < 1.5 newEX = 1.5 ok
        if newEX > GRID_W - 0.5 newEX = GRID_W - 0.5 ok
        if newEY < 1.5 newEY = 1.5 ok
        if newEY > GRID_H - 0.5 newEY = GRID_H - 0.5 ok

        // Check move possibility (basic check, no inter-enemy collision for performance)
        canGo = true
        hw = 0.38
        for cr = -1 to 1 step 2
            for cc = -1 to 1 step 2
                chkx = newEX + cc * hw
                chky = newEY + cr * hw
                ggc = floor(chkx + 0.5)
                ggr = floor(chky + 0.5)
                if ggr >= 1 and ggr <= GRID_H and ggc >= 1 and ggc <= GRID_W
                    tt = tiles[ggr][ggc]
                    if tt = T_BRICK or tt = T_STEEL or tt = T_WATER or tt = T_BASE or tt = T_BASEDEAD
                        canGo = false
                    ok
                else
                    canGo = false
                ok
            next
        next

        // Don't stack on player
        if palive
            ddx = newEX - px
            ddy = newEY - py
            if ddx > -0.85 and ddx < 0.85 and ddy > -0.85 and ddy < 0.85
                canGo = false
            ok
        ok

        if canGo
            enemies[e][1] = newEX
            enemies[e][2] = newEY
        else
            // Change direction if blocked
            enemies[e][3] = GetRandomValue(0, 3)
            enemies[e][10] = 0.5
        ok

        // Fire
        if enemies[e][9] <= 0
            fireDelay = GetRandomValue(150, 350) / 100.0
            if enemies[e][7] = 6 fireDelay = GetRandomValue(80, 150) / 100.0 ok  // Boss fires faster
            enemies[e][9] = fireDelay
            if len(ebullets) < MAX_BULLETS
                bspd = BULLET_SPEED * 0.75
                if enemies[e][7] = 6 bspd = BULLET_SPEED * 0.85 ok  // Boss bullets faster
                add(ebullets, [true, enemies[e][1], enemies[e][2],
                               enemies[e][3], bspd])
                SetSoundVolume(sndFire, 0.25)
                PlaySound(sndFire)
                SetSoundVolume(sndFire, 0.7)
            ok
        ok
    next

    // Respawn player if dead
    if !palive and gameState = ST_PLAYING
        pshield += dt  // pshield is negative timer during respawn
        if pshield >= 0
            palive = true
            px = 9.0
            py = 23.0
            pdir = DIR_UP
            pshield = 3.0   // Spawn protection
        ok
    ok

// =============================================================
// Enemy Spawning
// =============================================================

func tank_spawnEnemies dt
    if enemiesLeft <= 0 return ok

    // Count alive enemies
    aliveCount = 0
    nEnemies = len(enemies)
    for e = 1 to nEnemies
        if enemies[e][5] aliveCount += 1 ok
    next

    if aliveCount >= levelMaxOnScreen return ok

    enemySpawnTimer -= dt
    if enemySpawnTimer > 0 return ok
    enemySpawnTimer = RESPAWN_DELAY

    // Spawn at next spawn point
    sx = espawnX[espawnIdx]
    sy = 1.5

    // Boss level: spawn boss as last enemy
    isBossLevel = (level = 4 or level = 8 or level = 12)
    if isBossLevel and enemiesLeft = 1
        eType = 6
    else
        eType = tank_pickEnemyType()
    ok

    // Stats by type
    espd = ENEMY_SPEED_NORMAL
    ehp = 1
    if eType = 1 espd = ENEMY_SPEED_SLOW ehp = 1 ok
    if eType = 2 espd = ENEMY_SPEED_NORMAL ehp = 1 ok
    if eType = 3 espd = ENEMY_SPEED_FAST ehp = 1 ok
    if eType = 4 espd = ENEMY_SPEED_NORMAL ehp = 3 ok
    if eType = 5 espd = ENEMY_SPEED_FAST ehp = 2 ok     // Stealth
    if eType = 6 espd = ENEMY_SPEED_NORMAL ehp = 8 ok    // Boss

    // enemy: [x, y, dir, speed, alive, hp, type, animT, fireTimer, moveTimer, frozen, stealthTimer, visible]
    add(enemies, [sx, sy, DIR_DOWN, espd, true, ehp, eType, 0.0,
                  GetRandomValue(100, 250) / 100.0,
                  GetRandomValue(50, 200) / 100.0, false,
                  0.0, true])

    enemiesLeft -= 1
    espawnIdx = (espawnIdx % 3) + 1

// =============================================================
// Enemy Type Selection
// =============================================================

func tank_pickEnemyType
    roll = GetRandomValue(1, 100)
    if level <= 2
        if roll > 70 return 2 ok
        return 1
    ok
    if level <= 4
        if roll > 90 return 4 ok
        if roll > 75 return 3 ok
        if roll > 50 return 2 ok
        return 1
    ok
    if level <= 8
        if roll > 92 return 5 ok
        if roll > 80 return 4 ok
        if roll > 60 return 3 ok
        if roll > 35 return 2 ok
        return 1
    ok
    // Levels 9-12
    if roll > 88 return 5 ok
    if roll > 70 return 4 ok
    if roll > 45 return 3 ok
    if roll > 20 return 2 ok
    return 1
