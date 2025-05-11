# Author: Bert Mariani 

load "matrixlib.ring"
load "fastpro.ring"

Decimals(2) 
 
          
aListA = [[-1,  -2,   3],
          [-4,  -5,   6],
          [-7,  -8,   9],
          [-1.0,-1.1, 2],
          [-5,  -8,  -9]]         
    
           
See"aListA " MatrixPrint(aListA)

//==================================
// Ring

aListC = ReLuPrime(aListA)
see "Ring ReLuPrime "  MatrixPrint(aListC)

//==================================
// FastPro

aListC = updatelist( aListA,:ReLuPrime,:matrix)
see "FastPro ReLuPrime "  MatrixPrint(aListC)

//====================================
//====================================
// SPEED TEST

X = 900
Y = 900
aListA = list(X,Y)

updateList(aListA,:random,:matrix )       // 0.00 to 1.00
updateList(aListA,:sub,:manycols,1,Y,0.5)  // make some minus

aListA = updateList(aListA,:scalar,:matrix,100 ) 
//See"aListA " MatrixPrint(aListA)

//=================================

t1   = clock()
aListC = ReLuPrime(aListA)
t2   = clock()
Diff = t2 -t1

See "RING ReLuPrime "+X +"x"+Y +" Time "+ Diff +" millisecs"+nl
// see "Ring ReLuPrime "  MatrixPrint(aListC)


//==================================

t1   = clock()
aListC = updatelist( aListA,:reluprime,:matrix)
t2   = clock()
Diff = t2 -t1

See "FastPro ReLuPrime "+X +"x"+Y +" Time "+ Diff +" millisecs"+nl

//see "FastPro ReLuPrime "  MatrixPrint(aListC)




//===================================
//===================================


	func MReLuPrime (input) { 
		if input < 0 { 
			Output = 0
			return Output
		else
			Output = 1
			return Output
		} 
	}
 //===================================
 
 //===================================

	func ReLuPrime (Matrix) { 
		aReLuPrime = Matrix
		
		if len(Matrix) = 1 { 
			aReLuPrime = list(1,len(Matrix[1]))
			for v = 1 to len(Matrix[1]) { 
				aReLuPrime[1][v] = MReLuPrime(Matrix[1][v])
			} 
			return aReLuPrime
			
			elseif len(Matrix[1]) = 1
				aReLuPrime = list(len(Matrix),1)
				for v = 1 to len(Matrix) { 
					aReLuPrime[v][1] = MReLuPrime(Matrix[v][1])
				} 
				return aReLuPrime
				
			else
				for v = 1 to len(Matrix) { 
					for h = 1 to len(Matrix[1]) { 
						aReLuPrime[v][h] = MReLuPrime(Matrix[v][h])
					} 
				} 
				return aReLuPrime
		} 
	} 

//===================================
 
    func MReLu (input) { 
        if input < 0 { 
            Output = 0
            return Output
        else
            Output = input
            return Output
        } 
    } 
//===================================

    func ReLu (Matrix) { 
        aTanh = Matrix
        for v = 1 to len(aTanh) { 
            for h = 1 to len(aTanh[1]) { 
                aTanh[v][h] = MReLu(Matrix[v][h])
            } 
        } 
        return aTanh
    } 

//===================================
