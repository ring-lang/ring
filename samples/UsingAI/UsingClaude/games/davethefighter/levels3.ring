/*
**  Dave the Fighter - Levels 11-15 (Ice World)
**  White theme, double-width levels, moving platforms,
**  falling icicles, crumbling platforms, wind zones, checkpoints
**  Functions: dave_buildLevel11-15
*/

func dave_buildLevel11
    // Level 11: Introduction to Moving Platforms & Icicles
    // Double-width (60 tiles), gentle intro to new mechanics

    // Ground sections with gaps (need movers to cross)
    for c = 2 to 14
        tiles[15][c] = T_BRICK
    next
    // Gap from 15-20 (moving platform crosses it)
    for c = 21 to 35
        tiles[15][c] = T_BRICK
    next
    // Gap from 36-40
    for c = 41 to 59
        tiles[15][c] = T_BRICK
    next

    // Low platforms - first section
    for c = 4 to 7
        tiles[13][c] = T_PLATFORM
    next
    tiles[12][5] = T_GEM
    tiles[12][6] = T_GEM

    // Mid platform with gems
    for c = 9 to 12
        tiles[11][c] = T_PLATFORM
    next
    tiles[10][10] = T_RUBY
    tiles[10][11] = T_GEM

    // Moving platform to cross first gap (horizontal)
    tiles[14][15] = T_MOVER_H

    // Second section - icicles intro
    // Ceiling icicles above the walkway
    tiles[2][23] = T_ICICLE
    tiles[2][26] = T_ICICLE
    tiles[2][29] = T_ICICLE
    tiles[2][32] = T_ICICLE

    // Platforms in second section
    for c = 23 to 26
        tiles[12][c] = T_PLATFORM
    next
    tiles[11][24] = T_GEM
    tiles[11][25] = T_GEM

    for c = 28 to 31
        tiles[10][c] = T_PLATFORM
    next
    tiles[9][29] = T_RUBY
    tiles[9][30] = T_GEM

    // Ladder up to high section
    tiles[14][34] = T_LADDER
    tiles[13][34] = T_LADDER
    tiles[12][34] = T_LADDER

    // High platform
    for c = 33 to 35
        tiles[11][c] = T_BRICK
    next
    tiles[10][34] = T_GEM

    // Second moving platform for second gap
    tiles[14][36] = T_MOVER_H

    // Checkpoint mid-level
    tiles[14][42] = T_CHECKPOINT

    // Third section - more platforms and icicles
    for c = 42 to 46
        tiles[12][c] = T_PLATFORM
    next
    tiles[11][43] = T_GEM
    tiles[11][44] = T_GEM
    tiles[11][45] = T_RUBY

    tiles[2][44] = T_ICICLE
    tiles[2][46] = T_ICICLE

    for c = 48 to 52
        tiles[10][c] = T_PLATFORM
    next
    tiles[9][49] = T_RING
    tiles[9][51] = T_GEM

    // Key on high platform
    for c = 54 to 56
        tiles[8][c] = T_PLATFORM
    next
    tiles[7][55] = T_KEY

    // Door and trophy
    tiles[14][57] = T_DOOR
    tiles[14][58] = T_TROPHY

    // Enemies
    tiles[14][25] = T_ENEMY_WALK
    tiles[14][43] = T_ENEMY_WALK
    tiles[14][50] = T_ENEMY_SHOOT
    tiles[9][30] = T_ENEMY_FLY

    // Gun pickup (early)
    tiles[14][8] = T_GUN

    // Player start
    tiles[14][3] = T_PLAYER

