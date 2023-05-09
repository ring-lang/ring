// libraries/stdlib/stdlib.rh
// libraries/stdlib/stdlibcore.ring

Load "stdlibcore.ring"
Load "MatrixFunctions.ring"

// Multiply two matrices together.
? "MatrixMulti( MN x NP)"


A = [[1, 0, 3], 
     [2,-1,-2]] 

B = [[-2, 4 ,2],   
     [ 1, 0, 0], 
     [-1, 1,-1]]

C = [[-5, 7,-1],   // AxB = C
     [-3, 6, 6]]

D = [[ 2],
     [-1],
     [ 1]]

E = [[ 1,-2,-3]]

F = [[ 2,-4,-6],    // DxE = F
     [-1, 2, 3],
     [ 1,-2,-3]]

G = [[ 5, 4, 4],
     [-3, 1, 2]]

H = [[ 1, 2,-7],
     [ 0,-5, 1]]

K = [[ 1, 2, 3]]    // GxH =  2x3 2x3 => Invalid

//----------------------

? "----- MatrixMulti Func Call: C = AxB "
MatrixPrint(A)
MatrixPrint(B)

C = MatrixMulti(A,B)  See " RESULT: "
MatrixPrint(C)

//----------------

? "----- MatrixMulti Func Call: F = DxE "
MatrixPrint(D)
MatrixPrint(E)

F = MatrixMulti(D,E)  See " RESULT: "
MatrixPrint(F)

//----------------

? "----- MatrixMulti Func Call: K = GxH "
MatrixPrint(G)
MatrixPrint(H)

K = MatrixMulti(G,H)  See " RESULT: "

if K = 1
   ? "Matrix Check return: "+ K +" : K is Invalid:  MN x NP , N<>N"
   ? ""
else
   MatrixPrint(K)
ok

//===================================

