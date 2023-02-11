//  Bert Mariani
//  2023-02-09
//  A Monte Carlo method to solve the encryted message
//
//  "  SEND"
//  "  MORE"
//  " MONEY"
//
//  Time and cycles to solve varies considerably
// Start Clock: 27
// Solved: SEND: 9567 MORE: 1085 MONEY: 10652 Check 10652
// End   Clock.: 4197
// Count cycles: 30657
// 
// End   Clock.: 19505     Count cycles: 148081
// End   Clock.: 12518     Count cycles:  94660
// End   Clock.: 15572     Count cycles: 117848
// End   Clock.: 20832     Count cycles: 150848
// End   Clock.: 64703     Count cycles: 486035
// End   Clock.:  4197     Count cycles:  30657
// End   Clock.: 20827     Count cycles: 155153
// 
//
// "M = 1" because of carry
// S+M = O   S+M = O  S+M+c = 10+O   S+1 = 10+O  S+1+c = 10+0
// E+O = N   E+O = N  E+O+c = 10+N
// N+R = E   N+R = E  N+R+c = 10+E
// D+E = Y   D+E = Y  D+E+c = 10+Y
//
// sendmory  = 8 unique letters , m =1 , 0-9   = 10 possible numbers
// sendory   = 7 unique                  0,2-9 =  9 possible numbers
//
// 9999 + 9999 < 20000    therfore m =1
// 9999 * 9999 = 10000000 max cycles 100 million
//
// See "Solution: SEND = 9567 MORE = 1085 MONEY = 10652" +nl
//

t1 = clock()          // 
See "Start Clock: "+ t1 +nl

counter    = 1
aSendory   = [["s","-"],["e","-"],["n","-"],["d","-"],["o","-"],["r","-"],["y","-"]]
aRandom    = List(10)                       // 0-9


for j = 1 to 100000000
    aRandom = GenRandomUniq()            // 5 2 0 8 7 1 6 4 3 9 
    
    for i = 1 to 7
        if aRandom[1] != 1               // m = 1
           aSendory[i][2] = aRandom[1]
           del(aRandom,1)                // Shorten list, remove value entry picked
        else
           del(aRandom,1)
           i--
        ok
    next
    //PrintArray(aSendory)               // Debug
    

        if (TrySolution(aSendory)) break  else  counter++   ok  // True=1 = Solution Found
        
next

See "End   Clock.: "+ (clock() - t1) +nl
See "Count cycles: "+ counter +nl




//==========================================
//==========================================
//Random-10:  2 10 5 7 6 8 1 3 9 4  1-10
//Random-Fix  2  4 9 8 1 3 0 5 7 6  0-9

Func GenRandomUniq()
throwLimit = 10                      // 0-9, Ring does 1-10
aList = 1:throwLimit
aOut  = []

while len(aOut) != throwLimit
    nSize = len(aList)
    
    if nSize > 0
        nIndex = random(nSize)       // Random pointer into list
        if nIndex = 0  nIndex=1 ok   // Ignore 0, Ring Index at 1-10
        
        aOut + (aList[nIndex] -1)    // -1 fix value 0-9, Ring +1 Extract list entry content
        del(aList,nIndex)            // Shorten list, remove value entry picked

    else
        aOut + aList[1]
        aList = []
    ok
end

return aOut

//==========================================
// See array s-2, e-5 etc

Func PrintArray( aBC)

 size = len(aBC)
 See "aArray: "

 for i = 1 to size
    See  " | "+ aBC[i][1] +" "+ aBC[i][2]
 next
 See nl

return

//=========================================
// 1234567
// sendory  m = 1

Func TrySolution(aTry)

     s1 = ( aTry[1][2]) * 1000      // send   
     e1 = ( aTry[2][2]) *  100         
     n1 = ( aTry[3][2]) *   10        
     d1 = ( aTry[4][2]) *    1        

     nbr1 = s1 + e1 + n1 + d1

     m1 = 1             * 1000      // more
     o1 = ( aTry[5][2]) *  100
     r1 = ( aTry[6][2]) *   10
     e1 = ( aTry[2][2]) *    1 

     nbr2 = m1 + o1 + r1 + e1

     m1 = 1             * 10000     // money
     o1 = ( aTry[5][2]) *  1000
     n1 = ( aTry[3][2]) *   100
     e1 = ( aTry[2][2]) *    10
     y1 = ( aTry[7][2]) *     1

     nbr3 = m1 + o1 +n1 + e1 + y1

     nbr4 = nbr1 + nbr2

     if (nbr3 = nbr4)
        See "Solved: SEND: "+ nbr1 +" MORE: "+ nbr2 +" MONEY: "+ nbr3 +" Check "+ nbr4 +nl
        return (nbr3 = nbr4 )      // True
     ok
     
return False
