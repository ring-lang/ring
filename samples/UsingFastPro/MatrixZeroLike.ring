# Author: Bert Mariani

load "matrixlib.ring"
load "fastpro.ring"

Decimals(2) 
 
           
aListA = [ 1:5,
           2:6,
           3:7,
           4:8,
           5:9,
           6:10]   
           
                       
See"aListA " MatrixPrint(aListA)

//==================================
// Ring

aListC = ZeroLike ( aListA)
see nl+"Ring ZeroLike Matrix aListC"  MatrixPrint(aListC)


// FastPro

aListC = updatelist(aListA,:zerolike,:matrix)
see nl+"FastPro ZeroLike"  MatrixPrint(aListC)


//====================================
//====================================
// SPEED TEST


X = 900
Y = 900
aListA = list(X,Y)


//==================================

// FastPro

         t1 = clock()
aListC = updatelist(aListA,:zerolike,:matrix)
         t2   = clock()
         Diff = t2 -t1

See "FastPro ZeroLike "+X +"x"+Y  +" Time "+ Diff +" millisecs"+nl
//See "FastPro ZeroLike "  MatrixPrint(aListC


//=================================
// RING

         t1   = clock()
aListC = ZeroLike( aListA)
         t2   = clock()
         Diff = t2 -t1

See "RING ZeroLike "+X +"x"+Y +" Time "+ Diff +" millisecs"+nl
//See "Ring ZeroLike "  MatrixPrint(aListC)

 
//===================================
//===================================


See nl+"FINISHED"+nl

//===================================
//===================================


	func ZeroLike (Matrix) { 
		aZeroLike = Matrix
		for i = 1 to len(Matrix) { 
			for j = 1 to len(Matrix[1]) { 
				aZeroLike[i][j] = 0
			} 
		} 
		return aZeroLike
	}
