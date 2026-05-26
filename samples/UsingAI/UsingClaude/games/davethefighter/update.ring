/*
**  Dave the Fighter - Game Update & AI
**  Functions: dave_update, dave_updateEnemies, dave_updateBullets, dave_updateEnemyBullets
*/

func dave_update dt
    if gameState = ST_DYING
        dyingTimer -= dt
        dave_updateParticles(dt)
        if dyingTimer <= 0
            lives -= 1
            if lives <= 0
                gameState = ST_GAMEOVER
            else
                if checkpointActive
                    // Respawn at checkpoint instead of reloading
                    px = checkpointX
                    py = checkpointY
                    pvx = 0.0
                    pvy = 0.0
                    pOnGround = false
                    pFacingRight = true
                    pOnMover = false
                    particles = []
                    popups = []
                    bullets = []
                    eBullets = []
                    // Restore crumbling platforms
                    nCrumbles = len(crumbles)
                    for ci = 1 to nCrumbles
                        crumbles[ci][3] = 0.0
                        crumbles[ci][4] = 0
                        tiles[crumbles[ci][2]][crumbles[ci][1]] = T_CRUMBLE
                    next
                else
                    dave_loadLevel(level)
                ok
                gameState = ST_PLAYING
            ok
        ok
        return
    ok

    if gameState = ST_LEVELUP
        levelUpTimer -= dt
        dave_updateParticles(dt)
        if levelUpTimer <= 0
            level += 1
            if level > maxLevel
                gameState = ST_WON
            else
                dave_loadLevel(level)
                gameState = ST_PLAYING
            ok
        ok
        return
    ok

    if gameState != ST_PLAYING return ok

    // Apply gravity (unless on ladder)
    tileHere = dave_tileAtWorld(px, py + 0.3)
    tileAtFeet = dave_tileAtWorld(px, py)
    inLadderTile = (tileHere = T_LADDER or tileAtFeet = T_LADDER)
    // Player must be in a ladder tile AND not resting on ground to enter ladder mode
    if inLadderTile and !pOnGround
        pOnLadder = true
        pvy = pvy * 0.8  // Slow down on ladder
        if pvy != 0
            pClimbFrame += dt * 8.0
        ok
    else
        pOnLadder = false
        pvy -= GRAVITY * dt
        if pvy < -MAX_FALL pvy = -MAX_FALL ok
    ok

    // Move horizontally
    newX = px + pvx * dt
    if !dave_solidAt(newX, py + 0.1) and !dave_solidAt(newX, py + 0.8)
        px = newX
    else
        pvx = 0
    ok

    // Move vertically
    newY = py + pvy * dt
    if pvy > 0
        // Moving up
        if !dave_headSolid(px, newY + 0.95)
            py = newY
            pOnGround = false
        else
            pvy = 0
            // Snap below ceiling
            ceilR = dave_worldToRow(newY + 0.95)
            py = (LVL_H - ceilR) * 1.0 - 0.96
        ok
    else
        // Moving down
        if !dave_feetSolid(px, newY)
            py = newY
            pOnGround = false
        else
            pvy = 0
            pOnGround = true
            // Snap to top of floor
            floorR = dave_worldToRow(newY)
            py = (LVL_H - floorR + 1) * 1.0
        ok
    ok

    // Clamp position
    if px < 1.5 px = 1.5 ok
    if px > curLvlW - 0.5 px = curLvlW - 0.5 ok
    if py < 0.5
        dave_killPlayer()
        return
    ok

    // Check collectibles
    cr = dave_worldToRow(py + 0.5)
    cc = dave_worldToCol(px)
    if cr >= 1 and cr <= LVL_H and cc >= 1 and cc <= curLvlW
        t = tiles[cr][cc]
        if t = T_GEM
            tiles[cr][cc] = dave_bgTile(cr, cc)
            score += 100
            gemsLeft -= 1
            dave_spawnPickupParticles(px, py + 0.5, 50, 150, 255)
            add(popups, [px, py + 1.0, "+100", 1.0])
            PlaySound(sndGem)
        ok
        if t = T_RUBY
            tiles[cr][cc] = dave_bgTile(cr, cc)
            score += 250
            gemsLeft -= 1
            dave_spawnPickupParticles(px, py + 0.5, 255, 50, 80)
            add(popups, [px, py + 1.0, "+250", 1.0])
            PlaySound(sndRuby)
        ok
        if t = T_RING
            tiles[cr][cc] = dave_bgTile(cr, cc)
            score += 500
            gemsLeft -= 1
            dave_spawnPickupParticles(px, py + 0.5, 255, 215, 0)
            add(popups, [px, py + 1.0, "+500", 1.0])
            PlaySound(sndRing)
            // Level 20: the golden YES ring grants the key
            if level = 20
                hasKey = true
                add(popups, [px, py + 1.5, "Yes! You have the Key!", 2.5])
                PlaySound(sndKey)
            ok
        ok
        if t = T_KEY
            tiles[cr][cc] = dave_bgTile(cr, cc)
            hasKey = true
            dave_spawnPickupParticles(px, py + 0.5, 255, 255, 100)
            add(popups, [px, py + 1.0, "KEY!", 1.5])
            PlaySound(sndKey)
        ok
        if t = T_GUN
            tiles[cr][cc] = dave_bgTile(cr, cc)
            hasGun = true
            dave_spawnPickupParticles(px, py + 0.5, 255, 150, 0)
            add(popups, [px, py + 1.0, "GUN! [F]", 2.0])
            PlaySound(sndGunPickup)
        ok
        if t = T_DOOR
            if hasKey
                // Open all door tiles
                for dr = 1 to LVL_H
                    for dc = 1 to curLvlW
                        if tiles[dr][dc] = T_DOOR
                            tiles[dr][dc] = T_EMPTY
                            dave_spawnPickupParticles(dc * 1.0, (LVL_H - dr) * 1.0 + 0.5,
                                                     200, 100, 255)
                        ok
                    next
                next
                doorOpen = true
                add(popups, [px, py + 1.0, "OPEN!", 1.5])
                PlaySound(sndDoor)
            ok
        ok
        if t = T_TROPHY
            if doorOpen
                score += 1000
                add(popups, [px, py + 1.0, "+1000!", 2.0])
                dave_spawnPickupParticles(px, py + 0.5, 255, 255, 50)
                gameState = ST_LEVELUP
                levelUpTimer = 2.0
                PlaySound(sndTrophy)
            else
                // Push player back - can't get trophy without opening door first
                if pFacingRight
                    px -= 0.5
                else
                    px += 0.5
                ok
                add(popups, [px, py + 1.0, "NEED KEY!", 1.5])
            ok
        ok
        if t = T_SPIKE
            dave_killPlayer()
            return
        ok
    ok

    // Check all neighboring tiles for door proximity (all directions)
    // This ensures doors open when touched from any direction
    if hasKey and !doorOpen
        for checkDY = -1 to 1
            for checkDX = -1 to 1
                if checkDY = 0 and checkDX = 0 loop ok
                checkR = dave_worldToRow(py + 0.5) + checkDY
                checkC = dave_worldToCol(px) + checkDX
                if checkR >= 1 and checkR <= LVL_H and checkC >= 1 and checkC <= curLvlW
                    if tiles[checkR][checkC] = T_DOOR
                        // Player is adjacent to door and has key - open it
                        for dr = 1 to LVL_H
                            for dc = 1 to curLvlW
                                if tiles[dr][dc] = T_DOOR
                                    tiles[dr][dc] = T_EMPTY
                                    dave_spawnPickupParticles(dc * 1.0, (LVL_H - dr) * 1.0 + 0.5,
                                                             200, 100, 255)
                                ok
                            next
                        next
                        doorOpen = true
                        add(popups, [px, py + 1.0, "OPEN!", 1.5])
                        PlaySound(sndDoor)
                    ok
                ok
            next
        next
    ok

    // Also check half-tile above for tall player
    cr2 = dave_worldToRow(py + 0.3)
    if cr2 >= 1 and cr2 <= LVL_H and cc >= 1 and cc <= curLvlW
        t2 = tiles[cr2][cc]
        if t2 = T_GEM
            tiles[cr2][cc] = dave_bgTile(cr2, cc)
            score += 100
            gemsLeft -= 1
            dave_spawnPickupParticles(px, py + 0.5, 50, 150, 255)
            add(popups, [px, py + 1.0, "+100", 1.0])
            PlaySound(sndGem)
        ok
        if t2 = T_RUBY
            tiles[cr2][cc] = dave_bgTile(cr2, cc)
            score += 250
            gemsLeft -= 1
            dave_spawnPickupParticles(px, py + 0.5, 255, 50, 80)
            add(popups, [px, py + 1.0, "+250", 1.0])
            PlaySound(sndRuby)
        ok
        if t2 = T_RING
            tiles[cr2][cc] = dave_bgTile(cr2, cc)
            score += 500
            gemsLeft -= 1
            dave_spawnPickupParticles(px, py + 0.5, 255, 215, 0)
            add(popups, [px, py + 1.0, "+500", 1.0])
            PlaySound(sndRing)
            if level = 20
                hasKey = true
                add(popups, [px, py + 1.5, "Yes! You have the Key!", 2.5])
                PlaySound(sndKey)
            ok
        ok
        if t2 = T_KEY
            tiles[cr2][cc] = dave_bgTile(cr2, cc)
            hasKey = true
            dave_spawnPickupParticles(px, py + 0.5, 255, 255, 100)
            add(popups, [px, py + 1.0, "KEY!", 1.5])
            PlaySound(sndKey)
        ok
        if t2 = T_GUN
            tiles[cr2][cc] = dave_bgTile(cr2, cc)
            hasGun = true
            dave_spawnPickupParticles(px, py + 0.5, 255, 150, 0)
            add(popups, [px, py + 1.0, "GUN! [F]", 2.0])
            PlaySound(sndGunPickup)
        ok
    ok

    // Update shoot cooldown
    if pShootCooldown > 0
        pShootCooldown -= dt
    ok

    // Update enemies
    dave_updateEnemies(dt)

    // Update player bullets
    dave_updateBullets(dt)

    // Update enemy bullets
    dave_updateEnemyBullets(dt)

    // Check enemy collision
    nEnemies = len(enemies)
    for e = 1 to nEnemies
        if enemies[e][6]
            dx = px - enemies[e][1]
            dy = (py + 0.5) - enemies[e][2]
            dist = dx * dx + dy * dy
            if dist < 0.64
                dave_killPlayer()
                return
            ok
        ok
    next

    // Check enemy bullet collision with player
    i = 1
    nEB = len(eBullets)
    while i <= nEB
        dx = px - eBullets[i][1]
        dy = (py + 0.5) - eBullets[i][2]
        dist = dx * dx + dy * dy
        if dist < 0.36
            del(eBullets, i)
            dave_killPlayer()
            return
        else
            i += 1
        ok
    end

    // Update new systems
    dave_updateMovers(dt)
    dave_isOnMover()
    dave_updateIcicles(dt)
    dave_updateCrumbles(dt)
    dave_applyWind(dt)
    dave_checkCheckpoint()

    // Update particles & popups
    dave_updateParticles(dt)
    dave_updatePopups(dt)

