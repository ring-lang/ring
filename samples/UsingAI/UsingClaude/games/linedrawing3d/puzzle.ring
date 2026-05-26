/*
**  ld_puzzle.ring
**  Puzzle mode: loading, input, mouse, path, validation, solver
*/

func ld_loadPuzzleFromPanel panelIdx
    defIdx = puzzlePanels[panelIdx][5]
    if defIdx < 1 or defIdx > len(puzzleDefs) return ok

    pdef = puzzleDefs[defIdx]
    puzzGridW = pdef[1]
    puzzGridH = pdef[2]
    puzzStartR = pdef[3]
    puzzStartC = pdef[4]
    puzzExitR = pdef[5]
    puzzExitC = pdef[6]
    dotsStr = pdef[7]
    brokenStr = pdef[8]
    consStr = pdef[9]

    // Init node markers
    puzzNodeMarker = list(puzzGridH)
    for r = 1 to puzzGridH
        puzzNodeMarker[r] = list(puzzGridW)
        for c = 1 to puzzGridW
            puzzNodeMarker[r][c] = NODE_NONE
        next
    next
    puzzNodeMarker[puzzStartR][puzzStartC] = NODE_START
    puzzNodeMarker[puzzExitR][puzzExitC] = NODE_EXIT

    // Parse dot nodes
    if len(dotsStr) > 0
        parts = ld_splitStr(dotsStr, ";")
        nParts = len(parts)
        for i = 1 to nParts
            coords = ld_splitStr(parts[i], ",")
            if len(coords) >= 2
                dr = number(coords[1])
                dc = number(coords[2])
                if dr >= 1 and dr <= puzzGridH and dc >= 1 and dc <= puzzGridW
                    puzzNodeMarker[dr][dc] = NODE_DOT
                ok
            ok
        next
    ok

    // Init horizontal edges
    puzzHEdge = list(puzzGridH)
    for r = 1 to puzzGridH
        puzzHEdge[r] = list(puzzGridW - 1)
        for c = 1 to puzzGridW - 1
            puzzHEdge[r][c] = EDGE_NORMAL
        next
    next

    // Init vertical edges
    puzzVEdge = list(puzzGridH - 1)
    for r = 1 to puzzGridH - 1
        puzzVEdge[r] = list(puzzGridW)
        for c = 1 to puzzGridW
            puzzVEdge[r][c] = EDGE_NORMAL
        next
    next

    // Parse broken edges
    if len(brokenStr) > 0
        parts = ld_splitStr(brokenStr, ";")
        nParts = len(parts)
        for i = 1 to nParts
            tokens = ld_splitStr(parts[i], ",")
            if len(tokens) >= 3
                etype = tokens[1]
                er = number(tokens[2])
                ec = number(tokens[3])
                if etype = "H" and er >= 1 and er <= puzzGridH and ec >= 1 and ec <= puzzGridW - 1
                    puzzHEdge[er][ec] = EDGE_BROKEN
                ok
                if etype = "V" and er >= 1 and er <= puzzGridH - 1 and ec >= 1 and ec <= puzzGridW
                    puzzVEdge[er][ec] = EDGE_BROKEN
                ok
            ok
        next
    ok

    // Init cell constraints
    puzzCellCons = list(puzzGridH - 1)
    for r = 1 to puzzGridH - 1
        puzzCellCons[r] = list(puzzGridW - 1)
        for c = 1 to puzzGridW - 1
            puzzCellCons[r][c] = CONS_NONE
        next
    next

    if len(consStr) > 0
        parts = ld_splitStr(consStr, ";")
        nParts = len(parts)
        for i = 1 to nParts
            tokens = ld_splitStr(parts[i], ",")
            if len(tokens) >= 3
                cr = number(tokens[1])
                cc = number(tokens[2])
                ctype = tokens[3]
                if cr >= 1 and cr <= puzzGridH - 1 and cc >= 1 and cc <= puzzGridW - 1
                    if ctype = "B" puzzCellCons[cr][cc] = CONS_BLACK ok
                    if ctype = "W" puzzCellCons[cr][cc] = CONS_WHITE ok
                ok
            ok
        next
    ok

    // Init path
    puzzPathNodes = []
    add(puzzPathNodes, [puzzStartR, puzzStartC])
    puzzCursorR = puzzStartR
    puzzCursorC = puzzStartC

    puzzHintPath = []
    puzzShowHint = false
    puzzSolverActive = false
    puzzSolverStep = 0
    puzzParticles = []
    puzzValidTimer = 0.0
    puzzFailed = false
    puzzMouseDragging = false

    // Pre-compute screen layout for mouse support (must match ld_drawPuzzle2D)
    maxCellSz = 150
    if SCREEN_H < 900 maxCellSz = 120 ok
    if SCREEN_H < 700 maxCellSz = 90 ok
    availW = SCREEN_W - 200
    availH = SCREEN_H - 200
    cellW2 = availW / (puzzGridW - 1)
    cellH2 = availH / (puzzGridH - 1)
    cSz = cellW2
    if cellH2 < cSz cSz = cellH2 ok
    if cSz > maxCellSz cSz = maxCellSz ok
    if cSz < 40 cSz = 40 ok
    totalGW = floor((puzzGridW - 1) * cSz)
    totalGH = floor((puzzGridH - 1) * cSz)
    gridPad = floor(cSz * 0.7)
    if gridPad < 50 gridPad = 50 ok
    titleH = 70
    panelW2 = totalGW + gridPad * 2
    panelH2 = totalGH + gridPad * 2 + titleH
    panelX2 = floor((SCREEN_W - panelW2) / 2)
    panelY2 = floor((SCREEN_H - panelH2) / 2)
    puzzOffsetX = panelX2 + gridPad
    puzzOffsetY = panelY2 + gridPad + titleH
    puzzCellSz = cSz

