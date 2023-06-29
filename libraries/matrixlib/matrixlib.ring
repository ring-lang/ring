// Bert Mariani 2023/04/03
// MATRIX FUNCTIONS
//
//  1 MatrixMulti(A,B)            // Exists, aka MatrixMultiply(U,V)
//  2 MatrixTrans(A)              // Exists, aka MatrixTranspose(U)
//  3 MatrixPrint(U)
//  4 MatrixFlatPrint(U)
//  5 DotProduct(U,V)
//  6 MatrixAdd(U,V)
//  7 MatrixSub(U,V)
//  8 ScalarMultiply(k,U)
//  9 VectorAngle(U,V)
// 10 CrossProduct(U,V)
// 11 MatrixCofactor(U)
// 12 MatrixAdjoint(U)
// 13 MatrixInverse(U)
// 14 MatrixDetCalc(U)             // Calls MatrixDeterminantReduce(U)
// 15 MatrixDeterminantReduce(U)   // Any 2x2 to 10x10 Recursive
// 16 Determinant(U)               // Calls 16a-16e Determinant2x2,3x3,4x4,5x5,6x6
// 17 MatrixProjection(U,V)        // ProjvU = (U.V)/(V.V)xV
// 18 MatrixOrthoDistance(U,V)
// 19 VectorLength(U)
// 20 VectorNorm(U)                // Same as VectorLength - different name
// 21 VectorUnit(U)                // Vector Norm to a Unit Matrix
// 22 VectorDistance(U,V)
// 23 MatricOrthoNormal2(U,V)      // Gram-Schmidt method for 2 Vectors in R2 Space
// 24 MatrixOrthoNormal3(V1,V2,V3) // Gram-Schmidt method for 3 Vectors in R3 Space
// 25 MatrixLuDecompose(U)         // LU Decompose Matrix to Lower and Upper Matrix
// 26 SyntheticFactor(Eq)          // Find Factors of Quartric Equation
// 27 SyntheticDiv(Eq,Factors)     // Synthetic Division using Factors to try possible solutions the Quartic equation
// 28 QuadSolve(Eq)                // Quadratric equation solve format x^2 + x + c
// 29 CubicSolve(Eq)               // Cubic equation solve format x^3 + x^2 + x + c
// 30 QuarticSolve(Eq)             // Solve Quartic equation format x^4 + x^3 + x^2 + x + c
// 31 QuinticSolve(Eq)             // Solve Quintic equation format x^5 x^4 + x^3 + x^2 + x + c
// 32 EigenValue2(A)               // EigenValues calculated for a 2x2 matrix
// 33 EigenValue3(A)               // EigenValues calculated for a 3x3 matrix
// 34 PolyMultiply(A,B)            // Polynomial Multiple [A]*[B] ascending powers left to right
// 35 PolyAdd(A,B)                 // Polynomial Add [A]+[B] ascending powers left to right
// 35 PolySub(A,B)                 // Polynomial Subtract [A]-[B] ascending powers left to right
// 36 CharEquation(N)              // Characteristic Polynomial of 4x4 Matrix [A - λI] format -12 -44x -46x2 -10x3 +x4
// 37 EigenValue4(N)               // Finf EigenValues for a 4x4 matrix

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
 Row = len(U)     See " "+ Row      // Rows 
 Col = len(U[1])  See "x"+ Col +nl  // Cols 
                           
 for h = 1 to Row
   See "| "
   for v = 1 to Col
     Num = U[h][v]
     if (Num >= 0) See " " ok       // 2 places
     See Num  
     if v != Col   See "," ok       // Comma between numbers
   next
   See " |"+nl
 next
   See nl
   
return

//=============================================
// Bert Mariani 03/18/2023
// MatrixFlatPrint(U)
// Display a Matrix Array by Row and Col size

Func MatrixFlatPrint(U)

 See "      MatrixFlatPrint:"
 Row = len(U)     See " "+ Row +nl   // Row 

 for h = 1 to Row
    See " "+ U[h] +","
 next
   See nl+nl

return
//============================================
//============================================
// Alternate Name

Func MatrixMultiply(U,V)
     W = MatrixMulti(U,V)
return W

Func MatrixTranspose(U)
     W = MatrixTrans(U)
return W

//============================================
//============================================
// Bert Mariani 03/18/2023
// DotProduct(U,V)
// Dot Product of Vectors U.V => Scalar  UtxV
// U.V = Ut.V  Horz = 1 both  Vert = same on both

Func DotProduct(U,V)

    vertU = len(U)    horzU = len(U[1])
    vertV = len(V)    horzV = len(V[1])

      
    if (horzU != 1 OR horzV != 1) OR  (vertU != vertV) 
        See "Error: Dot Product Dimension: "+ nl
        See "horzU: "+ horzU +" horzV: "+ horzV +" MUST BE = 1 "+ nl
        See "vertU: "+ vertU +" vertV: "+ vertV +" MUST BE EQUAL " +nl
        return 1
    ok 

//Alternative 
//  Ut = MatrixTrans(U)
//  DP = MatrixMulti(Ut,V)
//  Distance = DP[1][1]
 

    Sum = 0
    for i = 1 to vertU
        product  = U[i][1] * V[i][1]
        Sum += product
    next
    Distance = Sum

return Distance   // Scalar number


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
      
    if  (vertU != vertV) OR (horzU != horzV )
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
      
    if  (vertU != vertV) OR (horzU != horzV )
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
// Return Angle Number  in Radians 0 < nbr < Pi => Degrees

Func VectorAngle(U,V)

    vertU = len(U)    horzU = len(U[1])
    vertV = len(V)    horzV = len(V[1])

    if (vertU != vertV ) OR  (horzU != horzV) 
        See "Error: Scalar Square Dimension: "+ nl
        See "vertU != vertV "+ vertU +" "+ vertV +"MUST BE EQUAL "+ nl
        See "horzU != horzV "+ horzU +" "+ horzV +"MUST BE EQUAL "+ nl
        return 1
    ok

 W    = DotProduct(U,V)
 Wdot = W               //  u.v DotProduct
    
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
 
 Z     = SumU * SumV         // ||u||||v||  magnitude
 Zsqrt = sqrt(Z)             
 X     = Wdot / ZSqrt          // u.v / ||u||||v||

 Radians = acos(X)             // aCos(X) => Radians 
 Degrees = Radians * 180 / PI

return Degrees                 // Angle in Degrees


//============================================
//============================================
// Bert Mariani 03/18/2023
// CrossProduct(U,V)
// Cross Product of Vectors in R3 Space Only, UxV => Vector W
// Dimension 3x1 Only

Func CrossProduct(U,V)

    vertU = len(U)    horzU = len(U[1])
    vertV = len(V)    horzV = len(V[1])
    vertW = len(U)    horzW = len(V[1])
    W     = list(vertU, horzV) 
      
    if  (vertU !=3 OR vertV != 3)  OR (horzU != 1 OR horzV != 1)  
        See "Error: Cross Product Dimension in R3 Space Only: "+ nl
                See "horzU: "+ horzU +" horzV: "+ horzV +" MUST BE = 1 "+ nl
                See "vertU: "+ vertU +" vertV: "+ vertV +" MUST BE = 3 " +nl
        return 1
    ok 

 // Assign Letters for U x Y 
 //  i             j             k
     ax = U[1][1]  ay = U[2][1]  az = U[3][1] 
     bx = V[1][1]  by = V[2][1]  bz = V[3][1] 
                                              
     ix = ay*bz - by*az    // Determinants
     jy = ax*bz - bx*az
     kz = ax*by - bx*ay

     W =[[ix],[-jy],[kz]]   // FlipSign + - +

return W


//============================================
//============================================
//=============================================
// Bert Mariani 03/18/2023
// MatrixCofactor(U)
// Return Matrix Adjoint
//        Used by MatrixInverse  U ==> Uinv   
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
 
    Ucof = U                                // CoFactors  returned ==> Ucof adjoint 3x3
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
                Ucof[Row][Col] = -CoFactor 
            else
                Ucof[Row][Col] =  CoFactor
            ok
        next
    next
     
