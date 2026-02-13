/*
**  ld_level.ring
**  Level building, room construction, map model generation
*/

func ld_loadLevel num
    doors = []
    puzzlePanels = []
    puzzParticles = []

    // Init empty map
    for r = 1 to MAP_H
        for c = 1 to MAP_W
            map[r][c] = T_EMPTY
        next
    next

    // Border walls
    for i = 1 to MAP_W
        map[1][i] = T_WALL1
        map[MAP_H][i] = T_WALL1
    next
    for i = 1 to MAP_H
        map[i][1] = T_WALL1
        map[i][MAP_W] = T_WALL1
    next

    ld_buildSingleLevel()

    // Generate cubicmap model from map array for textured rendering
    ld_buildMapModel()

// =============================================================
// Single Level: 16 rooms, 15 doors, all 15 puzzles

// =============================================================
// Linear dungeon with paired puzzles - NO overlapping rooms
//
// Snake path through 40x40 map:
//
//   Room1 ─[1,2]─→ Room2 ─[3,4]─→ Room3
//   r2-11,c2-10     r2-11,c10-25    r2-11,c25-38
//                                       │ [5,6]
//   Room5 ←[7,8]─ Room4 ←──────────────┘
//   r11-20,c2-11   r11-20,c11-38
//      │ [9,10]
//   Room6 ─[11,12]─→ Room7 ─[13,14]─→ Room8
//   r20-29,c2-15      r20-29,c15-28     r20-29,c28-38
//                                           │ [15]
//                    Room9(victory) ←───────┘
//                    r29-38,c28-38
// =============================================================

