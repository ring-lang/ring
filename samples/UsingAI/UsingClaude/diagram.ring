/*
**  Diagram Tool - RingRayLib
**  ============================
**  Flowchart / diagram maker with draggable boxes and arrows.
**
**  Controls:
**    Mouse Left       - Select / Drag box / Click toolbar
**    Mouse Left+Drag  - Drag selected box
**    Mouse Right      - Start connection from hovered box
**    Double-Click     - Edit box text (type + Enter to confirm)
**    Delete / X       - Delete selected box or connection
**    N                - New box at center
**    1-5              - Change selected box shape
**    C                - Cycle selected box color
**    G                - Toggle grid snap
**    A                - Auto-layout (arrange in grid)
**    U                - Undo last action
**    Ctrl+A           - Select all
**    ESC              - Cancel edit / Deselect / Exit
**
**  Shapes:
**    1. Rectangle     2. Rounded Rect
**    3. Diamond       4. Oval
**    5. Parallelogram
**
**  Connection:
**    Right-click a box, then right-click another box
**    to create an arrow between them.
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W = 1024
SCREEN_H = 700
TOOLBAR_H = 52
CANVAS_Y = 0
CANVAS_H = SCREEN_H - TOOLBAR_H

// Shapes
SHAPE_RECT       = 1
SHAPE_ROUNDED    = 2
SHAPE_DIAMOND    = 3
SHAPE_OVAL       = 4
SHAPE_PARALLEL   = 5
SHAPE_COUNT      = 5
shapeNames = ["Rect", "Rounded", "Diamond", "Oval", "Parallel"]

// Box colors (palette)
BOX_COLORS = [
    [100, 160, 255],
    [80, 200, 120],
    [255, 160, 60],
    [220, 80, 80],
    [180, 120, 220],
    [80, 200, 200],
    [220, 200, 60],
    [200, 140, 100],
    [160, 160, 180],
    [255, 255, 255]
]
COLOR_COUNT = 10

// Default box size
DEF_BOX_W = 140
DEF_BOX_H = 60

// Grid
GRID_SIZE = 20

PI = 3.14159265

// =============================================================
// Data Structures
// =============================================================

// Boxes: list of lists
//   [id, x, y, w, h, text, shapeType, colorIdx, selected]
MAX_BOXES = 200
boxes = []
nextBoxId = 1

// Connections: list of lists
//   [fromId, toId, selected]
connections = []

// =============================================================
// State
// =============================================================

// Interaction
selectedBox = 0         // index in boxes[]
dragging = false
dragOffX = 0
dragOffY = 0

// Connection mode
connectMode = false
connectFromId = 0

// Text editing
editMode = false
editBoxIdx = 0
editText = ""
editCursorBlink = 0.0

// Selection
selectedConn = 0        // index in connections[]

// Grid snap
gridSnap = true

// Undo stack
undoStack = []
MAX_UNDO = 50

// Toolbar
hoverBtn = 0
BTN_Y = SCREEN_H - 50
BTN_H = 38
BTN_GAP = 4

// Double-click detection
lastClickTime = 0.0
lastClickX = 0
lastClickY = 0
DBLCLICK_TIME = 0.4
DBLCLICK_DIST = 8

animTime = 0.0

// =============================================================
// Main
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Diagram Tool - RingRayLib")
SetTargetFPS(60)
SetExitKey(0)

// Create a few starter boxes
dg_addBox(200, 150, DEF_BOX_W, DEF_BOX_H, "Start", SHAPE_ROUNDED, 2)
dg_addBox(200, 320, DEF_BOX_W, DEF_BOX_H, "Process", SHAPE_RECT, 1)
dg_addBox(200, 490, DEF_BOX_W, DEF_BOX_H, "Decision", SHAPE_DIAMOND, 4)
dg_addBox(450, 320, DEF_BOX_W, DEF_BOX_H, "End", SHAPE_ROUNDED, 3)

// Starter connections
dg_addConnection(1, 2)
dg_addConnection(2, 3)
dg_addConnection(3, 4)

while !WindowShouldClose()
    dg_update()
    BeginDrawing()
        ClearBackground(RAYLIBColor(32, 34, 42, 255))
        dg_draw()
    EndDrawing()
end

CloseWindow()

// =============================================================
// Box Management
// =============================================================

func dg_addBox x, y, w, h, text, shape, colorIdx
    id = nextBoxId
    nextBoxId++
    add(boxes, [id, x, y, w, h, text, shape, colorIdx, 0])
    return id

func dg_addConnection fromId, toId
    // Don't duplicate
    for i = 1 to len(connections)
        c = connections[i]
        if c[1] = fromId and c[2] = toId return ok
    next
    add(connections, [fromId, toId, 0])

func dg_findBoxById id
    for i = 1 to len(boxes)
        if boxes[i][1] = id return i ok
    next
    return 0

func dg_boxAt mx, my
    // Return index of topmost box at position (reverse order = top)
    for i = len(boxes) to 1 step -1
        b = boxes[i]
        bx = b[2]  by = b[3]  bw = b[4]  bh = b[5]
        shape = b[7]

        if shape = SHAPE_DIAMOND
            // Diamond hit test
            cx = bx + bw / 2   cy = by + bh / 2
            dx = fabs(mx - cx) / (bw / 2.0)
            dy = fabs(my - cy) / (bh / 2.0)
            if dx + dy <= 1.15  return i  ok
        but shape = SHAPE_OVAL
            cx = bx + bw / 2   cy = by + bh / 2
            rx = bw / 2.0   ry = bh / 2.0
            dx = (mx - cx) / rx
            dy = (my - cy) / ry
            if dx * dx + dy * dy <= 1.1  return i  ok
        else
            // Rectangle-based shapes
            if mx >= bx and mx <= bx + bw and my >= by and my <= by + bh
                return i
            ok
        ok
    next
    return 0

func dg_connAt mx, my
    // Check if mouse is near a connection line
    for i = 1 to len(connections)
        c = connections[i]
        fi = dg_findBoxById(c[1])
        ti = dg_findBoxById(c[2])
        if fi = 0 or ti = 0 loop ok

        fb = boxes[fi]
        tb = boxes[ti]
        x1 = fb[2] + fb[4] / 2
        y1 = fb[3] + fb[5] / 2
        x2 = tb[2] + tb[4] / 2
        y2 = tb[3] + tb[5] / 2

        // Distance from point to line segment
        dist = dg_pointLineDist(mx, my, x1, y1, x2, y2)
        if dist < 8  return i  ok
    next
    return 0

func dg_pointLineDist px, py, x1, y1, x2, y2
    dx = x2 - x1   dy = y2 - y1
    lenSq = dx * dx + dy * dy
    if lenSq < 1  return sqrt((px-x1)*(px-x1) + (py-y1)*(py-y1))  ok
    t = ((px - x1) * dx + (py - y1) * dy) / lenSq
    if t < 0  t = 0  ok
    if t > 1  t = 1  ok
    projX = x1 + t * dx
    projY = y1 + t * dy
    return sqrt((px - projX) * (px - projX) + (py - projY) * (py - projY))

// =============================================================
// Undo
// =============================================================

func dg_saveUndo
    // Save snapshot of boxes and connections
    bSnap = []
    for i = 1 to len(boxes)
        b = boxes[i]
        add(bSnap, [b[1], b[2], b[3], b[4], b[5], b[6], b[7], b[8], b[9]])
    next
    cSnap = []
    for i = 1 to len(connections)
        c = connections[i]
        add(cSnap, [c[1], c[2], c[3]])
    next
    add(undoStack, [bSnap, cSnap, nextBoxId])
    if len(undoStack) > MAX_UNDO
        del(undoStack, 1)
    ok

func dg_undo
    if len(undoStack) = 0 return ok
    snap = undoStack[len(undoStack)]
    del(undoStack, len(undoStack))

    boxes = []
    for i = 1 to len(snap[1])
        s = snap[1][i]
        add(boxes, [s[1], s[2], s[3], s[4], s[5], s[6], s[7], s[8], s[9]])
    next
    connections = []
    for i = 1 to len(snap[2])
        s = snap[2][i]
        add(connections, [s[1], s[2], s[3]])
    next
    nextBoxId = snap[3]
    selectedBox = 0
    selectedConn = 0
    editMode = false

// =============================================================
// Update
// =============================================================

func dg_update
    dt = GetFrameTime()
    animTime += dt
    editCursorBlink += dt

    mx = GetMouseX()
    my = GetMouseY()

    if IsKeyPressed(KEY_ESCAPE)
        if editMode
            editMode = false
        but selectedBox > 0
            dg_deselectAll()
        but connectMode
            connectMode = false
        else
            CloseWindow()
            shutdown(0)
        ok
    ok

    // Text editing mode
    if editMode
        dg_handleTextEdit()
        return
    ok

    // Keyboard shortcuts
    if IsKeyPressed(KEY_N)
        dg_saveUndo()
        cx = SCREEN_W / 2 - DEF_BOX_W / 2
        cy = CANVAS_H / 2 - DEF_BOX_H / 2
        if gridSnap
            cx = floor(cx / GRID_SIZE) * GRID_SIZE
            cy = floor(cy / GRID_SIZE) * GRID_SIZE
        ok
        id = dg_addBox(cx, cy, DEF_BOX_W, DEF_BOX_H, "New Box", SHAPE_RECT, 1)
        dg_deselectAll()
        idx = dg_findBoxById(id)
        if idx > 0
            boxes[idx][9] = 1
            selectedBox = idx
        ok
    ok

    if IsKeyPressed(KEY_DELETE) or IsKeyPressed(KEY_X)
        dg_deleteSelected()
    ok

    if IsKeyPressed(KEY_U)
        dg_undo()
    ok

    if IsKeyPressed(KEY_G)
        gridSnap = !gridSnap
    ok

    if IsKeyPressed(KEY_A)
        dg_autoLayout()
    ok

    // Shape change for selected box
    if selectedBox > 0
        for k = 1 to SHAPE_COUNT
            if IsKeyPressed(48 + k)
                dg_saveUndo()
                boxes[selectedBox][7] = k
            ok
        next
        if IsKeyPressed(KEY_C)
            dg_saveUndo()
            ci = boxes[selectedBox][8] + 1
            if ci > COLOR_COUNT ci = 1 ok
            boxes[selectedBox][8] = ci
        ok
    ok

    // Toolbar
    if IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
        dg_handleToolbarClick(mx, my)
    ok

    // Canvas interactions
    if my < CANVAS_H
        dg_handleCanvasInput(mx, my, dt)
    ok

// =============================================================
// Canvas Input
// =============================================================

func dg_handleCanvasInput mx, my, dt
    // LEFT CLICK
    if IsMouseButtonPressed(MOUSE_LEFT_BUTTON) and hoverBtn = 0
        // Double click detection
        now = animTime
        dx = mx - lastClickX
        dy = my - lastClickY
        dist = sqrt(dx*dx + dy*dy)
        isDouble = (now - lastClickTime < DBLCLICK_TIME and dist < DBLCLICK_DIST)
        lastClickTime = now
        lastClickX = mx
        lastClickY = my

        hitBox = dg_boxAt(mx, my)

        if isDouble and hitBox > 0
            // Enter edit mode
            editMode = true
            editBoxIdx = hitBox
            editText = boxes[hitBox][6]
            editCursorBlink = 0.0
            dg_deselectAll()
            boxes[hitBox][9] = 1
            selectedBox = hitBox
            return
        ok

        if hitBox > 0
            // Select and start drag
            dg_deselectAll()
            boxes[hitBox][9] = 1
            selectedBox = hitBox
            dragging = true
            dragOffX = mx - boxes[hitBox][2]
            dragOffY = my - boxes[hitBox][3]
            dg_saveUndo()
        else
            // Check connection click
            hitConn = dg_connAt(mx, my)
            if hitConn > 0
                dg_deselectAll()
                connections[hitConn][3] = 1
                selectedConn = hitConn
            else
                dg_deselectAll()
            ok
        ok
    ok

    // Dragging
    if dragging
        if IsMouseButtonDown(MOUSE_LEFT_BUTTON) and selectedBox > 0
            newX = mx - dragOffX
            newY = my - dragOffY
            if gridSnap
                newX = floor(newX / GRID_SIZE + 0.5) * GRID_SIZE
                newY = floor(newY / GRID_SIZE + 0.5) * GRID_SIZE
            ok
            // Clamp to canvas
            if newX < 0 newX = 0 ok
            if newY < 0 newY = 0 ok
            if newX + boxes[selectedBox][4] > SCREEN_W
                newX = SCREEN_W - boxes[selectedBox][4]
            ok
            if newY + boxes[selectedBox][5] > CANVAS_H
                newY = CANVAS_H - boxes[selectedBox][5]
            ok
            boxes[selectedBox][2] = newX
            boxes[selectedBox][3] = newY
        else
            dragging = false
        ok
    ok

    // RIGHT CLICK - Connection mode
    if IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)
        hitBox = dg_boxAt(mx, my)
        if hitBox > 0
            if !connectMode
                connectMode = true
                connectFromId = boxes[hitBox][1]
            else
                // Complete connection
                toId = boxes[hitBox][1]
                if toId != connectFromId
                    dg_saveUndo()
                    dg_addConnection(connectFromId, toId)
                ok
                connectMode = false
            ok
        else
            connectMode = false
        ok
    ok

// =============================================================
// Text Editing
// =============================================================

func dg_handleTextEdit
    // Accept typed characters
    ch = GetCharPressed()
    while ch > 0
        if ch >= 32 and ch < 127
            editText += char(ch)
        ok
        ch = GetCharPressed()
    end

    // Backspace
    if IsKeyPressed(KEY_BACKSPACE) or IsKeyDown(KEY_BACKSPACE)
        if len(editText) > 0
            editText = left(editText, len(editText) - 1)
        ok
    ok

    // Enter = confirm
    if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_KP_ENTER)
        dg_saveUndo()
        if editBoxIdx > 0 and editBoxIdx <= len(boxes)
            boxes[editBoxIdx][6] = editText
        ok
        editMode = false
    ok

// =============================================================
// Delete Selected
// =============================================================

func dg_deleteSelected
    if selectedBox > 0
        dg_saveUndo()
        bid = boxes[selectedBox][1]
        del(boxes, selectedBox)
        // Remove connections involving this box
        i = len(connections)
        while i >= 1
            if connections[i][1] = bid or connections[i][2] = bid
                del(connections, i)
            ok
            i--
        end
        selectedBox = 0
    ok
    if selectedConn > 0
        dg_saveUndo()
        del(connections, selectedConn)
        selectedConn = 0
    ok

// =============================================================
// Auto Layout
// =============================================================

func dg_autoLayout
    if len(boxes) = 0 return ok
    dg_saveUndo()
    cols = floor(sqrt(len(boxes))) + 1
    padX = 180
    padY = 100
    startX = 60
    startY = 40

    for i = 1 to len(boxes)
        col = (i - 1) % cols
        row = floor((i - 1) / cols)
        nx = startX + col * padX
        ny = startY + row * padY
        if gridSnap
            nx = floor(nx / GRID_SIZE) * GRID_SIZE
            ny = floor(ny / GRID_SIZE) * GRID_SIZE
        ok
        boxes[i][2] = nx
        boxes[i][3] = ny
    next

// =============================================================
// Deselect
// =============================================================

func dg_deselectAll
    selectedBox = 0
    selectedConn = 0
    for i = 1 to len(boxes)
        boxes[i][9] = 0
    next
    for i = 1 to len(connections)
        connections[i][3] = 0
    next

// =============================================================
// Draw
// =============================================================

func dg_draw
    // Grid
    if gridSnap
        for gx = 0 to SCREEN_W step GRID_SIZE
            DrawLine(gx, 0, gx, CANVAS_H, RAYLIBColor(40, 42, 52, 255))
        next
        for gy = 0 to CANVAS_H step GRID_SIZE
            DrawLine(0, gy, SCREEN_W, gy, RAYLIBColor(40, 42, 52, 255))
        next
    ok

    // Connections
    for i = 1 to len(connections)
        dg_drawConnection(i)
    next

    // Connection in-progress
    if connectMode
        fi = dg_findBoxById(connectFromId)
        if fi > 0
            fb = boxes[fi]
            fx = fb[2] + fb[4] / 2
            fy = fb[3] + fb[5] / 2
            mx = GetMouseX()
            my = GetMouseY()
            // Dashed animated line
            pulse = floor(fabs(sin(animTime * 4)) * 100) + 155
            DrawLine(floor(fx), floor(fy), mx, my, RAYLIBColor(255, 200, 50, pulse))
            // Arrow at cursor
            dg_drawArrowHead(fx, fy, mx * 1.0, my * 1.0, 12, RAYLIBColor(255, 200, 50, pulse))
        ok
    ok

    // Boxes
    for i = 1 to len(boxes)
        dg_drawBox(i)
    next

    // HUD
    dg_drawHUD()

    // Toolbar
    dg_drawToolbar()

// =============================================================
// Draw Box
// =============================================================

func dg_drawBox idx
    b = boxes[idx]
    bx = b[2]   by = b[3]   bw = b[4]   bh = b[5]
    text = b[6]  shape = b[7]  ci = b[8]  sel = b[9]

    // Colors
    c = BOX_COLORS[ci]
    fillCol = RAYLIBColor(c[1], c[2], c[3], 240)
    borderCol = RAYLIBColor(floor(c[1]*0.6), floor(c[2]*0.6), floor(c[3]*0.6), 255)
    textCol = RAYLIBColor(20, 20, 30, 240)

    // Light text on dark colors
    brightness = c[1] * 0.299 + c[2] * 0.587 + c[3] * 0.114
    if brightness < 140
        textCol = RAYLIBColor(240, 240, 250, 240)
    ok

    if sel = 1
        borderCol = RAYLIBColor(255, 220, 50, 255)
    ok

    // Shadow
    dg_drawShape(bx + 3, by + 3, bw, bh, shape, RAYLIBColor(0, 0, 0, 50), RAYLIBColor(0, 0, 0, 0))

    // Fill
    dg_drawShape(bx, by, bw, bh, shape, fillCol, borderCol)

    // Selection glow
    if sel = 1
        pulse = floor(fabs(sin(animTime * 3)) * 40) + 20
        dg_drawShapeOutline(bx - 3, by - 3, bw + 6, bh + 6, shape, RAYLIBColor(255, 220, 50, pulse))
    ok

    // Text
    if editMode and editBoxIdx = idx
        // Editing: show edit text with cursor
        displayText = editText
        cursorOn = (floor(editCursorBlink * 2) % 2 = 0)
        if cursorOn
            displayText += "|"
        ok
        fontSize = 14
        tw = MeasureText(displayText, fontSize)
        DrawText(displayText, bx + (bw - tw) / 2, by + (bh - fontSize) / 2, fontSize, textCol)

        // Edit indicator
        DrawRectangleLines(bx + 4, by + bh - 8, bw - 8, 3, RAYLIBColor(255, 220, 50, 180))
    else
        // Normal text - word wrap simple
        fontSize = 14
        tw = MeasureText(text, fontSize)
        if tw < bw - 10
            DrawText(text, bx + (bw - tw) / 2, by + (bh - fontSize) / 2, fontSize, textCol)
        else
            // Smaller font
            fontSize = 12
            tw = MeasureText(text, fontSize)
            if tw < bw - 6
                DrawText(text, bx + (bw - tw) / 2, by + (bh - fontSize) / 2, fontSize, textCol)
            else
                // Two lines
                mid = floor(len(text) / 2)
                // Find nearest space
                sp = mid
                for s = mid to 1 step -1
                    if substr(text, s, 1) = " "
                        sp = s
                        exit
                    ok
                next
                line1 = left(text, sp)
                line2 = substr(text, sp + 1)
                tw1 = MeasureText(line1, fontSize)
                tw2 = MeasureText(line2, fontSize)
                DrawText(line1, bx + (bw - tw1) / 2, by + bh/2 - fontSize - 1, fontSize, textCol)
                DrawText(line2, bx + (bw - tw2) / 2, by + bh/2 + 2, fontSize, textCol)
            ok
        ok
    ok

    // Connection port dots (when hovering)
    hovIdx = dg_boxAt(GetMouseX(), GetMouseY())
    if hovIdx = idx and !editMode
        cx = bx + bw / 2   cy = by + bh / 2
        // Top, bottom, left, right
        DrawCircle(cx, by - 2, 4, RAYLIBColor(255, 200, 50, 180))
        DrawCircle(cx, by + bh + 2, 4, RAYLIBColor(255, 200, 50, 180))
        DrawCircle(bx - 2, cy, 4, RAYLIBColor(255, 200, 50, 180))
        DrawCircle(bx + bw + 2, cy, 4, RAYLIBColor(255, 200, 50, 180))
    ok

// =============================================================
// Draw Shape
// =============================================================

func dg_drawShape x, y, w, h, shape, fillCol, borderCol
    if shape = SHAPE_RECT
        DrawRectangle(x, y, w, h, fillCol)
        DrawRectangleLines(x, y, w, h, borderCol)
        DrawRectangleLines(x+1, y+1, w-2, h-2, borderCol)
    ok

    if shape = SHAPE_ROUNDED
        // Rounded rect approximation: rect + circles at corners
        r = 10
        DrawRectangle(x + r, y, w - r*2, h, fillCol)
        DrawRectangle(x, y + r, w, h - r*2, fillCol)
        DrawCircle(x + r, y + r, r, fillCol)
        DrawCircle(x + w - r, y + r, r, fillCol)
        DrawCircle(x + r, y + h - r, r, fillCol)
        DrawCircle(x + w - r, y + h - r, r, fillCol)
        // Border
        DrawLine(x + r, y, x + w - r, y, borderCol)
        DrawLine(x + r, y + h, x + w - r, y + h, borderCol)
        DrawLine(x, y + r, x, y + h - r, borderCol)
        DrawLine(x + w, y + r, x + w, y + h - r, borderCol)
    ok

    if shape = SHAPE_DIAMOND
        cx = x + w / 2   cy = y + h / 2
        // Four triangles
        DrawTriangle(Vector2(cx, y), Vector2(x, cy), Vector2(cx, y+h), fillCol)
        DrawTriangle(Vector2(cx, y), Vector2(cx, y+h), Vector2(x+w, cy), fillCol)
        // Border
        DrawLine(cx, y, x, cy, borderCol)
        DrawLine(x, cy, cx, y+h, borderCol)
        DrawLine(cx, y+h, x+w, cy, borderCol)
        DrawLine(x+w, cy, cx, y, borderCol)
    ok

    if shape = SHAPE_OVAL
        cx = x + w / 2   cy = y + h / 2
        // Approximate ellipse with segments
        segments = 36
        prevPX = cx + w/2   prevPY = cy
        for s = 1 to segments
            angle = s * PI * 2 / segments
            px = cx + cos(angle) * w / 2
            py = cy + sin(angle) * h / 2
            // Fill triangle
            DrawTriangle(Vector2(cx, cy), Vector2(prevPX, prevPY), Vector2(px, py), fillCol)
            // Border
            DrawLine(floor(prevPX), floor(prevPY), floor(px), floor(py), borderCol)
            prevPX = px   prevPY = py
        next
    ok

    if shape = SHAPE_PARALLEL
        skew = 15
        // Parallelogram: top-left shifted right, bottom-left at x
        DrawTriangle(Vector2(x+skew, y), Vector2(x, y+h), Vector2(x+w, y+h), fillCol)
        DrawTriangle(Vector2(x+skew, y), Vector2(x+w, y+h), Vector2(x+w+skew, y), fillCol)
        // Border
        DrawLine(x+skew, y, x+w+skew, y, borderCol)
        DrawLine(x+w+skew, y, x+w, y+h, borderCol)
        DrawLine(x+w, y+h, x, y+h, borderCol)
        DrawLine(x, y+h, x+skew, y, borderCol)
    ok

func dg_drawShapeOutline x, y, w, h, shape, col
    if shape = SHAPE_RECT or shape = SHAPE_ROUNDED
        DrawRectangleLines(x, y, w, h, col)
    ok
    if shape = SHAPE_DIAMOND
        cx = x + w/2  cy = y + h/2
        DrawLine(cx, y, x, cy, col)
        DrawLine(x, cy, cx, y+h, col)
        DrawLine(cx, y+h, x+w, cy, col)
        DrawLine(x+w, cy, cx, y, col)
    ok
    if shape = SHAPE_OVAL
        cx = x + w/2  cy = y + h/2
        segments = 36
        prevPX = cx + w/2   prevPY = cy
        for s = 1 to segments
            angle = s * PI * 2 / segments
            px = cx + cos(angle) * w / 2
            py = cy + sin(angle) * h / 2
            DrawLine(floor(prevPX), floor(prevPY), floor(px), floor(py), col)
            prevPX = px   prevPY = py
        next
    ok
    if shape = SHAPE_PARALLEL
        skew = 18
        DrawLine(x+skew, y, x+w+skew, y, col)
        DrawLine(x+w+skew, y, x+w, y+h, col)
        DrawLine(x+w, y+h, x, y+h, col)
        DrawLine(x, y+h, x+skew, y, col)
    ok

// =============================================================
// Draw Connection (arrow)
// =============================================================

func dg_drawConnection idx
    c = connections[idx]
    fi = dg_findBoxById(c[1])
    ti = dg_findBoxById(c[2])
    if fi = 0 or ti = 0 return ok

    fb = boxes[fi]
    tb = boxes[ti]

    // Centers
    fcx = fb[2] + fb[4] / 2
    fcy = fb[3] + fb[5] / 2
    tcx = tb[2] + tb[4] / 2
    tcy = tb[3] + tb[5] / 2

    // Find edge points (intersect line with box borders)
    fp = dg_boxEdge(fb, tcx, tcy)
    tp = dg_boxEdge(tb, fcx, fcy)

    x1 = fp[1]   y1 = fp[2]
    x2 = tp[1]   y2 = tp[2]

    // Color
    sel = c[3]
    if sel = 1
        lineCol = RAYLIBColor(255, 220, 50, 255)
    else
        lineCol = RAYLIBColor(180, 185, 200, 220)
    ok

    // Line
    DrawLine(floor(x1), floor(y1), floor(x2), floor(y2), lineCol)
    DrawLine(floor(x1)+1, floor(y1), floor(x2)+1, floor(y2), lineCol)

    // Arrowhead
    dg_drawArrowHead(x1, y1, x2, y2, 14, lineCol)

func dg_boxEdge b, targetX, targetY
    // Find where line from box center to target exits the box
    cx = b[2] + b[4] / 2.0
    cy = b[3] + b[5] / 2.0
    hw = b[4] / 2.0
    hh = b[5] / 2.0

    dx = targetX - cx
    dy = targetY - cy

    if fabs(dx) < 0.001 and fabs(dy) < 0.001
        return [cx, cy]
    ok

    // Use parametric: find t where ray exits rectangle
    tMin = 999999.0

    if fabs(dx) > 0.001
        t = hw / fabs(dx)
        if t < tMin tMin = t ok
    ok
    if fabs(dy) > 0.001
        t = hh / fabs(dy)
        if t < tMin tMin = t ok
    ok

    return [cx + dx * tMin, cy + dy * tMin]

func dg_drawArrowHead x1, y1, x2, y2, size, col
    dx = x2 - x1
    dy = y2 - y1
    len2 = sqrt(dx*dx + dy*dy)
    if len2 < 1 return ok
    dx /= len2   dy /= len2

    // Arrow wings
    angle = 0.4  // radians spread
    ax1 = x2 - (dx * cos(angle) - dy * sin(angle)) * size
    ay1 = y2 - (dx * sin(angle) + dy * cos(angle)) * size
    ax2 = x2 - (dx * cos(-angle) - dy * sin(-angle)) * size
    ay2 = y2 - (dx * sin(-angle) + dy * cos(-angle)) * size

    DrawTriangle(Vector2(x2, y2), Vector2(ax1, ay1), Vector2(ax2, ay2), col)

// =============================================================
// HUD
// =============================================================

func dg_drawHUD
    // Top info bar
    DrawRectangle(0, 0, SCREEN_W, 24, RAYLIBColor(0, 0, 0, 140))
    DrawText("Diagram Tool", 10, 4, 16, RAYLIBColor(255, 215, 0, 220))

    info = "Boxes: " + string(len(boxes)) + "  Connections: " + string(len(connections))
    DrawText(info, 160, 5, 13, RAYLIBColor(180, 200, 220, 180))

    if gridSnap
        DrawText("Grid: ON", 400, 5, 13, RAYLIBColor(100, 255, 100, 180))
    else
        DrawText("Grid: off", 400, 5, 13, RAYLIBColor(150, 150, 150, 150))
    ok

    if connectMode
        DrawText("CONNECT MODE: Right-click target box", 500, 5, 13, RAYLIBColor(255, 200, 50, 240))
    ok

    if editMode
        DrawText("EDITING: Type text, Enter to confirm", 500, 5, 13, RAYLIBColor(100, 255, 200, 240))
    ok

    if selectedBox > 0
        sb = boxes[selectedBox]
        sTxt = "Selected: " + sb[6] + " (" + shapeNames[sb[7]] + ")"
        DrawText(sTxt, 660, 5, 13, RAYLIBColor(200, 200, 255, 180))
    ok

    // Help hint
    DrawText("N:New  Del:Delete  Dbl-Click:Edit  R-Click:Connect  1-5:Shape  C:Color",
             6, CANVAS_H - 18, 12, RAYLIBColor(150, 150, 170, 100))

    // FPS
    fpsTxt = "" + string(GetFPS()) + " FPS"
    DrawText(fpsTxt, SCREEN_W - 60, SCREEN_H - 14, 12, RAYLIBColor(100, 200, 100, 120))

// =============================================================
// Toolbar
// =============================================================

func dg_drawToolbar
    DrawRectangle(0, SCREEN_H - TOOLBAR_H, SCREEN_W, TOOLBAR_H, RAYLIBColor(25, 27, 35, 255))
    DrawRectangle(0, SCREEN_H - TOOLBAR_H, SCREEN_W, 2, RAYLIBColor(60, 60, 100, 200))

    mx = GetMouseX()
    my = GetMouseY()
    hoverBtn = 0

    bx = BTN_GAP

    // New box
    bx = dg_drawBtn("New[N]", bx, 1, RAYLIBColor(60, 130, 80, 255), mx, my)
    bx += BTN_GAP

    // Delete
    bx = dg_drawBtn("Del[X]", bx, 2, RAYLIBColor(160, 50, 50, 255), mx, my)
    bx += BTN_GAP

    // Undo
    bx = dg_drawBtn("Undo[U]", bx, 3, RAYLIBColor(130, 100, 50, 255), mx, my)
    bx += BTN_GAP

    // Grid
    gcol = RAYLIBColor(50, 80, 50, 255)
    if gridSnap gcol = RAYLIBColor(60, 140, 60, 255) ok
    bx = dg_drawBtn("Grid[G]", bx, 4, gcol, mx, my)
    bx += BTN_GAP

    // Auto layout
    bx = dg_drawBtn("Layout[A]", bx, 5, RAYLIBColor(60, 80, 140, 255), mx, my)
    bx += BTN_GAP

    // Separator
    DrawRectangle(bx, BTN_Y + 4, 2, BTN_H - 8, RAYLIBColor(60, 60, 100, 150))
    bx += BTN_GAP + 2

    // Shape buttons
    for i = 1 to SHAPE_COUNT
        scol = RAYLIBColor(70, 70, 90, 255)
        if selectedBox > 0
            if boxes[selectedBox][7] = i
                scol = RAYLIBColor(180, 160, 60, 255)
            ok
        ok
        bx = dg_drawBtn(shapeNames[i] + "[" + string(i) + "]", bx, 10+i, scol, mx, my)
        bx += 3
    next

    bx += BTN_GAP

    // Separator
    DrawRectangle(bx, BTN_Y + 4, 2, BTN_H - 8, RAYLIBColor(60, 60, 100, 150))
    bx += BTN_GAP + 2

    // Color cycle
    bx = dg_drawBtn("Color[C]", bx, 20, RAYLIBColor(140, 80, 140, 255), mx, my)
    bx += BTN_GAP

    // Color preview for selected
    if selectedBox > 0
        ci = boxes[selectedBox][8]
        cc = BOX_COLORS[ci]
        DrawRectangle(bx, BTN_Y + 5, 28, BTN_H - 10, RAYLIBColor(cc[1], cc[2], cc[3], 255))
        DrawRectangleLines(bx, BTN_Y + 5, 28, BTN_H - 10, RAYLIBColor(255, 255, 255, 100))
        bx += 32
    ok

func dg_drawBtn label, bx, btnId, baseCol, mx, my
    tw = MeasureText(label, 12) + 14
    if tw < 38 tw = 38 ok

    isHover = (mx >= bx and mx <= bx + tw and my >= BTN_Y and my <= BTN_Y + BTN_H)

    if isHover
        hoverBtn = btnId
        DrawRectangle(bx, BTN_Y, tw, BTN_H, RAYLIBColor(255, 225, 100, 240))
        DrawRectangleLines(bx, BTN_Y, tw, BTN_H, RAYLIBColor(200, 180, 60, 255))
        lw = MeasureText(label, 12)
        DrawText(label, bx + (tw - lw) / 2, BTN_Y + 13, 12, RAYLIBColor(20, 15, 10, 255))
    else
        DrawRectangle(bx, BTN_Y, tw, BTN_H, baseCol)
        DrawRectangleLines(bx, BTN_Y, tw, BTN_H, RAYLIBColor(255, 255, 255, 30))
        lw = MeasureText(label, 12)
        DrawText(label, bx + (tw - lw) / 2, BTN_Y + 13, 12, WHITE)
    ok

    return bx + tw

// =============================================================
// Toolbar Click
// =============================================================

func dg_handleToolbarClick mx, my
    if hoverBtn = 1
        dg_saveUndo()
        cx = SCREEN_W / 2 - DEF_BOX_W / 2
        cy = CANVAS_H / 2 - DEF_BOX_H / 2
        if gridSnap
            cx = floor(cx / GRID_SIZE) * GRID_SIZE
            cy = floor(cy / GRID_SIZE) * GRID_SIZE
        ok
        id = dg_addBox(cx, cy, DEF_BOX_W, DEF_BOX_H, "New Box", SHAPE_RECT, 1)
        dg_deselectAll()
        idx = dg_findBoxById(id)
        if idx > 0
            boxes[idx][9] = 1
            selectedBox = idx
        ok
        return
    ok
    if hoverBtn = 2
        dg_deleteSelected()
        return
    ok
    if hoverBtn = 3
        dg_undo()
        return
    ok
    if hoverBtn = 4
        gridSnap = !gridSnap
        return
    ok
    if hoverBtn = 5
        dg_autoLayout()
        return
    ok
    // Shape buttons
    if hoverBtn >= 11 and hoverBtn <= 10 + SHAPE_COUNT and selectedBox > 0
        dg_saveUndo()
        boxes[selectedBox][7] = hoverBtn - 10
        return
    ok
    if hoverBtn = 20 and selectedBox > 0
        dg_saveUndo()
        ci = boxes[selectedBox][8] + 1
        if ci > COLOR_COUNT ci = 1 ok
        boxes[selectedBox][8] = ci
        return
    ok
