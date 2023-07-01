Load "stdlibcore.ring"
Load "matrixlib.ring"


Func Main()

Eq = [[ 2, 1,-13, 6]]  
See "Equation to Solve " MatrixPrint(Eq)

Q3 = CubicSolve(Eq)
See "Cubic Solution (2,0.5,-3)" MatrixPrint(Q3)

See nl+"============================"+nl

//-----------------------------------------------
// "1x^4 - 7x^3 + 5x^2 + 31x - 30   (-2,1,3,5) "

Eq = [[ 1, -7, 5, 31, -30]]  // (2,0.5,-3)
See "Equation to Solve  " MatrixPrint(Eq)

Q4 = QuarticSolve(Eq)
See "Quartic Solution (1,-2,5,3)" MatrixPrint(Q4)


