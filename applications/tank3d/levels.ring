/*
**  tank3d_levels.ring
**  Level loading and all 12 level definitions
*/

// =============================================================
// Level Loading
// =============================================================

func tank_loadLevel lvl
    // Reset state
    palive = true
    pshield = 2.0   // Brief spawn shield
    pspeedBoost = 0.0
    pdir = DIR_UP
    pbullets = []
    enemies = []
    ebullets = []
    explosions = []
    powerups = []
    particles = []
    enemiesKilled = 0
    enemySpawnTimer = 1.0
    espawnIdx = 1

    // Initialize grid
    tiles = list(GRID_H)
    for r = 1 to GRID_H
        tiles[r] = list(GRID_W)
        for c = 1 to GRID_W
            tiles[r][c] = T_EMPTY
        next
    next

    // Player start position (just above base)
    px = 9.0
    py = 23.0

    // Base (bottom center) - 2x2
    baseR = 25
    baseC = 13
    tiles[25][13] = T_BASE
    tiles[25][14] = T_BASE
    tiles[26][13] = T_BASE
    tiles[26][14] = T_BASE

    // Surround base with bricks
    for c = 12 to 15
        tiles[24][c] = T_BRICK
    next
    tiles[25][12] = T_BRICK
    tiles[26][12] = T_BRICK
    tiles[25][15] = T_BRICK
    tiles[26][15] = T_BRICK

    // Reset new systems
    comboCount = 0
    comboTimer = 0.0
    comboDisplayTimer = 0.0
    shakeTimer = 0.0
    globalFreezeTimer = 0.0
    lavaDamageTimer = 0.0
    pFireCooldown = 0.0

    // Difficulty scaling
    levelEnemyCount = 18 + lvl * 2
    if lvl > 8 levelEnemyCount = 30 + lvl ok
    enemiesLeft = levelEnemyCount
    levelMaxOnScreen = 4
    if lvl > 4 levelMaxOnScreen = 5 ok
    if lvl > 8 levelMaxOnScreen = 6 ok

    // Build level
    if lvl = 1 tank_buildLevel1()
    but lvl = 2 tank_buildLevel2()
    but lvl = 3 tank_buildLevel3()
    but lvl = 4 tank_buildLevel4()
    but lvl = 5 tank_buildLevel5()
    but lvl = 6 tank_buildLevel6()
    but lvl = 7 tank_buildLevel7()
    but lvl = 8 tank_buildLevel8()
    but lvl = 9 tank_buildLevel9()
    but lvl = 10 tank_buildLevel10()
    but lvl = 11 tank_buildLevel11()
    but lvl = 12 tank_buildLevel12()
    ok

// =============================================================
// Level 1: Boot Camp - Simple intro, mostly bricks
// =============================================================

func tank_buildLevel1
    // Brick clusters
    for r = 3 to 6
        for c = 3 to 4
            tiles[r][c] = T_BRICK
        next
        for c = 7 to 8
            tiles[r][c] = T_BRICK
        next
        for c = 11 to 12
            tiles[r][c] = T_BRICK
        next
        for c = 15 to 16
            tiles[r][c] = T_BRICK
        next
        for c = 19 to 20
            tiles[r][c] = T_BRICK
        next
        for c = 23 to 24
            tiles[r][c] = T_BRICK
        next
    next

    // Middle section
    for r = 9 to 12
        for c = 3 to 4
            tiles[r][c] = T_BRICK
        next
        for c = 7 to 8
            tiles[r][c] = T_BRICK
        next
        for c = 11 to 14
            tiles[r][c] = T_BRICK
        next
        for c = 19 to 20
            tiles[r][c] = T_BRICK
        next
        for c = 23 to 24
            tiles[r][c] = T_BRICK
        next
    next

    // Lower section
    for r = 15 to 18
        for c = 3 to 4
            tiles[r][c] = T_BRICK
        next
        for c = 7 to 8
            tiles[r][c] = T_BRICK
        next
        for c = 15 to 16
            tiles[r][c] = T_BRICK
        next
        for c = 19 to 20
            tiles[r][c] = T_BRICK
        next
        for c = 23 to 24
            tiles[r][c] = T_BRICK
        next
    next

    // Bottom walls near base
    for r = 21 to 22
        for c = 3 to 4
            tiles[r][c] = T_BRICK
        next
        for c = 7 to 8
            tiles[r][c] = T_BRICK
        next
        for c = 19 to 20
            tiles[r][c] = T_BRICK
        next
        for c = 23 to 24
            tiles[r][c] = T_BRICK
        next
    next

