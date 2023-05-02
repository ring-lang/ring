// Bert Mariani 2023/04/03
// MATRIX FUNCTIONS
//
// MatrixPrint(A)
// DotProduct(U,V)
// MatrixAdd(U,V)
// MatrixSub(U,V)
// ScalarMultiply(k,U)
// VectorAngle(U,V)
// CrossProduct(U,V)
// MatrixCofactor(U)
// MatrixInverse(U)
// MatrixDetCalc(U)
// MatrixDeterminantReduce(U)

//--------------------------------------------
// GLOBAL Constants
RAD = 57.295779513                             // 180/Pi=1  Radian=57.3 degress
PI  =  3.141592653
DetResults = [[],[],[],[],[],[],[],[],[],[]]   // Matrix Determinants up tp 10x10

//=============================================
// Bert Mariani 03/18/2023
// MatrixPrint(A)
// Display a Matrix Array by Row and Col size

Func MatrixPrint(U)

 See "      MatrixPrint:"
 x = len(U)     See " "+ x           // Rows 
 y = len(U[1])  See "x"+ y +nl       // Cols 

 for h = 1 to x
   for v = 1 to y
     See " "+ U[h][v]
   next
   See nl
 next
   See nl

return

//=============================================
// Bert Mariani 03/18/2023
// MatrixPrint(A)
// Display a Matrix Array by Row and Col size

Func MatrixFlatPrint(U)

 See "      MatrixFlatPrint:"
 x = len(U)     See " "+ x +":=> "           // Rows 

 for h = 1 to x
     See " "+ U[h]
 next
   See nl

return
//================================================

//============================================
//============================================
// Bert Mariani 03/18/2023
// DotProduct(U,V)
// Dot Product of Vectors U.V => Scalar  UtxV
// U.V = Ut.V  Horz = 1 both  Vert = same on both

Func DotProduct(U,V)

    vertU = len(U)    horzU = len(U[1])
    vertV = len(V)    horzV = len(V[1])

      
    if (horzU != 1 AND horzV != 1) AND  (vertU != vertV) 
        See "Error: Dot Product Dimension: "+ nl
        See "horzU: "+ horzU +" horzV: "+ horzV +" MUST BE = 1 "+ nl
        See "vertU: "+ vertU +" vertV: "+ vertV +" MUST BE EQUAL " +nl
        return 1
    ok 

  Ut = MatrixTrans(U)
  Dp = MatrixMulti(Ut,V)

return Dp

//=============================================
//=============================================
// Bert Mariani 03/18/2023
// MatrixAdd(U,V)
// Matrix ADD of Vectors U+V 
// U and V must be same size, Horz x Vert
// 
Func MatrixAdd(U,V)

    vertU = len(U)    horzU = len(U[1])
    vertV = len(V)    horzV = len(V[1])
    vertW = len(U)    horzW = len(V[1])
    W     = list(vertU, horzV) 
      
    if  (vertU != vertV) AND (horzU != horzV )
        See "Error: Matrix ADD Dimension: "+ nl
        See "vertU: "+ vertU +" vertV: "+ vertV +" MUST BE EQUAL " +nl
        See "horzU: "+ horzU +" horzV: "+ horzV +" MUST BE EQUAL "+ nl
        return 1
    ok 
    
    for i = 1 to vertU
        for j = 1 to horzV
            W[i][j] = U[i][j] + V[i][j]      
        next
    next
    
return W    

//=============================================
//=============================================
// Bert Mariani 03/18/2023
// MatrixSub(U,V)
// U and V must be same size, Horz x Vert
 
Func MatrixSub(U,V)

    vertU = len(U)    horzU = len(U[1])
    vertV = len(V)    horzV = len(V[1])
        vertW = len(U)    horzW = len(V[1])
        W     = list(vertU, horzV) 
      
    if  (vertU != vertV) AND (horzU != horzV )
        See "Error: Matrix ADD Dimension: "+ nl
        See "vertU: "+ vertU +" vertV: "+ vertV +" MUST BE EQUAL " +nl
        See "horzU: "+ horzU +" horzV: "+ horzV +" MUST BE EQUAL "+ nl
        return 1
    ok 
    
    for i = 1 to vertU
        for j = 1 to horzV
            W[i][j] = U[i][j] - V[i][j]      
        next
    next
    
