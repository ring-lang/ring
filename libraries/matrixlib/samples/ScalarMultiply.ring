// Bert Mariani 03/18/2023
// 
// libraries/stdlib/stdlib.rh
// libraries/stdlib/stdlibcore.ring

Load "stdlibcore.ring"

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
W = ScalarMulti(k,U) See " RESULT: k:"+ k +" " 
MatrixPrint(W)

//-----------------

U = [[ 1, 4]]    // 1x2
V = [[ 2,-2]]    // 1x2   1+2 =3, 4-2 =2  => 3,2


? "----- ScalarMulti Func Call k(U) "
MatrixPrint(U)
k = -3
W = ScalarMulti(k,U)  See " RESULT: k:"+ k +" " 
MatrixPrint(W)

//------------------


U = [[-1,2,3],[ 0, 4, 5],[1,6, 7]]
v = [[ 2,9,8],[-1,-4,-3],[5,1,-2]]   // 


? "----- ScalarMulti Func Call k(U) "
MatrixPrint(U)
k = 5
W = ScalarMulti(k,U)  See " RESULT: k:"+ k +" " 
MatrixPrint(W)


? "----- ScalarMulti Func Call k(U) "
MatrixPrint(U)
k = 0.5
W = ScalarMulti(k,U)  See " RESULT: k:"+ k +" " 
MatrixPrint(W)

//---------------------------
//---------------------------




//=============================================
//=============================================
// Bert Mariani 03/18/2023
// MatrixPrint(A)
// Display a Matrix Array by Row and Col size

Func MatrixPrint(A)

See "      MatrixPrint: "
x = len(A)     See "V: "+ x +"  "     // Rows 
y = len(A[1])  See "H: "+ y +nl       // Cols 


 for h = 1 to x
   for v = 1 to y
     See " "+ A[h][v]
   next
   See nl
 next
   See nl

return

//=============================================
//=============================================
// Bert Mariani 03/18/2023
// ScalarMulti(k,U)
// ScalarMulti of Vector U
// W = k(U) =>  Wij ....Wnm
// 
Func ScalarMulti(k,U)

    vertU = len(U)    horzU = len(U[1])
    vertW = len(U)    horzW = len(U[1])
        W = list(vertU, horzU) 
      
    if  ( ! isnumber(k) )
        See "Error: ScalarMulti K not a Number: "+ k +nl    
        return 1
    ok 
    
    for i = 1 to vertU
        for j = 1 to horzU
            W[i][j] = k * (U[i][j]) 
         
        next
    next
    
return W    

//=============================================
//=============================================
 
