/*
**  tank3d_draw3d.ring
**  All 3D drawing functions: floor, walls, base, trees, lava,
**  player tank, enemy tanks, bullets, explosions, powerups, particles
*/

// =============================================================
// 3D Drawing: Floor
// =============================================================

func tank_drawFloor
    // Dark floor
    DrawCube(Vector3(GRID_W / 2.0 + 0.5, -0.1, GRID_H / 2.0 + 0.5),
             GRID_W + 2.0, 0.15, GRID_H + 2.0,
             RAYLIBColor(30, 30, 35, 255))

    // Grid lines (subtle)
    for r = 1 to GRID_H
        for c = 1 to GRID_W
            t = tiles[r][c]
            wx = c * CELL_SZ
            wz = r * CELL_SZ

            if t = T_ICE
                // Icy surface
                DrawCube(Vector3(wx, 0.01, wz), 0.98, 0.02, 0.98,
                         RAYLIBColor(150, 200, 230, 180))
                DrawCube(Vector3(wx, 0.03, wz), 0.80, 0.01, 0.80,
                         RAYLIBColor(200, 230, 255, 100))
            ok

            if t = T_WATER
                // Animated water
                wh = sin(animTime * 3.0 + wx + wz) * 0.03
                DrawCube(Vector3(wx, 0.05 + wh, wz), 0.98, 0.10, 0.98,
                         RAYLIBColor(20, 60, 150, 200))
                // Surface shimmer
                DrawCube(Vector3(wx, 0.12 + wh, wz), 0.70, 0.01, 0.70,
                         RAYLIBColor(60, 120, 200, 120))
                // Ripple
                rSz = (sin(animTime * 2.0 + wx * 3.0) * 0.1 + 0.5)
                DrawCube(Vector3(wx, 0.13 + wh, wz), rSz, 0.005, rSz,
                         RAYLIBColor(100, 180, 255, 60))
            ok

            if t = T_LAVA
                // Animated lava - glowing orange/red
                lh = sin(animTime * 2.0 + wx * 2.0 + wz) * 0.04
                lr = 200 + floor(sin(animTime * 3.0 + wx) * 40)
                lg = 60 + floor(sin(animTime * 2.5 + wz) * 30)
                DrawCube(Vector3(wx, 0.05 + lh, wz), 0.98, 0.10, 0.98,
                         RAYLIBColor(lr, lg, 10, 230))
                // Bright surface
                DrawCube(Vector3(wx, 0.12 + lh, wz), 0.60, 0.01, 0.60,
                         RAYLIBColor(255, 150, 20, 150))
                // Bubbles
                bSz = fabs(sin(animTime * 4.0 + wx * 5.0 + wz * 3.0)) * 0.15 + 0.05
                DrawSphere(Vector3(wx + sin(animTime + wz) * 0.2, 0.15 + lh, wz + cos(animTime + wx) * 0.2),
                           bSz, RAYLIBColor(255, 200, 50, 180))
            ok
        next
    next

    // Border walls
    bh = 0.6
    DrawCube(Vector3(0.5, bh/2, GRID_H/2.0 + 0.5), 0.3, bh, GRID_H + 1.0,
             RAYLIBColor(80, 80, 80, 255))
    DrawCube(Vector3(GRID_W + 0.5, bh/2, GRID_H/2.0 + 0.5), 0.3, bh, GRID_H + 1.0,
             RAYLIBColor(80, 80, 80, 255))
    DrawCube(Vector3(GRID_W/2.0 + 0.5, bh/2, 0.5), GRID_W + 1.0, bh, 0.3,
             RAYLIBColor(80, 80, 80, 255))
    DrawCube(Vector3(GRID_W/2.0 + 0.5, bh/2, GRID_H + 0.5), GRID_W + 1.0, bh, 0.3,
             RAYLIBColor(80, 80, 80, 255))

// =============================================================
// 3D Drawing: Walls
// =============================================================

