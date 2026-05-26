/*
**  Dave the Fighter - Levels 6-10 (Gun & Shooting Enemies)
**  Functions: dave_buildLevel6-10
*/

func dave_buildLevel6
    for c = 2 to 29
        tiles[15][c] = T_BRICK
    next

    // Ground structures
    for c = 8 to 12
        tiles[13][c] = T_PLATFORM
    next
    for c = 16 to 20
        tiles[13][c] = T_PLATFORM
    next
    for c = 24 to 27
        tiles[11][c] = T_PLATFORM
    next

    // Upper platforms
    for c = 4 to 7
        tiles[10][c] = T_PLATFORM
    next
    for c = 12 to 16
        tiles[10][c] = T_PLATFORM
    next
    for c = 20 to 24
        tiles[8][c] = T_PLATFORM
    next

    // Wall obstacles
    for r = 12 to 14
        tiles[r][14] = T_BRICK
    next

    // Gun pickup - early in level!
    tiles[14][5] = T_GUN

    // Gems
    tiles[14][8] = T_GEM
    tiles[12][9] = T_GEM
    tiles[12][11] = T_GEM
    tiles[12][17] = T_GEM
    tiles[12][19] = T_RUBY
    tiles[9][5] = T_GEM
    tiles[9][6] = T_RUBY
    tiles[9][13] = T_GEM
    tiles[9][15] = T_GEM
    tiles[7][21] = T_RING
    tiles[7][23] = T_GEM
    tiles[10][25] = T_GEM
    tiles[10][26] = T_RUBY

    // Key on upper right
    tiles[7][24] = T_KEY

    // Door and trophy
    tiles[14][28] = T_DOOR
    tiles[13][28] = T_DOOR
    tiles[14][29] = T_TROPHY

    // Walking enemies
    tiles[14][10] = T_ENEMY_WALK
    tiles[12][18] = T_ENEMY_WALK

    // Shooting enemies - new type!
    tiles[14][22] = T_ENEMY_SHOOT
    tiles[9][14] = T_ENEMY_SHOOT

    // Flying enemies
    tiles[8][8] = T_ENEMY_FLY

    // Spikes
    tiles[15][13] = T_SPIKE

    // Player
    tiles[14][3] = T_PLAYER

// =============================================================
// Level 7: Crossfire - Multiple shooters
// =============================================================

func dave_buildLevel7
    for c = 2 to 29
        tiles[15][c] = T_BRICK
    next

    // Multi-tier structure
    // Tier 1
    for c = 2 to 8
        tiles[12][c] = T_BRICK
    next
    for c = 12 to 18
        tiles[12][c] = T_BRICK
    next
    for c = 22 to 29
        tiles[12][c] = T_BRICK
    next

    // Tier 2
    for c = 6 to 12
        tiles[9][c] = T_BRICK
    next
    for c = 18 to 24
        tiles[9][c] = T_BRICK
    next

    // Tier 3
    for c = 10 to 16
        tiles[6][c] = T_BRICK
    next

    // Ladders
    for r = 13 to 14
        tiles[r][8] = T_LADDER
    next
    for r = 10 to 11
        tiles[r][10] = T_LADDER
    next
    for r = 13 to 14
        tiles[r][22] = T_LADDER
    next
    for r = 10 to 11
        tiles[r][20] = T_LADDER
    next
    for r = 7 to 8
        tiles[r][12] = T_LADDER
    next

    // Gems on each tier
    tiles[14][5] = T_GEM
    tiles[14][15] = T_GEM
    tiles[11][4] = T_GEM
    tiles[11][6] = T_RUBY
    tiles[11][14] = T_GEM
    tiles[11][16] = T_GEM
    tiles[11][24] = T_GEM
    tiles[11][26] = T_RUBY
    tiles[8][7] = T_GEM
    tiles[8][11] = T_GEM
    tiles[8][19] = T_RUBY
    tiles[8][23] = T_GEM
    tiles[5][11] = T_GEM
    tiles[5][13] = T_RING
    tiles[5][15] = T_GEM

    // Key on tier 3
    tiles[5][16] = T_KEY

    // Gun pickup
    tiles[11][3] = T_GUN

    // Door and trophy
    tiles[14][28] = T_DOOR
    tiles[13][28] = T_DOOR
    tiles[14][29] = T_TROPHY

    // Shooting enemies on multiple tiers (with patrol room)
    tiles[11][5] = T_ENEMY_SHOOT
    tiles[11][15] = T_ENEMY_SHOOT
    tiles[8][21] = T_ENEMY_SHOOT

    // Flying enemies
    tiles[8][9] = T_ENEMY_FLY
    tiles[5][14] = T_ENEMY_FLY

    // Spikes (gaps in ground)
    tiles[15][10] = T_SPIKE
    tiles[15][11] = T_SPIKE
    tiles[15][20] = T_SPIKE
    tiles[15][21] = T_SPIKE

    // Walking enemy on solid ground away from spikes
    tiles[14][16] = T_ENEMY_WALK

    // Player
    tiles[14][3] = T_PLAYER