// =============================================================
// Enemy Update
// =============================================================

func dave_updateEnemies dt
    nEnemies = len(enemies)
    for e = 1 to nEnemies
        if !enemies[e][6] loop ok

        enemies[e][7] += dt  // anim timer

        if enemies[e][5] = 1
            // Walking enemy - patrol left/right
            ex = enemies[e][1]
            ey = enemies[e][2]
            evx = enemies[e][3]
            moveDir = 1
            if evx < 0 moveDir = -1 ok

            // Ground row is directly below enemy feet
            groundR = dave_worldToRow(ey) + 1
            if groundR > LVL_H groundR = LVL_H ok

            // Check 1.2 tiles ahead for floor
            checkC = dave_worldToCol(ex + moveDir * 1.2)
            hasFloorAhead = false
            spikeAhead = false
            if checkC >= 1 and checkC <= curLvlW and groundR >= 1 and groundR <= LVL_H
                if dave_enemyGroundSolid(groundR, checkC)
                    hasFloorAhead = true
                ok
                if tiles[groundR][checkC] = T_SPIKE
                    spikeAhead = true
                ok
            ok

            // Check current position has floor
            curC = dave_worldToCol(ex)
            hasFloorHere = false
            spikeHere = false
            if curC >= 1 and curC <= curLvlW and groundR >= 1 and groundR <= LVL_H
                if dave_enemyGroundSolid(groundR, curC)
                    hasFloorHere = true
                ok
                if tiles[groundR][curC] = T_SPIKE
                    spikeHere = true
                ok
            ok

            // Check wall ahead
            wallAheadC = dave_worldToCol(ex + moveDir * 0.5)
            wallAheadR = dave_worldToRow(ey + 0.3)
            hitWall = false
            if wallAheadC < 2 or wallAheadC >= curLvlW
                hitWall = true
            but dave_tileIsSolid(wallAheadR, wallAheadC)
                hitWall = true
            ok

            // Reverse if no floor ahead, hitting wall, or spikes ahead
            if !hasFloorAhead or hitWall or spikeAhead
                enemies[e][3] = -enemies[e][3]
            ok

            // If on spikes, reverse and nudge away
            if spikeHere
                enemies[e][3] = -enemies[e][3]
                enemies[e][1] += enemies[e][3] * 0.3
            // If floating (no floor here), nudge back
            but !hasFloorHere
                enemies[e][3] = -enemies[e][3]
                enemies[e][1] += enemies[e][3] * 0.3
            else
                // Only move if floor is safe
                enemies[e][1] += enemies[e][3] * dt
            ok
        ok

        if enemies[e][5] = 2
            // Flying enemy - sine wave pattern
            enemies[e][1] += enemies[e][3] * dt
            enemies[e][2] += sin(enemies[e][7] * 2.5) * dt * 1.5

            // Bounce off walls
            eCol = dave_worldToCol(enemies[e][1])
            if eCol < 2 or eCol >= curLvlW
                enemies[e][3] = -enemies[e][3]
            ok
        ok

        if enemies[e][5] = 3
            // Shooting enemy - patrols and shoots at player
            ex = enemies[e][1]
            ey = enemies[e][2]
            evx = enemies[e][3]
            moveDir = 1
            if evx < 0 moveDir = -1 ok

            // Ground row is directly below enemy feet
            groundR = dave_worldToRow(ey) + 1
            if groundR > LVL_H groundR = LVL_H ok

            // Check 1.2 tiles ahead for floor
            checkC = dave_worldToCol(ex + moveDir * 1.2)
            hasFloorAhead = false
            spikeAhead = false
            if checkC >= 1 and checkC <= curLvlW and groundR >= 1 and groundR <= LVL_H
                if dave_enemyGroundSolid(groundR, checkC)
                    hasFloorAhead = true
                ok
                if tiles[groundR][checkC] = T_SPIKE
                    spikeAhead = true
                ok
            ok

            // Check current position has floor
            curC = dave_worldToCol(ex)
            hasFloorHere = false
            spikeHere = false
            if curC >= 1 and curC <= curLvlW and groundR >= 1 and groundR <= LVL_H
                if dave_enemyGroundSolid(groundR, curC)
                    hasFloorHere = true
                ok
                if tiles[groundR][curC] = T_SPIKE
                    spikeHere = true
                ok
            ok

            // Check wall ahead
            wallAheadC = dave_worldToCol(ex + moveDir * 0.5)
            wallAheadR = dave_worldToRow(ey + 0.3)
            hitWall = false
            if wallAheadC < 2 or wallAheadC >= curLvlW
                hitWall = true
            but dave_tileIsSolid(wallAheadR, wallAheadC)
                hitWall = true
            ok

            // Reverse if no floor ahead, hitting wall, or spikes ahead
            if !hasFloorAhead or hitWall or spikeAhead
                enemies[e][3] = -enemies[e][3]
            ok

            // If on spikes, reverse and nudge away
            if spikeHere
                enemies[e][3] = -enemies[e][3]
                enemies[e][1] += enemies[e][3] * 0.3
            // If floating, nudge back
            but !hasFloorHere
                enemies[e][3] = -enemies[e][3]
                enemies[e][1] += enemies[e][3] * 0.3
            else
                enemies[e][1] += enemies[e][3] * dt
            ok

            // Shoot at player periodically
            enemies[e][8] -= dt
            if enemies[e][8] <= 0
                enemies[e][8] = 2.0 + GetRandomValue(0, 100) / 100.0
                // Calculate direction to player
                edx = px - enemies[e][1]
                edy = (py + 0.5) - enemies[e][2]
                eDist = sqrt(edx * edx + edy * edy)
                if eDist > 0.5 and eDist < 15.0
                    bvx = (edx / eDist) * 6.0
                    bvy = (edy / eDist) * 6.0
                    add(eBullets, [enemies[e][1], enemies[e][2], bvx, bvy, 3.0])
                    PlaySound(sndEnemyShoot)
                ok
            ok
        ok
    next

