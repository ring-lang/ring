// The Geometry of Linear Transformations in the Plane p396
// Reflections in the Plane p397

Load "stdlibcore.ring"
Load "MatrixFunctions.ring"
//=======================

k = 2  // ===<<< INITIALIZE

//Reflextion in Y-Axis
AY = [[-1, 0],
      [ 0, 1]]

//Reflextion in X-Axis
AX = [[ 1, 0],
      [ 0,-1]]

//Reflextion in XLine Y=X
AL = [[ 0, 1],
      [ 1, 0]]

//Horizontal Expansion (k>1) or Contraction (0<k<1)
AHK = [[ k, 0],
       [ 0, 1]]

//Vertical Expansion (k>1) or Contraction (0<k<1)
AVK = [[ 1, 0],
       [ 0, k]]

//Horizontal Shear()
AHS = [[ 1, k],
       [ 0, 1]]

//Vertical Shear()
AVS = [[ 1, 0],
       [ k, 1]]

//----------------------------
// Reflection in the Y-Axis
// T(x,y) = (-x,y)

x=2  y=3 

xy = [[  x],     
      [  y]]

R = MatrixMultiply(AY,xy)
See "Relection Y-Axis: ("+x+" "+y+") = (-2,3) = "  MatrixPrint(R)

//----------------------------
// Reflection in the X-Axis
// T(x,y) = (x,-y)

x=2  y=3  

xy = [[  x],     
      [  y]]

R = MatrixMultiply(AX,xy)
See "Relection X-Axis ("+x+" "+y+") = (2,-3) = "  MatrixPrint(R)

//----------------------------
// Reflection in the Line y=x
// T(x,y) = (y,x)

x=2  y=3  

xy = [[  x],     
      [  y]]

R = MatrixMultiply(AL,xy)
See "Relection Line-XY ("+x+" "+y+") = (3,2) = "  MatrixPrint(R)

//=============================
//=============================
//Expansions and Contractions in the Plane

//----------------------------
// Horizontal Contractions and Expansions
// T(x,y) = (kx,y)

See nl+"=========================="+nl+nl

x=2  y=3  //(k=2)

xy = [[  x],     
      [  y]]


R = MatrixMultiply(AHK,xy)
See "Horizontal Expansion xyk: "+x+" "+y+" "+k +" in X-Axis (4,3) = "  MatrixPrint(R)

//----------------------------
// Horizontal Contractions and Expansions
// T(x,y) = (kx,y)

x=2  y=3  //(k=2)

xy = [[  x],     
      [  y]]


R = MatrixMultiply(AVK,xy)
See "Vertical Expansion xyk: "+x+" "+y+" "+k +" in Y-Axis (2,6) = "  MatrixPrint(R)

See nl+"=========================="+nl+nl

//----------------------------
// Horizontal Contractions and Expansions
// T(x,y) = (kx,y)

x=2  y=3  k= 1/2

//Horizontal Expansion (k>1) or Contraction (0<k<1)
AHK = [[ k, 0],
       [ 0, 1]]

xy = [[  x],     
      [  y]]

R = MatrixMultiply(AHK,xy)
See "Horizontal Contraction xyk: "+x+" "+y+" "+k +" in X-Axis (1,3) = "  MatrixPrint(R)

//----------------------------

//----------------------------
// Horizontal Contractions and Expansions
// T(x,y) = (kx,y)

x=2  y=3  k= 1/2

//Vertical Expansion (k>1) or Contraction (0<k<1)
AVK = [[ 1, 0],
       [ 0, k]]

xy = [[  x],     
      [  y]]

R = MatrixMultiply(AVK,xy)
See "Vertical Contraction xyk: "+x+" "+y+" "+k +" in Y-Axis (2, 1.5) = "  MatrixPrint(R)


See nl+"=========================="+nl+nl

//=================================
//==================================
//Shears in a Plane

//---------------------
//T(x,y) = (x+ky,y)
// Horizontal Contractions and Expansions
// T(x,y) = (kx,y)

xy = [[  x],     //(k=2)
      [  y]]

R = MatrixMultiply(AHS, xy)
See "Shear Horizontal xyk: "+x+" "+y+" "+k +" in X-Axis (8,3) = "  MatrixPrint(R)


//---------------------
//T(x,y) = (x, y+kx)

xy = [[  x],     //(k=2)
      [  y]]



R = MatrixMultiply(AVS, xy)
See "Shear Vertical (xyk: "+x+" "+y+" "+k +" in Y-Axis (2,7) = " MatrixPrint(R)












