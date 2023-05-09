//Least Squares - Regression Analysis

Load "stdlibcore.ring"
Load "MatrixLib.ring"

//-------------------------

U2 = [[1,1],[2,2],[3,4],[4,4],[5,6]]

//Create X = [1,Ui] ...
X2 = [[1,1],[1,2],[1,3],[1,4],[1,5]]

//Create Y = [Uj]...
Y2 = [[1],[2],[4],[4],[6]]

//---------------------------

Xt  = MatrixTrans(X2)     // Transpose X
XtX = MatrixMulti(Xt,X2)  // Mutiply Transpose by X self  2x2
XtY = MatrixMulti(Xt,Y2)  // Mutiply Transpose by Y       1x2

//---------------------------

XtXi = MatrixInverse(XtX)        // Inverse  {(1.10 -0.30),(-0.30 0.10)
See "XtXi: " MatrixPrint(XtXi)

A2   = MatrixMulti(XtXi,XtY)     // Multply Inverse {(-0.20),(1.20)}
See "Result A2: " MatrixPrint(A2)

//==========================
// Checkbox 

k = 1/50
X3 = [[55,-15],[-15,5]]          // Det(2) special case
Y3 = [[17],[63]]

Z3 =  ScalarMultiply(k, MatrixMulti(X3,y3))  // Correct  (-0.20, 1.20)
See "Check Z3"  MatrixPrint(Z3)