// =============================================================
// String Split Helper

func ld_splitStr str, delim
    result = []
    current = ""
    sLen = len(str)
    for i = 1 to sLen
        ch = substr(str, i, 1)
        if ch = delim
            if len(current) > 0
                add(result, current)
                current = ""
            ok
        else
            current += ch
        ok
    next
    if len(current) > 0
        add(result, current)
    ok
    return result

func ld_handlePuzzleInput dt
    if puzzSolverActive return ok

    dr = 0   dc = 0

    if IsKeyPressed(KEY_UP) or IsKeyPressed(KEY_W)
        dr = -1   dc = 0
    ok
    if IsKeyPressed(KEY_DOWN) or IsKeyPressed(KEY_S)
        dr = 1    dc = 0
    ok
    if IsKeyPressed(KEY_LEFT) or IsKeyPressed(KEY_A)
        dr = 0    dc = -1
    ok
    if IsKeyPressed(KEY_RIGHT) or IsKeyPressed(KEY_D)
        dr = 0    dc = 1
    ok

    if dr != 0 or dc != 0
        ld_tryExtendPath(dr, dc)
    ok

    // Mouse drag support
    ld_handlePuzzleMouse()

    // Undo
    if IsKeyPressed(KEY_BACKSPACE) or IsKeyPressed(KEY_U)
        ld_undoPath()
    ok

    // Clear
    if IsKeyPressed(KEY_Z)
        ld_clearPath()
    ok

    // Auto-solve
    if IsKeyPressed(KEY_F)
        ld_computeHint()
    ok

    // Manual validate (press ENTER to check path)
    if IsKeyPressed(KEY_ENTER)
        ld_validatePuzzle()
    ok

    // Cancel puzzle
    if IsKeyPressed(KEY_ESCAPE) or IsKeyPressed(KEY_Q)
        puzzMouseDragging = false
        gameState = ST_EXPLORE
        HideCursor()
        SetMousePosition(centerX, centerY)
    ok

// =============================================================
// Puzzle Mouse Drag
// =============================================================

