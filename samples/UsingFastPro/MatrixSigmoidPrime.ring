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
 
aListA = [1:5,
          2:6,
          3:7,
          4:8,
		  5:9]
           
See"aListA " MatrixPrint(aListA)

//----------------------

aListC = SigmoidPrime(aListA) 
See "RING SigmoidPrime  : "  MatrixPrint(aListC)

aListC = updateList(aListA,:sigmoidprime,:matrix )
See "FASTPRO SigmoidPrime Matrix "  MatrixPrint(aListC)

//-----------------------

aListA = [[1],
          [2],
          [3],
          [4],
		  [5]]

See"aListA  " MatrixPrint(aListA)

//----------------------

aListC = SigmoidPrime(aListA) 
See "RING SigmoidPrime  : "  MatrixPrint(aListC)

aListC = updateList(aListA,:sigmoidprime,:matrix )
See "FASTPRO SigmoidPrime Matrix "  MatrixPrint(aListC)

//-----------------------

aListA = [6:10]

See"aListA  " MatrixPrint(aListA)

//----------------------

aListC = SigmoidPrime(aListA) 
See "RING SigmoidPrime  : "  MatrixPrint(aListC)

aListC = updateList(aListA,:sigmoidprime,:matrix )
See "FASTPRO SigmoidPrime Matrix "  MatrixPrint(aListC)


//==================================
//==================================

//==================================
// Speed Time

X = 900
Y = 900
aListA = list(X,Y)

updateList(aListA,:random,:matrix )
aListB = updateList(aListA,:scalar,:matrix, 100 )

//--------------------
// RING SigmoidPrime

   Start = clock()
aListC = Sigmoid(aListB)
   Stop  = clock()
   Diff  = Stop - Start
  
See "RING ...SigmoidPrime: "+X +"x"+Y +" Speed Test: "+Diff +" millisecs"+nl 
//MatrixPrint(aListC)

//----------------------
// FASTPRO SigmoidPrime

   Start = clock()
aListC = updateList(aListB,:sigmoidprime,:matrix )
   Stop  = clock()
   Diff  = Stop - Start

See "FASTPRO SigmoidPrime: "+X +"x"+Y +" Speed Test: "+Diff +" millisecs"+nl 
//MatrixPrint(aListC)

//-------------------


See "Finished"+nl

//=======================================
//=======================================


	func SigmoidPrime (Matrix) { 

		#--------------------------------------------------------------
		#The MatrixSigmoidPrime() is a mathematical function used to find
		#the derivative exponential values of all the elements present in the input Matrix.
		#--------------------------------------------------------------

		aSigmoidPrimeMatrix = Matrix
		if len(Matrix) = 1 { 
			aSigmoidPrimeMatrix = list(1,len(Matrix[1]))
			
			for v = 1 to len(Matrix[1]) { 
				aSigmoidPrimeMatrix[1][v] = Matrix[1][v]*(1-Matrix[1][v])
			} 
			return aSigmoidPrimeMatrix
			
			elseif len(Matrix[1]) = 1
				aSigmoidPrimeMatrix = list(len(Matrix),1)
				for v = 1 to len(Matrix) { 
					aSigmoidPrimeMatrix[v][1] = Matrix[v][1]*(1-Matrix[v][1])
				} 
				return aSigmoidPrimeMatrix
				
			else
				for v = 1 to len(Matrix) { 
					for h = 1 to len(Matrix[1]) { 
						aSigmoidPrimeMatrix[v][h] = Matrix[v][h]*(1-Matrix[v][h])
					} 
				} 
				return aSigmoidPrimeMatrix
		} 
	} 

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
