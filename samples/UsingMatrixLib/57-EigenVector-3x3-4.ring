// "EigenVectors 2x2 and 3x3 exampl


Load "stdlibcore.ring"
Load "MatrixLib.ring"

Func Main()



See nl+"-------------------------"+nl
// "EigenValue 2x2" 

A = [[-6, 3],  
     [ 4, 5]]
See "A  "  MatrixPrint(A)

S = EigenValue(A)
See "EigenValue S (6,-7): "  MatrixPrint(S)

D = EigenVector(A)
See "D returns 2 vertical vectors (1,4) and (3-1)"  MatrixPrint(D)

See nl+"-------------------------"+nl
// "EigenValue 3x3" 

    A = [[1,1,3],
         [1,5,1],
         [3,1,1]]

See "A  "  MatrixPrint(A)

S = EigenValue(A)
See "EigenValue S (-2,3,6): "  MatrixPrint(S)

D = EigenVector(A)
See "D returns 3 vertical vectors(-1,0,1) (1,-1,1) and (1,2,1)"  MatrixPrint(D)

See nl+"-------------------------"+nl