// =============================================================
// Level 2: Steel Intro - Steel walls introduced
// =============================================================

func tank_buildLevel2
    // Brick patterns
    for r = 3 to 6
        for c = 3 to 4
            tiles[r][c] = T_BRICK
        next
        for c = 9 to 10
            tiles[r][c] = T_BRICK
        next
        for c = 17 to 18
            tiles[r][c] = T_BRICK
        next
        for c = 23 to 24
            tiles[r][c] = T_BRICK
        next
    next

    // Steel barriers
    for r = 5 to 6
        tiles[r][13] = T_STEEL
        tiles[r][14] = T_STEEL
    next

    // Middle
    for r = 9 to 12
        for c = 3 to 4
            tiles[r][c] = T_BRICK
        next
        for c = 7 to 8
            tiles[r][c] = T_STEEL
        next
        for c = 12 to 15
            tiles[r][c] = T_BRICK
        next
        for c = 19 to 20
            tiles[r][c] = T_STEEL
        next
        for c = 23 to 24
            tiles[r][c] = T_BRICK
        next
    next

    // Water
    for r = 13 to 14
        for c = 9 to 10
            tiles[r][c] = T_WATER
        next
        for c = 17 to 18
            tiles[r][c] = T_WATER
        next
    next

    // Lower
    for r = 16 to 19
        for c = 3 to 4
            tiles[r][c] = T_BRICK
        next
        for c = 9 to 10
            tiles[r][c] = T_BRICK
        next
        for c = 17 to 18
            tiles[r][c] = T_BRICK
        next
        for c = 23 to 24
            tiles[r][c] = T_BRICK
        next
    next

    for r = 21 to 22
        for c = 7 to 8
            tiles[r][c] = T_BRICK
        next
        for c = 19 to 20
            tiles[r][c] = T_BRICK
        next
    next

// =============================================================
// Level 3: Wetlands - More water, ice, trees
// =============================================================

func tank_buildLevel3
    // Top section
    for r = 3 to 5
        for c = 2 to 3
            tiles[r][c] = T_BRICK
        next
        for c = 6 to 7
            tiles[r][c] = T_STEEL
        next
        for c = 11 to 12
            tiles[r][c] = T_BRICK
        next
        for c = 15 to 16
            tiles[r][c] = T_BRICK
        next
        for c = 20 to 21
            tiles[r][c] = T_STEEL
        next
        for c = 24 to 25
            tiles[r][c] = T_BRICK
        next
    next

    // Water moat middle
    for c = 5 to 8
        tiles[8][c] = T_WATER
        tiles[9][c] = T_WATER
    next
    for c = 19 to 22
        tiles[8][c] = T_WATER
        tiles[9][c] = T_WATER
    next

    // Central bricks
    for r = 7 to 10
        for c = 12 to 15
            tiles[r][c] = T_BRICK
        next
    next

    // Ice patches
    for c = 9 to 11
        tiles[12][c] = T_ICE
        tiles[13][c] = T_ICE
    next
    for c = 16 to 18
        tiles[12][c] = T_ICE
        tiles[13][c] = T_ICE
    next

    // Trees
    for r = 11 to 13
        for c = 3 to 4
            tiles[r][c] = T_TREES
        next
        for c = 23 to 24
            tiles[r][c] = T_TREES
        next
    next

    // Lower brick walls
    for r = 15 to 18
        for c = 5 to 6
            tiles[r][c] = T_BRICK
        next
        for c = 10 to 11
            tiles[r][c] = T_BRICK
        next
        for c = 16 to 17
            tiles[r][c] = T_BRICK
        next
        for c = 21 to 22
            tiles[r][c] = T_BRICK
        next
    next

    // Near base
    for r = 21 to 22
        for c = 5 to 6
            tiles[r][c] = T_BRICK
        next
        for c = 21 to 22
            tiles[r][c] = T_BRICK
        next
    next

// =============================================================
// Level 4: BOSS - Fortress (Heavy steel and water)
// =============================================================

