/*
**  Helicopter Gunship 3D - Using RingRayLib
**  ==========================================
**  Fly your attack helicopter over terrain!
**  Destroy ground targets, rescue hostages,
**  and dodge anti-air fire in intense missions!
**
**  Controls:
**    W / Up Arrow     -  Pitch forward (accelerate)
**    S / Down Arrow   -  Pitch backward (decelerate)
**    A / Left Arrow   -  Yaw left (turn)
**    D / Right Arrow  -  Yaw right (turn)
**    Q               -  Ascend
**    E               -  Descend
**    Space           -  Fire machine gun
**    R               -  Fire rocket
**    L               -  Land (near rescue zone)
**    Tab             -  Toggle radar zoom
**    C               -  Cycle camera mode
**    P               -  Pause
**    ESC             -  Exit
**
**  Missions:
**    - Destroy all enemy targets (tanks, SAMs, bunkers)
**    - Rescue hostages from marked landing zones
**    - Survive anti-air fire and complete objectives
**
**  Enemy Types:
**    Tank (olive)     -  Ground armor, fires shells
**    SAM Site (red)   -  Launches homing missiles
**    AA Gun (gray)    -  Rapid anti-air cannon
**    Bunker (brown)   -  Fortified, high HP
**    Radar (white)    -  Boosts enemy accuracy (destroy first!)
**
**  Power-ups:
**    Repair (green)   -  Restore HP
**    Ammo (yellow)    -  Restore rockets
**    Shield (blue)    -  Temporary invincibility
**    Airstrike (red)  -  Destroy all visible enemies
**
**  Sound files (in sounds/ folder):
**    fire.wav, hit_wall.wav, explosion.wav,
**    powerup.wav, player_death.wav, steel_hit.wav,
**    brick_break.wav, level_clear.wav, game_over.wav,
**    enemy_hit.wav, bomb.wav, engine.wav, victory.wav,
**    menu_music.wav, battle_music.wav
*/

load "raylib.ring"

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
musicPlaying    = 0

// =============================================================
// Constants
// =============================================================

SCREEN_W        = 1024
SCREEN_H        = 768

PI              = 3.14159265
DEG2RAD         = PI / 180.0

TERRAIN_SIZE    = 200.0
TERRAIN_HALF    = 100.0
TERRAIN_GRID    = 40
TERRAIN_CELL    = TERRAIN_SIZE / TERRAIN_GRID

HELI_MAX_HP     = 100
HELI_MAX_ROCKETS = 12
BULLET_SPEED    = 80.0
ROCKET_SPEED    = 50.0
BULLET_LIFETIME = 2.0
ROCKET_LIFETIME = 3.5

MAX_PBULLETS    = 30
MAX_ROCKETS     = 8
MAX_EBULLETS    = 40
MAX_MISSILES    = 10

ST_TITLE        = 0
ST_PLAYING      = 1
ST_PAUSED       = 2
ST_GAMEOVER     = 3
ST_MISSIONINTRO = 4
ST_MISSIONCLEAR = 5
ST_VICTORY      = 6

CAM_CHASE       = 0
CAM_COCKPIT     = 1
CAM_TOP         = 2
CAM_COUNT       = 3

// =============================================================
// Game State
// =============================================================

gameState       = ST_TITLE
score           = 0
highScore       = 0
lives           = 3
mission         = 1
maxMission      = 8
missionTimer    = 0.0
animTime        = 0.0
gameOverTimer   = 0.0

// =============================================================
// Helicopter (Player)
// =============================================================

hx              = 0.0
hy              = 15.0
hz              = 0.0
hYaw            = 0.0
hPitch          = 0.0
hRoll           = 0.0
hSpeedFwd       = 0.0
hSpeedVert      = 0.0
hHP             = 100
hRockets        = 12
hAlive          = true
hShield         = 0.0
hFireCooldown   = 0.0
hRocketCooldown = 0.0
hRotorAngle     = 0.0
hLanding        = false
hLandTimer      = 0.0

// Camera
cam             = NULL
camMode         = CAM_CHASE

// =============================================================
// Terrain heightmap
// =============================================================

terrainH        = []

// =============================================================
// Bullets & Rockets
// bullet: [x, y, z, vx, vy, vz, alive, timer]
// rocket: [x, y, z, vx, vy, vz, alive, timer]
// =============================================================

pbullets        = []
prockets        = []

// =============================================================
// Enemy bullets & missiles
// ebullet: [x, y, z, vx, vy, vz, alive, timer]
// missile: [x, y, z, vx, vy, vz, alive, timer, targetX, targetY, targetZ]
// =============================================================

ebullets        = []
missiles        = []

// =============================================================
// Enemies (ground targets)
// enemy: [x, y, z, type, hp, maxHp, alive, fireTimer, animTime, angle, alerted]
// type: 1=tank, 2=SAM, 3=AA gun, 4=bunker, 5=radar
// =============================================================

enemies         = []

// =============================================================
// Rescue zones
// rescue: [x, z, rescued, hostageCount, landingTimer]
// =============================================================

rescueZones     = []
totalRescued    = 0
rescueTarget    = 0

// =============================================================
// Power-ups
// powerup: [x, y, z, type, timer, active]
// type: 1=repair, 2=ammo, 3=shield, 4=airstrike
// =============================================================

powerups        = []

// =============================================================
// Explosions & Particles
// =============================================================

explosions      = []
particles       = []

// =============================================================
// Effects
// =============================================================

shakeIntensity  = 0.0
shakeDuration   = 0.0
shakeTimer      = 0.0
hitFlashTimer   = 0.0
comboCount      = 0
comboTimer      = 0.0
comboDuration   = 3.0
lastComboText   = ""
comboDisplayTimer = 0.0

// =============================================================
// Radar
// =============================================================

radarZoom       = 1

// =============================================================
// Stats
// =============================================================

totalKills      = 0
totalShots      = 0
totalHits       = 0
maxCombo        = 0

// =============================================================
// Main Program
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Helicopter Gunship 3D - Ring RayLib")
SetTargetFPS(60)

InitAudioDevice()
heli_loadSounds()

cam = Camera3D(0, 0, 0, 0, 0, 0, 0, 1, 0, 60, CAMERA_PERSPECTIVE)

heli_generateTerrain()

while !WindowShouldClose()
    dt = GetFrameTime()
    if dt > 0.05 dt = 0.05 ok
    animTime += dt

    heli_updateMusic()
    heli_handleInput(dt)
    heli_update(dt)

    if shakeTimer > 0
        shakeTimer -= dt
        if shakeTimer < 0 shakeTimer = 0 ok
    ok

    BeginDrawing()
        ClearBackground(RAYLIBColor(40, 60, 90, 255))

        heli_updateCamera()
        BeginMode3D(cam)
            heli_drawSky()
            heli_drawTerrain()
            heli_drawEnemies3D()
            heli_drawRescueZones3D()
            heli_drawBullets3D()
            heli_drawPowerups3D()
            heli_drawExplosions3D()
            heli_drawParticles3D()
            heli_drawHeli3D()
        EndMode3D()

        heli_drawHUD()
        heli_drawRadar()
        heli_drawCockpitOverlay()

    EndDrawing()
end

heli_unloadSounds()
CloseAudioDevice()
CloseWindow()

// =============================================================
// Sound Loading
// =============================================================

func heli_loadSounds
    if heli_fexists("sounds/fire.wav")
        sndFire        = LoadSound("sounds/fire.wav")
        sndHitWall     = LoadSound("sounds/hit_wall.wav")
        sndExplosion   = LoadSound("sounds/explosion.wav")
        sndPowerup     = LoadSound("sounds/powerup.wav")
        sndPlayerDeath = LoadSound("sounds/player_death.wav")
        sndSteelHit    = LoadSound("sounds/steel_hit.wav")
        sndBrickBreak  = LoadSound("sounds/brick_break.wav")
        sndLevelClear  = LoadSound("sounds/level_clear.wav")
        sndGameOver    = LoadSound("sounds/game_over.wav")
        sndEnemyHit    = LoadSound("sounds/enemy_hit.wav")
        sndBomb        = LoadSound("sounds/bomb.wav")
        sndEngine      = LoadSound("sounds/engine.wav")
        sndVictory     = LoadSound("sounds/victory.wav")
        SetSoundVolume(sndFire, 0.6)
        SetSoundVolume(sndExplosion, 0.8)
        SetSoundVolume(sndHitWall, 0.4)
        SetSoundVolume(sndPowerup, 0.6)
        SetSoundVolume(sndPlayerDeath, 0.9)
        SetSoundVolume(sndEnemyHit, 0.5)
        SetSoundVolume(sndBomb, 1.0)
        SetSoundVolume(sndEngine, 0.12)
    ok
    if heli_fexists("sounds/menu_music.wav")
        musMenu = LoadMusicStream("sounds/menu_music.wav")
        SetMusicVolume(musMenu, 0.4)
    ok
    if heli_fexists("sounds/battle_music.wav")
        musBattle = LoadMusicStream("sounds/battle_music.wav")
        SetMusicVolume(musBattle, 0.35)
    ok

func heli_unloadSounds
    if sndFire != NULL UnloadSound(sndFire) ok
    if sndHitWall != NULL UnloadSound(sndHitWall) ok
    if sndExplosion != NULL UnloadSound(sndExplosion) ok
    if sndPowerup != NULL UnloadSound(sndPowerup) ok
    if sndPlayerDeath != NULL UnloadSound(sndPlayerDeath) ok
    if sndSteelHit != NULL UnloadSound(sndSteelHit) ok
    if sndBrickBreak != NULL UnloadSound(sndBrickBreak) ok
    if sndLevelClear != NULL UnloadSound(sndLevelClear) ok
    if sndGameOver != NULL UnloadSound(sndGameOver) ok
    if sndEnemyHit != NULL UnloadSound(sndEnemyHit) ok
    if sndBomb != NULL UnloadSound(sndBomb) ok
    if sndEngine != NULL UnloadSound(sndEngine) ok
    if sndVictory != NULL UnloadSound(sndVictory) ok
    if musMenu != NULL UnloadMusicStream(musMenu) ok
    if musBattle != NULL UnloadMusicStream(musBattle) ok

