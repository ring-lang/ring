// Matrix Multiplication
// Bert Mariani 2020-10-26
//-------------------------------
/*
Matrix A
   A1 A2 A3 A4
1  11 12 13 14
2  21 22 23 24
3  31 32 33 34

Matrix B
   B1 B2 B3 B4 B5
1  51 52 53 54 55
2  61 62 63 64 65
3  71 72 73 74 75
4  81 82 83 84 85

c11 = 11 x 51 + 12 x 61 + 13 x 71 + 14 x 81 = 3350
c12 = 11 x 52 + 12 x 62 + 13 x 72 + 14 x 82 = 3400
c13 = 11 x 53 + 12 x 63 + 13 x 73 + 14 x 83 = 3450
c14 = 11 x 54 + 12 x 64 + 13 x 74 + 14 x 84 = 3500
c15 = 11 x 55 + 12 x 65 + 13 x 75 + 14 x 85 = 3550
c21 = 21 x 51 + 22 x 61 + 23 x 71 + 24 x 81 = 5990
c22 = 21 x 52 + 22 x 62 + 23 x 72 + 24 x 82 = 6080
c23 = 21 x 53 + 22 x 63 + 23 x 73 + 24 x 83 = 6170
c24 = 21 x 54 + 22 x 64 + 23 x 74 + 24 x 84 = 6260
c25 = 21 x 55 + 22 x 65 + 23 x 75 + 24 x 85 = 6350
c31 = 31 x 51 + 32 x 61 + 33 x 71 + 34 x 81 = 8630
c32 = 31 x 52 + 32 x 62 + 33 x 72 + 34 x 82 = 8760
c33 = 31 x 53 + 32 x 63 + 33 x 73 + 34 x 83 = 8890
c34 = 31 x 54 + 32 x 64 + 33 x 74 + 34 x 84 = 9020
c35 = 31 x 55 + 32 x 65 + 33 x 75 + 34 x 85 = 9150

Result:
   C1    C2    C3    C4    C5
1  3350  3400  3450  3500  3550
2  5990  6080  6170  6260  6350
3  8630  8760  8890  9020  9150

*/
//-------------------------------

FlagShowSolution = 0     // 1=Show  0=NoShow

A = [[11,12,13,14],
     [21,22,23,24],
     [31,32,33,34]]

B = [[51,52,53,54,55],
     [61,62,63,64,65],
     [71,72,73,74,75],
     [81,82,83,84,85]]

result = MatrixMultiply(A,B)
DisplayMatrix(result)  See nl

//-------------------------------

A =  [[3,4,2]]    

B = [[13,9,7,15],
     [ 8,7,4, 6],
     [ 6,4,0 ,3]]

result = MatrixMultiply(A,B)
DisplayMatrix(result)  See nl

//-------------------------------

A =  [[1,2,3]]    

B = [[ 4],
     [ 5],
     [ 6]]

result = MatrixMultiply(A,B)
DisplayMatrix(result)  See nl

//-------------------------------

A = [[ 4],
     [ 5],
     [ 6]]
     
B =  [[1,2,3]]    

result = MatrixMultiply(A,B)
DisplayMatrix(result)  See nl

//-------------------------------

A = [[ 4,5,6],
     [ 7,8,9],
     [ 1,2,3]]
     
B =  [[1,0,0],
      [0,1,0],   
      [0,0,1]]      

result = MatrixMultiply(A,B)
DisplayMatrix(result)  See nl

//-------------------------------

A = [[ 1,2],
     [ 3,4]]
     
B =  [[2,0],
      [1,2]]         

result = MatrixMultiply(A,B)
DisplayMatrix(result)  See nl

//-------------------------------

A =  [[2,0],
      [1,2]] 
      
B = [[ 1,2],
     [ 3,4]]
     
result = MatrixMultiply(A,B)
DisplayMatrix(result)  See nl

//-------------------------------

//-----------------------------------------------------------------
// Multiply  Array AxB  Horz-A MUST EQUAL vert-B  Ex A 3x4  B 4x5
// Use [[1,2,3]] for 1 Row matrix
// FlagShowSolution = 0     // 1=Show  0=NoShow

Func MatrixMultiply(A,B)      

   vertA = len(A)    horzA = len(A[1])
   vertB = len(B)    horzB = len(B[1])
   vertC = len(A)    horzC = len(B)
   C     = list(vertA, horzB)         // Make array bigV and bigH
      
   if horzA != vertB 
      See "Error: Matrix dimension: Horz-A:"+horzA +" MUST EQUAL vert-B:"+vertB +nl
      return 1
   ok
   
   
   for vA = 1 to vertA
      for hB = 1 to horzB

         Sum = 0
         for k = 1 to horzA             
            Sum += A[vA][k] * B[k][hB]    

            if FlagShowSolution = 1                  // 0 No Show, 1 = Show Solution
                See " "+ A[vA][k] +"*"+ B[k][hB]
            ok
            
         next
            if FlagShowSolution = 1  
                See " = "+ Sum  +"  C"+ vA + hB +nl
            ok
                
         C[va][hB] = Sum          
      
      next
   next

return C

//----------------------------
// Display Matrix

Func DisplayMatrix(M)

   if !IsList(M)
      return 1
   ok
   
   sizeV = len(M)
   sizeH = len(M[1])

   See nl
   for V = 1 to sizeV
      See ""+V +":"
      for h = 1 to sizeH
         See " "+ M[v][h]
      next
      See nl
   next
return

//----------------------------
