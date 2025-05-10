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

aListC = ReLU(aListA)
see "Ring ReLu "  MatrixPrint(aListC)

//==================================
// FastPro

aListC = updatelist( aListA,:relu,:matrix)
see "FastPro ReLu "  MatrixPrint(aListC)

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
aListC = ReLU(aListA)
t2   = clock()
Diff = t2 -t1

See "RING ReLu "+X +"x"+Y +" Time "+ Diff +" millisecs"+nl
// see "Ring ReLu "  MatrixPrint(aListC)


//==================================

t1   = clock()
aListC = updatelist( aListA,:leakyreluprime,:matrix)
t2   = clock()
Diff = t2 -t1

See "FastPro ReLu "+X +"x"+Y +" Time "+ Diff +" millisecs"+nl

//see "FastPro ReLu "  MatrixPrint(aListC)




//===================================
//===================================

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
