inputStr = ["",".","abcABC","XYZ ZYX","1234567890ABCDEFGHIJKLMN0PQRSTUVWXYZ"]
 
for Str in inputStr
    for x = 1 to len(Str)
        for y = x + 1 to len(Str)
            if Str[x] = Str[y]
               char = Str[x]
               ? "Input = " + "'" + Str + "'" + ", length = " + len(Str) 
               ? " First duplicate at positions " + x + " and " + y + ", character = " + "'" + char + "'" 
               loop 3
            ok
        next
    next
    ? "Input = " + "'" + Str + "'" + ", length = " + len(Str) 
    ? " All characters are unique." 
next
