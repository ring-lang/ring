/*
**  ld_explore.ring
**  Exploration mode: input, camera, collision, door interaction
*/

func ld_handleExploreInput dt
    // Mouse look
    curMX = GetMouseX()
    curMY = GetMouseY()
    mdx = curMX - centerX
    mdy = curMY - centerY
    camYaw += mdx * mouseSens
    camPitch -= mdy * mouseSens
    if camPitch > 0.8 camPitch = 0.8 ok
    if camPitch < -0.8 camPitch = -0.8 ok
    SetMousePosition(centerX, centerY)

    // Movement
    moveSpeed = 3.5 * dt
    strafeSpeed = 3.0 * dt

    forwardX = cos(camYaw)
    forwardZ = sin(camYaw)
    strafeX = cos(camYaw + PI/2)
    strafeZ = sin(camYaw + PI/2)

    dx = 0.0
    dz = 0.0

    if IsKeyDown(KEY_W) or IsKeyDown(KEY_UP)
        dx += forwardX * moveSpeed
        dz += forwardZ * moveSpeed
    ok
    if IsKeyDown(KEY_S) or IsKeyDown(KEY_DOWN)
        dx -= forwardX * moveSpeed
        dz -= forwardZ * moveSpeed
    ok
    if IsKeyDown(KEY_A) or IsKeyDown(KEY_LEFT)
        dx -= strafeX * strafeSpeed
        dz -= strafeZ * strafeSpeed
    ok
    if IsKeyDown(KEY_D) or IsKeyDown(KEY_RIGHT)
        dx += strafeX * strafeSpeed
        dz += strafeZ * strafeSpeed
    ok

    // Collision - try X and Z separately
    newX = pX + dx
    newZ = pZ + dz
    colRadius = 0.25

    if ld_canMove(newX, pZ, colRadius)
        pX = newX
    ok
    if ld_canMove(pX, newZ, colRadius)
        pZ = newZ
    ok

    // Footstep sounds when moving
    isMoving = (dx != 0 or dz != 0)
    if isMoving
        footstepTimer -= dt
        if footstepTimer <= 0
            PlaySound(sndFootstep)
            footstepTimer = 0.38
        ok
    else
        footstepTimer = 0
    ok

    // Check sphere collection
    nSpheres = len(sphereList)
    nQuotes = len(sphereQuotes)
    for spIdx = 1 to nSpheres
        if sphereList[spIdx][4] = true loop ok   // already collected
        spR = sphereList[spIdx][1]
        spC = sphereList[spIdx][2]
        spX = spC - 0.5
        spZ = spR - 0.5
        ddx = spX - pX
        ddz = spZ - pZ
        dist = sqrt(ddx*ddx + ddz*ddz)
        if dist < 0.8
            sphereList[spIdx][4] = true   // collected!
            spType = sphereList[spIdx][3]
            sphereScore += SPHERE_VALUES[spType + 1]
            PlaySound(sndSphereCollect)
            // Fireworks celebration!
            ld_spawnFireworks(spX, 0.3, spZ, spType)
            sphereQuoteIdx += 1
            if sphereQuoteIdx > nQuotes
                sphereQuoteIdx = 1
            ok
            // Show quote immediately (character by character)
            ld_showMsg(sphereQuotes[sphereQuoteIdx])
        ok
    next

    // Toggle map
    if IsKeyPressed(KEY_TAB)
        showMap = !showMap
    ok

    // ESC in explore mode exits the game
    if IsKeyPressed(KEY_ESCAPE)
        if hasMapModel
            UnloadModel(mapModel)
            UnloadTexture(mapTexture)
        ok
        UnloadTexture(texWall)
        ld_closeAudio()
        CloseWindow()
        bye
    ok


func ld_canMove x, z, radius
    for dr = -1 to 1 step 2
        for dc = -1 to 1 step 2
            cx = x + dc * radius
            cz = z + dr * radius
            gr = floor(cz) + 1
            gc = floor(cx) + 1
            if gr < 1 or gr > MAP_H or gc < 1 or gc > MAP_W
                return false
            ok
            t = map[gr][gc]
            if t = T_WALL1 or t = T_WALL2 or t = T_WALL3
                return false
            ok
            if t = T_DOOR
                // Check if door is solved/open
                if !ld_isDoorOpen(gr, gc)
                    // Auto-trigger puzzle for this door
                    ld_tryDoorPuzzle(gr, gc)
                    return false
                ok
            ok
        next
    next
    return true

func ld_isDoorOpen r, c
    nDoors = len(doors)
    for i = 1 to nDoors
        if doors[i][1] = r and doors[i][2] = c
            if doors[i][5]   // solved
                return true
            ok
            return false
        ok
    next
    return true

func ld_tryDoorPuzzle doorR, doorC
    if gameState != ST_EXPLORE return ok

    // Find which door entry this is
    doorPuzzIdx = 0
    nDoors = len(doors)
    for i = 1 to nDoors
        if doors[i][1] = doorR and doors[i][2] = doorC
            doorPuzzIdx = doors[i][4]   // puzzle index stored in door
        ok
    next
    if doorPuzzIdx = 0 return ok

    // Find the puzzle panel that opens this door
    nPanels = len(puzzlePanels)
    for i = 1 to nPanels
        panelDoorIdx = puzzlePanels[i][4]
        if panelDoorIdx >= 1 and panelDoorIdx <= nDoors
            if doors[panelDoorIdx][4] = doorPuzzIdx
                // Check not already solved
                if doors[panelDoorIdx][5] = false
                    activePanelIdx = i
                    ld_loadPuzzleFromPanel(i)
                    gameState = ST_PUZZLE
                    ShowCursor()
                    // Door puzzle triggers automatically
                    PlaySound(sndPuzzleOpen)
                    return
                ok
            ok
        ok
    next

func ld_updateCamera
    cam.position.x = pX
    cam.position.y = 0.5
    cam.position.z = pZ

    lookX = pX + cos(camYaw)
    lookY = 0.5 + sin(camPitch)
    lookZ = pZ + sin(camYaw)

    cam.target.x = lookX
    cam.target.y = lookY
    cam.target.z = lookZ


func ld_checkAllSolved
    if gameState != ST_EXPLORE return ok

    // Count unique puzzle indices among panels
    totalPuzzles = len(puzzleDefs)
    solvedCount = 0

    // Check each puzzle panel
    nPanels = len(puzzlePanels)
    nDoors = len(doors)
    for i = 1 to nPanels
        doorIdx = puzzlePanels[i][4]
        if doorIdx >= 1 and doorIdx <= nDoors
            if doors[doorIdx][5] = true
                solvedCount += 1
            ok
        ok
    next

    if solvedCount >= nPanels
        gameState = ST_WON
        PlaySound(sndWinFanfare)
    ok