return Ucof

//============================================
//=============================================
// Bert Mariani 03/18/2023
// MatrixAdjoint(U)
// Return Matrix Adjoint
//        Used by MatrixInverse  U ==> Uinv   
// 

Func MatrixAdjoint(U)
    vertU = len(U)    horzU = len(U[1])    
    if  (vertU != horzU  )
        See "Error: Matrix Not Square Dimension: "+ nl
        See "vertU: "+ vertU +" horzU: "+ horzU +" MUST BE Equal "+ nl
        return 1
    ok 
    
    CoF  = MatrixCoFactor(U)
    Uadj = MatrixTrans(CoF)
    
return Uadj   // Martix - Adjoint

//===================================
// Bert Mariani 03/18/2023
// MatrixInverse(U)
// Returns Inverse Matrix U ==> Uinv

Func MatrixInverse(U)

    vertU = len(U)    horzU = len(U[1])
    
    // 2x2 Special Case
    if(vertU = 2 AND horzU = 2 )    
       // Assign lettes a-i to matrix Orig-U
       a1 = U[1][1]  a2 = U[1][2]  
       b1 = U[2][1]  b2 = U[2][2] 
       
       //FlipPosition a1<->b2, FlipSign a2, b2
       U[1][1] =  b2   U[1][2] = -a2 
       U[2][1] = -b1   U[2][2] =  a1

       Det  = a1*b2 - a2*b1       // Determinate Cross multiply  
       if Det = 0                 // Inverse not possible
          return 1                // Error, flag as 1
       ok
       
       Uinv = ScalarMultiply(1/Det, U)
    
    else
      //Udet     = Determinant(U)
        Udet     = MatrixDetCalc(U) 
        Uadjoint = MatrixCofactor(U)
        Utrans   = MatrixTrans(Uadjoint)   
        Uinv     = ScalarMultiply((1/Udet), Utrans) 
    ok
     
return Uinv

//=========================================================
//=========================================================
// Clear the DataResults Array 10x10 before 
// Calling MatrixDeterminantReduce(U) -- RECURSIVE Loop 


Func MatrixDetCalc(U)

     vertU = len(U)   horzU = len(U[1]) 
     
     if vertu > 12
        See "Handles Matrix up to 12x12"+nl
        return 1
     ok

     DetResults = [[],[],[],[],[],[],[],[],[],[],[],[]]  // 10x10 3628800 Combinations
     DetRet     = MatrixDeterminantReduce(U)             // <=== CALL Recursive

return DetRet

//============================================
//============================================
// Make the Matrix Smaller on each Recursive Loop
// 6x6 => 5x5 => 4x4 => 3x3 => 2x2 ==> U11xU22 - U12xU21
// N! 2x3x4x5x6..x10  ==> 6, 24, 120, 720, 7=5040, 8=40320, 9=362880, 10=3628800 Combinations

Func MatrixDeterminantReduce(U)
                  
    vertU = len(U)   horzU = len(U[1])     

    if vertU = 1 AND horzU = 1
       return 1
    ok
    
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

//=====================================
//=====================================
// Bert Mariani 03/18/2023
// MatrixProjection
// ProjvU = (U.V)/(V.V)xV
//
//  (4,2).(3,4)/(3,4).(3.4) x(3,4)
//   12+8      / 9+16       x(3,4)
// = 20        / 25         x(3,4) 
// = 20/25 x(3,4)
// =  4/5  x(3,4) 
// = 12/5, 16/5
// =  2.4 ,  3.2

Func MatrixProjection(U,V)

    vertU = len(U)    horzU = len(U[1])
    vertV = len(V)    horzV = len(V[1])

      
    if (horzU != horzV ) OR  (vertU != vertV) 
        See "Error: MatricProjection Dimension: "+ nl
        See "horzU: "+ horzU +" horzV: "+ horzV +" MUST BE EQUAL " +nl
        See "vertU: "+ vertU +" vertV: "+ vertV +" MUST BE EQUAL " +nl
        return 1
    ok 

  p = DotProduct(U,V)
  q = DotProduct(V,V)


  Y = ScalarMultiply( (p/q), V)

return Y   // Vector array

//============================================
//============================================
// Bert Mariani 03/18/2023
// MatricOrthoDistance(U,V)
// Ortho-Projection and Distance
// Returns a Distance Vector between MatrixProjection(U,V) 

Func MatrixOrthoDistance(U,V)

    Y     = MatrixProjection(U,V)
    Ortho = MatrixSub(U,Y)

return Ortho  // Distance Vector between projection U

//============================================
//============================================

//-------------------------------------------------
// Bert Mariani 03/18/2023
// Determine Matrix Call Dertinants from 2x2 to 6x6    
// Call Determinant(U)

Func Determinant(U)

    vertU = len(U)    horzU = len(U[1])

    if vertU != horzU
        See "Error: Matrix Dimension: "+vertU +"x"+ horxU nl
        See "VertU: "+ vertU +" HorzU: "+ horzU +" MUST BE Equal "+ nl
        MatrixPrint(U)
        return 1
    OK
    
    if    (vertU = 1 AND horzU = 1  )
        return 1
    ok
 
    if    (vertU = 2 AND horzU = 2 )
        Det = Determinant2(U)

    elseif(vertU = 3 AND horzU = 3 )
        Det = Determinant3(U)

    elseif(vertU = 4 AND horzU = 4 )
        Det = Determinant4(U)

    elseif(vertU = 5 AND horzU = 5 )
        Det = Determinant5(U)

    elseif(vertU = 6 AND horzU = 6 )
        Det = Determinant6(U)
    else
        See "Curently support only upto 6x6 Matrix"+ nl
        MatrixPrint(U)
        return 1
    ok 

return Det

//============================================
// Bert Mariani 03/18/2023
// Determinant2(U)     
// Dimension 2x2 matrix Only

Func Determinant2(U)

   vertU = len(U)    horzU = len(U[1])

    if vertU != horzU
        See "Error: Matrix Dimension: "+vertU +"x"+ horxU nl
        See "VertU: "+ vertU +" HorzU: "+ horzU +" MUST BE Equal "+ nl
        MatrixPrint(U)
        return 1
    OK
      
   // Assign lettes a-i to matrix Orig-U
   a1 = U[1][1]  a2 = U[1][2]  
   b1 = U[2][1]  b2 = U[2][2] 

   //Determinat of U and flip sign + - +
   DetP = (a1 * b2)         
   DetQ = (a2 * b1)                     

   Det  = (DetP) - (DetQ)       // FlipSigns 

   //See "DetP : "+  DetP  +" "+ DetQ +nl   
   //See "RowA1: "+ a1 +"*"+b2 +" - "+a2 +"*"+b1  +" ==> "+Det +nl
   //See "CofA1: "+ (DetP) +" "+ -(DetQ) +" ==> Det: "+Det +nl+nl

   if (Det) = 0
       //See "Return: Determinant 2x2 Dimension 0: = "+ Det + nl
       return Det
   ok

return Det



//============================================
//============================================
// Bert Mariani 03/18/2023
// Determinant3(U)     
// Calls SubMatrix for Determinate2 2x2 

