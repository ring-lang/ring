// Bert Mariani 03/18/2023
// 
// libraries/stdlib/stdlib.rh
// libraries/stdlib/stdlibcore.ring

Load "stdlibcore.ring"

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


//------------------------------

//============================================
//============================================
// Bert Mariani 03/18/2023
// CrossProduct(U,V)
// Cross Product of Vectors UxV => Vectot W
// Dimension 3x1 Only

Func CrossProduct(U,V)

    vertU = len(U)    horzU = len(U[1])
    vertV = len(V)    horzV = len(V[1])
        vertW = len(U)    horzW = len(V[1])
        W     = list(vertU, horzV) 
      
    if  (vertU !=3 AND vertV != 3)  AND (horzU != 1 AND horzV != 1)  
        See "Error: Cross Product Dimension: "+ nl
                See "horzU: "+ horzU +" horzV: "+ horzV +" MUST BE = 1 "+ nl
                See "vertU: "+ vertU +" vertV: "+ vertV +" MUST BE = 3 " +nl
        return 1
    ok 

 // Assign Letters for U x Y 

     ax = U[1][1]  ay = U[2][1]  az = U[3][1]
     bx = V[1][1]  by = V[2][1]  bz = V[3][1]
     cx = W[1][1]  cy = W[2][1]  cz = W[3][1]
 
     cx = ay*bz - az*by    // Determinants
     cy = az*bx - ax*bz
     cz = ax*by - ay*bx

     W =[[cx],[cy],[cz]]

return W

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

//================================================