// =============================================================
// Bullet Updates
// =============================================================

func dave_updateBullets dt
    i = 1
    nBul = len(bullets)
    while i <= nBul
        bullets[i][1] += bullets[i][3] * dt
        bullets[i][2] += bullets[i][4] * dt
        bullets[i][5] -= dt

        // Check if hit a wall
        br = dave_worldToRow(bullets[i][2])
        bc = dave_worldToCol(bullets[i][1])
        hitWall = false
        if br >= 1 and br <= LVL_H and bc >= 1 and bc <= curLvlW
            if dave_tileIsSolid(br, bc)
                hitWall = true
            ok
        else
            hitWall = true
        ok

        // Check if hit an enemy
        hitEnemy = false
        nEnemies = len(enemies)
        for e = 1 to nEnemies
            if enemies[e][6]
                dx = bullets[i][1] - enemies[e][1]
                dy = bullets[i][2] - enemies[e][2]
                dist = dx * dx + dy * dy
                if dist < 0.5
                    enemies[e][6] = false
                    hitEnemy = true
                    score += 200
                    dave_spawnPickupParticles(enemies[e][1], enemies[e][2], 255, 100, 0)
                    add(popups, [enemies[e][1], enemies[e][2] + 0.5, "+200", 1.0])
                    PlaySound(sndEnemyDie)
                ok
            ok
        next

        if bullets[i][5] <= 0 or hitWall or hitEnemy
            if hitWall
                dave_spawnPickupParticles(bullets[i][1], bullets[i][2], 255, 200, 50)
            ok
            del(bullets, i)
            nBul -= 1
        else
            i += 1
        ok
    end

