/*
**  cr_gameplay.ring - Gameplay Functions
**  Code Rooms 3D
**  Room loading, input, movement, undo, solve checking, animations, camera
*/

func cr_loadRoom roomIdx
    if roomIdx > roomCount return ok

    roomTitle = roomTitles[roomIdx]
    roomCode  = roomCodes[roomIdx]

    // Set weather for this room
    w_setWeather(roomWeather[roomIdx])

    mapData   = roomMaps[roomIdx]
    labels    = roomLabels[roomIdx]
    slotLbls  = roomSlotLbls[roomIdx]

    GRID_H = len(mapData)
    GRID_W = len(mapData[1])

    // Init grid
    tiles = list(GRID_H)
    for i = 1 to GRID_H
        tiles[i] = list(GRID_W)
        for j = 1 to GRID_W
            tiles[i][j] = T_EMPTY
        next
    next

    // Reset blocks & slots
    blocks = []
    blockCount = 0
    slots = []
    slotCount = 0
    doorOpen = 0
    doorRow = 0
    doorCol = 0
    moveCount = 0
    undoStack = []
    particles = []
    pLen = 0
    solveTimer = 0.0
    transTimer = 0.0

    // Track which label index we are on for blocks
    blockIdx = 0
    labelsLen = len(labels)
    slotLblsLen = len(slotLbls)

    // Parse map
    for row = 1 to GRID_H
        line = mapData[row]
        for col = 1 to GRID_W
            ch = substr(line, col, 1)

            if ch = "#"
                tiles[row][col] = T_WALL
            ok

            if ch = "."
                tiles[row][col] = T_FLOOR
            ok

            if ch = "@"
                tiles[row][col] = T_FLOOR
                px = col
                py = row
                pDir = 0
                pAnimX = col * CELL
                pAnimZ = row * CELL
                pTargX = pAnimX
                pTargZ = pAnimZ
                pMoving = 0
            ok

            // Blocks: A-P
            chCode = ascii(ch)
            if chCode >= 65 and chCode <= 80
                tiles[row][col] = T_FLOOR
                blockIdx++
                lbl = ""
                if blockIdx <= labelsLen
                    lbl = labels[blockIdx]
                ok
                blockCount++
                blocks + [col, row, lbl, col * CELL, row * CELL, col * CELL, row * CELL, 0, 0]
            ok

            // Slots: 1-9, 0 (0 = slot 10)
            if chCode >= 48 and chCode <= 57
                tiles[row][col] = T_SLOT
                si = chCode - 48
                if si = 0
                    si = 10
                ok
                slbl = ""
                if si <= slotLblsLen
                    slbl = slotLbls[si]
                ok
                slotCount++
                slots + [col, row, slbl, 0, 0]
            ok

            // Door
            if ch = "Z"
                if doorCol = 0
                    tiles[row][col] = T_DOOR
                    doorRow = row
                    doorCol = col
                else
                    tiles[row][col] = T_DOOR
                    doorRow = row
                    doorCol = col
                ok
            ok
        next
    next

// =============================================================
// Handle Input
// =============================================================

