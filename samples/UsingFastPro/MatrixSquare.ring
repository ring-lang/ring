#Author: Bert Mariani

load "matrixlib.ring"
load "fastpro.ring"

aListA =  [1:5,
           6:10,
           12:16,
           22:26]
           
See"aListA " MatrixPrint(aListA)

//----------------------

aListC = Square(aListA)

See "RING Square  : "  MatrixPrint(aListC)


//=================================
         
aListC = updateList(aListA,:square,:matrix )
See "FASTPRO Square Matrix "  
MatrixPrint(aListC)


//==================================
//==================================
// Speed Time

X = 900
Y = 900
aListA = list(X,Y)

updateList(aListA,:random,:matrix )

//--------------------
// RING Square

   Start = clock()
aListC = Square(aListA)
   Stop  = clock()
   Diff  = Stop - Start
  
See "RING ...Square: "+X +"x"+Y +" Speed Test: "+Diff +" millisecs"+nl 
//MatrixPrint(aListC)

//----------------------
// FASTPRO SQuare

   Start = clock()
aListC = updateList(aListA,:square,:matrix )
   Stop  = clock()
   Diff  = Stop - Start

See "FASTPRO Square: "+X +"x"+Y +" Speed Test: "+Diff +" millisecs"+nl 
//MatrixPrint(aListC)

//-------------------



//=======================================
//=======================================


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
