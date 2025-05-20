# Author: Bert Mariani

load "matrixlib.ring"
load "fastpro.ring"

           
ZaListA = [1:5,
          2:6,
          3:7,
          4:8,
          5:9]
          
aListA =  [6,7,8,9,5,4,9,1,2,7,11,12]

See "aListA: Flat "+nl                               
MatrixFlatPrint(aListA)

//==================================
// Ring
aListC = DeRepeat( aListA)
See "Ring DeRepeat: " MatrixFlatPrint(aListC)  



// FastPro
aListC = updatelist(aListA,:derepeat,:matrix)
See "FastPro DeRepeat: 1xSize"  MatrixPrint( aListC)


//====================================
//====================================
// SPEED TEST

X = 500
Y = 500
Sum = X * Y
aListA = 9:Sum


//=================================
// RING

         t1   = clock()
aListC = DeRepeat(aListA)
         t2   = clock()
         Diff = t2 -t1

See "RING DeRepeat"+X +"x"+Y +" Time "+ Diff +" millisecs"+nl
//See "Ring DeRepeat"  MatrixFlatPrint(aListC)


//==================================
// FastPro

         t1 = clock()
Index = updatelist(aListA,:derepeat,:matrix)
         t2   = clock()
         Diff = t2 -t1

See "FastPro DeRepeat: "+X +"x"+Y  +" Time "+ Diff +" millisecs"+nl
//See "FastPro DeRepeat "  MatrixFlatPrint(aListC)


//===================================
//===================================


See nl+"FINISHED"+nl

//===================================
//===================================

//===================================

    func argmax (aList) {       // Flat List
        Max = Max(aList)        // max value    
        index = find(aList,Max) // Position index
        
// See "=== Max-value: "+Max +"  Position-Index: "+index +nl+nl     
        return index
    } 
//===================================  

//===================================
//// No Dup Add to output list

    func DeRepeat (aInput) {         // Flat array
        aDeRepeat = []               // Return array of Unique values
        for i = 1 to len(aInput)  
            if find(aDeRepeat,aInput[i]) = 0 {  
                aDeRepeat + aInput[i]                       
            ok
        } 
        return aDeRepeat
    } 
//===================================
