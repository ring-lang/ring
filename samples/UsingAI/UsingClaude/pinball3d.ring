/*
**  Pinball Game 3D - Using RingRayLib
**  =====================================
**  Classic pinball with 3D graphics!
**  Launch the ball, use flippers to keep it in play,
**  hit bumpers and targets for points!
**
**  Controls:
**    LEFT / Z       -  Left flipper
**    RIGHT / X      -  Right flipper
**    SPACE / DOWN   -  Plunger (hold & release)
**    C              -  Cycle camera view
**    P              -  Pause
**    R              -  New ball (when ball lost)
**    N              -  New game
**    ESC            -  Exit
*/

load "raylib.ring"

# ============================================================
# Constants
# ============================================================

SCREEN_W    = 900
SCREEN_H    = 700
GAME_TITLE  = "Pinball 3D"

# Table dimensions (length along Z, width along X)
TABLE_LEN   = 20.0
TABLE_W     = 11.0
TABLE_HALF_W = TABLE_W / 2.0
TABLE_HALF_L = TABLE_LEN / 2.0
WALL_H      = 1.2
WALL_THICK  = 0.4

# Table tilt angle (degrees) - ball rolls toward -Z (player)
TABLE_TILT  = 6.5
TILT_RAD    = TABLE_TILT * 0.01745329

# Ball
BALL_R      = 0.3
BALL_MASS   = 1.0

# Physics
GRAVITY     = 14.0
GRAV_Z      = -GRAVITY * sin(TILT_RAD)   # gravity component along table
GRAV_Y_VIS  = 0.0                        # ball stays on surface
FRICTION    = 0.990
WALL_BOUNCE = 0.80
BUMPER_BOUNCE = 2.2
MAX_SPEED   = 35.0

# Flipper geometry
FLIP_LEN    = 2.8
FLIP_W      = 0.45
FLIP_REST   = -30.0     # rest angle (flippers pointing down)
FLIP_ACTIVE = 30.0      # active angle (flippers swinging up)
FLIP_SPEED  = 800.0     # degrees per second
FLIP_Y      = 0.25
FLIP_BOUNCE = 2.0

# Flipper positions (X, Z) - pivots
FLIP_L_X    = -1.8
FLIP_R_X    =  1.8
FLIP_Z      = -TABLE_HALF_L + 2.5

# Plunger
PLUNGER_X   = TABLE_HALF_W - 0.8
PLUNGER_Z   = -TABLE_HALF_L + 0.5
PLUNGER_MAX = 28.0      # max launch speed
PLUNGER_CHARGE_RATE = 35.0

# Bumper data: [x, z, radius, points]
bumperX     = []
bumperZ     = []
bumperRad   = []
bumperPts   = []
bumperHit   = []    # flash timer
bumperCount = 0

# Target lanes: [x, z, width, active, points]
targetX     = []
targetZ     = []
targetW     = []
targetAct   = []
targetPts   = []
targetCount = 0

# Particle system
partX       = []
partY       = []
partZ       = []
partVX      = []
partVY      = []
partVZ      = []
partLife    = []
partR       = []
partG       = []
partB       = []
partCount   = 0
MAX_PARTS   = 200

# Ball state
ballX       = 0.0
ballZ       = 0.0
ballVX      = 0.0
ballVZ      = 0.0
ballActive  = false
ballLost    = false
ballLaunched = false
launchTimer = 0.0

# Flipper state
flipLAngle  = FLIP_REST
flipRAngle  = -FLIP_REST
flipLPrev   = FLIP_REST
flipRPrev   = -FLIP_REST

# Plunger state
plungerCharge  = 0.0
plungerCharging = false

# Game state
STATE_TITLE    = 0
STATE_PLAYING  = 1
STATE_PAUSED   = 2
STATE_BALLOVER = 3
STATE_GAMEOVER = 4
gameState   = STATE_TITLE
score       = 0
highScore   = 0
lives       = 3
combo       = 1
comboTimer  = 0.0

# Camera
camMode     = 1   # 0=top, 1=angled, 2=dynamic
CAM_MODES   = 3

# Animation
frameTime   = 0.0
totalTime   = 0.0

# ============================================================
# Initialize
# ============================================================

InitWindow(SCREEN_W, SCREEN_H, GAME_TITLE)
SetTargetFPS(60)

camera = Camera3D(
    0.0, 24.0, -22.0,
    0.0, 0.0, 2.0,
    0.0, 1.0, 0.0,
    45.0, CAMERA_PERSPECTIVE
)

pb_initTable()

# Initialize particle arrays
for i = 1 to MAX_PARTS
    partX + 0  partY + 0  partZ + 0
    partVX + 0 partVY + 0 partVZ + 0
    partLife + 0
    partR + 0  partG + 0  partB + 0
next

# ============================================================
# Main Loop
# ============================================================

