/*
**  Dave the Fighter - HUD & Game State Screens
**  Functions: dave_drawHUD
*/

func dave_drawHUD
    // Top bar background
    DrawRectangle(0, 0, SCREEN_W, 44, RAYLIBColor(0, 0, 0, 180))

    // Score
    DrawText("SCORE: " + string(score), 15, 10, 22,
             RAYLIBColor(255, 255, 255, 255))

    // Level number with game name
    lvlText = "Dave The Fighter (Level " + string(level) + ")"
    DrawText(lvlText, floor(SCREEN_W / 2 - MeasureText(lvlText, 22) / 2), 10, 22,
             RAYLIBColor(255, 220, 50, 255))

    // HUD accent bar color matches world
    if level <= 5
        DrawRectangle(0, 44, SCREEN_W, 2, RAYLIBColor(200, 30, 30, 255))
    but level <= 10
        DrawRectangle(0, 44, SCREEN_W, 2, RAYLIBColor(30, 60, 200, 255))
    but level <= 15
        DrawRectangle(0, 44, SCREEN_W, 2, RAYLIBColor(180, 210, 240, 255))
    else
        DrawRectangle(0, 44, SCREEN_W, 2, RAYLIBColor(230, 190, 60, 255))
    ok

    // Lives - draw player face icons
    DrawText("LIVES:", SCREEN_W - 200, 10, 22,
             RAYLIBColor(255, 80, 80, 255))
    for i = 1 to lives
        faceX = SCREEN_W - 120 + (i - 1) * 30
        faceY = 12
        // Face circle (skin)
        DrawCircle(faceX, faceY + 9, 10, RAYLIBColor(255, 200, 150, 255))
        // Hat (red like Dave)
        DrawRectangle(faceX - 10, faceY - 2, 20, 6, RAYLIBColor(220, 40, 40, 255))
        DrawRectangle(faceX - 7, faceY + 3, 14, 3, RAYLIBColor(220, 40, 40, 255))
        // Eyes
        DrawCircle(faceX - 4, faceY + 9, 2, RAYLIBColor(40, 40, 80, 255))
        DrawCircle(faceX + 4, faceY + 9, 2, RAYLIBColor(40, 40, 80, 255))
        // Smile
        DrawRectangle(faceX - 3, faceY + 14, 6, 2, RAYLIBColor(180, 80, 80, 255))
    next

    // Key indicator
    if hasKey
        DrawText("[KEY]", SCREEN_W - 280, 10, 22,
                 RAYLIBColor(255, 220, 50, 255))
    ok

    // Gun indicator
    if hasGun
        gunX = SCREEN_W - 360
        DrawText("[GUN]", gunX, 10, 22,
                 RAYLIBColor(255, 140, 30, 255))
    ok

    // Gems progress
    collected = totalGems - gemsLeft
    progText = "Gems: " + string(collected) + "/" + string(totalGems)
    DrawText(progText, 15, SCREEN_H - 30, 18,
             RAYLIBColor(100, 200, 255, 200))

    // Controls
    if hasGun
        DrawText("Arrows/WASD: Move | Space: Jump | F: Shoot | P: Pause | R: Restart",
                 floor(SCREEN_W / 2 - 280), SCREEN_H - 30, 14,
                 RAYLIBColor(140, 140, 140, 150))
    else
        DrawText("Arrows/WASD: Move | Space: Jump | P: Pause | R: Restart",
                 floor(SCREEN_W / 2 - 240), SCREEN_H - 30, 14,
                 RAYLIBColor(140, 140, 140, 150))
    ok

    // Popups (2D overlay text)
    nPopups = len(popups)
    for i = 1 to nPopups
        // TODO: could project 3D to 2D for popup text
    next

    // State overlays
    if gameState = ST_TITLE
        dt2 = GetFrameTime()
        if dt2 > 0.05 dt2 = 0.05 ok

        // Dark gray background
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(30, 30, 30, 255))

        // Twinkling stars (background layer)
        dave_drawTwinkleStars()

        // Shooting stars
        dave_updateShootingStars(dt2)
        dave_drawShootingStars()

        // Fireworks
        dave_updateFireworks(dt2)
        dave_drawFireworks()

        // Rainbow title - draw each letter with shifting hue
        title = "DAVE THE FIGHTER"
        tW = MeasureText(title, 52)
        titleX = floor(SCREEN_W / 2 - tW / 2)
        titleY = floor(SCREEN_H / 2 - 80)
        dave_drawRainbowTitle(title, titleX, titleY, 52)

        // Subtitle
        sub = "3D Action Platformer"
        subPulse = floor(sin(animTime * 1.5) * 30 + 225)
        DrawText(sub, floor(SCREEN_W / 2 - MeasureText(sub, 24) / 2),
                 floor(SCREEN_H / 2 - 15), 24, RAYLIBColor(255, 200, 100, subPulse))

        // Start prompt (pulsing)
        start = "Press ENTER or SPACE to Start"
        pulse = floor(sin(animTime * 3.0) * 60 + 195)
        DrawText(start, floor(SCREEN_W / 2 - MeasureText(start, 24) / 2),
                 floor(SCREEN_H / 2 + 40), 24, RAYLIBColor(255, 255, 255, pulse))

        // Instructions
        inst = "20 levels across 4 worlds!"
        DrawText(inst, floor(SCREEN_W / 2 - MeasureText(inst, 18) / 2),
                 floor(SCREEN_H / 2 + 90), 18, RAYLIBColor(180, 180, 180, 200))

        inst2 = "Collect gems, defeat enemies, find the key!"
        DrawText(inst2, floor(SCREEN_W / 2 - MeasureText(inst2, 18) / 2),
                 floor(SCREEN_H / 2 + 115), 18, RAYLIBColor(180, 180, 180, 200))

        // Controls
        ctrl = "Arrows/WASD: Move  |  Space: Jump  |  F: Shoot"
        DrawText(ctrl, floor(SCREEN_W / 2 - MeasureText(ctrl, 14) / 2),
                 floor(SCREEN_H / 2 + 155), 14, RAYLIBColor(120, 120, 120, 180))

        // Animated Dave running at bottom
        dave_updateTitleDave(dt2)
        dave_drawTitleDave()
    ok

    if gameState = ST_PAUSED
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 160))
        pTxt = "PAUSED"
        DrawText(pTxt, floor(SCREEN_W / 2 - MeasureText(pTxt, 48) / 2),
                 floor(SCREEN_H / 2 - 24), 48, RAYLIBColor(255, 255, 255, 255))
        rTxt = "Press P to Resume"
        DrawText(rTxt, floor(SCREEN_W / 2 - MeasureText(rTxt, 22) / 2),
                 floor(SCREEN_H / 2 + 30), 22, RAYLIBColor(200, 200, 200, 200))
    ok

    if gameState = ST_GAMEOVER
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 200))
        goTxt = "GAME OVER"
        DrawText(goTxt, floor(SCREEN_W / 2 - MeasureText(goTxt, 52) / 2),
                 floor(SCREEN_H / 2 - 50), 52, RAYLIBColor(255, 30, 30, 255))
        sTxt = "Final Score: " + string(score)
        DrawText(sTxt, floor(SCREEN_W / 2 - MeasureText(sTxt, 26) / 2),
                 floor(SCREEN_H / 2 + 10), 26, RAYLIBColor(255, 200, 100, 255))
        rr = "Press ENTER to Return to Title"
        DrawText(rr, floor(SCREEN_W / 2 - MeasureText(rr, 20) / 2),
                 floor(SCREEN_H / 2 + 50), 20, RAYLIBColor(200, 200, 200, 200))
    ok

    if gameState = ST_WON
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 200))
        wTxt = "YOU WIN!"
        DrawText(wTxt, floor(SCREEN_W / 2 - MeasureText(wTxt, 56) / 2),
                 floor(SCREEN_H / 2 - 50), 56, RAYLIBColor(255, 220, 50, 255))
        sTxt2 = "Final Score: " + string(score)
        DrawText(sTxt2, floor(SCREEN_W / 2 - MeasureText(sTxt2, 28) / 2),
                 floor(SCREEN_H / 2 + 10), 28, RAYLIBColor(255, 255, 200, 255))
        cTxt = "Congratulations, Fighter Dave!"
        DrawText(cTxt, floor(SCREEN_W / 2 - MeasureText(cTxt, 22) / 2),
                 floor(SCREEN_H / 2 + 50), 22, RAYLIBColor(200, 200, 200, 220))
        rr2 = "Press ENTER to Return to Title"
        DrawText(rr2, floor(SCREEN_W / 2 - MeasureText(rr2, 20) / 2),
                 floor(SCREEN_H / 2 + 90), 20, RAYLIBColor(180, 180, 180, 180))
    ok

    if gameState = ST_LEVELUP
        prog = 1.0 - (levelUpTimer / 2.0)
        alpha = floor(prog * 255)
        if alpha > 255 alpha = 255 ok
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, floor(alpha * 0.6)))
        lTxt = "LEVEL " + string(level) + " COMPLETE!"
        DrawText(lTxt, floor(SCREEN_W / 2 - MeasureText(lTxt, 44) / 2),
                 floor(SCREEN_H / 2 - 22), 44, RAYLIBColor(255, 220, 50, alpha))
    ok

    if gameState = ST_DYING
        prog = 1.0 - (dyingTimer / 1.5)
        alpha = floor(prog * 180)
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(255, 0, 0, alpha))
    ok

    // FPS
    // DrawFPS(SCREEN_W - 80, 50)

    // Level 20 story messages
    if level = 20 and gameState = ST_PLAYING
        dave_drawLevel20Messages()
    ok

