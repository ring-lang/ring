# Author: Bert Mariani 

load "matrixlib.ring"
load "fastpro.ring"

Decimals(2) 
 
           
aListA = [ 1:5,
           2:6,
           3:7,
           4:8,
           5:9,
           6:10]   
           
                       
See"aListA " MatrixPrint(aListA)

//==================================
// Ring

aListC = Ravel ( aListA)
see nl+"Ring Ravel Matrix aListC"  MatrixPrint(aListC)


// FastPro

aListC = updatelist(aListA,:ravel,:matrix)
see nl+"FastPro Ravel"  MatrixPrint(aListC)


//====================================
//====================================
// SPEED TEST


X = 900
Y = 900
aListA = list(X,Y)

         updateList(aListA,:random,:matrix )  // 0.00 to 1.00
aListA = updateList(aListA,:scalar,:matrix,10 ) 

//See " Generate aListA " MatrixPrint(aListA)


//==================================

// FastPro

         t1 = clock()
aListC = updatelist(aListA,:ravel,:matrix)
         t2   = clock()
         Diff = t2 -t1

See "FastPro Ravel "+X +"x"+Y  +" Time "+ Diff +" millisecs"+nl
//See "FastPro Ravel "  MatrixPrint(aListC


//=================================
// RING

         t1   = clock()
aListC = Ravel( aListA)
         t2   = clock()
         Diff = t2 -t1

See "RING Ravel "+X +"x"+Y +" Time "+ Diff +" millisecs"+nl
//See "Ring Ravel "  MatrixPrint(aListC)

//--------------------------
         t1   = clock()
aListC = RavelOrig( aListA)
         t2   = clock()
         Diff = t2 -t1

See "RING RavelOrig "+X +"x"+Y +" Time "+ Diff +" millisecs"+nl


//===================================
//===================================


See nl+"FINISHED"+nl

//===================================
//===================================

    
    func RavelOrig (Matrix) { 
        aRavel = []
        
        for i = 1 to len(Matrix) { 
            for j = 1 to len(Matrix[1]) { 
                aRavel + Matrix[i][j]
            } 
        } 
        return aRavel               
    }
    //====================
    
    func Ravel (Matrix) { 
        
         R = len(Matrix)
         C = len(Matrix[1])
         S = R*C
         
         aRavel = list(1,S)
         See "aRavel "+R +"x"+C  +" = "+S +nl

        for i = 1 to R { 
            for j = 1 to C { 
                k = ((i-1)*C) + j       
                aRavel[1][k] = Matrix[i][j]
            } 
        } 
        return aRavel
    }   
