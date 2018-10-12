### Program: MineSweeper - DOS Screen
### Author:  Bert MAriani
### Date:    2018-09-18
###
### TAB set to 3 Spaces
### aArray Letters: "."-Edge, e-empty, E-EmptyVisited, C-Chosen, M-Mine, B-Boom

load "stdlib.ring"

hSize  = 10     ### Size of array, Display -2 smaller
vSize  = 10     ### Size of array, Display -2 smaller
nMines = 18     ### Number of Mines

h      = 0      ### H-coord of Cell
v      = 0      ### V-coord of Cell
aArray = newList(hSize, vSize)

clearScreenOn = False           ### DOS clear screen True/False

###------------------------------------------------
### Populate array

n = 1
for v = 1 to vSize
    for h = 1 to hSize

        if h = 1 OR v = 1 or h = hSize OR v = vSize 
            aArray[h][v] = '.'  ### dot- Edges
        else    
            aArray[h][v] = 'e'  ### e - Empty
        ok

      n++
    next
next

###-------------------------------------------------
### Populate Mines at random

for n = 1 to nMines
    h = random(hSize -3 ) +2    ### Prevent Zero and Edges
    v = random(vSize -3 ) +2    ### Inside grid only
    ### See "Rdm: "+h +" "+ v +nl
    aArray[h][v] = 'M'          ### M - Mine
next

###-----------------------------------------------
### Display initial populated array

DisplayArray()


###-----------------------------------------------
### START GAME !!!
### Get user to choose cell Horz-Vert

while True

    GetUserInput()
    
    if aArray[h][v] = 'e'       ### e-Empty
        aArray[h][v] = 'C'      ### C-Chosen
        CheckCellChoosen(h,v)
        DisplayArray()
    ok

    if aArray[h][v] = 'M'       ### M-Mine
        aArray[h][v] = 'B'      ### Boom !!!     
        exit
    ok

end

###---------------------------------------
### BOOM !!! Mine was chosen - END of GAME

DisplayArray()
See "Boom !!!" +nl

###==================================
###==================================
### FUNCTIONS

Func DisplayArray()

    if clearScreenOn = True
        system("cls")               ### Clear Dos screen
    ok

    See nl
    See "  1 2 3 4 5 6 7 8 9 " +nl  ### Visual H pos

    for v = 1 to vSize
      See v                         ### Visual V pos
        for h = 1 to hSize
            See " "+ aArray[h][v]
        next
       See nl
    next
return

###-------------------------------------
### Get user to choose cell Format 2-4

Func GetUserInput()

    See "Choose H-V cell : " Give hvCoord
    aCoord = split(hvCoord,'-')
    h = 0+ aCoord[1]                ### convert to number
    v = 0+ aCoord[2]

    if h < 2 OR h > hsize -1 OR v < 2 OR v > vsize -1
        See "Bad coord."+nl
        GetUserInput()
    ok

    ### See "H"+ h +" V"+ v +nl

return

###-------------------------------------
### Check 8 Neighbors of C cell clicked
### Flip e-empty to E-visited

Func CheckCellChoosen(h,v)

    See "HV:"+h +"-"+v +" "+ aArray[h][v] +nl

    for vert = v-1 to v+1
        for horz = h-1 to h+1
    
            if aArray[horz][vert] = 'e'
                aArray[horz][vert] = "E" 

                ### Count number of Mines around the E cell
                MineCount = CheckMines(horz,vert)  
                if MineCount != 0   
                    aArray[horz][vert] = MineCount  
                ok 

                ### Flip e-Cells around E-Cell
                if MineCount = 0   
                    CheckAroundE(horz,vert)
                ok 

            ok  
        next
    next

return

###---------------------------------------------------
### Count the number of MINES around C and E cell

Func CheckMines(h,v)

   MineCount = 0

    for vert = v-1 to v+1
        for horz = h-1 to h+1
    
            if aArray[horz][vert] = 'M'  
                MineCount++  
            ok      
        next
    next

return MineCount

###--------------------------------------------------
### Check around E-cell for e-empty, Flip e to E 

Func CheckAroundE(h,v)

    ### See "E: "+h +"-"+ v +nl
    for vert = v-1 to v+1
        for horz = h-1 to h+1
    
            if aArray[horz][vert] = 'e'
                aArray[horz][vert] = "E" 

                ### Recursive - check around New E's
                CheckAroundE(horz,vert) 
            ok  
        next
    next

return

###--------------------------------------------------