Func Determinant3(U)

    vertU = len(U)    horzU = len(U[1])
      
    if vertU != horzU
        See "Error: Matrix Dimension: "+vertU +"x"+ horxU nl
        See "VertU: "+ vertU +" HorzU: "+ horzU +" MUST BE Equal "+ nl
        MatrixPrint(U)
        return 1
    OK

   // Assign lettes a-i to matrix Orig-U
       a1 = U[1][1]  a2 = U[1][2]  a3 = U[1][3]
       b1 = U[2][1]  b2 = U[2][2]  b3 = U[2][3]
       c1 = U[3][1]  c2 = U[3][2]  c3 = U[3][3]
               
       P = [[b2, b3],   // a1
            [c2, c3]] 
    
       Q = [[b1, b3],   // a2
            [c1, c3]] 

       R = [[b1, b2],   // a3
            [c1, c2]]  

       DetP = Determinant2(P)    //See "Call 2x2 P "+nl  MatrixPrint(P)  See "DetP: "+DetP +" <======"+nl
       DetQ = Determinant2(Q)    //See "Call 2x2 Q "+nl  MatrixPrint(Q)  See "DetQ: "+DetQ +" <======"+nl
       DetR = Determinant2(R)    //See "Call 2x2 R "+nl  MatrixPrint(R)  See "DetR: "+DetR +" <======"+nl
        
       Det  = (a1 * DetP) - (a2 * DetQ) + (a3 * DetR)       // SignFlip +a1 -a2 +a3 -a4

       //See "DetP "+ DetP +" Q "+ DetQ +" R "+ DetR  +nl   
       //See "a1: "+a1 +" "+a2  +" "+a3 +nl
       //See "Ca1: "+ ( a1 * DetP) +" "+ -(a2 * DetQ) +" "+ ( a3 * DetR) +" => Det: "+Det +nl+nl

       if (Det) = 0
          //See "Return: Matrix 3X3 Determinant 0: = "+ Det + nl
          return Det
       ok  

return Det

//============================================
//============================================
// Bert Mariani 03/18/2023
// Determinant4(U)     
// Calls SubMatrix for Determinate3 3x3

Func Determinant4(U)

    vertU = len(U)    horzU = len(U[1])

    if vertU != horzU
        See "Error: Matrix Dimension: "+vertU +"x"+ horxU nl
        See "VertU: "+ vertU +" HorzU: "+ horzU +" MUST BE Equal "+ nl
        MatrixPrint(U)
        return 1
    OK

      //=====================
      // Assign Letters
 
       a1 = U[1][1]  a2 = U[1][2]  a3 = U[1][3]  a4 = U[1][4]
       b1 = U[2][1]  b2 = U[2][2]  b3 = U[2][3]  b4 = U[2][4]
       c1 = U[3][1]  c2 = U[3][2]  c3 = U[3][3]  c4 = U[3][4]
       d1 = U[4][1]  d2 = U[4][2]  d3 = U[4][3]  d4 = U[4][4]

       P = [[b2, b3, b4],  // a1
            [c2, c3, c4], 
            [d2, d3, d4]]
             
       Q = [[b1, b3, b4],  // a2   
            [c1, c3, c4],
            [d1, d3, d4]]
       
       R = [[b1, b2, b4],  // a3
            [c1, c2, c4],      
            [d1, d2, d4]]
       
       S = [[b1, b2, b3],  // a4
            [c1, c2, c3],  
            [d1, d2, d3]]

       DetP = Determinant3(P)    //See "Call 3x3 P "+nl  MatrixPrint(P)  See "DetP: "+DetP +" <======"+nl+nl
       DetQ = Determinant3(Q)    //See "Call 3x3 Q "+nl  MatrixPrint(Q)  See "DetQ: "+DetQ +" <======"+nl+nl
       DetR = Determinant3(R)    //See "Call 3x3 R "+nl  MatrixPrint(R)  See "DetR: "+DetR +" <======"+nl+nl
       DetS = Determinant3(S)    //See "Call 3x3 S "+nl  MatrixPrint(S)  See "DetS: "+DetS +" <======"+nl+nl
  
       Det  = (a1 * DetP) - (a2 * DetQ) + (a3 * DetR) - (a4 * DetS)      // SignFlip +a1 -a2 +a3 -a4

       //See "DetP:  "+ DetP +" "+ DetQ +" "+ DetR +" "+ DetS +nl   
       //See "RowA1: "+ a1 +" "+a2 +" "+a3 +" "+a4 +nl
       //See "CofA1: "+ ( a1 * DetP) +" "+ -(a2 * DetQ) +" "+ ( a3 * DetR) +" "+ -(a4 * DetS) +" => Det: "+Det +nl+nl

       if (Det) = 0
          //See "Return: Matrix 4x4 Determinant 0: = "+ Det + nl
          return Det
       ok                       

return Det

//============================================
//============================================
// Bert Mariani 03/18/2023
// Determinant5(U)     
// Calls SubMatrix for Determinate4 4x4


Func Determinant5(U)

    vertU = len(U)    horzU = len(U[1])
      
    if vertU != horzU
        See "Error: Matrix Dimension: "+vertU +"x"+ horxU nl
        See "VertU: "+ vertU +" HorzU: "+ horzU +" MUST BE Equal "+ nl
        MatrixPrint(U)
        return 1
    OK

      //=====================
      // Assign Letters
 
       a1 = U[1][1]  a2 = U[1][2]  a3 = U[1][3]  a4 = U[1][4]  a5 = U[1][5]
       b1 = U[2][1]  b2 = U[2][2]  b3 = U[2][3]  b4 = U[2][4]  b5 = U[2][5]
       c1 = U[3][1]  c2 = U[3][2]  c3 = U[3][3]  c4 = U[3][4]  c5 = U[3][5]
       d1 = U[4][1]  d2 = U[4][2]  d3 = U[4][3]  d4 = U[4][4]  d5 = U[4][5]
       e1 = U[5][1]  e2 = U[5][2]  e3 = U[5][3]  e4 = U[5][4]  e5 = U[5][5]
   
       P = [[b2, b3, b4, b5],  // a1
            [c2, c3, c4, c5], 
            [d2, d3, d4, d5], 
            [e2, e3, e4, e5]] 
                 
       Q = [[b1, b3, b4, b5],  // a2
            [c1, c3, c4, c5], 
            [d1, d3, d4, d5], 
            [e1, e3, e4, e5]] 
       
       R = [[b1, b2, b4, b5],  // a3 
            [c1, c2, c4, c5], 
            [d1, d2, d4, d5], 
            [e1, e2, e4, e5]] 
       
       S = [[b1, b2, b3, b5],  // a4
            [c1, c2, c3, c5], 
            [d1, d2, d3, d5], 
            [e1, e2, e3, e5]] 
            
       T = [[b1, b2, b3, b4],  // a5 
            [c1, c2, c3, c4],   
            [d1, d2, d3, d4],   
            [e1, e2, e3, e4]]   


       DetP = Determinant4(P)    //See "Call 4x4 P "+nl  MatrixPrint(P)  See "DetP: "+DetP +" <======"+nl+nl
       DetQ = Determinant4(Q)    //See "Call 4x4 Q "+nl  MatrixPrint(Q)  See "DetQ: "+DetQ +" <======"+nl+nl
       DetR = Determinant4(R)    //See "Call 4x4 R "+nl  MatrixPrint(R)  See "DetR: "+DetR +" <======"+nl+nl
       DetS = Determinant4(S)    //See "Call 4x4 S "+nl  MatrixPrint(S)  See "DetS: "+DetS +" <======"+nl+nl
       DetT = Determinant4(T)    //See "Call 4x4 T "+nl  MatrixPrint(T)  See "DetT: "+DetT +" <======"+nl+nl
       
       Det  = (a1 * DetP) - (a2 * DetQ) + (a3 * DetR) - (a4 * DetS) + (a5 * DetT)      // SignFlip +a1 -a2 +a3 -a4 +a5

       //See "DetP:  "+ DetP +" "+ DetQ +" "+ DetR +" "+ DetS +" "+ DetT +nl   
       //See "RowA1: "+ a1 +" "+a2 +" "+a3 +" "+a4 +" "+a5 +nl
       //See "CofA1: "+ (a1 * DetP) +" "+ -(a2 * DetQ) +" "+ (a3 * DetR) +" "+ -(a4 * DetS) +" "+ (a5 * DetT) +" => Det: "+Det +nl+nl

       if (Det) = 0
          //See "Return: Matrix 5x5 Determinant 0: = "+ Det + nl
          return Det
       ok                       

return Det

//============================================
//============================================
// Bert Mariani 03/18/2023
// Determinant6(U)     
// Calls SubMatrix for Determinate5 5x5 


