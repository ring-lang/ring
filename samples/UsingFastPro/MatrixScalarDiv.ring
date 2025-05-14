# Author: Bert Mariani 

load "matrixlib.ring"
load "fastpro.ring"

Decimals(2) 
 
          
	   
		   
aListA = [ 1:5,
           2:6,
           3:7,
           4:8,
           5:9]          
     
See"aListA " MatrixPrint(aListA)

//==================================
// Ring

number = 3
aListC = DivByNum (aListA,number)
see "Ring DivByNum "  MatrixPrint(aListC)

// FastPro

aListC = updateList(aListA,:scalardiv,:matrix, number)
see "FastPro ScalarDiv "  MatrixPrint(aListC)

//==================================


//====================================
//====================================
// SPEED TEST


X = 500
Y = 500
aListA = list(X,Y)

         updateList(aListA,:random,:matrix )  // 0.00 to 1.00
aListA = updateList(aListA,:scalar,:matrix,10 ) 
//See " Generate aListA " MatrixPrint(aListA)


//==================================
// FastPro

         t1 = clock()
aListC = updateList(aListA,:scalardiv,:matrix, number)
         t2   = clock()
         Diff = t2 -t1

See "FastPro DivByNum "+X +"x"+Y  +" Time "+ Diff +" millisecs"+nl
//See "FastPro Sum "  MatrixPrint(aListC)



//=================================
// RING

         t1   = clock()
DaListC = DivByNum (aListA,number)
         t2   = clock()
         Diff = t2 -t1

See "RING DivByNum "+X +"x"+Y +" Time "+ Diff +" millisecs"+nl
//See "Ring Softmax "  MatrixPrint(aListC)



//===================================
//===================================


See nl+"FINISHED"+nl

//===================================
//===================================


//===================================
	
 	func DivByNum (Matrix,num) { 
 		aDivMatrix = Matrix
 		if len(Matrix[1]) = 1 { 
 			for v = 1 to len(Matrix) { 
 				aDivMatrix[v][1] = Matrix[v][1]/num
 			} 
 			elseif len(Matrix) = 1
 				for h = 1 to len(Matrix[1]) { 
 					aDivMatrix[1][h] = Matrix[1][h]/num
 				} 
 			else
 				for v = 1 to len(Matrix) { 
 					for h = 1 to len(Matrix[v]) { 
 						aDivMatrix[v][h] = Matrix[v][h]/num
 					} 
 				} 
 		} 
 		return aDivMatrix
 	} 
	
//==================================
//===================================

 
