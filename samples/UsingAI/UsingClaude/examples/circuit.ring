/*
**  Circuit Simulator - RingRayLib
**  =================================
**  Connect logic gates, toggle inputs, watch signals flow!
**
**  Controls:
**    Mouse Left       - Select / Drag gate / Click toolbar
**    Mouse Right      - Start wire from output pin, click input pin to connect
**    Double-Click     - Toggle input switch value
**    Delete / X       - Delete selected gate or wire
**    N                - Cycle gate type for next placement
**    1-8              - Quick select gate type
**    Space            - Place gate of current type at center
**    G                - Toggle grid snap
**    A                - Auto-layout gates
**    U                - Undo
**    R                - Reset all inputs to OFF
**    ESC              - Cancel / Deselect / Exit
**
**  Gate Types:
**    1. INPUT    - Toggle switch (click to flip)
**    2. OUTPUT   - LED indicator
**    3. AND      - Both inputs high
**    4. OR       - Either input high
**    5. NOT      - Inverter (single input)
**    6. NAND     - NOT AND
**    7. NOR      - NOT OR
**    8. XOR      - Exclusive OR
**
**  Wiring:
**    Right-click an output pin (right side of gate),
**    then right-click an input pin (left side) to connect.
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W = 1024
SCREEN_H = 700
TOOLBAR_H = 52
CANVAS_H = SCREEN_H - TOOLBAR_H

PI = 3.14159265

// Gate types
GATE_INPUT  = 1
GATE_OUTPUT = 2
GATE_AND    = 3
GATE_OR     = 4
GATE_NOT    = 5
GATE_NAND   = 6
GATE_NOR    = 7
GATE_XOR    = 8
GATE_COUNT  = 8
gateNames = ["INPUT", "OUTPUT", "AND", "OR", "NOT", "NAND", "NOR", "XOR"]

// Gate dimensions
GATE_W = 90
GATE_H = 50
PIN_R = 5
PIN_HITBOX = 10

// Grid
GRID_SIZE = 20

// Signal colors
COL_HIGH_R = 50   COL_HIGH_G = 220  COL_HIGH_B = 80
COL_LOW_R  = 100  COL_LOW_G  = 100  COL_LOW_B  = 110
COL_WIRE_HI_R = 50  COL_WIRE_HI_G = 230  COL_WIRE_HI_B = 80
COL_WIRE_LO_R = 80  COL_WIRE_LO_G = 80   COL_WIRE_LO_B = 95

// =============================================================
// Data
// =============================================================

// Gate: [id, type, x, y, selected, inputVals[], outputVal, label]
//   inputVals = list of input pin values (0 or 1)
//   outputVal = computed output (0 or 1)
gates = []
nextGateId = 1

// Wire: [fromGateId, fromPin, toGateId, toPin, selected, signal]
//   fromPin always = 1 (output pin)
//   toPin = 1 or 2 (input pin index)
wires = []

// =============================================================
// State
// =============================================================

selectedGate = 0
selectedWire = 0
dragging = false
dragOffX = 0
dragOffY = 0

// Wire drawing mode
wireMode = false
wireFromGateId = 0
wireFromPin = 0

// Current gate type for placement
placeType = GATE_AND

gridSnap = true

// Undo
undoStack = []
MAX_UNDO = 40

// Toolbar
hoverBtn = 0
BTN_Y = SCREEN_H - 50
BTN_H = 38
BTN_GAP = 4

// Double-click
lastClickTime = 0.0
lastClickX = 0
lastClickY = 0

animTime = 0.0
signalPulse = 0.0

// Input counter for labeling
inputCount = 0
outputCount = 0

// =============================================================
// Main
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Circuit Simulator - RingRayLib")
SetTargetFPS(60)
SetExitKey(0)

// Starter circuit: simple AND gate demo
cs_addGate(GATE_INPUT, 80, 140)
cs_addGate(GATE_INPUT, 80, 280)
cs_addGate(GATE_AND, 320, 200)
cs_addGate(GATE_OUTPUT, 560, 200)
cs_addWire(1, 1, 3, 1)
cs_addWire(2, 1, 3, 2)
cs_addWire(3, 1, 4, 1)

while !WindowShouldClose()
    cs_update()
    cs_simulate()
    BeginDrawing()
        ClearBackground(RAYLIBColor(28, 30, 38, 255))
        cs_draw()
    EndDrawing()
end

CloseWindow()

// =============================================================
// Gate Management
// =============================================================

func cs_addGate type, x, y
    id = nextGateId
    nextGateId++

    numInputs = cs_gateInputCount(type)
    inVals = []
    for i = 1 to numInputs
        add(inVals, 0)
    next

    label = gateNames[type]
    if type = GATE_INPUT
        inputCount++
        label = "IN " + string(inputCount)
    ok
    if type = GATE_OUTPUT
        outputCount++
        label = "OUT " + string(outputCount)
    ok

    add(gates, [id, type, x, y, 0, inVals, 0, label])
    return id

func cs_gateInputCount type
    if type = GATE_INPUT  return 0  ok
    if type = GATE_OUTPUT return 1  ok
    if type = GATE_NOT    return 1  ok
    return 2  // AND, OR, NAND, NOR, XOR

func cs_gateHasOutput type
    if type = GATE_OUTPUT return false ok
    return true

func cs_findGateById id
    for i = 1 to len(gates)
        if gates[i][1] = id return i ok
    next
    return 0

// Pin positions relative to gate
func cs_inputPinPos gateIdx, pinIdx
    g = gates[gateIdx]
    gx = g[3]   gy = g[4]
    numIn = cs_gateInputCount(g[2])
    if numIn = 0 return [gx, gy + GATE_H/2] ok
    if numIn = 1
        return [gx, gy + GATE_H / 2]
    ok
    // 2 inputs
    spacing = GATE_H / 3
    py = gy + spacing * pinIdx
    return [gx, py]

func cs_outputPinPos gateIdx
    g = gates[gateIdx]
    return [g[3] + GATE_W, g[4] + GATE_H / 2]

// Hit testing
func cs_gateAt mx, my
    for i = len(gates) to 1 step -1
        g = gates[i]
        if mx >= g[3] and mx <= g[3] + GATE_W and my >= g[4] and my <= g[4] + GATE_H
            return i
        ok
    next
    return 0

func cs_inputPinAt mx, my
    // Returns [gateIdx, pinIdx] or [0, 0]
    for i = 1 to len(gates)
        g = gates[i]
        numIn = cs_gateInputCount(g[2])
        for p = 1 to numIn
            pos = cs_inputPinPos(i, p)
            dx = mx - pos[1]
            dy = my - pos[2]
            if dx*dx + dy*dy < PIN_HITBOX * PIN_HITBOX
                return [i, p]
            ok
        next
    next
    return [0, 0]

func cs_outputPinAt mx, my
    // Returns gateIdx or 0
    for i = 1 to len(gates)
        g = gates[i]
        if !cs_gateHasOutput(g[2]) loop ok
        pos = cs_outputPinPos(i)
        dx = mx - pos[1]
        dy = my - pos[2]
        if dx*dx + dy*dy < PIN_HITBOX * PIN_HITBOX
            return i
        ok
    next
    return 0

func cs_wireAt mx, my
    for i = 1 to len(wires)
        w = wires[i]
        fi = cs_findGateById(w[1])
        ti = cs_findGateById(w[3])
        if fi = 0 or ti = 0 loop ok

        fp = cs_outputPinPos(fi)
        tp = cs_inputPinPos(ti, w[4])

        dist = cs_ptLineDist(mx, my, fp[1], fp[2], tp[1], tp[2])
        if dist < 8 return i ok
    next
    return 0

func cs_ptLineDist px, py, x1, y1, x2, y2
    dx = x2 - x1   dy = y2 - y1
    lenSq = dx*dx + dy*dy
    if lenSq < 1 return sqrt((px-x1)*(px-x1)+(py-y1)*(py-y1)) ok
    t = ((px-x1)*dx + (py-y1)*dy) / lenSq
    if t < 0 t = 0 ok
    if t > 1 t = 1 ok
    projX = x1 + t*dx   projY = y1 + t*dy
    return sqrt((px-projX)*(px-projX) + (py-projY)*(py-projY))

// =============================================================
// Wire Management
// =============================================================

func cs_addWire fromId, fromPin, toId, toPin
    // Don't duplicate
    for i = 1 to len(wires)
        w = wires[i]
        if w[1] = fromId and w[3] = toId and w[4] = toPin return ok
    next
    // Remove existing wire to same input pin
    i = len(wires)
    while i >= 1
        if wires[i][3] = toId and wires[i][4] = toPin
            del(wires, i)
        ok
        i--
    end
    add(wires, [fromId, fromPin, toId, toPin, 0, 0])

// =============================================================
// Simulation
// =============================================================

func cs_simulate
    // Reset all input values
    for i = 1 to len(gates)
        g = gates[i]
        numIn = cs_gateInputCount(g[2])
        for p = 1 to numIn
            gates[i][6][p] = 0
        next
    next

    // Propagate wire signals: set input pins from source output
    for i = 1 to len(wires)
        w = wires[i]
        fi = cs_findGateById(w[1])
        ti = cs_findGateById(w[3])
        if fi = 0 or ti = 0 loop ok

        srcVal = gates[fi][7]
        wires[i][6] = srcVal

        pin = w[4]
        if pin >= 1 and pin <= len(gates[ti][6])
            gates[ti][6][pin] = srcVal
        ok
    next

    // Evaluate each gate
    for i = 1 to len(gates)
        g = gates[i]
        gType = g[2]
        inVals = g[6]

        if gType = GATE_INPUT
            // Output is its own stored value (toggled by user)
            // outputVal is already set by toggle, don't overwrite
            // (it's stored in gates[i][7])
        ok

        if gType = GATE_OUTPUT
            if len(inVals) >= 1
                gates[i][7] = inVals[1]
            ok
        ok

        if gType = GATE_AND
            if len(inVals) >= 2
                gates[i][7] = (inVals[1] and inVals[2])
            ok
        ok

        if gType = GATE_OR
            if len(inVals) >= 2
                if inVals[1] = 1 or inVals[2] = 1
                    gates[i][7] = 1
                else
                    gates[i][7] = 0
                ok
            ok
        ok

        if gType = GATE_NOT
            if len(inVals) >= 1
                if inVals[1] = 0
                    gates[i][7] = 1
                else
                    gates[i][7] = 0
                ok
            ok
        ok

        if gType = GATE_NAND
            if len(inVals) >= 2
                if inVals[1] = 1 and inVals[2] = 1
                    gates[i][7] = 0
                else
                    gates[i][7] = 1
                ok
            ok
        ok

        if gType = GATE_NOR
            if len(inVals) >= 2
                if inVals[1] = 0 and inVals[2] = 0
                    gates[i][7] = 1
                else
                    gates[i][7] = 0
                ok
            ok
        ok

        if gType = GATE_XOR
            if len(inVals) >= 2
                if inVals[1] != inVals[2]
                    gates[i][7] = 1
                else
                    gates[i][7] = 0
                ok
            ok
        ok
    next

    // Multi-pass for propagation (handles chained gates)
    for pass = 1 to 5
        for i = 1 to len(gates)
            numIn = cs_gateInputCount(gates[i][2])
            for p = 1 to numIn
                gates[i][6][p] = 0
            next
        next
        for i = 1 to len(wires)
            w = wires[i]
            fi = cs_findGateById(w[1])
            ti = cs_findGateById(w[3])
            if fi = 0 or ti = 0 loop ok
            srcVal = gates[fi][7]
            wires[i][6] = srcVal
            pin = w[4]
            if pin >= 1 and pin <= len(gates[ti][6])
                gates[ti][6][pin] = srcVal
            ok
        next
        for i = 1 to len(gates)
            gType = gates[i][2]
            inVals = gates[i][6]
            if gType = GATE_OUTPUT
                if len(inVals) >= 1 gates[i][7] = inVals[1] ok
            ok
            if gType = GATE_AND
                if len(inVals) >= 2 gates[i][7] = (inVals[1] and inVals[2]) ok
            ok
            if gType = GATE_OR
                if len(inVals) >= 2
                    if inVals[1]=1 or inVals[2]=1 gates[i][7]=1 else gates[i][7]=0 ok
                ok
            ok
            if gType = GATE_NOT
                if len(inVals) >= 1
                    if inVals[1]=0 gates[i][7]=1 else gates[i][7]=0 ok
                ok
            ok
            if gType = GATE_NAND
                if len(inVals) >= 2
                    if inVals[1]=1 and inVals[2]=1 gates[i][7]=0 else gates[i][7]=1 ok
                ok
            ok
            if gType = GATE_NOR
                if len(inVals) >= 2
                    if inVals[1]=0 and inVals[2]=0 gates[i][7]=1 else gates[i][7]=0 ok
                ok
            ok
            if gType = GATE_XOR
                if len(inVals) >= 2
                    if inVals[1] != inVals[2] gates[i][7]=1 else gates[i][7]=0 ok
                ok
            ok
        next
    next

// =============================================================
// Undo
// =============================================================

func cs_saveUndo
    bSnap = []
    for i = 1 to len(gates)
        g = gates[i]
        inCopy = []
        for j = 1 to len(g[6])
            add(inCopy, g[6][j])
        next
        add(bSnap, [g[1], g[2], g[3], g[4], g[5], inCopy, g[7], g[8]])
    next
    wSnap = []
    for i = 1 to len(wires)
        w = wires[i]
        add(wSnap, [w[1], w[2], w[3], w[4], w[5], w[6]])
    next
    add(undoStack, [bSnap, wSnap, nextGateId, inputCount, outputCount])
    if len(undoStack) > MAX_UNDO del(undoStack, 1) ok

func cs_undo
    if len(undoStack) = 0 return ok
    snap = undoStack[len(undoStack)]
    del(undoStack, len(undoStack))
    gates = []
    for i = 1 to len(snap[1])
        s = snap[1][i]
        inCopy = []
        for j = 1 to len(s[6])
            add(inCopy, s[6][j])
        next
        add(gates, [s[1], s[2], s[3], s[4], s[5], inCopy, s[7], s[8]])
    next
    wires = []
    for i = 1 to len(snap[2])
        s = snap[2][i]
        add(wires, [s[1], s[2], s[3], s[4], s[5], s[6]])
    next
    nextGateId = snap[3]
    inputCount = snap[4]
    outputCount = snap[5]
    selectedGate = 0
    selectedWire = 0

// =============================================================
// Update
// =============================================================

func cs_update
    dt = GetFrameTime()
    animTime += dt
    signalPulse += dt * 4

    mx = GetMouseX()
    my = GetMouseY()

    if IsKeyPressed(KEY_ESCAPE)
        if wireMode
            wireMode = false
        but selectedGate > 0 or selectedWire > 0
            cs_deselectAll()
        else
            CloseWindow()
            shutdown(0)
        ok
    ok

    // Gate type selection
    if IsKeyPressed(KEY_N)
        placeType++
        if placeType > GATE_COUNT placeType = 1 ok
    ok
    for k = 1 to GATE_COUNT
        if IsKeyPressed(48 + k)
            placeType = k
        ok
    next

    // Place gate
    if IsKeyPressed(KEY_SPACE)
        cs_saveUndo()
        cx = SCREEN_W/2 - GATE_W/2
        cy = CANVAS_H/2 - GATE_H/2
        if gridSnap
            cx = floor(cx/GRID_SIZE)*GRID_SIZE
            cy = floor(cy/GRID_SIZE)*GRID_SIZE
        ok
        id = cs_addGate(placeType, cx, cy)
        cs_deselectAll()
        idx = cs_findGateById(id)
        if idx > 0 gates[idx][5] = 1 selectedGate = idx ok
    ok

    // Delete
    if IsKeyPressed(KEY_DELETE) or IsKeyPressed(KEY_X)
        cs_deleteSelected()
    ok

    // Undo
    if IsKeyPressed(KEY_U) cs_undo() ok

    // Grid
    if IsKeyPressed(KEY_G) gridSnap = !gridSnap ok

    // Auto layout
    if IsKeyPressed(KEY_A) cs_autoLayout() ok

    // Reset inputs
    if IsKeyPressed(KEY_R)
        for i = 1 to len(gates)
            if gates[i][2] = GATE_INPUT gates[i][7] = 0 ok
        next
    ok

    // Toolbar
    if IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
        cs_handleToolbar(mx, my)
    ok

    // Canvas
    if my < CANVAS_H
        cs_handleCanvas(mx, my, dt)
    ok

// =============================================================
// Canvas Input
// =============================================================

func cs_handleCanvas mx, my, dt
    // LEFT CLICK
    if IsMouseButtonPressed(MOUSE_LEFT_BUTTON) and hoverBtn = 0
        // Double click detection
        now = animTime
        ddx = mx - lastClickX   ddy = my - lastClickY
        dist = sqrt(ddx*ddx + ddy*ddy)
        isDouble = (now - lastClickTime < 0.4 and dist < 10)
        lastClickTime = now
        lastClickX = mx
        lastClickY = my

        hitGate = cs_gateAt(mx, my)

        if isDouble and hitGate > 0
            // Toggle input switch
            if gates[hitGate][2] = GATE_INPUT
                cs_saveUndo()
                if gates[hitGate][7] = 0
                    gates[hitGate][7] = 1
                else
                    gates[hitGate][7] = 0
                ok
            ok
            return
        ok

        if hitGate > 0
            cs_deselectAll()
            gates[hitGate][5] = 1
            selectedGate = hitGate
            dragging = true
            dragOffX = mx - gates[hitGate][3]
            dragOffY = my - gates[hitGate][4]
            cs_saveUndo()
        else
            hitWire = cs_wireAt(mx, my)
            if hitWire > 0
                cs_deselectAll()
                wires[hitWire][5] = 1
                selectedWire = hitWire
            else
                cs_deselectAll()
            ok
        ok
    ok

    // Dragging
    if dragging
        if IsMouseButtonDown(MOUSE_LEFT_BUTTON) and selectedGate > 0
            nx = mx - dragOffX
            ny = my - dragOffY
            if gridSnap
                nx = floor(nx/GRID_SIZE+0.5)*GRID_SIZE
                ny = floor(ny/GRID_SIZE+0.5)*GRID_SIZE
            ok
            if nx < 0 nx = 0 ok
            if ny < 0 ny = 0 ok
            if nx + GATE_W > SCREEN_W nx = SCREEN_W - GATE_W ok
            if ny + GATE_H > CANVAS_H ny = CANVAS_H - GATE_H ok
            gates[selectedGate][3] = nx
            gates[selectedGate][4] = ny
        else
            dragging = false
        ok
    ok

    // RIGHT CLICK - Wiring
    if IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)
        if !wireMode
            // Start from output pin
            outGate = cs_outputPinAt(mx, my)
            if outGate > 0
                wireMode = true
                wireFromGateId = gates[outGate][1]
                wireFromPin = 1
            else
                // Also allow clicking on gate body
                hitG = cs_gateAt(mx, my)
                if hitG > 0 and cs_gateHasOutput(gates[hitG][2])
                    wireMode = true
                    wireFromGateId = gates[hitG][1]
                    wireFromPin = 1
                ok
            ok
        else
            // Complete to input pin
            inPin = cs_inputPinAt(mx, my)
            if inPin[1] > 0
                toId = gates[inPin[1]][1]
                if toId != wireFromGateId
                    cs_saveUndo()
                    cs_addWire(wireFromGateId, wireFromPin, toId, inPin[2])
                ok
            else
                // Click on gate body for input
                hitG = cs_gateAt(mx, my)
                if hitG > 0 and cs_gateInputCount(gates[hitG][2]) > 0
                    toId = gates[hitG][1]
                    if toId != wireFromGateId
                        cs_saveUndo()
                        // Auto-assign first free input pin
                        freePin = cs_firstFreeInput(hitG)
                        if freePin > 0
                            cs_addWire(wireFromGateId, wireFromPin, toId, freePin)
                        ok
                    ok
                ok
            ok
            wireMode = false
        ok
    ok

func cs_firstFreeInput gateIdx
    gid = gates[gateIdx][1]
    numIn = cs_gateInputCount(gates[gateIdx][2])
    for p = 1 to numIn
        used = false
        for w = 1 to len(wires)
            if wires[w][3] = gid and wires[w][4] = p
                used = true
                exit
            ok
        next
        if !used return p ok
    next
    // All used, return pin 1 (will overwrite)
    if numIn > 0 return 1 ok
    return 0

// =============================================================
// Delete / Deselect
// =============================================================

func cs_deleteSelected
    if selectedGate > 0
        cs_saveUndo()
        gid = gates[selectedGate][1]
        del(gates, selectedGate)
        i = len(wires)
        while i >= 1
            if wires[i][1] = gid or wires[i][3] = gid
                del(wires, i)
            ok
            i--
        end
        selectedGate = 0
    ok
    if selectedWire > 0
        cs_saveUndo()
        del(wires, selectedWire)
        selectedWire = 0
    ok

func cs_deselectAll
    selectedGate = 0
    selectedWire = 0
    for i = 1 to len(gates) gates[i][5] = 0 next
    for i = 1 to len(wires) wires[i][5] = 0 next

func cs_autoLayout
    if len(gates) = 0 return ok
    cs_saveUndo()
    cols = floor(sqrt(len(gates))) + 1
    for i = 1 to len(gates)
        col = (i-1) % cols
        row = floor((i-1) / cols)
        nx = 60 + col * 160
        ny = 50 + row * 90
        if gridSnap
            nx = floor(nx/GRID_SIZE)*GRID_SIZE
            ny = floor(ny/GRID_SIZE)*GRID_SIZE
        ok
        gates[i][3] = nx
        gates[i][4] = ny
    next

// =============================================================
// Draw
// =============================================================

func cs_draw
    // Grid
    if gridSnap
        for gx = 0 to SCREEN_W step GRID_SIZE
            DrawLine(gx, 0, gx, CANVAS_H, RAYLIBColor(34, 36, 46, 255))
        next
        for gy = 0 to CANVAS_H step GRID_SIZE
            DrawLine(0, gy, SCREEN_W, gy, RAYLIBColor(34, 36, 46, 255))
        next
    ok

    // Wires
    for i = 1 to len(wires)
        cs_drawWire(i)
    next

    // Wire in-progress
    if wireMode
        fi = cs_findGateById(wireFromGateId)
        if fi > 0
            fp = cs_outputPinPos(fi)
            mx = GetMouseX()  my = GetMouseY()
            pulse = floor(fabs(sin(animTime*4))*100)+155
            // Draw routed wire preview
            midX = (fp[1] + mx) / 2
            DrawLine(floor(fp[1]), floor(fp[2]), floor(midX), floor(fp[2]), RAYLIBColor(255, 200, 50, pulse))
            DrawLine(floor(midX), floor(fp[2]), floor(midX), my, RAYLIBColor(255, 200, 50, pulse))
            DrawLine(floor(midX), my, mx, my, RAYLIBColor(255, 200, 50, pulse))
            DrawCircle(mx, my, 4, RAYLIBColor(255, 200, 50, pulse))
        ok
    ok

    // Gates
    for i = 1 to len(gates)
        cs_drawGate(i)
    next

    // HUD
    cs_drawHUD()

    // Toolbar
    cs_drawToolbar()

// =============================================================
// Draw Wire
// =============================================================

func cs_drawWire idx
    w = wires[idx]
    fi = cs_findGateById(w[1])
    ti = cs_findGateById(w[3])
    if fi = 0 or ti = 0 return ok

    fp = cs_outputPinPos(fi)
    tp = cs_inputPinPos(ti, w[4])

    sig = w[6]
    sel = w[5]

    if sel = 1
        cr = 255  cg = 220  cb = 50
    but sig = 1
        cr = COL_WIRE_HI_R  cg = COL_WIRE_HI_G  cb = COL_WIRE_HI_B
    else
        cr = COL_WIRE_LO_R  cg = COL_WIRE_LO_G  cb = COL_WIRE_LO_B
    ok

    col = RAYLIBColor(cr, cg, cb, 220)

    // Route: horizontal -> vertical -> horizontal (Manhattan routing)
    midX = floor((fp[1] + tp[1]) / 2)

    DrawLine(floor(fp[1]), floor(fp[2]), midX, floor(fp[2]), col)
    DrawLine(midX, floor(fp[2]), midX, floor(tp[2]), col)
    DrawLine(midX, floor(tp[2]), floor(tp[1]), floor(tp[2]), col)

    // Thicker
    DrawLine(floor(fp[1]), floor(fp[2])+1, midX, floor(fp[2])+1, col)
    DrawLine(midX+1, floor(fp[2]), midX+1, floor(tp[2]), col)
    DrawLine(midX, floor(tp[2])+1, floor(tp[1]), floor(tp[2])+1, col)

    // Signal flow animation (moving dot)
    if sig = 1
        t2 = (sin(signalPulse + idx * 1.5) + 1) / 2.0
        // Dot along the path
        totalLen = fabs(midX - fp[1]) + fabs(tp[2] - fp[2]) + fabs(tp[1] - midX)
        if totalLen > 0
            seg1 = fabs(midX - fp[1])
            seg2 = fabs(tp[2] - fp[2])
            seg3 = fabs(tp[1] - midX)
            pos = t2 * totalLen
            dotX = 0  dotY = 0

            if pos < seg1
                frac = pos / (seg1 + 0.001)
                dotX = fp[1] + (midX - fp[1]) * frac
                dotY = fp[2]
            but pos < seg1 + seg2
                frac = (pos - seg1) / (seg2 + 0.001)
                dotX = midX
                dotY = fp[2] + (tp[2] - fp[2]) * frac
            else
                frac = (pos - seg1 - seg2) / (seg3 + 0.001)
                dotX = midX + (tp[1] - midX) * frac
                dotY = tp[2]
            ok

            DrawCircle(floor(dotX), floor(dotY), 4, RAYLIBColor(100, 255, 120, 220))
            DrawCircle(floor(dotX), floor(dotY), 7, RAYLIBColor(100, 255, 120, 50))
        ok
    ok

// =============================================================
// Draw Gate
// =============================================================

func cs_drawGate idx
    g = gates[idx]
    gx = g[3]  gy = g[4]  gType = g[2]  sel = g[5]
    outVal = g[7]

    // Shadow
    DrawRectangle(gx+3, gy+3, GATE_W, GATE_H, RAYLIBColor(0, 0, 0, 50))

    // Body color based on type
    if gType = GATE_INPUT
        if outVal = 1
            bodyR = 50  bodyG = 180  bodyB = 80
        else
            bodyR = 60  bodyG = 65  bodyB = 75
        ok
    but gType = GATE_OUTPUT
        if outVal = 1
            bodyR = 220  bodyG = 60  bodyB = 60
        else
            bodyR = 70  bodyG = 50  bodyB = 55
        ok
    else
        bodyR = 55  bodyG = 65  bodyB = 85
    ok

    DrawRectangle(gx, gy, GATE_W, GATE_H, RAYLIBColor(bodyR, bodyG, bodyB, 240))

    // Border
    if sel = 1
        DrawRectangleLines(gx, gy, GATE_W, GATE_H, RAYLIBColor(255, 220, 50, 255))
        DrawRectangleLines(gx-1, gy-1, GATE_W+2, GATE_H+2, RAYLIBColor(255, 220, 50, 120))
    else
        DrawRectangleLines(gx, gy, GATE_W, GATE_H, RAYLIBColor(100, 110, 130, 200))
    ok

    // Gate symbol / label
    label = g[8]
    fontSize = 14
    if gType = GATE_INPUT
        if outVal = 1
            label = g[8] + ": 1"
        else
            label = g[8] + ": 0"
        ok
    ok
    if gType = GATE_OUTPUT
        if outVal = 1
            label = g[8] + ": 1"
            // LED glow
            DrawCircle(gx + GATE_W/2, gy + GATE_H/2, 18, RAYLIBColor(255, 60, 40, 60))
            DrawCircle(gx + GATE_W/2, gy + GATE_H/2, 12, RAYLIBColor(255, 80, 60, 100))
        else
            label = g[8] + ": 0"
        ok
    ok

    tw = MeasureText(label, fontSize)
    DrawText(label, gx + (GATE_W - tw)/2, gy + (GATE_H - fontSize)/2, fontSize, RAYLIBColor(220, 225, 240, 240))

    // Gate type indicator (small text at top)
    if gType >= GATE_AND and gType <= GATE_XOR
        typeTxt = gateNames[gType]
        ttw = MeasureText(typeTxt, 10)
        DrawText(typeTxt, gx + (GATE_W - ttw)/2, gy + 3, 10, RAYLIBColor(160, 170, 190, 150))

        // Output value indicator
        outTxt = "" + string(outVal)
        DrawText(outTxt, gx + GATE_W - 16, gy + GATE_H - 15, 12, RAYLIBColor(200, 210, 230, 180))
    ok

    // Input pins
    numIn = cs_gateInputCount(gType)
    for p = 1 to numIn
        pp = cs_inputPinPos(idx, p)
        pinVal = 0
        if p <= len(g[6]) pinVal = g[6][p] ok
        if pinVal = 1
            DrawCircle(floor(pp[1]), floor(pp[2]), PIN_R, RAYLIBColor(COL_HIGH_R, COL_HIGH_G, COL_HIGH_B, 255))
        else
            DrawCircle(floor(pp[1]), floor(pp[2]), PIN_R, RAYLIBColor(COL_LOW_R, COL_LOW_G, COL_LOW_B, 255))
        ok
        DrawCircleLines(floor(pp[1]), floor(pp[2]), PIN_R, RAYLIBColor(140, 150, 170, 180))
    next

    // Output pin
    if cs_gateHasOutput(gType)
        op = cs_outputPinPos(idx)
        if outVal = 1
            DrawCircle(floor(op[1]), floor(op[2]), PIN_R, RAYLIBColor(COL_HIGH_R, COL_HIGH_G, COL_HIGH_B, 255))
            DrawCircle(floor(op[1]), floor(op[2]), PIN_R+3, RAYLIBColor(COL_HIGH_R, COL_HIGH_G, COL_HIGH_B, 40))
        else
            DrawCircle(floor(op[1]), floor(op[2]), PIN_R, RAYLIBColor(COL_LOW_R, COL_LOW_G, COL_LOW_B, 255))
        ok
        DrawCircleLines(floor(op[1]), floor(op[2]), PIN_R, RAYLIBColor(140, 150, 170, 180))
    ok

    // NOT bubble
    if gType = GATE_NOT or gType = GATE_NAND or gType = GATE_NOR
        op = cs_outputPinPos(idx)
        DrawCircle(floor(op[1]) - 2, floor(op[2]), 3, RAYLIBColor(220, 220, 240, 200))
    ok

// =============================================================
// HUD
// =============================================================

func cs_drawHUD
    DrawRectangle(0, 0, SCREEN_W, 24, RAYLIBColor(0, 0, 0, 140))
    DrawText("Circuit Simulator", 10, 4, 16, RAYLIBColor(255, 215, 0, 220))

    info = "Gates: " + string(len(gates)) + "  Wires: " + string(len(wires))
    DrawText(info, 180, 5, 13, RAYLIBColor(180, 200, 220, 180))

    placeTxt = "Place: " + gateNames[placeType]
    DrawText(placeTxt, 370, 5, 13, RAYLIBColor(150, 200, 255, 200))

    if gridSnap
        DrawText("Grid ON", 510, 5, 13, RAYLIBColor(100, 255, 100, 180))
    ok

    if wireMode
        DrawText("WIRE MODE: Right-click target input pin", 590, 5, 13, RAYLIBColor(255, 200, 50, 240))
    ok

    // Help
    DrawText("R-Click:Wire  Dbl-Click:Toggle Input  Del:Delete  Space:Place  R:Reset",
             6, CANVAS_H - 18, 12, RAYLIBColor(140, 140, 160, 100))

    fpsTxt = "" + string(GetFPS()) + " FPS"
    DrawText(fpsTxt, SCREEN_W - 60, SCREEN_H - 14, 12, RAYLIBColor(100, 200, 100, 120))

// =============================================================
// Toolbar
// =============================================================

func cs_drawToolbar
    DrawRectangle(0, SCREEN_H - TOOLBAR_H, SCREEN_W, TOOLBAR_H, RAYLIBColor(22, 24, 32, 255))
    DrawRectangle(0, SCREEN_H - TOOLBAR_H, SCREEN_W, 2, RAYLIBColor(60, 60, 100, 200))

    mx = GetMouseX()  my = GetMouseY()
    hoverBtn = 0

    bx = BTN_GAP

    // Gate type buttons
    gateColors = [
        RAYLIBColor(50, 120, 60, 255),
        RAYLIBColor(160, 50, 50, 255),
        RAYLIBColor(60, 80, 150, 255),
        RAYLIBColor(60, 120, 140, 255),
        RAYLIBColor(140, 80, 60, 255),
        RAYLIBColor(80, 60, 140, 255),
        RAYLIBColor(60, 100, 100, 255),
        RAYLIBColor(130, 100, 50, 255)
    ]

    for i = 1 to GATE_COUNT
        lbl = gateNames[i] + "[" + string(i) + "]"
        col = gateColors[i]
        if placeType = i
            col = RAYLIBColor(200, 190, 60, 255)
        ok
        bx = cs_drawBtn(lbl, bx, i, col, mx, my)
        bx += 3
    next

    bx += BTN_GAP
    DrawRectangle(bx, BTN_Y+4, 2, BTN_H-8, RAYLIBColor(60, 60, 100, 150))
    bx += BTN_GAP + 2

    // Place
    bx = cs_drawBtn("Place", bx, 20, RAYLIBColor(50, 130, 70, 255), mx, my)
    bx += BTN_GAP

    // Delete
    bx = cs_drawBtn("Del", bx, 21, RAYLIBColor(150, 50, 50, 255), mx, my)
    bx += BTN_GAP

    // Undo
    bx = cs_drawBtn("Undo", bx, 22, RAYLIBColor(120, 90, 40, 255), mx, my)
    bx += BTN_GAP

    // Grid
    gcol = RAYLIBColor(50, 70, 50, 255)
    if gridSnap gcol = RAYLIBColor(50, 130, 50, 255) ok
    bx = cs_drawBtn("Grid", bx, 23, gcol, mx, my)
    bx += BTN_GAP

    // Reset
    bx = cs_drawBtn("Reset", bx, 24, RAYLIBColor(140, 80, 40, 255), mx, my)

func cs_drawBtn label, bx, btnId, baseCol, mx, my
    tw = MeasureText(label, 11) + 12
    if tw < 36 tw = 36 ok

    isHover = (mx >= bx and mx <= bx + tw and my >= BTN_Y and my <= BTN_Y + BTN_H)

    if isHover
        hoverBtn = btnId
        DrawRectangle(bx, BTN_Y, tw, BTN_H, RAYLIBColor(255, 225, 100, 240))
        DrawRectangleLines(bx, BTN_Y, tw, BTN_H, RAYLIBColor(200, 180, 60, 255))
        lw = MeasureText(label, 11)
        DrawText(label, bx + (tw-lw)/2, BTN_Y+14, 11, RAYLIBColor(20, 15, 10, 255))
    else
        DrawRectangle(bx, BTN_Y, tw, BTN_H, baseCol)
        DrawRectangleLines(bx, BTN_Y, tw, BTN_H, RAYLIBColor(255, 255, 255, 30))
        lw = MeasureText(label, 11)
        DrawText(label, bx + (tw-lw)/2, BTN_Y+14, 11, WHITE)
    ok

    return bx + tw

// =============================================================
// Toolbar Click
// =============================================================

func cs_handleToolbar mx, my
    if hoverBtn >= 1 and hoverBtn <= GATE_COUNT
        placeType = hoverBtn
        return
    ok
    if hoverBtn = 20
        cs_saveUndo()
        cx = SCREEN_W/2 - GATE_W/2
        cy = CANVAS_H/2 - GATE_H/2
        if gridSnap
            cx = floor(cx/GRID_SIZE)*GRID_SIZE
            cy = floor(cy/GRID_SIZE)*GRID_SIZE
        ok
        id = cs_addGate(placeType, cx, cy)
        cs_deselectAll()
        idx = cs_findGateById(id)
        if idx > 0 gates[idx][5] = 1 selectedGate = idx ok
        return
    ok
    if hoverBtn = 21 cs_deleteSelected() return ok
    if hoverBtn = 22 cs_undo() return ok
    if hoverBtn = 23 gridSnap = !gridSnap return ok
    if hoverBtn = 24
        for i = 1 to len(gates)
            if gates[i][2] = GATE_INPUT gates[i][7] = 0 ok
        next
        return
    ok
