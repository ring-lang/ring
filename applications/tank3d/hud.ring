/*
**  tank3d_hud.ring
**  HUD, minimap, and game state overlays (title, pause, game over, victory, level up)
*/

// =============================================================
// HUD
// =============================================================

func tank_drawHUD
    // Top bar background
    DrawRectangle(0, 0, SCREEN_W, 55, RAYLIBColor(0, 0, 0, 210))
    DrawRectangle(0, 55, SCREEN_W, 2, RAYLIBColor(200, 160, 40, 255))

    // Left section: Score & High Score
    DrawText("SCORE", 15, 4, 12, RAYLIBColor(160, 160, 160, 200))
    DrawText(string(score), 15, 18, 22, RAYLIBColor(255, 255, 255, 255))
    if highScore > 0
        DrawText("HI:" + string(highScore), 15, 40, 12, RAYLIBColor(200, 180, 80, 180))
    ok

    // Center: Stage + Level Name
    levelNames = ["Boot Camp", "Steel Intro", "Wetlands", "BOSS: Fortress",
                  "Iron Curtain", "Inferno", "Swamp Ambush", "BOSS: Frozen Fort",
                  "The Labyrinth", "Volcanic Core", "Steel Gauntlet", "BOSS: Final Assault"]
    stgTxt = "STAGE " + string(level)
    stgW = MeasureText(stgTxt, 22)
    isBoss = (level = 4 or level = 8 or level = 12)
    stgClr = RAYLIBColor(255, 220, 50, 255)
    if isBoss stgClr = RAYLIBColor(255, 60, 60, 255) ok
    DrawText(stgTxt, floor(SCREEN_W/2 - stgW/2), 6, 22, stgClr)
    if level >= 1 and level <= 12
        lvlName = levelNames[level]
        lnW = MeasureText(lvlName, 14)
        DrawText(lvlName, floor(SCREEN_W/2 - lnW/2), 28, 14,
                 RAYLIBColor(200, 200, 200, 200))
    ok

    // Enemies remaining
    total = enemiesLeft
    nEnemies = len(enemies)
    for e = 1 to nEnemies
        if enemies[e][5] total += 1 ok
    next
    enTxt = "Enemies: " + string(total)
    enW = MeasureText(enTxt, 12)
    DrawText(enTxt, floor(SCREEN_W/2 - enW/2), 42, 12,
             RAYLIBColor(255, 100, 80, 220))

    // Right section: Lives
    DrawText("LIVES", SCREEN_W - 170, 6, 14, RAYLIBColor(160, 160, 160, 200))
    for i = 1 to lives
        lx = SCREEN_W - 170 + (i - 1) * 30
        DrawRectangle(lx, 28, 20, 12, RAYLIBColor(180, 160, 40, 255))
        DrawRectangle(lx + 6, 22, 8, 8, RAYLIBColor(160, 140, 30, 255))
        DrawRectangle(lx + 8, 18, 4, 6, RAYLIBColor(140, 120, 25, 255))
    next

    // Power-up indicators
    indY = SCREEN_H - 80
    if pshield > 0
        DrawText("[SHIELD " + string(floor(pshield)) + "s]", 15, indY, 18,
                 RAYLIBColor(100, 180, 255, 255))
        indY -= 22
    ok
    if pspeedBoost > 0
        DrawText("[SPEED " + string(floor(pspeedBoost)) + "s]", 15, indY, 18,
                 RAYLIBColor(255, 220, 50, 255))
        indY -= 22
    ok
    if globalFreezeTimer > 0
        DrawText("[FREEZE " + string(floor(globalFreezeTimer)) + "s]", 15, indY, 18,
                 RAYLIBColor(50, 220, 255, 255))
    ok

    // Combo display
    if comboDisplayTimer > 0
        cAlpha = floor((comboDisplayTimer / 2.0) * 255)
        if cAlpha > 255 cAlpha = 255 ok
        cW = MeasureText(lastComboText, 30)
        DrawText(lastComboText, floor(SCREEN_W/2 - cW/2), 90, 30,
                 RAYLIBColor(255, 200, 50, cAlpha))
    ok

    // Bottom bar
    camNames = ["Top", "Angle", "Close"]
    camText = "Cam: " + camNames[camMode + 1] + " [C]"
    DrawText(camText, SCREEN_W - 160, SCREEN_H - 28, 16,
             RAYLIBColor(180, 180, 180, 180))

    DrawText("Move:WASD | Fire:Space | P:Pause | R:Restart | N/B:Level",
             floor(SCREEN_W/2 - 260), SCREEN_H - 28, 14,
             RAYLIBColor(140, 140, 140, 150))

    // State overlays
    if gameState = ST_TITLE
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 210))
        title = "3D TANK BATTLE"
        DrawText(title, floor(SCREEN_W/2 - MeasureText(title, 52) / 2),
                 floor(SCREEN_H/2 - 110), 52, RAYLIBColor(200, 160, 40, 255))
        sub0 = "- Ultimate Edition -"
        DrawText(sub0, floor(SCREEN_W/2 - MeasureText(sub0, 20) / 2),
                 floor(SCREEN_H/2 - 55), 20, RAYLIBColor(255, 100, 50, 255))
        sub = "12 Stages - Boss Battles - 6 Enemy Types"
        DrawText(sub, floor(SCREEN_W/2 - MeasureText(sub, 18) / 2),
                 floor(SCREEN_H/2 - 25), 18, RAYLIBColor(200, 200, 200, 255))
        start = "Press ENTER or SPACE to Start"
        pulse = floor(sin(animTime * 3.0) * 60 + 195)
        DrawText(start, floor(SCREEN_W/2 - MeasureText(start, 24) / 2),
                 floor(SCREEN_H/2 + 15), 24, RAYLIBColor(255, 255, 255, pulse))

        // Power-up legend
        DrawText("Power-ups: Star=Speed  Shield=Guard  Bomb=Nuke  Freeze=Stop  Life=+1",
                 floor(SCREEN_W/2 - 290), floor(SCREEN_H/2 + 65), 16,
                 RAYLIBColor(150, 150, 150, 200))
        if highScore > 0
            hsTxt = "High Score: " + string(highScore)
            DrawText(hsTxt, floor(SCREEN_W/2 - MeasureText(hsTxt, 18) / 2),
                     floor(SCREEN_H/2 + 95), 18, RAYLIBColor(255, 200, 80, 200))
        ok
    ok

    if gameState = ST_PAUSED
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 160))
        pTxt = "PAUSED"
        DrawText(pTxt, floor(SCREEN_W/2 - MeasureText(pTxt, 48) / 2),
                 floor(SCREEN_H/2 - 24), 48, RAYLIBColor(255, 255, 255, 255))
    ok

    if gameState = ST_GAMEOVER
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 200))
        goTxt = "GAME OVER"
        DrawText(goTxt, floor(SCREEN_W/2 - MeasureText(goTxt, 52) / 2),
                 floor(SCREEN_H/2 - 70), 52, RAYLIBColor(255, 40, 40, 255))
        sTxt = "Final Score: " + string(score)
        DrawText(sTxt, floor(SCREEN_W/2 - MeasureText(sTxt, 26) / 2),
                 floor(SCREEN_H/2 - 10), 26, RAYLIBColor(255, 200, 100, 255))
        // Stats
        statTxt = "Kills: " + string(totalKills) + "  |  Shots: " + string(totalShotsFired)
        DrawText(statTxt, floor(SCREEN_W/2 - MeasureText(statTxt, 16) / 2),
                 floor(SCREEN_H/2 + 25), 16, RAYLIBColor(180, 180, 180, 200))
        if totalShotsFired > 0
            acc = floor((accuracyHits * 100) / totalShotsFired)
            accTxt = "Accuracy: " + string(acc) + "%"
            DrawText(accTxt, floor(SCREEN_W/2 - MeasureText(accTxt, 16) / 2),
                     floor(SCREEN_H/2 + 45), 16, RAYLIBColor(180, 180, 180, 200))
        ok
        DrawText("Press ENTER to Return",
                 floor(SCREEN_W/2 - 110), floor(SCREEN_H/2 + 75), 20,
                 RAYLIBColor(200, 200, 200, 200))
    ok

    if gameState = ST_WON
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 200))
        wTxt = "VICTORY!"
        DrawText(wTxt, floor(SCREEN_W/2 - MeasureText(wTxt, 56) / 2),
                 floor(SCREEN_H/2 - 80), 56, RAYLIBColor(255, 220, 50, 255))
        sTxt2 = "Final Score: " + string(score)
        DrawText(sTxt2, floor(SCREEN_W/2 - MeasureText(sTxt2, 28) / 2),
                 floor(SCREEN_H/2 - 15), 28, RAYLIBColor(255, 255, 200, 255))
        DrawText("All 12 stages cleared!",
                 floor(SCREEN_W/2 - 100), floor(SCREEN_H/2 + 20), 22,
                 RAYLIBColor(200, 200, 200, 220))
        // Stats
        statTxt = "Total Kills: " + string(totalKills) + "  |  Shots Fired: " + string(totalShotsFired)
        DrawText(statTxt, floor(SCREEN_W/2 - MeasureText(statTxt, 16) / 2),
                 floor(SCREEN_H/2 + 55), 16, RAYLIBColor(180, 180, 180, 200))
        if totalShotsFired > 0
            acc = floor((accuracyHits * 100) / totalShotsFired)
            accTxt = "Accuracy: " + string(acc) + "%"
            DrawText(accTxt, floor(SCREEN_W/2 - MeasureText(accTxt, 16) / 2),
                     floor(SCREEN_H/2 + 75), 16, RAYLIBColor(180, 180, 180, 200))
        ok
        if score > highScore highScore = score ok
        DrawText("Press ENTER to Return",
                 floor(SCREEN_W/2 - 110), floor(SCREEN_H/2 + 105), 20,
                 RAYLIBColor(180, 180, 180, 180))
    ok

    if gameState = ST_LEVELUP
        prog = 1.0 - (levelUpTimer / 2.5)
        alpha = floor(prog * 255)
        if alpha > 255 alpha = 255 ok
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, floor(alpha * 0.6)))
        lTxt = "STAGE " + string(level) + " CLEAR!"
        DrawText(lTxt, floor(SCREEN_W/2 - MeasureText(lTxt, 44) / 2),
                 floor(SCREEN_H/2 - 35), 44, RAYLIBColor(255, 220, 50, alpha))
        bonusTxt = "Bonus: +" + string(500 + (level - 1) * 100)
        DrawText(bonusTxt, floor(SCREEN_W/2 - MeasureText(bonusTxt, 20) / 2),
                 floor(SCREEN_H/2 + 15), 20, RAYLIBColor(200, 200, 200, alpha))
        if level < maxLevel
            nextIsBoss = (level + 1 = 4 or level + 1 = 8 or level + 1 = 12)
            if nextIsBoss
                warnTxt = "!! BOSS BATTLE APPROACHING !!"
                wPulse = floor(sin(animTime * 5.0) * 80 + 175)
                DrawText(warnTxt, floor(SCREEN_W/2 - MeasureText(warnTxt, 22) / 2),
                         floor(SCREEN_H/2 + 45), 22, RAYLIBColor(255, 50, 50, wPulse))
            ok
        ok
    ok

    // FPS
    // DrawFPS(SCREEN_W - 80, 50)

