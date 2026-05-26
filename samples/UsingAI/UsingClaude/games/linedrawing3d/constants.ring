/*
**  ld_constants.ring
**  Constants for Line Drawing 3D
*/

// Screen size (will be set to monitor size for fullscreen)
SCREEN_W = 1024
SCREEN_H = 768

// Map tile types
T_EMPTY     = 0
T_WALL1     = 1    // Blue stone wall
T_WALL2     = 2    // Dark stone wall
T_WALL3     = 3    // Gray stone wall
T_DOOR      = 4    // Locked door (needs puzzle)
T_DOOR_OPEN = 5    // Unlocked/open door
T_EXIT      = 7    // Level exit trigger
T_PUZZLE    = 8    // Puzzle panel location (visual only, on wall)

// Game states
ST_TITLE    = 0
ST_EXPLORE  = 1    // First person exploration
ST_PUZZLE   = 2    // Solving a puzzle panel
ST_SOLVED   = 3    // Puzzle just solved (brief celebration)
ST_WON      = 4    // All puzzles solved - game won!

// Puzzle constraint types
CONS_NONE   = 0
CONS_BLACK  = 1
CONS_WHITE  = 2

// Edge states
EDGE_NORMAL  = 0
EDGE_BROKEN  = 1

// Node markers
NODE_NONE   = 0
NODE_START  = 1
NODE_EXIT   = 2
NODE_DOT    = 3

PI = 3.14159265

// Map dimensions
MAP_W = 40
MAP_H = 40

// Solver speed
SOLVER_WAIT = 0.12

// Sphere values per type
SPHERE_VALUES = [100, 200, 300, 100, 200, 300, 100, 200, 300, 100]
// cyan=0, purple=1, black=2 (cycling)