Func Determinant6(U)

    vertU = len(U)    horzU = len(U[1])

    if vertU != horzU
        See "Error: Matrix Dimension: "+vertU +"x"+ horxU nl
        See "VertU: "+ vertU +" HorzU: "+ horzU +" MUST BE Equal "+ nl
        MatrixPrint(U)
        return 1
    OK
       
      //=====================
      // Assign Letters
 
       a1 = U[1][1]  a2 = U[1][2]  a3 = U[1][3]  a4 = U[1][4]  a5 = U[1][5]  a6 = U[1][6]
       b1 = U[2][1]  b2 = U[2][2]  b3 = U[2][3]  b4 = U[2][4]  b5 = U[2][5]  b6 = U[2][6]
       c1 = U[3][1]  c2 = U[3][2]  c3 = U[3][3]  c4 = U[3][4]  c5 = U[3][5]  c6 = U[3][6]
       d1 = U[4][1]  d2 = U[4][2]  d3 = U[4][3]  d4 = U[4][4]  d5 = U[4][5]  d6 = U[4][6]
       e1 = U[5][1]  e2 = U[5][2]  e3 = U[5][3]  e4 = U[5][4]  e5 = U[5][5]  e6 = U[5][6]
       f1 = U[6][1]  f2 = U[6][2]  f3 = U[6][3]  f4 = U[6][4]  f5 = U[6][5]  f6 = U[6][6]
       
       P = [[b2, b3, b4, b5, b6],  // a1
            [c2, c3, c4, c5, c6], 
            [d2, d3, d4, d5, d6], 
            [e2, e3, e4, e5, e6], 
            [f2, f3, f4, f5, f6]] 
                              
       Q = [[b1, b3, b4, b5, b6],  // a2
            [c1, c3, c4, c5, c6], 
            [d1, d3, d4, d5, d6], 
            [e1, e3, e4, e5, e6], 
            [f1, f3, f4, f5, f6]]
                              
       R = [[b1, b2, b4, b5, b6],  // a3  
            [c1, c2, c4, c5, c6], 
            [d1, d2, d4, d5, d6], 
            [e1, e2, e4, e5, e6], 
            [f1, f2, f4, f5, f6]]
                              
       S = [[b1, b2, b3, b5, b6],  // a4
            [c1, c2, c3, c5, c6], 
            [d1, d2, d3, d5, d6], 
            [e1, e2, e3, e5, e6],
            [f1, f2, f3, f5, f6]]           
                           
       T = [[b1, b2, b3, b4, b6],  // a5 
            [c1, c2, c3, c4, c6],   
            [d1, d2, d3, d4, d6],   
            [e1, e2, e3, e4, e6], 
            [f1, f2, f3, f4, f6]]           
            
       V = [[b1, b2, b3, b4, b5],  // a6  
            [c1, c2, c3, c4, c5],   
            [d1, d2, d3, d4, d5],   
            [e1, e2, e3, e4, e5],
            [f1, f2, f3, f4, f5]]           
                  

       DetP = Determinant5(P)    //See "Call 5x5 P "+nl  MatrixPrint(P)  See "DetP: "+DetP +" <======"+nl+nl
       DetQ = Determinant5(Q)    //See "Call 5x5 Q "+nl  MatrixPrint(Q)  See "DetQ: "+DetQ +" <======"+nl+nl
       DetR = Determinant5(R)    //See "Call 5x5 R "+nl  MatrixPrint(R)  See "DetR: "+DetR +" <======"+nl+nl
       DetS = Determinant5(S)    //See "Call 5x5 S "+nl  MatrixPrint(S)  See "DetS: "+DetS +" <======"+nl+nl
       DetT = Determinant5(T)    //See "Call 5x5 T "+nl  MatrixPrint(T)  See "DetT: "+DetT +" <======"+nl+nl
       DetV = Determinant5(V)    //See "Call 5x5 T "+nl  MatrixPrint(V)  See "DetV: "+DetV +" <======"+nl+nl
       
       Det  = (a1 * DetP) - (a2 * DetQ) + (a3 * DetR) - (a4 * DetS) + (a5 * DetT) - (a6 * DetV)      // SignFlip +a1 -a2 +a3 -a4 +a5

       //See "DetP:  "+ DetP +" "+ DetQ +" "+ DetR +" "+ DetS +" "+ DetT +" "+ DetV +nl   
       //See "RowA1: "+ a1 +" "+ a2 +" "+ a3 +" "+ a4 +" "+ a5 +" "+ a6 +nl
       //See "CofA1: "+ (a1 * DetP) +" "+ -(a2 * DetQ) +" "+ ( a3 * DetR) +" "+ -(a4 * DetS) +" "+ (a5 * DetT) +" "+ -(a6 * DetV)+" => Det: "+Det +nl+nl

       if (Det) = 0
          //See "Return: Matrix 6x6 Determinant 0: = "+ Det + nl
          return Det
       ok                       

return Det


//============================================
//============================================
// Bert Mariani 03/18/2023
// VectorLength(U)
// VectorNorm(U)
//
// Length of a Vector
// ||U|| = Sqrt(Sums squared)

// AlternateNAme
Func VectorNorm(U)
     Norm = VectorLength(U)
return Norm
     
//-------------------    
Func VectorLength(U)

    vertU = len(U)    horzU = len(U[1])
  
    if (horzU != 1 ) 
        See "Error: VectorLength Dimension: "+ nl
        See "horzU: "+ horzU +" MUST BE = 1 "+ nl
        return 1
    ok 

    Sum = 0
    for i = 1 to vertU
          a  = U[i][1]
        Sum += a*a
    next

    Length = sqrt(Sum)

return Length   // Length of Vector U

//============================================
//============================================
// Bert Mariani 03/18/2023
// VectorUnit(U)
// Vector components / Length of a Vector
// Length ||U|| = Sqrt(Sums squared)
// U / ||U||


Func VectorUnit(U)

    vertU = len(U)    horzU = len(U[1])
  
    if (horzU != 1 ) 
        See "Error: VectorUnit Dimension: "+ nl
        See "horzU: "+ horzU +" MUST BE = 1 "+ nl
        return 1
    ok 

    Length = VectorLength(U)
    
    V = ScalarMultiply( 1/Length, U)
    
return V   // Unit Vector of U

//============================================
//============================================

//--------------------------------------
// Distance between 2 Vectors
// D = Sqrt( Sum ((Ui-Vi)Squared)
// D = ||U - V||  = Sqrt( Sum(Ui-Vi"squared

Func VectorDistance(U,V)

    vertU = len(U)   horzU = len(U[1])
    vertV = len(V)   horzV = len(V[1])
    
    if (horzU != 1 OR horzV != 1) OR  (vertU != vertV) 
        See "Error: Matrix VectorDistance Dimension: "+ nl
        See "horzU: "+ horzU +" horzV: "+ horzV +" MUST BE = 1 "+ nl
        See "vertU: "+ vertU +" vertV: "+ vertV +" MUST BE EQUAL " +nl
        return 1
    ok

    W  = MatrixSub(U,V)

    Sum = 0
    for i = 1 to vertU
        a  = W[i][1]
        Sum += a*a
    next

    Distance = sqrt(Sum)

return Distance  // Distance bewteen 2 Vectors

//============================================
//============================================
// Bert Mariani 03/18/2023
// MatrixOrthoNormal2(U,V)
// Apply Garm=Schmidt Ortho-Normalized in R2 Space
//  

