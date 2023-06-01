// Quadratic Equation Solver
// Cubic Equation Solver
// Bert Mariani 2023--6-30

Load "stdlibcore.ring"
Load "matrixlib.ring"

//--------------------------------

Func Main()

Eq = [[1,7,10]]

MatrixPrint(Eq)
X = QuadSolve(Eq)
See "Quad Solve (-2,-5) " MatrixPrint(X)

//--------------------------------

Eq = [[1,5,6]]

MatrixPrint(Eq)
X = QuadSolve(Eq)
See "Quad Solve (-2,-3) " MatrixPrint(X)

//---------------------------

Eq = [[3,6,-10]]

MatrixPrint(Eq)
X = QuadSolve(Eq)
See "Quad Solve (1.08,-3.08) " MatrixPrint(X)

//--------------------------------

Eq = [[2,3,-2]]

MatrixPrint(Eq)
X = QuadSolve(Eq)
See "Quad Solve (1/2, -2) " MatrixPrint(X)

//--------------------------------

Eq = [[6,-17,12]]

MatrixPrint(Eq)
X = QuadSolve(Eq)
See "Quad Solve (3/2, 4/3) " MatrixPrint(X)

//--------------------------------

Eq = [[1,-4,-7, 10]]

MatrixPrint(Eq)
X = CubicSolve(Eq)
See "Cubic Solve (-2,1,5) " MatrixPrint(X)

//----------------------------

Eq = [[ 2, 1,-13, 6]]

MatrixPrint(Eq)
X = CubicSolve(Eq)
See "PQ Cubic Solve (-3,2, 0.5) " MatrixPrint(X)


//========================================
//========================================
