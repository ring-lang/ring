/*
**  Color Animation Screensaver - RingRayLib
**  ============================================
**  Mesmerizing animated colors, shapes, and patterns.
**  Like a screensaver - just sit back and watch!
**
**  Controls:
**    1-8             - Switch visual mode
**    N               - Next mode
**    T               - Cycle color palette
**    Space / P       - Pause / Resume
**    B               - Toggle background trails
**    F               - Toggle fullscreen feel (hide HUD)
**    ESC             - Exit
**
**  Modes:
**    1. Plasma       - Flowing color plasma
**    2. Spirograph   - Spinning geometric curves
**    3. Lava Lamp    - Rising/falling color blobs
**    4. Matrix Rain  - Falling color streaks
**    5. Kaleidoscope - Mirrored symmetry patterns
**    6. Waves        - Overlapping sine waves
**    7. Stardust     - Swirling particle galaxy
**    8. Fireworks    - Bursting color explosions
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W = 1024
SCREEN_H = 700

PI = 3.14159265

// Visual modes
MODE_PLASMA      = 1
MODE_SPIROGRAPH  = 2
MODE_LAVALAMP    = 3
MODE_MATRIX      = 4
MODE_KALEIDOSCOPE = 5
MODE_WAVES       = 6
MODE_STARDUST    = 7
MODE_FIREWORKS   = 8
MODE_COUNT       = 8
modeNames = ["Plasma", "Spirograph", "Lava Lamp", "Matrix Rain", "Kaleidoscope", "Waves", "Stardust", "Fireworks"]

// Color palettes
PAL_RAINBOW  = 1
PAL_OCEAN    = 2
PAL_SUNSET   = 3
PAL_NEON     = 4
PAL_FOREST   = 5
PAL_CANDY    = 6
PAL_COUNT    = 6
palNames = ["Rainbow", "Ocean", "Sunset", "Neon", "Forest", "Candy"]

// =============================================================
// State
// =============================================================

currentMode = MODE_PLASMA
currentPal = PAL_RAINBOW
paused = false
showHUD = true
trailMode = true    // semi-transparent bg for trails
animTime = 0.0

// Trail alpha (lower = more trails)
trailAlpha = 20

// Lava lamp blobs
MAX_BLOBS = 15
blobX = list(MAX_BLOBS)
blobY = list(MAX_BLOBS)
blobVX = list(MAX_BLOBS)
blobVY = list(MAX_BLOBS)
blobR = list(MAX_BLOBS)
blobPhase = list(MAX_BLOBS)

for i = 1 to MAX_BLOBS
    blobX[i] = GetRandomValue(100, SCREEN_W - 100) * 1.0
    blobY[i] = GetRandomValue(100, SCREEN_H - 100) * 1.0
    blobVX[i] = (GetRandomValue(-100, 100) / 100.0) * 30
    blobVY[i] = (GetRandomValue(-100, 100) / 100.0) * 30
    blobR[i] = GetRandomValue(40, 90) * 1.0
    blobPhase[i] = GetRandomValue(0, 628) / 100.0
next

// Matrix rain columns
MAX_COLS = 60
matX = list(MAX_COLS)
matY = list(MAX_COLS)
matSpeed = list(MAX_COLS)
matLen = list(MAX_COLS)
matHue = list(MAX_COLS)

for i = 1 to MAX_COLS
    matX[i] = GetRandomValue(0, SCREEN_W)
    matY[i] = GetRandomValue(-SCREEN_H, 0)
    matSpeed[i] = GetRandomValue(150, 500) * 1.0
    matLen[i] = GetRandomValue(80, 300)
    matHue[i] = GetRandomValue(0, 360)
next

// Stardust particles
MAX_STARS = 300
starX = list(MAX_STARS)
starY = list(MAX_STARS)
starAngle = list(MAX_STARS)
starDist = list(MAX_STARS)
starSpeed = list(MAX_STARS)
starSize = list(MAX_STARS)
starHue = list(MAX_STARS)

for i = 1 to MAX_STARS
    starAngle[i] = GetRandomValue(0, 628) / 100.0
    starDist[i] = GetRandomValue(10, 350) * 1.0
    starSpeed[i] = GetRandomValue(20, 80) / 100.0
    starSize[i] = GetRandomValue(10, 35) / 10.0
    starHue[i] = GetRandomValue(0, 360)
next

// Fireworks
MAX_FW = 200
fwActive = list(MAX_FW)
fwX = list(MAX_FW)
fwY = list(MAX_FW)
fwVX = list(MAX_FW)
fwVY = list(MAX_FW)
fwLife = list(MAX_FW)
fwHue = list(MAX_FW)
fwSize = list(MAX_FW)
for i = 1 to MAX_FW
    fwActive[i] = 0
next
fwTimer = 0.0

// Spirograph history
MAX_SPIRO_PTS = 800
spiroX = list(MAX_SPIRO_PTS)
spiroY = list(MAX_SPIRO_PTS)
spiroIdx = 0
spiroCount = 0

// =============================================================
// Main
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Color Animation Screensaver - RingRayLib")
SetTargetFPS(60)
SetExitKey(0)

// First frame: clear to black
BeginDrawing()
    ClearBackground(BLACK)
EndDrawing()

while !WindowShouldClose()
    cs_update()
    BeginDrawing()
        cs_draw()
    EndDrawing()
end

CloseWindow()

// =============================================================
// Update
// =============================================================

func cs_update
    dt = GetFrameTime()
    if dt > 0.05 dt = 0.05 ok

    if IsKeyPressed(KEY_ESCAPE)
        CloseWindow()
        shutdown(0)
    ok

    // Mode selection
    for k = 1 to MODE_COUNT
        if IsKeyPressed(48 + k)
            currentMode = k
            cs_resetTrails()
        ok
    next

    if IsKeyPressed(KEY_N)
        currentMode++
        if currentMode > MODE_COUNT currentMode = 1 ok
        cs_resetTrails()
    ok

    if IsKeyPressed(KEY_T)
        currentPal++
        if currentPal > PAL_COUNT currentPal = 1 ok
    ok

    if IsKeyPressed(KEY_SPACE) or IsKeyPressed(KEY_P)
        paused = !paused
    ok

    if IsKeyPressed(KEY_B)
        trailMode = !trailMode
        if !trailMode cs_resetTrails() ok
    ok

    if IsKeyPressed(KEY_F)
        showHUD = !showHUD
    ok

    if !paused
        animTime += dt
        cs_updateMode(dt)
    ok

func cs_resetTrails
    // Will be cleared on next draw

func cs_updateMode dt
    // Update mode-specific state
    if currentMode = MODE_LAVALAMP
        for i = 1 to MAX_BLOBS
            blobX[i] += blobVX[i] * dt
            blobY[i] += blobVY[i] * dt

            // Bounce off walls
            if blobX[i] < blobR[i]
                blobX[i] = blobR[i]
                blobVX[i] = fabs(blobVX[i])
            ok
            if blobX[i] > SCREEN_W - blobR[i]
                blobX[i] = SCREEN_W - blobR[i]
                blobVX[i] = -fabs(blobVX[i])
            ok
            if blobY[i] < blobR[i]
                blobY[i] = blobR[i]
                blobVY[i] = fabs(blobVY[i])
            ok
            if blobY[i] > SCREEN_H - blobR[i]
                blobY[i] = SCREEN_H - blobR[i]
                blobVY[i] = -fabs(blobVY[i])
            ok

            // Gentle drift
            blobVX[i] += sin(animTime * 0.5 + blobPhase[i]) * 10 * dt
            blobVY[i] += cos(animTime * 0.3 + blobPhase[i]) * 10 * dt

            // Damping
            blobVX[i] *= 0.998
            blobVY[i] *= 0.998
        next
    ok

    if currentMode = MODE_MATRIX
        for i = 1 to MAX_COLS
            matY[i] += matSpeed[i] * dt
            if matY[i] > SCREEN_H + matLen[i]
                matY[i] = -matLen[i]
                matX[i] = GetRandomValue(0, SCREEN_W)
                matSpeed[i] = GetRandomValue(150, 500) * 1.0
                matLen[i] = GetRandomValue(80, 300)
                matHue[i] = GetRandomValue(0, 360)
            ok
        next
    ok

    if currentMode = MODE_FIREWORKS
        fwTimer += dt
        if fwTimer > 0.3
            fwTimer = 0.0
            cs_spawnFirework()
        ok
        for i = 1 to MAX_FW
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
    ok

func cs_spawnFirework
    cx = GetRandomValue(200, SCREEN_W - 200)
    cy = GetRandomValue(150, SCREEN_H - 200)
    hue = GetRandomValue(0, 360)
    count = GetRandomValue(30, 60)

    for p = 1 to count
        slot = 0
        for i = 1 to MAX_FW
            if fwActive[i] = 0
                slot = i
                exit
            ok
        next
        if slot = 0 exit ok

        angle = GetRandomValue(0, 628) / 100.0
        speed = GetRandomValue(80, 300) * 1.0
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

// =============================================================
// Get palette color from 0.0 - 1.0
// =============================================================

func cs_palColor t
    // Wrap t to 0-1
    t = t - floor(t)

    r = 0  g = 0  b = 0

    if currentPal = PAL_RAINBOW
        r = floor((sin(t * PI * 2) + 1) * 127)
        g = floor((sin(t * PI * 2 + 2.094) + 1) * 127)
        b = floor((sin(t * PI * 2 + 4.189) + 1) * 127)
    ok
    if currentPal = PAL_OCEAN
        r = floor(t * 30)
        g = floor(80 + sin(t * PI * 2) * 80)
        b = floor(150 + sin(t * PI * 4) * 105)
    ok
    if currentPal = PAL_SUNSET
        if t < 0.33
            t2 = t / 0.33
            r = floor(30 + t2 * 225)
            g = floor(t2 * 80)
            b = floor(80 + t2 * 60)
        but t < 0.66
            t2 = (t - 0.33) / 0.33
            r = 255
            g = floor(80 + t2 * 140)
            b = floor(140 - t2 * 80)
        else
            t2 = (t - 0.66) / 0.34
            r = 255
            g = floor(220 + t2 * 35)
            b = floor(60 + t2 * 140)
        ok
    ok
    if currentPal = PAL_NEON
        r = floor((sin(t * PI * 6) + 1) * 127)
        g = floor((sin(t * PI * 4 + 1) + 1) * 100)
        b = floor((sin(t * PI * 2 + 3) + 1) * 127)
        // Boost saturation
        mx = r
        if g > mx mx = g ok
        if b > mx mx = b ok
        if mx > 0
            scale = 255.0 / mx
            r = floor(r * scale * 0.8)
            g = floor(g * scale * 0.8)
            b = floor(b * scale * 0.8)
        ok
    ok
    if currentPal = PAL_FOREST
        r = floor(20 + sin(t * PI * 2 + 1) * 60)
        g = floor(100 + sin(t * PI * 2) * 120)
        b = floor(30 + sin(t * PI * 4 + 2) * 50)
    ok
    if currentPal = PAL_CANDY
        r = floor(200 + sin(t * PI * 4) * 55)
        g = floor(100 + sin(t * PI * 6 + 2) * 100)
        b = floor(180 + sin(t * PI * 2 + 4) * 75)
    ok

    if r > 255 r = 255 ok
    if g > 255 g = 255 ok
    if b > 255 b = 255 ok
    if r < 0 r = 0 ok
    if g < 0 g = 0 ok
    if b < 0 b = 0 ok

    return RAYLIBColor(r, g, b, 255)

func cs_palColorA t, alpha
    col = cs_palColor(t)
    return RAYLIBColor(col.r, col.g, col.b, alpha)

// Helper to get RGB values from palette
func cs_palRGB t
    t = t - floor(t)
    r = 0  g = 0  b = 0

    if currentPal = PAL_RAINBOW
        r = floor((sin(t * PI * 2) + 1) * 127)
        g = floor((sin(t * PI * 2 + 2.094) + 1) * 127)
        b = floor((sin(t * PI * 2 + 4.189) + 1) * 127)
    ok
    if currentPal = PAL_OCEAN
        r = floor(t * 30)
        g = floor(80 + sin(t * PI * 2) * 80)
        b = floor(150 + sin(t * PI * 4) * 105)
    ok
    if currentPal = PAL_SUNSET
        if t < 0.33
            t2 = t / 0.33
            r = floor(30 + t2 * 225)  g = floor(t2 * 80)  b = floor(80 + t2 * 60)
        but t < 0.66
            t2 = (t - 0.33) / 0.33
            r = 255  g = floor(80 + t2 * 140)  b = floor(140 - t2 * 80)
        else
            t2 = (t - 0.66) / 0.34
            r = 255  g = floor(220 + t2 * 35)  b = floor(60 + t2 * 140)
        ok
    ok
    if currentPal = PAL_NEON
        r = floor((sin(t * PI * 6) + 1) * 127)
        g = floor((sin(t * PI * 4 + 1) + 1) * 100)
        b = floor((sin(t * PI * 2 + 3) + 1) * 127)
    ok
    if currentPal = PAL_FOREST
        r = floor(20 + sin(t * PI * 2 + 1) * 60)
        g = floor(100 + sin(t * PI * 2) * 120)
        b = floor(30 + sin(t * PI * 4 + 2) * 50)
    ok
    if currentPal = PAL_CANDY
        r = floor(200 + sin(t * PI * 4) * 55)
        g = floor(100 + sin(t * PI * 6 + 2) * 100)
        b = floor(180 + sin(t * PI * 2 + 4) * 75)
    ok

    if r > 255 r = 255 ok  if g > 255 g = 255 ok  if b > 255 b = 255 ok
    if r < 0 r = 0 ok  if g < 0 g = 0 ok  if b < 0 b = 0 ok
    return [r, g, b]

// =============================================================
// Draw
// =============================================================

func cs_draw
    // Background: trail or clear
    if trailMode
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, trailAlpha))
    else
        ClearBackground(BLACK)
    ok

    // Draw current mode
    if currentMode = MODE_PLASMA       cs_drawPlasma()       ok
    if currentMode = MODE_SPIROGRAPH   cs_drawSpirograph()   ok
    if currentMode = MODE_LAVALAMP     cs_drawLavaLamp()     ok
    if currentMode = MODE_MATRIX       cs_drawMatrix()       ok
    if currentMode = MODE_KALEIDOSCOPE cs_drawKaleidoscope() ok
    if currentMode = MODE_WAVES        cs_drawWaves()        ok
    if currentMode = MODE_STARDUST     cs_drawStardust()     ok
    if currentMode = MODE_FIREWORKS    cs_drawFireworks()     ok

    // HUD
    if showHUD
        cs_drawHUD()
    ok

// =============================================================
// Mode 1: Plasma
// =============================================================

func cs_drawPlasma
    step = 12
    t = animTime * 0.8

    for y = 0 to SCREEN_H step step
        for x = 0 to SCREEN_W step step
            fx = x * 1.0 / SCREEN_W
            fy = y * 1.0 / SCREEN_H

            v1 = sin(fx * 10 + t)
            v2 = sin(fy * 8 + t * 1.3)
            v3 = sin((fx + fy) * 6 + t * 0.7)
            v4 = sin(sqrt((fx - 0.5) * (fx - 0.5) + (fy - 0.5) * (fy - 0.5)) * 12 - t * 2)

            v = (v1 + v2 + v3 + v4) / 4.0
            ct = (v + 1.0) / 2.0

            rgb = cs_palRGB(ct + t * 0.1)
            DrawRectangle(x, y, step, step, RAYLIBColor(rgb[1], rgb[2], rgb[3], 240))
        next
    next

// =============================================================
// Mode 2: Spirograph
// =============================================================

func cs_drawSpirograph
    cx = SCREEN_W / 2
    cy = SCREEN_H / 2
    t = animTime

    // Generate new points
    R1 = 200   R2 = 80   R3 = 40
    speed1 = 1.0   speed2 = 3.7   speed3 = 7.3

    for step = 0 to 5
        tt = t + step * 0.02
        px = cx + cos(tt * speed1) * R1 + cos(tt * speed2) * R2 + cos(tt * speed3) * R3
        py = cy + sin(tt * speed1) * R1 + sin(tt * speed2) * R2 + sin(tt * speed3) * R3

        spiroIdx++
        if spiroIdx > MAX_SPIRO_PTS spiroIdx = 1 ok
        spiroX[spiroIdx] = px
        spiroY[spiroIdx] = py
        if spiroCount < MAX_SPIRO_PTS spiroCount++ ok
    next

    // Draw trail
    for i = 1 to spiroCount
        age = (spiroIdx - i + MAX_SPIRO_PTS) % MAX_SPIRO_PTS
        if age < 0 age += MAX_SPIRO_PTS ok
        alpha = floor((1.0 - age * 1.0 / MAX_SPIRO_PTS) * 255)
        if alpha < 5 loop ok

        ct = i * 1.0 / MAX_SPIRO_PTS + t * 0.05
        rgb = cs_palRGB(ct)
        sz = 2.0 + (1.0 - age * 1.0 / MAX_SPIRO_PTS) * 4.0

        DrawCircle(floor(spiroX[i]), floor(spiroY[i]), floor(sz), RAYLIBColor(rgb[1], rgb[2], rgb[3], alpha))
    next

    // Bright head
    rgb = cs_palRGB(t * 0.2)
    DrawCircle(floor(spiroX[spiroIdx]), floor(spiroY[spiroIdx]), 6, RAYLIBColor(rgb[1], rgb[2], rgb[3], 255))
    DrawCircle(floor(spiroX[spiroIdx]), floor(spiroY[spiroIdx]), 3, RAYLIBColor(255, 255, 255, 200))

// =============================================================
// Mode 3: Lava Lamp
// =============================================================

func cs_drawLavaLamp
    for i = 1 to MAX_BLOBS
        t = i * 1.0 / MAX_BLOBS + animTime * 0.05
        rgb = cs_palRGB(t)
        r = blobR[i] + sin(animTime * 2.0 + blobPhase[i]) * 15

        // Outer glow
        for ring = 4 to 0 step -1
            rr = r + ring * 12
            alpha = floor(40 - ring * 8)
            if alpha < 0 alpha = 0 ok
            DrawCircle(floor(blobX[i]), floor(blobY[i]), floor(rr), RAYLIBColor(rgb[1], rgb[2], rgb[3], alpha))
        next

        // Core
        DrawCircle(floor(blobX[i]), floor(blobY[i]), floor(r), RAYLIBColor(rgb[1], rgb[2], rgb[3], 180))

        // Bright center
        DrawCircle(floor(blobX[i]), floor(blobY[i]), floor(r * 0.4), RAYLIBColor(255, 255, 255, 50))
    next

// =============================================================
// Mode 4: Matrix Rain
// =============================================================

func cs_drawMatrix
    for i = 1 to MAX_COLS
        headY = floor(matY[i])
        tailY = headY - matLen[i]

        t = matHue[i] / 360.0 + animTime * 0.02
        rgb = cs_palRGB(t)

        // Draw segments
        segH = 8
        for sy = tailY to headY step segH
            if sy < 0 or sy > SCREEN_H loop ok
            dist = (headY - sy) * 1.0 / matLen[i]
            alpha = floor((1.0 - dist) * 220)
            if alpha < 0 alpha = 0 ok

            bright = 1.0 - dist * 0.7
            cr = floor(rgb[1] * bright)
            cg = floor(rgb[2] * bright)
            cb = floor(rgb[3] * bright)

            w = GetRandomValue(2, 6)
            DrawRectangle(matX[i] - w/2, sy, w, segH - 1, RAYLIBColor(cr, cg, cb, alpha))
        next

        // Bright head
        if headY >= 0 and headY <= SCREEN_H
            DrawCircle(matX[i], headY, 4, RAYLIBColor(255, 255, 255, 200))
            DrawCircle(matX[i], headY, 8, RAYLIBColor(rgb[1], rgb[2], rgb[3], 80))
        ok
    next

// =============================================================
// Mode 5: Kaleidoscope
// =============================================================

func cs_drawKaleidoscope
    cx = SCREEN_W / 2
    cy = SCREEN_H / 2
    t = animTime

    segments = 8
    segAngle = PI * 2 / segments

    for s = 0 to segments - 1
        baseAngle = s * segAngle

        // Draw shapes in each segment
        for j = 1 to 6
            dist = 50 + j * 40 + sin(t * 1.5 + j * 0.8) * 30
            angle = baseAngle + sin(t * 0.7 + j * 0.5) * 0.3
            px = cx + cos(angle) * dist
            py = cy + sin(angle) * dist

            ct = j * 1.0 / 6.0 + t * 0.1 + s * 0.05
            rgb = cs_palRGB(ct)

            sz = 12 + sin(t * 2 + j + s) * 8
            if sz < 3 sz = 3 ok
            alpha = 150 + floor(sin(t * 3 + j * 2) * 80)
            if alpha > 255 alpha = 255 ok
            if alpha < 40 alpha = 40 ok

            // Alternate shapes
            shape = (j + s) % 3
            if shape = 0
                DrawCircle(floor(px), floor(py), floor(sz), RAYLIBColor(rgb[1], rgb[2], rgb[3], alpha))
            ok
            if shape = 1
                DrawRectangle(floor(px) - floor(sz/2), floor(py) - floor(sz/2), floor(sz), floor(sz), RAYLIBColor(rgb[1], rgb[2], rgb[3], alpha))
            ok
            if shape = 2
                // Triangle using DrawTriangle
                tx1 = px   ty1 = py - sz
                tx2 = px - sz * 0.866   ty2 = py + sz * 0.5
                tx3 = px + sz * 0.866   ty3 = py + sz * 0.5
                DrawTriangle(Vector2(tx1, ty1), Vector2(tx2, ty2), Vector2(tx3, ty3), RAYLIBColor(rgb[1], rgb[2], rgb[3], alpha))
            ok
        next
    next

    // Center glow
    pulse = floor(fabs(sin(t * 2)) * 120) + 40
    rgb = cs_palRGB(t * 0.15)
    DrawCircle(cx, cy, 25, RAYLIBColor(rgb[1], rgb[2], rgb[3], pulse))
    DrawCircle(cx, cy, 12, RAYLIBColor(255, 255, 255, floor(pulse * 0.5)))

// =============================================================
// Mode 6: Waves
// =============================================================

func cs_drawWaves
    t = animTime

    // Draw multiple overlapping sine waves
    for wave = 0 to 7
        waveOffset = wave * 0.4
        freq = 2 + wave * 0.5
        amp = 60 + wave * 15
        baseY = 100 + wave * 65

        ct = wave / 8.0 + t * 0.08
        rgb = cs_palRGB(ct)

        prevX = 0
        prevY = baseY + sin(t * (1 + wave * 0.2)) * amp

        for x = 0 to SCREEN_W step 3
            fx = x * 1.0 / SCREEN_W
            y1 = sin(fx * freq * PI * 2 + t * (1.5 + wave * 0.3) + waveOffset) * amp
            y2 = sin(fx * freq * 1.5 * PI * 2 + t * 0.8 + wave) * amp * 0.3
            py = baseY + y1 + y2

            // Fill below
            fillH = SCREEN_H - floor(py)
            if fillH > 0
                alpha = floor(30 - wave * 2)
                if alpha < 5 alpha = 5 ok
                DrawRectangle(x, floor(py), 4, fillH, RAYLIBColor(rgb[1], rgb[2], rgb[3], alpha))
            ok

            // Line
            DrawLine(prevX, floor(prevY), x, floor(py), RAYLIBColor(rgb[1], rgb[2], rgb[3], 200))
            prevX = x
            prevY = py
        next
    next

// =============================================================
// Mode 7: Stardust Galaxy
// =============================================================

func cs_drawStardust
    cx = SCREEN_W / 2
    cy = SCREEN_H / 2
    t = animTime

    for i = 1 to MAX_STARS
        // Spiral motion
        angle = starAngle[i] + t * starSpeed[i]
        dist = starDist[i] + sin(t * 0.5 + i * 0.1) * 20

        // Spiral arm shape
        armAngle = angle + dist * 0.008
        px = cx + cos(armAngle) * dist
        py = cy + sin(armAngle) * dist

        ct = starHue[i] / 360.0 + t * 0.03
        rgb = cs_palRGB(ct)

        // Twinkle
        twinkle = sin(t * 4 + i * 2.1)
        alpha = floor(150 + twinkle * 80)
        if alpha > 255 alpha = 255 ok
        if alpha < 30 alpha = 30 ok

        sz = starSize[i] + twinkle * 0.5
        if sz < 0.5 sz = 0.5 ok

        // Glow
        DrawCircle(floor(px), floor(py), floor(sz * 2.5), RAYLIBColor(rgb[1], rgb[2], rgb[3], floor(alpha * 0.2)))
        DrawCircle(floor(px), floor(py), floor(sz), RAYLIBColor(rgb[1], rgb[2], rgb[3], alpha))
    next

    // Center glow
    pulse = floor(fabs(sin(t)) * 80) + 60
    rgb = cs_palRGB(t * 0.1)
    DrawCircle(cx, cy, 30, RAYLIBColor(rgb[1], rgb[2], rgb[3], floor(pulse * 0.4)))
    DrawCircle(cx, cy, 12, RAYLIBColor(255, 255, 255, floor(pulse * 0.3)))

// =============================================================
// Mode 8: Fireworks
// =============================================================

func cs_drawFireworks
    for i = 1 to MAX_FW
        if fwActive[i] = 0 loop ok

        lifeRatio = fwLife[i] / 2.5
        if lifeRatio > 1.0 lifeRatio = 1.0 ok
        alpha = floor(lifeRatio * 255)
        if alpha > 255 alpha = 255 ok
        if alpha < 0 loop ok

        ct = fwHue[i] / 360.0
        rgb = cs_palRGB(ct)

        sz = fwSize[i] * lifeRatio
        if sz < 0.3 sz = 0.3 ok

        // Glow
        DrawCircle(floor(fwX[i]), floor(fwY[i]), floor(sz * 3), RAYLIBColor(rgb[1], rgb[2], rgb[3], floor(alpha * 0.2)))
        // Core
        DrawCircle(floor(fwX[i]), floor(fwY[i]), floor(sz), RAYLIBColor(rgb[1], rgb[2], rgb[3], alpha))
        // Bright center
        if sz > 1.5
            DrawCircle(floor(fwX[i]), floor(fwY[i]), floor(sz * 0.4), RAYLIBColor(255, 255, 255, floor(alpha * 0.5)))
        ok
    next

// =============================================================
// HUD
// =============================================================

func cs_drawHUD
    DrawRectangle(0, 0, SCREEN_W, 26, RAYLIBColor(0, 0, 0, 160))

    DrawText("Color Screensaver", 10, 4, 18, RAYLIBColor(255, 215, 0, 220))

    mTxt = "Mode: " + modeNames[currentMode] + " [" + string(currentMode) + "]"
    DrawText(mTxt, 210, 6, 14, RAYLIBColor(100, 200, 255, 220))

    pTxt = "Palette: " + palNames[currentPal]
    DrawText(pTxt, 460, 6, 14, RAYLIBColor(200, 180, 255, 200))

    if trailMode
        DrawText("Trails ON", 630, 6, 14, RAYLIBColor(100, 255, 100, 180))
    else
        DrawText("Trails off", 630, 6, 14, RAYLIBColor(150, 150, 150, 150))
    ok

    if paused
        DrawText("PAUSED", 740, 6, 14, RAYLIBColor(255, 100, 100, 240))
    ok

    // Controls
    DrawText("N:Next  T:Palette  B:Trails  F:HUD  P:Pause", 10, SCREEN_H - 18, 12, RAYLIBColor(200, 200, 220, 100))

    fpsTxt = "" + string(GetFPS()) + " FPS"
    DrawText(fpsTxt, SCREEN_W - 65, SCREEN_H - 18, 13, RAYLIBColor(100, 255, 100, 120))
