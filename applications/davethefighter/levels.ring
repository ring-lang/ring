/*
**  Dave the Fighter - Level Loader & Levels 1-5
**  Functions: dave_loadLevel, dave_buildLevel1-5
*/

func dave_loadLevel lvl
    hasKey = false
    doorOpen = false
    pShootCooldown = 0.0
    pOnMover = false
    pOnLadder = false
    pOnGround = false
    checkpointX = -1
    checkpointY = -1
    checkpointActive = false
    gemsLeft = 0
    totalGems = 0

    // Clear all entity lists
    enemies = []
    particles = []
    popups = []
    bullets = []
    eBullets = []
    movers = []
    icicles = []
    crumbles = []
    windZones = []
    tiles = []

    // Gun persists from level 6 onward once collected
    if lvl < 6
        hasGun = false
    ok

    // Set level width (11-15 double, 16-20 ultra)
    if lvl >= 16
        curLvlW = LVL_W_ULTRA
    but lvl >= 11
        curLvlW = LVL_W_WIDE
    else
        curLvlW = LVL_W
    ok

    // Build empty tile grid
    tiles = list(LVL_H)
    for r = 1 to LVL_H
        tiles[r] = list(curLvlW)
        for c = 1 to curLvlW
            tiles[r][c] = T_EMPTY
        next
    next

    // Floor and ceiling
    for c = 1 to curLvlW
        tiles[1][c] = T_BRICK
        tiles[LVL_H][c] = T_BRICK
    next
    // Side walls
    for r = 1 to LVL_H
        tiles[r][1] = T_BRICK
        tiles[r][curLvlW] = T_BRICK
    next

    if lvl = 1
        dave_buildLevel1()
    but lvl = 2
        dave_buildLevel2()
    but lvl = 3
        dave_buildLevel3()
    but lvl = 4
        dave_buildLevel4()
    but lvl = 5
        dave_buildLevel5()
    but lvl = 6
        dave_buildLevel6()
    but lvl = 7
        dave_buildLevel7()
    but lvl = 8
        dave_buildLevel8()
    but lvl = 9
        dave_buildLevel9()
    but lvl = 10
        dave_buildLevel10()
    but lvl = 11
        dave_buildLevel11()
    but lvl = 12
        dave_buildLevel12()
    but lvl = 13
        dave_buildLevel13()
    but lvl = 14
        dave_buildLevel14()
    but lvl = 15
        dave_buildLevel15()
    but lvl = 16
        dave_buildLevel16()
    but lvl = 17
        dave_buildLevel17()
    but lvl = 18
        dave_buildLevel18()
    but lvl = 19
        dave_buildLevel19()
    but lvl = 20
        dave_buildLevel20()
    ok

    // Scan for gems, player start, enemies, and new tile types
    for r = 1 to LVL_H
        for c = 1 to curLvlW
            t = tiles[r][c]
            if t = T_GEM or t = T_RUBY or t = T_RING
                gemsLeft += 1
                totalGems += 1
            ok
            if t = T_PLAYER
                px = c * 1.0
                py = (LVL_H - r) * 1.0
                tiles[r][c] = T_EMPTY
            ok
            if t = T_ENEMY_WALK
                add(enemies, [c * 1.0, (LVL_H - r) * 1.0, 1.5, 0.0, 1, true, 0.0, 0.0])
                tiles[r][c] = T_EMPTY
            ok
            if t = T_ENEMY_FLY
                add(enemies, [c * 1.0, (LVL_H - r) * 1.0, 1.2, 0.0, 2, true, 0.0, 0.0])
                tiles[r][c] = T_EMPTY
            ok
            if t = T_ENEMY_SHOOT
                add(enemies, [c * 1.0, (LVL_H - r) * 1.0, 1.0, 0.0, 3, true, 0.0, 2.0])
                tiles[r][c] = T_EMPTY
            ok
            if t = T_MOVER_H
                // Horizontal mover: moves right 8 tiles then back
                add(movers, [c * 1.0, (LVL_H - r + 1) * 1.0, 2.0, 0.0,
                             c * 1.0, (c + 8) * 1.0, 1, 2.0])
                tiles[r][c] = T_EMPTY
            ok
            if t = T_MOVER_V
                // Vertical mover: moves up 5 tiles then back
                wy = (LVL_H - r + 1) * 1.0
                add(movers, [c * 1.0, wy, 0.0, 2.0,
                             wy, wy + 5.0, 2, 2.0])
                tiles[r][c] = T_EMPTY
            ok
            if t = T_ICICLE
                add(icicles, [c * 1.0, (LVL_H - r) * 1.0 + 0.5, 0, 0.0, 0.0])
                tiles[r][c] = T_EMPTY
            ok
            if t = T_CRUMBLE
                add(crumbles, [c, r, 0.0, 0])
                // Leave tile as T_CRUMBLE so collision detects it
            ok
            if t = T_WIND_L
                add(windZones, [c, r, -1])
            ok
            if t = T_WIND_R
                add(windZones, [c, r, 1])
            ok
            if t = T_CHECKPOINT
                // Checkpoint stays as tile for visual
            ok
            if t = T_GUN
                // Gun stays as tile, picked up via collectible check
            ok
        next
    next

    pvx = 0.0
    pvy = 0.0
    pOnGround = false
    pFacingRight = true

    // Clear wall/platform tiles above ladders and extend ladder upward
    for r = 1 to LVL_H
        for c = 1 to curLvlW
            if tiles[r][c] = T_LADDER
                isTop = true
                if r - 1 >= 1
                    if tiles[r - 1][c] = T_LADDER
                        isTop = false
                    ok
                ok
                if isTop
                    aboveR = r - 1
                    if aboveR >= 1 and aboveR <= LVL_H
                        if tiles[aboveR][c] = T_BRICK or tiles[aboveR][c] = T_PLATFORM
                            tiles[aboveR][c] = T_LADDER
                            aboveR2 = aboveR - 1
                            if aboveR2 >= 1 and aboveR2 <= LVL_H
                                if tiles[aboveR2][c] = T_BRICK or tiles[aboveR2][c] = T_PLATFORM
                                    tiles[aboveR2][c] = T_LADDER
                                but tiles[aboveR2][c] = T_EMPTY
                                    tiles[aboveR2][c] = T_LADDER
                                ok
                            ok
                        ok
                    ok
                ok
            ok
        next
    next

