/*
**  Dave the Fighter - Levels 16-20 (Sand World - Ultra Wide)
**  Functions: dave_buildLevel16-20
*/

func dave_buildLevel16
    // Level 16: The Crumble Gauntlet
    // Ultra-wide (120 tiles). One massive crumbling bridge spans the level.
    // Icicles rain from above. Flying enemies everywhere.
    // Key is on a moving platform side path - must detour and return.
    // Checkpoints every ~30 tiles.

    // ===== GROUND: Only at start and end =====
    for c = 2 to 8
        tiles[15][c] = T_BRICK
    next
    for c = 112 to 119
        tiles[15][c] = T_BRICK
    next

    // ===== THE GREAT CRUMBLING BRIDGE (row 12, cols 6-115) =====
    // This is the main path - one long crumbling platform
    for c = 6 to 115
        tiles[12][c] = T_CRUMBLE
    next

    // ===== SAFE PLATFORM ISLANDS (row 12, solid - rest spots) =====
    // Every ~15 tiles, a small solid platform among the crumbles
    for c = 20 to 23
        tiles[12][c] = T_PLATFORM
    next
    for c = 38 to 41
        tiles[12][c] = T_PLATFORM
    next
    for c = 58 to 61
        tiles[12][c] = T_PLATFORM
    next
    for c = 78 to 81
        tiles[12][c] = T_PLATFORM
    next
    for c = 98 to 101
        tiles[12][c] = T_PLATFORM
    next

    // ===== ICICLES - Dense coverage across the bridge =====
    // Section 1 (cols 10-25)
    tiles[2][10] = T_ICICLE
    tiles[2][13] = T_ICICLE
    tiles[2][16] = T_ICICLE
    tiles[2][19] = T_ICICLE
    tiles[2][24] = T_ICICLE
    // Section 2 (cols 28-45)
    tiles[2][28] = T_ICICLE
    tiles[2][31] = T_ICICLE
    tiles[2][34] = T_ICICLE
    tiles[2][37] = T_ICICLE
    tiles[2][42] = T_ICICLE
    tiles[2][45] = T_ICICLE
    // Section 3 (cols 48-65)
    tiles[2][48] = T_ICICLE
    tiles[2][51] = T_ICICLE
    tiles[2][54] = T_ICICLE
    tiles[2][57] = T_ICICLE
    tiles[2][62] = T_ICICLE
    tiles[2][65] = T_ICICLE
    // Section 4 (cols 68-85)
    tiles[2][68] = T_ICICLE
    tiles[2][71] = T_ICICLE
    tiles[2][74] = T_ICICLE
    tiles[2][77] = T_ICICLE
    tiles[2][82] = T_ICICLE
    tiles[2][85] = T_ICICLE
    // Section 5 (cols 88-110)
    tiles[2][88] = T_ICICLE
    tiles[2][91] = T_ICICLE
    tiles[2][94] = T_ICICLE
    tiles[2][97] = T_ICICLE
    tiles[2][102] = T_ICICLE
    tiles[2][105] = T_ICICLE
    tiles[2][108] = T_ICICLE

    // ===== KEY DETOUR (cols 55-65, below the bridge) =====
    // Player must jump down to a moving platform, grab key, return up
    // Moving platform goes horizontally below the bridge
    tiles[14][56] = T_MOVER_H

    // Small platform to land on near key
    for c = 62 to 65
        tiles[14][c] = T_PLATFORM
    next
    tiles[13][64] = T_KEY

    // Ladder to climb back up to the bridge
    tiles[13][65] = T_LADDER
    tiles[12][65] = T_LADDER
    tiles[11][65] = T_LADDER

    // ===== GEMS scattered along the bridge =====
    tiles[11][10] = T_GEM
    tiles[11][15] = T_GEM
    tiles[11][22] = T_RUBY
    tiles[11][30] = T_GEM
    tiles[11][35] = T_GEM
    tiles[11][40] = T_RUBY
    tiles[11][50] = T_GEM
    tiles[11][55] = T_RING
    tiles[11][70] = T_GEM
    tiles[11][75] = T_GEM
    tiles[11][80] = T_RUBY
    tiles[11][90] = T_GEM
    tiles[11][95] = T_GEM
    tiles[11][100] = T_RUBY
    tiles[11][110] = T_RING

    // ===== CHECKPOINTS =====
    tiles[11][21] = T_CHECKPOINT
    tiles[11][59] = T_CHECKPOINT
    tiles[11][99] = T_CHECKPOINT

    // ===== DOOR AND TROPHY =====
    // Landing platform at end connects bridge to ground
    for c = 110 to 115
        tiles[12][c] = T_PLATFORM
    next
    tiles[14][116] = T_DOOR
    tiles[14][117] = T_TROPHY

    // ===== GUN =====
    tiles[11][5] = T_GUN

    // ===== FLYING ENEMIES - 2 per screen section, at player level =====
    tiles[11][10] = T_ENEMY_FLY
    tiles[11][17] = T_ENEMY_FLY
    tiles[11][25] = T_ENEMY_FLY
    tiles[11][32] = T_ENEMY_FLY
    tiles[11][42] = T_ENEMY_FLY
    tiles[11][47] = T_ENEMY_FLY
    tiles[11][55] = T_ENEMY_FLY
    tiles[11][63] = T_ENEMY_FLY
    tiles[11][70] = T_ENEMY_FLY
    tiles[11][77] = T_ENEMY_FLY
    tiles[11][85] = T_ENEMY_FLY
    tiles[11][92] = T_ENEMY_FLY
    tiles[11][103] = T_ENEMY_FLY
    tiles[11][107] = T_ENEMY_FLY
    tiles[11][115] = T_ENEMY_FLY
    tiles[11][118] = T_ENEMY_FLY

    // ===== GROUND ENEMIES on safe platforms =====
    // Walkers and shooters alternating
    tiles[11][22] = T_ENEMY_WALK
    tiles[11][39] = T_ENEMY_SHOOT
    tiles[11][60] = T_ENEMY_WALK
    tiles[11][79] = T_ENEMY_SHOOT
    tiles[11][100] = T_ENEMY_SHOOT

    // ===== SPIKES under sections of the bridge (death if you fall) =====
    for c = 9 to 19
        tiles[15][c] = T_SPIKE
    next
    for c = 24 to 37
        tiles[15][c] = T_SPIKE
    next
    for c = 42 to 55
        tiles[15][c] = T_SPIKE
    next
    for c = 66 to 77
        tiles[15][c] = T_SPIKE
    next
    for c = 82 to 97
        tiles[15][c] = T_SPIKE
    next
    for c = 102 to 111
        tiles[15][c] = T_SPIKE
    next

    // ===== PLAYER =====
    tiles[14][3] = T_PLAYER

