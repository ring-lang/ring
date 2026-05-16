/*
**  Voxel Terrain Explorer - Using RingRayLib
**  =============================================
**  Minecraft-style block world with procedural terrain,
**  block building/breaking, day-night cycle, and water.
**
**  OPTIMIZATIONS applied (inspired by ex5_wavingcubes_withoutthreads2.ring):
**
**  1. Pre-computed RAYLIBColor table (lightTable):
**       Just like ex5v2 pre-builds `colors[]` before the loop to avoid
**       calling ColorFromHSV every frame, here we pre-build a 2D table
**       [blockType][lightLevel] of ready-made RAYLIBColor objects.
**       lightMul is quantized to NUM_LIGHT_LEVELS buckets (16 steps),
**       so the draw loop never calls RAYLIBColor() or does float math.
**
**  2. DrawCube_2 + Vec3/Vec3Set instead of DrawCube + Vector3():
**       Vector3(x,y,z) allocates a new Ring object on every call.
**       Vec3() allocates once; Vec3Set() mutates the C pointer in place.
**       DrawCube_2 accepts the C pointer directly — same trick that
**       takes ex5 from 190 FPS to 260 FPS.
**
**  3. Water color pre-computed outside inner loop:
**       wc (water RAYLIBColor) is built once per frame, not per block.
**       (Was already done but now uses Vec3Set too.)
**
**  4. lightMul quantized to integer index (0..NUM_LIGHT_LEVELS-1):
**       Replaces per-block float multiply + 3x floor() with a single
**       integer index lookup into the pre-built color table.
**
**  Controls:
**    W/A/S/D            -  Move forward/left/back/right
**    SPACE              -  Jump / Fly up
**    X                  -  Fly down
**    Mouse Move         -  Look around
**    Left Click         -  Break block
**    Right Click        -  Place block
**    1-6                -  Select block type
**    F                  -  Toggle fly mode
**    T                  -  Cycle time speed
**    P                  -  Pause
**    R                  -  Regenerate world
**    ESC                -  Exit
*/

load "raylib.ring"

SCREEN_W    = 1024
SCREEN_H    = 768
WORLD_W     = 48
WORLD_D     = 48
WORLD_H     = 32
SEA_LEVEL   = 12
TERRAIN_BASE = 8
TERRAIN_AMP  = 14
WxD = WORLD_W * WORLD_D

BL_AIR      = 0
BL_GRASS    = 1
BL_DIRT     = 2
BL_STONE    = 3
BL_WOOD     = 4
BL_LEAF     = 5
BL_SAND     = 6
BL_WATER    = 7
BL_BEDROCK  = 8
BL_SNOW     = 9

PL_EYEOFF   = 1.5
PL_RAD      = 0.3
PL_SPEED    = 6.0
PL_JUMP     = 8.0
PL_GRAV     = 20.0
FLY_SPEED   = 12.0
MOUSE_SENS  = 0.003

ST_TITLE    = 1
ST_PLAY     = 2
ST_PAUSE    = 3

DAY_LENGTH  = 120.0
REACH_DIST  = 5.5
RENDER_DIST = 16
RD_SQ       = RENDER_DIST * RENDER_DIST

// ---------------------------------------------------------------
// Pre-computed block base colors [R,G,B] by block type
// ---------------------------------------------------------------
blkColors = list(9)
blkColors[1] = [80, 160, 60]
blkColors[2] = [140, 100, 60]
blkColors[3] = [130, 130, 130]
blkColors[4] = [120, 80, 40]
blkColors[5] = [50, 140, 40]
blkColors[6] = [210, 200, 130]
blkColors[7] = [40, 100, 200]
blkColors[8] = [50, 50, 55]
blkColors[9] = [230, 235, 240]

// ---------------------------------------------------------------
// Light level quantization  (same idea as ex5v2 color pre-build)
// lightMul ranges ~0.4 .. 1.0  => quantize to NUM_LIGHT_LEVELS buckets
// lightTable[blockType][lightLevel] = pre-built RAYLIBColor object
// ---------------------------------------------------------------
NUM_LIGHT_LEVELS = 16
LIGHT_MIN = 0.4
LIGHT_MAX = 1.0
LIGHT_RANGE = LIGHT_MAX - LIGHT_MIN   // 0.6

lightTable = list(9)
for bt = 1 to 9
    lightTable[bt] = list(NUM_LIGHT_LEVELS)
    bc = blkColors[bt]
    for li = 1 to NUM_LIGHT_LEVELS
        lm = LIGHT_MIN + (li - 1) / (NUM_LIGHT_LEVELS - 1) * LIGHT_RANGE
        cr = floor(bc[1] * lm)
        cg = floor(bc[2] * lm)
        cb = floor(bc[3] * lm)
        if cr > 255 cr = 255 ok
        if cg > 255 cg = 255 ok
        if cb > 255 cb = 255 ok
        lightTable[bt][li] = RAYLIBColor(cr, cg, cb, 255)
    next
