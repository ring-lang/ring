/*
**  cr_drawing.ring - 3D Drawing Functions
**  Code Rooms 3D
**  Floor, walls, slots, blocks, door, player, particles
*/

func cr_drawFloor
    // Dark void beneath the floor - gives floating island feel
    gx = (GRID_W + 1) / 2.0 * CELL
    gz = (GRID_H + 1) / 2.0 * CELL

    // Purple-blue void/water beneath
    vr = 45  vg = 35  vb = 75
    if currentWeather = W_RAIN   vr = 35  vg = 40  vb = 90  ok
    if currentWeather = W_STORM  vr = 25  vg = 20  vb = 65  ok
    if currentWeather = W_SNOW   vr = 70  vg = 75  vb = 100 ok
    if currentWeather = W_FOG    vr = 60  vg = 62  vb = 80  ok
    DrawCube(Vector3(gx, -0.5, gz), GRID_W * CELL + 6, 0.6, GRID_H * CELL + 6,
             RAYLIBColor(vr, vg, vb, 180))

    for row = 1 to GRID_H
        for col = 1 to GRID_W
            t = tiles[row][col]
            wx = col * CELL
            wz = row * CELL

            if t != T_WALL and t != T_EMPTY
                // Per-tile color variation
                seed = (row * 7 + col * 13) % 6
                vari = seed * 4 - 10

                tr = 165 + vari
                tg = 155 + vari
                tb = 185 + vari

                // Weather tinting
                if currentWeather = W_RAIN   tr -= 15  tg -= 5   tb += 15  ok
                if currentWeather = W_STORM  tr -= 25  tg -= 20  tb += 5   ok
                if currentWeather = W_SNOW   tr += 15  tg += 15  tb += 10  ok
                if currentWeather = W_FOG    tr += 5   tg += 5   tb += 5   ok

                // Thick stone slab
                DrawCube(Vector3(wx, 0.0, wz), 1.92, 0.20, 1.92,
                         RAYLIBColor(tr, tg, tb, 250))

                // Side depth - darker
                DrawCube(Vector3(wx, -0.08, wz), 1.96, 0.06, 1.96,
                         RAYLIBColor(tr - 40, tg - 40, tb - 30, 250))

                // Top edge highlight (one cube - north-west edge catch light)
                DrawCube(Vector3(wx - 0.90, 0.105, wz), 0.04, 0.01, 1.84,
                         RAYLIBColor(tr + 25, tg + 25, tb + 20, 140))

                // Grout gap - two cubes only (east + south edges)
                DrawCube(Vector3(wx + 0.97, 0.03, wz), 0.06, 0.16, 1.96,
                         RAYLIBColor(80, 65, 95, 200))
                DrawCube(Vector3(wx, 0.03, wz + 0.97), 1.96, 0.16, 0.06,
                         RAYLIBColor(80, 65, 95, 200))
            ok
        next
    next

// =============================================================
// 3D Drawing: Walls
// =============================================================

