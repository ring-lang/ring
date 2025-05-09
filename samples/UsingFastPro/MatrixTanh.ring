# Author: Bert Mariani

load "matrixlib.ring"
load "fastpro.ring"
   
Decimals(4) 
 
aListA = [1:5,
          2:6,
          3:7,
          4:8,
		  5:9]
           
See"aListA " MatrixPrint(aListA)

//----------------------

aListC = MTanh(aListA) 
See "RING MTanh  : "  MatrixPrint(aListC)

//-----------------------

aListC = updateList(aListA,:tanh,:matrix )
See "FASTPRO Tanh Matrix "  MatrixPrint(aListC)

//-----------------------

//==================================
//==================================

//==================================
// Speed Time

X = 900
Y = 900
aListB = list(X,Y)

updateList(aListB,:random,:matrix )
aListA = updateList(aListB,:scalar,:matrix, 100 )

//--------------------
// RING MTanh

   Start = clock()
aListC = Mtanh(aListA)
   Stop  = clock()
   Diff  = Stop - Start
  
See "RING ...Mtanh: "+X +"x"+Y +" Speed Test: "+Diff +" millisecs"+nl 
//MatrixPrint(aListC)

//----------------------
// FASTPRO SigmoidPrime

   Start = clock()
aListC = updateList(aListA,:tanh,:matrix )
   Stop  = clock()
   Diff  = Stop - Start

See "FASTPRO Tanh: "+X +"x"+Y +" Speed Test: "+Diff +" millisecs"+nl 
//MatrixPrint(aListC)

//-------------------


See "Finished"+nl

//=======================================
//=======================================

	func MTanh (Matrix) { 

		#--------------------------------------------------------------
		#The hyperbolic tangent of an angle x is the ratio of the hyperbolic sine and hyperbolic cosine.
		#tanh ( x ) = sinh ( x ) cosh ( x ) = e 2 x − 1 e 2 x + 1 .
		#In terms of the traditional tangent function with a complex argument,
		#the identity is. tanh ( x ) = − i tan ( i x )
		#--------------------------------------------------------------


		aTanh = Matrix
		for v = 1 to len(aTanh) { 
			for h = 1 to len(aTanh[1]) { 
				aTanh[v][h] = tanh(Matrix[v][h])
			} 
		} 
		return aTanh
	} 