next

// Pre-compute water color table too (2 levels: day / night)
waterColors = list(NUM_LIGHT_LEVELS)
for li = 1 to NUM_LIGHT_LEVELS
    lm = LIGHT_MIN + (li - 1) / (NUM_LIGHT_LEVELS - 1) * LIGHT_RANGE
    wr = floor(40 * lm)
    wg = floor(100 * lm)
    wb = floor(200 * lm)
    waterColors[li] = RAYLIBColor(wr, wg, wb, 140)
next

// Reusable C-pointer Vec3 objects (avoids Ring object allocation per cube)
cubePos  = Vec3()
waterPos = Vec3()
partPos  = Vec3()

// Noise permutation table
perm = list(512)
for i = 1 to 256
    perm[i] = i - 1
next
for i = 256 to 2 step -1
    j = (GetRandomValue(1, 32000) % i) + 1
    tmp = perm[i]
    perm[i] = perm[j]
    perm[j] = tmp
next
for i = 1 to 256
    perm[256 + i] = perm[i]
next

gameState   = ST_TITLE
animTime    = 0.0
dt          = 0.0

worldSize = WORLD_W * WORLD_D * WORLD_H
world = list(worldSize)
for i = 1 to worldSize
    world[i] = BL_AIR
next

// Surface-only visible list: [x, y, z, blockType] per entry
visList = []
visCount = 0
visDirty = true

// Water surface list: [x, y, z]
waterList = []
waterCount = 0

plX = 24.0
plY = 20.0
plZ = 24.0
plVX = 0.0
plVY = 0.0
plVZ = 0.0
plYaw   = 0.0
plPitch = 0.0
plOnGround = false
flyMode = false
selBlock = BL_GRASS

camera = Camera3D(0, 20, 0, 0, 20, -1, 0, 1, 0, 70, CAMERA_PERSPECTIVE)

dayTime   = 30.0
timeSpeed = 1
timeSpeeds = [0, 1, 5, 20]
timeSpeedIdx = 2

partList = []
blockNames = ["", "Grass", "Dirt", "Stone", "Wood", "Leaves", "Sand", "Water", "Bedrock", "Snow"]

hitBX = -1
hitBY = -1
hitBZ = -1
hitNX = 0
hitNY = 0
hitNZ = 0
hitFound = false

bcR = 0
bcG = 0
bcB = 0

blocksPlaced  = 0
blocksBroken  = 0

lastMouseX = SCREEN_W / 2
lastMouseY = SCREEN_H / 2
mouseActive = false

heightMap = list(WORLD_W * WORLD_D)
for i = 1 to WORLD_W * WORLD_D
    heightMap[i] = 0
next

// =============================================================
// Main
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Voxel Terrain Explorer - RingRayLib (Fast)")
SetTargetFPS(60)
vox_generateWorld()

while !WindowShouldClose()
    dt = GetFrameTime()
    if dt > 0.05 dt = 0.05 ok
    animTime += dt

    if gameState = ST_TITLE
        if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
            gameState = ST_PLAY
            lastMouseX = GetMouseX()
            lastMouseY = GetMouseY()
            mouseActive = true
        ok
    but gameState = ST_PLAY
        if IsKeyPressed(KEY_P)
            gameState = ST_PAUSE
            mouseActive = false
        ok
        if IsKeyPressed(KEY_R) vox_generateWorld() ok
        if IsKeyPressed(KEY_T)
            timeSpeedIdx += 1
            if timeSpeedIdx > 4 timeSpeedIdx = 1 ok
            timeSpeed = timeSpeeds[timeSpeedIdx]
        ok
        if IsKeyPressed(KEY_ONE)   selBlock = BL_GRASS ok
        if IsKeyPressed(KEY_TWO)   selBlock = BL_DIRT ok
        if IsKeyPressed(KEY_THREE) selBlock = BL_STONE ok
        if IsKeyPressed(KEY_FOUR)  selBlock = BL_WOOD ok
        if IsKeyPressed(KEY_FIVE)  selBlock = BL_LEAF ok
        if IsKeyPressed(KEY_SIX)   selBlock = BL_SAND ok
        if IsKeyPressed(KEY_F) flyMode = !flyMode ok

        vox_handleMouse()
        vox_updatePlayer()
        dayTime += dt * timeSpeed
        if dayTime > DAY_LENGTH dayTime -= DAY_LENGTH ok
        vox_raycast()

        if IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)
            vox_placeBlock()
        but IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
            vox_breakBlock()
        ok
        if visDirty vox_rebuildVisList() ok
        vox_updateParts()
        vox_updateCamera()
    but gameState = ST_PAUSE
        if IsKeyPressed(KEY_P) or IsKeyPressed(KEY_SPACE)
            gameState = ST_PLAY
            lastMouseX = GetMouseX()
            lastMouseY = GetMouseY()
            mouseActive = true
        ok
    ok

    BeginDrawing()
        vox_drawSky()
        if gameState = ST_TITLE
            vox_drawTitle()
        ok
        if gameState = ST_PLAY or gameState = ST_PAUSE
            BeginMode3D(camera)
                vox_drawWorld()
                vox_drawWater()
                vox_drawHighlight()
                vox_drawParts3D()
            EndMode3D()
            vox_drawHUD()
            if gameState = ST_PAUSE vox_drawPauseOverlay() ok
        ok
        DrawFPS(10, 10)
    EndDrawing()