func heli_updateMusic
    if musMenu = NULL or musBattle = NULL return ok
    if gameState = ST_TITLE
        if musicPlaying != 1
            StopMusicStream(musBattle)
            PlayMusicStream(musMenu)
            musicPlaying = 1
        ok
        UpdateMusicStream(musMenu)
    ok
    if gameState = ST_PLAYING or gameState = ST_MISSIONINTRO
        if musicPlaying != 2
            StopMusicStream(musMenu)
            PlayMusicStream(musBattle)
            musicPlaying = 2
        ok
        UpdateMusicStream(musBattle)
    ok
    if gameState = ST_PAUSED
        if musicPlaying = 2
            PauseMusicStream(musBattle)
            musicPlaying = 3
        ok
    ok
    if gameState = ST_GAMEOVER or gameState = ST_VICTORY
        if musicPlaying != 0
            StopMusicStream(musBattle)
            StopMusicStream(musMenu)
            musicPlaying = 0
        ok
    ok

// =============================================================
// Terrain Generation
// =============================================================

func heli_generateTerrain
    terrainH = list(TERRAIN_GRID + 1)
    for r = 1 to TERRAIN_GRID + 1
        terrainH[r] = list(TERRAIN_GRID + 1)
        for c = 1 to TERRAIN_GRID + 1
            // Multi-octave noise for natural terrain
            rx = (c - 1.0) / TERRAIN_GRID
            rz = (r - 1.0) / TERRAIN_GRID
            h = sin(rx * 3.0) * cos(rz * 2.5) * 4.0
            h += sin(rx * 7.0 + 1.3) * cos(rz * 6.0 + 0.7) * 2.0
            h += sin(rx * 13.0 + 2.1) * sin(rz * 11.0 + 3.3) * 1.0
            // Valley in center for gameplay
            distFromCenter = heli_dist(rx - 0.5, rz - 0.5, 0, 0) * 2.0
            if distFromCenter < 0.3
                h = h * distFromCenter / 0.3
            ok
            // Clamp minimum
            if h < 0.2 h = 0.2 ok
            terrainH[r][c] = h
        next
    next

func heli_getTerrainHeight tx, tz
    // Convert world coords to grid coords
    gx = (tx + TERRAIN_HALF) / TERRAIN_CELL
    gz = (tz + TERRAIN_HALF) / TERRAIN_CELL
    gc = floor(gx) + 1
    gr = floor(gz) + 1
    if gc < 1 gc = 1 ok
    if gc > TERRAIN_GRID gc = TERRAIN_GRID ok
    if gr < 1 gr = 1 ok
    if gr > TERRAIN_GRID gr = TERRAIN_GRID ok
    // Bilinear interpolation
    fx = gx - floor(gx)
    fz = gz - floor(gz)
    gc2 = gc + 1
    gr2 = gr + 1
    if gc2 > TERRAIN_GRID + 1 gc2 = TERRAIN_GRID + 1 ok
    if gr2 > TERRAIN_GRID + 1 gr2 = TERRAIN_GRID + 1 ok
    h00 = terrainH[gr][gc]
    h10 = terrainH[gr][gc2]
    h01 = terrainH[gr2][gc]
    h11 = terrainH[gr2][gc2]
    h = h00 * (1-fx) * (1-fz) + h10 * fx * (1-fz) + h01 * (1-fx) * fz + h11 * fx * fz
    return h

// =============================================================
// Mission Setup
// =============================================================

func heli_loadMission m
    enemies = []
    rescueZones = []
    powerups = []
    pbullets = []
    prockets = []
    ebullets = []
    missiles = []
    explosions = []
    particles = []
    totalRescued = 0
    comboCount = 0
    comboTimer = 0.0
    comboDisplayTimer = 0.0
    shakeTimer = 0.0
    hitFlashTimer = 0.0
    hFireCooldown = 0.0
    hRocketCooldown = 0.0
    hLanding = false
    hLandTimer = 0.0

    // Reset helicopter position
    hx = 0.0
    hy = 15.0
    hz = -80.0
    hYaw = 0.0
    hPitch = 0.0
    hRoll = 0.0
    hSpeedFwd = 0.0
    hSpeedVert = 0.0
    hHP = HELI_MAX_HP
    hRockets = HELI_MAX_ROCKETS
    hAlive = true
    hShield = 0.0

    // Difficulty scaling
    baseEnemies = 4 + m * 3
    if baseEnemies > 30 baseEnemies = 30 ok

    // Place enemies around the map
    for i = 1 to baseEnemies
        ex = GetRandomValue(-80, 80) * 1.0
        ez = GetRandomValue(-80, 80) * 1.0
        if heli_fabs(ex) < 15 and heli_fabs(ez + 80) < 15 loop ok  // Keep away from spawn
        ey = heli_getTerrainHeight(ex, ez)

        // Pick type
        eType = 1
        roll = GetRandomValue(1, 100)
        if m >= 2 and roll > 65 eType = 2 ok     // SAM
        if m >= 3 and roll > 80 eType = 3 ok     // AA gun
        if m >= 4 and roll > 88 eType = 4 ok     // Bunker
        if m >= 5 and roll > 93 eType = 5 ok     // Radar

        ehp = 1
        if eType = 1 ehp = 2 ok
        if eType = 2 ehp = 3 ok
        if eType = 3 ehp = 2 ok
        if eType = 4 ehp = 6 ok
        if eType = 5 ehp = 2 ok

        eAngle = GetRandomValue(0, 628) / 100.0

        // enemy: [x, y, z, type, hp, maxHp, alive, fireTimer, animTime, angle, alerted]
        add(enemies, [ex, ey, ez, eType, ehp, ehp, true,
                      GetRandomValue(200, 500) / 100.0, 0.0, eAngle, false])
    next

    // Rescue zones
    rescueTarget = 0
    if m >= 2
        numRescue = 1
        if m >= 4 numRescue = 2 ok
        if m >= 7 numRescue = 3 ok
        for i = 1 to numRescue
            rx = GetRandomValue(-60, 60) * 1.0
            rz = GetRandomValue(-60, 60) * 1.0
            if heli_fabs(rx) < 15 and heli_fabs(rz + 80) < 15
                rx = 40.0
                rz = 40.0
            ok
            hostages = GetRandomValue(2, 5)
            rescueTarget += hostages
            add(rescueZones, [rx, rz, false, hostages, 0.0])
        next
    ok

    // Place some starting powerups
    for i = 1 to 2 + floor(m / 3)
        ppx = GetRandomValue(-70, 70) * 1.0
        ppz = GetRandomValue(-70, 70) * 1.0
        ppy = heli_getTerrainHeight(ppx, ppz) + 3.0
        ptype = GetRandomValue(1, 3)
        add(powerups, [ppx, ppy, ppz, ptype, 30.0, true])
    next

    gameState = ST_MISSIONINTRO
    missionTimer = 3.0

// =============================================================
// Input
// =============================================================

func heli_handleInput dt
    if gameState = ST_TITLE
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            gameState = ST_PLAYING
            score = 0
            lives = 3
            mission = 1
            totalKills = 0
            totalShots = 0
            totalHits = 0
            maxCombo = 0
            heli_generateTerrain()
            heli_loadMission(mission)
        ok
        return
    ok

    if gameState = ST_GAMEOVER or gameState = ST_VICTORY
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            gameState = ST_TITLE
        ok
        return
    ok

    if gameState = ST_MISSIONCLEAR
        missionTimer -= dt
        if missionTimer <= 0
            mission += 1
            if mission > maxMission
                gameState = ST_VICTORY
                if score > highScore highScore = score ok
                if sndVictory != NULL PlaySound(sndVictory) ok
            else
                heli_generateTerrain()
                heli_loadMission(mission)
            ok
        ok
        return
    ok

    if gameState = ST_MISSIONINTRO
        missionTimer -= dt
        if missionTimer <= 0
            gameState = ST_PLAYING
        ok
        return
    ok

    if gameState = ST_PAUSED
        if IsKeyPressed(KEY_P) gameState = ST_PLAYING ok
        return
    ok

    if gameState != ST_PLAYING return ok

    if IsKeyPressed(KEY_P) gameState = ST_PAUSED return ok

    if IsKeyPressed(KEY_C)
        camMode = (camMode + 1) % CAM_COUNT
    ok

    if IsKeyPressed(KEY_TAB)
        radarZoom = (radarZoom % 3) + 1
    ok

    if !hAlive return ok

    // Yaw (turn left/right)
    yawSpd = 2.0
    if IsKeyDown(KEY_A) or IsKeyDown(KEY_LEFT)
        hYaw += yawSpd * dt
        hRoll = hRoll - 15 * dt
        if hRoll < -15 hRoll = -15 ok
    but IsKeyDown(KEY_D) or IsKeyDown(KEY_RIGHT)
        hYaw -= yawSpd * dt
        hRoll = hRoll + 15 * dt
        if hRoll > 15 hRoll = 15 ok
    else
        hRoll = hRoll * 0.9  // Auto-level roll
    ok

    while hYaw > PI  hYaw -= 2 * PI end
    while hYaw < -PI hYaw += 2 * PI end

    // Pitch (forward/backward speed)
    if IsKeyDown(KEY_W) or IsKeyDown(KEY_UP)
        hSpeedFwd += 12.0 * dt
        hPitch = hPitch - 10 * dt
        if hPitch < -20 hPitch = -20 ok
    but IsKeyDown(KEY_S) or IsKeyDown(KEY_DOWN)
        hSpeedFwd -= 8.0 * dt
        hPitch = hPitch + 10 * dt
        if hPitch > 10 hPitch = 10 ok
    else
        hPitch = hPitch * 0.92  // Auto-level pitch
    ok

    // Speed limits
    if hSpeedFwd > 25.0 hSpeedFwd = 25.0 ok
    if hSpeedFwd < -8.0 hSpeedFwd = -8.0 ok
    hSpeedFwd = hSpeedFwd * 0.98  // Drag

    // Altitude
    if IsKeyDown(KEY_Q)
        hSpeedVert += 10.0 * dt
    ok
    if IsKeyDown(KEY_E)
        hSpeedVert -= 10.0 * dt
    ok
    hSpeedVert = hSpeedVert * 0.95  // Drag
    if hSpeedVert > 12.0 hSpeedVert = 12.0 ok
    if hSpeedVert < -10.0 hSpeedVert = -10.0 ok

    // Apply movement
    fdx = sin(hYaw)
    fdz = cos(hYaw)
    newX = hx + fdx * hSpeedFwd * dt
    newZ = hz + fdz * hSpeedFwd * dt
    newY = hy + hSpeedVert * dt

    // Terrain collision
    groundH = heli_getTerrainHeight(newX, newZ) + 1.0
    if newY < groundH
        newY = groundH
        hSpeedVert = 0
        // Crash if too fast
        if hSpeedFwd > 15 or hSpeedVert < -8
            hHP -= 30
            heli_triggerShake(0.4, 0.5)
        ok
    ok

    // Height ceiling
    if newY > 60.0 newY = 60.0 hSpeedVert = 0 ok

    // Bounds
    if heli_fabs(newX) > TERRAIN_HALF - 5
        newX = hx
        hSpeedFwd = hSpeedFwd * 0.5
    ok
    if heli_fabs(newZ) > TERRAIN_HALF - 5
        newZ = hz
        hSpeedFwd = hSpeedFwd * 0.5
    ok

    hx = newX
    hy = newY
    hz = newZ

    // Rotor animation
    hRotorAngle += dt * 20.0

    // Landing
    if IsKeyDown(KEY_L)
        groundH2 = heli_getTerrainHeight(hx, hz) + 1.5
        if hy < groundH2 + 1.0 and heli_fabs(hSpeedFwd) < 2.0
            hLanding = true
        ok
    else
        hLanding = false
        hLandTimer = 0.0
    ok

    // Machine gun fire
    hFireCooldown -= dt
    if hFireCooldown < 0 hFireCooldown = 0 ok
    if IsKeyDown(KEY_SPACE)
        if len(pbullets) < MAX_PBULLETS and hFireCooldown <= 0
            bdx = sin(hYaw) * BULLET_SPEED
            bdy = -BULLET_SPEED * 0.15  // Slight downward angle
            bdz = cos(hYaw) * BULLET_SPEED
            bx = hx + sin(hYaw) * 2.0
            by = hy - 0.5
            bz = hz + cos(hYaw) * 2.0
            add(pbullets, [bx, by, bz, bdx, bdy, bdz, true, 0.0])
            hFireCooldown = 0.08
            totalShots += 1
            if sndFire != NULL
                SetSoundVolume(sndFire, 0.3)
                PlaySound(sndFire)
                SetSoundVolume(sndFire, 0.6)
            ok
        ok
    ok

    // Rocket fire
    hRocketCooldown -= dt
    if hRocketCooldown < 0 hRocketCooldown = 0 ok
    if IsKeyPressed(KEY_R)
        if hRockets > 0 and hRocketCooldown <= 0
            rdx = sin(hYaw) * ROCKET_SPEED
            rdy = -ROCKET_SPEED * 0.1
            rdz = cos(hYaw) * ROCKET_SPEED
            rx = hx + sin(hYaw) * 2.0
            ry = hy - 0.3
            rz = hz + cos(hYaw) * 2.0
            add(prockets, [rx, ry, rz, rdx, rdy, rdz, true, 0.0])
            hRockets -= 1
            hRocketCooldown = 0.5
            totalShots += 1
            if sndBomb != NULL
                SetSoundVolume(sndBomb, 0.5)
                PlaySound(sndBomb)
                SetSoundVolume(sndBomb, 1.0)
            ok
        ok
    ok

    // Engine sound
    if sndEngine != NULL
        if !IsSoundPlaying(sndEngine)
            PlaySound(sndEngine)
        ok
    ok