// Placeholder functions for levels 17-20
func dave_buildLevel17
    // Level 17: The Spike Abyss
    // 120 tiles wide. ENTIRE floor is spikes.
    // Player starts center. Must go LEFT for key, return, then go RIGHT to door.
    // A brick wall blocks the right path until the door is opened with key.
    // All travel via moving platforms over spike death pit.

    // ===== SPIKE FLOOR =====
    for c = 2 to 119
        tiles[15][c] = T_SPIKE
    next

    // ===== STARTING PLATFORM (center, cols 57-63, row 10) =====
    for c = 57 to 63
        tiles[10][c] = T_BRICK
    next

    // =========================================================
    // LEFT SIDE: Path to KEY (cols 2-56)
    // =========================================================

    // Island 1 (cols 44-46, row 10)
    for c = 44 to 46
        tiles[10][c] = T_PLATFORM
    next
    // Island 2 (cols 31-33, row 10)
    for c = 31 to 33
        tiles[10][c] = T_PLATFORM
    next
    // Island 3 (cols 24-26, row 7)
    for c = 24 to 26
        tiles[7][c] = T_PLATFORM
    next
    // Island 4 (cols 12-14, row 7)
    for c = 12 to 14
        tiles[7][c] = T_PLATFORM
    next
    // Key platform (cols 3-6, row 10)
    for c = 3 to 6
        tiles[10][c] = T_BRICK
    next

    // Moving platforms - left side
    tiles[11][48] = T_MOVER_H    // col 48-56, connects start to island 1
    tiles[11][35] = T_MOVER_H    // col 35-43, connects island 1 to island 2
    tiles[10][28] = T_MOVER_V    // col 28, lifts up from island 2 level to island 3
    tiles[8][16] = T_MOVER_H     // col 16-24, connects island 3 to island 4
    tiles[8][4] = T_MOVER_H      // col 4-12, connects island 4 to key platform

    // KEY
    tiles[9][4] = T_KEY

    // Ladder to climb back up from key platform
    for r = 8 to 9
        tiles[r][6] = T_LADDER
    next

    // =========================================================
    // RIGHT SIDE: Path to DOOR (cols 64-118)
    // Player can go right without key (trick - but door won't open)
    // =========================================================

    // Island 5 (cols 75-77, row 10)
    for c = 75 to 77
        tiles[10][c] = T_PLATFORM
    next
    // Island 6 (cols 87-89, row 10)
    for c = 87 to 89
        tiles[10][c] = T_PLATFORM
    next
    // Island 7 (cols 95-97, row 7)
    for c = 95 to 97
        tiles[7][c] = T_PLATFORM
    next
    // Island 8 (cols 107-109, row 7)
    for c = 107 to 109
        tiles[7][c] = T_PLATFORM
    next
    // Door platform (cols 113-118, row 10)
    for c = 113 to 118
        tiles[10][c] = T_BRICK
    next

    // Moving platforms - right side
    tiles[11][66] = T_MOVER_H    // col 66-74, connects start to island 5
    tiles[11][78] = T_MOVER_H    // col 78-86, connects island 5 to island 6
    tiles[10][92] = T_MOVER_V    // col 92, lifts from island 6 level to island 7
    tiles[8][98] = T_MOVER_H     // col 98-106, connects island 7 to island 8
    tiles[8][108] = T_MOVER_H    // col 108-116, connects island 8 to door platform

    // DOOR AND TROPHY
    tiles[9][117] = T_DOOR
    tiles[9][118] = T_DOOR
    tiles[9][119] = T_TROPHY

    // ===== WIND ZONES =====
    // Wind 1: between islands 1 and 2, push left (slows travel left)
    for c = 37 to 41
        tiles[10][c] = T_WIND_L
        tiles[11][c] = T_WIND_L
    next
    // Wind 2: near key, push left (harder to land on key platform)
    for c = 7 to 10
        tiles[9][c] = T_WIND_L
        tiles[10][c] = T_WIND_L
    next
    // Wind 3: right side between islands 5 and 6, push right (speeds up)
    for c = 80 to 85
        tiles[10][c] = T_WIND_R
        tiles[11][c] = T_WIND_R
    next
    // Wind 4: before door platform, push left (fight to reach door)
    for c = 110 to 114
        tiles[7][c] = T_WIND_L
        tiles[8][c] = T_WIND_L
    next

    // ===== GUN =====
    tiles[9][60] = T_GUN

    // ===== GEMS =====
    tiles[9][45] = T_GEM
    tiles[9][32] = T_GEM
    tiles[6][25] = T_RUBY
    tiles[6][13] = T_GEM
    tiles[9][5] = T_RING
    tiles[9][76] = T_GEM
    tiles[9][87] = T_GEM
    tiles[6][96] = T_RUBY
    tiles[6][108] = T_GEM
    tiles[9][115] = T_RING

    // ===== CHECKPOINTS =====
    tiles[9][61] = T_CHECKPOINT
    tiles[9][32] = T_CHECKPOINT  // Left side on island 2
    tiles[9][87] = T_CHECKPOINT  // Right side on island 6

    // ===== FLYING ENEMIES =====
    tiles[9][50] = T_ENEMY_FLY
    tiles[9][38] = T_ENEMY_FLY
    tiles[6][20] = T_ENEMY_FLY
    tiles[6][9] = T_ENEMY_FLY
    tiles[9][71] = T_ENEMY_FLY
    tiles[9][83] = T_ENEMY_FLY
    tiles[6][100] = T_ENEMY_FLY
    tiles[6][112] = T_ENEMY_FLY

    // ===== ICICLES =====
    tiles[2][45] = T_ICICLE
    tiles[2][32] = T_ICICLE
    tiles[2][13] = T_ICICLE
    tiles[2][76] = T_ICICLE
    tiles[2][96] = T_ICICLE
    tiles[2][115] = T_ICICLE

    // ===== PLAYER =====
    tiles[9][59] = T_PLAYER

