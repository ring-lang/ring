sanitation= 0
see "police fire sanitation" + nl

for police = 2 to 7 step 2
    for fire = 1 to 7
        if fire = police
           loop
        ok
        sanitation = 12 - police - fire
        if sanitation = fire or sanitation = police 
           loop
        ok  
        if sanitation >= 1 and sanitation <= 7 
           see "   " + police + "      " + fire + "       " + sanitation + nl
        ok
    next
next