// =============================================================
// Update
// =============================================================

func heli_update dt
    if gameState != ST_PLAYING return ok

    if comboTimer > 0
        comboTimer -= dt
        if comboTimer <= 0 comboCount = 0 ok
    ok
    if comboDisplayTimer > 0 comboDisplayTimer -= dt ok
    if hShield > 0 hShield -= dt ok
    if hitFlashTimer > 0 hitFlashTimer -= dt ok

    heli_updatePBullets(dt)
    heli_updatePRockets(dt)
    heli_updateEBullets(dt)
    heli_updateMissiles(dt)
    heli_updateEnemies(dt)
    heli_updateRescue(dt)
    heli_updatePowerups(dt)
    heli_updateExplosions(dt)
    heli_updateParticles(dt)

    // Check mission complete
    allDestroyed = true
    nEn = len(enemies)
    for e = 1 to nEn
        if enemies[e][7] allDestroyed = false ok
    next
    allRescued = true
    if rescueTarget > 0
        if totalRescued < rescueTarget allRescued = false ok
    ok

    if allDestroyed and allRescued
        gameState = ST_MISSIONCLEAR
        missionTimer = 3.0
        missionBonus = mission * 500
        score += missionBonus
        if sndLevelClear != NULL PlaySound(sndLevelClear) ok
        // Celebration
        for p = 1 to 40
            vx = (GetRandomValue(-100, 100) / 40.0)
            vy = (GetRandomValue(50, 200) / 40.0)
            vz = (GetRandomValue(-100, 100) / 40.0)
            add(particles, [hx, hy, hz, vx, vy, vz, 2.5, 2.5,
                           GetRandomValue(150, 255), GetRandomValue(150, 255),
                           GetRandomValue(50, 255), 0.2])
        next
    ok

    // Respawn
    if !hAlive and lives > 0
        hShield += dt
        if hShield >= 0
            hAlive = true
            hx = 0.0 hy = 15.0 hz = -80.0
            hYaw = 0.0 hPitch = 0.0 hRoll = 0.0
            hSpeedFwd = 0.0 hSpeedVert = 0.0
            hHP = HELI_MAX_HP
            hRockets = HELI_MAX_ROCKETS
            hShield = 3.0
        ok
    ok

// =============================================================
// Player Bullets
// =============================================================

func heli_updatePBullets dt
    i = 1
    while i <= len(pbullets)
        if !pbullets[i][7]
            del(pbullets, i)
            loop
        ok
        pbullets[i][1] += pbullets[i][4] * dt
        pbullets[i][2] += pbullets[i][5] * dt
        pbullets[i][3] += pbullets[i][6] * dt
        pbullets[i][5] -= 5.0 * dt  // Gravity
        pbullets[i][8] += dt
        bx = pbullets[i][1]
        by = pbullets[i][2]
        bz = pbullets[i][3]

        if pbullets[i][8] > BULLET_LIFETIME
            pbullets[i][7] = false
            i += 1 loop
        ok

        // Ground hit
        gH = heli_getTerrainHeight(bx, bz)
        if by <= gH
            pbullets[i][7] = false
            heli_spawnSmallExplosion(bx, gH, bz)
            i += 1 loop
        ok

        // Hit enemies
        hitE = false
        nEn = len(enemies)
        for e = 1 to nEn
            if !enemies[e][7] loop ok
            ddx = bx - enemies[e][1]
            ddy = by - enemies[e][2]
            ddz = bz - enemies[e][3]
            dist = ddx*ddx + ddy*ddy + ddz*ddz
            hitR = 2.0
            if enemies[e][4] = 4 hitR = 2.5 ok
            if dist < hitR * hitR
                enemies[e][5] -= 1
                totalHits += 1
                enemies[e][11] = true  // Alert
                if enemies[e][5] <= 0
                    heli_killEnemy(e)
                else
                    heli_spawnSmallExplosion(bx, by, bz)
                    if sndEnemyHit != NULL PlaySound(sndEnemyHit) ok
                ok
                hitE = true
                exit
            ok
        next
        if hitE pbullets[i][7] = false i += 1 loop ok

        // Bounds
        if heli_fabs(bx) > TERRAIN_HALF or heli_fabs(bz) > TERRAIN_HALF
            pbullets[i][7] = false
            i += 1 loop
        ok

        i += 1
    end

// =============================================================
// Player Rockets
// =============================================================

func heli_updatePRockets dt
    i = 1
    while i <= len(prockets)
        if !prockets[i][7]
            del(prockets, i)
            loop
        ok
        prockets[i][1] += prockets[i][4] * dt
        prockets[i][2] += prockets[i][5] * dt
        prockets[i][3] += prockets[i][6] * dt
        prockets[i][5] -= 3.0 * dt  // Gravity (less than bullets)
        prockets[i][8] += dt
        rx = prockets[i][1]
        ry = prockets[i][2]
        rz = prockets[i][3]

        if prockets[i][8] > ROCKET_LIFETIME
            prockets[i][7] = false
            heli_spawnBigExplosion(rx, ry, rz)
            i += 1 loop
        ok

        // Ground hit - splash damage
        gH = heli_getTerrainHeight(rx, rz)
        if ry <= gH
            prockets[i][7] = false
            heli_spawnBigExplosion(rx, gH, rz)
            heli_triggerShake(0.2, 0.3)
            if sndExplosion != NULL PlaySound(sndExplosion) ok
            // Splash damage to enemies
            nEn = len(enemies)
            for e = 1 to nEn
                if !enemies[e][7] loop ok
                dist = heli_dist3(rx, gH, rz, enemies[e][1], enemies[e][2], enemies[e][3])
                if dist < 5.0
                    enemies[e][5] -= 3
                    enemies[e][11] = true
                    if enemies[e][5] <= 0
                        heli_killEnemy(e)
                    ok
                ok
            next
            i += 1 loop
        ok

        // Direct hit enemies
        hitE = false
        nEn = len(enemies)
        for e = 1 to nEn
            if !enemies[e][7] loop ok
            dist = heli_dist3(rx, ry, rz, enemies[e][1], enemies[e][2] + 1, enemies[e][3])
            if dist < 2.5
                prockets[i][7] = false
                enemies[e][5] -= 4
                enemies[e][11] = true
                heli_spawnBigExplosion(rx, ry, rz)
                heli_triggerShake(0.3, 0.4)
                if sndExplosion != NULL PlaySound(sndExplosion) ok
                if enemies[e][5] <= 0
                    heli_killEnemy(e)
                ok
                hitE = true
                exit
            ok
        next
        if hitE i += 1 loop ok

        i += 1
    end

// =============================================================
// Enemy Updates
// =============================================================