// -- Level builders --

func dave_buildLevel1
    // Simple intro level - learn to jump, collect gems, get key, open door
    // Ground floor
    for c = 2 to 29
        tiles[15][c] = T_BRICK
    next

    // Step 1: low platforms (2 tiles above floor = reachable from floor)
    for c = 3 to 5
        tiles[13][c] = T_PLATFORM    // Y=3, floor at Y=1, gap=2 OK
    next

    // Step 2: from step 1 to mid platform
    for c = 5 to 8
        tiles[11][c] = T_PLATFORM    // Y=5, from Y=3, gap=2 OK
    next
    // Gems on this platform
    tiles[10][6] = T_GEM
    tiles[10][7] = T_GEM

    // Step 3: high platform (reachable from step 2)
    for c = 8 to 11
        tiles[9][c] = T_PLATFORM    // Y=7, from Y=5, gap=2 OK
    next
    // Rubies up high
    tiles[8][9] = T_RUBY
    tiles[8][10] = T_RUBY

    // Right side: low step
    for c = 12 to 14
        tiles[13][c] = T_PLATFORM    // Y=3
    next
    tiles[14][13] = T_GEM

    // Mid right platform
    for c = 16 to 19
        tiles[11][c] = T_PLATFORM    // Y=5, reachable from 13 or ground via stepping
    next
    tiles[10][17] = T_GEM
    tiles[10][18] = T_GEM

    // Far right low step
    for c = 20 to 22
        tiles[13][c] = T_PLATFORM    // Y=3
    next
    tiles[12][21] = T_GEM

    // Upper right platform for key
    for c = 23 to 26
        tiles[11][c] = T_PLATFORM    // Y=5
    next
    tiles[10][25] = T_KEY

    // Ground level gems
    tiles[14][10] = T_GEM
    tiles[14][16] = T_GEM
    tiles[14][24] = T_GEM

    // Wall obstacle
    tiles[14][17] = T_BRICK
    tiles[13][17] = T_BRICK

    // Door and trophy at end
    tiles[14][28] = T_DOOR
    tiles[13][28] = T_DOOR
    tiles[14][29] = T_TROPHY

    // Player start
    tiles[14][3] = T_PLAYER