func tank_drawWalls3D
    for r = 1 to GRID_H
        for c = 1 to GRID_W
            t = tiles[r][c]
            wx = c * CELL_SZ
            wz = r * CELL_SZ

            if t = T_BRICK
                // Orange/brown brick
                DrawCube(Vector3(wx, 0.3, wz), 0.96, 0.58, 0.96,
                         RAYLIBColor(180, 100, 30, 255))
                // Mortar lines
                DrawCube(Vector3(wx, 0.3, wz + 0.49), 0.98, 0.02, 0.01,
                         RAYLIBColor(80, 50, 20, 255))
                DrawCube(Vector3(wx, 0.45, wz + 0.49), 0.98, 0.02, 0.01,
                         RAYLIBColor(80, 50, 20, 255))
                DrawCube(Vector3(wx, 0.15, wz + 0.49), 0.98, 0.02, 0.01,
                         RAYLIBColor(80, 50, 20, 255))
                // Vertical mortar
                DrawCube(Vector3(wx, 0.22, wz + 0.49), 0.02, 0.16, 0.01,
                         RAYLIBColor(80, 50, 20, 255))
                DrawCube(Vector3(wx - 0.25, 0.38, wz + 0.49), 0.02, 0.16, 0.01,
                         RAYLIBColor(80, 50, 20, 255))
                DrawCube(Vector3(wx + 0.25, 0.38, wz + 0.49), 0.02, 0.16, 0.01,
                         RAYLIBColor(80, 50, 20, 255))
                // Top face highlight
                DrawCube(Vector3(wx, 0.59, wz), 0.94, 0.01, 0.94,
                         RAYLIBColor(210, 130, 50, 150))
            ok

            if t = T_STEEL
                // Silver steel wall
                DrawCube(Vector3(wx, 0.35, wz), 0.96, 0.68, 0.96,
                         RAYLIBColor(160, 160, 170, 255))
                // Rivet pattern
                for rx = -1 to 1 step 2
                    for rz = -1 to 1 step 2
                        DrawSphere(Vector3(wx + rx * 0.28, 0.50, wz + rz * 0.28),
                                   0.06, RAYLIBColor(200, 200, 210, 255))
                    next
                next
                // Center cross
                DrawCube(Vector3(wx, 0.35, wz + 0.49), 0.60, 0.06, 0.01,
                         RAYLIBColor(120, 120, 130, 255))
                DrawCube(Vector3(wx, 0.35, wz + 0.49), 0.06, 0.50, 0.01,
                         RAYLIBColor(120, 120, 130, 255))
                // Top shine
                DrawCube(Vector3(wx, 0.69, wz), 0.90, 0.01, 0.90,
                         RAYLIBColor(200, 200, 220, 120))
            ok
        next
    next

// =============================================================
// 3D Drawing: Base (Eagle)
// =============================================================

