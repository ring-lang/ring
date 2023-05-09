// Bert Mariani 03/18/2023
// 
// libraries/stdlib/stdlib.rh
// libraries/stdlib/stdlibcore.ring

Load "stdlibcore.ring"
Load "MatrixLib.ring"

//===================================
// MatrixInverse  3x3

U = [[ 1, 2 ,3],
     [ 0, 1, 4],
     [ 5, 6, 0]]

? "----- MatrixInverse Func Call: U 3x3"
MatrixPrint(U)

W = MatrixInverse(U)  See " RESULT: "
if W = 1
   See "Error: "+ 1 +nl
else
   MatrixPrint(W)
ok

//------------------------

U = [[ 2,-3, 1],                  
     [ 2, 0,-1],
     [ 1, 4, 5]]               
 

? "----- MatrixInverse Func Call: U 3x3"
MatrixPrint(U)

W = MatrixInverse(U)  See " RESULT: "
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
// MatrixInverse(U) 
// Inverse a 3x3 matrix
//
//  Tranpose   OrigU         Ut-trans
//  | a b c |  | 1 2 3 |     | 1 0 5 |
//  | d e f |  | 0 1 4 | =>  | 2 1 6 |
//  | g h i |  | 5 6 0 |     | 3 4 0 |
// 
// Determinat Orig-U
//           A     B     C
//           1x-24 2x-20 3x-5
//             -24   -40   -15
// FlipSign    +     -     +       
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

