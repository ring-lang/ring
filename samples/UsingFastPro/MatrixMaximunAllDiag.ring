# Author: Bert Mariani

load "matrixlib.ring"
load "fastpro.ring"

// Axis 0=ALL  1=Diagonal

Matrix = [1:5,
          22:62,
          38:34,
          18:22,
          27:31]

See nl+"=== Matrix = ORIG  ==================="+nl
See "Matrix "  MatrixPrint(Matrix)		  
		 

See nl+nl+"=== Matrix = Axis = 0 ALL ============"+nl
Axis   = 0
aListC = Maximum(Matrix,Axis)
See nl+" Axis = 0  ALL = "  See aListC  


See nl+nl+"=== Matrix = Axis = 1 DIAGONAL ========"+nl
Axis   = 1
aListC = Maximum(Matrix,Axis)
See nl+" Axis= 1  DIAGONAL = "   See aListC 


See nl+nl+"======================================"+nl
See "===FASTPRO============================"+nl


See nl+nl+"=== Matrix = Axis = 0 ALL ============"+nl
Axis = 0
valueA = updateList(Matrix,:maximum,:matrix,Axis )
See nl+" Axis = 0  ALL  Value = "+valueA  +nl


See nl+nl+"=== Matrix = Axis = 1 DIAGONAL ========"+nl
Axis   = 1
valueA = updateList(Matrix,:maximum,:matrix,Axis )
See nl+" Axis = 1  DIAGONAL Value = "+valueA +nl 


See nl+nl+"======================================"+nl
See " ===SPEED TEST FASTPRO Axis=0 ALL ============================"+nl

x = 900
Y = 900
Matrix = list(X,Y)

for i = 1 to X
for j = 1 to Y
    Matrix[i][j] = 1 +j +1

next
next

Matrix[x][y]   = 0
Matrix[x][y-2] = 45678



         Axis = 0
         Start = clock()
valueA = updateList(Matrix,:maximum,:matrix,Axis )
         Stop  = clock()
		 
		 Diff = Stop - Start

See nl+"Speed Test: "+diff  +"  millisecs  Axis = 0  ALL  Value = "+ valueA  +nl


//==========================

See nl+nl+"=== AZZEDINE MAXIMUM Matrix = Axis = 0 ALL ============"+nl

         Axis = 0
         Start = clock()
aListC = Maximum(Matrix,Axis)
         Stop  = clock()
		 Diff = Stop - Start

See nl+"Speed Test: "+diff  +"  millisecs  Axis = 0  ALL  Value = "+ valueA  +nl


See nl+nl+"======================================"+nl
See " ===SPEED TEST FASTPRO Axis = 1 Diagonal============================"+nl

x = 900
Y = 900
Matrix = list(X,Y)

for i = 1 to X
for j = 1 to Y
    Matrix[i][j] = 1 +j +1

next
next

Matrix[x][y]   = 0
Matrix[x][y-2] = 45678



         Axis = 1
         Start = clock()
valueA = updateList(Matrix,:maximum,:matrix,Axis )
         Stop  = clock()
		 
		 Diff = Stop - Start

See nl+"Speed Test: "+diff  +"  millisecs  Axis = 1 Diagonal  Value = "+ valueA  +nl


//==========================

See nl+nl+"=== AZZEDINE MAXIMUM Matrix = Axis = 1 Diagonal ============"+nl

         Axis = 1
         Start = clock()
aListC = Maximum(Matrix,Axis)
         Stop  = clock()
		 Diff = Stop - Start

See nl+"Speed Test: "+diff  +"  millisecs  Axis = 1  Diagonal  Value = "+ valueA  +nl



SEE nl+"FINISHED TEST"+nl

//================================
//================================


Func Maximum (Matrix,Axis) { 
	 aMaximum = Matrix
	 aAxis    = []
	
	if !isList(Matrix[1]) { 
		return Max( Matrix ) 
	} 
	
if Axis = 1 { 
	for v = 1 to len(Matrix) { 
		for h = 1 to len(Matrix) { 
			aAxis + aMaximum[v][Axis] // Col 1
			
		} 
		Axis++  // Col++
	} 
	//See"===MAX DIAGONAL ======="+nl
	//See "aAxis " matrixFlatprint(aAxis)
	
	aMaximum = Max(aAxis)
	return aMaximum
	
	elseif Axis = 0
		for v = 1 to len(Matrix) { 
			for h = 1 to len(Matrix[1]) { 
				aAxis + aMaximum[v][h]    // each R-C
			} 
		} 
		
	//See"===MAX IN ARRAY======="+nl
	//See "aAxis " matrixFlatprint(aAxis)				
		
		aMaximum = Max(aAxis)
		return aMaximum
} 
}
