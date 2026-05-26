/*
**  globals.ring - Constants & Global Variables
**  Code Rooms 3D
*/

// =============================================================
// Screen & World Constants
// =============================================================

SCREEN_W    = 1200
SCREEN_H    = 750
CELL        = 2.0
WALL_H      = 2.0

// Tile types
T_EMPTY     = 0
T_FLOOR     = 1
T_WALL      = 2
T_PLAYER    = 3
T_BLOCK     = 4
T_SLOT      = 5
T_DOOR      = 6
T_DOOROPEN  = 7
T_NEXTROOM  = 8

// Game states
GS_TITLE    = 0
GS_PLAYING  = 1
GS_SOLVED   = 2
GS_WON      = 3
GS_TRANS    = 4

// Camera modes
CAM_TOP     = 0
CAM_ANGLE   = 1
CAM_FOLLOW  = 2

// Max
MAX_BLOCKS  = 16
MAX_SLOTS   = 16
MAX_ROOMS   = 10

// =============================================================
// Game Variables
// =============================================================

GRID_W      = 0
GRID_H      = 0
tiles       = []

px          = 0
py          = 0
pDir        = 0
pAnimX      = 0.0
pAnimZ      = 0.0
pTargX      = 0.0
pTargZ      = 0.0
pMoving     = 0
pBobTime    = 0.0

blocks      = []
blockCount  = 0
slots       = []
slotCount   = 0

currentRoom = 1
roomTitle   = ""
roomCode    = ""

doorRow     = 0
doorCol     = 0
doorOpen    = 0

cam         = NULL
camMode     = CAM_FOLLOW

gameState   = GS_TITLE
animTime    = 0.0
solveTimer  = 0.0
transTimer  = 0.0
moveCount   = 0
moveTimer   = 0.0

undoStack   = []
undoMax     = 100

particles   = []
pLen        = 0

projSX      = 0
projSY      = 0

// =============================================================
// Weather Constants & Variables
// =============================================================

W_CLEAR   = 1
W_CLOUDY  = 2
W_RAIN    = 3
W_STORM   = 4
W_SNOW    = 5
W_FOG     = 6

roomWeather = [W_RAIN, W_SNOW, W_STORM, W_CLOUDY, W_FOG, W_CLEAR, W_STORM, W_SNOW, W_RAIN, W_CLEAR]
currentWeather = W_CLEAR
wAnimTime  = 0.0
wDayTime   = 0.35
wWindSpeed = 5.0
wWindDir   = 1.0
wFlashAlpha = 0.0

// Weather clouds
WC_MAX = 20
wcX = list(WC_MAX)  wcY = list(WC_MAX)  wcW = list(WC_MAX)
wcH = list(WC_MAX)  wcAlpha = list(WC_MAX)  wcActive = list(WC_MAX)
wcSpeed = list(WC_MAX)  wcDark = list(WC_MAX)
wcCount = 0

// Weather drops (rain/snow)
WD_MAX = 800
wdX = list(WD_MAX)  wdY = list(WD_MAX)  wdVX = list(WD_MAX)
wdVY = list(WD_MAX)  wdActive = list(WD_MAX)  wdSize = list(WD_MAX)
wdAlpha = list(WD_MAX)

// Lightning bolts
WL_MAX = 3
wlActive = list(WL_MAX)  wlX = list(WL_MAX)  wlTimer = list(WL_MAX)
wlSegX = []  wlSegY = []

// Stars
WS_MAX = 150
wsX = list(WS_MAX)  wsY = list(WS_MAX)
wsBright = list(WS_MAX)  wsPhase = list(WS_MAX)

// Fog
WF_MAX = 30
wfX = list(WF_MAX)  wfY = list(WF_MAX)  wfW = list(WF_MAX)
wfAlpha = list(WF_MAX)  wfSpeed = list(WF_MAX)

// =============================================================
// Colors - Stone Palace Palette
// =============================================================

colFloor1   = RAYLIBColor(165, 155, 185, 240)
colFloor2   = RAYLIBColor(145, 138, 170, 240)
colFloorEdge = RAYLIBColor(120, 110, 145, 255)
colWall     = RAYLIBColor(140, 105, 125, 255)
colWallTop  = RAYLIBColor(170, 145, 160, 255)
colWallDark = RAYLIBColor(90, 65, 85, 255)
colWallMortar = RAYLIBColor(80, 60, 80, 200)
colDoor     = RAYLIBColor(160, 50, 50, 255)
colDoorOpen = RAYLIBColor(50, 160, 70, 255)
colSlotBase = RAYLIBColor(80, 110, 160, 255)
colSlotOK   = RAYLIBColor(40, 160, 60, 255)
colPlayer   = RAYLIBColor(180, 60, 50, 255)
colPlayerEye = RAYLIBColor(255, 255, 255, 255)

// =============================================================
// Sound & Music Variables
// =============================================================

sndStep     = NULL
sndPush     = NULL
sndPlace    = NULL
sndCorrect  = NULL
sndWrong    = NULL
sndSolved   = NULL
sndDoor     = NULL
sndTransit  = NULL
sndUndo     = NULL
sndBump     = NULL
sndMenu     = NULL
sndWin      = NULL
bgMusic     = NULL

// =============================================================
// Temporary / Loop Variables
// =============================================================

dt          = 0.0
monIdx      = 0
monW        = 0
monH        = 0
anyMoving   = 0
alpha       = 0
fa          = 0

// =============================================================
// Initialize Weather Arrays
// =============================================================

for i = 1 to WC_MAX  wcActive[i] = 0  next
for i = 1 to WD_MAX  wdActive[i] = 0  next
for i = 1 to WL_MAX
    wlActive[i] = 0
    add(wlSegX, [])
    add(wlSegY, [])
next
for i = 1 to WS_MAX
    wsX[i] = GetRandomValue(0, SCREEN_W)
    wsY[i] = GetRandomValue(10, SCREEN_H)
    wsBright[i] = GetRandomValue(100, 255)
    wsPhase[i] = GetRandomValue(0, 628) / 100.0
next
for i = 1 to WF_MAX
    wfX[i] = GetRandomValue(-200, SCREEN_W + 200) * 1.0
    wfY[i] = GetRandomValue(200, 400) * 1.0
    wfW[i] = GetRandomValue(150, 400) * 1.0
    wfAlpha[i] = GetRandomValue(30, 80)
    wfSpeed[i] = GetRandomValue(5, 25) * 1.0
next