Func MatrixOrthoNormal2(V1,V2)

    vertU = len(V1)   horzU = len(V1[1])
    vertV = len(V2)   horzV = len(V2[1])
    
    if (horzU != 1 OR horzV != 1) OR  (vertU != vertV) 
        See "Error: Matrix OrthoNormal2 Dimension: "+ nl
        See "horzU: "+ horzU +" horzV: "+ horzV +" MUST BE = 1 "+ nl
        See "vertU: "+ vertU +" vertV: "+ vertV +" MUST BE EQUAL " +nl
        return 1
    ok
    
    // Basis  = { V1, V2}  ex. {(1,1),(0,1)
    //
    //   w1 = v1
    //              |v2.w1|  
    //   w2 = v2 - ---------  W1
    //              |w1.w1|
    //
    //---------------------------
    // OrthoNormalization

    W1 = V1
    W2 = MatrixSub( V2, MatrixProjection(V2,W1))

    //------------------------
    // Normalize Each Vector
    //         w1
    // u1 = --------
    //       ||w2||

    U1 =  ScalarMultiply( (1/VectorNorm(w1)), W1 )
    U2 =  ScalarMultiply( (1/VectorNorm(w2)), W2 )

    U1t = MatrixTranspose(U1)
    U2t = MatrixTranspose(U2)

    U3 = list(2, len(U1))        // Number of Vectors, Width of U1 (Depth)
    for i = 1 to len(U1)         // U3 Combo U1,U2  Matrix 2x2
        U3[1][i] = U1t[1][i]     // |  0.71, 0.71 |
        U3[2][i] = U2t[1][i]     // | -0.71, 0.71 |
    next

return U3  // OrthoNormalized U3 = U1,U2 Combo

//============================================
//============================================
// Bert Mariani 03/18/2023
// MatrixOrthoNormal3(V1,V2,V3)
// Apply Garm=Schmidt Ortho-Normalized in R3 Space
//
 
Func MatrixOrthoNormal3(V1,V2,V3)

    vertU = len(V1)   horzU = len(V1[1])
    vertV = len(V2)   horzV = len(V2[1])
    vertW = len(V3)   horzW = len(V3[1])
    
    if (horzU != 1 OR horzV != 1 OR horzV != 1) OR  (vertU != vertV OR vertU != vertW ) 
        See "Error: OrthoNormal3 Dimension: "+ nl
        See "horzU: "+ horzU +" horzV: "+ horzV +" MUST BE = 1 "+ nl
        See "vertU: "+ vertU +" vertV: "+ vertV +" MUST BE EQUAL " +nl
    ok 
      
    // Basis  = { V1, V2, V3}
    //
    //   w1 = v1
    //
    //              |v2.w1|  
    //   w2 = v2 - --------- W1
    //              |w1.w1|
    //
    //              |v3.w1|        |v3.w2|
    //   w3 = v3 - --------- W1 - --------- w2
    //              |w1.w1|         w2.w2
    //
    //---------------------------
    // OrthoNormalization

    W1  = V1

    W2p = MatrixProjection(V2,W1)
    W2  = MatrixSub(V2,W2p)

    W3p = MatrixProjection(V3,W1)
    W3q = MatrixProjection(V3,W2)

    W31 = MatrixSub(V3, W3p)
    W3  = MatrixSub(W31,W3q)

    //------------------------
    // Normalize Each Vector
    //         w1
    // u1 = --------
    //       ||w2||

    U1 =  ScalarMultiply( (1/VectorNorm(W1)), W1 )
    U2 =  ScalarMultiply( (1/VectorNorm(W2)), W2 )
    U3 =  ScalarMultiply( (1/VectorNorm(W3)), W3 )

    U1t = MatrixTranspose(U1)
    U2t = MatrixTranspose(U2)
    U3t = MatrixTranspose(U3)
    
    U4 = list(3, len(U1))       // Number of Vectors, Width(Depth) of Vector
    for i = 1 to len(U1)
        U4[1][i] = U1t[1][i]
        U4[2][i] = U2t[1][i]
        U4[3][i] = U3t[1][i]
    next

return U4  // OrthoNormalized U4 = U1,U2,U3 Combo

//============================================
//============================================
//========================================
// Bert Mariani 2023-05-30
// Quadratic Equation Solve => aX^2 + bX^1 + c
// Return 3x1 array-S
// x = ( -b +- (sqrt(b*b -4ac) ) ) / 2*a

Func QuadSolve(Eq)

   S = list(2,1)   // Row Column

   a  = Eq[1][1]
   b  = Eq[1][2]
   c  = Eq[1][3] 

   sq1 = sqrt( (b*b) - (4*a*c) ) 

   x1  = (-b + sq1 ) / (2*a)
   x2  = (-b - sq1 ) / (2*a)

   S[1][1] = x1
   S[2][1] = x2

return S  // Row-Col  1x2


//=================================================
// Cubic Equation Solve => aX^3 + bX^2 + cX^1 + d
// Return 3x1 array-S
// Alogorithm
// Bert Mariani 2023-05-30

Func CubicSolve(Eq)

   S = list(3,1)  // Row-Column

   a  = Eq[1][1]  //   2
   b  = Eq[1][2]  //   1
   c  = Eq[1][3]  // -13
   d  = Eq[1][4]  //   6
   
   // ERROR can NOT SOLVE Cubic eqaution that  ends with Zer0
   if (d = 0)                 // 4x3 +5x2  -x +0 => Can NOT solve
      
      quad = [[a,b,c]]      // drop last term
      QS   = QuadSolve(cube)
 
      S[1][1] = 0          // Insert 0 solution
      S[2][1] = QS[1][1]   // Insert Cubic solution
      S[3][1] = QS[2][1]

      return S   //  Matrix 3x1
   ok

   P = []         // d = 1..6
   Q = []         // a = 1..2
   R = []         // P/Q
   T = []         // +-R
//----------

   for i = 1 to fabs(d)
       if !(fabs(d) % i)       // Possible factors of D -> P
         Add(P,i)
       ok
   next
//----------

   for i = 1 to fabs(a)
       if !(fabs(a) % i)       // Possible factors of A -> Q
         Add(Q,i)
       ok
   next
//----------

   for k = 1 to len(P)         // R = Add all P factors
       Add(R,P[k])
   next 
//----------

   for k = 1 to len(Q)         // R = Add all unique Q factors
       found = Find(P,Q[k])
       if !found
          Add(R,P[k])
       ok
   next
//----------

   for m = 1 to len(Q)
      for k = 1 to len(P)

          nbr = P[k] / Q[m]    // R = Add all P/Q factors
          found = Find(P,nbr)
          if !found
             Add(R,nbr)
          ok
      next
   next
//-------------------

   for k = 1 to len(R)        // T = +- R factors
       posNbr =  R[k]         // Final possible list-T
       negNbr = -R[k]
       Add(T,posNbr)
       Add(T,negNbr)
   next

//------------------------
// Synthetic Division
// Factor a Cubic Equation to a Quadratic Equation
// Try possible solution of X in T[]
//
// T = list of possible solutions to try as X
// X   a  b    c  d
// 2 | 2  1  -13  6   row1
//   | v  4   10      mul   X*row2
//     2  5   -3      row2  add col

for i = 1 to len(T)
   X = T[i]
   a2    = a

   mb    = X * a2
   b2    = b + mb

   mc    = X * b2
   c2    = c + mc

   md    = X * c2
   d2    = d + md

   if (d2 = 0 )            // Remainder R=0 then X is a solution  
      QS = QuadSolve([[a2,b2,c2]])
 
      S[1][1] = X          // Insert X solution
      S[2][1] = QS[1][1]   // Insert Quadratic solution
      S[3][1] = QS[2][1]
      
     exit
   ok
next

return S  // 3x1 matrix


//==========================================================
// Decomposing Matrix into Upper and Lower Triangular Matrix
// MatrixLuDecompose(U): Doolittle’s Method 
// Return array = [Lower,Upper] 
// Bert Mariani 2023-06-01

