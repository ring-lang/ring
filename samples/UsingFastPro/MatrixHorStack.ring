# Author: Bert Mariani

load "matrixlib.ring"
load "fastpro.ring"

Decimals(2) 
 
           
aListA = [ 1:5,
           2:6,
           3:7,
           4:8,
           5:9]   

aListB = [ 6:10,
           7:11,
           8:12,
           9:13,
           10:14]
		   
     
See"aListA " MatrixPrint(aListA)
See"aListB " MatrixPrint(aListB)

//==================================
// Ring

aListC = HorStack ( aListA, aListB)
see " Ring HorStack"  MatrixPrint(aListC)



// FastPro

aListC = updatelist(aListA,:horstack,:matrix,aListB)
see "FastPro HorStack"  MatrixPrint(aListC)


//==================================


//====================================
//====================================
// SPEED TEST


X = 1000
Y = 1000
aListA = list(X,Y)

         updateList(aListA,:random,:matrix )  // 0.00 to 1.00
aListA = updateList(aListA,:scalar,:matrix,10 ) 
aListB = updateList(aListA,:scalar,:matrix,2 )

//See " Generate aListA " MatrixPrint(aListA)


//==================================

// FastPro

         t1 = clock()
aListC = updatelist(aListA,:horstack,:matrix,aListB)
         t2   = clock()
         Diff = t2 -t1

See "FastPro HorStack "+X +"x"+Y  +" Time "+ Diff +" millisecs"+nl
//See "FastPro Sum "  MatrixPrint(aListC


//=================================
// RING

         t1   = clock()
aListC = HorStack ( aListA, aListB)
         t2   = clock()
         Diff = t2 -t1

See "RING HorStack "+X +"x"+Y +" Time "+ Diff +" millisecs"+nl
//See "Ring Softmax "  MatrixPrint(aListC)



//===================================
//===================================


See nl+"FINISHED"+nl

//===================================
//===================================

	func HorStack (MatrixA,MatrixB) { 
		aHorStack = MatrixA
		for i = 1 to len(MatrixB) { 
			for j = 1 to len(MatrixB[1]) { 
				aHorStack[i] + MatrixB[i][j]
			} 
		} 
		return aHorStack
	}

	