func tank_drawBase3D
    bx = (baseC + 0.5) * CELL_SZ
    bz = (baseR + 0.5) * CELL_SZ

    hasBase = false
    if baseR >= 1 and baseR <= GRID_H and baseC >= 1 and baseC <= GRID_W
        if tiles[baseR][baseC] = T_BASE hasBase = true ok
    ok

    if hasBase
        // Living base - golden eagle
        // Platform
        DrawCube(Vector3(bx, 0.08, bz), 1.8, 0.15, 1.8,
                 RAYLIBColor(180, 150, 30, 255))
        // Eagle body
        DrawCylinder(Vector3(bx, 0.15, bz), 0.50, 0.35, 0.60, 8,
                     RAYLIBColor(220, 180, 40, 255))
        // Wings
        DrawCube(Vector3(bx - 0.55, 0.45, bz), 0.40, 0.06, 0.50,
                 RAYLIBColor(200, 160, 30, 255))
        DrawCube(Vector3(bx + 0.55, 0.45, bz), 0.40, 0.06, 0.50,
                 RAYLIBColor(200, 160, 30, 255))
        // Wing tips (angled up)
        DrawCube(Vector3(bx - 0.70, 0.55, bz), 0.15, 0.15, 0.35,
                 RAYLIBColor(190, 150, 25, 255))
        DrawCube(Vector3(bx + 0.70, 0.55, bz), 0.15, 0.15, 0.35,
                 RAYLIBColor(190, 150, 25, 255))
        // Head
        DrawSphere(Vector3(bx, 0.70, bz + 0.15), 0.18,
                   RAYLIBColor(230, 190, 50, 255))
        // Eyes
        DrawSphere(Vector3(bx - 0.08, 0.72, bz + 0.28), 0.04,
                   RAYLIBColor(20, 20, 20, 255))
        DrawSphere(Vector3(bx + 0.08, 0.72, bz + 0.28), 0.04,
                   RAYLIBColor(20, 20, 20, 255))
        // Glow
        glA = floor((sin(animTime * 3.0) * 0.3 + 0.7) * 50)
        DrawSphere(Vector3(bx, 0.45, bz), 0.80,
                   RAYLIBColor(255, 220, 50, glA))
    else
        // Destroyed base
        DrawCube(Vector3(bx, 0.15, bz), 1.8, 0.30, 1.8,
                 RAYLIBColor(40, 40, 40, 255))
        // Rubble
        for i = 1 to 5
            rx = bx + cos(i * 1.2) * 0.5
            rz = bz + sin(i * 1.8) * 0.5
            DrawCube(Vector3(rx, 0.15 + i * 0.04, rz), 0.20, 0.12, 0.20,
                     RAYLIBColor(60, 50, 20, 255))
        next
        // Smoke
        for i = 1 to 3
            sy = sin(animTime * 1.5 + i) * 0.3 + 0.8
            sa = floor(120 - sy * 50)
            if sa < 0 sa = 0 ok
            DrawSphere(Vector3(bx + cos(i * 2.0) * 0.3, sy, bz + sin(i * 2.0) * 0.3),
                       0.15, RAYLIBColor(60, 60, 60, sa))
        next
    ok

// =============================================================
// 3D Drawing: Trees
// =============================================================

func tank_drawTrees3D
    for r = 1 to GRID_H
        for c = 1 to GRID_W
            if tiles[r][c] = T_TREES
                wx = c * CELL_SZ
                wz = r * CELL_SZ

                // Tree trunk
                DrawCylinder(Vector3(wx, 0, wz), 0.08, 0.06, 0.35, 6,
                             RAYLIBColor(100, 70, 30, 255))
                // Foliage layers
                sway = sin(animTime * 1.5 + wx + wz) * 0.03
                DrawSphere(Vector3(wx + sway, 0.50, wz), 0.38,
                           RAYLIBColor(20, 100, 20, 220))
                DrawSphere(Vector3(wx + sway, 0.65, wz), 0.28,
                           RAYLIBColor(30, 120, 30, 210))
                DrawSphere(Vector3(wx + sway, 0.76, wz), 0.18,
                           RAYLIBColor(40, 140, 40, 200))
            ok
        next
    next

// =============================================================
// 3D Drawing: Lava (extra effects above the surface)
// =============================================================

func tank_drawLava3D
    // Lava glow columns and embers (already drawn in floor, this adds atmosphere)
    for r = 1 to GRID_H
        for c = 1 to GRID_W
            if tiles[r][c] = T_LAVA
                wx = c * CELL_SZ
                wz = r * CELL_SZ
                // Faint glow pillar
                glowH = fabs(sin(animTime * 1.5 + wx + wz * 2.0)) * 0.3
                DrawCube(Vector3(wx, 0.15 + glowH / 2, wz), 0.3, glowH, 0.3,
                         RAYLIBColor(255, 100, 0, 30))
            ok
        next
    next

// =============================================================
// 3D Drawing: Player Tank
// =============================================================

