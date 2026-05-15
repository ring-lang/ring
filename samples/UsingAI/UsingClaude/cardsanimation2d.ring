/*
**  Cards Animation - RingRayLib
**  =============================
**  Watch beautiful card animations on screen!
**
**  Controls:
**    A / Add Button      - Add a card with random animation
**    P / Pause Button    - Pause / Resume all animations
**    C / Clear Button    - Clear all cards
**    1-8                 - Add card with specific animation type
**    ESC                 - Exit
**
**  Animation Types:
**    1. Float       - Cards drift and bob gently
**    2. Spiral      - Cards spiral outward from center
**    3. Bounce      - Cards bounce off screen edges
**    4. Spin        - Cards spin in place with scaling
**    5. Wave        - Cards ride a sine wave
**    6. Cascade     - Cards fall like a waterfall
**    7. Orbit       - Cards orbit around a center point
**    8. Firework    - Cards explode outward then fade
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W    = 1024
SCREEN_H    = 700

CARD_W      = 72
CARD_H      = 100

SUIT_HEART  = 1
SUIT_DIAMOND = 2
SUIT_CLUB   = 3
SUIT_SPADE  = 4

ANIM_FLOAT    = 1
ANIM_SPIRAL   = 2
ANIM_BOUNCE   = 3
ANIM_SPIN     = 4
ANIM_WAVE     = 5
ANIM_CASCADE  = 6
ANIM_ORBIT    = 7
ANIM_FIREWORK = 8
ANIM_COUNT    = 8

animNames = ["Float", "Spiral", "Bounce", "Spin", "Wave", "Cascade", "Orbit", "Firework"]

rankNames = ["A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"]
suitSyms  = ["H", "D", "C", "S"]

// =============================================================
// State
// =============================================================

cards = []          // list of animated cards
animTime = 0.0
paused = false
hoverBtn = 0       // which button is hovered

// Button layout
BTN_Y = SCREEN_H - 52
BTN_H = 38
BTN_GAP = 8

// =============================================================
// Main
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Cards Animation - RingRayLib")
SetTargetFPS(60)
SetExitKey(0)

// Seed with a few cards
for i = 1 to 5
    ca_addRandomCard()
next

while !WindowShouldClose()
    ca_update()
    BeginDrawing()
        ca_draw()
    EndDrawing()
end

CloseWindow()

// =============================================================
// Update
// =============================================================

func ca_update
    dt = GetFrameTime()

    if IsKeyPressed(KEY_ESCAPE)
        CloseWindow()
        shutdown(0)
    ok

    // Add card
    if IsKeyPressed(KEY_A)
        ca_addRandomCard()
    ok

    // Specific animation
    for k = 1 to ANIM_COUNT
        if IsKeyPressed(48 + k)   // KEY_1 .. KEY_8
            ca_addCard(k)
        ok
    next

    // Pause / Resume
    if IsKeyPressed(KEY_P)
        paused = !paused
    ok

    // Clear
    if IsKeyPressed(KEY_C)
        cards = []
    ok

    // Mouse button clicks
    if IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
        ca_handleClick(GetMouseX(), GetMouseY())
    ok

    // Update animations
    if !paused
        animTime += dt
        ca_updateCards(dt)
    ok

// =============================================================
// Add Cards
// =============================================================

func ca_addRandomCard
    anim = GetRandomValue(1, ANIM_COUNT)
    ca_addCard(anim)

func ca_addCard animType
    rank = GetRandomValue(1, 13)
    suit = GetRandomValue(1, 4)

    // Starting position and per-card parameters
    cx = SCREEN_W / 2.0
    cy = SCREEN_H / 2.0
    vx = 0.0
    vy = 0.0
    angle = 0.0
    scaleV = 1.0
    lifetime = 0.0
    param1 = 0.0
    param2 = 0.0
    param3 = 0.0
    alpha = 255

    if animType = ANIM_FLOAT
        cx = GetRandomValue(80, SCREEN_W - 80)
        cy = GetRandomValue(100, SCREEN_H - 180)
        vx = (GetRandomValue(-100, 100) / 100.0) * 30.0
        vy = (GetRandomValue(-100, 100) / 100.0) * 15.0
        param1 = GetRandomValue(10, 30) / 10.0    // bob speed
        param2 = GetRandomValue(5, 20) * 1.0       // bob amplitude
        param3 = GetRandomValue(0, 628) / 100.0    // phase offset
    ok

    if animType = ANIM_SPIRAL
        param1 = GetRandomValue(0, 628) / 100.0    // start angle
        param2 = 20.0                                // initial radius
        param3 = GetRandomValue(80, 160) / 100.0   // spiral speed
    ok

    if animType = ANIM_BOUNCE
        cx = GetRandomValue(100, SCREEN_W - 100)
        cy = GetRandomValue(100, SCREEN_H - 200)
        vx = (GetRandomValue(-100, 100) / 100.0) * 200.0
        vy = (GetRandomValue(-100, 100) / 100.0) * 200.0
        if vx > -50 and vx < 50 vx = 100.0 ok
        if vy > -50 and vy < 50 vy = 100.0 ok
    ok

    if animType = ANIM_SPIN
        cx = GetRandomValue(100, SCREEN_W - 100)
        cy = GetRandomValue(100, SCREEN_H - 200)
        param1 = (GetRandomValue(-300, 300) / 100.0)  // spin speed (radians/s)
        if param1 > -0.5 and param1 < 0.5 param1 = 2.0 ok
    ok

    if animType = ANIM_WAVE
        cx = GetRandomValue(0, 50) * 1.0
        cy = SCREEN_H / 2.0
        vx = GetRandomValue(60, 150) * 1.0            // horizontal speed
        param1 = GetRandomValue(60, 150) * 1.0         // wave amplitude
        param2 = GetRandomValue(15, 40) / 10.0         // wave frequency
        param3 = GetRandomValue(0, 628) / 100.0        // phase
    ok

    if animType = ANIM_CASCADE
        cx = GetRandomValue(80, SCREEN_W - 80)
        cy = -CARD_H * 1.0
        vx = (GetRandomValue(-50, 50) / 100.0) * 40.0
        vy = GetRandomValue(80, 200) * 1.0
        param1 = (GetRandomValue(-200, 200) / 100.0)  // rotation speed
    ok

    if animType = ANIM_ORBIT
        param1 = GetRandomValue(0, 628) / 100.0        // start angle
        param2 = GetRandomValue(80, 250) * 1.0          // orbit radius
        param3 = GetRandomValue(50, 200) / 100.0        // orbit speed (rad/s)
        cx = SCREEN_W / 2.0
        cy = (SCREEN_H - 60) / 2.0
    ok

    if animType = ANIM_FIREWORK
        param1 = GetRandomValue(0, 628) / 100.0        // direction angle
        param2 = GetRandomValue(150, 400) * 1.0         // speed
        cx = SCREEN_W / 2.0
        cy = (SCREEN_H - 60) / 2.0
        vx = cos(param1) * param2
        vy = sin(param1) * param2
    ok

    add(cards, [rank, suit, animType, cx, cy, vx, vy, angle, scaleV, lifetime, param1, param2, param3, alpha])
    //  1      2     3         4   5   6   7   8      9       10        11      12      13      14

// =============================================================
// Update Card Animations
// =============================================================

func ca_updateCards dt
    toRemove = []
    for i = 1 to len(cards)
        c = cards[i]
        aType = c[3]
        c[10] += dt   // lifetime

        if aType = ANIM_FLOAT
            c[4] += c[6] * dt
            c[5] += c[7] * dt + sin(animTime * c[11] + c[13]) * c[12] * dt
            // Gentle boundary wrapping
            if c[4] < -CARD_W c[4] = SCREEN_W + 0.0 ok
            if c[4] > SCREEN_W c[4] = -CARD_W + 0.0 ok
            if c[5] < -CARD_H c[5] = SCREEN_H - 60.0 ok
            if c[5] > SCREEN_H - 60 c[5] = -CARD_H + 0.0 ok
        ok

        if aType = ANIM_SPIRAL
            c[12] += 40.0 * dt   // radius grows
            c[11] += c[13] * dt  // angle advances
            c[4] = SCREEN_W / 2.0 + cos(c[11]) * c[12]
            c[5] = (SCREEN_H - 60) / 2.0 + sin(c[11]) * c[12]
            c[8] = c[11]         // rotate with spiral
            // Remove if off screen
            if c[4] < -CARD_W or c[4] > SCREEN_W + CARD_W or c[5] < -CARD_H or c[5] > SCREEN_H + CARD_H
                add(toRemove, i)
            ok
        ok

        if aType = ANIM_BOUNCE
            c[4] += c[6] * dt
            c[5] += c[7] * dt
            // Bounce off walls
            if c[4] < 5
                c[4] = 5.0
                c[6] = fabs(c[6])
            ok
            if c[4] > SCREEN_W - CARD_W - 5
                c[4] = SCREEN_W - CARD_W - 5.0
                c[6] = -fabs(c[6])
            ok
            if c[5] < 5
                c[5] = 5.0
                c[7] = fabs(c[7])
            ok
            if c[5] > SCREEN_H - CARD_H - 65
                c[5] = SCREEN_H - CARD_H - 65.0
                c[7] = -fabs(c[7])
            ok
            // Slight rotation based on velocity
            c[8] = sin(c[10] * 3.0) * 0.15
        ok

        if aType = ANIM_SPIN
            c[8] += c[11] * dt
            c[9] = 0.7 + fabs(cos(c[8])) * 0.5  // scale oscillates
        ok

        if aType = ANIM_WAVE
            c[4] += c[6] * dt
            c[5] = (SCREEN_H - 60) / 2.0 + sin(c[4] * c[12] / 100.0 + c[13]) * c[11]
            c[8] = cos(c[4] * c[12] / 100.0 + c[13]) * 0.3  // tilt with wave
            // Wrap horizontally
            if c[4] > SCREEN_W + CARD_W
                c[4] = -CARD_W + 0.0
            ok
        ok

        if aType = ANIM_CASCADE
            c[4] += c[6] * dt
            c[5] += c[7] * dt
            c[7] += 150.0 * dt  // gravity
            c[8] += c[11] * dt  // rotation
            // Reset when off bottom
            if c[5] > SCREEN_H + CARD_H
                c[4] = GetRandomValue(80, SCREEN_W - 80)
                c[5] = -CARD_H * 1.0
                c[7] = GetRandomValue(80, 200) * 1.0
                c[6] = (GetRandomValue(-50, 50) / 100.0) * 40.0
            ok
        ok

        if aType = ANIM_ORBIT
            c[11] += c[13] * dt  // advance angle
            c[4] = c[4]  // cx stays as center
            c[5] = c[5]
            // actual draw position calculated in draw func
        ok

        if aType = ANIM_FIREWORK
            c[4] += c[6] * dt
            c[5] += c[7] * dt
            c[7] += 80.0 * dt  // gravity
            c[6] *= 0.995      // air resistance
            c[8] += 3.0 * dt   // spin
            // Fade out after 2 seconds
            if c[10] > 2.0
                fade = 255 - floor((c[10] - 2.0) * 180)
                if fade < 0 fade = 0 ok
                c[14] = fade
            ok
            if c[10] > 3.5
                add(toRemove, i)
            ok
        ok

        cards[i] = c
    next

    // Remove expired cards (reverse order)
    for i = len(toRemove) to 1 step -1
        del(cards, toRemove[i])
    next

// =============================================================
// Draw
// =============================================================

func ca_draw
    // Background gradient effect
    for row = 0 to SCREEN_H - 60 step 4
        ratio = row / (SCREEN_H - 60.0)
        r = floor(15 + ratio * 20)
        g = floor(20 + ratio * 30)
        b = floor(45 + ratio * 40)
        DrawRectangle(0, row, SCREEN_W, 4, RAYLIBColor(r, g, b, 255))
    next

    // Draw all animated cards
    for i = 1 to len(cards)
        ca_drawAnimCard(cards[i])
    next

    // Paused overlay
    if paused
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H - 55, RAYLIBColor(0, 0, 0, 100))
        ptxt = "PAUSED"
        pw = MeasureText(ptxt, 60)
        DrawText(ptxt, (SCREEN_W - pw) / 2 + 2, (SCREEN_H - 60) / 2 - 28, 60, RAYLIBColor(0, 0, 0, 120))
        DrawText(ptxt, (SCREEN_W - pw) / 2, (SCREEN_H - 60) / 2 - 30, 60, RAYLIBColor(255, 215, 0, 220))
    ok

    // Bottom toolbar
    ca_drawToolbar()

    // Title bar
    DrawRectangle(0, 0, SCREEN_W, 30, RAYLIBColor(0, 0, 0, 140))
    DrawText("Cards Animation", 10, 6, 18, RAYLIBColor(255, 215, 0, 220))

    cardsTxt = "Cards: " + string(len(cards))
    cw = MeasureText(cardsTxt, 16)
    DrawText(cardsTxt, SCREEN_W - cw - 14, 8, 16, RAYLIBColor(200, 200, 220, 200))

    DrawText("Press 1-8 for specific animations | A: Random | P: Pause | C: Clear", 180, 8, 14, RAYLIBColor(160, 170, 190, 180))

    // FPS
    fpsTxt = "" + string(GetFPS()) + " FPS"
    DrawText(fpsTxt, SCREEN_W - 70, SCREEN_H - 15, 14, RAYLIBColor(100, 255, 100, 180))

// =============================================================
// Draw Animated Card
// =============================================================

func ca_drawAnimCard c
    aType = c[3]
    px = c[4]
    py = c[5]
    angle = c[8]
    scaleV = c[9]
    alpha = c[14]

    // Special position for orbit
    if aType = ANIM_ORBIT
        orbitAngle = c[11]
        orbitR = c[12]
        centerX = c[4]
        centerY = c[5]
        px = centerX + cos(orbitAngle) * orbitR - CARD_W / 2
        py = centerY + sin(orbitAngle) * orbitR - CARD_H / 2
        angle = orbitAngle * 0.3
        // Draw orbit trail (faint circle)
        DrawCircleLines(floor(centerX), floor(centerY), floor(orbitR),
                        RAYLIBColor(255, 255, 255, 30))
    ok

    // Draw shadow
    if alpha > 50
        shadowAlpha = floor(alpha * 0.25)
        DrawRectangle(floor(px) + 4, floor(py) + 4, CARD_W, CARD_H,
                      RAYLIBColor(0, 0, 0, shadowAlpha))
    ok

    // Draw the card
    ca_drawCardFace(floor(px), floor(py), c[1], c[2], alpha, scaleV, aType)

// =============================================================
// Draw Card Face
// =============================================================

func ca_drawCardFace x, y, rank, suit, alpha, scaleV, animType
    w = floor(CARD_W * scaleV)
    h = floor(CARD_H * scaleV)
    ox = x + (CARD_W - w) / 2
    oy = y + (CARD_H - h) / 2

    if alpha < 10 return ok

    // Card body
    DrawRectangle(ox, oy, w, h, RAYLIBColor(255, 255, 250, alpha))
    DrawRectangleLines(ox, oy, w, h, RAYLIBColor(80, 80, 80, alpha))

    // Inner border
    if w > 10 and h > 14
        DrawRectangleLines(ox + 3, oy + 3, w - 6, h - 6, RAYLIBColor(180, 180, 180, floor(alpha * 0.5)))
    ok

    // Suit color
    if suit = SUIT_HEART or suit = SUIT_DIAMOND
        tc = RAYLIBColor(200, 30, 30, alpha)
    else
        tc = RAYLIBColor(20, 20, 20, alpha)
    ok

    rName = rankNames[rank]
    sName = suitSyms[suit]

    if w < 40 or h < 55 return ok

    // Top-left rank and suit
    fontSize = floor(16 * scaleV)
    if fontSize < 8 fontSize = 8 ok
    suitFontSize = floor(12 * scaleV)
    if suitFontSize < 6 suitFontSize = 6 ok
    DrawText(rName, ox + 5, oy + 4, fontSize, tc)
    DrawText(sName, ox + 5, oy + 4 + fontSize, suitFontSize, tc)

    // Center rank
    cFontSize = floor(32 * scaleV)
    if cFontSize < 12 cFontSize = 12 ok
    rw = MeasureText(rName, cFontSize)
    DrawText(rName, ox + (w - rw) / 2, oy + (h - cFontSize) / 2, cFontSize, tc)

    // Bottom-right rank and suit
    rw2 = MeasureText(rName, fontSize)
    DrawText(rName, ox + w - rw2 - 5, oy + h - fontSize - 4, fontSize, tc)
    DrawText(sName, ox + w - suitFontSize - 8, oy + h - fontSize - 4 - suitFontSize, suitFontSize, tc)

    // Animation-specific decoration
    if animType = ANIM_FIREWORK
        // Sparkle border
        sparkle = floor(fabs(sin(animTime * 10.0)) * 80) + 50
        DrawRectangleLines(ox - 1, oy - 1, w + 2, h + 2, RAYLIBColor(255, 215, 0, floor(sparkle * alpha / 255)))
    ok
    if animType = ANIM_ORBIT
        // Soft glow
        DrawRectangleLines(ox - 1, oy - 1, w + 2, h + 2, RAYLIBColor(100, 200, 255, floor(alpha * 0.4)))
    ok
    if animType = ANIM_WAVE
        // Rainbow tint based on position
        hue = floor(fabs(sin(ox * 0.01 + animTime)) * 60)
        DrawRectangleLines(ox - 1, oy - 1, w + 2, h + 2, RAYLIBColor(hue + 180, 100 + hue, 255, floor(alpha * 0.5)))
    ok

// =============================================================
// Toolbar
// =============================================================

func ca_drawToolbar
    // Toolbar background
    DrawRectangle(0, SCREEN_H - 55, SCREEN_W, 55, RAYLIBColor(20, 20, 35, 240))
    DrawRectangle(0, SCREEN_H - 55, SCREEN_W, 2, RAYLIBColor(80, 80, 120, 200))

    mx = GetMouseX()
    my = GetMouseY()
    hoverBtn = 0

    // Main action buttons
    bx = BTN_GAP
    bx = ca_drawBtn("Add [A]", bx, 1, RAYLIBColor(40, 130, 70, 255), mx, my)
    bx += BTN_GAP

    if paused
        bx = ca_drawBtn("Resume [P]", bx, 2, RAYLIBColor(200, 140, 30, 255), mx, my)
    else
        bx = ca_drawBtn("Pause [P]", bx, 2, RAYLIBColor(180, 120, 20, 255), mx, my)
    ok
    bx += BTN_GAP

    bx = ca_drawBtn("Clear [C]", bx, 3, RAYLIBColor(170, 40, 40, 255), mx, my)
    bx += BTN_GAP * 3

    // Separator
    DrawRectangle(bx - BTN_GAP, BTN_Y + 4, 2, BTN_H - 8, RAYLIBColor(80, 80, 120, 150))

    // Animation type buttons
    btnColors = [
        RAYLIBColor(60, 100, 160, 255),
        RAYLIBColor(130, 60, 150, 255),
        RAYLIBColor(40, 140, 140, 255),
        RAYLIBColor(160, 100, 40, 255),
        RAYLIBColor(50, 130, 80, 255),
        RAYLIBColor(140, 70, 70, 255),
        RAYLIBColor(60, 80, 160, 255),
        RAYLIBColor(160, 50, 100, 255)
    ]

    for i = 1 to ANIM_COUNT
        label = "" + string(i) + ":" + animNames[i]
        bx = ca_drawBtn(label, bx, 10 + i, btnColors[i], mx, my)
        bx += 4
    next

func ca_drawBtn label, bx, btnId, baseCol, mx, my
    tw = MeasureText(label, 14) + 18
    if tw < 60 tw = 60 ok

    isHover = (mx >= bx and mx <= bx + tw and my >= BTN_Y and my <= BTN_Y + BTN_H)

    if isHover
        hoverBtn = btnId
        DrawRectangle(bx, BTN_Y, tw, BTN_H, RAYLIBColor(255, 225, 100, 240))
        DrawRectangleLines(bx, BTN_Y, tw, BTN_H, RAYLIBColor(200, 180, 60, 255))
        lw = MeasureText(label, 14)
        DrawText(label, bx + (tw - lw) / 2, BTN_Y + 12, 14, RAYLIBColor(20, 15, 10, 255))
    else
        DrawRectangle(bx, BTN_Y, tw, BTN_H, baseCol)
        DrawRectangleLines(bx, BTN_Y, tw, BTN_H, RAYLIBColor(255, 255, 255, 40))
        lw = MeasureText(label, 14)
        DrawText(label, bx + (tw - lw) / 2, BTN_Y + 12, 14, WHITE)
    ok

    return bx + tw

// =============================================================
// Handle Click
// =============================================================

func ca_handleClick mx, my
    if hoverBtn = 1
        ca_addRandomCard()
        return
    ok
    if hoverBtn = 2
        paused = !paused
        return
    ok
    if hoverBtn = 3
        cards = []
        return
    ok
    if hoverBtn >= 11 and hoverBtn <= 10 + ANIM_COUNT
        ca_addCard(hoverBtn - 10)
        return
    ok
