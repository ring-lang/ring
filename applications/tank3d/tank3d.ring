/*
**  3D Tank Battle - Ultimate Edition - Using RingRayLib
**  =====================================================
**  Classic Battle City in full 3D - Remastered!
**
**  Controls:
**    Arrow Keys / WASD  -  Move tank
**    Space / Enter      -  Fire cannon
**    C                  -  Cycle camera
**    P                  -  Pause
**    R                  -  Restart level
**    N / B              -  Next / Previous level
**    ESC                -  Exit
**
**  Ultimate Edition Features:
**    - 12 levels with unique themes & increasing difficulty
**    - Boss battles every 4th level (Stages 4, 8, 12)
**    - 6 enemy types: Basic, Normal, Fast, Heavy, Stealth, Boss
**    - 5 power-ups: Star, Shield, Bomb, Freeze, Extra Life
**    - Lava hazard terrain (damages tanks!)
**    - Combo scoring (chain kills for score multipliers)
**    - Screen shake on explosions
**    - Difficulty scaling (more/faster enemies per level)
**    - High score tracking
**    - Level names and boss approach warnings
**
**  Sound files required (in sounds/ folder):
**    fire.wav, hit_wall.wav, explosion.wav,
**    powerup.wav, player_death.wav, steel_hit.wav,
**    brick_break.wav, level_clear.wav, game_over.wav,
**    enemy_hit.wav, bomb.wav, engine.wav, victory.wav,
**    menu_music.wav, battle_music.wav
*/

// =============================================================
// Load Source Files
// =============================================================

load "raylib.ring"
load "constants.ring"
load "levels.ring"
load "input.ring"
load "update.ring"
load "explosions.ring"
load "powerups.ring"
load "camera.ring"
load "draw3d.ring"
load "hud.ring"
load "music.ring"
load "globals.ring"

// =============================================================
// Main
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Ring 3D Tank Battle - Ultimate Edition - RingRayLib")
monIdx = GetCurrentMonitor()
monW = GetMonitorWidth(monIdx)
monH = GetMonitorHeight(monIdx)
SetWindowSize(monW, monH)
ToggleFullScreen()
SCREEN_W = GetScreenWidth()
SCREEN_H = GetScreenHeight()
SetTargetFPS(60)

// Initialize audio
tank_initAudio()

cam = Camera3D(
    GRID_W/2, 30, GRID_H/2 + 5,
    GRID_W/2, 0, GRID_H/2,
    0, 1, 0,
    45,
    0
)

tank_loadLevel(level)

while !WindowShouldClose()
    dt = GetFrameTime()
    if dt > 0.05 dt = 0.05 ok

    animTime += dt

    // Update music stream
    tank_updateMusic()

    tank_handleInput(dt)
    tank_update(dt)

    // Update screen shake
    if shakeTimer > 0
        shakeTimer -= dt
        if shakeTimer < 0 shakeTimer = 0 ok
    ok

    BeginDrawing()
        ClearBackground(RAYLIBColor(10, 10, 10, 255))
        tank_updateCamera()
        BeginMode3D(cam)
            tank_drawFloor()
            tank_drawWalls3D()
            tank_drawBase3D()
            tank_drawTrees3D()
            tank_drawLava3D()
            tank_drawPlayer3D()
            tank_drawEnemies3D()
            tank_drawBullets3D()
            tank_drawExplosions3D()
            tank_drawPowerups3D()
            tank_drawParticles3D()
        EndMode3D()
        tank_drawHUD()
        tank_drawMinimap()
    EndDrawing()
end

// Cleanup audio
tank_cleanupAudio()

CloseWindow()
