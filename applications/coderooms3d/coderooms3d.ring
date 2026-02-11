/*
**  Code Rooms 3D - Programming Puzzle Game
**  ==========================================
**  Using Ring Language + RingRayLib
**
**  The Player is trapped in a world of rooms separated by closed doors.
**  To open each door, you must push code blocks into the correct
**  order on the assembly line to form a valid program.
**
**  Controls:
**    Arrow Keys / WASD  -  Move player
**    R                  -  Restart current room
**    C                  -  Cycle camera view
**    U                  -  Undo last move
**    N / Page Down      -  Next level
**    P / Page Up        -  Previous level
**    ESC                -  Exit
**
**  Developed using Ring Language + RingRayLib
**
**  Source files:
**    coderooms3d.ring  -  Main (init, game loop)
**    globals.ring      -  Constants & global variables
**    rooms.ring     -  Room definitions (10 puzzle rooms)
**    utils.ring     -  Utility functions (fabs, isdigit, cr_tan)
**    gameplay.ring  -  Gameplay (input, movement, undo, solving, camera)
**    drawing.ring   -  3D drawing (floor, walls, blocks, player, etc.)
**    hud.ring       -  HUD, title screen, overlays
**    weather.ring   -  Weather system (6 weather types)
**    sound.ring        -  Audio (load/unload sounds and music)
*/

load "raylib.ring"
load "globals.ring"
load "rooms.ring"
load "utils.ring"
load "gameplay.ring"
load "drawing.ring"
load "hud.ring"
load "weather.ring"
load "sound.ring"

// =============================================================
// Initialize Window & Fullscreen
// =============================================================

monIdx = GetCurrentMonitor()
monW = GetMonitorWidth(monIdx)
monH = GetMonitorHeight(monIdx)

InitWindow(monW, monH, "Code Rooms 3D - Programming Puzzle Game")
SetTargetFPS(60)
ToggleFullscreen()
BeginDrawing()
ClearBackground(RAYLIBColor(0, 0, 0, 255))
EndDrawing()
 

SCREEN_W = GetScreenWidth()
SCREEN_H = GetScreenHeight()

// Re-init weather positions for actual screen size
w_initPositions()

// Load Sounds & Music
cr_loadAudio()

cam = Camera3D(0,0,0, 0,0,0, 0,1,0, 55, 0)

// Load first room
cr_loadRoom(1)

// =============================================================
// Main Game Loop
// =============================================================

while not WindowShouldClose()

    dt = GetFrameTime()
    animTime += dt
    UpdateMusicStream(bgMusic)

    // --- Input & Update ---
    if gameState = GS_TITLE
        gpStart = 0
        if IsGamepadAvailable(0)
            // Start button (11) or A/South button (7)
            if IsGamepadButtonPressed(0, 11) or IsGamepadButtonPressed(0, 7)
                gpStart = 1
            ok
        ok
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or gpStart
            PlaySound(sndMenu)
            gameState = GS_PLAYING
        ok
    ok

    if gameState = GS_PLAYING
        cr_handleInput()
        cr_updateAnimations(dt)
        cr_updateParticles(dt)
        anyMoving = 0
        if pMoving = 1 anyMoving = 1 ok
        for bi = 1 to blockCount
            if blocks[bi][8] = 1 anyMoving = 1 ok
        next
        if anyMoving = 0
            cr_checkSolved()
        ok
    ok

    if gameState = GS_SOLVED
        solveTimer += dt
        cr_updateParticles(dt)
        if solveTimer > 2.0
            doorOpen = 1
            tiles[doorRow][doorCol] = T_DOOROPEN
            PlaySound(sndDoor)
            gameState = GS_PLAYING
        ok
    ok

    if gameState = GS_TRANS
        transTimer += dt
        if transTimer > 1.0
            if currentRoom < roomCount
                currentRoom++
                cr_loadRoom(currentRoom)
                gameState = GS_PLAYING
            else
                PlaySound(sndWin)
                gameState = GS_WON
            ok
        ok
    ok

    if IsKeyPressed(KEY_C)
        camMode = (camMode + 1) % 3
    ok

    cr_updateCamera()
    w_update(dt)

    // --- Draw ---
    BeginDrawing()
    ClearBackground(RAYLIBColor(20, 18, 30, 255))

    w_drawSky()
    w_drawStars()
    w_drawCelestial()
    w_drawClouds()

    if gameState = GS_TITLE
        w_drawDrops()
        w_drawLightning()
        if currentWeather = W_FOG  w_drawFog()  ok
        cr_drawTitle()
    ok

    if gameState != GS_TITLE

        BeginMode3D(cam)
            cr_drawFloor()
            cr_drawWalls()
            cr_drawSlots()
            cr_drawBlocks()
            cr_drawDoor()
            cr_drawPlayer()
            cr_drawParticles3D()
        EndMode3D()

        w_drawDrops()
        w_drawLightning()
        if currentWeather = W_FOG  w_drawFog()  ok

        if wFlashAlpha > 0
            fa = floor(wFlashAlpha)
            if fa > 255 fa = 255 ok
            DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(255, 255, 240, fa))
        ok

        if currentWeather = W_RAIN
            DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(30, 40, 80, 55))
        ok
        if currentWeather = W_STORM
            DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(20, 20, 50, 75))
        ok
        if currentWeather = W_SNOW
            DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(200, 210, 230, 35))
        ok
        if currentWeather = W_FOG
            DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(160, 170, 180, 65))
        ok

        cr_drawHUD()

        if gameState = GS_SOLVED
            cr_drawSolvedOverlay()
        ok

        if gameState = GS_WON
            cr_drawWinScreen()
        ok

        if gameState = GS_TRANS
            alpha = floor(transTimer / 1.0 * 255)
            if alpha > 255 alpha = 255 ok
            DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, alpha))
        ok
    ok

    EndDrawing()
end

// =============================================================
// Cleanup
// =============================================================

cr_unloadAudio()

CloseWindow()
