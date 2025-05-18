# Author: Bert Mariani

load "matrixlib.ring"
load "fastpro.ring"

		   
ZaListA = [1:5,
          2:6,
		  3:7,
		  4:8,
		  5:9]
		  
aListA =  [6,7,8,9,5,4,9,1,2]

See "aListA: Flat "+nl                               
MatrixFlatPrint(aListA)

//==================================
// Ring

Index = ArgMax( aListA)
See "Ring ArgMax: Position-Index: "+Index +nl  

// FastPro

Index = updatelist(aListA,:argmax,:matrix)
See "FastPro ArgMax: Position-Index: "+Index +nl


//====================================
//====================================
// SPEED TEST


X = 900
Y = 900
Sum = X * Y
aListA = 9:Sum


//=================================
// RING

See nl+"RING Speed"+nl
         t1   = clock()
Index = ArgMax( aListA)
See nl+"Ret Max Position-Index: "+Index +nl
         t2   = clock()
         Diff = t2 -t1

See "RING ArgMax Position-Index"+X +"x"+Y +" Time "+ Diff +" millisecs"+nl
//See "Ring ArgMax Position-Index"  MatrixFlatPrint(aListA)


//==================================
// FastPro

         t1 = clock()
Index = updatelist(aListA,:argmax,:matrix)
See nl+"Ret Max Position-Index: "+Index +nl
         t2   = clock()
         Diff = t2 -t1

See "FastPro ArgMax Position-Index: "+X +"x"+Y  +" Time "+ Diff +" millisecs"+nl
//See "FastPro ArgMax Position-Index "  MatrixFlatPrint(aListC


//===================================
//===================================


See nl+"FINISHED"+nl

//===================================
//===================================

//===================================

	func argmax (aList) {       // Flat List
		Max = Max(aList)        // max value	
		index = find(aList,Max) // Position index
		
// See "=== Max-value: "+Max +"  Position-Index: "+index +nl+nl		
		return index
	} 
//===================================  

