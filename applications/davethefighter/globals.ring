/*
**  Dave the Fighter - Global Variables
**  Game state, player, level data, enemies, bullets, particles, timers, sound
*/

// Game state
gameState       = ST_TITLE
level           = 1
maxLevel        = 20
score           = 0
lives           = 3
hasKey          = false
doorOpen        = false
hasGun          = false

// Current level width (set per level)
curLvlW         = LVL_W

// Player
px              = 2.0
py              = 12.0
pvx             = 0.0
pvy             = 0.0
pOnGround       = false
pOnLadder       = false
pClimbFrame     = 0.0
pFacingRight    = true
pAnimTime       = 0.0
pWalkFrame      = 0.0
pShootCooldown  = 0.0
pOnMover        = false

// Checkpoint
checkpointX     = -1
checkpointY     = -1
checkpointActive = false

// Camera
camMode         = CAM_SIDE
cam             = NULL

// Level data
tiles           = []
gemsLeft        = 0
totalGems       = 0

// Moving platforms: [x, y, vx, vy, rangeMin, rangeMax, type(H/V), width]
movers          = []

// Falling icicles: [x, y, state(0=hanging,1=shaking,2=falling,3=gone), shakeTimer, vy]
icicles         = []

// Crumbling platforms: [col, row, timer, state(0=solid,1=crumbling,2=gone)]
crumbles        = []

// Wind zones: [col, row, direction(-1=left,+1=right)]
windZones       = []

// Enemies: [x, y, vx, vy, type, alive, animT, shootTimer]
enemies         = []

// Player bullets: [x, y, vx, vy, life]
bullets         = []

// Enemy bullets: [x, y, vx, vy, life]
eBullets        = []

// Particles: [x, y, vx, vy, life, maxLife, r, g, b, size]
particles       = []

// Popups: [x, y, text, life]
popups          = []

// Timer
animTime        = 0.0
dyingTimer      = 0.0
levelUpTimer    = 0.0

// Sound effects and music
sndJump         = NULL
sndGem          = NULL
sndRuby         = NULL
sndRing         = NULL
sndKey          = NULL
sndDoor         = NULL
sndTrophy       = NULL
sndShoot        = NULL
sndEnemyShoot   = NULL
sndEnemyDie     = NULL
sndHurt         = NULL
sndGunPickup    = NULL
bgMusic         = NULL

// Title screen fireworks: [active, x, y, vx, vy, life, hue, size]
FW_MAX = 300
fwActive = list(FW_MAX)
fwX = list(FW_MAX)
fwY = list(FW_MAX)
fwVX = list(FW_MAX)
fwVY = list(FW_MAX)
fwLife = list(FW_MAX)
fwHue = list(FW_MAX)
fwSize = list(FW_MAX)
for _fwi = 1 to FW_MAX
    fwActive[_fwi] = 0
next
fwTimer = 0.0

// Title screen twinkling stars
STAR_MAX = 80
tsX = list(STAR_MAX)
tsY = list(STAR_MAX)
tsPhase = list(STAR_MAX)
tsSpeed = list(STAR_MAX)
tsBright = list(STAR_MAX)
tsSz = list(STAR_MAX)
for _si = 1 to STAR_MAX
    tsX[_si] = GetRandomValue(5, 1195)
    tsY[_si] = GetRandomValue(5, 695)
    tsPhase[_si] = GetRandomValue(0, 628) / 100.0
    tsSpeed[_si] = GetRandomValue(15, 45) / 10.0
    tsBright[_si] = GetRandomValue(80, 255)
    tsSz[_si] = GetRandomValue(10, 25) / 10.0
next

// Title screen shooting stars
SS_MAX = 5
ssActive = list(SS_MAX)
ssX = list(SS_MAX)
ssY = list(SS_MAX)
ssVX = list(SS_MAX)
ssVY = list(SS_MAX)
ssLife = list(SS_MAX)
ssLen = list(SS_MAX)
ssHue = list(SS_MAX)
for _ssi = 1 to SS_MAX
    ssActive[_ssi] = 0
next
ssTimer = 0.0

// Title screen Dave animation
titleDaveX = -50.0
titleDaveDir = 1
titleDaveFrame = 0.0
titleDaveJumpY = 0.0
titleDaveJumpV = 0.0
titleDaveOnGround = true
titleDaveJumpTimer = 0.0
