/*
**  Analog Clock - RingRayLib
**  ============================
**  Beautiful analog clock with smooth hands and multiple themes.
**
**  Controls:
**    T               - Cycle clock theme
**    S               - Toggle smooth/tick second hand
**    D               - Toggle date display
**    N               - Toggle numerals (Roman / Arabic / None)
**    P               - Toggle pendulum
**    F               - Toggle fullscreen
**    ESC             - Exit
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W = 600
SCREEN_H = 650

PI = 3.14159265

// Themes
THEME_CLASSIC  = 1
THEME_DARK     = 2
THEME_GOLD     = 3
THEME_MINIMAL  = 4
THEME_OCEAN    = 5
THEME_COUNT    = 5
themeNames = ["Classic", "Dark", "Gold", "Minimal", "Ocean"]

// Numeral styles
NUM_ARABIC = 1
NUM_ROMAN  = 2
NUM_NONE   = 3
NUM_COUNT  = 3

romanNums = ["XII", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XI"]
arabicNums = ["12", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11"]

// =============================================================
// State
// =============================================================

clockTheme = THEME_CLASSIC
numeralStyle = NUM_ARABIC
smoothSeconds = true
showDate = true
showPendulum = true
animTime = 0.0

// Clock geometry
centerX = SCREEN_W / 2
centerY = 290
clockRadius = 230

// Pendulum
pendAngle = 0.0
pendSpeed = 0.0
pendLength = 120

// Time tracking - read once at startup, then advance with dt
curHour = 0
curMinute = 0
curSecond = 0
curFracSec = 0.0
totalSeconds = 0.0

// Initialize from system time
tl = TimeList()
curHour = number(tl[7])
curMinute = number(tl[8])
curSecond = number(tl[9])
totalSeconds = curHour * 3600 + curMinute * 60 + curSecond

// =============================================================
// Main
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Analog Clock - RingRayLib")
SetTargetFPS(60)
SetExitKey(0)

while !WindowShouldClose()
    ac_update()
    BeginDrawing()
        ac_draw()
    EndDrawing()
end

CloseWindow()

// =============================================================
// Update
// =============================================================

func ac_update
    dt = GetFrameTime()
    animTime += dt

    if IsKeyPressed(KEY_ESCAPE)
        CloseWindow()
        shutdown(0)
    ok

    if IsKeyPressed(KEY_T)
        clockTheme++
        if clockTheme > THEME_COUNT clockTheme = 1 ok
    ok

    if IsKeyPressed(KEY_S)
        smoothSeconds = !smoothSeconds
    ok

    if IsKeyPressed(KEY_D)
        showDate = !showDate
    ok

    if IsKeyPressed(KEY_N)
        numeralStyle++
        if numeralStyle > NUM_COUNT numeralStyle = 1 ok
    ok

    if IsKeyPressed(KEY_P)
        showPendulum = !showPendulum
    ok

    // Advance time using dt
    totalSeconds += dt
    if totalSeconds >= 86400 totalSeconds -= 86400 ok

    tsFloor = floor(totalSeconds)
    curFracSec = totalSeconds - tsFloor
    curSecond = tsFloor % 60
    curMinute = floor(tsFloor / 60) % 60
    curHour = floor(tsFloor / 3600) % 24

    // Pendulum physics (simple harmonic)
    if showPendulum
        gravity = 9.8
        pendAccel = -(gravity / (pendLength * 0.01)) * sin(pendAngle)
        pendSpeed += pendAccel * dt
        pendSpeed *= 0.998   // slight damping
        pendAngle += pendSpeed * dt

        // Keep it swinging - add energy if almost stopped
        if fabs(pendSpeed) < 0.3 and fabs(pendAngle) < 0.05
            pendAngle = 0.35
        ok
    ok

// =============================================================
// Get Theme Colors
// =============================================================

func ac_getColors
    // Returns: [bgR,bgG,bgB, faceR,faceG,faceB, rimR,rimG,rimB,
    //           hourR,hourG,hourB, minR,minG,minB, secR,secG,secB,
    //           tickR,tickG,tickB, numR,numG,numB]
    //            1-3               4-6              7-9
    //            10-12             13-15            16-18
    //            19-21             22-24

    if clockTheme = THEME_CLASSIC
        return [235,230,220,  255,253,248,  80,60,40,
                30,30,35,     30,30,50,     180,20,20,
                40,40,50,     50,40,30]
    ok
    if clockTheme = THEME_DARK
        return [20,20,30,     35,38,48,     100,100,120,
                200,200,210,  180,180,200,  255,80,60,
                120,120,140,  160,165,180]
    ok
    if clockTheme = THEME_GOLD
        return [40,25,15,     60,45,30,     200,170,80,
                220,200,140,  200,180,100,  180,50,30,
                180,160,80,   210,190,110]
    ok
    if clockTheme = THEME_MINIMAL
        return [245,245,245,  255,255,255,  200,200,200,
                60,60,60,     80,80,80,     220,60,40,
                150,150,150,  100,100,100]
    ok
    // THEME_OCEAN
    return [15,30,50,     25,50,75,     80,160,200,
            180,220,240,  140,200,220,  255,120,80,
            70,140,180,   150,200,230]

// =============================================================
// Draw
// =============================================================

func ac_draw
    cols = ac_getColors()

    // Background
    ClearBackground(RAYLIBColor(cols[1], cols[2], cols[3], 255))

    // Background texture (subtle radial gradient)
    for ring = 0 to 20
        ratio = ring / 20.0
        gr = floor(cols[1] + (cols[4] - cols[1]) * ratio * 0.3)
        gg = floor(cols[2] + (cols[5] - cols[2]) * ratio * 0.3)
        gb = floor(cols[3] + (cols[6] - cols[3]) * ratio * 0.3)
        r = clockRadius + 40 - ring * 3
        if r > 0
            DrawCircle(centerX, centerY, r + 50, RAYLIBColor(gr, gg, gb, 15))
        ok
    next

    // Pendulum (behind clock)
    if showPendulum
        ac_drawPendulum(cols)
    ok

    // Clock face shadow
    DrawCircle(centerX + 3, centerY + 3, clockRadius + 8, RAYLIBColor(0, 0, 0, 40))

    // Outer rim
    DrawCircle(centerX, centerY, clockRadius + 8, RAYLIBColor(cols[7], cols[8], cols[9], 255))
    DrawCircle(centerX, centerY, clockRadius + 5, RAYLIBColor(cols[7]+20, cols[8]+20, cols[9]+20, 255))

    // Clock face
    DrawCircle(centerX, centerY, clockRadius, RAYLIBColor(cols[4], cols[5], cols[6], 255))

    // Inner decorative ring
    DrawCircleLines(centerX, centerY, clockRadius - 15, RAYLIBColor(cols[19], cols[20], cols[21], 60))

    // Minute tick marks
    for i = 0 to 59
        angle = i * 6.0 * PI / 180.0 - PI / 2.0

        if i % 5 = 0
            // Hour tick - thicker, longer
            innerR = clockRadius - 28
            outerR = clockRadius - 8
            thick = 3
            tc = RAYLIBColor(cols[19], cols[20], cols[21], 255)
        else
            // Minute tick
            innerR = clockRadius - 18
            outerR = clockRadius - 8
            thick = 1
            tc = RAYLIBColor(cols[19], cols[20], cols[21], 120)
        ok

        x1 = centerX + cos(angle) * innerR
        y1 = centerY + sin(angle) * innerR
        x2 = centerX + cos(angle) * outerR
        y2 = centerY + sin(angle) * outerR

        if thick > 1
            // Draw thick line as thin rectangle
            dx = x2 - x1
            dy = y2 - y1
            len2 = sqrt(dx*dx + dy*dy)
            if len2 > 0
                nx = -dy / len2 * thick / 2.0
                ny = dx / len2 * thick / 2.0
                DrawTriangle(
                    Vector2(x1-nx, y1-ny),
                    Vector2(x1+nx, y1+ny),
                    Vector2(x2+nx, y2+ny), tc)
                DrawTriangle(
                    Vector2(x1-nx, y1-ny),
                    Vector2(x2+nx, y2+ny),
                    Vector2(x2-nx, y2-ny), tc)
            ok
        else
            DrawLine(floor(x1), floor(y1), floor(x2), floor(y2), tc)
        ok
    next

    // Numerals
    if numeralStyle != NUM_NONE
        ac_drawNumerals(cols)
    ok

    // Get current time using epoch seconds
    // Time() returns string like "HH:MM:SS" or seconds
    // Use Clock()/Time() approach - compute from epoch
    
    // Ring's time functions: 
    //   Time() returns time as "HH:MM:SS" string
    //   TimeList() returns list of time components
    //   Clock() returns clock ticks
    
    // Most reliable: use the total seconds approach
    // We track time ourselves using dt accumulation
    
    hour = curHour
    minute = curMinute
    second = curSecond

    // 12-hour format
    hour12 = hour % 12

    // Fractional second for smooth hand
    fracSec = second + curFracSec
    if !smoothSeconds
        fracSec = second * 1.0
    ok

    // Calculate angles (0 = 12 o'clock, clockwise)
    secAngle = fracSec * 6.0 * PI / 180.0 - PI / 2.0
    minAngle = (minute + second / 60.0) * 6.0 * PI / 180.0 - PI / 2.0
    hourAngle = (hour12 + minute / 60.0) * 30.0 * PI / 180.0 - PI / 2.0

    // Hour hand shadow
    ac_drawHand(centerX + 2, centerY + 2, hourAngle, clockRadius * 0.50, 7, RAYLIBColor(0, 0, 0, 30))
    // Minute hand shadow
    ac_drawHand(centerX + 2, centerY + 2, minAngle, clockRadius * 0.72, 5, RAYLIBColor(0, 0, 0, 30))

    // Hour hand
    ac_drawHand(centerX, centerY, hourAngle, clockRadius * 0.50, 7, RAYLIBColor(cols[10], cols[11], cols[12], 255))
    // Minute hand
    ac_drawHand(centerX, centerY, minAngle, clockRadius * 0.72, 5, RAYLIBColor(cols[13], cols[14], cols[15], 255))

    // Second hand
    secCol = RAYLIBColor(cols[16], cols[17], cols[18], 255)
    // Tail
    tailLen = clockRadius * 0.18
    tailAngle = secAngle + PI
    tx = centerX + cos(tailAngle) * tailLen
    ty = centerY + sin(tailAngle) * tailLen
    DrawLine(centerX, centerY, floor(tx), floor(ty), secCol)

    // Main second hand
    ac_drawHand(centerX, centerY, secAngle, clockRadius * 0.78, 2, secCol)

    // Center cap (decorative)
    DrawCircle(centerX, centerY, 10, RAYLIBColor(cols[7], cols[8], cols[9], 255))
    DrawCircle(centerX, centerY, 6, RAYLIBColor(cols[16], cols[17], cols[18], 255))
    DrawCircle(centerX, centerY, 3, RAYLIBColor(cols[7], cols[8], cols[9], 255))

    // Date display
    if showDate
        ac_drawDate(cols)
    ok

    // Bottom info
    ac_drawBottomInfo(cols)

// =============================================================
// Draw Hand (as tapered shape)
// =============================================================

func ac_drawHand cx, cy, angle, length, width, col
    // Tip
    tipX = cx + cos(angle) * length
    tipY = cy + sin(angle) * length

    // Perpendicular for width
    perpX = -sin(angle) * width / 2.0
    perpY = cos(angle) * width / 2.0

    // Base slightly forward from center
    baseLen = length * 0.12
    bx = cx + cos(angle) * baseLen
    by = cy + sin(angle) * baseLen

    // Tapered: wide at base, narrow at tip
    tipW = width * 0.3
    tipPX = -sin(angle) * tipW / 2.0
    tipPY = cos(angle) * tipW / 2.0

    // Draw as two triangles (quad)
    DrawTriangle(
        Vector2(bx - perpX, by - perpY),
        Vector2(bx + perpX, by + perpY),
        Vector2(tipX + tipPX, tipY + tipPY), col)
    DrawTriangle(
        Vector2(bx - perpX, by - perpY),
        Vector2(tipX + tipPX, tipY + tipPY),
        Vector2(tipX - tipPX, tipY - tipPY), col)

// =============================================================
// Draw Numerals
// =============================================================

func ac_drawNumerals cols
    for i = 0 to 11
        angle = i * 30.0 * PI / 180.0 - PI / 2.0
        dist = clockRadius - 45

        nx = centerX + cos(angle) * dist
        ny = centerY + sin(angle) * dist

        if numeralStyle = NUM_ROMAN
            label = romanNums[i + 1]
            fontSize = 20
            if i = 0 fontSize = 18 ok  // XII is wider
        else
            label = arabicNums[i + 1]
            fontSize = 24
        ok

        lw = MeasureText(label, fontSize)
        DrawText(label, floor(nx) - lw / 2, floor(ny) - fontSize / 2, fontSize, RAYLIBColor(cols[22], cols[23], cols[24], 230))
    next

// =============================================================
// Draw Date
// =============================================================

func ac_drawDate cols
    // Date window at 3 o'clock position
    dwX = centerX + clockRadius * 0.35
    dwY = centerY - 12
    dwW = 55
    dwH = 24

    DrawRectangle(floor(dwX), floor(dwY), dwW, dwH, RAYLIBColor(cols[4]-15, cols[5]-15, cols[6]-15, 255))
    DrawRectangleLines(floor(dwX), floor(dwY), dwW, dwH, RAYLIBColor(cols[19], cols[20], cols[21], 100))

    // Show day number from TimeList
    tl = TimeList()
    dayStr = tl[6]
    tw = MeasureText(dayStr, 16)
    DrawText(dayStr, floor(dwX) + (dwW - tw) / 2, floor(dwY) + 4, 16, RAYLIBColor(cols[22], cols[23], cols[24], 220))

// =============================================================
// Draw Pendulum
// =============================================================

func ac_drawPendulum cols
    pivotX = centerX
    pivotY = centerY + clockRadius + 15

    bobX = pivotX + sin(pendAngle) * pendLength
    bobY = pivotY + cos(pendAngle) * pendLength

    // Rod
    DrawLine(pivotX, pivotY, floor(bobX), floor(bobY), RAYLIBColor(cols[7], cols[8], cols[9], 180))
    DrawLine(pivotX + 1, pivotY, floor(bobX) + 1, floor(bobY), RAYLIBColor(cols[7], cols[8], cols[9], 120))

    // Bob shadow
    DrawCircle(floor(bobX) + 2, floor(bobY) + 2, 16, RAYLIBColor(0, 0, 0, 30))

    // Bob
    DrawCircle(floor(bobX), floor(bobY), 16, RAYLIBColor(cols[7], cols[8], cols[9], 230))
    DrawCircle(floor(bobX), floor(bobY), 12, RAYLIBColor(cols[7]+30, cols[8]+30, cols[9]+30, 200))
    DrawCircle(floor(bobX), floor(bobY), 5, RAYLIBColor(cols[7], cols[8], cols[9], 255))

// =============================================================
// Bottom Info
// =============================================================

func ac_drawBottomInfo cols
    // Digital time from tracked values
    hStr = "" + curHour
    if len(hStr) < 2 hStr = "0" + hStr ok
    mStr = "" + curMinute
    if len(mStr) < 2 mStr = "0" + mStr ok
    sStr = "" + curSecond
    if len(sStr) < 2 sStr = "0" + sStr ok
    digTime = hStr + ":" + mStr + ":" + sStr
    tw = MeasureText(digTime, 20)
    DrawText(digTime, (SCREEN_W - tw) / 2, SCREEN_H - 38, 20, RAYLIBColor(cols[22], cols[23], cols[24], 160))

    // Theme name
    tName = "Theme: " + themeNames[clockTheme] + " [T]"
    DrawText(tName, 10, SCREEN_H - 22, 13, RAYLIBColor(cols[22], cols[23], cols[24], 100))

    // Controls hint
    hint = "S:Smooth  D:Date  N:Numerals  P:Pendulum"
    hw = MeasureText(hint, 12)
    DrawText(hint, SCREEN_W - hw - 10, SCREEN_H - 22, 12, RAYLIBColor(cols[22], cols[23], cols[24], 80))

    // FPS
    fpsTxt = "" + string(GetFPS()) + " FPS"
    DrawText(fpsTxt, SCREEN_W - 60, SCREEN_H - 38, 12, RAYLIBColor(100, 200, 100, 100))
