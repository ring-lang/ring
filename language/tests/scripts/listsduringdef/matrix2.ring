# Based on code from MatrixLib by Bert Mariani

Func Main()

    A = [[1,1,3],
         [1,5,1],
         [3,1,1]]

    S = EigenValue(A)              // Find EigenValues
 
    x = S[1][1]                    // EigenValue position 1

    See "x = : "+ x +nl

Func EigenValue(A)

    vertU = len(A)    horzU = len(A[1])

    if vertU = 3   // 3x3 MATRIX
       R1 = CharEquation(A)
       S1 = CubicSolve([R1])

       return S1   // 2x1 matrix for EigenValues
    ok

Func CharEquation(N)
    Alen = len(N)
    // 2x2 MATRIX ==========================
    
    if len(N) = 2   // 2x2 matrix
        a1 = N[1][1]  a2 = N[1][2]
        b1 = N[2][1]  b2 = N[2][2]
    
        a1A = [a1,-1]  a2A = [a2]   
        b1A = [b1]     b2A = [b2,-1]
    
        K1 = PolySub( PolyMultiply(a1A,b2A), PolyMultiply(b1A,a2A) ) 
        
        R1 = [ K1[3], K1[2], K1[1] ]                

        return R1     // Characteristic Eqution: x^2 x^1 c
    ok
    
    
    //=======================================
    //=======================================
    // 3x3 MATRIX
 
    if len(N) = 3   // 3x3 matrix

        // Assign Letters 3x3                   
        a1 = N[1][1]  a2 = N[1][2]  a3 = N[1][3]
        b1 = N[2][1]  b2 = N[2][2]  b3 = N[2][3]        
        c1 = N[3][1]  c2 = N[3][2]  c3 = N[3][3]    

        // Convert to Flat Array and Lamda on Diagonal
        a1A = [a1,-1]  a2A = [a2]     a3A = [a3]    
        b1A = [b1]     b2A = [b2,-1]  b3A = [b3]    
        c1A = [c1]     c2A = [c2]     c3A = [c3,-1] 

        K  = PolyMultiply(a1A, (PolySub( PolyMultiply(b2A,c3A), PolyMultiply(c2A,b3A) ) ) ) 
        L  = PolyMultiply(a2A, (PolySub( PolyMultiply(b1A,c3A), PolyMultiply(c1A,b3A) ) ) ) 

        L  = PolyMultiply(L,[-1])  // FlipSign

        M  = PolyMultiply(a3A, (PolySub( PolyMultiply(b1A,c2A), PolyMultiply(c1A,b2A) ) ) )

        N1 = PolyAdd(M, PolyAdd(K,L))    // Add 3 Sum
        
        R1 = [ N1[4], N1[3], N1[2], N1[1] ]     //  x^3  x^2  x^1  c

        return R1     // Characteristic Eqution: x^2 x^1 c
    ok
 
    //=======================================
    //=======================================

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
 
#================================


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
