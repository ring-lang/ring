// Bert Mariani 03/18/2023
// 
// libraries/stdlib/stdlib.rh
// libraries/stdlib/stdlibcore.ring

Load "stdlibcore.ring"
Load "matrixlib.ring"

// p293 Finding Ortogonal Projection of Vector U onto Vector  V

//============================================
// Bert Mariani 03/18/2023
// MatricProjection
// projvU = (U.V)/(V.V)xV
//
//  (4,2).(3,4)/(3,4).(3.4) x(3,4)
//   4x3+2x4   / 3x3+4x4    x(3,4)
//   12+8      / 9+16       x(3,4)
// = 20        / 25         x(3,4) 
// = 20/25 x(3,4)
// =  4/5  x(3,4) 
// = 12/5, 16/5
// =  2.4 ,  3.2

U = [[4],[2]]
V = [[3],[4]]

U2 = [[6],[2],[4]]
V2 = [[1],[2],[0]]

Func Main 

MatrixPrint(U)
MatrixPrint(V)

Y  = MatrixProjection(U,V)
See "MatrixProjection Result: (12/5, 16/5): = "  MatrixPrint(Y)

//-------------------------------
// Ortho-Projection and Distance
// p293 Use the Euclidean Inner Product in R3 to find
// the orthogonal projection of U onto V

MatrixPrint(U2)
MatrixPrint(V2)

Y2  = MatrixProjection(U2,V2)
See "MatrixProjection Result2 (2,4,0): " MatrixPrint(Y2)

Ortho = MatrixSub(U2,Y2)
See "Matrix Result Ortho-Distance to V2 (4,-2,4): " MatrixPrint(Ortho)

//--------------------------------------
//p298 A Nonstandard Orthonormak Basis for R3

V1 = [[1/sqrt(2)],  [1/sqrt(2)], [0]]
V2 = [[-sqrt(2)/6], [sqrt(2)/6], [2*sqrt(2)/3]]
V3 = [[2/3],        [-2/3],      [1/3]]

R1 = DotProduct(v1,v2)  // 0
R2 = DotProduct(v1,v3)  // 0
R3 = DotProduct(v2,v3)  // 0

See "R1 "+ R1 +" R2 "+ R2 +" R3 "+ R3 +nl

//-------------------

s1 = DotProduct(v1,v1)  // 1
s2 = DotProduct(v2,v2)  // 1
s3 = DotProduct(v3,v3)  // 1

See "S1 "+s1 +" S2 "+s2 +" S3 "+s3 +nl

//-------------------
// Vectors Relative to an Orthonormal Basis (-1,-7,2)
W  = [[5],[-5],[2]]
v1 = [[3/5],[4/5],[0]]
v2 = [[-4/5],[3/5],[0]]
v3 = [[0],[0],[0]]

s1 = DotProduct(w,v1)
s2 = DotProduct(w,v2)
s3 = DotProduct(w,v3)

See "S1 "+s1 +" S2 "+s2 +" S3 "+s3 +nl+nl

Wb = [[s1], [s2], [S3]]  // Basis

See "OrthoNormal (-1,-7,0) "+nl
See "Wb " MatrixPrint(Wb) +nl

return