func dave_drawLevel20Messages
    msg = ""
    msg2 = ""
    msgColor = RAYLIBColor(255, 255, 255, 255)
    showMsg = false

    // Message 1: cols 15-28 - Empty prison, eerie silence
    if px >= 15 and px < 29
        msg = "There is no key in this level."
        msgColor = RAYLIBColor(255, 200, 50, 255)
        showMsg = true
    ok

    // Message 2: cols 30-43
    if px >= 30 and px < 44
        msg = "Life is not fair."
        msg2 = "You cannot win. You cannot finish this game."
        msgColor = RAYLIBColor(255, 100, 100, 255)
        showMsg = true
    ok

    // Message 3: cols 45-58
    if px >= 45 and px < 59
        msg = "You have killed many NPCs in this game."
        msg2 = "Now it is time for justice."
        msgColor = RAYLIBColor(255, 80, 80, 255)
        showMsg = true
    ok

    // Message 4: cols 60-73
    if px >= 60 and px < 74
        msg = "You will remain in this prison forever!"
        msgColor = RAYLIBColor(200, 50, 50, 255)
        showMsg = true
    ok

    // Message 5: cols 75-88
    if px >= 75 and px < 89
        msg = "There is only one way out of this world..."
        msg2 = "Do you love the Ring programming language?"
        msgColor = RAYLIBColor(100, 200, 255, 255)
        showMsg = true
    ok

    // Message 6: cols 89-100 - The answer
    if px >= 89 and px < 101
        if !hasKey
            msg = "Touch the golden Ring to answer Yes!"
            msgColor = RAYLIBColor(255, 220, 50, 255)
            showMsg = true
        else
            msg = "You now have the key!"
            msg2 = "Find the door and escape!"
            msgColor = RAYLIBColor(50, 255, 100, 255)
            showMsg = true
        ok
    ok

    // After collecting key
    if px >= 101 and hasKey
        msg = "Freedom awaits you!"
        msgColor = RAYLIBColor(50, 255, 100, 255)
        showMsg = true
    ok

    if showMsg
        // Dark overlay behind text
        DrawRectangle(floor(SCREEN_W / 2 - 350), floor(SCREEN_H / 2 - 60),
                      700, 120, RAYLIBColor(0, 0, 0, 180))
        DrawRectangleLines(floor(SCREEN_W / 2 - 350), floor(SCREEN_H / 2 - 60),
                           700, 120, msgColor)

        // Main message
        pulse = floor(sin(animTime * 2.0) * 30 + 225)
        sz = 28
        DrawText(msg, floor(SCREEN_W / 2 - MeasureText(msg, sz) / 2),
                 floor(SCREEN_H / 2 - 30), sz, msgColor)

        // Second line if present
        if len(msg2) > 0
            sz2 = 24
            DrawText(msg2, floor(SCREEN_W / 2 - MeasureText(msg2, sz2) / 2),
                     floor(SCREEN_H / 2 + 10), sz2, msgColor)
        ok
    ok