func tank_buildLevel4
    // Steel fortress top - leave gaps at spawn columns (4, 13, 22)
    for r = 2 to 4
        tiles[r][5] = T_STEEL
        tiles[r][6] = T_STEEL
        for c = 11 to 12
            tiles[r][c] = T_STEEL
        next
        for c = 14 to 16
            tiles[r][c] = T_STEEL
        next
        tiles[r][21] = T_STEEL
        tiles[r][23] = T_STEEL
    next

    // Brick maze
    for r = 6 to 9
        for c = 2 to 3
            tiles[r][c] = T_BRICK
        next
        for c = 6 to 9
            tiles[r][c] = T_BRICK
        next
        for c = 18 to 21
            tiles[r][c] = T_BRICK
        next
        for c = 24 to 25
            tiles[r][c] = T_BRICK
        next
    next

    // Central water cross
    for r = 10 to 17
        tiles[r][13] = T_WATER
        tiles[r][14] = T_WATER
    next
    for c = 8 to 19
        tiles[13][c] = T_WATER
        tiles[14][c] = T_WATER
    next

    // Bridge bricks over water
    tiles[13][13] = T_BRICK
    tiles[13][14] = T_BRICK
    tiles[14][13] = T_BRICK
    tiles[14][14] = T_BRICK
    tiles[11][13] = T_BRICK
    tiles[11][14] = T_BRICK
    tiles[16][13] = T_BRICK
    tiles[16][14] = T_BRICK
    tiles[13][10] = T_BRICK
    tiles[14][10] = T_BRICK
    tiles[13][17] = T_BRICK
    tiles[14][17] = T_BRICK

    // Lower section
    for r = 19 to 21
        for c = 4 to 5
            tiles[r][c] = T_BRICK
        next
        for c = 9 to 10
            tiles[r][c] = T_STEEL
        next
        for c = 17 to 18
            tiles[r][c] = T_STEEL
        next
        for c = 22 to 23
            tiles[r][c] = T_BRICK
        next
    next

    // Trees near base
    for r = 22 to 23
        for c = 7 to 8
            tiles[r][c] = T_TREES
        next
        for c = 19 to 20
            tiles[r][c] = T_TREES
        next
    next

// =============================================================
// Level 5: Iron Curtain - Lots of steel, challenging layout
// =============================================================

func tank_buildLevel5
    // Top steel wall - leave gaps at spawn columns (4, 13, 22)
    for c = 3 to 24
        if c = 4 or c = 13 or c = 22
            loop
        ok
        tiles[2][c] = T_STEEL
    next

    // Brick corridors
    for r = 4 to 7
        for c = 3 to 4
            tiles[r][c] = T_BRICK
        next
        for c = 7 to 8
            tiles[r][c] = T_STEEL
        next
        for c = 11 to 12
            tiles[r][c] = T_BRICK
        next
        for c = 15 to 16
            tiles[r][c] = T_BRICK
        next
        for c = 19 to 20
            tiles[r][c] = T_STEEL
        next
        for c = 23 to 24
            tiles[r][c] = T_BRICK
        next
    next

    // Water pools
    for r = 9 to 10
        for c = 5 to 6
            tiles[r][c] = T_WATER
        next
        for c = 9 to 10
            tiles[r][c] = T_WATER
        next
        for c = 17 to 18
            tiles[r][c] = T_WATER
        next
        for c = 21 to 22
            tiles[r][c] = T_WATER
        next
    next

    // Central fortress
    for r = 9 to 12
        tiles[r][13] = T_STEEL
        tiles[r][14] = T_STEEL
    next
    for c = 11 to 16
        tiles[9][c] = T_STEEL
        tiles[12][c] = T_STEEL
    next

    // Lower maze
    for r = 14 to 17
        for c = 3 to 4
            tiles[r][c] = T_BRICK
        next
        for c = 8 to 9
            tiles[r][c] = T_BRICK
        next
        for c = 12 to 13
            tiles[r][c] = T_BRICK
        next
        for c = 14 to 15
            tiles[r][c] = T_BRICK
        next
        for c = 18 to 19
            tiles[r][c] = T_BRICK
        next
        for c = 23 to 24
            tiles[r][c] = T_BRICK
        next
    next

    // Ice field
    for r = 19 to 20
        for c = 6 to 11
            tiles[r][c] = T_ICE
        next
        for c = 16 to 21
            tiles[r][c] = T_ICE
        next
    next

    // Trees
    for r = 21 to 22
        for c = 4 to 5
            tiles[r][c] = T_TREES
        next
        for c = 22 to 23
            tiles[r][c] = T_TREES
        next
    next