Func MatrixLuDecompose(U)
    Mat = U    // for clarity

    vertU = len(Mat)    horzU = len(Mat[1])

    if vertU != horzU
        See "Error: MatrixLuDecompose: "+vertU +"x"+ horzU nl
        See "VertU: "+ vertU +" HorzU: "+ horzU +" MUST BE Equal "+ nl
        MatrixPrint(Mat)
        return 1
    OK
 
    n = vertU
    h = horzU

    Lower = list(n,n)   // nxn
    Upper = list(n,n)   

    for i = 1 to n   
        for k = i to n                                // Upper Triangular           
            Sum = 0                                   // Summation of L(i, j) * U(j, k)
            for j = 1 to i  
                Sum += (Lower[i][j] * Upper[j][k])
            next
            Upper[i][k] = Mat[i][k] - Sum             // Evaluating U(i, k)
        next
    
        for k = i to n                                // Lower Triangular
            if (i = k)
                Lower[i][i] = 1                       // Diagonal as 1
            else             
                Sum = 0                               // Summation of L(k, j) * U(j, i)
                for j = 1 to i 
                    Sum += (Lower[k][j] * Upper[j][i])
                next               
                Lower[k][i]   = (Mat[k][i] - sum) / Upper[i][i]  // Evaluating L(k, i)
            ok
        next
    next

 return [Lower,Upper]
 
//======================================
//=================================================

//=================================================
// SyntheticFactor(Eq)
//
// Factor equation in to possible solutions => aX^4 + bX^3 + cX^2 +dX + e
// Return array List of Factors => //  1, -1, 2, -2, 3, -3, 5, -5, 
// Bert Mariani 2023-05-30

Func SyntheticFactor(Eq)

   last = len(Eq[1])   

   a  = Eq[1][1]  //   2
   d  = Eq[1][last]  //   6

   P = []         // d = 1..6
   Q = []         // a = 1..2
   R = []         // P/Q
   T = []         // +-R
   //----------
   for i = 1 to fabs(d)
       if !(fabs(d) % i)       // D Last Possible factors of D -> P
         Add(P,i)
       ok
   next
   //----------
   for i = 1 to fabs(a)
       if !(fabs(a) % i)       // A 1st Possible factors of A -> Q
         Add(Q,i)
       ok
   next
   //----------
   for k = 1 to len(P)         // R = Add all P factors
       Add(R,P[k])
   next 
   //----------
   for k = 1 to len(Q)         // R = Add all unique Q factors
       found = Find(P,Q[k])
       if !found
          Add(R,P[k])
       ok
   next
   //----------
   for m = 1 to len(Q)
      for k = 1 to len(P)

          nbr = P[k] / Q[m]    // P/Q R = Add all P/Q factors
          found = Find(P,nbr)
          if !found
             Add(R,nbr)
          ok
      next
   next
   //-------------------
   for k = 1 to len(R)        // T = +- R factors
       posNbr =  R[k]         // Final possible list-T
       negNbr = -R[k]
       Add(T,posNbr)
       Add(T,negNbr)
   next

return T  // 1xk array of Factors for Eq

//--------------------------------------------------
// Synthetic Division(Eq)
//
// Factor a Quartic Equation x^4"
// T[] 1xK is array of P and Q and P/Q factors from SyntheticFac"
// A[] 1xK is array of Equation to Solve"
// Try possible solution of X in T[]"
// Bert Mariani 2023-06-07


// T = list of possible solutions to try as X"
// X   a  b    c  d e f "
// 2 | 2  1  -13  6   1 row1"
//   | 0  4   10 -6     multiply   X*row2"
//     2  5   -3  0   2 row2  = row1 + multiply col"

Func SyntheticDiv(Eq,T)

    last = len(Eq[1])          // a,b,c,..d.. e...f
    S    = list(last-1,1)      // Row-Column
   
    F = []
    for i = 1 to len(T)
       X     = T[i]               // Try each factor

       Add(F,X) 
       for k = 1 to last-1       // Each term in the equatiom abcd..
           ma  = X * F[k]
           a2  = Eq[1][k+1] + ma
           Add(F,a2)
       next
       
       if F[last] = 0            // FOUND Possible Solution
          Del(F,last)            // x^4 => x^3   reduce polynomial by 1 power
          
          Q2 = QuadSolve([F])
          See "Q2 QuadSolve F[1]"+F[1]  MatrixPrint(Q2)
          
          S[1][1] = F[1] 
          S[2][1] = q2[1][1]
          S[3][1] = q2[2][1]
          return S
       ok
       
       F = []       // Clear for next try
       
    next

return S        // 4x1 matrix, if (0,0,0,0) Not solution


//=================================================
// Quartic Equation Solve 
//     => aX^4 + bX^3 + cX^2 + dX^1 +e
// Eq = [[1,8,5,-74,-120]] => (-2,3,-5,-4)
// Return 4x1 array-S
// Alogorithm
// Bert Mariani 2023-06-10

Func QuarticSolve(Eq)

   S = list(4,1)  // Row-Column

   a  = Eq[1][1]  //   1
   b  = Eq[1][2]  //   8
   c  = Eq[1][3]  //   5
   d  = Eq[1][4]  // -74
   e  = Eq[1][5]  //-120
   
   // ERROR can NOT SOLVE Quadritic eqaution that  ends with Zer0
   if (e = 0)                 // x4 -4x3 +5x2  -x +0 => Can NOT solve
      
      cube = [[a,b,c,d]]      // drop last term
      CS   = CubicSolve(cube)
 
      S[1][1] = 0          // Insert 0 solution
      S[2][1] = CS[1][1]   // Insert Cubic solution
      S[3][1] = CS[2][1]
      S[4][1] = CS[3][1]
      
      return S   //  Matrix 4x1
   ok

   P = []         // e = 1..-120
   Q = []         // a = 1..2
   R = []         // P/Q      other fractions
   T = []         // +-R
   //----------

   for i = 1 to fabs(e)
       if !(fabs(e) % i)       // Possible factors of |E| -> P
         Add(P,i)
       ok
   next
   //----------

   for i = 1 to fabs(a)
       if !(fabs(a) % i)       // Possible factors of |A| -> Q
         Add(Q,i)
       ok
   next
   //----------

   for k = 1 to len(P)         // R = Add all +P factors
       Add(R,P[k])
   next 
   //----------

   for k = 1 to len(Q)         // R = Add all Unique +Q factors
       found = Find(P,Q[k])
       if !found
          Add(R,P[k])
       ok
   next
   //----------

   for m = 1 to len(Q)
      for k = 1 to len(P)

          nbr = P[k] / Q[m]    // R = Add all +P/Q factors
          found = Find(P,nbr)
          if !found
             Add(R,nbr)
          ok
      next
   next
   //-------------------

   for k = 1 to len(R)        // T = +- R factors
       posNbr =  R[k]         // Final possible => T
       negNbr = -R[k]
       Add(T,posNbr)          // + factors
       Add(T,negNbr)          // - factors
   next

   //See "Factors "  MatrixFlatPrint(T)


    //------------------------
    // Synthetic Division
    // Factor a Quartic Equation to a Cubic Equation
    // Try All possible solution of X in T[]
    //
    // T = list of possible solutions to try as X
    // X   a  b    c  d  e 
    // 2 | 2  1  -13  6        1-row1
    //   | v  4   10             mul   X*row2
    //     2  5   -3           2-row2  add col(1row + mul)

    for i = 1 to len(T)
       X     = T[i]        // Try X as multiplier
       a2    = a           // a  = Eq[1][1]

       mb    = X * a2
       b2    = b + mb

       mc    = X * b2
       c2    = c + mc

       md    = X * c2
       d2    = d + md
       
       me    = X * d2
       e2    = e + me       // if last e2 result = 0, Possible solution
       

       if (e2 = 0 )         // Remainder R=0 then X is a solution  
       
          //See "Call CubicSolve [["+ a2 +" "+ b2 +" "+ c2 +" "+ d2 +"]]" +nl
          
          CS = CubicSolve([[a2,b2,c2,d2]])
     
          S[1][1] = X          // Insert X solution
          S[2][1] = CS[1][1]   // Insert Cubic solution
          S[3][1] = CS[2][1]
          S[4][1] = CS[3][1]
          
          //See "CubicReturn: " MatrixPrint(S)  
          
         exit
       ok
    next

return S  // 4x1 matrix