func dave_buildLevel2
    // More complex with enemies and spikes
    for c = 2 to 29
        tiles[15][c] = T_BRICK
    next

    // Pit with spikes (3 tiles wide)
    tiles[15][12] = T_EMPTY
    tiles[15][13] = T_EMPTY
    tiles[15][14] = T_EMPTY
    tiles[16][12] = T_SPIKE
    tiles[16][13] = T_SPIKE
    tiles[16][14] = T_SPIKE

    // Left section: stepping up
    for c = 3 to 5
        tiles[13][c] = T_PLATFORM    // Y=3
    next
    for c = 5 to 8
        tiles[11][c] = T_PLATFORM    // Y=5, from Y=3, gap=2
    next
    for c = 3 to 5
        tiles[9][c] = T_PLATFORM     // Y=7, from Y=5, gap=2
    next

    // Bridge over pit
    for c = 10 to 15
        tiles[12][c] = T_PLATFORM    // Y=4, reachable from floor Y=1
    next

    // Right section: stepping
    for c = 17 to 19
        tiles[13][c] = T_PLATFORM    // Y=3
    next
    for c = 20 to 23
        tiles[11][c] = T_PLATFORM    // Y=5
    next
    for c = 24 to 27
        tiles[9][c] = T_PLATFORM     // Y=7, from Y=5
    next

    // Wall pillar
    for r = 11 to 14
        tiles[r][16] = T_BRICK
    next

    // Gems
    tiles[12][4] = T_GEM
    tiles[10][6] = T_GEM
    tiles[10][7] = T_GEM
    tiles[8][4] = T_RING
    tiles[11][11] = T_GEM
    tiles[11][14] = T_GEM
    tiles[14][8] = T_GEM
    tiles[12][18] = T_GEM
    tiles[10][21] = T_GEM
    tiles[10][22] = T_RUBY
    tiles[8][25] = T_RUBY
    tiles[8][26] = T_GEM

    // Key on high right
    tiles[8][27] = T_KEY

    // Door
    tiles[14][28] = T_DOOR
    tiles[13][28] = T_DOOR
    tiles[14][29] = T_TROPHY

    // Enemies
    tiles[14][9] = T_ENEMY_WALK
    tiles[14][22] = T_ENEMY_WALK
    tiles[8][6] = T_ENEMY_FLY

    // Player
    tiles[14][3] = T_PLAYER

func dave_buildLevel3
    // Multi-tier with ladders
    for c = 2 to 29
        tiles[15][c] = T_BRICK
    next

    // Tier 1 (row 12 = Y=4, gap from floor=3 → jumpable)
    for c = 2 to 10
        tiles[12][c] = T_BRICK
    next
    for c = 14 to 22
        tiles[12][c] = T_BRICK
    next
    for c = 26 to 27
        tiles[12][c] = T_BRICK
    next

    // Tier 2 (row 9 = Y=7, gap from tier1=3 → jumpable with ladder help)
    for c = 5 to 12
        tiles[9][c] = T_BRICK
    next
    for c = 17 to 25
        tiles[9][c] = T_BRICK
    next

    // Tier 3 (row 6 = Y=10, gap from tier2=3)
    for c = 8 to 15
        tiles[6][c] = T_BRICK
    next
    for c = 20 to 27
        tiles[6][c] = T_BRICK
    next

    // Ladders connecting tiers
    for r = 13 to 14
        tiles[r][10] = T_LADDER    // Floor to tier 1
    next
    for r = 10 to 11
        tiles[r][8] = T_LADDER     // Tier 1 to tier 2
    next
    for r = 13 to 14
        tiles[r][22] = T_LADDER    // Floor to tier 1
    next
    for r = 10 to 11
        tiles[r][20] = T_LADDER    // Tier 1 to tier 2
    next
    for r = 7 to 8
        tiles[r][12] = T_LADDER    // Tier 2 to tier 3
    next
    for r = 7 to 8
        tiles[r][22] = T_LADDER    // Tier 2 to tier 3
    next

    // Gems on each tier
    tiles[14][5] = T_GEM
    tiles[14][15] = T_GEM
    tiles[11][4] = T_GEM
    tiles[11][7] = T_GEM
    tiles[11][16] = T_GEM
    tiles[11][19] = T_RUBY
    tiles[8][6] = T_GEM
    tiles[8][9] = T_GEM
    tiles[8][18] = T_GEM
    tiles[8][23] = T_RUBY
    tiles[5][10] = T_RING
    tiles[5][13] = T_GEM
    tiles[5][22] = T_GEM
    tiles[5][25] = T_GEM

    // Key on top tier
    tiles[5][26] = T_KEY

    // Door
    tiles[14][28] = T_DOOR
    tiles[13][28] = T_DOOR
    tiles[14][29] = T_TROPHY

    // Enemies
    tiles[11][6] = T_ENEMY_WALK
    tiles[14][20] = T_ENEMY_WALK
    tiles[8][17] = T_ENEMY_WALK
    tiles[5][11] = T_ENEMY_FLY

    // Player
    tiles[14][3] = T_PLAYER

    // Spikes in gaps
    tiles[15][12] = T_SPIKE
    tiles[15][13] = T_SPIKE
    tiles[15][24] = T_SPIKE
    tiles[15][25] = T_SPIKE

