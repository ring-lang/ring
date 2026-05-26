/*
**  Dave the Fighter - Sound & Music
**  Functions: dave_initAudio, dave_loadSounds, dave_startMusic, dave_cleanupAudio
*/

func dave_initAudio
    InitAudioDevice()

func dave_loadSounds
    sndJump       = LoadSound("sounds/jump.wav")
    sndGem        = LoadSound("sounds/gem.wav")
    sndRuby       = LoadSound("sounds/ruby.wav")
    sndRing       = LoadSound("sounds/ring.wav")
    sndKey        = LoadSound("sounds/key.wav")
    sndDoor       = LoadSound("sounds/door.wav")
    sndTrophy     = LoadSound("sounds/trophy.wav")
    sndShoot      = LoadSound("sounds/shoot.wav")
    sndEnemyShoot = LoadSound("sounds/enemy_shoot.wav")
    sndEnemyDie   = LoadSound("sounds/enemy_die.wav")
    sndHurt       = LoadSound("sounds/hurt.wav")
    sndGunPickup  = LoadSound("sounds/gun_pickup.wav")

func dave_startMusic
    bgMusic = LoadMusicStream("sounds/music.wav")
    PlayMusicStream(bgMusic)
    SetMusicVolume(bgMusic, 0.5)

func dave_cleanupAudio
    UnloadMusicStream(bgMusic)
    UnloadSound(sndJump)
    UnloadSound(sndGem)
    UnloadSound(sndRuby)
    UnloadSound(sndRing)
    UnloadSound(sndKey)
    UnloadSound(sndDoor)
    UnloadSound(sndTrophy)
    UnloadSound(sndShoot)
    UnloadSound(sndEnemyShoot)
    UnloadSound(sndEnemyDie)
    UnloadSound(sndHurt)
    UnloadSound(sndGunPickup)
    CloseAudioDevice()
