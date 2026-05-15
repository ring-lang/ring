/*
**  Particle System Playground - RingRayLib
**  ==========================================
**  Interactive particle emitters with physics!
**
**  Controls:
**    Mouse Left       - Place/drag attractor (pulls particles)
**    Mouse Right      - Place/drag repulsor (pushes particles)
**    1-6              - Switch emitter type
**    E                - Add emitter at center
**    T                - Cycle color theme
**    G                - Toggle gravity on/off
**    W                - Toggle wind on/off
**    Space / P        - Pause / Resume
**    C                - Clear all particles
**    R                - Reset everything
**    +/-              - Increase / Decrease emission rate
**    [ / ]            - Decrease / Increase particle life
**    ESC              - Exit
**
**  Emitter Types:
**    1. Fountain      - Upward spray
**    2. Explosion     - Radial burst
**    3. Fire          - Flame effect
**    4. Snow          - Gentle falling
**    5. Vortex        - Spinning spiral
**    6. Rain          - Falling streaks
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W = 1024
SCREEN_H = 700
TOOLBAR_H = 55

MAX_PARTICLES = 5000

// Emitter types
EMIT_FOUNTAIN  = 1
EMIT_EXPLOSION = 2
EMIT_FIRE      = 3
EMIT_SNOW      = 4
EMIT_VORTEX    = 5
EMIT_RAIN      = 6
EMIT_COUNT     = 6
emitNames = ["Fountain", "Explosion", "Fire", "Snow", "Vortex", "Rain"]

// Color themes
THEME_FIRE     = 1
THEME_ICE      = 2
THEME_RAINBOW  = 3
THEME_NEON     = 4
THEME_GOLD     = 5
THEME_NATURE   = 6
THEME_COUNT    = 6
themeNames = ["Fire", "Ice", "Rainbow", "Neon", "Gold", "Nature"]

// =============================================================
// Particle Structure (stored in flat lists for performance)
// =============================================================

// Particle arrays
pActive = list(MAX_PARTICLES)   // 0=dead, 1=alive
pX  = list(MAX_PARTICLES)      // position x
pY  = list(MAX_PARTICLES)      // position y
pVX = list(MAX_PARTICLES)      // velocity x
pVY = list(MAX_PARTICLES)      // velocity y
pLife = list(MAX_PARTICLES)     // remaining life
pMaxLife = list(MAX_PARTICLES)  // max life (for alpha calc)
pSize = list(MAX_PARTICLES)    // size
pR = list(MAX_PARTICLES)       // color R
pG = list(MAX_PARTICLES)       // color G
pB = list(MAX_PARTICLES)       // color B

for i = 1 to MAX_PARTICLES
    pActive[i] = 0
next

particleCount = 0

// =============================================================
// Emitters
// =============================================================

MAX_EMITTERS = 10
emitters = []
// Each emitter: [type, x, y, rate, timer, active]

// =============================================================
// Physics
// =============================================================

gravityOn = true
gravityX = 0.0
gravityY = 300.0

windOn = false
windX = 80.0
windY = 0.0

// Attractor / Repulsor (mouse-driven)
attractorActive = false
attractorX = 0.0
attractorY = 0.0
attractorStrength = 50000.0

repulsorActive = false
repulsorX = 0.0
repulsorY = 0.0
repulsorStrength = 60000.0

// =============================================================
// Settings
// =============================================================

emitterType = EMIT_FOUNTAIN
colorTheme = THEME_FIRE
emitRate = 60          // particles per second per emitter
particleLife = 3.0     // seconds
paused = false
animTime = 0.0

// Toolbar
hoverBtn = 0
BTN_Y = SCREEN_H - 52
BTN_H = 38
BTN_GAP = 5

// Trail effect
trailFade = 15   // background alpha for trails (lower = more trail)

// =============================================================
// Main
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Particle System Playground - RingRayLib")
SetTargetFPS(60)
SetExitKey(0)

// Start with one fountain emitter at center
ps_addEmitter(EMIT_FOUNTAIN, SCREEN_W / 2, SCREEN_H / 2 + 50)

while !WindowShouldClose()
    ps_update()
    BeginDrawing()
        ps_draw()
    EndDrawing()
end

CloseWindow()

// =============================================================
// Update
// =============================================================

func ps_update
    dt = GetFrameTime()
    if dt > 0.05 dt = 0.05 ok  // clamp for stability

    if IsKeyPressed(KEY_ESCAPE)
        CloseWindow()
        shutdown(0)
    ok

    // Emitter type selection
    for k = 1 to EMIT_COUNT
        if IsKeyPressed(48 + k)
            emitterType = k
        ok
    next

    // Add emitter
    if IsKeyPressed(KEY_E)
        ps_addEmitter(emitterType, SCREEN_W / 2, SCREEN_H / 2)
    ok

    // Color theme
    if IsKeyPressed(KEY_T)
        colorTheme++
        if colorTheme > THEME_COUNT colorTheme = 1 ok
    ok

    // Gravity toggle
    if IsKeyPressed(KEY_G)
        gravityOn = !gravityOn
    ok

    // Wind toggle
    if IsKeyPressed(KEY_W)
        windOn = !windOn
    ok

    // Pause
    if IsKeyPressed(KEY_SPACE) or IsKeyPressed(KEY_P)
        paused = !paused
    ok

    // Clear particles
    if IsKeyPressed(KEY_C)
        for i = 1 to MAX_PARTICLES
            pActive[i] = 0
        next
        particleCount = 0
    ok

    // Reset
    if IsKeyPressed(KEY_R)
        for i = 1 to MAX_PARTICLES
            pActive[i] = 0
        next
        particleCount = 0
        emitters = []
        ps_addEmitter(EMIT_FOUNTAIN, SCREEN_W / 2, SCREEN_H / 2 + 50)
        gravityOn = true
        windOn = false
        emitterType = EMIT_FOUNTAIN
        colorTheme = THEME_FIRE
        emitRate = 60
        particleLife = 3.0
    ok

    // Emission rate
    if IsKeyPressed(KEY_EQUAL) or IsKeyPressed(KEY_KP_ADD)
        emitRate += 10
        if emitRate > 300 emitRate = 300 ok
    ok
    if IsKeyPressed(KEY_MINUS) or IsKeyPressed(KEY_KP_SUBTRACT)
        emitRate -= 10
        if emitRate < 5 emitRate = 5 ok
    ok

    // Particle life
    if IsKeyPressed(KEY_RIGHT_BRACKET)
        particleLife += 0.5
        if particleLife > 10.0 particleLife = 10.0 ok
    ok
    if IsKeyPressed(KEY_LEFT_BRACKET)
        particleLife -= 0.5
        if particleLife < 0.5 particleLife = 0.5 ok
    ok

    // Mouse - attractor (left) / repulsor (right)
    attractorActive = false
    repulsorActive = false

    my = GetMouseY()
    if my < SCREEN_H - TOOLBAR_H
        if IsMouseButtonDown(MOUSE_LEFT_BUTTON)
            if hoverBtn = 0
                attractorActive = true
                attractorX = GetMouseX()
                attractorY = GetMouseY()
            ok
        ok
        if IsMouseButtonDown(MOUSE_RIGHT_BUTTON)
            repulsorActive = true
            repulsorX = GetMouseX()
            repulsorY = GetMouseY()
        ok
    ok

    // Toolbar clicks
    if IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
        ps_handleClick(GetMouseX(), GetMouseY())
    ok

    if !paused
        animTime += dt
        ps_emitParticles(dt)
        ps_updateParticles(dt)
    ok

// =============================================================
// Add Emitter
// =============================================================

func ps_addEmitter eType, ex, ey
    if len(emitters) >= MAX_EMITTERS return ok
    add(emitters, [eType, ex, ey, emitRate, 0.0, 1])

// =============================================================
// Emit Particles
// =============================================================

func ps_emitParticles dt
    for e = 1 to len(emitters)
        em = emitters[e]
        if em[6] = 0 loop ok  // inactive

        eType = em[1]
        ex = em[2]
        ey = em[3]
        rate = emitRate

        // Explosion emits in bursts
        if eType = EMIT_EXPLOSION
            em[5] += dt
            if em[5] >= 1.5   // burst every 1.5s
                em[5] = 0.0
                for b = 1 to 80
                    ps_spawnParticle(eType, ex, ey)
                next
            ok
            emitters[e] = em
            loop
        ok

        // Continuous emit
        em[5] += dt
        interval = 1.0 / rate
        while em[5] >= interval
            em[5] -= interval
            ps_spawnParticle(eType, ex, ey)
        end
        emitters[e] = em
    next

func ps_spawnParticle eType, ex, ey
    // Find a dead slot
    slot = 0
    for i = 1 to MAX_PARTICLES
        if pActive[i] = 0
            slot = i
            exit
        ok
    next
    if slot = 0 return ok  // full

    pActive[slot] = 1
    pX[slot] = ex
    pY[slot] = ey
    pLife[slot] = particleLife
    pMaxLife[slot] = particleLife

    vx = 0.0  vy = 0.0  sz = 3.0

    if eType = EMIT_FOUNTAIN
        spread = GetRandomValue(-150, 150) * 1.0
        vx = spread
        vy = -GetRandomValue(250, 500) * 1.0
        sz = GetRandomValue(20, 40) / 10.0
    ok

    if eType = EMIT_EXPLOSION
        angle = GetRandomValue(0, 628) / 100.0
        speed = GetRandomValue(100, 500) * 1.0
        vx = cos(angle) * speed
        vy = sin(angle) * speed
        sz = GetRandomValue(20, 50) / 10.0
        pLife[slot] = particleLife * 0.7
        pMaxLife[slot] = pLife[slot]
    ok

    if eType = EMIT_FIRE
        vx = GetRandomValue(-60, 60) * 1.0
        vy = -GetRandomValue(100, 300) * 1.0
        pX[slot] = ex + GetRandomValue(-20, 20)
        sz = GetRandomValue(30, 60) / 10.0
        pLife[slot] = particleLife * 0.5
        pMaxLife[slot] = pLife[slot]
    ok

    if eType = EMIT_SNOW
        vx = GetRandomValue(-30, 30) * 1.0
        vy = GetRandomValue(30, 100) * 1.0
        pX[slot] = GetRandomValue(0, SCREEN_W)
        pY[slot] = -10.0
        sz = GetRandomValue(15, 40) / 10.0
        pLife[slot] = particleLife * 1.5
        pMaxLife[slot] = pLife[slot]
    ok

    if eType = EMIT_VORTEX
        angle = GetRandomValue(0, 628) / 100.0
        radius = GetRandomValue(5, 30) * 1.0
        pX[slot] = ex + cos(angle) * radius
        pY[slot] = ey + sin(angle) * radius
        // Tangential velocity
        speed = GetRandomValue(100, 250) * 1.0
        vx = -sin(angle) * speed
        vy = cos(angle) * speed
        sz = GetRandomValue(15, 35) / 10.0
    ok

    if eType = EMIT_RAIN
        pX[slot] = GetRandomValue(0, SCREEN_W)
        pY[slot] = -5.0
        vx = GetRandomValue(-20, -5) * 1.0
        vy = GetRandomValue(400, 700) * 1.0
        sz = GetRandomValue(10, 20) / 10.0
        pLife[slot] = particleLife * 0.6
        pMaxLife[slot] = pLife[slot]
    ok

    pVX[slot] = vx
    pVY[slot] = vy
    pSize[slot] = sz

    // Color from theme
    ps_assignColor(slot)

func ps_assignColor slot
    if colorTheme = THEME_FIRE
        pR[slot] = GetRandomValue(200, 255)
        pG[slot] = GetRandomValue(50, 180)
        pB[slot] = GetRandomValue(0, 40)
    ok
    if colorTheme = THEME_ICE
        pR[slot] = GetRandomValue(150, 220)
        pG[slot] = GetRandomValue(200, 255)
        pB[slot] = 255
    ok
    if colorTheme = THEME_RAINBOW
        h = GetRandomValue(0, 360)
        rgb = ps_hsvToRgb(h, 100, 100)
        pR[slot] = rgb[1]
        pG[slot] = rgb[2]
        pB[slot] = rgb[3]
    ok
    if colorTheme = THEME_NEON
        pick = GetRandomValue(1, 4)
        if pick = 1   pR[slot] = 255  pG[slot] = 0    pB[slot] = 255  ok
        if pick = 2   pR[slot] = 0    pG[slot] = 255  pB[slot] = 200  ok
        if pick = 3   pR[slot] = 255  pG[slot] = 255  pB[slot] = 0    ok
        if pick = 4   pR[slot] = 0    pG[slot] = 200  pB[slot] = 255  ok
    ok
    if colorTheme = THEME_GOLD
        pR[slot] = GetRandomValue(200, 255)
        pG[slot] = GetRandomValue(150, 220)
        pB[slot] = GetRandomValue(20, 80)
    ok
    if colorTheme = THEME_NATURE
        pick = GetRandomValue(1, 3)
        if pick = 1  pR[slot] = GetRandomValue(30, 80)    pG[slot] = GetRandomValue(150, 230)  pB[slot] = GetRandomValue(30, 80) ok
        if pick = 2  pR[slot] = GetRandomValue(100, 180)   pG[slot] = GetRandomValue(60, 120)   pB[slot] = GetRandomValue(20, 50) ok
        if pick = 3  pR[slot] = GetRandomValue(50, 120)    pG[slot] = GetRandomValue(180, 255)  pB[slot] = GetRandomValue(80, 150) ok
    ok

// Simple HSV to RGB (s and v are 0-100)
func ps_hsvToRgb h, s, v
    s2 = s / 100.0
    v2 = v / 100.0
    c = v2 * s2
    x = c * (1.0 - fabs(((h / 60.0) % 2) - 1.0))
    m = v2 - c

    if h < 60        r1 = c  g1 = x  b1 = 0
    but h < 120   r1 = x  g1 = c  b1 = 0
    but h < 180   r1 = 0  g1 = c  b1 = x
    but h < 240   r1 = 0  g1 = x  b1 = c
    but h < 300   r1 = x  g1 = 0  b1 = c
    else              r1 = c  g1 = 0  b1 = x
    ok

    return [floor((r1 + m) * 255), floor((g1 + m) * 255), floor((b1 + m) * 255)]

// =============================================================
// Update Particles
// =============================================================

func ps_updateParticles dt
    particleCount = 0

    for i = 1 to MAX_PARTICLES
        if pActive[i] = 0 loop ok

        // Apply gravity
        if gravityOn
            pVY[i] += gravityY * dt
            pVX[i] += gravityX * dt
        ok

        // Apply wind
        if windOn
            pVX[i] += windX * dt
            pVY[i] += windY * dt
        ok

        // Attractor force
        if attractorActive
            dx = attractorX - pX[i]
            dy = attractorY - pY[i]
            dist2 = dx * dx + dy * dy
            if dist2 < 100 dist2 = 100 ok
            dist = sqrt(dist2)
            force = attractorStrength / dist2
            pVX[i] += (dx / dist) * force * dt
            pVY[i] += (dy / dist) * force * dt
        ok

        // Repulsor force
        if repulsorActive
            dx = pX[i] - repulsorX
            dy = pY[i] - repulsorY
            dist2 = dx * dx + dy * dy
            if dist2 < 100 dist2 = 100 ok
            dist = sqrt(dist2)
            force = repulsorStrength / dist2
            pVX[i] += (dx / dist) * force * dt
            pVY[i] += (dy / dist) * force * dt
        ok

        // Vortex emitter: add centripetal pull toward emitter center
        // (find the vortex emitter if one exists)
        for e = 1 to len(emitters)
            if emitters[e][1] = EMIT_VORTEX
                ecx = emitters[e][2]
                ecy = emitters[e][3]
                dx = ecx - pX[i]
                dy = ecy - pY[i]
                dist = sqrt(dx * dx + dy * dy)
                if dist > 1
                    pVX[i] += (dx / dist) * 120.0 * dt
                    pVY[i] += (dy / dist) * 120.0 * dt
                ok
            ok
        next

        // Update position
        pX[i] += pVX[i] * dt
        pY[i] += pVY[i] * dt

        // Decrease life
        pLife[i] -= dt

        // Kill if dead or far off screen
        if pLife[i] <= 0
            pActive[i] = 0
            loop
        ok
        if pX[i] < -200 or pX[i] > SCREEN_W + 200 or pY[i] > SCREEN_H + 200
            pActive[i] = 0
            loop
        ok

        particleCount++
    next

// =============================================================
// Draw
// =============================================================

func ps_draw
    // Trail effect: semi-transparent black overlay instead of full clear
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H - TOOLBAR_H, RAYLIBColor(10, 10, 18, trailFade))

    // Draw particles
    for i = 1 to MAX_PARTICLES
        if pActive[i] = 0 loop ok

        lifeRatio = pLife[i] / pMaxLife[i]
        if lifeRatio < 0 lifeRatio = 0 ok
        alpha = floor(lifeRatio * 255)
        if alpha > 255 alpha = 255 ok
        if alpha < 5 loop ok

        sz = pSize[i] * (0.3 + lifeRatio * 0.7)
        ix = floor(pX[i])
        iy = floor(pY[i])

        cr = pR[i]
        cg = pG[i]
        cb = pB[i]

        // Draw glow (larger, dimmer)
        glowA = floor(alpha * 0.3)
        glowSz = sz * 2.5
        DrawCircle(ix, iy, floor(glowSz), RAYLIBColor(cr, cg, cb, glowA))

        // Draw core
        DrawCircle(ix, iy, floor(sz), RAYLIBColor(cr, cg, cb, alpha))

        // Bright center for larger particles
        if sz > 2.0
            coreA = floor(alpha * 0.6)
            DrawCircle(ix, iy, floor(sz * 0.4), RAYLIBColor(255, 255, 255, coreA))
        ok
    next

    // Draw attractor
    if attractorActive
        pulse = floor(fabs(sin(animTime * 5.0)) * 100) + 80
        DrawCircleLines(floor(attractorX), floor(attractorY), 25, RAYLIBColor(100, 200, 255, pulse))
        DrawCircleLines(floor(attractorX), floor(attractorY), 15, RAYLIBColor(150, 230, 255, pulse + 40))
        DrawCircle(floor(attractorX), floor(attractorY), 4, RAYLIBColor(200, 240, 255, 200))
    ok

    // Draw repulsor
    if repulsorActive
        pulse = floor(fabs(sin(animTime * 5.0)) * 100) + 80
        DrawCircleLines(floor(repulsorX), floor(repulsorY), 25, RAYLIBColor(255, 100, 100, pulse))
        DrawCircleLines(floor(repulsorX), floor(repulsorY), 15, RAYLIBColor(255, 150, 100, pulse + 40))
        DrawCircle(floor(repulsorX), floor(repulsorY), 4, RAYLIBColor(255, 200, 150, 200))
    ok

    // Draw emitter positions
    for e = 1 to len(emitters)
        ex = emitters[e][2]
        ey = emitters[e][3]
        DrawCircleLines(floor(ex), floor(ey), 8, RAYLIBColor(255, 255, 255, 60))
        DrawCircle(floor(ex), floor(ey), 3, RAYLIBColor(255, 255, 255, 100))
    next

    // HUD
    ps_drawHUD()

    // Toolbar (drawn on solid background)
    ps_drawToolbar()

func ps_drawHUD
    // Top bar
    DrawRectangle(0, 0, SCREEN_W, 28, RAYLIBColor(0, 0, 0, 180))

    DrawText("Particle Playground", 10, 5, 18, RAYLIBColor(255, 215, 0, 220))

    pTxt = "Particles: " + string(particleCount) + "/" + string(MAX_PARTICLES)
    DrawText(pTxt, 210, 7, 14, RAYLIBColor(200, 220, 255, 200))

    eTxt = "Emitters: " + string(len(emitters))
    DrawText(eTxt, 400, 7, 14, RAYLIBColor(200, 220, 255, 200))

    rTxt = "Rate: " + string(emitRate) + "/s"
    DrawText(rTxt, 510, 7, 14, RAYLIBColor(255, 200, 150, 200))

    lTxt = "Life: " + string(particleLife) + "s"
    DrawText(lTxt, 610, 7, 14, RAYLIBColor(150, 255, 200, 200))

    if paused
        DrawText("PAUSED", 710, 7, 14, RAYLIBColor(255, 100, 100, 240))
    ok

    // Physics indicators
    gTxt = "Grav:"
    if gravityOn
        DrawText(gTxt, 780, 7, 14, RAYLIBColor(100, 255, 100, 200))
        DrawText("ON", 820, 7, 14, RAYLIBColor(100, 255, 100, 240))
    else
        DrawText(gTxt, 780, 7, 14, RAYLIBColor(180, 180, 180, 150))
        DrawText("off", 820, 7, 14, RAYLIBColor(150, 150, 150, 150))
    ok

    wTxt = "Wind:"
    if windOn
        DrawText(wTxt, 860, 7, 14, RAYLIBColor(100, 200, 255, 200))
        DrawText("ON", 900, 7, 14, RAYLIBColor(100, 200, 255, 240))
    else
        DrawText(wTxt, 860, 7, 14, RAYLIBColor(180, 180, 180, 150))
        DrawText("off", 900, 7, 14, RAYLIBColor(150, 150, 150, 150))
    ok

    // Type and theme
    DrawText("Type: " + emitNames[emitterType], 10, SCREEN_H - TOOLBAR_H - 22, 14, RAYLIBColor(255, 255, 255, 150))
    DrawText("Theme: " + themeNames[colorTheme], 160, SCREEN_H - TOOLBAR_H - 22, 14, RAYLIBColor(255, 255, 255, 150))

    // Instructions
    DrawText("LMB: Attract | RMB: Repel", SCREEN_W - 220, SCREEN_H - TOOLBAR_H - 22, 13, RAYLIBColor(200, 200, 220, 130))

    // FPS
    fpsTxt = "" + string(GetFPS()) + " FPS"
    DrawText(fpsTxt, SCREEN_W - 70, SCREEN_H - 15, 14, RAYLIBColor(100, 255, 100, 180))

// =============================================================
// Toolbar
// =============================================================

func ps_drawToolbar
    DrawRectangle(0, SCREEN_H - TOOLBAR_H, SCREEN_W, TOOLBAR_H, RAYLIBColor(20, 20, 35, 255))
    DrawRectangle(0, SCREEN_H - TOOLBAR_H, SCREEN_W, 2, RAYLIBColor(80, 80, 120, 200))

    mx = GetMouseX()
    my = GetMouseY()
    hoverBtn = 0

    bx = BTN_GAP

    // Play/Pause
    if paused
        bx = ps_drawBtn("Play [P]", bx, 1, RAYLIBColor(40, 130, 70, 255), mx, my)
    else
        bx = ps_drawBtn("Pause [P]", bx, 1, RAYLIBColor(180, 120, 20, 255), mx, my)
    ok
    bx += BTN_GAP

    // Add Emitter
    bx = ps_drawBtn("Add [E]", bx, 2, RAYLIBColor(60, 100, 160, 255), mx, my)
    bx += BTN_GAP

    // Clear
    bx = ps_drawBtn("Clear [C]", bx, 3, RAYLIBColor(170, 40, 40, 255), mx, my)
    bx += BTN_GAP

    // Reset
    bx = ps_drawBtn("Reset [R]", bx, 4, RAYLIBColor(130, 60, 60, 255), mx, my)
    bx += BTN_GAP

    // Gravity
    if gravityOn
        bx = ps_drawBtn("Grav ON", bx, 5, RAYLIBColor(40, 120, 40, 255), mx, my)
    else
        bx = ps_drawBtn("Grav off", bx, 5, RAYLIBColor(80, 80, 80, 255), mx, my)
    ok
    bx += BTN_GAP

    // Wind
    if windOn
        bx = ps_drawBtn("Wind ON", bx, 6, RAYLIBColor(40, 100, 140, 255), mx, my)
    else
        bx = ps_drawBtn("Wind off", bx, 6, RAYLIBColor(80, 80, 80, 255), mx, my)
    ok
    bx += BTN_GAP

    // Theme
    bx = ps_drawBtn("Theme [T]", bx, 7, RAYLIBColor(130, 60, 150, 255), mx, my)
    bx += BTN_GAP

    // Separator
    DrawRectangle(bx, BTN_Y + 4, 2, BTN_H - 8, RAYLIBColor(80, 80, 120, 150))
    bx += BTN_GAP

    // Emitter type buttons
    btnColors = [
        RAYLIBColor(180, 80, 30, 255),
        RAYLIBColor(200, 50, 50, 255),
        RAYLIBColor(200, 120, 20, 255),
        RAYLIBColor(100, 160, 200, 255),
        RAYLIBColor(120, 50, 180, 255),
        RAYLIBColor(60, 100, 160, 255)
    ]

    for i = 1 to EMIT_COUNT
        label = "" + string(i) + ":" + emitNames[i]
        col = btnColors[i]
        if emitterType = i
            col = RAYLIBColor(200, 200, 80, 255)
        ok
        bx = ps_drawBtn(label, bx, 10 + i, col, mx, my)
        bx += 3
    next

func ps_drawBtn label, bx, btnId, baseCol, mx, my
    tw = MeasureText(label, 13) + 14
    if tw < 45 tw = 45 ok

    isHover = (mx >= bx and mx <= bx + tw and my >= BTN_Y and my <= BTN_Y + BTN_H)

    if isHover
        hoverBtn = btnId
        DrawRectangle(bx, BTN_Y, tw, BTN_H, RAYLIBColor(255, 225, 100, 240))
        DrawRectangleLines(bx, BTN_Y, tw, BTN_H, RAYLIBColor(200, 180, 60, 255))
        lw = MeasureText(label, 13)
        DrawText(label, bx + (tw - lw) / 2, BTN_Y + 13, 13, RAYLIBColor(20, 15, 10, 255))
    else
        DrawRectangle(bx, BTN_Y, tw, BTN_H, baseCol)
        DrawRectangleLines(bx, BTN_Y, tw, BTN_H, RAYLIBColor(255, 255, 255, 40))
        lw = MeasureText(label, 13)
        DrawText(label, bx + (tw - lw) / 2, BTN_Y + 13, 13, WHITE)
    ok

    return bx + tw

// =============================================================
// Handle Click
// =============================================================

func ps_handleClick mx, my
    if hoverBtn = 1
        paused = !paused
        return
    ok
    if hoverBtn = 2
        ps_addEmitter(emitterType, SCREEN_W / 2, SCREEN_H / 2)
        return
    ok
    if hoverBtn = 3
        for i = 1 to MAX_PARTICLES
            pActive[i] = 0
        next
        particleCount = 0
        return
    ok
    if hoverBtn = 4
        for i = 1 to MAX_PARTICLES
            pActive[i] = 0
        next
        particleCount = 0
        emitters = []
        ps_addEmitter(EMIT_FOUNTAIN, SCREEN_W / 2, SCREEN_H / 2 + 50)
        gravityOn = true
        windOn = false
        emitterType = EMIT_FOUNTAIN
        colorTheme = THEME_FIRE
        emitRate = 60
        particleLife = 3.0
        return
    ok
    if hoverBtn = 5
        gravityOn = !gravityOn
        return
    ok
    if hoverBtn = 6
        windOn = !windOn
        return
    ok
    if hoverBtn = 7
        colorTheme++
        if colorTheme > THEME_COUNT colorTheme = 1 ok
        return
    ok
    // Emitter type selection
    if hoverBtn >= 11 and hoverBtn <= 10 + EMIT_COUNT
        emitterType = hoverBtn - 10
        return
    ok
