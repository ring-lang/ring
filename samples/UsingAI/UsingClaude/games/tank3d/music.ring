/*
**  tank3d_music.ring
**  Music management and helper functions
*/

// =============================================================
// Audio Initialization
// =============================================================

func tank_initAudio
    // Initialize audio system
    InitAudioDevice()

    // Load sound effects (from sounds/ folder)
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

    // Load music streams
    musMenu   = LoadMusicStream("sounds/menu_music.wav")
    musBattle = LoadMusicStream("sounds/battle_music.wav")

    // Set volumes
    SetSoundVolume(sndFire, 0.7)
    SetSoundVolume(sndHitWall, 0.5)
    SetSoundVolume(sndExplosion, 0.8)
    SetSoundVolume(sndPowerup, 0.7)
    SetSoundVolume(sndPlayerDeath, 0.9)
    SetSoundVolume(sndSteelHit, 0.5)
    SetSoundVolume(sndBrickBreak, 0.5)
    SetSoundVolume(sndLevelClear, 0.8)
    SetSoundVolume(sndGameOver, 0.9)
    SetSoundVolume(sndEnemyHit, 0.5)
    SetSoundVolume(sndBomb, 0.8)
    SetSoundVolume(sndEngine, 0.3)
    SetSoundVolume(sndVictory, 0.8)
    SetMusicVolume(musMenu, 0.75)
    SetMusicVolume(musBattle, 1.0)

    // Start menu music
    PlayMusicStream(musMenu)
    musicPlaying = 1

// =============================================================
// Audio Cleanup
// =============================================================

func tank_cleanupAudio
    // Unload sounds
    UnloadSound(sndFire)
    UnloadSound(sndHitWall)
    UnloadSound(sndExplosion)
    UnloadSound(sndPowerup)
    UnloadSound(sndPlayerDeath)
    UnloadSound(sndSteelHit)
    UnloadSound(sndBrickBreak)
    UnloadSound(sndLevelClear)
    UnloadSound(sndGameOver)
    UnloadSound(sndEnemyHit)
    UnloadSound(sndBomb)
    UnloadSound(sndEngine)
    UnloadSound(sndVictory)

    // Unload music
    UnloadMusicStream(musMenu)
    UnloadMusicStream(musBattle)

    // Close audio device
    CloseAudioDevice()

// =============================================================
// Music Management
// =============================================================

func tank_updateMusic
    // Update the currently playing music stream
    if musicPlaying = 1
        UpdateMusicStream(musMenu)
    ok
    if musicPlaying = 2
        UpdateMusicStream(musBattle)
    ok

    // Switch music based on game state
    if gameState = ST_TITLE or gameState = ST_GAMEOVER or gameState = ST_WON
        if musicPlaying != 1
            StopMusicStream(musBattle)
            PlayMusicStream(musMenu)
            musicPlaying = 1
        ok
    ok
    if gameState = ST_PLAYING or gameState = ST_LEVELUP
        if musicPlaying != 2
            StopMusicStream(musMenu)
            PlayMusicStream(musBattle)
            musicPlaying = 2
        ok
    ok
    if gameState = ST_PAUSED
        if musicPlaying = 2
            PauseMusicStream(musBattle)
            musicPlaying = 0
        ok
    ok

// =============================================================
// Helper: Absolute Value
// =============================================================

func fabs n
    if n < 0 return -n ok
    return n
