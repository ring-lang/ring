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
// 16 MatrixDeterminant(U)         // Calls 16a-16e Determinant2x2,3x3,4x4,5x5,6x6
// 17 MatrixProjection(U,V)        // ProjvU = (U.V)/(V.V)xV
// 18 MatrixOrthoDistance(U,V)
// 19 VectorLength(U)
// 20 VectorNorm(U)                // Same as VectorLength - different name
// 21 VectorUnit(U)                // Vector Norm to a Unit Matrix
// 22 VectorDistance(U,V)
// 23 MatricOrthoNormal2(U,V)      // Gram-Schmidt method for 2 Vectors in R2 Space
// 24 MatrixOrthoNormal3(V1,V2,V3) // Gram-Schmidt method for 3 Vectors in R3 Space


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
   See nl

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
