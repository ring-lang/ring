// Bert Mariani 03/18/2023
// 
// libraries/stdlib/stdlib.rh
// libraries/stdlib/stdlibcore.ring

Load "stdlibcore.ring"
Load "matrixlib.ring"

Decimals(3)
//===================================

See "==========================="+nl
? nl+"====== Determinate(U) Func Call "+nl
    U = [[1, 1, 1, 1, 1], // Det=6   CoFactor  -60 -39 -10 18   <<<< FlipSign -60-39 -10 18 ==>
         [1, 1,-2, 3, 1],  
         [1, 4,-6, 3, 2], //                     6   3   0  0     RowColValue   1 -2  3  1
         [1,-2, 4,-9,-3], //                   -12  -9  -2  0     Multiply    -60 78 -30 18
         [1, 3,-6 ,9, 2]] //   
MatrixPrint(U)
Det = (Determinant(U))
See "RESULT Deteminant: Correct 6: "+ Det +nl+nl


See "==========================="+nl
? nl+"====== Determinate(U) Func Call "+nl
U = [[ 1,-2, 3, 1],           
     [ 4,-6, 3, 2],
     [-2, 4,-9,-3],
     [ 3,-6 ,9, 2]]

MatrixPrint(U)
Det = (Determinant(U))
See "RESULT Deteminant: Correct 6: "+ Det +nl+nl

See "----------------------"+nl+nl

M = MatrixTrans(U)
MatrixPrint(M)
Det = (Determinant(M))
See "RESULT Deteminant Transpose: Correct 6: "+ Det +nl+nl

See "======================"+nl+nl
? nl+"====== Determinate(U) Func Call:  "+nl
U = [[ 7, 2, 1, 4, 5],           
     [ 2,-7, 4, 5, 6],
     [ 3, 4, 7, 1, 1],
     [ 1, 1, 6,-7, 2],
     [ 5, 6, 1, 2, 7]]


MatrixPrint(U)
Det = (Determinant(U))
See "RESULT Deteminant: Correct 20774 : "+ Det +nl+nl

See "======================"+nl+nl
? nl+"====== Determinate(U) Func Call: "+nl
U = [[ 7, 2, 1, 4, 5, 6],           
     [ 2,-7, 4, 5, 6, 1],
     [ 3, 4, 7, 1, 1, 2],
     [ 1, 1, 6,-7, 2, 3],
     [ 5, 6, 1, 2, 7, 4],
     [ 6, 1, 2, 1, 4,-7]]


MatrixPrint(U)
Det = (Determinant(U))
See "RESULT Deteminant: Correct -270000: "+ Det +nl+nl

See "----------------------"+nl+nl

U = MatrixTrans(U)
MatrixPrint(U)
Det = (Determinant(U))
See "RESULT Deteminant Transpose: Correct -270000: "+ Det +nl+nl



See "======================"+nl+nl
? "----- VOLUME Tetrahedron Func Call: "
U = [[ 0, 4, 1, 1],
     [ 4, 0, 0, 1],
     [ 3, 5, 2, 1],
     [ 2, 2, 5, 1]]

MatrixPrint(U)

Det = (Determinant4(U))
if Det = 0
  See "Volume: 0 Colinear Points, Determant: "+ Det +nl+nl
else
  Volume = 1/6 * Det  See " Using Determinant RESULT: Correct -12: "
  See "Volume Tetrahedron: "+ Volume +" cubic units "+nl+nl
ok

//-----------------------

