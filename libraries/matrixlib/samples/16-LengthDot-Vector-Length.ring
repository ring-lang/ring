// VectorLength p 272

Load "stdlibcore.ring"
Load "MatrixLib.ring"

//-------------------------

U = [[0],[-2],[1],[4],[-2]]   //5x1  in R5 space


Lt = VectorLength(U)
See "VectorLength: sqrt(25) 5: "+Lt  MatrixPrint(U)

a = sqrt(17)  See "a sqrt(17): "+a +nl
V = [[2/a],[-2/a],[3/a]]  // 3x1 R3 space

Lt = VectorLength(V)
See "VectorLength: sqrt(17/17) 1: "+Lt  MatrixPrint(V)
