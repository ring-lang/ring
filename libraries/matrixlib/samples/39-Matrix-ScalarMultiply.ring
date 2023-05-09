// Bert Mariani 03/18/2023
// 
// libraries/stdlib/stdlib.rh
// libraries/stdlib/stdlibcore.ring

Load "stdlibcore.ring"
Load "MatrixFunctions.ring"

//===================================
// Scalar Multiply
// k x U  => kU[ij ... ]

//------------------------------

U = [[ 1],   // 2x1
     [ 4]]

V = [[ 2],   // 2x1
     [-2]]   // 1+2 =3, 4-2 =2  => 3,2


? "----- ScalarMulti Func Call k(U) "
MatrixPrint(U)
k = 2
W = ScalarMultiply(k,U) See " RESULT: k:"+ k +" " 
MatrixPrint(W)

//-----------------

U = [[ 1, 4]]    // 1x2
V = [[ 2,-2]]    // 1x2   1+2 =3, 4-2 =2  => 3,2


? "----- ScalarMulti Func Call k(U) "
MatrixPrint(U)
k = -3
W = ScalarMultiply(k,U)  See " RESULT: k:"+ k +" " 
MatrixPrint(W)

//------------------


U = [[-1,2,3],[ 0, 4, 5],[1,6, 7]]
v = [[ 2,9,8],[-1,-4,-3],[5,1,-2]]   // 


? "----- ScalarMulti Func Call k(U) "
MatrixPrint(U)
k = 5
W = ScalarMultiply(k,U)  See " RESULT: k:"+ k +" " 
MatrixPrint(W)


? "----- ScalarMulti Func Call k(U) "
MatrixPrint(U)
k = 0.5
W = ScalarMultiply(k,U)  See " RESULT: k:"+ k +" " 
MatrixPrint(W)

//---------------------------
//---------------------------

