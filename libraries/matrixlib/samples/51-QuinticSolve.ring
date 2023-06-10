Load "stdlibcore.ring"
Load "matrixlib.ring"


Func Main()

See nl+"============================"+nl

// 2x4  9x3 -9x2 -46x 24"  (x +6)
// 2x5  21x4  45x3  -100x  -252x1  144 
EQ = [[2, 21, 45, -100,	-252,  144]]
See "Equation to Solve  " MatrixPrint(Eq)


Q5 = QuinticSolve(Eq)
See "Q5 Quintic (2,0.5,-3,-4,-6)" MatrixPrint(Q5)

 See nl+"============================"+nl

//Eq = [[ 1, -3,-23, 81, -20]] . ((x + 2)) => 4, 3.73,0.27,-5
//   = 1, -1, -29, 35, 142, -40

EQ = [[1, -1, -29, 35, 142, -40]]
See "Equation to Solve  " MatrixPrint(Eq)


Q5 = QuinticSolve(Eq)
See "Q5 Quintic (4, 3.73,0.27,-5,-2)" MatrixPrint(Q5)

/
