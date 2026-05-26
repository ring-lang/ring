/*
**  Dave the Fighter - 3D Rendering
**  Functions: Level, collectibles, player, enemies, bullets, particles drawing
*/

func dave_drawLevel3D
    // Background wall (far back) - color matches level theme
    bgW = curLvlW * CELL_SZ + 2.0
    bgH = LVL_H * CELL_SZ + 2.0
    if level <= 5
        DrawCube(Vector3(curLvlW * 0.5, LVL_H * 0.5, -1.0), bgW, bgH, 0.2,
                 RAYLIBColor(18, 8, 8, 255))
        DrawCube(Vector3(curLvlW * 0.5, LVL_H * 0.7, -0.9), bgW * 0.95, bgH * 0.3, 0.1,
                 RAYLIBColor(35, 10, 10, 100))
    but level <= 10
        DrawCube(Vector3(curLvlW * 0.5, LVL_H * 0.5, -1.0), bgW, bgH, 0.2,
                 RAYLIBColor(8, 8, 18, 255))
        DrawCube(Vector3(curLvlW * 0.5, LVL_H * 0.7, -0.9), bgW * 0.95, bgH * 0.3, 0.1,
                 RAYLIBColor(10, 10, 35, 100))
    but level <= 15
        DrawCube(Vector3(curLvlW * 0.5, LVL_H * 0.5, -1.0), bgW, bgH, 0.2,
                 RAYLIBColor(20, 22, 28, 255))
        DrawCube(Vector3(curLvlW * 0.5, LVL_H * 0.7, -0.9), bgW * 0.95, bgH * 0.3, 0.1,
                 RAYLIBColor(30, 35, 45, 100))
    else
        // Yellow/sand world
        DrawCube(Vector3(curLvlW * 0.5, LVL_H * 0.5, -1.0), bgW, bgH, 0.2,
                 RAYLIBColor(25, 18, 8, 255))
        DrawCube(Vector3(curLvlW * 0.5, LVL_H * 0.7, -0.9), bgW * 0.95, bgH * 0.3, 0.1,
                 RAYLIBColor(45, 30, 10, 100))
    ok

    // Frustum culling - only draw columns visible to camera
    viewRange = 18
    cMin = floor(px) - viewRange
    cMax = floor(px) + viewRange
    if cMin < 1 cMin = 1 ok
    if cMax > curLvlW cMax = curLvlW ok

    for r = 1 to LVL_H
        for c = cMin to cMax
            t = tiles[r][c]
            if t = T_EMPTY loop ok
            wx = c * CELL_SZ
            wy = (LVL_H - r) * CELL_SZ + 0.5
            wz = 0.0

            if t = T_BRICK
                dave_drawBrick3D(wx, wy, wz)
            ok

            if t = T_PLATFORM
                dave_drawPlatform3D(wx, wy + 0.5, wz)
            ok

            if t = T_SPIKE
                dave_drawSpike3D(wx, wy, wz)
            ok

            if t = T_LADDER
                dave_drawLadder3D(wx, wy, wz)
            ok

            if t = T_DOOR
                dave_drawDoor3D(wx, wy, wz)
            ok

            if t = T_CRUMBLE
                dave_drawCrumble3D(wx, wy + 0.5, wz, r, c)
            ok

            if t = T_WIND_L or t = T_WIND_R
                dave_drawWind3D(wx, wy, wz, t)
            ok

            if t = T_CHECKPOINT
                dave_drawCheckpoint3D(wx, wy, wz)
            ok
        next
    next

func dave_drawBrick3D wx, wy, wz
    // Brick color: red 1-5, blue 6-10, white/ice 11-15
    if level <= 5
        brickR = 160  brickG = 30   brickB = 30
        mortR = 60    mortG = 15    mortB = 10
        highR = 200   highG = 60    highB = 50
        faceR = 180   faceG = 40    faceB = 35
    but level <= 10
        brickR = 30   brickG = 50   brickB = 160
        mortR = 10    mortG = 15    mortB = 60
        highR = 50    highG = 80    highB = 200
        faceR = 35    faceG = 55    faceB = 180
    but level <= 15
        brickR = 200  brickG = 210  brickB = 220
        mortR = 140   mortG = 150   mortB = 165
        highR = 240   highG = 245   highB = 255
        faceR = 220   faceG = 225   faceB = 235
    else
        // Yellow sandstone
        brickR = 200  brickG = 170  brickB = 80
        mortR = 120   mortG = 95    mortB = 40
        highR = 240   highG = 210   highB = 120
        faceR = 220   faceG = 190   faceB = 100
    ok

    // Main brick body
    DrawCube(Vector3(wx, wy, wz), 0.96, 0.96, 0.8,
             RAYLIBColor(brickR, brickG, brickB, 255))

    // Mortar lines (dark grooves) - horizontal
    DrawCube(Vector3(wx, wy + 0.24, wz + 0.41), 0.98, 0.04, 0.02,
             RAYLIBColor(mortR, mortG, mortB, 255))
    DrawCube(Vector3(wx, wy - 0.24, wz + 0.41), 0.98, 0.04, 0.02,
             RAYLIBColor(mortR, mortG, mortB, 255))

    // Mortar vertical (offset for brick pattern)
    DrawCube(Vector3(wx, wy + 0.0, wz + 0.41), 0.04, 0.48, 0.02,
             RAYLIBColor(mortR, mortG, mortB, 255))
    DrawCube(Vector3(wx - 0.25, wy + 0.24, wz + 0.41), 0.04, 0.52, 0.02,
             RAYLIBColor(mortR, mortG, mortB, 255))
    DrawCube(Vector3(wx + 0.25, wy - 0.24, wz + 0.41), 0.04, 0.52, 0.02,
             RAYLIBColor(mortR, mortG, mortB, 255))

    // Top highlight
    DrawCube(Vector3(wx, wy + 0.49, wz), 0.94, 0.02, 0.78,
             RAYLIBColor(highR, highG, highB, 200))

    // Front face slight lighting variation
    DrawCube(Vector3(wx, wy, wz + 0.42), 0.94, 0.94, 0.01,
             RAYLIBColor(faceR, faceG, faceB, 100))

func dave_drawPlatform3D wx, wy, wz
    // Metallic platform - silver-grey for levels 1-5, blue-steel for 6-10
    if level <= 5
        platR = 100  platG = 100  platB = 120
        shinR = 150  shinG = 150  shinB = 180
        shadR = 50   shadG = 50   shadB = 65
        rivR = 180   rivG = 180   rivB = 200
    but level <= 10
        platR = 70   platG = 80   platB = 140
        shinR = 110  shinG = 130  shinB = 200
        shadR = 30   shadG = 35   shadB = 75
        rivR = 140   rivG = 160   rivB = 220
    but level <= 15
        platR = 180  platG = 190  platB = 200
        shinR = 220  shinG = 230  shinB = 245
        shadR = 120  shadG = 130  shadB = 145
        rivR = 200   rivG = 210   rivB = 230
    else
        // Bronze/gold platform
        platR = 180  platG = 150  platB = 70
        shinR = 230  shinG = 200  shinB = 110
        shadR = 110  shadG = 85   shadB = 35
        rivR = 220   rivG = 190   rivB = 90
    ok
    DrawCube(Vector3(wx, wy, wz), 1.0, 0.14, 0.9,
             RAYLIBColor(platR, platG, platB, 255))
    // Top shine
    DrawCube(Vector3(wx, wy + 0.08, wz), 0.92, 0.02, 0.82,
             RAYLIBColor(shinR, shinG, shinB, 200))
    // Bottom shadow
    DrawCube(Vector3(wx, wy - 0.08, wz), 0.96, 0.02, 0.86,
             RAYLIBColor(shadR, shadG, shadB, 200))
    // Edge rivets
    DrawSphere(Vector3(wx - 0.4, wy + 0.04, wz + 0.4), 0.04,
               RAYLIBColor(rivR, rivG, rivB, 255))
    DrawSphere(Vector3(wx + 0.4, wy + 0.04, wz + 0.4), 0.04,
               RAYLIBColor(rivR, rivG, rivB, 255))

