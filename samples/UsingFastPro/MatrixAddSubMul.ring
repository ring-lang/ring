# Author: Bert Mariani
#               A,B,=> C    
# Add Matrix   (1,2,   3)        
#  
# updateList(<aList>,:add,:matrix,<Matrix-A>,<Matrix-B>,<matrix-C>)
#
#========================================

? "Loading Library"
load "fastpro.ring"


#=========================================

See nl+"===ADD MATRIX================================="+nl+nl
See "===== Add Matrix aListA, aListB  => A+B => C  ========"+nl

aListA = [1:5,
          2:6,
          3:7,
          4:8,
          5:9]
         
aListB = [12:16,
          13:17,
          14:18,
          15:19,
          16:10] 
		 

See "aList A"  MatrixPrint(aListA)
See "aList B"  MatrixPrint(aListB)

aListC = updateList(aListA,:add,:matrix, aListB )

See ">>> ADD A+B=>C >>>>>>>>>>>>>>"+nl
See "RESULT C "  MatrixPrint(aListC)



#=========================================

See nl+"===SUB MATRIX================================="+nl+nl
See "===== Sub Matrix aListA, aListB => A-B => A  ========"+nl

aListA = [1:5,
          2:6,
          3:7,
          4:8,
          5:9]
         
aListB = [12:16,
          13:17,
          14:18,
          15:19,
          16:10] 
		 

See "aList A"  MatrixPrint(aListA)
See "aList B"  MatrixPrint(aListB)

aListC = updateList(aListA,:sub,:matrix, aListB )

See ">>> SUB A-B=>C >>>>>>>>>>>>>>"+nl
See "RESULT C "  MatrixPrint(aListC)


#=========================================
#=========================================

See "///// MUL /////////////////////////////"+nl+nl

aListA =  [[1,2,3,4,5],   
           [1,1,1,1,1],
           [1,1,1,1,1]]
         
            
 aListB = [[1,1,1],
           [2,1,1],
           [3,1,1],
		   [4,1,1],
		   [5,1,1]]
		 
	     
	 	  

See "Start MUL A aListA (A*B=>C)"  MatrixPrint(aListA)
See "Start MUL B aListB (A*B=>)"  MatrixPrint(aListB)

aListC = updateList(aListA,:mul,:matrix, aListB )

See ">>>>>>>>>>>>>>>>>>> A*B=>C" +nl
See "RESULT MUL C aListC (A*B)"  MatrixPrint(aListC)


#========================================

See nl+nl+"FINISHED TESTING"+nl+nl


//=============================================
//=============================================
//=============================================
// Bert Mariani 03/18/2023
// MatrixPrint(A)
// Display a Matrix Array by Row and Col size

Func MatrixPrint(U)

 See "      MatrixPrint:"
 Row = len(U)     See " "+ Row      // Rows 
 Col = len(U[1])  See "x"+ Col +nl  // Cols 
                           
 for h = 1 to Row
   See "| "
   for v = 1 to Col
     Num = U[h][v]
     if (Num >= 0) See " " ok       // 2 places
     See Num  
     if v != Col   See "," ok       // Comma between numbers
   next
   See " |"+nl
 next
   See nl
   
return
//=============================================

//=============================================
// Bert Mariani 03/18/2023
// MatrixFlatPrint(U)
// Display a Matrix Array by Row and Col size

Func MatrixFlatPrint(U)

 See "      MatrixFlatPrint:"
 Row = len(U)     See " "+ Row +nl   // Row 

 for h = 1 to Row
    See " "+ U[h] +","
 next
   See nl+nl

return
//============================================