func cr_drawWalls
    for row = 1 to GRID_H
        for col = 1 to GRID_W
            if tiles[row][col] = T_WALL
                wx = col * CELL
                wz = row * CELL

                // Per-block variation
                seed = (row * 11 + col * 7) % 8
                vari = seed * 3 - 12

                // Base wall colors - warm stone
                wr = 140 + vari
                wg = 105 + vari
                wb = 125 + vari

                // Weather tinting
                if currentWeather = W_RAIN   wr -= 15  wg -= 10  wb += 10  ok
                if currentWeather = W_STORM  wr -= 25  wg -= 20  wb += 5   ok
                if currentWeather = W_SNOW   wr += 15  wg += 18  wb += 20  ok
                if currentWeather = W_FOG    wr += 8   wg += 8   wb += 8   ok

                // Check neighbors for edge detection
                hasFloorN = 0  hasFloorS = 0  hasFloorE = 0  hasFloorW = 0
                if row > 1
                    if tiles[row-1][col] != T_WALL and tiles[row-1][col] != T_EMPTY hasFloorN = 1 ok
                ok
                if row < GRID_H
                    if tiles[row+1][col] != T_WALL and tiles[row+1][col] != T_EMPTY hasFloorS = 1 ok
                ok
                if col < GRID_W
                    if tiles[row][col+1] != T_WALL and tiles[row][col+1] != T_EMPTY hasFloorE = 1 ok
                ok
                if col > 1
                    if tiles[row][col-1] != T_WALL and tiles[row][col-1] != T_EMPTY hasFloorW = 1 ok
                ok

                isEdge = hasFloorN + hasFloorS + hasFloorE + hasFloorW

                // === MAIN WALL BODY ===
                // Lower foundation - darker, thicker
                DrawCube(Vector3(wx, WALL_H * 0.3, wz), 2.0, WALL_H * 0.6, 2.0,
                         RAYLIBColor(wr - 30, wg - 30, wb - 25, 255))

                // Upper wall - slightly lighter
                DrawCube(Vector3(wx, WALL_H * 0.75, wz), 1.96, WALL_H * 0.5, 1.96,
                         RAYLIBColor(wr, wg, wb, 255))

                // === STONE BLOCK PATTERN (horizontal mortar lines) ===
                // Three rows of mortar lines on visible faces
                mortR = wr - 50
                mortG = wg - 40
                mortB = wb - 40
                if mortR < 0 mortR = 0 ok
                if mortG < 0 mortG = 0 ok
                if mortB < 0 mortB = 0 ok

                if hasFloorS = 1
                    // South face mortar
                    DrawCube(Vector3(wx, WALL_H * 0.25, wz + 1.01), 1.96, 0.04, 0.01,
                             RAYLIBColor(mortR, mortG, mortB, 180))
                    DrawCube(Vector3(wx, WALL_H * 0.50, wz + 1.01), 1.96, 0.04, 0.01,
                             RAYLIBColor(mortR, mortG, mortB, 180))
                    DrawCube(Vector3(wx, WALL_H * 0.75, wz + 1.01), 1.96, 0.04, 0.01,
                             RAYLIBColor(mortR, mortG, mortB, 180))
                    // Vertical mortar - offset per row
                    DrawCube(Vector3(wx - 0.35, WALL_H * 0.375, wz + 1.01), 0.03, WALL_H * 0.25, 0.01,
                             RAYLIBColor(mortR, mortG, mortB, 150))
                    DrawCube(Vector3(wx + 0.35, WALL_H * 0.375, wz + 1.01), 0.03, WALL_H * 0.25, 0.01,
                             RAYLIBColor(mortR, mortG, mortB, 150))
                    DrawCube(Vector3(wx, WALL_H * 0.625, wz + 1.01), 0.03, WALL_H * 0.25, 0.01,
                             RAYLIBColor(mortR, mortG, mortB, 150))
                ok

                if hasFloorN = 1
                    // North face mortar
                    DrawCube(Vector3(wx, WALL_H * 0.25, wz - 1.01), 1.96, 0.04, 0.01,
                             RAYLIBColor(mortR, mortG, mortB, 180))
                    DrawCube(Vector3(wx, WALL_H * 0.50, wz - 1.01), 1.96, 0.04, 0.01,
                             RAYLIBColor(mortR, mortG, mortB, 180))
                    DrawCube(Vector3(wx, WALL_H * 0.75, wz - 1.01), 1.96, 0.04, 0.01,
                             RAYLIBColor(mortR, mortG, mortB, 180))
                    DrawCube(Vector3(wx + 0.3, WALL_H * 0.375, wz - 1.01), 0.03, WALL_H * 0.25, 0.01,
                             RAYLIBColor(mortR, mortG, mortB, 150))
                    DrawCube(Vector3(wx - 0.3, WALL_H * 0.625, wz - 1.01), 0.03, WALL_H * 0.25, 0.01,
                             RAYLIBColor(mortR, mortG, mortB, 150))
                ok

                if hasFloorE = 1
                    // East face mortar
                    DrawCube(Vector3(wx + 1.01, WALL_H * 0.25, wz), 0.01, 0.04, 1.96,
                             RAYLIBColor(mortR, mortG, mortB, 180))
                    DrawCube(Vector3(wx + 1.01, WALL_H * 0.50, wz), 0.01, 0.04, 1.96,
                             RAYLIBColor(mortR, mortG, mortB, 180))
                    DrawCube(Vector3(wx + 1.01, WALL_H * 0.75, wz), 0.01, 0.04, 1.96,
                             RAYLIBColor(mortR, mortG, mortB, 180))
                ok

                if hasFloorW = 1
                    // West face mortar
                    DrawCube(Vector3(wx - 1.01, WALL_H * 0.25, wz), 0.01, 0.04, 1.96,
                             RAYLIBColor(mortR, mortG, mortB, 180))
                    DrawCube(Vector3(wx - 1.01, WALL_H * 0.50, wz), 0.01, 0.04, 1.96,
                             RAYLIBColor(mortR, mortG, mortB, 180))
                    DrawCube(Vector3(wx - 1.01, WALL_H * 0.75, wz), 0.01, 0.04, 1.96,
                             RAYLIBColor(mortR, mortG, mortB, 180))
                ok

                // === TOP CAP - Layered stone capstone ===
                // Wide capstone
                DrawCube(Vector3(wx, WALL_H + 0.06, wz), 2.08, 0.12, 2.08,
                         RAYLIBColor(wr + 15, wg + 15, wb + 10, 255))
                // Top highlight strip
                DrawCube(Vector3(wx, WALL_H + 0.13, wz), 1.90, 0.02, 1.90,
                         RAYLIBColor(wr + 35, wg + 35, wb + 30, 200))

                // === EDGE PILLARS on corners adjacent to floor ===
                if isEdge >= 2
                    // Corner pillar accent
                    pilR = wr + 10
                    pilG = wg + 5
                    pilB = wb + 10
                    if hasFloorS = 1 and hasFloorE = 1
                        DrawCube(Vector3(wx + 0.9, WALL_H * 0.5 + 0.05, wz + 0.9), 0.22, WALL_H + 0.1, 0.22,
                                 RAYLIBColor(pilR, pilG, pilB, 255))
                        DrawCube(Vector3(wx + 0.9, WALL_H + 0.18, wz + 0.9), 0.32, 0.08, 0.32,
                                 RAYLIBColor(pilR + 20, pilG + 20, pilB + 15, 255))
                    ok
                    if hasFloorS = 1 and hasFloorW = 1
                        DrawCube(Vector3(wx - 0.9, WALL_H * 0.5 + 0.05, wz + 0.9), 0.22, WALL_H + 0.1, 0.22,
                                 RAYLIBColor(pilR, pilG, pilB, 255))
                        DrawCube(Vector3(wx - 0.9, WALL_H + 0.18, wz + 0.9), 0.32, 0.08, 0.32,
                                 RAYLIBColor(pilR + 20, pilG + 20, pilB + 15, 255))
                    ok
                    if hasFloorN = 1 and hasFloorE = 1
                        DrawCube(Vector3(wx + 0.9, WALL_H * 0.5 + 0.05, wz - 0.9), 0.22, WALL_H + 0.1, 0.22,
                                 RAYLIBColor(pilR, pilG, pilB, 255))
                        DrawCube(Vector3(wx + 0.9, WALL_H + 0.18, wz - 0.9), 0.32, 0.08, 0.32,
                                 RAYLIBColor(pilR + 20, pilG + 20, pilB + 15, 255))
                    ok
                    if hasFloorN = 1 and hasFloorW = 1
                        DrawCube(Vector3(wx - 0.9, WALL_H * 0.5 + 0.05, wz - 0.9), 0.22, WALL_H + 0.1, 0.22,
                                 RAYLIBColor(pilR, pilG, pilB, 255))
                        DrawCube(Vector3(wx - 0.9, WALL_H + 0.18, wz - 0.9), 0.32, 0.08, 0.32,
                                 RAYLIBColor(pilR + 20, pilG + 20, pilB + 15, 255))
                    ok
                ok

                // === BASE TRIM - foundation ledge ===
                if isEdge > 0
                    DrawCube(Vector3(wx, 0.06, wz), 2.10, 0.12, 2.10,
                             RAYLIBColor(wr - 40, wg - 35, wb - 30, 255))
                ok

                // Subtle wireframe on edge walls only
                if isEdge > 0
                    DrawCubeWires(Vector3(wx, WALL_H/2, wz), 2.0, WALL_H, 2.0,
                                  RAYLIBColor(wr - 55, wg - 50, wb - 45, 80))
                ok
            ok
        next
    next

