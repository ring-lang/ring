// Bert Mariani 03/18/2023
//
// libraries/stdlib/stdlib.rh
// libraries/stdlib/stdlibcore.ring

Load "stdlibcore.ring"

//===================================
// Cos@ of 2 Vectors U-V
// Find angle between the Vectors based on [Uij ..][Vij ..]
// DotProduct u.v = u1v1 + u2v2 + ...uNVn  ,  DotProduvt of 2 Vectors is a Scalar
//
// cos @ = u1v1 + u2v2 / ||u|| ||v||  ,  0<= @ <= Pi
//
//  u.v        =    -12           =     - 12  = -  12  => -1
//  ||u||||v|| = sqrt24 x sqrt 6  = sqrt 144  =    12
//
//  Cos@ = -1
//
//------------------------------
//One radian is equal 57.295779513 degrees: 
//1 rad = 180°/π = 57.295779513° 
//The angle α in degrees is equal to the angle α in radians times 180 degrees 
//divided by pi constant: α (degrees)

RAD = 57.295779513   // 180 / Pi  = 1    Radian = 57.3 degress
PI  =  3.141592653


U = [[ 3],   // u.v   = 24
     [ 4]]   // ||u|| = 25 => 5

V = [[ 4],  
     [ 3]]   // ||v|| = 25 => 5


? "----- VectorAngle Func Call U.V) "
MatrixPrint(U)
MatrixPrint(V)

X   = VectorAngle(U,V)       // X = Radians
Deg = X * Rad                // Radiands to Degress

See " RESULT: VectorAngle 24/25 = 0.96 Radians = "+ X +" Deg: "+ Deg +nl +nl      


//------------------------------

U = [[ 7],[ 1]]   // u .v = 40  ||u|| = 50^^1/2
V = [[ 5],[ 5]]   //            ||v|| = 50^^1/2

? "----- VectorAngle Func Call U.V) "
MatrixPrint(U)
MatrixPrint(V)

X   = VectorAngle(U,V)       // X = Radians
Deg = X * Rad                // Radiands to Degress

See " RESULT: VectorAngle 24/25 = 0.96 Radians = "+ X +" Deg: "+ Deg +nl +nl  
 

//------------------------------

U = [[ 3],[ 4],[ 0]]  
V = [[ 4],[ 4],[ 2]]   

? "----- VectorAngle Func Call U.V) "
MatrixPrint(U)
MatrixPrint(V)

X   = VectorAngle(U,V)       // X = Radians
Deg = X * Rad                // Radiands to Degress

See " RESULT: VectorAngle 24/25 = 0.96 Radians = "+ X +" Deg: "+ Deg +nl +nl 


//------------------------------

U = [[ 1],[ 0],[ 3]]  
V = [[ 5],[ 5],[ 0]]   

? "----- VectorAngle Func Call U.V) "
MatrixPrint(U)
MatrixPrint(V)

X   = VectorAngle(U,V)       // X = Radians
Deg = X * Rad                // Radiands to Degress

See " RESULT: VectorAngle 24/25 = 0.96 Radians = "+ X +" Deg: "+ Deg +nl +nl 

//------------------------------

U = [[ 4],[ 0]]   // u .v = 16  ||u|| = 16 => Zsqr 512 Zsqrt 22.63  Angle 0.7070
V = [[ 4],[ 4]]   //            ||v|| = 32 => Cos@ = 0.7071  aCos Deg 45

? "----- VectorAngle Func Call U.V) "
MatrixPrint(U)
MatrixPrint(V)

X   = VectorAngle(U,V)       // X = Radians
Deg = X * Rad                // Radiands to Degress

See " RESULT: VectorAngle 24/25 = 0.96 Radians = "+ X +" Deg: "+ Deg +nl +nl  


//---------------------------------------
// Cos@ = X => aCos(X) => Rad => Degress

See "------------"+nl
A = Cos(Pi/1)  F = acos(A)  DF = F*Rad  See "Pi/1 cos "+ A  +" acos "+ F +" Deg "+ DF +nl 
B = Cos(Pi/2)  G = acos(B)  DG = g*Rad  See "Pi/2 cos "+ B  +" acos "+ G +" Deg "+ DG +nl  
C = Cos(Pi/3)  H = acos(C)  DH = H*Rad  See "Pi/3 cos "+ C  +" acos "+ H +" Deg "+ DH +nl 
D = Cos(Pi/4)  I = acos(D)  DI = I*Rad  See "Pi/4 cos "+ D  +" acos "+ I +" Deg "+ DI +nl 
E = Cos(Pi/6)  J = acos(E)  DJ = J*Rad  See "Pi/6 cos "+ E  +" acos "+ J +" Deg "+ DJ +nl 



//=============================================
//=============================================
// Bert Mariani 03/18/2023
// MatrixPrint(A)
// Display a Matrix Array by Row and Col size

Func MatrixPrint(A)

See "      MatrixPrint: "
x = len(A)     See "V: "+ x +"  "     // Rows 
y = len(A[1])  See "H: "+ y +nl       // Cols 


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
// VectorAngle(U,V)
// VectorAngle = u.v / ||u||||v||
// DotProdut (u.v) / (U^2 x V^2)^1/2
// Return Angle Number  in Radians 0 < nbr < Pi

Func VectorAngle(U,V)

	vertU = len(U)    horzU = len(U[1])
	vertV = len(V)    horzV = len(V[1])

	if  (vertU != vertV ) AND  (horzU != horzV) 
		See "Error: Scalar Square Dimension: "+ nl
                See "vertU != vertV "+ vertU +" "+ vertV +"MUST BE EQUAL "+ nl
                See "horzU != horzV "+ horzU +" "+ horzV +"MUST BE EQUAL "+ nl
		return 1
	ok

 W    = DotProduct(U,V)
 Wdot = W[1][1]            //  u.v
 
	
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
 
 Z     = SumU * SumV         // ||u|| * ||v||
 Zsqrt = sqrt(Z)             
 X     = Wdot / ZSqrt        //  u.v /  ||u||||v||

 Angle = acos(X)             // aCos(X) => Radians 

return Angle

//============================================
//============================================
// Bert Mariani 03/18/2023
// DotProduct(U,V)
// Dot Product of Vectors U.V =  UtxV
// U.V = Ut.V  Horz = 1 both  Vert = same on both

Func DotProduct(U,V)

	vertU = len(U)    horzU = len(U[1])
	vertV = len(V)    horzV = len(V[1])

      
	if  (horzU != 1 AND horzV != 1) AND  (vertU != vertV) 
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
// ScalarMulti(k,U)
// ScalarMulti of Vector U
// W = k(U) =>  Wij .... Wnm
// 
Func ScalarMulti(k,U)

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

//=============================================
//=============================================
 
