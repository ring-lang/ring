// "EigenValue 3x3" 
// "Video: www.youtube.com/watch?v=PIoBUX_PN68 "
// "Casio Calculator keisan.casio.com/exec/system/1181809414 For Quad,Cubic,Quartic"

// "Method to solve EigenValues for a Matrix"
// "Characteristic equation"
// " |A-hI| = 0                  Use 'h' Lambda Symbol (λ) "
// " +h^3 -s1h^2 +s2h -s3 = 0	 Cubic equation "
// " s1 -> Sum of main diagonal"	 
// " s2 -> Sum of CoFactors of main diagonal"
//  "s3 -> Determinant|A|" 


Load "stdlibcore.ring"
Load "matrixlib.ring"

Func Main()

//-------------------------
// Detail steps

A = [[ 1, 1, 3],  
     [ 1, 5, 1],
     [ 3, 1, 1]]

See "A - Matrix to solve for EigenValues"  MatrixPrint(A)

s1 = A[1][1] + A[2][2] + A[3][3]
See "s1 Sum Diag (7): = "+s1 +nl+nl

Cof = MatrixCoFactor(A)
See "CoFactors: " MatrixPrint(Cof)

s2 = Cof[1][1] + Cof[2][2] + Cof[3][3]
See "s2 Sum of Cofactors Diag = "+s2 +nl+nl

s3 = MatrixDetCalc(A)
See "s3 Matrix Determinant|A|): = "+s3  +nl+nl

Eq = [[1, -s1, s2, -s3 ]]   // + - + 1
See "Eq (1, -s1, s2, -s3) : " MatrixPrint(Eq)

X = CubicSolve(Eq)   // Can use Casio calculator
See "EigenValues LAMDAS h = (-2,6,3) = " MatrixPrint(X)

See nl+"====================="+nl
//LArspn p352

A  = [[ 2, 1, 0],  //(1,21,2)
      [ 0, 2, 0],
      [ 0, 0, 2]] 

See "A - Matrix to solve for EigenValues"  MatrixPrint(A)
S = EigenValue3(A)
See "EigenValues (2,2,2): "  MAtrixPrint(S)

See nl+"====================="+nl
// Larson p354

A  = [[ 2, 0, 0],  //(1,21,2)
      [-1, 1, 0],
      [ 5, 3,-3]] 


See "A - Matrix to solve for EigenValues"  MatrixPrint(A)
S = EigenValue3(A)
See "EigenValues (2,1,-3): "  MAtrixPrint(S)

See nl+"====================="+nl
// Larson p354

A  = [[ 1, 3, 0],  //(1,21,2)
      [ 3, 1, 0],
      [ 0, 0,-2]] 

See "A - Matrix to solve for EigenValues"  MatrixPrint(A)
S = EigenValue3(A)
See "EigenValues (-2,4,-2): "  MAtrixPrint(S)

See nl+"====================="+nl
// Larson p356
A  = [[-2, 2,-3],  //(1,21,2)
      [ 2, 1,-6],
      [-1,-2, 0]] 

See "A - Matrix to solve for EigenValues"  MatrixPrint(A)
S = EigenValue3(A)
See "EigenValues (-3,5,-3): "  MAtrixPrint(S)

See nl+"====================="+nl

// Larson p356
A  = [[ 4,-1, 3],  //(1,21,2)
      [ 0, 2, 1],
      [ 0, 0, 3]] 


See "A - Matrix to solve for EigenValues"  MatrixPrint(A)
S = EigenValue3(A)
See "EigenValues (2,4,3): "  MAtrixPrint(S)

See nl+"====================="+nl

A  = [[ 1, 2, 3],  //(1,21,2)
      [ 3, 2, 1],
      [ 2, 1, 3]] 


See "A - Matrix to solve for EigenValues"  MatrixPrint(A)
S = EigenValue3(A)
See "EigenValues (6 -2^12, +2^1/2): "  MAtrixPrint(S)

See nl+"====================="+nl
