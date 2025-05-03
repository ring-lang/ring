# Author: Bert Mariani

load "matrixlib.ring"
load "fastpro.ring"

// IdentityMatrix


See nl+"=== FastPro IDENTITY ======================="+nl

X = 900
Y = 900

aListA = list(X,Y)

   // See "aListA "  MatrixPrint(aListA)

   StartClk = clock()
updateList(aListA,:identity,:matrix)
   StopClk = clock()
   See "Speed Test: "+ (stopClk - StartClk) +" millisecs" +nl 
   
   See "Identity aListA "+ X +"x"+Y +" with  Diagonal 1's "  
   // MatrixPrint(aListA)
   
 
See nl+"=== Azzedine IDENTITY ======================="+nl

X = 900
Y = 900


   StartClk = clock()
aIdentity = Identity (X) 
   StopClk = clock()
   See "Speed Test: "+ (stopClk - StartClk) +" millisecs" +nl 
   
   See "Azzedine Identity aListA "+ X +"x"+Y +" with  Diagonal 1's "  
   //MatrixPrint(aIdentity) 
   
   

//=====================================



func Identity (Num) { 
		aIdentity = Zeros(Num,Num)
		for v = 1 to Num { 
			aIdentity[v][v] = 1
		} 
		return aIdentity
	} 


func Zeros (vNum,hNum) { 
		aZeros = list(vNum,hNum)
		for v = 1 to vNum { 
			for h = 1 to hNum { 
				aZeros[v][h] = 0
			} 
		} 
		return aZeros
	} 