// =============================================================
// 3D Drawing: Slots (Assembly Line)
// =============================================================

func cr_drawSlots
    for si = 1 to slotCount
        wx = slots[si][1] * CELL
        wz = slots[si][2] * CELL
        expected = slots[si][3]
        filled = slots[si][4]
        fbi = slots[si][5]

        pulse = 0.5 + sin(animTime * 2.5 + si * 0.7) * 0.5

        if filled and fbi > 0 and blocks[fbi][3] = expected
            // Correct block in place - bright green glowing platform
            DrawCube(Vector3(wx, 0.14, wz), 1.92, 0.08, 1.92,
                     RAYLIBColor(40, 180, 60, 255))
            // Green glow halo
            DrawCube(Vector3(wx, 0.11, wz), 2.00, 0.02, 2.00,
                     RAYLIBColor(50, 220, 70, floor(pulse * 100)))
            // Bright border
            DrawCubeWires(Vector3(wx, 0.14, wz), 1.94, 0.10, 1.94,
                          RAYLIBColor(100, 255, 120, 200))
        else
            // Empty or wrong - golden/cyan glowing target platform
            // Recessed dark base
            DrawCube(Vector3(wx, 0.06, wz), 1.92, 0.12, 1.92,
                     RAYLIBColor(30, 50, 80, 255))
            // Glowing golden rim
            DrawCube(Vector3(wx, 0.13, wz + 0.90), 1.80, 0.06, 0.06,
                     RAYLIBColor(220, 180, 50, floor(150 + pulse * 100)))
            DrawCube(Vector3(wx, 0.13, wz - 0.90), 1.80, 0.06, 0.06,
                     RAYLIBColor(220, 180, 50, floor(150 + pulse * 100)))
            DrawCube(Vector3(wx + 0.90, 0.13, wz), 0.06, 0.06, 1.80,
                     RAYLIBColor(220, 180, 50, floor(150 + pulse * 100)))
            DrawCube(Vector3(wx - 0.90, 0.13, wz), 0.06, 0.06, 1.80,
                     RAYLIBColor(220, 180, 50, floor(150 + pulse * 100)))
            // Inner cross guide lines - cyan
            DrawCube(Vector3(wx, 0.12, wz), 1.40, 0.02, 0.04,
                     RAYLIBColor(60, 180, 230, floor(80 + pulse * 70)))
            DrawCube(Vector3(wx, 0.12, wz), 0.04, 0.02, 1.40,
                     RAYLIBColor(60, 180, 230, floor(80 + pulse * 70)))
            // Corner diamonds
            DrawCube(Vector3(wx - 0.80, 0.15, wz - 0.80), 0.20, 0.04, 0.20,
                     RAYLIBColor(230, 200, 60, floor(180 + pulse * 75)))
            DrawCube(Vector3(wx + 0.80, 0.15, wz - 0.80), 0.20, 0.04, 0.20,
                     RAYLIBColor(230, 200, 60, floor(180 + pulse * 75)))
            DrawCube(Vector3(wx - 0.80, 0.15, wz + 0.80), 0.20, 0.04, 0.20,
                     RAYLIBColor(230, 200, 60, floor(180 + pulse * 75)))
            DrawCube(Vector3(wx + 0.80, 0.15, wz + 0.80), 0.20, 0.04, 0.20,
                     RAYLIBColor(230, 200, 60, floor(180 + pulse * 75)))
            // Wireframe border
            DrawCubeWires(Vector3(wx, 0.12, wz), 1.94, 0.14, 1.94,
                          RAYLIBColor(200, 170, 50, 180))
        ok
    next

