// Bert Mariani 03/18/2023
// 
// libraries/stdlib/stdlib.rh
// libraries/stdlib/stdlibcore.ring

Load "stdlibcore.ring"

//===================================
// InverseMatrix3  3x3

U = [[ 1, 2 ,3],
     [ 0, 1, 4],
     [ 5, 6, 0]]

? "----- InverseMatrix3 Func Call: U 3x3"
MatrixPrint(U)

W = InverseMatrix3(U)  See " RESULT: "
if W = 1
   See "Error: "+ 1 +nl
else
   MatrixPrint(W)
ok

//------------------------

U = [[ 2,-3, 1],                  
     [ 2, 0,-1],
     [ 1, 4, 5]]               
 

? "----- InverseMatrix3 Func Call: U 3x3"
MatrixPrint(U)

W = InverseMatrix3(U)  See " RESULT: "
if W = 1
   See "Error: "+ 1 +nl
else
   MatrixPrint(W)
ok

//-------------------------------


//------------------------------

//============================================
//============================================
// Bert Mariani 03/18/2023
// InverseMatrix3(U) 
// Inverse a 3x3 matrix
//
// Transpose      Trans Mt     Orig U
// Ut  =  | a b c| 1 0 5 |    | 1 2 3 |
//        | d e f| 2 1 6 | <= | 0 1 4 |
//        | g h i| 3 4 0 |    | 5 6 0 |
// 
// Determinate Orig-U
//           A     B     C
//           1x-24 2x-20 3x-5
//             -24   -40   -15
// FlipSign   +     -     +       
//             -24   +40   -15 ==> 1 Determinate
// 
// Detrminates Mt transpose
//         A ei-hf=-24 B di-gf=-18 C dh-eg=5  
//         D bi-cg=-20 E ai-cg=-15 F ah-bg=4
//         G bf-ce=-5  H af-cd=-4  I ae-bd=1
// 
//            Adj(M)        Sign      Adj(M) signs
// Adj(M) = |-24 -18  5|   |+ - +|   |-24  18  5|
//          |-20 -15  4| X |- + -| = | 20 -15 -4|
//          | -5  -4  1|   |+ - +|   | -5   4  1|
// 
// M-Inverse
// Mi  = 1/Det(U) x Adj(M)
// 
//           Adj(M) signs
//          |-24  18  5|
// Mi =  1/1| 20 -15 -4|  // 1/1 = Det
//          | -5   4  1|
// 
//------------------------------------

Func InverseMatrix3(U)

    vertU = len(U)    horzU = len(U[1])
      
    if  (vertU != 3 AND horzU != 3 )
        See "Error: InverseMatrix3 Dimension: "+ nl
        See "vertU: "+ vertU +" horzU: "+ horzU +" MUST BE Equal = 3 "+ nl
        return 1
    ok 

   // Assign lettes a-i to matrix Orig-U
   a = U[1][1]  b = U[1][2]  c = U[1][3]
   d = U[2][1]  e = U[2][2]  f = U[2][3]
   g = U[3][1]  h = U[3][2]  i = U[3][3]

   //Determinate or Original U and flip sign + - +

   Det = (a*(e*i - f*h)) - (b*(d*i -f*g)) + (c*(d*h - e*g))

   See "Fac: "+ a +"* (("+ (e*i) +") - ("+ (f*h) +")) ="+ (a*(e*i - f*h)) +nl
   See "Fac: "+ b +"* (("+ (d*i) +") - ("+ (f*g) +")) ="+ (b*(d*i - f*g)) +nl
   See "Fac: "+ c +"* (("+ (d*h) +") - ("+ (e*g) +")) ="+ (c*(d*h - e*g)) +nl

   See "Det: 49: "+ det +nl

    if (Det) = 0
       See "Error: InverseMatrix Dimension: "+ nl
       See "Matrix Not Reversible: Determinate = "+ Det  + nl
       return 1
    ok

   // Transpose U => Mt 
   M = MatrixTrans(U)

   // Assign lettes a-i to Transpose M
   a = M[1][1]  b = M[1][2]  c = M[1][3]
   d = M[2][1]  e = M[2][2]  f = M[2][3]
   g = M[3][1]  h = M[3][2]  i = M[3][3]

   // Detrminates Mt transpose
   //         A ei-hf=-24 B di-gf=-18 C dh-eg=5  
   //         D bi-cg=-20 E ai-cg=-15 F ah-bg=4
   //         G bf-ce=-5  H af-cd=-4  I ae-bd=1

   MA = ((e*i) - (h*f))  MB = ((d*i) - (f*g))  MC = ((d*h) - (e*g))  
   MD = ((b*i) - (c*h))  ME = ((a*i) - (c*g))  MF = ((a*h) - (b*g)) 
   MG = ((b*f) - (c*e))  MH = ((a*f) - (c*d))  MI = ((a*e) - (b*d)) 

   AdjM = [[ MA, -MB,  MC],  // Adjunct Matrix with SignFlip
           [-MD,  ME, -MF],
           [ MG, -MH,  MI]] 
   
   Mi = ScalarMulti( 1/det, AdjM)


return Mi

//============================================
//=============================================
//=============================================
// ScalarMulti of Vector U
// W = k(U) =>  Wij ....
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
 

//=============================================
//=============================================
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