func dave_buildLevel12
    // Level 12: Crumbling Platforms & Wind Zones
    // Must time jumps as platforms crumble beneath you

    // Ground - broken up into sections
    for c = 2 to 10
        tiles[15][c] = T_BRICK
    next
    for c = 20 to 30
        tiles[15][c] = T_BRICK
    next
    for c = 45 to 59
        tiles[15][c] = T_BRICK
    next

    // Crumbling bridge over first gap (cols 11-19)
    for c = 11 to 19
        tiles[13][c] = T_CRUMBLE
    next
    tiles[12][14] = T_GEM
    tiles[12][16] = T_GEM

    // Wind zone section (cols 22-28)
    for c = 22 to 28
        tiles[12][c] = T_WIND_R
    next
    // Platforms that wind pushes you toward/away from
    for c = 22 to 24
        tiles[10][c] = T_PLATFORM
    next
    tiles[9][23] = T_RUBY

    for c = 26 to 28
        tiles[8][c] = T_PLATFORM
    next
    tiles[7][27] = T_GEM
    tiles[7][28] = T_RING

    // Ladder section
    tiles[14][30] = T_LADDER
    tiles[13][30] = T_LADDER
    tiles[12][30] = T_LADDER
    tiles[11][30] = T_LADDER
    tiles[10][30] = T_LADDER
    tiles[9][30] = T_LADDER

    // Upper bridge with crumbling platforms
    for c = 31 to 35
        tiles[11][c] = T_BRICK
    next
    for c = 36 to 42
        tiles[11][c] = T_CRUMBLE
    next
    tiles[10][33] = T_GEM
    tiles[10][38] = T_GEM
    tiles[10][40] = T_RUBY

    // Moving platform after crumble section
    tiles[12][43] = T_MOVER_H

    // Checkpoint
    tiles[14][46] = T_CHECKPOINT

    // Wind zone pushing left (tricky section)
    for c = 47 to 53
        tiles[10][c] = T_WIND_L
    next
    for c = 47 to 51
        tiles[9][c] = T_PLATFORM
    next
    tiles[8][49] = T_GEM

    for c = 51 to 56
        tiles[7][c] = T_PLATFORM
    next
    tiles[6][53] = T_KEY

    // Icicles in final stretch
    tiles[2][48] = T_ICICLE
    tiles[2][51] = T_ICICLE
    tiles[2][54] = T_ICICLE

    // Door and trophy
    tiles[14][56] = T_DOOR
    tiles[14][57] = T_TROPHY

    // Enemies
    tiles[14][5] = T_ENEMY_WALK
    tiles[14][25] = T_ENEMY_SHOOT
    tiles[10][34] = T_ENEMY_WALK
    tiles[14][50] = T_ENEMY_SHOOT
    tiles[8][49] = T_ENEMY_FLY
    tiles[5][45] = T_ENEMY_FLY

    // Gun
    tiles[14][4] = T_GUN

    // Player
    tiles[14][3] = T_PLAYER

