// Representing Vectors Relative to an Orthonormal Basis  p303

Load "stdlibcore.ring"
Load "MatrixFunctions.ring"
    
// B  = { V1, V2, V3 }

V1 = [[ 3/5],[4/5],[ 0]]
V2 = [[-4/5],[3/5],[ 0]]
V3 = [[   0],[  0],[ 1]]

W  = [[   5],[ -5],[ 2]]

See "V1 " MatrixPrint(v1)
See "V2 " MatrixPrint(V2)
See "V3 " MatrixPrint(V3)

W1 = DotProduct(W,V1)
See "W1  DotProduct V1.V2: 0 =  "+ W1 +nl

W2 = DotProduct(W,V2)
See "W2  DotProduct V1.V3: 0 =  "+ W2 +nl

W3 = DotProduct(W,V3)
See "W3  DotProduct V2.V3: 0 =  "+W3 +nl

WBasis = [[W1],[W2],[W3]]

See "WBasis (-1,-7,2) : = " MatrixPrint(WBasis)

