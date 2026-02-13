/*
**  LINE DRAWING 3D - Puzzle Maze Explorer
**  =======================================
**  A first-person 3D maze game where you solve
**  line-drawing puzzles on walls to open doors.
**
**  Controls:
**    EXPLORATION MODE:
**      W/S or Up/Down    - Move forward/backward
**      A/D or Left/Right - Strafe left/right
**      Mouse             - Look around
**      TAB               - Toggle minimap
**      ESC               - Exit
**
**    PUZZLE MODE:
**      Arrow Keys / Mouse Drag - Draw path along grid edges
**      Backspace / U           - Undo last path segment
**      Z                       - Clear entire path
**      F                       - Auto-solve puzzle
**      ENTER                   - Validate path
**      ESC / Q                 - Cancel puzzle (back to explore)
**
**  Rules:
**    - Find glowing puzzle panels on walls near doors
**    - Trace from START circle to EXIT notch along edges
**    - Pass through all yellow DOTS (required)
**    - Avoid BROKEN edges (red markers)
**    - Separate BLACK and WHITE squares by path
**    - Solving the puzzle opens the nearby door
**    - Collect spheres for inspiring life quotes
**    - Solve all 15 puzzles to win!
*/

// === Load files ===
load "raylib.ring"
load "constants.ring"
load "globals.ring"
load "puzzledefs.ring"
load "audio.ring"
load "helpers.ring"
load "level.ring"
load "explore.ring"
load "puzzle.ring"
load "render.ring"

// =============================================================
// Initialization
// =============================================================

// Initialize window first to query monitor info
SetConfigFlags(FLAG_WINDOW_RESIZABLE)
InitWindow(800, 600, "Line Drawing 3D - Puzzle Maze Explorer")

// Get maximum supported resolution from current monitor
curMonitor = GetCurrentMonitor()
monW = GetMonitorWidth(curMonitor)
monH = GetMonitorHeight(curMonitor)
if monW > 0 and monH > 0
    SCREEN_W = monW
    SCREEN_H = monH
ok
centerX = SCREEN_W / 2
centerY = SCREEN_H / 2

// Set to fullscreen at maximum resolution
SetWindowSize(SCREEN_W, SCREEN_H)
ToggleFullscreen()

SetTargetFPS(60)
HideCursor()
SetMousePosition(centerX, centerY)

cam = Camera3D(
    3.5, 0.5, 3.5,
    4.5, 0.5, 3.5,
    0, 1, 0,
    60,
    0
)

// Load the texture atlas for walls/floor/ceiling
texWall = LoadTexture("image/cubicmap_atlas.png")

// Initialize audio
ld_initAudio()

// Load level
ld_loadLevel(1)

// Disable ESC auto-close (we handle ESC ourselves for puzzle cancel)
SetExitKey(0)

// =============================================================
// Main Game Loop
// =============================================================

