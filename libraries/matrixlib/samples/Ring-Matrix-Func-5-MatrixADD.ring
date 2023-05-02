// Bert Mariani 03/18/2023
// 
// libraries/stdlib/stdlib.rh
// libraries/stdlib/stdlibcore.ring

Load "stdlibcore.ring"

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
// MatrixAdd(U,V)
// Matrix ADD of Vectors U+V 
// U and V must be same size, Horz x Vert
// 
Func MatrixAdd(U,V)

    vertU = len(U)    horzU = len(U[1])
    vertV = len(V)    horzV = len(V[1])
    vertW = len(U)    horzW = len(V[1])
    W     = list(vertU, horzV) 
      
    if  (vertU != vertV) AND (horzU != horzV )
        See "Error: Matrix ADD Dimension: "+ nl
        See "vertU: "+ vertU +" vertV: "+ vertV +" MUST BE EQUAL " +nl
        See "horzU: "+ horzU +" horzV: "+ horzV +" MUST BE EQUAL "+ nl

        return 1
    ok 
    
    for i = 1 to vertU
        for j = 1 to horzV
            W[i][j] = U[i][j] + V[i][j]
         
        next
    next
    
return W    

//================================================
//================================================

