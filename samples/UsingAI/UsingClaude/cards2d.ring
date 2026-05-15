/*
**  Cards Game - Using RingRayLib
**  ==============================
**  A two-player card matching game where players take turns
**  revealing cards. Matching cards get "eaten" (captured).
**  Value 5 is wild and captures all revealed cards!
**
**  Based on the RingQt Cards Game by Mahmoud Fayed.
**
**  Controls:
**    Mouse Click       - Select a card to reveal
**    Left/Right Arrow  - Move card selection cursor
**    Enter/Space       - Reveal selected card
**    Up/Down Arrow     - Navigate menu options
**    M                 - Back to menu (during game)
**    ESC               - Exit
**
**  Rules:
**    - Players alternate turns clicking face-down cards
**    - Each click reveals a random card from the deck
**    - If the revealed card matches any open card (same value),
**      the current player captures all matches + their card
**    - Card value 5 is WILD - it captures ALL open cards!
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

SCREEN_W    = 1200
SCREEN_H    = 700

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

// Card dimensions for display
CARD_W      = 85
CARD_H      = 120
CARD_RAD    = 6

// Cards per player
CARDS_COUNT = 10

// Suits
SUIT_HEART  = 1
SUIT_DIAMOND = 2
SUIT_CLUB   = 3
SUIT_SPADE  = 4

// Delays (frames at 60fps)
DELAY_EAT       = 30
DELAY_NEWGAME   = 45
DELAY_COMPUTER  = 25

// =============================================================
// Global Variables
// =============================================================

gameState   = ST_MENU
gameMode    = GM_TWOPLAYERS

// Deck (cards remaining to draw)
deckCards   = []        // Each item: [rank, suit]

// Player 1 (top row)
p1Status    = []        // CS_HIDDEN / CS_OPEN / CS_EATEN
p1Rank      = []        // Card rank 1-13
p1Suit      = []        // Card suit 1-4

// Player 2 (bottom row)
p2Status    = []
p2Rank      = []
p2Suit      = []

// Scores (persist across rounds)
p1Score     = 0
p2Score     = 0

// Turn: 1 = Player 1, 2 = Player 2
role        = 1

// Animation/delay
eatAnimating    = false
eatTimer        = 0
eatPlayer       = 0
eatPos          = 0
eatValue        = 0

gameOver        = false
gameOverTimer   = 0
winnerMsg       = ""

// Computer
computerTimer   = 0

// Card positions (calculated once)
p1X         = []
p1Y         = 0
p2X         = []
p2Y         = 0

// Menu hover
menuHover   = 0

// Menu keyboard selection (1=OnePlayer, 2=TwoPlayers, 3=Exit)
menuSel     = 1

// Card keyboard cursor (1 to CARDS_COUNT, 0 = no keyboard selection)
cardCursor  = 0

// Animation time
animTime    = 0.0

// Suit symbols and rank names for drawing
suitSyms    = ["H", "D", "C", "S"]
rankNames   = ["A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"]

// =============================================================
// Main
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "The Cards Game - RingRayLib")
SetTargetFPS(60)
SetExitKey(0)

cards_calcPositions()

while !WindowShouldClose()
    dt = GetFrameTime()
    if dt > 0.05 dt = 0.05 ok
    animTime += dt

    BeginDrawing()
    if gameState = ST_MENU
        cards_updateMenu()
        cards_drawMenu()
    but gameState = ST_PLAYING
        cards_updateGame()
        cards_drawGame()
    ok
    EndDrawing()
end

CloseWindow()

// =============================================================
// Calculate Card Positions
// =============================================================

func cards_calcPositions
    p1X = []
    p2X = []
    totalW = CARDS_COUNT * CARD_W + (CARDS_COUNT - 1) * 12
    startX = (SCREEN_W - totalW) / 2
    for i = 1 to CARDS_COUNT
        add(p1X, startX + (i - 1) * (CARD_W + 12))
        add(p2X, startX + (i - 1) * (CARD_W + 12))
    next
    p1Y = 95
    p2Y = SCREEN_H - CARD_H - 95

// =============================================================
// Initialize New Round
// =============================================================

func cards_initRound
    // Build deck: 52 cards (4 suits x 13 ranks)
    deckCards = []
    for s = 1 to 4
        for r = 1 to 13
            add(deckCards, [r, s])
        next
    next

    // Shuffle the deck
    for i = len(deckCards) to 2 step -1
        j = GetRandomValue(1, i)
        tmp = deckCards[i]
        deckCards[i] = deckCards[j]
        deckCards[j] = tmp
    next

    // Init player slots
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

// =============================================================
// Menu
// =============================================================

func cards_updateMenu
    mx = GetMouseX()
    my = GetMouseY()

    // ESC in menu = quit
    if IsKeyPressed(KEY_ESCAPE)
        CloseWindow()
        shutdown(0)
    ok

    // Update mouse hover
    menuHover = 0
    if cards_insideRect(mx, my, SCREEN_W/2 - 160, 260, 320, 65)
        menuHover = 1
    ok
    if cards_insideRect(mx, my, SCREEN_W/2 - 160, 350, 320, 65)
        menuHover = 2
    ok
    if cards_insideRect(mx, my, SCREEN_W/2 - 160, 440, 320, 65)
        menuHover = 3
    ok

    // If mouse hovers, sync keyboard selection to it
    if menuHover > 0
        menuSel = menuHover
    ok

    // Keyboard navigation
    if IsKeyPressed(KEY_UP)
        menuSel--
        if menuSel < 1 menuSel = 3 ok
    ok
    if IsKeyPressed(KEY_DOWN)
        menuSel++
        if menuSel > 3 menuSel = 1 ok
    ok

    // Mouse click
    if IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
        if menuHover > 0
            menuSel = menuHover
            cards_menuSelect(menuSel)
        ok
    ok

    // Keyboard confirm
    if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
        cards_menuSelect(menuSel)
    ok

func cards_menuSelect nSel
    if nSel = 1
        gameMode = GM_ONEPLAYER
        cards_initRound()
        gameState = ST_PLAYING
    ok
    if nSel = 2
        gameMode = GM_TWOPLAYERS
        cards_initRound()
        gameState = ST_PLAYING
    ok
    if nSel = 3
        CloseWindow()
        shutdown(0)
    ok

func cards_drawMenu
    ClearBackground(RAYLIBColor(25, 100, 50, 255))

    // Title
    title = "The Cards Game"
    tw = MeasureText(title, 56)
    DrawText(title, (SCREEN_W - tw) / 2, 100, 56, WHITE)

    // Subtitle
    sub = "RayLib Edition"
    sw = MeasureText(sub, 22)
    DrawText(sub, (SCREEN_W - sw) / 2, 170, 22, GOLD)

    // Decorative cards on sides
    cards_drawCardFace(80, 200, 5, SUIT_HEART, true, false)
    cards_drawCardFace(SCREEN_W - 80 - CARD_W, 200, 13, SUIT_SPADE, true, false)
    cards_drawCardFace(140, 350, 1, SUIT_DIAMOND, true, false)
    cards_drawCardFace(SCREEN_W - 140 - CARD_W, 350, 1, SUIT_CLUB, true, false)

    // Buttons (highlight based on keyboard selection)
    cards_drawMenuBtn("One Player", SCREEN_W/2 - 160, 260, 320, 65, menuSel = 1)
    cards_drawMenuBtn("Two Players", SCREEN_W/2 - 160, 350, 320, 65, menuSel = 2)
    cards_drawMenuBtn("Exit", SCREEN_W/2 - 160, 440, 320, 65, menuSel = 3)

    // Instructions
    inst = "Up/Down: Navigate | Enter: Select | Mouse: Click"
    iw = MeasureText(inst, 20)
    DrawText(inst, (SCREEN_W - iw) / 2, 540, 20, RAYLIBColor(180, 220, 180, 200))

func cards_drawMenuBtn cText, nX, nY, nW, nH, lHover
    if lHover
        DrawRectangle(nX, nY, nW, nH, RAYLIBColor(173, 216, 230, 255))
        DrawRectangleLines(nX, nY, nW, nH, RAYLIBColor(0, 0, 80, 255))
        tw = MeasureText(cText, 30)
        DrawText(cText, nX + (nW - tw)/2, nY + (nH - 30)/2, 30, RAYLIBColor(0, 0, 80, 255))
    else
        DrawRectangle(nX, nY, nW, nH, RAYLIBColor(0, 0, 80, 255))
        DrawRectangleLines(nX, nY, nW, nH, RAYLIBColor(173, 216, 230, 255))
        tw = MeasureText(cText, 30)
        DrawText(cText, nX + (nW - tw)/2, nY + (nH - 30)/2, 30, RAYLIBColor(173, 216, 230, 255))
    ok

// =============================================================
// Game Update
// =============================================================

func cards_updateGame
    // Handle eat animation delay - block ALL input
    if eatAnimating
        eatTimer++
        if eatTimer >= DELAY_EAT
            eatAnimating = false
            eatTimer = 0
            cards_performEat(eatPlayer, eatPos, eatValue)
            cards_checkNewGame()
            cards_resetCursor()
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

    // Handle game over delay - block ALL input
    if gameOver
        gameOverTimer++
        if gameOverTimer >= DELAY_NEWGAME
            cards_initRound()
        ok
        return
    ok

    // Computer player timer - block ALL input
    if gameMode = GM_ONEPLAYER
        if role = 1
            computerTimer++
            if computerTimer >= DELAY_COMPUTER
                computerTimer = 0
                cards_computerAction()
            ok
            return
        ok
    ok

    // === Human input ===

    // M or ESC = back to menu
    if IsKeyPressed(KEY_M) or IsKeyPressed(KEY_ESCAPE)
        gameState = ST_MENU
        return
    ok

    // Keyboard card selection (Left/Right)
    if IsKeyPressed(KEY_LEFT)
        cardCursor--
        if cardCursor < 1 cardCursor = CARDS_COUNT ok
        cards_snapCursorLeft()
    ok
    if IsKeyPressed(KEY_RIGHT)
        cardCursor++
        if cardCursor > CARDS_COUNT cardCursor = 1 ok
        cards_snapCursorRight()
    ok

    // Keyboard confirm - pick card for the active player (role)
    if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
        cards_pickCard(cardCursor)
    ok

    // Mouse click
    if !eatAnimating
        if IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
            mx = GetMouseX()
            my = GetMouseY()
            if cards_insideRect(mx, my, SCREEN_W/2 - 75, SCREEN_H - 38, 150, 32)
                gameState = ST_MENU
                return
            ok
            cards_pickCardByMouse(mx, my)
        ok
    ok

// =============================================================
// Unified pick: uses role to decide which player's card to pick
// =============================================================

func cards_pickCard pos
    if pos < 1 return ok
    if pos > CARDS_COUNT return ok
    if eatAnimating return ok
    if role = 1
        if p1Status[pos] = CS_HIDDEN
            cards_player1Click(pos)
        ok
        return
    ok
    if role = 2
        if p2Status[pos] = CS_HIDDEN
            cards_player2Click(pos)
        ok
    ok

func cards_pickCardByMouse mx, my
    if eatAnimating return ok
    if role = 1
        for i = 1 to CARDS_COUNT
            if p1Status[i] = CS_HIDDEN
                if cards_insideRect(mx, my, p1X[i], p1Y, CARD_W, CARD_H)
                    cardCursor = i
                    cards_player1Click(i)
                    return
                ok
            ok
        next
        return
    ok
    if role = 2
        for i = 1 to CARDS_COUNT
            if p2Status[i] = CS_HIDDEN
                if cards_insideRect(mx, my, p2X[i], p2Y, CARD_W, CARD_H)
                    cardCursor = i
                    cards_player2Click(i)
                    return
                ok
            ok
        next
    ok

// =============================================================
// Game Draw
// =============================================================

func cards_drawGame
    ClearBackground(RAYLIBColor(25, 100, 50, 255))

    // Player 1 header bar
    p1Text = "Player (1) - Score: " + string(p1Score)
    if gameMode = GM_ONEPLAYER
        p1Text = "Computer - Score: " + string(p1Score)
    ok
    DrawRectangle(0, 0, SCREEN_W, 45, RAYLIBColor(100, 0, 130, 255))
    tw = MeasureText(p1Text, 24)
    DrawText(p1Text, (SCREEN_W - tw) / 2, 10, 24, WHITE)

    // Player 1 turn indicator
    if role = 1 and !gameOver
        DrawRectangle(0, 45, SCREEN_W, 4, GOLD)
    ok

    // Draw Player 1 cards (top row)
    for i = 1 to CARDS_COUNT
        lClickable = (role = 1 and gameMode = GM_TWOPLAYERS and p1Status[i] = CS_HIDDEN)
        lCursor = (role = 1 and gameMode = GM_TWOPLAYERS and cardCursor = i)
        cards_drawSlot(p1X[i], p1Y, p1Status[i], p1Rank[i], p1Suit[i], 1, lClickable, lCursor)
    next

    // Middle area - turn/status text
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
                turnText = "Player 1's Turn - Click a card above"
            ok
        but role = 2
            turnText = "Player 2's Turn - Click a card below"
        ok
    ok
    midY = (p1Y + CARD_H + p2Y) / 2 - 14

    // Draw turn text with background
    ttw = MeasureText(turnText, 22)
    DrawRectangle((SCREEN_W - ttw) / 2 - 15, midY - 5, ttw + 30, 32,
                  RAYLIBColor(0, 0, 0, 120))
    DrawText(turnText, (SCREEN_W - ttw) / 2, midY, 22, WHITE)

    // Eat animation pulse
    if eatAnimating
        pulse = floor(sin(animTime * 8.0) * 60 + 195)
        subTxt = "* * *"
        subW = MeasureText(subTxt, 18)
        DrawText(subTxt, (SCREEN_W - subW) / 2, midY + 30, 18,
                 RAYLIBColor(255, 215, 0, pulse))
    ok

    // Player 2 turn indicator
    if role = 2 and !gameOver
        DrawRectangle(0, SCREEN_H - 82, SCREEN_W, 4, GOLD)
    ok

    // Player 2 header bar
    p2Text = "Player (2) - Score: " + string(p2Score)
    DrawRectangle(0, SCREEN_H - 78, SCREEN_W, 45, RAYLIBColor(180, 30, 30, 255))
    tw2 = MeasureText(p2Text, 24)
    DrawText(p2Text, (SCREEN_W - tw2) / 2, SCREEN_H - 68, 24, WHITE)

    // Draw Player 2 cards (bottom row)
    for i = 1 to CARDS_COUNT
        lClickable = (role = 2 and p2Status[i] = CS_HIDDEN)
        lCursor = (role = 2 and cardCursor = i)
        cards_drawSlot(p2X[i], p2Y, p2Status[i], p2Rank[i], p2Suit[i], 2, lClickable, lCursor)
    next

    // Back to menu button
    btnX = SCREEN_W/2 - 75
    btnY = SCREEN_H - 38
    DrawRectangle(btnX, btnY, 150, 32, RAYLIBColor(0, 0, 0, 200))
    DrawRectangleLines(btnX, btnY, 150, 32, RAYLIBColor(150, 150, 150, 200))
    bTxt = "Back to Menu"
    bw = MeasureText(bTxt, 16)
    DrawText(bTxt, btnX + (150 - bw)/2, btnY + 8, 16, WHITE)

    // Wild card reminder + controls
    wildTxt = "Card 5 is WILD!  |  Left/Right: Select  Enter: Reveal  M: Menu"
    wildW = MeasureText(wildTxt, 14)
    DrawText(wildTxt, (SCREEN_W - wildW) / 2, midY - 30, 14,
             RAYLIBColor(255, 215, 0, 140))

// =============================================================
// Draw Card Slot
// =============================================================

func cards_drawSlot nX, nY, nStatus, nRank, nSuit, nPlayer, lClickable, lCursor
    // Draw keyboard cursor highlight
    if lCursor
        pulse = floor(sin(animTime * 5.0) * 40 + 215)
        DrawRectangle(floor(nX) - 4, floor(nY) - 4, CARD_W + 8, CARD_H + 8,
                      RAYLIBColor(255, 255, 100, pulse))
    ok

    if nStatus = CS_HIDDEN
        cards_drawCardFace(nX, nY, 0, 0, false, lClickable)
    but nStatus = CS_OPEN
        cards_drawCardFace(nX, nY, nRank, nSuit, true, false)
    but nStatus = CS_EATEN
        cards_drawEaten(nX, nY, nPlayer)
    ok

    // Draw card number below for keyboard reference
    if lCursor or lClickable
        numTxt = string(floor(nX / (CARD_W + 12) - 1))
    ok

// =============================================================
// Draw Card (Programmatic - like solitaire.ring)
// =============================================================

func cards_drawCardFace x, y, rank, suit, faceUp, lHover
    ix = floor(x)
    iy = floor(y)

    // Hover glow for clickable cards
    if lHover
        mx = GetMouseX()
        my = GetMouseY()
        if cards_insideRect(mx, my, ix, iy, CARD_W, CARD_H)
            DrawRectangle(ix - 3, iy - 3, CARD_W + 6, CARD_H + 6,
                          RAYLIBColor(255, 215, 0, 200))
        ok
    ok

    if !faceUp
        // Card back - decorative pattern
        DrawRectangle(ix, iy, CARD_W, CARD_H, RAYLIBColor(30, 50, 120, 255))
        DrawRectangle(ix + 3, iy + 3, CARD_W - 6, CARD_H - 6,
                      RAYLIBColor(45, 70, 160, 255))
        // Diamond pattern
        for py = iy + 10 to iy + CARD_H - 10 step 10
            for px = ix + 10 to ix + CARD_W - 10 step 10
                DrawRectangle(px, py, 5, 5, RAYLIBColor(60, 90, 190, 255))
            next
        next
        DrawRectangleLines(ix, iy, CARD_W, CARD_H, RAYLIBColor(20, 35, 90, 255))

        // Question mark in center
        qm = "?"
        qw = MeasureText(qm, 32)
        DrawText(qm, ix + (CARD_W - qw)/2, iy + (CARD_H - 32)/2, 32,
                 RAYLIBColor(100, 140, 255, 200))
        return
    ok

    // Face-up card
    DrawRectangle(ix, iy, CARD_W, CARD_H, RAYLIBColor(255, 255, 250, 255))
    DrawRectangleLines(ix, iy, CARD_W, CARD_H, RAYLIBColor(80, 80, 80, 255))

    // Color based on suit
    if suit = SUIT_HEART or suit = SUIT_DIAMOND
        tc = RAYLIBColor(200, 30, 30, 255)
    else
        tc = RAYLIBColor(20, 20, 20, 255)
    ok

    rName = rankNames[rank]
    sName = suitSyms[suit]

    // Top-left rank and suit
    DrawText(rName, ix + 6, iy + 5, 20, tc)
    DrawText(sName, ix + 6, iy + 25, 14, tc)

    // Center rank value (large)
    rw2 = MeasureText(rName, 40)
    DrawText(rName, ix + (CARD_W - rw2) / 2, iy + (CARD_H - 40) / 2, 40, tc)

    // Bottom-right rank and suit (inverted position)
    rw = MeasureText(rName, 20)
    DrawText(rName, ix + CARD_W - rw - 6, iy + CARD_H - 25, 20, tc)
    DrawText(sName, ix + CARD_W - 20, iy + CARD_H - 42, 14, tc)

    // Highlight wild cards (rank 5)
    if rank = 5
        DrawRectangleLines(ix + 1, iy + 1, CARD_W - 2, CARD_H - 2,
                           RAYLIBColor(255, 215, 0, 180))
        DrawRectangleLines(ix + 2, iy + 2, CARD_W - 4, CARD_H - 4,
                           RAYLIBColor(255, 215, 0, 120))
        // Small "WILD" text
        wt = "WILD"
        ww = MeasureText(wt, 10)
        DrawText(wt, ix + (CARD_W - ww)/2, iy + CARD_H - 14, 10,
                 RAYLIBColor(255, 180, 0, 200))
    ok

// =============================================================
// Draw Eaten Card
// =============================================================

func cards_drawEaten nX, nY, nPlayer
    ix = floor(nX)
    iy = floor(nY)

    if nPlayer = 1
        // Player 1 captured - purple theme
        DrawRectangle(ix, iy, CARD_W, CARD_H, RAYLIBColor(80, 20, 100, 255))
        DrawRectangle(ix + 3, iy + 3, CARD_W - 6, CARD_H - 6,
                      RAYLIBColor(100, 40, 130, 255))
        DrawRectangleLines(ix, iy, CARD_W, CARD_H, RAYLIBColor(60, 10, 80, 255))
        ct = "P1"
        if gameMode = GM_ONEPLAYER ct = "PC" ok
    else
        // Player 2 captured - red theme
        DrawRectangle(ix, iy, CARD_W, CARD_H, RAYLIBColor(140, 20, 20, 255))
        DrawRectangle(ix + 3, iy + 3, CARD_W - 6, CARD_H - 6,
                      RAYLIBColor(170, 40, 40, 255))
        DrawRectangleLines(ix, iy, CARD_W, CARD_H, RAYLIBColor(100, 10, 10, 255))
        ct = "P2"
    ok

    // Captured text
    cw = MeasureText(ct, 28)
    DrawText(ct, ix + (CARD_W - cw)/2, iy + (CARD_H - 28)/2, 28,
             RAYLIBColor(255, 255, 255, 180))

// =============================================================
// Game Logic
// =============================================================

func cards_player1Click x
    if role != 1 return ok
    if p1Status[x] != CS_HIDDEN return ok
    if len(deckCards) < 1 return ok

    // Draw a card from the shuffled deck
    nPos = GetRandomValue(1, len(deckCards))
    card = deckCards[nPos]
    p1Rank[x] = card[1]
    p1Suit[x] = card[2]
    p1Status[x] = CS_OPEN
    del(deckCards, nPos)

    // Switch turn
    role = 2

    // Start eat animation
    eatAnimating = true
    eatTimer = 0
    eatPlayer = 1
    eatPos = x
    eatValue = p1Rank[x]

func cards_player2Click x
    if role != 2 return ok
    if p2Status[x] != CS_HIDDEN return ok
    if len(deckCards) < 1 return ok

    // Draw a card from the shuffled deck
    nPos = GetRandomValue(1, len(deckCards))
    card = deckCards[nPos]
    p2Rank[x] = card[1]
    p2Suit[x] = card[2]
    p2Status[x] = CS_OPEN
    del(deckCards, nPos)

    // Switch turn
    role = 1

    // Start eat animation
    eatAnimating = true
    eatTimer = 0
    eatPlayer = 2
    eatPos = x
    eatValue = p2Rank[x]

// =============================================================
// Eat Logic (matching cards)
// =============================================================

func cards_performEat nPlayer, nPos, nValue
    if nPlayer = 1
        lEat = false
        // Check Player 2's open cards
        for x = 1 to CARDS_COUNT
            if p2Status[x] = CS_OPEN and (p2Rank[x] = nValue or nValue = 5)
                p2Status[x] = CS_EATEN
                lEat = true
                p1Score++
            ok
            // Check Player 1's own open cards (except the one just played)
            if x != nPos and p1Status[x] = CS_OPEN and (p1Rank[x] = nValue or nValue = 5)
                p1Status[x] = CS_EATEN
                lEat = true
                p1Score++
            ok
        next
        if lEat
            p1Score++
            p1Status[nPos] = CS_EATEN
        ok
    ok

    if nPlayer = 2
        lEat = false
        // Check Player 1's open cards
        for x = 1 to CARDS_COUNT
            if p1Status[x] = CS_OPEN and (p1Rank[x] = nValue or nValue = 5)
                p1Status[x] = CS_EATEN
                lEat = true
                p2Score++
            ok
            // Check Player 2's own open cards (except the one just played)
            if x != nPos and p2Status[x] = CS_OPEN and (p2Rank[x] = nValue or nValue = 5)
                p2Status[x] = CS_EATEN
                lEat = true
                p2Score++
            ok
        next
        if lEat
            p2Score++
            p2Status[nPos] = CS_EATEN
        ok
    ok

// =============================================================
// Check for New Game (all cards revealed)
// =============================================================

func cards_checkNewGame
    if !cards_isRoundOver() return ok

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

func cards_isRoundOver
    for i = 1 to CARDS_COUNT
        if p1Status[i] = CS_HIDDEN
            return false
        ok
    next
    for i = 1 to CARDS_COUNT
        if p2Status[i] = CS_HIDDEN
            return false
        ok
    next
    return true

// =============================================================
// Computer Player
// =============================================================

func cards_computerAction
    // Build list of available positions
    aOptions = []
    for i = 1 to CARDS_COUNT
        if p1Status[i] = CS_HIDDEN
            add(aOptions, i)
        ok
    next

    if len(aOptions) > 0
        idx = GetRandomValue(1, len(aOptions))
        cardNum = aOptions[idx]
        cards_player1Click(cardNum)
    ok

// =============================================================
// Utility
// =============================================================

func cards_insideRect mx, my, rx, ry, rw, rh
    if mx >= rx and mx <= rx + rw and my >= ry and my <= ry + rh
        return true
    ok
    return false

// =============================================================
// Keyboard Cursor Helpers
// =============================================================

func cards_snapCursorLeft
    // Find nearest hidden card going left from current cursor
    aStatus = cards_currentStatus()
    startPos = cardCursor
    for tries = 1 to CARDS_COUNT
        if aStatus[cardCursor] = CS_HIDDEN
            return
        ok
        cardCursor--
        if cardCursor < 1 cardCursor = CARDS_COUNT ok
    next
    // If all revealed, stay at original
    cardCursor = startPos

func cards_snapCursorRight
    // Find nearest hidden card going right from current cursor
    aStatus = cards_currentStatus()
    startPos = cardCursor
    for tries = 1 to CARDS_COUNT
        if aStatus[cardCursor] = CS_HIDDEN
            return
        ok
        cardCursor++
        if cardCursor > CARDS_COUNT cardCursor = 1 ok
    next
    // If all revealed, stay at original
    cardCursor = startPos

func cards_currentStatus
    // Return the status array for the current player's turn
    if role = 1
        return p1Status
    ok
    return p2Status

func cards_resetCursor
    aStatus = cards_currentStatus()
    for i = cardCursor to CARDS_COUNT
        if aStatus[i] = CS_HIDDEN
            cardCursor = i
            return
        ok
    next
    for i = 1 to cardCursor - 1
        if aStatus[i] = CS_HIDDEN
            cardCursor = i
            return
        ok
    next
    cardCursor = 1
