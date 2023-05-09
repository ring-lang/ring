// Bert Mariani 03/18/2023 - Determinants
// 
// libraries/stdlib/stdlib.rh
// libraries/stdlib/stdlibcore.ring

Load "stdlibcore.ring"
Load "MatrixFunctions.ring"

    U2 = [[ 3,-2],             // 11  (3x1)-(-2x4) => (3)-(-8) => 3+8 => 11
          [ 4, 1]]             //


    U3 = [[ 0, 2, 1],          // 14 CoFactor  -1 -5  4  Sign -1  5  4   + - +
          [ 3,-1, 2],          //               2 -4 -8       -2 -4  8   - + -
          [ 4, 0, 1]]          //               5 -3 -6        5  3 -6   + - +
         
    U4 = [[ 1,-2, 3, 1],       //  6 CoFactor -60 -39 -10 18   <<<< FlipSign -60-39 -10 18 ==>
          [ 4,-6, 3, 2],       //               6   3   0  0     RowColValue   1 -2   3  1
          [-2, 4,-9,-3],       //             -12  -9  -2  0     Multiply    -60 78 -30 18
          [ 3,-6 ,9, 2]]       //               6   3   2 -6     Sum         -60 18 -12  6 ==> 6


    U5 = [[1, 1, 1, 1, 1],     // 106 CoFactor  6   60  42  10 -12   
          [1, 1,-2, 3, 1],     //              91 -150 -52 -25 136              
          [1, 4,-6, 3, 2],     //              -9   16 -10 -15  18 
          [1,-2, 4,-9,-3],     //              23   18   2   3 -46 
          [1, 3,-6 ,9, 2]]     //              -5   56  18  27 -96                                          -5   56  18  27 -96

    U6 = [[ 7, 2, 1, 4, 5, 6],  // -270000 CoFactor  -52400  18800  12600   5600 29800 -20800     
          [ 2,-7, 4, 5, 6, 1], //                    16832  13366 -10818 -10208 -19414   694
          [ 3, 4, 7, 1, 1, 2], //                     7072 -16264 -32328 -22768  18856  2024
          [ 1, 1, 6,-7, 2, 3], //                    -9392  10604  -3492  30848  -6716 -6964
          [ 5, 6, 1, 2, 7, 4], //                    37776 -27012   5076  -4944 -44052  4092
          [ 6, 1, 2, 1, 4,-7]] //                   -22928   2486   1422   7232    106 20774         

    U7 = [[ 7, 2, 1, 4, 5, 6, 2], // -588188 
          [ 2,-7, 4, 5, 6, 1, 4], //         
          [ 3, 4, 7, 1, 1, 2, 6], //         
          [ 1, 1, 6,-7, 2, 3, 1], //         
          [ 5, 6, 1, 2, 7, 4, 2], //         
          [ 6, 1, 2, 1, 4,-7, 3], // 
          [ 1, 3, 5, 2, 4, 2, 7]] //          

    U8 = [[ 7, 2, 1, 4, 5, 6, 2, 1], // 6176408
          [ 2,-7, 4, 5, 6, 1, 4, 5], //         
          [ 3, 4, 7, 1, 1, 2, 6, 2], //         
          [ 1, 1, 6,-7, 2, 3, 1, 4], //         
          [ 5, 6, 1, 2, 7, 4, 2, 3], //         
          [ 6, 1, 2, 1, 4,-7, 3, 6], // 
          [ 1, 3, 5, 2, 4, 2, 7, 2], //      
          [ 3, 2, 5, 3, 6, 7, 3,-7]] //           
 
    U9 = [[ 7, 2, 1, 4, 5, 6, 2, 1, 3], // -53968476
          [ 2,-7, 4, 5, 6, 1, 4, 5, 1], //         
          [ 3, 4, 7, 1, 1, 2, 6, 2, 6], //         
          [ 1, 1, 6,-7, 2, 3, 1, 4, 2], //         
          [ 5, 6, 1, 2, 7, 4, 2, 3, 5], //         
          [ 6, 1, 2, 1, 4,-7, 3, 6, 3], // 
          [ 1, 3, 5, 2, 4, 2, 7, 2, 4], //      
          [ 3, 2, 5, 3, 6, 7, 3,-7, 6], // 
          [ 6, 3, 2, 5, 3, 6, 7, 3,-7]] // 		  
		  
   U10 = [[ 7, 2, 1, 4, 5, 6, 2, 1, 3, 5], // -693393924
          [ 2,-7, 4, 5, 6, 1, 4, 5, 1, 6], //         
          [ 3, 4, 7, 1, 1, 2, 6, 2, 6, 7], //         
          [ 1, 1, 6,-7, 2, 3, 1, 4, 2, 4], //         
          [ 5, 6, 1, 2, 7, 4, 2, 3, 5, 3], //         
          [ 6, 1, 2, 1, 4,-7, 3, 6, 3, 2], // 
          [ 1, 3, 5, 2, 4, 2, 7, 2, 4, 1], //      
          [ 3, 2, 5, 3, 6, 7, 3,-7, 6, 5], // 
          [ 6, 3, 2, 5, 3, 6, 7, 3,-7, 6], // 
          [ 6, 7, 3,-7, 6, 6, 3, 2, 5, 7]] //		  
		  