while !WindowShouldClose()

    frameTime = GetFrameTime()
    if frameTime > 0.05 frameTime = 0.05 ok
    totalTime += frameTime

    # Input
    if gameState = STATE_TITLE
        if IsKeyPressed(KEY_SPACE) or IsKeyPressed(KEY_ENTER)
            pb_newGame()
            gameState = STATE_PLAYING
        ok
    elseif gameState = STATE_PLAYING
        pb_handleInput()
        pb_updatePhysics()
        pb_updateParticles()
        pb_updateCombo()
    elseif gameState = STATE_PAUSED
        if IsKeyPressed(KEY_P)
            gameState = STATE_PLAYING
        ok
    elseif gameState = STATE_BALLOVER
        if IsKeyPressed(KEY_R) or IsKeyPressed(KEY_SPACE)
            pb_launchNewBall()
            gameState = STATE_PLAYING
        ok
    elseif gameState = STATE_GAMEOVER
        if IsKeyPressed(KEY_N) or IsKeyPressed(KEY_SPACE)
            pb_newGame()
            gameState = STATE_PLAYING
        ok
    ok

    # Camera toggle (all states)
    if IsKeyPressed(KEY_C)
        camMode += 1
        if camMode >= CAM_MODES camMode = 0 ok
    ok

    pb_updateCamera()

    # Draw
    BeginDrawing()
    ClearBackground(RAYLIBColor(15, 10, 25, 255))
    BeginMode3D(camera)

    pb_drawTable()
    pb_drawBumpers()
    pb_drawTargets()
    pb_drawFlippers()
    pb_drawPlunger()
    if ballActive
        pb_drawBall()
    ok
    pb_drawParticles()

    EndMode3D()

    pb_drawHUD()

    EndDrawing()

end

CloseWindow()

# ============================================================
# Initialize Table Layout
# ============================================================

func pb_initTable

    # Bumpers - 3 round bumpers in upper area
    bumperX + -2.2  bumperZ + 3.5  bumperRad + 0.7  bumperPts + 100  bumperHit + 0.0
    bumperX +  2.2  bumperZ + 3.5  bumperRad + 0.7  bumperPts + 100  bumperHit + 0.0
    bumperX +  0.0  bumperZ + 5.5  bumperRad + 0.7  bumperPts + 100  bumperHit + 0.0

    # Extra bumpers - middle area
    bumperX + -3.0  bumperZ + 6.5  bumperRad + 0.55 bumperPts + 250  bumperHit + 0.0
    bumperX +  3.0  bumperZ + 6.5  bumperRad + 0.55 bumperPts + 250  bumperHit + 0.0

    # Top bumper - jackpot
    bumperX +  0.0  bumperZ + 8.0  bumperRad + 0.8  bumperPts + 500  bumperHit + 0.0

    bumperCount = 6

    # Targets - lanes across upper section
    targetX + -2.5  targetZ + 1.5  targetW + 0.9  targetAct + 1  targetPts + 200
    targetX + -0.8  targetZ + 1.5  targetW + 0.9  targetAct + 1  targetPts + 200
    targetX +  0.8  targetZ + 1.5  targetW + 0.9  targetAct + 1  targetPts + 200
    targetX +  2.5  targetZ + 1.5  targetW + 0.9  targetAct + 1  targetPts + 200

    # Upper targets
    targetX + -1.8  targetZ + 8.0  targetW + 0.8  targetAct + 1  targetPts + 500
    targetX +  1.8  targetZ + 8.0  targetW + 0.8  targetAct + 1  targetPts + 500

    targetCount = 6

# ============================================================
# Game State Functions
# ============================================================

func pb_newGame
    score = 0
    lives = 3
    combo = 1
    comboTimer = 0.0
    pb_resetTargets()
    pb_launchNewBall()

func pb_launchNewBall
    ballX = 0.0
    ballZ = 0.0
    ballVX = GetRandomValue(-20, 20) * 0.05
    ballVZ = PLUNGER_MAX * 0.6
    ballActive = true
    ballLost = false
    ballLaunched = true
    launchTimer = 1.5
    plungerCharge = 0.0
    plungerCharging = false
    flipLAngle = FLIP_REST
    flipRAngle = -FLIP_REST

func pb_resetTargets
    for i = 1 to targetCount
        targetAct[i] = 1
    next

# ============================================================
# Input Handling
# ============================================================

