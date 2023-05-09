// Adjoint, Cofactor p 154

Load "stdlibcore.ring"
Load "MatrixLib.ring"

//-------------------------

U = [[-1, 3, 2],  // 3x3
     [ 0,-2, 1],
     [ 1, 0,-2]]

See "U   " MatrixPrint(U)

CoF = MatrixCoFactor(U)
See "CoFactor: "  MatrixPrint(Cof)

Adjoint = MatrixAdjoint(U)
See "Adjoint "  MatrixPrint(Adjoint)

Inverse = MatrixInverse(U)
See "Inverse "  MatrixPrint(Inverse)

ProofInverse = MatrixMulti(U,Inverse)
See "PROOF-Inverse = Identity"  MatrixPrint(ProofInverse)

/*
CoFactor:       MatrixPrint: 3x3
 4 1 2
 6 0 3
 7 1 2

Adjoint       MatrixPrint: 3x3
 4 6 7
 1 0 1
 2 3 2
Inverse       MatrixPrint: 3x3
 1.33 2 2.33
 0.33 0 0.33
 0.67 1 0.67

ProofInverse = Identity      MatrixPrint: 3x3
 1 0 0.00
 0 1 0
 0 0 1.00

*/