func dave_buildLevel4
    // Vertical challenge - lots of jumping
    for c = 2 to 29
        tiles[15][c] = T_BRICK
    next

    // Left zigzag climb (each step max 3 tiles higher)
    // Step 1: Y=3 (gap 2 from floor)
    tiles[13][3] = T_PLATFORM
    tiles[13][4] = T_PLATFORM
    // Step 2: Y=5 (gap 2)
    tiles[11][6] = T_PLATFORM
    tiles[11][7] = T_PLATFORM
    // Step 3: Y=7 (gap 2)
    tiles[9][4] = T_PLATFORM
    tiles[9][5] = T_PLATFORM
    // Step 4: Y=9 (gap 2)
    tiles[7][7] = T_PLATFORM
    tiles[7][8] = T_PLATFORM
    // Step 5: Y=11 (gap 2)
    tiles[5][5] = T_PLATFORM
    tiles[5][6] = T_PLATFORM
    // Top: Y=13 (gap 2)
    tiles[3][8] = T_PLATFORM
    tiles[3][9] = T_PLATFORM

    // Right zigzag climb
    // Step 1: Y=3
    tiles[13][16] = T_PLATFORM
    tiles[13][17] = T_PLATFORM
    // Step 2: Y=5
    tiles[11][19] = T_PLATFORM
    tiles[11][20] = T_PLATFORM
    // Step 3: Y=7
    tiles[9][17] = T_PLATFORM
    tiles[9][18] = T_PLATFORM
    // Step 4: Y=9
    tiles[7][20] = T_PLATFORM
    tiles[7][21] = T_PLATFORM
    // Step 5: Y=11
    tiles[5][18] = T_PLATFORM
    tiles[5][19] = T_PLATFORM
    // Top: Y=13
    tiles[3][21] = T_PLATFORM
    tiles[3][22] = T_PLATFORM

    // Connection bridge at mid height
    for c = 10 to 14
        tiles[9][c] = T_PLATFORM    // Y=7
    next

    // Middle wall
    for r = 10 to 14
        tiles[r][15] = T_BRICK
    next

    // Spikes in bottom
    for c = 5 to 8
        tiles[15][c] = T_SPIKE
    next
    for c = 18 to 21
        tiles[15][c] = T_SPIKE
    next

    // Gems along the climb
    tiles[12][3] = T_GEM
    tiles[10][6] = T_GEM
    tiles[8][4] = T_GEM
    tiles[6][7] = T_RUBY
    tiles[4][5] = T_GEM
    tiles[2][8] = T_RING
    tiles[8][11] = T_GEM
    tiles[8][13] = T_GEM
    tiles[12][16] = T_GEM
    tiles[10][19] = T_GEM
    tiles[8][17] = T_RUBY
    tiles[6][20] = T_GEM
    tiles[4][18] = T_GEM

    // Key at top
    tiles[2][9] = T_KEY

    // Door and exit
    for c = 27 to 29
        tiles[13][c] = T_PLATFORM
    next
    tiles[14][28] = T_DOOR
    tiles[13][28] = T_DOOR
    tiles[12][29] = T_TROPHY

    // Enemies
    tiles[14][10] = T_ENEMY_WALK
    tiles[14][22] = T_ENEMY_WALK
    tiles[6][6] = T_ENEMY_FLY
    tiles[6][19] = T_ENEMY_FLY

    // Player
    tiles[14][2] = T_PLAYER

