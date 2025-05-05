# Author: Bert Mariani

load "matrixlib.ring"
load "fastpro.ring"


Matrix =  [1:5,
           6:10,
           12:16,
           22:26]
           
See"Matrix " MatrixPrint(Matrix)

//----------------

value = Mean( Matrix)

See "RING    value: "+value +nl

//==================================

value = updateList(Matrix,:mean,:matrix )

See "FASTPRO value: "+value +nl+nl


//==================================
// Gen RANDOM list

X = 900
Y = 900

aListA = list(X,Y)
updateList(aListA,:random,:matrix )

//--------------------
// RING MEAN

   Start = clock()
value = Mean(aListA)
   Stop  = clock()
   Diff  = Stop - Start
  
See "RING...: value: "+value +"  "+X +"x"+Y +" Speed Test: "+Diff +" millisecs"+nl 

//----------------------
// FASTPRO MEAN

   Start = clock()
updateList(aListA,:mean,:matrix )
   Stop  = clock()
   Diff  = Stop - Start

See "FASTPRO: value: "+value +"  "+X +"x"+Y +" Speed Test: "+Diff +" millisecs"+nl 

//-------------------
//See nl+"aListA "+nl  MatrixPrint(aListA)


//=======================================
//=======================================


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