func pb_handleInput

    # Pause
    if IsKeyPressed(KEY_P)
        gameState = STATE_PAUSED
        return
    ok

    # Left flipper - LEFT key swings it up
    if IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_Z)
        flipRAngle -= FLIP_SPEED * frameTime
        if flipRAngle < -FLIP_ACTIVE flipRAngle = -FLIP_ACTIVE ok
    else
        flipRAngle += FLIP_SPEED * 0.6 * frameTime
        if flipRAngle > -FLIP_REST flipRAngle = -FLIP_REST ok
    ok

    # Right flipper - RIGHT key swings it up
    if IsKeyDown(KEY_RIGHT) or IsKeyDown(KEY_X)
        flipLAngle += FLIP_SPEED * frameTime
        if flipLAngle > FLIP_ACTIVE flipLAngle = FLIP_ACTIVE ok
    else
        flipLAngle -= FLIP_SPEED * 0.6 * frameTime
        if flipLAngle < FLIP_REST flipLAngle = FLIP_REST ok
    ok

    # Plunger - relaunch if ball rolls back to plunger area
    if ballActive and ballLaunched
        inLane = (ballZ < -TABLE_HALF_L + 2.5) and (fabs(ballX - PLUNGER_X) < 1.0) and (fabs(ballVZ) < 2.0)
        if inLane
            if IsKeyDown(KEY_DOWN)
                plungerCharging = true
                plungerCharge += PLUNGER_CHARGE_RATE * frameTime
                if plungerCharge > PLUNGER_MAX plungerCharge = PLUNGER_MAX ok
            else
                if plungerCharging and plungerCharge > 1.0
                    ballVZ = plungerCharge
                    ballVX = GetRandomValue(-10, 10) * 0.02
                ok
                plungerCharge = 0.0
                plungerCharging = false
            ok
        ok
    ok

# ============================================================
# Physics Update
# ============================================================

func pb_updatePhysics

    if !ballActive return ok
    if !ballLaunched return ok

    # Gravity along tilted table (ball moves toward -Z = toward player)
    ballVZ += GRAV_Z * frameTime

    # Friction
    ballVX *= FRICTION
    ballVZ *= FRICTION

    # Clamp speed
    spd = pb_sqrt(ballVX * ballVX + ballVZ * ballVZ)
    if spd > MAX_SPEED
        ballVX = ballVX / spd * MAX_SPEED
        ballVZ = ballVZ / spd * MAX_SPEED
    ok

    # Move
    ballX += ballVX * frameTime
    ballZ += ballVZ * frameTime

    # Wall collisions
    # Left wall
    if ballX < -TABLE_HALF_W + WALL_THICK + BALL_R
        ballX = -TABLE_HALF_W + WALL_THICK + BALL_R
        ballVX = fabs(ballVX) * WALL_BOUNCE
    ok
    # Right wall
    if ballX > TABLE_HALF_W - WALL_THICK - BALL_R
        ballX = TABLE_HALF_W - WALL_THICK - BALL_R
        ballVX = -fabs(ballVX) * WALL_BOUNCE
    ok
    # Top wall
    if ballZ > TABLE_HALF_L - WALL_THICK - BALL_R
        ballZ = TABLE_HALF_L - WALL_THICK - BALL_R
        ballVZ = -fabs(ballVZ) * WALL_BOUNCE
    ok

    # Right side - no plunger lane trap (ball spawns at center now)

    # Launch invincibility timer
    if launchTimer > 0
        launchTimer -= frameTime
    ok

    # Bottom drain - only in the center gap between flippers
    if ballZ < -TABLE_HALF_L - 0.5
        # Exempt plunger lane area
        if ballX < TABLE_HALF_W - 2.5
            if launchTimer <= 0
                pb_ballLost()
                return
            else
                # Bounce back during invincibility
                ballZ = -TABLE_HALF_L - 0.5
                ballVZ = fabs(ballVZ) * 0.5 + 5.0
            ok
        ok
    ok

    # Hard bottom limit
    if ballZ < -TABLE_HALF_L - 3.0
        if launchTimer <= 0
            pb_ballLost()
            return
        else
            ballZ = -TABLE_HALF_L - 3.0
            ballVZ = fabs(ballVZ) * 0.5 + 8.0
        ok
    ok

    # Bumper collisions
    for i = 1 to bumperCount
        dx = ballX - bumperX[i]
        dz = ballZ - bumperZ[i]
        dist = pb_sqrt(dx * dx + dz * dz)
        minDist = BALL_R + bumperRad[i]
        if dist < minDist and dist > 0.01
            # Push ball away
            nx = dx / dist
            nz = dz / dist
            ballX = bumperX[i] + nx * minDist
            ballZ = bumperZ[i] + nz * minDist
            # Bounce
            dotV = ballVX * nx + ballVZ * nz
            ballVX = ballVX - 2 * dotV * nx
            ballVZ = ballVZ - 2 * dotV * nz
            # Add bumper energy
            ballVX += nx * BUMPER_BOUNCE * 3
            ballVZ += nz * BUMPER_BOUNCE * 3
            # Score
            pb_addScore(bumperPts[i])
            bumperHit[i] = 0.3
            # Particles
            pb_spawnParticles(bumperX[i], 0.5, bumperZ[i], 8, 255, 200, 50)
        ok
    next

    # Flipper collisions
    pb_checkFlipperCollision("L")
    pb_checkFlipperCollision("R")

    # Target collisions
    for i = 1 to targetCount
        if targetAct[i] = 1
            dx = fabs(ballX - targetX[i])
            dz = fabs(ballZ - targetZ[i])
            if dx < targetW[i] / 2 + BALL_R and dz < 0.4 + BALL_R
                targetAct[i] = 0
                pb_addScore(targetPts[i])
                ballVZ = -fabs(ballVZ) * 0.6
                pb_spawnParticles(targetX[i], 0.5, targetZ[i], 6, 50, 255, 100)
                # Check if all targets down - bonus + reset
                allDown = true
                for j = 1 to targetCount
                    if targetAct[j] = 1 allDown = false exit ok
                next
                if allDown
                    pb_addScore(5000)
                    pb_resetTargets()
                    pb_spawnParticles(0, 1.0, 5.0, 20, 255, 255, 0)
                ok
            ok
        ok
    next

    # Slingshot walls - gentle bounce near flippers
    # Left slingshot
    slX = -TABLE_HALF_W + 1.5
    slZ1 = FLIP_Z - 1.0
    slZ2 = FLIP_Z + 3.0
    if ballX < slX + BALL_R + 0.3 and ballX > -TABLE_HALF_W + WALL_THICK + BALL_R
        if ballZ > slZ1 and ballZ < slZ2
            ballX = slX + BALL_R + 0.3
            ballVX = fabs(ballVX) * 1.2 + 1.5
            pb_addScore(10)
        ok
    ok
    # Right slingshot
    srX = TABLE_HALF_W - 1.5
    if ballX > srX - BALL_R - 0.3 and ballX < TABLE_HALF_W - WALL_THICK - BALL_R
        if ballZ > slZ1 and ballZ < slZ2
            ballX = srX - BALL_R - 0.3
            ballVX = -fabs(ballVX) * 1.2 - 1.5
            pb_addScore(10)
        ok
    ok