func tank_drawPlayer3D
    if !palive return ok

    wx = px * CELL_SZ
    wz = py * CELL_SZ

    // Direction vectors (UP = -Z toward top of screen)
    fdx = 0.0 fdz = 0.0
    if pdir = DIR_UP fdz = -1.0 ok
    if pdir = DIR_DOWN fdz = 1.0 ok
    if pdir = DIR_LEFT fdx = -1.0 ok
    if pdir = DIR_RIGHT fdx = 1.0 ok

    // Shadow
    DrawCylinder(Vector3(wx, 0.01, wz), 0.40, 0.45, 0.01, 10,
                 RAYLIBColor(0, 0, 0, 40))

    // Track marks (treads)
    perpX = -fdz
    perpZ = fdx
    treadBob = sin(pMoveAnim) * 0.01

    // Left tread
    DrawCube(Vector3(wx + perpX * 0.32, 0.08 + treadBob, wz + perpZ * 0.32),
             0.14 + fabs(fdx) * 0.40, 0.12, 0.14 + fabs(fdz) * 0.40,
             RAYLIBColor(50, 55, 40, 255))
    // Right tread
    DrawCube(Vector3(wx - perpX * 0.32, 0.08 - treadBob, wz - perpZ * 0.32),
             0.14 + fabs(fdx) * 0.40, 0.12, 0.14 + fabs(fdz) * 0.40,
             RAYLIBColor(50, 55, 40, 255))

    // Tread detail (segments)
    for s = -2 to 2
        off = s * 0.12
        DrawCube(Vector3(wx + perpX * 0.32 + fdx * off, 0.14, wz + perpZ * 0.32 + fdz * off),
                 0.16 + fabs(fdx) * 0.02, 0.02, 0.16 + fabs(fdz) * 0.02,
                 RAYLIBColor(70, 75, 55, 255))
        DrawCube(Vector3(wx - perpX * 0.32 + fdx * off, 0.14, wz - perpZ * 0.32 + fdz * off),
                 0.16 + fabs(fdx) * 0.02, 0.02, 0.16 + fabs(fdz) * 0.02,
                 RAYLIBColor(70, 75, 55, 255))
    next

    // Hull (main body) - olive/yellow player color
    DrawCube(Vector3(wx, 0.18, wz), 0.55, 0.16, 0.55,
             RAYLIBColor(180, 160, 40, 255))
    // Hull top
    DrawCube(Vector3(wx, 0.27, wz), 0.50, 0.02, 0.50,
             RAYLIBColor(200, 180, 60, 180))

    // Turret
    DrawCylinder(Vector3(wx, 0.26, wz), 0.22, 0.20, 0.14, 10,
                 RAYLIBColor(160, 145, 35, 255))
    // Turret top
    DrawCylinder(Vector3(wx, 0.39, wz), 0.18, 0.16, 0.02, 10,
                 RAYLIBColor(190, 170, 55, 200))

    // Cannon barrel
    barrelLen = 0.50
    bx = wx + fdx * 0.15
    bz2 = wz + fdz * 0.15
    DrawCylinder(Vector3(bx + fdx * barrelLen * 0.5, 0.33,
                         bz2 + fdz * barrelLen * 0.5),
                 0.05, 0.04, barrelLen, 8,
                 RAYLIBColor(130, 120, 30, 255))
    // Muzzle
    DrawCylinder(Vector3(bx + fdx * barrelLen, 0.33,
                         bz2 + fdz * barrelLen),
                 0.06, 0.06, 0.05, 8,
                 RAYLIBColor(100, 90, 25, 255))

    // Commander's hatch
    DrawCylinder(Vector3(wx - fdx * 0.08, 0.40, wz - fdz * 0.08),
                 0.06, 0.06, 0.03, 8,
                 RAYLIBColor(140, 130, 30, 255))

    // Star emblem on turret side
    DrawSphere(Vector3(wx + perpX * 0.21, 0.32, wz + perpZ * 0.21),
               0.04, RAYLIBColor(255, 50, 50, 255))

    // Shield effect
    if pshield > 0
        shA = floor((sin(animTime * 8.0) * 0.3 + 0.5) * 100)
        DrawSphere(Vector3(wx, 0.25, wz), 0.55,
                   RAYLIBColor(100, 180, 255, shA))
    ok

    // Speed boost effect
    if pspeedBoost > 0
        for i = 1 to 3
            tOff = i * 0.15
            DrawSphere(Vector3(wx - fdx * (0.3 + tOff), 0.15,
                               wz - fdz * (0.3 + tOff)),
                       0.08, RAYLIBColor(255, 200, 50, floor(60 / i)))
        next
    ok