func dave_buildLevel18
    // Level 18: The Snake
    // Three horizontal corridors forming a zigzag path across the 120-tile level.
    // Bottom: walk right (start to end) -> ladder up
    // Middle: walk left (end to start) with walking/shooting enemies -> ladder up
    // Top: walk right (start to end) with flying enemies, key, then door
    // Each corridor is 4 rows tall so the player can jump over hazards.

    // ===== CORRIDOR STRUCTURE =====
    // Bottom corridor: rows 12-15 (floor=15, ceiling=11)
    // Middle corridor: rows 6-10 (floor=10, ceiling=6)
    // Top corridor: rows 1-5 (floor=5, ceiling=1 which is top wall)

    // --- Bottom corridor ceiling (row 11) ---
    for c = 2 to 119
        tiles[11][c] = T_BRICK
    next

    // --- Middle corridor floor (row 10) ---
    for c = 2 to 119
        tiles[10][c] = T_BRICK
    next
    // Middle corridor ceiling (row 6)
    for c = 2 to 119
        tiles[6][c] = T_BRICK
    next

    // --- Top corridor floor (row 5) ---
    for c = 2 to 119
        tiles[5][c] = T_BRICK
    next
    // Top corridor ceiling is row 1 (already brick from loadLevel)

    // ===== RIGHT LADDER: Bottom to Middle (col 117-118) =====
    // Open bottom ceiling and middle floor
    tiles[11][117] = T_EMPTY
    tiles[11][118] = T_EMPTY
    tiles[10][117] = T_EMPTY
    tiles[10][118] = T_EMPTY
    // Ladder from bottom floor up through ceiling into middle corridor
    for r = 9 to 14
        tiles[r][117] = T_LADDER
    next

    // ===== LEFT LADDER: Middle to Top (col 3-4) =====
    // Open middle ceiling and top floor
    tiles[6][3] = T_EMPTY
    tiles[6][4] = T_EMPTY
    tiles[5][3] = T_EMPTY
    tiles[5][4] = T_EMPTY
    // Ladder from middle floor up through ceiling into top corridor
    for r = 4 to 9
        tiles[r][3] = T_LADDER
    next

    // ===== BOTTOM CORRIDOR: Gems and decoration (walk right) =====
    tiles[14][10] = T_GEM
    tiles[14][20] = T_GEM
    tiles[14][30] = T_GEM
    tiles[14][40] = T_RUBY
    tiles[14][50] = T_GEM
    tiles[14][65] = T_GEM
    tiles[14][75] = T_GEM
    tiles[14][85] = T_RUBY
    tiles[14][95] = T_GEM
    tiles[14][105] = T_GEM
    tiles[14][110] = T_GEM

    // Gun in bottom corridor
    tiles[14][5] = T_GUN

    // Spikes in bottom corridor (jumpable with 4 rows of space)
    tiles[15][25] = T_SPIKE
    tiles[15][26] = T_SPIKE
    tiles[15][55] = T_SPIKE
    tiles[15][56] = T_SPIKE
    tiles[15][85] = T_SPIKE
    tiles[15][86] = T_SPIKE

    // Checkpoint at bottom corridor midpoint
    tiles[14][60] = T_CHECKPOINT

    // ===== MIDDLE CORRIDOR: Walking and shooting enemies (walk left) =====
    tiles[9][110] = T_ENEMY_WALK
    tiles[9][100] = T_ENEMY_WALK
    tiles[9][90] = T_ENEMY_SHOOT
    tiles[9][80] = T_ENEMY_WALK
    tiles[9][70] = T_ENEMY_SHOOT
    tiles[9][60] = T_ENEMY_WALK
    tiles[9][50] = T_ENEMY_SHOOT
    tiles[9][40] = T_ENEMY_WALK
    tiles[9][30] = T_ENEMY_SHOOT
    tiles[9][20] = T_ENEMY_WALK
    tiles[9][10] = T_ENEMY_WALK

    // Gems in middle corridor
    tiles[9][105] = T_GEM
    tiles[9][85] = T_RUBY
    tiles[9][65] = T_GEM
    tiles[9][45] = T_RUBY
    tiles[9][25] = T_GEM
    tiles[9][15] = T_RING

    // Spikes in middle corridor
    tiles[10][35] = T_SPIKE
    tiles[10][36] = T_SPIKE
    tiles[10][75] = T_SPIKE
    tiles[10][76] = T_SPIKE
    tiles[10][105] = T_SPIKE
    tiles[10][106] = T_SPIKE

    // Checkpoint at middle corridor midpoint
    tiles[9][60] = T_CHECKPOINT

    // ===== TOP CORRIDOR: Flying enemies, key, door (walk right) =====
    tiles[4][10] = T_ENEMY_FLY
    tiles[4][20] = T_ENEMY_FLY
    tiles[4][30] = T_ENEMY_FLY
    tiles[4][40] = T_ENEMY_FLY
    tiles[4][50] = T_ENEMY_FLY
    tiles[4][60] = T_ENEMY_FLY
    tiles[4][70] = T_ENEMY_FLY
    tiles[4][80] = T_ENEMY_FLY
    tiles[4][90] = T_ENEMY_FLY
    tiles[4][100] = T_ENEMY_FLY

    // Gems in top corridor
    tiles[4][15] = T_GEM
    tiles[4][35] = T_GEM
    tiles[4][55] = T_RUBY
    tiles[4][75] = T_GEM
    tiles[4][95] = T_RUBY
    tiles[4][105] = T_RING

    // KEY at col 85
    tiles[4][85] = T_KEY

    // Spikes in top corridor
    tiles[5][45] = T_SPIKE
    tiles[5][46] = T_SPIKE
    tiles[5][65] = T_SPIKE
    tiles[5][66] = T_SPIKE
    tiles[5][95] = T_SPIKE
    tiles[5][96] = T_SPIKE

    // Checkpoint in top corridor
    tiles[4][50] = T_CHECKPOINT

    // DOOR AND TROPHY at far right of top corridor
    tiles[4][117] = T_DOOR
    tiles[4][118] = T_DOOR
    tiles[4][119] = T_TROPHY

    // ===== PLAYER starts bottom-left =====
    tiles[14][3] = T_PLAYER

