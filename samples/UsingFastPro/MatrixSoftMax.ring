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

aListC = Softmax(aListA)
see " Ring Softmax "  MatrixPrint(aListC)

// FastPro

aListC = FastProSoftmax(aListA)
see "FastPro Sum Axis 0=Cols"  MatrixPrint(aListC)

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
aListC = FastProSoftmax(aListA)
         t2   = clock()
         Diff = t2 -t1

See "FastPro SoftMax "+X +"x"+Y  +" Time "+ Diff +" millisecs"+nl
//See "FastPro Sum "  MatrixPrint(aListC)



//=================================
// RING

         t1   = clock()
aListC = Softmax (aListA)
         t2   = clock()
         Diff = t2 -t1

See "RING Softmax "+X +"x"+Y +" Time "+ Diff +" millisecs"+nl
//See "Ring Softmax "  MatrixPrint(aListC)



//===================================
//===================================


See nl+"FINISHED"+nl

//===================================
//===================================


    func MSum (Matrix,Axis) { 
        if Axis { 
        //See "Axis-1st = Rows "+Axis +nl
            aSum = list(len(Matrix),1)
            for v = 1 to len(Matrix) { 
                for h = 1 to len(Matrix[1]) { 
                    nSum = 0
                    for k = 1 to len(Matrix[1]) { 
                        nSum += Matrix[v][k]
                    } 
                    aSum[v][1] = nSum
                } 
            } 
            return aSum
            else
                //See "Axis-2nd  = Cols "+Axis +nl
                aSum = list(1,len(Matrix[1]))
                for v = 1 to len(Matrix) { 
                    for h = 1 to len(Matrix[1]) { 
                        nSum = 0
                        for k = 1 to len(Matrix) { 
                            nSum += Matrix[k][h]
                            #?"sum:" +   nSum
                        } 
                        aSum[1][h] = nSum
                    } 
                } 
                return aSum
        } 
    } 


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

    Func Softmax(Matrix) { 
        MatrixExp = MExp(Matrix)        
        MatrixSum = MSum(MatrixExp,0)
        MtxSoftmax = DivByNum(MatrixExp,MatrixSum[1][1])        
        return MtxSoftmax
    }
    

//==================================

Func FastProSoftmax(aListA)
        aListExp = updateList(aListA,:exp,:matrix ) ;   
        aListSum = updateList(aListExp,:sum,:matrix,0 ) ;   
        valueA   = aListSum[1][1]   
        aListSoftMax = updateList(aListExp,:scalardiv,:matrix,valueA ) ;
        
return aListSoftMax
