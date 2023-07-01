// Applying the Gram=Schmidt OrtoNormalization Process  p305

Load "stdlibcore.ring"
Load "matrixlib.ring"
    
// B  = { V1, V2}

//   w1 = v1
//   w2 = v2 -  |v2.w1|  * w1
//             ---------
//              |w1.w1|

V1 = [[ 1],[ 1]]
V2 = [[ 0],[ 1]]

See "W1 = V1 "  MatrixPrint(V1)
See "W2 = V2  " MatrixPrint(V2)

W1 = V1

// ALL in One: OrthoNormalization
W2 = MatrixSub(V2, ScalarMultiply(  (DotProduct(v2,w1) / DotProduct(W1,W1)), W1) ) 
See "All in One W2  (-1/2, 1/2)  = " MatrixPrint(W2)

//---------------------------
// Same as above: OrthoNormalization

X2 = MatrixSub( V2, MatrixProjection(V2,W1))
See "V2 - Matrix Proj(v2mw1) => X2  (-1/2, 1/2)  = " MatrixPrint(X2)

//------------------------
// Normalize Each Vector
// u1 =   w1
//     --------
//      ||w2||


U1 =  ScalarMultiply( (1/VectorNorm(w1)), w1 )
See "Orthogonal Normalize U1 normalize w1 (0.707, 0.707) = "  MatrixPrint(U1)

U2 =  ScalarMultiply( (1/VectorNorm(w2)), w2 )
See "Orthogonal Normalize U1 normalize w1 (-0.707, 0.707) = "  MatrixPrint(U2)