func dave_drawSpike3D wx, wy, wz
    // Dangerous spikes - pointed upward
    // Silver spikes in levels 1-5, icy blue in 6-10
    if level <= 5
        spkR = 180  spkG = 180  spkB = 190
        tipR = 255  tipG = 100  tipB = 100
        basR = 80   basG = 80   basB = 90
    but level <= 10
        spkR = 160  spkG = 180  spkB = 220
        tipR = 100  tipG = 150  tipB = 255
        basR = 50   basG = 60   basB = 100
    but level <= 15
        spkR = 210  spkG = 225  spkB = 240
        tipR = 150  tipG = 220  tipB = 255
        basR = 160  basG = 170  basB = 185
    else
        // Golden spikes with orange tips
        spkR = 210  spkG = 185  spkB = 100
        tipR = 255  tipG = 180  tipB = 50
        basR = 140  basG = 110  basB = 50
    ok
    for s = -1 to 1
        sx = wx + s * 0.28
        DrawCylinder(Vector3(sx, wy - 0.2, wz), 0.01, 0.12, 0.6, 4,
                     RAYLIBColor(spkR, spkG, spkB, 255))
        // Tip glow
        DrawSphere(Vector3(sx, wy + 0.35, wz), 0.04,
                   RAYLIBColor(tipR, tipG, tipB, 200))
    next
    // Base
    DrawCube(Vector3(wx, wy - 0.35, wz), 0.9, 0.15, 0.6,
             RAYLIBColor(basR, basG, basB, 255))

func dave_drawLadder3D wx, wy, wz
    // Side rails (pushed back behind player)
    // Warm wood in levels 1-5, cool steel-blue in 6-10
    if level <= 5
        railR = 140  railG = 100  railB = 40
        rungR = 160  rungG = 120  rungB = 50
        highR = 200  highG = 160  highB = 80
    but level <= 10
        railR = 60   railG = 80   railB = 140
        rungR = 80   rungG = 100  rungB = 160
        highR = 120  highG = 150  highB = 210
    but level <= 15
        railR = 160  railG = 170  railB = 185
        rungR = 180  rungG = 190  rungB = 205
        highR = 220  highG = 230  highB = 245
    else
        // Dark bronze ladder
        railR = 140  railG = 110  railB = 50
        rungR = 170  rungG = 140  rungB = 65
        highR = 210  highG = 180  highB = 90
    ok
    DrawCube(Vector3(wx - 0.3, wy, wz - 0.15), 0.08, 1.0, 0.08,
             RAYLIBColor(railR, railG, railB, 255))
    DrawCube(Vector3(wx + 0.3, wy, wz - 0.15), 0.08, 1.0, 0.08,
             RAYLIBColor(railR, railG, railB, 255))
    // Rungs
    DrawCube(Vector3(wx, wy + 0.25, wz - 0.15), 0.56, 0.06, 0.06,
             RAYLIBColor(rungR, rungG, rungB, 255))
    DrawCube(Vector3(wx, wy - 0.25, wz - 0.15), 0.56, 0.06, 0.06,
             RAYLIBColor(rungR, rungG, rungB, 255))
    // Highlights on rungs
    DrawCube(Vector3(wx, wy + 0.28, wz - 0.15), 0.50, 0.02, 0.04,
             RAYLIBColor(highR, highG, highB, 150))
    DrawCube(Vector3(wx, wy - 0.22, wz - 0.15), 0.50, 0.02, 0.04,
             RAYLIBColor(highR, highG, highB, 150))

func dave_drawDoor3D wx, wy, wz
    // Heavy locked door - warm wood in 1-5, cold iron-blue in 6-10
    if level <= 5
        doorR = 80   doorG = 50   doorB = 30
        grainR = 50  grainG = 30  grainB = 15
        bandR = 120  bandG = 120  bandB = 130
    but level <= 10
        doorR = 35   doorG = 45   doorB = 85
        grainR = 20  grainG = 25  grainB = 55
        bandR = 100  bandG = 115  bandB = 150
    but level <= 15
        doorR = 170  doorG = 180  doorB = 195
        grainR = 130 grainG = 140 grainB = 155
        bandR = 190  bandG = 200  bandB = 215
    else
        // Warm golden door
        doorR = 140  doorG = 110  doorB = 45
        grainR = 100 grainG = 75  grainB = 25
        bandR = 190  bandG = 160  bandB = 70
    ok
    DrawCube(Vector3(wx, wy, wz), 0.9, 0.96, 0.5,
             RAYLIBColor(doorR, doorG, doorB, 255))
    // Wood grain lines
    for ln = -2 to 2
        DrawCube(Vector3(wx + ln * 0.15, wy, wz + 0.26), 0.03, 0.90, 0.01,
                 RAYLIBColor(grainR, grainG, grainB, 255))
    next
    // Metal bands
    DrawCube(Vector3(wx, wy + 0.3, wz + 0.27), 0.92, 0.06, 0.03,
             RAYLIBColor(bandR, bandG, bandB, 255))
    DrawCube(Vector3(wx, wy - 0.3, wz + 0.27), 0.92, 0.06, 0.03,
             RAYLIBColor(bandR, bandG, bandB, 255))
    // Lock
    DrawSphere(Vector3(wx + 0.2, wy, wz + 0.30), 0.08,
               RAYLIBColor(200, 180, 50, 255))
    // Keyhole
    DrawSphere(Vector3(wx + 0.2, wy, wz + 0.34), 0.03,
               RAYLIBColor(20, 20, 20, 255))
    // Glow if player has key
    if hasKey
        glow = sin(animTime * 5.0) * 0.3 + 0.7
        glA = floor(glow * 80)
        DrawSphere(Vector3(wx + 0.2, wy, wz + 0.32), 0.15,
                   RAYLIBColor(255, 255, 100, glA))
    ok

// =============================================================
// 3D Drawing: Collectibles
// =============================================================

func dave_drawCollectibles3D
    viewRange = 18
    cMin = floor(px) - viewRange
    cMax = floor(px) + viewRange
    if cMin < 1 cMin = 1 ok
    if cMax > curLvlW cMax = curLvlW ok

    for r = 1 to LVL_H
        for c = cMin to cMax
            t = tiles[r][c]
            if t != T_GEM and t != T_RUBY and t != T_RING and t != T_KEY and t != T_TROPHY and t != T_GUN loop ok
            wx = c * CELL_SZ
            wy = (LVL_H - r) * CELL_SZ + 0.5
            wz = 0.0

            if t = T_GEM
                dave_drawGem3D(wx, wy, wz)
            ok
            if t = T_RUBY
                dave_drawRuby3D(wx, wy, wz)
            ok
            if t = T_RING
                dave_drawGoldRing3D(wx, wy, wz)
            ok
            if t = T_KEY
                dave_drawKey3D(wx, wy, wz)
            ok
            if t = T_TROPHY
                dave_drawTrophy3D(wx, wy, wz)
            ok
            if t = T_GUN
                dave_drawGunPickup3D(wx, wy, wz)
            ok
        next
    next