// =============================================================
// 3D Drawing: Blocks (Code Pieces)
// =============================================================

func cr_drawBlocks
    for bi = 1 to blockCount
        bx = blocks[bi][4]
        bz = blocks[bi][5]
        label = blocks[bi][3]
        placed = blocks[bi][9]

        // Block height and bob
        bh = 0.80
        by = bh / 2 + 0.04
        bob = 0

        if placed = 0
            bob = sin(animTime * 2.0 + bi * 1.3) * 0.04
        ok

        // Block color based on label type
        cr = 180  cg = 120  cb = 60

        // Color-code by type
        lbl = lower(label)
        if lbl = "print" or lbl = "see"
            cr = 220  cg = 80  cb = 60
        ok
        if lbl = "for" or lbl = "while" or lbl = "to" or lbl = "end"
            cr = 80  cg = 140  cb = 220
        ok
        if lbl = "if" or lbl = "ok" or lbl = "else" or lbl = "other"
            cr = 200  cg = 160  cb = 40
        ok
        if lbl = "func" or lbl = "class" or lbl = "return"
            cr = 160  cg = 60  cb = 200
        ok
        if lbl = "try" or lbl = "catch" or lbl = "done"
            cr = 60  cg = 180  cb = 140
        ok
        if lbl = "switch" or lbl = "on" or lbl = "off"
            cr = 180  cg = 100  cb = 180
        ok
        if lbl = "=" or lbl = ">" or lbl = "<" or lbl = "+" or lbl = "-" or lbl = ","
            cr = 150  cg = 150  cb = 160
        ok
        if lbl = "x" or lbl = "x--" or lbl = "sum" or lbl = "list" or lbl = "point"
            cr = 100  cg = 200  cb = 100
        ok
        // Number literals
        if isdigit(lbl)
            cr = 240  cg = 180  cb = 80
        ok

        if placed
            cr = floor(cr * 0.85 + 50 * 0.15)
            cg = floor(cg * 0.85 + 200 * 0.15)
            cb = floor(cb * 0.85 + 80 * 0.15)
        ok

        blockCol = RAYLIBColor(cr, cg, cb, 255)
        darkCol = RAYLIBColor(floor(cr * 0.6), floor(cg * 0.6), floor(cb * 0.6), 255)
        lightCol = RAYLIBColor(floor(cr * 1.2), floor(cg * 1.2), floor(cb * 1.2), 200)

        // Main block body
        DrawCube(Vector3(bx, by + bob, bz), 1.6, bh, 1.6, blockCol)

        // Top face highlight
        DrawCube(Vector3(bx, by + bh/2 + 0.01 + bob, bz), 1.50, 0.02, 1.50, lightCol)

        // Bottom dark edge
        DrawCube(Vector3(bx, 0.05 + bob, bz), 1.62, 0.04, 1.62, darkCol)

        // Wire outline
        DrawCubeWires(Vector3(bx, by + bob, bz), 1.62, bh + 0.02, 1.62,
                      RAYLIBColor(floor(cr * 0.4), floor(cg * 0.4), floor(cb * 0.4), 200))

        // Code symbol on front face (simplified visual indicator)
        // Draw a small colored bar on the front to indicate label
        barW = cr_labelWidth(label)
        DrawCube(Vector3(bx, by + bob, bz + 0.82), barW, 0.25, 0.02,
                 RAYLIBColor(255, 255, 255, 160))

        // Side decorative stripe
        DrawCube(Vector3(bx + 0.82, by + bob, bz), 0.02, bh * 0.6, 1.4,
                 RAYLIBColor(255, 255, 255, 40))
    next

