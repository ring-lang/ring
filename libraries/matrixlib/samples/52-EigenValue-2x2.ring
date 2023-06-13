// "EigenValue 2x2" 
// https://www.vcalc.com/wiki/SavannahBergen/Understanding+Eigenvalues+and+Eigenvectors+of+a+2x2+Matrix#:~:text=For%20a%202x2%20matrix%2C%20the%20characteristic%20polynomial%20is,%28trace%29%20%C2%B1%20%28trace%29%202%20-%204%20%28determinant%29%202


Load "stdlibcore.ring"
Load "matrixlib.ring"

Func Main()

//-------------------------
// Detail steps

A = [[-1, 2],  
     [ 4,-3]]

    See "A solve " MatrixPrint(A)
    t1  = A[1][1] + A[2][2]        // Trace = Sum of Diagonal
    See "Trace T1: "+ t1 +nl+nl

    d2  = MatrixDetCalc(A)         // Determinant of Matrrix 2x2
    See "Determinant D2: "+ d2 +nl+nl  

    p3  = (t1 + sqrt( t1*t1 -(4*d2)) ) / 2    // pos Polynomial Quadratic
    p4  = (t1 - sqrt( t1*t1 -(4*d2)) ) / 2    // neg Polynomial Quadratic	   

    S = [[p3],[p4]]
    See "Solution S (1,-5): "  MatrixPrint(S)


See nl+"========================="+nl

A = [[ 7,1],  
     [-4,3]]

See "A solve " MatrixPrint(A)
S = EigenValue2(A)
See "Solution (5,5) " MatrixPrint(S)

See nl+"========================="+nl

A = [[ 2,-3],  
     [ 0, 2]]

See "A solve " MatrixPrint(A)
S = EigenValue2(A)
See "Solution (2,2) " MatrixPrint(S)

See nl+"========================="+nl

A = [[ 2, 2],  
     [ 1, 3]]

See "A solve " MatrixPrint(A)
S = EigenValue2(A)
See "Solution (2,2) " MatrixPrint(S)

See nl+"========================="+nl


See "A solve " MatrixPrint(A)
S = EigenValue2(A)
See "Solution (2,2) " MatrixPrint(S)

See nl+"========================="+nl

