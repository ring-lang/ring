/*
**  cr_hud.ring - HUD, Title Screen & Overlay Functions
**  Code Rooms 3D
*/

func cr_drawHUD
    // Top bar background
    DrawRectangle(0, 0, SCREEN_W, 80, RAYLIBColor(15, 12, 25, 220))
    DrawRectangle(0, 80, SCREEN_W, 2, RAYLIBColor(80, 60, 140, 255))

    // Room number
    roomStr = "Room " + currentRoom + " / " + roomCount
    DrawText(roomStr, 20, 12, 20, RAYLIBColor(180, 160, 220, 255))

    // Room title
    DrawText(roomTitle, 20, 38, 24, RAYLIBColor(255, 220, 80, 255))

    // Hint: number of blocks to place
    hintStr = "Arrange " + slotCount + " blocks in the correct order"
    DrawText(hintStr, 20, 62, 14, RAYLIBColor(140, 200, 140, 200))

    // Right side - move count and controls
    mvStr = "Moves: " + moveCount
    mvW = MeasureText(mvStr, 18)
    DrawText(mvStr, SCREEN_W - mvW - 20, 12, 18, RAYLIBColor(200, 200, 220, 255))

    ctrlStr = "R:Restart  C:Camera  U:Undo"
    ctrlW = MeasureText(ctrlStr, 14)
    DrawText(ctrlStr, SCREEN_W - ctrlW - 20, 38, 14, RAYLIBColor(140, 140, 160, 200))

    camNames = ["Top-Down", "Angled", "Follow"]
    camStr = "Camera: " + camNames[camMode + 1]
    camSW = MeasureText(camStr, 14)
    DrawText(camStr, SCREEN_W - camSW - 20, 56, 14, RAYLIBColor(120, 160, 200, 200))

    // Bottom: Assembly line status
    cr_drawAssemblyHUD()

    // Block labels overlay (2D projected from 3D)
    cr_drawBlockLabels2D()

// =============================================================
// Assembly Line HUD (bottom bar)
// =============================================================

func cr_drawAssemblyHUD
    barH = 70
    barY = SCREEN_H - barH
    DrawRectangle(0, barY, SCREEN_W, barH, RAYLIBColor(15, 12, 25, 220))
    DrawRectangle(0, barY, SCREEN_W, 2, RAYLIBColor(80, 60, 140, 255))

    DrawText("Assembly Line:", 20, barY + 8, 16, RAYLIBColor(180, 160, 220, 255))

    // Draw slot boxes
    slotW = 80
    slotH = 36
    startX = 20
    sy = barY + 30

    for si = 1 to slotCount
        sx = startX + (si - 1) * (slotW + 6)
        expected = slots[si][3]
        filled = slots[si][4]
        fbi = slots[si][5]

        // Background
        if filled and fbi > 0 and blocks[fbi][3] = expected
            // Correct - green
            DrawRectangle(sx, sy, slotW, slotH, RAYLIBColor(40, 160, 60, 255))
            DrawText(blocks[fbi][3], sx + 4, sy + 10, 16, WHITE)
        but filled and fbi > 0
            // Wrong block - red
            DrawRectangle(sx, sy, slotW, slotH, RAYLIBColor(180, 50, 40, 255))
            DrawText(blocks[fbi][3], sx + 4, sy + 10, 16, WHITE)
        else
            // Empty slot
            DrawRectangle(sx, sy, slotW, slotH, RAYLIBColor(40, 50, 80, 255))
            numStr = "" + si
            DrawText(numStr, sx + slotW/2 - 4, sy + 10, 16, RAYLIBColor(100, 120, 150, 200))
        ok

        // Border
        DrawRectangleLines(sx, sy, slotW, slotH, RAYLIBColor(100, 80, 160, 255))
    next

// =============================================================
// Block Labels as 2D Projected Text
// =============================================================

func cr_drawBlockLabels2D
    for bi = 1 to blockCount
        bx = blocks[bi][4]
        bz = blocks[bi][5]
        label = blocks[bi][3]

        // Manual 3D to 2D projection
        sx = 0
        sy = 0
        cr_project3Dto2D(bx, 1.4, bz)
        sx = projSX
        sy = projSY

        if sx > 0 and sx < SCREEN_W and sy > 0 and sy < SCREEN_H
            tw = MeasureText(label, 18)
            bx2 = sx - tw / 2 - 4
            by2 = sy - 12

            // Background
            DrawRectangle(bx2, by2, tw + 8, 22, RAYLIBColor(20, 15, 30, 200))
            DrawRectangleLines(bx2, by2, tw + 8, 22, RAYLIBColor(140, 120, 180, 200))

            // Text
            DrawText(label, bx2 + 4, by2 + 3, 18, RAYLIBColor(255, 240, 200, 255))
        ok
    next