func ld_buildSingleLevel

    // === Room 1 (Start) ===
    ld_roomWalls(2, 2, 11, 10, T_WALL2)
    map[5][6] = T_WALL3
    map[8][6] = T_WALL3

    // === Room 2 ===
    ld_roomWalls(2, 10, 11, 25, T_WALL1)
    map[5][15] = T_WALL3
    map[5][20] = T_WALL3
    map[8][15] = T_WALL3
    map[8][20] = T_WALL3

    // Puzzles 1 & 2: Room1 east → Room2
    map[4][10] = T_DOOR
    map[5][10] = T_DOOR
    add(doors, [4, 10, 0.0, 1, false])
    add(doors, [5, 10, 0.0, 1, false])
    add(puzzlePanels, [4, 9, 3, 1, 1])

    map[8][10] = T_DOOR
    map[9][10] = T_DOOR
    add(doors, [8, 10, 0.0, 2, false])
    add(doors, [9, 10, 0.0, 2, false])
    add(puzzlePanels, [8, 9, 3, 3, 2])

    // === Room 3 ===
    ld_roomWalls(2, 25, 11, 38, T_WALL2)
    map[5][30] = T_WALL3
    map[5][35] = T_WALL3
    map[8][30] = T_WALL3
    map[8][35] = T_WALL3

    // Puzzles 3 & 4: Room2 east → Room3
    map[4][25] = T_DOOR
    map[5][25] = T_DOOR
    add(doors, [4, 25, 0.0, 3, false])
    add(doors, [5, 25, 0.0, 3, false])
    add(puzzlePanels, [4, 24, 3, 5, 3])

    map[8][25] = T_DOOR
    map[9][25] = T_DOOR
    add(doors, [8, 25, 0.0, 4, false])
    add(doors, [9, 25, 0.0, 4, false])
    add(puzzlePanels, [8, 24, 3, 7, 4])

    // === Room 4 ===
    ld_roomWalls(11, 11, 20, 38, T_WALL3)
    map[14][18] = T_WALL3
    map[14][25] = T_WALL3
    map[14][32] = T_WALL3
    map[17][18] = T_WALL3
    map[17][25] = T_WALL3
    map[17][32] = T_WALL3

    // Puzzles 5 & 6: Room3 south → Room4 (shared row 11)
    map[11][30] = T_DOOR
    map[11][31] = T_DOOR
    add(doors, [11, 30, 0.0, 5, false])
    add(doors, [11, 31, 0.0, 5, false])
    add(puzzlePanels, [10, 30, 2, 9, 5])

    map[11][35] = T_DOOR
    map[11][36] = T_DOOR
    add(doors, [11, 35, 0.0, 6, false])
    add(doors, [11, 36, 0.0, 6, false])
    add(puzzlePanels, [10, 35, 2, 11, 6])

    // === Room 5 ===
    ld_roomWalls(11, 2, 20, 11, T_WALL1)
    map[14][6] = T_WALL3
    map[17][6] = T_WALL3

    // Puzzles 7 & 8: Room4 west → Room5 (shared col 11)
    map[14][11] = T_DOOR
    map[15][11] = T_DOOR
    add(doors, [14, 11, 0.0, 7, false])
    add(doors, [15, 11, 0.0, 7, false])
    add(puzzlePanels, [14, 12, 4, 13, 7])

    map[17][11] = T_DOOR
    map[18][11] = T_DOOR
    add(doors, [17, 11, 0.0, 8, false])
    add(doors, [18, 11, 0.0, 8, false])
    add(puzzlePanels, [17, 12, 4, 15, 8])

    // === Room 6 ===
    ld_roomWalls(20, 2, 29, 15, T_WALL2)
    map[23][6] = T_WALL3
    map[23][11] = T_WALL3
    map[26][6] = T_WALL3
    map[26][11] = T_WALL3

    // Puzzles 9 & 10: Room5 south → Room6 (shared row 20)
    map[20][4] = T_DOOR
    map[20][5] = T_DOOR
    add(doors, [20, 4, 0.0, 9, false])
    add(doors, [20, 5, 0.0, 9, false])
    add(puzzlePanels, [19, 4, 2, 17, 9])

    map[20][8] = T_DOOR
    map[20][9] = T_DOOR
    add(doors, [20, 8, 0.0, 10, false])
    add(doors, [20, 9, 0.0, 10, false])
    add(puzzlePanels, [19, 8, 2, 19, 10])

    // === Room 7 ===
    ld_roomWalls(20, 15, 29, 28, T_WALL3)
    map[23][20] = T_WALL3
    map[23][24] = T_WALL3
    map[26][20] = T_WALL3
    map[26][24] = T_WALL3

    // Puzzles 11 & 12: Room6 east → Room7 (shared col 15)
    map[23][15] = T_DOOR
    map[24][15] = T_DOOR
    add(doors, [23, 15, 0.0, 11, false])
    add(doors, [24, 15, 0.0, 11, false])
    add(puzzlePanels, [23, 14, 3, 21, 11])

    map[26][15] = T_DOOR
    map[27][15] = T_DOOR
    add(doors, [26, 15, 0.0, 12, false])
    add(doors, [27, 15, 0.0, 12, false])
    add(puzzlePanels, [26, 14, 3, 23, 12])

    // === Room 8 ===
    ld_roomWalls(20, 28, 29, 38, T_WALL1)
    map[23][33] = T_WALL3
    map[26][33] = T_WALL3

    // Puzzles 13 & 14: Room7 east → Room8 (shared col 28)
    map[23][28] = T_DOOR
    map[24][28] = T_DOOR
    add(doors, [23, 28, 0.0, 13, false])
    add(doors, [24, 28, 0.0, 13, false])
    add(puzzlePanels, [23, 27, 3, 25, 13])

    map[26][28] = T_DOOR
    map[27][28] = T_DOOR
    add(doors, [26, 28, 0.0, 14, false])
    add(doors, [27, 28, 0.0, 14, false])
    add(puzzlePanels, [26, 27, 3, 27, 14])

    // === Room 9 (Victory) ===
    ld_roomWalls(29, 28, 38, 38, T_WALL2)
    map[33][33] = T_WALL3

    // Puzzle 15: Room8 south → Room9 (shared row 29)
    map[29][32] = T_DOOR
    map[29][33] = T_DOOR
    add(doors, [29, 32, 0.0, 15, false])
    add(doors, [29, 33, 0.0, 15, false])
    add(puzzlePanels, [28, 32, 2, 29, 15])

    // === Room Bounds (for minimap highlight) ===
    // Format: [r1, c1, r2, c2] (top-left to bottom-right)
    roomBounds = [
        [2, 2, 11, 10],      // Room 1
        [2, 10, 11, 25],     // Room 2
        [2, 25, 11, 38],     // Room 3
        [11, 11, 20, 38],    // Room 4
        [11, 2, 20, 11],     // Room 5
        [20, 2, 29, 15],     // Room 6
        [20, 15, 29, 28],    // Room 7
        [20, 28, 29, 38],    // Room 8
        [29, 28, 38, 38]     // Room 9
    ]

    // === Sphere Collectibles ===
    // Place 2-3 spheres per room, each with a unique type
    // Format: [row, col, type(0-9), collected(false), bobPhase(random)]
    sphereList = []

    // Room 1 (start)
    add(sphereList, [5, 4, 0, false, 0.0])     // white
    add(sphereList, [8, 7, 1, false, 1.2])     // purple

    // Room 2
    add(sphereList, [5, 14, 2, false, 0.5])    // black
    add(sphereList, [8, 18, 0, false, 1.8])    // white (was 8,20 - wall)
    add(sphereList, [4, 22, 1, false, 2.5])    // purple

    // Room 3
    add(sphereList, [5, 32, 2, false, 0.3])    // black (was 5,30 - wall)
    add(sphereList, [8, 34, 0, false, 1.6])    // white
    add(sphereList, [4, 36, 1, false, 2.1])    // purple

    // Room 4 (large)
    add(sphereList, [15, 18, 2, false, 0.7])   // black
    add(sphereList, [18, 28, 0, false, 1.4])   // white
    add(sphereList, [15, 34, 1, false, 2.8])   // purple

    // Room 5
    add(sphereList, [15, 5, 0, false, 0.9])    // white
    add(sphereList, [18, 7, 2, false, 2.2])    // black

    // Room 6
    add(sphereList, [23, 8, 1, false, 0.4])    // purple (was 23,6 - wall)
    add(sphereList, [27, 10, 0, false, 1.7])   // white
    add(sphereList, [25, 4, 2, false, 2.6])    // black

    // Room 7
    add(sphereList, [23, 22, 1, false, 0.8])   // purple (was 23,20 - wall)
    add(sphereList, [27, 24, 0, false, 1.5])   // white
    add(sphereList, [25, 18, 2, false, 2.3])   // black

    // Room 8
    add(sphereList, [23, 35, 1, false, 0.6])   // purple
    add(sphereList, [27, 35, 0, false, 1.9])   // white
    add(sphereList, [25, 32, 2, false, 0.2])   // black (moved from Room 9)

    // Player start - center of Room 1
    pX = 6.0
    pZ = 6.5
    camYaw = 0.0
    camPitch = 0.0