func dave_buildLevel13
    // Level 13: Vertical Movers & Icicle Gauntlet
    // Heavy use of vertical moving platforms and falling hazards

    // Ground sections
    for c = 2 to 12
        tiles[15][c] = T_BRICK
    next
    for c = 25 to 38
        tiles[15][c] = T_BRICK
    next
    for c = 50 to 59
        tiles[15][c] = T_BRICK
    next

    // Vertical mover section (cols 13-24)
    tiles[15][13] = T_MOVER_V
    tiles[15][17] = T_MOVER_V
    tiles[15][21] = T_MOVER_V

    // Gems floating in the vertical mover area
    tiles[9][13] = T_GEM
    tiles[7][17] = T_RUBY
    tiles[9][21] = T_GEM

    // Platforms between movers
    for c = 14 to 16
        tiles[10][c] = T_PLATFORM
    next
    tiles[9][15] = T_GEM

    for c = 18 to 20
        tiles[8][c] = T_PLATFORM
    next
    tiles[7][19] = T_GEM

    for c = 22 to 24
        tiles[10][c] = T_PLATFORM
    next
    tiles[9][23] = T_RING

    // Icicle gauntlet section (cols 26-37)
    tiles[2][27] = T_ICICLE
    tiles[2][28] = T_ICICLE
    tiles[2][30] = T_ICICLE
    tiles[2][31] = T_ICICLE
    tiles[2][33] = T_ICICLE
    tiles[2][34] = T_ICICLE
    tiles[2][36] = T_ICICLE
    tiles[2][37] = T_ICICLE

    // Platforms in gauntlet
    for c = 27 to 29
        tiles[12][c] = T_PLATFORM
    next
    tiles[11][28] = T_GEM

    for c = 31 to 33
        tiles[10][c] = T_PLATFORM
    next
    tiles[9][32] = T_RUBY

    for c = 35 to 37
        tiles[12][c] = T_PLATFORM
    next
    tiles[11][36] = T_GEM

    // Checkpoint
    tiles[14][38] = T_CHECKPOINT

    // Mixed section - crumbles + movers
    for c = 39 to 44
        tiles[12][c] = T_CRUMBLE
    next
    tiles[11][41] = T_GEM
    tiles[11][43] = T_RUBY

    // Horizontal mover over gap
    tiles[14][45] = T_MOVER_H

    // Final section
    for c = 50 to 53
        tiles[11][c] = T_PLATFORM
    next
    tiles[10][51] = T_GEM
    tiles[10][52] = T_GEM

    // Key on high platform
    for c = 54 to 56
        tiles[7][c] = T_PLATFORM
    next
    tiles[6][55] = T_KEY

    // Ladder to key
    tiles[14][54] = T_LADDER
    tiles[13][54] = T_LADDER
    tiles[12][54] = T_LADDER
    tiles[11][54] = T_LADDER
    tiles[10][54] = T_LADDER
    tiles[9][54] = T_LADDER
    tiles[8][54] = T_LADDER

    // Door and trophy
    tiles[14][57] = T_DOOR
    tiles[14][58] = T_TROPHY

    // Enemies
    tiles[14][28] = T_ENEMY_WALK
    tiles[14][35] = T_ENEMY_SHOOT
    tiles[14][51] = T_ENEMY_SHOOT
    tiles[7][17] = T_ENEMY_FLY
    tiles[5][30] = T_ENEMY_FLY
    tiles[5][50] = T_ENEMY_FLY

    // Gun
    tiles[14][5] = T_GUN

    // Player
    tiles[14][3] = T_PLAYER

