/*
**  tank3d_input.ring
**  Input handling and movement collision checking
*/

// =============================================================
// Input Handling
// =============================================================

func tank_handleInput dt
    if IsKeyPressed(KEY_C)
        camMode = (camMode + 1) % CAM_COUNT
    ok

    if IsKeyPressed(KEY_R)
        tank_loadLevel(level)
        gameState = ST_PLAYING
        return
    ok

    // Level skip keys: N = next level, B = previous level
    if gameState = ST_PLAYING or gameState = ST_PAUSED
        if IsKeyPressed(KEY_N)
            if level < maxLevel
                level += 1
                tank_loadLevel(level)
                gameState = ST_PLAYING
                PlaySound(sndLevelClear)
            ok
            return
        ok
        if IsKeyPressed(KEY_B)
            if level > 1
                level -= 1
                tank_loadLevel(level)
                gameState = ST_PLAYING
                PlaySound(sndLevelClear)
            ok
            return
        ok
    ok

    if gameState = ST_TITLE
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            gameState = ST_PLAYING
            level = 1
            score = 0
            lives = 3
            totalKills = 0
            totalShotsFired = 0
            accuracyHits = 0
            tank_loadLevel(level)
        ok
        return
    ok

    if gameState = ST_GAMEOVER or gameState = ST_WON
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            gameState = ST_TITLE
        ok
        return
    ok

    if gameState = ST_PLAYING
        if IsKeyPressed(KEY_P)
            gameState = ST_PAUSED
            return
        ok
    ok

    if gameState = ST_PAUSED
        if IsKeyPressed(KEY_P) or IsKeyPressed(KEY_SPACE)
            gameState = ST_PLAYING
            ResumeMusicStream(musBattle)
            musicPlaying = 2
        ok
        return
    ok

    if gameState != ST_PLAYING return ok
    if !palive return ok

    // Tank movement
    moving = false
    spd = PLAYER_SPEED
    if pspeedBoost > 0 spd = spd * 1.5 ok

    if IsKeyDown(KEY_UP) or IsKeyDown(KEY_W)
        pdir = DIR_UP
        moving = true
    ok
    if IsKeyDown(KEY_DOWN) or IsKeyDown(KEY_S)
        pdir = DIR_DOWN
        moving = true
    ok
    if IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_A)
        pdir = DIR_LEFT
        moving = true
    ok
    if IsKeyDown(KEY_RIGHT) or IsKeyDown(KEY_D)
        pdir = DIR_RIGHT
        moving = true
    ok

    if moving
        dx = 0 dy = 0
        if pdir = DIR_UP dy = -1 ok
        if pdir = DIR_DOWN dy = 1 ok
        if pdir = DIR_LEFT dx = -1 ok
        if pdir = DIR_RIGHT dx = 1 ok

        newX = px + dx * spd * dt
        newY = py + dy * spd * dt

        // Collision check (tank occupies ~1.0 unit)
        if tank_canMove(newX, newY, true)
            px = newX
            py = newY
        but tank_canMove(newX, py, true)
            px = newX
        but tank_canMove(px, newY, true)
            py = newY
        ok

        pMoveAnim += dt * 10.0
        // Engine sound when moving
        if !IsSoundPlaying(sndEngine)
            PlaySound(sndEngine)
        ok
    ok

    // Clamp to grid
    if px < 1.5 px = 1.5 ok
    if px > GRID_W - 0.5 px = GRID_W - 0.5 ok
    if py < 1.5 py = 1.5 ok
    if py > GRID_H - 0.5 py = GRID_H - 0.5 ok

    // Fire (with cooldown)
    pFireCooldown -= dt
    if pFireCooldown < 0 pFireCooldown = 0 ok
    if IsKeyPressed(KEY_SPACE) or IsKeyPressed(KEY_ENTER)
        if len(pbullets) < 2 and pFireCooldown <= 0
            bspd = BULLET_SPEED
            if pspeedBoost > 0 bspd = bspd * 1.3 ok
            add(pbullets, [true, px, py, pdir, bspd])
            tank_muzzleFlash(px, py, pdir)
            PlaySound(sndFire)
            pFireCooldown = 0.25
            totalShotsFired += 1
        ok
    ok

// =============================================================
// Movement Collision Check
// =============================================================

func tank_canMove x, y, isPlayer
    // Tank is about 0.8 wide, check corners
    hw = 0.38   // Half-width
    corners = [
        [x - hw, y - hw],
        [x + hw, y - hw],
        [x - hw, y + hw],
        [x + hw, y + hw]
    ]

    for i = 1 to 4
        cx = corners[i][1]
        cy = corners[i][2]
        gc = floor(cx + 0.5)
        gr = floor(cy + 0.5)
        if gr < 1 or gr > GRID_H or gc < 1 or gc > GRID_W return false ok
        t = tiles[gr][gc]
        if t = T_BRICK or t = T_STEEL or t = T_WATER or t = T_BASE or t = T_BASEDEAD
            return false
        ok
    next

    // Check collision with other tanks
    if isPlayer
        nEnemies = len(enemies)
        for e = 1 to nEnemies
            if enemies[e][5]  // alive
                dx = x - enemies[e][1]
                dy = y - enemies[e][2]
                if dx > -0.85 and dx < 0.85 and dy > -0.85 and dy < 0.85
                    return false
                ok
            ok
        next
    ok

    return true
