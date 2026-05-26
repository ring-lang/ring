/*
**  Dave the Fighter - Collision Detection & Player Death
**  Functions: dave_worldToRow/Col, dave_tileIsSolid, dave_solidAt,
**             dave_feetSolid, dave_headSolid, dave_enemyGroundSolid, dave_killPlayer
*/

func dave_worldToRow y
    r = LVL_H - floor(y)
    if r < 1 r = 1 ok
    if r > LVL_H r = LVL_H ok
    return r

func dave_worldToCol x
    c = floor(x + 0.5)
    if c < 1 c = 1 ok
    if c > curLvlW c = curLvlW ok
    return c

func dave_tileAtWorld x, y
    r = dave_worldToRow(y)
    c = dave_worldToCol(x)
    if r >= 1 and r <= LVL_H and c >= 1 and c <= curLvlW
        return tiles[r][c]
    ok
    return T_BRICK

func dave_tileIsSolid r, c
    if r < 1 or r > LVL_H or c < 1 or c > curLvlW return true ok
    t = tiles[r][c]
    if t = T_BRICK return true ok
    if t = T_DOOR return true ok
    return false

func dave_solidAt x, y
    r = dave_worldToRow(y)
    c = dave_worldToCol(x)
    return dave_tileIsSolid(r, c)

func dave_feetSolid x, y
    r = dave_worldToRow(y)
    c = dave_worldToCol(x)
    if r < 1 or r > LVL_H or c < 1 or c > curLvlW return true ok
    t = tiles[r][c]
    if t = T_BRICK return true ok
    if t = T_DOOR return true ok
    if t = T_PLATFORM
        tileTopY = (LVL_H - r + 1) * 1.0
        if py >= tileTopY - 0.1 and pvy <= 0
            return true
        ok
    ok
    if t = T_CRUMBLE
        tileTopY = (LVL_H - r + 1) * 1.0
        if py >= tileTopY - 0.1 and pvy <= 0
            return true
        ok
    ok
    // Ladder acts as ground when player is on top and has solid neighbor
    // (i.e. ladder was converted from brick, part of a walkable floor)
    if t = T_LADDER
        tileTopY = (LVL_H - r + 1) * 1.0
        if py >= tileTopY - 0.1 and pvy <= 0
            // Check if adjacent tiles are solid (this ladder is part of a floor)
            hasAdjacentSolid = false
            if c > 1
                nt = tiles[r][c-1]
                if nt = T_BRICK or nt = T_PLATFORM or nt = T_CRUMBLE or nt = T_DOOR
                    hasAdjacentSolid = true
                ok
            ok
            if c < curLvlW
                nt = tiles[r][c+1]
                if nt = T_BRICK or nt = T_PLATFORM or nt = T_CRUMBLE or nt = T_DOOR
                    hasAdjacentSolid = true
                ok
            ok
            if hasAdjacentSolid
                return true
            ok
        ok
    ok
    return false

func dave_headSolid x, y
    r = dave_worldToRow(y)
    c = dave_worldToCol(x)
    if r < 1 or r > LVL_H or c < 1 or c > curLvlW return true ok
    t = tiles[r][c]
    if t = T_BRICK return true ok
    if t = T_DOOR return true ok
    return false

func dave_enemyGroundSolid r, c
    if r < 1 or r > LVL_H or c < 1 or c > curLvlW return true ok
    t = tiles[r][c]
    if t = T_BRICK return true ok
    if t = T_DOOR return true ok
    if t = T_PLATFORM return true ok
    if t = T_CRUMBLE return true ok
    if t = T_SPIKE return true ok
    if t = T_LADDER return true ok
    return false

func dave_killPlayer
    gameState = ST_DYING
    dyingTimer = 1.5
    PlaySound(sndHurt)
    for i = 1 to 25
        ang = GetRandomValue(0, 628) / 100.0
        spd = GetRandomValue(200, 500) / 100.0
        add(particles, [px, py + 0.5,
                        cos(ang) * spd, sin(ang) * spd + 3.0,
                        1.2, 1.2,
                        255, GetRandomValue(100, 255), 0,
                        0.12])
    next

func dave_isOnMover
    pOnMover = false
    nMovers = len(movers)
    for m = 1 to nMovers
        mx = movers[m][1]
        my = movers[m][2]
        mw = movers[m][8]
        moverTop = my + 0.15
        // Check if player feet are near the top of this mover
        if px >= mx - mw * 0.5 - 0.4 and px <= mx + mw * 0.5 + 0.4
            dy = py - moverTop
            // Player must be near the top (within 0.5 above or 0.3 below) and falling/standing
            if dy >= -0.3 and dy <= 0.5 and pvy <= 0.5
                pOnGround = true
                pOnMover = true
                pvy = 0.0
                py = moverTop
                // Carry player with mover velocity
                px += movers[m][3] * GetFrameTime()
                py += movers[m][4] * GetFrameTime()
                return
            ok
        ok
    next