// =============================================================
// Level 6: Inferno - Lava fields with narrow brick paths
// =============================================================

func tank_buildLevel6
    // Lava pools across the map
    for r = 3 to 6
        for c = 3 to 11
            tiles[r][c] = T_LAVA
        next
        for c = 16 to 24
            tiles[r][c] = T_LAVA
        next
    next
    // Safe brick paths through lava
    for r = 3 to 6
        tiles[r][5] = T_BRICK
        tiles[r][13] = T_EMPTY
        tiles[r][22] = T_BRICK
    next
    // Mid section walls
    for r = 8 to 11
        for c = 4 to 5
            tiles[r][c] = T_STEEL
        next
        for c = 10 to 11
            tiles[r][c] = T_BRICK
        next
        for c = 16 to 17
            tiles[r][c] = T_BRICK
        next
        for c = 22 to 23
            tiles[r][c] = T_STEEL
        next
    next
    // More lava in lower section
    for r = 13 to 16
        for c = 6 to 8
            tiles[r][c] = T_LAVA
        next
        for c = 19 to 21
            tiles[r][c] = T_LAVA
        next
    next
    // Central steel fortress
    for c = 11 to 16
        tiles[13][c] = T_STEEL
        tiles[16][c] = T_STEEL
    next
    tiles[14][11] = T_STEEL
    tiles[15][11] = T_STEEL
    tiles[14][16] = T_STEEL
    tiles[15][16] = T_STEEL
    // Lower brick maze
    for r = 18 to 21
        for c = 3 to 4
            tiles[r][c] = T_BRICK
        next
        for c = 9 to 10
            tiles[r][c] = T_BRICK
        next
        for c = 17 to 18
            tiles[r][c] = T_BRICK
        next
        for c = 23 to 24
            tiles[r][c] = T_BRICK
        next
    next

// =============================================================
// Level 7: Swamp Ambush - Dense trees and water channels
// =============================================================

func tank_buildLevel7
    // Water channels running vertically
    for r = 3 to 22
        tiles[r][6] = T_WATER
        tiles[r][21] = T_WATER
    next
    for r = 3 to 10
        tiles[r][13] = T_WATER
        tiles[r][14] = T_WATER
    next
    // Dense tree cover
    for r = 3 to 8
        for c = 3 to 5
            tiles[r][c] = T_TREES
        next
        for c = 22 to 24
            tiles[r][c] = T_TREES
        next
    next
    for r = 10 to 14
        for c = 8 to 10
            tiles[r][c] = T_TREES
        next
        for c = 17 to 19
            tiles[r][c] = T_TREES
        next
    next
    // Brick structures among trees
    for r = 5 to 7
        tiles[r][9] = T_BRICK
        tiles[r][10] = T_BRICK
        tiles[r][17] = T_BRICK
        tiles[r][18] = T_BRICK
    next
    // Lower section
    for r = 16 to 19
        for c = 4 to 5
            tiles[r][c] = T_BRICK
        next
        for c = 11 to 12
            tiles[r][c] = T_TREES
        next
        for c = 15 to 16
            tiles[r][c] = T_TREES
        next
        for c = 22 to 23
            tiles[r][c] = T_BRICK
        next
    next
    // Ice patches
    for r = 20 to 22
        for c = 8 to 12
            tiles[r][c] = T_ICE
        next
        for c = 15 to 19
            tiles[r][c] = T_ICE
        next
    next

// =============================================================
// Level 8: BOSS - Frozen Fortress (ice field boss battle)
// =============================================================

