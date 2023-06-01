// Finding Area of Parallelogram p331
// And "SOME APPLICATIONS OF LINEAR ALGEBRA AND GEOMETRY IN REAL LIFE
//     Vittoria Bonanzinga


Load "stdlibcore.ring"
Load "matrixlib.ring"

// Find the Cross Product of 2 Vectors in R3 Space
// Finding the Area of a Parallelogram in 3D Space
// UxV
//        | i  j  k  |
//  UxV = | u1 u2 u3 |
//        | v1 v2 v3 |

// p 331
// AREA of Parallelogram

U = [[-3],[ 4],[ 1]]
V = [[ 0],[-2],[ 6]]

See "U "  MatrixPrint(U)
See "V "  MatrixPrint(V)

W = CrossProduct(U,V)
See "Cross Product result matrix W "  MatrixPrint(W)

  //-------------------------
  // W  is Orthogonal to both U and V
  // ||UxV|| = magnitude  = Sqrt(Sum of Squares of W
  // Area of Parallelogram: 32.19 L*L: 1036

 a = W[1][1]  b = W[2][1]  c = W[3][1]

 L =  sqrt( a*a + b*b +c*c)  // sqrt 134
 See "Area of Parallelogram: 32.19  sqrt(1036): = "+ L +" square units,  L*L: "+ (L*L) +nl+nl


//=========================================
//=========================================

//  Volume of a Parallelogram  
//  Vol = |U.(VxW)|   DotProdoct CrossProduct


//-----------------------

U = [[-3],[ 4],[ 1]]
V = [[ 0],[-2],[ 6]]
W = [[ 2],[ 2],[ 2]]

UV  = CrossProduct(U,V)
WUV = DotProduct(W,UV)

See "UxV CrossProduct "  MatrixPrint(UV)
See "W.UxV DotProduct 1036  = "+ WUV +nl+nl

//=============================
//=============================
///SOME APPLICATIONS OF LINEAR ALGEBRA AND GEOMETRY IN REAL LIFE
///Vittoria Bonanzinga

See nl+"Applications of Linear Algebra and Geometry "+nl+nl
// Area Parallelogram

U = [[1,5],
     [6,2]]

Area = MatrixDetCalc(U)
See "Area Parallelogram: 28 sq: = "+ Area  +nl

//----------------------
// Area Triangle
U = [[1,5,1],
     [6,2,1],
     [7,7,1]]

Area = (1/2)*MatrixDetCalc(U)
See "Area Triangle: 14 sq: = "+ Area  +nl 

//-----------------------
// Volume Parallelogram

U = [[1,5,0],
     [6,2,0],
     [3,2,4]]

Vol = MatrixDetCalc(U)
See "Vol Parallelogram: 112 cubic: = "+ Vol  +nl 

//---------------------
// Volume Tetrahedron

U = [[1,5,0],
     [6,2,0],
     [3,2,4]]

Vol = (1/6)*MatrixDetCalc(U)
See "Vol Tretrahedron: 56/3 cubic: = "+ Vol  +nl

//-----------------------
// Volume Parallelogram

U = [[1,5,0],
     [6,2,0],
     [5,12,4]]

Vol = MatrixDetCalc(U)
See "Vol Parallelogram: 112 cubic: = "+ Vol  +nl+nl







