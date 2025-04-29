# Author: Bert Mariani

load "matrixlib.ring"
load "fastpro.ring"

// FILL Matrix

See nl+"=== FILL ======================="+nl

X = 5
Y = 5
nValue = 12         // fill nbr

aListA = list(X,Y)

See "aListA "  MatrixPrint(aListA)

StartClk = clock()
updateList(aListA,:fill,:matrix,nValue)
StopClk = clock()
   
See "Speed Test: "+ (stopClk - StartClk) +nl 
See "FIlled aListA "+ X +"x"+Y +" with "+nValue   
MatrixPrint(aListA)

See nl+"=== FASTPRO FILL ======================="+nl

X = 300
Y = 300
nValue = 34         // fill nbr

aListA = list(X,Y)

StartClk = clock()
updateList(aListA,:fill,:matrix,nValue)
StopClk = clock()
   
See "Speed Test: "+ (stopClk - StartClk) +nl 
See "FastPro FIlled aListA "+ X +"x"+Y +" with "+nValue   

See nl+"=========================="+nl

See nl+"=== RING FILL ======================="+nl


aListA = list(X,Y)

StartClk = clock()
   
for i = 1 to X
   for j = 1 to Y
       aListA[i][j] = nValue
   next
next

StopClk = clock()
   
See "Speed Test: "+ (stopClk - StartClk) +nl 
See "Ring FIlled aListA "+ X +"x"+Y +" with "+nValue   

See nl+"=========================="+nl