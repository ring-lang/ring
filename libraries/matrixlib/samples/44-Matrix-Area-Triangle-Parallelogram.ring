// Bert Mariani 03/18/2023
// 
// libraries/stdlib/stdlib.rh
// libraries/stdlib/stdlibcore.ring

Load "stdlibcore.ring"
Load "MatrixLib.ring"

//===================================
// Area of a Triangle  UxV

? "----- AREA Triangle Func Call: (U,V,W)  -1.50 square units"
U = [[ 1],[ 0]]
V = [[ 2],[ 2]]
W = [[ 4],[ 3]]

MatrixPrint(U)
MatrixPrint(V)
MatrixPrint(W)

Area = AreaTriangle(U,V,W)  See " Using Area Formula RESULT: "
See "Area: "+ Area +nl+nl

//-------------------------------

? "----- AREA Triangle Func Call: Determinate3(U) -1.50 square units"
U = [[ 1, 0, 1],
     [ 2, 2, 1],
     [ 4, 3, 1]]

MatrixPrint(U)

Area = 1/2 * (Determinant3(U))  See " Using Determinant RESULT: "
See "Area: "+ Area +nl+nl

//-------------------------------

? "----- AREA Triangle Func Call: (U,V,W) 0"
U = [[ 0],[ 1]]
V = [[ 2],[ 2]]
W = [[ 4],[ 3]]

MatrixPrint(U)
MatrixPrint(V)
MatrixPrint(W)

Area = AreaTriangle(U,V,W)  See " Using Area Formula RESULT: "
See "Area: "+ Area +nl+nl

//-------------------------------

? "----- AREA Triangle Func Call: Determinate3(U) = 0 square units"
U = [[ 0, 1, 1],
     [ 2, 2, 1],
     [ 4, 3, 1]]

MatrixPrint(U)

Det = (Determinant3(U))
if Det = 0
  See "Area: 0 Colinear Points, Determant: "+ Det +nl+nl
else
  Area = 1/2 * Det  See " Using Determinant3 RESULT: "
  See "Area: "+ Area +nl+nl
ok

//-------------------------------
//-------------------------------

See "==========================="+nl
See "==========================="+nl+nl

? "----- VOLUME Tetrahedron Func Call: Determinate3(U) = 56/3 = 18.66 cubic units"
U = [[ 1, 5, 0],
     [ 6, 2, 0],
     [ 3, 2, 4]]

MatrixPrint(U)

Det = (Determinant3(U))
if Det = 0
  See "Volume: 0 Colinear Points, Determant: "+ Det +nl+nl
else
  Volume = 1/6 * Det  See " Using Determinant3 RESULT: "
  See "Volume Tetrahedron: "+ Volume +nl+nl
ok

//-----------------------



See "==========================="+nl
See "==========================="+nl+nl

? "----- AREA Parallelogram Func Call: Determinate2(U) = 28 square units"

U = [[ 1, 5],
     [ 6, 2]]

MatrixPrint(U)

Det = (Determinant2(U))
if Det = 0
  See "Area: 0 Colinear Points, Determant: "+ Det +nl+nl
else
  Area = fabs(Det)  See " Using Determinant2 RESULT: "
  See "Area: "+ Area +nl+nl
ok

//---------------------
See "==========================="+nl
See "==========================="+nl

? "----- VOLUME Parallelepiped Func Call: Determinate3(U) = 112 cubic units"
U = [[ 1, 5, 0],
     [ 6, 2, 0],
     [ 3, 2, 4]]

MatrixPrint(U)



Det = (Determinant3(U))
if Det = 0
  See "Volume: 0 Colinear Points, Determant: "+ Det +nl+nl
else
  Volume = 1 * Det  See " Using Determinant3 RESULT: "
  See "Volume Parallelepiped: "+ Volume +nl+nl
ok


//------------------------------

//============================================
//============================================
// Bert Mariani 03/18/2023
// Area of a Triange (X1,X2,X3)
// Dimension 2x1 Only

Func AreaTriangle(U,V,W)

    vertU = len(U)    horzU = len(U[1])
    vertV = len(V)    horzV = len(V[1])
    vertW = len(W)    horzW = len(W[1])
    M     = list(vertU, horzV) 
      
    if  (vertU != 2 AND vertV != 2 AND vertW != 2)  AND 
        (horzU != 1 AND horzV != 1 AND horzW != 1)  
        See "Error: Area of a Triangle Dimension: "+ nl
                See "horzU: "+ horzU +" horzV: "+ horzV +" horzW: "+ horzW+" MUST BE = 1 "+ nl
                See "vertU: "+ vertU +" vertV: "+ vertV +" vertW: "+ vertW+" MUST BE = 2 " +nl
        return 1
    ok 

 // Assign Letters for U x Y 

     x1 = U[1][1]  y1 = U[2][1]  
     x2 = V[1][1]  y2 = V[2][1]  
     x3 = W[1][1]  y3 = W[2][1] 
 
     a1 = 1/2*((y1+y3) * (x3 - x1))   //   Area of Trapezoid 1
     b1 = 1/2*((y3+y2) * (x2 - x3))   // + Area of Trapezoid 2
     c1 = 1/2*((y1+y2) * (x2 - x1))   // - Area of Trapezoid 3

     Area = a1 + b1 - c1

     // ALternative formula
     AreaAlt = 1/2*(x1*y2 + x2*y3 + x3*y1 - x1*y3 -x2*y1 -x3*y2)

     See "Area: "+ Area +" ArealAlt: "+ AreaAlt +nl

return Area

//============================================
//============================================