// =============================================================
// Helper: Label width indicator
// =============================================================

func cr_labelWidth label
    ln = len(label)
    w = 0.2 + ln * 0.12
    if w > 1.4 w = 1.4 ok
    return w

// =============================================================
// 3D Drawing: Door
// =============================================================

func cr_drawDoor
    if doorCol = 0 return ok

    wx = doorCol * CELL
    wz = doorRow * CELL

    if doorOpen
        // Open door - green archway
        DrawCube(Vector3(wx - 0.9, WALL_H/2, wz), 0.2, WALL_H, 2.0, colDoorOpen)
        DrawCube(Vector3(wx + 0.9, WALL_H/2, wz), 0.2, WALL_H, 2.0, colDoorOpen)
        DrawCube(Vector3(wx, WALL_H - 0.1, wz), 2.0, 0.2, 2.0, colDoorOpen)

        // Green glow
        pulse = 0.5 + sin(animTime * 3) * 0.5
        DrawCube(Vector3(wx, WALL_H/2, wz), 1.6, WALL_H - 0.4, 0.2,
                 RAYLIBColor(50, 220, 80, floor(pulse * 60)))

        // Arrow on floor pointing through
        DrawCube(Vector3(wx, 0.08, wz), 0.4, 0.04, 1.0,
                 RAYLIBColor(50, 220, 80, 180))
    else
        // Closed door - red/brown
        DrawCube(Vector3(wx, WALL_H/2, wz), 2.0, WALL_H, 2.0, colDoor)

        // Door frame
        DrawCube(Vector3(wx - 0.9, WALL_H/2, wz + 1.01), 0.2, WALL_H, 0.02,
                 RAYLIBColor(120, 90, 40, 255))
        DrawCube(Vector3(wx + 0.9, WALL_H/2, wz + 1.01), 0.2, WALL_H, 0.02,
                 RAYLIBColor(120, 90, 40, 255))
        DrawCube(Vector3(wx, WALL_H - 0.1, wz + 1.01), 2.0, 0.2, 0.02,
                 RAYLIBColor(120, 90, 40, 255))

        // Lock symbol - small yellow cube
        pulse = 0.5 + sin(animTime * 2.5) * 0.5
        DrawCube(Vector3(wx, WALL_H * 0.45, wz + 1.02), 0.25, 0.25, 0.02,
                 RAYLIBColor(220, 180, 40, floor(160 + pulse * 95)))

        // Cross on door (X)
        DrawCube(Vector3(wx, WALL_H * 0.5, wz + 1.02), 1.0, 0.06, 0.01,
                 RAYLIBColor(80, 30, 30, 200))
        DrawCube(Vector3(wx, WALL_H * 0.5, wz + 1.02), 0.06, 1.0, 0.01,
                 RAYLIBColor(80, 30, 30, 200))

        // Wire
        DrawCubeWires(Vector3(wx, WALL_H/2, wz), 2.02, WALL_H + 0.02, 2.02,
                      RAYLIBColor(100, 30, 30, 180))
    ok

// =============================================================
// 3D Drawing: Player
// =============================================================

