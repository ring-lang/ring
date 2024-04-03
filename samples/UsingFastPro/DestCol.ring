# Author: Bert Mariani

? "Loading Library"
load "fastpro.ring"

aList = [1:5,
         1:5,
         1:5]

See nl+"=== ORIGINAL aList ==="  MatrixPrint(aList)

updateList(aList,:mul,:col,1,3)
See "MUL updateList(aList,:mul,:col,1,3  => 1)"   MatrixPrint(aList)

//=======================

updateList(aList,:mul,:col,1,10,2)
See "MUL DCOL updateList(aList,:mul,:col,1,10,2  => 2)"   MatrixPrint(aList)

//===============================

updateList(aList,:mul,:col,2,4,3)
See "MUL DCOL updateList(aList,:mul,:col,2,4,3  => 3)"   MatrixPrint(aList)


updateList(aList,:mul,:col,1,5,3)
See "MUL DCOL updateList(aList,:mul,:col,1,5,3 => 3)"   MatrixPrint(aList)

///////////////////////////////////////////////

aList = [1:5,
         1:5,
         1:5]

See nl+"=== ORIGINAL aList ==="  MatrixPrint(aList)

updateList(aList,:add,:col,1,9,2)
See "ADD DCOL updateList(aList,:add,:col,1,9,2  => 2)"   MatrixPrint(aList)

//=======================

updateList(aList,:div,:col,2,2,3)
See "DIV DCOL updateList(aList,:div,:col,2,2,3  => 3)"   MatrixPrint(aList)

//===============================

updateList(aList,:sub,:col,2,7,4)
See "SUB DCOL updateList(aList,:sub,:col,2,7,4  => 4)"   MatrixPrint(aList)

///////////////////////////////////////////////

aList = [1:5,
         1:5,
         1:5]

See nl+"=== ORIGINAL aList ==="  MatrixPrint(aList)

updateList(aList,:add,:col,1,9)
See "ADD updateList(aList,:add,:col,1,9  => 1)"   MatrixPrint(aList)

//=======================

updateList(aList,:div,:col,2,2)
See "DIV updateList(aList,:div,:col,2,2  => 2)"   MatrixPrint(aList)

//===============================

updateList(aList,:sub,:col,4,1)
See "SUB updateList(aList,:sub,:col,4,1  => 4)"   MatrixPrint(aList)


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

