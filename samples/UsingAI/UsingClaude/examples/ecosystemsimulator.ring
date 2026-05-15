/*
**  EcoSystem Simulator - RingRayLib
**  ====================================
**  Predator/Prey simulation — foxes and rabbits evolving.
**  Watch Lotka-Volterra population dynamics unfold in real time!
**
**  Controls:
**    Space / P       - Pause / Resume
**    +/-             - Speed up / Slow down
**    R               - Reset ecosystem
**    G               - Toggle grass regrowth speed
**    T               - Toggle terrain view / stats view
**    D               - Toggle debug (show energy values)
**    F               - Spawn 5 foxes
**    B               - Spawn 10 rabbits
**    1-3             - Preset scenarios
**    ESC             - Exit
**
**  Organisms:
**    Grass   - Green tiles, regrows over time
**    Rabbits - White dots, eat grass, reproduce, flee foxes
**    Foxes   - Orange dots, hunt rabbits, reproduce, starve
**
**  Evolution:
**    Each creature has genes: speed, vision, reproduction rate.
**    Offspring inherit genes with small mutations.
**    Over generations, populations adapt!
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

// World grid
CELL = 5
WORLD_W = floor(SCREEN_W / CELL)
WORLD_H = floor(CANVAS_H / CELL)

// Grass states
GRASS_EMPTY  = 0
GRASS_GROWING = 1
GRASS_FULL   = 2

// Grass timing
GRASS_GROW_SLOW   = 1
GRASS_GROW_MEDIUM = 2
GRASS_GROW_FAST   = 3
GRASS_COUNT = 3
grassNames = ["Slow", "Medium", "Fast"]
grassTimes = [30.0, 15.0, 7.0]

// Creature types
TYPE_RABBIT = 1
TYPE_FOX    = 2

// =============================================================
// World
// =============================================================

// Grass grid: [state, timer]
grassState = []
grassTimer = []
totalGrass = WORLD_W * WORLD_H

for i = 1 to totalGrass
    add(grassState, GRASS_FULL)
    add(grassTimer, 0.0)
next

// =============================================================
// Creatures
// =============================================================

// Creature: [type, x, y, energy, maxEnergy, age, alive,
//            geneSpeed, geneVision, geneReproRate,
//            reproTimer, generation, dir]
creatures = []
nextId = 1
MAX_CREATURES = 800

// Initial params
RABBIT_START_ENERGY = 40.0
RABBIT_MAX_ENERGY   = 80.0
RABBIT_GRASS_ENERGY = 15.0
RABBIT_MOVE_COST    = 0.3
RABBIT_REPRO_COST   = 25.0
RABBIT_BASE_SPEED   = 1.0
RABBIT_BASE_VISION  = 4.0
RABBIT_BASE_REPRO   = 8.0

FOX_START_ENERGY  = 60.0
FOX_MAX_ENERGY    = 120.0
FOX_EAT_ENERGY    = 40.0
FOX_MOVE_COST     = 0.5
FOX_REPRO_COST    = 40.0
FOX_BASE_SPEED    = 1.3
FOX_BASE_VISION   = 6.0
FOX_BASE_REPRO    = 15.0

// Mutation
MUTATION_RATE = 0.15

// =============================================================
// State
// =============================================================

paused = false
simSpeed = 1.0
animTime = 0.0
simTick = 0.0
TICK_RATE = 0.05     // seconds per simulation step

grassGrowMode = GRASS_GROW_MEDIUM
showStats = false
debugView = false

// Population history for graph
POP_HISTORY = 300
rabbitHistory = []
foxHistory = []
grassHistory = []
for i = 1 to POP_HISTORY
    add(rabbitHistory, 0)
    add(foxHistory, 0)
    add(grassHistory, 0)
next
historyIdx = 0
historyTimer = 0.0

generation = 0
totalBorn = 0
totalDied = 0

// Toolbar
hoverBtn = 0
BTN_Y = SCREEN_H - 46
BTN_H = 36
BTN_GAP = 4

// =============================================================
// Main
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "EcoSystem Simulator - RingRayLib")
SetTargetFPS(60)
SetExitKey(0)

eco_reset()

while !WindowShouldClose()
    eco_update()
    BeginDrawing()
        ClearBackground(RAYLIBColor(20, 25, 15, 255))
        eco_draw()
    EndDrawing()
end

CloseWindow()

// =============================================================
// Grid Helpers
// =============================================================

func eco_gIdx x, y
    if x < 1 or x > WORLD_W or y < 1 or y > WORLD_H return 0 ok
    return (y - 1) * WORLD_W + x

// =============================================================
// Reset
// =============================================================

func eco_reset
    creatures = []
    nextId = 1
    generation = 0
    totalBorn = 0
    totalDied = 0

    // Reset grass
    for i = 1 to totalGrass
        grassState[i] = GRASS_FULL
        grassTimer[i] = 0.0
    next

    // Spawn rabbits
    for i = 1 to 60
        rx = GetRandomValue(1, WORLD_W)
        ry = GetRandomValue(1, WORLD_H)
        eco_spawnCreature(TYPE_RABBIT, rx, ry,
                          RABBIT_BASE_SPEED, RABBIT_BASE_VISION, RABBIT_BASE_REPRO, 1)
    next

    // Spawn foxes
    for i = 1 to 15
        fx = GetRandomValue(1, WORLD_W)
        fy = GetRandomValue(1, WORLD_H)
        eco_spawnCreature(TYPE_FOX, fx, fy,
                          FOX_BASE_SPEED, FOX_BASE_VISION, FOX_BASE_REPRO, 1)
    next

    // Reset history
    for i = 1 to POP_HISTORY
        rabbitHistory[i] = 0
        foxHistory[i] = 0
        grassHistory[i] = 0
    next
    historyIdx = 0

// =============================================================
// Spawn Creature
// =============================================================

func eco_spawnCreature type, x, y, spd, vis, repro, gen
    if len(creatures) >= MAX_CREATURES return ok

    if x < 1 x = 1 ok
    if x > WORLD_W x = WORLD_W ok
    if y < 1 y = 1 ok
    if y > WORLD_H y = WORLD_H ok

    energy = RABBIT_START_ENERGY
    maxE = RABBIT_MAX_ENERGY
    if type = TYPE_FOX
        energy = FOX_START_ENERGY
        maxE = FOX_MAX_ENERGY
    ok

    dir = GetRandomValue(1, 4)

    add(creatures, [type, x * 1.0, y * 1.0, energy, maxE, 0.0, 1,
                    spd, vis, repro, 0.0, gen, dir])
    totalBorn++
    return len(creatures)

// =============================================================
// Presets
// =============================================================

func eco_preset1
    // Balanced start
    eco_reset()

func eco_preset2
    // Lots of rabbits, few foxes (population explosion then crash)
    eco_reset()
    // Add more rabbits
    for i = 1 to 100
        rx = GetRandomValue(1, WORLD_W)
        ry = GetRandomValue(1, WORLD_H)
        eco_spawnCreature(TYPE_RABBIT, rx, ry,
                          RABBIT_BASE_SPEED, RABBIT_BASE_VISION, RABBIT_BASE_REPRO, 1)
    next

func eco_preset3
    // Many foxes, few rabbits (starvation pressure)
    eco_reset()
    for i = 1 to 30
        fx = GetRandomValue(1, WORLD_W)
        fy = GetRandomValue(1, WORLD_H)
        eco_spawnCreature(TYPE_FOX, fx, fy,
                          FOX_BASE_SPEED, FOX_BASE_VISION, FOX_BASE_REPRO, 1)
    next

// =============================================================
// Update
// =============================================================

func eco_update
    dt = GetFrameTime()
    if dt > 0.05 dt = 0.05 ok
    animTime += dt

    if IsKeyPressed(KEY_ESCAPE)
        CloseWindow()
        shutdown(0)
    ok

    if IsKeyPressed(KEY_SPACE) or IsKeyPressed(KEY_P) paused = !paused ok

    if IsKeyPressed(KEY_EQUAL) or IsKeyPressed(KEY_KP_ADD)
        simSpeed *= 1.5
        if simSpeed > 8.0 simSpeed = 8.0 ok
    ok
    if IsKeyPressed(KEY_MINUS) or IsKeyPressed(KEY_KP_SUBTRACT)
        simSpeed /= 1.5
        if simSpeed < 0.25 simSpeed = 0.25 ok
    ok

    if IsKeyPressed(KEY_R) eco_reset() ok

    if IsKeyPressed(KEY_G)
        grassGrowMode++
        if grassGrowMode > GRASS_COUNT grassGrowMode = 1 ok
    ok

    if IsKeyPressed(KEY_T) showStats = !showStats ok
    if IsKeyPressed(KEY_D) debugView = !debugView ok

    if IsKeyPressed(KEY_F)
        for i = 1 to 5
            fx = GetRandomValue(1, WORLD_W)
            fy = GetRandomValue(1, WORLD_H)
            eco_spawnCreature(TYPE_FOX, fx, fy,
                              FOX_BASE_SPEED, FOX_BASE_VISION, FOX_BASE_REPRO, 1)
        next
    ok

    if IsKeyPressed(KEY_B)
        for i = 1 to 10
            rx = GetRandomValue(1, WORLD_W)
            ry = GetRandomValue(1, WORLD_H)
            eco_spawnCreature(TYPE_RABBIT, rx, ry,
                              RABBIT_BASE_SPEED, RABBIT_BASE_VISION, RABBIT_BASE_REPRO, 1)
        next
    ok

    if IsKeyPressed(KEY_ONE) eco_preset1() ok
    if IsKeyPressed(KEY_TWO) eco_preset2() ok
    if IsKeyPressed(KEY_THREE) eco_preset3() ok

    // Toolbar
    if IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
        eco_handleToolbar(GetMouseX(), GetMouseY())
    ok

    // Click on canvas to spawn
    if IsMouseButtonPressed(MOUSE_LEFT_BUTTON) and hoverBtn = 0
        mx = GetMouseX()  my = GetMouseY()
        if my < CANVAS_H
            gx = floor(mx / CELL) + 1
            gy = floor(my / CELL) + 1
            eco_spawnCreature(TYPE_RABBIT, gx, gy,
                              RABBIT_BASE_SPEED, RABBIT_BASE_VISION, RABBIT_BASE_REPRO, 1)
        ok
    ok

    if IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)
        mx = GetMouseX()  my = GetMouseY()
        if my < CANVAS_H
            gx = floor(mx / CELL) + 1
            gy = floor(my / CELL) + 1
            eco_spawnCreature(TYPE_FOX, gx, gy,
                              FOX_BASE_SPEED, FOX_BASE_VISION, FOX_BASE_REPRO, 1)
        ok
    ok

    if paused return ok

    simTick += dt * simSpeed
    while simTick >= TICK_RATE
        simTick -= TICK_RATE
        eco_step(TICK_RATE)
    end

    // Population history
    historyTimer += dt
    if historyTimer >= 0.2
        historyTimer -= 0.2
        historyIdx++
        if historyIdx > POP_HISTORY historyIdx = 1 ok

        rCount = 0  fCount = 0  gCount = 0
        for i = 1 to len(creatures)
            if creatures[i][7] = 0 loop ok
            if creatures[i][1] = TYPE_RABBIT rCount++ ok
            if creatures[i][1] = TYPE_FOX fCount++ ok
        next
        for i = 1 to totalGrass
            if grassState[i] = GRASS_FULL gCount++ ok
        next

        rabbitHistory[historyIdx] = rCount
        foxHistory[historyIdx] = fCount
        grassHistory[historyIdx] = floor(gCount / 10)
    ok

// =============================================================
// Simulation Step
// =============================================================

func eco_step dt
    // Grow grass
    growTime = grassTimes[grassGrowMode]
    for i = 1 to totalGrass
        if grassState[i] = GRASS_EMPTY
            grassTimer[i] += dt
            if grassTimer[i] >= growTime * 0.5
                grassState[i] = GRASS_GROWING
            ok
        ok
        if grassState[i] = GRASS_GROWING
            grassTimer[i] += dt
            if grassTimer[i] >= growTime
                grassState[i] = GRASS_FULL
                grassTimer[i] = 0.0
            ok
        ok
    next

    // Shuffle order for fairness
    order = []
    for i = 1 to len(creatures)
        add(order, i)
    next
    // Simple shuffle
    for i = len(order) to 2 step -1
        j = GetRandomValue(1, i)
        temp = order[i]
        order[i] = order[j]
        order[j] = temp
    next

    // Update each creature
    for oi = 1 to len(order)
        ci = order[oi]
        if ci > len(creatures) loop ok
        if creatures[ci][7] = 0 loop ok

        cType = creatures[ci][1]
        if cType = TYPE_RABBIT
            eco_updateRabbit(ci, dt)
        ok
        if cType = TYPE_FOX
            eco_updateFox(ci, dt)
        ok
    next

    // Remove dead
    i = len(creatures)
    while i >= 1
        if creatures[i][7] = 0
            del(creatures, i)
            totalDied++
        ok
        i--
    end

// =============================================================
// Update Rabbit
// =============================================================

func eco_updateRabbit ci, dt
    c = creatures[ci]
    cx = c[2]   cy = c[3]
    energy = c[4]
    spd = c[8]  vis = c[9]  reproRate = c[10]

    // Age
    creatures[ci][6] += dt

    // Energy drain
    moveCost = RABBIT_MOVE_COST * spd * 0.8
    energy -= moveCost * dt
    if energy <= 0
        creatures[ci][7] = 0
        return
    ok

    // Look for nearby fox (flee)
    nearFoxDx = 0   nearFoxDy = 0   nearFoxDist = 9999.0
    for j = 1 to len(creatures)
        if j = ci loop ok
        if creatures[j][7] = 0 loop ok
        if creatures[j][1] != TYPE_FOX loop ok
        dx = creatures[j][2] - cx
        dy = creatures[j][3] - cy
        dist = sqrt(dx*dx + dy*dy)
        if dist < vis and dist < nearFoxDist
            nearFoxDist = dist
            nearFoxDx = dx
            nearFoxDy = dy
        ok
    next

    // Movement
    moveX = 0.0   moveY = 0.0

    if nearFoxDist < vis
        // Flee away from fox
        fleeDist = sqrt(nearFoxDx * nearFoxDx + nearFoxDy * nearFoxDy)
        if fleeDist > 0.01
            moveX = -(nearFoxDx / fleeDist) * spd
            moveY = -(nearFoxDy / fleeDist) * spd
        ok
    else
        // Wander toward grass
        bestDx = 0  bestDy = 0  bestDist = 9999.0
        gxi = floor(cx)  gyi = floor(cy)
        visI = floor(vis)
        for dy = -visI to visI
            for dx = -visI to visI
                if dx = 0 and dy = 0 loop ok
                tx = gxi + dx   ty = gyi + dy
                gi = eco_gIdx(tx, ty)
                if gi > 0
                    if grassState[gi] = GRASS_FULL
                        dist = sqrt(dx*dx + dy*dy)
                        if dist < bestDist
                            bestDist = dist
                            bestDx = dx   bestDy = dy
                        ok
                    ok
                ok
            next
        next

        if bestDist < 9000
            nd = sqrt(bestDx*bestDx + bestDy*bestDy)
            if nd > 0.01
                moveX = (bestDx / nd) * spd
                moveY = (bestDy / nd) * spd
            ok
        else
            // Random wander
            moveX = (GetRandomValue(-100, 100) / 100.0) * spd * 0.5
            moveY = (GetRandomValue(-100, 100) / 100.0) * spd * 0.5
        ok
    ok

    // Apply movement
    nx = cx + moveX * dt * 8
    ny = cy + moveY * dt * 8
    if nx < 1 nx = 1 ok
    if nx > WORLD_W nx = WORLD_W ok
    if ny < 1 ny = 1 ok
    if ny > WORLD_H ny = WORLD_H ok
    creatures[ci][2] = nx
    creatures[ci][3] = ny

    // Eat grass
    gi = eco_gIdx(floor(nx), floor(ny))
    if gi > 0
        if grassState[gi] = GRASS_FULL
            grassState[gi] = GRASS_EMPTY
            grassTimer[gi] = 0.0
            energy += RABBIT_GRASS_ENERGY
            if energy > creatures[ci][5] energy = creatures[ci][5] ok
        ok
    ok

    creatures[ci][4] = energy

    // Reproduce
    creatures[ci][11] += dt
    if creatures[ci][11] >= reproRate and energy > RABBIT_REPRO_COST * 1.2
        creatures[ci][11] = 0.0
        creatures[ci][4] -= RABBIT_REPRO_COST
        // Offspring with mutated genes
        newSpd = spd + (GetRandomValue(-100, 100) / 100.0) * MUTATION_RATE
        newVis = vis + (GetRandomValue(-100, 100) / 100.0) * MUTATION_RATE * 2
        newRepro = reproRate + (GetRandomValue(-100, 100) / 100.0) * MUTATION_RATE * 3
        if newSpd < 0.3 newSpd = 0.3 ok
        if newVis < 1.0 newVis = 1.0 ok
        if newRepro < 3.0 newRepro = 3.0 ok
        offX = floor(nx) + GetRandomValue(-2, 2)
        offY = floor(ny) + GetRandomValue(-2, 2)
        eco_spawnCreature(TYPE_RABBIT, offX, offY, newSpd, newVis, newRepro, c[12] + 1)
    ok

// =============================================================
// Update Fox
// =============================================================

func eco_updateFox ci, dt
    c = creatures[ci]
    cx = c[2]   cy = c[3]
    energy = c[4]
    spd = c[8]  vis = c[9]  reproRate = c[10]

    creatures[ci][6] += dt

    // Energy drain (foxes drain faster)
    moveCost = FOX_MOVE_COST * spd * 0.6
    energy -= moveCost * dt
    if energy <= 0
        creatures[ci][7] = 0
        return
    ok

    // Hunt: find nearest rabbit
    nearIdx = 0   nearDist = 9999.0
    nearDx = 0.0  nearDy = 0.0
    for j = 1 to len(creatures)
        if j = ci loop ok
        if creatures[j][7] = 0 loop ok
        if creatures[j][1] != TYPE_RABBIT loop ok
        dx = creatures[j][2] - cx
        dy = creatures[j][3] - cy
        dist = sqrt(dx*dx + dy*dy)
        if dist < vis and dist < nearDist
            nearDist = dist
            nearIdx = j
            nearDx = dx
            nearDy = dy
        ok
    next

    // Movement
    moveX = 0.0   moveY = 0.0

    if nearIdx > 0
        // Chase rabbit
        nd = sqrt(nearDx*nearDx + nearDy*nearDy)
        if nd > 0.01
            moveX = (nearDx / nd) * spd
            moveY = (nearDy / nd) * spd
        ok

        // Catch rabbit (close enough)
        if nearDist < 1.2
            if nearIdx <= len(creatures)
                if creatures[nearIdx][7] = 1
                    creatures[nearIdx][7] = 0  // kill rabbit
                    energy += FOX_EAT_ENERGY
                    if energy > creatures[ci][5] energy = creatures[ci][5] ok
                ok
            ok
        ok
    else
        // Wander
        moveX = (GetRandomValue(-100, 100) / 100.0) * spd * 0.4
        moveY = (GetRandomValue(-100, 100) / 100.0) * spd * 0.4
    ok

    nx = cx + moveX * dt * 8
    ny = cy + moveY * dt * 8
    if nx < 1 nx = 1 ok
    if nx > WORLD_W nx = WORLD_W ok
    if ny < 1 ny = 1 ok
    if ny > WORLD_H ny = WORLD_H ok
    creatures[ci][2] = nx
    creatures[ci][3] = ny
    creatures[ci][4] = energy

    // Reproduce
    creatures[ci][11] += dt
    if creatures[ci][11] >= reproRate and energy > FOX_REPRO_COST * 1.2
        creatures[ci][11] = 0.0
        creatures[ci][4] -= FOX_REPRO_COST
        newSpd = spd + (GetRandomValue(-100, 100) / 100.0) * MUTATION_RATE
        newVis = vis + (GetRandomValue(-100, 100) / 100.0) * MUTATION_RATE * 2
        newRepro = reproRate + (GetRandomValue(-100, 100) / 100.0) * MUTATION_RATE * 3
        if newSpd < 0.5 newSpd = 0.5 ok
        if newVis < 2.0 newVis = 2.0 ok
        if newRepro < 5.0 newRepro = 5.0 ok
        offX = floor(nx) + GetRandomValue(-2, 2)
        offY = floor(ny) + GetRandomValue(-2, 2)
        eco_spawnCreature(TYPE_FOX, offX, offY, newSpd, newVis, newRepro, c[12] + 1)
    ok

// =============================================================
// Draw
// =============================================================

func eco_draw
    if showStats
        eco_drawStats()
    else
        eco_drawWorld()
    ok

    eco_drawHUD()
    eco_drawToolbar()

// =============================================================
// Draw World
// =============================================================

func eco_drawWorld
    // Grass
    for y = 1 to WORLD_H
        rowOff = (y - 1) * WORLD_W
        sy = (y - 1) * CELL
        for x = 1 to WORLD_W
            idx = rowOff + x
            sx = (x - 1) * CELL
            gs = grassState[idx]

            if gs = GRASS_FULL
                DrawRectangle(sx, sy, CELL, CELL, RAYLIBColor(40, 120, 30, 255))
            but gs = GRASS_GROWING
                t = grassTimer[idx] / grassTimes[grassGrowMode]
                g = floor(50 + t * 60)
                DrawRectangle(sx, sy, CELL, CELL, RAYLIBColor(35, g, 25, 255))
            else
                DrawRectangle(sx, sy, CELL, CELL, RAYLIBColor(50, 45, 20, 255))
            ok
        next
    next

    // Creatures
    for i = 1 to len(creatures)
        if creatures[i][7] = 0 loop ok
        c = creatures[i]
        cx = (c[2] - 1) * CELL + CELL / 2
        cy = (c[3] - 1) * CELL + CELL / 2

        if c[1] = TYPE_RABBIT
            // White dot with slight size based on energy
            sz = 2 + floor(c[4] / c[5] * 2)
            if sz < 2 sz = 2 ok
            DrawCircle(floor(cx), floor(cy), sz, RAYLIBColor(240, 240, 250, 240))
            // Vision ring in debug
            if debugView
                DrawCircleLines(floor(cx), floor(cy), floor(c[9] * CELL), RAYLIBColor(200, 200, 255, 30))
            ok
        ok

        if c[1] = TYPE_FOX
            sz = 3 + floor(c[4] / c[5] * 2)
            if sz < 3 sz = 3 ok
            // Orange body
            DrawCircle(floor(cx), floor(cy), sz, RAYLIBColor(230, 140, 40, 240))
            // Dark center
            DrawCircle(floor(cx), floor(cy), floor(sz * 0.4), RAYLIBColor(180, 80, 20, 200))
            if debugView
                DrawCircleLines(floor(cx), floor(cy), floor(c[9] * CELL), RAYLIBColor(255, 180, 80, 30))
            ok
        ok

        // Debug: energy text
        if debugView
            eTxt = string(floor(c[4]))
            DrawText(eTxt, floor(cx) + 4, floor(cy) - 4, 8, RAYLIBColor(255, 255, 255, 100))
        ok
    next

    // Mini population graph at bottom-right
    eco_drawMiniGraph(SCREEN_W - 210, CANVAS_H - 65, 200, 58)

// =============================================================
// Draw Mini Graph
// =============================================================

func eco_drawMiniGraph gx, gy, gw, gh
    DrawRectangle(gx, gy, gw, gh, RAYLIBColor(0, 0, 0, 140))
    DrawRectangleLines(gx, gy, gw, gh, RAYLIBColor(80, 80, 100, 150))

    // Find max for scaling
    maxVal = 10
    for i = 1 to POP_HISTORY
        if rabbitHistory[i] > maxVal maxVal = rabbitHistory[i] ok
        if foxHistory[i] > maxVal maxVal = foxHistory[i] ok
        if grassHistory[i] > maxVal maxVal = grassHistory[i] ok
    next

    // Draw lines
    for i = 2 to POP_HISTORY
        idx1 = ((historyIdx + i - 2) % POP_HISTORY) + 1
        idx2 = ((historyIdx + i - 1) % POP_HISTORY) + 1

        x1 = gx + (i - 2) * gw / POP_HISTORY
        x2 = gx + (i - 1) * gw / POP_HISTORY

        // Grass (green, dimmed)
        gy1 = gy + gh - floor(grassHistory[idx1] * 1.0 / maxVal * (gh - 4))
        gy2 = gy + gh - floor(grassHistory[idx2] * 1.0 / maxVal * (gh - 4))
        DrawLine(floor(x1), gy1, floor(x2), gy2, RAYLIBColor(60, 160, 40, 100))

        // Rabbits (white)
        ry1 = gy + gh - floor(rabbitHistory[idx1] * 1.0 / maxVal * (gh - 4))
        ry2 = gy + gh - floor(rabbitHistory[idx2] * 1.0 / maxVal * (gh - 4))
        DrawLine(floor(x1), ry1, floor(x2), ry2, RAYLIBColor(240, 240, 255, 180))

        // Foxes (orange)
        fy1 = gy + gh - floor(foxHistory[idx1] * 1.0 / maxVal * (gh - 4))
        fy2 = gy + gh - floor(foxHistory[idx2] * 1.0 / maxVal * (gh - 4))
        DrawLine(floor(x1), fy1, floor(x2), fy2, RAYLIBColor(230, 140, 40, 180))
    next

    // Labels
    DrawText("Pop", gx + 3, gy + 2, 9, RAYLIBColor(200, 200, 220, 120))

// =============================================================
// Draw Stats View
// =============================================================

func eco_drawStats
    DrawRectangle(0, 0, SCREEN_W, CANVAS_H, RAYLIBColor(20, 22, 30, 255))

    // Count populations
    rCount = 0  fCount = 0  gCount = 0
    rAvgSpd = 0.0  rAvgVis = 0.0  rAvgRepro = 0.0
    fAvgSpd = 0.0  fAvgVis = 0.0  fAvgRepro = 0.0
    rMaxGen = 0  fMaxGen = 0

    for i = 1 to len(creatures)
        if creatures[i][7] = 0 loop ok
        if creatures[i][1] = TYPE_RABBIT
            rCount++
            rAvgSpd += creatures[i][8]
            rAvgVis += creatures[i][9]
            rAvgRepro += creatures[i][10]
            if creatures[i][12] > rMaxGen rMaxGen = creatures[i][12] ok
        ok
        if creatures[i][1] = TYPE_FOX
            fCount++
            fAvgSpd += creatures[i][8]
            fAvgVis += creatures[i][9]
            fAvgRepro += creatures[i][10]
            if creatures[i][12] > fMaxGen fMaxGen = creatures[i][12] ok
        ok
    next
    for i = 1 to totalGrass
        if grassState[i] = GRASS_FULL gCount++ ok
    next

    if rCount > 0
        rAvgSpd /= rCount   rAvgVis /= rCount   rAvgRepro /= rCount
    ok
    if fCount > 0
        fAvgSpd /= fCount   fAvgVis /= fCount   fAvgRepro /= fCount
    ok

    // Large population graph
    eco_drawLargeGraph(30, 30, SCREEN_W - 60, 200)

    // Stats panels
    py = 260

    // Rabbit stats
    DrawRectangle(30, py, 300, 180, RAYLIBColor(30, 30, 40, 255))
    DrawRectangleLines(30, py, 300, 180, RAYLIBColor(200, 200, 255, 80))
    DrawCircle(50, py + 18, 6, RAYLIBColor(240, 240, 250, 240))
    DrawText("RABBITS", 65, py + 10, 18, RAYLIBColor(240, 240, 255, 220))
    DrawText("Population: " + string(rCount), 45, py + 40, 14, RAYLIBColor(200, 220, 200, 200))
    DrawText("Avg Speed: " + string(floor(rAvgSpd * 100) / 100.0), 45, py + 60, 14, RAYLIBColor(200, 200, 220, 180))
    DrawText("Avg Vision: " + string(floor(rAvgVis * 100) / 100.0), 45, py + 80, 14, RAYLIBColor(200, 200, 220, 180))
    DrawText("Avg Repro: " + string(floor(rAvgRepro * 100) / 100.0) + "s", 45, py + 100, 14, RAYLIBColor(200, 200, 220, 180))
    DrawText("Max Generation: " + string(rMaxGen), 45, py + 120, 14, RAYLIBColor(180, 200, 255, 180))

    // Gene bars
    eco_drawGeneBar(45, py + 145, 240, 10, "SPD", rAvgSpd, 0.3, 3.0, RAYLIBColor(100, 200, 255, 200))
    eco_drawGeneBar(45, py + 160, 240, 10, "VIS", rAvgVis, 1.0, 15.0, RAYLIBColor(100, 255, 150, 200))

    // Fox stats
    DrawRectangle(360, py, 300, 180, RAYLIBColor(30, 30, 40, 255))
    DrawRectangleLines(360, py, 300, 180, RAYLIBColor(255, 180, 80, 80))
    DrawCircle(380, py + 18, 6, RAYLIBColor(230, 140, 40, 240))
    DrawText("FOXES", 395, py + 10, 18, RAYLIBColor(255, 200, 100, 220))
    DrawText("Population: " + string(fCount), 375, py + 40, 14, RAYLIBColor(220, 200, 180, 200))
    DrawText("Avg Speed: " + string(floor(fAvgSpd * 100) / 100.0), 375, py + 60, 14, RAYLIBColor(220, 200, 180, 180))
    DrawText("Avg Vision: " + string(floor(fAvgVis * 100) / 100.0), 375, py + 80, 14, RAYLIBColor(220, 200, 180, 180))
    DrawText("Avg Repro: " + string(floor(fAvgRepro * 100) / 100.0) + "s", 375, py + 100, 14, RAYLIBColor(220, 200, 180, 180))
    DrawText("Max Generation: " + string(fMaxGen), 375, py + 120, 14, RAYLIBColor(255, 200, 150, 180))

    eco_drawGeneBar(375, py + 145, 240, 10, "SPD", fAvgSpd, 0.5, 4.0, RAYLIBColor(255, 150, 80, 200))
    eco_drawGeneBar(375, py + 160, 240, 10, "VIS", fAvgVis, 2.0, 20.0, RAYLIBColor(255, 200, 100, 200))

    // World stats
    DrawRectangle(690, py, 300, 180, RAYLIBColor(30, 30, 40, 255))
    DrawRectangleLines(690, py, 300, 180, RAYLIBColor(100, 180, 80, 80))
    DrawText("WORLD", 710, py + 10, 18, RAYLIBColor(120, 220, 100, 220))
    gPct = floor(gCount * 100.0 / totalGrass)
    DrawText("Grass: " + string(gCount) + " (" + string(gPct) + "%)", 710, py + 40, 14, RAYLIBColor(100, 200, 100, 200))
    DrawText("Growth: " + grassNames[grassGrowMode], 710, py + 60, 14, RAYLIBColor(150, 200, 150, 180))
    DrawText("Total Born: " + string(totalBorn), 710, py + 90, 14, RAYLIBColor(180, 200, 200, 180))
    DrawText("Total Died: " + string(totalDied), 710, py + 110, 14, RAYLIBColor(200, 150, 150, 180))
    DrawText("Sim Speed: " + string(floor(simSpeed * 100)) + "%", 710, py + 140, 14, RAYLIBColor(180, 180, 200, 180))

    // Grass bar
    eco_drawGeneBar(710, py + 165, 240, 10, "GRS", gPct * 1.0, 0.0, 100.0, RAYLIBColor(80, 180, 60, 200))

func eco_drawGeneBar bx, by, bw, bh, label, val, minV, maxV, col
    DrawRectangle(bx, by, bw, bh, RAYLIBColor(20, 20, 28, 255))
    frac = (val - minV) / (maxV - minV + 0.001)
    if frac > 1.0 frac = 1.0 ok
    if frac < 0.0 frac = 0.0 ok
    fillW = floor(frac * bw)
    DrawRectangle(bx, by, fillW, bh, col)
    DrawText(label, bx - 30, by, 10, RAYLIBColor(160, 160, 180, 150))

// =============================================================
// Draw Large Graph
// =============================================================

func eco_drawLargeGraph gx, gy, gw, gh
    DrawRectangle(gx, gy, gw, gh, RAYLIBColor(15, 15, 22, 255))
    DrawRectangleLines(gx, gy, gw, gh, RAYLIBColor(60, 60, 80, 200))

    // Title
    DrawText("Population Over Time", gx + 10, gy + 5, 14, RAYLIBColor(200, 200, 220, 180))

    // Legend
    DrawRectangle(gx + gw - 180, gy + 5, 10, 10, RAYLIBColor(240, 240, 255, 200))
    DrawText("Rabbits", gx + gw - 166, gy + 5, 11, RAYLIBColor(200, 200, 220, 160))
    DrawRectangle(gx + gw - 100, gy + 5, 10, 10, RAYLIBColor(230, 140, 40, 200))
    DrawText("Foxes", gx + gw - 86, gy + 5, 11, RAYLIBColor(200, 180, 150, 160))

    maxVal = 10
    for i = 1 to POP_HISTORY
        if rabbitHistory[i] > maxVal maxVal = rabbitHistory[i] ok
        if foxHistory[i] * 3 > maxVal maxVal = foxHistory[i] * 3 ok
    next

    plotY = gy + 22
    plotH = gh - 28

    for i = 2 to POP_HISTORY
        idx1 = ((historyIdx + i - 2) % POP_HISTORY) + 1
        idx2 = ((historyIdx + i - 1) % POP_HISTORY) + 1

        x1 = gx + (i - 2) * gw / POP_HISTORY
        x2 = gx + (i - 1) * gw / POP_HISTORY

        // Grass
        gy1 = plotY + plotH - floor(grassHistory[idx1] * 1.0 / maxVal * plotH)
        gy2 = plotY + plotH - floor(grassHistory[idx2] * 1.0 / maxVal * plotH)
        DrawLine(floor(x1), gy1, floor(x2), gy2, RAYLIBColor(60, 140, 40, 60))

        // Rabbits
        ry1 = plotY + plotH - floor(rabbitHistory[idx1] * 1.0 / maxVal * plotH)
        ry2 = plotY + plotH - floor(rabbitHistory[idx2] * 1.0 / maxVal * plotH)
        DrawLine(floor(x1), ry1, floor(x2), ry2, RAYLIBColor(240, 240, 255, 200))

        // Foxes (scaled up for visibility)
        fy1 = plotY + plotH - floor(foxHistory[idx1] * 3.0 / maxVal * plotH)
        fy2 = plotY + plotH - floor(foxHistory[idx2] * 3.0 / maxVal * plotH)
        DrawLine(floor(x1), fy1, floor(x2), fy2, RAYLIBColor(230, 140, 40, 200))
    next

// =============================================================
// HUD
// =============================================================

func eco_drawHUD
    if !showStats
        DrawRectangle(0, 0, SCREEN_W, 26, RAYLIBColor(0, 0, 0, 160))
    ok

    DrawText("EcoSystem", 10, 4, 16, RAYLIBColor(255, 215, 0, 220))

    // Count
    rCount = 0  fCount = 0
    for i = 1 to len(creatures)
        if creatures[i][7] = 0 loop ok
        if creatures[i][1] = TYPE_RABBIT rCount++ ok
        if creatures[i][1] = TYPE_FOX fCount++ ok
    next

    rTxt = "Rabbits: " + string(rCount)
    DrawText(rTxt, 140, 6, 13, RAYLIBColor(240, 240, 255, 220))

    fTxt = "Foxes: " + string(fCount)
    DrawText(fTxt, 260, 6, 13, RAYLIBColor(230, 160, 60, 220))

    spdTxt = "Speed: " + string(floor(simSpeed * 100)) + "%"
    DrawText(spdTxt, 380, 6, 13, RAYLIBColor(200, 200, 180, 180))

    grassTxt = "Grass: " + grassNames[grassGrowMode]
    DrawText(grassTxt, 490, 6, 13, RAYLIBColor(100, 200, 100, 180))

    if paused
        DrawText("PAUSED", 620, 6, 14, RAYLIBColor(255, 100, 100, 240))
    ok

    // View hint
    if showStats
        DrawText("T: World View", 720, 6, 13, RAYLIBColor(180, 200, 255, 150))
    else
        DrawText("T: Stats View", 720, 6, 13, RAYLIBColor(180, 200, 255, 150))
    ok

    // Help
    if !showStats
        DrawText("L-Click:+Rabbit  R-Click:+Fox  B:+10Rabbits  F:+5Foxes  1-3:Presets",
                 6, CANVAS_H - 18, 12, RAYLIBColor(150, 150, 170, 100))
    ok

    fpsTxt = "" + string(GetFPS()) + " FPS"
    DrawText(fpsTxt, SCREEN_W - 60, SCREEN_H - 14, 12, RAYLIBColor(100, 200, 100, 120))

// =============================================================
// Toolbar
// =============================================================

func eco_drawToolbar
    DrawRectangle(0, SCREEN_H - TOOLBAR_H, SCREEN_W, TOOLBAR_H, RAYLIBColor(22, 24, 32, 255))
    DrawRectangle(0, SCREEN_H - TOOLBAR_H, SCREEN_W, 2, RAYLIBColor(60, 60, 100, 200))

    mx = GetMouseX()  my = GetMouseY()
    hoverBtn = 0

    bx = BTN_GAP

    if paused
        bx = eco_drawBtn("Resume[P]", bx, 1, RAYLIBColor(40, 120, 60, 255), mx, my)
    else
        bx = eco_drawBtn("Pause[P]", bx, 1, RAYLIBColor(140, 100, 30, 255), mx, my)
    ok
    bx += BTN_GAP

    bx = eco_drawBtn("Slow[-]", bx, 2, RAYLIBColor(120, 60, 60, 255), mx, my)
    bx += BTN_GAP
    bx = eco_drawBtn("Fast[+]", bx, 3, RAYLIBColor(60, 120, 60, 255), mx, my)
    bx += BTN_GAP

    DrawRectangle(bx, BTN_Y+4, 2, BTN_H-8, RAYLIBColor(60, 60, 100, 150))
    bx += BTN_GAP + 2

    bx = eco_drawBtn("+Rabbit[B]", bx, 4, RAYLIBColor(80, 80, 130, 255), mx, my)
    bx += BTN_GAP
    bx = eco_drawBtn("+Fox[F]", bx, 5, RAYLIBColor(160, 100, 30, 255), mx, my)
    bx += BTN_GAP

    DrawRectangle(bx, BTN_Y+4, 2, BTN_H-8, RAYLIBColor(60, 60, 100, 150))
    bx += BTN_GAP + 2

    bx = eco_drawBtn("Grass[G]", bx, 6, RAYLIBColor(40, 100, 40, 255), mx, my)
    bx += BTN_GAP
    bx = eco_drawBtn("Stats[T]", bx, 7, RAYLIBColor(60, 60, 100, 255), mx, my)
    bx += BTN_GAP
    bx = eco_drawBtn("Debug[D]", bx, 8, RAYLIBColor(80, 70, 40, 255), mx, my)
    bx += BTN_GAP

    DrawRectangle(bx, BTN_Y+4, 2, BTN_H-8, RAYLIBColor(60, 60, 100, 150))
    bx += BTN_GAP + 2

    bx = eco_drawBtn("Preset1", bx, 10, RAYLIBColor(60, 80, 100, 255), mx, my)
    bx += BTN_GAP
    bx = eco_drawBtn("Preset2", bx, 11, RAYLIBColor(80, 80, 60, 255), mx, my)
    bx += BTN_GAP
    bx = eco_drawBtn("Preset3", bx, 12, RAYLIBColor(100, 60, 60, 255), mx, my)
    bx += BTN_GAP

    bx = eco_drawBtn("Reset[R]", bx, 13, RAYLIBColor(140, 40, 40, 255), mx, my)

func eco_drawBtn label, bx, btnId, baseCol, mx, my
    tw = MeasureText(label, 11) + 12
    if tw < 36 tw = 36 ok

    isHover = (mx >= bx and mx <= bx + tw and my >= BTN_Y and my <= BTN_Y + BTN_H)

    if isHover
        hoverBtn = btnId
        DrawRectangle(bx, BTN_Y, tw, BTN_H, RAYLIBColor(255, 225, 100, 240))
        DrawRectangleLines(bx, BTN_Y, tw, BTN_H, RAYLIBColor(200, 180, 60, 255))
        lw = MeasureText(label, 11)
        DrawText(label, bx + (tw-lw)/2, BTN_Y+13, 11, RAYLIBColor(20, 15, 10, 255))
    else
        DrawRectangle(bx, BTN_Y, tw, BTN_H, baseCol)
        DrawRectangleLines(bx, BTN_Y, tw, BTN_H, RAYLIBColor(255, 255, 255, 30))
        lw = MeasureText(label, 11)
        DrawText(label, bx + (tw-lw)/2, BTN_Y+13, 11, WHITE)
    ok

    return bx + tw

// =============================================================
// Toolbar Click
// =============================================================

func eco_handleToolbar mx, my
    if hoverBtn = 1 paused = !paused return ok
    if hoverBtn = 2
        simSpeed /= 1.5
        if simSpeed < 0.25 simSpeed = 0.25 ok
        return
    ok
    if hoverBtn = 3
        simSpeed *= 1.5
        if simSpeed > 8.0 simSpeed = 8.0 ok
        return
    ok
    if hoverBtn = 4
        for i = 1 to 10
            rx = GetRandomValue(1, WORLD_W)
            ry = GetRandomValue(1, WORLD_H)
            eco_spawnCreature(TYPE_RABBIT, rx, ry,
                              RABBIT_BASE_SPEED, RABBIT_BASE_VISION, RABBIT_BASE_REPRO, 1)
        next
        return
    ok
    if hoverBtn = 5
        for i = 1 to 5
            fx = GetRandomValue(1, WORLD_W)
            fy = GetRandomValue(1, WORLD_H)
            eco_spawnCreature(TYPE_FOX, fx, fy,
                              FOX_BASE_SPEED, FOX_BASE_VISION, FOX_BASE_REPRO, 1)
        next
        return
    ok
    if hoverBtn = 6
        grassGrowMode++
        if grassGrowMode > GRASS_COUNT grassGrowMode = 1 ok
        return
    ok
    if hoverBtn = 7 showStats = !showStats return ok
    if hoverBtn = 8 debugView = !debugView return ok
    if hoverBtn = 10 eco_preset1() return ok
    if hoverBtn = 11 eco_preset2() return ok
    if hoverBtn = 12 eco_preset3() return ok
    if hoverBtn = 13 eco_reset() return ok
