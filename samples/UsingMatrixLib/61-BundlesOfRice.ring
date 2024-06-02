// Bundle of 3 Types of Rice Problem - Bretscher Chapter 1 p. 1
// Bert Mariani 02024/05/01
 
Load "stdlibcore.ring"
Load "MatrixLib.ring"

// 1. The yield of 1 bundle of inferior rice, 2 bundles of medium-grade rice,
//    and 3 bundles of superior rice is 39 dou of grain.
// 2. The yield of 1 bundle of inferior rice, 3 bundles of medium-grade rice, 
//    and 2 bundles of superior rice is 34 dou. 
// 3. The yield of 3 bundles of inferior rice, 2 bundles of medium-grade rice,
//    and 1 bundle of superior rice is 26 dou.
// 4. What is the yield of one bundle of each grade of rice?
//
// Bundles        Dou    Yield-Solution
// 1x + 2y + 3z = 39     x = 2.75
// 1x + 3y + 2z = 34     y = 4.25
// 3x + 2y + 1z = 26     z = 9.25
//
//===================================

 Decimals(3)
 See nl+"====================================="+ nl

 A = [[ 1, 2, 3, 39],   // x =  4.125  2.75
      [ 1, 3, 2, 34],   // y =  1.500  4.25
      [ 3, 2, 1, 26]]   // z = 10.625  9.25
	
 // Use a copy of A-matrix because it gets modified by RREF call	
 A2 = A	 
 See "Rice Original Matrix A2"  MatrixPrint(A2)
 
 B = RowReduceEchelonForm(A2)
 See "Solved using RowReduceEchelonForm A2 => B " MatrixPrint(B) 

 See nl+"====================================="+ nl

 //===========================================
 // PROOF -- Take first 3 colums X Result => 4th colum

 See nl+"=== Proof ==========================="+ nl

 S = MatrixCopyCol(A,1,3)     // Select x,y,z
 T = MatrixCopyCol(B,4,4)     // Select solution

 See "S cols 1:3 of A = Rice new Matrix "   MatrixPrint(S)
 See "T cols 4:4 of B = Rice new Matrix "   MatrixPrint(T)
 
 R = MatrixMultiply(S,T)

 See "Rice Proof by MatrixMutiply SxT=>R" MatrixPrint(R)
 
 See nl+"====================================="+ nl

//============================================
//============================================

