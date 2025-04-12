# Author: Bert Mariani
#               Col   Col-Dest  Row   Row-Dest
# Add-Value    (1,2)  (1,2,3)  (1,2)  (1,2,3)    
# Sub-Value    (1,2)  (1,2,3)  (1,2)  (1,2,3)               
# Mul-Value    (1,2)  (1,2,3)  (1,2)  (1,2,3)
# Div-Value    (1,2)  (1,2,3)  (1,2)  (1,2,3)
#----------------------------------------

? "Loading Library"
load "fastpro.ring"

#-----------------------------------------

See nl+"====================================="+nl+nl
See "===== ADD COL-Value 2,11 => 2 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:add,:col,2,11)
MatrixPrint(aList)

#-----------------------------------------

See "===== ADD COL-Value DEST 2,11,4 => 4 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:add,:col,2,11,4)
MatrixPrint(aList)

#-----------------------------------------


See "===== ADD ROW-Value 2,11 => 2 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:add,:row,2,11)
MatrixPrint(aList)

#-----------------------------------------

See "===== ADD ROW-Value DEST 2,11,4 => 4 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:add,:row,2,11,4)
MatrixPrint(aList)

#-----------------------------------------
#=========================================
#-----------------------------------------

See nl+"====================================="+nl+nl
See "===== Sub COL-Value 4,11, => 4 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:sub,:col,4,11)
MatrixPrint(aList)

#-----------------------------------------

See "===== SUB COL-Value DEST 4,11,2 => 2 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:sub,:col,4,11,2)
MatrixPrint(aList)

#-----------------------------------------


See "===== SUB ROW-Value 3,11 => 3 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:sub,:row,3,11)
MatrixPrint(aList)

#-----------------------------------------

See "===== SUB ROW-Value DEST 4,11,2 => 2 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:sub,:row,4,11,2)
MatrixPrint(aList)


#-----------------------------------------
#=========================================
#-----------------------------------------

See nl+"====================================="+nl+nl
See "===== Mul COL-Value 4,11, => 4 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:mul,:col,4,11)
MatrixPrint(aList)

#-----------------------------------------

See "===== Mul COL-Value DEST 4,11,2 => 2 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:mul,:col,4,11,2)
MatrixPrint(aList)

#-----------------------------------------


See "===== Mul ROW-Value 3,11 => 3 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:mul,:row,3,11)
MatrixPrint(aList)

#-----------------------------------------

See "===== Mul ROW-Value DEST 4,11,2 => 2 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:mul,:row,4,11,2)
MatrixPrint(aList)


#-----------------------------------------
#=========================================
#-----------------------------------------

See nl+"====================================="+nl+nl
See "===== Div COL-Value 4,11, => 4 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:div,:col,4,11)
MatrixPrint(aList)

#-----------------------------------------

See "===== Div COL-Value DEST 4,11,2 => 2 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:div,:col,4,11,2)
MatrixPrint(aList)

#-----------------------------------------


See "===== Div ROW-Value 3,11 => 3 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:div,:row,3,11)
MatrixPrint(aList)

#-----------------------------------------

See "===== Div ROW-Value DEST 4,11,2 => 2 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:div,:row,4,11,2)
MatrixPrint(aList)

#-----------------------------------------
See nl+"====================================="+nl+nl


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