end

CloseWindow()

// =============================================================
// Noise
// =============================================================

func vox_fade t
    return t * t * t * (t * (t * 6 - 15) + 10)

func vox_noise2d nx, nz
    xi = floor(nx) % 256
    zi = floor(nz) % 256
    if xi < 0 xi += 256 ok
    if zi < 0 zi += 256 ok
    xf = nx - floor(nx)
    zf = nz - floor(nz)
    u = vox_fade(xf)
    v = vox_fade(zf)
    aa = perm[perm[xi + 1] + zi + 1]
    ab = perm[perm[xi + 1] + zi + 2]
    ba = perm[perm[xi + 2] + zi + 1]
    bb = perm[perm[xi + 2] + zi + 2]
    x1 = aa / 256.0 + u * (ba / 256.0 - aa / 256.0)
    x2 = ab / 256.0 + u * (bb / 256.0 - ab / 256.0)
    return x1 + v * (x2 - x1)

func vox_fbm x, z, octaves, freq, amp
    total = 0.0
    f = freq
    a = amp
    maxVal = 0.0
    for o = 1 to octaves
        total += vox_noise2d(x * f, z * f) * a
        maxVal += a
        f = f * 2.0
        a = a * 0.5
    next
    return total / maxVal

// =============================================================
// World Generation
// =============================================================

func vox_generateWorld
    for i = 1 to worldSize
        world[i] = BL_AIR
    next
    for i = 256 to 2 step -1
        j = (GetRandomValue(1, 32000) % i) + 1
        tmp = perm[i]
        perm[i] = perm[j]
        perm[j] = tmp
    next
    for i = 1 to 256
        perm[256 + i] = perm[i]
    next

    ww = WORLD_W
    wd = WORLD_D
    wh = WORLD_H
    sl = SEA_LEVEL
    tb = TERRAIN_BASE
    ta = TERRAIN_AMP
    wxd = WxD

    for x = 0 to ww - 1
        for z = 0 to wd - 1
            n = vox_fbm(x, z, 4, 0.04, 1.0)
            height = floor(tb + n * ta)
            if height < 1 height = 1 ok
            if height >= wh height = wh - 1 ok
            biome = vox_fbm(x + 100, z + 100, 2, 0.02, 1.0)
            heightMap[x + z * ww + 1] = height
            baseIdx = x + z * ww + 1
            for y = 0 to height
                idx = baseIdx + y * wxd
                if y = 0
                    world[idx] = BL_BEDROCK
                but y < height - 3
                    world[idx] = BL_STONE
                but y < height
                    if height <= sl + 1 and biome > 0.4
                        world[idx] = BL_SAND
                    else
                        world[idx] = BL_DIRT
                    ok
                but y = height
                    if height <= sl + 1 and biome > 0.4
                        world[idx] = BL_SAND
                    but height > tb + ta - 3
                        world[idx] = BL_SNOW
                    else
                        world[idx] = BL_GRASS
                    ok
                ok
            next
            for y = height + 1 to sl
                idx = baseIdx + y * wxd
                if world[idx] = BL_AIR
                    world[idx] = BL_WATER
                ok
            next
        next
    next

    for t = 1 to 40
        tx = GetRandomValue(3, ww - 4)
        tz = GetRandomValue(3, wd - 4)
        th = heightMap[tx + tz * ww + 1]
        if th > sl and th < wh - 7
            tsb = world[tx + tz * ww + th * wxd + 1]
            if tsb = BL_GRASS
                vox_plantTree(tx, th, tz)
            ok
        ok
    next

    cx = floor(ww / 2)
    cz = floor(wd / 2)
    ch = heightMap[cx + cz * ww + 1]
    plX = cx + 0.5
    plY = ch + 1 + PL_EYEOFF - 0.05
    plZ = cz + 0.5
    plVX = 0.0
    plVY = 0.0
    plVZ = 0.0
    plOnGround = false
    blocksPlaced = 0
    blocksBroken = 0
    partList = []
    visDirty = true

