//Least Squares - Application to Astronomy p324

Load "stdlibcore.ring"
Load "matrixlib.ring"

//-------------------------
// Application to Astonomy
//Mean distance X and periods Y of the 6 Planets
//Find a model for these data 
//Planets do not lie in a straight line 
//They lie on a Log Line  Y = (3/2)ln(X) or Y = X^3/2

//Planet      Mercury  Venus  Earth  Mars   Jupiter  Saturn
//Distance X  0.387    0.723  1.000  1.523   5.203    9.541
//Period Y    0.241    0.615  1.000  1.881  11.861   29.457
//ln X       -0.949   -0.324  0.000  0.421   1.649    2.256
//ln Y       -1.423   -0.486  0.000  0.632   2.473    3.383

// Ax = b
A  = [[1, 0.387],  //   
      [1, 0.723],  //   
      [1, 1.000],  // 
      [1, 1.523],  //   
      [1, 5.203],
      [1, 9.541]]


b  = [[ 0.241],
      [ 0.615],
      [ 1.000],
      [ 1.881],
      [11.881],
      [29.457]]

AL  = [[1, -0.949],  //   
      [1, -0.324],   //   
      [1,  0.000],   // 
      [1,  0.421],   //   
      [1,  1.649],
      [1,  2.256]]


bL  = [[-1.423],
      [-0.486],
      [ 0.000],
      [ 0.632],
      [ 2.473],
      [ 3.383]]


See "A "  MatrixPrint(A)
See "b "  MatrixPrint(b)


// Transpose  AtA  and AtB

AtA = MatrixMulti( MatrixTrans(A), A ) //  ( 6 18.38)(18.38 122.09)
Atb = MatrixMulti( MatrixTrans(A), b ) //  ( 45.08)( 347.27)

See "AtA A-Transpose x A" MatrixPrint(AtA)
See "Atb A-Transpose x b" MatrixPrint(Atb)

//AtAx =Atb solve for x = c0, c1, c2

X1  = MatrixMulti( MatrixInverse(AtA), Atb)  // ( -2.22)( 3.18)
See "Result X1: (Inverse AtA) x AtB  " MatrixPrint(x1)

See "Y = c0: "+ X1[1][1] +" c1x: "+ X1[2][1] +nl
See "Y = -2.22 + X^3.18" +nl+nl

//---------------------------------------------------
// LOG  LN

See "AL "  MatrixPrint(AL)
See "bL "  MatrixPrint(bL)


// Transpose  AtA  and AtB

ALtAL = MatrixMulti( MatrixTrans(AL), AL ) //  ( 6 3.05)( 3.05 8.99)
ALtbL = MatrixMulti( MatrixTrans(AL), bL ) //  (4.58)( 13.48)

See "ALtAL A-Transpose x AL" MatrixPrint(ALtAL)
See "ALtbL A-Transpose x bL" MatrixPrint(ALtbL)

//AtAx =Atb solve for x = c0, c1, c2

X1L  = MatrixMulti( MatrixInverse(ALtAL), ALtbL)  // ( 0.00)( 1.50)
See "Result X1L: (Inverse ALtAL) x ALtBL  " MatrixPrint(x1L)

See "LN Y = c0: "+X1L[1][1] +" c1x^: "+ X1L[2][1] +nl

See "   Y = (3/2)ln(X) or Y = X^3/2" +nl  


//------------------------