func dave_buildLevel14
    // Level 14: The Gauntlet - all mechanics combined
    // Wind + crumbles + movers + icicles in challenging combinations

    // Ground - minimal safe ground
    for c = 2 to 8
        tiles[15][c] = T_BRICK
    next
    for c = 18 to 22
        tiles[15][c] = T_BRICK
    next
    for c = 35 to 42
        tiles[15][c] = T_BRICK
    next
    for c = 55 to 59
        tiles[15][c] = T_BRICK
    next

    // Section 1: Wind corridor with crumbling floor (cols 9-17)
    for c = 9 to 17
        tiles[13][c] = T_CRUMBLE
    next
    for c = 9 to 17
        tiles[11][c] = T_WIND_R
    next
    tiles[12][11] = T_GEM
    tiles[12][13] = T_GEM
    tiles[12][15] = T_RUBY

    // Icicles above wind section
    tiles[2][10] = T_ICICLE
    tiles[2][12] = T_ICICLE
    tiles[2][14] = T_ICICLE
    tiles[2][16] = T_ICICLE

    // Section 2: Vertical mover chain (cols 23-34)
    tiles[15][23] = T_MOVER_V
    tiles[15][27] = T_MOVER_V
    tiles[15][31] = T_MOVER_V

    // Crumbling platforms between movers
    for c = 24 to 26
        tiles[9][c] = T_CRUMBLE
    next
    tiles[8][25] = T_RING

    for c = 28 to 30
        tiles[7][c] = T_CRUMBLE
    next
    tiles[6][29] = T_GEM

    for c = 32 to 34
        tiles[9][c] = T_PLATFORM
    next
    tiles[8][33] = T_RUBY

    // Checkpoint
    tiles[14][36] = T_CHECKPOINT

    // Section 3: Horizontal movers over spike pits (cols 35-54)
    for c = 43 to 45
        tiles[15][c] = T_SPIKE
    next
    for c = 47 to 49
        tiles[15][c] = T_SPIKE
    next
    for c = 51 to 53
        tiles[15][c] = T_SPIKE
    next

    tiles[14][43] = T_MOVER_H
    tiles[14][50] = T_MOVER_H

    // Platforms above spikes
    for c = 44 to 46
        tiles[10][c] = T_PLATFORM
    next
    tiles[9][45] = T_GEM

    for c = 48 to 50
        tiles[8][c] = T_PLATFORM
    next
    tiles[7][49] = T_GEM

    // Wind pushing left in final approach (away from ladder)
    for c = 53 to 56
        tiles[8][c] = T_WIND_L
    next

    // Icicles in final stretch
    tiles[2][55] = T_ICICLE
    tiles[2][57] = T_ICICLE

    // Key on high platform with wind
    for c = 54 to 58
        tiles[6][c] = T_PLATFORM
    next
    tiles[5][56] = T_KEY

    // Ladder to reach high platform (outside wind zone)
    tiles[14][58] = T_LADDER
    tiles[13][58] = T_LADDER
    tiles[12][58] = T_LADDER
    tiles[11][58] = T_LADDER
    tiles[10][58] = T_LADDER
    tiles[9][58] = T_LADDER
    tiles[8][58] = T_LADDER
    tiles[7][58] = T_LADDER
    tiles[6][58] = T_LADDER
    tiles[5][58] = T_LADDER

    // Door and trophy
    tiles[14][57] = T_DOOR
    tiles[14][59] = T_TROPHY

    // Many enemies
    tiles[14][20] = T_ENEMY_WALK
    tiles[14][37] = T_ENEMY_SHOOT
    tiles[14][40] = T_ENEMY_WALK
    tiles[14][56] = T_ENEMY_SHOOT
    tiles[5][30] = T_ENEMY_FLY
    tiles[5][45] = T_ENEMY_FLY
    tiles[5][55] = T_ENEMY_FLY
    tiles[8][25] = T_ENEMY_FLY

    // Gun
    tiles[14][4] = T_GUN

    // Player
    tiles[14][3] = T_PLAYER

