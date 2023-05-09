// Computer Graphics p399
// Rotation About the Z-Axis

Load "stdlibcore.ring"
Load "MatrixLib.ring"
//Load "MatrixDraw-3D-Rotation.ring"

//=================================
// Z-Axis is vertical in R 3Space
// Y-Axis goes to Right 45
// X-Axis goes to Left 45
  
// |x1|   |cos(a)  -sin(a)  0| |x|   |xcos(a) - ysin(a)|
// |y1| = |sin(a)   cos(a)  0| |y| = |xsin(a) + ycos(a)|
// |z1|   |  0        0     1| [z|   |   Z             |

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

See nl+nl+"======= Rotate Z =============="+nl+nl
 ang = PI/3  // Radians = 60 degrees

//       x           x        z
 Z = [[cos(ang),  -sin(ang),  0],
      [sin(ang),   cos(ang),  0],
      [  0 ,         0,       1]]

 See "Z matrix for "+ang MatrixPrint(Z)

 V1 = [[0],[0],[0]]  
 V2 = [[1],[0],[0]]   
 V3 = [[1],[2],[0]]  
 V4 = [[0],[2],[0]]
 V5 = [[0],[0],[3]]  
 V6 = [[1],[0],[3]]  
 V7 = [[1],[2],[3]]  
 V8 = [[0],[2],[3]]

 V1a = MatrixMultiply(Z,V1)
 V2a = MatrixMultiply(Z,V2)
 V3a = MatrixMultiply(Z,V3)
 V4a = MatrixMultiply(Z,V4)
 V5a = MatrixMultiply(Z,V5)
 V6a = MatrixMultiply(Z,V6)
 V7a = MatrixMultiply(Z,V7)
 V8a = MatrixMultiply(Z,V8)

See "V1a  0, 0, 0 "       MAtrixPrint(V1a)
See "V2a  0.5, 0.87, 0 "  MAtrixPrint(V2a)
See "V3a -1.23, 1.87, 0 " MAtrixPrint(V3a)
See "V4a -1.73, 1, 0 "    MAtrixPrint(V4a)
See "V5a  0, 0, 3 "       MAtrixPrint(V5a)
See "V6a  0.5, 0.87, 3 "  MAtrixPrint(V6a)
See "V7a -1.23, 1.87, 3 " MAtrixPrint(V7a)
See "V8a -1.73, 1, 3 "    MAtrixPrint(V8a)

//==========================================
//==========================================

See nl+nl+"======= Rotate X =============="+nl+nl
 ang = PI/3  // Radians = 60 degrees

//       x           x        z
 X = [[  1 ,         0,       0],
      [cos(ang),  -sin(ang),  0],
      [sin(ang),   cos(ang),  0]]

 See "X matrix for "+ang MatrixPrint(Z)

 V1 = [[0],[0],[0]]  
 V2 = [[1],[0],[0]]   
 V3 = [[1],[2],[0]]  
 V4 = [[0],[2],[0]]
 V5 = [[0],[0],[3]]  
 V6 = [[1],[0],[3]]  
 V7 = [[1],[2],[3]]  
 V8 = [[0],[2],[3]]

 V1a = MatrixMultiply(X,V1)
 V2a = MatrixMultiply(X,V2)
 V3a = MatrixMultiply(X,V3)
 V4a = MatrixMultiply(X,V4)
 V5a = MatrixMultiply(X,V5)
 V6a = MatrixMultiply(X,V6)
 V7a = MatrixMultiply(X,V7)
 V8a = MatrixMultiply(X,V8)

See "V1a  0, 0, 0 "        MAtrixPrint(V1a)
See "V2a  1, 0.5, 0.87 "   MAtrixPrint(V2a)
See "V3a  1, -1.23, 1.87 " MAtrixPrint(V3a)
See "V4a  0, -1.73, 1 "    MAtrixPrint(V4a)
See "V5a  0, 0, 0 "        MAtrixPrint(V5a)
See "V6a  1, 0.5, 0.87 "   MAtrixPrint(V6a)
See "V7a  1, -1.23, 1.87 " MAtrixPrint(V7a)
See "V8a  0, -1.73, 1 "    MAtrixPrint(V8a)

//==========================================
//==========================================

See nl+nl+"======= Rotate Y =============="+nl+nl
 ang = PI/3  // Radians = 60 degrees

//       x           x        z
 Y = [[cos(ang),   sin(ang),  0],
      [  0 ,         1,       0],
      [sin(ang),   cos(ang),  0]]

 See "X matrix for "+ang MatrixPrint(Z)

 V1 = [[0],[0],[0]]  
 V2 = [[1],[0],[0]]   
 V3 = [[1],[2],[0]]  
 V4 = [[0],[2],[0]]
 V5 = [[0],[0],[3]]  
 V6 = [[1],[0],[3]]  
 V7 = [[1],[2],[3]]  
 V8 = [[0],[2],[3]]

 V1a = MatrixMultiply(Y,V1)
 V2a = MatrixMultiply(Y,V2)
 V3a = MatrixMultiply(Y,V3)
 V4a = MatrixMultiply(Y,V4)
 V5a = MatrixMultiply(Y,V5)
 V6a = MatrixMultiply(Y,V6)
 V7a = MatrixMultiply(Y,V7)
 V8a = MatrixMultiply(Y,V8)

See "V1a  0, 0, 0 "        MAtrixPrint(V1a)
See "V2a  0.5, 0, 0.87 "   MAtrixPrint(V2a)
See "V3a  2.23, 2, 1.87 "  MAtrixPrint(V3a)
See "V4a  1.73, 2, 1 "     MAtrixPrint(V4a)
See "V5a  0, 0, 0 "        MAtrixPrint(V5a)
See "V6a  0.5, 0, 0.87 "   MAtrixPrint(V6a)
See "V7a  2.23, 2, 1.87 "  MAtrixPrint(V7a)
See "V8a  1.73, 2, 1 "     MAtrixPrint(V8a)

//===========================================
//===========================================
// Called by MatrixDraw
// Points of Ogject to Draw
Func GetShape()

See "GetShape() Called "+nl
VShape = [
    [0,0,0],       //  V1 = [[0],[0],[0]]
    [1,0,0],       //  V2 = [[1],[0],[0]]
    [1,2,0],       //  V3 = [[1],[2],[0]]
    [0,2,0],       //  V4 = [[0],[2],[0]]
    [0,0,3],       //  V5 = [[0],[0],[3]]
    [1,0,3],       //  V6 = [[1],[0],[3]]
    [1,2,3],       //  V7 = [[1],[2],[3]]
    [0,2,3]] //       //  V8 = [[0],[2],[3]]

k = 50

V = ScalarMultiply(k,VShape)

return Vshape

//===========================
// Edges to Connectionname()

Func GetEdge()

See "GetEdge() Called "+nl
VShape = [
    [0,0,0],       //  V1 = [[0],[0],[0]]
    [1,0,0],       //  V2 = [[1],[0],[0]]
    [1,2,0],       //  V3 = [[1],[2],[0]]
    [0,2,0],       //  V4 = [[0],[2],[0]]
    [0,0,3],       //  V5 = [[0],[0],[3]]
    [1,0,3],       //  V6 = [[1],[0],[3]]
    [1,2,3],       //  V7 = [[1],[2],[3]]
    [0,2,3]] //    //  V8 = [[0],[2],[3]]

EPoints = [
    [1, 2],
    [1, 3],
    [1, 4],
    [5, 6],
    [5, 7],
    [5, 8]]      


return EPoints

