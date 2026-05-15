/*
**  Conway's Game of Life - RingRayLib
**  =====================================
**  Classic cellular automaton simulation.
**
**  Rules:
**    - Any live cell with 2 or 3 neighbors survives
**    - Any dead cell with exactly 3 neighbors becomes alive
**    - All other cells die or stay dead
**
**  Controls:
**    Mouse Left      - Toggle cell alive/dead (while paused or running)
**    Mouse Right     - Pan the grid (drag)
**    Mouse Wheel     - Zoom in/out
**    Space / P       - Pause / Resume simulation
**    S               - Step one generation (while paused)
**    C               - Clear all cells
**    R               - Randomize grid
**    N               - Next pattern preset
**    G               - Toggle grid lines
**    F               - Fit grid to screen
**    +/-             - Speed up / Slow down
**    ESC             - Exit
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W = 1024
SCREEN_H = 700

GRID_W = 150
GRID_H = 100

TOOLBAR_H = 55

// Cell states
DEAD  = 0
ALIVE = 1

// Speed presets (generations per second)
SPEED_MIN = 1
SPEED_MAX = 60
SPEED_DEFAULT = 10

// =============================================================
// State
// =============================================================

// Two grids for double buffering
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

// View
cellSize = 6.0
offsetX = 0.0
offsetY = 0.0
showGrid = true

// Simulation
paused = true
generation = 0
population = 0
speed = SPEED_DEFAULT
simTimer = 0.0

// Pan
panning = false
panStartX = 0
panStartY = 0
panOffX = 0.0
panOffY = 0.0

// Drawing with mouse
drawing = false
drawValue = ALIVE

// Toolbar
hoverBtn = 0
BTN_Y = SCREEN_H - 52
BTN_H = 38
BTN_GAP = 6

// Pattern presets
patternIdx = 0
patternNames = ["Glider", "LWSS", "Pulsar", "Gosper Gun", "Pentadecathlon", "Acorn", "R-pentomino", "Diehard"]
PATTERN_COUNT = 8

// =============================================================
// Main
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Game of Life - RingRayLib")
SetTargetFPS(60)
SetExitKey(0)

// Center the grid
gol_fitToScreen()

// Start with a glider gun
gol_placePattern(1)

while !WindowShouldClose()
    gol_update()
    BeginDrawing()
        ClearBackground(RAYLIBColor(18, 18, 25, 255))
        gol_drawGrid()
        gol_drawHUD()
        gol_drawToolbar()
    EndDrawing()
end

CloseWindow()

// =============================================================
// Update
// =============================================================

func gol_update
    dt = GetFrameTime()

    if IsKeyPressed(KEY_ESCAPE)
        CloseWindow()
        shutdown(0)
    ok

    // Pause / Resume
    if IsKeyPressed(KEY_SPACE) or IsKeyPressed(KEY_P)
        paused = !paused
    ok

    // Step
    if IsKeyPressed(KEY_S)
        if paused
            gol_step()
        ok
    ok

    // Clear
    if IsKeyPressed(KEY_C)
        gol_clearGrid()
        generation = 0
        population = 0
        paused = true
    ok

    // Randomize
    if IsKeyPressed(KEY_R)
        gol_randomize()
        generation = 0
        paused = true
    ok

    // Next pattern
    if IsKeyPressed(KEY_N)
        patternIdx++
        if patternIdx > PATTERN_COUNT patternIdx = 1 ok
        gol_clearGrid()
        gol_placePattern(patternIdx)
        generation = 0
        paused = true
    ok

    // Toggle grid
    if IsKeyPressed(KEY_G)
        showGrid = !showGrid
    ok

    // Fit to screen
    if IsKeyPressed(KEY_F)
        gol_fitToScreen()
    ok

    // Speed
    if IsKeyPressed(KEY_EQUAL) or IsKeyPressed(KEY_KP_ADD)
        speed += 2
        if speed > SPEED_MAX speed = SPEED_MAX ok
    ok
    if IsKeyPressed(KEY_MINUS) or IsKeyPressed(KEY_KP_SUBTRACT)
        speed -= 2
        if speed < SPEED_MIN speed = SPEED_MIN ok
    ok

    // Zoom with mouse wheel
    wheel = GetMouseWheelMove()
    if wheel != 0
        mx = GetMouseX()
        my = GetMouseY()
        if my < SCREEN_H - TOOLBAR_H
            oldSize = cellSize
            cellSize += wheel * cellSize * 0.15
            if cellSize < 2.0 cellSize = 2.0 ok
            if cellSize > 50.0 cellSize = 50.0 ok
            // Zoom toward mouse position
            ratio = cellSize / oldSize
            offsetX = mx - (mx - offsetX) * ratio
            offsetY = my - (my - offsetY) * ratio
        ok
    ok

    // Right mouse - pan
    if IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)
        panning = true
        panStartX = GetMouseX()
        panStartY = GetMouseY()
        panOffX = offsetX
        panOffY = offsetY
    ok
    if panning
        if IsMouseButtonDown(MOUSE_RIGHT_BUTTON)
            offsetX = panOffX + (GetMouseX() - panStartX)
            offsetY = panOffY + (GetMouseY() - panStartY)
        else
            panning = false
        ok
    ok

    // Left mouse - draw cells
    my = GetMouseY()
    if my < SCREEN_H - TOOLBAR_H
        if IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
            // Check toolbar first
            if hoverBtn = 0
                drawing = true
                gc = gol_mouseToGrid(GetMouseX(), GetMouseY())
                gr = gc[1]  gco = gc[2]
                if gr >= 1 and gr <= GRID_H and gco >= 1 and gco <= GRID_W
                    if grid[gr][gco] = ALIVE
                        drawValue = DEAD
                    else
                        drawValue = ALIVE
                    ok
                    grid[gr][gco] = drawValue
                ok
            ok
        ok
    ok

    if drawing
        if IsMouseButtonDown(MOUSE_LEFT_BUTTON)
            gc = gol_mouseToGrid(GetMouseX(), GetMouseY())
            gr = gc[1]  gco = gc[2]
            if gr >= 1 and gr <= GRID_H and gco >= 1 and gco <= GRID_W
                grid[gr][gco] = drawValue
            ok
        else
            drawing = false
        ok
    ok

    // Mouse click on toolbar
    if IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
        gol_handleClick(GetMouseX(), GetMouseY())
    ok

    // Simulation
    if !paused
        simTimer += dt
        interval = 1.0 / speed
        if simTimer >= interval
            simTimer -= interval
            gol_step()
        ok
    ok

    // Count population
    gol_countPopulation()

// =============================================================
// Mouse to Grid Conversion
// =============================================================

func gol_mouseToGrid mx, my
    col = floor((mx - offsetX) / cellSize) + 1
    row = floor((my - offsetY) / cellSize) + 1
    return [row, col]

// =============================================================
// Fit Grid to Screen
// =============================================================

func gol_fitToScreen
    viewH = SCREEN_H - TOOLBAR_H
    sizeByW = SCREEN_W / GRID_W
    sizeByH = viewH / GRID_H
    if sizeByW < sizeByH
        cellSize = sizeByW
    else
        cellSize = sizeByH
    ok
    if cellSize < 2.0 cellSize = 2.0 ok
    offsetX = (SCREEN_W - GRID_W * cellSize) / 2.0
    offsetY = (viewH - GRID_H * cellSize) / 2.0

// =============================================================
// Simulation Step
// =============================================================

func gol_step
    for r = 1 to GRID_H
        for c = 1 to GRID_W
            n = gol_countNeighbors(r, c)
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

    // Swap grids
    temp = grid
    grid = gridNext
    gridNext = temp

    generation++

func gol_countNeighbors r, c
    count = 0
    for dr = -1 to 1
        for dc = -1 to 1
            if dr = 0 and dc = 0 loop ok
            nr = r + dr
            nc = c + dc
            // Wrap around (toroidal)
            if nr < 1 nr = GRID_H ok
            if nr > GRID_H nr = 1 ok
            if nc < 1 nc = GRID_W ok
            if nc > GRID_W nc = 1 ok
            if grid[nr][nc] = ALIVE
                count++
            ok
        next
    next
    return count

func gol_countPopulation
    population = 0
    for r = 1 to GRID_H
        for c = 1 to GRID_W
            if grid[r][c] = ALIVE
                population++
            ok
        next
    next

// =============================================================
// Clear / Randomize
// =============================================================

func gol_clearGrid
    for r = 1 to GRID_H
        for c = 1 to GRID_W
            grid[r][c] = DEAD
        next
    next

func gol_randomize
    for r = 1 to GRID_H
        for c = 1 to GRID_W
            if GetRandomValue(1, 100) <= 25
                grid[r][c] = ALIVE
            else
                grid[r][c] = DEAD
            ok
        next
    next

// =============================================================
// Pattern Presets
// =============================================================

func gol_placePattern idx
    midR = floor(GRID_H / 2)
    midC = floor(GRID_W / 2)

    if idx = 1   // Glider
        gol_setCells(midR, midC, [
            [0,1,0],
            [0,0,1],
            [1,1,1]
        ])
    ok
    if idx = 2   // LWSS (Lightweight Spaceship)
        gol_setCells(midR, midC, [
            [0,1,0,0,1],
            [1,0,0,0,0],
            [1,0,0,0,1],
            [1,1,1,1,0]
        ])
    ok
    if idx = 3   // Pulsar
        gol_setCells(midR - 6, midC - 6, [
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
    if idx = 4   // Gosper Glider Gun
        gol_setCells(midR - 5, midC - 18, [
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
    if idx = 5   // Pentadecathlon
        gol_setCells(midR - 1, midC - 4, [
            [0,0,1,0,0,0,0,1,0,0],
            [1,1,0,1,1,1,1,0,1,1],
            [0,0,1,0,0,0,0,1,0,0]
        ])
    ok
    if idx = 6   // Acorn
        gol_setCells(midR, midC - 3, [
            [0,1,0,0,0,0,0],
            [0,0,0,1,0,0,0],
            [1,1,0,0,1,1,1]
        ])
    ok
    if idx = 7   // R-pentomino
        gol_setCells(midR, midC, [
            [0,1,1],
            [1,1,0],
            [0,1,0]
        ])
    ok
    if idx = 8   // Diehard
        gol_setCells(midR, midC - 3, [
            [0,0,0,0,0,0,1,0],
            [1,1,0,0,0,0,0,0],
            [0,1,0,0,0,1,1,1]
        ])
    ok

func gol_setCells startR, startC, pattern
    for r = 1 to len(pattern)
        row = pattern[r]
        for c = 1 to len(row)
            gr = startR + r - 1
            gc = startC + c - 1
            if gr >= 1 and gr <= GRID_H and gc >= 1 and gc <= GRID_W
                if row[c] = 1
                    grid[gr][gc] = ALIVE
                ok
            ok
        next
    next

// =============================================================
// Draw Grid
// =============================================================

func gol_drawGrid
    viewH = SCREEN_H - TOOLBAR_H

    // Visible cell range (optimization)
    startC = floor(-offsetX / cellSize)
    startR = floor(-offsetY / cellSize)
    endC = floor((SCREEN_W - offsetX) / cellSize) + 1
    endR = floor((viewH - offsetY) / cellSize) + 1

    if startC < 0 startC = 0 ok
    if startR < 0 startR = 0 ok
    if endC > GRID_W endC = GRID_W ok
    if endR > GRID_H endR = GRID_H ok

    // Draw alive cells
    for r = startR + 1 to endR
        for c = startC + 1 to endC
            if grid[r][c] = ALIVE
                px = floor(offsetX + (c - 1) * cellSize)
                py = floor(offsetY + (r - 1) * cellSize)
                sz = floor(cellSize)
                if sz < 1 sz = 1 ok

                // Color based on neighbor count for visual variety
                n = gol_countNeighbors(r, c)
                if n = 2
                    col = RAYLIBColor(50, 200, 100, 255)
                but n = 3
                    col = RAYLIBColor(100, 255, 150, 255)
                else
                    col = RAYLIBColor(30, 160, 80, 255)
                ok

                DrawRectangle(px, py, sz, sz, col)
            ok
        next
    next

    // Grid lines
    if showGrid and cellSize >= 6.0
        gridCol = RAYLIBColor(40, 42, 55, 255)
        for c = startC to endC
            px = floor(offsetX + c * cellSize)
            if px >= 0 and px <= SCREEN_W
                DrawLine(px, 0, px, viewH, gridCol)
            ok
        next
        for r = startR to endR
            py = floor(offsetY + r * cellSize)
            if py >= 0 and py <= viewH
                DrawLine(0, py, SCREEN_W, py, gridCol)
            ok
        next
    ok

    // Mouse hover cell highlight
    mx = GetMouseX()
    my = GetMouseY()
    if my < viewH
        gc = gol_mouseToGrid(mx, my)
        hr = gc[1]  hc = gc[2]
        if hr >= 1 and hr <= GRID_H and hc >= 1 and hc <= GRID_W
            px = floor(offsetX + (hc - 1) * cellSize)
            py = floor(offsetY + (hr - 1) * cellSize)
            sz = floor(cellSize)
            DrawRectangleLines(px, py, sz, sz, RAYLIBColor(255, 255, 255, 80))
        ok
    ok

    // Clip toolbar area
    DrawRectangle(0, viewH, SCREEN_W, TOOLBAR_H + 5, RAYLIBColor(18, 18, 25, 255))

// =============================================================
// Draw HUD
// =============================================================

func gol_drawHUD
    // Top info bar
    DrawRectangle(0, 0, SCREEN_W, 28, RAYLIBColor(0, 0, 0, 160))

    DrawText("Game of Life", 10, 5, 18, RAYLIBColor(255, 215, 0, 220))

    // Generation
    genTxt = "Gen: " + string(generation)
    DrawText(genTxt, 180, 7, 16, RAYLIBColor(180, 220, 255, 220))

    // Population
    popTxt = "Pop: " + string(population)
    DrawText(popTxt, 310, 7, 16, RAYLIBColor(150, 255, 150, 220))

    // Speed
    spdTxt = "Speed: " + string(speed) + " gen/s"
    DrawText(spdTxt, 440, 7, 16, RAYLIBColor(255, 200, 150, 220))

    // Grid size
    grdTxt = "" + string(GRID_W) + "x" + string(GRID_H)
    DrawText(grdTxt, 600, 7, 16, RAYLIBColor(180, 180, 200, 180))

    // Status
    if paused
        DrawText("PAUSED", 700, 7, 16, RAYLIBColor(255, 100, 100, 240))
    else
        DrawText("RUNNING", 700, 7, 16, RAYLIBColor(100, 255, 100, 240))
    ok

    // Pattern name
    if patternIdx >= 1 and patternIdx <= PATTERN_COUNT
        pName = "Pattern: " + patternNames[patternIdx]
        pw = MeasureText(pName, 14)
        DrawText(pName, SCREEN_W - pw - 10, 8, 14, RAYLIBColor(200, 180, 255, 180))
    ok

    // FPS
    fpsTxt = "" + string(GetFPS()) + " FPS"
    DrawText(fpsTxt, SCREEN_W - 70, SCREEN_H - 15, 14, RAYLIBColor(100, 255, 100, 180))

// =============================================================
// Toolbar
// =============================================================

func gol_drawToolbar
    DrawRectangle(0, SCREEN_H - TOOLBAR_H, SCREEN_W, TOOLBAR_H, RAYLIBColor(20, 20, 35, 240))
    DrawRectangle(0, SCREEN_H - TOOLBAR_H, SCREEN_W, 2, RAYLIBColor(80, 80, 120, 200))

    mx = GetMouseX()
    my = GetMouseY()
    hoverBtn = 0

    bx = BTN_GAP

    // Play/Pause
    if paused
        bx = gol_drawBtn("Play [Space]", bx, 1, RAYLIBColor(40, 130, 70, 255), mx, my)
    else
        bx = gol_drawBtn("Pause [Space]", bx, 1, RAYLIBColor(180, 120, 20, 255), mx, my)
    ok
    bx += BTN_GAP

    // Step
    bx = gol_drawBtn("Step [S]", bx, 2, RAYLIBColor(60, 100, 160, 255), mx, my)
    bx += BTN_GAP

    // Clear
    bx = gol_drawBtn("Clear [C]", bx, 3, RAYLIBColor(170, 40, 40, 255), mx, my)
    bx += BTN_GAP

    // Random
    bx = gol_drawBtn("Random [R]", bx, 4, RAYLIBColor(130, 60, 150, 255), mx, my)
    bx += BTN_GAP

    // Pattern
    bx = gol_drawBtn("Pattern [N]", bx, 5, RAYLIBColor(40, 120, 140, 255), mx, my)
    bx += BTN_GAP

    // Grid toggle
    bx = gol_drawBtn("Grid [G]", bx, 6, RAYLIBColor(80, 80, 120, 255), mx, my)
    bx += BTN_GAP

    // Fit
    bx = gol_drawBtn("Fit [F]", bx, 7, RAYLIBColor(100, 90, 50, 255), mx, my)
    bx += BTN_GAP

    // Separator
    DrawRectangle(bx, BTN_Y + 4, 2, BTN_H - 8, RAYLIBColor(80, 80, 120, 150))
    bx += BTN_GAP

    // Speed down
    bx = gol_drawBtn("Slow [-]", bx, 8, RAYLIBColor(140, 70, 70, 255), mx, my)
    bx += BTN_GAP

    // Speed up
    bx = gol_drawBtn("Fast [+]", bx, 9, RAYLIBColor(70, 140, 70, 255), mx, my)

func gol_drawBtn label, bx, btnId, baseCol, mx, my
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

func gol_handleClick mx, my
    if hoverBtn = 1
        paused = !paused
        return
    ok
    if hoverBtn = 2
        if paused gol_step() ok
        return
    ok
    if hoverBtn = 3
        gol_clearGrid()
        generation = 0
        population = 0
        paused = true
        return
    ok
    if hoverBtn = 4
        gol_randomize()
        generation = 0
        paused = true
        return
    ok
    if hoverBtn = 5
        patternIdx++
        if patternIdx > PATTERN_COUNT patternIdx = 1 ok
        gol_clearGrid()
        gol_placePattern(patternIdx)
        generation = 0
        paused = true
        return
    ok
    if hoverBtn = 6
        showGrid = !showGrid
        return
    ok
    if hoverBtn = 7
        gol_fitToScreen()
        return
    ok
    if hoverBtn = 8
        speed -= 2
        if speed < SPEED_MIN speed = SPEED_MIN ok
        return
    ok
    if hoverBtn = 9
        speed += 2
        if speed > SPEED_MAX speed = SPEED_MAX ok
        return
    ok