func heli_updateEBullets dt
    i = 1
    while i <= len(ebullets)
        if !ebullets[i][7]
            del(ebullets, i)
            loop
        ok
        ebullets[i][1] += ebullets[i][4] * dt
        ebullets[i][2] += ebullets[i][5] * dt
        ebullets[i][3] += ebullets[i][6] * dt
        ebullets[i][8] += dt

        if ebullets[i][8] > 3.0
            ebullets[i][7] = false
            i += 1 loop
        ok

        // Hit player
        if hAlive
            dist = heli_dist3(ebullets[i][1], ebullets[i][2], ebullets[i][3], hx, hy, hz)
            if dist < 2.5
                ebullets[i][7] = false
                if hShield <= 0
                    hHP -= 10
                    hitFlashTimer = 0.2
                    heli_triggerShake(0.2, 0.3)
                    if hHP <= 0
                        heli_playerDeath()
                    ok
                ok
                i += 1 loop
            ok
        ok
        i += 1
    end

func heli_updateMissiles dt
    i = 1
    while i <= len(missiles)
        if !missiles[i][7]
            del(missiles, i)
            loop
        ok
        // Homing toward player
        if hAlive
            missiles[i][9] = hx
            missiles[i][10] = hy
            missiles[i][11] = hz
        ok
        // Steer toward target
        dx = missiles[i][9] - missiles[i][1]
        dy = missiles[i][10] - missiles[i][2]
        dz = missiles[i][11] - missiles[i][3]
        dist = sqrt(dx*dx + dy*dy + dz*dz)
        if dist > 0.1
            mspd = 20.0
            steer = 3.0 * dt
            missiles[i][4] += (dx / dist * mspd - missiles[i][4]) * steer
            missiles[i][5] += (dy / dist * mspd - missiles[i][5]) * steer
            missiles[i][6] += (dz / dist * mspd - missiles[i][6]) * steer
        ok
        missiles[i][1] += missiles[i][4] * dt
        missiles[i][2] += missiles[i][5] * dt
        missiles[i][3] += missiles[i][6] * dt
        missiles[i][8] += dt

        if missiles[i][8] > 6.0
            missiles[i][7] = false
            heli_spawnSmallExplosion(missiles[i][1], missiles[i][2], missiles[i][3])
            i += 1 loop
        ok

        // Ground collision
        gH = heli_getTerrainHeight(missiles[i][1], missiles[i][3])
        if missiles[i][2] <= gH
            missiles[i][7] = false
            heli_spawnBigExplosion(missiles[i][1], gH, missiles[i][3])
            if sndExplosion != NULL PlaySound(sndExplosion) ok
            i += 1 loop
        ok

        // Hit player
        if hAlive
            dist = heli_dist3(missiles[i][1], missiles[i][2], missiles[i][3], hx, hy, hz)
            if dist < 3.0
                missiles[i][7] = false
                heli_spawnBigExplosion(missiles[i][1], missiles[i][2], missiles[i][3])
                heli_triggerShake(0.4, 0.5)
                if sndExplosion != NULL PlaySound(sndExplosion) ok
                if hShield <= 0
                    hHP -= 30
                    hitFlashTimer = 0.4
                    if hHP <= 0
                        heli_playerDeath()
                    ok
                ok
                i += 1 loop
            ok
        ok
        i += 1
    end

func heli_updateEnemies dt
    // Check if any radar alive (boosts accuracy)
    radarAlive = false
    nEn = len(enemies)
    for e = 1 to nEn
        if enemies[e][7] and enemies[e][4] = 5
            radarAlive = true
        ok
    next

    for e = 1 to nEn
        if !enemies[e][7] loop ok
        enemies[e][9] += dt
        enemies[e][8] -= dt

        ex = enemies[e][1]
        ey = enemies[e][2]
        ez = enemies[e][3]
        eType = enemies[e][4]

        // Alert range
        alertRange = 40.0
        if radarAlive alertRange = 60.0 ok
        dist = heli_dist(ex - hx, ez - hz, 0, 0)
        if dist < alertRange enemies[e][11] = true ok

        if !enemies[e][11] loop ok

        // Face player
        targetAngle = heli_atan2(hx - ex, hz - ez)
        angleDiff = targetAngle - enemies[e][10]
        while angleDiff > PI angleDiff -= 2 * PI end
        while angleDiff < -PI angleDiff += 2 * PI end
        if angleDiff > 0.05
            enemies[e][10] += 1.5 * dt
        but angleDiff < -0.05
            enemies[e][10] -= 1.5 * dt
        ok

        // Fire
        if enemies[e][8] <= 0 and hAlive
            dist3d = heli_dist3(ex, ey, ez, hx, hy, hz)

            if eType = 1
                // Tank - fires shells
                enemies[e][8] = GetRandomValue(200, 400) / 100.0
                if dist3d < 50 and len(ebullets) < MAX_EBULLETS
                    accuracy = 0.15
                    if radarAlive accuracy = 0.08 ok
                    bspd = 30.0
                    dx = (hx - ex) / dist3d + (GetRandomValue(-100, 100) / 100.0) * accuracy
                    dy = (hy - ey) / dist3d + (GetRandomValue(-100, 100) / 100.0) * accuracy
                    dz = (hz - ez) / dist3d + (GetRandomValue(-100, 100) / 100.0) * accuracy
                    add(ebullets, [ex, ey + 1.5, ez, dx * bspd, dy * bspd, dz * bspd, true, 0.0])
                    if sndFire != NULL
                        SetSoundVolume(sndFire, 0.15)
                        PlaySound(sndFire)
                        SetSoundVolume(sndFire, 0.6)
                    ok
                ok
            ok
            if eType = 2
                // SAM - launches homing missile
                enemies[e][8] = GetRandomValue(400, 700) / 100.0
                if dist3d < 70 and len(missiles) < MAX_MISSILES
                    mspd = 15.0
                    dx = (hx - ex) / dist3d
                    dy = (hy - ey) / dist3d
                    dz = (hz - ez) / dist3d
                    add(missiles, [ex, ey + 2, ez, dx * mspd, dy * mspd, dz * mspd, true, 0.0,
                                   hx, hy, hz])
                    if sndBomb != NULL
                        SetSoundVolume(sndBomb, 0.3)
                        PlaySound(sndBomb)
                        SetSoundVolume(sndBomb, 1.0)
                    ok
                ok
            ok
            if eType = 3
                // AA Gun - rapid fire
                enemies[e][8] = GetRandomValue(30, 80) / 100.0
                if dist3d < 45 and len(ebullets) < MAX_EBULLETS
                    accuracy = 0.20
                    if radarAlive accuracy = 0.12 ok
                    bspd = 40.0
                    dx = (hx - ex) / dist3d + (GetRandomValue(-100, 100) / 100.0) * accuracy
                    dy = (hy - ey) / dist3d + (GetRandomValue(-100, 100) / 100.0) * accuracy
                    dz = (hz - ez) / dist3d + (GetRandomValue(-100, 100) / 100.0) * accuracy
                    add(ebullets, [ex, ey + 1, ez, dx * bspd, dy * bspd, dz * bspd, true, 0.0])
                ok
            ok
            if eType = 4
                // Bunker - slow but strong shots
                enemies[e][8] = GetRandomValue(300, 500) / 100.0
                if dist3d < 55 and len(ebullets) < MAX_EBULLETS
                    accuracy = 0.10
                    bspd = 25.0
                    dx = (hx - ex) / dist3d + (GetRandomValue(-100, 100) / 100.0) * accuracy
                    dy = (hy - ey) / dist3d + (GetRandomValue(-100, 100) / 100.0) * accuracy
                    dz = (hz - ez) / dist3d + (GetRandomValue(-100, 100) / 100.0) * accuracy
                    add(ebullets, [ex, ey + 1, ez, dx * bspd, dy * bspd, dz * bspd, true, 0.0])
                ok
            ok
            if eType = 5
                // Radar - doesn't fire, just boosts others
                enemies[e][8] = 5.0
            ok
        ok
    next

// =============================================================
// Rescue System
// =============================================================

func heli_updateRescue dt
    nRZ = len(rescueZones)
    for i = 1 to nRZ
        if rescueZones[i][3] loop ok  // Already rescued
        rx = rescueZones[i][1]
        rz = rescueZones[i][2]

        // Check if helicopter is landed near zone
        if hLanding
            dist = heli_dist(hx - rx, hz - rz, 0, 0)
            groundH = heli_getTerrainHeight(hx, hz)
            if dist < 8.0 and hy < groundH + 2.5
                rescueZones[i][5] += dt
                if rescueZones[i][5] >= 3.0
                    // Rescued!
                    rescueZones[i][3] = true
                    totalRescued += rescueZones[i][4]
                    score += rescueZones[i][4] * 200
                    if sndPowerup != NULL PlaySound(sndPowerup) ok
                    // Celebration
                    for p = 1 to 15
                        vx = (GetRandomValue(-100, 100) / 50.0)
                        vy = (GetRandomValue(50, 150) / 50.0)
                        vz = (GetRandomValue(-100, 100) / 50.0)
                        add(particles, [rx, groundH + 1, rz, vx, vy, vz, 1.5, 1.5,
                                       50, 255, 50, 0.15])
                    next
                ok
            else
                rescueZones[i][5] = 0.0
            ok
        else
            rescueZones[i][5] = 0.0
        ok
    next

// =============================================================
// Powerups
// =============================================================

func heli_updatePowerups dt
    i = 1
    while i <= len(powerups)
        if !powerups[i][6]
            del(powerups, i)
            loop
        ok
        powerups[i][5] -= dt
        if powerups[i][5] <= 0
            del(powerups, i)
            loop
        ok
        if hAlive
            dist = heli_dist3(hx, hy, hz, powerups[i][1], powerups[i][2], powerups[i][3])
            if dist < 4.0
                ptype = powerups[i][4]
                if ptype = 1
                    hHP += 40
                    if hHP > HELI_MAX_HP hHP = HELI_MAX_HP ok
                    score += 100
                ok
                if ptype = 2
                    hRockets += 6
                    if hRockets > HELI_MAX_ROCKETS hRockets = HELI_MAX_ROCKETS ok
                    score += 100
                ok
                if ptype = 3
                    hShield = 8.0
                    score += 100
                ok
                if ptype = 4
                    nEn = len(enemies)
                    for e = 1 to nEn
                        if enemies[e][7]
                            enemies[e][7] = false
                            totalKills += 1
                            score += 50
                            heli_spawnBigExplosion(enemies[e][1], enemies[e][2], enemies[e][3])
                        ok
                    next
                    heli_triggerShake(0.6, 0.8)
                    score += 500
                    if sndBomb != NULL PlaySound(sndBomb) ok
                ok
                if sndPowerup != NULL PlaySound(sndPowerup) ok
                del(powerups, i)
                loop
            ok
        ok
        i += 1
    end