func ld_handlePuzzleMouse
    mmx = GetMouseX()
    mmy = GetMouseY()

    if IsMouseButtonDown(0) = false
        puzzMouseDragging = false
        return
    ok

    puzzMouseDragging = true

    // Get screen position of current cursor node
    ld_puzzNodeToScreen(puzzCursorR, puzzCursorC)
    curSX = puzzProjSX
    curSY = puzzProjSY

    // Clamp mouse draw position to valid edge directions only
    // Find which direction mouse is pulling toward
    rawDX = mmx - curSX
    rawDY = mmy - curSY

    // Determine dominant direction
    absDX = rawDX
    if absDX < 0 absDX = -absDX ok
    absDY = rawDY
    if absDY < 0 absDY = -absDY ok

    // Compute cell size in screen pixels
    cellPx = 50.0
    if puzzCursorC < puzzGridW
        ld_puzzNodeToScreen(puzzCursorR, puzzCursorC + 1)
        cellPx = puzzProjSX - curSX
        if cellPx < 0 cellPx = -cellPx ok
    but puzzCursorR < puzzGridH
        ld_puzzNodeToScreen(puzzCursorR + 1, puzzCursorC)
        cellPx = puzzProjSY - curSY
        if cellPx < 0 cellPx = -cellPx ok
    ok

    // Determine target direction and clamp
    tDR = 0   tDC = 0
    if absDX > absDY
        if rawDX > 0 tDC = 1 else tDC = -1 ok
    else
        if rawDY > 0 tDR = 1 else tDR = -1 ok
    ok

    // Check if this direction is valid
    tR = puzzCursorR + tDR
    tC = puzzCursorC + tDC
    dirValid = true

    if tR < 1 or tR > puzzGridH or tC < 1 or tC > puzzGridW
        dirValid = false
    ok

    if dirValid
        // Check edge not broken
        if tDR = 0
            edgeC = puzzCursorC
            if tDC < 0 edgeC = puzzCursorC - 1 ok
            if edgeC < 1 or edgeC > puzzGridW - 1
                dirValid = false
            but puzzHEdge[puzzCursorR][edgeC] = EDGE_BROKEN
                dirValid = false
            ok
        else
            edgeR = puzzCursorR
            if tDR < 0 edgeR = puzzCursorR - 1 ok
            if edgeR < 1 or edgeR > puzzGridH - 1
                dirValid = false
            but puzzVEdge[edgeR][puzzCursorC] = EDGE_BROKEN
                dirValid = false
            ok
        ok
    ok

    // Check not crossing existing path (except for retrace/undo)
    isRetrace = false
    nPath = len(puzzPathNodes)
    if dirValid
        if nPath >= 2
            prevR = puzzPathNodes[nPath - 1][1]
            prevC = puzzPathNodes[nPath - 1][2]
            if tR = prevR and tC = prevC
                isRetrace = true
            ok
        ok
        if !isRetrace
            for i = 1 to nPath
                if puzzPathNodes[i][1] = tR and puzzPathNodes[i][2] = tC
                    dirValid = false
                ok
            next
        ok
    ok

    if dirValid
        // Get target node screen position
        ld_puzzNodeToScreen(tR, tC)
        targSX = puzzProjSX
        targSY = puzzProjSY

        // Clamp draw position along the edge toward target
        if tDR = 0
            // Horizontal movement - clamp Y to node Y, X follows mouse
            puzzMouseDrawY = curSY
            if tDC > 0
                puzzMouseDrawX = mmx
                if puzzMouseDrawX < curSX puzzMouseDrawX = curSX ok
                if puzzMouseDrawX > targSX puzzMouseDrawX = targSX ok
            else
                puzzMouseDrawX = mmx
                if puzzMouseDrawX > curSX puzzMouseDrawX = curSX ok
                if puzzMouseDrawX < targSX puzzMouseDrawX = targSX ok
            ok
        else
            // Vertical movement - clamp X to node X, Y follows mouse
            puzzMouseDrawX = curSX
            if tDR > 0
                puzzMouseDrawY = mmy
                if puzzMouseDrawY < curSY puzzMouseDrawY = curSY ok
                if puzzMouseDrawY > targSY puzzMouseDrawY = targSY ok
            else
                puzzMouseDrawY = mmy
                if puzzMouseDrawY > curSY puzzMouseDrawY = curSY ok
                if puzzMouseDrawY < targSY puzzMouseDrawY = targSY ok
            ok
        ok

        // Check if mouse reached close enough to target node to snap
        snapDX = puzzMouseDrawX - targSX
        snapDY = puzzMouseDrawY - targSY
        snapDist = sqrt(snapDX * snapDX + snapDY * snapDY)
        snapThreshold = cellPx * 0.15
        if snapThreshold < 8 snapThreshold = 8 ok

        if snapDist < snapThreshold
            if isRetrace
                ld_undoPath()
            else
                ld_doExtendPath(tDR, tDC)
            ok
        ok
    else
        // No valid direction - keep draw at cursor node
        puzzMouseDrawX = curSX
        puzzMouseDrawY = curSY
    ok

// =============================================================
// Path Extension
// =============================================================


func ld_tryExtendPath dr, dc
    // For keyboard: instant extend
    ld_doExtendPath(dr, dc)

