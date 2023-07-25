// Row Reduce Echelon Form, Gausian-Jordan Elimination
//        Ones in a Column have ALL ZEROS BELOW && ABOVE
// 
// Bert MAriani 2023-Jul-25
//
// Row Reduce Echelon Form , Gausian-Elimination
//     Reduced Row Echelon Form
//        Ones in a Column have ALL ZEROS BELOW
//
// Row Operations
// 1 - Replace     (curRow - ( pivRow * Scalar) 
// 2 - Interchange (switch two rows)
// 3 - Scale       (multiply by a Scalar)
// 4 - FlipSign    (piviotCol is negative)
// 5 - Sort        (to get pivotCol=0 at bottom, rest by abs 1,2,3
// 
//====================================================================
          
Load "stdlibcore.ring"
Load "matrixlib.ring"

//Globals
//    lastRow  = 1
//    lastCol  = 1
//    pivotRow = 1                     // pivotCol Position in curRow
//    pivotCol = 1                      // pivotCol Position in curRow
//    pivotVal = 1 
//------------------------------

Func Main()

See nl+"=================================================="+ nl
 
A = [[ 3, 1,-4,-1],         //  [1,0,0,0]  
     [ 1, 0,10, 5],         //  [0,1,0,0]
     [ 0, 1, 0, 1],         //  [0,0,1,0]
     [ 4, 1, 6, 1]]         //  [0,0,0,1] 
	 
See "Original Matrix A" MatrixPrint(A)
 
B = RowReduceEchelonForm(A)
See "RREF A => B " MatrixPrint(B) 

See nl+"=================================================="+ nl
 
A = [[ 3, 1,-4,-1],         //  [ 1, 0, 10, 0]     
     [ 1, 0,10, 5],         //  [ 0, 1,-34, 0]    
     [ 4, 1, 6, 1]]         //  [ 0, 0,  0, 1]] 
     
See "Original Matrix A" MatrixPrint(A)
 
B = RowReduceEchelonForm(A)
See "RREF A => B " MatrixPrint(B) 

See nl+"================================================="+ nl

A = [[-2,-2,-2, 0,-8],         //  [ 1, 0,-1, 0, 0]  
     [ 1, 1, 1,-1, 0],         //  [ 0, 1, 2, 0, 0]  
     [ 0, 1, 2, 0, 1],         //  [ 0, 0, 0, 1, 0]  
     [ 2, 1, 0, 2,12]]         //  [ 0, 0, 0, 0, 1]  
	 
See "Original Matrix A" MatrixPrint(A)
 
B = RowReduceEchelonForm(A)
See "RREF A => B " MatrixPrint(B) 
 

See nl+"================================================="+ nl
 
A = [[ 1, 2, -1,  -4],    //  [1, 0, 0,-8]
     [ 2, 3, -1, -11],    //  [0, 1, 0, 1]
     [-2, 0, -3,  22]]    //  [0, 0 ,1,-2]    
	 
See "Original Matrix " MatrixPrint(A)         
      
B = RowReduceEchelonForm(A)
See "RREF A ==> B " MatrixPrint(B)

See nl+"===================================================="+ nl

A = [[ 1,1,1,1,1],        // [[ 1, 0, 0, 1, 1],       
     [ 1,1,0,0,1],        //  [ 0, 1, 0,-1, 0],       
     [ 0,1,1,0,0],        //  [ 0, 0, 1, 1, 0],     
     [ 0,0,1,1,0],        //  [ 0, 0, 0, 0, 0],
     [ 1,0,0,1,1]]        //  [ 0, 0, 0, 0, 0]]
	 
See "Original Matrix A" MatrixPrint(A)
 
B = RowReduceEchelonForm(A)
See "RREF A => B " MatrixPrint(B) 
 
See nl+"===================================================="+ nl

A = [[ 0, 0, -2, 0, 7,12],        // [[ 1,2,0,3,0,7]      
     [ 2, 4,-10, 6,12,28],        //  [ 0,0,1,0,0,1],       
     [ 2, 4, -5, 6,-5,-1]]        //  [ 0,0,0,0,1,2],     

See "Original Matrix A" MatrixPrint(A)
 
B = RowReduceEchelonForm(A)
See "RREF A => B " MatrixPrint(B) 
 
See nl+"===================================================="+ nl


A = [[ 1,-2, 3, 9],        // [[ 1, 0, 0, 1]      
     [-1, 3, 0,-4],        //  [ 0, 1, 0,-1],       
     [ 2,-5, 5,17]]        //  [ 0, 0, 1, 2],     

See "Original Matrix A" MatrixPrint(A)
 
B = RowReduceEchelonForm(A)
See "RREF A => B " MatrixPrint(B) 
 
See nl+"===================================================="+ nl

A = [[ 0, 1, 1,-2, -3],        // [[ 1, 0, 0, 0,-1],       
     [ 1, 2,-1, 0,  2],        //  [ 0, 1, 0, 0, 2],       
     [ 2, 4, 1,-3, -2],        //  [ 0, 0, 1, 0, 1],     
     [ 1,-4,-7,-1,-19]]        //  [ 0, 0, 0, 1, 3],

See "Original Matrix A" MatrixPrint(A)
 
B = RowReduceEchelonForm(A)
See "RREF A => B " MatrixPrint(B) 
 
See nl+"===================================================="+ nl

return