func pb_checkFlipperCollision side

    if side = "L"
        pivotX = FLIP_L_X
        angle = flipLAngle
        prevAngle = flipLPrev
    else
        pivotX = FLIP_R_X
        angle = flipRAngle
        prevAngle = flipRPrev
    ok
    pivotZ = FLIP_Z

    # Flipper tip position
    angRad = angle * 0.01745329
    tipX = pivotX + cos(angRad) * FLIP_LEN
    tipZ = pivotZ + sin(angRad) * FLIP_LEN

    # Check ball against flipper line segment
    # Project ball onto flipper line
    fvX = tipX - pivotX
    fvZ = tipZ - pivotZ
    fLen = pb_sqrt(fvX * fvX + fvZ * fvZ)
    if fLen < 0.01 return ok
    fnX = fvX / fLen
    fnZ = fvZ / fLen

    # Vector from pivot to ball
    bpX = ballX - pivotX
    bpZ = ballZ - pivotZ

    # Project
    proj = bpX * fnX + bpZ * fnZ
    if proj < 0 proj = 0 ok
    if proj > fLen proj = fLen ok

    # Closest point on flipper
    cpX = pivotX + fnX * proj
    cpZ = pivotZ + fnZ * proj

    dx = ballX - cpX
    dz = ballZ - cpZ
    dist = pb_sqrt(dx * dx + dz * dz)

    if dist < BALL_R + FLIP_W / 2 and dist > 0.01
        # Push out
        nx = dx / dist
        nz = dz / dist
        ballX = cpX + nx * (BALL_R + FLIP_W / 2 + 0.05)
        ballZ = cpZ + nz * (BALL_R + FLIP_W / 2 + 0.05)

        # Flipper angular velocity contributes to ball
        angVel = (angle - prevAngle) / frameTime * 0.01745329
        # Tangential velocity at contact point
        tVel = angVel * proj

        # Reflect velocity
        dotV = ballVX * nx + ballVZ * nz
        ballVX = ballVX - 2 * dotV * nx
        ballVZ = ballVZ - 2 * dotV * nz

        # Add flipper hit energy
        flipHitPower = fabs(tVel) * FLIP_BOUNCE
        if flipHitPower > 0.5
            ballVX += nx * flipHitPower * 0.3
            ballVZ += nz * flipHitPower + fabs(tVel) * 0.8
            if ballVZ < 0 ballVZ = fabs(ballVZ) ok
        ok

        # Minimum upward velocity from flipper
        if ballVZ < 5.0 and (angle - prevAngle) != 0
            ballVZ = 5.0 + fabs(tVel) * 0.8
        ok
    ok

func pb_ballLost
    ballActive = false
    ballLost = true
    lives -= 1
    combo = 1
    comboTimer = 0.0
    if lives <= 0
        if score > highScore highScore = score ok
        gameState = STATE_GAMEOVER
    else
        gameState = STATE_BALLOVER
    ok