while !WindowShouldClose()
    dt = GetFrameTime()
    if dt > 0.05 dt = 0.05 ok

    // Update music stream
    UpdateMusicStream(bgMusic)

    animTime += dt

    if msgTimer > 0
        // Advance character reveal
        msgLen = len(msgText)
        if msgCharCount < msgLen
            msgCharAccum += dt * msgCharSpeed
            if msgCharAccum >= 1.0
                addChars = floor(msgCharAccum)
                msgCharCount += addChars
                if msgCharCount >= msgLen
                    msgCharCount = msgLen
                    // All characters shown - start 0.5s countdown
                    msgTimer = 1.5
                ok
                msgCharAccum -= addChars
            ok
        else
            // All revealed - count down to hide
            msgTimer -= dt
        ok
    ok

    switch gameState
    on ST_TITLE
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsMouseButtonPressed(0)
            gameState = ST_EXPLORE
            SetMousePosition(centerX, centerY)
        ok
        if IsKeyPressed(KEY_ESCAPE)
            CloseWindow()
            bye
        ok
    on ST_EXPLORE
        ld_handleExploreInput(dt)
        ld_updateFireworks(dt)
        // Check if all puzzles solved
        ld_checkAllSolved()
    on ST_PUZZLE
        ld_handlePuzzleInput(dt)
        ld_updatePuzzleParticles(dt)
        if puzzSolverActive
            ld_updateSolver(dt)
        ok
        if puzzValidTimer > 0
            puzzValidTimer -= dt
            if puzzValidTimer <= 0
                puzzFailed = false
            ok
        ok
    on ST_SOLVED
        solvedTimer -= dt
        ld_updatePuzzleParticles(dt)
        if solvedTimer <= 0
            gameState = ST_EXPLORE
            HideCursor()
            SetMousePosition(centerX, centerY)
            // Check if that was the last puzzle
            ld_checkAllSolved()
        ok
    on ST_WON
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            ld_loadLevel(1)
            gameState = ST_TITLE
        ok
    off

    // Render
    BeginDrawing()
        ClearBackground(RAYLIBColor(20, 22, 30, 255))

        if gameState = ST_TITLE
            ld_drawTitle()
        ok

        if gameState = ST_EXPLORE or gameState = ST_WON
            // Sky/ambient background behind the 3D world
            DrawRectangleGradientV(0, 0, SCREEN_W, SCREEN_H/2,
                                   RAYLIBColor(30, 35, 55, 255),
                                   RAYLIBColor(20, 22, 30, 255))

            ld_updateCamera()
            BeginMode3D(cam)
                ld_drawMap()
                ld_drawDoors()
                ld_drawPuzzlePanels3D()
                ld_drawSpheres3D()
                ld_drawFireworks()
            EndMode3D()

            ld_drawCrosshair()
            ld_drawExploreHUD()

            if showMap
                ld_drawMinimap()
            ok

            ld_drawDoorPrompt()

            if gameState = ST_WON
                ld_drawWinOverlay()
            ok
        ok

        if gameState = ST_PUZZLE or gameState = ST_SOLVED
            // Draw the 3D world in background
            DrawRectangleGradientV(0, 0, SCREEN_W, SCREEN_H/2,
                                   RAYLIBColor(20, 22, 30, 255),
                                   RAYLIBColor(15, 16, 20, 255))

            ld_updateCamera()
            BeginMode3D(cam)
                ld_drawMap()
                ld_drawDoors()
                ld_drawPuzzlePanels3D()
            EndMode3D()

            // Dim overlay
            DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 180))

            // Draw puzzle panel in 2D overlay
            ld_drawPuzzle2D()

            if gameState = ST_SOLVED
                ld_drawSolvedOverlay()
            ok
        ok

        // Message display (quotes, notifications) - character by character
        if msgTimer > 0
            mA = 255
            if msgTimer < 0.5 mA = floor(msgTimer * 510) ok
            msgLen = len(msgText)
            fontSize = 36
            if msgLen > 40 fontSize = 32 ok
            if msgLen > 55 fontSize = 28 ok
            // Size box based on full text so it doesn't resize
            mW = MeasureText(msgText, fontSize)
            msgX = floor(SCREEN_W/2 - mW/2)
            msgY = floor(SCREEN_H/2 - fontSize/2)
            DrawRectangle(msgX - 20, msgY - 12, mW + 40, fontSize + 24,
                         RAYLIBColor(40, 30, 70, floor(mA * 0.85)))
            DrawRectangleLines(msgX - 20, msgY - 12, mW + 40, fontSize + 24,
                         RAYLIBColor(120, 100, 200, mA))
            // Show only revealed characters
            if msgCharCount > 0
                visibleText = left(msgText, msgCharCount)
                DrawText(visibleText, msgX, msgY, fontSize,
                         RAYLIBColor(255, 255, 255, mA))
            ok
        ok

    EndDrawing()
end

// =============================================================
// Cleanup
// =============================================================

ShowCursor()
if hasMapModel
    UnloadModel(mapModel)
    UnloadTexture(mapTexture)
ok
UnloadTexture(texWall)
CloseWindow()
