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

aListC = LeakyReLU(aListA)
see "Ring LeakyReLu "  MatrixPrint(aListC)

//==================================
// FastPro

aListC = updatelist( aListA,:leakyrelu,:matrix)
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
aListC = LeakyReLU(aListA)
t2   = clock()
Diff = t2 -t1

See "RING LeakyReLu "+X +"x"+Y +" Time "+ Diff +" millisecs"+nl
// see "Ring LeakyReLu "  MatrixPrint(aListC)


//==================================

t1   = clock()
aListC = updatelist( aListA,:leakyrelu,:matrix)
t2   = clock()
Diff = t2 -t1

See "FastPro LeakyReLu "+X +"x"+Y +" Time "+ Diff +" millisecs"+nl

//see "FastPro LeakyReLu "  MatrixPrint(aListC)




//===================================



        #--------------------------------------------------------------
        #/*What is LeakyReLU?
        #       Image result for LeakyReLU derivative
        #       Leaky Rectified Linear Unit, or Leaky ReLU,
        #       is a type of activation function based on a ReLU,
        #        but it has a small slope for negative values instead of a flat slope.
        #        The slope coefficient is determined before training,
        #        i.e. it is not learnt during training*/
        #--------------------------------------------------------------

    func LeakyReLU (Matrix) { 
    
        aTanh = Matrix
        for v = 1 to len(aTanh) { 
            for h = 1 to len(aTanh[1]) { 
                aTanh[v][h] = MLeakyReLU(Matrix[v][h])
                
                //See " Matrix[v][h] "+Matrix[v][h] +" aTanh[v][h] "+aTanh[v][h] +nl
            } 
        } 
        return aTanh
    } 


//===================================

    func MLeakyReLU (input) { 
        if input < 0 { 
            Output = input*0.01
            return Output
        else
            Output = input
            return Output
        } 
    } 
//===================================
//===================================