# ============================================================
# Scoring & Combo
# ============================================================

func pb_addScore pts
    score += pts * combo
    comboTimer = 3.0
    combo += 1
    if combo > 10 combo = 10 ok

func pb_updateCombo
    if comboTimer > 0
        comboTimer -= frameTime
        if comboTimer <= 0
            combo = 1
        ok
    ok

# ============================================================
# Particles
# ============================================================

func pb_spawnParticles px, py, pz, count, cr, cg, cb
    for i = 1 to count
        slot = 0
        for j = 1 to MAX_PARTS
            if partLife[j] <= 0
                slot = j
                exit
            ok
        next
        if slot = 0 return ok
        partX[slot] = px
        partY[slot] = py
        partZ[slot] = pz
        partVX[slot] = (GetRandomValue(-100, 100)) * 0.05
        partVY[slot] = (GetRandomValue(20, 100)) * 0.05
        partVZ[slot] = (GetRandomValue(-100, 100)) * 0.05
        partLife[slot] = 0.5 + GetRandomValue(0, 50) * 0.01
        partR[slot] = cr
        partG[slot] = cg
        partB[slot] = cb
    next

func pb_updateParticles
    for i = 1 to MAX_PARTS
        if partLife[i] > 0
            partLife[i] -= frameTime
            partX[i] += partVX[i] * frameTime
            partY[i] += partVY[i] * frameTime
            partZ[i] += partVZ[i] * frameTime
            partVY[i] -= 9.0 * frameTime
        ok
    next

func pb_drawParticles
    for i = 1 to MAX_PARTS
        if partLife[i] > 0
            alpha = partLife[i] * 255
            if alpha > 255 alpha = 255 ok
            sz = 0.08 + partLife[i] * 0.12
            DrawCube(Vector3(partX[i], partY[i], partZ[i]),
                     sz, sz, sz,
                     RAYLIBColor(partR[i], partG[i], partB[i], alpha))
        ok
    next

# ============================================================
# Camera
# ============================================================

func pb_updateCamera

    if camMode = 0
        # Top-down view - high enough to see entire table
        camera.position.x = 0.0
        camera.position.y = 32.0
        camera.position.z = -2.0
        camera.target.x = 0.0
        camera.target.y = 0.0
        camera.target.z = 1.0

    elseif camMode = 1
        # Angled view (classic pinball perspective)
        camera.position.x = 0.0
        camera.position.y = 24.0
        camera.position.z = -22.0
        camera.target.x = 0.0
        camera.target.y = 0.0
        camera.target.z = 2.0

    elseif camMode = 2
        # Dynamic - follow ball
        if ballActive
            tx = ballX * 0.3
            tz = ballZ * 0.3
        else
            tx = 0.0
            tz = 0.0
        ok
        camera.position.x = tx
        camera.position.y = 26.0
        camera.position.z = tz - 18.0
        camera.target.x = tx
        camera.target.y = 0.0
        camera.target.z = tz + 2.0
    ok

    # Store previous flipper angles (after camera, before next frame)
    flipLPrev = flipLAngle
    flipRPrev = flipRAngle

# ============================================================
# Draw Table
# ============================================================

