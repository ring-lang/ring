# Author: Bert Mariani

load "matrixlib.ring"
load "fastpro.ring"

		   
aListA = [6,5,1,2,3,4,5,6,7]

See "aListA:  Flat R:"+len(aListA)  +nl                               
MatrixFlatPrint(aListA)

//==================================
// Ring

aListC = Atleast2d( aListA)
See nl+"Ring Atleast2d Matrix aListC R-C"  MatrixPrint(aListC)


// FastPro

aListC = updatelist(aListA,:atleast2d,:matrix)
See nl+"FastPro AtLeast2D"  MatrixPrint(aListC)


//====================================
//====================================
// SPEED TEST


X = 900
Y = 900
Size   = X*Y
aListA = 1:Size  // Flat List

//=================================
// RING

         t1   = clock()
aListC = Atleast2d( aListA)
         t2   = clock()
         Diff = t2 -t1

See "RING AtLeast2D "+X +"x"+Y +" Time "+ Diff +" millisecs"+nl
//See "Ring AtLeast2D "  MatrixPrint(aListC)


//==================================
// FastPro

         t1 = clock()
aListC = updatelist(aListA,:atleast2d,:matrix)
         t2   = clock()
         Diff = t2 -t1

See "FastPro AtLeast2D "+X +"x"+Y  +" Time "+ Diff +" millisecs"+nl
//See "FastPro AtLeast2D "  MatrixPrint(aListC

//===================================
//===================================


See nl+"FINISHED"+nl

//===================================
//===================================

//===================================
// Flat array 1:10  to a 2D [1][array]

	func Atleast2d (aInput) { 
		aAtleast2d = []
		
		for i = 1 to len(aInput) {    // Row
			aAtleast2d + [aInput[i]]
		
		} 
		return aAtleast2d
	} 

//===================================    

