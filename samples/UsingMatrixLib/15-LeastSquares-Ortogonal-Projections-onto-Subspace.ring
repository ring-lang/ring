//Least Squares - Ortogonal Projection onto a Subspace p321

Load "stdlibcore.ring"
Load "matrixlib.ring"

//-------------------------
// Ortogonal Projection onto a Subspace
// Find the orthogonal projection of the Vector B
// onto thr the column space S of the Matrix A

A  = [[0,2],
      [3,0],
      [1,0]]

b  = [[1],
      [1],
      [3]]

See "A "  MatrixPrint(A)
See "b "  MatrixPrint(b)


// Transpose  AtA  and AtB

AtA = MatrixMulti( MatrixTrans(A), A )  //  10 0
                                        //   0 4

Atb = MatrixMulti( MatrixTrans(A), b )  //  6
                                        //  2

See "AtA A-Transpose x A" MatrixPrint(AtA)
See "Atb A-Transpose x b" MatrixPrint(Atb)


X1  = MatrixMulti( MatrixInverse(AtA), Atb)   // 0.60, 0.50 
See "Result C Slope c X:  (Inverse AtA) x AtB  " MatrixPrint(x1)

Ax = Matrixmulti(A,x1)  // 1,  1.8,  0.6

See "A x X= Projection  1, 9/5, 3/5" MatrixPrint(Ax)

//------------------------







