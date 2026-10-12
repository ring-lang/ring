# Author: Gal Zsolt

# Rubik's Magic 3D GUI Simulation using Ring and RayLib
load "raylib.ring"

# Window dimensions and initialization
SCREEN_WIDTH  = 1024
SCREEN_HEIGHT = 768

InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Rubik's Magic 3D GUI Simulation")
SetTargetFPS(60)

# Proper 3D Camera initialization directly via Camera3D function
# Parameters: pos_x, pos_y, pos_z, target_x, target_y, target_z, up_x, up_y, up_z, fovy, projection
camera = Camera3D( 0.0, 10.0, 15.0,  0.0, 0.0, 0.0,  0.0, 1.0, 0.0,  45.0, CAMERA_PERSPECTIVE )

# Description of steps and states
allapotok = [
    "1/5 Starting State: 2x4 flat rectangle (3 separate rings)",
    "2/5 First Fold: Side panels folded to the center (Thick 2x2 square)",
    "3/5 Loop Shape: Top row folded onto the bottom row (Closed loop)",
    "4/5 Shifted Loop: Panels shifted to the right",
    "5/5 Completed State: 3x3 shape with a missing corner (3 Linked rings)"
]
aktualis_lepes = 1

# Main loop running until the window is closed
while !WindowShouldClose()

    # Interaction: Press SPACE key to cycle through folding states
    if IsKeyPressed(KEY_SPACE)
        aktualis_lepes++
        if aktualis_lepes > 5
            aktualis_lepes = 1
        ok
    ok

    # Rendering
    BeginDrawing()
        ClearBackground(RAYWHITE)

        # Start 3D Mode with the camera
        BeginMode3D(camera)

            # Draw grid for orientation
            DrawGrid(10, 1.0)

            # Calculate and draw positions for the 8 panels
            for i = 1 to 8
                # Default 2x4 layout coordinates
                x = (i - 4.5) * 1.5
                y = 0.0
                z = 0.0
                if i > 4
                    x = (i - 8.5) * 1.5
                    z = 1.5
                ok

                # State-dependent position modifications
                if aktualis_lepes = 2  # 2x2 thick square
                    if i = 1 or i = 2 or i = 7 or i = 8 
                        y = 0.3 
                        if i <= 2 
                            x = x + 2.0 
                        else 
                            x = x - 2.0 
                        ok
                    ok
                ok

                if aktualis_lepes = 3  # Loop
                    if i > 4
                        z = 0.0
                        y = 0.4 
                    ok
                ok

                if aktualis_lepes = 4  # Shifted loop
                    if i > 4
                        z = 0.0 
                        y = 0.4 
                        x = x + 1.5
                    ok
                ok

                if aktualis_lepes = 5  # 3x3 completed state
                    if i = 1 x=-1.5 z=-1.5 ok
                    if i = 2 x=0.0  z=-1.5 ok
                    if i = 3 x=1.5  z=-1.5 ok
                    if i = 4 x=-1.5 z=0.0  ok
                    if i = 5 x=1.5  z=0.0  ok
                    if i = 6 x=-1.5 z=1.5  ok
                    if i = 7 x=0.0  z=1.5  ok
                    if i = 8 x=1.5  z=1.5  ok
                    y = 0.0
                ok

                # Color the panels alternately for better visibility
                color = RED
                if i % 2 = 0 
                    color = BLUE 
                ok

                # Create the Vector3 object correctly using Vector3()
                pos = Vector3(x, y, z)

                # Draw the 3D panel (position, width, height, length, color)
                DrawCube(pos, 1.2, 0.1, 1.2, color)
                DrawCubeWires(pos, 1.2, 0.1, 1.2, BLACK)
            next

        EndMode3D()

        # 2D GUI Overlay text and instructions
        DrawRectangle(10, 10, 680, 90, Fade(SKYBLUE, 0.5))
        DrawText("RUBIK'S MAGIC 3D SIMULATOR", 20, 20, 20, DARKGRAY)
        DrawText(allapotok[aktualis_lepes], 20, 50, 18, MAROON)
        DrawText("Press [SPACE] to perform the next fold!", 20, 75, 14, DARKGRAY)

    EndDrawing()
end

# Close window on exit
CloseWindow()