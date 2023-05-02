// Bert Mariani 03/18/2023
// 
// libraries/stdlib/stdlib.rh
// libraries/stdlib/stdlibcore.ring

Load "stdlibcore.ring"

//===================================
// InverseMatrix 2x2

U = [[ 3,-1],
     [-2, 2]]


? "----- InverseMatrix Func Call: U 2x2"
MatrixPrint(U)

W = InverseMatrix(U)  See " RESULT: "
if W = 1
   See "Error: "+ 1 +nl+nl
else
   MatrixPrint(W)
ok

//-------------------------------

U =  [[ 3,-1],
      [-6, 2]]   

? "----- InverseMatrix Func Call: U 2x2"
MatrixPrint(U)

W = InverseMatrix(U)  See " RESULT: "
if W = 1
   See "Error: "+ 1 +nl+nl
else
   MatrixPrint(W)
ok

//-------------------------------

U =  [[ 5,-3],
      [-2, 2]]   

? "----- InverseMatrix Func Call: U 2x2"
MatrixPrint(U)

W = InverseMatrix(U)  See " RESULT: "
if W = 1
   See "Error: "+ 1 +nl+nl
else
   MatrixPrint(W)
ok

//------------------------------

//============================================
//============================================
// Bert Mariani 03/18/2023
// InverseMatrix(U)
// Inverse Matrix U 2x2
// U   =  | a b|
//        | c d|
//
// u1  =  (1 / (ad - bc)) X | d -b|   // Criss-cross d,a  and negative -b,-c
//                          |-c  a|

Func InverseMatrix(U)

    vertU = len(U)    horzU = len(U[1])

      
    if  (vertU != 2 AND horzU != 2 )
        See "Error: InverseMatrix Dimension: "+ nl
        See "vertU: "+ vertU +" horzU: "+ horzU +" MUST BE Equal = 2 "+ nl
        return 1
    ok 

    ad  =   U[1][1]  *   U[2][2]
    bc  = (-U[1][2]) * (-U[2][1])  

    if (ad - bc) = 0
       See "Error: InverseMatrix Dimension: "+ nl
       See "Matrix Not Reversible (ad - bc) "+ ad +" - "+ bc +" = 0 "+ nl
       return 1
    ok

    det = 1 / (ad - bc)                           // Determinate
    
    a =   U[1][1] * det    b =  -U[1][2] * det    // Negate b and c
    c =  -U[2][1] * det    d =   U[2][2] * det  
    
    U[1][1] = d    U[1][2] = b                    // Criss-cross d,a 
    U[2][1] = c    U[2][2] = a
    
    //See "Determinate: ad: "+ ad +" bc: "+ bc +" sub: "+ (ad - bc) +" det: "+ det +nl


return U

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

