// LU Decomposition: Doolittle’s Method 
// Matrix into Lower and Upper Triangular Matrix
// Return array = [Loweer,Upper] 
// Bert Mariani 2023-06-01

Load "stdlibcore.ring"
Load "matrixlib.ring"

Func Main()
	
//----------------------------------------	
    U = [[ 2,-1,-2],  // 3x3
         [-4, 6, 3],
         [-4,-2, 6]]


    Triangle =	MatrixLuDecompose(U)
	
    Lower = Triangle[1]
    Upper = Triangle[2]

    See "Matrix ---------------- "  MatrixPrint(U)
    See "Return Lower"  MatrixPrint(Lower)
    See "Return Upper"  MatrixPrint(Upper)


//----------------------------------------

    U = [[ 2,-1,-2, 1],  // 3x3
         [-4, 6, 3, 2],
         [-4,-2, 6, 3],
         [ 2, 2, 4, 1]]


    Triangle =	MatrixLuDecompose(U)
	
    Lower = Triangle[1]
    Upper = Triangle[2]

    See "Matrix ---------------- "  MatrixPrint(U)
    See "Return Lower"  MatrixPrint(Lower)
    See "Return Upper"  MatrixPrint(Upper)

//--------------------------------------

    U = [[ 2,-1,-2, 1],  // 3x3
         [-4, 6, 3, 2],
         [-4,-2, 6, 3]]

    Triangle =	MatrixLuDecompose(U)

    if isList(Triangle)	
        Lower = Triangle[1]
        Upper = Triangle[2]

        See "Matrix ---------------- "  MatrixPrint(U)
        See "Return Lower"  MatrixPrint(Lower)
        See "Ret Upper"  MatrixPrint(Upper)
    ok

return


//======================================
/*
Matrix         MatrixPrint: 3x3
|  2,-1,-2 |
| -4, 6, 3 |
| -4,-2, 6 |

Ret Lower      MatrixPrint: 3x3
|  1, 0, 0 |
| -2, 1, 0 |
| -2,-1, 1 |

Ret Upper      MatrixPrint: 3x3
|  2,-1,-2 |
|  0, 4,-1 |
|  0, 0, 1 |

//-------------------------

Matrix         MatrixPrint: 4x4
|  2,-1,-2, 1 |
| -4, 6, 3, 2 |
| -4,-2, 6, 3 |
|  2, 2, 4, 1 |

Ret Lower      MatrixPrint: 4x4
|  1, 0, 0, 0 |
| -2, 1, 0, 0 |
| -2,-1, 1, 0 |
|  1, 0.75, 6.75, 1 |

Ret Upper      MatrixPrint: 4x4
|  2,-1,-2, 1 |
|  0, 4,-1, 4 |
|  0, 0, 1, 9 |
|  0, 0, 0,-63.75 |
*/
