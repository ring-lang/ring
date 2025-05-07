# Author: Bert Mariani

load "matrixlib.ring"
load "fastpro.ring"
//
//  σ    = 1 / 1+(e−x)
//  σ(x) = (e−x) / ((e−x)+1)
//  x is the input value,
//  e is Euler’s number(≈2.718)
//
   
 Decimals(4) 
 
aListA = [[0.1,0.2,0.3],
          [0.4,0.5,0.6],
          [0.7,0.8,0.9],
          [1.0,1.1,1.2],
		  [5,  8,  9]]
           
See"aListA " MatrixPrint(aListA)

//----------------------

aListC = Sigmoid(aListA) 
See "RING Sigmoid  : "  MatrixPrint(aListC)

//-----------------------

aListC = updateList(aListA,:sigmoid,:matrix )
See "FASTPRO Sigmoid Matrix "  MatrixPrint(aListC)


//==================================
//==================================

//==================================
// Speed Time



X = 900
Y = 900
aListA = list(X,Y)

updateList(aListA,:random,:matrix )

//--------------------
// RING Sigmoid

   Start = clock()
aListC = Sigmoid(aListA)
   Stop  = clock()
   Diff  = Stop - Start
  
See "RING ...Sigmoid: "+X +"x"+Y +" Speed Test: "+Diff +" millisecs"+nl 
//MatrixPrint(aListC)

//----------------------
// FASTPRO SQuare

   Start = clock()
aListC = updateList(aListA,:sigmoid,:matrix )
   Stop  = clock()
   Diff  = Stop - Start

See "FASTPRO Sigmoid: "+X +"x"+Y +" Speed Test: "+Diff +" millisecs"+nl 
//MatrixPrint(aListC)

//-------------------


//=======================================
//=======================================


	func Sigmoid (Matrix) { 

		#--------------------------------------------------------------
		#The MatrixSigmoid() is a mathematical function used to find
		#the exponential values of all the elements present in the input Matrix.
		#--------------------------------------------------------------

		aSigmoid = Matrix
		for v = 1 to len(aSigmoid) { 
			for h = 1 to len(aSigmoid[1]) { 

//See " "+ Matrix[v][h]
				aSigmoid[v][h] = 1 / (1 + exp(-Matrix[v][h]))
			} 
		} 
		return aSigmoid
	} 



    func Square (Matrix) { 
        aSquare = Matrix
        for v = 1 to len(aSquare) { 
            for h = 1 to len(aSquare[1]) { 
                aSquare[v][h] = pow(Matrix[v][h],2)
            } 
        } 
        return aSquare
    }

    func Mean (Matrix) { 
        aArithmeticMean = Matrix
        aSum = []
        
        for v = 1 to len(aArithmeticMean) { 
            for h = 1 to len(aArithmeticMean[1]) { 
                aSum + aArithmeticMean[v][h]
            } 
            //see "aSum: " MatrixFlatPrint(aSum)
        } 
        Sum = 0
        #? ToCode(aSum)
        for x = 1 to len(aSum) { 
            Sum += aSum[x]
            //See "Sum: "+Sum +nl
        } 
        return Sum/ len( aSum ) 
    } 
    
    
    func Msqrt (Matrix) { 
        aSquare = Matrix
        for v = 1 to len(aSquare) { 
            for h = 1 to len(aSquare[1]) { 
                aSquare[v][h] = sqrt(Matrix[v][h])
            } 
        } 
        return aSquare
    } 
