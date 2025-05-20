# Author: Bert Mariani

load "matrixlib.ring"
load "fastpro.ring"

           
aListA = [1:5,
          2:6,
          3:7,
          4:8,
          5:9,
		  6:10]
		  

See "aListA: "   MatrixPrint(aListA)


//==================================
// Ring

sum = AllSum (aListA) 
See "Ring AllSum:  Sum: "+Sum +nl   

//--------------------
// FastPro

//Index = updatelist(aListA,:argmax,:matrix)
sum     = updatelist(aListA,:allsum,:matrix)
See     "FastPro AllSum: AllSum:  Sum: "+Sum +nl 


//====================================
//====================================
// SPEED TEST

X = 900
Y = 900

aListA = list(X,Y)
         updateList(aListA,:random,:matrix )    // 0.00 to 1.00
aListA = updateList(aListA,:scalar,:matrix,10 ) // Mul by 10


//=================================
// RING

         t1   = clock()
sum = AllSum (aListA) 
         t2   = clock()
         Diff = t2 -t1

See nl+"Ring AllSum:  Sum: "+Sum  +"  "+X +"x"+Y +" Time "+ Diff +" millisecs"+nl



//==================================
// FastPro

         t1 = clock()
sum = updatelist(aListA,:AllSum,:matrix)
         t2   = clock()
         Diff = t2 -t1

See "FastPro AllSum:  Sum: "+Sum +"  "+X +"x"+Y  +" Time "+ Diff +" millisecs"+nl



//===================================
//===================================


See nl+"FINISHED"+nl

//===================================
//===================================

//===================================
//===================================

	func AllSum (Matrix) { 
		aArithmeticMean = Matrix
		aSum = []                  // Flat
		
		for v = 1 to len(aArithmeticMean) {          // Row
			for h = 1 to len(aArithmeticMean[1]) {   // Col
				aSum + aArithmeticMean[v][h]         // Add to Flat array
			} 
		} 
		Sum = 0
		for x = 1 to len(aSum) { 
			Sum += aSum[x]
		} 
		return Sum
	} 

//=============================================