// =============================================================
// Minimap
// =============================================================

func tank_drawMinimap
    // Minimap size and position (bottom-right corner)
    mmSize = 5      // Pixels per cell
    mmW = GRID_W * mmSize
    mmH = GRID_H * mmSize
    mmX = SCREEN_W - mmW - 12
    mmY = SCREEN_H - mmH - 35

    // Background with border
    DrawRectangle(mmX - 2, mmY - 2, mmW + 4, mmH + 4,
                  RAYLIBColor(200, 160, 40, 200))
    DrawRectangle(mmX, mmY, mmW, mmH,
                  RAYLIBColor(0, 0, 0, 220))

    // Draw tiles
    for r = 1 to GRID_H
        for c = 1 to GRID_W
            t = tiles[r][c]
            tx = mmX + (c - 1) * mmSize
            ty = mmY + (r - 1) * mmSize

            if t = T_BRICK
                DrawRectangle(tx, ty, mmSize, mmSize,
                              RAYLIBColor(180, 100, 30, 255))
            ok
            if t = T_STEEL
                DrawRectangle(tx, ty, mmSize, mmSize,
                              RAYLIBColor(170, 170, 180, 255))
            ok
            if t = T_WATER
                DrawRectangle(tx, ty, mmSize, mmSize,
                              RAYLIBColor(30, 70, 160, 255))
            ok
            if t = T_TREES
                DrawRectangle(tx, ty, mmSize, mmSize,
                              RAYLIBColor(20, 100, 30, 255))
            ok
            if t = T_ICE
                DrawRectangle(tx, ty, mmSize, mmSize,
                              RAYLIBColor(150, 200, 240, 255))
            ok
            if t = T_BASE
                DrawRectangle(tx, ty, mmSize, mmSize,
                              RAYLIBColor(255, 220, 50, 255))
            ok
            if t = T_BASEDEAD
                DrawRectangle(tx, ty, mmSize, mmSize,
                              RAYLIBColor(80, 40, 20, 255))
            ok
            if t = T_LAVA
                DrawRectangle(tx, ty, mmSize, mmSize,
                              RAYLIBColor(220, 80, 10, 255))
            ok
        next
    next

    // Draw player on minimap
    if palive
        // Convert py to grid row directly
        pGridR = floor(py + 0.5)
        pGridC = floor(px + 0.5)
        pmx = mmX + (pGridC - 1) * mmSize
        pmy = mmY + (pGridR - 1) * mmSize
        // Player dot - yellow with flashing
        flash = floor(sin(animTime * 6.0) * 40 + 215)
        DrawRectangle(pmx - 1, pmy - 1, mmSize + 2, mmSize + 2,
                      RAYLIBColor(255, 255, 50, flash))
    ok

    // Draw enemies on minimap
    nEnemies = len(enemies)
    for e = 1 to nEnemies
        if enemies[e][5]
            eGridR = floor(enemies[e][2] + 0.5)
            eGridC = floor(enemies[e][1] + 0.5)
            if eGridR >= 1 and eGridR <= GRID_H and eGridC >= 1 and eGridC <= GRID_W
                emx = mmX + (eGridC - 1) * mmSize
                emy = mmY + (eGridR - 1) * mmSize
                DrawRectangle(emx, emy, mmSize, mmSize,
                              RAYLIBColor(255, 50, 50, 230))
            ok
        ok
    next

    // Draw player bullets
    nPB = len(pbullets)
    for i = 1 to nPB
        if pbullets[i][1]
            bGridR = floor(pbullets[i][3] + 0.5)
            bGridC = floor(pbullets[i][2] + 0.5)
            if bGridR >= 1 and bGridR <= GRID_H and bGridC >= 1 and bGridC <= GRID_W
                bbx = mmX + (bGridC - 1) * mmSize + floor(mmSize / 2)
                bby = mmY + (bGridR - 1) * mmSize + floor(mmSize / 2)
                DrawCircle(bbx, bby, 2, RAYLIBColor(255, 255, 150, 255))
            ok
        ok
    next

    // Draw powerups
    nPU = len(powerups)
    for i = 1 to nPU
        if powerups[i][5]
            puGridR = floor(powerups[i][2] + 0.5)
            puGridC = floor(powerups[i][1] + 0.5)
            if puGridR >= 1 and puGridR <= GRID_H and puGridC >= 1 and puGridC <= GRID_W
                pux = mmX + (puGridC - 1) * mmSize
                puy = mmY + (puGridR - 1) * mmSize
                flash2 = floor(sin(animTime * 5.0) * 80 + 175)
                DrawRectangle(pux, puy, mmSize, mmSize,
                              RAYLIBColor(50, 255, 50, flash2))
            ok
        ok
    next

    // Minimap label
    DrawText("MAP", mmX + mmW / 2 - 12, mmY - 14, 12,
             RAYLIBColor(200, 200, 200, 200))