func dave_buildLevel5
    // Final level - hardest, multi-tier with ladders and enemies
    for c = 2 to 29
        tiles[15][c] = T_BRICK
    next

    // Tier structure with ladders and jumps
    // Tier 1: row 12 (Y=4, gap 3 from floor - tight but reachable)
    for c = 2 to 7
        tiles[12][c] = T_BRICK
    next
    for c = 17 to 20
        tiles[12][c] = T_BRICK
    next
    for c = 23 to 29
        tiles[12][c] = T_BRICK
    next

    // Stepping stones to reach tier 1 where gaps exist
    for c = 10 to 13
        tiles[13][c] = T_PLATFORM    // Y=3 stepping stone
    next

    // Tier 2: row 9 (Y=7, gap 3 from tier 1)
    for c = 5 to 10
        tiles[9][c] = T_PLATFORM
    next
    for c = 14 to 19
        tiles[9][c] = T_PLATFORM
    next
    for c = 24 to 28
        tiles[9][c] = T_PLATFORM
    next

    // Tier 3: row 6 (Y=10, gap 3 from tier 2)
    for c = 8 to 13
        tiles[6][c] = T_PLATFORM
    next
    for c = 18 to 23
        tiles[6][c] = T_PLATFORM
    next

    // Top: row 4 (Y=12, gap 2 from tier 3)
    for c = 12 to 16
        tiles[4][c] = T_PLATFORM
    next

    // Ladders
    for r = 13 to 14
        tiles[r][7] = T_LADDER     // Floor to tier 1
    next
    for r = 10 to 11
        tiles[r][9] = T_LADDER     // Tier 1 to tier 2
    next
    for r = 13 to 14
        tiles[r][24] = T_LADDER    // Floor to tier 1 right
    next
    for r = 10 to 11
        tiles[r][17] = T_LADDER    // Tier 1 to tier 2
    next
    for r = 7 to 8
        tiles[r][11] = T_LADDER    // Tier 2 to tier 3
    next
    for r = 7 to 8
        tiles[r][20] = T_LADDER    // Tier 2 to tier 3
    next
    for r = 5 to 5
        tiles[r][13] = T_LADDER    // Tier 3 to top
    next

    // Spikes
    tiles[15][9] = T_SPIKE
    tiles[15][10] = T_SPIKE
    tiles[15][15] = T_SPIKE
    tiles[15][16] = T_SPIKE
    tiles[15][21] = T_SPIKE
    tiles[15][22] = T_SPIKE

    // Gems everywhere
    tiles[14][4] = T_GEM
    tiles[14][11] = T_GEM
    tiles[12][12] = T_GEM
    tiles[11][18] = T_GEM
    tiles[11][19] = T_RUBY
    tiles[11][25] = T_GEM
    tiles[8][6] = T_GEM
    tiles[8][8] = T_RUBY
    tiles[8][15] = T_GEM
    tiles[8][17] = T_GEM
    tiles[8][25] = T_GEM
    tiles[5][9] = T_GEM
    tiles[5][12] = T_RUBY
    tiles[5][19] = T_RING
    tiles[5][22] = T_GEM
    tiles[3][14] = T_RING

    // Key at very top
    tiles[3][15] = T_KEY

    // Door and trophy (right side, on tier 1 - door blocks, trophy behind)
    tiles[11][28] = T_DOOR
    tiles[10][28] = T_DOOR
    tiles[11][29] = T_TROPHY

    // Many enemies
    tiles[14][6] = T_ENEMY_WALK
    tiles[14][18] = T_ENEMY_WALK
    tiles[11][26] = T_ENEMY_WALK
    tiles[8][7] = T_ENEMY_FLY
    tiles[5][15] = T_ENEMY_FLY
    tiles[8][21] = T_ENEMY_FLY

    // Player
    tiles[14][3] = T_PLAYER
