/*
**  3D Maze Game - Using RingRayLib
**  ================================
**  A complete 3D maze game where you navigate a glowing sphere
**  through a procedurally generated maze with lighting effects.
**
**  Controls:
**    Arrow Keys / WASD  - Move the sphere
**    R                  - Restart with a new maze
**    ESC                - Exit
**
**  Features:
**    - Procedural maze generation (Recursive Backtracker algorithm)
**    - Smooth sphere movement with collision detection
**    - 3D camera following the player
**    - Atmospheric lighting with multiple colored lights
**    - Textured floor and walls with color variation
**    - Collectible gems scattered through the maze
**    - Timer and move counter HUD
**    - Win detection when reaching the exit
**    - Animated sphere (bobbing + rotation glow)
**    - Mini-map overlay
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_WIDTH    = 1024
SCREEN_HEIGHT   = 768
CELL_SIZE       = 4.0
WALL_HEIGHT     = 3.5
WALL_THICKNESS  = 0.3
SPHERE_RADIUS   = 0.5
MOVE_SPEED      = 0.06
MAZE_ROWS       = 12
MAZE_COLS       = 12

// Game states
STATE_PLAYING   = 1
STATE_WON       = 2
STATE_START     = 3

// Maze cell flags (bitmask for walls)
WALL_NORTH = 1      // top
WALL_SOUTH = 2      // bottom
WALL_EAST  = 4      // right
WALL_WEST  = 8      // left
CELL_VISITED = 16   // visited flag for generation

// =============================================================
// Global Variables
// =============================================================

// Maze grid: each cell stores a bitmask of walls
maze        = NULL
playerRow   = 1
playerCol   = 1
playerX     = 0.0
playerZ     = 0.0
targetX     = 0.0
targetZ     = 0.0
exitRow     = MAZE_ROWS
exitCol     = MAZE_COLS
gameState   = STATE_START
gameTime    = 0.0
moveCount   = 0
animTime    = 0.0

// Gem collection
gems        = []
gemsCollected = 0
totalGems   = 0

// =============================================================
// Main Program
// =============================================================

InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ring 3D Maze - RingRayLib")
SetTargetFPS(60)

// Setup camera (3rd person following player)
camera = Camera3D(
    0, 12, 8,              // position (will be updated)
    0, 0, 0,               // target (will be updated)
    0, 1, 0,               // up vector
    45,                     // FOV
    CAMERA_PERSPECTIVE      // projection
)

// Generate initial maze
generateMaze()
resetPlayer()

// =============================================================
// Main Game Loop
// =============================================================

while !WindowShouldClose()

    dt = GetFrameTime()
    animTime += dt

    // --- Handle restart ---
    if IsKeyPressed(KEY_R)
        generateMaze()
        resetPlayer()
        gameState = STATE_PLAYING
    ok

    // --- Handle start screen ---
    if gameState = STATE_START
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            gameState = STATE_PLAYING
        ok
    ok

    // --- Update game logic ---
    if gameState = STATE_PLAYING
        gameTime += dt
        updatePlayer()
        game_updateCamera()
        checkGemCollection()
        checkWinCondition()
    ok

    if gameState = STATE_WON
        game_updateCamera()  // keep camera alive
    ok

    // --- Draw ---
    BeginDrawing()
        ClearBackground(RAYLIBColor(15, 15, 25, 255))

        if gameState = STATE_START
            drawStartScreen()
        else
            BeginMode3D(camera)
                drawFloor()
                drawMazeWalls()
                drawExitMarker()
                drawGems()
                drawPlayer()
                drawLightIndicators()
            EndMode3D()

            drawHUD()
            drawMiniMap()

            if gameState = STATE_WON
                drawWinScreen()
            ok
        ok

        DrawFPS(10, 10)
    EndDrawing()

end

CloseWindow()

// =============================================================
// Maze Generation - Recursive Backtracker (iterative with stack)
// =============================================================

func generateMaze

    // Initialize maze: all walls present for each cell
    maze = list(MAZE_ROWS)
    for r = 1 to MAZE_ROWS
        maze[r] = list(MAZE_COLS)
        for c = 1 to MAZE_COLS
            maze[r][c] = WALL_NORTH | WALL_SOUTH | WALL_EAST | WALL_WEST
        next
    next

    // Stack-based iterative backtracker
    stack = []
    startR = 1
    startC = 1
    maze[startR][startC] = maze[startR][startC] | CELL_VISITED

    add(stack, [startR, startC])

    while len(stack) > 0
        current = stack[len(stack)]
        cr = current[1]
        cc = current[2]

        // Find unvisited neighbors
        neighbors = []
        // North
        if cr > 1
            if !(maze[cr-1][cc] & CELL_VISITED)
                add(neighbors, [cr-1, cc, WALL_NORTH, WALL_SOUTH])
            ok
        ok
        // South
        if cr < MAZE_ROWS
            if !(maze[cr+1][cc] & CELL_VISITED)
                add(neighbors, [cr+1, cc, WALL_SOUTH, WALL_NORTH])
            ok
        ok
        // East
        if cc < MAZE_COLS
            if !(maze[cr][cc+1] & CELL_VISITED)
                add(neighbors, [cr, cc+1, WALL_EAST, WALL_WEST])
            ok
        ok
        // West
        if cc > 1
            if !(maze[cr][cc-1] & CELL_VISITED)
                add(neighbors, [cr, cc-1, WALL_WEST, WALL_EAST])
            ok
        ok

        if len(neighbors) > 0
            // Pick a random neighbor
            idx = GetRandomValue(1, len(neighbors))
            chosen = neighbors[idx]
            nr = chosen[1]
            nc = chosen[2]
            wallCurrent = chosen[3]
            wallNeighbor = chosen[4]

            // Remove walls between current and chosen
            maze[cr][cc] = maze[cr][cc] & (~wallCurrent)
            maze[nr][nc] = maze[nr][nc] & (~wallNeighbor)

            // Mark neighbor as visited
            maze[nr][nc] = maze[nr][nc] | CELL_VISITED
            add(stack, [nr, nc])
        else
            // Backtrack
            del(stack, len(stack))
        ok
    end

    // Place gems in the maze (at random open cells)
    gems = []
    gemsCollected = 0
    totalGems = 0
    for r = 1 to MAZE_ROWS
        for c = 1 to MAZE_COLS
            // Skip start and exit cells
            if r = 1 and c = 1 loop ok
            if r = exitRow and c = exitCol loop ok
            // ~25% chance to place a gem
            if GetRandomValue(1, 4) = 1
                gx = (c - 1) * CELL_SIZE + CELL_SIZE / 2
                gz = (r - 1) * CELL_SIZE + CELL_SIZE / 2
                add(gems, [gx, gz, 1])  // x, z, active(1)/collected(0)
                totalGems++
            ok
        next
    next

// =============================================================
// Player Functions
// =============================================================

func resetPlayer
    playerRow = 1
    playerCol = 1
    playerX   = (playerCol - 1) * CELL_SIZE + CELL_SIZE / 2
    playerZ   = (playerRow - 1) * CELL_SIZE + CELL_SIZE / 2
    targetX   = playerX
    targetZ   = playerZ
    gameTime  = 0.0
    moveCount = 0
    gemsCollected = 0
    // Reset all gems to active
    for i = 1 to len(gems)
        gems[i][3] = 1
    next

func updatePlayer
    // Movement input
    dx = 0
    dz = 0

    if IsKeyDown(KEY_RIGHT) or IsKeyDown(KEY_D)    dx =  MOVE_SPEED ok
    if IsKeyDown(KEY_LEFT)  or IsKeyDown(KEY_A)     dx = -MOVE_SPEED ok
    if IsKeyDown(KEY_DOWN)  or IsKeyDown(KEY_S)     dz =  MOVE_SPEED ok
    if IsKeyDown(KEY_UP)    or IsKeyDown(KEY_W)     dz = -MOVE_SPEED ok

    if dx != 0 or dz != 0
        // Try to move with collision detection
        newX = playerX + dx
        newZ = playerZ + dz

        // Check collision with maze walls
        if !checkWallCollision(newX, playerZ)
            playerX = newX
        ok
        if !checkWallCollision(playerX, newZ)
            playerZ = newZ
        ok

        // Update grid position
        newCol = floor(playerX / CELL_SIZE) + 1
        newRow = floor(playerZ / CELL_SIZE) + 1
        if newCol < 1 newCol = 1 ok
        if newCol > MAZE_COLS newCol = MAZE_COLS ok
        if newRow < 1 newRow = 1 ok
        if newRow > MAZE_ROWS newRow = MAZE_ROWS ok

        if newRow != playerRow or newCol != playerCol
            moveCount++
        ok
        playerRow = newRow
        playerCol = newCol
    ok

func checkWallCollision px, pz
    // Calculate which cell the player is in
    col = floor(px / CELL_SIZE) + 1
    row = floor(pz / CELL_SIZE) + 1

    // Clamp to maze bounds (outer boundary collision)
    if px - SPHERE_RADIUS < 0 return true ok
    if pz - SPHERE_RADIUS < 0 return true ok
    if px + SPHERE_RADIUS > MAZE_COLS * CELL_SIZE return true ok
    if pz + SPHERE_RADIUS > MAZE_ROWS * CELL_SIZE return true ok

    if col < 1 or col > MAZE_COLS return true ok
    if row < 1 or row > MAZE_ROWS return true ok

    // Local position within the cell
    localX = px - (col - 1) * CELL_SIZE
    localZ = pz - (row - 1) * CELL_SIZE

    cellWalls = maze[row][col] & 0x0F   // mask out visited flag

    // Check north wall (top of cell, z = 0)
    if (cellWalls & WALL_NORTH)
        if localZ - SPHERE_RADIUS < WALL_THICKNESS
            return true
        ok
    ok

    // Check south wall (bottom of cell, z = CELL_SIZE)
    if (cellWalls & WALL_SOUTH)
        if localZ + SPHERE_RADIUS > CELL_SIZE - WALL_THICKNESS
            return true
        ok
    ok

    // Check west wall (left of cell, x = 0)
    if (cellWalls & WALL_WEST)
        if localX - SPHERE_RADIUS < WALL_THICKNESS
            return true
        ok
    ok

    // Check east wall (right of cell, x = CELL_SIZE)
    if (cellWalls & WALL_EAST)
        if localX + SPHERE_RADIUS > CELL_SIZE - WALL_THICKNESS
            return true
        ok
    ok

    return false

func checkGemCollection
    for i = 1 to len(gems)
        if gems[i][3] = 1  // active
            gx = gems[i][1]
            gz = gems[i][2]
            dist = sqrt((playerX - gx) * (playerX - gx) + (playerZ - gz) * (playerZ - gz))
            if dist < SPHERE_RADIUS + 0.4
                gems[i][3] = 0  // collect it
                gemsCollected++
            ok
        ok
    next

func checkWinCondition
    if playerRow = exitRow and playerCol = exitCol
        // Check if player is close to the exit center
        exitX = (exitCol - 1) * CELL_SIZE + CELL_SIZE / 2
        exitZ = (exitRow - 1) * CELL_SIZE + CELL_SIZE / 2
        dist = sqrt((playerX - exitX) * (playerX - exitX) + (playerZ - exitZ) * (playerZ - exitZ))
        if dist < CELL_SIZE / 2
            gameState = STATE_WON
        ok
    ok

// =============================================================
// Camera Update
// =============================================================

func game_updateCamera
    // Smooth follow camera behind and above the player
    camHeight = 10.0
    camDist   = 7.0

    camera.target.x   = playerX
    camera.target.y   = 0.5
    camera.target.z   = playerZ

    camera.position.x = playerX - 2.0
    camera.position.y = camHeight
    camera.position.z = playerZ + camDist

// =============================================================
// Drawing Functions
// =============================================================

func drawFloor
    // Draw a large textured ground plane
    floorW = MAZE_COLS * CELL_SIZE
    floorH = MAZE_ROWS * CELL_SIZE
    // Main floor
    DrawPlane(
        Vector3(floorW / 2, -0.01, floorH / 2),
        Vector2(floorW + 2, floorH + 2),
        RAYLIBColor(40, 45, 55, 255)
    )
    // Floor grid lines for visual texture
    for r = 0 to MAZE_ROWS
        z = r * CELL_SIZE
        DrawLine3D(
            Vector3(0, 0.0, z),
            Vector3(floorW, 0.0, z),
            RAYLIBColor(55, 60, 70, 255)
        )
    next
    for c = 0 to MAZE_COLS
        x = c * CELL_SIZE
        DrawLine3D(
            Vector3(x, 0.0, 0),
            Vector3(x, 0.0, floorH),
            RAYLIBColor(55, 60, 70, 255)
        )
    next

func drawMazeWalls
    for r = 1 to MAZE_ROWS
        for c = 1 to MAZE_COLS
            cellX = (c - 1) * CELL_SIZE
            cellZ = (r - 1) * CELL_SIZE
            cellWalls = maze[r][c] & 0x0F

            // Color variation based on position for visual interest
            rVal = 60 + ((r * 17 + c * 31) % 40)
            gVal = 70 + ((r * 23 + c * 13) % 35)
            bVal = 100 + ((r * 7 + c * 41) % 50)
            wallColor = RAYLIBColor(rVal, gVal, bVal, 255)
            wireColor = RAYLIBColor(rVal + 30, gVal + 30, bVal + 30, 255)

            wallY = WALL_HEIGHT / 2

            // North wall
            if (cellWalls & WALL_NORTH)
                DrawCube(
                    Vector3(cellX + CELL_SIZE/2, wallY, cellZ),
                    CELL_SIZE + WALL_THICKNESS, WALL_HEIGHT, WALL_THICKNESS,
                    wallColor
                )
                DrawCubeWires(
                    Vector3(cellX + CELL_SIZE/2, wallY, cellZ),
                    CELL_SIZE + WALL_THICKNESS, WALL_HEIGHT, WALL_THICKNESS,
                    wireColor
                )
            ok

            // South wall
            if (cellWalls & WALL_SOUTH)
                DrawCube(
                    Vector3(cellX + CELL_SIZE/2, wallY, cellZ + CELL_SIZE),
                    CELL_SIZE + WALL_THICKNESS, WALL_HEIGHT, WALL_THICKNESS,
                    wallColor
                )
                DrawCubeWires(
                    Vector3(cellX + CELL_SIZE/2, wallY, cellZ + CELL_SIZE),
                    CELL_SIZE + WALL_THICKNESS, WALL_HEIGHT, WALL_THICKNESS,
                    wireColor
                )
            ok

            // West wall
            if (cellWalls & WALL_WEST)
                DrawCube(
                    Vector3(cellX, wallY, cellZ + CELL_SIZE/2),
                    WALL_THICKNESS, WALL_HEIGHT, CELL_SIZE + WALL_THICKNESS,
                    wallColor
                )
                DrawCubeWires(
                    Vector3(cellX, wallY, cellZ + CELL_SIZE/2),
                    WALL_THICKNESS, WALL_HEIGHT, CELL_SIZE + WALL_THICKNESS,
                    wireColor
                )
            ok

            // East wall
            if (cellWalls & WALL_EAST)
                DrawCube(
                    Vector3(cellX + CELL_SIZE, wallY, cellZ + CELL_SIZE/2),
                    WALL_THICKNESS, WALL_HEIGHT, CELL_SIZE + WALL_THICKNESS,
                    wallColor
                )
                DrawCubeWires(
                    Vector3(cellX + CELL_SIZE, wallY, cellZ + CELL_SIZE/2),
                    WALL_THICKNESS, WALL_HEIGHT, CELL_SIZE + WALL_THICKNESS,
                    wireColor
                )
            ok

            // Add small pillars at cell corners for visual richness
            if r = 1 and c = 1
                drawPillar(cellX, cellZ)
            ok
            if r = 1
                drawPillar(cellX + CELL_SIZE, cellZ)
            ok
            if c = 1
                drawPillar(cellX, cellZ + CELL_SIZE)
            ok
            drawPillar(cellX + CELL_SIZE, cellZ + CELL_SIZE)
        next
    next

func drawPillar x, z
    DrawCube(
        Vector3(x, WALL_HEIGHT / 2, z),
        WALL_THICKNESS * 2, WALL_HEIGHT + 0.2, WALL_THICKNESS * 2,
        RAYLIBColor(80, 85, 110, 255)
    )

func drawPlayer
    // Bobbing animation
    bobY = SPHERE_RADIUS + 0.05 + sin(animTime * 3.0) * 0.1

    // Main sphere - golden color
    DrawSphereEx(
        Vector3(playerX, bobY, playerZ),
        SPHERE_RADIUS, 16, 16,
        RAYLIBColor(255, 200, 50, 255)
    )

    // Outer glow sphere (slightly larger, semi-transparent)
    glowSize = SPHERE_RADIUS + 0.08 + sin(animTime * 5.0) * 0.03
    DrawSphereEx(
        Vector3(playerX, bobY, playerZ),
        glowSize, 12, 12,
        RAYLIBColor(255, 220, 80, 80)
    )

    // Wire overlay for detail
    DrawSphereWires(
        Vector3(playerX, bobY, playerZ),
        SPHERE_RADIUS + 0.01, 8, 8,
        RAYLIBColor(255, 160, 0, 120)
    )

    // Ground glow circle beneath the player
    DrawCircle3D(
        Vector3(playerX, 0.02, playerZ),
        SPHERE_RADIUS + 0.3 + sin(animTime * 4.0) * 0.1,
        Vector3(1, 0, 0), 90.0,
        RAYLIBColor(255, 200, 50, 60)
    )

func drawExitMarker
    exitX = (exitCol - 1) * CELL_SIZE + CELL_SIZE / 2
    exitZ = (exitRow - 1) * CELL_SIZE + CELL_SIZE / 2

    // Pulsing green column at the exit
    pulseH = 2.0 + sin(animTime * 2.0) * 0.5
    DrawCylinder(
        Vector3(exitX, 0, exitZ),
        0.0, 0.8, pulseH, 8,
        RAYLIBColor(0, 255, 100, 120)
    )
    DrawCylinderWires(
        Vector3(exitX, 0, exitZ),
        0.0, 0.8, pulseH, 8,
        RAYLIBColor(0, 255, 150, 200)
    )

    // Spinning ring around the exit
    DrawCircle3D(
        Vector3(exitX, 1.0 + sin(animTime * 1.5) * 0.3, exitZ),
        1.0, Vector3(0, 1, 0), animTime * 90,
        RAYLIBColor(0, 255, 120, 200)
    )
    DrawCircle3D(
        Vector3(exitX, 1.5 + sin(animTime * 1.5 + 1.5) * 0.3, exitZ),
        0.7, Vector3(1, 0, 0), animTime * 120,
        RAYLIBColor(100, 255, 100, 150)
    )

func drawGems
    for i = 1 to len(gems)
        if gems[i][3] = 1  // active gem
            gx = gems[i][1]
            gz = gems[i][2]
            gy = 0.6 + sin(animTime * 3.0 + i * 0.7) * 0.15

            // Gem diamond shape: two cones
            DrawCylinder(
                Vector3(gx, gy - 0.2, gz),
                0.0, 0.25, 0.25, 4,
                RAYLIBColor(0, 180, 255, 220)
            )
            DrawCylinder(
                Vector3(gx, gy + 0.05, gz),
                0.25, 0.0, 0.25, 4,
                RAYLIBColor(100, 220, 255, 220)
            )
            // Wire highlight
            DrawCylinderWires(
                Vector3(gx, gy - 0.2, gz),
                0.0, 0.27, 0.25, 4,
                RAYLIBColor(150, 240, 255, 255)
            )
        ok
    next

func drawLightIndicators
    // Draw small glowing spheres at key locations to simulate light sources
    // Placed at the four corners and center of the maze
    mazeW = MAZE_COLS * CELL_SIZE
    mazeH = MAZE_ROWS * CELL_SIZE

    drawLightOrb(2, WALL_HEIGHT + 1.0, 2, 220, 200, 150)
    drawLightOrb(mazeW - 2, WALL_HEIGHT + 1.0, 2, 150, 200, 220)
    drawLightOrb(2, WALL_HEIGHT + 1.0, mazeH - 2, 200, 150, 220)
    drawLightOrb(mazeW - 2, WALL_HEIGHT + 1.0, mazeH - 2, 220, 150, 150)
    drawLightOrb(mazeW/2, WALL_HEIGHT + 2.0, mazeH/2, 255, 240, 200)

func drawLightOrb x, y, z, r, g, b
    DrawSphere(Vector3(x, y, z), 0.2, RAYLIBColor(r, g, b, 255))
    DrawSphereEx(
        Vector3(x, y, z), 0.5, 8, 8,
        RAYLIBColor(r, g, b, 40)
    )

// =============================================================
// HUD Drawing
// =============================================================

func drawHUD
    // Semi-transparent background panel
    DrawRectangle(10, 30, 260, 115, Fade(BLACK, 0.7))
    DrawRectangleLines(10, 30, 260, 115, RAYLIBColor(100, 180, 255, 200))

    // Title
    DrawText("3D MAZE", 20, 38, 20, RAYLIBColor(255, 200, 50, 255))

    // Timer
    minutes = floor(gameTime / 60)
    seconds = floor(gameTime) % 60
    timerText = "" + minutes + ":" 
    if seconds < 10 timerText += "0" ok
    timerText += seconds
    DrawText("Time: " + timerText, 20, 65, 16, RAYLIBColor(200, 220, 255, 255))

    // Move counter
    DrawText("Moves: " + moveCount, 20, 85, 16, RAYLIBColor(200, 220, 255, 255))

    // Gems
    DrawText("Gems: " + gemsCollected + "/" + totalGems, 20, 105, 16, RAYLIBColor(100, 220, 255, 255))

    // Position info
    DrawText("Cell: [" + playerRow + "," + playerCol + "]", 20, 125, 12, RAYLIBColor(150, 150, 180, 200))

    // Controls hint at bottom
    DrawRectangle(SCREEN_WIDTH - 260, SCREEN_HEIGHT - 35, 250, 25, Fade(BLACK, 0.6))
    DrawText("WASD/Arrows: Move | R: Restart", SCREEN_WIDTH - 255, SCREEN_HEIGHT - 30, 14,
             RAYLIBColor(180, 180, 200, 200))

func drawMiniMap
    // Mini-map in the top-right corner
    mapSize   = 150
    mapX      = SCREEN_WIDTH - mapSize - 15
    mapY      = 30
    cellW     = mapSize / MAZE_COLS
    cellH     = mapSize / MAZE_ROWS

    // Background
    DrawRectangle(mapX - 2, mapY - 2, mapSize + 4, mapSize + 4, Fade(BLACK, 0.8))
    DrawRectangleLines(mapX - 2, mapY - 2, mapSize + 4, mapSize + 4, RAYLIBColor(100, 180, 255, 200))

    // Draw maze cells and walls
    for r = 1 to MAZE_ROWS
        for c = 1 to MAZE_COLS
            cx = mapX + (c - 1) * cellW
            cy = mapY + (r - 1) * cellH
            cellWalls = maze[r][c] & 0x0F

            // Cell background
            DrawRectangle(cx, cy, cellW, cellH, RAYLIBColor(30, 35, 45, 200))

            // Draw walls as lines
            wallCol = RAYLIBColor(100, 130, 180, 255)
            if (cellWalls & WALL_NORTH)
                DrawLine(cx, cy, cx + cellW, cy, wallCol)
            ok
            if (cellWalls & WALL_SOUTH)
                DrawLine(cx, cy + cellH, cx + cellW, cy + cellH, wallCol)
            ok
            if (cellWalls & WALL_WEST)
                DrawLine(cx, cy, cx, cy + cellH, wallCol)
            ok
            if (cellWalls & WALL_EAST)
                DrawLine(cx + cellW, cy, cx + cellW, cy + cellH, wallCol)
            ok
        next
    next

    // Draw gems on minimap
    for i = 1 to len(gems)
        if gems[i][3] = 1
            gc = floor(gems[i][1] / CELL_SIZE) + 1
            gr = floor(gems[i][2] / CELL_SIZE) + 1
            gmx = mapX + (gc - 1) * cellW + cellW / 2
            gmy = mapY + (gr - 1) * cellH + cellH / 2
            DrawCircle(gmx, gmy, 2, RAYLIBColor(0, 200, 255, 200))
        ok
    next

    // Draw exit on minimap
    ex = mapX + (exitCol - 1) * cellW + cellW / 2
    ey = mapY + (exitRow - 1) * cellH + cellH / 2
    DrawCircle(ex, ey, 4, RAYLIBColor(0, 255, 100, 255))

    // Draw player on minimap
    px = mapX + (playerX / (MAZE_COLS * CELL_SIZE)) * mapSize
    py = mapY + (playerZ / (MAZE_ROWS * CELL_SIZE)) * mapSize
    DrawCircle(px, py, 3, RAYLIBColor(255, 200, 50, 255))
    // Pulsing ring around player dot
    DrawCircleLines(px, py, 5 + sin(animTime * 4) * 2, RAYLIBColor(255, 200, 50, 150))

    // Label
    DrawText("MAP", mapX + mapSize/2 - 15, mapY - 15, 12, RAYLIBColor(200, 220, 255, 200))

// =============================================================
// Screens
// =============================================================

func drawStartScreen
    // Dark background with gradient feel
    DrawRectangleGradientV(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,
        RAYLIBColor(10, 10, 30, 255), RAYLIBColor(20, 30, 60, 255))

    // Title
    titleText = "3D MAZE GAME"
    titleW = MeasureText(titleText, 60)
    DrawText(titleText, (SCREEN_WIDTH - titleW)/2, 180, 60, RAYLIBColor(255, 200, 50, 255))

    // Subtitle
    subText = "Navigate the golden sphere to the green exit!"
    subW = MeasureText(subText, 20)
    DrawText(subText, (SCREEN_WIDTH - subW)/2, 260, 20, RAYLIBColor(180, 200, 220, 255))

    // Controls info
    cText1 = "Controls: WASD or Arrow Keys to move"
    cText2 = "Collect blue gems for bonus points"
    cText3 = "R to generate a new maze"
    c1W = MeasureText(cText1, 18)
    c2W = MeasureText(cText2, 18)
    c3W = MeasureText(cText3, 18)
    DrawText(cText1, (SCREEN_WIDTH - c1W)/2, 320, 18, RAYLIBColor(150, 170, 200, 255))
    DrawText(cText2, (SCREEN_WIDTH - c2W)/2, 348, 18, RAYLIBColor(100, 200, 255, 255))
    DrawText(cText3, (SCREEN_WIDTH - c3W)/2, 376, 18, RAYLIBColor(150, 170, 200, 255))

    // Blinking start prompt
    if floor(animTime * 2) % 2 = 0
        startText = "Press ENTER or SPACE to Start"
        stW = MeasureText(startText, 24)
        DrawText(startText, (SCREEN_WIDTH - stW)/2, 460, 24, RAYLIBColor(255, 255, 255, 255))
    ok

    // Credits
    credText = "Developed using Ring Language + RingRayLib"
    crW = MeasureText(credText, 14)
    DrawText(credText, (SCREEN_WIDTH - crW)/2, SCREEN_HEIGHT - 40, 14, RAYLIBColor(120, 120, 150, 200))

func drawWinScreen
    // Overlay
    DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, Fade(BLACK, 0.6))

    // Win message
    winText = "MAZE COMPLETED!"
    winW = MeasureText(winText, 50)
    DrawText(winText, (SCREEN_WIDTH - winW)/2, 200, 50, RAYLIBColor(0, 255, 100, 255))

    // Stats
    minutes = floor(gameTime / 60)
    seconds = floor(gameTime) % 60
    timeStr = "" + minutes + ":"
    if seconds < 10 timeStr += "0" ok
    timeStr += seconds

    statY = 280
    stat1 = "Time: " + timeStr
    stat2 = "Moves: " + moveCount
    stat3 = "Gems Collected: " + gemsCollected + "/" + totalGems

    s1W = MeasureText(stat1, 24)
    s2W = MeasureText(stat2, 24)
    s3W = MeasureText(stat3, 24)

    DrawText(stat1, (SCREEN_WIDTH - s1W)/2, statY, 24, RAYLIBColor(200, 220, 255, 255))
    DrawText(stat2, (SCREEN_WIDTH - s2W)/2, statY + 35, 24, RAYLIBColor(200, 220, 255, 255))
    DrawText(stat3, (SCREEN_WIDTH - s3W)/2, statY + 70, 24, RAYLIBColor(100, 220, 255, 255))

    // Score calculation
    score = 1000 - moveCount + gemsCollected * 50 - floor(gameTime)
    if score < 0 score = 0 ok
    scoreText = "Score: " + score
    scW = MeasureText(scoreText, 30)
    DrawText(scoreText, (SCREEN_WIDTH - scW)/2, statY + 120, 30, RAYLIBColor(255, 200, 50, 255))

    // Restart prompt
    if floor(animTime * 2) % 2 = 0
        rText = "Press R for a new maze"
        rW = MeasureText(rText, 20)
        DrawText(rText, (SCREEN_WIDTH - rW)/2, statY + 180, 20, WHITE)
    ok
