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

aListC = LeakyReLUPrime(aListA)
see "Ring LeakyReLu "  MatrixPrint(aListC)

//==================================
// FastPro

aListC = updatelist( aListA,:leakyreluprime,:matrix)
see "FastPro LeakyReLu "  MatrixPrint(aListC)

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
aListC = LeakyReLUPrime(aListA)
t2   = clock()
Diff = t2 -t1

See "RING LeakyReLuPrime "+X +"x"+Y +" Time "+ Diff +" millisecs"+nl
// see "Ring LeakyReLuPrime "  MatrixPrint(aListC)


//==================================

t1   = clock()
aListC = updatelist( aListA,:leakyreluprime,:matrix)
t2   = clock()
Diff = t2 -t1

See "FastPro LeakyReLuPrime "+X +"x"+Y +" Time "+ Diff +" millisecs"+nl

//see "FastPro LeakyReLuPrime "  MatrixPrint(aListC)




//===================================
//===================================

    func MLeakyReLUPrime (input) { 
        if input < 0 { 
            Output = 0.01
            return Output
        else
            Output = 1
            return Output
        } 
    } 

//===================================

//===================================

    func LeakyReLUPrime (Matrix) { 
        aTanhPrime = Matrix
        
        if len(Matrix) = 1 { 
            aTanhPrime = list(1,len(Matrix[1]))
            for v = 1 to len(Matrix[1]) { 
                aTanhPrime[1][v] = MLeakyReLUPrime(Matrix[1][v])
            } 
            return aTanhPrime
            
            elseif len(Matrix[1]) = 1
                aTanhPrime = list(len(Matrix),1)
                for v = 1 to len(Matrix) { 
                    aTanhPrime[v][1] = MLeakyReLUPrime(Matrix[v][1])
                } 
                return aTanhPrime
                
            else
                for v = 1 to len(Matrix) { 
                    for h = 1 to len(Matrix[1]) { 
                        aTanhPrime[v][h] = MLeakyReLUPrime(Matrix[v][h])
                    } 
                } 
                return aTanhPrime
        } 
    } 

//===================================