func vox_plantTree tx, ty, tz
    trunkH = GetRandomValue(4, 6)
    ww = WORLD_W
    wxd = WxD
    wh = WORLD_H
    for h = 1 to trunkH
        yy = ty + h
        if yy < wh
            world[tx + tz * ww + yy * wxd + 1] = BL_WOOD
        ok
    next
    topY = ty + trunkH
    for ly = topY - 1 to topY + 2
        rad = 2
        if ly = topY + 2 rad = 1 ok
        if ly = topY - 1 rad = 1 ok
        for lx = tx - rad to tx + rad
            for lz = tz - rad to tz + rad
                dist = (lx-tx)*(lx-tx) + (lz-tz)*(lz-tz) + (ly-topY)*(ly-topY)
                if dist <= rad * rad + 1
                    if lx >= 0 and lx < ww and lz >= 0 and lz < WORLD_D and ly >= 0 and ly < wh
                        idx = lx + lz * ww + ly * wxd + 1
                        if world[idx] = BL_AIR
                            world[idx] = BL_LEAF
                        ok
                    ok
                ok
            next
        next
    next

// =============================================================
// Rebuild Visible Surface List (called only on world change)
// =============================================================

func vox_rebuildVisList
    visList = []
    waterList = []
    ww = WORLD_W
    wd = WORLD_D
    wh = WORLD_H
    wxd = WxD
    sl = SEA_LEVEL

    for x = 0 to ww - 1
        for z = 0 to wd - 1
            baseIdx = x + z * ww + 1
            for y = 0 to wh - 1
                idx = baseIdx + y * wxd
                bl = world[idx]
                if bl = BL_AIR loop ok

                if bl = BL_WATER
                    if y >= sl
                        add(waterList, [x, y, z])
                    but y + 1 < wh
                        if world[idx + wxd] = BL_AIR
                            add(waterList, [x, y, z])
                        ok
                    ok
                    loop
                ok

                // Inline face exposure check
                exposed = false
                if x = 0
                    exposed = true
                else
                    nb = world[idx - 1]
                    if nb = BL_AIR or nb = BL_WATER exposed = true ok
                ok
                if !exposed
                    if x = ww - 1
                        exposed = true
                    else
                        nb = world[idx + 1]
                        if nb = BL_AIR or nb = BL_WATER exposed = true ok
                    ok
                ok
                if !exposed
                    if z = 0
                        exposed = true
                    else
                        nb = world[idx - ww]
                        if nb = BL_AIR or nb = BL_WATER exposed = true ok
                    ok
                ok
                if !exposed
                    if z = wd - 1
                        exposed = true
                    else
                        nb = world[idx + ww]
                        if nb = BL_AIR or nb = BL_WATER exposed = true ok
                    ok
                ok
                if !exposed
                    if y = 0
                        exposed = true
                    else
                        nb = world[idx - wxd]
                        if nb = BL_AIR or nb = BL_WATER exposed = true ok
                    ok
                ok
                if !exposed
                    if y = wh - 1
                        exposed = true
                    else
                        nb = world[idx + wxd]
                        if nb = BL_AIR or nb = BL_WATER exposed = true ok
                    ok
                ok
                if exposed
                    add(visList, [x, y, z, bl])
                ok
            next
        next
    next
    visCount = len(visList)
    waterCount = len(waterList)
    visDirty = false

// =============================================================
// Player
// =============================================================

func vox_handleMouse
    if !mouseActive return ok
    mcx = GetMouseX()
    mcy = GetMouseY()
    mdx = mcx - lastMouseX
    mdy = mcy - lastMouseY
    lastMouseX = mcx
    lastMouseY = mcy
    plYaw   += mdx * MOUSE_SENS
    plPitch -= mdy * MOUSE_SENS
    if plPitch > 1.4 plPitch = 1.4 ok
    if plPitch < -1.4 plPitch = -1.4 ok

func vox_updatePlayer
    fwdX = sin(plYaw)
    fwdZ = -cos(plYaw)
    rightX = cos(plYaw)
    rightZ = sin(plYaw)
    moveX = 0.0
    moveZ = 0.0
    if IsKeyDown(KEY_W) or IsKeyDown(KEY_UP)
        moveX += fwdX
        moveZ += fwdZ
    ok
    if IsKeyDown(KEY_S) or IsKeyDown(KEY_DOWN)
        moveX -= fwdX
        moveZ -= fwdZ
    ok
    if IsKeyDown(KEY_A) or IsKeyDown(KEY_LEFT)
        moveX -= rightX
        moveZ -= rightZ
    ok
    if IsKeyDown(KEY_D) or IsKeyDown(KEY_RIGHT)
        moveX += rightX
        moveZ += rightZ
    ok
    mLen = sqrt(moveX * moveX + moveZ * moveZ)
    if mLen > 0.001
        moveX = moveX / mLen
        moveZ = moveZ / mLen
    ok
    spd = PL_SPEED
    if flyMode spd = FLY_SPEED ok
    plVX = moveX * spd
    plVZ = moveZ * spd
    if flyMode
        plVY = 0.0
        if IsKeyDown(KEY_SPACE) plVY = FLY_SPEED ok
        if IsKeyDown(KEY_X) plVY = -FLY_SPEED ok
    else
        plVY -= PL_GRAV * dt
        if IsKeyPressed(KEY_SPACE) and plOnGround
            plVY = PL_JUMP
            plOnGround = false
        ok
    ok
    newX = plX + plVX * dt
    newY = plY + plVY * dt
    newZ = plZ + plVZ * dt
    if vox_collidesAt(newX, plY, plZ)
        newX = plX
        plVX = 0.0
    ok
    if vox_collidesAt(newX, plY, newZ)
        newZ = plZ
        plVZ = 0.0
    ok
    plOnGround = false
    if vox_collidesAt(newX, newY, newZ)
        if plVY < 0
            footBlock = floor(newY - PL_EYEOFF + 0.05)
            newY = footBlock + 1 + PL_EYEOFF - 0.05
            plOnGround = true
        else
            newY = plY
        ok
        plVY = 0.0
    ok
    plX = newX
    plY = newY
    plZ = newZ
    if plX < 0.5 plX = 0.5 ok
    if plX > WORLD_W - 0.5 plX = WORLD_W - 0.5 ok
    if plZ < 0.5 plZ = 0.5 ok
    if plZ > WORLD_D - 0.5 plZ = WORLD_D - 0.5 ok
    if plY < 1.0 plY = 1.0 ok
    if plY > WORLD_H + 5 plY = WORLD_H + 5 ok

