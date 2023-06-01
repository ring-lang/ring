//Least Squares - Projection into Subspace

Load "stdlibcore.ring"
Load "matrixlib.ring"

//-------------------------
//Find the projection of Vector V onto the Subspace R3
//Spanned by the Vectors W1 and W2

V  = [[1],[1],[3]]
W1 = [[0],[3],[1]]
W2 = [[2],[0],[0]]

//---------------------------
// Normalize W1 and W2
// Length
U1 = VectorNorm(W1)
U2 = VectorNorm(W2)

See "U1 norm 1/sqrt(10) = "+ U1 +nl
See "U2 norm 1/2 = "+ U2 +nl

//------------------------------
// Normalize

U3 = ScalarMultiply(1/U1, W1)
U4 = ScalarMultiply(1/U2, W2)

See "U3 norm  = " MatrixPrint(U3)
See "U4 norm  = " MatrixPrint(U4)

vu1 = MatrixProjection(v,u3)  
vu2 = MatrixProjection(v,u4) 

See "Proj,vu1 "   MatrixPrint(vu1)
See "Proj,vu2 "   MatrixPrint(vu2)

Proj = MatrixAdd(vu1, vu2)
See "Proj Add vu1, vu2 "   MatrixPrint(Proj)

//========================================
// LIBRARY

vW1  = MatrixProjection(v,W1)  
vW2  = MatrixProjection(v,W2) 
ProjW = MatrixAdd(vW1, vW2)

See "Lib Proj Add vW1, vW2 "   MatrixPrint(ProjW)


