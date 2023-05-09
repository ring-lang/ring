//Least Squares - Solving the Normal Equations p320

Load "stdlibcore.ring"
Load "MatrixLib.ring"

//-------------------------
// Find the Solution of the Least Squares problem
// Ax = b

A  = [[1,1],
      [1,2],
      [1,3]]

B  = [[0],
      [1],
      [3]]

See "A "  MatrixPrint(A)
See "B "  MatrixPrint(B)


// Transpose  AtA  and AtB

AtA = MatrixMulti( MatrixTrans(A), A )  //  3 6
                                        //  6 14

AtB = MatrixMulti( MatrixTrans(A), B )  //  4
                                        //  11

See "AtA A-Transpose x A" MatrixPrint(AtA)
See "AtB A-Transpose x B" MatrixPrint(AtB)

// Manual Solve using reduction
// The normal equations are:
// [AtA][x] = [AtB]
// Solve for X  show a column vector C
// 
// C =[[c0],
//     [c1]]

// 3co + 6c1  = 4  =>        3co + 6c1 = 4 =>           3co + 6(3/2) =4 => 3co = -5  =>  c0 = -5/3
// 6co + 14c1 = 11 => (-2a)  0co + 2c1 = 3 => c1 = 3/2
//
// Y = 3/2(X) -5/3

// Auto Solve  -- Multply x Inverse

C   = MatrixMulti( MatrixInverse(AtA), AtB)    
See "Result C Slope c X:  (Inverse AtA) x AtB  " MatrixPrint(C)

// Result C Slope c X:  (Inverse AtA) x AtB        MatrixPrint: 2x1
//  -1.67  c
//   1.50  x,  Y = (3/2)(X) - (5/3)




