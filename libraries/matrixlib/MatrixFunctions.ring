// Bert Mariani 03/18/2023
// MATRIX FUNCTIONS
//
// MatrixPrint(A)
// DotProduct(U,V)
// MatrixAdd(U,V)
// MatrixSub(U,V)
// ScalarMulti(k,U)
// VectorAngle(U,V)
// InverseMatrix(U)	 2x2
// InverseMatrix3(U) 3x3
// CrossProduct(U,V)


//=============================================
// Bert Mariani 03/18/2023
// MatrixPrint(A)
// Display a Matrix Array by Row and Col size

Func MatrixPrint(A)

x = len(A)		 // Rows horz
y = len(A[1])	 // Cols vert

 for h = 1 to x
   for v = 1 to y
	 See " "+ A[h][v]
   next
   See nl
 next
   See nl

return


//============================================
//============================================
// Bert Mariani 03/18/2023
// DotProduct(U,V)
// Dot Product of Vectors U.V => Scalar	 UtxV
// U.V = Ut.V  Horz = 1 both  Vert = same on both

Func DotProduct(U,V)

	vertU = len(U)	  horzU = len(U[1])
	vertV = len(V)	  horzV = len(V[1])

	  
	if	(horzU != 1 AND horzV != 1) AND	 (vertU != vertV) 
		See "Error: Dot Product Dimension: "+ nl
				See "horzU: "+ horzU +" horzV: "+ horzV +" MUST BE = 1 "+ nl
				See "vertU: "+ vertU +" vertV: "+ vertV +" MUST BE EQUAL " +nl
		return 1
	ok 

  Ut = MatrixTrans(U)
  Dp = MatrixMulti(Ut,V)

return Dp

//=============================================
//=============================================
// Bert Mariani 03/18/2023
// MatrixAdd(U,V)
// Matrix ADD of Vectors U+V 
// U and V must be same size, Horz x Vert
// 
Func MatrixAdd(U,V)

	vertU = len(U)	  horzU = len(U[1])
	vertV = len(V)	  horzV = len(V[1])
	vertW = len(U)	  horzW = len(V[1])
	W	  = list(vertU, horzV) 
	  
	if	(vertU != vertV) AND (horzU != horzV )
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

	vertU = len(U)	  horzU = len(U[1])
	vertV = len(V)	  horzV = len(V[1])
		vertW = len(U)	  horzW = len(V[1])
		W	  = list(vertU, horzV) 
	  
	if	(vertU != vertV) AND (horzU != horzV )
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
// W = k(U) =>	Wij ....Wnm
// 
Func ScalarMulti(k,U)

	vertU = len(U)	  horzU = len(U[1])
	vertW = len(U)	  horzW = len(U[1])
		W = list(vertU, horzU) 
	  
	if	( ! isnumber(k) )
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
// VectorAngle = u.v / ||u||||v||
// DotProdut (u.v) / (U^2 x V^2)^1/2
// Return Angle Number	in Radians 0 < nbr < Pi

Func VectorAngle(U,V)

	vertU = len(U)	  horzU = len(U[1])
	vertV = len(V)	  horzV = len(V[1])

	if	(vertU != vertV ) AND  (horzU != horzV) 
		See "Error: Scalar Square Dimension: "+ nl
				See "vertU != vertV "+ vertU +" "+ vertV +"MUST BE EQUAL "+ nl
				See "horzU != horzV "+ horzU +" "+ horzV +"MUST BE EQUAL "+ nl
		return 1
	ok

 W	  = DotProduct(U,V)
 Wdot = W[1][1]			   //  u.v
 
	
 SumU = 0
 for i = 1 to vertU
	for j = 1 to horzU
		nbr = U[i][j]
		X = nbr * nbr
	SumU += X
	next
 next
 
 SumV = 0
 for i = 1 to vertV
	for j = 1 to horzV
		nbr = V[i][j]
		Y = nbr * nbr
	SumV += Y
	next
 next
 
 Z	   = SumU * SumV		 // ||u|| * ||v||
 Zsqrt = sqrt(Z)			 
 X	   = Wdot / ZSqrt		 //	 u.v /	||u||||v||

 Angle = acos(X)			 // aCos(X) => Radians 

return Angle


//============================================
//============================================
// Bert Mariani 03/18/2023
// InverseMatrix(U)
// Inverse Matrix U 2x2
// U   =  | a b|
//		  | c d|
//
// u1  =  (1 / (ad - bc)) X | d -b|	  // Criss-cross d,a  and negative -b,-c
//							|-c	 a|

Func InverseMatrix(U)

	vertU = len(U)	  horzU = len(U[1])

	  
	if	(vertU != 2 AND horzU != 2 )
		See "Error: InverseMatrix Dimension: "+ nl
		See "vertU: "+ vertU +" horzU: "+ horzU +" MUST BE Equal = 2 "+ nl
		return 1
	ok 

	ad	=	U[1][1]	 *	 U[2][2]
	bc	= (-U[1][2]) * (-U[2][1])  

	if (ad - bc) = 0
	   See "Error: InverseMatrix Dimension: "+ nl
	   See "Matrix Not Reversible (ad - bc) "+ ad +" - "+ bc +" = 0 "+ nl
	   return 1
	ok

	det = 1 / (ad - bc)							  // Determinate
	
	a =	  U[1][1] * det	   b =	-U[1][2] * det	  // Negate b and c
	c =	 -U[2][1] * det	   d =	 U[2][2] * det	
	
	U[1][1] = d	   U[1][2] = b					  // Criss-cross d,a 
	U[2][1] = c	   U[2][2] = a
	
	//See "Determinate: ad: "+ ad +" bc: "+ bc +" sub: "+ (ad - bc) +" det: "+ det +nl