// =============================================================
// Level 8: Fortress - Heavy combat
// =============================================================

func dave_buildLevel8
    for c = 2 to 29
        tiles[15][c] = T_BRICK
    next

    // Fortress walls creating corridors
    for r = 10 to 14
        tiles[r][8] = T_BRICK
    next
    for r = 10 to 14
        tiles[r][16] = T_BRICK
    next
    for r = 10 to 14
        tiles[r][22] = T_BRICK
    next

    // Ceiling sections over corridors
    for c = 2 to 8
        tiles[10][c] = T_BRICK
    next
    for c = 8 to 16
        tiles[10][c] = T_BRICK
    next
    for c = 16 to 22
        tiles[10][c] = T_BRICK
    next

    // Upper area platforms
    for c = 3 to 6
        tiles[7][c] = T_PLATFORM
    next
    for c = 10 to 14
        tiles[7][c] = T_PLATFORM
    next
    for c = 18 to 21
        tiles[7][c] = T_PLATFORM
    next
    for c = 24 to 28
        tiles[7][c] = T_PLATFORM
    next

    // Top platforms
    for c = 6 to 10
        tiles[4][c] = T_PLATFORM
    next
    for c = 14 to 20
        tiles[4][c] = T_PLATFORM
    next

    // Ladders through ceilings
    for r = 11 to 14
        tiles[r][5] = T_LADDER
    next
    for r = 11 to 14
        tiles[r][12] = T_LADDER
    next
    for r = 11 to 14
        tiles[r][19] = T_LADDER
    next

    // Open passage in right wall
    tiles[13][22] = T_EMPTY
    tiles[14][22] = T_EMPTY

    // Upper ladders
    for r = 5 to 6
        tiles[r][8] = T_LADDER
    next
    for r = 5 to 6
        tiles[r][17] = T_LADDER
    next

    // Gems in corridors
    tiles[14][4] = T_GEM
    tiles[14][6] = T_GEM
    tiles[14][10] = T_GEM
    tiles[14][14] = T_RUBY
    tiles[14][18] = T_GEM
    tiles[14][20] = T_GEM
    tiles[14][24] = T_GEM
    tiles[14][27] = T_RUBY

    // Gems on upper platforms
    tiles[6][4] = T_GEM
    tiles[6][5] = T_GEM
    tiles[6][11] = T_RUBY
    tiles[6][13] = T_GEM
    tiles[6][19] = T_GEM
    tiles[6][20] = T_GEM
    tiles[6][25] = T_GEM
    tiles[6][27] = T_RING
    tiles[3][7] = T_GEM
    tiles[3][9] = T_GEM
    tiles[3][15] = T_RUBY
    tiles[3][18] = T_GEM

    // Key at top
    tiles[3][19] = T_KEY

    // Gun pickup
    tiles[14][3] = T_GUN

    // Door and trophy on far right
    tiles[14][28] = T_DOOR
    tiles[13][28] = T_DOOR
    tiles[14][29] = T_TROPHY

    // Shooting enemies in corridors
    tiles[14][7] = T_ENEMY_SHOOT
    tiles[14][13] = T_ENEMY_SHOOT
    tiles[14][17] = T_ENEMY_SHOOT
    tiles[14][25] = T_ENEMY_SHOOT

    // Shooters on upper platforms
    tiles[6][12] = T_ENEMY_SHOOT
    tiles[6][26] = T_ENEMY_SHOOT

    // Flying enemies
    tiles[6][15] = T_ENEMY_FLY
    tiles[3][10] = T_ENEMY_FLY

    // Spikes at corridor ends
    tiles[15][9] = T_SPIKE
    tiles[15][15] = T_SPIKE
    tiles[15][23] = T_SPIKE

    // Player
    tiles[14][2] = T_PLAYER

