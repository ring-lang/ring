/*
**  ld_helpers.ring
**  Utility functions
*/

func ld_showMsg txt
    msgText = txt
    msgTimer = 99.0    // stays alive until typing finishes
    msgCharCount = 0
    msgCharAccum = 0.0

func fabs n
    if n < 0 return -n ok
    return n

// Firework celebration particles
func ld_spawnFireworks x, y, z, spType
    // Direction away from player
    awayX = x - pX
    awayZ = z - pZ
    awayLen = sqrt(awayX * awayX + awayZ * awayZ)
    if awayLen < 0.01
        awayX = 0   awayZ = 1
    else
        awayX = awayX / awayLen
        awayZ = awayZ / awayLen
    ok

    // Spawn 40 particles bursting away from player
    for i = 1 to 40
        // Fan out in a hemisphere away from player
        spread = (i % 11 - 5) * 0.2
        upSpread = (i % 7) * 0.15
        speed = 1.8 + (i % 5) * 0.4

        vx = (awayX + spread * awayZ) * speed
        vz = (awayZ - spread * awayX) * speed
        vy = 1.5 + upSpread * speed

        // Constant colors matching environment: white, purple, cyan
        colorType = i % 3
        if colorType = 0
            // White
            pr = 240   pg = 240   pb = 250
        but colorType = 1
            // Purple
            pr = 130   pg = 70    pb = 210
        else
            // Cyan
            pr = 80    pg = 200   pb = 235
        ok

        life = 0.4 + (i % 5) * 0.04
        add(fireworkParticles, [x, y + 0.3, z, vx, vy, vz, life, pr, pg, pb])
    next

func ld_updateFireworks dt
    i = 1
    fwCount = len(fireworkParticles)
    while i <= fwCount
        p = fireworkParticles[i]
        // Move
        p[1] += p[4] * dt
        p[2] += p[5] * dt
        p[3] += p[6] * dt
        // Gravity
        p[5] -= 3.5 * dt
        // Drag
        p[4] *= (1.0 - 1.2 * dt)
        p[6] *= (1.0 - 1.2 * dt)
        // Age
        p[7] -= dt
        fireworkParticles[i] = p
        if p[7] <= 0
            del(fireworkParticles, i)
            fwCount -= 1
        else
            i += 1
        ok
    end

func ld_drawFireworks
    nFW = len(fireworkParticles)
    for i = 1 to nFW
        p = fireworkParticles[i]
        alpha = floor(p[7] * 255)
        if alpha > 255 alpha = 255 ok
        if alpha < 0 alpha = 0 ok
        sz = 0.03 + p[7] * 0.03
        pos = Vector3(p[1], p[2], p[3])
        DrawSphere(pos, sz, RAYLIBColor(p[8], p[9], p[10], alpha))
        // Bright core for sparkle
        if p[7] > 0.5
            DrawSphere(pos, sz * 0.4, RAYLIBColor(255, 255, 255, floor(alpha * 0.6)))
        ok
    next