// =============================================================
// Title Screen Fireworks (adapted from Color Screensaver)
// =============================================================

func dave_updateFireworks dt
    if dt > 0.05 dt = 0.05 ok

    // Spawn new firework burst periodically
    fwTimer += dt
    if fwTimer > 0.4
        fwTimer = 0.0
        dave_spawnFirework()
    ok

    // Update active particles
    for i = 1 to FW_MAX
        if fwActive[i] = 0 loop ok
        fwX[i] += fwVX[i] * dt
        fwY[i] += fwVY[i] * dt
        fwVY[i] += 120 * dt    // gravity
        fwVX[i] *= 0.99
        fwVY[i] *= 0.99
        fwLife[i] -= dt
        if fwLife[i] <= 0
            fwActive[i] = 0
        ok
    next

func dave_spawnFirework
    // Random burst position
    cx = GetRandomValue(150, SCREEN_W - 150)
    cy = GetRandomValue(100, SCREEN_H - 200)
    hue = GetRandomValue(0, 360)
    count = GetRandomValue(30, 50)

    for p = 1 to count
        slot = 0
        for i = 1 to FW_MAX
            if fwActive[i] = 0
                slot = i
                exit
            ok
        next
        if slot = 0 exit ok

        angle = GetRandomValue(0, 628) / 100.0
        speed = GetRandomValue(80, 280) * 1.0
        fwActive[slot] = 1
        fwX[slot] = cx * 1.0
        fwY[slot] = cy * 1.0
        fwVX[slot] = cos(angle) * speed
        fwVY[slot] = sin(angle) * speed
        fwLife[slot] = GetRandomValue(10, 25) / 10.0
        fwHue[slot] = hue + GetRandomValue(-30, 30)
        if fwHue[slot] < 0 fwHue[slot] += 360 ok
        if fwHue[slot] > 360 fwHue[slot] -= 360 ok
        fwSize[slot] = GetRandomValue(15, 40) / 10.0
    next