// =============================================================
// Room Wall Helper - draws walls for a rectangular room
// Shared walls with adjacent rooms are only drawn if empty
// =============================================================

func ld_roomWalls r1, c1, r2, c2, wallType
    // Top and bottom walls
    for c = c1 to c2
        if map[r1][c] = T_EMPTY map[r1][c] = wallType ok
        if map[r2][c] = T_EMPTY map[r2][c] = wallType ok
    next
    // Left and right walls
    for r = r1 to r2
        if map[r][c1] = T_EMPTY map[r][c1] = wallType ok
        if map[r][c2] = T_EMPTY map[r][c2] = wallType ok
    next

// =============================================================
// Build Map Model (cubicmap from map array)
// =============================================================
func ld_buildMapModel
    // Unload previous model if exists
    if hasMapModel
        UnloadModel(mapModel)
        UnloadTexture(mapTexture)
        hasMapModel = false
    ok

    // Create image from map array
    // White pixels = walls, Black pixels = empty
    mapImage = GenImageColor(MAP_W, MAP_H, BLACK)

    for r = 1 to MAP_H
        for c = 1 to MAP_W
            t = map[r][c]
            if t = T_WALL1 or t = T_WALL2 or t = T_WALL3
                ImageDrawPixel(mapImage, c - 1, r - 1, WHITE)
            ok
        next
    next

    // Create texture from image for minimap display
    mapTexture = LoadTextureFromImage(mapImage)

    // Generate 3D mesh from cubicmap
    mesh = GenMeshCubicmap(mapImage, Vector3(1.0, 1.0, 1.0))
    mapModel = LoadModelFromMesh(mesh)

    // Apply the texture atlas
    SetModelMaterialTexture(mapModel, 0, MAP_DIFFUSE, texWall)

    // Position: cubicmap pixel(c-1, r-1) generates cube at (c-1, 0, r-1)
    // Our world: map[r][c] should be at (c-0.5, 0.5, r-0.5)
    // GenMeshCubicmap cubes are 1x1x1, centered at y=0.5
    // So cube at pixel(0,0) is at world (0, 0.5, 0)
    // We need it at (0.5, 0.5, 0.5), so offset = (0.5, 0, 0.5)
    mapModelPos = Vector3(0.5, 0.0, 0.5)

    UnloadImage(mapImage)
    hasMapModel = true

