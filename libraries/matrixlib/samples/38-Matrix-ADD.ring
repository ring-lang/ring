// Bert Mariani 03/18/2023
// 
// libraries/stdlib/stdlib.rh
// libraries/stdlib/stdlibcore.ring

Load "stdlibcore.ring"
Load "MatrixLib.ring"

//===================================
// MATRIX ADD

//------------------------------

U = [[ 1],   // 2x1
     [ 4]]

V = [[ 2],   // 2x1
     [-2]]   // 1+2 =3, 4-2 =2  => 3,2


? "----- MatrixADD Func Call U+V "
MatrixPrint(U)
MatrixPrint(V)

W = MatrixAdd(U,V) See " RESULT: "
MatrixPrint(W)

//-----------------

U = [[ 1, 4]]    // 1x2
V = [[ 2,-2]]    // 1x2   1+2 =3, 4-2 =2  => 3,2


? "----- MatrixADD Func Call U+V "
MatrixPrint(U)
MatrixPrint(V)

W = MatrixAdd(U,V)  See " RESULT: "
MatrixPrint(W)

//------------------


U = [[-1,2,3],[ 0, 4, 5],[1,6, 7]]
v = [[ 2,9,8],[-1,-4,-3],[5,1,-2]]   // 


? "----- MatrixADD Func Call U+V "
MatrixPrint(U)
MatrixPrint(V)

W = MatrixAdd(U,V)  See " RESULT: "
MatrixPrint(W)