func dave_updateEnemyBullets dt
    i = 1
    nEB2 = len(eBullets)
    while i <= nEB2
        eBullets[i][1] += eBullets[i][3] * dt
        eBullets[i][2] += eBullets[i][4] * dt
        eBullets[i][5] -= dt

        // Check if hit a wall
        br = dave_worldToRow(eBullets[i][2])
        bc = dave_worldToCol(eBullets[i][1])
        hitWall = false
        if br >= 1 and br <= LVL_H and bc >= 1 and bc <= curLvlW
            if dave_tileIsSolid(br, bc)
                hitWall = true
            ok
        else
            hitWall = true
        ok

        if eBullets[i][5] <= 0 or hitWall
            del(eBullets, i)
            nEB2 -= 1
        else
            i += 1
        ok
    end

func dave_updateMovers dt
    nMovers = len(movers)
    for m = 1 to nMovers
        mx = movers[m][1]
        my = movers[m][2]
        mvx = movers[m][3]
        mvy = movers[m][4]
        rMin = movers[m][5]
        rMax = movers[m][6]
        mType = movers[m][7]
        mw = movers[m][8]

        if mType = 1
            // Horizontal mover
            mx += mvx * dt
            // Range limits
            if mx >= rMax
                mx = rMax
                mvx = -fabs(mvx)
            ok
            if mx <= rMin
                mx = rMin
                mvx = fabs(mvx)
            ok
            // Wall collision - check leading edge
            mDir = 1
            if mvx < 0 mDir = -1 ok
            checkX = mx + mDir * (mw * 0.5 + 0.2)
            checkR = dave_worldToRow(my)
            checkC = dave_worldToCol(checkX)
            if checkC >= 1 and checkC <= curLvlW and checkR >= 1 and checkR <= LVL_H
                if dave_tileIsSolid(checkR, checkC)
                    mvx = -mvx
                    mx += mvx * dt * 2
                ok
            else
                mvx = -mvx
            ok
            movers[m][1] = mx
            movers[m][3] = mvx
        else
            // Vertical mover
            my += mvy * dt
            // Range limits
            if my >= rMax
                my = rMax
                mvy = -fabs(mvy)
            ok
            if my <= rMin
                my = rMin
                mvy = fabs(mvy)
            ok
            // Wall collision - check top/bottom edge
            if mvy > 0
                checkY = my + 0.3
            else
                checkY = my - 0.3
            ok
            checkR = dave_worldToRow(checkY)
            checkC = dave_worldToCol(mx)
            if checkR >= 1 and checkR <= LVL_H and checkC >= 1 and checkC <= curLvlW
                if dave_tileIsSolid(checkR, checkC)
                    mvy = -mvy
                    my += mvy * dt * 2
                ok
            else
                mvy = -mvy
            ok
            movers[m][2] = my
            movers[m][4] = mvy
        ok
    next

