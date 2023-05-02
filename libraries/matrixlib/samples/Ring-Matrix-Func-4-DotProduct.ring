// Bert Mariani 03/18/2023
// 
// libraries/stdlib/stdlib.rh
// libraries/stdlib/stdlibcore.ring

Load "stdlibcore.ring"

//===================================
// Dot Product of Vectors = UtxV

U = [[ 1],
     [ 2],
     [-1]]

V = [[ 3],
     [-2],
     [ 4]]

? "----- DotProduct Func Call: U.V "
MatrixPrint(U)
MatrixPrint(V)

W = DotProduct(U,V)  See " RESULT: "
MatrixPrint(W)

//-------------------------------

U =  [[4], [0], [-3], [5]]
V =  [[0], [2], [5],  [4]]   // 0 + 0 -15 20 => sum   5

? "----- DotProduct Func Call: U.V "
MatrixPrint(U)
MatrixPrint(V)

W = DotProduct(U,V)  See " RESULT: "
MatrixPrint(W)

//------------------------------

//============================================
//============================================
// Bert Mariani 03/18/2023
// DotProduct(U,V)
// Dot Product of Vectors U.V => Scalar  UtxV
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

//================================================

