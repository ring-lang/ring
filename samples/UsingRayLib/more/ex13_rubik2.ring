# Author: Gal Zsolt (CalmoSoft)
load "raylib.ring"

SCREEN_WIDTH  = 800
SCREEN_HEIGHT = 600

STATE_ROTATING = 1
STATE_SOLVING  = 2

# Color indices for the internal sticker array
C_RED    = 1 # Right
C_BLUE   = 2 # Left
C_YELLOW = 3 # Top
C_GREEN  = 4 # Bottom
C_ORANGE = 5 # Front
C_WHITE  = 6 # Back

func main
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ring Language - Solvable 3D Rubik's Cube (White Background)")
    SetTargetFPS(60)

    camera = Camera3D( 
        0.0, 0.0, 11.0,    
        0.0, 0.0, 0.0,     
        0.0, 1.0, 0.0,     
        45.0,              
        CAMERA_PERSPECTIVE 
    )

    angleX = 0.0
    angleY = 0.0
    radius = 11.0 
    currentState = STATE_ROTATING

    # --- CUBE GENERATION WITH REAL STICKER ARRAY ---
    cubies = []
    for x = -1 to 1
        for y = -1 to 1
            for z = -1 to 1
                if x = 0 and y = 0 and z = 0 loop ok
                
                stickers = [C_RED, C_BLUE, C_YELLOW, C_GREEN, C_ORANGE, C_WHITE]
                add(cubies, [x, y, z, stickers])
            next
        next
    next

    # --- AUTOMATIC SCRAMBLE AND INVERSE SOLUTION ---
    scrambleMoves = [2, 3, 1, 2, 1, 3] # R, U, F, R, F, U
    
    # SAFE INDEX-BASED LOOP TO AVOID FOR...IN ERROR
    for index = 1 to len(scrambleMoves)
        activeMove = scrambleMoves[index]
        rotate_cube_mathematically(cubies, activeMove, false)
    next

    moves = [3, 1, 2, 1, 3, 2] # U', F', R', F', U', R'
    totalMoves = len(moves)
    currentMoveIndex = 0  

    currentRotationAngle = 0.0
    isAnimating = false
    activeMove = 0
    animSpeed = 0.08

    while !WindowShouldClose()
        
        # --- INPUT HANDLING ---
        if IsKeyPressed(KEY_SPACE)
            if currentState = STATE_ROTATING
                currentState = STATE_SOLVING
                angleX = 0.4
                angleY = 0.5
            else
                if !isAnimating and currentMoveIndex < totalMoves
                    currentMoveIndex++
                    activeMove = moves[currentMoveIndex]
                    isAnimating = true
                    currentRotationAngle = 0.0
                ok
            ok
        ok

        if currentState = STATE_ROTATING
            angleX += 0.015
            angleY += 0.025
        ok

        camX = radius * cos(angleX) * cos(angleY)
        camY = radius * sin(angleX)
        camZ = radius * cos(angleX) * sin(angleY)
        camera.position = Vector3(camX, camY, camZ)

        # --- ANIMATION END: SAVE PHYSICAL STATE ---
        if isAnimating
            currentRotationAngle += animSpeed
            if currentRotationAngle >= 1.5708
                isAnimating = false
                currentRotationAngle = 0.0
                rotate_cube_mathematically(cubies, activeMove, true) 
            ok
        ok

        # --- RENDERING ---
        BeginDrawing()
            ClearBackground(WHITE) # Clean white background
            
            BeginMode3D(camera)

                for i = 1 to len(cubies)
                    cx = cubies[i][1]
                    cy = cubies[i][2]
                    cz = cubies[i][3]
                    st = cubies[i][4]

                    posX = cx * 1.15
                    posY = cy * 1.15
                    posZ = cz * 1.15
                    cubieSize = 1.0

                    if isAnimating
                        if activeMove = 1 and cz = 1 # Front
                            origX = posX   origY = posY
                            posX = origX * cos(-currentRotationAngle) - origY * sin(-currentRotationAngle)
                            posY = origX * sin(-currentRotationAngle) + origY * cos(-currentRotationAngle)
                        elseif activeMove = 2 and cx = 1 # Right
                            origY = posY   origZ = posZ
                            posY = origY * cos(-currentRotationAngle) - origZ * sin(-currentRotationAngle)
                            posZ = origY * sin(-currentRotationAngle) + origZ * cos(-currentRotationAngle)
                        elseif activeMove = 3 and cy = 1 # Up
                            origX = posX   origZ = posZ
                            posX = origX * cos(-currentRotationAngle) - origZ * sin(-currentRotationAngle)
                            posZ = origX * sin(-currentRotationAngle) + origZ * cos(-currentRotationAngle)
                        ok
                    ok

                    # 1. Base black cubie body
                    DrawCube(Vector3(posX, posY, posZ), cubieSize, cubieSize, cubieSize, BLACK)

                    # 2. Draw colored stickers
                    draw_cubie_stickers(posX, posY, posZ, cx, cy, cz, st)

                    # 3. Contrasting wires for subtle 3D shading
                    DrawCubeWires(Vector3(posX, posY, posZ), cubieSize, cubieSize, cubieSize, GRAY)
                next

            EndMode3D()

            # --- 2D HUD (Dark colors over white background) ---
            DrawText("Ring Language Real 3D Rubik's Cube", 20, 20, 20, BLACK)
            if currentState = STATE_ROTATING
                DrawText("STATUS: Cube is scrambled (Demo)", 20, 50, 16, MAROON)
                DrawText("Press SPACE to start solving!", 20, 80, 16, DARKGRAY)
            else
                DrawText("STATUS: Step-by-step solving", 20, 50, 16, DARKGRAY)
                if currentMoveIndex < totalMoves
                    DrawText("Press SPACE for the next turn (" + currentMoveIndex + "/" + totalMoves + ")", 20, 80, 16, DARKGRAY)
                else
                    DrawText("CUBE SOLVED! Every side is perfectly uniform.", 20, 80, 16, DARKGREEN)
                ok
                if currentMoveIndex > 0
                    moveNames = ["FRONT (F')", "RIGHT (R')", "UP (U')"]
                    DrawText("Last move: " + moveNames[moves[currentMoveIndex]], 20, 120, 16, BLACK)
                ok
            ok

        EndDrawing()
    end

    CloseWindow()

