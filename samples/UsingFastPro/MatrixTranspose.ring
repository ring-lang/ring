# Author: Bert Mariani
# FastPro MatrixTranspose
#
#========================================

? "Loading Library"
load "fastpro.ring"

#================================a========
See nl+"RING MatrixTrans() A=>C "+nl

aListA = [1:5,
          1:5,
          1:5,
          1:5,
          1:5]
	  
//======================================
// RING MatrixTrans()

  See "Start RING MatrixTrans()  A => C "  MatrixPrint(aListA)
  See nl+">>> RING Matrix Trans  >>>>>>>>>>>>>>>> " +nl
  
  aListC = MatrixTrans(aListA)   // <<<===  

  See "RESULT RING MatrixTrans C"  MatrixPrint(aListC)
			  
//====================================


See nl+"#================================a========"+nl+nl
See "FastPro FastPro MatrixTranspose A => C "+nl

aListA = [1:5,
          1:5,
          1:5,
          1:5,
          1:5]
         		  
//======================================
// FastPro Transpose Matrix

  See "FastPro Transpose Matrix  A=>C "  MatrixPrint(aListA)
  See nl+">>> FastPro Transpose Matrix >>>>>>>>>>>>>>>> " +nl
  
  aListC = updateList(aListA,:transpose,:matrix )  // <<<<<===
 
  See "RESULT FastPro Transpose Matrix C"  MatrixPrint(aListC) 
  
//=======================================

See nl+"FINISHED TESTING"+nl
See "========================="+nl

///////////////////////////////////////////////

// SPEED RING ScalarMultipl() 
	
X = 500 Y = 500  
k = 9
See nl+"SPEED TESTING  TRANSPOSE: "+X +"x"+Y   +nl

aListA = list(X,Y)


for i = 1 to X
for j = 1 to Y
    aListA[i][j] = i + j +1
next
next	

//See "aListA Init" MatrixPrint(aListA)

  startClock = clock()	
aListC = MatrixTrans(aListA)   // <<<===   
	
  stopClock  = clock()	
  diffClock  = stopClock - startClock
  See "RING Transpose  Time: "+ diffClock +nl
  
//See "ScalarMultiply C out"  matrixPrint(aListC)
 
//==================================== 
// SPEED FastPro Transpose Matrix 
	
aListB = list(X,Y)

for i = 1 to X
for j = 1 to Y
    aListB[i][j] = i + j +1
next
next	

//See "aListB Init" MatrixPrint(aListB)

  startClock = clock()	
  aListC = updateList(aListA,:transpose,:matrix )  // <<<<<===  	

  stopClock  = clock()	
  diffClock  = stopClock - startClock
  See "FastPro Transpose Matrix  Time: "+ diffClock +nl
  
  
//See "Scalar Matrix C out"   MatrixPrint(aListC) 

///////////////////////////////////////////







//=============================================
//=============================================

Func Matrixtrans matrix
	rows = len(matrix)
	cols = len(matrix[1])	
	transpose = newlist(cols,rows)
	for i = 1 to cols
		for j = 1 to rows
			transpose[i][j] = matrix[j][i]             
		next         
	next
return transpose



//=============================================
// Bert Mariani 03/18/2023
// MatrixPrint(A)
// Display a Matrix Array by Row and Col size

Func MatrixPrint(U)

 See "      MatrixPrint:"
 Row = len(U)     See " "+ Row      // Rows 
 Col = len(U[1])  See "x"+ Col +nl  // Cols 
                           
 for h = 1 to Row
   See "| "
   for v = 1 to Col
     Num = U[h][v]
     if (Num >= 0) See " " ok       // 2 places
     See Num  
     if v != Col   See "," ok       // Comma between numbers
   next
   See " |"+nl
 next
   See nl
   
return
//=============================================

//=============================================
// Bert Mariani 03/18/2023
// MatrixFlatPrint(U)
// Display a Matrix Array by Row and Col size

Func MatrixFlatPrint(U)

 See "      MatrixFlatPrint:"
 Row = len(U)     See " "+ Row +nl   // Row 

 for h = 1 to Row
    See " "+ U[h] +","
 next
   See nl+nl

return
//============================================

//============================================
// Alternate Name -- Code from StdLibCore

Func Matrixmultiply(A, B)

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
			next
			
			C[va][hB] = Sum          
		next
	next
return C     


//===============================	

