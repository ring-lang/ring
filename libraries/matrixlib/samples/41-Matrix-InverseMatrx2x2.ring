// Bert Mariani 03/18/2023
// 
// libraries/stdlib/stdlib.rh
// libraries/stdlib/stdlibcore.ring

Load "stdlibcore.ring"
Load "MatrixLib.ring"

//===================================
// InverseMatrix 2x2

U = [[ 3,-1],
     [-2, 2]]


? "----- MatrixInverse Func Call: U 2x2"
MatrixPrint(U)

W = MatrixInverse(U)  See " RESULT: "+nl
if W = 1
   See "Error: Inverse not possible "+ W +nl+nl
else
   MatrixPrint(W)
ok

//-------------------------------

U =  [[ 3,-1],
      [-6, 2]]   

? "----- MatrixInverse Func Call: U 2x2"  MatrixPrint(U)

W = MatrixInverse(U)  See " RESULT: "+nl
if W = 1
   See "Error: Inverse not possible "+ W +nl+nl
else
   MatrixPrint(W)
ok

//-------------------------------

U =  [[ 5,-3],
      [-2, 2]]   

? "----- MatrixInverse Func Call: U 2x2"  MatrixPrint(U)

W = MatrixInverse(U)  See " RESULT: "
if W = 1
   See "Error: "+ 1 +nl+nl
else
   MatrixPrint(W)
ok

//------------------------------

//============================================