func pb_drawTable

    # Table surface (dark green felt)
    DrawCube(Vector3(0, -0.1, 0), TABLE_W - WALL_THICK * 2, 0.15, TABLE_LEN,
             RAYLIBColor(15, 60, 30, 255))

    # Playfield markings - center circle
    DrawCylinder(Vector3(0, 0.01, 3.0), 2.0, 2.0, 0.02, 20,
                 RAYLIBColor(25, 80, 40, 255))

    # Table border - walls
    wallCol = RAYLIBColor(100, 100, 120, 255)
    wallTopCol = RAYLIBColor(140, 140, 160, 255)

    # Left wall
    DrawCube(Vector3(-TABLE_HALF_W + WALL_THICK / 2, WALL_H / 2, 0),
             WALL_THICK, WALL_H, TABLE_LEN, wallCol)
    DrawCube(Vector3(-TABLE_HALF_W + WALL_THICK / 2, WALL_H, 0),
             WALL_THICK + 0.1, 0.1, TABLE_LEN, wallTopCol)

    # Right wall
    DrawCube(Vector3(TABLE_HALF_W - WALL_THICK / 2, WALL_H / 2, 0),
             WALL_THICK, WALL_H, TABLE_LEN, wallCol)
    DrawCube(Vector3(TABLE_HALF_W - WALL_THICK / 2, WALL_H, 0),
             WALL_THICK + 0.1, 0.1, TABLE_LEN, wallTopCol)

    # Top wall
    DrawCube(Vector3(0, WALL_H / 2, TABLE_HALF_L - WALL_THICK / 2),
             TABLE_W, WALL_H, WALL_THICK, wallCol)
    DrawCube(Vector3(0, WALL_H, TABLE_HALF_L - WALL_THICK / 2),
             TABLE_W, 0.1, WALL_THICK + 0.1, wallTopCol)

    # Bottom partial walls (leave gap for drain between flippers)
    gapW = 4.5   # gap between flipper area walls
    # Left bottom wall
    leftBotW = TABLE_HALF_W - gapW / 2
    DrawCube(Vector3(-TABLE_HALF_W + leftBotW / 2 + WALL_THICK / 2, WALL_H / 2,
             -TABLE_HALF_L + WALL_THICK / 2),
             leftBotW, WALL_H, WALL_THICK, wallCol)
    # Right bottom wall
    DrawCube(Vector3(TABLE_HALF_W - leftBotW / 2 - WALL_THICK / 2, WALL_H / 2,
             -TABLE_HALF_L + WALL_THICK / 2),
             leftBotW, WALL_H, WALL_THICK, wallCol)

    # Decorative strip where plunger lane was
    DrawCube(Vector3(TABLE_HALF_W - 1.5, 0.02, -TABLE_HALF_L + 3.0),
             0.8, 0.04, 5.0, RAYLIBColor(20, 50, 25, 255))

    # Slingshot walls (angled near flippers)
    slingCol = RAYLIBColor(180, 60, 60, 255)
    # Left slingshot
    DrawCube(Vector3(-TABLE_HALF_W + 1.5, 0.4, FLIP_Z + 1.0),
             0.25, 0.8, 3.5, slingCol)
    # Right slingshot
    DrawCube(Vector3(TABLE_HALF_W - 2.5, 0.4, FLIP_Z + 1.0),
             0.25, 0.8, 3.5, slingCol)

    # Lane guides - upper area decorative strips
    guideCol = RAYLIBColor(60, 60, 80, 200)
    DrawCube(Vector3(-1.5, 0.15, 7.0), 0.15, 0.3, 2.5, guideCol)
    DrawCube(Vector3( 1.5, 0.15, 7.0), 0.15, 0.3, 2.5, guideCol)

    # Ramp entrance decoration
    DrawCube(Vector3(0, 0.2, TABLE_HALF_L - 1.5), 3.0, 0.05, 0.3,
             RAYLIBColor(200, 180, 50, 255))

# ============================================================
# Draw Bumpers
# ============================================================

func pb_drawBumpers
    for i = 1 to bumperCount
        bx = bumperX[i]
        bz = bumperZ[i]
        br = bumperRad[i]

        # Flash when hit
        if bumperHit[i] > 0
            bumperHit[i] -= frameTime
            flashI = bumperHit[i] / 0.3
            cr = 255
            cg = 100 + flashI * 155
            cb = 50 + flashI * 205
            # Glow ring
            DrawCylinder(Vector3(bx, 0.01, bz), br + 0.3, br + 0.3, 0.02, 16,
                         RAYLIBColor(255, 255, 100, 100 * flashI))
        else
            cr = 200
            cg = 60
            cb = 60
        ok

        # Bumper body (cylinder)
        DrawCylinder(Vector3(bx, 0.0, bz), br, br, 0.8, 16,
                     RAYLIBColor(cr, cg, cb, 255))
        # Top cap
        DrawCylinder(Vector3(bx, 0.8, bz), br * 0.7, br, 0.15, 16,
                     RAYLIBColor(cr + 30, cg + 30, cb + 30, 255))
        # Chrome ring
        DrawCylinder(Vector3(bx, 0.4, bz), br + 0.05, br + 0.05, 0.1, 16,
                     RAYLIBColor(200, 200, 220, 255))

        # Score label ring on top
        DrawCylinderWires(Vector3(bx, 0.82, bz), br * 0.5, br * 0.5, 0.05, 12,
                         RAYLIBColor(255, 255, 200, 200))
    next

# ============================================================
# Draw Targets
# ============================================================

func pb_drawTargets
    for i = 1 to targetCount
        tx = targetX[i]
        tz = targetZ[i]
        tw = targetW[i]

        if targetAct[i] = 1
            # Active target - glowing
            pulse = (sin(totalTime * 5 + i) + 1) * 0.5
            cr = 50 + pulse * 50
            cg = 200 + pulse * 55
            cb = 100 + pulse * 50
            DrawCube(Vector3(tx, 0.3, tz), tw, 0.6, 0.3,
                     RAYLIBColor(cr, cg, cb, 255))
            DrawCubeWires(Vector3(tx, 0.3, tz), tw, 0.6, 0.3,
                     RAYLIBColor(200, 255, 200, 200))
            # Light on top
            DrawSphere(Vector3(tx, 0.65, tz), 0.1,
                     RAYLIBColor(100, 255, 150, 200))
        else
            # Inactive target - dim
            DrawCube(Vector3(tx, 0.2, tz), tw, 0.4, 0.3,
                     RAYLIBColor(40, 60, 40, 255))
        ok
    next