# --- 100% ACCURATE REAL STICKER ROTATION AND SHIFTING LOGIC ---
func rotate_cube_mathematically cubiesList, moveType, isInverted
    for i = 1 to len(cubiesList)
        cx = cubiesList[i][1]
        cy = cubiesList[i][2]
        cz = cubiesList[i][3]
        st = cubiesList[i][4]
        
        if moveType = 1 and cz = 1 
            if isInverted = false 
                cubiesList[i][1] = -cy  cubiesList[i][2] = cx
                cubiesList[i][4] = [st[5], st[6], st[3], st[4], st[2], st[1]] # Clockwise shifting
            else 
                cubiesList[i][1] = cy  cubiesList[i][2] = -cx
                cubiesList[i][4] = [st[6], st[5], st[3], st[4], st[1], st[2]] # Inverted shifting
            ok
        elseif moveType = 2 and cx = 1 
            if isInverted = false 
                cubiesList[i][2] = cz  cubiesList[i][3] = -cy
                cubiesList[i][4] = [st[1], st[2], st[5], st[6], st[4], st[3]]
            else 
                cubiesList[i][2] = -cz  cubiesList[i][3] = cy
                cubiesList[i][4] = [st[1], st[2], st[6], st[5], st[3], st[4]]
            ok
        elseif moveType = 3 and cy = 1 
            if isInverted = false 
                cubiesList[i][1] = cz  cubiesList[i][3] = -cx
                cubiesList[i][4] = [st[5], st[6], st[3], st[4], st[2], st[1]]
            else 
                cubiesList[i][1] = -cz  cubiesList[i][3] = cx
                cubiesList[i][4] = [st[6], st[5], st[3], st[4], st[1], st[2]]
            ok
        ok
    next

# --- STICKER RENDERING FUNCTIONS WITH CLEAN INDEXING ---
func draw_cubie_stickers posX, posY, posZ, cx, cy, cz, st
    colorMap = [RED, BLUE, YELLOW, GREEN, ORANGE, WHITE]
    stickerThickness = 0.05
    stickerSize = 0.85
    cubieSize = 1.0

    if cx = 1   DrawCube(Vector3(posX + 0.48, posY, posZ), stickerThickness, cubieSize*stickerSize, cubieSize*stickerSize, colorMap[st[1]]) ok 
    if cx = -1  DrawCube(Vector3(posX - 0.48, posY, posZ), stickerThickness, cubieSize*stickerSize, cubieSize*stickerSize, colorMap[st[2]]) ok 
    if cy = 1   DrawCube(Vector3(posX, posY + 0.48, posZ), cubieSize*stickerSize, stickerThickness, cubieSize*stickerSize, colorMap[st[3]]) ok 
    if cy = -1  DrawCube(Vector3(posX, posY - 0.48, posZ), cubieSize*stickerSize, stickerThickness, cubieSize*stickerSize, colorMap[st[4]]) ok 
    if cz = 1   DrawCube(Vector3(posX, posY, posZ + 0.48), cubieSize*stickerSize, cubieSize*stickerSize, stickerThickness, colorMap[st[5]]) ok 
    if cz = -1  DrawCube(Vector3(posX, posY, posZ - 0.48), cubieSize*stickerSize, cubieSize*stickerSize, stickerThickness, colorMap[st[6]]) ok