func cr_drawPlayer
    wx = pAnimX
    wz = pAnimZ
    s = 1.5
    hover = sin(pBobTime * 3) * 0.08 * s
    corePulse = 0.6 + sin(pBobTime * 3.5) * 0.4

    // Direction vectors
    fx = 0.0  fz = 0.0  rx = 0.0  rz = 0.0
    if pDir = 0  fz = -1.0  rx = 1.0  rz = 0.0  ok
    if pDir = 2  fz = 1.0   rx = -1.0 rz = 0.0  ok
    if pDir = 1  fx = 1.0   rx = 0.0  rz = 1.0  ok
    if pDir = 3  fx = -1.0  rx = 0.0  rz = -1.0 ok

    armSwing = sin(pBobTime * 7) * 0.10 * s
    if pMoving = 0 armSwing = 0 ok

    // Sphere offset along right axis
    sOff = 0.32 * s

    // === SHADOW on ground ===
    shAlpha = floor(55 - hover * 80)
    if shAlpha < 15 shAlpha = 15 ok
    DrawCube(Vector3(wx, 0.12, wz), 1.4 * s, 0.02, 1.0 * s,
             RAYLIBColor(15, 10, 30, shAlpha))

    // === LEFT ENERGY SPHERE ===
    lsx = wx + rx * sOff
    lsz = wz + rz * sOff
    sphereY = 0.50 * s + hover
    DrawSphere(Vector3(lsx, sphereY, lsz), 0.36 * s,
               RAYLIBColor(30, 160, 220, floor(100 * corePulse)))
    DrawSphere(Vector3(lsx, sphereY, lsz), 0.26 * s,
               RAYLIBColor(60, 200, 245, floor(160 * corePulse)))
    DrawSphere(Vector3(lsx, sphereY, lsz), 0.14 * s,
               RAYLIBColor(180, 240, 255, floor(200 * corePulse)))
    DrawSphereWires(Vector3(lsx, sphereY, lsz), 0.38 * s, 8, 6,
                    RAYLIBColor(80, 220, 255, floor(50 * corePulse)))

    // === RIGHT ENERGY SPHERE ===
    rsx = wx - rx * sOff
    rsz = wz - rz * sOff
    DrawSphere(Vector3(rsx, sphereY, rsz), 0.36 * s,
               RAYLIBColor(30, 160, 220, floor(100 * corePulse)))
    DrawSphere(Vector3(rsx, sphereY, rsz), 0.26 * s,
               RAYLIBColor(60, 200, 245, floor(160 * corePulse)))
    DrawSphere(Vector3(rsx, sphereY, rsz), 0.14 * s,
               RAYLIBColor(180, 240, 255, floor(200 * corePulse)))
    DrawSphereWires(Vector3(rsx, sphereY, rsz), 0.38 * s, 8, 6,
                    RAYLIBColor(80, 220, 255, floor(50 * corePulse)))

    // Energy rings around each sphere
    ringA = floor(80 + 60 * corePulse)
    DrawCube(Vector3(lsx, sphereY, lsz), 0.84 * s, 0.03, 0.05,
             RAYLIBColor(40, 200, 240, ringA))
    DrawCube(Vector3(lsx, sphereY, lsz), 0.05, 0.03, 0.84 * s,
             RAYLIBColor(40, 200, 240, ringA))
    DrawCube(Vector3(rsx, sphereY, rsz), 0.84 * s, 0.03, 0.05,
             RAYLIBColor(40, 200, 240, ringA))
    DrawCube(Vector3(rsx, sphereY, rsz), 0.05, 0.03, 0.84 * s,
             RAYLIBColor(40, 200, 240, ringA))

    // Ground glow beneath spheres
    glowA = floor(40 * corePulse)
    DrawCube(Vector3(lsx, 0.13, lsz), 0.7 * s, 0.02, 0.7 * s,
             RAYLIBColor(40, 180, 230, glowA))
    DrawCube(Vector3(rsx, 0.13, rsz), 0.7 * s, 0.02, 0.7 * s,
             RAYLIBColor(40, 180, 230, glowA))

    // === AXLE connecting spheres ===
    axleY = sphereY + 0.30 * s
    DrawCube(Vector3(wx, axleY, wz), 0.12 * s, 0.10 * s, 0.10 * s,
             RAYLIBColor(50, 50, 66, 255))
    // Axle bar between spheres
    DrawCube(Vector3(wx, axleY - 0.06 * s, wz), sOff * 2.2, 0.06 * s, 0.06 * s,
             RAYLIBColor(55, 55, 70, 255))
    // Connector glow
    DrawCube(Vector3(wx, axleY - 0.02 * s, wz), 0.30 * s, 0.04 * s, 0.30 * s,
             RAYLIBColor(40, 190, 230, floor(120 * corePulse)))

    // === TORSO (main chassis) ===
    torsoY = axleY + 0.36 * s + hover
    DrawCube(Vector3(wx, torsoY, wz), 0.68 * s, 0.52 * s, 0.46 * s,
             RAYLIBColor(60, 60, 78, 255))
    // Chest plate
    DrawCube(Vector3(wx + fx * 0.24 * s, torsoY + 0.02 * s, wz + fz * 0.24 * s),
             0.54 * s, 0.40 * s, 0.02 * s, RAYLIBColor(80, 80, 98, 255))
    // Glowing chest core
    DrawCube(Vector3(wx + fx * 0.25 * s, torsoY + 0.04 * s, wz + fz * 0.25 * s),
             0.20 * s, 0.20 * s, 0.02 * s, RAYLIBColor(40, 200, 240, floor(180 * corePulse)))
    DrawCube(Vector3(wx + fx * 0.26 * s, torsoY + 0.04 * s, wz + fz * 0.26 * s),
             0.10 * s, 0.10 * s, 0.02 * s, RAYLIBColor(160, 245, 255, floor(220 * corePulse)))
    // Side vents
    DrawCube(Vector3(wx + rx * 0.35 * s, torsoY - 0.06 * s, wz + rz * 0.35 * s),
             0.02 * s, 0.10 * s, 0.22 * s, RAYLIBColor(40, 170, 210, 150))
    DrawCube(Vector3(wx + rx * 0.35 * s, torsoY + 0.06 * s, wz + rz * 0.35 * s),
             0.02 * s, 0.10 * s, 0.22 * s, RAYLIBColor(40, 170, 210, 150))
    DrawCube(Vector3(wx - rx * 0.35 * s, torsoY - 0.06 * s, wz - rz * 0.35 * s),
             0.02 * s, 0.10 * s, 0.22 * s, RAYLIBColor(40, 170, 210, 150))
    DrawCube(Vector3(wx - rx * 0.35 * s, torsoY + 0.06 * s, wz - rz * 0.35 * s),
             0.02 * s, 0.10 * s, 0.22 * s, RAYLIBColor(40, 170, 210, 150))
    // Torso wireframe
    DrawCubeWires(Vector3(wx, torsoY, wz), 0.70 * s, 0.54 * s, 0.48 * s,
                  RAYLIBColor(70, 200, 240, 50))

    // === SHOULDERS ===
    shoulderY = torsoY + 0.24 * s + hover
    DrawCube(Vector3(wx + rx * 0.42 * s, shoulderY, wz + rz * 0.42 * s),
             0.26 * s, 0.16 * s, 0.30 * s, RAYLIBColor(70, 70, 88, 255))
    DrawCube(Vector3(wx + rx * 0.42 * s, shoulderY + 0.06 * s, wz + rz * 0.42 * s),
             0.22 * s, 0.04 * s, 0.26 * s, RAYLIBColor(50, 185, 225, 170))
    DrawCube(Vector3(wx - rx * 0.42 * s, shoulderY, wz - rz * 0.42 * s),
             0.26 * s, 0.16 * s, 0.30 * s, RAYLIBColor(70, 70, 88, 255))
    DrawCube(Vector3(wx - rx * 0.42 * s, shoulderY + 0.06 * s, wz - rz * 0.42 * s),
             0.22 * s, 0.04 * s, 0.26 * s, RAYLIBColor(50, 185, 225, 170))

    // === ARMS ===
    armY = torsoY - 0.04 * s + hover
    // Left arm
    lax = wx + rx * 0.48 * s
    laz = wz + rz * 0.48 * s
    DrawCube(Vector3(lax + fx * armSwing, armY, laz + fz * armSwing),
             0.14 * s, 0.36 * s, 0.14 * s, RAYLIBColor(60, 60, 78, 255))
    DrawCube(Vector3(lax + fx * armSwing, armY - 0.12 * s, laz + fz * armSwing),
             0.18 * s, 0.04 * s, 0.18 * s, RAYLIBColor(50, 175, 215, 170))
    DrawCube(Vector3(lax + fx * armSwing, armY - 0.24 * s, laz + fz * armSwing),
             0.18 * s, 0.12 * s, 0.20 * s, RAYLIBColor(75, 75, 92, 255))
    // Right arm
    rax = wx - rx * 0.48 * s
    raz = wz - rz * 0.48 * s
    DrawCube(Vector3(rax - fx * armSwing, armY, raz - fz * armSwing),
             0.14 * s, 0.36 * s, 0.14 * s, RAYLIBColor(60, 60, 78, 255))
    DrawCube(Vector3(rax - fx * armSwing, armY - 0.12 * s, raz - fz * armSwing),
             0.18 * s, 0.04 * s, 0.18 * s, RAYLIBColor(50, 175, 215, 170))
    DrawCube(Vector3(rax - fx * armSwing, armY - 0.24 * s, raz - fz * armSwing),
             0.18 * s, 0.12 * s, 0.20 * s, RAYLIBColor(75, 75, 92, 255))

    // === NECK ===
    neckY = torsoY + 0.30 * s + hover
    DrawCube(Vector3(wx, neckY, wz), 0.20 * s, 0.10 * s, 0.20 * s,
             RAYLIBColor(50, 50, 68, 255))

    // === HEAD ===
    headY = neckY + 0.28 * s
    DrawCube(Vector3(wx, headY, wz), 0.52 * s, 0.42 * s, 0.46 * s,
             RAYLIBColor(55, 55, 72, 255))
    DrawCube(Vector3(wx, headY + 0.22 * s, wz), 0.48 * s, 0.04 * s, 0.42 * s,
             RAYLIBColor(68, 68, 85, 255))
    DrawCubeWires(Vector3(wx, headY, wz), 0.54 * s, 0.44 * s, 0.48 * s,
                  RAYLIBColor(55, 185, 225, 45))

    // === FACE VISOR ===
    screenY = headY + 0.03 * s
    DrawCube(Vector3(wx + fx * 0.24 * s, screenY, wz + fz * 0.24 * s),
             0.42 * s, 0.24 * s, 0.02 * s, RAYLIBColor(12, 22, 35, 255))
    DrawCube(Vector3(wx + fx * 0.25 * s, screenY, wz + fz * 0.25 * s),
             0.44 * s, 0.26 * s, 0.01 * s, RAYLIBColor(40, 185, 235, floor(110 * corePulse)))

    // === EYES ===
    eyeY = screenY + 0.03 * s
    eyeBright = floor(200 + 55 * corePulse)
    DrawCube(Vector3(wx + fx * 0.26 * s + rx * 0.11 * s, eyeY, wz + fz * 0.26 * s + rz * 0.11 * s),
             0.11 * s, 0.11 * s, 0.02 * s, RAYLIBColor(40, eyeBright, 255, 255))
    DrawCube(Vector3(wx + fx * 0.26 * s - rx * 0.11 * s, eyeY, wz + fz * 0.26 * s - rz * 0.11 * s),
             0.11 * s, 0.11 * s, 0.02 * s, RAYLIBColor(40, eyeBright, 255, 255))
    DrawCube(Vector3(wx + fx * 0.27 * s + rx * 0.11 * s, eyeY, wz + fz * 0.27 * s + rz * 0.11 * s),
             0.05 * s, 0.06 * s, 0.02 * s, RAYLIBColor(200, 255, 255, eyeBright))
    DrawCube(Vector3(wx + fx * 0.27 * s - rx * 0.11 * s, eyeY, wz + fz * 0.27 * s - rz * 0.11 * s),
             0.05 * s, 0.06 * s, 0.02 * s, RAYLIBColor(200, 255, 255, eyeBright))

    // === ANTENNA ===
    antY = headY + 0.32 * s
    DrawCube(Vector3(wx, antY, wz), 0.04 * s, 0.22 * s, 0.04 * s,
             RAYLIBColor(80, 80, 95, 255))
    blink = sin(pBobTime * 4)
    if blink > 0.3
        DrawSphere(Vector3(wx, antY + 0.14 * s, wz), 0.06 * s,
                   RAYLIBColor(255, 70, 50, 255))
    else
        DrawSphere(Vector3(wx, antY + 0.14 * s, wz), 0.06 * s,
                   RAYLIBColor(120, 35, 25, 255))
    ok

    // === BACKPACK ===
    bpY = torsoY + 0.04 * s + hover
    DrawCube(Vector3(wx - fx * 0.30 * s, bpY, wz - fz * 0.30 * s),
             0.38 * s, 0.36 * s, 0.16 * s, RAYLIBColor(58, 58, 74, 255))
    DrawCube(Vector3(wx - fx * 0.39 * s, bpY + 0.06 * s, wz - fz * 0.39 * s),
             0.14 * s, 0.12 * s, 0.02 * s, RAYLIBColor(40, 200, 240, floor(140 * corePulse)))
    DrawCube(Vector3(wx - fx * 0.39 * s, bpY - 0.08 * s, wz - fz * 0.39 * s),
             0.14 * s, 0.12 * s, 0.02 * s, RAYLIBColor(40, 200, 240, floor(100 * corePulse)))

