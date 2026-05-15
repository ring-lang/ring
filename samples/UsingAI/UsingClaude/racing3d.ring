/*
**  3D Racing Game - Using RingRayLib
**  ====================================
**  Race around a track against 3 AI opponents!
**
**  Controls:
**    W / Up          -  Accelerate
**    S / Down        -  Brake / Reverse
**    A/D Left/Right  -  Steer
**    SPACE           -  Handbrake
**    C               -  Cycle camera
**    R               -  Restart race
**    P               -  Pause
**    ENTER/SPACE     -  Start / Next race
**    ESC             -  Exit
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W = 1024
SCREEN_H = 768

MAX_SPEED    = 32.0
ACCEL_FORCE  = 14.0
BRAKE_FORCE  = 22.0
DRAG_COEFF   = 0.985
STEER_RATE   = 2.2
HANDBRAKE_DR = 0.92
REVERSE_MAX  = 8.0

TRACK_W      = 14.0
WALL_H       = 1.2
CAR_RAD      = 1.4
WALL_COL_RAD = 1.0

TOTAL_LAPS  = 3
NUM_AI      = 3

GS_TITLE    = 1
GS_COUNT    = 2
GS_PLAY     = 3
GS_PAUSE    = 4
GS_FINISH   = 5

// =============================================================
// Track Waypoints
// =============================================================

wpX = []
wpZ = []
wpLen = 0

// =============================================================
// Globals
// =============================================================

gameState   = GS_TITLE
animTime    = 0.0
dt          = 0.0

plX = 0.0   plZ = 0.0   plAng = 0.0   plSpd = 0.0
plLap = 0   plWP = 1
plLapTime = 0.0   plBestLap = 999.0   plTotalTime = 0.0
plFinished = false
plFinishTime = 0.0
plDrift = 0.0

// AI: [x, z, ang, spd, lap, wpIdx, skill, cR, cG, cB, totalTime, finished, finishTime]
aiCars = []

countDown = 3.0
camAngle = 1
plPosition = 1

// Particles: [x, y, z, vx, vy, vz, life, r, g, b]
parts = []
camera = 0
sceneryTrees = []

// Smooth camera
camX = 0.0    camZ = 0.0    camTX = 0.0   camTZ = 0.0

// =============================================================
// Main
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "3D Racing - RingRayLib")
SetTargetFPS(60)

camera = Camera3D(
    0, 10, 10,
    0, 0, 0,
    0, 1, 0,
    55.0,
    CAMERA_PERSPECTIVE
)

rc_buildTrack()
rc_buildScenery()

while !WindowShouldClose()
    dt = GetFrameTime()
    if dt > 0.033 dt = 0.033 ok
    animTime += dt

    if gameState = GS_TITLE
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            rc_newRace()
            gameState = GS_COUNT
        ok
    but gameState = GS_COUNT
        countDown -= dt
        if countDown <= 0
            gameState = GS_PLAY
        ok
    but gameState = GS_PLAY
        if IsKeyPressed(KEY_P) gameState = GS_PAUSE ok
        if IsKeyPressed(KEY_R)
            rc_newRace()
            gameState = GS_COUNT
        ok
        if IsKeyPressed(KEY_C)
            camAngle += 1
            if camAngle > 3 camAngle = 1 ok
        ok
        rc_updatePlayer()
        rc_updateAI()
        rc_collideCarCar()
        rc_updateParts()
        rc_updatePositions()
    but gameState = GS_PAUSE
        if IsKeyPressed(KEY_P) or IsKeyPressed(KEY_SPACE)
            gameState = GS_PLAY
        ok
    but gameState = GS_FINISH
        rc_updateParts()
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            rc_newRace()
            gameState = GS_COUNT
        ok
    ok

    rc_updateCamera()

    BeginDrawing()
        ClearBackground(RAYLIBColor(25, 45, 25, 255))
        BeginMode3D(camera)
            rc_drawGround()
            rc_drawTrack()
            rc_drawScenery()
            rc_drawCars()
            rc_drawParts3D()
        EndMode3D()

        rc_drawHUD()
        rc_drawMinimap()

        if gameState = GS_TITLE rc_drawTitle() ok
        if gameState = GS_COUNT rc_drawCountdown() ok
        if gameState = GS_PAUSE rc_drawPauseScreen() ok
        if gameState = GS_FINISH rc_drawFinish() ok

        DrawFPS(SCREEN_W - 90, SCREEN_H - 25)
    EndDrawing()
end

CloseWindow()

// =============================================================
// sqrt helper
// =============================================================

func rc_sqrt val
    if val <= 0 return 0.01 ok
    g = val / 2.0
    if g < 0.5 g = 0.5 ok
    g = (g + val / g) / 2.0
    g = (g + val / g) / 2.0
    g = (g + val / g) / 2.0
    g = (g + val / g) / 2.0
    return g

// =============================================================
// Build Track - large oval with smooth curves
// =============================================================

func rc_buildTrack
    wpX = []
    wpZ = []

    straightLen = 300.0
    curveRadius = 100.0
    segsPerStraight = 20
    segsPerCurve = 40

    // Straight 1 (left side, going +Z)
    for i = 0 to segsPerStraight - 1
        frac = i * 1.0 / segsPerStraight
        add(wpX, -curveRadius)
        add(wpZ, -straightLen / 2.0 + frac * straightLen)
    next
    // Curve 1 (top semicircle, left to right) - 40 segments for smoothness
    for i = 0 to segsPerCurve - 1
        ang = 3.14159 + (i * 1.0 / segsPerCurve) * 3.14159
        add(wpX, cos(ang) * curveRadius)
        add(wpZ, straightLen / 2.0 + sin(ang) * curveRadius)
    next
    // Straight 2 (right side, going -Z)
    for i = 0 to segsPerStraight - 1
        frac = i * 1.0 / segsPerStraight
        add(wpX, curveRadius)
        add(wpZ, straightLen / 2.0 - frac * straightLen)
    next
    // Curve 2 (bottom semicircle, right to left) - 40 segments
    for i = 0 to segsPerCurve - 1
        ang = (i * 1.0 / segsPerCurve) * 3.14159
        add(wpX, cos(ang) * curveRadius)
        add(wpZ, -straightLen / 2.0 + sin(ang) * curveRadius)
    next
    wpLen = len(wpX)

// =============================================================
// Build Scenery
// =============================================================

func rc_buildScenery
    sceneryTrees = []
    for i = 1 to 200
        angle = GetRandomValue(0, 628) / 100.0
        dist = 130.0 + GetRandomValue(0, 1500) / 10.0
        tx = cos(angle) * dist
        tz = sin(angle) * dist
        th = 3.0 + GetRandomValue(0, 50) / 10.0
        add(sceneryTrees, [tx, tz, th])
    next

// =============================================================
// New Race
// =============================================================

func rc_newRace
    dx = wpX[2] - wpX[1]
    dz = wpZ[2] - wpZ[1]
    startAng = atan2(dx, dz)

    plX = wpX[1]
    plZ = wpZ[1]
    plAng = startAng
    plSpd = 0.0
    plLap = 0
    plWP = 1
    plLapTime = 0.0
    plBestLap = 999.0
    plTotalTime = 0.0
    plFinished = false
    plFinishTime = 0.0
    plDrift = 0.0
    countDown = 3.5
    parts = []

    // Init smooth camera
    camX = plX - sin(plAng) * 10
    camZ = plZ - cos(plAng) * 10
    camTX = plX + sin(plAng) * 8
    camTZ = plZ + cos(plAng) * 8

    aiCars = []
    aiColors = [
        [220, 50, 50],
        [50, 200, 50],
        [220, 180, 40]
    ]
    perpX = cos(startAng)
    perpZ = -sin(startAng)
    for i = 1 to NUM_AI
        behindOff = i * 5.0
        sideOff = (i - 2) * 3.5
        bx = -sin(startAng) * behindOff
        bz = -cos(startAng) * behindOff
        ax = wpX[1] + bx + perpX * sideOff
        az = wpZ[1] + bz + perpZ * sideOff
        skill = 0.82 + i * 0.05
        cr = aiColors[i][1]
        cg = aiColors[i][2]
        cb = aiColors[i][3]
        add(aiCars, [ax, az, startAng, 0.0, 0, 1, skill, cr, cg, cb, 0.0, false, 0.0])
    next

// =============================================================
// Player Update
// =============================================================

func rc_updatePlayer
    if plFinished
        plSpd = plSpd * 0.95
        plX += sin(plAng) * plSpd * dt
        plZ += cos(plAng) * plSpd * dt
        return
    ok

    plTotalTime += dt
    plLapTime += dt

    // Steering
    steer = 0.0
    if IsKeyDown(KEY_A) steer = 1.0 ok
    if IsKeyDown(KEY_D) steer = -1.0 ok
    if IsKeyDown(KEY_LEFT) steer = 1.0 ok
    if IsKeyDown(KEY_RIGHT) steer = -1.0 ok

    absSpd = plSpd
    if absSpd < 0 absSpd = -absSpd ok

    // Speed-dependent steering
    spdRatio = absSpd / MAX_SPEED
    if spdRatio > 1.0 spdRatio = 1.0 ok
    steerMul = 1.0 - spdRatio * 0.55
    if steerMul < 0.35 steerMul = 0.35 ok

    if absSpd > 0.5
        plAng += steer * STEER_RATE * steerMul * dt
    ok

    // Drift
    if steer != 0 and absSpd > 12.0
        plDrift += dt
    else
        plDrift = plDrift * 0.9
    ok

    // Accel
    if IsKeyDown(KEY_UP) or IsKeyDown(KEY_W)
        plSpd += ACCEL_FORCE * dt
    ok
    // Brake
    if IsKeyDown(KEY_DOWN) or IsKeyDown(KEY_S)
        if plSpd > 0.5
            plSpd -= BRAKE_FORCE * dt
        else
            plSpd -= ACCEL_FORCE * 0.4 * dt
        ok
    ok

    // Handbrake
    if IsKeyDown(KEY_SPACE)
        plSpd = plSpd * HANDBRAKE_DR
        if absSpd > 5
            for k = 1 to 2
                pvx = GetRandomValue(-80, 80) / 100.0
                pvy = GetRandomValue(10, 60) / 100.0
                pvz = GetRandomValue(-80, 80) / 100.0
                add(parts, [plX, 0.1, plZ, pvx, pvy, pvz, 0.5, 180, 180, 180])
            next
        ok
    ok

    plSpd = plSpd * DRAG_COEFF
    if plSpd > MAX_SPEED plSpd = MAX_SPEED ok
    if plSpd < -REVERSE_MAX plSpd = -REVERSE_MAX ok

    // Move
    plX += sin(plAng) * plSpd * dt
    plZ += cos(plAng) * plSpd * dt

    // Track wall constraint
    rc_constrainPlayer()

    // Waypoint advance
    rc_advanceWP_player()

// =============================================================
// Constrain player to track walls
// =============================================================

func rc_constrainPlayer
    // Only search segments near player's current waypoint
    // This prevents snapping to wrong segment at curves
    bestDist = 999999.0
    bestSeg = plWP
    searchRange = 6
    for offset = -searchRange to searchRange
        s = plWP + offset
        // Wrap around
        while s < 1
            s += wpLen
        end
        while s > wpLen
            s -= wpLen
        end
        sN = s + 1
        if sN > wpLen sN = 1 ok
        mx = (wpX[s] + wpX[sN]) / 2.0
        mz = (wpZ[s] + wpZ[sN]) / 2.0
        ddx = plX - mx
        ddz = plZ - mz
        d2 = ddx * ddx + ddz * ddz
        if d2 < bestDist
            bestDist = d2
            bestSeg = s
        ok
    next

    sN = bestSeg + 1
    if sN > wpLen sN = 1 ok
    sx = wpX[bestSeg]   sz = wpZ[bestSeg]
    ex = wpX[sN]        ez = wpZ[sN]
    segDx = ex - sx      segDz = ez - sz
    segLen2 = segDx * segDx + segDz * segDz
    if segLen2 < 0.01 return ok

    t = ((plX - sx) * segDx + (plZ - sz) * segDz) / segLen2
    if t < 0 t = 0 ok
    if t > 1 t = 1 ok
    projX = sx + segDx * t
    projZ = sz + segDz * t

    offX = plX - projX
    offZ = plZ - projZ
    offD2 = offX * offX + offZ * offZ
    halfW = TRACK_W / 2.0 - WALL_COL_RAD

    if offD2 > halfW * halfW
        od = rc_sqrt(offD2)
        if od > 0.01
            nx = offX / od
            nz = offZ / od
            plX = projX + nx * halfW
            plZ = projZ + nz * halfW

            // Car forward direction
            vfx = sin(plAng)
            vfz = cos(plAng)
            // How much velocity goes INTO the wall
            dotN = vfx * nx + vfz * nz

            if dotN > 0.1
                // Deflect: remove wall-normal component from angle
                // New direction = forward minus normal component
                newFx = vfx - nx * dotN
                newFz = vfz - nz * dotN
                // Only redirect if result is meaningful
                newLen2 = newFx * newFx + newFz * newFz
                if newLen2 > 0.01
                    plAng = atan2(newFx, newFz)
                ok
                // Speed penalty proportional to impact angle
                // Head-on (dotN~1) loses more, glancing (dotN~0.1) loses less
                keepFrac = 1.0 - dotN * 0.5
                if keepFrac < 0.5 keepFrac = 0.5 ok
                plSpd = plSpd * keepFrac
            ok

            // Sparks only on meaningful contact
            absSpd2 = plSpd
            if absSpd2 < 0 absSpd2 = -absSpd2 ok
            if absSpd2 > 3
                for k = 1 to 2
                    pvx = nx * 2 + GetRandomValue(-100, 100) / 100.0
                    pvy = GetRandomValue(50, 200) / 100.0
                    pvz = nz * 2 + GetRandomValue(-100, 100) / 100.0
                    add(parts, [plX, 0.3, plZ, pvx, pvy, pvz, 0.4, 255, 200, 50])
                next
            ok
        ok
    ok

// =============================================================
// Waypoint advance (player)
// =============================================================

func rc_advanceWP_player
    nxt = plWP + 1
    if nxt > wpLen nxt = 1 ok
    dx = wpX[nxt] - plX
    dz = wpZ[nxt] - plZ
    d2 = dx * dx + dz * dz
    if d2 < 225
        plWP = nxt
        if plWP = 1
            plLap += 1
            if plLapTime < plBestLap and plLap > 1
                plBestLap = plLapTime
            ok
            plLapTime = 0.0
            if plLap > TOTAL_LAPS
                plFinished = true
                plFinishTime = plTotalTime
                rc_checkRaceEnd()
            ok
        ok
    ok

// =============================================================
// AI Update
// =============================================================

func rc_updateAI
    nAI = len(aiCars)
    for i = 1 to nAI
        a = aiCars[i]
        if a[12]
            a[4] = a[4] * 0.95
            a[1] += sin(a[3]) * a[4] * dt
            a[2] += cos(a[3]) * a[4] * dt
            aiCars[i] = a
            loop
        ok

        a[11] += dt

        // Target NEXT waypoint directly (no lookahead blend)
        tWP = a[6]
        tN1 = tWP + 1
        if tN1 > wpLen tN1 = 1 ok
        tx = wpX[tN1]
        tz = wpZ[tN1]

        dx = tx - a[1]
        dz = tz - a[2]
        targetAng = atan2(dx, dz)

        diff = targetAng - a[3]
        while diff > 3.14159
            diff -= 6.28318
        end
        while diff < -3.14159
            diff += 6.28318
        end

        // Strong steering multiplier
        steerStr = diff * 3.5
        maxSt = 3.0
        if steerStr > maxSt steerStr = maxSt ok
        if steerStr < -maxSt steerStr = -maxSt ok

        absSpd = a[4]
        if absSpd < 0 absSpd = -absSpd ok

        // Apply steering with less speed reduction
        if absSpd > 0.3
            spdR = absSpd / MAX_SPEED
            sMul = 1.0 - spdR * 0.35
            if sMul < 0.45 sMul = 0.45 ok
            a[3] += steerStr * sMul * dt
        ok

        // Speed - slow down hard at curves
        targetSpd = MAX_SPEED * a[7]
        absDiff = diff
        if absDiff < 0 absDiff = -absDiff ok
        if absDiff > 0.15
            curveFac = 1.0 - absDiff / 2.0
            if curveFac < 0.3 curveFac = 0.3 ok
            targetSpd = targetSpd * curveFac
        ok
        if a[4] < targetSpd
            a[4] += ACCEL_FORCE * a[7] * dt
        else
            a[4] -= BRAKE_FORCE * 0.5 * dt
        ok
        a[4] = a[4] * DRAG_COEFF
        if a[4] > MAX_SPEED a[4] = MAX_SPEED ok
        if a[4] < 0 a[4] = 0 ok

        // Move
        a[1] += sin(a[3]) * a[4] * dt
        a[2] += cos(a[3]) * a[4] * dt

        aiCars[i] = a

        // Constrain to track
        rc_constrainAI(i)
        a = aiCars[i]

        // Waypoint advance - SMALL radius to not skip curve waypoints
        ddx = wpX[tN1] - a[1]
        ddz = wpZ[tN1] - a[2]
        dd2 = ddx * ddx + ddz * ddz
        if dd2 < 80
            a[6] = tN1
            if a[6] = 1
                a[5] += 1
                if a[5] > TOTAL_LAPS
                    a[12] = true
                    a[13] = a[11]
                ok
            ok
        ok

        aiCars[i] = a
    next

// =============================================================
// Constrain AI to track walls
// =============================================================

func rc_constrainAI idx
    a = aiCars[idx]
    ax = a[1]
    az = a[2]
    aiWP = a[6]

    // Only search segments near AI's current waypoint
    bestDist = 999999.0
    bestSeg = aiWP
    searchRange = 6
    for offset = -searchRange to searchRange
        s = aiWP + offset
        while s < 1
            s += wpLen
        end
        while s > wpLen
            s -= wpLen
        end
        sN = s + 1
        if sN > wpLen sN = 1 ok
        mx = (wpX[s] + wpX[sN]) / 2.0
        mz = (wpZ[s] + wpZ[sN]) / 2.0
        ddx = ax - mx
        ddz = az - mz
        d2 = ddx * ddx + ddz * ddz
        if d2 < bestDist
            bestDist = d2
            bestSeg = s
        ok
    next

    sN = bestSeg + 1
    if sN > wpLen sN = 1 ok
    sx = wpX[bestSeg]   sz = wpZ[bestSeg]
    exx = wpX[sN]       ezz = wpZ[sN]
    segDx = exx - sx     segDz = ezz - sz
    segLen2 = segDx * segDx + segDz * segDz
    if segLen2 < 0.01
        aiCars[idx] = a
        return
    ok
    t = ((ax - sx) * segDx + (az - sz) * segDz) / segLen2
    if t < 0 t = 0 ok
    if t > 1 t = 1 ok
    projX = sx + segDx * t
    projZ = sz + segDz * t
    offX = ax - projX
    offZ = az - projZ
    offD2 = offX * offX + offZ * offZ
    halfW = TRACK_W / 2.0 - WALL_COL_RAD - 0.5
    if offD2 > halfW * halfW
        od = rc_sqrt(offD2)
        if od > 0.01
            nx = offX / od
            nz = offZ / od
            a[1] = projX + nx * halfW * 0.95
            a[2] = projZ + nz * halfW * 0.95

            // Deflect AI angle along wall
            vfx = sin(a[3])
            vfz = cos(a[3])
            dotN = vfx * nx + vfz * nz
            if dotN > 0.1
                newFx = vfx - nx * dotN
                newFz = vfz - nz * dotN
                newLen2 = newFx * newFx + newFz * newFz
                if newLen2 > 0.01
                    a[3] = atan2(newFx, newFz)
                ok
                keepFrac = 1.0 - dotN * 0.4
                if keepFrac < 0.55 keepFrac = 0.55 ok
                a[4] = a[4] * keepFrac
            ok
        ok
    ok
    aiCars[idx] = a

// =============================================================
// Car-Car Collision
// =============================================================

func rc_collideCarCar
    // Build array of all cars: [x, z, spd, ang, isPlayer, idx]
    allX = [plX]
    allZ = [plZ]
    allS = [plSpd]
    allA = [plAng]
    nAI = len(aiCars)
    for i = 1 to nAI
        add(allX, aiCars[i][1])
        add(allZ, aiCars[i][2])
        add(allS, aiCars[i][4])
        add(allA, aiCars[i][3])
    next

    total = 1 + nAI
    for i = 1 to total
        j = i + 1
        while j <= total
            ddx = allX[i] - allX[j]
            ddz = allZ[i] - allZ[j]
            d2 = ddx * ddx + ddz * ddz
            minD = CAR_RAD * 2
            if d2 < minD * minD and d2 > 0.01
                dist = rc_sqrt(d2)
                // Overlap - push apart
                nx = ddx / dist
                nz = ddz / dist
                overlap = minD - dist
                pushX = nx * overlap * 0.5
                pushZ = nz * overlap * 0.5

                // Push car i away
                if i = 1
                    plX += pushX
                    plZ += pushZ
                    plSpd = plSpd * 0.85
                else
                    ai = i - 1
                    aiCars[ai][1] += pushX
                    aiCars[ai][2] += pushZ
                    aiCars[ai][4] = aiCars[ai][4] * 0.85
                ok

                // Push car j away
                if j = 1
                    plX -= pushX
                    plZ -= pushZ
                    plSpd = plSpd * 0.85
                else
                    aj = j - 1
                    aiCars[aj][1] -= pushX
                    aiCars[aj][2] -= pushZ
                    aiCars[aj][4] = aiCars[aj][4] * 0.85
                ok

                // Collision sparks
                mx = (allX[i] + allX[j]) / 2.0
                mz = (allZ[i] + allZ[j]) / 2.0
                for k = 1 to 4
                    pvx = GetRandomValue(-200, 200) / 100.0
                    pvy = GetRandomValue(50, 250) / 100.0
                    pvz = GetRandomValue(-200, 200) / 100.0
                    add(parts, [mx, 0.4, mz, pvx, pvy, pvz, 0.3, 255, 150, 30])
                next
            ok
            j += 1
        end
    next

    // Update allX/allZ back to aiCars
    for i = 1 to nAI
        allX[i + 1] = aiCars[i][1]
        allZ[i + 1] = aiCars[i][2]
    next

// =============================================================
// Check Race End
// =============================================================

func rc_checkRaceEnd
    if plFinished
        gameState = GS_FINISH
        for k = 1 to 30
            pvx = GetRandomValue(-300, 300) / 100.0
            pvy = GetRandomValue(100, 500) / 100.0
            pvz = GetRandomValue(-300, 300) / 100.0
            pr = GetRandomValue(150, 255)
            pg = GetRandomValue(150, 255)
            pb = GetRandomValue(50, 150)
            add(parts, [plX, 1.0, plZ, pvx, pvy, pvz, 1.5, pr, pg, pb])
        next
    ok

// =============================================================
// Position Tracking
// =============================================================

func rc_updatePositions
    plProg = plLap * wpLen + plWP
    plPosition = 1
    nAI = len(aiCars)
    for i = 1 to nAI
        aiProg = aiCars[i][5] * wpLen + aiCars[i][6]
        if aiProg > plProg
            plPosition += 1
        ok
    next

// =============================================================
// Particles
// =============================================================

func rc_updateParts
    i = 1
    nP = len(parts)
    while i <= nP
        p = parts[i]
        p[1] += p[4] * dt
        p[2] += p[5] * dt
        p[3] += p[6] * dt
        p[5] -= 5.0 * dt
        p[7] -= dt
        if p[7] <= 0
            del(parts, i)
            nP -= 1
        else
            parts[i] = p
            i += 1
        ok
    end

// =============================================================
// Camera - smooth follow behind car
// =============================================================

func rc_updateCamera
    behindDist = 10.0
    upDist = 5.0
    if camAngle = 2
        behindDist = 16.0
        upDist = 12.0
    ok
    if camAngle = 3
        behindDist = 1.5
        upDist = 1.8
    ok

    // Target camera position (behind car)
    tgtCX = plX - sin(plAng) * behindDist
    tgtCZ = plZ - cos(plAng) * behindDist
    tgtTX = plX + sin(plAng) * 8.0
    tgtTZ = plZ + cos(plAng) * 8.0

    // Smooth interpolation
    smoothF = 6.0 * dt
    if smoothF > 1.0 smoothF = 1.0 ok
    camX += (tgtCX - camX) * smoothF
    camZ += (tgtCZ - camZ) * smoothF
    camTX += (tgtTX - camTX) * smoothF
    camTZ += (tgtTZ - camTZ) * smoothF

    camera.position.x = camX
    camera.position.y = upDist
    camera.position.z = camZ
    camera.target.x = camTX
    camera.target.y = 0.5
    camera.target.z = camTZ

// =============================================================
// Draw Ground
// =============================================================

func rc_drawGround
    DrawPlane(Vector3(0, -0.05, 0), Vector2(600, 600),
        RAYLIBColor(40, 65, 35, 255))

// =============================================================
// Draw Track
// =============================================================

func rc_drawTrack
    for s = 1 to wpLen
        sN = s + 1
        if sN > wpLen sN = 1 ok

        ax = wpX[s]    az = wpZ[s]
        bx = wpX[sN]   bz = wpZ[sN]

        sdx = bx - ax   sdz = bz - az
        sLen2 = sdx * sdx + sdz * sdz
        if sLen2 < 0.01 loop ok

        // Distance cull
        cx = (ax + bx) / 2.0
        cz = (az + bz) / 2.0
        ddx = cx - plX
        ddz = cz - plZ
        dd = ddx * ddx + ddz * ddz
        if dd > 50000 loop ok

        sLen = rc_sqrt(sLen2)
        nx = -sdz / sLen
        nz = sdx / sLen
        halfW = TRACK_W / 2.0

        // Road surface
        DrawCube(Vector3(cx, -0.01, cz), TRACK_W, 0.02, sLen + 0.5,
            RAYLIBColor(55, 55, 65, 255))

        // Left wall (red)
        lwx = (ax + bx) / 2.0 + nx * halfW
        lwz = (az + bz) / 2.0 + nz * halfW
        DrawCube(Vector3(lwx, WALL_H / 2, lwz), 0.6, WALL_H, sLen + 0.3,
            RAYLIBColor(180, 40, 40, 255))

        // Right wall (blue)
        rwx = (ax + bx) / 2.0 - nx * halfW
        rwz = (az + bz) / 2.0 - nz * halfW
        DrawCube(Vector3(rwx, WALL_H / 2, rwz), 0.6, WALL_H, sLen + 0.3,
            RAYLIBColor(40, 40, 180, 255))

        // Center dash every 4 segments
        rem = s
        while rem > 4
            rem -= 4
        end
        if rem = 0
            DrawCube(Vector3(cx, 0.02, cz), 0.15, 0.04, sLen * 0.4,
                RAYLIBColor(255, 255, 255, 100))
        ok
    next

    // Start/finish line
    sfx = wpX[1]
    sfz = wpZ[1]
    DrawCube(Vector3(sfx, 0.03, sfz), TRACK_W, 0.06, 2.5,
        RAYLIBColor(255, 255, 255, 200))
    for cb = -3 to 3
        rem2 = cb
        if rem2 < 0 rem2 = -rem2 ok
        rem3 = rem2
        while rem3 > 1
            rem3 -= 2
        end
        clr = 30
        if rem3 = 0 clr = 230 ok
        DrawCube(Vector3(sfx + cb * 1.8, 0.04, sfz), 1.5, 0.06, 2.0,
            RAYLIBColor(clr, clr, clr, 200))
    next

// =============================================================
// Draw Scenery
// =============================================================

func rc_drawScenery
    nT = len(sceneryTrees)
    for i = 1 to nT
        t = sceneryTrees[i]
        tx = t[1]   tz = t[2]   th = t[3]
        ddx = tx - plX
        ddz = tz - plZ
        dd = ddx * ddx + ddz * ddz
        if dd > 50000 loop ok
        DrawCylinder(Vector3(tx, 0, tz), 0.3, 0.3, th * 0.4, 5,
            RAYLIBColor(100, 70, 40, 255))
        DrawSphereEx(Vector3(tx, th * 0.6, tz), th * 0.4, 5, 5,
            RAYLIBColor(30, 120, 30, 255))
    next

// =============================================================
// Draw Cars - built from direction-offset cubes (rotates with angle)
// =============================================================

func rc_drawCars
    if gameState != GS_TITLE
        rc_drawOneCar(plX, plZ, plAng, 60, 120, 240, true)
    ok
    nAI = len(aiCars)
    for i = 1 to nAI
        a = aiCars[i]
        rc_drawOneCar(a[1], a[2], a[3], a[8], a[9], a[10], false)
    next

func rc_drawOneCar cx, cz, cAng, cr, cg, cb, isPlayer
    // Forward and right direction vectors
    fX = sin(cAng)
    fZ = cos(cAng)
    rX = fZ
    rZ = -fX

    // === BODY: 5 slices along car length to show rotation ===
    // Each slice is a small cube offset along forward direction
    dkR = floor(cr * 0.7)   dkG = floor(cg * 0.7)   dkB = floor(cb * 0.7)

    for sl = -2 to 2
        off = sl * 0.45
        px = cx + fX * off
        pz = cz + fZ * off
        // Width varies: narrower at front/back
        w = 1.3
        if sl = -2 or sl = 2 w = 0.9 ok
        if sl = -1 or sl = 1 w = 1.2 ok
        DrawCube(Vector3(px, 0.32, pz), w, 0.38, 0.5,
            RAYLIBColor(cr, cg, cb, 255))
    next

    // Body outline (wireframe on center slice)
    DrawCubeWires(Vector3(cx, 0.32, cz), 1.3, 0.38, 0.5,
        RAYLIBColor(dkR, dkG, dkB, 130))

    // === ROOF: 3 slices offset slightly back ===
    for sl = -1 to 1
        off = sl * 0.32 - 0.1
        px = cx + fX * off
        pz = cz + fZ * off
        w = 0.9
        if sl = -1 or sl = 1 w = 0.7 ok
        DrawCube(Vector3(px, 0.58, pz), w, 0.2, 0.36,
            RAYLIBColor(floor(cr * 0.8), floor(cg * 0.8), floor(cb * 0.8), 255))
    next

    // === WINDSHIELD ===
    wx = cx + fX * 0.5
    wz = cz + fZ * 0.5
    DrawCube(Vector3(wx, 0.53, wz), 0.85, 0.18, 0.08,
        RAYLIBColor(140, 190, 230, 180))

    // === WHEELS (4 corners) ===
    wOff = 0.6
    fOff = 0.75
    // Front-left
    DrawCube(Vector3(cx + rX * wOff + fX * fOff, 0.15, cz + rZ * wOff + fZ * fOff),
        0.2, 0.3, 0.3, RAYLIBColor(25, 25, 25, 255))
    // Front-right
    DrawCube(Vector3(cx - rX * wOff + fX * fOff, 0.15, cz - rZ * wOff + fZ * fOff),
        0.2, 0.3, 0.3, RAYLIBColor(25, 25, 25, 255))
    // Rear-left
    DrawCube(Vector3(cx + rX * wOff - fX * fOff, 0.15, cz + rZ * wOff - fZ * fOff),
        0.2, 0.3, 0.3, RAYLIBColor(25, 25, 25, 255))
    // Rear-right
    DrawCube(Vector3(cx - rX * wOff - fX * fOff, 0.15, cz - rZ * wOff - fZ * fOff),
        0.2, 0.3, 0.3, RAYLIBColor(25, 25, 25, 255))

    // === TAIL LIGHTS ===
    DrawSphereEx(Vector3(cx + rX * 0.45 - fX * 1.0, 0.35, cz + rZ * 0.45 - fZ * 1.0),
        0.1, 4, 4, RAYLIBColor(255, 30, 30, 220))
    DrawSphereEx(Vector3(cx - rX * 0.45 - fX * 1.0, 0.35, cz - rZ * 0.45 - fZ * 1.0),
        0.1, 4, 4, RAYLIBColor(255, 30, 30, 220))

    // === HEADLIGHTS ===
    DrawSphereEx(Vector3(cx + rX * 0.4 + fX * 1.0, 0.3, cz + rZ * 0.4 + fZ * 1.0),
        0.1, 4, 4, RAYLIBColor(255, 255, 200, 220))
    DrawSphereEx(Vector3(cx - rX * 0.4 + fX * 1.0, 0.3, cz - rZ * 0.4 + fZ * 1.0),
        0.1, 4, 4, RAYLIBColor(255, 255, 200, 220))

    // Player marker above car
    if isPlayer
        pulse = 0.8 + sin(animTime * 4) * 0.3
        DrawSphereEx(Vector3(cx, 2.0, cz), 0.2, 4, 4,
            RAYLIBColor(80, 200, 255, floor(pulse * 200)))
        DrawCylinder(Vector3(cx, 1.1, cz), 0.02, 0.02, 0.8, 4,
            RAYLIBColor(80, 200, 255, 100))
    ok

// =============================================================
// Draw Particles (3D)
// =============================================================

func rc_drawParts3D
    nP = len(parts)
    for i = 1 to nP
        p = parts[i]
        alpha = floor(p[7] / 1.5 * 255)
        if alpha > 255 alpha = 255 ok
        if alpha < 0 alpha = 0 ok
        sz = 0.06 + p[7] * 0.07
        DrawSphereEx(Vector3(p[1], p[2], p[3]), sz, 3, 3,
            RAYLIBColor(p[8], p[9], p[10], alpha))
    next

// =============================================================
// HUD
// =============================================================

func rc_drawHUD
    if gameState = GS_TITLE return ok

    DrawRectangle(0, 0, SCREEN_W, 55, RAYLIBColor(0, 0, 0, 160))

    posStr = ""
    if plPosition = 1 posStr = "1st"
    but plPosition = 2 posStr = "2nd"
    but plPosition = 3 posStr = "3rd"
    but plPosition = 4 posStr = "4th"
    ok
    DrawText(posStr, 20, 5, 36, RAYLIBColor(255, 220, 50, 255))

    dispLap = plLap
    if dispLap > TOTAL_LAPS dispLap = TOTAL_LAPS ok
    if dispLap < 1 dispLap = 1 ok
    DrawText("Lap " + dispLap + "/" + TOTAL_LAPS, 120, 12, 22,
        RAYLIBColor(200, 220, 255, 230))

    lt = floor(plLapTime * 10) / 10.0
    DrawText("Lap: " + lt + "s", 280, 12, 18,
        RAYLIBColor(200, 210, 220, 220))

    if plBestLap < 900
        bt = floor(plBestLap * 10) / 10.0
        DrawText("Best: " + bt + "s", 410, 12, 18,
            RAYLIBColor(100, 255, 100, 220))
    ok

    tt = floor(plTotalTime * 10) / 10.0
    DrawText("Time: " + tt + "s", 550, 12, 18,
        RAYLIBColor(200, 200, 220, 200))

    kmh = floor(plSpd * 3.6)
    if kmh < 0 kmh = -kmh ok
    DrawText("" + kmh + " km/h", SCREEN_W - 170, 8, 30,
        RAYLIBColor(255, 255, 255, 240))

    DrawText("[C] Cam", SCREEN_W - 75, 40, 12, RAYLIBColor(150, 160, 170, 180))

    // Speed bar
    barX = 15
    barY = SCREEN_H - 50
    barW = 200
    barH = 16
    DrawRectangle(barX, barY, barW, barH, RAYLIBColor(40, 40, 50, 180))
    spdPct = plSpd / MAX_SPEED
    if spdPct < 0 spdPct = 0 ok
    if spdPct > 1 spdPct = 1 ok
    fillW = floor(barW * spdPct)
    sr = floor(50 + spdPct * 200)
    if sr > 255 sr = 255 ok
    sg = floor(200 - spdPct * 180)
    if sg < 0 sg = 0 ok
    DrawRectangle(barX, barY, fillW, barH,
        RAYLIBColor(sr, sg, 60, 220))
    DrawText("SPEED", barX, barY - 16, 13, RAYLIBColor(180, 190, 200, 180))

    DrawRectangle(0, SCREEN_H - 26, SCREEN_W, 26, RAYLIBColor(0, 0, 0, 100))
    DrawText("W/S=Accel/Brake  A/D=Steer  Arrows=Same  SPACE=Handbrake  C=Camera  P=Pause  R=Restart",
        10, SCREEN_H - 21, 12, RAYLIBColor(140, 150, 160, 170))

    if plFinished
        DrawText("FINISHED!", 15, 62, 22, RAYLIBColor(255, 215, 0, 255))
    ok

// =============================================================
// Minimap
// =============================================================

func rc_drawMinimap
    if gameState = GS_TITLE return ok

    mmX = SCREEN_W - 175
    mmY = SCREEN_H - 195
    mmW = 165
    mmH = 165

    DrawRectangle(mmX, mmY, mmW, mmH, RAYLIBColor(0, 0, 0, 160))
    DrawRectangleLines(mmX, mmY, mmW, mmH, RAYLIBColor(100, 100, 120, 200))

    scaleV = mmW / 450.0
    offMX = mmX + mmW / 2
    offMZ = mmY + mmH / 2

    for s = 1 to wpLen
        sN = s + 1
        if sN > wpLen sN = 1 ok
        x1 = offMX + wpX[s] * scaleV
        y1 = offMZ - wpZ[s] * scaleV
        x2 = offMX + wpX[sN] * scaleV
        y2 = offMZ - wpZ[sN] * scaleV
        DrawLine(floor(x1), floor(y1), floor(x2), floor(y2),
            RAYLIBColor(100, 100, 120, 200))
    next

    px = offMX + plX * scaleV
    pz = offMZ - plZ * scaleV
    DrawCircle(floor(px), floor(pz), 4, RAYLIBColor(60, 150, 255, 255))

    nAI = len(aiCars)
    for i = 1 to nAI
        a = aiCars[i]
        amx = offMX + a[1] * scaleV
        amz = offMZ - a[2] * scaleV
        DrawCircle(floor(amx), floor(amz), 3,
            RAYLIBColor(a[8], a[9], a[10], 255))
    next

// =============================================================
// Title Screen
// =============================================================

func rc_drawTitle
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 180))

    t1 = "3D RACING"
    t1w = MeasureText(t1, 56)
    pulse = sin(animTime * 3) * 5
    DrawText(t1, (SCREEN_W - t1w) / 2, 150 + floor(pulse), 56,
        RAYLIBColor(255, 220, 60, 255))

    t2 = "Race 3 laps against 3 AI opponents!"
    t2w = MeasureText(t2, 22)
    DrawText(t2, (SCREEN_W - t2w) / 2, 230, 22,
        RAYLIBColor(200, 210, 220, 220))

    ty = 280
    DrawText("W / Up Arrow   -  Accelerate", 320, ty, 17,
        RAYLIBColor(180, 190, 200, 200))
    DrawText("S / Down Arrow -  Brake / Reverse", 320, ty + 26, 17,
        RAYLIBColor(180, 190, 200, 200))
    DrawText("A / D          -  Steer Left / Right", 320, ty + 52, 17,
        RAYLIBColor(180, 190, 200, 200))
    DrawText("Left / Right   -  Steer Left / Right", 320, ty + 78, 17,
        RAYLIBColor(180, 190, 200, 200))
    DrawText("SPACE          -  Handbrake", 320, ty + 104, 17,
        RAYLIBColor(180, 190, 200, 200))
    DrawText("C              -  Cycle camera", 320, ty + 130, 17,
        RAYLIBColor(180, 190, 200, 200))
    DrawText("P              -  Pause", 320, ty + 156, 17,
        RAYLIBColor(180, 190, 200, 200))

    ty2 = 480
    DrawText("Opponents:", 320, ty2, 17,
        RAYLIBColor(200, 210, 220, 220))
    DrawRectangle(320, ty2 + 25, 14, 14, RAYLIBColor(60, 120, 240, 255))
    DrawText("You", 342, ty2 + 25, 16, RAYLIBColor(180, 180, 190, 200))
    DrawRectangle(400, ty2 + 25, 14, 14, RAYLIBColor(220, 50, 50, 255))
    DrawText("Red", 422, ty2 + 25, 16, RAYLIBColor(180, 180, 190, 200))
    DrawRectangle(480, ty2 + 25, 14, 14, RAYLIBColor(50, 200, 50, 255))
    DrawText("Green", 502, ty2 + 25, 16, RAYLIBColor(180, 180, 190, 200))
    DrawRectangle(570, ty2 + 25, 14, 14, RAYLIBColor(220, 180, 40, 255))
    DrawText("Gold", 592, ty2 + 25, 16, RAYLIBColor(180, 180, 190, 200))

    if floor(animTime * 2) % 2 = 0
        t3 = "Press ENTER or SPACE to Start"
        t3w = MeasureText(t3, 24)
        DrawText(t3, (SCREEN_W - t3w) / 2, 560, 24,
            RAYLIBColor(255, 255, 200, 255))
    ok

// =============================================================
// Countdown
// =============================================================

func rc_drawCountdown
    cd = floor(countDown) + 1
    if cd > 3 cd = 3 ok
    cdTxt = "" + cd
    cdCol = RAYLIBColor(255, 255, 80, 255)
    if cd < 1
        cdTxt = "GO!"
        cdCol = RAYLIBColor(50, 255, 50, 255)
    ok
    tw = MeasureText(cdTxt, 80)
    DrawText(cdTxt, (SCREEN_W - tw) / 2, SCREEN_H / 2 - 60, 80, cdCol)

// =============================================================
// Pause
// =============================================================

func rc_drawPauseScreen
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 150))
    t1 = "PAUSED"
    t1w = MeasureText(t1, 48)
    DrawText(t1, (SCREEN_W - t1w) / 2, SCREEN_H / 2 - 40, 48,
        RAYLIBColor(200, 210, 230, 255))
    t2 = "Press P or SPACE to Resume"
    t2w = MeasureText(t2, 20)
    DrawText(t2, (SCREEN_W - t2w) / 2, SCREEN_H / 2 + 20, 20,
        RAYLIBColor(160, 170, 180, 200))

// =============================================================
// Finish Screen
// =============================================================

func rc_drawFinish
    DrawRectangle(SCREEN_W / 6, SCREEN_H / 4, SCREEN_W * 2 / 3, SCREEN_H / 2,
        RAYLIBColor(0, 0, 0, 200))
    DrawRectangleLines(SCREEN_W / 6, SCREEN_H / 4, SCREEN_W * 2 / 3, SCREEN_H / 2,
        RAYLIBColor(255, 215, 0, 200))

    t1 = "RACE COMPLETE!"
    t1w = MeasureText(t1, 42)
    pulse = sin(animTime * 3) * 4
    DrawText(t1, (SCREEN_W - t1w) / 2, SCREEN_H / 4 + 15 + floor(pulse), 42,
        RAYLIBColor(255, 215, 0, 255))

    posStr = ""
    colR = 160   colG = 160   colB = 180
    if plPosition = 1
        posStr = "1st Place!"
        colR = 255   colG = 215   colB = 0
    but plPosition = 2
        posStr = "2nd Place"
        colR = 192   colG = 192   colB = 192
    but plPosition = 3
        posStr = "3rd Place"
        colR = 180   colG = 120   colB = 60
    but plPosition = 4
        posStr = "4th Place"
        colR = 160   colG = 160   colB = 180
    ok
    col = RAYLIBColor(colR, colG, colB, 255)
    pw = MeasureText(posStr, 32)
    DrawText(posStr, (SCREEN_W - pw) / 2, SCREEN_H / 4 + 70, 32, col)

    ft = floor(plFinishTime * 10) / 10.0
    DrawText("Total Time: " + ft + "s", SCREEN_W / 3, SCREEN_H / 4 + 120, 20, WHITE)

    if plBestLap < 900
        bt = floor(plBestLap * 10) / 10.0
        DrawText("Best Lap: " + bt + "s", SCREEN_W / 3, SCREEN_H / 4 + 150, 20,
            RAYLIBColor(100, 255, 100, 230))
    ok

    ry = SCREEN_H / 4 + 190
    DrawText("Results:", SCREEN_W / 3, ry, 18, RAYLIBColor(200, 210, 220, 220))
    ry += 25

    results = []
    pft = plFinishTime
    if !plFinished pft = 9999 ok
    add(results, [pft, "You", 60, 120, 240])
    nAI = len(aiCars)
    for i = 1 to nAI
        a = aiCars[i]
        aft = a[13]
        if !a[12] aft = 9999 ok
        names = ["Red", "Green", "Gold"]
        add(results, [aft, names[i], a[8], a[9], a[10]])
    next

    nRes = len(results)
    for i = 1 to nRes
        for j = 1 to nRes - 1
            if results[j][1] > results[j + 1][1]
                tmp = results[j]
                results[j] = results[j + 1]
                results[j + 1] = tmp
            ok
        next
    next

    for i = 1 to nRes
        r = results[i]
        tStr = ""
        if r[1] < 9000
            tStr = "" + (floor(r[1] * 10) / 10.0) + "s"
        else
            tStr = "DNF"
        ok
        DrawText("" + i + ". " + r[2] + "  " + tStr,
            SCREEN_W / 3, ry, 16,
            RAYLIBColor(r[3], r[4], r[5], 230))
        ry += 22
    next

    if floor(animTime * 2) % 2 = 0
        t3 = "Press ENTER or SPACE for New Race"
        t3w = MeasureText(t3, 20)
        DrawText(t3, (SCREEN_W - t3w) / 2, SCREEN_H / 4 + SCREEN_H / 2 - 35, 20,
            RAYLIBColor(255, 255, 200, 220))
    ok