func dave_buildLevel19
    // Level 19: The Gauntlet
    // Four zones spanning 120 tiles, combining all Sand World mechanics.
    //   Zone A (cols 2-30):  Crumble bridge over spikes with icicles (like L16)
    //   Zone B (cols 31-60): Moving platform chains over spike pit with wind (like L17)
    //   Zone C (cols 61-90): Snake corridors with enemies (like L18)
    //   Zone D (cols 91-119): Final gauntlet combining everything, key + door

    // ===== ZONE A: CRUMBLE BRIDGE (cols 2-30) =====
    // Spike floor
    for c = 2 to 30
        tiles[15][c] = T_SPIKE
    next

    // Starting ground
    for c = 2 to 5
        tiles[12][c] = T_BRICK
    next

    // Gun on starting ground (col 4, player at col 3)
    tiles[11][4] = T_GUN

    // Crumbling bridge across zone A
    for c = 6 to 29
        tiles[12][c] = T_CRUMBLE
    next

    // Safe rest platforms within crumble bridge
    for c = 14 to 16
        tiles[12][c] = T_PLATFORM
    next
    for c = 24 to 26
        tiles[12][c] = T_PLATFORM
    next

    // Landing platform connecting zone A to zone B
    for c = 28 to 32
        tiles[12][c] = T_BRICK
    next

    // Icicles above the bridge
    tiles[2][8] = T_ICICLE
    tiles[2][12] = T_ICICLE
    tiles[2][18] = T_ICICLE
    tiles[2][22] = T_ICICLE
    tiles[2][27] = T_ICICLE

    // Flying enemies over the bridge
    tiles[10][10] = T_ENEMY_FLY
    tiles[10][20] = T_ENEMY_FLY

    // Walking enemy on rest platform
    tiles[11][25] = T_ENEMY_WALK

    // Gems
    tiles[11][8] = T_GEM
    tiles[11][15] = T_RUBY
    tiles[11][22] = T_GEM

    // Checkpoint
    tiles[11][16] = T_CHECKPOINT

    // ===== ZONE B: MOVING PLATFORMS OVER SPIKES (cols 31-60) =====
    // Spike floor
    for c = 31 to 60
        tiles[15][c] = T_SPIKE
    next

    // Player arrives on brick at row 12 cols 28-32
    // H-Mover 1: row 13, col 32 -> 40 (below island height, player jumps to island)
    tiles[13][32] = T_MOVER_H

    // Island B1 (cols 41-43, row 12)
    for c = 41 to 43
        tiles[12][c] = T_PLATFORM
    next

    // H-Mover 2: row 13, col 44 -> 52 (below island height)
    tiles[13][44] = T_MOVER_H

    // Island B2 (cols 53-55, row 12)
    for c = 53 to 55
        tiles[12][c] = T_PLATFORM
    next

    // V-Mover 3: col 57, row 13, goes up 5 tiles (reaches row 8 height)
    tiles[13][57] = T_MOVER_V

    // Island B3 (cols 57-59, row 8 - higher level)
    for c = 57 to 59
        tiles[8][c] = T_PLATFORM
    next

    // H-Mover 4: row 9, col 60 -> 68 (bridges into zone C, below corridor floor)
    tiles[9][60] = T_MOVER_H

    // Wind zone between islands B1 and B2 (push left, slows player)
    for c = 44 to 48
        tiles[11][c] = T_WIND_L
        tiles[12][c] = T_WIND_L
    next

    // Wind zone near V-mover (push right, harder to land)
    for c = 53 to 56
        tiles[10][c] = T_WIND_R
        tiles[11][c] = T_WIND_R
    next

    // Flying enemies in zone B
    tiles[10][36] = T_ENEMY_FLY
    tiles[10][48] = T_ENEMY_FLY

    // Gems
    tiles[11][41] = T_GEM
    tiles[11][51] = T_RUBY
    tiles[7][58] = T_GEM

    // Checkpoint
    tiles[11][51] = T_CHECKPOINT

    // ===== ZONE C: SNAKE CORRIDORS (cols 61-90) =====
    // Player arrives from H-mover 4 at row 8 area
    // Two corridors: top walk right, bottom walk left (reversed from L18)

    // Top corridor floor (row 8, cols 61-90)
    for c = 61 to 90
        tiles[8][c] = T_BRICK
    next
    // Top corridor ceiling (row 4, cols 61-90)
    for c = 61 to 90
        tiles[4][c] = T_BRICK
    next

    // Landing from zone B mover
    for c = 61 to 63
        tiles[8][c] = T_BRICK
    next

    // Bottom corridor floor (row 14, cols 61-90)
    for c = 61 to 90
        tiles[14][c] = T_BRICK
    next
    // Bottom corridor ceiling (row 10, cols 61-90)
    for c = 61 to 90
        tiles[10][c] = T_BRICK
    next

    // Ladder at right end: top corridor down to bottom (col 89)
    tiles[8][89] = T_EMPTY
    tiles[8][90] = T_EMPTY
    tiles[10][89] = T_EMPTY
    tiles[10][90] = T_EMPTY
    for r = 8 to 13
        tiles[r][89] = T_LADDER
    next

    // Player walks RIGHT in top corridor, climbs DOWN at col 89
    // Then walks LEFT in bottom corridor, exits at col 61

    // Flying enemies in top corridor
    tiles[6][65] = T_ENEMY_FLY
    tiles[6][73] = T_ENEMY_FLY
    tiles[6][82] = T_ENEMY_FLY

    // Spikes in top corridor
    tiles[8][70] = T_SPIKE
    tiles[8][71] = T_SPIKE
    tiles[8][83] = T_SPIKE
    tiles[8][84] = T_SPIKE

    // Walking/shooting enemies in bottom corridor
    tiles[13][85] = T_ENEMY_WALK
    tiles[13][78] = T_ENEMY_SHOOT
    tiles[13][70] = T_ENEMY_WALK
    tiles[13][65] = T_ENEMY_SHOOT

    // Spikes in bottom corridor
    tiles[14][75] = T_SPIKE
    tiles[14][76] = T_SPIKE
    tiles[14][82] = T_SPIKE
    tiles[14][83] = T_SPIKE

    // Gems in corridors
    tiles[6][68] = T_GEM
    tiles[6][78] = T_GEM
    tiles[6][86] = T_RUBY
    tiles[13][80] = T_GEM
    tiles[13][72] = T_GEM
    tiles[13][63] = T_RUBY

    // Checkpoints
    tiles[6][75] = T_CHECKPOINT
    tiles[13][72] = T_CHECKPOINT

    // Exit bottom corridor at col 61: ladder down to zone D level
    // Opening in bottom corridor floor at col 61-62
    tiles[14][61] = T_EMPTY
    tiles[14][62] = T_EMPTY

    // ===== ZONE D: FINAL GAUNTLET (cols 91-119) =====
    // Spike floor  
    for c = 91 to 119
        tiles[15][c] = T_SPIKE
    next

    // Player drops from bottom corridor (row 14) at col 61
    // Zone D is actually accessed by continuing from bottom corridor exit
    // Redirect: bottom corridor left exit leads to a platform dropping to zone D height

    // Actually, reconnect: player in bottom corridor walks left to col 61
    // Provide a bridge from zone C bottom corridor to zone D
    // Zone D entry: cols 90-92, row 12 - bridge across
    tiles[12][91] = T_BRICK
    tiles[12][92] = T_BRICK
    tiles[10][91] = T_EMPTY
    tiles[10][92] = T_EMPTY

    // Restore bottom corridor exit: player walks right in bottom to col 90
    // then continues onto bridge at row 12 into zone D (floor is row 14)
    // Wait - bottom corridor floor is row 14, bridge is row 12. 
    // Better: extend bottom corridor into zone D

    // Bottom corridor extension into zone D (floor row 14)
    for c = 91 to 93
        tiles[14][c] = T_BRICK
    next
    for c = 91 to 93
        tiles[10][c] = T_BRICK
    next

    // Crumble bridge in zone D (row 12, cols 94-108)
    for c = 94 to 108
        tiles[12][c] = T_CRUMBLE
    next

    // Ladder from bottom corridor up to crumble bridge (col 93)
    for r = 11 to 13
        tiles[r][93] = T_LADDER
    next
    tiles[10][93] = T_EMPTY

    // Safe platform in crumble bridge
    for c = 100 to 102
        tiles[12][c] = T_PLATFORM
    next

    // Shooting enemy on safe platform
    tiles[11][101] = T_ENEMY_SHOOT

    // Wind pushing left above crumble bridge (player feels push while walking)
    for c = 104 to 108
        tiles[10][c] = T_WIND_L
        tiles[11][c] = T_WIND_L
    next

    // Landing after crumble bridge
    for c = 109 to 111
        tiles[12][c] = T_BRICK
    next

    // V-Mover to reach key (col 113, from row 12 going up)
    tiles[12][113] = T_MOVER_V

    // KEY platform (cols 114-116, row 7)
    for c = 114 to 116
        tiles[7][c] = T_PLATFORM
    next
    tiles[6][115] = T_KEY

    // Icicles above key
    tiles[2][114] = T_ICICLE
    tiles[2][116] = T_ICICLE

    // Door platform (cols 116-119, row 12)
    for c = 116 to 119
        tiles[12][c] = T_BRICK
    next

    // DOOR AND TROPHY
    tiles[11][118] = T_DOOR
    tiles[11][119] = T_TROPHY

    // Flying enemies in zone D
    tiles[10][96] = T_ENEMY_FLY
    tiles[10][105] = T_ENEMY_FLY
    tiles[5][115] = T_ENEMY_FLY

    // Final gems
    tiles[11][95] = T_GEM
    tiles[11][101] = T_RING
    tiles[6][114] = T_GEM

    // Final checkpoint
    tiles[11][110] = T_CHECKPOINT

    // ===== PLAYER starts at zone A =====
    tiles[11][3] = T_PLAYER

