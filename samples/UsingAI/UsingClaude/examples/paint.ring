/*
**  Paint Program - RingRayLib
**  =============================
**  Simple 2D drawing tool with brushes, colors, and shapes.
**
**  Controls:
**    Mouse Left       - Draw with current tool
**    Mouse Right      - Erase
**    B                - Brush tool
**    L                - Line tool
**    R                - Rectangle tool
**    O                - Circle/Oval tool
**    F                - Fill rectangle tool
**    E                - Eraser tool
**    1-9              - Brush size (1=tiny, 9=huge)
**    +/-              - Adjust brush size
**    U                - Undo last stroke
**    C                - Clear canvas
**    G                - Toggle grid
**    ESC              - Exit
**
**  Click the color palette on the left to pick colors.
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W = 1024
SCREEN_H = 700

// Layout
TOOLBAR_H = 50
PALETTE_W = 50
CANVAS_X = PALETTE_W
CANVAS_Y = 0
CANVAS_W = SCREEN_W - PALETTE_W
CANVAS_H = SCREEN_H - TOOLBAR_H

// Tools
TOOL_BRUSH   = 1
TOOL_LINE    = 2
TOOL_RECT    = 3
TOOL_CIRCLE  = 4
TOOL_FILLRECT = 5
TOOL_ERASER  = 6
TOOL_COUNT   = 6
toolNames = ["Brush", "Line", "Rect", "Circle", "FillRect", "Eraser"]
toolKeys  = ["B", "L", "R", "O", "F", "E"]

// =============================================================
// Color Palette
// =============================================================

// 10 rows of colors
paletteColors = []

// Row 1: Grayscale
add(paletteColors, [0, 0, 0])
add(paletteColors, [40, 40, 40])
add(paletteColors, [80, 80, 80])
add(paletteColors, [120, 120, 120])
add(paletteColors, [160, 160, 160])
add(paletteColors, [200, 200, 200])
add(paletteColors, [230, 230, 230])
add(paletteColors, [255, 255, 255])

// Row 2: Reds
add(paletteColors, [128, 0, 0])
add(paletteColors, [180, 0, 0])
add(paletteColors, [220, 30, 30])
add(paletteColors, [255, 60, 60])
add(paletteColors, [255, 100, 80])
add(paletteColors, [255, 140, 120])
add(paletteColors, [255, 180, 160])
add(paletteColors, [255, 220, 210])

// Row 3: Oranges/Yellows
add(paletteColors, [180, 80, 0])
add(paletteColors, [220, 120, 0])
add(paletteColors, [255, 160, 0])
add(paletteColors, [255, 200, 0])
add(paletteColors, [255, 230, 50])
add(paletteColors, [255, 245, 100])
add(paletteColors, [255, 250, 150])
add(paletteColors, [255, 255, 200])

// Row 4: Greens
add(paletteColors, [0, 80, 0])
add(paletteColors, [0, 130, 0])
add(paletteColors, [30, 180, 30])
add(paletteColors, [60, 220, 60])
add(paletteColors, [100, 240, 100])
add(paletteColors, [140, 255, 140])
add(paletteColors, [180, 255, 180])
add(paletteColors, [220, 255, 220])

// Row 5: Blues
add(paletteColors, [0, 0, 128])
add(paletteColors, [0, 0, 200])
add(paletteColors, [30, 60, 255])
add(paletteColors, [60, 120, 255])
add(paletteColors, [100, 160, 255])
add(paletteColors, [140, 200, 255])
add(paletteColors, [180, 220, 255])
add(paletteColors, [220, 240, 255])

// Row 6: Purples
add(paletteColors, [80, 0, 120])
add(paletteColors, [130, 0, 180])
add(paletteColors, [170, 50, 220])
add(paletteColors, [200, 100, 240])
add(paletteColors, [220, 140, 255])
add(paletteColors, [235, 180, 255])
add(paletteColors, [245, 210, 255])
add(paletteColors, [250, 235, 255])

// Row 7: Pinks
add(paletteColors, [180, 0, 80])
add(paletteColors, [220, 30, 120])
add(paletteColors, [255, 70, 160])
add(paletteColors, [255, 120, 180])
add(paletteColors, [255, 160, 200])
add(paletteColors, [255, 190, 220])
add(paletteColors, [255, 215, 235])
add(paletteColors, [255, 235, 245])

// Row 8: Browns/Earth
add(paletteColors, [60, 30, 10])
add(paletteColors, [100, 60, 20])
add(paletteColors, [140, 90, 40])
add(paletteColors, [180, 120, 60])
add(paletteColors, [210, 160, 100])
add(paletteColors, [230, 190, 140])
add(paletteColors, [240, 215, 180])
add(paletteColors, [250, 235, 215])

// Row 9: Cyans/Teals
add(paletteColors, [0, 80, 80])
add(paletteColors, [0, 140, 140])
add(paletteColors, [0, 200, 200])
add(paletteColors, [50, 230, 220])
add(paletteColors, [100, 240, 235])
add(paletteColors, [150, 250, 245])
add(paletteColors, [200, 255, 250])
add(paletteColors, [230, 255, 255])

PALETTE_COLS = 2
PALETTE_CELL = 24
PALETTE_ROWS = len(paletteColors) / PALETTE_COLS

// =============================================================
// State
// =============================================================

currentTool = TOOL_BRUSH
brushSize = 4
brushColor = [0, 0, 0]    // current drawing color
bgColor = [255, 255, 255]  // canvas background

showGrid = false

// Drawing state
isDrawing = false
drawStartX = 0
drawStartY = 0
lastDrawX = 0
lastDrawY = 0

// Stroke storage for undo and repaint
// Each stroke: [tool, color[3], size, points[]]
//   For brush/eraser: points = [[x1,y1], [x2,y2], ...]
//   For line/rect/circle: points = [[x1,y1,x2,y2]]
strokes = []
MAX_UNDO = 100
currentStrokePoints = []

// Toolbar
hoverBtn = 0
BTN_Y = SCREEN_H - 48
BTN_H = 36
BTN_GAP = 4

// =============================================================
// Main
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Paint Program - RingRayLib")
SetTargetFPS(60)
SetExitKey(0)

while !WindowShouldClose()
    pt_update()
    BeginDrawing()
        ClearBackground(RAYLIBColor(200, 200, 200, 255))
        pt_draw()
    EndDrawing()
end

CloseWindow()

// =============================================================
// Update
// =============================================================

func pt_update
    dt = GetFrameTime()

    if IsKeyPressed(KEY_ESCAPE)
        CloseWindow()
        shutdown(0)
    ok

    // Tool selection
    if IsKeyPressed(KEY_B) currentTool = TOOL_BRUSH ok
    if IsKeyPressed(KEY_L) currentTool = TOOL_LINE ok
    if IsKeyPressed(KEY_O) currentTool = TOOL_CIRCLE ok
    if IsKeyPressed(KEY_F) currentTool = TOOL_FILLRECT ok
    if IsKeyPressed(KEY_E) currentTool = TOOL_ERASER ok

    // R key: rectangle tool (but not if just pressed for other purposes)
    if IsKeyPressed(KEY_R)
        // Only switch tool if not ctrl pressed (avoid conflict)
        currentTool = TOOL_RECT
    ok

    // Brush size with number keys
    for k = 1 to 9
        if IsKeyPressed(48 + k)
            brushSize = k * 2
        ok
    next

    // Brush size +/-
    if IsKeyPressed(KEY_EQUAL) or IsKeyPressed(KEY_KP_ADD)
        brushSize += 2
        if brushSize > 50 brushSize = 50 ok
    ok
    if IsKeyPressed(KEY_MINUS) or IsKeyPressed(KEY_KP_SUBTRACT)
        brushSize -= 2
        if brushSize < 1 brushSize = 1 ok
    ok

    // Undo
    if IsKeyPressed(KEY_U)
        if len(strokes) > 0
            del(strokes, len(strokes))
        ok
    ok

    // Clear
    if IsKeyPressed(KEY_C)
        strokes = []
    ok

    // Grid
    if IsKeyPressed(KEY_G)
        showGrid = !showGrid
    ok

    // Mouse interaction
    mx = GetMouseX()
    my = GetMouseY()

    // Color palette click
    if IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
        if mx < PALETTE_W and my < CANVAS_H
            // Determine which color was clicked
            col = floor(mx / PALETTE_CELL)
            row = floor(my / PALETTE_CELL)
            idx = row * PALETTE_COLS + col + 1
            if idx >= 1 and idx <= len(paletteColors)
                c = paletteColors[idx]
                brushColor = [c[1], c[2], c[3]]
            ok
        ok
    ok

    // Toolbar click
    if IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
        pt_handleClick(mx, my)
    ok

    // Drawing on canvas
    if mx >= CANVAS_X and mx < CANVAS_X + CANVAS_W and my >= CANVAS_Y and my < CANVAS_Y + CANVAS_H
        // Right-click eraser
        drawCol = brushColor
        drawTool = currentTool
        if IsMouseButtonDown(MOUSE_RIGHT_BUTTON)
            drawCol = bgColor
            drawTool = TOOL_ERASER
        ok

        if IsMouseButtonPressed(MOUSE_LEFT_BUTTON) and hoverBtn = 0 and mx >= CANVAS_X
            isDrawing = true
            drawStartX = mx
            drawStartY = my
            lastDrawX = mx
            lastDrawY = my
            currentStrokePoints = []
            if drawTool = TOOL_BRUSH or drawTool = TOOL_ERASER
                add(currentStrokePoints, [mx, my])
            ok
        ok

        if IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)
            isDrawing = true
            drawStartX = mx
            drawStartY = my
            lastDrawX = mx
            lastDrawY = my
            currentStrokePoints = []
            add(currentStrokePoints, [mx, my])
        ok

        if isDrawing
            if IsMouseButtonDown(MOUSE_LEFT_BUTTON) or IsMouseButtonDown(MOUSE_RIGHT_BUTTON)
                if drawTool = TOOL_BRUSH or drawTool = TOOL_ERASER
                    if mx != lastDrawX or my != lastDrawY
                        add(currentStrokePoints, [mx, my])
                        lastDrawX = mx
                        lastDrawY = my
                    ok
                ok
            ok
        ok

        // Release
        if IsMouseButtonReleased(MOUSE_LEFT_BUTTON) or IsMouseButtonReleased(MOUSE_RIGHT_BUTTON)
            if isDrawing
                isDrawing = false
                // Store completed stroke
                if drawTool = TOOL_BRUSH or drawTool = TOOL_ERASER
                    if len(currentStrokePoints) > 0
                        pt_addStroke(drawTool, drawCol, brushSize, currentStrokePoints)
                    ok
                ok
                if drawTool = TOOL_LINE or drawTool = TOOL_RECT or drawTool = TOOL_CIRCLE or drawTool = TOOL_FILLRECT
                    pts = [[drawStartX, drawStartY, mx, my]]
                    pt_addStroke(drawTool, drawCol, brushSize, pts)
                ok
                currentStrokePoints = []
            ok
        ok
    else
        // Mouse left canvas
        if isDrawing
            if IsMouseButtonReleased(MOUSE_LEFT_BUTTON) or IsMouseButtonReleased(MOUSE_RIGHT_BUTTON)
                isDrawing = false
                drawTool2 = currentTool
                drawCol2 = brushColor
                if IsMouseButtonReleased(MOUSE_RIGHT_BUTTON)
                    drawCol2 = bgColor
                    drawTool2 = TOOL_ERASER
                ok
                if drawTool2 = TOOL_BRUSH or drawTool2 = TOOL_ERASER
                    if len(currentStrokePoints) > 0
                        pt_addStroke(drawTool2, drawCol2, brushSize, currentStrokePoints)
                    ok
                ok
                currentStrokePoints = []
            ok
        ok
    ok

func pt_addStroke tool, color, size, points
    if len(strokes) >= MAX_UNDO
        del(strokes, 1)
    ok
    add(strokes, [tool, [color[1], color[2], color[3]], size, points])

// =============================================================
// Draw
// =============================================================

func pt_draw
    // Canvas background
    DrawRectangle(CANVAS_X, CANVAS_Y, CANVAS_W, CANVAS_H, RAYLIBColor(bgColor[1], bgColor[2], bgColor[3], 255))

    // Grid
    if showGrid
        gridStep = 20
        for gx = CANVAS_X to CANVAS_X + CANVAS_W step gridStep
            DrawLine(gx, 0, gx, CANVAS_H, RAYLIBColor(200, 200, 200, 80))
        next
        for gy = 0 to CANVAS_H step gridStep
            DrawLine(CANVAS_X, gy, CANVAS_X + CANVAS_W, gy, RAYLIBColor(200, 200, 200, 80))
        next
    ok

    // Draw all strokes
    for s = 1 to len(strokes)
        st = strokes[s]
        sTool = st[1]
        sCol = st[2]
        sSize = st[3]
        sPts = st[4]

        col = RAYLIBColor(sCol[1], sCol[2], sCol[3], 255)

        if sTool = TOOL_BRUSH or sTool = TOOL_ERASER
            pt_drawBrushStroke(sPts, sSize, col)
        ok
        if sTool = TOOL_LINE
            p = sPts[1]
            DrawLine(p[1], p[2], p[3], p[4], col)
            // Thicker line
            for off = -floor(sSize/2) to floor(sSize/2)
                DrawLine(p[1], p[2]+off, p[3], p[4]+off, col)
            next
        ok
        if sTool = TOOL_RECT
            p = sPts[1]
            rx = p[1]  ry = p[2]  rx2 = p[3]  ry2 = p[4]
            if rx > rx2  temp = rx  rx = rx2  rx2 = temp ok
            if ry > ry2  temp = ry  ry = ry2  ry2 = temp ok
            rw = rx2 - rx   rh = ry2 - ry
            for t = 0 to sSize - 1
                DrawRectangleLines(rx - t, ry - t, rw + t*2, rh + t*2, col)
            next
        ok
        if sTool = TOOL_FILLRECT
            p = sPts[1]
            rx = p[1]  ry = p[2]  rx2 = p[3]  ry2 = p[4]
            if rx > rx2  temp = rx  rx = rx2  rx2 = temp ok
            if ry > ry2  temp = ry  ry = ry2  ry2 = temp ok
            DrawRectangle(rx, ry, rx2 - rx, ry2 - ry, col)
        ok
        if sTool = TOOL_CIRCLE
            p = sPts[1]
            cx = (p[1] + p[3]) / 2
            cy = (p[2] + p[4]) / 2
            dx = p[3] - p[1]
            dy = p[4] - p[2]
            radius = floor(sqrt(dx*dx + dy*dy) / 2)
            if radius > 0
                DrawCircleLines(cx, cy, radius, col)
                for t = 1 to sSize - 1
                    DrawCircleLines(cx, cy, radius - t, col)
                next
            ok
        ok
    next

    // Live preview of current stroke
    if isDrawing
        mx = GetMouseX()
        my = GetMouseY()
        drawCol = brushColor
        drawTool = currentTool
        if IsMouseButtonDown(MOUSE_RIGHT_BUTTON)
            drawCol = bgColor
            drawTool = TOOL_ERASER
        ok
        col = RAYLIBColor(drawCol[1], drawCol[2], drawCol[3], 255)

        if drawTool = TOOL_BRUSH or drawTool = TOOL_ERASER
            if len(currentStrokePoints) > 0
                pt_drawBrushStroke(currentStrokePoints, brushSize, col)
            ok
        ok
        if drawTool = TOOL_LINE
            for off = -floor(brushSize/2) to floor(brushSize/2)
                DrawLine(drawStartX, drawStartY+off, mx, my+off, col)
            next
        ok
        if drawTool = TOOL_RECT
            rx = drawStartX  ry = drawStartY  rx2 = mx  ry2 = my
            if rx > rx2  temp = rx  rx = rx2  rx2 = temp ok
            if ry > ry2  temp = ry  ry = ry2  ry2 = temp ok
            rw = rx2 - rx   rh = ry2 - ry
            for t = 0 to brushSize - 1
                DrawRectangleLines(rx - t, ry - t, rw + t*2, rh + t*2, col)
            next
        ok
        if drawTool = TOOL_FILLRECT
            rx = drawStartX  ry = drawStartY  rx2 = mx  ry2 = my
            if rx > rx2  temp = rx  rx = rx2  rx2 = temp ok
            if ry > ry2  temp = ry  ry = ry2  ry2 = temp ok
            DrawRectangle(rx, ry, rx2 - rx, ry2 - ry, col)
        ok
        if drawTool = TOOL_CIRCLE
            cx2 = (drawStartX + mx) / 2
            cy2 = (drawStartY + my) / 2
            dx = mx - drawStartX
            dy = my - drawStartY
            radius = floor(sqrt(dx*dx + dy*dy) / 2)
            if radius > 0
                DrawCircleLines(cx2, cy2, radius, col)
                for t = 1 to brushSize - 1
                    DrawCircleLines(cx2, cy2, radius - t, col)
                next
            ok
        ok
    ok

    // Cursor preview
    mx = GetMouseX()
    my = GetMouseY()
    if mx >= CANVAS_X and mx < CANVAS_X + CANVAS_W and my < CANVAS_H
        if currentTool = TOOL_BRUSH
            DrawCircleLines(mx, my, brushSize, RAYLIBColor(0, 0, 0, 120))
        ok
        if currentTool = TOOL_ERASER
            DrawCircleLines(mx, my, brushSize, RAYLIBColor(255, 0, 0, 120))
            DrawLine(mx - brushSize, my, mx + brushSize, my, RAYLIBColor(255, 0, 0, 80))
            DrawLine(mx, my - brushSize, mx, my + brushSize, RAYLIBColor(255, 0, 0, 80))
        ok
    ok

    // Color palette
    pt_drawPalette()

    // Toolbar
    pt_drawToolbar()

// =============================================================
// Draw Brush Stroke (interpolated circles)
// =============================================================

func pt_drawBrushStroke pts, size, col
    if len(pts) < 1 return ok

    // Draw first point
    DrawCircle(pts[1][1], pts[1][2], size, col)

    // Interpolate between consecutive points
    for i = 2 to len(pts)
        x1 = pts[i-1][1]  y1 = pts[i-1][2]
        x2 = pts[i][1]    y2 = pts[i][2]

        dx = x2 - x1
        dy = y2 - y1
        dist = sqrt(dx*dx + dy*dy)
        steps = floor(dist / (size * 0.3))
        if steps < 1 steps = 1 ok

        for s = 0 to steps
            t = s * 1.0 / steps
            px = x1 + dx * t
            py = y1 + dy * t
            DrawCircle(floor(px), floor(py), size, col)
        next
    next

// =============================================================
// Color Palette (left sidebar)
// =============================================================

func pt_drawPalette
    // Background
    DrawRectangle(0, 0, PALETTE_W, CANVAS_H, RAYLIBColor(50, 50, 60, 255))

    // Color cells
    for i = 1 to len(paletteColors)
        c = paletteColors[i]
        row = floor((i - 1) / PALETTE_COLS)
        col = (i - 1) % PALETTE_COLS

        px = col * PALETTE_CELL + 1
        py = row * PALETTE_CELL + 1
        cw = PALETTE_CELL - 2
        ch = PALETTE_CELL - 2

        DrawRectangle(px, py, cw, ch, RAYLIBColor(c[1], c[2], c[3], 255))

        // Highlight if selected
        if c[1] = brushColor[1] and c[2] = brushColor[2] and c[3] = brushColor[3]
            DrawRectangleLines(px - 1, py - 1, cw + 2, ch + 2, RAYLIBColor(255, 255, 0, 255))
            DrawRectangleLines(px - 2, py - 2, cw + 4, ch + 4, RAYLIBColor(255, 255, 0, 255))
        ok
    next

    // Current color preview at bottom of palette
    previewY = CANVAS_H - 70
    DrawRectangle(2, previewY, PALETTE_W - 4, 30, RAYLIBColor(brushColor[1], brushColor[2], brushColor[3], 255))
    DrawRectangleLines(2, previewY, PALETTE_W - 4, 30, RAYLIBColor(255, 255, 255, 120))

    // Brush size preview
    szY = previewY + 35
    DrawCircle(PALETTE_W / 2, szY + 15, brushSize, RAYLIBColor(brushColor[1], brushColor[2], brushColor[3], 200))
    DrawCircleLines(PALETTE_W / 2, szY + 15, brushSize, RAYLIBColor(255, 255, 255, 100))

// =============================================================
// Toolbar
// =============================================================

func pt_drawToolbar
    DrawRectangle(0, SCREEN_H - TOOLBAR_H, SCREEN_W, TOOLBAR_H, RAYLIBColor(40, 40, 55, 255))
    DrawRectangle(0, SCREEN_H - TOOLBAR_H, SCREEN_W, 2, RAYLIBColor(80, 80, 120, 200))

    mx = GetMouseX()
    my = GetMouseY()
    hoverBtn = 0

    bx = PALETTE_W + BTN_GAP

    // Tool buttons
    toolBtnColors = [
        RAYLIBColor(60, 100, 160, 255),
        RAYLIBColor(60, 130, 80, 255),
        RAYLIBColor(130, 80, 60, 255),
        RAYLIBColor(100, 60, 140, 255),
        RAYLIBColor(140, 100, 40, 255),
        RAYLIBColor(140, 50, 50, 255)
    ]

    for i = 1 to TOOL_COUNT
        label = toolNames[i] + "[" + toolKeys[i] + "]"
        col = toolBtnColors[i]
        if currentTool = i
            col = RAYLIBColor(200, 200, 80, 255)
        ok
        bx = pt_drawBtn(label, bx, i, col, mx, my)
        bx += BTN_GAP
    next

    // Separator
    DrawRectangle(bx, BTN_Y + 4, 2, BTN_H - 8, RAYLIBColor(80, 80, 120, 150))
    bx += BTN_GAP + 2

    // Undo
    bx = pt_drawBtn("Undo[U]", bx, 20, RAYLIBColor(130, 100, 40, 255), mx, my)
    bx += BTN_GAP

    // Clear
    bx = pt_drawBtn("Clear[C]", bx, 21, RAYLIBColor(160, 40, 40, 255), mx, my)
    bx += BTN_GAP

    // Grid
    gridCol = RAYLIBColor(60, 60, 60, 255)
    if showGrid gridCol = RAYLIBColor(60, 120, 60, 255) ok
    bx = pt_drawBtn("Grid[G]", bx, 22, gridCol, mx, my)
    bx += BTN_GAP

    // Separator
    DrawRectangle(bx, BTN_Y + 4, 2, BTN_H - 8, RAYLIBColor(80, 80, 120, 150))
    bx += BTN_GAP + 2

    // Size -/+
    bx = pt_drawBtn("Size-", bx, 30, RAYLIBColor(120, 60, 60, 255), mx, my)
    bx += BTN_GAP
    bx = pt_drawBtn("Size+", bx, 31, RAYLIBColor(60, 120, 60, 255), mx, my)
    bx += BTN_GAP

    // Info text
    infoTxt = "Size:" + string(brushSize) + "  Strokes:" + string(len(strokes))
    DrawText(infoTxt, bx + 5, BTN_Y + 12, 13, RAYLIBColor(180, 180, 200, 180))

    // FPS
    fpsTxt = "" + string(GetFPS()) + " FPS"
    DrawText(fpsTxt, SCREEN_W - 60, SCREEN_H - 14, 12, RAYLIBColor(100, 200, 100, 120))

func pt_drawBtn label, bx, btnId, baseCol, mx, my
    tw = MeasureText(label, 12) + 12
    if tw < 36 tw = 36 ok

    isHover = (mx >= bx and mx <= bx + tw and my >= BTN_Y and my <= BTN_Y + BTN_H)

    if isHover
        hoverBtn = btnId
        DrawRectangle(bx, BTN_Y, tw, BTN_H, RAYLIBColor(255, 225, 100, 240))
        DrawRectangleLines(bx, BTN_Y, tw, BTN_H, RAYLIBColor(200, 180, 60, 255))
        lw = MeasureText(label, 12)
        DrawText(label, bx + (tw - lw) / 2, BTN_Y + 12, 12, RAYLIBColor(20, 15, 10, 255))
    else
        DrawRectangle(bx, BTN_Y, tw, BTN_H, baseCol)
        DrawRectangleLines(bx, BTN_Y, tw, BTN_H, RAYLIBColor(255, 255, 255, 30))
        lw = MeasureText(label, 12)
        DrawText(label, bx + (tw - lw) / 2, BTN_Y + 12, 12, WHITE)
    ok

    return bx + tw

// =============================================================
// Handle Click
// =============================================================

func pt_handleClick mx, my
    if hoverBtn >= 1 and hoverBtn <= TOOL_COUNT
        currentTool = hoverBtn
        return
    ok
    if hoverBtn = 20
        if len(strokes) > 0
            del(strokes, len(strokes))
        ok
        return
    ok
    if hoverBtn = 21
        strokes = []
        return
    ok
    if hoverBtn = 22
        showGrid = !showGrid
        return
    ok
    if hoverBtn = 30
        brushSize -= 2
        if brushSize < 1 brushSize = 1 ok
        return
    ok
    if hoverBtn = 31
        brushSize += 2
        if brushSize > 50 brushSize = 50 ok
        return
    ok

