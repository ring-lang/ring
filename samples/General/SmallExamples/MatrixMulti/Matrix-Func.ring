// libraries/stdlib/stdlib.rh
// libraries/stdlib/stdlibcore.ring

Load "stdlibcore.ring"

// Multiply two matrices together.
? "Test MatrixMulti( MN x NP)"


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


? "Matrix A 2x3"
MatrixPrint(A)
? "Matrix B 3x3"
MatrixPrint(B)

? "Matrix multiply AxB = C 2x3"
MatrixPrint( MatrixMultiX(A, B) )

? "Matrix Check: C"
MatrixPrint( C)
//----------------

? "Matrix D 3x1"
MatrixPrint(D)
? "Matrix E 1x3"
MatrixPrint(E)

? "Matrix multiply DxE = F 3x3"
MatrixPrint( MatrixMultiX(D, E) )

? "Matrix Check: F"
MatrixPrint( F)
//----------------

? "Matrix G 2x3"
MatrixPrint(G)
? "Matrix H 2x3"
MatrixPrint(H)

? "Matrix multiply GxH = K  Invalid"
K = MatrixMultiX(G, H)       // Invalid  2x3  2x3   3<>2

if K = 1
   ? "Matrix Check return: "+ K +" : K is Invalid:  MN x NP , N<>N"
   ? ""
ok

//------------------------------

//==================================================
//==================================================
//
//  Function Name   : MatrixMulti
//  Usage       : Multiply two matrices together. 
//  Parameters  : Two matrices to multiply.
//  Output      : Result of multiply.
//
//  Check       : Inner Equal: MN x NP  => MP  Ex.  4x2  2x3 => 4x3
//                  
//---------------------------------------------  
   
Func MatrixMultiX A, B
    vertA = len(A)    horzA = len(A[1])   // RC  MxN 
    vertB = len(B)    horzB = len(B[1])   // RC    NxP
    vertC = len(A)    horzC = len(B[1])   // RC  M x P
    C     = list(vertA, horzB)            // Make array bigV and bigH
      
    // ? "MxN: "+ vertA +"x"+ horzA +" NxP: "+ vertB +"x"+ horzB +" => MxP: "+ vertA +"x"+ horzB +nl
    
    if horzA != vertB 
       See "Error: Matrix Dimension: MxN NxP : N:"+horzA +" MUST EQUAL N:"+vertB +nl
       return 1
    ok   
   
    for vA = 1 to vertA
        for hB = 1 to horzB
            Sum = 0
            for k = 1 to horzA             
                Sum += A[vA][k] * B[k][hB]    
                if C_FLAGSHOWSOLUTION = 1                  // 0 No Show, 1 = Show Solution
                    See " "+ A[vA][k] +"*"+ B[k][hB]
                ok
            next

            if C_FLAGSHOWSOLUTION = 1 
                See " = "+ Sum  +"  C"+ vA + hB +nl
            ok
            C[va][hB] = Sum          
        next
    next
return C


//=============================================
// Display a Matrix Array by Row and Col size

Func MatrixPrint(A)

x = len(A)       // Rows horz
y = len(A[1])    // Cols vert

 for h = 1 to x
   for v = 1 to y
     See " "+ A[h][v]
   next
   See nl
 next
   See nl

return

//================================================


//================================================