// =============================================================
// Particles
// =============================================================

func cr_spawnParticles wx, wy, wz, pr, pg, pb, count
    for i = 1 to count
        vx = (GetRandomValue(-100, 100) / 100.0) * 3.0
        vy = (GetRandomValue(50, 200) / 100.0) * 2.0
        vz = (GetRandomValue(-100, 100) / 100.0) * 3.0
        life = 1.0 + GetRandomValue(0, 100) / 100.0
        pLen++
        particles + [wx, wy, wz, vx, vy, vz, life, pr, pg, pb]
    next

func cr_updateParticles dt
    i = 1
    while i <= pLen
        particles[i][1] += particles[i][4] * dt
        particles[i][2] += particles[i][5] * dt
        particles[i][3] += particles[i][6] * dt
        particles[i][5] -= 4.0 * dt  // gravity
        particles[i][7] -= dt

        if particles[i][7] <= 0
            if i < pLen
                particles[i] = particles[pLen]
            ok
            del(particles, pLen)
            pLen--
        else
            i++
        ok
    end

func cr_drawParticles3D
    for i = 1 to pLen
        p = particles[i]
        alpha = floor(p[7] * 200)
        if alpha < 0 alpha = 0 ok
        if alpha > 255 alpha = 255 ok
        sz = 0.06 + p[7] * 0.06
        DrawCube(Vector3(p[1], p[2], p[3]), sz, sz, sz,
                 RAYLIBColor(p[8], p[9], p[10], alpha))
    next