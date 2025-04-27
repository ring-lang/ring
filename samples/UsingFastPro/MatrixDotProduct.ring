load "matrixlib.ring"
load "fastpro.ring"

// DotProduct Matrix
// a · b = ax × bx + ay × by
// 
// a · b = -6 × 5 + 8 × 12
// a · b = -30 + 96
// a · b = 66

See nl+"=========================="+nl

U = [[-6],[ 8],[15]]
V = [[ 5],[12],[ 9]]

   See "RING Vector U" MatrixPrint(U)
   See "RING Vector V" MatrixPrint(V)

Ans = DotProduct(U,V)
  
   See "RING Answer: Scalar: "+Ans +nl 

See nl+"=========================="+nl

See nl+"=========================="+nl

aListA = [[-6],
          [ 8],
          [15]]
		  
aListB = [[ 5],[12],[ 9]]

   See "FASTPRO Vector aListA " MatrixPrint(aListA)
   See "FASTPRO Vector aListB " MatrixPrint(aListB)
   
Ans = updateList(aListA,:dotproduct,:matrix,aListB) 
  
   See "FASTPRO Answer Scalar: "+Ans +nl

See nl+"=========================="+nl

See nl+"=========================="+nl