func tank_buildLevel8
    // Large ice field
    for r = 3 to 12
        for c = 3 to 24
            tiles[r][c] = T_ICE
        next
    next
    // Steel fortress walls on ice
    for c = 8 to 19
        tiles[5][c] = T_STEEL
        tiles[10][c] = T_STEEL
    next
    tiles[6][8] = T_STEEL
    tiles[7][8] = T_STEEL
    tiles[8][8] = T_STEEL
    tiles[9][8] = T_STEEL
    tiles[6][19] = T_STEEL
    tiles[7][19] = T_STEEL
    tiles[8][19] = T_STEEL
    tiles[9][19] = T_STEEL
    // Openings in fortress
    tiles[5][13] = T_EMPTY
    tiles[10][13] = T_EMPTY
    // Lower section with brick cover
    for r = 14 to 17
        for c = 4 to 5
            tiles[r][c] = T_BRICK
        next
        for c = 9 to 10
            tiles[r][c] = T_BRICK
        next
        for c = 17 to 18
            tiles[r][c] = T_BRICK
        next
        for c = 22 to 23
            tiles[r][c] = T_BRICK
        next
    next
    // Water moat
    for c = 6 to 21
        tiles[19][c] = T_WATER
    next
    tiles[19][13] = T_BRICK
    tiles[19][14] = T_BRICK

// =============================================================
// Level 9: The Labyrinth - Complex maze
// =============================================================

func tank_buildLevel9
    // Vertical walls creating maze corridors
    for r = 3 to 10
        tiles[r][5] = T_BRICK
        tiles[r][9] = T_BRICK
        tiles[r][13] = T_BRICK
        tiles[r][17] = T_BRICK
        tiles[r][21] = T_BRICK
    next
    // Horizontal connections
    for c = 5 to 9
        tiles[6][c] = T_BRICK
    next
    for c = 13 to 17
        tiles[6][c] = T_BRICK
    next
    for c = 9 to 13
        tiles[9][c] = T_BRICK
    next
    for c = 17 to 21
        tiles[9][c] = T_BRICK
    next
    // Gaps for passage
    tiles[4][5] = T_EMPTY
    tiles[7][9] = T_EMPTY
    tiles[5][13] = T_EMPTY
    tiles[8][17] = T_EMPTY
    tiles[4][21] = T_EMPTY
    // Lower maze section
    for r = 12 to 19
        tiles[r][4] = T_BRICK
        tiles[r][8] = T_BRICK
        tiles[r][12] = T_BRICK
        tiles[r][15] = T_BRICK
        tiles[r][19] = T_BRICK
        tiles[r][23] = T_BRICK
    next
    // More gaps
    tiles[14][4] = T_EMPTY
    tiles[16][8] = T_EMPTY
    tiles[13][12] = T_EMPTY
    tiles[17][15] = T_EMPTY
    tiles[15][19] = T_EMPTY
    tiles[14][23] = T_EMPTY
    // Steel reinforcement
    for c = 8 to 19
        tiles[12][c] = T_STEEL
    next
    tiles[12][10] = T_EMPTY
    tiles[12][14] = T_EMPTY
    tiles[12][17] = T_EMPTY
    // Trees for cover
    for r = 20 to 22
        tiles[r][6] = T_TREES
        tiles[r][7] = T_TREES
        tiles[r][20] = T_TREES
        tiles[r][21] = T_TREES
    next

// =============================================================
// Level 10: Volcanic Core - Heavy lava, intense combat
// =============================================================

func tank_buildLevel10
    // Lava rivers
    for r = 3 to 22
        tiles[r][7] = T_LAVA
        tiles[r][8] = T_LAVA
        tiles[r][19] = T_LAVA
        tiles[r][20] = T_LAVA
    next
    // Bridges over lava
    for c = 7 to 8
        tiles[6][c] = T_BRICK
        tiles[12][c] = T_BRICK
        tiles[18][c] = T_BRICK
    next
    for c = 19 to 20
        tiles[6][c] = T_BRICK
        tiles[12][c] = T_BRICK
        tiles[18][c] = T_BRICK
    next
    // Central lava pool
    for r = 9 to 11
        for c = 12 to 15
            tiles[r][c] = T_LAVA
        next
    next
    // Steel walls along lava
    for r = 4 to 10
        tiles[r][5] = T_STEEL
        tiles[r][22] = T_STEEL
    next
    // Brick structures between rivers
    for r = 4 to 8
        for c = 10 to 11
            tiles[r][c] = T_BRICK
        next
        for c = 16 to 17
            tiles[r][c] = T_BRICK
        next
    next
    for r = 14 to 18
        for c = 10 to 11
            tiles[r][c] = T_BRICK
        next
        for c = 16 to 17
            tiles[r][c] = T_BRICK
        next
    next
    // Trees near base
    for r = 20 to 22
        for c = 4 to 5
            tiles[r][c] = T_TREES
        next
        for c = 22 to 23
            tiles[r][c] = T_TREES
        next
    next