// =============================================================
// Helper functions
// =============================================================

func heli_killEnemy e
    enemies[e][7] = false
    ex = enemies[e][1]
    ey = enemies[e][2]
    ez = enemies[e][3]
    eType = enemies[e][4]
    heli_spawnBigExplosion(ex, ey, ez)
    heli_triggerShake(0.2, 0.3)
    if sndExplosion != NULL PlaySound(sndExplosion) ok
    totalKills += 1
    // Score
    baseScore = 100
    if eType = 2 baseScore = 300 ok
    if eType = 3 baseScore = 200 ok
    if eType = 4 baseScore = 500 ok
    if eType = 5 baseScore = 400 ok
    // Combo
    comboCount += 1
    comboTimer = comboDuration
    comboMult = 1.0
    if comboCount = 2 comboMult = 1.5 ok
    if comboCount = 3 comboMult = 2.0 ok
    if comboCount = 4 comboMult = 3.0 ok
    if comboCount >= 5 comboMult = 5.0 ok
    if comboCount > maxCombo maxCombo = comboCount ok
    finalScore = floor(baseScore * comboMult)
    score += finalScore
    if comboCount >= 2
        lastComboText = "x" + comboCount + " COMBO! +" + finalScore
        comboDisplayTimer = 2.0
    ok
    // Power-up drop
    if GetRandomValue(1, 100) <= 20 + eType * 5
        ptype = GetRandomValue(1, 4)
        if ptype = 4 and GetRandomValue(1, 100) > 15 ptype = GetRandomValue(1, 3) ok
        ppy = ey + 3.0
        add(powerups, [ex, ppy, ez, ptype, 20.0, true])
    ok

func heli_playerDeath
    hAlive = false
    lives -= 1
    heli_spawnBigExplosion(hx, hy, hz)
    heli_triggerShake(0.5, 0.7)
    if sndExplosion != NULL PlaySound(sndExplosion) ok
    if lives <= 0
        gameState = ST_GAMEOVER
        gameOverTimer = 4.0
        if score > highScore highScore = score ok
        if sndGameOver != NULL PlaySound(sndGameOver) ok
    else
        hShield = -2.5
    ok

// =============================================================
// Explosions & Particles
// =============================================================

func heli_spawnSmallExplosion bx, by, bz
    add(explosions, [bx, by, bz, 0.4, 0.4, 1.0])
    for i = 1 to 5
        ang = GetRandomValue(0, 628) / 100.0
        spd = GetRandomValue(100, 300) / 100.0
        add(particles, [bx, by, bz,
                        cos(ang)*spd, GetRandomValue(100, 300)/100.0, sin(ang)*spd,
                        0.5, 0.5, 255, GetRandomValue(100, 200), 30, 0.08])
    next

func heli_spawnBigExplosion bx, by, bz
    add(explosions, [bx, by, bz, 1.0, 1.0, 3.0])
    for i = 1 to 18
        ang = GetRandomValue(0, 628) / 100.0
        spd = GetRandomValue(200, 600) / 100.0
        add(particles, [bx, by, bz,
                        cos(ang)*spd, GetRandomValue(200, 600)/100.0, sin(ang)*spd,
                        1.2, 1.2, 255, GetRandomValue(80, 200), GetRandomValue(10, 80), 0.18])
    next

func heli_updateExplosions dt
    i = 1
    while i <= len(explosions)
        explosions[i][4] -= dt
        if explosions[i][4] <= 0
            del(explosions, i)
        else
            i += 1
        ok
    end

func heli_updateParticles dt
    i = 1
    while i <= len(particles)
        particles[i][1] += particles[i][4] * dt
        particles[i][2] += particles[i][5] * dt
        particles[i][3] += particles[i][6] * dt
        particles[i][5] -= 6.0 * dt
        particles[i][7] -= dt
        if particles[i][7] <= 0
            del(particles, i)
        else
            i += 1
        ok
    end

func heli_triggerShake intensity, duration
    shakeIntensity = intensity
    shakeDuration = duration
    shakeTimer = duration

// =============================================================
// Camera
// =============================================================

func heli_updateCamera
    if camMode = CAM_CHASE
        // Chase camera behind helicopter
        camDist = 12.0
        camHt = 5.0
        backX = hx - sin(hYaw) * camDist
        backZ = hz - cos(hYaw) * camDist
        cam.position.x = backX
        cam.position.y = hy + camHt
        cam.position.z = backZ
        cam.target.x = hx + sin(hYaw) * 5
        cam.target.y = hy
        cam.target.z = hz + cos(hYaw) * 5
        cam.fovy = 60
    ok
    if camMode = CAM_COCKPIT
        cam.position.x = hx
        cam.position.y = hy + 0.5
        cam.position.z = hz
        cam.target.x = hx + sin(hYaw) * 20
        cam.target.y = hy - 2
        cam.target.z = hz + cos(hYaw) * 20
        cam.fovy = 70
    ok
    if camMode = CAM_TOP
        cam.position.x = hx
        cam.position.y = hy + 40
        cam.position.z = hz + 15
        cam.target.x = hx
        cam.target.y = 0
        cam.target.z = hz
        cam.fovy = 50
    ok
    cam.up.x = 0 cam.up.y = 1 cam.up.z = 0

    // Shake
    if shakeTimer > 0
        sf = shakeTimer / shakeDuration * shakeIntensity
        cam.position.x += (GetRandomValue(-100, 100) / 100.0) * sf
        cam.position.y += (GetRandomValue(-100, 100) / 100.0) * sf * 0.5
        cam.position.z += (GetRandomValue(-100, 100) / 100.0) * sf
    ok

// =============================================================
// 3D Drawing: Sky
// =============================================================

func heli_drawSky
    // Sky dome approximation - gradient from horizon
    DrawSphere(Vector3(0, -50, 0), 300, RAYLIBColor(60, 100, 160, 255))
    // Sun
    DrawSphere(Vector3(80, 80, -60), 8, RAYLIBColor(255, 240, 200, 200))
    // Clouds
    for i = 1 to 10
        cx = sin(i * 1.7) * 120
        cz = cos(i * 2.3) * 120
        cy = 50 + sin(i * 3.1) * 10
        cw = 15 + sin(i * 2.7) * 8
        DrawCube(Vector3(cx, cy, cz), cw, 1.5, cw * 0.6,
                 RAYLIBColor(220, 230, 240, 80))
    next

// =============================================================
// 3D Drawing: Terrain
// =============================================================

func heli_drawTerrain
    for r = 1 to TERRAIN_GRID
        for c = 1 to TERRAIN_GRID
            wx = -TERRAIN_HALF + (c - 1) * TERRAIN_CELL + TERRAIN_CELL / 2
            wz = -TERRAIN_HALF + (r - 1) * TERRAIN_CELL + TERRAIN_CELL / 2

            h00 = terrainH[r][c]
            h10 = terrainH[r][c + 1]
            h01 = terrainH[r + 1][c]
            h11 = terrainH[r + 1][c + 1]
            avgH = (h00 + h10 + h01 + h11) / 4.0

            // Color based on height
            gr = 40 + floor(avgH * 12)
            gg = 70 + floor(avgH * 15)
            gb = 30 + floor(avgH * 5)
            if avgH > 5 gr += 30 gg -= 10 gb += 10 ok  // Mountain
            if avgH < 1.5 gr = 50 gg = 80 gb = 40 ok   // Flat/valley
            if gr > 255 gr = 255 ok
            if gg > 255 gg = 255 ok

            DrawCube(Vector3(wx, avgH / 2, wz),
                     TERRAIN_CELL, avgH, TERRAIN_CELL,
                     RAYLIBColor(gr, gg, gb, 255))
        next
    next

    // Water in low areas
    DrawPlane(Vector3(0, 0.3, 0), Vector2(TERRAIN_SIZE, TERRAIN_SIZE),
              RAYLIBColor(20, 50, 120, 100))

// =============================================================
// 3D Drawing: Enemies
// =============================================================

