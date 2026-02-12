/*
**  Dave the Fighter - Input Handling
**  Functions: dave_handleInput
*/

func dave_handleInput dt

    // Restart
    if IsKeyPressed(KEY_R)
        dave_loadLevel(level)
        gameState = ST_PLAYING
        return
    ok

    // Next level (N)
    if IsKeyPressed(KEY_N)
        if level < maxLevel
            level += 1
            dave_loadLevel(level)
            gameState = ST_PLAYING
        ok
        return
    ok

    // Previous level (B)
    if IsKeyPressed(KEY_B)
        if level > 1
            level -= 1
            dave_loadLevel(level)
            gameState = ST_PLAYING
        ok
        return
    ok

    if gameState = ST_TITLE
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            gameState = ST_PLAYING
            level = 1
            score = 0
            lives = 3
            dave_loadLevel(level)
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
            PauseMusicStream(bgMusic)
            return
        ok
    ok

    if gameState = ST_PAUSED
        if IsKeyPressed(KEY_P) or IsKeyPressed(KEY_SPACE)
            gameState = ST_PLAYING
            ResumeMusicStream(bgMusic)
        ok
        return
    ok

    if gameState != ST_PLAYING return ok

    // Movement
    moveDir = 0
    if IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_A)
        moveDir = -1
        pFacingRight = false
    ok
    if IsKeyDown(KEY_RIGHT) or IsKeyDown(KEY_D)
        moveDir = 1
        pFacingRight = true
    ok

    // Acceleration
    if moveDir != 0
        pvx = moveDir * MOVE_SPEED
        pWalkFrame += dt * 8.0
    else
        pvx = pvx * 0.7
        if pvx > -0.3 and pvx < 0.3 pvx = 0 ok
    ok

    // Jump
    if IsKeyPressed(KEY_SPACE) or IsKeyPressed(KEY_UP) or IsKeyPressed(KEY_W)
        if pOnGround
            pvy = JUMP_FORCE
            pOnGround = false
            PlaySound(sndJump)
        ok
    ok

    // Ladder climbing
    tr = dave_tileAtWorld(px, py)
    trBody = dave_tileAtWorld(px, py + 0.3)
    trBelow = dave_tileAtWorld(px, py - 0.3)
    onLadderTile = (tr = T_LADDER or trBody = T_LADDER)

    if onLadderTile and !pOnGround
        // Already inside a ladder and not on ground - climb freely
        if IsKeyDown(KEY_UP) or IsKeyDown(KEY_W)
            pvy = 3.5
            pOnGround = false
        ok
        if IsKeyDown(KEY_DOWN) or IsKeyDown(KEY_S)
            pvy = -3.5
        ok
    but onLadderTile and pOnGround
        // Standing on a ladder tile that acts as ground (converted from brick)
        if IsKeyDown(KEY_DOWN) or IsKeyDown(KEY_S)
            py -= 0.5
            pvy = -2.5
            pOnGround = false
        ok
        if IsKeyDown(KEY_UP) or IsKeyDown(KEY_W)
            pvy = 3.5
            pOnGround = false
        ok
    but trBelow = T_LADDER and pOnGround
        // Standing on solid ground above a ladder - press down to enter
        if IsKeyDown(KEY_DOWN) or IsKeyDown(KEY_S)
            py -= 0.5
            pvy = -2.5
            pOnGround = false
        ok
    ok

    // Shooting
    if hasGun and pShootCooldown <= 0
        if IsKeyPressed(KEY_F)
            bDir = 1
            if !pFacingRight bDir = -1 ok
            add(bullets, [px + bDir * 0.3, py + 0.5, bDir * 14.0, 0.0, 1.5])
            pShootCooldown = 0.25
            dave_spawnPickupParticles(px + bDir * 0.3, py + 0.5, 255, 200, 50)
            PlaySound(sndShoot)
        ok
    ok