func dave_drawGem3D wx, wy, wz
    bob = sin(animTime * 3.0 + wx * 2.0) * 0.08
    rot = animTime * 2.0

    // Diamond shape (two pyramids)
    by = wy + bob
    sz = 0.18

    // Core
    DrawSphere(Vector3(wx, by, wz + 0.2), sz,
               RAYLIBColor(30, 120, 255, 255))
    // Bright highlight
    DrawSphere(Vector3(wx, by + 0.06, wz + 0.2), sz * 0.5,
               RAYLIBColor(120, 200, 255, 200))
    // Sparkle
    DrawSphere(Vector3(wx - 0.05, by + 0.10, wz + 0.25), 0.04,
               RAYLIBColor(255, 255, 255, 180))
    // Glow
    DrawSphere(Vector3(wx, by, wz + 0.2), sz + 0.08,
               RAYLIBColor(30, 120, 255, 40))

func dave_drawRuby3D wx, wy, wz
    bob = sin(animTime * 3.5 + wx) * 0.08
    by = wy + bob

    // Red ruby
    DrawSphere(Vector3(wx, by, wz + 0.2), 0.20,
               RAYLIBColor(220, 20, 60, 255))
    // Facet highlights
    DrawSphere(Vector3(wx - 0.05, by + 0.08, wz + 0.2), 0.10,
               RAYLIBColor(255, 80, 100, 200))
    DrawSphere(Vector3(wx + 0.06, by + 0.04, wz + 0.25), 0.06,
               RAYLIBColor(255, 150, 160, 220))
    // Sparkle
    DrawSphere(Vector3(wx + 0.05, by + 0.12, wz + 0.25), 0.04,
               RAYLIBColor(255, 255, 255, 200))
    // Glow
    DrawSphere(Vector3(wx, by, wz + 0.2), 0.30,
               RAYLIBColor(255, 30, 60, 35))

func dave_drawGoldRing3D wx, wy, wz
    bob = sin(animTime * 2.5 + wx * 1.5) * 0.10
    by = wy + bob

    // Gold ring (torus approximation with spheres in a circle)
    ringR = 0.16
    for a = 0 to 11
        ang = a * 0.5236  // 30 degrees
        rx = wx + cos(ang) * ringR
        ry = by + sin(ang) * ringR
        DrawSphere(Vector3(rx, ry, wz + 0.2), 0.06,
                   RAYLIBColor(255, 200, 30, 255))
    next
    // Center glow
    DrawSphere(Vector3(wx, by, wz + 0.2), ringR - 0.02,
               RAYLIBColor(255, 220, 80, 60))
    // Outer glow
    DrawSphere(Vector3(wx, by, wz + 0.2), ringR + 0.12,
               RAYLIBColor(255, 200, 0, 30))
    // Sparkle
    sp = sin(animTime * 6.0) * 0.5 + 0.5
    DrawSphere(Vector3(wx, by + ringR, wz + 0.25), 0.04,
               RAYLIBColor(255, 255, 220, floor(sp * 200)))

func dave_drawKey3D wx, wy, wz
    bob = sin(animTime * 4.0) * 0.12
    by = wy + bob

    // Key head (ring)
    for a = 0 to 7
        ang = a * 0.7854
        kx = wx + cos(ang) * 0.12
        ky = by + 0.12 + sin(ang) * 0.12
        DrawSphere(Vector3(kx, ky, wz + 0.3), 0.04,
                   RAYLIBColor(255, 220, 50, 255))
    next
    // Key shaft
    DrawCube(Vector3(wx, by - 0.08, wz + 0.3), 0.05, 0.25, 0.05,
             RAYLIBColor(255, 200, 30, 255))
    // Key teeth
    DrawCube(Vector3(wx + 0.06, by - 0.18, wz + 0.3), 0.08, 0.05, 0.05,
             RAYLIBColor(255, 200, 30, 255))
    DrawCube(Vector3(wx + 0.06, by - 0.12, wz + 0.3), 0.06, 0.04, 0.05,
             RAYLIBColor(255, 200, 30, 255))
    // Glow
    glowA = floor((sin(animTime * 5.0) * 0.3 + 0.7) * 60)
    DrawSphere(Vector3(wx, by, wz + 0.3), 0.30,
               RAYLIBColor(255, 255, 100, glowA))

func dave_drawTrophy3D wx, wy, wz
    bob = sin(animTime * 2.0) * 0.05
    by = wy + bob
    glow = sin(animTime * 3.0) * 0.3 + 0.7

    // Base
    DrawCube(Vector3(wx, by - 0.25, wz + 0.2), 0.35, 0.08, 0.35,
             RAYLIBColor(180, 140, 20, 255))
    // Stem
    DrawCylinder(Vector3(wx, by - 0.22, wz + 0.2), 0.06, 0.08, 0.18, 8,
                 RAYLIBColor(200, 160, 30, 255))
    // Cup body
    DrawCylinder(Vector3(wx, by - 0.04, wz + 0.2), 0.12, 0.22, 0.28, 10,
                 RAYLIBColor(255, 210, 40, 255))
    // Cup highlight
    DrawCylinder(Vector3(wx, by + 0.02, wz + 0.2), 0.08, 0.18, 0.20, 10,
                 RAYLIBColor(255, 240, 120, 120))
    // Handles (two side spheres)
    DrawSphere(Vector3(wx - 0.28, by + 0.10, wz + 0.2), 0.07,
               RAYLIBColor(230, 190, 30, 255))
    DrawSphere(Vector3(wx + 0.28, by + 0.10, wz + 0.2), 0.07,
               RAYLIBColor(230, 190, 30, 255))
    // Glow
    gA = floor(glow * 50)
    DrawSphere(Vector3(wx, by + 0.10, wz + 0.2), 0.40,
               RAYLIBColor(255, 220, 50, gA))

func dave_drawGunPickup3D wx, wy, wz
    bob = sin(animTime * 3.5) * 0.10
    by = wy + bob
    glow = sin(animTime * 4.0) * 0.3 + 0.7

    // Gun body (dark metal)
    DrawCube(Vector3(wx, by, wz + 0.25), 0.35, 0.12, 0.10,
             RAYLIBColor(60, 60, 70, 255))
    // Barrel
    DrawCube(Vector3(wx + 0.22, by + 0.02, wz + 0.25), 0.18, 0.07, 0.07,
             RAYLIBColor(80, 80, 90, 255))
    // Barrel tip
    DrawSphere(Vector3(wx + 0.32, by + 0.02, wz + 0.25), 0.04,
               RAYLIBColor(100, 100, 110, 255))
    // Handle
    DrawCube(Vector3(wx - 0.05, by - 0.12, wz + 0.25), 0.08, 0.16, 0.08,
             RAYLIBColor(90, 55, 25, 255))
    // Trigger guard
    DrawCube(Vector3(wx + 0.04, by - 0.08, wz + 0.30), 0.10, 0.03, 0.02,
             RAYLIBColor(70, 70, 80, 255))
    // Orange glow
    glA = floor(glow * 60)
    DrawSphere(Vector3(wx, by, wz + 0.25), 0.35,
               RAYLIBColor(255, 150, 0, glA))