func heli_drawEnemies3D
    nEn = len(enemies)
    for e = 1 to nEn
        if !enemies[e][7] loop ok
        ex = enemies[e][1]
        ey = enemies[e][2]
        ez = enemies[e][3]
        eType = enemies[e][4]
        eAngle = enemies[e][10]
        eAnim = enemies[e][9]

        fdx = sin(eAngle)
        fdz = cos(eAngle)

        if eType = 1
            // Tank - olive green
            DrawCube(Vector3(ex, ey + 0.4, ez), 1.8, 0.6, 2.2,
                     RAYLIBColor(80, 90, 50, 255))
            DrawCube(Vector3(ex, ey + 0.8, ez), 1.2, 0.4, 1.2,
                     RAYLIBColor(70, 80, 45, 255))
            // Barrel
            DrawCylinder(Vector3(ex + fdx * 1.2, ey + 0.9, ez + fdz * 1.2),
                         0.06, 0.05, 1.5, 6,
                         RAYLIBColor(60, 65, 40, 255))
        ok
        if eType = 2
            // SAM - red launcher
            DrawCube(Vector3(ex, ey + 0.3, ez), 2.0, 0.4, 2.0,
                     RAYLIBColor(100, 100, 100, 255))
            // Launcher tubes
            DrawCylinder(Vector3(ex, ey + 0.8, ez), 0.15, 0.15, 1.0, 6,
                         RAYLIBColor(180, 50, 40, 255))
            DrawCylinder(Vector3(ex + 0.4, ey + 0.8, ez), 0.15, 0.15, 1.0, 6,
                         RAYLIBColor(180, 50, 40, 255))
            DrawCylinder(Vector3(ex - 0.4, ey + 0.8, ez), 0.15, 0.15, 1.0, 6,
                         RAYLIBColor(180, 50, 40, 255))
            // Tracking dish
            spinAngle = eAnim * 2.0
            DrawCylinder(Vector3(ex + cos(spinAngle) * 0.3, ey + 1.8, ez + sin(spinAngle) * 0.3),
                         0.3, 0.05, 0.3, 6,
                         RAYLIBColor(200, 60, 50, 255))
        ok
        if eType = 3
            // AA Gun - gray rapid fire
            DrawCube(Vector3(ex, ey + 0.3, ez), 1.5, 0.5, 1.5,
                     RAYLIBColor(120, 120, 130, 255))
            DrawCylinder(Vector3(ex, ey + 0.5, ez), 0.3, 0.25, 0.6, 8,
                         RAYLIBColor(100, 100, 110, 255))
            // Twin barrels
            DrawCylinder(Vector3(ex + fdx * 0.8 + 0.12, ey + 1.0, ez + fdz * 0.8),
                         0.04, 0.04, 1.2, 6,
                         RAYLIBColor(80, 80, 90, 255))
            DrawCylinder(Vector3(ex + fdx * 0.8 - 0.12, ey + 1.0, ez + fdz * 0.8),
                         0.04, 0.04, 1.2, 6,
                         RAYLIBColor(80, 80, 90, 255))
        ok
        if eType = 4
            // Bunker - fortified brown
            DrawCube(Vector3(ex, ey + 0.5, ez), 3.0, 1.0, 3.0,
                     RAYLIBColor(120, 90, 60, 255))
            DrawCube(Vector3(ex, ey + 1.2, ez), 2.0, 0.5, 2.0,
                     RAYLIBColor(110, 80, 55, 255))
            // Gun slit
            DrawCube(Vector3(ex + fdx * 1.5, ey + 1.0, ez + fdz * 1.5),
                     0.8, 0.2, 0.2,
                     RAYLIBColor(30, 30, 30, 255))
        ok
        if eType = 5
            // Radar - spinning dish
            DrawCube(Vector3(ex, ey + 0.3, ez), 1.5, 0.4, 1.5,
                     RAYLIBColor(100, 100, 100, 255))
            DrawCylinder(Vector3(ex, ey + 0.4, ez), 0.12, 0.1, 3.0, 6,
                         RAYLIBColor(180, 180, 190, 255))
            // Spinning dish
            dishAngle = eAnim * 3.0
            dx2 = cos(dishAngle) * 1.2
            dz2 = sin(dishAngle) * 1.2
            DrawCube(Vector3(ex + dx2, ey + 3.2, ez + dz2), 2.0, 0.15, 0.5,
                     RAYLIBColor(200, 200, 210, 255))
        ok

        // HP bar
        if enemies[e][5] < enemies[e][6]
            hpFrac = enemies[e][5] * 1.0 / enemies[e][6]
            barW = 2.0
            barY2 = ey + 2.5
            if eType = 5 barY2 = ey + 4.0 ok
            DrawCube(Vector3(ex, barY2, ez), barW, 0.1, 0.1,
                     RAYLIBColor(60, 60, 60, 200))
            DrawCube(Vector3(ex - (barW * (1 - hpFrac))/2, barY2, ez),
                     barW * hpFrac, 0.12, 0.12,
                     RAYLIBColor(floor(255*(1-hpFrac)), floor(255*hpFrac), 30, 255))
        ok

        // Alert indicator
        if enemies[e][11]
            DrawSphere(Vector3(ex, ey + 3.0, ez), 0.15,
                       RAYLIBColor(255, 50, 50, floor(sin(eAnim * 6) * 80 + 175)))
        ok
    next

// =============================================================
// 3D Drawing: Rescue Zones
// =============================================================

func heli_drawRescueZones3D
    nRZ = len(rescueZones)
    for i = 1 to nRZ
        rx = rescueZones[i][1]
        rz = rescueZones[i][2]
        ry = heli_getTerrainHeight(rx, rz)

        if rescueZones[i][3]
            // Rescued - green marker
            DrawCylinder(Vector3(rx, ry + 0.05, rz), 4.0, 4.0, 0.05, 16,
                         RAYLIBColor(50, 200, 50, 100))
        else
            // Active - pulsing yellow/orange circle
            pulse = sin(animTime * 3.0) * 0.3 + 1.0
            DrawCylinder(Vector3(rx, ry + 0.05, rz), 5.0 * pulse, 5.0 * pulse, 0.05, 16,
                         RAYLIBColor(255, 180, 50, 80))
            DrawCylinder(Vector3(rx, ry + 0.08, rz), 3.0, 3.0, 0.05, 16,
                         RAYLIBColor(255, 220, 50, 120))
            // H landing pad
            DrawCube(Vector3(rx, ry + 0.1, rz), 0.3, 0.05, 2.0,
                     RAYLIBColor(255, 255, 255, 200))
            DrawCube(Vector3(rx, ry + 0.1, rz), 1.5, 0.05, 0.3,
                     RAYLIBColor(255, 255, 255, 200))
            DrawCube(Vector3(rx - 0.75, ry + 0.1, rz), 0.3, 0.05, 2.0,
                     RAYLIBColor(255, 255, 255, 200))
            DrawCube(Vector3(rx + 0.75, ry + 0.1, rz), 0.3, 0.05, 2.0,
                     RAYLIBColor(255, 255, 255, 200))
            // Hostage figures
            for h = 1 to rescueZones[i][4]
                hAng = h * (2 * PI / rescueZones[i][4])
                hpx = rx + cos(hAng) * 2.0
                hpz = rz + sin(hAng) * 2.0
                DrawCylinder(Vector3(hpx, ry + 0.4, hpz), 0.12, 0.1, 0.8, 6,
                             RAYLIBColor(200, 150, 50, 255))
                DrawSphere(Vector3(hpx, ry + 1.0, hpz), 0.18,
                           RAYLIBColor(220, 170, 80, 255))
            next
            // Landing progress
            if rescueZones[i][5] > 0
                prog = rescueZones[i][5] / 3.0
                DrawCylinder(Vector3(rx, ry + 0.12, rz), 3.0 * prog, 3.0 * prog, 0.08, 16,
                             RAYLIBColor(50, 255, 50, floor(150 * prog)))
            ok
        ok
    next

// =============================================================
// 3D Drawing: Helicopter
// =============================================================

func heli_drawHeli3D
    if !hAlive return ok
    if camMode = CAM_COCKPIT return ok  // Don't draw in first person

    // Fuselage
    DrawCube(Vector3(hx, hy, hz), 1.2, 1.0, 3.0,
             RAYLIBColor(60, 80, 60, 255))
    // Cockpit glass
    fdx = sin(hYaw)
    fdz = cos(hYaw)
    DrawSphere(Vector3(hx + fdx * 1.2, hy + 0.2, hz + fdz * 1.2), 0.6,
               RAYLIBColor(100, 180, 220, 150))
    // Tail boom
    DrawCube(Vector3(hx - fdx * 2.5, hy + 0.3, hz - fdz * 2.5), 0.4, 0.4, 2.5,
             RAYLIBColor(60, 75, 55, 255))
    // Tail fin
    DrawCube(Vector3(hx - fdx * 3.8, hy + 0.8, hz - fdz * 3.8), 0.05, 1.0, 0.6,
             RAYLIBColor(70, 85, 60, 255))

    // Main rotor
    rotRad = 3.5
    for b = 0 to 3
        bAng = hRotorAngle + b * PI / 2
        bx1 = hx + cos(bAng) * rotRad
        bz1 = hz + sin(bAng) * rotRad
        DrawLine3D(Vector3(hx, hy + 1.0, hz),
                   Vector3(bx1, hy + 1.0, bz1),
                   RAYLIBColor(150, 150, 150, 180))
    next
    // Rotor hub
    DrawSphere(Vector3(hx, hy + 1.0, hz), 0.15,
               RAYLIBColor(80, 80, 80, 255))

    // Tail rotor
    trotRad = 0.6
    for b = 0 to 1
        bAng = hRotorAngle * 3 + b * PI
        tbx = hx - fdx * 3.8
        tbz = hz - fdz * 3.8
        DrawLine3D(Vector3(tbx, hy + 0.8, tbz),
                   Vector3(tbx, hy + 0.8 + sin(bAng) * trotRad, tbz + cos(bAng) * trotRad),
                   RAYLIBColor(140, 140, 140, 160))
    next

    // Weapon pods
    perpX = cos(hYaw)
    perpZ = -sin(hYaw)
    DrawCube(Vector3(hx + perpX * 1.2, hy - 0.5, hz + perpZ * 1.2), 0.3, 0.2, 0.8,
             RAYLIBColor(50, 50, 50, 255))
    DrawCube(Vector3(hx - perpX * 1.2, hy - 0.5, hz - perpZ * 1.2), 0.3, 0.2, 0.8,
             RAYLIBColor(50, 50, 50, 255))

    // Shield effect
    if hShield > 0
        DrawSphere(Vector3(hx, hy, hz), 3.0,
                   RAYLIBColor(50, 100, 255, floor(sin(animTime * 6) * 20 + 25)))
    ok

// =============================================================
// 3D Drawing: Bullets / Rockets / Missiles
// =============================================================

func heli_drawBullets3D
    // Player bullets
    nPB = len(pbullets)
    for i = 1 to nPB
        if !pbullets[i][7] loop ok
        DrawSphere(Vector3(pbullets[i][1], pbullets[i][2], pbullets[i][3]),
                   0.1, RAYLIBColor(255, 255, 100, 255))
        DrawSphere(Vector3(pbullets[i][1], pbullets[i][2], pbullets[i][3]),
                   0.2, RAYLIBColor(255, 200, 50, 40))
    next
    // Player rockets
    nPR = len(prockets)
    for i = 1 to nPR
        if !prockets[i][7] loop ok
        DrawSphere(Vector3(prockets[i][1], prockets[i][2], prockets[i][3]),
                   0.2, RAYLIBColor(255, 150, 50, 255))
        // Trail
        DrawSphere(Vector3(prockets[i][1] - prockets[i][4] * 0.02,
                           prockets[i][2] - prockets[i][5] * 0.02,
                           prockets[i][3] - prockets[i][6] * 0.02),
                   0.15, RAYLIBColor(255, 100, 30, 120))
    next
    // Enemy bullets
    nEB = len(ebullets)
    for i = 1 to nEB
        if !ebullets[i][7] loop ok
        DrawSphere(Vector3(ebullets[i][1], ebullets[i][2], ebullets[i][3]),
                   0.08, RAYLIBColor(255, 80, 50, 255))
    next
    // Missiles
    nM = len(missiles)
    for i = 1 to nM
        if !missiles[i][7] loop ok
        DrawSphere(Vector3(missiles[i][1], missiles[i][2], missiles[i][3]),
                   0.25, RAYLIBColor(255, 50, 30, 255))
        DrawSphere(Vector3(missiles[i][1], missiles[i][2], missiles[i][3]),
                   0.5, RAYLIBColor(255, 30, 10, 40))
        // Smoke trail
        DrawSphere(Vector3(missiles[i][1] - missiles[i][4] * 0.05,
                           missiles[i][2] - missiles[i][5] * 0.05,
                           missiles[i][3] - missiles[i][6] * 0.05),
                   0.3, RAYLIBColor(200, 200, 200, 60))
    next