// =============================================================
// 3D Drawing: Enemy Tanks
// =============================================================

func tank_drawEnemies3D
    nEnemies = len(enemies)
    for e = 1 to nEnemies
        if !enemies[e][5] loop ok

        ex = enemies[e][1] * CELL_SZ
        ez = enemies[e][2] * CELL_SZ
        edir = enemies[e][3]
        eType = enemies[e][7]
        eAnim = enemies[e][8]

        // Direction
        edx = 0.0 edz = 0.0
        if edir = DIR_UP edz = -1.0 ok
        if edir = DIR_DOWN edz = 1.0 ok
        if edir = DIR_LEFT edx = -1.0 ok
        if edir = DIR_RIGHT edx = 1.0 ok

        perpX = -edz
        perpZ = edx

        // Color by type
        hullR = 180 hullG = 180 hullB = 180
        hullA = 255
        if eType = 1 hullR = 180 hullG = 180 hullB = 180 ok   // Basic gray
        if eType = 2 hullR = 180 hullG = 140 hullB = 80 ok    // Fast brown
        if eType = 3 hullR = 80 hullG = 180 hullB = 80 ok     // Fast green
        if eType = 4 hullR = 180 hullG = 60 hullB = 60 ok     // Heavy red
        if eType = 5 hullR = 140 hullG = 60 hullB = 180 ok    // Stealth purple
        if eType = 6 hullR = 220 hullG = 180 hullB = 40 ok    // Boss gold

        // Stealth visibility
        if eType = 5 and !enemies[e][13]
            hullA = 40  // Nearly invisible
        ok

        // Frozen tint
        if globalFreezeTimer > 0
            hullR = floor(hullR * 0.5 + 50)
            hullG = floor(hullG * 0.5 + 80)
            hullB = floor(hullB * 0.5 + 120)
        ok

        // Boss aura
        if eType = 6
            aGlow = fabs(sin(eAnim * 3.0)) * 0.15 + 0.4
            DrawSphere(Vector3(ex, 0.25, ez), aGlow + 0.2,
                       RAYLIBColor(255, 200, 50, 30))
        ok

        // Shadow
        DrawCylinder(Vector3(ex, 0.01, ez), 0.38, 0.42, 0.01, 10,
                     RAYLIBColor(0, 0, 0, 35))

        treadBob = sin(eAnim * 8.0) * 0.01

        // Treads
        DrawCube(Vector3(ex + perpX * 0.30, 0.08 + treadBob, ez + perpZ * 0.30),
                 0.12 + fabs(edx) * 0.38, 0.11, 0.12 + fabs(edz) * 0.38,
                 RAYLIBColor(50, 50, 50, 255))
        DrawCube(Vector3(ex - perpX * 0.30, 0.08 - treadBob, ez - perpZ * 0.30),
                 0.12 + fabs(edx) * 0.38, 0.11, 0.12 + fabs(edz) * 0.38,
                 RAYLIBColor(50, 50, 50, 255))

        // Hull
        DrawCube(Vector3(ex, 0.17, ez), 0.52, 0.14, 0.52,
                 RAYLIBColor(hullR, hullG, hullB, hullA))
        // Hull top
        DrawCube(Vector3(ex, 0.25, ez), 0.48, 0.02, 0.48,
                 RAYLIBColor(floor(hullR * 1.1), floor(hullG * 1.1), floor(hullB * 1.1), floor(hullA * 0.63)))

        // Turret
        DrawCylinder(Vector3(ex, 0.24, ez), 0.20, 0.18, 0.13, 8,
                     RAYLIBColor(floor(hullR * 0.85), floor(hullG * 0.85), floor(hullB * 0.85), hullA))

        // Cannon
        bLen = 0.45
        if eType = 4 bLen = 0.55 ok
        if eType = 6 bLen = 0.60 ok  // Boss has longer cannon
        cbx = ex + edx * 0.12
        cbz = ez + edz * 0.12
        DrawCylinder(Vector3(cbx + edx * bLen * 0.5, 0.30,
                             cbz + edz * bLen * 0.5),
                     0.045, 0.035, bLen, 8,
                     RAYLIBColor(floor(hullR * 0.7), floor(hullG * 0.7), floor(hullB * 0.7), hullA))

        // HP indicator for heavy tanks and boss
        if (eType = 4 or eType = 5 or eType = 6) and enemies[e][6] > 1
            maxDots = enemies[e][6]
            if maxDots > 8 maxDots = 8 ok
            for hp = 1 to maxDots
                dotClr = RAYLIBColor(255, 50, 50, 255)
                if eType = 6 dotClr = RAYLIBColor(255, 200, 50, 255) ok
                DrawSphere(Vector3(ex + (hp - (maxDots+1)/2.0) * 0.12, 0.55, ez),
                           0.04, dotClr)
            next
        ok

        // Boss crown
        if eType = 6
            DrawCylinder(Vector3(ex, 0.42, ez), 0.12, 0.15, 0.08, 5,
                         RAYLIBColor(255, 215, 0, 200))
        ok

        // Frozen overlay
        if globalFreezeTimer > 0
            DrawCube(Vector3(ex, 0.25, ez), 0.55, 0.35, 0.55,
                     RAYLIBColor(100, 150, 255, 50))
        ok
    next