// =============================================================

// =============================================================
// 3D Drawing: New Objects (Movers, Icicles, Crumbles, Wind, Checkpoints)
// =============================================================

func dave_drawMovers3D
    nMovers = len(movers)
    for m = 1 to nMovers
        mx = movers[m][1]
        if fabs(mx - px) > 20 loop ok
        mxs = mx * CELL_SZ
        my = movers[m][2] * CELL_SZ
        mw = movers[m][8]
        DrawCube(Vector3(mxs, my, 0.0), mw, 0.18, 0.9,
                 RAYLIBColor(180, 200, 220, 255))
        DrawCube(Vector3(mxs, my + 0.10, 0.0), mw - 0.1, 0.03, 0.8,
                 RAYLIBColor(220, 235, 255, 200))
        DrawCube(Vector3(mxs, my - 0.10, 0.0), mw - 0.05, 0.03, 0.85,
                 RAYLIBColor(100, 110, 130, 200))
        glow = sin(animTime * 3.0) * 0.3 + 0.7
        glA = floor(glow * 100)
        DrawSphere(Vector3(mxs - mw * 0.4, my + 0.05, 0.4), 0.05,
                   RAYLIBColor(100, 200, 255, glA))
        DrawSphere(Vector3(mxs + mw * 0.4, my + 0.05, 0.4), 0.05,
                   RAYLIBColor(100, 200, 255, glA))
    next

func dave_drawIcicles3D
    nIcicles = len(icicles)
    for i = 1 to nIcicles
        state = icicles[i][3]
        if state = 3 loop ok
        if fabs(icicles[i][1] - px) > 20 loop ok
        ix = icicles[i][1] * CELL_SZ
        iy = icicles[i][2] * CELL_SZ
        shakeX = 0.0
        if state = 1
            shakeX = sin(animTime * 40.0) * 0.05
        ok
        DrawCylinder(Vector3(ix + shakeX, iy - 0.3, 0.2), 0.15, 0.02, 0.6, 6,
                     RAYLIBColor(180, 220, 255, 230))
        DrawSphere(Vector3(ix + shakeX, iy - 0.55, 0.2), 0.04,
                   RAYLIBColor(200, 240, 255, 200))
        DrawCube(Vector3(ix + shakeX, iy + 0.05, 0.2), 0.20, 0.10, 0.15,
                 RAYLIBColor(200, 230, 255, 255))
    next

func dave_drawCrumble3D wx, wy, wz, row, col
    crState = 0
    crTimer = 0.0
    nCrumbles = len(crumbles)
    for i = 1 to nCrumbles
        if crumbles[i][1] = col and crumbles[i][2] = row
            crState = crumbles[i][4]
            crTimer = crumbles[i][3]
        ok
    next
    if crState = 2 return ok
    shakeX = 0.0
    if crState = 1
        shakeX = sin(animTime * 30.0) * 0.04
    ok
    alpha = 255
    if crState = 1
        alpha = floor(crTimer / 0.8 * 255)
        if alpha < 80 alpha = 80 ok
    ok
    DrawCube(Vector3(wx + shakeX, wy, wz), 0.96, 0.14, 0.9,
             RAYLIBColor(190, 210, 230, alpha))
    DrawCube(Vector3(wx + shakeX - 0.15, wy + 0.03, wz + 0.42), 0.30, 0.02, 0.01,
             RAYLIBColor(140, 160, 180, alpha))
    DrawCube(Vector3(wx + shakeX + 0.10, wy - 0.01, wz + 0.42), 0.25, 0.02, 0.01,
             RAYLIBColor(140, 160, 180, alpha))
    DrawCube(Vector3(wx + shakeX, wy + 0.08, wz), 0.90, 0.02, 0.85,
             RAYLIBColor(220, 235, 250, floor(alpha * 0.7)))

func dave_drawWind3D wx, wy, wz, tileType
    wDir = 1
    if tileType = T_WIND_L wDir = -1 ok

    // Semi-transparent background tint to mark wind zone
    DrawCube(Vector3(wx, wy, wz + 0.1), 0.95, 0.95, 0.1,
             RAYLIBColor(150, 210, 255, 25))

    // Animated arrow-like streaks (thicker and more visible)
    for s = 0 to 3
        phase = animTime * 2.5 + s * 1.5 + wx * 0.3 + wy * 0.2
        t = phase - floor(phase)
        streakX = wx + (t - 0.5) * 0.85 * wDir
        streakY = wy + s * 0.22 - 0.33
        // Fade in then out
        alpha = floor((1.0 - fabs(t - 0.5) * 2.0) * 160)
        if alpha < 0 alpha = 0 ok

        // Main streak (wider)
        DrawCube(Vector3(streakX, streakY, wz + 0.35), 0.35, 0.035, 0.02,
                 RAYLIBColor(130, 200, 255, alpha))

        // Arrow head (two angled lines forming a >)
        tipX = streakX + wDir * 0.18
        DrawCube(Vector3(tipX, streakY + 0.04, wz + 0.36), 0.12, 0.025, 0.01,
                 RAYLIBColor(130, 200, 255, alpha))
        DrawCube(Vector3(tipX, streakY - 0.04, wz + 0.36), 0.12, 0.025, 0.01,
                 RAYLIBColor(130, 200, 255, alpha))
    next

    // Subtle swirl particles
    sparkPhase = animTime * 4.0 + wx * 1.7 + wy * 0.9
    sparkT = sparkPhase - floor(sparkPhase)
    sparkX = wx + (sparkT - 0.5) * 0.7 * wDir
    sparkY = wy + sin(sparkPhase * 3.0) * 0.2
    sparkA = floor((1.0 - fabs(sparkT - 0.5) * 2.0) * 120)
    if sparkA < 0 sparkA = 0 ok
    DrawSphere(Vector3(sparkX, sparkY, wz + 0.4), 0.03,
               RAYLIBColor(180, 230, 255, sparkA))

func dave_drawCheckpoint3D wx, wy, wz
    // Flag pole
    DrawCube(Vector3(wx, wy + 0.2, wz + 0.3), 0.04, 0.8, 0.04,
             RAYLIBColor(180, 180, 190, 255))
    // Flag (green if active, grey if not)
    flagWave = sin(animTime * 4.0 + wx) * 0.05
    if checkpointActive and fabs(checkpointX - wx) < 1.5
        DrawCube(Vector3(wx + 0.15 + flagWave, wy + 0.45, wz + 0.3),
                 0.24, 0.16, 0.02, RAYLIBColor(50, 220, 50, 255))
        // Glow
        DrawSphere(Vector3(wx, wy + 0.65, wz + 0.3), 0.06,
                   RAYLIBColor(50, 255, 50, floor(sin(animTime * 5.0) * 50 + 100)))
    else
        DrawCube(Vector3(wx + 0.15 + flagWave, wy + 0.45, wz + 0.3),
                 0.24, 0.16, 0.02, RAYLIBColor(150, 150, 160, 255))
    ok
    // Base
    DrawCube(Vector3(wx, wy - 0.18, wz + 0.3), 0.20, 0.06, 0.20,
             RAYLIBColor(140, 140, 150, 255))

