/*
**  tank3d_explosions.ring
**  Explosions, particles, muzzle flash, and screen shake
*/

// =============================================================
// Screen Shake
// =============================================================

func tank_triggerShake intensity, duration
    shakeIntensity = intensity
    shakeDuration = duration
    shakeTimer = duration

// =============================================================
// Explosion Spawning
// =============================================================

func tank_spawnBrickExplosion gc, gr
    wx = gc * 1.0
    wy = gr * 1.0
    add(explosions, [wx, wy, 0.4, 0.4, 0.8])
    for i = 1 to 8
        ang = GetRandomValue(0, 628) / 100.0
        spd = GetRandomValue(100, 400) / 100.0
        add(particles, [wx, 0.5, wy,
                        cos(ang) * spd, GetRandomValue(100, 400)/100.0, sin(ang) * spd,
                        0.6, 0.6,
                        GetRandomValue(150, 200), GetRandomValue(80, 130), 30,
                        0.06])
    next

func tank_spawnSmallExplosion bx, by
    add(explosions, [bx, by, 0.25, 0.25, 0.4])
    for i = 1 to 5
        ang = GetRandomValue(0, 628) / 100.0
        spd = GetRandomValue(100, 300) / 100.0
        add(particles, [bx, 0.4, by,
                        cos(ang) * spd, GetRandomValue(100, 300)/100.0, sin(ang) * spd,
                        0.4, 0.4,
                        255, GetRandomValue(150, 255), 30,
                        0.05])
    next

func tank_spawnBigExplosion bx, by
    add(explosions, [bx, by, 0.8, 0.8, 1.5])
    for i = 1 to 20
        ang = GetRandomValue(0, 628) / 100.0
        spd = GetRandomValue(200, 600) / 100.0
        add(particles, [bx, 0.5, by,
                        cos(ang) * spd, GetRandomValue(200, 600)/100.0, sin(ang) * spd,
                        1.0, 1.0,
                        255, GetRandomValue(100, 255), GetRandomValue(0, 80),
                        0.10])
    next

// =============================================================
// Muzzle Flash
// =============================================================

func tank_muzzleFlash bx, by, dir
    dx = 0 dy = 0
    if dir = DIR_UP dy = -0.6 ok
    if dir = DIR_DOWN dy = 0.6 ok
    if dir = DIR_LEFT dx = -0.6 ok
    if dir = DIR_RIGHT dx = 0.6 ok
    fx = bx + dx
    fy = by + dy
    for i = 1 to 4
        add(particles, [fx, 0.5, fy,
                        GetRandomValue(-100, 100)/100.0, GetRandomValue(100, 300)/100.0,
                        GetRandomValue(-100, 100)/100.0,
                        0.2, 0.2,
                        255, 255, 150,
                        0.06])
    next

// =============================================================
// Explosion & Particle Updates
// =============================================================

func tank_updateExplosions dt
    i = 1
    while i <= len(explosions)
        explosions[i][3] -= dt
        if explosions[i][3] <= 0
            del(explosions, i)
        else
            i += 1
        ok
    end

func tank_updateParticles dt
    i = 1
    while i <= len(particles)
        particles[i][1] += particles[i][4] * dt
        particles[i][2] += particles[i][5] * dt
        particles[i][3] += particles[i][6] * dt
        particles[i][5] -= 5.0 * dt  // gravity
        particles[i][7] -= dt
        if particles[i][7] <= 0
            del(particles, i)
        else
            i += 1
        ok
    end