func ld_doExtendPath dr, dc
    newR = puzzCursorR + dr
    newC = puzzCursorC + dc

    if newR < 1 or newR > puzzGridH or newC < 1 or newC > puzzGridW return ok

    // Check retrace (undo)
    nPath = len(puzzPathNodes)
    if nPath >= 2
        prevR = puzzPathNodes[nPath - 1][1]
        prevC = puzzPathNodes[nPath - 1][2]
        if newR = prevR and newC = prevC
            ld_undoPath()
            return
        ok
    ok

    // No crossing
    for i = 1 to nPath
        if puzzPathNodes[i][1] = newR and puzzPathNodes[i][2] = newC
            return
        ok
    next

    // Check edge
    if dr = 0
        edgeC = puzzCursorC
        if dc < 0 edgeC = puzzCursorC - 1 ok
        if edgeC < 1 or edgeC > puzzGridW - 1 return ok
        if puzzHEdge[puzzCursorR][edgeC] = EDGE_BROKEN return ok
    else
        edgeR = puzzCursorR
        if dr < 0 edgeR = puzzCursorR - 1 ok
        if edgeR < 1 or edgeR > puzzGridH - 1 return ok
        if puzzVEdge[edgeR][puzzCursorC] = EDGE_BROKEN return ok
    ok

    // Extend
    add(puzzPathNodes, [newR, newC])
    puzzCursorR = newR
    puzzCursorC = newC

    // Spawn particles
    ld_spawnPuzzleParticle(newR, newC)
    PlaySound(sndPathDraw)

    // Auto-validate at exit
    if puzzCursorR = puzzExitR and puzzCursorC = puzzExitC
        ld_validatePuzzle()
    ok

func ld_undoPath
    nPath = len(puzzPathNodes)
    if nPath <= 1 return ok
    puzzMouseDragging = false
    del(puzzPathNodes, nPath)
    nPath -= 1
    puzzCursorR = puzzPathNodes[nPath][1]
    puzzCursorC = puzzPathNodes[nPath][2]

func ld_clearPath
    puzzPathNodes = []
    add(puzzPathNodes, [puzzStartR, puzzStartC])
    puzzCursorR = puzzStartR
    puzzCursorC = puzzStartC
    puzzShowHint = false
    puzzMouseDragging = false

func ld_validatePuzzle
    // Check end at exit
    if puzzCursorR != puzzExitR or puzzCursorC != puzzExitC
        ld_showMsg("Path must reach the EXIT!")
        puzzFailed = true
        puzzValidTimer = 1.5
        PlaySound(sndPuzzleFail)
        return
    ok

    // Check all dots visited
    nPath = len(puzzPathNodes)
    for r = 1 to puzzGridH
        for c = 1 to puzzGridW
            if puzzNodeMarker[r][c] = NODE_DOT
                found = false
                for i = 1 to nPath
                    if puzzPathNodes[i][1] = r and puzzPathNodes[i][2] = c
                        found = true
                    ok
                next
                if found = false
                    ld_showMsg("Missing required dot!")
                    puzzFailed = true
                    puzzValidTimer = 1.5
                    PlaySound(sndPuzzleFail)
                    return
                ok
            ok
        next
    next

    // Check color separation
    if ld_checkColorSeparation() = false
        ld_showMsg("Colors not properly separated!")
        puzzFailed = true
        puzzValidTimer = 1.5
        PlaySound(sndPuzzleFail)
        return
    ok

    // SUCCESS!
    gameState = ST_SOLVED
    solvedTimer = 1.5
    PlaySound(sndPuzzleSolved)

    // Open the associated door(s)
    nPanels = len(puzzlePanels)
    nDoors = len(doors)
    if activePanelIdx >= 1 and activePanelIdx <= nPanels
        doorIdx = puzzlePanels[activePanelIdx][4]
        // Open all doors with same puzzle index
        for i = 1 to nDoors
            if doors[i][4] = doors[doorIdx][4]
                doors[i][5] = true
                doors[i][3] = 1.0
            ok
        next
        PlaySound(sndDoorOpen)
    ok

    // Spawn celebration particles
    for i = 1 to 30
        ppx = GetRandomValue(100, SCREEN_W - 100)
        ppy = GetRandomValue(100, SCREEN_H - 100)
        vx = GetRandomValue(-200, 200) / 100.0
        vy = GetRandomValue(-300, -50) / 100.0
        add(puzzParticles, [ppx, ppy, vx, vy, 2.0, 240, 245, 255])
    next