func dave_drawFireworks
    for i = 1 to FW_MAX
        if fwActive[i] = 0 loop ok

        lifeRatio = fwLife[i] / 2.5
        if lifeRatio > 1.0 lifeRatio = 1.0 ok
        alpha = floor(lifeRatio * 255)
        if alpha > 255 alpha = 255 ok
        if alpha < 0 loop ok

        rgb = dave_fwColor(fwHue[i])
        fr = rgb[1]  fg = rgb[2]  fb = rgb[3]

        sz = fwSize[i] * lifeRatio
        if sz < 0.3 sz = 0.3 ok

        // Outer glow
        DrawCircle(floor(fwX[i]), floor(fwY[i]), floor(sz * 3),
                   RAYLIBColor(fr, fg, fb, floor(alpha * 0.15)))
        // Core
        DrawCircle(floor(fwX[i]), floor(fwY[i]), floor(sz),
                   RAYLIBColor(fr, fg, fb, alpha))
        // Bright center spark
        if sz > 1.5
            DrawCircle(floor(fwX[i]), floor(fwY[i]), floor(sz * 0.4),
                       RAYLIBColor(255, 255, 255, floor(alpha * 0.5)))
        ok
    next

func dave_fwColor hue
    // Convert hue (0-360) to RGB rainbow
    h = (hue % 360) / 60.0
    sector = floor(h)
    f = h - sector
    q = floor(255 * (1.0 - f))
    t = floor(255 * f)

    if sector = 0 return [255, t, 0] ok
    if sector = 1 return [q, 255, 0] ok
    if sector = 2 return [0, 255, t] ok
    if sector = 3 return [0, q, 255] ok
    if sector = 4 return [t, 0, 255] ok
    return [255, 0, q]

// =============================================================
// Twinkling Stars
// =============================================================