// 3D Drawing: Player
// =============================================================

func dave_drawPlayer3D
    if gameState = ST_DYING
        return  // Particles handle death visual
    ok

    if gameState != ST_PLAYING and
       gameState != ST_PAUSED and gameState != ST_LEVELUP
        return
    ok

    wx = px * CELL_SZ
    wy = py * CELL_SZ + 0.5
    wz = 0.0
    fDir = 1
    if !pFacingRight fDir = -1 ok

    // On ladder: face into the screen (toward ladder, away from camera)
    onLadder = pOnLadder

    // Gentle bob while walking
    walkBob = 0.0
    if pOnGround and pvx != 0
        walkBob = sin(pWalkFrame) * 0.04
    ok

    // Climb bob on ladder
    climbBob = 0.0
    if onLadder and pvy != 0
        climbBob = sin(pClimbFrame) * 0.03
    ok

    // === Shadow on ground ===
    DrawCylinder(Vector3(wx, py * CELL_SZ - 0.02, wz + 0.1),
                 0.25, 0.30, 0.01, 12,
                 RAYLIBColor(0, 0, 0, 50))

    // === Determine body Z offset for ladder (face into screen) ===
    bodyZ = wz + 0.1
    frontZ = wz + 0.22
    if onLadder
        bodyZ = wz - 0.05
        frontZ = wz - 0.15
    ok

    // === Determine if airborne (jumping/falling) ===
    inAir = false
    if !pOnGround and !onLadder
        inAir = true
    ok

    // === Boots (brown) ===
    bootY = wy - 0.32 + walkBob + climbBob
    lbOff = 0.0
    rbOff = 0.0
    // Jump leg offsets: front leg raised, back leg trails
    lbJumpX = 0.0
    rbJumpX = 0.0
    lbJumpY = 0.0
    rbJumpY = 0.0
    if onLadder and pvy != 0
        // Climbing: alternate feet up/down
        lbOff = sin(pClimbFrame) * 0.12
        rbOff = sin(pClimbFrame + 3.14159) * 0.12
    but inAir
        // Jumping: front leg bends up and forward, back leg hangs straight
        // Use Z offset so both legs are visible from side camera
        jumpBend = 0.0
        if pvy > 0
            jumpBend = 0.30
        but pvy < -2.0
            jumpBend = 0.12
        else
            jumpBend = 0.20
        ok
        // Front leg raises up and bends forward
        rbJumpY = jumpBend
        rbJumpX = fDir * 0.08
        // Back leg hangs straight down (no X offset - stays visible)
    but pOnGround and pvx != 0
        lbOff = sin(pWalkFrame) * 0.06
        rbOff = sin(pWalkFrame + 3.14159) * 0.06
    ok
    if onLadder
        // Feet side by side, offset vertically for climbing
        DrawCube(Vector3(wx - 0.08, bootY + lbOff, wz + 0.15),
                 0.12, 0.12, 0.14, RAYLIBColor(100, 60, 20, 255))
        DrawCube(Vector3(wx + 0.08, bootY + rbOff, wz + 0.15),
                 0.12, 0.12, 0.14, RAYLIBColor(100, 60, 20, 255))
        DrawCube(Vector3(wx - 0.08, bootY + lbOff - 0.06, wz + 0.18),
                 0.14, 0.04, 0.16, RAYLIBColor(40, 25, 10, 255))
        DrawCube(Vector3(wx + 0.08, bootY + rbOff - 0.06, wz + 0.18),
                 0.14, 0.04, 0.16, RAYLIBColor(40, 25, 10, 255))
    else
        // Back foot - slightly further from camera when jumping
        backZ = wz + 0.15
        frontZ2 = wz + 0.15
        if inAir
            backZ = wz + 0.08
            frontZ2 = wz + 0.22
        ok
        DrawCube(Vector3(wx - 0.08 * fDir + lbOff * fDir + lbJumpX, bootY + lbJumpY, backZ),
                 0.12, 0.12, 0.14, RAYLIBColor(100, 60, 20, 255))
        DrawCube(Vector3(wx - 0.08 * fDir + lbOff * fDir + lbJumpX, bootY + lbJumpY - 0.06, backZ + 0.03),
                 0.14, 0.04, 0.16, RAYLIBColor(40, 25, 10, 255))
        // Front foot - closer to camera when jumping, raised
        DrawCube(Vector3(wx + 0.08 * fDir + rbOff * fDir + rbJumpX, bootY + rbJumpY, frontZ2),
                 0.12, 0.12, 0.14, RAYLIBColor(100, 60, 20, 255))
        DrawCube(Vector3(wx + 0.08 * fDir + rbOff * fDir + rbJumpX, bootY + rbJumpY - 0.06, frontZ2 + 0.03),
                 0.14, 0.04, 0.16, RAYLIBColor(40, 25, 10, 255))
    ok

    // === Legs (blue pants) ===
    legY = wy - 0.16 + walkBob + climbBob
    if onLadder
        DrawCube(Vector3(wx - 0.06, legY + lbOff * 0.5, wz + 0.12),
                 0.10, 0.22, 0.10, RAYLIBColor(30, 50, 150, 255))
        DrawCube(Vector3(wx + 0.06, legY + rbOff * 0.5, wz + 0.12),
                 0.10, 0.22, 0.10, RAYLIBColor(30, 50, 150, 255))
    else
        // Back leg
        backLegZ = wz + 0.12
        frontLegZ = wz + 0.12
        if inAir
            backLegZ = wz + 0.05
            frontLegZ = wz + 0.19
        ok
        DrawCube(Vector3(wx - 0.06 * fDir + lbOff * fDir * 0.5 + lbJumpX * 0.5, legY + lbJumpY * 0.5, backLegZ),
                 0.10, 0.22, 0.10, RAYLIBColor(30, 50, 150, 255))
        // Front leg
        DrawCube(Vector3(wx + 0.06 * fDir + rbOff * fDir * 0.5 + rbJumpX * 0.5, legY + rbJumpY * 0.5, frontLegZ),
                 0.10, 0.22, 0.10, RAYLIBColor(30, 50, 150, 255))
    ok

    // === Body (red shirt like Dave!) ===
    bodyY = wy + 0.08 + walkBob + climbBob
    DrawCube(Vector3(wx, bodyY, bodyZ), 0.28, 0.30, 0.22,
             RAYLIBColor(200, 30, 30, 255))
    // Shirt highlight (on the visible side)
    DrawCube(Vector3(wx, bodyY + 0.06, frontZ), 0.22, 0.18, 0.01,
             RAYLIBColor(240, 60, 50, 150))

    // === Belt ===
    DrawCube(Vector3(wx, wy - 0.04 + walkBob + climbBob, frontZ), 0.30, 0.05, 0.01,
             RAYLIBColor(80, 60, 20, 255))
    // Belt buckle
    DrawSphere(Vector3(wx, wy - 0.04 + walkBob + climbBob, frontZ + 0.02), 0.035,
               RAYLIBColor(220, 200, 50, 255))

    // === Arms ===
    if onLadder
        // Climbing: arms reach up alternately, gripping the ladder
        lArmUp = sin(pClimbFrame) * 0.18
        rArmUp = sin(pClimbFrame + 3.14159) * 0.18
        // Left arm reaching up on ladder
        DrawCube(Vector3(wx - 0.20, bodyY + 0.06 + lArmUp, wz + 0.12),
                 0.08, 0.24, 0.08, RAYLIBColor(200, 30, 30, 255))
        DrawSphere(Vector3(wx - 0.20, bodyY + 0.18 + lArmUp, wz + 0.12),
                   0.05, RAYLIBColor(230, 180, 140, 255))
        // Right arm reaching up on ladder
        DrawCube(Vector3(wx + 0.20, bodyY + 0.06 + rArmUp, wz + 0.12),
                 0.08, 0.24, 0.08, RAYLIBColor(200, 30, 30, 255))
        DrawSphere(Vector3(wx + 0.20, bodyY + 0.18 + rArmUp, wz + 0.12),
                   0.05, RAYLIBColor(230, 180, 140, 255))
    else
        // Arm angles - different for walking vs jumping
        lAngle = 0.0
        rAngle = 0.0
        if inAir
            // Jumping: back arm reaches forward-up, front arm trails back-down
            if pvy > 0
                // Rising - dynamic pose
                lAngle = -0.4    // back arm swings forward
                rAngle = 0.35   // front arm swings back
            but pvy < -2.0
                // Falling - arms spread slightly
                lAngle = -0.2
                rAngle = 0.2
            else
                // Peak of jump
                lAngle = -0.3
                rAngle = 0.25
            ok
        but pOnGround and pvx != 0
            // Walking: natural cross-body swing
            lAngle = sin(pWalkFrame + 3.14159) * 0.5
            rAngle = sin(pWalkFrame) * 0.5
        ok

        // Back arm - shoulder anchored to body
        lShX = wx - 0.20 * fDir
        lShY = bodyY + 0.04
        // Upper arm (fixed at shoulder, tilts slightly)
        lUaX = lShX + sin(lAngle) * 0.04 * fDir
        lUaY = lShY - 0.08 - (1.0 - cos(lAngle)) * 0.02
        DrawCube(Vector3(lUaX, lUaY, wz + 0.12),
                 0.08, 0.16, 0.08, RAYLIBColor(200, 30, 30, 255))
        // Forearm + hand (swings from elbow)
        lHdX = lShX + sin(lAngle) * 0.12 * fDir
        lHdY = lShY - 0.22 - (1.0 - cos(lAngle)) * 0.04
        DrawCube(Vector3(lHdX, lHdY, wz + 0.12),
                 0.07, 0.14, 0.07, RAYLIBColor(200, 30, 30, 255))
        DrawSphere(Vector3(lHdX, lHdY - 0.08, wz + 0.12),
                   0.05, RAYLIBColor(230, 180, 140, 255))

        // Front arm - shoulder anchored to body
        rShX = wx + 0.20 * fDir
        rShY = bodyY + 0.04
        // Upper arm
        rUaX = rShX + sin(rAngle) * 0.04 * fDir
        rUaY = rShY - 0.08 - (1.0 - cos(rAngle)) * 0.02
        DrawCube(Vector3(rUaX, rUaY, wz + 0.12),
                 0.08, 0.16, 0.08, RAYLIBColor(200, 30, 30, 255))
        // Forearm + hand
        rHdX = rShX + sin(rAngle) * 0.12 * fDir
        rHdY = rShY - 0.22 - (1.0 - cos(rAngle)) * 0.04
        DrawCube(Vector3(rHdX, rHdY, wz + 0.12),
                 0.07, 0.14, 0.07, RAYLIBColor(200, 30, 30, 255))
        DrawSphere(Vector3(rHdX, rHdY - 0.08, wz + 0.12),
                   0.05, RAYLIBColor(230, 180, 140, 255))
    ok

    // === Head ===
    headY = wy + 0.32 + walkBob + climbBob

    if onLadder
        // Facing away from camera: head pushed back, show back of head
        // Face (skin) - pushed away from camera (into the screen)
        DrawSphere(Vector3(wx, headY, wz - 0.05), 0.16,
                   RAYLIBColor(230, 180, 140, 255))
        // Cap covers back of head (toward camera)
        DrawSphere(Vector3(wx, headY + 0.08, wz + 0.08), 0.17,
                   RAYLIBColor(200, 20, 20, 255))
        // Cap button on top
        DrawSphere(Vector3(wx, headY + 0.18, wz + 0.05), 0.04,
                   RAYLIBColor(255, 50, 50, 255))
        // Hair/neck visible at back (closest to camera)
        DrawSphere(Vector3(wx, headY - 0.04, wz + 0.18), 0.10,
                   RAYLIBColor(100, 60, 30, 255))
    else
        // Face (skin) - toward camera
        DrawSphere(Vector3(wx, headY, wz + 0.15), 0.16,
                   RAYLIBColor(230, 180, 140, 255))
        // Normal facing: show face, eyes, cap brim
        // Cheek blush
        DrawSphere(Vector3(wx + fDir * 0.10, headY - 0.03, wz + 0.25), 0.05,
                   RAYLIBColor(240, 140, 120, 100))

        // === Cap (red like Dave!) ===
        DrawSphere(Vector3(wx, headY + 0.08, wz + 0.12), 0.17,
                   RAYLIBColor(200, 20, 20, 255))
        // Cap brim
        DrawCube(Vector3(wx + fDir * 0.10, headY + 0.02, wz + 0.22),
                 0.22, 0.04, 0.14, RAYLIBColor(180, 15, 15, 255))
        // Cap button
        DrawSphere(Vector3(wx, headY + 0.18, wz + 0.12), 0.04,
                   RAYLIBColor(255, 50, 50, 255))

        // === Eyes ===
        eyeY = headY + 0.02
        eyeFwd = 0.20
        // White sclera
        DrawSphere(Vector3(wx + fDir * 0.06, eyeY, wz + eyeFwd), 0.05,
                   RAYLIBColor(255, 255, 255, 255))
        // Pupil (looks in facing direction)
        DrawSphere(Vector3(wx + fDir * 0.08, eyeY - 0.01, wz + eyeFwd + 0.02),
                   0.03, RAYLIBColor(20, 20, 80, 255))
        // Specular
        DrawSphere(Vector3(wx + fDir * 0.05, eyeY + 0.02, wz + eyeFwd + 0.01),
                   0.015, RAYLIBColor(255, 255, 255, 200))

        // === Mouth (small smile) ===
        DrawSphere(Vector3(wx + fDir * 0.04, headY - 0.06, wz + 0.26), 0.025,
                   RAYLIBColor(180, 80, 80, 255))
    ok

    // Key indicator on belt
    if hasKey
        keyGlow = sin(animTime * 6.0) * 0.3 + 0.7
        DrawSphere(Vector3(wx + fDir * 0.15, wy - 0.02 + walkBob, frontZ + 0.03),
                   0.05, RAYLIBColor(255, 220, 50, floor(keyGlow * 255)))
    ok

    // Gun in hand when player has gun (not on ladder)
    if hasGun and !onLadder
        gunX = wx + fDir * 0.26
        gunY = bodyY - 0.04
        // Gun body
        DrawCube(Vector3(gunX, gunY, wz + 0.20), 0.18, 0.07, 0.06,
                 RAYLIBColor(60, 60, 70, 255))
        // Barrel
        DrawCube(Vector3(gunX + fDir * 0.14, gunY + 0.02, wz + 0.20),
                 0.12, 0.04, 0.04, RAYLIBColor(80, 80, 90, 255))
        // Muzzle flash when shooting
        if pShootCooldown > 0.15
            DrawSphere(Vector3(gunX + fDir * 0.22, gunY + 0.02, wz + 0.20),
                       0.06, RAYLIBColor(255, 200, 50, 200))
        ok
    ok

