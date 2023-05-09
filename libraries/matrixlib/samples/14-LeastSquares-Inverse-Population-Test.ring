//Least Squares

Load "stdlibcore.ring"
Load "MatrixLib.ring"


U1 = [[ 5,15,4],
      [15,55,3],
      [1, 2, 3]]

See "U1: "  MatrixPrint(U1)

Ui   = MatrixInverse(U1)
See "Ui: " MatrixPrint(Ui)


PSq = [[0.70, 0.15, 0,15],
      [0.20, 0.80, 0.15],
      [0.10, 0.05, 0.70]] 

PS = [[0.70,0.15,0.15],
      [0.20,0.80,0.15],
      [0.10,0.05, 0.70]]
	 
MAtrixPrint(PS)

// State Matrix representing the current population in each of 3 states
// A B None
XS = [[15000],
      [20000],
      [65000]]

MatrixPrint(XS)