func dave_updateIcicles dt
    nIcicles = len(icicles)
    for i = 1 to nIcicles
        state = icicles[i][3]
        if state = 0
            // Hanging - check if player is below
            dx = fabs(px - icicles[i][1])
            if dx < 1.5 and py < icicles[i][2]
                icicles[i][3] = 1
                icicles[i][4] = 0.6  // shake timer
            ok
        ok
        if state = 1
            // Shaking - countdown then fall
            icicles[i][4] -= dt
            if icicles[i][4] <= 0
                icicles[i][3] = 2
                icicles[i][5] = 0.0  // initial fall speed
            ok
        ok
        if state = 2
            // Falling
            icicles[i][5] += GRAVITY * dt
            icicles[i][2] -= icicles[i][5] * dt
            // Check if hit player
            dx = fabs(px - icicles[i][1])
            dy = fabs(py + 0.5 - icicles[i][2])
            if dx < 0.4 and dy < 0.5
                dave_killPlayer()
                icicles[i][3] = 3
                return
            ok
            // Check if hit ground
            if icicles[i][2] <= 0.5
                icicles[i][3] = 3
                // Shatter particles
                dave_spawnPickupParticles(icicles[i][1], 0.5, 180, 220, 255)
            ok
            fr = dave_worldToRow(icicles[i][2])
            fc = dave_worldToCol(icicles[i][1])
            if fr >= 1 and fr <= LVL_H and fc >= 1 and fc <= curLvlW
                if dave_tileIsSolid(fr, fc)
                    icicles[i][3] = 3
                    dave_spawnPickupParticles(icicles[i][1], icicles[i][2], 180, 220, 255)
                ok
            ok
        ok
    next