// =============================================================
// 3D Drawing: Bullets
// =============================================================

func tank_drawBullets3D
    // Player bullets
    nPB = len(pbullets)
    for i = 1 to nPB
        if !pbullets[i][1] loop ok
        bx = pbullets[i][2] * CELL_SZ
        bz = pbullets[i][3] * CELL_SZ
        // Bright yellow bullet
        DrawSphere(Vector3(bx, 0.33, bz), 0.08,
                   RAYLIBColor(255, 255, 100, 255))
        DrawSphere(Vector3(bx, 0.33, bz), 0.14,
                   RAYLIBColor(255, 200, 50, 60))
    next

    // Enemy bullets
    nEB = len(ebullets)
    for i = 1 to nEB
        if !ebullets[i][1] loop ok
        bx = ebullets[i][2] * CELL_SZ
        bz = ebullets[i][3] * CELL_SZ
        // Red bullet
        DrawSphere(Vector3(bx, 0.33, bz), 0.07,
                   RAYLIBColor(255, 80, 50, 255))
        DrawSphere(Vector3(bx, 0.33, bz), 0.12,
                   RAYLIBColor(255, 50, 30, 50))
    next

// =============================================================
// 3D Drawing: Explosions
// =============================================================

func tank_drawExplosions3D
    nExp = len(explosions)
    for i = 1 to nExp
        ex = explosions[i][1] * CELL_SZ
        ez = explosions[i][2] * CELL_SZ
        life = explosions[i][3] / explosions[i][4]
        maxSz = explosions[i][5]

        // Expand then fade
        sz = maxSz * (1.0 - life * 0.3)
        alpha = floor(life * 200)
        if alpha > 255 alpha = 255 ok
        if alpha < 0 alpha = 0 ok

        // Fire core
        DrawSphere(Vector3(ex, 0.4, ez), sz * 0.5,
                   RAYLIBColor(255, 200, 50, alpha))
        // Outer fire
        DrawSphere(Vector3(ex, 0.4, ez), sz * 0.8,
                   RAYLIBColor(255, 100, 20, floor(alpha * 0.5)))
        // Smoke
        DrawSphere(Vector3(ex, 0.6, ez), sz * 0.6,
                   RAYLIBColor(80, 80, 80, floor(alpha * 0.3)))
    next