func dave_drawTwinkleStars
    for i = 1 to STAR_MAX
        // Twinkle using sin wave
        bright = sin(animTime * tsSpeed[i] + tsPhase[i])
        alpha = floor((bright + 1.0) * 0.5 * tsBright[i])
        if alpha > 255 alpha = 255 ok
        if alpha < 10 alpha = 10 ok

        sz = tsSz[i]

        // Outer glow
        DrawCircle(floor(tsX[i]), floor(tsY[i]), floor(sz * 2.5),
                   RAYLIBColor(200, 220, 255, floor(alpha * 0.15)))
        // Core
        DrawCircle(floor(tsX[i]), floor(tsY[i]), floor(sz),
                   RAYLIBColor(220, 230, 255, alpha))
        // Bright center on peak brightness
        if bright > 0.7
            DrawCircle(floor(tsX[i]), floor(tsY[i]), floor(sz * 0.4),
                       RAYLIBColor(255, 255, 255, floor(alpha * 0.8)))
        ok
    next

// =============================================================
// Shooting Stars
// =============================================================

func dave_updateShootingStars dt
    ssTimer += dt
    if ssTimer > 1.5
        ssTimer = 0.0
        dave_spawnShootingStar()
    ok

    for i = 1 to SS_MAX
        if ssActive[i] = 0 loop ok
        ssX[i] += ssVX[i] * dt
        ssY[i] += ssVY[i] * dt
        ssLife[i] -= dt
        if ssLife[i] <= 0
            ssActive[i] = 0
        ok
    next

func dave_spawnShootingStar
    slot = 0
    for i = 1 to SS_MAX
        if ssActive[i] = 0
            slot = i
            exit
        ok
    next
    if slot = 0 return ok

    ssActive[slot] = 1
    // Start from random position along top or left edge
    if GetRandomValue(0, 1) = 0
        ssX[slot] = GetRandomValue(100, SCREEN_W) * 1.0
        ssY[slot] = -5.0
    else
        ssX[slot] = -5.0
        ssY[slot] = GetRandomValue(50, 300) * 1.0
    ok
    speed = GetRandomValue(400, 800) * 1.0
    angle = GetRandomValue(20, 50) / 100.0 + 0.5   // roughly 30-60 degrees
    ssVX[slot] = cos(angle) * speed
    ssVY[slot] = sin(angle) * speed
    ssLife[slot] = GetRandomValue(8, 15) / 10.0
    ssLen[slot] = GetRandomValue(40, 100) * 1.0
    ssHue[slot] = GetRandomValue(0, 360)

func dave_drawShootingStars
    for i = 1 to SS_MAX
        if ssActive[i] = 0 loop ok

        lifeRatio = ssLife[i] / 1.5
        if lifeRatio > 1.0 lifeRatio = 1.0 ok
        alpha = floor(lifeRatio * 255)
        if alpha > 255 alpha = 255 ok

        rgb = dave_fwColor(ssHue[i])
        fr = rgb[1]  fg = rgb[2]  fb = rgb[3]

        // Tail direction (opposite of velocity)
        speed = sqrt(ssVX[i] * ssVX[i] + ssVY[i] * ssVY[i])
        if speed < 1 speed = 1 ok
        dx = -ssVX[i] / speed
        dy = -ssVY[i] / speed

        // Draw trail segments
        nSegs = 8
        for s = 0 to nSegs
            segRatio = s * 1.0 / nSegs
            sx = floor(ssX[i] + dx * ssLen[i] * segRatio)
            sy = floor(ssY[i] + dy * ssLen[i] * segRatio)
            segAlpha = floor(alpha * (1.0 - segRatio))
            segSz = floor(3.0 * (1.0 - segRatio * 0.7))
            if segSz < 1 segSz = 1 ok
            DrawCircle(sx, sy, segSz,
                       RAYLIBColor(fr, fg, fb, segAlpha))
        next

        // Bright head
        DrawCircle(floor(ssX[i]), floor(ssY[i]), 4,
                   RAYLIBColor(255, 255, 255, alpha))
        DrawCircle(floor(ssX[i]), floor(ssY[i]), 7,
                   RAYLIBColor(fr, fg, fb, floor(alpha * 0.4)))
    next

// =============================================================
// Rainbow Title Text
// =============================================================

