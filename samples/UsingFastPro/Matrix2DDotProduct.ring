load "fastpro.ring"
load "matrixlib.ring"

alistA = [[1,2],   
          [3,4]]
	 
alistB = [[5,6], 
          [7,8]] 
				 

alistD = [[17,23],
          [39,53]]
	 
    See nl+"======================="+nl
	
aListC = updateList(aListA,:dotproduct,:matrix,aListB) 

   See "aListC Output  result" MatrixPrint(alistD)
   See "aListD Correct result" MatrixPrint(alistd)

    See nl+"======================="+nl   
   
//============================================
  
aListA = [[1,2,3,4,5],
          [1,2,3,4,5],
          [1,2,3,4,5],
          [1,2,3,4,5],
          [1,2,3,4,5]]
		  
aListB = [[1,2,3,4,5],
          [1,2,3,4,5],
          [1,2,3,4,5],
          [1,2,3,4,5],
          [1,2,3,4,5]]
				
     See nl+"======================="+nl
	 
See "aListA"  MatrixPrint(aListA)
See "aListB"  MatrixPrint(aListB)
 
    See nl+"======================="+nl 
	
MatrixC = MultDot(aListA,aListB)

   See "MultDot MatrixC" MatrixPrint(MatrixC) 

    See nl+"======================="+nl
	
aListC  = updateList(aListA,:dotproduct,:matrix,aListB)  

   See "FastPro aListC"  MatrixPrint(aListC)  
 
//=====================================
//=====================================
// SPEED 

X = 200
Y = 200

aListA = list(X,Y)
aListB = list(X,Y)

for i = 1 to X 
for j = 1 to Y
   aListA[i][j] = i +j +1
   aListB[i][j] = i +j +2
next
next


    See nl+"======================="+nl
	See nl+"=== Speed Test 2D DotProduct  Array: "+X +"x"+Y +nl
	
   StartClk = clock()
MatrixC = MultDot(aListA,aListB)
   StopClk = clock()
   See "MultDot Speed Test:"+ (stopClk - StartClk) +" millesecs" +nl 
 
   StartClk = clock()
aListC  = updateList(aListA,:dotproduct,:matrix,aListB) 
   StopClk = clock()
   See "FastPro Speed Test:"+ (stopClk - StartClk) +" millesecs" +nl 


   
  
////////////////////////////////////
////////////////////////////////////

//Author : Azzeddine Remmal

Func MultDot (MatrixA,MatrixB) { 
		vertA = len(MatrixA)
		horzA = len(MatrixA[1])
		vertB = len(MatrixB)
		horzB = len(MatrixB[1])
		vertC = len(MatrixA)
		horzC = len(MatrixB)
		
		MulMatrix = list(vertA,horzB)
		#Make array bigV and bigH
		if horzA! = vertB { 
			? "Error: Cant Multiply the Matrix dimension: Horz-A:"+horzA+" MUST EQUAL vert-B:"+vertB
			? "dimension-A:"+vertA+"X"+horzA+"-----"+"dimension-B:"+vertB+"X"+horzB
			return 
		} 
		for v = 1 to vertA { 
			for h = 1 to horzB { 
				Sum = 0
				for k = 1 to horzA { 
					Sum += MatrixA[v][k]*MatrixB[k][h]
				} 
				MulMatrix[v][h] = Sum
			} 
		} 
		return MulMatrix
	} 