func vox_collidesAt px, py, pz
    r = PL_RAD
    footY = py - PL_EYEOFF + 0.05
    headY = py + 0.1
    bx1 = floor(px - r)
    bx2 = floor(px + r)
    bz1 = floor(pz - r)
    bz2 = floor(pz + r)
    by1 = floor(footY)
    by2 = floor(headY)
    ww = WORLD_W
    wd = WORLD_D
    wh = WORLD_H
    wxd = WxD
    for bx = bx1 to bx2
        for bz = bz1 to bz2
            for by = by1 to by2
                if bx >= 0 and bx < ww and bz >= 0 and bz < wd and by >= 0 and by < wh
                    b = world[bx + bz * ww + by * wxd + 1]
                    if b != BL_AIR and b != BL_WATER return true ok
                ok
            next
        next
    next
    return false

func vox_updateCamera
    dirX = cos(plPitch) * sin(plYaw)
    dirY = sin(plPitch)
    dirZ = -cos(plPitch) * cos(plYaw)
    camera.position.x = plX
    camera.position.y = plY
    camera.position.z = plZ
    camera.target.x = plX + dirX
    camera.target.y = plY + dirY
    camera.target.z = plZ + dirZ

// =============================================================
// Raycasting (inline)
// =============================================================

func vox_raycast
    dirX = cos(plPitch) * sin(plYaw)
    dirY = sin(plPitch)
    dirZ = -cos(plPitch) * cos(plYaw)
    hitFound = false
    rx = plX
    ry = plY
    rz = plZ
    stepSize = 0.08
    ww = WORLD_W
    wd = WORLD_D
    wh = WORLD_H
    wxd = WxD
    sdx = dirX * stepSize
    sdy = dirY * stepSize
    sdz = dirZ * stepSize
    maxSteps = floor(REACH_DIST / stepSize)

    lastAirX = floor(rx)
    lastAirY = floor(ry)
    lastAirZ = floor(rz)
    hadAir = false

    for i = 1 to maxSteps
        rx += sdx
        ry += sdy
        rz += sdz
        bx = floor(rx)
        by = floor(ry)
        bz = floor(rz)
        if bx >= 0 and bx < ww and by >= 0 and by < wh and bz >= 0 and bz < wd
            bl = world[bx + bz * ww + by * wxd + 1]
            if bl = BL_AIR or bl = BL_WATER
                lastAirX = bx
                lastAirY = by
                lastAirZ = bz
                hadAir = true
            else
                hitFound = true
                hitBX = bx
                hitBY = by
                hitBZ = bz
                if hadAir
                    hitNX = lastAirX - bx
                    hitNY = lastAirY - by
                    hitNZ = lastAirZ - bz
                else
                    hitNX = 0
                    hitNY = 1
                    hitNZ = 0
                ok
                return
            ok
        ok
    next

// =============================================================
// Block Interaction
// =============================================================

func vox_breakBlock
    if !hitFound return ok
    idx = hitBX + hitBZ * WORLD_W + hitBY * WxD + 1
    bl = world[idx]
    if bl = BL_BEDROCK return ok
    world[idx] = BL_AIR
    blocksBroken += 1
    visDirty = true
    if bl >= 1 and bl <= 9
        pr = blkColors[bl][1]
        pg = blkColors[bl][2]
        pb = blkColors[bl][3]
    else
        pr = 100
        pg = 100
        pb = 100
    ok
    for k = 1 to 8
        ppx = hitBX + 0.5 + (GetRandomValue(-40, 40) / 100.0)
        ppy = hitBY + 0.5 + (GetRandomValue(-40, 40) / 100.0)
        ppz = hitBZ + 0.5 + (GetRandomValue(-40, 40) / 100.0)
        pvx = (GetRandomValue(-100, 100) / 100.0) * 3.0
        pvy = (GetRandomValue(50, 200) / 100.0) * 2.0
        pvz = (GetRandomValue(-100, 100) / 100.0) * 3.0
        add(partList, [ppx, ppy, ppz, pvx, pvy, pvz, 0.8, pr, pg, pb])
    next

