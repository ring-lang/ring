// VectorUnit p 273  Vector Length and Angle

Load "stdlibcore.ring"
Load "MatrixFunctions.ring"

//-------------------------

U = [[3],[-1],[2]]   // 3x1  in R3 space
MatrixPrint(U)

// 3.74165 Lenth
Lt = VectorLength(U)
See "VectorLength: 3.74: "+Lt +nl

V = VectorUnit(U)
See "VectorUnit: 0.8017, -0.26726, 0.5345  : "  MatrixPrint(V)  

//-------------------------------------
// Unit Vector = Sqrt (Sum of Vector U /

Lt = VectorLength(V)
See "Unit Vector Length:V 1: "+Lt +nl

//--------------------------------------
// Distance between 2 Vectors
// D = Sqrt( Sum(Ui-Vi"squared
// D = ||U - V||  = Sqrt( Sum(Ui-Vi"squared

U = [[0],[2],[2]]
V = [[2],[0],[1]]
MatrixPrint(U) MatrixPrint(V)

Distance  = VectorDistance(U,V)

See "Distance: 3: = "+ Distance  

//----------------------------------
// Angle between2 Vectors p279

U = [[-4],[0],[2],[-2]]
V = [[2],[0],[-1],[1]]
MatrixPrint(U) MatrixPrint(V)

Angle = VectorAngle(U,V)
See "VectorAngle in Radians -1: "+ Angle 







