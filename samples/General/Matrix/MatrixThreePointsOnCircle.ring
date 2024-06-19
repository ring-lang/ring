// Bretscher Chapter 1 Problem 39
// Bert Mariani 02024/05/01
 
Load "stdlibcore.ring"
Load "matrixlib.ring"

//--------------------------------------------------
// Bretscher Chapter1 Problem39
//
// 39. Find the circle that runs through the points 
//       (5, 5), (4, 6),and (6, 2). 
//  Write your equation in the form 
//        a + bx +cy + x2 + y2 = 0. 
//
//  Find the center and radius of this circle.
//  
//--------------------------------------------
//
// The centre and the radius of the circle can be represented by the following equation: 
//    (x−h)^2  +(y−k)^2       = r^2 
//    (x−h)^2  +(y−k)^2 - r^2 = 0
//
// Substituting the given points in the equation 
//     x^2 + y^2 + 2gx + 2fy + c = 0  , for all values of g, f and c.
// Adding g2 + f2 on both sides of the equation gives,
//     x^2 + y^2 + 2gx + 2fy + c = g^2 + f^2 -c  (1)
//
// Since, (x+g)2 = x2+ 2gx + g2 and (y+f)2 =y2 + 2fy + f2 substituting the values in equation (1), we have
//    (x+g)2+ (y+f)2 = g2 + f2−c  (2)
//
// Comparing (2) with (x−h)2 + (y−k)2 = a2, where (h, k) is the center and ‘a’ is the radius of the circle.
//     h =-g, k =-f2
//     a^2 = g^2 + f^2 -c
//
// Therefore,
//     x2 + y2 + 2gx + 2fy + c = 0, represents the circle with centre (−g,−f) and radius equal to a2 = g2 + f2− c.
// 
//
//-----------------------------------------------


See "Find the circle that runs through the points "+nl
See "   (5, 5), (4, 6),and (6, 2)   "+nl+nl

g1 = 5  f1 = 5   
g2 = 4  f2 = 6   
g3 = 6  f3 = 2   

// Calc x^2+y^2 column
xy1 = g1*g1 + f1*f1
xy2 = g2*g2 + f2*f2
xy3 = g3*g3 + f3*f3

//       c  g   f    x2+y2  
 U =  [[ 1, g1, f1, -(xy1)],      // point (5,5)
       [ 1, g2, f2, -(xy2)],      // point (4,6)
       [ 1, g3, f3, -(xy3)]]      // point (6,2)
        
        
 See "Original Matrix U"  MatrixPrint(U)
 
 V = RowReduceEchelonForm(U)
 See "Solved using RowReduceEchelonForm U => V " MatrixPrint(V)


 c = -(V[1][4])                       // -20
 g = -(V[2][4] / 2)                   // -1
 f = -(V[3][4] / 2)                   // -2
 
 gSqr =  g^^2                            // 1^^2
 fSqr =  f^^2                            // 2^^2
 r   = (c +gSqr +fSqr)^^(1/2)             // 25 => 5
 
 See "Circle Eq: c:"+ c +" gSqr:"+ gSqr +" fSq:"+ fSqr +" r: "+ r +nl
 
 See "Solution: Circle Center: "+ g +","+ f  +"  Radius: "+ r +nl

 See nl+"====================================="+ nl

//=========================================================
//=========================================================

See "Find the circle that runs through the points "+nl
See "   (-6, 5), (-3, -4),and (2, 1)   "+nl+nl

// Calc x^2+y^2 column
g1 = -6  f1 =  5   
g2 = -3  f2 = -4   
g3 =  2  f3 =  1   


// Calc x^2+y^2 column
xy1 = g1*g1 + f1*f1
xy2 = g2*g2 + f2*f2
xy3 = g3*g3 + f3*f3

//       c  g   f    x2+y2  
 U =  [[ 1, g1, f1, -(xy1)],      // point )
       [ 1, g2, f2, -(xy2)],      // point )
       [ 1, g3, f3, -(xy3)]]      // point )
        
        
 See "Original Matrix U"  MatrixPrint(U)
 
 V = RowReduceEchelonForm(U)
 See "Solved using RowReduceEchelonForm U => V " MatrixPrint(V)


 c = -(V[1][4])                       // -20
 g = -(V[2][4] / 2)                   // -1
 f = -(V[3][4] / 2)                   // -2
 
 gSqr =  g^^2                            // 1^^2
 fSqr =  f^^2                            // 2^^2
 r   = (c +gSqr +fSqr)^^(1/2)             // 25 => 5
 
 See "Circle Eq: c:"+ c +" gSqr:"+ gSqr +" fSq:"+ fSqr +" r: "+ r +nl
 
 See "Solution: Circle Center: "+ g +","+ f  +"  Radius: "+ r +nl

 See nl+"====================================="+ nl


//=========================================================
//=========================================================

See "Find the circle that runs through the points "+nl
See "   (8, 7), (1, 8),and (0, 1)   "+nl+nl

// Calc x^2+y^2 column
g1 = 8  f1 = 7   
g2 = 1  f2 = 8   
g3 = 0  f3 = 1   


// Calc x^2+y^2 column
xy1 = g1*g1 + f1*f1
xy2 = g2*g2 + f2*f2
xy3 = g3*g3 + f3*f3

//       c  g   f    x2+y2  
 U =  [[ 1, g1, f1, -(xy1)],      // point )
       [ 1, g2, f2, -(xy2)],      // point )
       [ 1, g3, f3, -(xy3)]]      // point )
        
        
 See "Original Matrix U"  MatrixPrint(U)
 
 V = RowReduceEchelonForm(U)
 See "Solved using RowReduceEchelonForm U => V " MatrixPrint(V)


 c = -(V[1][4])                       // -20
 g = -(V[2][4] / 2)                   // -1
 f = -(V[3][4] / 2)                   // -2
 
 gSqr =  g^^2                            // 1^^2
 fSqr =  f^^2                            // 2^^2
 r   = (c +gSqr +fSqr)^^(1/2)             // 25 => 5
 
 See "Circle Eq: c:"+ c +" gSqr:"+ gSqr +" fSq:"+ fSqr +" r: "+ r +nl
 
 See "Solution: Circle Center: "+ g +","+ f  +"  Radius: "+ r +nl

 See nl+"====================================="+ nl