//==========================================================
//=================================================
// Quintic Equation Solve 
//     => aX^5 + bX^4 + cX^3 + dX^2 + eX^1 + f
// EQ = [[2, 21, 45, -100,  -252,  144]] => (2,0.5,-3,-4,-6)
// Return 5x1 array-S
// Alogorithm
// Bert Mariani 2023-06-10

Func QuinticSolve(Eq)

   S = list(5,1)  // Row-Column

   a  = Eq[1][1]  //   1
   b  = Eq[1][2]  //   8
   c  = Eq[1][3]  //   5
   d  = Eq[1][4]  // -74
   e  = Eq[1][5]  //-120
   f  = Eq[1][6]  //-12

   P = []         // e = 1..-120
   Q = []         // a = 1..2
   R = []         // P/Q      other fractions
   T = []         // +-R
//----------

   for i = 1 to fabs(f)
       if !(fabs(f) % i)       // Possible factors of |E| -> P
         Add(P,i)
       ok
   next
//----------

   for i = 1 to fabs(a)
       if !(fabs(a) % i)       // Possible factors of |A| -> Q
         Add(Q,i)
       ok
   next
//----------

   for k = 1 to len(P)         // R = Add all +P factors
       Add(R,P[k])
   next 
//----------

   for k = 1 to len(Q)         // R = Add all Unique +Q factors
       found = Find(P,Q[k])
       if !found
          Add(R,P[k])
       ok
   next
//----------

   for m = 1 to len(Q)
      for k = 1 to len(P)

          nbr = P[k] / Q[m]    // R = Add all +P/Q factors
          found = Find(P,nbr)
          if !found
             Add(R,nbr)
          ok
      next
   next
//-------------------

   for k = 1 to len(R)        // T = +- R factors
       posNbr =  R[k]         // Final possible => T
       negNbr = -R[k]
       Add(T,posNbr)          // + factors
       Add(T,negNbr)          // - factors
   next

//See "Factors "  MatrixFlatPrint(T)


//------------------------
// Synthetic Division
// Factor a Quartic Equation to a Cubic Equation
// Try All possible solution of X in T[]
//
// T = list of possible solutions to try as X
// X   a  b    c  d  e  f 
// 2 | 2  1  -13  6         1-row1
//   | v  4   10              mul   X*row2
//     2  5   -3            2-row2  add col(1row + mul)

for i = 1 to len(T)
   X     = T[i]        // Try X as multiplier
   a2    = a           // a  = Eq[1][1]

   mb    = X * a2
   b2    = b + mb

   mc    = X * b2
   c2    = c + mc

   md    = X * c2
   d2    = d + md
   
   me    = X * d2
   e2    = e + me       
   
   mf    = X * e2
   f2    = f + mf       // if last f2 result = 0, Possible solution
 

   //See "i: "+i +" X: "+X +" abcdef "+ a2 +" "+ b2 +" "+ c2 +" "+ d2 +" "+ e2 +" "+ f2  +nl 
  

   if (f2 = 0 )            // Remainder R=0 then X is a solution  
   
      //See "i: "+i +" X: "+X +" abcde "+ a2 +" "+ b2 +" "+ c2 +" "+ d2 +" "+ e2 +" "+ f2 +nl 
      //See "Call QuarticSolve [["+ a2 +" "+ b2 +" "+ c2 +" "+ d2 +" "+ e2 +"]]" +nl
      
      QS = QuarticSolve([[a2,b2,c2,d2,e2]])
 
      S[1][1] = X          // Insert X solution
      S[2][1] = QS[1][1]   // Insert Cubic solution
      S[3][1] = QS[2][1]
      S[4][1] = QS[3][1]
      S[5][1] = QS[4][1]
      
      //See "QuarticReturn: " MatrixPrint(S)  
      
     //exit
   ok
next

return S  // 5x1 matrix

//=====================================
// EigenValue3(A)
//
// Calculate EigenValues for a 3x3 Matrix
// Return matrix 1x3 with EigenValues
// Bert Mariani 2023-06-11
//
//------------------------------------------------
// Simple Method to solve EigenValues for a 3x3 Matrix
// Characteristic equation"
//  |A-hI| = 0                   Use 'h' Lambda Symbol (λ) 
//  +h^3 -s1h^2 +s2h -s3 = 0     Cubic equation 
//  s1 -> Sum of main diagonal   
//  s2 -> Sum of CoFactors of main diagonal
//  s3 -> Determinant|A|"

Func EigenValue3(A)

    vertU = len(A)    horzU = len(A[1])

    if vertU != horzU
        See "Error: EigenValue3: "+vertU +"x"+ horzU nl
        See "VertU: "+ vertU +" HorzU: "+ horzU +" MUST BE Equal "+ nl
        MatrixPrint(Mat)
        return 1
    OK

    s1  = A[1][1] + A[2][2] + A[3][3]        // Sum of Diagonal = TRACE
    Cof = MatrixCoFactor(A)                  // CoFactors of Matrix 
    s2  = Cof[1][1] + Cof[2][2] + Cof[3][3]  // Sum of CoFactors of Diagonal
    s3  = MatrixDetCalc(A)                   // Determinant of Matrrix 3x3
    Eq  = [[1, -s1, s2, -s3]]                // Formulate Cubic Equation + - + 1
    S   = CubicSolve(Eq)                     // Solve cubic equation

return S   // Solution 3x1 matix 

//=====================================
// EigenValue2(A)
//
// Calculate EigenValues for a 2x2 Matrix
// Return matrix 2x1 with EigenValues
// Bert Mariani 2023-06-11
//
//------------------------------------------------
// Simple Method to solve EigenValues for a 2x2 Matrix
// Characteristic equation"
// Quaddratic formula 


Func EigenValue2(A)

    vertU = len(A)    horzU = len(A[1])

    if vertU != horzU
        See "Error: EigenValue2: "+vertU +"x"+ horzU nl
        See "VertU: "+ vertU +" HorzU: "+ horzU +" MUST BE Equal "+ nl
        MatrixPrint(Mat)
        return 1
    OK

    t1  = A[1][1] + A[2][2]        // Trace = Sum of Diagonal
    d2  = MatrixDetCalc(A)         // Determinant of Matrrix 2x2
   
    p3  = (t1 + sqrt( (t1*t1) -(4*d2) )) / 2    // pos Polynomial Quadratic
    p4  = (t1 - sqrt( (t1*t1) -(4*d2) )) / 2    // neg Polynomial Quadratic
    
    S = [[p3],[p4]]

return S   // Solution 2x1 matix 

//===================================
// PolyMultiply of 2 polynomials of X
// Format is Pwr 0,1,2,3 etc 
// Put 0's in places not used
// Returns flat matrix in same ascending power
// Bert Mariani 2023/06/26

Func PolyMultiply(A,B)

   Alen = len(A)
   Blen = len(B)

   Prod = List(Alen + Blen -1)

   for i=1 to Alen
      for j=1 to Blen
         Prod[i+j-1] += A[i] * B[j]
      next
   next
   
return Prod   //   Flat Matrix [1,2,3] Pwr 0,1,2,3 etc
  
  
//===================================
// PolyAdd of 2 polynomials of X
// Format is Pwr 0,1,2,3 etc 
// Put 0's in places not used
// Returns flat matrix in same ascending power
// Bert Mariani 2023/06/26

Func PolyAdd(A,B)

   Alen   = len(A)
   Blen   = len(B)
   maxLen = max(len(A), len(B))

   P = list(maxLen)    // Make same lenght
   Q = list(maxLen)
   R = list(maxLen)    // Result of Add

   for i = 1 to Alen   // Zer0's will be at end if needed
      P[i] = A[i]
   next

   for j = 1 to Blen   // Zer0's will be at end
      Q[j] = B[j]
   next

   for k = 1 to maxLen
      R[k] = P[k] + Q[k]
   next


return R   //   Flat Matrix [1,2,3] Pwr 0,1,2,3 etc
  
