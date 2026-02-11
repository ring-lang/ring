/*
**  globals.ring
**  All global variables for 3D Tank Battle - Ultimate Edition
*/

// =============================================================
// Sound & Music Resources
// =============================================================

sndFire         = NULL
sndHitWall      = NULL
sndExplosion    = NULL
sndPowerup      = NULL
sndPlayerDeath  = NULL
sndSteelHit     = NULL
sndBrickBreak   = NULL
sndLevelClear   = NULL
sndGameOver     = NULL
sndEnemyHit     = NULL
sndBomb         = NULL
sndEngine       = NULL
sndVictory      = NULL
musMenu         = NULL
musBattle       = NULL
musicPlaying    = 0     // 0=none, 1=menu, 2=battle

// =============================================================
// Global Variables
// =============================================================

gameState       = ST_TITLE
level           = 1
maxLevel        = 12
score           = 0
lives           = 3
highScore       = 0

// Grid
tiles           = []

// Player tank
px = 9.0
py = 1.0
pdir = DIR_UP
palive = true
pshield = 0.0
pspeedBoost = 0.0
pAnimTime = 0.0
pMoveAnim = 0.0
pFireCooldown = 0.0

// Player bullets
pbullets = []

// Enemy tanks: [x, y, dir, speed, alive, hp, type, animT, fireTimer, moveTimer, frozen, stealthTimer, visible]
enemies = []
enemySpawnTimer = 0.0
enemiesLeft = 0
enemiesKilled = 0

// Enemy bullets
ebullets = []

// Explosions: [x, y, timer, maxTime, size]
explosions = []

// Power-ups: [x, y, type, timer, active]
powerups = []

// Particles: [x, y, z, vx, vy, vz, life, maxLife, r, g, b, size]
particles = []

// Spawn points for enemies (top of map)
espawnX = [4.0, 13.0, 22.0]
espawnIdx = 1

// Base position
baseR = 25
baseC = 13

// Camera
camMode = CAM_CLOSE
cam = NULL

// Animation
animTime = 0.0
levelUpTimer = 0.0
gameOverTimer = 0.0

// Combo system
comboCount = 0
comboTimer = 0.0
comboDuration = 3.0
lastComboText = ""
comboDisplayTimer = 0.0

// Screen shake
shakeIntensity = 0.0
shakeDuration = 0.0
shakeTimer = 0.0

// Global freeze & lava damage
globalFreezeTimer = 0.0
lavaDamageTimer = 0.0

// Difficulty scaling
levelEnemyCount = 0
levelMaxOnScreen = 0

// Stats
totalKills = 0
totalShotsFired = 0
accuracyHits = 0