func dave_buildLevel15
    // Level 15: FINAL LEVEL - The Ice Fortress
    // Boss-like difficulty, every mechanic combined, epic finale
    // Two checkpoints due to extreme length and difficulty

    // Ground - very fragmented
    for c = 2 to 6
        tiles[15][c] = T_BRICK
    next
    for c = 14 to 18
        tiles[15][c] = T_BRICK
    next
    for c = 28 to 32
        tiles[15][c] = T_BRICK
    next
    for c = 42 to 46
        tiles[15][c] = T_BRICK
    next
    for c = 55 to 59
        tiles[15][c] = T_BRICK
    next

    // ===== ZONE 1: Crumble Run (cols 2-13) =====
    // Solid platforms underneath to land on after crumbles fall
    for c = 7 to 13
        tiles[15][c] = T_BRICK
    next
    for c = 7 to 13
        tiles[13][c] = T_CRUMBLE
    next
    tiles[12][8] = T_GEM
    tiles[12][10] = T_GEM
    tiles[12][12] = T_RUBY

    // Higher platform to jump to from crumble run
    for c = 11 to 14
        tiles[11][c] = T_PLATFORM
    next

    // Icicles above crumble run
    tiles[2][8] = T_ICICLE
    tiles[2][10] = T_ICICLE
    tiles[2][12] = T_ICICLE

    // ===== ZONE 2: Mover Maze (cols 14-27) =====
    tiles[14][14] = T_MOVER_H

    // Vertical movers
    tiles[15][19] = T_MOVER_V
    tiles[15][23] = T_MOVER_V

    // Platforms between movers
    for c = 20 to 22
        tiles[9][c] = T_PLATFORM
    next
    tiles[8][21] = T_RING

    for c = 24 to 27
        tiles[7][c] = T_PLATFORM
    next
    tiles[6][25] = T_GEM
    tiles[6][26] = T_RUBY

    // Wind zone making movers harder
    for c = 19 to 23
        tiles[6][c] = T_WIND_R
    next

    // First checkpoint
    tiles[14][29] = T_CHECKPOINT

    // ===== ZONE 3: Icicle Storm (cols 28-41) =====
    // Dense icicle field
    tiles[2][29] = T_ICICLE
    tiles[2][30] = T_ICICLE
    tiles[2][32] = T_ICICLE
    tiles[2][33] = T_ICICLE
    tiles[2][35] = T_ICICLE
    tiles[2][36] = T_ICICLE
    tiles[2][38] = T_ICICLE
    tiles[2][39] = T_ICICLE
    tiles[2][41] = T_ICICLE

    // Platforms to navigate through icicles
    for c = 30 to 32
        tiles[12][c] = T_PLATFORM
    next
    tiles[11][31] = T_GEM

    for c = 34 to 36
        tiles[10][c] = T_CRUMBLE
    next
    tiles[9][35] = T_RUBY

    for c = 38 to 40
        tiles[12][c] = T_PLATFORM
    next
    tiles[11][39] = T_GEM

    // Horizontal mover to cross gap after icicle zone
    tiles[14][41] = T_MOVER_H

    // Second checkpoint
    tiles[14][43] = T_CHECKPOINT

    // ===== ZONE 4: The Fortress (cols 42-59) =====
    // Multi-tier fortress with everything

    // Stepping platforms to climb over fortress wall
    for c = 44 to 46
        tiles[13][c] = T_PLATFORM
    next
    for c = 45 to 47
        tiles[11][c] = T_PLATFORM
    next
    for c = 46 to 48
        tiles[9][c] = T_PLATFORM
    next

    // Fortress wall (left side, floor to ceiling)
    for r = 9 to 14
        tiles[r][47] = T_BRICK
    next
    // Fortress ceiling - extends all the way to the right wall
    for c = 47 to 59
        tiles[8][c] = T_BRICK
    next

    // Lower fortress floor (extends to right wall - no escape, must return through wind)
    for c = 48 to 59
        tiles[12][c] = T_PLATFORM
    next

    // Wind zone inside fortress - wide and multi-row for serious challenge
    for c = 49 to 56
        tiles[10][c] = T_WIND_L
    next
    for c = 49 to 56
        tiles[11][c] = T_WIND_L
    next
    for c = 49 to 56
        tiles[9][c] = T_WIND_L
    next

    // Ladder inside fortress
    tiles[14][48] = T_LADDER
    tiles[13][48] = T_LADDER
    tiles[12][48] = T_LADDER
    tiles[11][48] = T_LADDER
    tiles[10][48] = T_LADDER
    tiles[9][48] = T_LADDER

    // Gems inside fortress (scattered through wind zone)
    tiles[11][50] = T_GEM
    tiles[11][53] = T_RUBY
    tiles[9][51] = T_RING

    // Icicles inside fortress
    tiles[2][49] = T_ICICLE
    tiles[2][51] = T_ICICLE
    tiles[2][53] = T_ICICLE
    tiles[2][55] = T_ICICLE

    // Key at the far end past the wind zone - same row, must walk through all the wind
    tiles[11][58] = T_KEY

    // Spike pit before door
    tiles[15][54] = T_SPIKE
    tiles[15][53] = T_SPIKE

    // Door and trophy at the very end
    tiles[14][57] = T_DOOR
    tiles[14][58] = T_TROPHY

    // Many enemies - fortress defense (all on solid ground)
    tiles[14][5] = T_ENEMY_WALK
    tiles[14][16] = T_ENEMY_SHOOT
    tiles[14][30] = T_ENEMY_WALK
    tiles[14][44] = T_ENEMY_WALK
    tiles[14][56] = T_ENEMY_SHOOT
    tiles[5][20] = T_ENEMY_FLY
    tiles[5][35] = T_ENEMY_FLY
    tiles[5][50] = T_ENEMY_FLY
    tiles[5][55] = T_ENEMY_FLY

    // Gun at start
    tiles[14][3] = T_GUN

    // Player
    tiles[14][2] = T_PLAYER
