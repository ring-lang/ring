# Author: Bert Mariani 

load "matrixlib.ring"
load "fastpro.ring"

Decimals(2) 
 
          
aListA = [ 1:5,
           3:7,
           9:13,
           15:19,
           [0.1, 0.2, 0.3, 0.4, 0.5]] 
     
See"aListA " MatrixPrint(aListA)

//==================================
// Ring

aListC = MExp(aListA)
see "Ring MExp "  MatrixPrint(aListC)

//==================================
// FastPro

aListC = updatelist( aListA,:exp,:matrix)
see "FastPro Exp "  MatrixPrint(aListC)

//====================================
//====================================
// SPEED TEST

X = 900
Y = 900
aListA = list(X,Y)

updateList(aListA,:random,:matrix )       // 0.00 to 1.00
aListA = updateList(aListA,:scalar,:matrix,100 ) 
//See"aListA " MatrixPrint(aListA)

//=================================

t1   = clock()
aListC = MExp(aListA)
t2   = clock()
Diff = t2 -t1

See "RING MExp "+X +"x"+Y +" Time "+ Diff +" millisecs"+nl
// see "Ring MEXP "  MatrixPrint(aListC)


//==================================

t1   = clock()
aListC = updatelist( aListA,:exp,:matrix)
t2   = clock()
Diff = t2 -t1

See "FastPro Exp"+X +"x"+Y +" Time "+ Diff +" millisecs"+nl

//see "FastPro Exp "  MatrixPrint(aListC)


//===================================
//===================================

//===================================

    func MExp (Matrix) { 
        aExp = Matrix
        for v = 1 to len(aExp) { 
            for h = 1 to len(aExp[1]) { 
                aExp[v][h] = exp(Matrix[v][h])
            } 
        } 
        return aExp
    } 

//===================================