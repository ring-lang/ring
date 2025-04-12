# Author: Bert Mariani
#              Col   Col-Dest  Row   Row-Dest
# Merge (add) (1,2)  (1,2,3)  (1,2)  (1,2,3)    
# MergeSub    (1,2)  (1,2,3)  (1,2)  (1,2,3)               
# MergeMul    (1,2)  (1,2,3)  (1,2)  (1,2,3)
# MergeDiv    (1,2)  (1,2,3)  (1,2)  (1,2,3)
#----------------------------------------

? "Loading Library"
load "fastpro.ring"

#-----------------------------------------

See nl+"===================================="+nl+nl
See "===== Merge COL 2,3 => 2 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:merge,:col,2,3)
MatrixPrint(aList)

#-----------------------------------------

See "===== Merge COL DEST 2,3,4 => 4 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:merge,:col,2,3,4)
MatrixPrint(aList)

#-----------------------------------------


See "===== Merge ROW 2,3 => 2 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:merge,:row,2,3)
MatrixPrint(aList)

#-----------------------------------------

See "===== Merge ROW DEST 2,3,4 => 4 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:merge,:row,2,3,4)
MatrixPrint(aList)

#-----------------------------------------
#=========================================
#-----------------------------------------

See nl+"===================================="+nl+nl
See "===== MergeSub COL 4,3, => 4 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:mergesub,:col,4,3)
MatrixPrint(aList)

#-----------------------------------------

See "===== MergeSub COL DEST 4,3,2 => 2 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:mergesub,:col,4,3,2)
MatrixPrint(aList)

#-----------------------------------------


See "===== MergeSub ROW 3,2 => 3 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:mergesub,:row,3,2)
MatrixPrint(aList)

#-----------------------------------------

See "===== MergeSub ROW DEST 4,3,2 => 2 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:merge,:row,4,3,2)
MatrixPrint(aList)


#-----------------------------------------
#=========================================
#-----------------------------------------

See nl+"===================================="+nl+nl
See "===== MergeMul COL 4,3, => 4 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:mergemul,:col,4,3)
MatrixPrint(aList)

#-----------------------------------------

See "===== MergeMul COL DEST 4,3,2 => 2 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:mergemul,:col,4,3,2)
MatrixPrint(aList)

#-----------------------------------------


See "===== MergeMul ROW 3,2 => 3 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:mergemul,:row,3,2)
MatrixPrint(aList)

#-----------------------------------------

See "===== MergeMul ROW DEST 4,3,2 => 2 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:mergemul,:row,4,3,2)
MatrixPrint(aList)


#-----------------------------------------
#=========================================
#-----------------------------------------

See nl+"===================================="+nl+nl
See "===== MergeDiv COL 4,3, => 4 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:mergediv,:col,4,3)
MatrixPrint(aList)

#-----------------------------------------

See "===== MergeDiv COL DEST 4,3,2 => 2 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:mergediv,:col,4,3,2)
MatrixPrint(aList)

#-----------------------------------------


See "===== MergeDiv ROW 3,2 => 3 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:mergediv,:row,3,2)
MatrixPrint(aList)

#-----------------------------------------

See "===== MergeDiv ROW DEST 4,3,2 => 2 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:mergediv,:row,4,3,2)
MatrixPrint(aList)

#-----------------------------------------
See nl+"===================================="+nl+nl


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

