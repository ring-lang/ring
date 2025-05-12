# Author: Bert Mariani

load "matrixlib.ring"
load "fastpro.ring"

Decimals(2) 
 
          
aListA = [ 1:11,
           2:12,
           3:13,
           4:14,
           5:15, 
           6:16,
           7:17,
           8:18,
           9:19,
           10:20]
           
     
See"aListA " MatrixPrint(aListA)

//==================================
// Ring

value = 0 // Col
aListC = MSum(aListA, value)
see " Ring MSum Axis 0=Cols"  MatrixPrint(aListC)

// FastPro

aListC = updatelist( aListA,:sum,:matrix, value)
see "FastPro Sum Axis 0=Cols"  MatrixPrint(aListC)

//==================================

value = 1
aListC = MSum(aListA, value)
see " Ring MSum Axis 1=Rows"  MatrixPrint(aListC)

aListC = updatelist( aListA,:sum,:matrix, value)
see "FastPro Sum Axis 1=Rows"  MatrixPrint(aListC)

//====================================
//====================================
// SPEED TEST


X = 500
Y = 500
aListA = list(X,Y)

         updateList(aListA,:random,:matrix )       // 0.00 to 1.00
aListA = updateList(aListA,:scalar,:matrix,100 ) 
//See"aListA " MatrixPrint(aListA)

//==================================
value = 1 // ROW

t1   = clock()
aListC = updatelist( aListA,:sum,:matrix,value)
t2   = clock()
Diff = t2 -t1

See "FastPro Row Sum"+X +"x"+Y +" Value "+value +" Time "+ Diff +" millisecs"+nl
//See "FastPro Sum "  MatrixPrint(aListC)

//=================================

t1   = clock()
aListC = MSum(aListA,value)
t2   = clock()
Diff = t2 -t1

See "RING Row MSum "+X +"x"+Y +" Value "+value +" Time "+ Diff +" millisecs"+nl
//See "Ring Row MSum "  MatrixPrint(aListC)

//===================================
//===================================

value = 0  // COL

t1   = clock()
aListC = updatelist( aListA,:sum,:matrix,value)
t2   = clock()
Diff = t2 -t1

See "FastPro Col Sum"+X +"x"+Y +" Value "+value +" Time "+ Diff +" millisecs"+nl
//See "FastPro Col Sum "  MatrixPrint(aListC)

//=================================

t1   = clock()
aListC = MSum(aListA,value)
t2   = clock()
Diff = t2 -t1

See "RING Col MSum "+X +"x"+Y +" Value "+value +" Time "+ Diff +" millisecs"+nl
//See "Ring Col MSum "  MatrixPrint(aListC)

//===================================
//===================================
See nl+"FINISHED"+nl

//===================================
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