// =============================================================
// 3D Drawing: Powerups
// =============================================================

func tank_drawPowerups3D
    nPU = len(powerups)
    for i = 1 to nPU
        if !powerups[i][5] loop ok

        pwx = powerups[i][1] * CELL_SZ
        pwz = powerups[i][2] * CELL_SZ
        ptype = powerups[i][3]
        bob = sin(animTime * 4.0) * 0.15

        // Flashing effect
        flash = floor((sin(animTime * 6.0) * 0.3 + 0.7) * 255)

        if ptype = 1
            // Star - yellow
            DrawSphere(Vector3(pwx, 0.40 + bob, pwz), 0.20,
                       RAYLIBColor(255, 220, 50, flash))
            DrawSphere(Vector3(pwx, 0.40 + bob, pwz), 0.30,
                       RAYLIBColor(255, 200, 0, floor(flash * 0.3)))
        ok
        if ptype = 2
            // Shield - blue
            DrawSphere(Vector3(pwx, 0.40 + bob, pwz), 0.20,
                       RAYLIBColor(80, 150, 255, flash))
            DrawSphere(Vector3(pwx, 0.40 + bob, pwz), 0.30,
                       RAYLIBColor(50, 100, 255, floor(flash * 0.3)))
        ok
        if ptype = 3
            // Bomb - red
            DrawSphere(Vector3(pwx, 0.40 + bob, pwz), 0.20,
                       RAYLIBColor(255, 60, 40, flash))
            DrawSphere(Vector3(pwx, 0.40 + bob, pwz), 0.30,
                       RAYLIBColor(255, 30, 20, floor(flash * 0.3)))
        ok
        if ptype = 4
            // Freeze - cyan with snowflake sparkles
            DrawSphere(Vector3(pwx, 0.40 + bob, pwz), 0.20,
                       RAYLIBColor(50, 220, 255, flash))
            DrawSphere(Vector3(pwx, 0.40 + bob, pwz), 0.30,
                       RAYLIBColor(100, 240, 255, floor(flash * 0.3)))
            // Sparkle
            for sp = 1 to 3
                sAng = animTime * 4.0 + sp * 2.1
                sDist = 0.25
                DrawSphere(Vector3(pwx + cos(sAng) * sDist, 0.40 + bob + sin(sAng * 1.5) * 0.1,
                                   pwz + sin(sAng) * sDist), 0.04,
                           RAYLIBColor(200, 240, 255, floor(flash * 0.8)))
            next
        ok
        if ptype = 5
            // Life - green with plus sign effect
            DrawSphere(Vector3(pwx, 0.40 + bob, pwz), 0.20,
                       RAYLIBColor(50, 255, 80, flash))
            DrawSphere(Vector3(pwx, 0.40 + bob, pwz), 0.30,
                       RAYLIBColor(30, 200, 50, floor(flash * 0.3)))
            // Plus sign
            DrawCube(Vector3(pwx, 0.40 + bob, pwz), 0.25, 0.05, 0.08,
                     RAYLIBColor(255, 255, 255, floor(flash * 0.7)))
            DrawCube(Vector3(pwx, 0.40 + bob, pwz), 0.08, 0.05, 0.25,
                     RAYLIBColor(255, 255, 255, floor(flash * 0.7)))
        ok
    next

// =============================================================
// 3D Drawing: Particles
// =============================================================

func tank_drawParticles3D
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
