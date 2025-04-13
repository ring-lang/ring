# Author: Bert Mariani
#         Col     Row   
# Copy   (1,2)   (1,2)     
# Serial (1,2)   (1,2)                
# Pow    (1,2)   (1,2)  
# REM    (1,2)   (1,2)  
# 
# updateList(<aList>,:set,:row,<nRow>,<nValue>)
# updateList(<aList>,:set,:col,<nCol>,<nValue>)
# updateList(<aList>,:set,:manyrows,<nRowStart>,<nRowEnd>,<nValue>)
# updateList(<aList>,:set,:manycols,<nColStart>,<nColEnd>,<nValue>)
# updateList(<aList>,:set,:items,<nValue>)
# updateList(<aList>,:copy,:row,<nRowSrc>,<nRowDest>)
# updateList(<aList>,:copy,:col,<nColSrc>,<nColDest>)
#----------------------------------------

? "Loading Library"
load "fastpro.ring"

#-----------------------------------------
# updateList(<aList>,:set,:col,<nCol>,<nValue>)

See nl+"===================================="+nl+nl

See "===== Set COL 2,11 => 2 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:set,:col,2,11)
MatrixPrint(aList)

#-----------------------------------------
# updateList(<aList>,:set,:row,<nRow>,<nValue>)

See "===== Set ROW 2,11 => 2 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:set,:row,2,11)
MatrixPrint(aList)

#-----------------------------------------
#=========================================
#-----------------------------------------

#-----------------------------------------
# updateList(<aList>,:set,:manycols,<nColStart>,<nColEnd>,<nValue>)

See nl+"===================================="+nl+nl

See "===== Set ManyCOLS 2,3,12 => 2-4 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:set,:manycols,2,3,12)
MatrixPrint(aList)

#-----------------------------------------
# updateList(<aList>,:set,:manyrows,<nRowStart>,<nRowEnd>,<nValue>)

See "===== Set ManyROWS 3,4,15 => 2-4 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:set,:manyrows,3,4,15)
MatrixPrint(aList)



#-----------------------------------------
#=========================================
#-----------------------------------------


#-----------------------------------------
# updateList(<aList>,:copy,:col,<nColSrc>,<nColDest>)

See nl+"===================================="+nl+nl

See "===== Copy COL 2,5 => 5 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:copy,:col,2,5)
MatrixPrint(aList)

#-----------------------------------------
# updateList(<aList>,:copy,:row,<nRowSrc>,<nRowDest>)

See "===== Copy ROW 2,5 => 5 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:copy,:row,2,5)
MatrixPrint(aList)

#-----------------------------------------
#=========================================
#-----------------------------------------

See nl+"===================================="+nl+nl

See "===== Serial COL 4,11, => 4 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:serial,:col,4,11)
MatrixPrint(aList)

#-----------------------------------------

See "===== Serial ROW 4,11 => 4 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:serial,:row,4,11)
MatrixPrint(aList)

#-----------------------------------------
#=========================================
#-----------------------------------------

See nl+"===================================="+nl+nl

See "===== Pow COL 4,3, => 4 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:pow,:col,4,3)
MatrixPrint(aList)

#-----------------------------------------

See "===== Pow ROW 4,3 => 4 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:pow,:row,4,3)
MatrixPrint(aList)


#-----------------------------------------
#=========================================
#-----------------------------------------

See nl+"===================================="+nl+nl

See "===== Rem COL 4,3, => 4 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:rem,:col,4,3)
MatrixPrint(aList)

#-----------------------------------------

See "=====Rem ROW 4,3 => 4 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:rem,:row,4,3)
MatrixPrint(aList)



#-----------------------------------------
#=========================================
#-----------------------------------------
See nl+"===================================="+nl+nl

#-----------------------------------------
# updateList(<aList>,:set,:items,<nValue>)


See "===== Set ITEMS (1Dem) 1:12 16 => 16 ========"+nl
aList = 1:12

MatrixFlatPrint(aList)
updateList(aList,:set,:items,16)
MatrixFlatPrint(aList)

#-----------------------------------------
# updateList(<aList>,:mul,:items,<nValue>)


See "===== Mul ITEMS (1Dem) 1:12 * 3 => 3:48 ========"+nl
aList = 1:12

MatrixFlatPrint(aList)
updateList(aList,:mul,:items,3)
MatrixFlatPrint(aList)

#-----------------------------------------
# updateList(<aList>,:add,:items,<nValue>)


See "===== Add ITEMS (1Dem) 1:12 + 4 => 5:16 ========"+nl
aList = 1:12

MatrixFlatPrint(aList)
updateList(aList,:add,:items,4)
MatrixFlatPrint(aList)

#-----------------------------------------
# updateList(<aList>,:sub,:items,<nValue>)


See "===== Sub ITEMS (1Dem) 1:12 - 4 => -3:8 ========"+nl
aList = 1:12

MatrixFlatPrint(aList)
updateList(aList,:sub,:items,4)
MatrixFlatPrint(aList)

#-----------------------------------------
# updateList(<aList>,:div,:items,<nValue>)


See "===== Div ITEMS (1Dem) 1:12 / 4 => 0.25:3 ========"+nl
aList = 1:12

MatrixFlatPrint(aList)
updateList(aList,:div,:items,4)
MatrixFlatPrint(aList)


//=============================================
//=============================================
// Bert Mariani 03/18/2023
// MatrixPrint(A)
// Display a Matrix Array by Row and Col size

Func MatrixPrint(U)

 See "      MatrixPrint:"
 Row = len(U)     See " "+ Row      // Rows 
 Col = len(U[1])  See "x"+ Col +nl  // Cols 
                           
 for h = 1 to Row
   See "| "
   for v = 1 to Col
     Num = U[h][v]
     if (Num >= 0) See " " ok       // 2 places
     See Num  
     if v != Col   See "," ok       // Comma between numbers
   next
   See " |"+nl
 next
   See nl
   
return
//=============================================

//=============================================
// Bert Mariani 03/18/2023
// MatrixFlatPrint(U)
// Display a Matrix Array by Row and Col size

Func MatrixFlatPrint(U)

 See "      MatrixFlatPrint:"
 Row = len(U)     See " "+ Row +nl   // Row 

 for h = 1 to Row
    See " "+ U[h] +","
 next
   See nl+nl

return
//============================================