func vox_placeBlock
    if !hitFound return ok
    px = hitBX + hitNX
    py = hitBY + hitNY
    pz = hitBZ + hitNZ
    if px < 0 or px >= WORLD_W return ok
    if py < 0 or py >= WORLD_H return ok
    if pz < 0 or pz >= WORLD_D return ok
    if floor(plX) = px and floor(plZ) = pz
        footY = floor(plY - PL_EYEOFF + 0.1)
        headY = floor(plY + 0.1)
        if py >= footY and py <= headY return ok
    ok
    idx = px + pz * WORLD_W + py * WxD + 1
    b = world[idx]
    if b = BL_AIR or b = BL_WATER
        world[idx] = selBlock
        blocksPlaced += 1
        visDirty = true
    ok

// =============================================================
// Particles
// =============================================================

func vox_updateParts
    i = 1
    nParts = len(partList)
    while i <= nParts
        p = partList[i]
        p[1] += p[4] * dt
        p[2] += p[5] * dt
        p[3] += p[6] * dt
        p[5] -= 12.0 * dt
        p[7] -= dt
        if p[7] <= 0
            del(partList, i)
            nParts -= 1
        else
            partList[i] = p
            i += 1
        ok
    end

// =============================================================
// Drawing: Sky
// =============================================================

func vox_drawSky
    phase = dayTime / DAY_LENGTH
    if phase < 0.25
        t = phase / 0.25
        sr = floor(80 + t * 55)
        sg = floor(120 + t * 70)
        sb = floor(180 + t * 60)
    but phase < 0.5
        t = (phase - 0.25) / 0.25
        sr = floor(135 - t * 100)
        sg = floor(190 - t * 140)
        sb = floor(240 - t * 180)
    but phase < 0.75
        t = (phase - 0.5) / 0.25
        sr = floor(35 - t * 25)
        sg = floor(50 - t * 40)
        sb = floor(60 - t * 40)
    else
        t = (phase - 0.75) / 0.25
        sr = floor(10 + t * 70)
        sg = floor(10 + t * 110)
        sb = floor(20 + t * 160)
    ok
    if sr < 0 sr = 0 ok
    if sg < 0 sg = 0 ok
    if sb < 0 sb = 0 ok
    if sr > 255 sr = 255 ok
    if sg > 255 sg = 255 ok
    if sb > 255 sb = 255 ok
    ClearBackground(RAYLIBColor(sr, sg, sb, 255))

    if phase > 0.45 and phase < 0.85
        starAlpha = 0
        if phase < 0.55
            starAlpha = floor((phase - 0.45) / 0.10 * 200)
        but phase > 0.75
            starAlpha = floor((0.85 - phase) / 0.10 * 200)
        else
            starAlpha = 200
        ok
        if starAlpha > 255 starAlpha = 255 ok
        if starAlpha < 0 starAlpha = 0 ok
        sc = RAYLIBColor(255, 255, 220, starAlpha)
        for s = 1 to 40
            stx = (s * 137 + s * s * 31) % SCREEN_W
            sty = (s * 89 + s * s * 17) % (SCREEN_H / 2)
            DrawCircle(stx, sty, 1, sc)
        next
    ok

    sunAngle = phase * 6.28318 - 1.5708
    sunX = floor(SCREEN_W / 2 + cos(sunAngle) * 350)
    sunY = floor(SCREEN_H / 2 - sin(sunAngle) * 300)
    if phase < 0.5
        if sunY < SCREEN_H
            DrawCircle(sunX, sunY, 25, RAYLIBColor(255, 220, 80, 200))
            DrawCircle(sunX, sunY, 20, RAYLIBColor(255, 240, 150, 255))
        ok
    else
        moonX = floor(SCREEN_W / 2 + cos(sunAngle + 3.14159) * 350)
        moonY = floor(SCREEN_H / 2 - sin(sunAngle + 3.14159) * 300)
        if moonY < SCREEN_H
            DrawCircle(moonX, moonY, 18, RAYLIBColor(200, 210, 230, 180))
            DrawCircle(moonX, moonY, 15, RAYLIBColor(220, 225, 235, 220))
        ok
    ok

// =============================================================
// Drawing: World  -- KEY OPTIMIZATION
// Instead of: RAYLIBColor(floor(cc[i]*lightMul), ...) per block
// We: quantize lightMul -> li, look up lightTable[blockType][li]
//     and use DrawCube_2 + Vec3Set (no per-block object allocation)
// =============================================================

