//DotProduct p282, 289

Load "stdlibcore.ring"
Load "matrixlib.ring"
    
//q = c    x    x^2
P = [[1],[ 0],[-2]]
Q = [[4],[-2],[ 1]]
R = [[0],[ 1],[ 2]]

See "P " MatrixPrint(P)
See "Q " MatrixPrint(Q)
See "R " MatrixPrint(R)

InnerProd = DotProduct(P,Q)
See "Inner Prod P.Q : 2: = "+InnerProd +nl

InnerProd = DotProduct(Q,R)
See "Inner Prod Q.R : 0: = "+InnerProd +nl
	
Norm = VectorNorm(Q)
See "Norm Q sqrt(21) 4.58 = "+ Norm +nl

Distance = VectorDistance(P,Q)
See "Vector Distance P,Q sqrt(22) 4.69 =  "+ Distance +nl
