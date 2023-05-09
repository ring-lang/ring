// Applying the Gram-Schmidt OrtoNormalization Process usin Library p306

Load "stdlibcore.ring"
Load "MatrixLib.ring"
    
// Basis  = { V1, V2, V3}
//
//   w1 = v1
//
//   w2 = v2 -  |v2.w1|  
//             --------- W1
//              |w1.w1|
//
//   w3 = v3 -  |v3.w1|     -  |v3.w2|
//             --------- W1   --------- w2
//              |w1.w1|         w2.w2

V1 = [[ 1],[ 1],[0]]
V2 = [[ 1],[ 2],[0]]
v3 = [[ 0],[ 1],[2]]

MatrixPrint(v1)
MatrixPrint(v2)
MatrixPrint(v2)

W1 = V1


//---------------------------
// OrthoNormalization

See "W1  1,1,0  "  MatrixPrint(w1)

W2p = MatrixProjection(V2,W1)
w2  = MatrixSub(v2,w2p)
See "W2  -1/2 1/2, 0"  MatrixPrint(w2)


W3p = MatrixProjection(v3,w1)
w3q = MatrixProjection(v3,w2)
See "W3p  1/2(1,1,0) "  MatrixPrint(w3p)
See "W3q  1/2 / 1/2 (-1/2, 1/2, 0 ) "  MatrixPrint(w3q)

w31 = MatrixSub(v3,w3p)
w3 = MatrixSub(w31,w3q)

See "W31 v3-w3p "   MatrixPrint(w31)
See "W3  w31-w3q "  MatrixPrint(w3)


//-----------------

//------------------------
// Normalize Each Vector
// u1 =   w1
//     --------
//      ||w2||


U1 =  ScalarMultiply( (1/VectorNorm(w1)), w1 )
See "Orthogonal-Normalize U1 normalize w1 (0.707, 0.707) = "  MatrixPrint(U1)

U2 =  ScalarMultiply( (1/VectorNorm(w2)), w2 )
See "Orthogonal-Normalize U2 normalize w2 (-0.707, 0.707) = "  MatrixPrint(U2)

U3 =  ScalarMultiply( (1/VectorNorm(w3)), w3 )
See "Orthogonal-Normalize U3 normalize w2 (0,0,1) = "  MatrixPrint(U3)


U1t = MatrixTranspose(U1)
U2t = MatrixTranspose(U2)
U3t = MatrixTranspose(U3)

MatrixPrint(u1t)
MatrixPrint(u2t)
MatrixPrint(u3t)

U4 = list(len(U1), 3)     // Length of Vector, Number of Vectors
for i = 1 to len(U1)
    U4[1][i] = U1t[1][i]
    U4[2][i] = U2t[1][i]
    U4[3][i] = U3t[1][i]
next

See "U4 combo u1,u2  "  MatrixPrint(u4)


//==================
// Library

U4 = MatrixOrthoNormal3(V1,V2,V3)
See "U4 Library OrthoNormal3 V1,V2,V3 "  MatrixPrint(U4)