return W    

//=============================================
//=============================================
// Bert Mariani 03/18/2023
// ScalarMulti(k,U)
// ScalarMulti of Vector U
// W = k(U) =>  Wij ....Wnm
// 
Func ScalarMultiply(k,U)

    vertU = len(U)    horzU = len(U[1])
    vertW = len(U)    horzW = len(U[1])
        W = list(vertU, horzU) 
      
    if  ( ! isnumber(k) )
        See "Error: ScalarMulti K not a Number: "+ k +nl    
        return 1
    ok 
    
    for i = 1 to vertU
        for j = 1 to horzU
            W[i][j] = k * (U[i][j])          
        next
    next
    
return W    

//============================================
//============================================
// Bert Mariani 03/18/2023
// VectorAngle(U,V)
// VectorAngle =  u.v  / ||u||||v||
// DotProdut   = (u.v) / (U^2 x V^2)^1/2
// Return Angle Number  in Radians 0 < nbr < Pi

Func VectorAngle(U,V)

    vertU = len(U)    horzU = len(U[1])
    vertV = len(V)    horzV = len(V[1])

    if (vertU != vertV ) AND  (horzU != horzV) 
        See "Error: Scalar Square Dimension: "+ nl
        See "vertU != vertV "+ vertU +" "+ vertV +"MUST BE EQUAL "+ nl
        See "horzU != horzV "+ horzU +" "+ horzV +"MUST BE EQUAL "+ nl
        return 1
    ok

 W    = DotProduct(U,V)
 Wdot = W[1][1]            //  u.v
    
 SumU = 0
 for i = 1 to vertU
     for j = 1 to horzU
         nbr   = U[i][j]
         X     = nbr * nbr
         SumU += X
      next
 next
 
 SumV = 0
 for i = 1 to vertV
     for j = 1 to horzV
         nbr   = V[i][j]
         Y     = nbr * nbr
         SumV += Y
      next
 next
 
 Z     = SumU * SumV         // ||u|| * ||v||
 Zsqrt = sqrt(Z)             
 X     = Wdot / ZSqrt        // u.v /   ||u||||v||

 Angle = acos(X)             // aCos(X) => Radians 

return Angle


//============================================
//============================================
// Bert Mariani 03/18/2023
// CrossProduct(U,V)
// Cross Product of Vectors UxV => Vectot W
// Dimension 3x1 Only

Func CrossProduct(U,V)

    vertU = len(U)    horzU = len(U[1])
    vertV = len(V)    horzV = len(V[1])
        vertW = len(U)    horzW = len(V[1])
        W     = list(vertU, horzV) 
      
    if  (vertU !=3 AND vertV != 3)  AND (horzU != 1 AND horzV != 1)  
        See "Error: Cross Product Dimension: "+ nl
        See "horzU: "+ horzU +" horzV: "+ horzV +" MUST BE = 1 "+ nl
        See "vertU: "+ vertU +" vertV: "+ vertV +" MUST BE = 3 " +nl
        return 1
    ok 

    // Assign Letters for U x Y 

     ax = U[1][1]  ay = U[2][1]  az = U[3][1]
     bx = V[1][1]  by = V[2][1]  bz = V[3][1]
     cx = W[1][1]  cy = W[2][1]  cz = W[3][1]
 
     cx = ay*bz - az*by    // Determinants
     cy = az*bx - ax*bz
     cz = ax*by - ay*bx

     W =[[cx],[cy],[cz]]

return W

//============================================
//============================================
//=============================================
// Bert Mariani 03/18/2023
// MatrixCofactor(U)
// Return Matrix Adjoint
// Used by MatrixInverse  U ==> Uinv   
// 