func dave_buildLevel20
    // Level 20: The Prison
    // A long empty corridor. No enemies, no hazards at first.
    // Story messages appear as the player walks right.
    // The golden "YES" ring at col 95 grants the key.
    // Door at the far end.

    // ===== PRISON CORRIDOR =====
    // Floor (row 15 already brick from loadLevel)
    // Ceiling is row 1 (already brick)
    // Walls at cols 1 and 120 (already brick)

    // Upper ceiling to create a corridor feel (row 4)
    for c = 2 to 119
        tiles[4][c] = T_BRICK
    next

    // Prison bars (columns of brick every 15 tiles for atmosphere)
    for c = 15 to 105 step 15
        for r = 5 to 14
            if r = 8 or r = 11
                // gaps in bars for walking through
            else
                tiles[r][c] = T_BRICK
            ok
        next
    next

    // Starting area - small room feel (cols 2-12)
    // Empty, just the player alone

    // ===== MESSAGE ZONES (triggered by player X position in HUD) =====
    // Zone 1 (cols 15-28): "There is no key on this level"
    // Zone 2 (cols 30-43): "Life is not fair..."
    // Zone 3 (cols 45-58): "You killed many NPCs..."
    // Zone 4 (cols 60-73): "You will stay in prison forever!"
    // Zone 5 (cols 75-88): "Do you love Ring?"
    // Zone 6 (cols 89-100): The golden YES

    // ===== THE GOLDEN "YES" =====
    // A gold ring on the floor - the player walks into it
    tiles[14][95] = T_RING    // The YES answer - grants key on level 20

    // ===== DOOR at far end =====
    tiles[14][115] = T_DOOR
    tiles[13][115] = T_DOOR
    tiles[14][116] = T_TROPHY

    // ===== ATMOSPHERE =====
    // Scattered gems as breadcrumbs leading the player right
    tiles[14][10] = T_GEM
    tiles[14][25] = T_GEM
    tiles[14][40] = T_GEM
    tiles[14][55] = T_GEM
    tiles[14][70] = T_GEM
    tiles[14][85] = T_GEM

    // ===== PLAYER =====
    tiles[14][3] = T_PLAYER