func vox_drawWorld
    phase = dayTime / DAY_LENGTH
    lightMul = 1.0
    if phase < 0.2
        lightMul = 0.5 + (phase / 0.2) * 0.5
    but phase < 0.4
        lightMul = 1.0
    but phase < 0.55
        lightMul = 1.0 - ((phase - 0.4) / 0.15) * 0.6
    but phase < 0.8
        lightMul = 0.4
    else
        lightMul = 0.4 + ((phase - 0.8) / 0.2) * 0.1
    ok

    // Quantize lightMul to table index (1..NUM_LIGHT_LEVELS)
    li = floor((lightMul - LIGHT_MIN) / LIGHT_RANGE * (NUM_LIGHT_LEVELS - 1) + 0.5) + 1
    if li < 1 li = 1 ok
    if li > NUM_LIGHT_LEVELS li = NUM_LIGHT_LEVELS ok

    pix = floor(plX)
    piz = floor(plZ)
    n = visCount
    lt = lightTable   // local ref avoids repeated global lookup

    for i = 1 to n
        v = visList[i]
        vx = v[1]
        vz = v[3]
        dx = vx - pix
        dz = vz - piz
        if dx * dx + dz * dz > RD_SQ loop ok

        vy = v[2]
        vbl = v[4]
        // Single table lookup — no multiply, no floor(), no RAYLIBColor() call
        Vec3Set(cubePos, vx + 0.5, vy + 0.5, vz + 0.5)
        DrawCube_2(cubePos, 1.0, 1.0, 1.0, lt[vbl][li])
    next

// =============================================================
// Drawing: Water  -- uses Vec3Set + pre-built waterColors table
// =============================================================

func vox_drawWater
    phase = dayTime / DAY_LENGTH
    lightMul = 1.0
    if phase > 0.4 and phase < 0.8 lightMul = 0.5 ok

    // Map lightMul -> water color table index
    li = floor((lightMul - LIGHT_MIN) / LIGHT_RANGE * (NUM_LIGHT_LEVELS - 1) + 0.5) + 1
    if li < 1 li = 1 ok
    if li > NUM_LIGHT_LEVELS li = NUM_LIGHT_LEVELS ok
    wc = waterColors[li]

    pix = floor(plX)
    piz = floor(plZ)
    at = animTime
    n = waterCount
    for i = 1 to n
        w = waterList[i]
        wx = w[1]
        wz = w[3]
        dx = wx - pix
        dz = wz - piz
        if dx * dx + dz * dz > RD_SQ loop ok
        wy = w[2]
        wave = sin(at * 2.0 + wx * 0.5 + wz * 0.3) * 0.05
        Vec3Set(waterPos, wx + 0.5, wy + 0.4 + wave, wz + 0.5)
        DrawCube_2(waterPos, 1.0, 0.8, 1.0, wc)
    next

func vox_drawHighlight
    if !hitFound return ok
    DrawCubeWires(Vector3(hitBX + 0.5, hitBY + 0.5, hitBZ + 0.5), 1.02, 1.02, 1.02, WHITE)

func vox_drawParts3D
    nP = len(partList)
    for i = 1 to nP
        p = partList[i]
        alpha = floor(p[7] / 0.8 * 255)
        if alpha > 255 alpha = 255 ok
        if alpha < 0 alpha = 0 ok
        sz = 0.08 + p[7] * 0.12
        Vec3Set(partPos, p[1], p[2], p[3])
        DrawCube_2(partPos, sz, sz, sz, RAYLIBColor(p[8], p[9], p[10], alpha))
    next

// =============================================================
// HUD
// =============================================================

