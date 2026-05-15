/*
**  3D Cards Game - Using RingRayLib
**  ==================================
**  A two-player card matching game in full 3D!
**  Cards are rendered as 3D blocks on a felt table.
**  Reveal cards, match values, and capture them!
**
**  Based on the RingQt Cards Game by Mahmoud Fayed.
**
**  Controls:
**    Left/Right Arrow  - Move card cursor
**    Enter/Space       - Reveal selected card
**    Up/Down Arrow     - Navigate menu
**    Mouse Click       - Select and reveal a card
**    C                 - Cycle camera view
**    M                 - Back to menu (during game)
**    ESC               - Exit
**
**  Rules:
**    - Players alternate turns revealing face-down cards
**    - Each click reveals a random card from the deck
**    - If the revealed card matches any open card (same value),
**      the current player captures all matches + their card
**    - Card value 5 is WILD - captures ALL open cards!
**    - Round ends when all card slots are revealed
**    - Scores persist across rounds
**
**  Modes:
**    One Player   - Play against the computer
**    Two Players  - Play against a friend
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W    = 1024
SCREEN_H    = 768

// Game modes
GM_ONEPLAYER    = 1
GM_TWOPLAYERS   = 2

// Game states
ST_MENU     = 1
ST_PLAYING  = 2

// Card status
CS_HIDDEN   = 0
CS_OPEN     = 1
CS_EATEN    = 2

// Cards per player
CARDS_COUNT = 10

// Suits
SUIT_HEART  = 1
SUIT_DIAMOND = 2
SUIT_CLUB   = 3
SUIT_SPADE  = 4

// 3D Card dimensions (world units)
CARD3D_W    = 1.2
CARD3D_H    = 0.12
CARD3D_D    = 1.7
CARD3D_GAP  = 0.15

// Row Z positions (Player 1 = back, Player 2 = front)
ROW_P1_Z    = -2.8
ROW_P2_Z    = 2.8

// Table
TABLE_W     = 18.0
TABLE_D     = 12.0

// Delays (frames at 60fps)
DELAY_EAT       = 30
DELAY_NEWGAME   = 60
DELAY_COMPUTER  = 25

// Camera modes
CAM_FRONT       = 1
CAM_OVERHEAD    = 2
CAM_ANGLE       = 3
CAM_COUNT       = 3

// =============================================================
// Global Variables
// =============================================================

gameState   = ST_MENU
gameMode    = GM_TWOPLAYERS

// Deck
deckCards   = []

// Player 1 (back row)
p1Status    = []
p1Rank      = []
p1Suit      = []

// Player 2 (front row)
p2Status    = []
p2Rank      = []
p2Suit      = []

// Scores
p1Score     = 0
p2Score     = 0

// Turn
role        = 1

// Eat animation
eatAnimating    = false
eatTimer        = 0
eatPlayer       = 0
eatPos          = 0
eatValue        = 0

// Game over
gameOver        = false
gameOverTimer   = 0
winnerMsg       = ""

// Computer
computerTimer   = 0

// Keyboard
menuSel     = 1
cardCursor  = 1

// Animation
animTime    = 0.0
dt          = 0.0

// Camera
cameraMode  = CAM_FRONT
camPosX = 0.0   camPosY = 14.0  camPosZ = 11.0
camTgtX = 0.0   camTgtY = 0.0   camTgtZ = -0.5
camera  = NULL

// Particles: [x, y, z, vx, vy, vz, life, cr, cg, cb]
particles   = []

// Card 3D X positions
p1PosX      = []
p2PosX      = []

// Rank names
rankNames   = ["A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"]
suitSyms    = ["H", "D", "C", "S"]

// =============================================================
// Main
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "3D Cards Game - RingRayLib")
SetTargetFPS(60)
SetExitKey(0)

camera = Camera3D(
    0, 14, 11,
    0, 0, -0.5,
    0, 1, 0,
    45,
    CAMERA_PERSPECTIVE
)

c3d_calcPositions()

while !WindowShouldClose()
    dt = GetFrameTime()
    if dt > 0.05 dt = 0.05 ok
    animTime += dt

    if gameState = ST_MENU
        c3d_updateMenu()
    but gameState = ST_PLAYING
        c3d_updateGame()
    ok

    c3d_updateParticles()
    c3d_positionCamera()

    BeginDrawing()
        ClearBackground(RAYLIBColor(15, 12, 20, 255))

        if gameState = ST_MENU
            BeginMode3D(camera)
                c3d_drawTable()
            EndMode3D()
            c3d_drawMenuOverlay()
        but gameState = ST_PLAYING
            BeginMode3D(camera)
                c3d_drawTable()
                c3d_drawCards3D()
                c3d_drawParticles3D()
            EndMode3D()
            c3d_drawHUD()
        ok

        DrawFPS(SCREEN_W - 90, SCREEN_H - 25)
    EndDrawing()
end

CloseWindow()

// =============================================================
// Calculate 3D Card Positions
// =============================================================

func c3d_calcPositions
    p1PosX = []
    p2PosX = []
    totalW = CARDS_COUNT * CARD3D_W + (CARDS_COUNT - 1) * CARD3D_GAP
    startX = -totalW / 2 + CARD3D_W / 2
    for i = 1 to CARDS_COUNT
        add(p1PosX, startX + (i - 1) * (CARD3D_W + CARD3D_GAP))
        add(p2PosX, startX + (i - 1) * (CARD3D_W + CARD3D_GAP))
    next

// =============================================================
// Init Round
// =============================================================

func c3d_initRound
    deckCards = []
    for s = 1 to 4
        for r = 1 to 13
            add(deckCards, [r, s])
        next
    next
    for i = len(deckCards) to 2 step -1
        j = GetRandomValue(1, i)
        tmp = deckCards[i]
        deckCards[i] = deckCards[j]
        deckCards[j] = tmp
    next

    p1Status = list(CARDS_COUNT)
    p1Rank   = list(CARDS_COUNT)
    p1Suit   = list(CARDS_COUNT)
    p2Status = list(CARDS_COUNT)
    p2Rank   = list(CARDS_COUNT)
    p2Suit   = list(CARDS_COUNT)

    for i = 1 to CARDS_COUNT
        p1Status[i] = CS_HIDDEN
        p1Rank[i]   = 0
        p1Suit[i]   = 0
        p2Status[i] = CS_HIDDEN
        p2Rank[i]   = 0
        p2Suit[i]   = 0
    next

    role = 1
    gameOver = false
    gameOverTimer = 0
    winnerMsg = ""
    eatAnimating = false
    eatTimer = 0
    computerTimer = 0
    cardCursor = 1
    particles = []

// =============================================================
// Menu
// =============================================================

func c3d_updateMenu
    // ESC in menu = quit
    if IsKeyPressed(KEY_ESCAPE)
        CloseWindow()
        shutdown(0)
    ok

    // Keyboard
    if IsKeyPressed(KEY_UP)
        menuSel--
        if menuSel < 1 menuSel = 3 ok
    ok
    if IsKeyPressed(KEY_DOWN)
        menuSel++
        if menuSel > 3 menuSel = 1 ok
    ok
    if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
        c3d_menuSelect(menuSel)
    ok

    // Mouse
    mx = GetMouseX()
    my = GetMouseY()
    btnX = SCREEN_W/2 - 160
    btnW = 320
    btnH = 55
    if c3d_insideRect(mx, my, btnX, 310, btnW, btnH)
        menuSel = 1
        if IsMouseButtonPressed(MOUSE_LEFT_BUTTON) c3d_menuSelect(1) ok
    ok
    if c3d_insideRect(mx, my, btnX, 390, btnW, btnH)
        menuSel = 2
        if IsMouseButtonPressed(MOUSE_LEFT_BUTTON) c3d_menuSelect(2) ok
    ok
    if c3d_insideRect(mx, my, btnX, 470, btnW, btnH)
        menuSel = 3
        if IsMouseButtonPressed(MOUSE_LEFT_BUTTON) c3d_menuSelect(3) ok
    ok

func c3d_menuSelect nSel
    if nSel = 1
        gameMode = GM_ONEPLAYER
        c3d_initRound()
        gameState = ST_PLAYING
    ok
    if nSel = 2
        gameMode = GM_TWOPLAYERS
        c3d_initRound()
        gameState = ST_PLAYING
    ok
    if nSel = 3
        CloseWindow()
        shutdown(0)
    ok

func c3d_drawMenuOverlay
    // Dark overlay
    DrawRectangle(0, 0, SCREEN_W, SCREEN_H, RAYLIBColor(0, 0, 0, 160))

    // Title
    title = "3D Cards Game"
    tw = MeasureText(title, 56)
    DrawText(title, (SCREEN_W - tw)/2, 120, 56, WHITE)

    sub = "RingRayLib Edition"
    sw = MeasureText(sub, 22)
    DrawText(sub, (SCREEN_W - sw)/2, 185, 22, GOLD)

    // Buttons
    c3d_drawMenuBtn("One Player",  SCREEN_W/2 - 160, 310, 320, 55, menuSel = 1)
    c3d_drawMenuBtn("Two Players", SCREEN_W/2 - 160, 390, 320, 55, menuSel = 2)
    c3d_drawMenuBtn("Exit",        SCREEN_W/2 - 160, 470, 320, 55, menuSel = 3)

    // Instructions
    inst = "Up/Down: Navigate | Enter: Select | Mouse: Click"
    iw = MeasureText(inst, 16)
    DrawText(inst, (SCREEN_W - iw)/2, 560, 16, RAYLIBColor(180, 200, 180, 200))

func c3d_drawMenuBtn cText, nX, nY, nW, nH, lSel
    if lSel
        DrawRectangle(nX, nY, nW, nH, RAYLIBColor(255, 215, 0, 220))
        DrawRectangleLines(nX, nY, nW, nH, RAYLIBColor(200, 160, 0, 255))
        tw = MeasureText(cText, 28)
        DrawText(cText, nX + (nW - tw)/2, nY + (nH - 28)/2, 28, RAYLIBColor(20, 15, 10, 255))
    else
        DrawRectangle(nX, nY, nW, nH, RAYLIBColor(40, 35, 60, 220))
        DrawRectangleLines(nX, nY, nW, nH, RAYLIBColor(100, 90, 140, 200))
        tw = MeasureText(cText, 28)
        DrawText(cText, nX + (nW - tw)/2, nY + (nH - 28)/2, 28, RAYLIBColor(200, 200, 220, 255))
    ok

// =============================================================
// Game Update
// =============================================================

func c3d_updateGame
    // Eat animation - block ALL input
    if eatAnimating
        eatTimer++
        if eatTimer >= DELAY_EAT
            eatAnimating = false
            eatTimer = 0
            c3d_performEat(eatPlayer, eatPos, eatValue)
            c3d_checkNewGame()
            // Snap cursor to valid hidden card for the new active player
            c3d_resetCursor()
            if gameMode = GM_ONEPLAYER
                if role = 1
                    if !gameOver
                        computerTimer = DELAY_COMPUTER
                    ok
                ok
            ok
        ok
        return
    ok

    // Game over delay - block ALL input
    if gameOver
        gameOverTimer++
        if gameOverTimer >= DELAY_NEWGAME
            c3d_initRound()
        ok
        return
    ok

    // Computer turn - block ALL input
    if gameMode = GM_ONEPLAYER
        if role = 1
            computerTimer++
            if computerTimer >= DELAY_COMPUTER
                computerTimer = 0
                c3d_computerAction()
            ok
            return
        ok
    ok

    // === Human input (only the active player via role) ===

    // Camera toggle
    if IsKeyPressed(KEY_C)
        cameraMode++
        if cameraMode > CAM_COUNT
            cameraMode = CAM_FRONT
        ok
    ok

    // Back to menu
    if IsKeyPressed(KEY_M) or IsKeyPressed(KEY_ESCAPE)
        gameState = ST_MENU
        return
    ok

    // Keyboard card selection (Left/Right)
    if IsKeyPressed(KEY_LEFT)
        cardCursor--
        if cardCursor < 1 cardCursor = CARDS_COUNT ok
        c3d_snapCursorLeft()
    ok
    if IsKeyPressed(KEY_RIGHT)
        cardCursor++
        if cardCursor > CARDS_COUNT cardCursor = 1 ok
        c3d_snapCursorRight()
    ok

    // Keyboard confirm - pick card for the active player (role)
    if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
        c3d_pickCard(cardCursor)
    ok

    // Mouse click - pick card for the active player (role)
    if !eatAnimating
        if IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
            mx = GetMouseX()
            my = GetMouseY()
            if c3d_insideRect(mx, my, SCREEN_W - 110, 10, 100, 30)
                gameState = ST_MENU
                return
            ok
            mouseRay = GetMouseRay(GetMousePosition(), camera)
            c3d_pickCardByMouse(mouseRay)
        ok
    ok

// =============================================================
// Unified pick: uses role to decide which player's card to pick
// =============================================================

func c3d_pickCard pos
    if pos < 1 return ok
    if pos > CARDS_COUNT return ok
    if eatAnimating return ok
    if role = 1
        if p1Status[pos] = CS_HIDDEN
            c3d_player1Click(pos)
        ok
        return
    ok
    if role = 2
        if p2Status[pos] = CS_HIDDEN
            c3d_player2Click(pos)
        ok
    ok

func c3d_pickCardByMouse mouseRay
    if eatAnimating return ok
    if role = 1
        for i = 1 to CARDS_COUNT
            if p1Status[i] = CS_HIDDEN
                if c3d_rayHitsCard(mouseRay, p1PosX[i], ROW_P1_Z)
                    cardCursor = i
                    c3d_player1Click(i)
                    return
                ok
            ok
        next
        return
    ok
    if role = 2
        for i = 1 to CARDS_COUNT
            if p2Status[i] = CS_HIDDEN
                if c3d_rayHitsCard(mouseRay, p2PosX[i], ROW_P2_Z)
                    cardCursor = i
                    c3d_player2Click(i)
                    return
                ok
            ok
        next
    ok

// =============================================================
// Ray-AABB Hit Test for Card (3D mouse picking)
// =============================================================

func c3d_rayHitsCard mouseRay, cx, cz
    minX = cx - CARD3D_W / 2
    minY = 0.0
    minZ = cz - CARD3D_D / 2
    maxX = cx + CARD3D_W / 2
    maxY = CARD3D_H + 0.3
    maxZ = cz + CARD3D_D / 2
    box = BoundingBox(minX, minY, minZ, maxX, maxY, maxZ)
    collision = GetRayCollisionBox(mouseRay, box)
    return collision.hit

// =============================================================
// Camera
// =============================================================

func c3d_positionCamera
    goalX = 0  goalY = 0  goalZ = 0
    tgtX = 0   tgtY = 0   tgtZ = 0

    if cameraMode = CAM_FRONT
        goalX = 0
        goalY = 14.0
        goalZ = 11.0
        tgtX = 0
        tgtY = 0.0
        tgtZ = -0.5
    ok
    if cameraMode = CAM_OVERHEAD
        goalX = 0
        goalY = 18.0
        goalZ = 0.5
        tgtX = 0
        tgtY = 0
        tgtZ = 0
    ok
    if cameraMode = CAM_ANGLE
        goalX = 8.0
        goalY = 14.0
        goalZ = 8.0
        tgtX = 0
        tgtY = 0.0
        tgtZ = 0
    ok

    lerpSpd = 0.05
    camPosX += (goalX - camPosX) * lerpSpd
    camPosY += (goalY - camPosY) * lerpSpd
    camPosZ += (goalZ - camPosZ) * lerpSpd
    camTgtX += (tgtX - camTgtX) * lerpSpd
    camTgtY += (tgtY - camTgtY) * lerpSpd
    camTgtZ += (tgtZ - camTgtZ) * lerpSpd

    camera.position.x = camPosX
    camera.position.y = camPosY
    camera.position.z = camPosZ
    camera.target.x   = camTgtX
    camera.target.y   = camTgtY
    camera.target.z   = camTgtZ

// =============================================================
// 3D Drawing: Table
// =============================================================

func c3d_drawTable
    // Table surface (felt green)
    DrawCube(Vector3(0, -0.15, 0), TABLE_W, 0.3, TABLE_D,
             RAYLIBColor(30, 110, 55, 255))
    DrawCubeWires(Vector3(0, -0.15, 0), TABLE_W, 0.3, TABLE_D,
                  RAYLIBColor(20, 80, 40, 200))

    // Table border (wood frame)
    bThick = 0.4
    bH = 0.35
    halfW = TABLE_W / 2 + 0.1
    halfD = TABLE_D / 2 + 0.1
    woodCol = RAYLIBColor(100, 60, 25, 255)
    woodWire = RAYLIBColor(70, 40, 15, 200)

    DrawCube(Vector3(0, bH/2, -halfD), TABLE_W + 0.4, bH, bThick, woodCol)
    DrawCube(Vector3(0, bH/2, halfD),  TABLE_W + 0.4, bH, bThick, woodCol)
    DrawCube(Vector3(-halfW, bH/2, 0), bThick, bH, TABLE_D + 0.2, woodCol)
    DrawCube(Vector3(halfW, bH/2, 0),  bThick, bH, TABLE_D + 0.2, woodCol)

    DrawCubeWires(Vector3(0, bH/2, -halfD), TABLE_W + 0.4, bH, bThick, woodWire)
    DrawCubeWires(Vector3(0, bH/2, halfD),  TABLE_W + 0.4, bH, bThick, woodWire)
    DrawCubeWires(Vector3(-halfW, bH/2, 0), bThick, bH, TABLE_D + 0.2, woodWire)
    DrawCubeWires(Vector3(halfW, bH/2, 0),  bThick, bH, TABLE_D + 0.2, woodWire)

    // Floor beneath
    DrawPlane(Vector3(0, -0.31, 0), Vector2(50, 50),
              RAYLIBColor(10, 8, 14, 255))

    // Player zone labels on table (as thin colored strips)
    DrawCube(Vector3(0, 0.01, ROW_P1_Z), TABLE_W - 1.0, 0.02, CARD3D_D + 0.6,
             RAYLIBColor(80, 0, 100, 40))
    DrawCube(Vector3(0, 0.01, ROW_P2_Z), TABLE_W - 1.0, 0.02, CARD3D_D + 0.6,
             RAYLIBColor(150, 20, 20, 40))

// =============================================================
// 3D Drawing: Cards
// =============================================================

func c3d_drawCards3D
    // Player 1 cards (back row)
    for i = 1 to CARDS_COUNT
        lCursor = (role = 1 and gameMode = GM_TWOPLAYERS and cardCursor = i)
        c3d_drawCard3D(p1PosX[i], ROW_P1_Z, p1Status[i], p1Rank[i], p1Suit[i], 1, lCursor)
    next

    // Player 2 cards (front row)
    for i = 1 to CARDS_COUNT
        lCursor = (role = 2 and cardCursor = i)
        c3d_drawCard3D(p2PosX[i], ROW_P2_Z, p2Status[i], p2Rank[i], p2Suit[i], 2, lCursor)
    next

func c3d_drawCard3D cx, cz, nStatus, nRank, nSuit, nPlayer, lCursor
    cardY = CARD3D_H / 2 + 0.01

    if nStatus = CS_HIDDEN
        // Face-down card - blue
        DrawCube(Vector3(cx, cardY, cz), CARD3D_W, CARD3D_H, CARD3D_D,
                 RAYLIBColor(30, 50, 130, 255))
        DrawCubeWires(Vector3(cx, cardY, cz), CARD3D_W, CARD3D_H, CARD3D_D,
                      RAYLIBColor(20, 35, 90, 255))
        // Decorative top face pattern
        DrawCube(Vector3(cx, cardY + CARD3D_H/2 + 0.005, cz),
                 CARD3D_W * 0.7, 0.01, CARD3D_D * 0.7,
                 RAYLIBColor(50, 75, 170, 255))

    but nStatus = CS_OPEN
        // Face-up card - white with colored top
        DrawCube(Vector3(cx, cardY, cz), CARD3D_W, CARD3D_H, CARD3D_D,
                 RAYLIBColor(250, 250, 245, 255))
        DrawCubeWires(Vector3(cx, cardY, cz), CARD3D_W, CARD3D_H, CARD3D_D,
                      RAYLIBColor(100, 100, 100, 200))

        // Colored top face based on suit
        if nSuit = SUIT_HEART or nSuit = SUIT_DIAMOND
            topCol = RAYLIBColor(220, 40, 40, 255)
        else
            topCol = RAYLIBColor(30, 30, 30, 255)
        ok
        DrawCube(Vector3(cx, cardY + CARD3D_H/2 + 0.005, cz),
                 CARD3D_W * 0.85, 0.01, CARD3D_D * 0.85, topCol)

        // Wild card glow (rank 5)
        if nRank = 5
            pulse = 0.5 + sin(animTime * 4.0) * 0.3
            glowA = floor(80 * pulse)
            DrawCube(Vector3(cx, cardY, cz),
                     CARD3D_W + 0.15, CARD3D_H + 0.15, CARD3D_D + 0.15,
                     RAYLIBColor(255, 215, 0, glowA))
        ok

    but nStatus = CS_EATEN
        // Eaten card - colored by capturing player, flat
        if nPlayer = 1
            eCol = RAYLIBColor(120, 40, 160, 255)
            eWire = RAYLIBColor(80, 20, 110, 200)
        else
            eCol = RAYLIBColor(180, 40, 40, 255)
            eWire = RAYLIBColor(130, 20, 20, 200)
        ok
        flatH = 0.06
        DrawCube(Vector3(cx, flatH/2 + 0.01, cz), CARD3D_W, flatH, CARD3D_D, eCol)
        DrawCubeWires(Vector3(cx, flatH/2 + 0.01, cz), CARD3D_W, flatH, CARD3D_D, eWire)
    ok

    // Cursor highlight (pulsing golden ring around card)
    if lCursor
        pulse = 0.6 + sin(animTime * 5.0) * 0.4
        cursorA = floor(160 * pulse)
        DrawCubeWires(Vector3(cx, cardY + 0.02, cz),
                      CARD3D_W + 0.2, CARD3D_H + 0.1, CARD3D_D + 0.2,
                      RAYLIBColor(255, 255, 100, cursorA))
        DrawCubeWires(Vector3(cx, cardY + 0.02, cz),
                      CARD3D_W + 0.3, CARD3D_H + 0.15, CARD3D_D + 0.3,
                      RAYLIBColor(255, 215, 0, floor(cursorA * 0.5)))
    ok

// =============================================================
// 3D-to-Screen Projection for Labels
// =============================================================

func c3d_projectToScreen wx, wy, wz
    fwdX = camTgtX - camPosX
    fwdY = camTgtY - camPosY
    fwdZ = camTgtZ - camPosZ
    fLen = sqrt(fwdX*fwdX + fwdY*fwdY + fwdZ*fwdZ)
    if fLen < 0.0001
        return [-9999, -9999]
    ok
    fwdX = fwdX / fLen
    fwdY = fwdY / fLen
    fwdZ = fwdZ / fLen

    rightX = -fwdZ
    rightY = 0
    rightZ = fwdX
    rLen = sqrt(rightX*rightX + rightY*rightY + rightZ*rightZ)
    if rLen < 0.0001
        return [-9999, -9999]
    ok
    rightX = rightX / rLen
    rightZ = rightZ / rLen

    upX = rightY * fwdZ - rightZ * fwdY
    upY = rightZ * fwdX - rightX * fwdZ
    upZ = rightX * fwdY - rightY * fwdX

    dx = wx - camPosX
    dy = wy - camPosY
    dz = wz - camPosZ
    dotFwd   = dx * fwdX   + dy * fwdY   + dz * fwdZ
    dotRight = dx * rightX + dy * rightY + dz * rightZ
    dotUp    = dx * upX    + dy * upY    + dz * upZ

    if dotFwd < 0.01
        return [-9999, -9999]
    ok

    fovRad = 45.0 * 3.14159265 / 180.0
    tanHalf = tan(fovRad / 2.0)
    aspect = SCREEN_W * 1.0 / SCREEN_H

    ndcX = (dotRight / dotFwd) / (tanHalf * aspect)
    ndcY = (dotUp / dotFwd) / tanHalf

    scrX = (ndcX * 0.5 + 0.5) * SCREEN_W
    scrY = (1.0 - (ndcY * 0.5 + 0.5)) * SCREEN_H

    return [scrX, scrY]

// =============================================================
// HUD (2D overlay after EndMode3D)
// =============================================================

func c3d_drawHUD
    // Player 1 bar (top)
    DrawRectangle(0, 0, SCREEN_W, 45, RAYLIBColor(100, 0, 130, 220))
    p1Text = "Player (1) - Score: " + string(p1Score)
    if gameMode = GM_ONEPLAYER
        p1Text = "Computer - Score: " + string(p1Score)
    ok
    tw = MeasureText(p1Text, 24)
    DrawText(p1Text, (SCREEN_W - tw)/2, 10, 24, WHITE)
    if role = 1 and !gameOver
        DrawRectangle(0, 45, SCREEN_W, 3, GOLD)
    ok

    // Player 2 bar (bottom)
    DrawRectangle(0, SCREEN_H - 78, SCREEN_W, 45, RAYLIBColor(180, 30, 30, 220))
    p2Text = "Player (2) - Score: " + string(p2Score)
    tw2 = MeasureText(p2Text, 24)
    DrawText(p2Text, (SCREEN_W - tw2)/2, SCREEN_H - 68, 24, WHITE)
    if role = 2 and !gameOver
        DrawRectangle(0, SCREEN_H - 82, SCREEN_W, 3, GOLD)
    ok

    // Turn / status text
    turnText = ""
    if gameOver
        turnText = winnerMsg
    else
        if eatAnimating
            turnText = "Checking for matches..."
        but role = 1
            if gameMode = GM_ONEPLAYER
                turnText = "Computer is thinking..."
            else
                turnText = "Player 1's Turn"
            ok
        but role = 2
            turnText = "Player 2's Turn"
        ok
    ok
    ttw = MeasureText(turnText, 22)
    DrawRectangle((SCREEN_W - ttw)/2 - 12, 54, ttw + 24, 30,
                  RAYLIBColor(0, 0, 0, 160))
    DrawText(turnText, (SCREEN_W - ttw)/2, 58, 22, WHITE)

    // Eat pulse
    if eatAnimating
        pulse = floor(sin(animTime * 8.0) * 60 + 195)
        starTxt = "* * *"
        starW = MeasureText(starTxt, 16)
        DrawText(starTxt, (SCREEN_W - starW)/2, 86, 16,
                 RAYLIBColor(255, 215, 0, pulse))
    ok

    // Card value labels (projected from 3D onto 2D)
    c3d_drawCardLabels()

    // Controls bar
    DrawRectangle(0, SCREEN_H - 35, SCREEN_W, 35, RAYLIBColor(0, 0, 0, 180))
    ctrlTxt = "Left/Right: Select | Enter: Reveal | C: Camera | M: Menu | Card 5 = WILD"
    ctrlW = MeasureText(ctrlTxt, 14)
    DrawText(ctrlTxt, (SCREEN_W - ctrlW)/2, SCREEN_H - 25, 14,
             RAYLIBColor(180, 180, 180, 200))

    // Camera mode indicator
    camNames = ["Front", "Overhead", "Angle"]
    camTxt = "Cam: " + camNames[cameraMode]
    DrawText(camTxt, SCREEN_W - 120, 55, 14, RAYLIBColor(200, 200, 200, 180))

    // Menu button (top-right)
    menuBtnX = SCREEN_W - 110
    menuBtnY = 10
    menuBtnW = 100
    menuBtnH = 30
    mx = GetMouseX()
    my = GetMouseY()
    if c3d_insideRect(mx, my, menuBtnX, menuBtnY, menuBtnW, menuBtnH)
        DrawRectangle(menuBtnX, menuBtnY, menuBtnW, menuBtnH, RAYLIBColor(255, 215, 0, 220))
        mtw = MeasureText("Menu", 20)
        DrawText("Menu", menuBtnX + (menuBtnW - mtw)/2, menuBtnY + 5, 20, RAYLIBColor(20, 15, 10, 255))
    else
        DrawRectangle(menuBtnX, menuBtnY, menuBtnW, menuBtnH, RAYLIBColor(60, 50, 90, 220))
        DrawRectangleLines(menuBtnX, menuBtnY, menuBtnW, menuBtnH, RAYLIBColor(150, 130, 180, 200))
        mtw = MeasureText("Menu", 20)
        DrawText("Menu", menuBtnX + (menuBtnW - mtw)/2, menuBtnY + 5, 20, WHITE)
    ok

// =============================================================
// Card Labels (projected 3D to 2D)
// =============================================================

func c3d_drawCardLabels
    labelY = CARD3D_H + 0.3

    // Player 1 labels
    for i = 1 to CARDS_COUNT
        if p1Status[i] = CS_OPEN
            pos = c3d_projectToScreen(p1PosX[i], labelY, ROW_P1_Z)
            if pos[1] > -100 and pos[1] < SCREEN_W + 100
                valStr = rankNames[p1Rank[i]]
                fontSize = 20
                vw = MeasureText(valStr, fontSize)
                sx = floor(pos[1]) - vw/2
                sy = floor(pos[2]) - fontSize/2
                DrawRectangle(sx - 4, sy - 2, vw + 8, fontSize + 4,
                              RAYLIBColor(0, 0, 0, 170))
                if p1Suit[i] = SUIT_HEART or p1Suit[i] = SUIT_DIAMOND
                    txtCol = RAYLIBColor(255, 80, 80, 255)
                else
                    txtCol = RAYLIBColor(240, 240, 240, 255)
                ok
                DrawText(valStr, sx, sy, fontSize, txtCol)

                // Wild indicator
                if p1Rank[i] = 5
                    wt = "WILD"
                    ww = MeasureText(wt, 10)
                    DrawText(wt, sx + (vw - ww)/2, sy + fontSize + 2, 10,
                             RAYLIBColor(255, 215, 0, 220))
                ok
            ok
        ok
    next

    // Player 2 labels
    for i = 1 to CARDS_COUNT
        if p2Status[i] = CS_OPEN
            pos = c3d_projectToScreen(p2PosX[i], labelY, ROW_P2_Z)
            if pos[1] > -100 and pos[1] < SCREEN_W + 100
                valStr = rankNames[p2Rank[i]]
                fontSize = 20
                vw = MeasureText(valStr, fontSize)
                sx = floor(pos[1]) - vw/2
                sy = floor(pos[2]) - fontSize/2
                DrawRectangle(sx - 4, sy - 2, vw + 8, fontSize + 4,
                              RAYLIBColor(0, 0, 0, 170))
                if p2Suit[i] = SUIT_HEART or p2Suit[i] = SUIT_DIAMOND
                    txtCol = RAYLIBColor(255, 80, 80, 255)
                else
                    txtCol = RAYLIBColor(240, 240, 240, 255)
                ok
                DrawText(valStr, sx, sy, fontSize, txtCol)

                if p2Rank[i] = 5
                    wt = "WILD"
                    ww = MeasureText(wt, 10)
                    DrawText(wt, sx + (vw - ww)/2, sy + fontSize + 2, 10,
                             RAYLIBColor(255, 215, 0, 220))
                ok
            ok
        ok
    next

// =============================================================
// Particles
// =============================================================

func c3d_spawnEatParticles cx, cz, nPlayer
    if nPlayer = 1
        cr0 = 180  cg0 = 80  cb0 = 220
    else
        cr0 = 240  cg0 = 60  cb0 = 60
    ok
    for i = 1 to 12
        vx = (GetRandomValue(-100, 100) / 100.0) * 2.0
        vy = (GetRandomValue(200, 500) / 100.0)
        vz = (GetRandomValue(-100, 100) / 100.0) * 2.0
        cr = cr0 + GetRandomValue(-30, 30)
        cg = cg0 + GetRandomValue(-30, 30)
        cb = cb0 + GetRandomValue(-20, 20)
        if cr > 255 cr = 255 ok  if cr < 0 cr = 0 ok
        if cg > 255 cg = 255 ok  if cg < 0 cg = 0 ok
        if cb > 255 cb = 255 ok  if cb < 0 cb = 0 ok
        add(particles, [cx, 0.3, cz, vx, vy, vz, 1.5, cr, cg, cb])
    next

func c3d_updateParticles
    i = 1
    while i <= len(particles)
        particles[i][1] += particles[i][4] * dt
        particles[i][2] += particles[i][5] * dt
        particles[i][3] += particles[i][6] * dt
        particles[i][5] -= 6.0 * dt
        particles[i][7] -= dt
        if particles[i][7] <= 0
            del(particles, i)
        else
            i += 1
        ok
    end

func c3d_drawParticles3D
    for i = 1 to len(particles)
        p = particles[i]
        alpha = floor((p[7] / 1.5) * 255)
        if alpha > 255 alpha = 255 ok
        if alpha < 0 alpha = 0 ok
        sz = 0.04 + p[7] * 0.06
        DrawSphere(Vector3(p[1], p[2], p[3]),
                   sz, RAYLIBColor(p[8], p[9], p[10], alpha))
    next

// =============================================================
// Game Logic
// =============================================================

func c3d_player1Click x
    if role != 1 return ok
    if p1Status[x] != CS_HIDDEN return ok
    if len(deckCards) < 1 return ok

    nPos = GetRandomValue(1, len(deckCards))
    card = deckCards[nPos]
    p1Rank[x] = card[1]
    p1Suit[x] = card[2]
    p1Status[x] = CS_OPEN
    del(deckCards, nPos)

    role = 2

    eatAnimating = true
    eatTimer = 0
    eatPlayer = 1
    eatPos = x
    eatValue = p1Rank[x]

func c3d_player2Click x
    if role != 2 return ok
    if p2Status[x] != CS_HIDDEN return ok
    if len(deckCards) < 1 return ok

    nPos = GetRandomValue(1, len(deckCards))
    card = deckCards[nPos]
    p2Rank[x] = card[1]
    p2Suit[x] = card[2]
    p2Status[x] = CS_OPEN
    del(deckCards, nPos)

    role = 1

    eatAnimating = true
    eatTimer = 0
    eatPlayer = 2
    eatPos = x
    eatValue = p2Rank[x]

// =============================================================
// Eat Logic
// =============================================================

func c3d_performEat nPlayer, nPos, nValue
    if nPlayer = 1
        lEat = false
        for x = 1 to CARDS_COUNT
            if p2Status[x] = CS_OPEN and (p2Rank[x] = nValue or nValue = 5)
                p2Status[x] = CS_EATEN
                c3d_spawnEatParticles(p2PosX[x], ROW_P2_Z, 1)
                lEat = true
                p1Score++
            ok
            if x != nPos and p1Status[x] = CS_OPEN and (p1Rank[x] = nValue or nValue = 5)
                p1Status[x] = CS_EATEN
                c3d_spawnEatParticles(p1PosX[x], ROW_P1_Z, 1)
                lEat = true
                p1Score++
            ok
        next
        if lEat
            p1Score++
            p1Status[nPos] = CS_EATEN
            c3d_spawnEatParticles(p1PosX[nPos], ROW_P1_Z, 1)
        ok
    ok

    if nPlayer = 2
        lEat = false
        for x = 1 to CARDS_COUNT
            if p1Status[x] = CS_OPEN and (p1Rank[x] = nValue or nValue = 5)
                p1Status[x] = CS_EATEN
                c3d_spawnEatParticles(p1PosX[x], ROW_P1_Z, 2)
                lEat = true
                p2Score++
            ok
            if x != nPos and p2Status[x] = CS_OPEN and (p2Rank[x] = nValue or nValue = 5)
                p2Status[x] = CS_EATEN
                c3d_spawnEatParticles(p2PosX[x], ROW_P2_Z, 2)
                lEat = true
                p2Score++
            ok
        next
        if lEat
            p2Score++
            p2Status[nPos] = CS_EATEN
            c3d_spawnEatParticles(p2PosX[nPos], ROW_P2_Z, 2)
        ok
    ok

// =============================================================
// Check New Game
// =============================================================

func c3d_checkNewGame
    if !c3d_isRoundOver() return ok

    gameOver = true
    gameOverTimer = 0

    if p1Score > p2Score
        if gameMode = GM_ONEPLAYER
            winnerMsg = "Computer Wins!!!"
        else
            winnerMsg = "Player (1) Wins!!!"
        ok
    but p2Score > p1Score
        winnerMsg = "Player (2) Wins!!!"
    else
        winnerMsg = "It's a Draw!"
    ok

func c3d_isRoundOver
    for i = 1 to CARDS_COUNT
        if p1Status[i] = CS_HIDDEN return false ok
    next
    for i = 1 to CARDS_COUNT
        if p2Status[i] = CS_HIDDEN return false ok
    next
    return true

// =============================================================
// Computer Player
// =============================================================

func c3d_computerAction
    aOptions = []
    for i = 1 to CARDS_COUNT
        if p1Status[i] = CS_HIDDEN
            add(aOptions, i)
        ok
    next
    if len(aOptions) > 0
        idx = GetRandomValue(1, len(aOptions))
        c3d_player1Click(aOptions[idx])
    ok

// =============================================================
// Cursor Snap Helpers
// =============================================================

func c3d_snapCursorLeft
    aStatus = c3d_currentStatus()
    startPos = cardCursor
    for tries = 1 to CARDS_COUNT
        if aStatus[cardCursor] = CS_HIDDEN return ok
        cardCursor--
        if cardCursor < 1 cardCursor = CARDS_COUNT ok
    next
    cardCursor = startPos

func c3d_snapCursorRight
    aStatus = c3d_currentStatus()
    startPos = cardCursor
    for tries = 1 to CARDS_COUNT
        if aStatus[cardCursor] = CS_HIDDEN return ok
        cardCursor++
        if cardCursor > CARDS_COUNT cardCursor = 1 ok
    next
    cardCursor = startPos

func c3d_resetCursor
    // Find next hidden card for the current player, starting near current cursor
    aStatus = c3d_currentStatus()
    // Try from current position forward first
    for i = cardCursor to CARDS_COUNT
        if aStatus[i] = CS_HIDDEN
            cardCursor = i
            return
        ok
    next
    // Wrap around from beginning
    for i = 1 to cardCursor - 1
        if aStatus[i] = CS_HIDDEN
            cardCursor = i
            return
        ok
    next
    cardCursor = 1

func c3d_currentStatus
    if role = 1 return p1Status ok
    return p2Status

// =============================================================
// Utility
// =============================================================

func c3d_insideRect mx, my, rx, ry, rw, rh
    if mx >= rx and mx <= rx + rw and my >= ry and my <= ry + rh
        return true
    ok
    return false