# ============================================================
# Draw Flippers
# ============================================================

func pb_drawFlippers
    flipCol = RAYLIBColor(220, 180, 50, 255)
    flipEdge = RAYLIBColor(255, 220, 80, 255)

    # Left flipper
    angL = flipLAngle * 0.01745329
    lTipX = FLIP_L_X + cos(angL) * FLIP_LEN
    lTipZ = FLIP_Z + sin(angL) * FLIP_LEN
    lMidX = (FLIP_L_X + lTipX) / 2
    lMidZ = (FLIP_Z + lTipZ) / 2
    DrawCube(Vector3(lMidX, FLIP_Y, lMidZ), FLIP_LEN, 0.35, FLIP_W, flipCol)
    # Pivot
    DrawCylinder(Vector3(FLIP_L_X, 0, FLIP_Z), 0.25, 0.25, 0.5, 10, flipEdge)

    # Crude rotation: draw multiple cubes along flipper line to approximate
    segs = 5
    for s = 0 to segs
        frac = s / segs
        sx = FLIP_L_X + cos(angL) * FLIP_LEN * frac
        sz = FLIP_Z + sin(angL) * FLIP_LEN * frac
        sw = FLIP_W * (1.0 - frac * 0.4)  # taper
        DrawCube(Vector3(sx, FLIP_Y, sz), sw, 0.35, sw, flipCol)
    next

    # Right flipper
    angR = flipRAngle * 0.01745329
    rTipX = FLIP_R_X + cos(angR) * FLIP_LEN
    rTipZ = FLIP_Z + sin(angR) * FLIP_LEN
    DrawCylinder(Vector3(FLIP_R_X, 0, FLIP_Z), 0.25, 0.25, 0.5, 10, flipEdge)
    for s = 0 to segs
        frac = s / segs
        sx = FLIP_R_X + cos(angR) * FLIP_LEN * frac
        sz = FLIP_Z + sin(angR) * FLIP_LEN * frac
        sw = FLIP_W * (1.0 - frac * 0.4)
        DrawCube(Vector3(sx, FLIP_Y, sz), sw, 0.35, sw, flipCol)
    next

# ============================================================
# Draw Plunger
# ============================================================

func pb_drawPlunger
    # Plunger lane
    DrawCube(Vector3(PLUNGER_X, 0.01, -TABLE_HALF_L + 3.0),
             1.2, 0.02, 6.0, RAYLIBColor(20, 50, 25, 255))

    # Plunger rod
    pullBack = plungerCharge / PLUNGER_MAX * 2.0
    rodZ = PLUNGER_Z - pullBack
    rodCol = RAYLIBColor(180, 180, 200, 255)
    DrawCylinder(Vector3(PLUNGER_X, 0.25, rodZ), 0.15, 0.15, 0.5, 8, rodCol)

    # Plunger head
    headCol = RAYLIBColor(200, 50, 50, 255)
    DrawCylinder(Vector3(PLUNGER_X, 0.15, rodZ + 0.3), 0.3, 0.3, 0.35, 10, headCol)

    # Charge indicator glow
    if plungerCharging and plungerCharge > 0.5
        glowI = plungerCharge / PLUNGER_MAX
        DrawCylinder(Vector3(PLUNGER_X, 0.01, rodZ),
                     0.5, 0.5, 0.02, 10,
                     RAYLIBColor(255, 100, 50, 150 * glowI))
    ok

    # Spring visualization
    springCol = RAYLIBColor(150, 150, 160, 200)
    springZ = rodZ - 0.3
    for i = 1 to 5
        sz = springZ - i * 0.15
        DrawCube(Vector3(PLUNGER_X, 0.2, sz), 0.3, 0.08, 0.05, springCol)
    next

# ============================================================
# Draw Ball
# ============================================================

func pb_drawBall
    by = BALL_R + 0.05

    # Shadow
    DrawCylinder(Vector3(ballX, 0.01, ballZ), BALL_R * 0.9, BALL_R * 0.9, 0.01, 12,
                 RAYLIBColor(0, 0, 0, 80))

    # Ball body (metallic silver)
    DrawSphere(Vector3(ballX, by, ballZ), BALL_R,
               RAYLIBColor(200, 200, 210, 255))

    # Specular highlight
    DrawSphere(Vector3(ballX - 0.05, by + 0.1, ballZ + 0.05), BALL_R * 0.35,
               RAYLIBColor(255, 255, 255, 120))

    # Motion trail when fast
    spd = pb_sqrt(ballVX * ballVX + ballVZ * ballVZ)
    if spd > 5.0
        trailA = (spd - 5.0) / MAX_SPEED * 100
        if trailA > 100 trailA = 100 ok
        for t = 1 to 3
            tx = ballX - ballVX * frameTime * t * 2
            tz = ballZ - ballVZ * frameTime * t * 2
            DrawSphere(Vector3(tx, by, tz), BALL_R * (0.6 - t * 0.15),
                       RAYLIBColor(180, 180, 200, trailA / t))
        next
    ok

