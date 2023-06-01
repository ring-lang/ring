// Bert Mariani 03/18/2023
// 
// libraries/stdlib/stdlib.rh
// libraries/stdlib/stdlibcore.ring

Load "stdlibcore.ring"
Load "matrixlib.ring"

//===================================
// Dot Product of Vectors = UtxV

U = [[ 1],
     [ 2],
     [-1]]

V = [[ 3],
     [-2],
     [ 4]]

? "----- DotProduct Func Call: U.V "
MatrixPrint(U)
MatrixPrint(V)

W = DotProduct(U,V)  See "W RESULT: "+W +nl

//-------------------------------

U =  [[4], [0], [-3], [5]]
V =  [[0], [2], [5],  [4]]   // 0 + 0 -15 20 => sum   5

? "----- DotProduct Func Call: U.V "
MatrixPrint(U)
MatrixPrint(V)

W = DotProduct(U,V)  See "W RESULT: "+W +nl


//------------------------------

