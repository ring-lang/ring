/*
**  ld_globals.ring
**  Global variables for Line Drawing 3D
*/

// Map grid
map = list(MAP_H, MAP_W)

// Player state
pX = 0.0
pZ = 0.0
pAngle = 0.0

// Camera
cam = NULL
camYaw = 0.0
camPitch = 0.0
mouseSens = 0.003
centerX = SCREEN_W / 2
centerY = SCREEN_H / 2

// Game
gameState = ST_TITLE
animTime = 0.0
showMap = true
roomBounds = []
msgText = ""
msgTimer = 0.0
msgCharCount = 0         // how many characters currently revealed
msgCharSpeed = 30.0      // characters per second
msgCharAccum = 0.0       // accumulator for character timing

// Doors: [row, col, openAmount, puzzleIndex, solved]
doors = []

// Puzzle panels: [row, col, wallSide, doorIndex, puzzleDefIndex]
puzzlePanels = []

// Active puzzle state (when in ST_PUZZLE mode)
activePanelIdx = 0
puzzGridW = 0
puzzGridH = 0
puzzStartR = 0
puzzStartC = 0
puzzExitR = 0
puzzExitC = 0
puzzNodeMarker = []
puzzHEdge = []
puzzVEdge = []
puzzCellCons = []
puzzPathNodes = []
puzzCursorR = 0
puzzCursorC = 0
puzzSolverActive = false
puzzSolverStep = 0
puzzSolverDelay = 0.0
puzzHintPath = []
puzzShowHint = false
puzzValidTimer = 0.0
puzzFailed = false
puzzParticles = []

// Mouse drag drawing (line follows mouse)
puzzMouseDragging = false
puzzMouseDrawX = 0.0
puzzMouseDrawY = 0.0

// Puzzle screen projection (for mouse support)
puzzProjSX = 0.0
puzzProjSY = 0.0

// Puzzle grid screen layout cache
puzzOffsetX = 0
puzzOffsetY = 0
puzzCellSz = 0

// Puzzle definitions (all 15 from Witness3D)
puzzleDefs = []

// Level complete timer
solvedTimer = 0.0

// Sphere collectibles
sphereList = []
sphereTextures = []
sphereScore = 0

// Firework particles (3D celebration on sphere collect)
// Each: [x, y, z, vx, vy, vz, life, r, g, b]
fireworkParticles = []
fireworkPendingQuote = ""
fireworkActive = false

// Life quotes - one unique quote per sphere collected
sphereQuoteIdx = 0
sphereQuotes = [
    "Every step forward is a step toward something better.",
    "The quietest moments often hold the deepest meaning.",
    "You carry more strength than you realize.",
    "Small things done with care change everything.",
    "There is always light for those who look up.",
    "Patience is not waiting - it is growing.",
    "A calm mind sees the way through any maze.",
    "You are exactly where you need to be right now.",
    "The best discoveries come from unexpected paths.",
    "Kindness is a language everyone understands.",
    "Each new day is a page waiting to be written.",
    "What feels impossible today becomes tomorrow's memory.",
    "The world is richer because you are in it.",
    "Peace begins the moment you choose not to rush.",
    "A single spark of curiosity can light the way.",
    "Courage is not the absence of fear but one step beyond it.",
    "The simplest joys are often the most lasting.",
    "You do not need all the answers to keep moving.",
    "Every ending makes room for a new beginning.",
    "What you give to the world comes back tenfold.",
    "Breathe deeply - this moment is yours.",
    "The journey matters more than the destination."
]

// Textures and map model
texWall = NULL
mapModel = NULL
mapImage = NULL
mapTexture = NULL
mapModelPos = NULL
hasMapModel = false

// Audio handles (set during init)
bgMusic = NULL
sndFootstep = NULL
sndDoorOpen = NULL
sndPuzzleOpen = NULL
sndPuzzleSolved = NULL
sndPuzzleFail = NULL
sndWinFanfare = NULL
sndPathDraw = NULL
sndSphereCollect = NULL
footstepTimer = 0.0
