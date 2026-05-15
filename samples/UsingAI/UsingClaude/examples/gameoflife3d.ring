/*
**  3D Game of Life - RingRayLib
**  ===============================
**  Conway's Game of Life visualized in 3D!
**  Live cells rise as glowing cubes on a dark grid plane.
**
**  Controls:
**    Mouse Left      - Toggle cell (via ray picking)
**    V               - Cycle camera view (Front / Overhead / Orbit)
**    Space / P       - Pause / Resume simulation
**    S               - Step one generation (while paused)
**    C               - Clear all cells
**    R               - Randomize grid
**    N               - Next pattern preset
**    +/-             - Speed up / Slow down
**    ESC             - Exit
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W = 1024
SCREEN_H = 700

GRID_W = 60
GRID_H = 60

TOOLBAR_H = 55

DEAD  = 0
ALIVE = 1

SPEED_MIN = 1
SPEED_MAX = 60
SPEED_DEFAULT = 10

// 3D cell dimensions
CELL3D_SIZE  = 0.9
CELL3D_GAP   = 1.0
CELL3D_HEIGHT = 0.6

// Camera modes
CAM_FRONT    = 1
CAM_OVERHEAD = 2
CAM_ORBIT    = 3
CAM_COUNT    = 3
camModeNames = ["Front", "Overhead", "Orbit"]

// =============================================================
// State
// =============================================================

grid = list(GRID_H)
for r = 1 to GRID_H
    grid[r] = list(GRID_W)
    for c = 1 to GRID_W
        grid[r][c] = DEAD
    next
next

gridNext = list(GRID_H)
for r = 1 to GRID_H
    gridNext[r] = list(GRID_W)
    for c = 1 to GRID_W
        gridNext[r][c] = DEAD
    next
next

// Age tracking for visual effects (how many gens a cell has been alive)
cellAge = list(GRID_H)
for r = 1 to GRID_H
    cellAge[r] = list(GRID_W)
    for c = 1 to GRID_W
        cellAge[r][c] = 0
    next
next

// Simulation
paused = true
generation = 0
population = 0
speed = SPEED_DEFAULT
simTimer = 0.0
animTime = 0.0

// Camera
cameraMode = CAM_FRONT
camPosX = 0.0   camPosY = 45.0  camPosZ = 40.0
camTgtX = 0.0   camTgtY = 0.0   camTgtZ = 0.0
camOrbitAngle = 0.0

// Grid center offset (to center grid at origin)
gridOffX = -(GRID_W * CELL3D_GAP) / 2.0
gridOffZ = -(GRID_H * CELL3D_GAP) / 2.0

// Toolbar
hoverBtn = 0
BTN_Y = SCREEN_H - 52
BTN_H = 38
BTN_GAP = 6

// Particles (for cell death effects)
particles = []

// Patterns
patternIdx = 0
patternNames = ["Glider", "LWSS", "Pulsar", "Gosper Gun", "Pentadecathlon", "Acorn", "R-pentomino", "Diehard"]
PATTERN_COUNT = 8

// =============================================================
// Main
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "3D Game of Life - RingRayLib")
SetTargetFPS(60)
SetExitKey(0)

camera = Camera3D(
    0, 45, 40,
    0, 0, 0,
    0, 1, 0,
    45,
    CAMERA_PERSPECTIVE
)

// Start with Gosper Gun
gol3_placePattern(4)
patternIdx = 4

while !WindowShouldClose()
    gol3_update()
    BeginDrawing()
        ClearBackground(RAYLIBColor(10, 12, 20, 255))
        BeginMode3D(camera)
            gol3_draw3D()
        EndMode3D()
        gol3_drawHUD()
        gol3_drawToolbar()
    EndDrawing()
end

CloseWindow()

// =============================================================
// Update
// =============================================================

func gol3_update
    dt = GetFrameTime()
    animTime += dt

    if IsKeyPressed(KEY_ESCAPE)
        CloseWindow()
        shutdown(0)
    ok

    if IsKeyPressed(KEY_SPACE) or IsKeyPressed(KEY_P)
        paused = !paused
    ok

    if IsKeyPressed(KEY_S)
        if paused gol3_step() ok
    ok

    if IsKeyPressed(KEY_C)
        gol3_clearGrid()
        generation = 0
        population = 0
        paused = true
    ok

    if IsKeyPressed(KEY_R)
        gol3_randomize()
        generation = 0
        paused = true
    ok

    if IsKeyPressed(KEY_N)
        patternIdx++
        if patternIdx > PATTERN_COUNT patternIdx = 1 ok
        gol3_clearGrid()
        gol3_placePattern(patternIdx)
        generation = 0
        paused = true
    ok

    if IsKeyPressed(KEY_V)
        cameraMode++
        if cameraMode > CAM_COUNT cameraMode = CAM_FRONT ok
    ok

    if IsKeyPressed(KEY_EQUAL) or IsKeyPressed(KEY_KP_ADD)
        speed += 2
        if speed > SPEED_MAX speed = SPEED_MAX ok
    ok
    if IsKeyPressed(KEY_MINUS) or IsKeyPressed(KEY_KP_SUBTRACT)
        speed -= 2
        if speed < SPEED_MIN speed = SPEED_MIN ok
    ok

    // Mouse click - toolbar first, then ray pick
    if IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
        mx = GetMouseX()
        my = GetMouseY()
        gol3_handleClick(mx, my)
        if hoverBtn = 0
            if my < SCREEN_H - TOOLBAR_H
                gol3_pickCell()
            ok
        ok
    ok

    // Camera
    gol3_updateCamera(dt)

    // Simulation
    if !paused
        simTimer += dt
        interval = 1.0 / speed
        if simTimer >= interval
            simTimer -= interval
            gol3_step()
        ok
    ok

    // Particles
    gol3_updateParticles(dt)

    // Count population
    gol3_countPopulation()

// =============================================================
// Camera
// =============================================================

func gol3_updateCamera dt
    goalX = 0.0  goalY = 0.0  goalZ = 0.0
    tgtX = 0.0   tgtY = 0.0   tgtZ = 0.0

    halfGrid = GRID_W * CELL3D_GAP / 2.0

    if cameraMode = CAM_FRONT
        goalX = 0.0    goalY = halfGrid * 1.3   goalZ = halfGrid * 1.2
        tgtX = 0.0     tgtY = 0.0               tgtZ = -2.0
    ok
    if cameraMode = CAM_OVERHEAD
        goalX = 0.0    goalY = halfGrid * 2.2   goalZ = 2.0
        tgtX = 0.0     tgtY = 0.0               tgtZ = 0.0
    ok
    if cameraMode = CAM_ORBIT
        if !paused
            camOrbitAngle += dt * 0.3
        else
            camOrbitAngle += dt * 0.15
        ok
        dist = halfGrid * 1.6
        goalX = cos(camOrbitAngle) * dist
        goalY = halfGrid * 1.0
        goalZ = sin(camOrbitAngle) * dist
        tgtX = 0.0  tgtY = 0.0  tgtZ = 0.0
    ok

    lerpSpd = 0.04
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
// Ray Pick Cell (click to toggle)
// =============================================================

func gol3_pickCell
    // Project mouse click to Y=0 ground plane using camera math
    mx = GetMouseX()
    my = GetMouseY()

    // Build camera vectors
    fwdX = camTgtX - camPosX
    fwdY = camTgtY - camPosY
    fwdZ = camTgtZ - camPosZ
    fLen = sqrt(fwdX*fwdX + fwdY*fwdY + fwdZ*fwdZ)
    if fLen < 0.0001 return ok
    fwdX /= fLen   fwdY /= fLen   fwdZ /= fLen

    // Right vector = forward x up(0,1,0)
    rX = fwdY * 0 - fwdZ * 1
    rY = fwdZ * 0 - fwdX * 0
    rZ = fwdX * 1 - fwdY * 0
    rLen = sqrt(rX*rX + rY*rY + rZ*rZ)
    if rLen < 0.0001 return ok
    rX /= rLen   rY /= rLen   rZ /= rLen

    // True up vector = right x forward
    uX = rY * fwdZ - rZ * fwdY
    uY = rZ * fwdX - rX * fwdZ
    uZ = rX * fwdY - rY * fwdX

    // NDC coordinates from screen
    ndcX = (mx / (SCREEN_W / 2.0)) - 1.0
    ndcY = 1.0 - (my / (SCREEN_H / 2.0))

    // Unproject using FOV
    fov = 45.0
    aspect = SCREEN_W * 1.0 / SCREEN_H
    tanHalf = tan((fov / 2.0) * 3.14159 / 180.0)

    // Ray direction in world space
    rdX = fwdX + rX * ndcX * tanHalf * aspect + uX * ndcY * tanHalf
    rdY = fwdY + rY * ndcX * tanHalf * aspect + uY * ndcY * tanHalf
    rdZ = fwdZ + rZ * ndcX * tanHalf * aspect + uZ * ndcY * tanHalf

    // Intersect with Y=0 plane: camPosY + t * rdY = 0
    if fabs(rdY) < 0.0001 return ok
    t = -camPosY / rdY
    if t < 0 return ok

    hitX = camPosX + rdX * t
    hitZ = camPosZ + rdZ * t

    // Convert world to grid
    gc = floor((hitX - gridOffX) / CELL3D_GAP) + 1
    gr = floor((hitZ - gridOffZ) / CELL3D_GAP) + 1

    if gr >= 1 and gr <= GRID_H and gc >= 1 and gc <= GRID_W
        if grid[gr][gc] = ALIVE
            grid[gr][gc] = DEAD
            cellAge[gr][gc] = 0
        else
            grid[gr][gc] = ALIVE
            cellAge[gr][gc] = 1
        ok
    ok

// =============================================================
// Simulation
// =============================================================

func gol3_step
    for r = 1 to GRID_H
        for c = 1 to GRID_W
            n = gol3_countNeighbors(r, c)
            if grid[r][c] = ALIVE
                if n = 2 or n = 3
                    gridNext[r][c] = ALIVE
                else
                    gridNext[r][c] = DEAD
                ok
            else
                if n = 3
                    gridNext[r][c] = ALIVE
                else
                    gridNext[r][c] = DEAD
                ok
            ok
        next
    next

    // Swap, update ages, spawn death particles
    for r = 1 to GRID_H
        for c = 1 to GRID_W
            oldVal = grid[r][c]
            newVal = gridNext[r][c]

            if oldVal = ALIVE and newVal = DEAD
                // Cell died - spawn particles
                wx = gridOffX + (c - 1) * CELL3D_GAP + CELL3D_GAP / 2.0
                wz = gridOffZ + (r - 1) * CELL3D_GAP + CELL3D_GAP / 2.0
                gol3_spawnParticles(wx, CELL3D_HEIGHT, wz, 3)
                cellAge[r][c] = 0
            ok
            if newVal = ALIVE
                cellAge[r][c] += 1
            else
                cellAge[r][c] = 0
            ok

            grid[r][c] = newVal
        next
    next

    generation++

func gol3_countNeighbors r, c
    count = 0
    for dr = -1 to 1
        for dc = -1 to 1
            if dr = 0 and dc = 0 loop ok
            nr = r + dr
            nc = c + dc
            if nr < 1 nr = GRID_H ok
            if nr > GRID_H nr = 1 ok
            if nc < 1 nc = GRID_W ok
            if nc > GRID_W nc = 1 ok
            if grid[nr][nc] = ALIVE count++ ok
        next
    next
    return count

func gol3_countPopulation
    population = 0
    for r = 1 to GRID_H
        for c = 1 to GRID_W
            if grid[r][c] = ALIVE population++ ok
        next
    next

// =============================================================
// Clear / Randomize
// =============================================================

func gol3_clearGrid
    for r = 1 to GRID_H
        for c = 1 to GRID_W
            grid[r][c] = DEAD
            cellAge[r][c] = 0
        next
    next

func gol3_randomize
    for r = 1 to GRID_H
        for c = 1 to GRID_W
            if GetRandomValue(1, 100) <= 20
                grid[r][c] = ALIVE
                cellAge[r][c] = 1
            else
                grid[r][c] = DEAD
                cellAge[r][c] = 0
            ok
        next
    next

// =============================================================
// Particles
// =============================================================

func gol3_spawnParticles cx, cy, cz, count
    for i = 1 to count
        pvx = (GetRandomValue(-100, 100) / 100.0) * 1.5
        pvy = (GetRandomValue(100, 300) / 100.0)
        pvz = (GetRandomValue(-100, 100) / 100.0) * 1.5
        cr = GetRandomValue(60, 150)
        cg = GetRandomValue(180, 255)
        cb = GetRandomValue(80, 160)
        add(particles, [cx, cy, cz, pvx, pvy, pvz, 0.8, cr, cg, cb])
    next

func gol3_updateParticles dt
    i = 1
    while i <= len(particles)
        p = particles[i]
        p[1] += p[4] * dt
        p[2] += p[5] * dt
        p[3] += p[6] * dt
        p[5] -= 6.0 * dt
        p[7] -= dt
        if p[7] <= 0
            del(particles, i)
        else
            particles[i] = p
            i++
        ok
    end

// =============================================================
// Draw 3D
// =============================================================

func gol3_draw3D
    halfW = GRID_W * CELL3D_GAP / 2.0
    halfH = GRID_H * CELL3D_GAP / 2.0

    // Ground plane
    DrawPlane(Vector3(0, -0.05, 0), Vector2(halfW * 2 + 2, halfH * 2 + 2), RAYLIBColor(15, 18, 30, 255))

    // Grid lines on floor
    gridCol = RAYLIBColor(30, 35, 55, 255)
    for c = 0 to GRID_W
        lx = gridOffX + c * CELL3D_GAP
        DrawLine3D(Vector3(lx, 0.01, gridOffZ), Vector3(lx, 0.01, gridOffZ + GRID_H * CELL3D_GAP), gridCol)
    next
    for r = 0 to GRID_H
        lz = gridOffZ + r * CELL3D_GAP
        DrawLine3D(Vector3(gridOffX, 0.01, lz), Vector3(gridOffX + GRID_W * CELL3D_GAP, 0.01, lz), gridCol)
    next

    // Border frame
    borderCol = RAYLIBColor(50, 60, 90, 200)
    bx1 = gridOffX
    bx2 = gridOffX + GRID_W * CELL3D_GAP
    bz1 = gridOffZ
    bz2 = gridOffZ + GRID_H * CELL3D_GAP
    DrawLine3D(Vector3(bx1, 0.02, bz1), Vector3(bx2, 0.02, bz1), borderCol)
    DrawLine3D(Vector3(bx2, 0.02, bz1), Vector3(bx2, 0.02, bz2), borderCol)
    DrawLine3D(Vector3(bx2, 0.02, bz2), Vector3(bx1, 0.02, bz2), borderCol)
    DrawLine3D(Vector3(bx1, 0.02, bz2), Vector3(bx1, 0.02, bz1), borderCol)

    // Draw alive cells as cubes
    for r = 1 to GRID_H
        for c = 1 to GRID_W
            if grid[r][c] = ALIVE
                wx = gridOffX + (c - 1) * CELL3D_GAP + CELL3D_GAP / 2.0
                wz = gridOffZ + (r - 1) * CELL3D_GAP + CELL3D_GAP / 2.0

                age = cellAge[r][c]
                n = gol3_countNeighbors(r, c)

                // Height grows with age
                h = CELL3D_HEIGHT
                if age < 4
                    h = CELL3D_HEIGHT * age / 4.0
                    if h < 0.1 h = 0.1 ok
                ok
                wy = h / 2.0

                // Color based on neighbors and age
                if n = 2
                    cr = 30   cg = 180  cb = 90
                but n = 3
                    cr = 80   cg = 240  cb = 130
                else
                    cr = 20   cg = 140  cb = 70
                ok

                // Age brightness boost
                if age > 5
                    cr += 30  cg += 30  cb += 30
                    if cr > 255 cr = 255 ok
                    if cg > 255 cg = 255 ok
                    if cb > 255 cb = 255 ok
                ok

                DrawCube(Vector3(wx, wy, wz), CELL3D_SIZE, h, CELL3D_SIZE, RAYLIBColor(cr, cg, cb, 255))
                DrawCubeWires(Vector3(wx, wy, wz), CELL3D_SIZE, h, CELL3D_SIZE, RAYLIBColor(cr + 30, cg + 20, cb + 10, 100))

                // Glow on floor for newborn cells
                if age <= 2
                    glowA = floor((3 - age) * 25)
                    DrawCube(Vector3(wx, 0.02, wz), CELL3D_SIZE + 0.2, 0.01, CELL3D_SIZE + 0.2,
                             RAYLIBColor(100, 255, 150, glowA))
                ok
            ok
        next
    next

    // Particles
    for i = 1 to len(particles)
        p = particles[i]
        alphaP = floor((p[7] / 0.8) * 200)
        if alphaP > 255 alphaP = 255 ok
        if alphaP < 0 alphaP = 0 ok
        sz = 0.05 + p[7] * 0.08
        DrawSphere(Vector3(p[1], p[2], p[3]), sz, RAYLIBColor(p[8], p[9], p[10], alphaP))
    next

// =============================================================
// HUD
// =============================================================

func gol3_drawHUD
    DrawRectangle(0, 0, SCREEN_W, 28, RAYLIBColor(0, 0, 0, 180))

    DrawText("3D Game of Life", 10, 5, 18, RAYLIBColor(255, 215, 0, 220))

    genTxt = "Gen: " + string(generation)
    DrawText(genTxt, 200, 7, 16, RAYLIBColor(180, 220, 255, 220))

    popTxt = "Pop: " + string(population)
    DrawText(popTxt, 320, 7, 16, RAYLIBColor(150, 255, 150, 220))

    spdTxt = "Speed: " + string(speed) + " gen/s"
    DrawText(spdTxt, 440, 7, 16, RAYLIBColor(255, 200, 150, 220))

    grdTxt = "" + string(GRID_W) + "x" + string(GRID_H)
    DrawText(grdTxt, 600, 7, 16, RAYLIBColor(180, 180, 200, 180))

    if paused
        DrawText("PAUSED", 680, 7, 16, RAYLIBColor(255, 100, 100, 240))
    else
        DrawText("RUNNING", 680, 7, 16, RAYLIBColor(100, 255, 100, 240))
    ok

    camTxt = "Cam: " + camModeNames[cameraMode]
    DrawText(camTxt, 780, 7, 14, RAYLIBColor(180, 200, 220, 180))

    if patternIdx >= 1 and patternIdx <= PATTERN_COUNT
        pName = patternNames[patternIdx]
        pw = MeasureText(pName, 14)
        DrawText(pName, SCREEN_W - pw - 10, 8, 14, RAYLIBColor(200, 180, 255, 180))
    ok

    // FPS
    fpsTxt = "" + string(GetFPS()) + " FPS"
    DrawText(fpsTxt, SCREEN_W - 70, SCREEN_H - 15, 14, RAYLIBColor(100, 255, 100, 180))

// =============================================================
// Toolbar
// =============================================================

func gol3_drawToolbar
    DrawRectangle(0, SCREEN_H - TOOLBAR_H, SCREEN_W, TOOLBAR_H, RAYLIBColor(20, 20, 35, 240))
    DrawRectangle(0, SCREEN_H - TOOLBAR_H, SCREEN_W, 2, RAYLIBColor(80, 80, 120, 200))

    mx = GetMouseX()
    my = GetMouseY()
    hoverBtn = 0

    bx = BTN_GAP

    if paused
        bx = gol3_drawBtn("Play [Space]", bx, 1, RAYLIBColor(40, 130, 70, 255), mx, my)
    else
        bx = gol3_drawBtn("Pause [Space]", bx, 1, RAYLIBColor(180, 120, 20, 255), mx, my)
    ok
    bx += BTN_GAP

    bx = gol3_drawBtn("Step [S]", bx, 2, RAYLIBColor(60, 100, 160, 255), mx, my)
    bx += BTN_GAP

    bx = gol3_drawBtn("Clear [C]", bx, 3, RAYLIBColor(170, 40, 40, 255), mx, my)
    bx += BTN_GAP

    bx = gol3_drawBtn("Random [R]", bx, 4, RAYLIBColor(130, 60, 150, 255), mx, my)
    bx += BTN_GAP

    bx = gol3_drawBtn("Pattern [N]", bx, 5, RAYLIBColor(40, 120, 140, 255), mx, my)
    bx += BTN_GAP

    bx = gol3_drawBtn("Camera [V]", bx, 6, RAYLIBColor(80, 80, 150, 255), mx, my)
    bx += BTN_GAP

    DrawRectangle(bx, BTN_Y + 4, 2, BTN_H - 8, RAYLIBColor(80, 80, 120, 150))
    bx += BTN_GAP

    bx = gol3_drawBtn("Slow [-]", bx, 7, RAYLIBColor(140, 70, 70, 255), mx, my)
    bx += BTN_GAP

    bx = gol3_drawBtn("Fast [+]", bx, 8, RAYLIBColor(70, 140, 70, 255), mx, my)

func gol3_drawBtn label, bx, btnId, baseCol, mx, my
    tw = MeasureText(label, 14) + 16
    if tw < 50 tw = 50 ok

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

func gol3_handleClick mx, my
    if hoverBtn = 1
        paused = !paused
        return
    ok
    if hoverBtn = 2
        if paused gol3_step() ok
        return
    ok
    if hoverBtn = 3
        gol3_clearGrid()
        generation = 0
        population = 0
        paused = true
        return
    ok
    if hoverBtn = 4
        gol3_randomize()
        generation = 0
        paused = true
        return
    ok
    if hoverBtn = 5
        patternIdx++
        if patternIdx > PATTERN_COUNT patternIdx = 1 ok
        gol3_clearGrid()
        gol3_placePattern(patternIdx)
        generation = 0
        paused = true
        return
    ok
    if hoverBtn = 6
        cameraMode++
        if cameraMode > CAM_COUNT cameraMode = CAM_FRONT ok
        return
    ok
    if hoverBtn = 7
        speed -= 2
        if speed < SPEED_MIN speed = SPEED_MIN ok
        return
    ok
    if hoverBtn = 8
        speed += 2
        if speed > SPEED_MAX speed = SPEED_MAX ok
        return
    ok

// =============================================================
// Patterns
// =============================================================

func gol3_placePattern idx
    midR = floor(GRID_H / 2)
    midC = floor(GRID_W / 2)

    if idx = 1
        gol3_setCells(midR, midC, [
            [0,1,0],
            [0,0,1],
            [1,1,1]
        ])
    ok
    if idx = 2
        gol3_setCells(midR, midC, [
            [0,1,0,0,1],
            [1,0,0,0,0],
            [1,0,0,0,1],
            [1,1,1,1,0]
        ])
    ok
    if idx = 3
        gol3_setCells(midR - 6, midC - 6, [
            [0,0,1,1,1,0,0,0,1,1,1,0,0],
            [0,0,0,0,0,0,0,0,0,0,0,0,0],
            [1,0,0,0,0,1,0,1,0,0,0,0,1],
            [1,0,0,0,0,1,0,1,0,0,0,0,1],
            [1,0,0,0,0,1,0,1,0,0,0,0,1],
            [0,0,1,1,1,0,0,0,1,1,1,0,0],
            [0,0,0,0,0,0,0,0,0,0,0,0,0],
            [0,0,1,1,1,0,0,0,1,1,1,0,0],
            [1,0,0,0,0,1,0,1,0,0,0,0,1],
            [1,0,0,0,0,1,0,1,0,0,0,0,1],
            [1,0,0,0,0,1,0,1,0,0,0,0,1],
            [0,0,0,0,0,0,0,0,0,0,0,0,0],
            [0,0,1,1,1,0,0,0,1,1,1,0,0]
        ])
    ok
    if idx = 4
        gol3_setCells(midR - 5, midC - 18, [
            [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0],
            [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0],
            [0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1],
            [0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1],
            [1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
            [1,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0],
            [0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0],
            [0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
            [0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
        ])
    ok
    if idx = 5
        gol3_setCells(midR - 1, midC - 4, [
            [0,0,1,0,0,0,0,1,0,0],
            [1,1,0,1,1,1,1,0,1,1],
            [0,0,1,0,0,0,0,1,0,0]
        ])
    ok
    if idx = 6
        gol3_setCells(midR, midC - 3, [
            [0,1,0,0,0,0,0],
            [0,0,0,1,0,0,0],
            [1,1,0,0,1,1,1]
        ])
    ok
    if idx = 7
        gol3_setCells(midR, midC, [
            [0,1,1],
            [1,1,0],
            [0,1,0]
        ])
    ok
    if idx = 8
        gol3_setCells(midR, midC - 3, [
            [0,0,0,0,0,0,1,0],
            [1,1,0,0,0,0,0,0],
            [0,1,0,0,0,1,1,1]
        ])
    ok

func gol3_setCells startR, startC, pattern
    for r = 1 to len(pattern)
        row = pattern[r]
        for c = 1 to len(row)
            gr = startR + r - 1
            gc = startC + c - 1
            if gr >= 1 and gr <= GRID_H and gc >= 1 and gc <= GRID_W
                if row[c] = 1
                    grid[gr][gc] = ALIVE
                    cellAge[gr][gc] = 1
                ok
            ok
        next
    next
