# Author: Clement
# Matrix Rain effect in Ring using raylib
# Ring Programming Language Demo 
# Version 2.0 - Faster and simpler

load "raylib.ring"

func main()

    fontSize = 18
    w = 800
    h = 600

    InitWindow(w, h, "Matrix Rain - Faster Ring V2.0")
    SetTargetFPS(60)

    chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789~!@#$%^&*()_+-=|\/?<>"
    columns = floor(w / fontSize)
    pos = []

    for i = 1 to columns
        add(pos, random(floor(h/fontSize)))
    next

    while !WindowShouldClose()

        BeginDrawing()

        # transparent black overlay creates trail effect
        DrawRectangle(0, 0, w, h, ColorAlpha(BLACK, 0.15))

        for i = 1 to columns

            x = (i-1) * fontSize
            y = pos[i] * fontSize

            char = substr(chars, random(len(chars)-1)+1, 1)

            if random(10) > 8
                DrawText(char, x, y, fontSize, WHITE)
            else
                DrawText(char, x, y, fontSize, GREEN)
            ok

            pos[i] = pos[i] + 1

            if y > h and random(100) > 95 pos[i] = 0 ok

        next

        EndDrawing()

        Delay(0.08) 

    end

    CloseWindow()

end

func Delay(nTime) 
	# Wait for some time (nTime in seconds)
    t1 = clock()
    while clock() - t1  < (nTime * Clockspersecond())
    end