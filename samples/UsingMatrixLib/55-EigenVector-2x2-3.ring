// "EigenValue 2x2" 
//

Load "stdlibcore.ring"
Load "MatrixLib.ring"

Func Main()

See nl+"-------------------------"+nl

A = [[-6, 3],  
     [ 4, 5]]
See "A  "  MatrixPrint(A)

S = EigenValue(A)
See "EigenValue S (6,-7): "  MatrixPrint(S)

x = S[1][1]
B = [[x,0],
     [0,x]]

See "x = : "+ x +nl
C = MatrixSub(A,B)
See "C SUB(A,B)" MatrixPrint(C)

// Assign Letters 4x4     
a1 = C[1][1]  a2 = C[1][2]
b1 = C[2][1]  b2 = C[2][2]

minZ = min( fabs(a1), fabs(a2) ) // Use smaller
See "minZ : "+ minZ +nl

    if ( ((a1 % minZ) = 0) && ((a2 % minZ) = 0) ) 
       x1 = a1 / minZ   
       y1 = a2 / minZ
    ok

x2 =  x1  // Swap
y2 =  y1  // Flip even

D = [ [y2],[-x2] ]  // Swap, FlipSign
See "D (-12,3) => (1,4) " matrixPrint(D)

E = MatrixMultiply(A,D)
See "Proof EigenVector E=AD (6,24) / X: "+x +" => (1,4)"  MatrixPrint(E)

See nl+"-------------------------"+nl

x = S[2][1]
B = [[x,0],
     [0,x]]

See "A  "  MatrixPrint(A)

See "x = : "+ x +nl
C = MatrixSub(A,B)
See "C SUB(A,B)" MatrixPrint(C)

// Assign Letters 4x4     
a1 = C[1][1]  a2 = C[1][2]
b1 = C[2][1]  b2 = C[2][2]

minZ = min( fabs(a1), fabs(a2) ) // Use smaller
See "minZ : "+ minZ +nl

    if ( ((a1 % minZ) = 0) && ((a2 % minZ) = 0) ) 
       x1 = a1 / minZ   
       y1 = a2 / minZ
    ok

x2 =  x1  // Swap
y2 =  y1  // Flip even

D = [ [y2],[-x2] ]  // Swap, FlipSign
See "D (3,1) => (3,1) " matrixPrint(D)

E = MatrixMultiply(A,D)
See "Proof EigenVector E=AD (-21,7) / X: "+x +" => (-3,1)"  MatrixPrint(E)

See nl+"-------------------------"+nl
See nl+"========================="+nl
See nl+"-------------------------"+nl
