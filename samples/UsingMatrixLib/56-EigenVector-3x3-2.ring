// "EigenVectors 3x3 Matrix" 


Load "stdlibcore.ring"
Load "matrixlib.ring"

Func Main()

    //-------------------------

    A = [[1,1,3],
         [1,5,1],
         [3,1,1]]
    See "A  "  MatrixPrint(A)

    S = EigenValue(A)              // Find EigenValues
    See "EigenValue S (-2,3,6): "  MatrixPrint(S)

    See nl+"-------------------------"+nl

    x = S[1][1]                    // EigenValue position 1
    B = [[x,0,0],
         [0,x,0],
         [0,0,x]]

    See "x = : "+ x +nl
    C = MatrixSub(A,B)
    See "C SUB(A,B)" MatrixPrint(C)

    // Assign Letters 4x4                   
    a1 = C[1][1]  a2 = C[1][2]  a3 = C[1][3]
    b1 = C[2][1]  b2 = C[2][2]  b3 = C[2][3]        
    c1 = C[3][1]  c2 = C[3][2]  c3 = C[3][3]

    x1 =   (a2*b3) - (b2*a3)   // Cross multiply
    y1 = -((a1*b3) - (b1*a3))  // FlipSign even position
    z1 =   (a1*b2) - (b1*a2)

    See "Before X: (-20,0,20) "+x +" x1: "+x1 +" y1: "+y1 +" z1: "+z1 +nl

    minXY = fabs(min(x1,y1))
    minZ  = fabs(min(z1,minXY))
    
    if ( ((x1 % minz) = 0) && ((y1 % minz) = 0) && ((z1 % minz) = 0) )
       x2 = x1 / minZ   
       y2 = y1 / minZ
       z2 = Z1 / minZ
    ok

    See "After  X: (-1,0,1) = "+ x2 +","+y2 +","+z2 +nl
    
    D = [[x2],[y2],[z2]]
    E = MatrixMultiply(A,D)
    
    See "Proof E = A*D" MatrixPrint(E)

    See nl+"---------------------------"+nl


    x = S[2][1]                     // EigenValue position 1
    B = [[x,0,0],
         [0,x,0],
         [0,0,x]]

    See "x = : "+ x +nl
    C = MatrixSub(A,B)
    See "C SUB(A,B)" MatrixPrint(C)

    // Assign Letters 4x4                   
    a1 = C[1][1]  a2 = C[1][2]  a3 = C[1][3]
    b1 = C[2][1]  b2 = C[2][2]  b3 = C[2][3]        
    c1 = C[3][1]  c2 = C[3][2]  c3 = C[3][3]

    x1 =   (a2*b3) - (b2*a3)
    y1 = -((a1*b3) - (b1*a3))  // FlipSign
    z1 =   (a1*b2) - (b1*a2)

    See "Before X: (-5,5,-5) = "+ x1 +","+y1 +","+z1 +nl
    
    minXY = fabs(min(x1,y1))
    minZ  = fabs(min(z1,minXY))
    
    if ( ((x1 % minz) = 0) && ((y1 % minz) = 0) && ((z1 % minz) = 0) )
       x2 = -x1 / minZ   // Flip even eigenvector
       y2 = -y1 / minZ
       z2 = -z1 / minZ
    ok

    See "After  X: (1,-1,1) = "+ x2 +","+y2 +","+z2 +nl
  
    D = [[x2],[y2],[z2]]
    E = MatrixMultiply(A,D)
    
    See "Proof E = A*D" MatrixPrint(E)  
    


    See nl+"---------------------------"+nl

    x = S[3][1]                     // EigenValue position 1
    B = [[x,0,0],
         [0,x,0],
         [0,0,x]]

    See "x = : "+ x +nl
    C = MatrixSub(A,B)
    See "C SUB(A,B)" MatrixPrint(C)
    
    // Assign Letters 4x4                   
    a1 = C[1][1]  a2 = C[1][2]  a3 = C[1][3]
    b1 = C[2][1]  b2 = C[2][2]  b3 = C[2][3]        
    c1 = C[3][1]  c2 = C[3][2]  c3 = C[3][3]

    x1 =   (a2*b3) - (b2*a3)
    y1 = -((a1*b3) - (b1*a3))  // FlipSign
    z1 =   (a1*b2) - (b1*a2)

    See "Before X: (4,8,4) = "+ x1 +","+y1 +","+z1 +nl

    minXY = fabs(min(x1,y1))
    minZ  = fabs(min(z1,minXY))
    
    if ( ((x1 % minz) = 0) && ((y1 % minz) = 0) && ((z1 % minz) = 0) )
       x2 = x1 / minZ   
       y2 = y1 / minZ
       z2 = x1 / minZ
    ok

    See "After  X: (1,2,1) = "+ x2 +","+y2 +","+z2 +nl

    D = [[x2],[y2],[z2]]
    E = MatrixMultiply(A,D)
    
    See "Proof E = A*D" MatrixPrint(E)
	
    See nl+"---------------------------"+nl