return U

//============================================
//============================================
// Bert Mariani 03/18/2023
// InverseMatrix3(U)  
// Inverse a 3x3 matrix
//
// Transpose	  Trans Mt	   Orig U
// Ut  =  | a b c| 1 0 5 |	  | 1 2 3 |
//		  | d e f| 2 1 6 | <= | 0 1 4 |
//		  | g h i| 3 4 0 |	  | 5 6 0 |
// 
// Determinate Orig-U
//			 A	   B	 C
//			 1x-24 2x-20 3x-5
//			   -24	 -40   -15
// FlipSign	  +		-	  +		  
//			   -24	 +40   -15 ==> 1 Determinate
// 
// Detrminates Mt transpose
//		   A ei-hf=-24 B di-gf=-18 C dh-eg=5  
//		   D bi-cg=-20 E ai-cg=-15 F ah-bg=4
//		   G bf-ce=-5  H af-cd=-4  I ae-bd=1
// 
//			  Adj(M)		Sign	  Adj(M) signs
// Adj(M) = |-24 -18  5|   |+ - +|	 |-24  18  5|
//			|-20 -15  4| X |- + -| = | 20 -15 -4|
//			| -5  -4  1|   |+ - +|	 | -5	4  1|
// 
// M-Inverse
// Mi  = 1/Det(U) x Adj(M)
// 
//			 Adj(M) signs
//			|-24  18  5|
// Mi =	 1/1| 20 -15 -4|  // 1/1 = Det
//			| -5   4  1|
// 
//------------------------------------

Func InverseMatrix3(U)

	vertU = len(U)	  horzU = len(U[1])
	  
	if	(vertU != 3 AND horzU != 3 )
		See "Error: InverseMatrix3 Dimension: "+ nl
		See "vertU: "+ vertU +" horzU: "+ horzU +" MUST BE Equal = 3 "+ nl
		return 1
	ok 

   // Assign lettes a-i to matrix Orig-U
   a = U[1][1]	b = U[1][2]	 c = U[1][3]
   d = U[2][1]	e = U[2][2]	 f = U[2][3]
   g = U[3][1]	h = U[3][2]	 i = U[3][3]

   //Determinate or Original U and flip sign + - +

   Det = (a*(e*i - f*h)) - (b*(d*i -f*g)) + (c*(d*h - e*g))

   See "Fac: "+ a +"* (("+ (e*i) +") - ("+ (f*h) +")) ="+ (a*(e*i - f*h)) +nl
   See "Fac: "+ b +"* (("+ (d*i) +") - ("+ (f*g) +")) ="+ (b*(d*i - f*g)) +nl
   See "Fac: "+ c +"* (("+ (d*h) +") - ("+ (e*g) +")) ="+ (c*(d*h - e*g)) +nl

   See "Det: 49: "+ det +nl

	if (Det) = 0
	   See "Error: InverseMatrix Dimension: "+ nl
	   See "Matrix Not Reversible: Determinate = "+ Det	 + nl
	   return 1
	ok

   // Transpose U => Mt 
   M = MatrixTrans(U)

   // Assign lettes a-i to Transpose M
   a = M[1][1]	b = M[1][2]	 c = M[1][3]
   d = M[2][1]	e = M[2][2]	 f = M[2][3]
   g = M[3][1]	h = M[3][2]	 i = M[3][3]

   // Detrminates Mt transpose
   //		  A ei-hf=-24 B di-gf=-18 C dh-eg=5	 
   //		  D bi-cg=-20 E ai-cg=-15 F ah-bg=4
   //		  G bf-ce=-5  H af-cd=-4  I ae-bd=1

   MA = ((e*i) - (h*f))	 MB = ((d*i) - (f*g))  MC = ((d*h) - (e*g))	 
   MD = ((b*i) - (c*h))	 ME = ((a*i) - (c*g))  MF = ((a*h) - (b*g)) 
   MG = ((b*f) - (c*e))	 MH = ((a*f) - (c*d))  MI = ((a*e) - (b*d)) 

   AdjM = [[ MA, -MB,  MC],	 // Adjunct Matrix with SignFlip
		   [-MD,  ME, -MF],
		   [ MG, -MH,  MI]] 
   
   Mi = ScalarMulti( 1/det, AdjM)


return Mi

//============================================
//============================================
// Bert Mariani 03/18/2023
// CrossProduct(U,V)
// Cross Product of Vectors UxV => Vectot W
// Dimension 3x1 Only

Func CrossProduct(U,V)

	vertU = len(U)	  horzU = len(U[1])
	vertV = len(V)	  horzV = len(V[1])
		vertW = len(U)	  horzW = len(V[1])
		W	  = list(vertU, horzV) 
	  
	if	(vertU !=3 AND vertV != 3)	AND (horzU != 1 AND horzV != 1)	 
		See "Error: Cross Product Dimension: "+ nl
				See "horzU: "+ horzU +" horzV: "+ horzV +" MUST BE = 1 "+ nl
				See "vertU: "+ vertU +" vertV: "+ vertV +" MUST BE = 3 " +nl
		return 1
	ok 

	// Assign Letters for U x Y 

	 ax = U[1][1]  ay = U[2][1]	 az = U[3][1]
	 bx = V[1][1]  by = V[2][1]	 bz = V[3][1]
	 cx = W[1][1]  cy = W[2][1]	 cz = W[3][1]
 
	 cx = ay*bz - az*by	   // Determinants
	 cy = az*bx - ax*bz
	 cz = ax*by - ay*bx

	 W =[[cx],[cy],[cz]]

return W

//============================================
//============================================