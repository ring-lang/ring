/*
**  tank3d_powerups.ring
**  Power-up update and pickup logic
*/

// =============================================================
// Powerup Update
// =============================================================

func tank_updatePowerups dt
    i = 1
    while i <= len(powerups)
        if !powerups[i][5]
            del(powerups, i)
            loop
        ok
        powerups[i][4] -= dt
        if powerups[i][4] <= 0
            powerups[i][5] = false
            del(powerups, i)
            loop
        ok

        // Check player pickup
        if palive
            ddx = px - powerups[i][1]
            ddy = py - powerups[i][2]
            if ddx > -0.8 and ddx < 0.8 and ddy > -0.8 and ddy < 0.8
                ptype = powerups[i][3]
                if ptype = 1
                    // Star - speed boost
                    pspeedBoost = 15.0
                    score += 200
                    PlaySound(sndPowerup)
                ok
                if ptype = 2
                    // Shield
                    pshield = 12.0
                    score += 200
                    PlaySound(sndPowerup)
                ok
                if ptype = 3
                    // Bomb - destroy all enemies
                    nEnemies = len(enemies)
                    for e = 1 to nEnemies
                        if enemies[e][5]
                            enemies[e][5] = false
                            enemiesKilled += 1
                            totalKills += 1
                            score += 100
                            tank_spawnBigExplosion(enemies[e][1], enemies[e][2])
                        ok
                    next
                    score += 200
                    tank_triggerShake(0.5, 0.6)
                    PlaySound(sndBomb)
                ok
                if ptype = 4
                    // Freeze - stop all enemies
                    globalFreezeTimer = 6.0
                    score += 200
                    PlaySound(sndPowerup)
                ok
                if ptype = 5
                    // Extra life
                    lives += 1
                    score += 300
                    PlaySound(sndPowerup)
                ok
                powerups[i][5] = false
                del(powerups, i)
                loop
            ok
        ok
        i += 1
    end