//===================================
// PolySub of 2 polynomials of X
// Format is Pwr 0,1,2,3 etc 
// Put 0's in places not used
// Returns flat matrix in same ascending power
// Bert Mariani 2023/06/26

Func PolySub(A,B)

   Alen   = len(A)
   Blen   = len(B)
   maxLen = max(len(A), len(B))

   P = list(maxLen)    // Make same lenght
   Q = list(maxLen)
   R = list(maxLen)    // Result of Add


   for i = 1 to Alen   // Zer0's will be at end if needed
      P[i] = A[i]
   next

   for j = 1 to Blen   // Zer0's will be at end
      Q[j] = B[j]
   next

   for k = 1 to maxLen
      R[k] = P[k] - Q[k]
   next
   
return R   //   Flat Matrix [1,2,3] Pwr 0,1,2,3 etc
  
//========================
//===========================
// Func CharEquation(N) 4x4 Matrix
// Characteristic Polynomial of a 4x4 Matrix [A - λI]
// Return format -12 -44x -46x2 -10x3 +x4
// Bert MAriani 2023/06/23

Func CharEquation(N)
    // Assign Letters 4x4                                  //   [ A - λI ] format
    a1 = N[1][1]  a2 = N[1][2]  a3 = N[1][3]  a4 = N[1][4] //   [ 1-x, 2,   1,    3  ]
    b1 = N[2][1]  b2 = N[2][2]  b3 = N[2][3]  b4 = N[2][4] //   [ 2,   2-x, 1,    3  ]
    c1 = N[3][1]  c2 = N[3][2]  c3 = N[3][3]  c4 = N[3][4] //   [ 1,   1,   2-x,  3  ] 
    d1 = N[4][1]  d2 = N[4][2]  d3 = N[4][3]  d4 = N[4][4] //   [ 3,   3,   3,   20-x]
    
    // Convert to Flat Array and Lamda on Diagonal         //   [ A - λI ] format
    a1A = [a1,-1]  a2A = [a2]     a3A = [a3]     a4A = [a4]
    b1A = [b1]     b2A = [b2,-1]  b3A = [b3]     b4A = [b4]
    c1A = [c1]     c2A = [c2]     c3A = [c3,-1]  c4A = [c4]
    d1A = [d1]     d2A = [d2]     d3A = [d3]     d4A = [d4,-1]
   
    //================================================================================   
    // 3x3 SumMatrix:  Characteristic Equations
    //
    // +(a1)                                                                              
    //      ( b2, b3, b4)
    //      ( c2, c3, c4)
    //      ( d2, d3, d4)   
    //                   (b2)[(c3)(d4)-(d3)(c4)] 
    //                   (b3)[(c2)(d4)-(d2)(c4)] 
    //                   (b4)[(c2)(d3)-(d2)(c3)] 
    //                                           
 

    K  = PolyMultiply(b2A, (PolySub( PolyMultiply(c3A,d4A), PolyMultiply(d3A,c4A) ) ) ) 
    L  = PolyMultiply(b3A, (PolySub( PolyMultiply(c2A,d4A), PolyMultiply(d2A,c4A) ) ) ) 
    L  = PolyMultiply(L,[-1])  // FlipSign 
    M  = PolyMultiply(b4A, (PolySub( PolyMultiply(c2A,d3A), PolyMultiply(d2A,c3A) ) ) )

    N1 = PolyAdd(M, PolyAdd(K,L))    // Add 3 Sum
    P1 = PolyMultiply(a1A, N1)       // Multipyl by Row-1
         
    //  ------------------------------------------------------------------------------                                       1    2    3    4                                              
    // -(a2) = (flip sign on even position)                                             
    //      ( b1, b3, b4)                                                               
    //      ( c1, c3, c4)                                                               
    //      ( d1, d3, d4)                                                               
    //                   (b1)[(c3)(d4)-(d3)(c4) 
    //                   (b3)[(c1)(d4)-(d1)(c4) 
    //                   (b4)[(c1)(d3)-(d1)(c3) 
    //                                          

    K  = PolyMultiply(b1A, (PolySub( PolyMultiply(c3A,d4A), PolyMultiply(d3A,c4A) ) ) ) 
    L  = PolyMultiply(b3A, (PolySub( PolyMultiply(c1A,d4A), PolyMultiply(d1A,c4A) ) ) )  
    L  = PolyMultiply(L,[-1])  // FlipSign 
    M  = PolyMultiply(b4A, (PolySub( PolyMultiply(c1A,d3A), PolyMultiply(d1A,c3A) ) ) )

    N2 = PolyAdd(M, PolyAdd(K,L))    // Add 3 Sums
    P2 = PolyMultiply(a2A, N2)       // Multipl by Row-1
    P2 = PolyMultiply(P2,[-1])       // FlipSign
                                               
    //   ----------------------------------------------------------------------------                                      
    // +(a3)                                                                              
    //      ( b1, b2, b4)                                                                 
    //      ( c1, c2, c4)
    //      ( d1, d2, d4)      
    //                   (b1)[(c2)(d4)-(d2)(c4)] 
    //                   (b2)[(c1)(d4)-(d1)(c4)] 
    //                   (b4)[(c1)(d2)-(d1)(c2)] 
    //                                           
    //                          
    K  = PolyMultiply(b1A, (PolySub( PolyMultiply(c2A,d4A), PolyMultiply(d2A,c4A) ) ) ) 
    L  = PolyMultiply(b2A, (PolySub( PolyMultiply(c1A,d4A), PolyMultiply(d1A,c4A) ) ) )  
    L  = PolyMultiply(L,[-1])  // FlipSign 
    M  = PolyMultiply(b4A, (PolySub( PolyMultiply(c1A,d2A), PolyMultiply(d1A,c2A) ) ) )

    N3 = PolyAdd(M, PolyAdd(K,L))    // Add 3 Sums
    P3 = PolyMultiply(a3A, N3)        // Multipl by Row-1 
                                              

    //     ----------------------------------------------- -----------------------------                                
    //                                                                                     
    //  -(a4) (flip sign on even position)                                                 
    //       ( b1, b2, b3)                                                                 
    //       ( c1, c2, c3)
    //       ( d1, d2, d3)                   
    //                    (b1)[(c2)(d3)-(d2)(c3)] 
    //                    (b2)[(c1)(d3)-(d1)(c3)] 
    //                    (b3)[(c1)(d2)-(d1)(c2)] 
    //                                                                                                 

    K  = PolyMultiply(b1A, (PolySub( PolyMultiply(c2A,d3A), PolyMultiply(d2A,c3A) ) ) ) 
    L  = PolyMultiply(b2A, (PolySub( PolyMultiply(c1A,d3A), PolyMultiply(d1A,c3A) ) ) )  
    L  = PolyMultiply(L,[-1])  // FlipSign 
    M  = PolyMultiply(b3A, (PolySub( PolyMultiply(c1A,d2A), PolyMultiply(d1A,c2A) ) ) )

    N4 = PolyAdd(M, PolyAdd(K,L))    // Add 3 Sums
    P4 = PolyMultiply(a4A, N4)       // Multipl by Row-1
    P4 = PolyMultiply(P4,[-1])       // FlipSign

                                              
    //==========================================================================
    // Add ALL the 4 results of  Row-1  results 
    // c x^1 x^2 x^3 x^5                                                                                                             

    S1 = PolyAdd( PolyAdd(P1, P2), PolyAdd(P3, P4))
    R1 = [S1[5], S1[4], S1[3], S1[2], S1[1]]
                   
return R1  // Characteristic Eqution: high to low [] 1x4: x^5 ... x^1 c

//=================================
//=================================
// Func EigenValue4(N)
// EigenValues for 4x4 Matrix 
// Calls CharEquation to solve Polynomial
// Call QuarticSolve to find EigenValues
// Return matrix 4x1
// Bert MAriani 2023/06/28

Func EigenValue4(N)

  S1 = CharEquation(N)
  L1 = QuarticSolve([S1])

return L1  // Matrix 4x1

//===================================