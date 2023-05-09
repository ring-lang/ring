// A Nonstandard Orthonormal Basis for R3 Space p298

Load "stdlibcore.ring"
Load "MatrixLib.ring"
    
// R3 Space
s2 = sqrt(2)

V1 = [[ 1/s2],[ 1/s2],[ 0]]
V2 = [[-s2/6],[ s2/6],[ 2*s2/3]]
V3 = [[  2/3],[ -2/3],[ 1/3]]

See "V1 " MatrixPrint(v1)
See "V2 " MatrixPrint(V2)
See "V3 " MatrixPrint(V3)

W1 = DotProduct(V1,V2)
See "W1  DotProduct V1.V2: 0 =  "+ W1 +nl

W2 = DotProduct(V1,V3)
See "W2  DotProduct V1.V3: 0 =  "+ W2 +nl

W3 = DotProduct(V2,V3)
See "W3  DotProduct V2.V3: 0 =  "+W3 +nl


L1 = VectorLength(V1)
See "L1 Vector Length L1: 1 = "+ L1 +nl

L2 = VectorLength(V2)
See "L1 Vector Length L2: 1 = "+ L2 +nl

L3 = VectorLength(V3)
See "L1 Vector Length L3: 1 = "+ L3 +nl
