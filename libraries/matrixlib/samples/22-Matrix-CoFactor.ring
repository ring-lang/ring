
// Bert Mariani 03/18/2023
// 
// libraries/stdlib/stdlib.rh
// libraries/stdlib/stdlibcore.ring

Load "stdlibcore.ring"
Load "matrixlib.ring"
Decimals(3)


// 
//   OrigU             Row-Col                               
//  | 1 2 3 |    U = | U[1][1] U[1][2] U[1][3] |   
//  | 0 1 4 |   =>   | U[2][1] U[2][2] U[3][3] |   
//  | 5 6 0 |        | U[3][1] U[3][2] U[3][3] |   
//
//  Udet = 14   
//  Mi  = 1/Udet x Adj(M)
//
//------------------------------------------------
//            Adj(M)        Sign      Adj(M) signs
// Adj(M) = |-24 -18  5|   |+ - +|   |-24  18  5|
//          |-20 -15  4| X |- + -| = | 20 -15 -4|
//          | -5  -4  1|   |+ - +|   | -5   4  1|
// 
// M-Inverse
// Mi  = 1/Det(U) x Adj(M)
// 
//           Adj(M) signs
//          |-24  18  5|
// Mi =  1/1| 20 -15 -4|  // 1/Det1 
//          | -5   4  1|
// 
//-----------------------------------------
// Find Determanent for each Row-Col
// Find size of Matrix
// Create a SubMatrix 1 smaller
// Create a Adjoint of Determinants

Func Main()

    U0 = [[ 3,-2],
         [ 4, 1]]


    U1 = [[ 0, 2, 1],   // CoFactors -1 -5  4  Sign -1  5  4  + - +
         [ 3,-1, 2],   //            2 -4 -8       -2 -4  8  - + -
         [ 4, 0, 1]]   //            5 -3 -6        5  3 -6  + - +

    U2 = [[ 1,-2, 3, 1], 
          [ 4,-6, 3, 2], 
          [-2, 4,-9,-3], 
          [ 3,-6 ,9, 2]] 


    U3 = [[1, 1, 1, 1, 1],
          [1, 1,-2, 3, 1],
          [1, 4,-6, 3, 2],
          [1,-2, 4,-9,-3],
          [1, 3,-6 ,9, 2]]


    U = [[ 7, 2, 1, 4, 5, 6], 
          [ 2,-7, 4, 5, 6, 1],
          [ 3, 4, 7, 1, 1, 2],
          [ 1, 1, 6,-7, 2, 3],
          [ 5, 6, 1, 2, 7, 4],
          [ 6, 1, 2, 1, 4,-7]]


    vertU = len(U)    horzU = len(U[1])    
    if  (vertU != horzU  )
        See "Error: Matrix Not Square Dimension: "+ nl
        See "vertU: "+ vertU +" horzU: "+ horzU +" MUST BE Equal "+ nl
        return 1
    ok 

    //Init-Start -------------------------------------------

    Udet   = Determinant(U)        // See "Udet: "+ Udet +nl   
    if (Udet = 0)
        See "Error: Matrix can not be Inversed. Determinate 0: "+ Udet + nl
    ok
 
    Uadj = U                                // CoFactors  returned ==> Uadj adjoint 3x3
    for Row = 1 to vertU
        for Col = 1 to horzU
            V = list(vertU-1, horzU-1)      // 3x3 => 2x2

            r=1                             // vert
            for i = 1 to vertU
                s = 1                       // horz
                for j = 1 to horzU
                    if (i != Row) AND (j != Col)    // Skip if Not this Row and Col     
                        num = U[i][j]
                        //See "Pos: ij: "+i +"-"+ j +" rs: "+r +"-"+s  +" Uij: "+ num +nl 
                        V[r][s] = num
                        s++
                    ok                                  
                next

                if (i != Row) AND (j != Col)
                   r++
                ok
            next  
            
            MatrixPrint(U)
            MatrixPrint(V)
                
            CoFactor = Determinant(V)
            See "CoFactor: "+ CoFactor +nl

            // SignFlip based on Row+Col if Odd
            if (Row + Col) % 2
                Uadj[Row][Col] = -CoFactor 
            else
                Uadj[Row][Col] =  CoFactor
            ok

        next
    next

    MatrixPrint(U)
    See "Udet: "+ Udet +nl+nl
    MatrixPrint(Uadj)
    Utrans = MatrixTrans(Uadj)               MatrixPrint(Utrans)
    Uinv   = ScalarMultiply((1/Udet), Utrans)   MatrixPrint(Uinv)
    Uidentity = MatrixMulti(U, Uinv)         MatrixPrint(Uidentity)

return Uinv

// U matrix 
//    1  2  3
//    0  1  4
//    5  6  0
// 
// U cofactors        Signs      Adjoint
//   |-24 -20  -5|   |+ - +|   |-24  20 -5|
//   |-18 -15  -4| X |- + -| = | 18 -15  4|
//   |  5   4   1|   |+ - +|   |  5  -4  1|
// 
// U adjoint
//   -24  20 -5
//    18 -15  4
//     5  -4  1
// 
// U determinant 1
// 
// U scalar multiply buy 1/Udet
//   -24  20 -5
//    18 -15  4
//     5  -4  1
// 
// U transpose
//   -24  18  5
//    20 -15 -4
//    -5   4  1
// 
// U identity = PROOF
//     1 0 0
//     0 1 0
//     0 0 1

//============================================