// =============================================================
// 3D to 2D Projection (manual - struct access workaround)
// =============================================================

func cr_project3Dto2D wx, wy, wz
    // Get camera vectors
    cpx = cam.position.x
    cpy = cam.position.y
    cpz = cam.position.z
    ctx = cam.target.x
    cty = cam.target.y
    ctz = cam.target.z

    // Forward vector
    fx = ctx - cpx
    fy = cty - cpy
    fz = ctz - cpz
    fl = sqrt(fx*fx + fy*fy + fz*fz)
    if fl < 0.001 fl = 0.001 ok
    fx = fx / fl  fy = fy / fl  fz = fz / fl

    // Right vector (cross with up)
    ux = 0  uy = 1  uz = 0
    rx = fy * uz - fz * uy
    ry = fz * ux - fx * uz
    rz = fx * uy - fy * ux
    rl = sqrt(rx*rx + ry*ry + rz*rz)
    if rl < 0.001 rl = 0.001 ok
    rx = rx / rl  ry = ry / rl  rz = rz / rl

    // Recalc up
    ux2 = ry * fz - rz * fy
    uy2 = rz * fx - rx * fz
    uz2 = rx * fy - ry * fx

    // Point relative to camera
    dx = wx - cpx
    dy = wy - cpy
    dz = wz - cpz

    // View coords
    vx = dx * rx + dy * ry + dz * rz
    vy = dx * ux2 + dy * uy2 + dz * uz2
    vz = dx * fx + dy * fy + dz * fz

    if vz < 0.1
        projSX = -1000
        projSY = -1000
        return
    ok

    // Perspective
    fov = cam.fovy
    tanHalf = cr_tan(fov * 0.5 * 3.14159 / 180)
    aspect = SCREEN_W / SCREEN_H

    projSX = floor(SCREEN_W / 2 + (vx / (vz * tanHalf * aspect)) * SCREEN_W / 2)
    projSY = floor(SCREEN_H / 2 - (vy / (vz * tanHalf)) * SCREEN_H / 2)

// =============================================================
// Title Screen
// =============================================================

