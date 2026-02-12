/*
**  Dave the Fighter - 3D Action Platformer
**  ==========================================
**  Using RingRayLib
**  Fight your way through 20 dangerous levels!
**  Collect gems, grab weapons, defeat enemies,
**  find keys to unlock doors, and claim the
**  trophy to advance!
**
**  Controls:
**    Arrow Keys / WASD  -  Move left/right
**    Space / Up / W     -  Jump
**    F                  -  Shoot (when gun collected)
**    N / B              -  Next / Previous level
**    C                  -  Cycle camera
**    P                  -  Pause
**    R                  -  Restart level
**    ESC                -  Exit
**
**  Collectibles:
**    Blue Gems     =  100 points
**    Red Rubies    =  250 points
**    Gold Ring     =  500 points
**    Gun           -  Shoot enemies! (press F)
**    Key           -  Opens locked door
**    Trophy        -  Complete the level!
**
**  Features:
**    - 20 unique levels across 4 themed worlds
**    - Red World (1-5): Learn the basics
**    - Blue World (6-10): Combat with guns and shooting enemies
**    - Ice World (11-15): Double-width levels with new mechanics
**    - Sand World (16-20): Ultra-wide levels, ultimate challenge
**    - Moving platforms (horizontal & vertical)
**    - Falling icicles that detect the player
**    - Crumbling platforms that break underfoot
**    - Wind zones that push the player
**    - Mid-level checkpoints
**    - Smooth platformer physics
**    - Enemies: guards, bats, and soldiers
**    - Rich 3D graphics with lighting effects
**    - Sound effects and chiptune background music
**
**  Source Code Files:
**    dave3d.ring      -  Main file (game loop)
**    constants.ring   -  Game constants
**    globals.ring     -  Global variables
**    sound.ring       -  Sound & music management
**    levels.ring      -  Level loader + levels 1-5
**    levels2.ring     -  Levels 6-10 (gun & shooting enemies)
**    levels3.ring     -  Levels 11-15 (ice world, new mechanics)
**    levels4.ring     -  Levels 16-20 (sand world, ultra-wide)
**    input.ring       -  Input handling
**    update.ring      -  Game update, enemy AI, bullet systems
**    collision.ring   -  Collision detection & player death
**    particles.ring   -  Particle effects & popups
**    camera.ring      -  Camera control
**    draw.ring        -  3D rendering
**    hud.ring         -  HUD overlay & game state screens
*/

load "raylib.ring"
load "constants.ring"
load "globals.ring"
load "sound.ring"
load "levels.ring"
load "levels2.ring"
load "levels3.ring"
load "levels4.ring"
load "input.ring"
load "update.ring"
load "collision.ring"
load "particles.ring"
load "camera.ring"
load "draw.ring"
load "hud.ring"

// =============================================================
// Main
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Dave the Fighter - 3D Action Platformer - RingRayLib")
monIdx = GetCurrentMonitor()
monW = GetMonitorWidth(monIdx)
monH = GetMonitorHeight(monIdx)
SetWindowSize(monW, monH)
ToggleFullScreen()
SCREEN_W = GetScreenWidth()
SCREEN_H = GetScreenHeight()
SetTargetFPS(60)

dave_initAudio()
dave_loadSounds()
dave_startMusic()

cam = Camera3D(
    0, 10, 12,
    0, 0, 0,
    0, 1, 0,
    45,
    0
)

dave_loadLevel(level)

while !WindowShouldClose()
    dt = GetFrameTime()
    if dt > 0.05 dt = 0.05 ok
    animTime += dt

    UpdateMusicStream(bgMusic)

    dave_handleInput(dt)
    dave_update(dt)

    BeginDrawing()
        ClearBackground(RAYLIBColor(5, 5, 15, 255))
        dave_updateCamera()
        BeginMode3D(cam)
            dave_drawLevel3D()
            dave_drawMovers3D()
            dave_drawIcicles3D()
            dave_drawCollectibles3D()
            dave_drawEnemies3D()
            dave_drawPlayer3D()
            dave_drawBullets3D()
            dave_drawParticles3D()
        EndMode3D()
        dave_drawHUD()
    EndDrawing()
end

dave_cleanupAudio()
CloseWindow()
