/*
**  Dave the Fighter - Game Constants
**  Screen, tiles, states, physics, and level dimensions
*/

// Screen
SCREEN_W        = 1024
SCREEN_H        = 768
CELL_SZ         = 1.0

// Tile types
T_EMPTY         = 0
T_BRICK         = 1
T_PLATFORM      = 2
T_GEM           = 3
T_RUBY          = 4
T_RING          = 5
T_KEY           = 6
T_DOOR          = 7
T_TROPHY        = 8
T_SPIKE         = 9
T_LADDER        = 10
T_ENEMY_WALK    = 11
T_ENEMY_FLY     = 12
T_PLAYER        = 13
T_EXIT          = 14
T_GUN           = 15
T_ENEMY_SHOOT   = 16
T_MOVER_H       = 17
T_MOVER_V       = 18
T_ICICLE        = 19
T_CRUMBLE       = 20
T_WIND_L        = 21
T_WIND_R        = 22
T_CHECKPOINT    = 23

// Game states
ST_TITLE        = 0
ST_PLAYING      = 1
ST_PAUSED       = 2
ST_DYING        = 3
ST_LEVELUP      = 4
ST_GAMEOVER     = 5
ST_WON          = 6

// Camera modes
CAM_SIDE        = 0
CAM_ANGLE       = 1
CAM_TOP         = 2
CAM_COUNT       = 3

// Physics
GRAVITY         = 18.0
JUMP_FORCE      = 11.0
MOVE_SPEED      = 5.0
MAX_FALL        = 15.0
WIND_FORCE      = 3.5

// Level dimensions (levels 11-15 use LVL_W_WIDE, levels 16-20 use LVL_W_ULTRA)
LVL_W           = 30
LVL_H           = 16
LVL_W_WIDE      = 60
LVL_W_ULTRA     = 120
