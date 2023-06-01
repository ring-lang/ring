// Find the Orthogonal Projection of U onto V  p293

Load "stdlibcore.ring"
Load "matrixlib.ring"
    
//R2 Space
U = [[4],[ 2]]
V = [[3],[ 4]]

See "U " MatrixPrint(U)
See "V " MatrixPrint(V)

W2 = MatrixProjection(U,V)
See "W2  MatrixProj Call (2.4, 3.2) =  "  MatrixPrint(W2)

//================================
// Finding an Orthogonal Projection in R3 Spce

U = [[6],[ 2],[4]]
V = [[1],[ 2],[0]]

W2 = MatrixProjection(U,V)
See "W2  MatrixProj Call (2,4,0) =  "  MatrixPrint(W2)

//=============================
// Distance from Ortho W2 to U
D2 = MatrixSub(U,W2)    
See "Distance from U to W2 (4,-2,4) = " MatrixPrint(D2)
