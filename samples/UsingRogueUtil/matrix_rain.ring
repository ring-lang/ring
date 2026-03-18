# Author: Azzeddine Remmal
# Matrix Rain effect in Ring using RogueUtil
# Version 2.0 - Console Based

load "rogueutil.ring"

func main()

    setConsoleTitle("Matrix Rain - RogueUtil")
    hidecursor()
    saveDefaultColor()
    setBackgroundColor(BLACK)
    cls()

    chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789~!@#$%^&*()_+-=|\/?<>"
    lenChars = len(chars)
    
    w = tcols()
    h = trows()
    
    pos = []
    trailLen = []
    
    for i = 1 to w
        add(pos, random(h))
        add(trailLen, 10 + random(15))
    next

    while !kbhit()

        for i = 1 to w
            
            x = i
            y = pos[i]
            
            # Draw Head
            if y >= 1 and y <= h
                char = substr(chars, random(lenChars), 1)
                
                if random(10) > 8
                    setColor(WHITE)
                else
                    setColor(LIGHTGREEN)
                ok
                printXY(x, y, char)
                
                # Darken the previous character for tail effect
                if y > 1
                    setColor(GREEN)
                    char_tail = substr(chars, random(lenChars), 1)
                    printXY(x, y - 1, char_tail)
                ok
            ok
            
            # Erase the end of the tail
            trailY = y - trailLen[i]
            if trailY >= 1 and trailY <= h
                printXY(x, trailY, " ")
            ok

            pos[i]++

            # Reset column if the whole tail went out of screen
            if (y - trailLen[i]) > h 
                if random(100) > 95 
                    pos[i] = 0 
                    trailLen[i] = 10 + random(15)
                ok
            ok

        next

        msleep(50) 
        
        # Handle terminal resize dynamically
        if w != tcols() or h != trows()
            w = tcols()
            h = trows()
            cls()
            pos = []
            trailLen = []
            for i = 1 to w
                add(pos, random(h))
                add(trailLen, 10 + random(15))
            next
        ok

    end
    
    # Consume the key that was pressed to exit
    getkey()

    resetColor()
    showCursor()
    cls()

end