func ld_checkColorSeparation
    numCellR = puzzGridH - 1
    numCellC = puzzGridW - 1
    if numCellR < 1 or numCellC < 1 return true ok

    regionMap = list(numCellR)
    for r = 1 to numCellR
        regionMap[r] = list(numCellC)
        for c = 1 to numCellC
            regionMap[r][c] = 0
        next
    next

    regionID = 0

    for r = 1 to numCellR
        for c = 1 to numCellC
            if regionMap[r][c] = 0
                regionID += 1
                queue = []
                add(queue, [r, c])
                regionMap[r][c] = regionID
                head = 1
                while head <= len(queue)
                    cr = queue[head][1]
                    cc = queue[head][2]
                    head += 1

                    // Up
                    if cr > 1
                        if regionMap[cr-1][cc] = 0
                            if ld_isEdgeOnPath(cr, cc, cr, cc+1) = false
                                regionMap[cr-1][cc] = regionID
                                add(queue, [cr-1, cc])
                            ok
                        ok
                    ok
                    // Down
                    if cr < numCellR
                        if regionMap[cr+1][cc] = 0
                            if ld_isEdgeOnPath(cr+1, cc, cr+1, cc+1) = false
                                regionMap[cr+1][cc] = regionID
                                add(queue, [cr+1, cc])
                            ok
                        ok
                    ok
                    // Left
                    if cc > 1
                        if regionMap[cr][cc-1] = 0
                            if ld_isEdgeOnPath(cr, cc, cr+1, cc) = false
                                regionMap[cr][cc-1] = regionID
                                add(queue, [cr, cc-1])
                            ok
                        ok
                    ok
                    // Right
                    if cc < numCellC
                        if regionMap[cr][cc+1] = 0
                            if ld_isEdgeOnPath(cr, cc+1, cr+1, cc+1) = false
                                regionMap[cr][cc+1] = regionID
                                add(queue, [cr, cc+1])
                            ok
                        ok
                    ok
                end
            ok
        next
    next

    // Check each region: no mixed colors
    for rid = 1 to regionID
        hasBlack = false
        hasWhite = false
        for r = 1 to numCellR
            for c = 1 to numCellC
                if regionMap[r][c] = rid
                    if puzzCellCons[r][c] = CONS_BLACK hasBlack = true ok
                    if puzzCellCons[r][c] = CONS_WHITE hasWhite = true ok
                ok
            next
        next
        if hasBlack and hasWhite
            return false
        ok
    next

    return true

func ld_isEdgeOnPath r1, c1, r2, c2
    nPath = len(puzzPathNodes)
    for i = 1 to nPath - 1
        pr1 = puzzPathNodes[i][1]
        pc1 = puzzPathNodes[i][2]
        pr2 = puzzPathNodes[i+1][1]
        pc2 = puzzPathNodes[i+1][2]
        if (pr1 = r1 and pc1 = c1 and pr2 = r2 and pc2 = c2) or
           (pr1 = r2 and pc1 = c2 and pr2 = r1 and pc2 = c1)
            return true
        ok
    next
    return false


func ld_computeHint
    ld_clearPath()
    puzzHintPath = []
    puzzShowHint = false
    puzzSolverActive = false

    path = []
    add(path, [puzzStartR, puzzStartC])
    visited = list(puzzGridH)
    for r = 1 to puzzGridH
        visited[r] = list(puzzGridW)
        for c = 1 to puzzGridW
            visited[r][c] = false
        next
    next
    visited[puzzStartR][puzzStartC] = true

    result = ld_dfsSolve(path, visited)
    if result
        puzzHintPath = []
        nPath = len(path)
        for i = 1 to nPath
            add(puzzHintPath, [path[i][1], path[i][2]])
        next
        puzzShowHint = true
        puzzSolverActive = true
        puzzSolverStep = 1
        puzzSolverDelay = 0.3
        ld_showMsg("Auto-solving...")
    else
        ld_showMsg("No solution found!")
    ok

