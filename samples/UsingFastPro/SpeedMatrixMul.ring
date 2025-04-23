# Author: Bert Mariani
#               A,B,=> C    
# Add Matrix   (1,2,   3)        
#  
# updateList(<aList>,:add,:matrix,<Matrix-A>,<Matrix-B>,<matrix-C>)
#
#========================================

? "Loading Library"
load "fastpro.ring"

#================================a========
See "FastPro Mul Matrix vs Ring MatrixMultiply"+nl

X = 500  Y = 500   // <<<<<

aListA = list(X,Y) 
 
aListB = list(X,Y)
          
 
for i = 1 to X
for j = 1 to Y
    aListA[i][j] = i + j
    aListB[i][j] = i + j +2
next
next 
		  
//======================================
// FastPro Mul Matrix

//See "Start MUL A aListA (A*B=>C)"  MatrixPrint(aListA)
//See "Start MUL B aListB (A*B=>)"  MatrixPrint(aListB)

StartClock = clock()

aListC = updateList(aListA,:mul,:matrix, aListB )  // <<<<<

StopClock  = clock()
Time = stopClock - startClock
 
  See nl+nl+">>> FastPro Mul Matrix >>>>>>>>>>>>>>>> AxB=C: "+X +"*"+Y +" = "+ (X*Y) +nl
//See "RESULT FartPro MUL Matrix"  MatrixPrint(aListC)
  See "Speed: Time: "+ Time +" milliSecs"+ nl

//=======================================


//==a====================================
// Ring MatrixMultiply

tartClock = clock()

aListC = MatrixMultiply( aListA, aListB )  // <<<<<

StopClock  = clock()
Time = stopClock - startClock

  See nl+nl+">>> Ring MatrixMultiply >>>>>>>>>>>>>>>> AxB=C: "+X +"*"+Y +" = "+ (X*Y) +nl
//See "RESULT  C aListC (A*B)"  MatrixPrint(aListC)
  See "Speed: Time: "+ Time +" milliSecs"+ nl




#========================================

See nl+"FINISHED TESTING"+nl


//=============================================
//=============================================
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

