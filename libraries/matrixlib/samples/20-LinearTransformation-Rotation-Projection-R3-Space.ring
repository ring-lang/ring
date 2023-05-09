// A Linear Transformation Defined by a Matrix p 360
// Rotation in a Plane R3 Space
// A Projection in R3 Space

Load "stdlibcore.ring"
Load "MatrixLib.ring"


//--------------------------------
// Rotation in the Plane p359

// T:R2 -> R2
// V = (x,y) = rCos(a), rSin(a)
// T(v) = A(v)

// Degrees (°) Radians (rad)   Radians (rad)
// 0°      0    rad    0            rad
// 30°     π/6  rad    0.5235987756 rad
// 45°     π/4  rad    0.7853981634 rad
// 60°     π/3  rad    1.0471975512 rad
// 90°     π/2  rad    1.5707963268 rad

// Angle   0  π6-30 ∘ π4-45 ∘ π3-60 ∘ π2-90 ∘  75
// Cosine  1  3/√2    2/√2    1/2     0       
// Sine    0  1/2     2/√2    3/√2    1       
// x       1  0.8660  0.7071  0.5000  0        0.2588
// y       0  0.5000  0.7071  0.8660  1        0.9659

//================================================
//================================================
// A Projection in R3
// The linear transformation  T: R3 -> R3 given by "A" matrix

A = [[1,0,0],
     [0,1,0],
     [0,0,1]] 
// ???
//=========================

T = [[ 3, 0],
     [ 2, 1],
     [-1,-2]]

V = [[ 2],
     [-1]]


Av = MatrixMulti(T,V)
See "Linear Transformation Defined by a Matrix T(v) = Av = (6,3,0) " MatrixPrint(Av)


Ta = PI/12  //PI/6         // angle Ta  30=0.5235   x=0.87  y=0.50
Va = PI/4         // angle Va  45=0.7853 , x=0.71  y=0.71
R1 = 1            // radius()  75=

See nl+nl+"======================================"+nl+nl
See "Rotation in the Plane  T(v) = Av "+nl
See "Radius: "+R1 +" Radian-Ta-30 "+TA +" Radian-Va-45 "+Va +nl+nl

T1 = [[r1 * cos(Ta)],         
      [r1 * sin(Ta)]]
See "Initial-45    T1 x-y angle Va = PI/4=45  "  MatrixPrint(T1)
 
A1 = [[cos(Ta), -sin(Ta)],
      [sin(Ta),  cos(Ta)]]
See "Cos-Sin Transform A1 x-y  angle Ta = PI/6-30 "  MatrixPrint(A1)


V1 = [[r1 * cos(Va)],         
      [r1 * sin(Va)]]
See "Rotate-45     V1 x-y angle Va = PI/4=45  "  MatrixPrint(V1)

Av = MatrixMulti(A1,V1)
See "EndPoint-75   Av x-y A1xV1 Radius: "+r1 +" AngleTa: "+Ta  +" AngleVa: "+Va   MatrixPrint(Av)