//Matrix       1  2  3  4  5  6  7  8  9 10  
DetResults = [[],[],[],[],[],[],[],[],[],[]]  // GLOBAL -- Matrix up to 10x10 -- 3628800 Combinations


//===============================

Func Main()


         MatrixPrint(U2)
         t1 = clock()
         DetRet = MatrixDetCalc(U2)              // Call N! = Row=1 for Each Column     
         See "Determinant Return "+ DetRet +"  Clock:"+ (clock() - t1) +nl+nl


         MatrixPrint(U3)
         t1 = clock()
         DetRet = MatrixDetCalc(U3)              // Call N! = Row=1 for Each Column
         See "Determinant Return "+ DetRet +"  Clock:"+ (clock() - t1) +nl+nl


         MatrixPrint(U4)
         t1 = clock()
         DetRet = MatrixDetCalc(U4)
         See "Determinant Return "+ DetRet +"  Clock:"+ (clock() - t1) +nl+nl


         MatrixPrint(U5)
         t1 = clock()
         DetRet =MatrixDetCalc(U5)              // Call N! = Row=1 for Each Column
         See "Determinant Return "+ DetRet +"  Clock:"+ (clock() - t1) +nl+nl


         MatrixPrint(U6)
         t1 = clock()
         DetRet = MatrixDetCalc(U6)              // Call N! = Row=1 for Each Column
         See "Determinant Return "+ DetRet +"  Clock:"+ (clock() - t1) +nl+nl


         MatrixPrint(U7)
         t1 = clock()
         DetRet = MatrixDetCalc(U7)              // Call N! = Row=1 for Each Column
         See "Determinant Return "+ DetRet +"  Clock:"+ (clock() - t1) +nl+nl


         MatrixPrint(U8)
         t1 = clock()
         DetRet = MatrixDetCalc(U8)              // Call N! = Row=1 for Each Column
         See "Determinant Return "+ DetRet +"  Clock:"+ (clock() - t1) +nl+nl


         MatrixPrint(U9)
         t1 = clock()
         DetRet =MatrixDetCalc(U9)              // Call N! = Row=1 for Each Column
         See "Determinant Return "+ DetRet +"  Clock:"+ (clock() - t1) +nl+nl


         MatrixPrint(U10)
         t1 = clock()
         DetRet = MatrixDetCalc(U10)              // Call N! = Row=1 for Each Column
         See "Determinant Return "+ DetRet +"  Clock:"+ (clock() - t1) +nl+nl


return



//===========================
//===========================
// Clock the Speed in Milleseconds
/*
      MatrixPrint: 2x2
 3 -2
 4 1

Determinant Return 11  Clock:0

      MatrixPrint: 3x3
 0 2 1
 3 -1 2
 4 0 1

Determinant Return 14  Clock:1

      MatrixPrint: 4x4
 1 -2 3 1
 4 -6 3 2
 -2 4 -9 -3
 3 -6 9 2

Determinant Return 6  Clock:1

      MatrixPrint: 5x5
 1 1 1 1 1
 1 1 -2 3 1
 1 4 -6 3 2
 1 -2 4 -9 -3
 1 3 -6 9 2

Determinant Return 106  Clock:5

      MatrixPrint: 6x6
 7 2 1 4 5 6
 2 -7 4 5 6 1
 3 4 7 1 1 2
 1 1 6 -7 2 3
 5 6 1 2 7 4
 6 1 2 1 4 -7

Determinant Return -270000  Clock:32

      MatrixPrint: 7x7
 7 2 1 4 5 6 2
 2 -7 4 5 6 1 4
 3 4 7 1 1 2 6
 1 1 6 -7 2 3 1
 5 6 1 2 7 4 2
 6 1 2 1 4 -7 3
 1 3 5 2 4 2 7

Determinant Return -588188  Clock:176

      MatrixPrint: 8x8
 7 2 1 4 5 6 2 1
 2 -7 4 5 6 1 4 5
 3 4 7 1 1 2 6 2
 1 1 6 -7 2 3 1 4
 5 6 1 2 7 4 2 3
 6 1 2 1 4 -7 3 6
 1 3 5 2 4 2 7 2
 3 2 5 3 6 7 3 -7

Determinant Return 6176408  Clock:1358

      MatrixPrint: 9x9
 7 2 1 4 5 6 2 1 3
 2 -7 4 5 6 1 4 5 1
 3 4 7 1 1 2 6 2 6
 1 1 6 -7 2 3 1 4 2
 5 6 1 2 7 4 2 3 5
 6 1 2 1 4 -7 3 6 3
 1 3 5 2 4 2 7 2 4
 3 2 5 3 6 7 3 -7 6
 6 3 2 5 3 6 7 3 -7

Determinant Return -53968476  Clock:13140

      MatrixPrint: 10x10
 7 2 1 4 5 6 2 1 3 5
 2 -7 4 5 6 1 4 5 1 6
 3 4 7 1 1 2 6 2 6 7
 1 1 6 -7 2 3 1 4 2 4
 5 6 1 2 7 4 2 3 5 3
 6 1 2 1 4 -7 3 6 3 2
 1 3 5 2 4 2 7 2 4 1
 3 2 5 3 6 7 3 -7 6 5
 6 3 2 5 3 6 7 3 -7 6
 6 7 3 -7 6 6 3 2 5 7

Determinant Return -693393924  Clock:144395

*/


