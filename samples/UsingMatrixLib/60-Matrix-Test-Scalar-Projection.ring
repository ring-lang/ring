//============================
// Bert Mariani 16/04/2024
// Scalar Projection A onto B =   A.B  / |B|
// Vector    ProjbA  A onto B =  (A.B) / (B.B) x |B|
//
// Let A = [3, 4] and B = [1, 2]. 
// Find the scalar projection of A onto B.
// The formula for the scalar projection of A onto B is given by A.B/||B||. 
// The dot product is: A.B = (3)(1) + (4)(2) = A.B   = 11
// The magnitude of B is:  ||B|| = √(1² + 2²) ||B||  = √5
// Hence, the scalar projection of A onto B is 11/√5 = 4.9193.
//------------------------------------------------------------
  
Load "stdlibcore.ring"
Load package "MatrixLib.ring"

//===========================

Func Main()
 
A =  [[  1],[  6],[ 18]]       
B =  [[ 42],[-69],[ 98]]       
                        
See "A " MatrixPrint(A)
See "B " MatrixPrint(B)

SP = MatrixScalarProjection(B,A)
See "Scalar projection of B onto A = 73.26  => "+ SP +nl

SP = MatrixScalarProjection(A,B)
See "Scalar projection of A onto B = 10.96  => "+ SP +nl

A =  [[ 3],[ 4]]       
B =  [[ 1],[ 2]] 

See "A " MatrixPrint(A)
See "B " MatrixPrint(B) 

SP = MatrixScalarProjection(A,B)
See "Scalar projection of A onto B = 4.9193 => "+ SP +nl



