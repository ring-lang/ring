# Author: Bert Mariani
# MERGE    (add)      2 colums  => dCol  destination colume if Param 6
#                     2 rows
# MERGEMUL (multiply) 2 colums  => dCol  destination colume if Param 6
#                     2 rows
#
# To Do = dRow Destination Row
#----------------------------------------

? "Loading Library"
load "fastpro.ring"

See "MERGE Col======================="+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8]

See nl+"=== ORIGINAL aList ==="  MatrixPrint(aList)
updateList(aList,:merge,:col,4,1)
See "Merge COL updateList(aList,:merge,:col,4,1  => 4)"   MatrixPrint(aList)


See "MERGE DestCol======================="+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8]
		 
See nl+"=== ORIGINAL aList ==="  MatrixPrint(aList)
updateList(aList,:merge,:col,4,1,5)
See "Merge DestCol updateList(aList,:merge,:col,4,1,5  => 5)"   MatrixPrint(aList)



See "MERGE MULTIPLY DestCol======================="+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8]
		 
See nl+"=== ORIGINAL aList ==="  MatrixPrint(aList)
updateList(aList,:mergemul,:col,4,1,5)
See "Merge Multiply DestCol updateList(aList,:mergemul,:col,4,1,5  => 5)"   MatrixPrint(aList)


See "MERGE MULTTIPLY Row======================="+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8]
		 
See nl+"=== ORIGINAL aList ==="  MatrixPrint(aList)
updateList(aList,:mergemul,:row,2,3)
See "Merge Multiply Row updateList(aList,:mergemul,:row,2,3  => 2)"   MatrixPrint(aList)




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