# ============================================================
# Draw HUD
# ============================================================

func pb_drawHUD

    # Score panel background
    DrawRectangle(10, 10, 250, 100, RAYLIBColor(0, 0, 0, 160))
    DrawRectangleLines(10, 10, 250, 100, RAYLIBColor(200, 180, 50, 200))

    DrawText("SCORE: " + score, 20, 18, 28, RAYLIBColor(255, 220, 50, 255))
    DrawText("HIGH:  " + highScore, 20, 50, 20, RAYLIBColor(200, 200, 200, 255))

    # Lives
    lifeStr = "BALLS: "
    for i = 1 to lives
        lifeStr += "O "
    next
    DrawText(lifeStr, 20, 78, 20, RAYLIBColor(255, 100, 100, 255))

    # Combo indicator
    if combo > 1
        comboCol = RAYLIBColor(100, 255, 100, 255)
        DrawText("COMBO x" + combo, SCREEN_W - 200, 18, 28, comboCol)
        # Combo bar
        barW = 150 * comboTimer / 3.0
        DrawRectangle(SCREEN_W - 200, 50, barW, 8, comboCol)
    ok

    # Plunger power bar
    if plungerCharging
        barH = 200 * plungerCharge / PLUNGER_MAX
        DrawRectangle(SCREEN_W - 40, SCREEN_H - 220, 20, 200, RAYLIBColor(40, 40, 40, 200))
        DrawRectangle(SCREEN_W - 40, SCREEN_H - 20 - barH, 20, barH,
                      RAYLIBColor(255, 100 + 155 * plungerCharge / PLUNGER_MAX, 50, 255))
        DrawText("PWR", SCREEN_W - 50, SCREEN_H - 240, 16, WHITE)
    ok

    # Camera mode
    camNames = ["TOP", "ANGLE", "FOLLOW"]
    DrawText("CAM: " + camNames[camMode + 1] + "  [C]", SCREEN_W - 200, SCREEN_H - 30, 16,
             RAYLIBColor(150, 150, 150, 200))

    # State overlays
    if gameState = STATE_TITLE
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 180))
        pb_drawCenteredText("PINBALL 3D", SCREEN_H / 2 - 60, 60, RAYLIBColor(255, 220, 50, 255))
        pb_drawCenteredText("Press SPACE to Start", SCREEN_H / 2 + 20, 24, WHITE)
        pb_drawCenteredText("LEFT/RIGHT = Flippers   SPACE = Launch", SCREEN_H / 2 + 60, 18,
                           RAYLIBColor(180, 180, 180, 255))
    elseif gameState = STATE_PAUSED
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 150))
        pb_drawCenteredText("PAUSED", SCREEN_H / 2 - 20, 50, WHITE)
        pb_drawCenteredText("Press P to Resume", SCREEN_H / 2 + 30, 20, LIGHTGRAY)
    elseif gameState = STATE_BALLOVER
        DrawRectangle(SCREEN_W / 2 - 160, SCREEN_H / 2 - 40, 320, 80,
                      RAYLIBColor(0, 0, 0, 200))
        pb_drawCenteredText("BALL LOST!", SCREEN_H / 2 - 20, 30, RAYLIBColor(255, 80, 80, 255))
        pb_drawCenteredText("Press SPACE for next ball", SCREEN_H / 2 + 15, 18, WHITE)
    elseif gameState = STATE_GAMEOVER
        DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 200))
        pb_drawCenteredText("GAME OVER", SCREEN_H / 2 - 50, 50, RAYLIBColor(255, 50, 50, 255))
        pb_drawCenteredText("Final Score: " + score, SCREEN_H / 2 + 10, 30,
                           RAYLIBColor(255, 220, 50, 255))
        if score >= highScore and score > 0
            pb_drawCenteredText("NEW HIGH SCORE!", SCREEN_H / 2 + 50, 24,
                               RAYLIBColor(255, 255, 100, 255))
        ok
        pb_drawCenteredText("Press SPACE for New Game", SCREEN_H / 2 + 85, 20, WHITE)
    ok

    DrawFPS(SCREEN_W - 80, 10)

# ============================================================
# Utility Functions
# ============================================================

func pb_drawCenteredText txt, y, fontSize, color
    tw = MeasureText(txt, fontSize)
    DrawText(txt, (SCREEN_W - tw) / 2, y, fontSize, color)

func pb_sqrt val
    if val <= 0 return 0 ok
    g = val / 2
    if g < 1 g = 1 ok
    g = (g + val / g) / 2
    g = (g + val / g) / 2
    g = (g + val / g) / 2
    g = (g + val / g) / 2
    return g

func fabs val
    if val < 0 return -val ok
    return val
