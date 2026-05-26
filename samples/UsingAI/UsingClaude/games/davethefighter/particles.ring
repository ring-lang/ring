/*
**  Dave the Fighter - Particle Effects & Popups
**  Functions: dave_spawnPickupParticles, dave_updateParticles, dave_updatePopups
*/

func dave_spawnPickupParticles x, y, pr, pg, pb
    for i = 1 to 12
        ang = GetRandomValue(0, 628) / 100.0
        spd = GetRandomValue(100, 350) / 100.0
        add(particles, [x, y,
                        cos(ang) * spd, sin(ang) * spd + 2.0,
                        0.8, 0.8,
                        pr, pg, pb,
                        0.08])
    next

func dave_updateParticles dt
    i = 1
    nParts = len(particles)
    while i <= nParts
        particles[i][1] += particles[i][3] * dt
        particles[i][2] += particles[i][4] * dt
        particles[i][4] -= 8.0 * dt  // gravity on particles
        particles[i][5] -= dt
        if particles[i][5] <= 0
            del(particles, i)
            nParts -= 1
        else
            i += 1
        ok
    end

func dave_updatePopups dt
    i = 1
    nPops = len(popups)
    while i <= nPops
        popups[i][2] += dt * 1.5  // Float up
        popups[i][4] -= dt
        if popups[i][4] <= 0
            del(popups, i)
            nPops -= 1
        else
            i += 1
        ok
    end