// =============================================================
// 3D Drawing: Enemies
// =============================================================

func dave_drawEnemies3D
    nEnemies = len(enemies)
    for e = 1 to nEnemies
        if !enemies[e][6] loop ok
        if fabs(enemies[e][1] - px) > 20 loop ok

        ex = enemies[e][1] * CELL_SZ
        ey = enemies[e][2] * CELL_SZ + 0.5
        ez = 0.0
        eType = enemies[e][5]
        eAnim = enemies[e][7]
        eFacing = 1
        if enemies[e][3] < 0 eFacing = -1 ok

        if eType = 1
            // Walking enemy - armored guard
            bob2 = sin(eAnim * 6.0) * 0.03

            // Shadow
            DrawCylinder(Vector3(ex, enemies[e][2] * CELL_SZ - 0.02, ez + 0.1),
                         0.22, 0.26, 0.01, 10,
                         RAYLIBColor(0, 0, 0, 40))

            // Feet
            fOff = sin(eAnim * 5.0) * 0.05
            DrawCube(Vector3(ex - 0.06 + fOff, ey - 0.34 + bob2, ez + 0.15),
                     0.10, 0.10, 0.12, RAYLIBColor(50, 50, 60, 255))
            DrawCube(Vector3(ex + 0.06 - fOff, ey - 0.34 + bob2, ez + 0.15),
                     0.10, 0.10, 0.12, RAYLIBColor(50, 50, 60, 255))

            // Body (dark armor)
            DrawCube(Vector3(ex, ey - 0.05 + bob2, ez + 0.1), 0.26, 0.36, 0.20,
                     RAYLIBColor(60, 60, 80, 255))
            // Armor shine
            DrawCube(Vector3(ex, ey + 0.02 + bob2, ez + 0.21), 0.20, 0.24, 0.01,
                     RAYLIBColor(90, 90, 120, 130))

            // Head (helmet)
            DrawSphere(Vector3(ex, ey + 0.18 + bob2, ez + 0.15), 0.14,
                       RAYLIBColor(70, 70, 90, 255))
            // Visor
            DrawCube(Vector3(ex + eFacing * 0.04, ey + 0.16 + bob2, ez + 0.25),
                     0.18, 0.06, 0.04, RAYLIBColor(20, 20, 30, 255))
            // Red eyes behind visor
            DrawSphere(Vector3(ex + eFacing * 0.04, ey + 0.17 + bob2, ez + 0.27),
                       0.025, RAYLIBColor(255, 30, 30, 255))
            DrawSphere(Vector3(ex + eFacing * 0.10, ey + 0.17 + bob2, ez + 0.27),
                       0.025, RAYLIBColor(255, 30, 30, 255))
            // Eye glow
            DrawSphere(Vector3(ex + eFacing * 0.07, ey + 0.17 + bob2, ez + 0.27),
                       0.06, RAYLIBColor(255, 30, 0, 40))

            // Weapon (sword)
            DrawCube(Vector3(ex + eFacing * 0.22, ey - 0.10 + bob2, ez + 0.18),
                     0.04, 0.35, 0.04, RAYLIBColor(180, 180, 200, 255))
            // Sword tip
            DrawSphere(Vector3(ex + eFacing * 0.22, ey + 0.08 + bob2, ez + 0.18),
                       0.03, RAYLIBColor(220, 220, 240, 255))
        ok

        if eType = 2
            // Flying enemy - bat
            wingFlap = sin(eAnim * 10.0) * 0.4
            bob3 = sin(eAnim * 2.5) * 0.15

            // Colors depend on world theme
            if level <= 10
                // Purple bat (red & blue worlds)
                bodyR = 50   bodyG = 20   bodyB = 60
                bellyR = 80  bellyG = 40  bellyB = 80
                wingR = 60   wingG = 25   wingB = 70
                wingTR = 50  wingTG = 20  wingTB = 55
                eyeR = 255   eyeG = 200   eyeB = 0
                bordR = 30   bordG = 10   bordB = 40
            but level <= 15
                // White ghost bat (ice world)
                bodyR = 240  bodyG = 245  bodyB = 255
                bellyR = 220 bellyG = 225 bellyB = 235
                wingR = 235  wingG = 240  wingB = 250
                wingTR = 210 wingTG = 215 wingTB = 225
                eyeR = 255   eyeG = 30    eyeB = 30
                bordR = 30   bordG = 30   bordB = 40
            else
                // Dark brown bat (yellow/sand world)
                bodyR = 80   bodyG = 50   bodyB = 20
                bellyR = 110 bellyG = 75  bellyB = 35
                wingR = 90   wingG = 60   wingB = 25
                wingTR = 70  wingTG = 45  wingTB = 15
                eyeR = 255   eyeG = 200   eyeB = 50
                bordR = 40   bordG = 25   bordB = 10
            ok

            // Body with black outline
            DrawSphere(Vector3(ex, ey + bob3, ez + 0.18), 0.16,
                       RAYLIBColor(bordR, bordG, bordB, 255))
            DrawSphere(Vector3(ex, ey + bob3, ez + 0.2), 0.14,
                       RAYLIBColor(bodyR, bodyG, bodyB, 255))
            // Belly
            DrawSphere(Vector3(ex, ey - 0.06 + bob3, ez + 0.22), 0.10,
                       RAYLIBColor(bellyR, bellyG, bellyB, 255))

            // Wings with black border
            // Left wing - border then fill
            DrawCube(Vector3(ex - 0.25, ey + 0.05 + bob3 + wingFlap * 0.15,
                            ez + 0.16),
                     0.30, 0.06, 0.20, RAYLIBColor(bordR, bordG, bordB, 255))
            DrawCube(Vector3(ex - 0.25, ey + 0.05 + bob3 + wingFlap * 0.15,
                            ez + 0.18),
                     0.28, 0.04, 0.18, RAYLIBColor(wingR, wingG, wingB, 255))
            DrawCube(Vector3(ex - 0.38, ey + 0.08 + bob3 + wingFlap * 0.25,
                            ez + 0.16),
                     0.16, 0.05, 0.16, RAYLIBColor(bordR, bordG, bordB, 255))
            DrawCube(Vector3(ex - 0.38, ey + 0.08 + bob3 + wingFlap * 0.25,
                            ez + 0.18),
                     0.14, 0.03, 0.14, RAYLIBColor(wingTR, wingTG, wingTB, 255))
            // Right wing - border then fill
            DrawCube(Vector3(ex + 0.25, ey + 0.05 + bob3 + wingFlap * 0.15,
                            ez + 0.16),
                     0.30, 0.06, 0.20, RAYLIBColor(bordR, bordG, bordB, 255))
            DrawCube(Vector3(ex + 0.25, ey + 0.05 + bob3 + wingFlap * 0.15,
                            ez + 0.18),
                     0.28, 0.04, 0.18, RAYLIBColor(wingR, wingG, wingB, 255))
            DrawCube(Vector3(ex + 0.38, ey + 0.08 + bob3 + wingFlap * 0.25,
                            ez + 0.16),
                     0.16, 0.05, 0.16, RAYLIBColor(bordR, bordG, bordB, 255))
            DrawCube(Vector3(ex + 0.38, ey + 0.08 + bob3 + wingFlap * 0.25,
                            ez + 0.18),
                     0.14, 0.03, 0.14, RAYLIBColor(wingTR, wingTG, wingTB, 255))

            // Eyes (glowing)
            DrawSphere(Vector3(ex - 0.05, ey + 0.06 + bob3, ez + 0.30),
                       0.04, RAYLIBColor(eyeR, eyeG, eyeB, 255))
            DrawSphere(Vector3(ex + 0.05, ey + 0.06 + bob3, ez + 0.30),
                       0.04, RAYLIBColor(eyeR, eyeG, eyeB, 255))
            // Eye glow
            DrawSphere(Vector3(ex, ey + 0.06 + bob3, ez + 0.30),
                       0.08, RAYLIBColor(eyeR, eyeG, eyeB, 30))

            // Fangs
            DrawCube(Vector3(ex - 0.03, ey - 0.08 + bob3, ez + 0.28),
                     0.02, 0.05, 0.02, RAYLIBColor(255, 255, 255, 255))
            DrawCube(Vector3(ex + 0.03, ey - 0.08 + bob3, ez + 0.28),
                     0.02, 0.05, 0.02, RAYLIBColor(255, 255, 255, 255))
        ok

        if eType = 3
            // Shooting enemy - armored soldier with gun
            bob4 = sin(eAnim * 5.0) * 0.03

            // Shadow
            DrawCylinder(Vector3(ex, enemies[e][2] * CELL_SZ - 0.02, ez + 0.1),
                         0.22, 0.26, 0.01, 10, RAYLIBColor(0, 0, 0, 40))

            // Feet
            fOff2 = sin(eAnim * 4.0) * 0.04
            DrawCube(Vector3(ex - 0.06 + fOff2, ey - 0.34 + bob4, ez + 0.15),
                     0.10, 0.10, 0.12, RAYLIBColor(40, 50, 30, 255))
            DrawCube(Vector3(ex + 0.06 - fOff2, ey - 0.34 + bob4, ez + 0.15),
                     0.10, 0.10, 0.12, RAYLIBColor(40, 50, 30, 255))

            // Body (military green armor)
            DrawCube(Vector3(ex, ey - 0.05 + bob4, ez + 0.1), 0.28, 0.36, 0.22,
                     RAYLIBColor(50, 80, 40, 255))
            // Armor plate
            DrawCube(Vector3(ex, ey + 0.02 + bob4, ez + 0.22), 0.22, 0.26, 0.01,
                     RAYLIBColor(70, 100, 55, 130))

            // Head (helmet with red visor)
            DrawSphere(Vector3(ex, ey + 0.20 + bob4, ez + 0.15), 0.15,
                       RAYLIBColor(50, 70, 35, 255))
            // Visor (red - menacing)
            DrawCube(Vector3(ex + eFacing * 0.04, ey + 0.18 + bob4, ez + 0.26),
                     0.20, 0.07, 0.04, RAYLIBColor(180, 20, 20, 255))
            // Visor glow
            DrawSphere(Vector3(ex + eFacing * 0.07, ey + 0.18 + bob4, ez + 0.28),
                       0.05, RAYLIBColor(255, 50, 20, 80))

            // Gun in hand
            DrawCube(Vector3(ex + eFacing * 0.22, ey - 0.02 + bob4, ez + 0.20),
                     0.22, 0.07, 0.06, RAYLIBColor(50, 50, 55, 255))
            // Gun barrel
            DrawCube(Vector3(ex + eFacing * 0.36, ey + 0.0 + bob4, ez + 0.20),
                     0.10, 0.04, 0.04, RAYLIBColor(70, 70, 75, 255))
            // Muzzle flash when shooting
            if enemies[e][8] > 1.8
                DrawSphere(Vector3(ex + eFacing * 0.42, ey + 0.0 + bob4, ez + 0.20),
                           0.07, RAYLIBColor(255, 180, 30, 200))
            ok

            // Ammo belt across body
            DrawCube(Vector3(ex - eFacing * 0.02, ey + 0.06 + bob4, ez + 0.23),
                     0.28, 0.04, 0.02, RAYLIBColor(120, 100, 40, 255))
        ok
    next

