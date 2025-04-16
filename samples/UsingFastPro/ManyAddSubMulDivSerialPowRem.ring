# Author: Bert Mariani
#         Col     Row   
# Copy   (1,2,11)   (1,2,11)     
# Serial (1,2,11)   (1,2,11)                
# Pow    (1,2,11)   (1,2,11)  
# REM    (1,2,11)   (1,2,11)  
# 
# updateList(<aList>,:add,:manyrows,<nRowStart>,<nRowEnd>,<nValue>)
# updateList(<aList>,:add,:manycols,<nColStart>,<nColEnd>,<nValue>)
# updateList(<aList>,:sub,:manyrows,<nRowStart>,<nRowEnd>,<nValue>)
# updateList(<aList>,:sub,:manycols,<nColStart>,<nColEnd>,<nValue>)
# updateList(<aList>,:mul,:manyrows,<nRowStart>,<nRowEnd>,<nValue>)
# updateList(<aList>,:mul,:manycols,<nColStart>,<nColEnd>,<nValue>)
# updateList(<aList>,:div,:manyrows,<nRowStart>,<nRowEnd>,<nValue>)
# updateList(<aList>,:div,:manycols,<nColStart>,<nColEnd>,<nValue>)
#
# updateList(<aList>,:serial,:manyrows,<nRowStart>,<nRowEnd>,<nValue>)
# updateList(<aList>,:serial,:manycols,<nColStart>,<nColEnd>,<nValue>)
# updateList(<aList>,:pow,:manyrows,<nRowStart>,<nRowEnd>,<nValue>)
# updateList(<aList>,:pow,:manycols,<nColStart>,<nColEnd>,<nValue>)
# updateList(<aList>,:rem,:manyrows,<nRowStart>,<nRowEnd>,<nValue>)
# updateList(<aList>,:rem,:manycols,<nColStart>,<nColEnd>,<nValue>)
#
#========================================

? "Loading Library"
load "fastpro.ring"

#=========================================

#-----------------------------------------
# updateList(<aList>,:add,:manycols,<nColStart>,<nColEnd>,<nValue>)


See nl+"===ADD================================="+nl+nl

See "===== Add ManyCOLS 2,4,11 => 2-4 + 11  ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:add,:manycols,2,4,11)
MatrixPrint(aList)

#-----------------------------------------
# updateList(<aList>,:add,:manyrows,<nRowStart>,<nRowEnd>,<nValue>)


See "===== Add ManyROWS 2,4,11 => 2-4 + 11 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:add,:manyrows,2,4,11)
MatrixPrint(aList)


#-----------------------------------------
#=========================================
#-----------------------------------------

#-----------------------------------------
# updateList(<aList>,:sub,:manycols,<nColStart>,<nColEnd>,<nValue>)


See nl+"===SUB================================="+nl+nl

See "===== Sub ManyCOLS 2,4,11 => 2-4 - 11 2========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:sub,:manycols,2,4,11)
MatrixPrint(aList)

#-----------------------------------------
# updateList(<aList>,:sub,:manyrows,<nRowStart>,<nRowEnd>,<nValue>)


See "===== Sub ManyROWS 2,4,11 => 2-4 - 11 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:sub,:manyrows,2,4,11)
MatrixPrint(aList)


#-----------------------------------------
#=========================================
#-----------------------------------------
#-----------------------------------------
# updateList(<aList>,:mul,:manycols,<nColStart>,<nColEnd>,<nValue>)


See nl+"===MUL================================="+nl+nl

See "===== Mul ManyCOLS 2,4,3 => 2-4 * 3 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:mul,:manycols,2,4,3)
MatrixPrint(aList)

#-----------------------------------------
# updateList(<aList>,:mul,:manyrows,<nRowStart>,<nRowEnd>,<nValue>)


See "===== Mul ManyROWS 2,4,3 => 2-4 * 3 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:mul,:manyrows,2,4,3)
MatrixPrint(aList)


#-----------------------------------------
#=========================================
#-----------------------------------------
#-----------------------------------------
# DIV

# updateList(<aList>,:div,:manycols,<nColStart>,<nColEnd>,<nValue>)

See nl+"===DIV================================="+nl+nl

See "===== Div ManyCOLS 2,4,2 => 2-4 / 3 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:div,:manycols,2,4,3)
MatrixPrint(aList)

#-----------------------------------------
# updateList(<aList>,:div,:manyrows,<nRowStart>,<nRowEnd>,<nValue>)


See "===== Div ManyROWS 2,4,3 => 2-4 / 3 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:div,:manyrows,3,4,3)
MatrixPrint(aList)


#-----------------------------------------
#=========================================
#-----------------------------------------
#-----------------------------------------
#SERIAL

# updateList(<aList>,:serial,:manycols,<nColStart>,<nColEnd>,<nValue>)


See nl+"===SERIAL================================="+nl+nl

See "===== Serial ManyCOLS 2,4,3 => 2-4  3... ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:serial,:manycols,2,4,3)
MatrixPrint(aList)



#-----------------------------------------
# updateList(<aList>,:serial,:manyrows,<nRowStart>,<nRowEnd>,<nValue>)


See "===== Serial ManyROWS 2,4,3 => 2-4  3... ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:serial,:manyrows,2,4,3)
MatrixPrint(aList)


#-----------------------------------------
#=========================================
#-----------------------------------------

# REM

# updateList(<aList>,:rem,:manycols,<nColStart>,<nColEnd>,<nValue>)


See nl+"===REM================================="+nl+nl

See "===== Rem ManyCOLS 2,4,3 => 2-4 % 3... ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:rem,:manycols,2,4,3)
MatrixPrint(aList)

#-----------------------------------------
# updateList(<aList>,:rem,:manyrows,<nRowStart>,<nRowEnd>,<nValue>)


See "===== Rem ManyROWS 2,4,3 => 2-4 % 3... ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:rem,:manyrows,2,4,3)
MatrixPrint(aList)


#-----------------------------------------
#=========================================
#--------------------------------------
#POW

#-----------------------------------------
# updateList(<aList>,:pow,:manyrows,<nRowStart>,<nRowEnd>,<nValue>)


See "===== Pow ManyROWS 2,4,3 => 2-4 ^ 3 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:pow,:manyrows,2,4,3)
MatrixPrint(aList)

#-----------------------------------------
# updateList(<aList>,:pow,:manycols,<nColStart>,<nColEnd>,<nValue>)

See nl+"===POW================================="+nl+nl

See "===== Pow ManyCOLS 2,4,3 => 2-4 ^ 3 ========"+nl
aList = [1:5,
         2:6,
         3:7,
		 4:8,
		 5:9]

MatrixPrint(aList)
updateList(aList,:pow,:manycols,2,4,3)
MatrixPrint(aList)


#-----------------------------------------
#=========================================
#--------------------------------------

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