func cr_handleInput
    // Block input while animating
    if pMoving return ok

    dx = 0
    dy = 0

    if IsKeyPressed(KEY_UP) or IsKeyPressed(KEY_W)
        dy = -1  pDir = 0
    ok
    if IsKeyPressed(KEY_DOWN) or IsKeyPressed(KEY_S)
        dy = 1  pDir = 2
    ok
    if IsKeyPressed(KEY_LEFT) or IsKeyPressed(KEY_A)
        dx = -1  pDir = 3
    ok
    if IsKeyPressed(KEY_RIGHT) or IsKeyPressed(KEY_D)
        dx = 1  pDir = 1
    ok

    // Held key repeat
    if dx = 0 and dy = 0
        moveTimer += GetFrameTime()
        if moveTimer > 0.06
            moveTimer = 0.0
            if IsKeyDown(KEY_UP) or IsKeyDown(KEY_W)
                dy = -1  pDir = 0
            ok
            if IsKeyDown(KEY_DOWN) or IsKeyDown(KEY_S)
                dy = 1  pDir = 2
            ok
            if IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_A)
                dx = -1  pDir = 3
            ok
            if IsKeyDown(KEY_RIGHT) or IsKeyDown(KEY_D)
                dx = 1  pDir = 1
            ok
        ok
    else
        moveTimer = 0.0
    ok

    // Restart room
    if IsKeyPressed(KEY_R)
        cr_loadRoom(currentRoom)
        return
    ok

    // Next level (Page Down or N)
    if IsKeyPressed(KEY_PAGE_DOWN) or IsKeyPressed(KEY_N)
        if currentRoom < roomCount
            currentRoom++
            cr_loadRoom(currentRoom)
            gameState = GS_PLAYING
            PlaySound(sndTransit)
        ok
        return
    ok

    // Previous level (Page Up or P)
    if IsKeyPressed(KEY_PAGE_UP) or IsKeyPressed(KEY_P)
        if currentRoom > 1
            currentRoom--
            cr_loadRoom(currentRoom)
            gameState = GS_PLAYING
            PlaySound(sndTransit)
        ok
        return
    ok

    // Undo
    if IsKeyPressed(KEY_U) or IsKeyPressed(KEY_BACKSPACE)
        PlaySound(sndUndo)
        cr_undo()
        return
    ok

    if dx = 0 and dy = 0 return ok

    nx = px + dx
    ny = py + dy

    // Check bounds
    if nx < 1 or nx > GRID_W or ny < 1 or ny > GRID_H
        PlaySound(sndBump)
        return
    ok

    // Check wall
    if tiles[ny][nx] = T_WALL
        PlaySound(sndBump)
        return
    ok

    // Check closed door
    if tiles[ny][nx] = T_DOOR and doorOpen = 0
        PlaySound(sndBump)
        return
    ok

    // Check open door -> trigger transition
    if tiles[ny][nx] = T_DOOROPEN
        cr_saveUndo()
        px = nx
        py = ny
        pTargX = nx * CELL
        pTargZ = ny * CELL
        pMoving = 1
        moveCount++
        PlaySound(sndTransit)
        gameState = GS_TRANS
        transTimer = 0.0
        return
    ok

    // Check if next room trigger
    if tiles[ny][nx] = T_NEXTROOM
        gameState = GS_TRANS
        transTimer = 0.0
        return
    ok

    // Check for block at target position
    bIdx = cr_blockAt(nx, ny)
    if bIdx > 0
        bnx = nx + dx
        bny = ny + dy

        if bnx < 1 or bnx > GRID_W or bny < 1 or bny > GRID_H return ok
        if tiles[bny][bnx] = T_WALL return ok
        if tiles[bny][bnx] = T_DOOR and doorOpen = 0 return ok
        if cr_blockAt(bnx, bny) > 0 return ok

        // Can push!
        cr_saveUndo()
        PlaySound(sndPush)

        blocks[bIdx][1] = bnx
        blocks[bIdx][2] = bny
        blocks[bIdx][6] = bnx * CELL
        blocks[bIdx][7] = bny * CELL
        blocks[bIdx][8] = 1

        blocks[bIdx][9] = 0
        for si = 1 to slotCount
            if slots[si][1] = bnx and slots[si][2] = bny
                blocks[bIdx][9] = 1
                PlaySound(sndPlace)
            ok
        next

        px = nx
        py = ny
        pTargX = nx * CELL
        pTargZ = ny * CELL
        pMoving = 1
        moveCount++
        return
    ok

    // Empty floor or slot - just move
    cr_saveUndo()
    PlaySound(sndStep)
    px = nx
    py = ny
    pTargX = nx * CELL
    pTargZ = ny * CELL
    pMoving = 1
    moveCount++

// =============================================================
// Block at position
// =============================================================

func cr_blockAt col, row
    for i = 1 to blockCount
        if blocks[i][1] = col and blocks[i][2] = row
            return i
        ok
    next
    return 0

// =============================================================
// Undo System
// =============================================================

func cr_saveUndo
    state = []
    state + px
    state + py
    state + pDir
    for i = 1 to blockCount
        state + blocks[i][1]
        state + blocks[i][2]
        state + blocks[i][9]
    next
    add(undoStack, state)
    undoLen = len(undoStack)
    if undoLen > undoMax
        del(undoStack, 1)
    ok