// =============================================================
// 3D Drawing: Powerups
// =============================================================

func heli_drawPowerups3D
    nPU = len(powerups)
    for i = 1 to nPU
        if !powerups[i][6] loop ok
        px2 = powerups[i][1]
        py2 = powerups[i][2] + sin(animTime * 3.0 + i) * 0.5
        pz2 = powerups[i][3]
        ptype = powerups[i][4]
        flash = floor(sin(animTime * 5.0) * 40 + 215)

        if ptype = 1
            DrawSphere(Vector3(px2, py2, pz2), 0.5, RAYLIBColor(50, 255, 50, flash))
            DrawCube(Vector3(px2, py2, pz2), 0.8, 0.15, 0.25, RAYLIBColor(255, 255, 255, flash))
            DrawCube(Vector3(px2, py2, pz2), 0.25, 0.15, 0.8, RAYLIBColor(255, 255, 255, flash))
        ok
        if ptype = 2
            DrawSphere(Vector3(px2, py2, pz2), 0.5, RAYLIBColor(255, 220, 50, flash))
            DrawCube(Vector3(px2, py2, pz2), 0.6, 0.6, 0.2, RAYLIBColor(200, 180, 40, flash))
        ok
        if ptype = 3
            DrawSphere(Vector3(px2, py2, pz2), 0.5, RAYLIBColor(80, 150, 255, flash))
            DrawSphere(Vector3(px2, py2, pz2), 0.8, RAYLIBColor(50, 100, 255, 30))
        ok
        if ptype = 4
            pulse = sin(animTime * 6.0) * 0.1
            DrawSphere(Vector3(px2, py2, pz2), 0.5 + pulse, RAYLIBColor(255, 40, 30, flash))
            DrawSphere(Vector3(px2, py2, pz2), 0.9, RAYLIBColor(255, 20, 10, 25))
        ok
    next

// =============================================================
// 3D Drawing: Explosions & Particles
// =============================================================

func heli_drawExplosions3D
    nExp = len(explosions)
    for i = 1 to nExp
        life = explosions[i][4] / explosions[i][5]
        sz = explosions[i][6] * (1.0 - life * 0.3)
        alpha = floor(life * 200)
        if alpha > 255 alpha = 255 ok
        if alpha < 0 alpha = 0 ok
        DrawSphere(Vector3(explosions[i][1], explosions[i][2], explosions[i][3]),
                   sz, RAYLIBColor(255, 150 + floor(life * 100), 30, alpha))
        DrawSphere(Vector3(explosions[i][1], explosions[i][2] + 0.5, explosions[i][3]),
                   sz * 1.3, RAYLIBColor(255, 100, 10, floor(alpha * 0.3)))
    next

func heli_drawParticles3D
    nPart = len(particles)
    for i = 1 to nPart
        life = particles[i][7] / particles[i][8]
        if life < 0 life = 0 ok
        alpha = floor(life * 255)
        if alpha < 0 alpha = 0 ok
        if alpha > 255 alpha = 255 ok
        sz = particles[i][12] * life
        if sz < 0.01 sz = 0.01 ok
        DrawSphere(Vector3(particles[i][1], particles[i][2], particles[i][3]),
                   sz, RAYLIBColor(particles[i][9], particles[i][10],
                                   particles[i][11], alpha))
    next

// =============================================================
// HUD
// =============================================================

func heli_drawHUD
    // Hit flash
    if hitFlashTimer > 0
        fAlpha = floor((hitFlashTimer / 0.4) * 100)
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(255, 0, 0, fAlpha))
    ok

    // Top bar
    DrawRectangle(0, 0, SCREEN_W, 50, RAYLIBColor(0, 0, 0, 200))
    DrawRectangle(0, 50, SCREEN_W, 2, RAYLIBColor(0, 200, 100, 200))

    // Score
    DrawText("SCORE", 15, 4, 12, RAYLIBColor(100, 200, 100, 200))
    DrawText(string(score), 15, 18, 22, RAYLIBColor(200, 255, 200, 255))

    // Mission
    mTxt = "MISSION " + string(mission)
    mW = MeasureText(mTxt, 22)
    DrawText(mTxt, floor(SCREEN_W/2 - mW/2), 4, 22, RAYLIBColor(200, 255, 200, 255))

    missionNames = ["Recon Patrol", "First Contact", "SAM Alley",
                    "Deep Strike", "Radar Hunt", "Bunker Buster",
                    "Iron Storm", "Final Assault"]
    if mission >= 1 and mission <= 8
        mnTxt = missionNames[mission]
        mnW = MeasureText(mnTxt, 14)
        DrawText(mnTxt, floor(SCREEN_W/2 - mnW/2), 28, 14, RAYLIBColor(150, 200, 150, 200))
    ok

    // Objectives
    nEn = len(enemies)
    alive = 0
    for e = 1 to nEn
        if enemies[e][7] alive += 1 ok
    next
    objTxt = "Targets: " + string(alive)
    if rescueTarget > 0
        objTxt += "  |  Rescued: " + string(totalRescued) + "/" + string(rescueTarget)
    ok
    oW = MeasureText(objTxt, 12)
    DrawText(objTxt, floor(SCREEN_W/2 - oW/2), 40, 12, RAYLIBColor(255, 180, 80, 200))

    // Lives
    DrawText("LIVES", SCREEN_W - 140, 4, 12, RAYLIBColor(100, 200, 100, 200))
    for i = 1 to lives
        lx = SCREEN_W - 140 + (i - 1) * 28
        DrawRectangle(lx, 22, 20, 8, RAYLIBColor(80, 180, 80, 255))
        DrawRectangle(lx + 8, 18, 4, 6, RAYLIBColor(60, 160, 60, 255))
    next

    // HP bar
    if hAlive
        barX = 15
        barY = SCREEN_H - 50
        barW = 160
        barH = 14
        hpFrac = hHP * 1.0 / HELI_MAX_HP
        DrawRectangle(barX - 1, barY - 1, barW + 2, barH + 2, RAYLIBColor(0, 80, 0, 200))
        DrawRectangle(barX, barY, barW, barH, RAYLIBColor(30, 30, 30, 200))
        hpR = floor(255 * (1 - hpFrac))
        hpG = floor(255 * hpFrac)
        DrawRectangle(barX, barY, floor(barW * hpFrac), barH,
                      RAYLIBColor(hpR, hpG, 30, 255))
        DrawText("HP " + string(hHP), barX + 5, barY + 1, 12,
                 RAYLIBColor(255, 255, 255, 220))
    ok

    // Rockets
    DrawText("RKT: " + string(hRockets), 15, SCREEN_H - 30, 14,
             RAYLIBColor(255, 180, 50, 255))

    // Altitude & Speed
    DrawText("ALT: " + string(floor(hy)), 190, SCREEN_H - 50, 12,
             RAYLIBColor(100, 200, 100, 200))
    DrawText("SPD: " + string(floor(heli_fabs(hSpeedFwd))), 190, SCREEN_H - 36, 12,
             RAYLIBColor(100, 200, 100, 200))

    // Shield indicator
    if hShield > 0
        DrawText("[SHIELD " + string(floor(hShield)) + "s]", 15, SCREEN_H - 70, 14,
                 RAYLIBColor(80, 150, 255, 255))
    ok

    // Combo
    if comboDisplayTimer > 0
        cAlpha = floor((comboDisplayTimer / 2.0) * 255)
        if cAlpha > 255 cAlpha = 255 ok
        cW = MeasureText(lastComboText, 28)
        DrawText(lastComboText, floor(SCREEN_W/2 - cW/2), 80, 28,
                 RAYLIBColor(255, 220, 50, cAlpha))
    ok

    // Crosshair
    if gameState = ST_PLAYING and hAlive
        cx = SCREEN_W / 2
        cy = SCREEN_H / 2 + 30
        DrawLine(cx - 18, cy, cx - 5, cy, RAYLIBColor(100, 255, 100, 180))
        DrawLine(cx + 5, cy, cx + 18, cy, RAYLIBColor(100, 255, 100, 180))
        DrawLine(cx, cy - 18, cx, cy - 5, RAYLIBColor(100, 255, 100, 180))
        DrawLine(cx, cy + 5, cx, cy + 18, RAYLIBColor(100, 255, 100, 180))
        DrawCircleLines(cx, cy, 3, RAYLIBColor(100, 255, 100, 120))
    ok

    // State overlays
    if gameState = ST_TITLE
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 220))
        title = "HELICOPTER GUNSHIP 3D"
        DrawText(title, floor(SCREEN_W/2 - MeasureText(title, 48) / 2),
                 floor(SCREEN_H/2 - 120), 48, RAYLIBColor(100, 255, 100, 255))
        sub = "Attack Helicopter Combat Simulator"
        DrawText(sub, floor(SCREEN_W/2 - MeasureText(sub, 18) / 2),
                 floor(SCREEN_H/2 - 60), 18, RAYLIBColor(150, 220, 150, 220))
        start = "Press ENTER or SPACE to Launch"
        pulse = floor(sin(animTime * 3.0) * 60 + 195)
        DrawText(start, floor(SCREEN_W/2 - MeasureText(start, 22) / 2),
                 floor(SCREEN_H/2 + 0), 22, RAYLIBColor(200, 255, 200, pulse))
        ctrl1 = "WASD: Fly  QE: Altitude  SPACE: Gun  R: Rocket  L: Land  C: Camera"
        DrawText(ctrl1, floor(SCREEN_W/2 - MeasureText(ctrl1, 13) / 2),
                 floor(SCREEN_H/2 + 45), 13, RAYLIBColor(100, 180, 100, 180))
        ctrl2 = "Destroy targets, rescue hostages, survive 8 missions!"
        DrawText(ctrl2, floor(SCREEN_W/2 - MeasureText(ctrl2, 14) / 2),
                 floor(SCREEN_H/2 + 65), 14, RAYLIBColor(100, 180, 100, 180))
        if highScore > 0
            hsTxt = "High Score: " + string(highScore)
            DrawText(hsTxt, floor(SCREEN_W/2 - MeasureText(hsTxt, 18) / 2),
                     floor(SCREEN_H/2 + 100), 18, RAYLIBColor(150, 220, 100, 200))
        ok
    ok

    if gameState = ST_PAUSED
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 160))
        DrawText("PAUSED", floor(SCREEN_W/2 - MeasureText("PAUSED", 48) / 2),
                 floor(SCREEN_H/2 - 24), 48, RAYLIBColor(200, 255, 200, 255))
    ok

    if gameState = ST_GAMEOVER
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 210))
        DrawText("SHOT DOWN", floor(SCREEN_W/2 - MeasureText("SHOT DOWN", 52) / 2),
                 floor(SCREEN_H/2 - 90), 52, RAYLIBColor(255, 40, 40, 255))
        sTxt = "Score: " + string(score)
        DrawText(sTxt, floor(SCREEN_W/2 - MeasureText(sTxt, 26) / 2),
                 floor(SCREEN_H/2 - 30), 26, RAYLIBColor(200, 255, 200, 255))
        statTxt = "Kills: " + string(totalKills)
        DrawText(statTxt, floor(SCREEN_W/2 - MeasureText(statTxt, 16) / 2),
                 floor(SCREEN_H/2 + 5), 16, RAYLIBColor(150, 200, 150, 200))
        if totalShots > 0
            acc = floor((totalHits * 100) / totalShots)
            accTxt = "Accuracy: " + string(acc) + "%  |  Best Combo: " + string(maxCombo) + "x"
            DrawText(accTxt, floor(SCREEN_W/2 - MeasureText(accTxt, 16) / 2),
                     floor(SCREEN_H/2 + 28), 16, RAYLIBColor(150, 200, 150, 200))
        ok
        DrawText("Press ENTER to Return",
                 floor(SCREEN_W/2 - 110), floor(SCREEN_H/2 + 60), 20,
                 RAYLIBColor(150, 200, 150, 180))
    ok

    if gameState = ST_VICTORY
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 210))
        DrawText("MISSION COMPLETE!", floor(SCREEN_W/2 - MeasureText("MISSION COMPLETE!", 48) / 2),
                 floor(SCREEN_H/2 - 90), 48, RAYLIBColor(255, 220, 50, 255))
        sTxt = "Final Score: " + string(score)
        DrawText(sTxt, floor(SCREEN_W/2 - MeasureText(sTxt, 26) / 2),
                 floor(SCREEN_H/2 - 30), 26, RAYLIBColor(200, 255, 200, 255))
        DrawText("All 8 missions cleared!",
                 floor(SCREEN_W/2 - 100), floor(SCREEN_H/2 + 5), 20,
                 RAYLIBColor(200, 200, 200, 220))
        DrawText("Press ENTER to Return",
                 floor(SCREEN_W/2 - 110), floor(SCREEN_H/2 + 60), 20,
                 RAYLIBColor(150, 200, 150, 180))
    ok

    if gameState = ST_MISSIONINTRO
        mIntro = "MISSION " + string(mission)
        DrawText(mIntro, floor(SCREEN_W/2 - MeasureText(mIntro, 56) / 2),
                 floor(SCREEN_H/2 - 50), 56, RAYLIBColor(200, 255, 200, 255))
        if mission >= 1 and mission <= 8
            mName = missionNames[mission]
            DrawText(mName, floor(SCREEN_W/2 - MeasureText(mName, 24) / 2),
                     floor(SCREEN_H/2 + 15), 24, RAYLIBColor(255, 220, 100, 255))
        ok
        objText = "Destroy all targets"
        if rescueTarget > 0
            objText += " & rescue " + string(rescueTarget) + " hostages"
        ok
        DrawText(objText, floor(SCREEN_W/2 - MeasureText(objText, 16) / 2),
                 floor(SCREEN_H/2 + 50), 16, RAYLIBColor(150, 200, 150, 200))
    ok

    if gameState = ST_MISSIONCLEAR
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 150))
        clrTxt = "MISSION " + string(mission) + " CLEAR!"
        DrawText(clrTxt, floor(SCREEN_W/2 - MeasureText(clrTxt, 44) / 2),
                 floor(SCREEN_H/2 - 30), 44, RAYLIBColor(255, 220, 50, 255))
        bonusTxt = "Bonus: +" + string(mission * 500)
        DrawText(bonusTxt, floor(SCREEN_W/2 - MeasureText(bonusTxt, 20) / 2),
                 floor(SCREEN_H/2 + 20), 20, RAYLIBColor(200, 255, 200, 220))
    ok