func dave_updateCrumbles dt
    nCrumbles = len(crumbles)
    for i = 1 to nCrumbles
        state = crumbles[i][4]
        cc = crumbles[i][1]
        cr = crumbles[i][2]
        if state = 0
            // Solid - check if player standing on it
            tileTopY = (LVL_H - cr + 1) * 1.0
            if fabs(px - cc) < 0.8 and fabs(py - tileTopY) < 0.2 and pOnGround
                crumbles[i][4] = 1
                crumbles[i][3] = 0.8  // time before crumble
            ok
        ok
        if state = 1
            // Crumbling countdown
            crumbles[i][3] -= dt
            if crumbles[i][3] <= 0
                crumbles[i][4] = 2
                tiles[cr][cc] = T_EMPTY
                dave_spawnPickupParticles(cc * 1.0, (LVL_H - cr) * 1.0 + 0.5,
                                         200, 210, 230)
            ok
        ok
    next

func dave_applyWind dt
    inWind = false
    windDir = 0
    nWind = len(windZones)
    for i = 1 to nWind
        wc = windZones[i][1]
        wr = windZones[i][2]
        wDir = windZones[i][3]
        // Wind tile world bounds
        windX = wc * 1.0
        windY = (LVL_H - wr) * 1.0 + 0.5
        // Check if player overlaps this wind tile (generous range)
        dx = fabs(px - windX)
        dy = fabs((py + 0.5) - windY)
        if dx < 1.0 and dy < 1.5
            inWind = true
            windDir = wDir
        ok
    next
    if inWind
        // Strong push: directly move player + add velocity
        px += windDir * 4.0 * dt
        pvx += windDir * 8.0 * dt
        // Clamp wind-induced velocity
        if pvx > 8.0 pvx = 8.0 ok
        if pvx < -8.0 pvx = -8.0 ok
    ok

func dave_checkCheckpoint
    cr = dave_worldToRow(py + 0.5)
    cc = dave_worldToCol(px)
    if cr >= 1 and cr <= LVL_H and cc >= 1 and cc <= curLvlW
        if tiles[cr][cc] = T_CHECKPOINT
            if !checkpointActive or (checkpointX != px or checkpointY != py)
                checkpointX = px
                checkpointY = py
                checkpointActive = true
                add(popups, [px, py + 1.0, "CHECKPOINT!", 1.5])
                dave_spawnPickupParticles(px, py + 0.5, 100, 255, 100)
            ok
        ok
    ok

// Determine background tile when a collectible is picked up
// Checks neighbors - if surrounded by wind tiles, return wind type
func dave_bgTile r, c
    // Check left, right, above, below for wind tiles
    if c > 1
        nt = tiles[r][c-1]
        if nt = T_WIND_L return T_WIND_L ok
        if nt = T_WIND_R return T_WIND_R ok
    ok
    if c < curLvlW
        nt = tiles[r][c+1]
        if nt = T_WIND_L return T_WIND_L ok
        if nt = T_WIND_R return T_WIND_R ok
    ok
    if r > 1
        nt = tiles[r-1][c]
        if nt = T_WIND_L return T_WIND_L ok
        if nt = T_WIND_R return T_WIND_R ok
    ok
    if r < LVL_H
        nt = tiles[r+1][c]
        if nt = T_WIND_L return T_WIND_L ok
        if nt = T_WIND_R return T_WIND_R ok
    ok
    return T_EMPTY