func cr_drawTitle
    // Blue gradient background
    bands = 20
    bandH = floor(SCREEN_H / bands) + 1
    for b = 0 to bands - 1
        f = b * 1.0 / bands
        r = floor(10 + f * 15)
        g = floor(20 + f * 40)
        bl = floor(80 + f * 100)
        DrawRectangle(0, b * bandH, SCREEN_W, bandH + 1, RAYLIBColor(r, g, bl, 255))
    next

    // Animated twinkling stars
    for tsi = 1 to WS_MAX
        twinkle = sin(animTime * 2.5 + wsPhase[tsi])
        bright = floor(wsBright[tsi] * (0.5 + twinkle * 0.5))
        if bright > 255 bright = 255 ok
        if bright < 10 loop ok
        starSz = 2
        if wsBright[tsi] > 180 starSz = 3 ok
        if wsBright[tsi] > 230 starSz = 4 ok
        DrawCircle(wsX[tsi], wsY[tsi], starSz, RAYLIBColor(255, 255, 255, bright))
        // Bright stars get a cross sparkle
        if bright > 100
            spkLen = starSz + floor(bright / 60)
            DrawLine(wsX[tsi] - spkLen, wsY[tsi], wsX[tsi] + spkLen, wsY[tsi], RAYLIBColor(255, 255, 255, floor(bright * 0.5)))
            DrawLine(wsX[tsi], wsY[tsi] - spkLen, wsX[tsi], wsY[tsi] + spkLen, RAYLIBColor(255, 255, 255, floor(bright * 0.5)))
        ok
        // Glow halo for biggest stars
        if starSz >= 4
            DrawCircle(wsX[tsi], wsY[tsi], starSz + 4, RAYLIBColor(200, 220, 255, floor(bright * 0.15)))
        ok
    next

    // Title - sine wave animated per character (centered)
    t1 = "CODE ROOMS 3D"
    titleSz = 120
    t1Len = len(t1)
    // Measure total width accounting for per-character rendering
    totalW = 0
    for ci = 1 to t1Len
        totalW += MeasureText(substr(t1, ci, 1), titleSz)
    next
    charX = (SCREEN_W - totalW) / 2
    titleY = floor(SCREEN_H * 0.04)
    for ci = 1 to t1Len
        ch = substr(t1, ci, 1)
        chW = MeasureText(ch, titleSz)
        waveY = floor(sin(animTime * 3 + ci * 0.5) * 20)
        // Glow
        DrawText(ch, charX + 3, titleY + 3 + waveY, titleSz, RAYLIBColor(255, 220, 60, 80))
        // Letter with color shift
        hue = floor((animTime * 40 + ci * 20) % 60)
        DrawText(ch, charX, titleY + waveY, titleSz, RAYLIBColor(255, 235 + hue/3, 200 + hue, 255))
        charX += chW
    next

    // Calculate vertical centering zone
    // Title bottom edge
    titleBottom = titleY + titleSz + 25
    // Start prompt top edge
    promptY = SCREEN_H - 140
    // Content: subtitle(52) + gap(20) + 11 lines * 40 = ~512
    subSz = 52
    bodySz = 30
    lineH = 40
    contentH = subSz + 20 + 13 * lineH
    // Center content in the gap
    midZone = titleBottom + (promptY - titleBottom - contentH) / 2

    // Subtitle - yellow
    t2 = "Programming Puzzle Game"
    t2w = MeasureText(t2, subSz)
    DrawText(t2, (SCREEN_W - t2w) / 2, midZone, subSz, RAYLIBColor(255, 220, 60, 255))

    // Description
    lines = [
        "You are trapped in a world of rooms!",
        "Each room has a programming puzzle to solve.",
        "",
        "Push the code blocks onto the assembly line",
        "in the correct order to form a valid program.",
        "When the code is correct, the door opens!",
        "",
        "Controls:",
        "Arrow Keys / WASD - Move & Push Blocks",
        "U - Undo Last Move    R - Restart Room",
        "N / Page Down - Next Level",
        "P / Page Up - Previous Level",
        "C - Cycle Camera View"
    ]

    cy = midZone + subSz + 20
    linesLen = len(lines)
    for i = 1 to linesLen
        if i = 8
            // "Controls:" in yellow
            col = RAYLIBColor(255, 220, 60, 240)
        but i >= 9
            // Control keys in silver
            col = RAYLIBColor(200, 205, 215, 230)
        but i <= 2
            // Story text in white
            col = RAYLIBColor(240, 245, 255, 240)
        else
            // Other text in silver
            col = RAYLIBColor(190, 195, 210, 220)
        ok
        lw = MeasureText(lines[i], bodySz)
        DrawText(lines[i], (SCREEN_W - lw) / 2, cy + (i - 1) * lineH, bodySz, col)
    next

    // Blinking start prompt - white
    if floor(animTime * 2) % 2 = 0
        st = "Press ENTER or SPACE to Start"
        startSz = 48
        stw = MeasureText(st, startSz)
        DrawText(st, (SCREEN_W - stw) / 2, promptY, startSz, RAYLIBColor(255, 255, 255, 255))
    ok

    // Credit - silver
    cr2 = "Developed using Ring Language + RingRayLib"
    credSz = 24
    crw = MeasureText(cr2, credSz)
    DrawText(cr2, (SCREEN_W - crw) / 2, SCREEN_H - 55, credSz, RAYLIBColor(170, 175, 190, 200))

// =============================================================
// Solved Overlay
// =============================================================

func cr_drawSolvedOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 80))

    t1 = "PUZZLE SOLVED!"
    t1w = MeasureText(t1, 48)
    DrawText(t1, (SCREEN_W - t1w) / 2, SCREEN_H / 2 - 60, 48,
             RAYLIBColor(50, 255, 80, 255))

    t2 = "Door is opening..."
    t2w = MeasureText(t2, 22)
    DrawText(t2, (SCREEN_W - t2w) / 2, SCREEN_H / 2, 22,
             RAYLIBColor(200, 220, 255, 255))

// =============================================================
// Win Screen
// =============================================================

func cr_drawWinScreen
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 160))

    t1 = "CONGRATULATIONS!"
    t1w = MeasureText(t1, 52)
    DrawText(t1, (SCREEN_W - t1w) / 2, SCREEN_H / 2 - 100, 52,
             RAYLIBColor(255, 215, 0, 255))

    t2 = "You escaped all " + roomCount + " rooms!"
    t2w = MeasureText(t2, 28)
    DrawText(t2, (SCREEN_W - t2w) / 2, SCREEN_H / 2 - 30, 28,
             RAYLIBColor(200, 220, 255, 255))

    t3 = "Total Moves: " + moveCount
    t3w = MeasureText(t3, 22)
    DrawText(t3, (SCREEN_W - t3w) / 2, SCREEN_H / 2 + 20, 22,
             RAYLIBColor(180, 200, 220, 255))

    t4 = "A true programmer escapes any trap!"
    t4w = MeasureText(t4, 20)
    DrawText(t4, (SCREEN_W - t4w) / 2, SCREEN_H / 2 + 70, 20,
             RAYLIBColor(255, 220, 80, 220))

    cr2 = "Developed using Ring Language + RingRayLib"
    crw = MeasureText(cr2, 14)
    DrawText(cr2, (SCREEN_W - crw) / 2, SCREEN_H - 40, 14,
             RAYLIBColor(100, 100, 120, 180))

