
Load "stdlibcore.ring"
Load "matrixlib.ring"

//============================================
// Bert Mariani 03/18/2023
// MatricOrtho
// projvU = (U.V)/(V.V)xV

U = [[6],[2],[4]]
V = [[1],[2],[0]]

Func Main 

MatrixPrint(U)
MatrixPrint(V)

Ortho  = MatrixOrthoDistance(U,V)     // // Ortho-Projection and Distance
See "MatrixOrtho Result: (4,-2,4): "  MatrixPrint(Ortho)

//------------------------
//Basis B = {(1,1),(0,1)} Basis v1 v2  w1=v1  w2=v2

V1 = [[1],[1]]
V2 = [[0],[1]]

W1 = v1
W2 = MatrixOrthoDistance(v2,w1)  // (-1/2, 1/2)
See "W2 (-1/2, 1/2) = "  MatrixPrint(w2)

//----------------------

//Basis B1 = {w1,w2}

u1 = ScalarMultiply(1/sqrt(2),w1)  // (sqrt(2)/2 , sqrt(2)/2 )

See "U1  (sqrt(2)/2 , sqrt(2)/2 ) = " MatrixPrint(u1)

u2 = ScalarMultiply(1/(1/sqrt(2)), w2 ) //  (-sqrt(2)/2 , sqrt(2)/2 )
See "U2  (-sqrt(2)/2 , sqrt(2)/2 ) = "  MatrixPrint(u2)

//------------------------

// Basis B2 = {u1,u2}

OrthoU12 = MatrixOrthoDistance(u1,u2)  // ( 0.71, 0.71)
See "OrthoU12-u1,u2  ( 0.71, 0.71) = "  MatrixPrint(OrthoU12)

//---------------------------
//---------------------------
//Basis = {v1(1,1,0), v2(1,2,0), v3(0,1,2)

v1 = [[1],[1],[0]]
v2 = [[1],[2],[0]]
v3 = [[0],[1],[2]]

w1 = v1

w2 = MatrixOrthoDistance(v2,w1)  // (-0.5, 0.5, 0)
See "w2 ortho: (-0.5, 0.5, 0)" MatrixPrint(w2)


w3 =  MatrixSub( MatrixOrthoDistance(v3,w1), MatrixProjection(v3,w2) ) // (0,0,2)
See "w3 ortho-proj: (0,0,2) =  "  MatrixPrint(w3)