// =============================================================
// Level 11: Steel Gauntlet - Brutal steel maze
// =============================================================

func tank_buildLevel11
    // Thick steel walls everywhere
    for r = 3 to 6
        for c = 3 to 6
            tiles[r][c] = T_STEEL
        next
        for c = 10 to 12
            tiles[r][c] = T_STEEL
        next
        for c = 15 to 17
            tiles[r][c] = T_STEEL
        next
        for c = 21 to 24
            tiles[r][c] = T_STEEL
        next
    next
    // Gaps in steel for spawn
    tiles[3][4] = T_EMPTY
    tiles[3][13] = T_EMPTY
    tiles[3][22] = T_EMPTY
    // Brick fill (destructible paths)
    for r = 8 to 11
        for c = 4 to 5
            tiles[r][c] = T_BRICK
        next
        for c = 8 to 9
            tiles[r][c] = T_BRICK
        next
        for c = 13 to 14
            tiles[r][c] = T_STEEL
        next
        for c = 18 to 19
            tiles[r][c] = T_BRICK
        next
        for c = 22 to 23
            tiles[r][c] = T_BRICK
        next
    next
    // Water and ice mix
    for r = 13 to 15
        for c = 6 to 8
            tiles[r][c] = T_WATER
        next
        for c = 11 to 12
            tiles[r][c] = T_ICE
        next
        for c = 15 to 16
            tiles[r][c] = T_ICE
        next
        for c = 19 to 21
            tiles[r][c] = T_WATER
        next
    next
    // Lower steel barriers
    for c = 3 to 24
        tiles[17][c] = T_STEEL
    next
    // Leave gaps
    tiles[17][6] = T_EMPTY
    tiles[17][13] = T_EMPTY
    tiles[17][14] = T_EMPTY
    tiles[17][21] = T_EMPTY
    // Lower brick area
    for r = 19 to 21
        for c = 4 to 6
            tiles[r][c] = T_BRICK
        next
        for c = 10 to 12
            tiles[r][c] = T_BRICK
        next
        for c = 15 to 17
            tiles[r][c] = T_BRICK
        next
        for c = 21 to 23
            tiles[r][c] = T_BRICK
        next
    next

// =============================================================
// Level 12: BOSS - Final Assault
// =============================================================

func tank_buildLevel12
    // Lava borders
    for r = 3 to 22
        tiles[r][3] = T_LAVA
        tiles[r][24] = T_LAVA
    next
    for c = 3 to 24
        tiles[3][c] = T_LAVA
    next
    // Leave spawn gaps
    tiles[3][4] = T_EMPTY
    tiles[3][13] = T_EMPTY
    tiles[3][22] = T_EMPTY
    // Steel fortress in center
    for r = 7 to 12
        tiles[r][9] = T_STEEL
        tiles[r][18] = T_STEEL
    next
    for c = 9 to 18
        tiles[7][c] = T_STEEL
        tiles[12][c] = T_STEEL
    next
    // Fortress openings
    tiles[7][13] = T_EMPTY
    tiles[7][14] = T_EMPTY
    tiles[12][13] = T_EMPTY
    tiles[12][14] = T_EMPTY
    tiles[9][9] = T_EMPTY
    tiles[9][18] = T_EMPTY
    // Inside fortress - brick
    for r = 8 to 11
        for c = 11 to 16
            tiles[r][c] = T_BRICK
        next
    next
    tiles[9][13] = T_EMPTY
    tiles[10][13] = T_EMPTY
    tiles[9][14] = T_EMPTY
    tiles[10][14] = T_EMPTY
    // Approach paths with cover
    for r = 14 to 18
        for c = 5 to 6
            tiles[r][c] = T_BRICK
        next
        for c = 11 to 12
            tiles[r][c] = T_BRICK
        next
        for c = 15 to 16
            tiles[r][c] = T_BRICK
        next
        for c = 21 to 22
            tiles[r][c] = T_BRICK
        next
    next
    // Water channels
    for r = 14 to 18
        tiles[r][8] = T_WATER
        tiles[r][19] = T_WATER
    next
    // Trees near base
    for r = 20 to 22
        for c = 5 to 7
            tiles[r][c] = T_TREES
        next
        for c = 20 to 22
            tiles[r][c] = T_TREES
        next
    next
