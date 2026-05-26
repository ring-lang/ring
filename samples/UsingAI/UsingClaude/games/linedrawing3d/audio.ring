/*
**  ld_audio.ring
**  Audio initialization and sound loading
*/

func ld_initAudio
    InitAudioDevice()

    // Load music (streaming)
    bgMusic = LoadMusicStream("sound/dungeon_ambient.wav")
    PlayMusicStream(bgMusic)
    SetMusicVolume(bgMusic, 1.0)

    // Load sound effects
    sndFootstep = LoadSound("sound/footstep.wav")
    sndDoorOpen = LoadSound("sound/door_open.wav")
    sndPuzzleOpen = LoadSound("sound/puzzle_open.wav")
    sndPuzzleSolved = LoadSound("sound/puzzle_solved.wav")
    sndPuzzleFail = LoadSound("sound/puzzle_fail.wav")
    sndWinFanfare = LoadSound("sound/win_fanfare.wav")
    sndPathDraw = LoadSound("sound/path_draw.wav")
    sndSphereCollect = LoadSound("sound/sphere_collect.wav")

    // Set volumes
    SetSoundVolume(sndFootstep, 0.3)
    SetSoundVolume(sndDoorOpen, 0.6)
    SetSoundVolume(sndPuzzleOpen, 0.5)
    SetSoundVolume(sndPuzzleSolved, 0.7)
    SetSoundVolume(sndPuzzleFail, 0.5)
    SetSoundVolume(sndWinFanfare, 0.8)
    SetSoundVolume(sndPathDraw, 0.25)
    SetSoundVolume(sndSphereCollect, 0.7)

func ld_closeAudio
    UnloadMusicStream(bgMusic)
    UnloadSound(sndFootstep)
    UnloadSound(sndDoorOpen)
    UnloadSound(sndPuzzleOpen)
    UnloadSound(sndPuzzleSolved)
    UnloadSound(sndPuzzleFail)
    UnloadSound(sndWinFanfare)
    UnloadSound(sndPathDraw)
    UnloadSound(sndSphereCollect)
    CloseAudioDevice()