func ld_dfsSolve pathRef, visitedRef
    stack = []
    add(stack, [puzzStartR, puzzStartC, 1])
    dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]]

    nStack = len(stack)
    while nStack > 0
        top = stack[nStack]
        cr = top[1]
        cc = top[2]
        di = top[3]

        if di = 1 and cr = puzzExitR and cc = puzzExitC
            oldPath = puzzPathNodes
            puzzPathNodes = []
            for si = 1 to nStack
                add(puzzPathNodes, [stack[si][1], stack[si][2]])
            next
            puzzCursorR = puzzExitR
            puzzCursorC = puzzExitC

            allDots = true
            nPathCheck = len(puzzPathNodes)
            for r = 1 to puzzGridH
                for c = 1 to puzzGridW
                    if puzzNodeMarker[r][c] = NODE_DOT
                        found = false
                        for pIdx = 1 to nPathCheck
                            if puzzPathNodes[pIdx][1] = r and puzzPathNodes[pIdx][2] = c
                                found = true
                            ok
                        next
                        if found = false allDots = false ok
                    ok
                next
            next

            colorOk = ld_checkColorSeparation()

            puzzPathNodes = oldPath
            nOld = len(puzzPathNodes)
            if nOld > 0
                puzzCursorR = puzzPathNodes[nOld][1]
                puzzCursorC = puzzPathNodes[nOld][2]
            ok

            if allDots and colorOk
                while len(pathRef) > 0
                    del(pathRef, len(pathRef))
                end
                for si = 1 to nStack
                    add(pathRef, [stack[si][1], stack[si][2]])
                next
                return true
            ok
            stack[nStack][3] = 5
            loop
        ok

        if di > 4
            visitedRef[cr][cc] = false
            del(stack, nStack)
            nStack -= 1
            loop
        ok

        stack[nStack][3] = di + 1

        dr2 = dirs[di][1]
        dc2 = dirs[di][2]
        nr = cr + dr2
        nc = cc + dc2

        if nr < 1 or nr > puzzGridH or nc < 1 or nc > puzzGridW loop ok
        if visitedRef[nr][nc] loop ok

        edgeOk = true
        if dr2 = 0
            edgeC = cc
            if dc2 < 0 edgeC = cc - 1 ok
            if edgeC < 1 or edgeC > puzzGridW - 1 edgeOk = false ok
            if edgeOk
                if puzzHEdge[cr][edgeC] = EDGE_BROKEN edgeOk = false ok
            ok
        else
            edgeR = cr
            if dr2 < 0 edgeR = cr - 1 ok
            if edgeR < 1 or edgeR > puzzGridH - 1 edgeOk = false ok
            if edgeOk
                if puzzVEdge[edgeR][cc] = EDGE_BROKEN edgeOk = false ok
            ok
        ok

        if edgeOk = false loop ok

        visitedRef[nr][nc] = true
        add(stack, [nr, nc, 1])
        nStack += 1
    end

    return false

func ld_updateSolver dt
    puzzSolverDelay -= dt
    if puzzSolverDelay <= 0
        nHint = len(puzzHintPath)
        if puzzSolverStep <= nHint
            puzzPathNodes = []
            for si = 1 to puzzSolverStep
                add(puzzPathNodes, [puzzHintPath[si][1], puzzHintPath[si][2]])
            next
            puzzCursorR = puzzHintPath[puzzSolverStep][1]
            puzzCursorC = puzzHintPath[puzzSolverStep][2]
            ld_spawnPuzzleParticle(puzzCursorR, puzzCursorC)

            if puzzCursorR = puzzExitR and puzzCursorC = puzzExitC
                puzzSolverActive = false
                ld_validatePuzzle()
            else
                puzzSolverStep += 1
                puzzSolverDelay = SOLVER_WAIT
            ok
        else
            puzzSolverActive = false
        ok
    ok


func ld_puzzNodeToScreen r, c
    // Uses cached layout from ld_drawPuzzle2D
    puzzProjSX = puzzOffsetX + (c - 1) * puzzCellSz
    puzzProjSY = puzzOffsetY + (r - 1) * puzzCellSz


func ld_spawnPuzzleParticle r, c
    // Use cached layout from ld_drawPuzzle2D
    spx = puzzOffsetX + (c - 1) * puzzCellSz
    spy = puzzOffsetY + (r - 1) * puzzCellSz

    // If layout not yet computed, use center of screen
    if puzzCellSz < 1
        spx = SCREEN_W / 2
        spy = SCREEN_H / 2
    ok

    for k = 1 to 6
        vx = GetRandomValue(-100, 100) / 50.0
        vy = GetRandomValue(-100, 100) / 50.0
        add(puzzParticles, [spx, spy, vx, vy, 0.8, 255, 200, 80])
    next

func ld_updatePuzzleParticles dt
    i = 1
    nPP = len(puzzParticles)
    while i <= nPP
        puzzParticles[i][1] += puzzParticles[i][3] * 60 * dt
        puzzParticles[i][2] += puzzParticles[i][4] * 60 * dt
        puzzParticles[i][5] -= dt
        if puzzParticles[i][5] <= 0
            del(puzzParticles, i)
            nPP -= 1
        else
            i += 1
        ok
    end

