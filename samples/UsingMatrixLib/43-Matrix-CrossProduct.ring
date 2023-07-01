// Bert Mariani 03/18/2023
// 
// libraries/stdlib/stdlib.rh
// libraries/stdlib/stdlibcore.ring

Load "stdlibcore.ring"
Load "matrixlib.ring"

//===================================
// Cross Product of Vectors  UxV

U = [[ 2],[ 3],[ 4]]
V = [[ 5],[ 6],[ 7]]  // U x V = (-3,6,-3)

? "----- CrossProduct Func Call: U x V = (-3,6,-3)"
MatrixPrint(U)
MatrixPrint(V)

W = CrossProduct(U,V)  See " RESULT: "
MatrixPrint(W)

//-------------------------------

U = [[ 2],[-1],[ 4]]
V = [[ 3],[ 2],[ 5]]   // U x V = 

? "----- CrossProduct Func Call: U x V = (-13,2,7)"
MatrixPrint(U)
MatrixPrint(V)

W = CrossProduct(U,V)  See " RESULT: "
MatrixPrint(W)

//-----------------------------

U = [[ 1],[-2],[ 1]]
V = [[ 3],[ 1],[ 2]]   // U x V = 

? "----- CrossProduct Func Call: U x V = (-3i -5j -7k)"
MatrixPrint(U)
MatrixPrint(V)

W = CrossProduct(U,V)  
See " p328 Result: "   MatrixPrint(W)

//------------------------------

//============================================
