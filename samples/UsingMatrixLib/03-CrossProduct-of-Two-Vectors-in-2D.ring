// Finding the Cross Product of 2 Vectors p328

Load "stdlibcore.ring"
Load "matrixlib.ring"

// Find the Cross Product of 2 Vectors in R3 Space
// UxV
//        | i  j  k  |
//  UxV = | u1 u2 u3 |
//        | v1 v2 v3 |

U = [[ 1],[-2],[ 1]]
V = [[ 3],[ 1],[-2]]

See "U "  MatrixPrint(U)
See "V "  MatrixPrint(V)

W = CrossProduct(U,V)
See "After return UV W (3,5,7)  "  MatrixPrint(W)


W = CrossProduct(V,U)
See "After return VU W  (-3,-5,-7) "  MatrixPrint(W)

W = CrossProduct(V,V)
See "After return VV W (0,0,0) "  MatrixPrint(W)
//--------------------------