// =============================================================
// 3D Drawing: Bullets
// =============================================================

func dave_drawBullets3D
    // Player bullets (yellow/orange energy)
    nBullets = len(bullets)
    for i = 1 to nBullets
        if fabs(bullets[i][1] - px) > 20 loop ok
        bx = bullets[i][1] * CELL_SZ
        by = bullets[i][2] * CELL_SZ
        bz = 0.2
        // Bullet core
        DrawSphere(Vector3(bx, by, bz), 0.08,
                   RAYLIBColor(255, 220, 50, 255))
        // Bullet glow
        DrawSphere(Vector3(bx, by, bz), 0.14,
                   RAYLIBColor(255, 180, 0, 100))
        // Trail
        tDir = -1
        if bullets[i][3] > 0 tDir = 1 ok
        DrawCube(Vector3(bx - tDir * 0.12, by, bz), 0.16, 0.04, 0.04,
                 RAYLIBColor(255, 200, 50, 150))
    next

    // Enemy bullets (red energy)
    nEBullets = len(eBullets)
    for i = 1 to nEBullets
        if fabs(eBullets[i][1] - px) > 20 loop ok
        bx = eBullets[i][1] * CELL_SZ
        by = eBullets[i][2] * CELL_SZ
        bz = 0.2
        // Bullet core
        DrawSphere(Vector3(bx, by, bz), 0.07,
                   RAYLIBColor(255, 40, 40, 255))
        // Bullet glow
        DrawSphere(Vector3(bx, by, bz), 0.12,
                   RAYLIBColor(255, 20, 0, 80))
        // Trail
        DrawCube(Vector3(bx - eBullets[i][3] * 0.02, by - eBullets[i][4] * 0.02, bz),
                 0.10, 0.03, 0.03, RAYLIBColor(255, 60, 30, 120))
    next

// =============================================================
// 3D Drawing: Particles
// =============================================================

func dave_drawParticles3D
    nParticles = len(particles)
    for i = 1 to nParticles
        if fabs(particles[i][1] - px) > 20 loop ok
        life = particles[i][5] / particles[i][6]
        if life < 0 life = 0 ok
        alpha = floor(life * 255)
        if alpha < 0 alpha = 0 ok
        if alpha > 255 alpha = 255 ok
        sz = particles[i][10] * life
        if sz < 0.01 sz = 0.01 ok
        DrawSphere(Vector3(particles[i][1], particles[i][2], 0.3),
                   sz, RAYLIBColor(particles[i][7], particles[i][8],
                                   particles[i][9], alpha))
    next

    // Score popups as 3D text (spheres)
    nPopups = len(popups)
    for i = 1 to nPopups
        if fabs(popups[i][1] - px) > 20 loop ok
        life = popups[i][4]
        alpha = floor(life * 200)
        if alpha > 255 alpha = 255 ok
        if alpha < 0 alpha = 0 ok
        DrawSphere(Vector3(popups[i][1], popups[i][2], 0.5), 0.06,
                   RAYLIBColor(255, 255, 255, alpha))
    next
