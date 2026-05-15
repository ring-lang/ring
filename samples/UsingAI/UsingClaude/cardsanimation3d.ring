/*
**  3D Cards Animation - RingRayLib
**  =================================
**  Watch beautiful 3D card animations!
**
**  Controls:
**    A / Add Button      - Add a card with random animation
**    P / Pause Button    - Pause / Resume all animations
**    C / Clear Button    - Clear all cards
**    V / Camera Button   - Cycle camera view
**    1-8                 - Add card with specific animation type
**    ESC                 - Exit
**
**  Animation Types:
**    1. Float       - Cards drift and bob in 3D space
**    2. Spiral      - Cards spiral outward and upward
**    3. Bounce      - Cards bounce off invisible walls
**    4. Spin        - Cards spin on their Y axis
**    5. Wave        - Cards ride a 3D sine wave
**    6. Cascade     - Cards rain down with gravity
**    7. Orbit       - Cards orbit a center point in 3D
**    8. Firework    - Cards explode outward in all directions
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W    = 1024
SCREEN_H    = 700

// 3D card dimensions
CARD3D_W    = 1.2
CARD3D_H    = 0.08
CARD3D_D    = 1.7

// Arena bounds
ARENA_SIZE  = 12.0
ARENA_HALF  = ARENA_SIZE / 2.0

SUIT_HEART   = 1
SUIT_DIAMOND = 2
SUIT_CLUB    = 3
SUIT_SPADE   = 4

ANIM_FLOAT    = 1
ANIM_SPIRAL   = 2
ANIM_BOUNCE   = 3
ANIM_SPIN     = 4
ANIM_WAVE     = 5
ANIM_CASCADE  = 6
ANIM_ORBIT    = 7
ANIM_FIREWORK = 8
ANIM_COUNT    = 8

animNames = ["Float", "Spiral", "Bounce", "Spin", "Wave", "Cascade", "Orbit", "Firework"]
rankNames = ["A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"]
suitSyms  = ["H", "D", "C", "S"]

// Camera modes
CAM_FRONT    = 1
CAM_OVERHEAD = 2
CAM_ORBIT_CAM = 3
CAM_COUNT    = 3
camModeNames = ["Front", "Overhead", "Orbit"]

// =============================================================
// State
// =============================================================

cards = []
particles = []
animTime = 0.0
paused = false
hoverBtn = 0

cameraMode = CAM_FRONT
camPosX = 0.0    camPosY = 10.0   camPosZ = 16.0
camTgtX = 0.0    camTgtY = 1.0    camTgtZ = 0.0
camOrbitAngle = 0.0

// Button layout
BTN_Y = SCREEN_H - 52
BTN_H = 38
BTN_GAP = 8

// Projection helper
projCamPosX = 0.0  projCamPosY = 0.0  projCamPosZ = 0.0
projCamTgtX = 0.0  projCamTgtY = 0.0  projCamTgtZ = 0.0

// =============================================================
// Main
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "3D Cards Animation - RingRayLib")
SetTargetFPS(60)
SetExitKey(0)

camera = Camera3D(
    0, 10, 16,
    0, 1, 0,
    0, 1, 0,
    45,
    CAMERA_PERSPECTIVE
)

// Seed with a few cards
for i = 1 to 5
    ca3_addRandomCard()
next

while !WindowShouldClose()
    ca3_update()
    BeginDrawing()
        ClearBackground(RAYLIBColor(15, 18, 30, 255))
        BeginMode3D(camera)
            ca3_draw3D()
        EndMode3D()
        ca3_drawHUD()
    EndDrawing()
end

CloseWindow()

// =============================================================
// Update
// =============================================================

func ca3_update
    dt = GetFrameTime()

    if IsKeyPressed(KEY_ESCAPE)
        CloseWindow()
        shutdown(0)
    ok

    if IsKeyPressed(KEY_A)
        ca3_addRandomCard()
    ok

    for k = 1 to ANIM_COUNT
        if IsKeyPressed(48 + k)
            ca3_addCard(k)
        ok
    next

    if IsKeyPressed(KEY_P)
        paused = !paused
    ok

    if IsKeyPressed(KEY_C)
        cards = []
        particles = []
    ok

    if IsKeyPressed(KEY_V)
        cameraMode++
        if cameraMode > CAM_COUNT cameraMode = CAM_FRONT ok
    ok

    if IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
        ca3_handleClick(GetMouseX(), GetMouseY())
    ok

    // Camera
    ca3_updateCamera(dt)

    if !paused
        animTime += dt
        ca3_updateCards(dt)
        ca3_updateParticles(dt)
    ok

// =============================================================
// Camera
// =============================================================

func ca3_updateCamera dt
    goalX = 0.0  goalY = 0.0  goalZ = 0.0
    tgtX = 0.0   tgtY = 1.0   tgtZ = 0.0

    if cameraMode = CAM_FRONT
        goalX = 0.0   goalY = 10.0  goalZ = 16.0
        tgtX = 0.0    tgtY = 1.0    tgtZ = 0.0
    ok
    if cameraMode = CAM_OVERHEAD
        goalX = 0.0   goalY = 22.0  goalZ = 1.0
        tgtX = 0.0    tgtY = 0.0    tgtZ = 0.0
    ok
    if cameraMode = CAM_ORBIT_CAM
        if !paused
            camOrbitAngle += dt * 0.4
        ok
        goalX = cos(camOrbitAngle) * 18.0
        goalY = 10.0
        goalZ = sin(camOrbitAngle) * 18.0
        tgtX = 0.0    tgtY = 1.0    tgtZ = 0.0
    ok

    lerpSpd = 0.04
    camPosX += (goalX - camPosX) * lerpSpd
    camPosY += (goalY - camPosY) * lerpSpd
    camPosZ += (goalZ - camPosZ) * lerpSpd
    camTgtX += (tgtX - camTgtX) * lerpSpd
    camTgtY += (tgtY - camTgtY) * lerpSpd
    camTgtZ += (tgtZ - camTgtZ) * lerpSpd

    camera = Camera3D(
        camPosX, camPosY, camPosZ,
        camTgtX, camTgtY, camTgtZ,
        0, 1, 0,
        45, CAMERA_PERSPECTIVE
    )

    projCamPosX = camPosX  projCamPosY = camPosY  projCamPosZ = camPosZ
    projCamTgtX = camTgtX  projCamTgtY = camTgtY  projCamTgtZ = camTgtZ

// =============================================================
// Add Cards
// =============================================================

func ca3_addRandomCard
    ca3_addCard(GetRandomValue(1, ANIM_COUNT))

func ca3_addCard animType
    rank = GetRandomValue(1, 13)
    suit = GetRandomValue(1, 4)

    // Card data: [rank, suit, animType, px, py, pz, vx, vy, vz, rotY, lifetime, p1, p2, p3, alpha]
    //              1     2       3       4   5   6   7   8   9   10     11       12  13  14   15
    px = 0.0  py = 1.0  pz = 0.0
    vx = 0.0  vy = 0.0  vz = 0.0
    rotY = 0.0
    lifetime = 0.0
    p1 = 0.0  p2 = 0.0  p3 = 0.0
    alpha = 255

    if animType = ANIM_FLOAT
        px = (GetRandomValue(-80, 80) / 100.0) * ARENA_HALF
        py = GetRandomValue(5, 60) / 10.0
        pz = (GetRandomValue(-80, 80) / 100.0) * ARENA_HALF
        vx = (GetRandomValue(-100, 100) / 100.0) * 1.5
        vy = 0.0
        vz = (GetRandomValue(-100, 100) / 100.0) * 1.5
        p1 = GetRandomValue(10, 30) / 10.0   // bob speed
        p2 = GetRandomValue(3, 12) / 10.0     // bob amplitude
        p3 = GetRandomValue(0, 628) / 100.0   // phase
    ok

    if animType = ANIM_SPIRAL
        p1 = GetRandomValue(0, 628) / 100.0   // start angle
        p2 = 0.5                                // initial radius
        p3 = GetRandomValue(80, 180) / 100.0   // spiral speed
        py = 0.5
    ok

    if animType = ANIM_BOUNCE
        px = (GetRandomValue(-60, 60) / 100.0) * ARENA_HALF
        py = GetRandomValue(20, 50) / 10.0
        pz = (GetRandomValue(-60, 60) / 100.0) * ARENA_HALF
        vx = (GetRandomValue(-200, 200) / 100.0) * 3.0
        vy = (GetRandomValue(50, 200) / 100.0) * 2.0
        vz = (GetRandomValue(-200, 200) / 100.0) * 3.0
        if vx > -1.0 and vx < 1.0 vx = 3.0 ok
        if vz > -1.0 and vz < 1.0 vz = 3.0 ok
    ok

    if animType = ANIM_SPIN
        px = (GetRandomValue(-60, 60) / 100.0) * ARENA_HALF
        py = GetRandomValue(10, 40) / 10.0
        pz = (GetRandomValue(-60, 60) / 100.0) * ARENA_HALF
        p1 = (GetRandomValue(-400, 400) / 100.0)  // spin speed rad/s
        if p1 > -1.0 and p1 < 1.0 p1 = 3.0 ok
    ok

    if animType = ANIM_WAVE
        px = -ARENA_HALF
        py = 2.0
        pz = (GetRandomValue(-50, 50) / 100.0) * ARENA_HALF
        vx = GetRandomValue(20, 60) / 10.0
        p1 = GetRandomValue(10, 30) / 10.0     // amplitude
        p2 = GetRandomValue(10, 30) / 10.0     // frequency
        p3 = GetRandomValue(0, 628) / 100.0    // phase
    ok

    if animType = ANIM_CASCADE
        px = (GetRandomValue(-80, 80) / 100.0) * ARENA_HALF
        py = 12.0
        pz = (GetRandomValue(-80, 80) / 100.0) * ARENA_HALF
        vx = (GetRandomValue(-50, 50) / 100.0) * 1.0
        vy = -GetRandomValue(10, 40) / 10.0
        vz = (GetRandomValue(-50, 50) / 100.0) * 1.0
        p1 = (GetRandomValue(-300, 300) / 100.0)  // rotation speed
    ok

    if animType = ANIM_ORBIT
        p1 = GetRandomValue(0, 628) / 100.0      // start angle
        p2 = GetRandomValue(30, 80) / 10.0         // radius
        p3 = GetRandomValue(50, 200) / 100.0       // speed rad/s
        py = GetRandomValue(10, 40) / 10.0
    ok

    if animType = ANIM_FIREWORK
        p1 = GetRandomValue(0, 628) / 100.0        // horizontal angle
        p2 = GetRandomValue(0, 314) / 100.0         // vertical angle
        speed = GetRandomValue(40, 100) / 10.0
        vx = cos(p1) * sin(p2) * speed
        vy = cos(p2) * speed + 3.0
        vz = sin(p1) * sin(p2) * speed
        py = 1.0
    ok

    add(cards, [rank, suit, animType, px, py, pz, vx, vy, vz, rotY, lifetime, p1, p2, p3, alpha])

// =============================================================
// Update Card Animations
// =============================================================

func ca3_updateCards dt
    toRemove = []
    for i = 1 to len(cards)
        c = cards[i]
        aType = c[3]
        c[11] += dt  // lifetime

        if aType = ANIM_FLOAT
            c[4] += c[7] * dt
            c[5] += sin(animTime * c[12] + c[14]) * c[13] * dt
            c[6] += c[9] * dt
            c[10] = sin(animTime * 0.5 + c[14]) * 0.3
            // Wrap
            if c[4] < -ARENA_HALF c[4] = ARENA_HALF ok
            if c[4] > ARENA_HALF c[4] = -ARENA_HALF ok
            if c[6] < -ARENA_HALF c[6] = ARENA_HALF ok
            if c[6] > ARENA_HALF c[6] = -ARENA_HALF ok
        ok

        if aType = ANIM_SPIRAL
            c[13] += 2.5 * dt        // radius grows
            c[12] += c[14] * dt      // angle advances
            c[5] += 1.5 * dt         // rises
            c[4] = cos(c[12]) * c[13]
            c[6] = sin(c[12]) * c[13]
            c[10] = c[12]
            if c[13] > ARENA_HALF + 2 or c[5] > 15.0
                add(toRemove, i)
            ok
        ok

        if aType = ANIM_BOUNCE
            c[4] += c[7] * dt
            c[5] += c[8] * dt
            c[6] += c[9] * dt
            c[8] -= 9.0 * dt  // gravity
            // Bounce off walls
            if c[4] < -ARENA_HALF  c[4] = -ARENA_HALF  c[7] = fabs(c[7]) ok
            if c[4] > ARENA_HALF   c[4] = ARENA_HALF   c[7] = -fabs(c[7]) ok
            if c[6] < -ARENA_HALF  c[6] = -ARENA_HALF  c[9] = fabs(c[9]) ok
            if c[6] > ARENA_HALF   c[6] = ARENA_HALF   c[9] = -fabs(c[9]) ok
            // Bounce off floor
            if c[5] < 0.2
                c[5] = 0.2
                c[8] = fabs(c[8]) * 0.85
            ok
            if c[5] > 12.0
                c[5] = 12.0
                c[8] = -fabs(c[8])
            ok
            c[10] = sin(c[11] * 2.0) * 0.5
        ok

        if aType = ANIM_SPIN
            c[10] += c[12] * dt  // rotate on Y axis
            c[5] = c[5] + sin(animTime * 1.5) * 0.003
        ok

        if aType = ANIM_WAVE
            c[4] += c[7] * dt
            c[5] = 2.0 + sin(c[4] * c[13] + c[14]) * c[12]
            c[10] = cos(c[4] * c[13] + c[14]) * 0.4
            if c[4] > ARENA_HALF + 2
                c[4] = -ARENA_HALF - 1.0
            ok
        ok

        if aType = ANIM_CASCADE
            c[4] += c[7] * dt
            c[5] += c[8] * dt
            c[6] += c[9] * dt
            c[8] -= 6.0 * dt   // gravity
            c[10] += c[12] * dt
            if c[5] < -1.0
                // Spawn particles on impact
                ca3_spawnParticles(c[4], 0.2, c[6], 6)
                c[4] = (GetRandomValue(-80, 80) / 100.0) * ARENA_HALF
                c[5] = 12.0
                c[6] = (GetRandomValue(-80, 80) / 100.0) * ARENA_HALF
                c[8] = -GetRandomValue(10, 40) / 10.0
            ok
        ok

        if aType = ANIM_ORBIT
            c[12] += c[14] * dt
            c[4] = cos(c[12]) * c[13]
            c[6] = sin(c[12]) * c[13]
            c[10] = c[12] * 0.5
        ok

        if aType = ANIM_FIREWORK
            c[4] += c[7] * dt
            c[5] += c[8] * dt
            c[6] += c[9] * dt
            c[8] -= 5.0 * dt   // gravity
            c[7] *= 0.997
            c[9] *= 0.997
            c[10] += 3.0 * dt
            // Fade after 2s
            if c[11] > 2.0
                fade = 255 - floor((c[11] - 2.0) * 200)
                if fade < 0 fade = 0 ok
                c[15] = fade
            ok
            // Trail particles
            if c[11] < 2.5
                if GetRandomValue(1, 4) = 1
                    ca3_spawnParticles(c[4], c[5], c[6], 1)
                ok
            ok
            if c[11] > 3.5
                add(toRemove, i)
            ok
        ok

        cards[i] = c
    next

    for i = len(toRemove) to 1 step -1
        del(cards, toRemove[i])
    next

// =============================================================
// Particles
// =============================================================

func ca3_spawnParticles cx, cy, cz, count
    for i = 1 to count
        pvx = (GetRandomValue(-100, 100) / 100.0) * 2.0
        pvy = (GetRandomValue(100, 400) / 100.0)
        pvz = (GetRandomValue(-100, 100) / 100.0) * 2.0
        cr = GetRandomValue(180, 255)
        cg = GetRandomValue(150, 255)
        cb = GetRandomValue(50, 150)
        add(particles, [cx, cy, cz, pvx, pvy, pvz, 1.2, cr, cg, cb])
        //               1   2   3   4    5    6    7    8   9   10
    next

func ca3_updateParticles dt
    i = 1
    while i <= len(particles)
        p = particles[i]
        p[1] += p[4] * dt
        p[2] += p[5] * dt
        p[3] += p[6] * dt
        p[5] -= 8.0 * dt   // gravity
        p[7] -= dt          // lifetime
        if p[7] <= 0
            del(particles, i)
        else
            particles[i] = p
            i++
        ok
    end

// =============================================================
// Draw 3D Scene
// =============================================================

func ca3_draw3D
    // Ground grid
    DrawPlane(Vector3(0, -0.05, 0), Vector2(ARENA_SIZE + 2, ARENA_SIZE + 2), RAYLIBColor(25, 30, 50, 255))

    // Grid lines on floor
    gridCol = RAYLIBColor(40, 50, 80, 255)
    for g = -6 to 6
        gf = g * 1.0
        DrawLine3D(Vector3(gf, 0.0, -ARENA_HALF - 1), Vector3(gf, 0.0, ARENA_HALF + 1), gridCol)
        DrawLine3D(Vector3(-ARENA_HALF - 1, 0.0, gf), Vector3(ARENA_HALF + 1, 0.0, gf), gridCol)
    next

    // Arena boundary pillars (corners)
    pillarCol = RAYLIBColor(60, 70, 110, 200)
    DrawCube(Vector3(-ARENA_HALF, 3.0, -ARENA_HALF), 0.2, 6.0, 0.2, pillarCol)
    DrawCube(Vector3( ARENA_HALF, 3.0, -ARENA_HALF), 0.2, 6.0, 0.2, pillarCol)
    DrawCube(Vector3(-ARENA_HALF, 3.0,  ARENA_HALF), 0.2, 6.0, 0.2, pillarCol)
    DrawCube(Vector3( ARENA_HALF, 3.0,  ARENA_HALF), 0.2, 6.0, 0.2, pillarCol)

    // Draw orbit trails
    for i = 1 to len(cards)
        c = cards[i]
        if c[3] = ANIM_ORBIT
            radius = c[13]
            cy = c[5]
            trailCol = RAYLIBColor(100, 150, 255, 60)
            DrawCircle3D(Vector3(0, cy, 0), radius, Vector3(1, 0, 0), 90.0, trailCol)
        ok
    next

    // Draw animated cards
    for i = 1 to len(cards)
        ca3_drawCard3D(cards[i])
    next

    // Draw particles
    for i = 1 to len(particles)
        p = particles[i]
        alphaP = floor((p[7] / 1.2) * 255)
        if alphaP > 255 alphaP = 255 ok
        if alphaP < 0 alphaP = 0 ok
        sz = 0.04 + p[7] * 0.05
        DrawSphere(Vector3(p[1], p[2], p[3]), sz, RAYLIBColor(p[8], p[9], p[10], alphaP))
    next

// =============================================================
// Draw Single 3D Card
// =============================================================

func ca3_drawCard3D c
    rank = c[1]
    suit = c[2]
    aType = c[3]
    px = c[4]
    py = c[5]
    pz = c[6]
    rotY = c[10]
    alpha = c[15]

    if alpha < 10 return ok

    // Card body - white face
    if suit = SUIT_HEART or suit = SUIT_DIAMOND
        topCol = RAYLIBColor(220, 60, 60, alpha)
    else
        topCol = RAYLIBColor(50, 50, 70, alpha)
    ok

    cardCol = RAYLIBColor(240, 240, 235, alpha)
    wireCol = RAYLIBColor(100, 100, 100, alpha)

    DrawCube(Vector3(px, py, pz), CARD3D_W, CARD3D_H, CARD3D_D, cardCol)
    DrawCubeWires(Vector3(px, py, pz), CARD3D_W, CARD3D_H, CARD3D_D, wireCol)

    // Colored top strip
    DrawCube(Vector3(px, py + CARD3D_H / 2 + 0.005, pz), CARD3D_W - 0.05, 0.01, CARD3D_D - 0.05, topCol)

    // Shadow on floor
    if py > 0.2
        shadowAlpha = floor(alpha * 0.3 * (1.0 - py / 15.0))
        if shadowAlpha < 0 shadowAlpha = 0 ok
        if shadowAlpha > 80 shadowAlpha = 80 ok
        DrawCube(Vector3(px, 0.01, pz), CARD3D_W * 0.9, 0.01, CARD3D_D * 0.9, RAYLIBColor(0, 0, 0, shadowAlpha))
    ok

    // Animation-specific decorations
    if aType = ANIM_FIREWORK
        glow = floor(fabs(sin(animTime * 8.0)) * 40) + 30
        DrawCubeWires(Vector3(px, py, pz), CARD3D_W + 0.1, CARD3D_H + 0.1, CARD3D_D + 0.1, RAYLIBColor(255, 215, 0, glow))
    ok
    if aType = ANIM_ORBIT
        DrawCubeWires(Vector3(px, py, pz), CARD3D_W + 0.08, CARD3D_H + 0.08, CARD3D_D + 0.08, RAYLIBColor(100, 180, 255, 50))
    ok
    if aType = ANIM_BOUNCE
        if py < 0.6
            // Impact glow near floor
            impactGlow = floor((1.0 - py / 0.6) * 60)
            DrawSphere(Vector3(px, 0.05, pz), 0.5, RAYLIBColor(255, 200, 100, impactGlow))
        ok
    ok
    if aType = ANIM_SPIN
        glow = floor(fabs(sin(c[10] * 2.0)) * 40) + 20
        DrawCubeWires(Vector3(px, py, pz), CARD3D_W + 0.12, CARD3D_H + 0.12, CARD3D_D + 0.12, RAYLIBColor(180, 255, 180, glow))
    ok

// =============================================================
// 3D to 2D Projection (for card labels)
// =============================================================

func ca3_projectToScreen wx, wy, wz
    fwdX = projCamTgtX - projCamPosX
    fwdY = projCamTgtY - projCamPosY
    fwdZ = projCamTgtZ - projCamPosZ
    fLen = sqrt(fwdX*fwdX + fwdY*fwdY + fwdZ*fwdZ)
    if fLen < 0.0001 return [-9999, -9999] ok
    fwdX /= fLen   fwdY /= fLen   fwdZ /= fLen

    upX = 0   upY = 1   upZ = 0
    rX = fwdY * upZ - fwdZ * upY
    rY = fwdZ * upX - fwdX * upZ
    rZ = fwdX * upY - fwdY * upX
    rLen = sqrt(rX*rX + rY*rY + rZ*rZ)
    if rLen < 0.0001 return [-9999, -9999] ok
    rX /= rLen   rY /= rLen   rZ /= rLen

    uX = rY * fwdZ - rZ * fwdY
    uY = rZ * fwdX - rX * fwdZ
    uZ = rX * fwdY - rY * fwdX

    dx = wx - projCamPosX
    dy = wy - projCamPosY
    dz = wz - projCamPosZ

    camZ = dx * fwdX + dy * fwdY + dz * fwdZ
    if camZ < 0.1 return [-9999, -9999] ok
    camX = dx * rX + dy * rY + dz * rZ
    camY = dx * uX + dy * uY + dz * uZ

    fov = 45.0
    aspect = SCREEN_W / SCREEN_H
    tanHalf = tan((fov / 2.0) * 3.14159 / 180.0)

    ndcX = camX / (camZ * tanHalf * aspect)
    ndcY = camY / (camZ * tanHalf)

    scrX = (ndcX + 1.0) * SCREEN_W / 2.0
    scrY = (1.0 - ndcY) * SCREEN_H / 2.0

    return [scrX, scrY]

// =============================================================
// Draw HUD (2D overlay)
// =============================================================

func ca3_drawHUD
    // Card labels (projected from 3D)
    for i = 1 to len(cards)
        c = cards[i]
        if c[15] < 30 loop ok
        pos = ca3_projectToScreen(c[4], c[5] + CARD3D_H + 0.3, c[6])
        sx = pos[1]  sy = pos[2]
        if sx < -200 or sx > SCREEN_W + 200 loop ok
        if sy < -100 or sy > SCREEN_H + 100 loop ok

        rName = rankNames[c[1]]
        sName = suitSyms[c[2]]
        label = rName + sName
        fontSize = 14
        lw = MeasureText(label, fontSize)

        // Background pill
        DrawRectangle(floor(sx) - lw/2 - 4, floor(sy) - 2, lw + 8, fontSize + 4, RAYLIBColor(0, 0, 0, 150))

        if c[2] = SUIT_HEART or c[2] = SUIT_DIAMOND
            txtCol = RAYLIBColor(255, 100, 100, 220)
        else
            txtCol = RAYLIBColor(220, 220, 240, 220)
        ok
        DrawText(label, floor(sx) - lw/2, floor(sy), fontSize, txtCol)
    next

    // Title bar
    DrawRectangle(0, 0, SCREEN_W, 30, RAYLIBColor(0, 0, 0, 180))
    DrawText("3D Cards Animation", 10, 6, 18, RAYLIBColor(255, 215, 0, 220))

    cardsTxt = "Cards: " + string(len(cards))
    cw = MeasureText(cardsTxt, 16)
    DrawText(cardsTxt, SCREEN_W - cw - 14, 8, 16, RAYLIBColor(200, 200, 220, 200))

    DrawText("1-8: Animations | A: Add | P: Pause | C: Clear | V: Camera", 210, 8, 14, RAYLIBColor(160, 170, 190, 180))

    // Camera mode
    camTxt = "Cam: " + camModeNames[cameraMode]
    DrawText(camTxt, SCREEN_W - 110, 36, 14, RAYLIBColor(180, 200, 220, 180))

    // Paused overlay
    if paused
        DrawRectangle(0, 30, SCREEN_W, SCREEN_H - 85, RAYLIBColor(0, 0, 0, 80))
        ptxt = "PAUSED"
        pw = MeasureText(ptxt, 60)
        DrawText(ptxt, (SCREEN_W - pw) / 2 + 2, SCREEN_H / 2 - 58, 60, RAYLIBColor(0, 0, 0, 120))
        DrawText(ptxt, (SCREEN_W - pw) / 2, SCREEN_H / 2 - 60, 60, RAYLIBColor(255, 215, 0, 220))
    ok

    // Toolbar
    ca3_drawToolbar()

    // FPS
    fpsTxt = "" + string(GetFPS()) + " FPS"
    DrawText(fpsTxt, SCREEN_W - 70, SCREEN_H - 15, 14, RAYLIBColor(100, 255, 100, 180))

// =============================================================
// Toolbar
// =============================================================

func ca3_drawToolbar
    DrawRectangle(0, SCREEN_H - 55, SCREEN_W, 55, RAYLIBColor(20, 20, 35, 240))
    DrawRectangle(0, SCREEN_H - 55, SCREEN_W, 2, RAYLIBColor(80, 80, 120, 200))

    mx = GetMouseX()
    my = GetMouseY()
    hoverBtn = 0

    bx = BTN_GAP
    bx = ca3_drawBtn("Add [A]", bx, 1, RAYLIBColor(40, 130, 70, 255), mx, my)
    bx += BTN_GAP

    if paused
        bx = ca3_drawBtn("Resume [P]", bx, 2, RAYLIBColor(200, 140, 30, 255), mx, my)
    else
        bx = ca3_drawBtn("Pause [P]", bx, 2, RAYLIBColor(180, 120, 20, 255), mx, my)
    ok
    bx += BTN_GAP

    bx = ca3_drawBtn("Clear [C]", bx, 3, RAYLIBColor(170, 40, 40, 255), mx, my)
    bx += BTN_GAP

    bx = ca3_drawBtn("Camera [V]", bx, 4, RAYLIBColor(80, 80, 150, 255), mx, my)
    bx += BTN_GAP * 3

    DrawRectangle(bx - BTN_GAP, BTN_Y + 4, 2, BTN_H - 8, RAYLIBColor(80, 80, 120, 150))

    btnColors = [
        RAYLIBColor(60, 100, 160, 255),
        RAYLIBColor(130, 60, 150, 255),
        RAYLIBColor(40, 140, 140, 255),
        RAYLIBColor(160, 100, 40, 255),
        RAYLIBColor(50, 130, 80, 255),
        RAYLIBColor(140, 70, 70, 255),
        RAYLIBColor(60, 80, 160, 255),
        RAYLIBColor(160, 50, 100, 255)
    ]

    for i = 1 to ANIM_COUNT
        label = "" + string(i) + ":" + animNames[i]
        bx = ca3_drawBtn(label, bx, 10 + i, btnColors[i], mx, my)
        bx += 4
    next

func ca3_drawBtn label, bx, btnId, baseCol, mx, my
    tw = MeasureText(label, 14) + 18
    if tw < 60 tw = 60 ok

    isHover = (mx >= bx and mx <= bx + tw and my >= BTN_Y and my <= BTN_Y + BTN_H)

    if isHover
        hoverBtn = btnId
        DrawRectangle(bx, BTN_Y, tw, BTN_H, RAYLIBColor(255, 225, 100, 240))
        DrawRectangleLines(bx, BTN_Y, tw, BTN_H, RAYLIBColor(200, 180, 60, 255))
        lw = MeasureText(label, 14)
        DrawText(label, bx + (tw - lw) / 2, BTN_Y + 12, 14, RAYLIBColor(20, 15, 10, 255))
    else
        DrawRectangle(bx, BTN_Y, tw, BTN_H, baseCol)
        DrawRectangleLines(bx, BTN_Y, tw, BTN_H, RAYLIBColor(255, 255, 255, 40))
        lw = MeasureText(label, 14)
        DrawText(label, bx + (tw - lw) / 2, BTN_Y + 12, 14, WHITE)
    ok

    return bx + tw

// =============================================================
// Handle Click
// =============================================================

func ca3_handleClick mx, my
    if hoverBtn = 1
        ca3_addRandomCard()
        return
    ok
    if hoverBtn = 2
        paused = !paused
        return
    ok
    if hoverBtn = 3
        cards = []
        particles = []
        return
    ok
    if hoverBtn = 4
        cameraMode++
        if cameraMode > CAM_COUNT cameraMode = CAM_FRONT ok
        return
    ok
    if hoverBtn >= 11 and hoverBtn <= 10 + ANIM_COUNT
        ca3_addCard(hoverBtn - 10)
        return
    ok
