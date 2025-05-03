# Author: Bert Mariani 

load "fastpro.ring"
load "matrixlib.ring"

nSeed = 20
Seed  = 3

vNum = 900
hNum = 900

See nl+"=== Azzedine MRand ======================"+nl

RandSeed (nSeed)

    Start = clock()
aRand = MRand (vNum,hNum)
    Stop  = clock()
	Diff  = Stop - Start

See "Azzedine MRand Speed Test: "+vNum +"x"+ hNum +" Time: "+ Diff +" millesecs" +nl   
//MatrixPrint(aRand)

//============================
//============================

See nl+"=== FastPro Random Matrix ================"+nl

     aListA = list(vNum,hNum)
	 Start = clock()
updateList(aListA,:random,:matrix )
     Stop  = clock()
	 Diff  = Stop - Start
	 
See "FastPro Random Speed Test: "+vNum +"x"+ hNum +" Time: "+ Diff +" millesecs" +nl   
//MatrixPrint(aListA)	 


//================================

	func RandSeed (nSeed) { 
		Seed = nSeed
	} 

	func rand () { 
		x = sin( seed++ ) * 10000
		return x- floor( x ) 
	} 
	

	func MRand (vNum,hNum) { 
		aRand = list(vNum,hNum)
		for v = 1 to vNum { 
			for h = 1 to hNum { 
				aRand[v][h] = Rand()
			} 
		} 
		return aRand
		
	}
