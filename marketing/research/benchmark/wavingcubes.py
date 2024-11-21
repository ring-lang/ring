from pyray import *
import pyray
import math

# Program main entry point
# Initialization
screenWidth = 800
screenHeight = 450

init_window(screenWidth, screenHeight, "raylib [models] example - waving cubes")

# Initialize the camera
camera = Camera3D()
camera.position = Vector3(30.0, 20.0, 30.0)  # Camera position
camera.target = Vector3(0.0, 0.0, 0.0)       # Camera looking at point
camera.up = Vector3(0.0, 1.0, 0.0)           # Camera up vector (rotation towards target)
camera.fovy = 70.0                           # Camera field-of-view Y
camera.projection = pyray.CAMERA_PERSPECTIVE      # Camera projection type

# Specify the amount of blocks in each direction
numBlocks = 15

set_target_fps(10000)

# Main game loop
while not window_should_close():  # Detect window close button or ESC key
    # Update
    time = get_time()

    # Calculate time scale for cube position and size
    scale = (2.0 + math.sin(time)) * 0.7

    # Move camera around the scene
    cameraTime = time * 0.3
    camera.position.x = math.cos(cameraTime) * 40.0
    camera.position.z = math.sin(cameraTime) * 40.0

    # Draw
    begin_drawing()

    clear_background(RAYWHITE)

    begin_mode_3d(camera)

    draw_grid(10, 5.0)

    for x in range(numBlocks):
        for y in range(numBlocks):
            for z in range(numBlocks):
                # Scale of the blocks depends on x/y/z positions
                blockScale = (x + y + z) / 30.0

                # Scatter makes the waving effect by adding blockScale over time
                scatter = math.sin(blockScale * 20.0 + time * 4.0)

                # Calculate the cube position
                cubePos = Vector3(
                    (x - numBlocks / 2) * (scale * 3.0) + scatter,
                    (y - numBlocks / 2) * (scale * 2.0) + scatter,
                    (z - numBlocks / 2) * (scale * 3.0) + scatter,
                )

                # Pick a color with a hue depending on cube position for the rainbow color effect
                cubeColor = color_from_hsv(((x + y + z) * 18) % 360, 0.75, 0.9)

                # Calculate cube size
                cubeSize = (2.4 - scale) * blockScale

                # And finally, draw the cube!
                draw_cube(cubePos, cubeSize, cubeSize, cubeSize, cubeColor)

    end_mode_3d()

    draw_fps(10, 10)

    end_drawing()

# De-Initialization
close_window()  # Close window and OpenGL context