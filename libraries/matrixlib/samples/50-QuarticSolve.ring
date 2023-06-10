Load "stdlibcore.ring"
Load "matrixlib.ring"


Func Main()

See nl+"============================"+nl

// "(2x3 1x2 -13x 6 ) (x +4) =>(2,0.5,-3,4) "
// " 2x4  9x3 -9x2 -46x 24"

Eq = [[2,9,-9,-46,24]]  //  
See "Equation to Solve  " MatrixPrint(Eq)

Q4 = QuarticSolve(Eq)
See "Q4 solve2 (2,0.5,-3,-4) " MatrixPrint(Q4)

See nl+"============================"+nl


Eq = [[ 1, -3,-23, 81, -20]]  
See "Equation to Solve " MatrixPrint(Eq)

Q4 = QuarticSolve(Eq)
See "Q4 solve2 (4, 3.73,0.27,-5) " MatrixPrint(Q4)

See nl+"============================"+nl

// "[[ 1, -8, 17, -4]] (4, 3.73,0.27) "
// "1x3  -8x2  17x  -4  . (  3x  -5 )  note -5/3x = -1.67"  
// "3x4 -29x3  91x2 -97x  20 "

Eq = [[ 3,-29, 91,-97, 20]]   
See "Equation to Solve " MatrixPrint(Eq)

Q4 = QuarticSolve(Eq)
See "Q4 solve2  (4, 1.67, 3.73,0.27) " MatrixPrint(Q4)

See nl+"============================"+nl

///////////////////////////
///////////////////////////
///////////////////////////

//=================================================
// Quartic Equation Solve 
//     => aX^4 + bX^3 + cX^2 + dX^1 +e
// Eq = [[1,8,5,-74,-120]] => (-2,3,-5,-4)
// Return 4x1 array-S
// Alogorithm
// Bert Mariani 2023-06-10

Func Quartic3Solve3(Eq)

   S = list(4,1)  // Row-Column

   a  = Eq[1][1]  //   1
   b  = Eq[1][2]  //   8
   c  = Eq[1][3]  //   5
   d  = Eq[1][4]  // -74
   e  = Eq[1][5]  //-120

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
   

   if (e2 = 0 )            // Remainder R=0 then X is a solution  
   
      //See "i: "+i +" X: "+X +" abcde "+ a2 +" "+ b2 +" "+ c2 +" "+ d2 +" "+ e2  +nl 
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
