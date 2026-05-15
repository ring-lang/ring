/*
**  Sorting Visualizer - RingRayLib
**  ==================================
**  Watch sorting algorithms animate on colorful bars!
**
**  Algorithms:
**    1. Bubble Sort
**    2. Selection Sort
**    3. Insertion Sort
**    4. Quick Sort
**    5. Merge Sort
**    6. Shell Sort
**
**  Controls:
**    Space / P       - Start / Pause sorting
**    R               - Randomize array
**    N               - Next algorithm
**    +/-             - Speed up / Slow down
**    A               - Toggle array size (32 / 64 / 128)
**    C               - Toggle color mode
**    ESC             - Exit
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W = 1024
SCREEN_H = 700
TOOLBAR_H = 55

VIEW_H = SCREEN_H - TOOLBAR_H

// Algorithms
ALG_BUBBLE    = 1
ALG_SELECTION = 2
ALG_INSERTION = 3
ALG_QUICK     = 4
ALG_MERGE     = 5
ALG_SHELL     = 6
ALG_COUNT     = 6
algNames = ["Bubble Sort", "Selection Sort", "Insertion Sort", "Quick Sort", "Merge Sort", "Shell Sort"]

// Color modes
CMODE_RAINBOW = 1
CMODE_HEIGHT  = 2
CMODE_WHITE   = 3
CMODE_COUNT   = 3
cmodeNames = ["Rainbow", "Height", "White"]

// Array size presets
SIZE_PRESETS = [32, 64, 128]
SIZE_COUNT = 3

// States
STATE_IDLE     = 1
STATE_SORTING  = 2
STATE_PAUSED   = 3
STATE_DONE     = 4

// =============================================================
// State
// =============================================================

arr = []
arrSize = 64
sizeIdx = 2

algorithm = ALG_BUBBLE
colorMode = CMODE_RAINBOW
sortState = STATE_IDLE

// Speed: operations per frame
speed = 2
SPEED_MIN = 1
SPEED_MAX = 50

// Stats
comparisons = 0
swaps = 0
sortTime = 0.0

// Visual highlights
hlCompare1 = -1     // index being compared (green)
hlCompare2 = -1     // index being compared (green)
hlSwap1 = -1        // index being swapped (red)
hlSwap2 = -1        // index being swapped (red)
hlSorted = []        // indices confirmed sorted (gold)
hlActive = -1        // current active index (cyan)

// Sort operation queue - we precompute all operations
// Each op: [type, i, j] where type = "cmp", "swap", "set", "mark", "done"
ops = []
opIdx = 0

// Toolbar
hoverBtn = 0
BTN_Y = SCREEN_H - 52
BTN_H = 38
BTN_GAP = 5

// Animation
animTime = 0.0
doneAnimTime = 0.0

// =============================================================
// Main
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Sorting Visualizer - RingRayLib")
SetTargetFPS(60)
SetExitKey(0)

sv_randomize()

while !WindowShouldClose()
    sv_update()
    BeginDrawing()
        ClearBackground(RAYLIBColor(18, 18, 28, 255))
        sv_draw()
    EndDrawing()
end

CloseWindow()

// =============================================================
// Randomize Array
// =============================================================

func sv_randomize
    arr = list(arrSize)
    for i = 1 to arrSize
        arr[i] = i
    next
    // Fisher-Yates shuffle
    for i = arrSize to 2 step -1
        j = GetRandomValue(1, i)
        temp = arr[i]
        arr[i] = arr[j]
        arr[j] = temp
    next
    sortState = STATE_IDLE
    comparisons = 0
    swaps = 0
    sortTime = 0.0
    ops = []
    opIdx = 0
    hlCompare1 = -1  hlCompare2 = -1
    hlSwap1 = -1     hlSwap2 = -1
    hlSorted = []
    hlActive = -1
    doneAnimTime = 0.0

// =============================================================
// Generate Sort Operations
// =============================================================

func sv_generateOps
    // Copy array for simulation
    a = list(arrSize)
    for i = 1 to arrSize
        a[i] = arr[i]
    next
    ops = []
    opIdx = 1

    if algorithm = ALG_BUBBLE
        sv_genBubble(a)
    ok
    if algorithm = ALG_SELECTION
        sv_genSelection(a)
    ok
    if algorithm = ALG_INSERTION
        sv_genInsertion(a)
    ok
    if algorithm = ALG_QUICK
        sv_genQuick(a, 1, arrSize)
    ok
    if algorithm = ALG_MERGE
        sv_genMerge(a, 1, arrSize)
    ok
    if algorithm = ALG_SHELL
        sv_genShell(a)
    ok

    // Final sweep animation
    for i = 1 to arrSize
        add(ops, ["done", i, 0])
    next

func sv_addOp type, i, j
    add(ops, [type, i, j])

// --- Bubble Sort ---
func sv_genBubble a
    n = len(a)
    for i = 1 to n - 1
        swapped = false
        for j = 1 to n - i
            sv_addOp("cmp", j, j + 1)
            if a[j] > a[j + 1]
                temp = a[j]
                a[j] = a[j + 1]
                a[j + 1] = temp
                sv_addOp("swap", j, j + 1)
                swapped = true
            ok
        next
        sv_addOp("mark", n - i + 1, 0)
        if !swapped exit ok
    next
    sv_addOp("mark", 1, 0)

// --- Selection Sort ---
func sv_genSelection a
    n = len(a)
    for i = 1 to n - 1
        minIdx = i
        sv_addOp("active", i, 0)
        for j = i + 1 to n
            sv_addOp("cmp", minIdx, j)
            if a[j] < a[minIdx]
                minIdx = j
            ok
        next
        if minIdx != i
            temp = a[i]
            a[i] = a[minIdx]
            a[minIdx] = temp
            sv_addOp("swap", i, minIdx)
        ok
        sv_addOp("mark", i, 0)
    next
    sv_addOp("mark", n, 0)

// --- Insertion Sort ---
func sv_genInsertion a
    n = len(a)
    for i = 2 to n
        key = a[i]
        j = i - 1
        sv_addOp("active", i, 0)
        while j >= 1
            sv_addOp("cmp", j, j + 1)
            if a[j] > key
                a[j + 1] = a[j]
                sv_addOp("set", j + 1, a[j + 1])
                j--
            else
                exit
            ok
        end
        a[j + 1] = key
        sv_addOp("set", j + 1, key)
    next

// --- Quick Sort ---
func sv_genQuick a, lo, hi
    if lo >= hi return ok

    // Partition
    pivot = a[hi]
    sv_addOp("active", hi, 0)
    i = lo - 1

    for j = lo to hi - 1
        sv_addOp("cmp", j, hi)
        if a[j] <= pivot
            i++
            if i != j
                temp = a[i]
                a[i] = a[j]
                a[j] = temp
                sv_addOp("swap", i, j)
            ok
        ok
    next

    i++
    if i != hi
        temp = a[i]
        a[i] = a[hi]
        a[hi] = temp
        sv_addOp("swap", i, hi)
    ok

    sv_addOp("mark", i, 0)

    sv_genQuick(a, lo, i - 1)
    sv_genQuick(a, i + 1, hi)

// --- Merge Sort ---
func sv_genMerge a, lo, hi
    if lo >= hi return ok

    mid = floor((lo + hi) / 2)
    sv_genMerge(a, lo, mid)
    sv_genMerge(a, mid + 1, hi)

    // Merge
    temp2 = []
    i = lo
    j = mid + 1

    while i <= mid and j <= hi
        sv_addOp("cmp", i, j)
        if a[i] <= a[j]
            add(temp2, a[i])
            i++
        else
            add(temp2, a[j])
            j++
        ok
    end
    while i <= mid
        add(temp2, a[i])
        i++
    end
    while j <= hi
        add(temp2, a[j])
        j++
    end

    for k = 1 to len(temp2)
        a[lo + k - 1] = temp2[k]
        sv_addOp("set", lo + k - 1, temp2[k])
    next

// --- Shell Sort ---
func sv_genShell a
    n = len(a)
    gap = floor(n / 2)

    while gap > 0
        for i = gap + 1 to n
            temp = a[i]
            j = i
            sv_addOp("active", i, 0)
            while j > gap
                sv_addOp("cmp", j - gap, j)
                if a[j - gap] > temp
                    a[j] = a[j - gap]
                    sv_addOp("set", j, a[j])
                    j -= gap
                else
                    exit
                ok
            end
            a[j] = temp
            sv_addOp("set", j, temp)
        next
        gap = floor(gap / 2)
    end

// =============================================================
// Update
// =============================================================

func sv_update
    dt = GetFrameTime()
    animTime += dt

    if IsKeyPressed(KEY_ESCAPE)
        CloseWindow()
        shutdown(0)
    ok

    // Start / Pause
    if IsKeyPressed(KEY_SPACE) or IsKeyPressed(KEY_P)
        if sortState = STATE_IDLE
            sv_generateOps()
            sortState = STATE_SORTING
            comparisons = 0
            swaps = 0
            sortTime = 0.0
            hlSorted = []
        ok
        if sortState = STATE_SORTING
            sortState = STATE_PAUSED
        but sortState = STATE_PAUSED
            sortState = STATE_SORTING
        ok
    ok

    // Randomize
    if IsKeyPressed(KEY_R)
        sv_randomize()
    ok

    // Next algorithm
    if IsKeyPressed(KEY_N)
        algorithm++
        if algorithm > ALG_COUNT algorithm = 1 ok
        sv_randomize()
    ok

    // Speed
    if IsKeyPressed(KEY_EQUAL) or IsKeyPressed(KEY_KP_ADD)
        speed += 1
        if speed > SPEED_MAX speed = SPEED_MAX ok
    ok
    if IsKeyPressed(KEY_MINUS) or IsKeyPressed(KEY_KP_SUBTRACT)
        speed -= 1
        if speed < SPEED_MIN speed = SPEED_MIN ok
    ok

    // Array size
    if IsKeyPressed(KEY_A)
        sizeIdx++
        if sizeIdx > SIZE_COUNT sizeIdx = 1 ok
        arrSize = SIZE_PRESETS[sizeIdx]
        sv_randomize()
    ok

    // Color mode
    if IsKeyPressed(KEY_C)
        colorMode++
        if colorMode > CMODE_COUNT colorMode = 1 ok
    ok

    // Toolbar clicks
    if IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
        sv_handleClick(GetMouseX(), GetMouseY())
    ok

    // Process sort operations
    if sortState = STATE_SORTING
        sortTime += dt
        sv_processOps()
    ok

    // Done animation
    if sortState = STATE_DONE
        doneAnimTime += dt
    ok

// =============================================================
// Process Sort Operations
// =============================================================

func sv_processOps
    hlCompare1 = -1  hlCompare2 = -1
    hlSwap1 = -1     hlSwap2 = -1
    hlActive = -1

    opsThisFrame = 0
    while opsThisFrame < speed and opIdx <= len(ops)
        op = ops[opIdx]
        opType = op[1]
        opI = op[2]
        opJ = op[3]

        if opType = "cmp"
            hlCompare1 = opI
            hlCompare2 = opJ
            comparisons++
            opsThisFrame++
        ok

        if opType = "swap"
            temp = arr[opI]
            arr[opI] = arr[opJ]
            arr[opJ] = temp
            hlSwap1 = opI
            hlSwap2 = opJ
            swaps++
            opsThisFrame++
        ok

        if opType = "set"
            arr[opI] = opJ
            hlActive = opI
            opsThisFrame++
        ok

        if opType = "active"
            hlActive = opI
        ok

        if opType = "mark"
            add(hlSorted, opI)
        ok

        if opType = "done"
            add(hlSorted, opI)
            opsThisFrame++
        ok

        opIdx++
    end

    if opIdx > len(ops)
        sortState = STATE_DONE
        hlCompare1 = -1  hlCompare2 = -1
        hlSwap1 = -1     hlSwap2 = -1
        hlActive = -1
        doneAnimTime = 0.0
    ok

// =============================================================
// Draw
// =============================================================

func sv_draw
    // Bars
    barAreaW = SCREEN_W - 20
    barW = floor(barAreaW / arrSize)
    if barW < 2 barW = 2 ok
    gap = 1
    if barW <= 3 gap = 0 ok
    actualBarW = barW - gap
    startX = (SCREEN_W - arrSize * barW) / 2

    maxVal = arrSize

    for i = 1 to arrSize
        val = arr[i]
        barH = floor((val * 1.0 / maxVal) * (VIEW_H - 50))
        bx = startX + (i - 1) * barW
        by = VIEW_H - barH

        // Determine color
        col = sv_getBarColor(i, val, barH)

        // Check highlights
        isCompare = (i = hlCompare1 or i = hlCompare2)
        isSwap = (i = hlSwap1 or i = hlSwap2)
        isActive = (i = hlActive)
        isSorted = sv_isSorted(i)

        if isSwap
            col = RAYLIBColor(255, 60, 60, 255)
        but isCompare
            col = RAYLIBColor(60, 255, 100, 255)
        but isActive
            col = RAYLIBColor(60, 200, 255, 255)
        but isSorted
            if sortState = STATE_DONE
                // Sweep animation
                sweepIdx = 0
                for s = 1 to len(hlSorted)
                    if hlSorted[s] = i sweepIdx = s ok
                next
                // Gold with wave
                wave = sin(animTime * 6.0 - sweepIdx * 0.15)
                gb = 180 + floor(wave * 40)
                col = RAYLIBColor(255, gb, 30, 255)
            else
                col = RAYLIBColor(255, 200, 40, 255)
            ok
        ok

        DrawRectangle(bx, by, actualBarW, barH, col)

        // Top highlight
        if barH > 3
            DrawRectangle(bx, by, actualBarW, 2, RAYLIBColor(255, 255, 255, 40))
        ok
    next

    // Swap/compare visualization lines
    if hlSwap1 > 0 and hlSwap2 > 0
        sx1 = startX + (hlSwap1 - 1) * barW + actualBarW / 2
        sx2 = startX + (hlSwap2 - 1) * barW + actualBarW / 2
        DrawLine(sx1, VIEW_H + 2, sx2, VIEW_H + 2, RAYLIBColor(255, 60, 60, 180))
        DrawCircle(sx1, VIEW_H + 2, 3, RAYLIBColor(255, 60, 60, 200))
        DrawCircle(sx2, VIEW_H + 2, 3, RAYLIBColor(255, 60, 60, 200))
    ok

    if hlCompare1 > 0 and hlCompare2 > 0 and hlSwap1 <= 0
        sx1 = startX + (hlCompare1 - 1) * barW + actualBarW / 2
        sx2 = startX + (hlCompare2 - 1) * barW + actualBarW / 2
        DrawLine(sx1, VIEW_H + 4, sx2, VIEW_H + 4, RAYLIBColor(60, 255, 100, 120))
    ok

    // HUD
    sv_drawHUD()

    // Toolbar
    sv_drawToolbar()

func sv_getBarColor i, val, barH
    if colorMode = CMODE_RAINBOW
        hue = floor((val * 1.0 / arrSize) * 300)
        return sv_hsvColor(hue, 80, 90)
    ok
    if colorMode = CMODE_HEIGHT
        t = val * 1.0 / arrSize
        r = floor(40 + t * 180)
        g = floor(80 + t * 140)
        b = floor(200 - t * 140)
        return RAYLIBColor(r, g, b, 255)
    ok
    // White
    v = floor(100 + (val * 1.0 / arrSize) * 155)
    return RAYLIBColor(v, v, v, 255)

func sv_hsvColor h, s, v
    s2 = s / 100.0
    v2 = v / 100.0
    c = v2 * s2
    hmod = (h / 60.0) % 6
    x = c * (1.0 - fabs(hmod % 2 - 1.0))
    m = v2 - c

    r1 = 0  g1 = 0  b1 = 0
    if hmod < 1       r1 = c  g1 = x  b1 = 0
    but hmod < 2   r1 = x  g1 = c  b1 = 0
    but hmod < 3   r1 = 0  g1 = c  b1 = x
    but hmod < 4   r1 = 0  g1 = x  b1 = c
    but hmod < 5   r1 = x  g1 = 0  b1 = c
    else              r1 = c  g1 = 0  b1 = x
    ok

    return RAYLIBColor(floor((r1+m)*255), floor((g1+m)*255), floor((b1+m)*255), 255)

func sv_isSorted idx
    for s = 1 to len(hlSorted)
        if hlSorted[s] = idx return true ok
    next
    return false

// =============================================================
// HUD
// =============================================================

func sv_drawHUD
    // Top bar
    DrawRectangle(0, 0, SCREEN_W, 30, RAYLIBColor(0, 0, 0, 200))

    DrawText("Sorting Visualizer", 10, 6, 18, RAYLIBColor(255, 215, 0, 220))

    // Algorithm name
    algTxt = algNames[algorithm]
    DrawText(algTxt, 200, 8, 16, RAYLIBColor(100, 200, 255, 230))

    // Stats
    cmpTxt = "Cmp: " + string(comparisons)
    DrawText(cmpTxt, 400, 8, 14, RAYLIBColor(60, 255, 100, 200))

    swpTxt = "Swap: " + string(swaps)
    DrawText(swpTxt, 510, 8, 14, RAYLIBColor(255, 100, 100, 200))

    sizeTxt = "n=" + string(arrSize)
    DrawText(sizeTxt, 620, 8, 14, RAYLIBColor(200, 200, 220, 180))

    spdTxt = "Speed: " + string(speed)
    DrawText(spdTxt, 690, 8, 14, RAYLIBColor(200, 180, 150, 180))

    // State
    if sortState = STATE_IDLE
        DrawText("READY", 790, 8, 14, RAYLIBColor(200, 200, 200, 200))
    ok
    if sortState = STATE_SORTING
        DrawText("SORTING", 790, 8, 14, RAYLIBColor(100, 255, 100, 240))
        // Timer
        tTxt = sv_fmtTime(sortTime)
        DrawText(tTxt, 880, 8, 14, RAYLIBColor(180, 200, 220, 180))
    ok
    if sortState = STATE_PAUSED
        DrawText("PAUSED", 790, 8, 14, RAYLIBColor(255, 200, 50, 240))
    ok
    if sortState = STATE_DONE
        DrawText("DONE!", 790, 8, 14, RAYLIBColor(255, 215, 0, 255))
        tTxt = sv_fmtTime(sortTime)
        DrawText(tTxt, 860, 8, 14, RAYLIBColor(180, 200, 220, 180))
    ok

    // Progress bar
    if sortState = STATE_SORTING or sortState = STATE_PAUSED
        if len(ops) > 0
            progress = opIdx * 1.0 / len(ops)
            barW = floor(SCREEN_W * progress)
            DrawRectangle(0, 30, barW, 3, RAYLIBColor(100, 200, 255, 180))
        ok
    ok

    // Legend
    legY = VIEW_H - 18
    DrawRectangle(8, legY, 12, 12, RAYLIBColor(60, 255, 100, 255))
    DrawText("Compare", 24, legY, 12, RAYLIBColor(180, 200, 180, 160))

    DrawRectangle(100, legY, 12, 12, RAYLIBColor(255, 60, 60, 255))
    DrawText("Swap", 116, legY, 12, RAYLIBColor(200, 180, 180, 160))

    DrawRectangle(168, legY, 12, 12, RAYLIBColor(60, 200, 255, 255))
    DrawText("Active", 184, legY, 12, RAYLIBColor(180, 200, 200, 160))

    DrawRectangle(246, legY, 12, 12, RAYLIBColor(255, 200, 40, 255))
    DrawText("Sorted", 262, legY, 12, RAYLIBColor(200, 200, 180, 160))

    // FPS
    fpsTxt = "" + string(GetFPS()) + " FPS"
    DrawText(fpsTxt, SCREEN_W - 65, SCREEN_H - 14, 13, RAYLIBColor(100, 255, 100, 150))

func sv_fmtTime t
    if t < 1.0
        ms = floor(t * 1000)
        return "" + ms + "ms"
    ok
    return "" + floor(t * 10) / 10.0 + "s"

// =============================================================
// Toolbar
// =============================================================

func sv_drawToolbar
    DrawRectangle(0, SCREEN_H - TOOLBAR_H, SCREEN_W, TOOLBAR_H, RAYLIBColor(15, 15, 28, 255))
    DrawRectangle(0, SCREEN_H - TOOLBAR_H, SCREEN_W, 2, RAYLIBColor(60, 60, 100, 200))

    mx = GetMouseX()
    my = GetMouseY()
    hoverBtn = 0

    bx = BTN_GAP

    // Start/Pause
    if sortState = STATE_IDLE or sortState = STATE_DONE
        bx = sv_drawBtn("Start [P]", bx, 1, RAYLIBColor(40, 130, 70, 255), mx, my)
    but sortState = STATE_SORTING
        bx = sv_drawBtn("Pause [P]", bx, 1, RAYLIBColor(180, 120, 20, 255), mx, my)
    but sortState = STATE_PAUSED
        bx = sv_drawBtn("Resume [P]", bx, 1, RAYLIBColor(40, 130, 70, 255), mx, my)
    ok
    bx += BTN_GAP

    // Randomize
    bx = sv_drawBtn("Random [R]", bx, 2, RAYLIBColor(130, 60, 150, 255), mx, my)
    bx += BTN_GAP

    // Algorithm
    bx = sv_drawBtn("Algo [N]", bx, 3, RAYLIBColor(60, 100, 160, 255), mx, my)
    bx += BTN_GAP

    // Size
    bx = sv_drawBtn("Size [A]", bx, 4, RAYLIBColor(100, 80, 60, 255), mx, my)
    bx += BTN_GAP

    // Color
    bx = sv_drawBtn("Color [C]", bx, 5, RAYLIBColor(140, 60, 100, 255), mx, my)
    bx += BTN_GAP

    // Separator
    DrawRectangle(bx, BTN_Y + 4, 2, BTN_H - 8, RAYLIBColor(60, 60, 100, 150))
    bx += BTN_GAP

    // Speed
    bx = sv_drawBtn("Slow [-]", bx, 6, RAYLIBColor(140, 70, 70, 255), mx, my)
    bx += BTN_GAP
    bx = sv_drawBtn("Fast [+]", bx, 7, RAYLIBColor(70, 140, 70, 255), mx, my)
    bx += BTN_GAP

    // Separator
    DrawRectangle(bx, BTN_Y + 4, 2, BTN_H - 8, RAYLIBColor(60, 60, 100, 150))
    bx += BTN_GAP + 2

    // Algorithm quick buttons
    algBtnColors = [
        RAYLIBColor(160, 80, 40, 255),
        RAYLIBColor(40, 120, 80, 255),
        RAYLIBColor(80, 60, 160, 255),
        RAYLIBColor(160, 40, 80, 255),
        RAYLIBColor(40, 80, 160, 255),
        RAYLIBColor(120, 120, 40, 255)
    ]

    shortNames = ["Bub", "Sel", "Ins", "Qck", "Mrg", "Shl"]

    for i = 1 to ALG_COUNT
        lbl = shortNames[i]
        col = algBtnColors[i]
        if algorithm = i
            col = RAYLIBColor(200, 200, 80, 255)
        ok
        bx = sv_drawBtn(lbl, bx, 10 + i, col, mx, my)
        bx += 3
    next

func sv_drawBtn label, bx, btnId, baseCol, mx, my
    tw = MeasureText(label, 13) + 14
    if tw < 38 tw = 38 ok

    isHover = (mx >= bx and mx <= bx + tw and my >= BTN_Y and my <= BTN_Y + BTN_H)

    if isHover
        hoverBtn = btnId
        DrawRectangle(bx, BTN_Y, tw, BTN_H, RAYLIBColor(255, 225, 100, 240))
        DrawRectangleLines(bx, BTN_Y, tw, BTN_H, RAYLIBColor(200, 180, 60, 255))
        lw = MeasureText(label, 13)
        DrawText(label, bx + (tw - lw) / 2, BTN_Y + 13, 13, RAYLIBColor(20, 15, 10, 255))
    else
        DrawRectangle(bx, BTN_Y, tw, BTN_H, baseCol)
        DrawRectangleLines(bx, BTN_Y, tw, BTN_H, RAYLIBColor(255, 255, 255, 30))
        lw = MeasureText(label, 13)
        DrawText(label, bx + (tw - lw) / 2, BTN_Y + 13, 13, WHITE)
    ok

    return bx + tw

// =============================================================
// Handle Click
// =============================================================

func sv_handleClick mx, my
    if hoverBtn = 1
        if sortState = STATE_IDLE or sortState = STATE_DONE
            if sortState = STATE_DONE
                sv_randomize()
            ok
            sv_generateOps()
            sortState = STATE_SORTING
            comparisons = 0
            swaps = 0
            sortTime = 0.0
            hlSorted = []
        but sortState = STATE_SORTING
            sortState = STATE_PAUSED
        but sortState = STATE_PAUSED
            sortState = STATE_SORTING
        ok
        return
    ok
    if hoverBtn = 2
        sv_randomize()
        return
    ok
    if hoverBtn = 3
        algorithm++
        if algorithm > ALG_COUNT algorithm = 1 ok
        sv_randomize()
        return
    ok
    if hoverBtn = 4
        sizeIdx++
        if sizeIdx > SIZE_COUNT sizeIdx = 1 ok
        arrSize = SIZE_PRESETS[sizeIdx]
        sv_randomize()
        return
    ok
    if hoverBtn = 5
        colorMode++
        if colorMode > CMODE_COUNT colorMode = 1 ok
        return
    ok
    if hoverBtn = 6
        speed -= 1
        if speed < SPEED_MIN speed = SPEED_MIN ok
        return
    ok
    if hoverBtn = 7
        speed += 1
        if speed > SPEED_MAX speed = SPEED_MAX ok
        return
    ok
    // Algorithm quick select
    if hoverBtn >= 11 and hoverBtn <= 10 + ALG_COUNT
        algorithm = hoverBtn - 10
        sv_randomize()
        return
    ok