func dave_drawRainbowTitle title, startX, startY, fontSize
    // First pass: calculate total width from individual characters
    nChars = len(title)
    totalW = 0
    for i = 1 to nChars
        ch = substr(title, i, 1)
        totalW += MeasureText(ch, fontSize)
    next

    // Center based on actual total width
    charX = floor(SCREEN_W / 2 - totalW / 2)

    // Second pass: draw each character
    for i = 1 to nChars
        ch = substr(title, i, 1)
        chW = MeasureText(ch, fontSize)

        // Hue shifts per character and over time
        hue = ((i - 1) * 22 + floor(animTime * 80)) % 360
        rgb = dave_fwColor(hue)

        // Wave bob - each letter bobs up/down slightly
        bob = sin(animTime * 3.0 + (i - 1) * 0.4) * 4.0
        cy = startY + floor(bob)

        // Glow behind letter
        glowAlpha = floor(sin(animTime * 2.0 + i * 0.3) * 30 + 50)
        DrawText(ch, charX + 2, cy + 2, fontSize,
                 RAYLIBColor(rgb[1], rgb[2], rgb[3], glowAlpha))

        // Main letter
        DrawText(ch, charX, cy, fontSize,
                 RAYLIBColor(rgb[1], rgb[2], rgb[3], 255))

        charX += chW
    next

// =============================================================
// Title Screen Dave - Running and Jumping Silhouette
// =============================================================

func dave_updateTitleDave dt
    groundY = SCREEN_H - 60

    // Move Dave across screen
    speed = 120.0
    titleDaveX += speed * titleDaveDir * dt
    titleDaveFrame += dt * 8.0

    // Random jump
    titleDaveJumpTimer += dt
    if titleDaveOnGround and titleDaveJumpTimer > 2.0
        titleDaveJumpV = -350.0
        titleDaveOnGround = false
        titleDaveJumpTimer = 0.0
    ok

    // Gravity
    if !titleDaveOnGround
        titleDaveJumpY += titleDaveJumpV * dt
        titleDaveJumpV += 800.0 * dt
        if titleDaveJumpY >= 0
            titleDaveJumpY = 0
            titleDaveOnGround = true
            titleDaveJumpV = 0
        ok
    ok

    // Wrap around edges
    if titleDaveX > SCREEN_W + 50
        titleDaveX = -50.0
    ok
    if titleDaveX < -50
        titleDaveX = SCREEN_W + 50.0
    ok

func dave_drawTitleDave
    groundY = SCREEN_H - 60
    dx = floor(titleDaveX)
    dy = floor(groundY + titleDaveJumpY)

    // Ground line
    DrawRectangle(0, SCREEN_H - 35, SCREEN_W, 2, RAYLIBColor(60, 60, 60, 100))

    // Legs animation
    legSwing = sin(titleDaveFrame) * 6
    if !titleDaveOnGround legSwing = -4 ok

    // Left leg
    DrawRectangle(dx - 5, dy + 12, 4, 12 + floor(legSwing),
                  RAYLIBColor(50, 50, 180, 255))
    // Right leg
    DrawRectangle(dx + 2, dy + 12, 4, 12 - floor(legSwing),
                  RAYLIBColor(50, 50, 180, 255))

    // Body
    DrawRectangle(dx - 6, dy, 13, 14, RAYLIBColor(220, 40, 40, 255))

    // Arms swinging
    armSwing = sin(titleDaveFrame + 1.57) * 5
    DrawRectangle(dx - 10, dy + 2 + floor(armSwing), 5, 4,
                  RAYLIBColor(255, 200, 150, 255))
    DrawRectangle(dx + 7, dy + 2 - floor(armSwing), 5, 4,
                  RAYLIBColor(255, 200, 150, 255))

    // Head
    DrawCircle(dx + 1, dy - 5, 8, RAYLIBColor(255, 200, 150, 255))

    // Hat (red cap)
    DrawRectangle(dx - 9, dy - 14, 20, 5, RAYLIBColor(220, 40, 40, 255))
    DrawRectangle(dx - 6, dy - 10, 14, 3, RAYLIBColor(220, 40, 40, 255))

    // Eyes
    DrawCircle(dx - 2, dy - 5, 1, RAYLIBColor(40, 40, 80, 255))
    DrawCircle(dx + 4, dy - 5, 1, RAYLIBColor(40, 40, 80, 255))

    // Smile
    DrawRectangle(dx - 1, dy - 1, 4, 1, RAYLIBColor(180, 80, 80, 255))