func vox_drawHUD
    cx = SCREEN_W / 2
    cy = SCREEN_H / 2
    DrawLine(cx - 10, cy, cx - 3, cy, WHITE)
    DrawLine(cx + 3, cy, cx + 10, cy, WHITE)
    DrawLine(cx, cy - 10, cx, cy - 3, WHITE)
    DrawLine(cx, cy + 3, cx, cy + 10, WHITE)

    DrawRectangle(0, SCREEN_H - 50, SCREEN_W, 50, RAYLIBColor(0, 0, 0, 150))

    for i = 1 to 6
        bx = 20 + (i - 1) * 52
        by = SCREEN_H - 44
        isSelected = false
        if i = 1 and selBlock = BL_GRASS isSelected = true ok
        if i = 2 and selBlock = BL_DIRT isSelected = true ok
        if i = 3 and selBlock = BL_STONE isSelected = true ok
        if i = 4 and selBlock = BL_WOOD isSelected = true ok
        if i = 5 and selBlock = BL_LEAF isSelected = true ok
        if i = 6 and selBlock = BL_SAND isSelected = true ok
        if isSelected
            DrawRectangle(bx - 2, by - 2, 40, 40, WHITE)
        ok
        cc = blkColors[i]
        DrawRectangle(bx, by, 36, 36, RAYLIBColor(cc[1], cc[2], cc[3], 255))
        DrawText("" + i, bx + 2, by + 2, 10, RAYLIBColor(255, 255, 255, 200))
    next

    bnIdx = selBlock + 1
    DrawText(blockNames[bnIdx], 350, SCREEN_H - 38, 20, WHITE)

    psx = floor(plX)
    psy = floor(plY)
    psz = floor(plZ)
    pos = "[" + psx + ", " + psy + ", " + psz + "]"
    DrawText(pos, 350, SCREEN_H - 18, 14, RAYLIBColor(180, 200, 220, 200))

    hour = floor((dayTime / DAY_LENGTH) * 24)
    if hour >= 24 hour -= 24 ok
    minute = floor(((dayTime / DAY_LENGTH) * 24 - hour) * 60)
    timeStr = ""
    if hour < 10 timeStr = "0" ok
    timeStr += "" + hour + ":"
    if minute < 10 timeStr += "0" ok
    timeStr += "" + minute
    timeLabel = "Time: " + timeStr
    if timeSpeed = 0 timeLabel += " [FROZEN]" ok
    if timeSpeed > 1 timeLabel += " [x" + timeSpeed + "]" ok
    DrawText(timeLabel, SCREEN_W - 220, SCREEN_H - 38, 16, RAYLIBColor(255, 220, 100, 220))

    if flyMode
        DrawText("FLY MODE", SCREEN_W - 120, SCREEN_H - 18, 14, RAYLIBColor(100, 200, 255, 220))
    ok
    DrawText("Placed: " + blocksPlaced + "  Broken: " + blocksBroken, 550, SCREEN_H - 18, 12, RAYLIBColor(160, 180, 200, 180))
    DrawRectangle(0, 26, 230, 20, RAYLIBColor(0, 0, 0, 100))
    DrawText("F=Fly T=Time P=Pause R=Regen", 6, 28, 11, RAYLIBColor(150, 170, 200, 180))
    DrawText("Surfaces: " + visCount, SCREEN_W - 150, 10, 12, RAYLIBColor(180, 180, 180, 150))

// =============================================================
// Title Screen
// =============================================================

func vox_drawTitle
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 130))
    t1 = "VOXEL TERRAIN EXPLORER"
    t1w = MeasureText(t1, 48)
    DrawText(t1, (SCREEN_W - t1w)/2, 60, 48, RAYLIBColor(80, 200, 120, 255))
    t2 = "A Block World Adventure"
    t2w = MeasureText(t2, 20)
    DrawText(t2, (SCREEN_W - t2w)/2, 120, 20, RAYLIBColor(120, 200, 160, 220))

    cy = 170
    cLines = [
        "W/A/S/D  -  Move        Mouse  -  Look",
        "Left Click  -  Break    Right Click  -  Place",
        "SPACE  -  Jump/Fly up   X  -  Fly down",
        "1-6  -  Select block    F  -  Toggle fly",
        "T  -  Time speed        P  -  Pause",
        "R  -  Regenerate world",
        "",
        "Build, explore, and watch the day-night cycle!",
        "",
        "Block Types:",
        "  1=Grass  2=Dirt  3=Stone  4=Wood  5=Leaves  6=Sand",
        "",
        "Perlin noise terrain, trees, water, snow peaks,",
        "full day-night sky cycle with sun, moon and stars"
    ]
    nLines = len(cLines)
    for i = 1 to nLines
        lw = MeasureText(cLines[i], 14)
        if i <= 6
            col = RAYLIBColor(150, 190, 230, 220)
        but i = 8
            col = RAYLIBColor(255, 210, 90, 230)
        but i >= 10
            col = RAYLIBColor(120, 230, 160, 220)
        else
            col = RAYLIBColor(150, 190, 230, 220)
        ok
        DrawText(cLines[i], (SCREEN_W - lw)/2, cy + (i - 1) * 22, 14, col)
    next
    if floor(animTime * 2) % 2 = 0
        st = "Press ENTER or SPACE to Explore"
        stw = MeasureText(st, 26)
        DrawText(st, (SCREEN_W - stw)/2, SCREEN_H - 80, 26, WHITE)
    ok
    cr = "Developed using Ring Language + RingRayLib"
    crw = MeasureText(cr, 14)
    DrawText(cr, (SCREEN_W - crw)/2, SCREEN_H - 35, 14, RAYLIBColor(60, 80, 130, 175))

func vox_drawPauseOverlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 130))
    pt = "PAUSED"
    ptw = MeasureText(pt, 50)
    DrawText(pt, (SCREEN_W - ptw)/2, SCREEN_H/2 - 35, 50, WHITE)
    p2 = "Press P or SPACE to resume"
    p2w = MeasureText(p2, 20)
    DrawText(p2, (SCREEN_W - p2w)/2, SCREEN_H/2 + 25, 20, RAYLIBColor(180, 200, 230, 220))