// =============================================================
// Level 9: Sky Tower - Vertical assault
// =============================================================

func dave_buildLevel9
    for c = 2 to 29
        tiles[15][c] = T_BRICK
    next

    // Left tower
    for c = 2 to 6
        tiles[12][c] = T_BRICK
    next
    for c = 2 to 6
        tiles[9][c] = T_BRICK
    next
    for c = 2 to 6
        tiles[6][c] = T_BRICK
    next
    for c = 2 to 6
        tiles[3][c] = T_BRICK
    next

    // Center platforms
    for c = 9 to 13
        tiles[13][c] = T_PLATFORM
    next
    for c = 8 to 12
        tiles[10][c] = T_PLATFORM
    next
    for c = 9 to 13
        tiles[7][c] = T_PLATFORM
    next
    for c = 8 to 13
        tiles[4][c] = T_PLATFORM
    next

    // Right side structure
    for c = 16 to 20
        tiles[12][c] = T_BRICK
    next
    for c = 16 to 20
        tiles[9][c] = T_BRICK
    next
    for c = 16 to 20
        tiles[6][c] = T_BRICK
    next

    // Far right area
    for c = 23 to 28
        tiles[11][c] = T_PLATFORM
    next
    for c = 24 to 28
        tiles[8][c] = T_PLATFORM
    next

    // Ladders
    for r = 13 to 14
        tiles[r][4] = T_LADDER
    next
    for r = 10 to 11
        tiles[r][3] = T_LADDER
    next
    for r = 7 to 8
        tiles[r][5] = T_LADDER
    next
    for r = 4 to 5
        tiles[r][3] = T_LADDER
    next
    for r = 13 to 14
        tiles[r][18] = T_LADDER
    next
    for r = 10 to 11
        tiles[r][17] = T_LADDER
    next
    for r = 7 to 8
        tiles[r][19] = T_LADDER
    next

    // Gems
    tiles[14][7] = T_GEM
    tiles[14][15] = T_GEM
    tiles[12][10] = T_GEM
    tiles[12][12] = T_GEM
    tiles[11][4] = T_RUBY
    tiles[11][5] = T_GEM
    tiles[9][9] = T_GEM
    tiles[9][11] = T_RUBY
    tiles[8][3] = T_GEM
    tiles[8][5] = T_GEM
    tiles[6][10] = T_GEM
    tiles[6][12] = T_GEM
    tiles[5][4] = T_RING
    tiles[3][10] = T_GEM
    tiles[3][12] = T_RUBY
    tiles[10][25] = T_GEM
    tiles[10][27] = T_GEM
    tiles[7][25] = T_RUBY
    tiles[7][27] = T_GEM

    // Key at very top
    tiles[2][5] = T_KEY

    // Gun
    tiles[12][11] = T_GUN

    // Door and trophy far right
    tiles[14][28] = T_DOOR
    tiles[13][28] = T_DOOR
    tiles[14][29] = T_TROPHY

    // Shooting enemies
    tiles[11][18] = T_ENEMY_SHOOT
    tiles[8][17] = T_ENEMY_SHOOT
    tiles[10][26] = T_ENEMY_SHOOT
    tiles[7][26] = T_ENEMY_SHOOT

    // Walking enemies (on solid ground away from spikes)
    tiles[14][5] = T_ENEMY_WALK
    tiles[14][26] = T_ENEMY_WALK

    // Flying enemies
    tiles[8][10] = T_ENEMY_FLY
    tiles[5][8] = T_ENEMY_FLY
    tiles[6][24] = T_ENEMY_FLY

    // Spikes
    tiles[15][8] = T_SPIKE
    tiles[15][14] = T_SPIKE
    tiles[15][21] = T_SPIKE
    tiles[15][22] = T_SPIKE

    // Player
    tiles[14][3] = T_PLAYER

// =============================================================
// Level 10: Final Showdown - Ultimate challenge
// =============================================================

