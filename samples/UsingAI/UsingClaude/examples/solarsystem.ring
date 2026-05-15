/*
**  3D Solar System - RingRayLib
**  ==============================
**  Interactive 3D solar system with orbiting planets.
**  Relative sizes, distances, and orbital speeds are
**  scaled for visual appeal while keeping proportions.
**
**  Controls:
**    V               - Cycle camera (Free / Follow / Overhead / Orbit)
**    N               - Next planet (for follow camera)
**    L               - Toggle orbit lines
**    I               - Toggle info panel
**    T               - Toggle planet labels
**    +/-             - Speed up / Slow down simulation
**    Space / P       - Pause / Resume
**    R               - Reset time
**    ESC             - Exit
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W = 1024
SCREEN_H = 700
TOOLBAR_H = 55

// =============================================================
// Planet Data (scaled for visual appeal)
//   Real ratios kept approximate but scaled so everything fits
//   Distances: AU scaled to units (1 AU ~ 30 units)
//   Sizes: log-scaled so small planets are visible
//   Orbital periods in Earth-years (1 year = base speed)
// =============================================================

PLANET_COUNT = 8

// Names
planetNames = ["Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"]

// Orbital distance (scaled AU -> units)
planetDist = [11.6, 21.6, 30.0, 45.6, 78.0, 114.0, 172.0, 225.0]

// Planet radius (log-scaled for visibility)
planetRadius = [0.6, 0.9, 1.0, 0.7, 3.2, 2.7, 1.8, 1.7]

// Orbital period in Earth-years
planetPeriod = [0.24, 0.615, 1.0, 1.88, 11.86, 29.46, 84.01, 164.8]

// Orbit inclination (degrees, exaggerated for 3D effect)
planetIncl = [3.0, 1.5, 0.0, 2.5, 1.0, 2.0, 4.0, 1.5]

// Planet colors [R, G, B]
planetColors = [
    [180, 160, 140],
    [230, 190, 120],
    [70, 130, 230],
    [200, 100, 60],
    [210, 170, 120],
    [220, 200, 150],
    [170, 220, 230],
    [80, 120, 200]
]

// Axial tilt for visual variety (degrees)
planetTilt = [0.03, 177.4, 23.4, 25.2, 3.1, 26.7, 97.8, 28.3]

// Has rings
planetRings = [0, 0, 0, 0, 0, 1, 1, 0]

// Sun
SUN_RADIUS = 6.0

// Moon around Earth
MOON_DIST = 2.5
MOON_RADIUS = 0.3
MOON_PERIOD = 0.0748  // ~27.3 days in years

// =============================================================
// State
// =============================================================

simTime = 0.0          // simulation time in years
simSpeed = 1.0         // years per second
paused = false
animTime = 0.0

// Planet current positions
planetX = list(PLANET_COUNT)
planetY = list(PLANET_COUNT)
planetZ = list(PLANET_COUNT)

// Planet orbit angles
planetAngle = list(PLANET_COUNT)
for i = 1 to PLANET_COUNT
    planetAngle[i] = GetRandomValue(0, 628) / 100.0
next

moonAngle = 0.0

// Camera
CAM_FREE     = 1
CAM_FOLLOW   = 2
CAM_OVERHEAD = 3
CAM_ORBIT    = 4
CAM_COUNT    = 4
camModeNames = ["Free", "Follow", "Overhead", "Orbit"]

cameraMode = CAM_FREE
camPosX = 0.0    camPosY = 80.0   camPosZ = 120.0
camTgtX = 0.0    camTgtY = 0.0    camTgtZ = 0.0
camOrbitAngle = 0.0
followPlanet = 3  // Earth by default

// Display toggles
showOrbits = true
showLabels = true
showInfo = true

// Toolbar
hoverBtn = 0
BTN_Y = SCREEN_H - 52
BTN_H = 38
BTN_GAP = 5

// Starfield
STAR_COUNT = 500
starX = list(STAR_COUNT)
starY = list(STAR_COUNT)
starZ = list(STAR_COUNT)
starBright = list(STAR_COUNT)
for i = 1 to STAR_COUNT
    starX[i] = GetRandomValue(-500, 500)
    starY[i] = GetRandomValue(-500, 500)
    starZ[i] = GetRandomValue(-500, 500)
    starBright[i] = GetRandomValue(80, 255)
next

// =============================================================
// Main
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "3D Solar System - RingRayLib")
SetTargetFPS(60)
SetExitKey(0)

camera = Camera3D(
    0, 80, 120,
    0, 0, 0,
    0, 1, 0,
    45,
    CAMERA_PERSPECTIVE
)

while !WindowShouldClose()
    ss_update()
    BeginDrawing()
        ClearBackground(RAYLIBColor(2, 2, 8, 255))
        BeginMode3D(camera)
            ss_draw3D()
        EndMode3D()
        ss_drawHUD()
        ss_drawToolbar()
    EndDrawing()
end

CloseWindow()

// =============================================================
// Update
// =============================================================

func ss_update
    dt = GetFrameTime()
    animTime += dt

    if IsKeyPressed(KEY_ESCAPE)
        CloseWindow()
        shutdown(0)
    ok

    if IsKeyPressed(KEY_SPACE) or IsKeyPressed(KEY_P)
        paused = !paused
    ok

    if IsKeyPressed(KEY_V)
        cameraMode++
        if cameraMode > CAM_COUNT cameraMode = CAM_FREE ok
    ok

    if IsKeyPressed(KEY_N)
        followPlanet++
        if followPlanet > PLANET_COUNT followPlanet = 1 ok
    ok

    if IsKeyPressed(KEY_L)
        showOrbits = !showOrbits
    ok

    if IsKeyPressed(KEY_I)
        showInfo = !showInfo
    ok

    if IsKeyPressed(KEY_T)
        showLabels = !showLabels
    ok

    if IsKeyPressed(KEY_R)
        simTime = 0.0
    ok

    // Speed control
    if IsKeyPressed(KEY_EQUAL) or IsKeyPressed(KEY_KP_ADD)
        simSpeed *= 2.0
        if simSpeed > 128.0 simSpeed = 128.0 ok
    ok
    if IsKeyPressed(KEY_MINUS) or IsKeyPressed(KEY_KP_SUBTRACT)
        simSpeed /= 2.0
        if simSpeed < 0.0625 simSpeed = 0.0625 ok
    ok

    // Toolbar clicks
    if IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
        ss_handleClick(GetMouseX(), GetMouseY())
    ok

    // Simulation
    if !paused
        simTime += dt * simSpeed
    ok

    // Update planet positions
    ss_updatePlanets()

    // Camera
    ss_updateCamera(dt)

// =============================================================
// Update Planet Positions
// =============================================================

func ss_updatePlanets
    for i = 1 to PLANET_COUNT
        // Angle based on period: angle = 2*PI * time / period
        planetAngle[i] = 2.0 * 3.14159 * simTime / planetPeriod[i]

        dist = planetDist[i]
        incl = planetIncl[i] * 3.14159 / 180.0

        planetX[i] = cos(planetAngle[i]) * dist
        planetZ[i] = sin(planetAngle[i]) * dist
        planetY[i] = sin(planetAngle[i]) * sin(incl) * dist * 0.05
    next

    moonAngle = 2.0 * 3.14159 * simTime / MOON_PERIOD

// =============================================================
// Camera
// =============================================================

func ss_updateCamera dt
    goalX = 0.0  goalY = 0.0  goalZ = 0.0
    tgtX = 0.0   tgtY = 0.0   tgtZ = 0.0

    if cameraMode = CAM_FREE
        goalX = 0.0    goalY = 80.0   goalZ = 120.0
        tgtX = 0.0     tgtY = 0.0     tgtZ = 0.0
    ok

    if cameraMode = CAM_FOLLOW
        fp = followPlanet
        px = planetX[fp]
        py = planetY[fp]
        pz = planetZ[fp]
        // Camera behind and above the planet looking toward sun
        dist = planetDist[fp] * 0.3
        if dist < 8 dist = 8 ok
        if dist > 40 dist = 40 ok
        angle = planetAngle[fp]
        goalX = px + cos(angle) * dist
        goalY = py + dist * 0.6
        goalZ = pz + sin(angle) * dist
        tgtX = px   tgtY = py   tgtZ = pz
    ok

    if cameraMode = CAM_OVERHEAD
        goalX = 0.0    goalY = 280.0   goalZ = 10.0
        tgtX = 0.0     tgtY = 0.0      tgtZ = 0.0
    ok

    if cameraMode = CAM_ORBIT
        camOrbitAngle += dt * 0.15
        dist = 200.0
        goalX = cos(camOrbitAngle) * dist
        goalY = 100.0
        goalZ = sin(camOrbitAngle) * dist
        tgtX = 0.0  tgtY = 0.0  tgtZ = 0.0
    ok

    lerpSpd = 0.03
    camPosX += (goalX - camPosX) * lerpSpd
    camPosY += (goalY - camPosY) * lerpSpd
    camPosZ += (goalZ - camPosZ) * lerpSpd
    camTgtX += (tgtX - camTgtX) * lerpSpd
    camTgtY += (tgtY - camTgtY) * lerpSpd
    camTgtZ += (tgtZ - camTgtZ) * lerpSpd

    camera = Camera3D(
        camPosX, camPosY, camPosZ,
        camTgtX, camTgtY, camTgtZ,
        0, 1, 0,
        45, CAMERA_PERSPECTIVE
    )

// =============================================================
// Draw 3D
// =============================================================

func ss_draw3D
    // Stars
    for i = 1 to STAR_COUNT
        b = starBright[i]
        twinkle = floor(sin(animTime * 2.0 + i * 0.7) * 30)
        sb = b + twinkle
        if sb > 255 sb = 255 ok
        if sb < 50 sb = 50 ok
        DrawSphere(Vector3(starX[i], starY[i], starZ[i]), 0.3, RAYLIBColor(sb, sb, floor(sb * 0.9), 255))
    next

    // Sun
    sunPulse = 1.0 + sin(animTime * 2.0) * 0.05
    sunR = SUN_RADIUS * sunPulse
    DrawSphere(Vector3(0, 0, 0), sunR, RAYLIBColor(255, 200, 50, 255))
    // Sun glow layers
    DrawSphere(Vector3(0, 0, 0), sunR * 1.15, RAYLIBColor(255, 180, 30, 60))
    DrawSphere(Vector3(0, 0, 0), sunR * 1.35, RAYLIBColor(255, 150, 20, 30))

    // Orbit lines
    if showOrbits
        for i = 1 to PLANET_COUNT
            ss_drawOrbitLine(planetDist[i], planetIncl[i], i)
        next
    ok

    // Planets
    for i = 1 to PLANET_COUNT
        px = planetX[i]
        py = planetY[i]
        pz = planetZ[i]
        pr = planetRadius[i]
        pc = planetColors[i]

        // Planet sphere
        DrawSphere(Vector3(px, py, pz), pr, RAYLIBColor(pc[1], pc[2], pc[3], 255))

        // Atmosphere/glow for gas giants
        if i >= 5
            DrawSphere(Vector3(px, py, pz), pr * 1.08, RAYLIBColor(pc[1], pc[2], pc[3], 40))
        ok

        // Rings for Saturn and Uranus
        if planetRings[i] = 1
            ss_drawRings(px, py, pz, pr, pc)
        ok

        // Earth's moon
        if i = 3
            mx = px + cos(moonAngle) * MOON_DIST
            my = py + 0.1
            mz = pz + sin(moonAngle) * MOON_DIST
            DrawSphere(Vector3(mx, my, mz), MOON_RADIUS, RAYLIBColor(200, 200, 190, 255))
        ok
    next

// =============================================================
// Draw Orbit Line (circle in 3D using line segments)
// =============================================================

func ss_drawOrbitLine dist, inclDeg, planetIdx
    segments = 80
    incl = inclDeg * 3.14159 / 180.0

    // Orbit color - subtle, based on planet
    pc = planetColors[planetIdx]
    oc = RAYLIBColor(floor(pc[1] * 0.4), floor(pc[2] * 0.4), floor(pc[3] * 0.4), 50)

    prevX = cos(0) * dist
    prevZ = sin(0) * dist
    prevY = sin(0) * sin(incl) * dist * 0.05

    for s = 1 to segments
        angle = 2.0 * 3.14159 * s / segments
        cx = cos(angle) * dist
        cz = sin(angle) * dist
        cy = sin(angle) * sin(incl) * dist * 0.05

        DrawLine3D(Vector3(prevX, prevY, prevZ), Vector3(cx, cy, cz), oc)

        prevX = cx
        prevY = cy
        prevZ = cz
    next

// =============================================================
// Draw Rings (for Saturn/Uranus)
// =============================================================

func ss_drawRings px, py, pz, pr, pc
    ringSegments = 48
    innerR = pr * 1.5
    outerR = pr * 2.5

    ringCol = RAYLIBColor(floor(pc[1] * 0.8), floor(pc[2] * 0.8), floor(pc[3] * 0.6), 120)

    // Draw ring as a series of line segments at two radii
    for ring = 0 to 3
        r = innerR + (outerR - innerR) * ring / 3.0
        prevX = px + cos(0) * r
        prevZ = pz + sin(0) * r

        for s = 1 to ringSegments
            angle = 2.0 * 3.14159 * s / ringSegments
            cx = px + cos(angle) * r
            cz = pz + sin(angle) * r
            DrawLine3D(Vector3(prevX, py, prevZ), Vector3(cx, py, cz), ringCol)
            prevX = cx
            prevZ = cz
        next
    next

// =============================================================
// 3D to 2D Projection
// =============================================================

func ss_project wx, wy, wz
    fwdX = camTgtX - camPosX
    fwdY = camTgtY - camPosY
    fwdZ = camTgtZ - camPosZ
    fLen = sqrt(fwdX*fwdX + fwdY*fwdY + fwdZ*fwdZ)
    if fLen < 0.0001 return [-9999, -9999] ok
    fwdX /= fLen   fwdY /= fLen   fwdZ /= fLen

    rX = fwdY * 0 - fwdZ * 1
    rY = fwdZ * 0 - fwdX * 0
    rZ = fwdX * 1 - fwdY * 0
    rLen = sqrt(rX*rX + rY*rY + rZ*rZ)
    if rLen < 0.0001 return [-9999, -9999] ok
    rX /= rLen   rY /= rLen   rZ /= rLen

    uX = rY * fwdZ - rZ * fwdY
    uY = rZ * fwdX - rX * fwdZ
    uZ = rX * fwdY - rY * fwdX

    dx = wx - camPosX
    dy = wy - camPosY
    dz = wz - camPosZ

    camZv = dx * fwdX + dy * fwdY + dz * fwdZ
    if camZv < 0.1 return [-9999, -9999] ok
    camXv = dx * rX + dy * rY + dz * rZ
    camYv = dx * uX + dy * uY + dz * uZ

    fov = 45.0
    aspect = SCREEN_W * 1.0 / SCREEN_H
    tanHalf = tan((fov / 2.0) * 3.14159 / 180.0)

    ndcX = camXv / (camZv * tanHalf * aspect)
    ndcY = camYv / (camZv * tanHalf)

    scrX = (ndcX + 1.0) * SCREEN_W / 2.0
    scrY = (1.0 - ndcY) * SCREEN_H / 2.0

    return [scrX, scrY]

// =============================================================
// HUD
// =============================================================

func ss_drawHUD
    // Planet labels
    if showLabels
        for i = 1 to PLANET_COUNT
            pos = ss_project(planetX[i], planetY[i] + planetRadius[i] + 1.5, planetZ[i])
            sx = pos[1]   sy = pos[2]
            if sx < -100 or sx > SCREEN_W + 100 loop ok
            if sy < -50 or sy > SCREEN_H loop ok

            pc = planetColors[i]
            label = planetNames[i]
            lw = MeasureText(label, 14)

            DrawRectangle(floor(sx) - lw/2 - 4, floor(sy) - 2, lw + 8, 18, RAYLIBColor(0, 0, 0, 140))
            DrawText(label, floor(sx) - lw/2, floor(sy), 14, RAYLIBColor(pc[1], pc[2], pc[3], 220))
        next

        // Sun label
        spos = ss_project(0, SUN_RADIUS + 2, 0)
        if spos[1] > -100 and spos[1] < SCREEN_W + 100
            slw = MeasureText("Sun", 16)
            DrawRectangle(floor(spos[1]) - slw/2 - 4, floor(spos[2]) - 2, slw + 8, 20, RAYLIBColor(0, 0, 0, 140))
            DrawText("Sun", floor(spos[1]) - slw/2, floor(spos[2]), 16, RAYLIBColor(255, 220, 80, 230))
        ok
    ok

    // Top bar
    DrawRectangle(0, 0, SCREEN_W, 28, RAYLIBColor(0, 0, 0, 200))
    DrawText("3D Solar System", 10, 5, 18, RAYLIBColor(255, 215, 0, 220))

    timeTxt = "Time: " + ss_formatTime(simTime)
    DrawText(timeTxt, 200, 7, 14, RAYLIBColor(180, 220, 255, 200))

    spdTxt = "Speed: " + ss_formatSpeed(simSpeed)
    DrawText(spdTxt, 420, 7, 14, RAYLIBColor(255, 200, 150, 200))

    camTxt = "Cam: " + camModeNames[cameraMode]
    DrawText(camTxt, 580, 7, 14, RAYLIBColor(180, 200, 220, 180))

    if cameraMode = CAM_FOLLOW
        fTxt = "-> " + planetNames[followPlanet]
        DrawText(fTxt, 660, 7, 14, RAYLIBColor(planetColors[followPlanet][1], planetColors[followPlanet][2], planetColors[followPlanet][3], 230))
    ok

    if paused
        DrawText("PAUSED", SCREEN_W - 80, 7, 14, RAYLIBColor(255, 100, 100, 240))
    ok

    // Info panel
    if showInfo
        ss_drawInfoPanel()
    ok

    // FPS
    fpsTxt = "" + string(GetFPS()) + " FPS"
    DrawText(fpsTxt, SCREEN_W - 70, SCREEN_H - 15, 14, RAYLIBColor(100, 255, 100, 180))

// =============================================================
// Info Panel
// =============================================================

func ss_drawInfoPanel
    panelX = SCREEN_W - 195
    panelY = 34
    panelW = 190
    panelH = 26 + PLANET_COUNT * 22

    DrawRectangle(panelX, panelY, panelW, panelH, RAYLIBColor(0, 0, 0, 180))
    DrawRectangleLines(panelX, panelY, panelW, panelH, RAYLIBColor(60, 60, 100, 180))

    DrawText("Planet Distances", panelX + 8, panelY + 5, 13, RAYLIBColor(255, 215, 0, 200))

    for i = 1 to PLANET_COUNT
        py = panelY + 22 + (i - 1) * 22
        pc = planetColors[i]

        // Color dot
        DrawCircle(panelX + 14, py + 7, 5, RAYLIBColor(pc[1], pc[2], pc[3], 220))

        // Name
        DrawText(planetNames[i], panelX + 24, py, 13, RAYLIBColor(200, 200, 220, 200))

        // Distance from sun
        dx = planetX[i]
        dy = planetY[i]
        dz = planetZ[i]
        dist = sqrt(dx*dx + dy*dy + dz*dz)
        au = dist / 30.0
        auTxt = ss_floatStr(au, 1) + " AU"
        tw = MeasureText(auTxt, 12)
        DrawText(auTxt, panelX + panelW - tw - 8, py + 1, 12, RAYLIBColor(150, 180, 200, 180))
    next

// =============================================================
// Format Helpers
// =============================================================

func ss_formatTime years
    if fabs(years) < 1.0
        days = years * 365.25
        return ss_floatStr(days, 1) + " days"
    ok
    return ss_floatStr(years, 2) + " years"

func ss_formatSpeed spd
    if spd >= 1.0
        return ss_floatStr(spd, 1) + "x"
    ok
    return "1/" + string(floor(1.0 / spd)) + "x"

func ss_floatStr val, decimals
    if decimals = 0 return string(floor(val)) ok
    factor = pow(10, decimals)
    rounded = floor(val * factor + 0.5)
    intPart = floor(rounded / factor)
    fracPart = floor(rounded % factor)

    fracStr = string(fracPart)
    while len(fracStr) < decimals
        fracStr = "0" + fracStr
    end

    return string(intPart) + "." + fracStr

// =============================================================
// Toolbar
// =============================================================

func ss_drawToolbar
    DrawRectangle(0, SCREEN_H - TOOLBAR_H, SCREEN_W, TOOLBAR_H, RAYLIBColor(10, 10, 25, 255))
    DrawRectangle(0, SCREEN_H - TOOLBAR_H, SCREEN_W, 2, RAYLIBColor(60, 60, 100, 200))

    mx = GetMouseX()
    my = GetMouseY()
    hoverBtn = 0

    bx = BTN_GAP

    // Play/Pause
    if paused
        bx = ss_drawBtn("Play [P]", bx, 1, RAYLIBColor(40, 130, 70, 255), mx, my)
    else
        bx = ss_drawBtn("Pause [P]", bx, 1, RAYLIBColor(180, 120, 20, 255), mx, my)
    ok
    bx += BTN_GAP

    // Camera
    bx = ss_drawBtn("Camera [V]", bx, 2, RAYLIBColor(60, 80, 150, 255), mx, my)
    bx += BTN_GAP

    // Follow Next
    bx = ss_drawBtn("Next [N]", bx, 3, RAYLIBColor(80, 60, 140, 255), mx, my)
    bx += BTN_GAP

    // Orbits
    if showOrbits
        bx = ss_drawBtn("Orbits [L]", bx, 4, RAYLIBColor(40, 100, 100, 255), mx, my)
    else
        bx = ss_drawBtn("Orbits [L]", bx, 4, RAYLIBColor(60, 60, 60, 255), mx, my)
    ok
    bx += BTN_GAP

    // Labels
    if showLabels
        bx = ss_drawBtn("Labels [T]", bx, 5, RAYLIBColor(40, 100, 100, 255), mx, my)
    else
        bx = ss_drawBtn("Labels [T]", bx, 5, RAYLIBColor(60, 60, 60, 255), mx, my)
    ok
    bx += BTN_GAP

    // Info
    if showInfo
        bx = ss_drawBtn("Info [I]", bx, 6, RAYLIBColor(40, 100, 100, 255), mx, my)
    else
        bx = ss_drawBtn("Info [I]", bx, 6, RAYLIBColor(60, 60, 60, 255), mx, my)
    ok
    bx += BTN_GAP

    // Separator
    DrawRectangle(bx, BTN_Y + 4, 2, BTN_H - 8, RAYLIBColor(60, 60, 100, 150))
    bx += BTN_GAP

    // Speed
    bx = ss_drawBtn("Slow [-]", bx, 7, RAYLIBColor(140, 70, 70, 255), mx, my)
    bx += BTN_GAP

    bx = ss_drawBtn("Fast [+]", bx, 8, RAYLIBColor(70, 140, 70, 255), mx, my)
    bx += BTN_GAP

    // Reset
    bx = ss_drawBtn("Reset [R]", bx, 9, RAYLIBColor(130, 60, 60, 255), mx, my)

func ss_drawBtn label, bx, btnId, baseCol, mx, my
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
        DrawRectangleLines(bx, BTN_Y, tw, BTN_H, RAYLIBColor(255, 255, 255, 30))
        lw = MeasureText(label, 13)
        DrawText(label, bx + (tw - lw) / 2, BTN_Y + 13, 13, WHITE)
    ok

    return bx + tw

// =============================================================
// Handle Click
// =============================================================

func ss_handleClick mx, my
    if hoverBtn = 1
        paused = !paused
        return
    ok
    if hoverBtn = 2
        cameraMode++
        if cameraMode > CAM_COUNT cameraMode = CAM_FREE ok
        return
    ok
    if hoverBtn = 3
        followPlanet++
        if followPlanet > PLANET_COUNT followPlanet = 1 ok
        return
    ok
    if hoverBtn = 4
        showOrbits = !showOrbits
        return
    ok
    if hoverBtn = 5
        showLabels = !showLabels
        return
    ok
    if hoverBtn = 6
        showInfo = !showInfo
        return
    ok
    if hoverBtn = 7
        simSpeed /= 2.0
        if simSpeed < 0.0625 simSpeed = 0.0625 ok
        return
    ok
    if hoverBtn = 8
        simSpeed *= 2.0
        if simSpeed > 128.0 simSpeed = 128.0 ok
        return
    ok
    if hoverBtn = 9
        simTime = 0.0
        return
    ok