func cr_undo
    undoLen = len(undoStack)
    if undoLen = 0 return ok
    state = undoStack[undoLen]
    del(undoStack, undoLen)

    px = state[1]
    py = state[2]
    pDir = state[3]
    pTargX = px * CELL
    pTargZ = py * CELL
    pAnimX = pTargX
    pAnimZ = pTargZ
    pMoving = 0

    idx = 4
    for i = 1 to blockCount
        blocks[i][1] = state[idx]
        blocks[i][2] = state[idx + 1]
        blocks[i][9] = state[idx + 2]
        blocks[i][4] = blocks[i][1] * CELL
        blocks[i][5] = blocks[i][2] * CELL
        blocks[i][6] = blocks[i][4]
        blocks[i][7] = blocks[i][5]
        blocks[i][8] = 0
        idx += 3
    next

    for si = 1 to slotCount
        slots[si][4] = 0
        slots[si][5] = 0
    next
    for bi = 1 to blockCount
        for si = 1 to slotCount
            if blocks[bi][1] = slots[si][1] and blocks[bi][2] = slots[si][2]
                slots[si][4] = 1
                slots[si][5] = bi
            ok
        next
    next

// =============================================================
// Check if puzzle is solved
// =============================================================

func cr_checkSolved
    if doorOpen return ok

    allCorrect = 1
    for si = 1 to slotCount
        sCol = slots[si][1]
        sRow = slots[si][2]
        expected = slots[si][3]

        bIdx = cr_blockAt(sCol, sRow)
        if bIdx = 0
            allCorrect = 0
            slots[si][4] = 0
            slots[si][5] = 0
        else
            slots[si][4] = 1
            slots[si][5] = bIdx
            if blocks[bIdx][3] != expected
                allCorrect = 0
            ok
        ok
    next

    if allCorrect
        gameState = GS_SOLVED
        solveTimer = 0.0
        PlaySound(sndSolved)
        for si = 1 to slotCount
            wx = slots[si][1] * CELL
            wz = slots[si][2] * CELL
            cr_spawnParticles(wx, 1.5, wz, 50, 200, 80, 15)
        next
    ok

// =============================================================
// Update Animations
// =============================================================

func cr_updateAnimations dt
    if pMoving
        spd = 32.0
        diffX = pTargX - pAnimX
        diffZ = pTargZ - pAnimZ
        dist = diffX * diffX + diffZ * diffZ
        if dist < 0.01
            pAnimX = pTargX
            pAnimZ = pTargZ
            pMoving = 0
        else
            step = spd * dt
            if step * step > dist
                pAnimX = pTargX
                pAnimZ = pTargZ
                pMoving = 0
            else
                len = 1.0
                if dist > 0.001 len = step / (dist * 0.5 + 0.5) ok
                if len > 1 len = 1 ok
                pAnimX += diffX * len
                pAnimZ += diffZ * len
            ok
        ok
    ok

    for i = 1 to blockCount
        if blocks[i][8]
            spd = 28.0
            diffX = blocks[i][6] - blocks[i][4]
            diffZ = blocks[i][7] - blocks[i][5]
            dist = diffX * diffX + diffZ * diffZ
            if dist < 0.01
                blocks[i][4] = blocks[i][6]
                blocks[i][5] = blocks[i][7]
                blocks[i][8] = 0
            else
                step = spd * dt
                if step * step > dist
                    blocks[i][4] = blocks[i][6]
                    blocks[i][5] = blocks[i][7]
                    blocks[i][8] = 0
                else
                    len = 1.0
                    if dist > 0.001 len = step / (dist * 0.5 + 0.5) ok
                    if len > 1 len = 1 ok
                    blocks[i][4] += diffX * len
                    blocks[i][5] += diffZ * len
                ok
            ok
        ok
    next

    pBobTime += dt

// =============================================================
// Camera
// =============================================================

func cr_updateCamera
    cx = (GRID_W + 1) / 2.0 * CELL
    cz = (GRID_H + 1) / 2.0 * CELL

    roomSize = GRID_W
    if GRID_H > roomSize roomSize = GRID_H ok
    camH = roomSize * 1.8 + 4
    camDist = roomSize * 1.2 + 2

    if camMode = CAM_TOP
        cam.position.x = cx
        cam.position.y = camH + 6
        cam.position.z = cz + 1.0
        cam.target.x = cx
        cam.target.y = 0.8
        cam.target.z = cz
        cam.fovy = 50
    ok

    if camMode = CAM_ANGLE
        cam.position.x = cx
        cam.position.y = camH
        cam.position.z = cz + camDist
        cam.target.x = cx
        cam.target.y = 0.8
        cam.target.z = cz
        cam.fovy = 50
    ok

    if camMode = CAM_FOLLOW
        cam.position.x = pAnimX
        cam.position.y = camH * 0.7
        cam.position.z = pAnimZ + camDist * 0.8
        cam.target.x = pAnimX
        cam.target.y = 0.8
        cam.target.z = pAnimZ
        cam.fovy = 50
    ok