Func MatrixCofactor(U)
    vertU = len(U)    horzU = len(U[1])    
    if  (vertU != horzU  )
        See "Error: Matrix Not Square Dimension: "+ nl
        See "vertU: "+ vertU +" horzU: "+ horzU +" MUST BE Equal "+ nl
        return 1
    ok 

    //Init-Start -------------------------------------------
    Udet   = Determinant(U)          
    if (Udet = 0)
        See "Error: Matrix can not be Inversed. Determinate 0: "+ Udet + nl
        MatrixPrint(U)
        return 1
    ok
 
    Uadj = U                                // CoFactors  returned ==> Uadj adjoint 3x3
    for Row = 1 to vertU
        for Col = 1 to horzU
            V = list(vertU-1, horzU-1)      // 3x3 => 2x2

            r=1                             // vert
            for i = 1 to vertU
                s = 1                       // horz
                for j = 1 to horzU
                    if (i != Row) AND (j != Col)    // Skip if Not this Row and Col     
                        num = U[i][j]
                        V[r][s] = num
                        s++
                    ok                                  
                next

                if (i != Row) AND (j != Col)
                   r++
                ok
            next  
                         
            CoFactor = Determinant(V)
            if (Row + Col) % 2              // SignFlip based on Row+Col if Odd
                Uadj[Row][Col] = -CoFactor 
            else
                Uadj[Row][Col] =  CoFactor
            ok
        next
    next
     
return Uadj

//===================================
// Bert Mariani 03/18/2023
// MatrixInverse(U)
// Returns Inverse Matrix U ==> Uinv

Func MatrixInverse(U)

    Udet     = Determinant(U)
    Uadjoint = MatrixCofactor(U)
    Utrans   = MatrixTrans(Uadjoint)             
    Uinv     = ScalarMultiply((1/Udet), Utrans) 
     
return Uinv

//=========================================================
//=========================================================
// Clear the DataResults Array 10x10 before 
// Calling MatrixDeterminantReduce(U) -- RECURSIVE Loop 

Func MatrixDetCalc(U)

     vertU = len(U)   horzU = len(U[1]) 
     
     if vertu > 10
        See "Handles Matrix up to 10x10"+nl
        return 1
     ok

     DetResults = [[],[],[],[],[],[],[],[],[],[]]  // 10x10 3628800 Combinations
     DetRet     = MatrixDeterminantReduce(U)

return DetRet

//============================================
//============================================
// Make the Matrix Smaller on each Recursive Loop
// 6x6 => 5x5 => 4x4 => 3x3 => 2x2 ==> U11xU22 - U12xU21
// N! 2x3x4x5x6..x10  ==> 6, 24, 120, 720, 7=5040, 8=40320, 9=362880, 10=3628800 Combinations

Func MatrixDeterminantReduce(U)
                  
    vertU = len(U)   horzU = len(U[1])     

    if vertU = 2 AND horzU = 2
       DetAdd = (U[1][1]*U[2][2]) - (U[1][2]*U[2][1])
       Add(DetResults[vertu], DetAdd)
       return DetAdd
    ok

    // For Matrix 3 to 10
    for Row = 1 to 1                            //vertU  Handle ONLY 1st Row                
        for Col = 1 to horzU 
            V = list(vertU-1, horzU-1)           
            if Row = 1                          // Top Row Only, Col 1-n
                r=1                             // vert
                for i = 1 to vertU 
                    s = 1                       // horz
                    for j = 1 to horzU
                        if (i != Row) AND (j != Col)    // Skip if Not this Row and Col                         
                           num = U[i][j]
                           V[r][s] = num
                           s++
                        ok                                  
                    next
                    if (i != Row) AND (j != Col)
                       r++
                    ok
                next          
                MatrixDeterminantReduce(V)   // <=== LOOP RECURSIVE with smaller array
             ok
        next    
    next        
    
    // See "Matrix: size: "+vertU +"-"+ horzU +nl
    
    DetAdd = 0
    for Row = 1 to 1
       for Col = 1 to horzU   
           Det = U[Row][Col] * DetResults[vertU-1][Col]
           if Col % 2   DetAdd += Det    // SignFlip
              else      DetAdd -= Det   
           ok    
       next
    next
    
    DetResults[vertU-1] = []          // <=== Clear Smaller Matrix determinants
    Add(DetResults[vertU], DetAdd)    // <=== Add Determinant to Current Matrix


return DetAdd   // Return calculated Determinant for this size Matrx

//===========================
