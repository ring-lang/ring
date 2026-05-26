/*
**  sound.ring - Audio Functions
**  Code Rooms 3D
**  Load and unload sound effects and music
*/

func cr_loadAudio
    InitAudioDevice()
    sndStep     = LoadSound("sounds/step.wav")
    sndPush     = LoadSound("sounds/push.wav")
    sndPlace    = LoadSound("sounds/place.wav")
    sndCorrect  = LoadSound("sounds/correct.wav")
    sndWrong    = LoadSound("sounds/wrong.wav")
    sndSolved   = LoadSound("sounds/solved.wav")
    sndDoor     = LoadSound("sounds/door.wav")
    sndTransit  = LoadSound("sounds/transition.wav")
    sndUndo     = LoadSound("sounds/undo.wav")
    sndBump     = LoadSound("sounds/bump.wav")
    sndMenu     = LoadSound("sounds/menu.wav")
    sndWin      = LoadSound("sounds/win.wav")
    bgMusic     = LoadMusicStream("sounds/music.ogg")
    SetMusicVolume(bgMusic, 1.0)
    PlayMusicStream(bgMusic)

func cr_unloadAudio
    UnloadSound(sndStep)
    UnloadSound(sndPush)
    UnloadSound(sndPlace)
    UnloadSound(sndCorrect)
    UnloadSound(sndWrong)
    UnloadSound(sndSolved)
    UnloadSound(sndDoor)
    UnloadSound(sndTransit)
    UnloadSound(sndUndo)
    UnloadSound(sndBump)
    UnloadSound(sndMenu)
    UnloadSound(sndWin)
    UnloadMusicStream(bgMusic)
    CloseAudioDevice()