func dave_buildLevel10
    for c = 2 to 29
        tiles[15][c] = T_BRICK
    next

    // Complex multi-tier fortress
    for c = 2 to 5
        tiles[12][c] = T_BRICK
    next
    for c = 8 to 12
        tiles[12][c] = T_BRICK
    next
    for c = 15 to 19
        tiles[12][c] = T_BRICK
    next
    for c = 22 to 26
        tiles[12][c] = T_BRICK
    next

    // Tier 2
    for c = 4 to 8
        tiles[9][c] = T_BRICK
    next
    for c = 11 to 15
        tiles[9][c] = T_BRICK
    next
    for c = 19 to 23
        tiles[9][c] = T_BRICK
    next

    // Tier 3
    for c = 7 to 11
        tiles[6][c] = T_BRICK
    next
    for c = 15 to 20
        tiles[6][c] = T_BRICK
    next

    // Top tier
    for c = 11 to 16
        tiles[3][c] = T_BRICK
    next

    // Ladders
    for r = 13 to 14
        tiles[r][5] = T_LADDER
    next
    for r = 13 to 14
        tiles[r][15] = T_LADDER
    next
    for r = 13 to 14
        tiles[r][22] = T_LADDER
    next
    for r = 10 to 11
        tiles[r][7] = T_LADDER
    next
    for r = 10 to 11
        tiles[r][13] = T_LADDER
    next
    for r = 10 to 11
        tiles[r][21] = T_LADDER
    next
    for r = 7 to 8
        tiles[r][9] = T_LADDER
    next
    for r = 7 to 8
        tiles[r][18] = T_LADDER
    next
    for r = 4 to 5
        tiles[r][13] = T_LADDER
    next

    // Gems everywhere
    tiles[14][4] = T_GEM
    tiles[14][7] = T_GEM
    tiles[14][13] = T_GEM
    tiles[14][20] = T_GEM
    tiles[14][27] = T_GEM
    tiles[11][3] = T_GEM
    tiles[11][5] = T_RUBY
    tiles[11][9] = T_GEM
    tiles[11][11] = T_GEM
    tiles[11][16] = T_GEM
    tiles[11][18] = T_RUBY
    tiles[11][23] = T_GEM
    tiles[11][25] = T_GEM
    tiles[8][5] = T_GEM
    tiles[8][7] = T_RUBY
    tiles[8][12] = T_GEM
    tiles[8][14] = T_GEM
    tiles[8][20] = T_GEM
    tiles[8][22] = T_RUBY
    tiles[5][8] = T_GEM
    tiles[5][10] = T_RING
    tiles[5][16] = T_GEM
    tiles[5][19] = T_RUBY
    tiles[2][12] = T_RING
    tiles[2][15] = T_GEM

    // Key at the very top
    tiles[2][16] = T_KEY

    // Gun
    tiles[14][3] = T_GUN

    // Door and trophy far right
    for c = 27 to 29
        tiles[13][c] = T_PLATFORM
    next
    tiles[14][28] = T_DOOR
    tiles[13][28] = T_DOOR
    tiles[14][29] = T_TROPHY

    // Heavy enemy presence!
    tiles[11][4] = T_ENEMY_SHOOT
    tiles[11][17] = T_ENEMY_SHOOT
    tiles[11][24] = T_ENEMY_SHOOT
    tiles[8][6] = T_ENEMY_SHOOT
    tiles[8][13] = T_ENEMY_SHOOT
    tiles[8][21] = T_ENEMY_SHOOT
    tiles[5][9] = T_ENEMY_SHOOT
    tiles[5][17] = T_ENEMY_SHOOT

    // Walking enemies
    tiles[14][10] = T_ENEMY_WALK
    tiles[14][18] = T_ENEMY_WALK
    tiles[14][25] = T_ENEMY_WALK

    // Flying enemies
    tiles[7][10] = T_ENEMY_FLY
    tiles[4][14] = T_ENEMY_FLY
    tiles[7][20] = T_ENEMY_FLY

    // Lots of spikes
    tiles[15][6] = T_SPIKE
    tiles[15][9] = T_SPIKE
    tiles[15][14] = T_SPIKE
    tiles[15][17] = T_SPIKE
    tiles[15][21] = T_SPIKE
    tiles[15][24] = T_SPIKE

    // Player
    tiles[14][2] = T_PLAYER
