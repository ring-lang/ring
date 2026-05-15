/*
**  Traffic Simulator - RingRayLib
**  ==================================
**  Cars on roads with traffic lights and intersections.
**  Watch traffic flow, adjust light timing, add/remove cars.
**
**  Controls:
**    Space / P       - Pause / Resume
**    +/-             - Speed up / Slow down simulation
**    C               - Spawn extra car
**    L               - Cycle traffic light timing (short/medium/long)
**    T               - Toggle between 2x2 and 3x3 grid
**    R               - Reset simulation
**    D               - Toggle debug view (show car IDs, speeds)
**    ESC             - Exit
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W = 1024
SCREEN_H = 700
TOOLBAR_H = 48
CANVAS_H = SCREEN_H - TOOLBAR_H

PI = 3.14159265

// Road dimensions
ROAD_W = 48         // road width (both lanes)
LANE_W = 24         // single lane
HALF_ROAD = 24

// Car dimensions
CAR_W = 18
CAR_H = 10

// Directions
DIR_NORTH = 1
DIR_SOUTH = 2
DIR_EAST  = 3
DIR_WEST  = 4

// Traffic light states
LIGHT_GREEN   = 1
LIGHT_YELLOW  = 2
LIGHT_RED     = 3

// Light timing presets
TIMING_SHORT  = 1
TIMING_MEDIUM = 2
TIMING_LONG   = 3
TIMING_COUNT  = 3
timingNames = ["Short", "Medium", "Long"]
timingGreen  = [3.0, 5.0, 8.0]
timingYellow = [1.0, 1.5, 2.0]

// =============================================================
// State
// =============================================================

paused = false
simSpeed = 1.0
animTime = 0.0
debugView = false
currentTiming = TIMING_MEDIUM

// Grid mode
gridMode = 2         // 2 = 2x2, 3 = 3x3
gridCols = 2
gridRows = 2

// Road network
// Intersections: [x, y, lightNS, lightEW, timer, phase]
//   lightNS = light state for North-South
//   lightEW = light state for East-West
//   phase = 1 (NS green) or 2 (EW green) or transition
intersections = []

// Road segments for drawing: computed from intersections
// Horizontal roads: row of intersections
// Vertical roads: column of intersections

// Cars: [id, x, y, dir, speed, targetSpeed, lane, colorIdx, alive, waitTimer]
cars = []
nextCarId = 1
MAX_CARS = 120

// Car colors
carColors = [
    [200, 60, 60],
    [60, 120, 200],
    [60, 200, 80],
    [220, 180, 40],
    [180, 80, 200],
    [200, 130, 60],
    [60, 200, 200],
    [255, 255, 255],
    [140, 140, 160],
    [200, 100, 140]
]
CAR_COLOR_COUNT = 10

// Stats
totalCarsSpawned = 0
totalCarsExited = 0
totalWaitTime = 0.0

// Spawn timer
spawnTimer = 0.0
SPAWN_INTERVAL = 0.8

// Toolbar
hoverBtn = 0
BTN_Y = SCREEN_H - 46
BTN_H = 36
BTN_GAP = 4

// =============================================================
// Main
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Traffic Simulator - RingRayLib")
SetTargetFPS(60)
SetExitKey(0)

ts_buildGrid()

while !WindowShouldClose()
    ts_update()
    BeginDrawing()
        ClearBackground(RAYLIBColor(60, 90, 50, 255))
        ts_draw()
    EndDrawing()
end

CloseWindow()

// =============================================================
// Build Road Grid
// =============================================================

func ts_buildGrid
    intersections = []
    cars = []
    nextCarId = 1
    totalCarsSpawned = 0
    totalCarsExited = 0
    totalWaitTime = 0.0

    if gridMode = 2
        gridCols = 2   gridRows = 2
    else
        gridCols = 3   gridRows = 3
    ok

    // Evenly space intersections
    padX = 120
    padY = 80
    spacingX = (SCREEN_W - padX * 2) / (gridCols - 1 + 0.001)
    spacingY = (CANVAS_H - padY * 2) / (gridRows - 1 + 0.001)
    if gridCols = 1 spacingX = 0 ok
    if gridRows = 1 spacingY = 0 ok

    for row = 0 to gridRows - 1
        for col = 0 to gridCols - 1
            ix = padX + col * spacingX
            iy = padY + row * spacingY
            // Alternate starting phase for better flow
            phase = 1
            if (row + col) % 2 = 1 phase = 2 ok
            add(intersections, [floor(ix), floor(iy), LIGHT_GREEN, LIGHT_RED, 0.0, phase])
            // Set initial lights based on phase
            idx = len(intersections)
            if phase = 1
                intersections[idx][3] = LIGHT_GREEN
                intersections[idx][4] = LIGHT_RED
            else
                intersections[idx][3] = LIGHT_RED
                intersections[idx][4] = LIGHT_GREEN
            ok
        next
    next

    // Spawn initial cars
    for i = 1 to gridCols * gridRows * 4
        ts_spawnCar()
    next

// =============================================================
// Intersection Access
// =============================================================

func ts_intIdx row, col
    return row * gridCols + col + 1

func ts_intRow idx
    return floor((idx - 1) / gridCols)

func ts_intCol idx
    return (idx - 1) % gridCols

// =============================================================
// Spawn Car
// =============================================================

func ts_spawnCar
    if len(cars) >= MAX_CARS return ok

    // Pick a random edge to spawn from
    edge = GetRandomValue(1, 4)
    dir = 0  sx = 0.0  sy = 0.0

    if edge = 1
        // Top edge, going south
        dir = DIR_SOUTH
        col = GetRandomValue(0, gridCols - 1)
        ix = intersections[ts_intIdx(0, col)]
        sx = ix[1] + HALF_ROAD / 2.0
        sy = -CAR_W * 1.0
    ok
    if edge = 2
        // Bottom edge, going north
        dir = DIR_NORTH
        col = GetRandomValue(0, gridCols - 1)
        ix = intersections[ts_intIdx(0, col)]
        sx = ix[1] - HALF_ROAD / 2.0
        sy = CANVAS_H + CAR_W * 1.0
    ok
    if edge = 3
        // Left edge, going east
        dir = DIR_EAST
        row = GetRandomValue(0, gridRows - 1)
        ix = intersections[ts_intIdx(row, 0)]
        sx = -CAR_W * 1.0
        sy = ix[2] + HALF_ROAD / 2.0
    ok
    if edge = 4
        // Right edge, going west
        dir = DIR_WEST
        row = GetRandomValue(0, gridRows - 1)
        ix = intersections[ts_intIdx(row, 0)]
        sx = SCREEN_W + CAR_W * 1.0
        sy = ix[2] - HALF_ROAD / 2.0
    ok

    speed = GetRandomValue(60, 110) * 1.0
    colorIdx = GetRandomValue(1, CAR_COLOR_COUNT)

    add(cars, [nextCarId, sx, sy, dir, speed, speed, 0, colorIdx, 1, 0.0])
    nextCarId++
    totalCarsSpawned++

// =============================================================
// Update
// =============================================================

func ts_update
    dt = GetFrameTime()
    if dt > 0.05 dt = 0.05 ok
    animTime += dt

    if IsKeyPressed(KEY_ESCAPE)
        CloseWindow()
        shutdown(0)
    ok

    if IsKeyPressed(KEY_SPACE) or IsKeyPressed(KEY_P)
        paused = !paused
    ok

    if IsKeyPressed(KEY_EQUAL) or IsKeyPressed(KEY_KP_ADD)
        simSpeed *= 1.5
        if simSpeed > 5.0 simSpeed = 5.0 ok
    ok
    if IsKeyPressed(KEY_MINUS) or IsKeyPressed(KEY_KP_SUBTRACT)
        simSpeed /= 1.5
        if simSpeed < 0.25 simSpeed = 0.25 ok
    ok

    if IsKeyPressed(KEY_C)
        ts_spawnCar()
    ok

    if IsKeyPressed(KEY_L)
        currentTiming++
        if currentTiming > TIMING_COUNT currentTiming = 1 ok
    ok

    if IsKeyPressed(KEY_T)
        if gridMode = 2 gridMode = 3 else gridMode = 2 ok
        ts_buildGrid()
    ok

    if IsKeyPressed(KEY_R)
        ts_buildGrid()
    ok

    if IsKeyPressed(KEY_D)
        debugView = !debugView
    ok

    if IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
        ts_handleToolbar(GetMouseX(), GetMouseY())
    ok

    if paused return ok

    sDt = dt * simSpeed

    // Update traffic lights
    ts_updateLights(sDt)

    // Spawn cars
    spawnTimer += sDt
    if spawnTimer >= SPAWN_INTERVAL
        spawnTimer -= SPAWN_INTERVAL
        ts_spawnCar()
    ok

    // Update cars
    ts_updateCars(sDt)

    // Remove dead cars
    i = len(cars)
    while i >= 1
        if cars[i][9] = 0
            del(cars, i)
            totalCarsExited++
        ok
        i--
    end

// =============================================================
// Update Traffic Lights
// =============================================================

func ts_updateLights dt
    greenTime = timingGreen[currentTiming]
    yellowTime = timingYellow[currentTiming]
    cycleTime = greenTime + yellowTime

    for i = 1 to len(intersections)
        intersections[i][5] += dt

        timer = intersections[i][5]
        phase = intersections[i][6]

        if phase = 1
            // NS green phase
            if timer < greenTime
                intersections[i][3] = LIGHT_GREEN
                intersections[i][4] = LIGHT_RED
            but timer < greenTime + yellowTime
                intersections[i][3] = LIGHT_YELLOW
                intersections[i][4] = LIGHT_RED
            else
                // Switch to phase 2
                intersections[i][6] = 2
                intersections[i][5] = 0.0
            ok
        else
            // EW green phase
            if timer < greenTime
                intersections[i][3] = LIGHT_RED
                intersections[i][4] = LIGHT_GREEN
            but timer < greenTime + yellowTime
                intersections[i][3] = LIGHT_RED
                intersections[i][4] = LIGHT_YELLOW
            else
                intersections[i][6] = 1
                intersections[i][5] = 0.0
            ok
        ok
    next

// =============================================================
// Update Cars
// =============================================================

func ts_updateCars dt
    for i = 1 to len(cars)
        if cars[i][9] = 0 loop ok

        cx = cars[i][2]
        cy = cars[i][3]
        dir = cars[i][4]
        speed = cars[i][5]
        targetSpd = cars[i][6]

        // Check if should stop for red light
        shouldStop = ts_checkRedLight(cx, cy, dir)

        // Check car ahead
        carAhead = ts_checkCarAhead(i, cx, cy, dir)

        if shouldStop or carAhead
            // Decelerate
            speed -= 200 * dt
            if speed < 0 speed = 0 ok
            cars[i][10] += dt
        else
            // Accelerate toward target
            if speed < targetSpd
                speed += 120 * dt
                if speed > targetSpd speed = targetSpd ok
            ok
        ok

        cars[i][5] = speed

        // Move
        if dir = DIR_NORTH
            cars[i][3] -= speed * dt
        ok
        if dir = DIR_SOUTH
            cars[i][3] += speed * dt
        ok
        if dir = DIR_EAST
            cars[i][2] += speed * dt
        ok
        if dir = DIR_WEST
            cars[i][2] -= speed * dt
        ok

        // Check if exited screen
        if cars[i][2] < -50 or cars[i][2] > SCREEN_W + 50
            cars[i][9] = 0
        ok
        if cars[i][3] < -50 or cars[i][3] > CANVAS_H + 50
            cars[i][9] = 0
        ok
    next

// =============================================================
// Check Red Light
// =============================================================

func ts_checkRedLight cx, cy, dir
    stopDist = 35
    for i = 1 to len(intersections)
        ix = intersections[i][1]
        iy = intersections[i][2]

        if dir = DIR_SOUTH
            light = intersections[i][3]  // NS light
            if light != LIGHT_GREEN
                // Stop line is above intersection
                stopY = iy - HALF_ROAD - 2
                if cy > stopY - stopDist and cy < stopY and fabs(cx - ix - HALF_ROAD/2) < LANE_W
                    return true
                ok
            ok
        ok
        if dir = DIR_NORTH
            light = intersections[i][3]
            if light != LIGHT_GREEN
                stopY = iy + HALF_ROAD + 2
                if cy < stopY + stopDist and cy > stopY and fabs(cx - ix + HALF_ROAD/2) < LANE_W
                    return true
                ok
            ok
        ok
        if dir = DIR_EAST
            light = intersections[i][4]  // EW light
            if light != LIGHT_GREEN
                stopX = ix - HALF_ROAD - 2
                if cx > stopX - stopDist and cx < stopX and fabs(cy - iy - HALF_ROAD/2) < LANE_W
                    return true
                ok
            ok
        ok
        if dir = DIR_WEST
            light = intersections[i][4]
            if light != LIGHT_GREEN
                stopX = ix + HALF_ROAD + 2
                if cx < stopX + stopDist and cx > stopX and fabs(cy - iy + HALF_ROAD/2) < LANE_W
                    return true
                ok
            ok
        ok
    next
    return false

// =============================================================
// Check Car Ahead
// =============================================================

func ts_checkCarAhead carIdx, cx, cy, dir
    followDist = 30

    for j = 1 to len(cars)
        if j = carIdx loop ok
        if cars[j][9] = 0 loop ok
        if cars[j][4] != dir loop ok

        ox = cars[j][2]
        oy = cars[j][3]

        if dir = DIR_SOUTH
            if fabs(ox - cx) < LANE_W and oy > cy and oy - cy < followDist
                return true
            ok
        ok
        if dir = DIR_NORTH
            if fabs(ox - cx) < LANE_W and oy < cy and cy - oy < followDist
                return true
            ok
        ok
        if dir = DIR_EAST
            if fabs(oy - cy) < LANE_W and ox > cx and ox - cx < followDist
                return true
            ok
        ok
        if dir = DIR_WEST
            if fabs(oy - cy) < LANE_W and ox < cx and cx - ox < followDist
                return true
            ok
        ok
    next
    return false

// =============================================================
// Draw
// =============================================================

func ts_draw
    // Grass background
    // Already cleared to green-ish

    // Draw roads first
    ts_drawRoads()

    // Traffic lights
    ts_drawLights()

    // Cars
    ts_drawCars()

    // HUD
    ts_drawHUD()

    // Toolbar
    ts_drawToolbar()

// =============================================================
// Draw Roads
// =============================================================

func ts_drawRoads
    roadCol = RAYLIBColor(55, 55, 65, 255)
    lineCol = RAYLIBColor(220, 220, 100, 100)
    edgeCol = RAYLIBColor(180, 180, 180, 80)

    // Vertical roads (through all rows for each column)
    for col = 0 to gridCols - 1
        ix = intersections[ts_intIdx(0, col)]
        rx = ix[1] - HALF_ROAD
        DrawRectangle(rx, 0, ROAD_W, CANVAS_H, roadCol)
        // Center dashed line
        cx = ix[1]
        for dy = 0 to CANVAS_H step 20
            DrawRectangle(cx - 1, dy, 2, 10, lineCol)
        next
        // Edge lines
        DrawLine(rx, 0, rx, CANVAS_H, edgeCol)
        DrawLine(rx + ROAD_W, 0, rx + ROAD_W, CANVAS_H, edgeCol)
    next

    // Horizontal roads (through all cols for each row)
    for row = 0 to gridRows - 1
        ix = intersections[ts_intIdx(row, 0)]
        ry = ix[2] - HALF_ROAD
        DrawRectangle(0, ry, SCREEN_W, ROAD_W, roadCol)
        // Center dashed line
        cy = ix[2]
        for dx = 0 to SCREEN_W step 20
            DrawRectangle(dx, cy - 1, 10, 2, lineCol)
        next
        // Edge lines
        DrawLine(0, ry, SCREEN_W, ry, edgeCol)
        DrawLine(0, ry + ROAD_W, SCREEN_W, ry + ROAD_W, edgeCol)
    next

    // Intersection fills (cover crosshatch)
    for i = 1 to len(intersections)
        ix = intersections[i][1]
        iy = intersections[i][2]
        DrawRectangle(ix - HALF_ROAD, iy - HALF_ROAD, ROAD_W, ROAD_W, roadCol)

        // Crosswalk marks
        for m = 0 to 3
            offset = -HALF_ROAD + 4 + m * 12
            // North crosswalk
            DrawRectangle(ix + offset, iy - HALF_ROAD - 4, 8, 3, RAYLIBColor(200, 200, 200, 60))
            // South crosswalk
            DrawRectangle(ix + offset, iy + HALF_ROAD + 1, 8, 3, RAYLIBColor(200, 200, 200, 60))
            // West crosswalk
            DrawRectangle(ix - HALF_ROAD - 4, iy + offset, 3, 8, RAYLIBColor(200, 200, 200, 60))
            // East crosswalk
            DrawRectangle(ix + HALF_ROAD + 1, iy + offset, 3, 8, RAYLIBColor(200, 200, 200, 60))
        next
    next

// =============================================================
// Draw Traffic Lights
// =============================================================

func ts_drawLights
    for i = 1 to len(intersections)
        ix = intersections[i][1]
        iy = intersections[i][2]
        lightNS = intersections[i][3]
        lightEW = intersections[i][4]

        // NS lights (at top and bottom of intersection)
        ts_drawLightBox(ix + HALF_ROAD + 4, iy - HALF_ROAD - 14, lightNS, false)
        ts_drawLightBox(ix - HALF_ROAD - 16, iy + HALF_ROAD + 2, lightNS, false)

        // EW lights (at left and right)
        ts_drawLightBox(ix - HALF_ROAD - 14, iy - HALF_ROAD - 16, lightEW, true)
        ts_drawLightBox(ix + HALF_ROAD + 2, iy + HALF_ROAD + 4, lightEW, true)
    next

func ts_drawLightBox lx, ly, state, horizontal
    // Light housing
    if horizontal
        DrawRectangle(lx, ly, 30, 12, RAYLIBColor(30, 30, 35, 240))
        // Three circles
        rCol = RAYLIBColor(80, 20, 20, 255)
        yCol = RAYLIBColor(80, 70, 20, 255)
        gCol = RAYLIBColor(20, 60, 20, 255)
        if state = LIGHT_RED    rCol = RAYLIBColor(255, 40, 40, 255) ok
        if state = LIGHT_YELLOW yCol = RAYLIBColor(255, 220, 40, 255) ok
        if state = LIGHT_GREEN  gCol = RAYLIBColor(40, 255, 60, 255) ok
        DrawCircle(lx + 5, ly + 6, 4, rCol)
        DrawCircle(lx + 15, ly + 6, 4, yCol)
        DrawCircle(lx + 25, ly + 6, 4, gCol)
        // Glow
        if state = LIGHT_RED    DrawCircle(lx+5, ly+6, 7, RAYLIBColor(255,40,40,30)) ok
        if state = LIGHT_YELLOW DrawCircle(lx+15, ly+6, 7, RAYLIBColor(255,220,40,30)) ok
        if state = LIGHT_GREEN  DrawCircle(lx+25, ly+6, 7, RAYLIBColor(40,255,60,30)) ok
    else
        DrawRectangle(lx, ly, 12, 30, RAYLIBColor(30, 30, 35, 240))
        rCol = RAYLIBColor(80, 20, 20, 255)
        yCol = RAYLIBColor(80, 70, 20, 255)
        gCol = RAYLIBColor(20, 60, 20, 255)
        if state = LIGHT_RED    rCol = RAYLIBColor(255, 40, 40, 255) ok
        if state = LIGHT_YELLOW yCol = RAYLIBColor(255, 220, 40, 255) ok
        if state = LIGHT_GREEN  gCol = RAYLIBColor(40, 255, 60, 255) ok
        DrawCircle(lx + 6, ly + 5, 4, rCol)
        DrawCircle(lx + 6, ly + 15, 4, yCol)
        DrawCircle(lx + 6, ly + 25, 4, gCol)
        if state = LIGHT_RED    DrawCircle(lx+6, ly+5, 7, RAYLIBColor(255,40,40,30)) ok
        if state = LIGHT_YELLOW DrawCircle(lx+6, ly+15, 7, RAYLIBColor(255,220,40,30)) ok
        if state = LIGHT_GREEN  DrawCircle(lx+6, ly+25, 7, RAYLIBColor(40,255,60,30)) ok
    ok

// =============================================================
// Draw Cars
// =============================================================

func ts_drawCars
    for i = 1 to len(cars)
        if cars[i][9] = 0 loop ok

        cx = cars[i][2]
        cy = cars[i][3]
        dir = cars[i][4]
        speed = cars[i][5]
        ci = cars[i][8]
        cc = carColors[ci]

        // Car body (oriented by direction)
        if dir = DIR_NORTH or dir = DIR_SOUTH
            // Vertical car
            hw = CAR_H / 2   hh = CAR_W / 2
            // Shadow
            DrawRectangle(floor(cx - hw) + 2, floor(cy - hh) + 2, CAR_H, CAR_W, RAYLIBColor(0, 0, 0, 40))
            // Body
            DrawRectangle(floor(cx - hw), floor(cy - hh), CAR_H, CAR_W, RAYLIBColor(cc[1], cc[2], cc[3], 240))
            // Windshield
            if dir = DIR_SOUTH
                DrawRectangle(floor(cx - hw) + 2, floor(cy - hh) + CAR_W - 5, CAR_H - 4, 4, RAYLIBColor(150, 200, 240, 150))
            else
                DrawRectangle(floor(cx - hw) + 2, floor(cy - hh) + 1, CAR_H - 4, 4, RAYLIBColor(150, 200, 240, 150))
            ok
            // Headlights
            if dir = DIR_SOUTH
                DrawRectangle(floor(cx - hw), floor(cy + hh) - 2, 3, 2, RAYLIBColor(255, 255, 200, 200))
                DrawRectangle(floor(cx + hw) - 3, floor(cy + hh) - 2, 3, 2, RAYLIBColor(255, 255, 200, 200))
            else
                DrawRectangle(floor(cx - hw), floor(cy - hh), 3, 2, RAYLIBColor(255, 255, 200, 200))
                DrawRectangle(floor(cx + hw) - 3, floor(cy - hh), 3, 2, RAYLIBColor(255, 255, 200, 200))
            ok
            // Brake lights when stopped
            if speed < 5
                if dir = DIR_SOUTH
                    DrawRectangle(floor(cx-hw), floor(cy-hh), 3, 2, RAYLIBColor(255, 30, 30, 220))
                    DrawRectangle(floor(cx+hw)-3, floor(cy-hh), 3, 2, RAYLIBColor(255, 30, 30, 220))
                else
                    DrawRectangle(floor(cx-hw), floor(cy+hh)-2, 3, 2, RAYLIBColor(255, 30, 30, 220))
                    DrawRectangle(floor(cx+hw)-3, floor(cy+hh)-2, 3, 2, RAYLIBColor(255, 30, 30, 220))
                ok
            ok
        else
            // Horizontal car
            hw = CAR_W / 2   hh = CAR_H / 2
            DrawRectangle(floor(cx - hw) + 2, floor(cy - hh) + 2, CAR_W, CAR_H, RAYLIBColor(0, 0, 0, 40))
            DrawRectangle(floor(cx - hw), floor(cy - hh), CAR_W, CAR_H, RAYLIBColor(cc[1], cc[2], cc[3], 240))
            // Windshield
            if dir = DIR_EAST
                DrawRectangle(floor(cx + hw) - 5, floor(cy - hh) + 2, 4, CAR_H - 4, RAYLIBColor(150, 200, 240, 150))
            else
                DrawRectangle(floor(cx - hw) + 1, floor(cy - hh) + 2, 4, CAR_H - 4, RAYLIBColor(150, 200, 240, 150))
            ok
            // Headlights
            if dir = DIR_EAST
                DrawRectangle(floor(cx + hw) - 2, floor(cy - hh), 2, 3, RAYLIBColor(255, 255, 200, 200))
                DrawRectangle(floor(cx + hw) - 2, floor(cy + hh) - 3, 2, 3, RAYLIBColor(255, 255, 200, 200))
            else
                DrawRectangle(floor(cx - hw), floor(cy - hh), 2, 3, RAYLIBColor(255, 255, 200, 200))
                DrawRectangle(floor(cx - hw), floor(cy + hh) - 3, 2, 3, RAYLIBColor(255, 255, 200, 200))
            ok
            if speed < 5
                if dir = DIR_EAST
                    DrawRectangle(floor(cx-hw), floor(cy-hh), 2, 3, RAYLIBColor(255, 30, 30, 220))
                    DrawRectangle(floor(cx-hw), floor(cy+hh)-3, 2, 3, RAYLIBColor(255, 30, 30, 220))
                else
                    DrawRectangle(floor(cx+hw)-2, floor(cy-hh), 2, 3, RAYLIBColor(255, 30, 30, 220))
                    DrawRectangle(floor(cx+hw)-2, floor(cy+hh)-3, 2, 3, RAYLIBColor(255, 30, 30, 220))
                ok
            ok
        ok

        // Debug
        if debugView
            idTxt = string(cars[i][1])
            DrawText(idTxt, floor(cx) - 4, floor(cy) - 16, 10, RAYLIBColor(255, 255, 255, 160))
            spdTxt = string(floor(speed))
            DrawText(spdTxt, floor(cx) - 6, floor(cy) + 10, 9, RAYLIBColor(200, 255, 200, 140))
        ok
    next

// =============================================================
// HUD
// =============================================================

func ts_drawHUD
    DrawRectangle(0, 0, SCREEN_W, 26, RAYLIBColor(0, 0, 0, 160))
    DrawText("Traffic Simulator", 10, 4, 16, RAYLIBColor(255, 215, 0, 220))

    carTxt = "Cars: " + string(len(cars))
    DrawText(carTxt, 180, 6, 13, RAYLIBColor(100, 200, 255, 200))

    spawnTxt = "Spawned: " + string(totalCarsSpawned) + "  Exited: " + string(totalCarsExited)
    DrawText(spawnTxt, 270, 6, 13, RAYLIBColor(180, 200, 220, 180))

    spdTxt = "Speed: " + string(floor(simSpeed * 100)) + "%"
    DrawText(spdTxt, 500, 6, 13, RAYLIBColor(200, 200, 180, 180))

    gridTxt = "Grid: " + string(gridCols) + "x" + string(gridRows)
    DrawText(gridTxt, 610, 6, 13, RAYLIBColor(180, 220, 180, 180))

    timTxt = "Timing: " + timingNames[currentTiming]
    DrawText(timTxt, 700, 6, 13, RAYLIBColor(200, 200, 150, 180))

    if paused
        DrawText("PAUSED", 830, 6, 14, RAYLIBColor(255, 100, 100, 240))
    ok

    if debugView
        DrawText("DEBUG", 910, 6, 13, RAYLIBColor(255, 200, 50, 200))
    ok

    fpsTxt = "" + string(GetFPS()) + " FPS"
    DrawText(fpsTxt, SCREEN_W - 60, SCREEN_H - 14, 12, RAYLIBColor(100, 200, 100, 120))

// =============================================================
// Toolbar
// =============================================================

func ts_drawToolbar
    DrawRectangle(0, SCREEN_H - TOOLBAR_H, SCREEN_W, TOOLBAR_H, RAYLIBColor(25, 28, 35, 255))
    DrawRectangle(0, SCREEN_H - TOOLBAR_H, SCREEN_W, 2, RAYLIBColor(60, 60, 100, 200))

    mx = GetMouseX()  my = GetMouseY()
    hoverBtn = 0

    bx = BTN_GAP

    // Pause/Resume
    if paused
        bx = ts_drawBtn("Resume[P]", bx, 1, RAYLIBColor(40, 120, 60, 255), mx, my)
    else
        bx = ts_drawBtn("Pause[P]", bx, 1, RAYLIBColor(150, 110, 30, 255), mx, my)
    ok
    bx += BTN_GAP

    // Speed
    bx = ts_drawBtn("Slow[-]", bx, 2, RAYLIBColor(120, 60, 60, 255), mx, my)
    bx += BTN_GAP
    bx = ts_drawBtn("Fast[+]", bx, 3, RAYLIBColor(60, 120, 60, 255), mx, my)
    bx += BTN_GAP

    // Spawn
    bx = ts_drawBtn("AddCar[C]", bx, 4, RAYLIBColor(60, 80, 140, 255), mx, my)
    bx += BTN_GAP

    // Light timing
    bx = ts_drawBtn("Timing[L]", bx, 5, RAYLIBColor(140, 100, 40, 255), mx, my)
    bx += BTN_GAP

    // Grid toggle
    bx = ts_drawBtn("Grid[T]", bx, 6, RAYLIBColor(80, 80, 120, 255), mx, my)
    bx += BTN_GAP

    // Reset
    bx = ts_drawBtn("Reset[R]", bx, 7, RAYLIBColor(140, 50, 50, 255), mx, my)
    bx += BTN_GAP

    // Debug
    dcol = RAYLIBColor(60, 60, 60, 255)
    if debugView dcol = RAYLIBColor(140, 120, 40, 255) ok
    bx = ts_drawBtn("Debug[D]", bx, 8, dcol, mx, my)

func ts_drawBtn label, bx, btnId, baseCol, mx, my
    tw = MeasureText(label, 12) + 14
    if tw < 40 tw = 40 ok

    isHover = (mx >= bx and mx <= bx + tw and my >= BTN_Y and my <= BTN_Y + BTN_H)

    if isHover
        hoverBtn = btnId
        DrawRectangle(bx, BTN_Y, tw, BTN_H, RAYLIBColor(255, 225, 100, 240))
        DrawRectangleLines(bx, BTN_Y, tw, BTN_H, RAYLIBColor(200, 180, 60, 255))
        lw = MeasureText(label, 12)
        DrawText(label, bx + (tw-lw)/2, BTN_Y+12, 12, RAYLIBColor(20, 15, 10, 255))
    else
        DrawRectangle(bx, BTN_Y, tw, BTN_H, baseCol)
        DrawRectangleLines(bx, BTN_Y, tw, BTN_H, RAYLIBColor(255, 255, 255, 30))
        lw = MeasureText(label, 12)
        DrawText(label, bx + (tw-lw)/2, BTN_Y+12, 12, WHITE)
    ok

    return bx + tw

// =============================================================
// Toolbar Click
// =============================================================

func ts_handleToolbar mx, my
    if hoverBtn = 1 paused = !paused  return ok
    if hoverBtn = 2
        simSpeed /= 1.5
        if simSpeed < 0.25 simSpeed = 0.25 ok
        return
    ok
    if hoverBtn = 3
        simSpeed *= 1.5
        if simSpeed > 5.0 simSpeed = 5.0 ok
        return
    ok
    if hoverBtn = 4 ts_spawnCar() return ok
    if hoverBtn = 5
        currentTiming++
        if currentTiming > TIMING_COUNT currentTiming = 1 ok
        return
    ok
    if hoverBtn = 6
        if gridMode = 2 gridMode = 3 else gridMode = 2 ok
        ts_buildGrid()
        return
    ok
    if hoverBtn = 7 ts_buildGrid() return ok
    if hoverBtn = 8 debugView = !debugView return ok
