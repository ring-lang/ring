# Author: Gal Zsolt

scaleX = 2
scaleY = 1
black  = "#"
white  = "."
clear  = " "

func main
    printYinYang(17)
    printYinYang(8)

func printYinYang radius
    for sy = radius * scaleY to -radius * scaleY step -1
        line = ""
        for sx = -radius * scaleX to radius * scaleX
            x = sx / scaleX
            y = sy / scaleY
            
            if inCircle(0, 0, radius, x, y)
                if inCircle(0, radius/2, radius/2, x, y)
                    if inCircle(0, radius/2, radius/6, x, y) line += black else line += white ok
                elseif inCircle(0, -radius/2, radius/2, x, y)
                    if inCircle(0, -radius/2, radius/6, x, y) line += white else line += black ok
                elseif x < 0
                    line += white
                else
                    line += black
                ok
            else
                line += clear
            ok
        next
        see line + nl
    next

func inCircle cx, cy, r, x, y
    return (pow(x-cx, 2) + pow(y-cy, 2)) <= pow(r, 2)