// =============================================================
// Cockpit Overlay
// =============================================================

func heli_drawCockpitOverlay
    if gameState != ST_PLAYING and gameState != ST_MISSIONINTRO return ok

    // Bottom frame
    DrawRectangle(0, SCREEN_H - 24, SCREEN_W, 24, RAYLIBColor(20, 30, 20, 180))
    DrawRectangle(0, SCREEN_H - 26, SCREEN_W, 2, RAYLIBColor(80, 180, 80, 120))

    // Heading
    headDeg = floor(hYaw * 180 / PI)
    while headDeg < 0 headDeg += 360 end
    while headDeg >= 360 headDeg -= 360 end
    hTxt = "HDG:" + string(headDeg)
    DrawText(hTxt, floor(SCREEN_W / 2 - 25), SCREEN_H - 20, 14,
             RAYLIBColor(80, 200, 80, 200))

    // Camera mode
    camNames = ["Chase", "Cockpit", "Top"]
    cTxt = "CAM:" + camNames[camMode + 1]
    DrawText(cTxt, SCREEN_W - 100, SCREEN_H - 20, 14,
             RAYLIBColor(80, 200, 80, 200))

    // Controls
    DrawText("W/S:Fly A/D:Turn Q/E:Alt SPACE:Gun R:Rocket L:Land C:Cam",
             15, SCREEN_H - 18, 11, RAYLIBColor(60, 140, 60, 120))

// =============================================================
// Radar
// =============================================================

func heli_drawRadar
    if gameState != ST_PLAYING and gameState != ST_MISSIONINTRO return ok

    rSize = 90
    rX = SCREEN_W - rSize - 15
    rY = SCREEN_H - rSize - 35
    rScale = rSize / (TERRAIN_SIZE * 0.5)
    if radarZoom = 2 rScale = rScale * 2 ok
    if radarZoom = 3 rScale = rScale * 4 ok

    DrawRectangle(rX - 2, rY - 2, rSize + 4, rSize + 4, RAYLIBColor(0, 120, 0, 180))
    DrawRectangle(rX, rY, rSize, rSize, RAYLIBColor(0, 15, 0, 220))

    rcx = rX + rSize / 2
    rcy = rY + rSize / 2

    // Sweep
    sweepAng = animTime * 2.5
    DrawLine(rcx, rcy, rcx + floor(cos(sweepAng) * rSize / 2),
             rcy + floor(sin(sweepAng) * rSize / 2), RAYLIBColor(0, 80, 0, 60))

    // Enemies
    nEn = len(enemies)
    for e = 1 to nEn
        if !enemies[e][7] loop ok
        erx = rcx + floor((enemies[e][1] - hx) * rScale)
        ery = rcy + floor((enemies[e][3] - hz) * rScale)
        if erx > rX and erx < rX + rSize and ery > rY and ery < rY + rSize
            eClr = RAYLIBColor(255, 50, 50, 255)
            if enemies[e][4] = 2 eClr = RAYLIBColor(255, 100, 50, 255) ok
            if enemies[e][4] = 5 eClr = RAYLIBColor(255, 255, 100, 255) ok
            DrawRectangle(erx - 2, ery - 2, 4, 4, eClr)
        ok
    next

    // Rescue zones
    nRZ = len(rescueZones)
    for i = 1 to nRZ
        if rescueZones[i][3] loop ok
        rrx = rcx + floor((rescueZones[i][1] - hx) * rScale)
        rry = rcy + floor((rescueZones[i][2] - hz) * rScale)
        if rrx > rX and rrx < rX + rSize and rry > rY and rry < rY + rSize
            DrawRectangle(rrx - 2, rry - 2, 5, 5, RAYLIBColor(255, 220, 50, 200))
        ok
    next

    // Missiles on radar
    nM = len(missiles)
    for i = 1 to nM
        if !missiles[i][7] loop ok
        mrx = rcx + floor((missiles[i][1] - hx) * rScale)
        mry = rcy + floor((missiles[i][3] - hz) * rScale)
        if mrx > rX and mrx < rX + rSize and mry > rY and mry < rY + rSize
            flash = floor(sin(animTime * 10) * 80 + 175)
            DrawRectangle(mrx - 1, mry - 1, 3, 3, RAYLIBColor(255, 50, 255, flash))
        ok
    next

    // Player
    DrawRectangle(rcx - 2, rcy - 2, 4, 4, RAYLIBColor(100, 255, 100, 255))
    pdx = sin(hYaw) * 6
    pdz = cos(hYaw) * 6
    DrawLine(rcx, rcy, rcx + floor(pdx), rcy + floor(pdz), RAYLIBColor(100, 255, 100, 200))

    // Label
    zTxt = "x1"
    if radarZoom = 2 zTxt = "x2" ok
    if radarZoom = 3 zTxt = "x4" ok
    DrawText("RADAR " + zTxt, rX, rY - 14, 11, RAYLIBColor(80, 200, 80, 200))

// =============================================================
// Utility Functions
// =============================================================

func heli_fabs n
    if n < 0 return -n ok
    return n

func heli_atan2 dx, dz
    if dz = 0 and dx = 0 return 0 ok
    dist = sqrt(dx * dx + dz * dz)
    if dist = 0 return 0 ok
    angle = asin(dx / dist)
    if dz < 0 angle = PI - angle ok
    return angle

func heli_dist x1, y1, x2, y2
    dx = x2 - x1
    dy = y2 - y1
    return sqrt(dx * dx + dy * dy)

func heli_dist3 x1, y1, z1, x2, y2, z2
    dx = x2 - x1
    dy = y2 - y1
    dz = z2 - z1
    return sqrt(dx*dx + dy*dy + dz*dz)

func heli_fexists path
    try
        fp = fopen(path, "r")
        fclose(fp)
        return true
    catch
        return false
    done
