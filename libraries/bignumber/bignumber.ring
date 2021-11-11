### Project : bignumber.ring
### Date    : 2018/08/19
### Author  : Bert Mariani, Gal Zsolt (~ CalmoSoft ~)
#
###----------------------------------------------------------
# Uses Strings. Handles numbers over 15 digits
# Verify using site: 
# https://www.calculator.net/big-number-calculator.html?cx=12345&cy=24&cp=1&co=divide
#
# Functions:
#   FuncAdd         - The BASE block
#   FuncSubtract    - Depends on FuncAdd. Uses Additive Subtract
#   FuncCompare     - Compare numbers. returns: Greater 1, Equal 0, Less -1
#   FuncDivide      - Depends on FuncSubtract, FuncAdd, FuncCompare
#   FuncMultiply    - Depends on FuncAdd and FuncCompare
#   FuncPower       - Depends on FuncMultiply 
#
#   FuncDecimalToBinary
#   FuncBinaryToDecimal
#
#   printBinaryDigits
#   printDecimalDigits
#
#   SEE commands displays details of steps. UnComment to use.
###----------------------------------------------------------

load "stdlibcore.ring"

if isMainSourceFile()
   ? "Testing class..."
   BigNumber_testClass()
   ? "Testing functions..."
   BigNumber_testFunctions()
ok

###----------------------------------------------------------
### Test with various numbers

Func BigNumber_testClass() 

    ###     123456789 123456789 123456789 12345 
    num1 = "62345678901234567891678345123456789"    ### Big
    num2 =  "1237894567890123419871236545"          ### Small
    num3 =     "64"                                 ### Divide Small
    num4 = "765432"                 
    num5 =      "3"                                  ### Power            
    num6 =  "12985"                 
    num7 =   "9876"   
    num8 =    "789" 
    num9 =   "1234"
    numA =   "5432"  
    numB =   "285432"
    numC =  "1432109"
    numD =  "21432"
    numE =  "24000"
    numF =  "0"
    numG =  "11011" ### Binary
    numH =  "11000011011010011011110101011001000100100011010001010110"
    numI =  "12345678911234567892"
    numJ =  "10"
    numK =  "100"
    numSqrt2 = "14142135623730950488016887242096980785696718753769480731766797379907324784621070388503875343276415727"
    numSqrt  = "2"

    a3 = new BigNumber(1)
    
    see "Compare USE % for Greater Equal Less:" + nl
    a1 = new BigNumber(num7)        ; See a1 +nl
    a2 = new BigNumber(num8)        ; See a2 +nl     
    a3 = a1 % a2                    ; See a3 See " A1 > A2 " +nl 
    a3 = a1 % a1                    ; See a3 See " A1 = A2 " +nl
    a3 = a2 % a1                    ; See a3 See " A1 < A2 " +nl+nl
    
    
    see "Add big numbers:" + nl 
    a1 = new BigNumber(num1)        ; See a1 +nl 
    a2 = new BigNumber(num2)        ; See a2 +nl
    a3 = a1 + a2                    ; See a3 +nl See nl+nl

    
    see "Substract big numbers:" + nl 
    a1 = new BigNumber(num1)        ; See a1 +nl 
    a2 = new BigNumber(num2)        ; See a2 +nl
    a3 = a1 - a2                    ; See a3 +nl See nl+nl

    see "Divide big numbers:" + nl 
    a1 = new BigNumber(num1)        ; See a1 +nl 
    a2 = new BigNumber(num2)        ; See a2 +nl         
    a3 = a1 / a2                    ; See a3 +nl  See nl+nl
    
    see "Divide big numbers: by very small number" +nl 
    a1 = new BigNumber(num1)        ; See a1 +nl 
    a2 = new BigNumber(num3)        ; See a2 +nl       
    a3 = a1 / a2                    ; See a3 +nl  See nl+nl 

    see "Multiply big numbers:" + nl    
    a1 = new BigNumber(num1)        ; See a1 +nl 
    a2 = new BigNumber(num2)        ; See a2 +nl      
    a3 = a1 * a2                    ; See a3 +nl See nl+nl 

    see "Power of big number:" + nl 
    a1 = new BigNumber(num1)        ; See a1 +nl 
    a2 = new BigNumber(num5)        ; See a2 +nl     
    a3 = a1 ^ a2                    ; See a3 +nl See nl+nl
    
    ###---------------------------------------------
    ### Do NOT have Operator for these Conversions
    
        see "BinaryToDecimal of big number:" + nl
        a1 = numH                       ; See a1 +nl
        a3 = FuncBinaryToDecimal(a1)    ; See a3 +nl See nl+nl
        
        see "DecimalToBinary of big number:" + nl
        a1 = numI                       ; See a1 +nl
        a3 = FuncDecimalToBinary(a1)    ; See a3 +nl See nl+nl
    
    ###--------------------------------------------

    See "Finished Calculations "+ nl   
return

Func BigNumber_testFunctions() 

    ###     123456789 123456789 123456789 12345 
    num1 = "62345678901234567891678345123456789"    ### Big
    num2 =  "1237894567890123419871236545"    ### Small
    num3 =      "64"                           ### Power   number
    num4 = "765432"                 
    num5 =     "3"                 
    num6 =  "12985"                 
    num7 =   "9876"   
    num8 =    "789" 
    num9 =  "1234"
    numA =  "5432"  
    numB =   "285432"
    numC =  "1432109"
    numD =  "21432"
    numE =  "24000"
    numF =  "0"
    numG =  "11011" ### Binary
    numH =  "11000011011010011011110101011001000100100011010001010110"
    numI =  "12345678911234567892"
    numJ =  "10"
    numK =  "100"
    numL = "3457243"
    numM = "37"
    numSqrt2 = "14142135623730950488016887242096980785696718753769480731766797379907324784621070388503875343276415727"
    numSqrt  = "2"

    see "Compare - Greater Equal Less:" + nl
    a1 = num7                   ; See a1 +nl
    a2 = num8                   ; See a2 +nl     
    a3 = FuncCompare(a1, a2)   ; See a3 See " A1 > A2 " +nl 
    a3 = FuncCompare(a1, a1)   ; See a3 See " A1 = A2 " +nl
    a3 = FuncCompare(a2, a1)   ; See a3 See " A1 < A2 " +nl+nl
    
    
    see "Add big numbers:" + nl 
    a1 = num1                   ; See a1 +nl 
    a2 = num2                   ; See a2 +nl
    a3 = FuncAdd(a1, a2)        ; See a3 +nl+nl

    
    see "Substract big numbers:" + nl 
    a1 = num2                   ; See a1 +nl
    a2 = num1                   ; See a2 +nl   
    a3 = FuncSubtract(a1, a2)  ; See a3 +nl+nl

    see "Divide big numbers:" + nl 
    a1 = num1                   ; See a1 +nl
    a2 = num2                   ; See a2 +nl         
    a3 = FuncDivide(a1, a2)     ; See a3 +nl  See nl+nl
    
    see "Divide big numbers: by very small number" +nl 
    a1 = numL                   ; See a1 +nl
    a2 = numM                   ; See a2 +nl         
    a3 = FuncDivide(a1, a2)     ; See a3 +nl  See nl+nl 

    see "Multiply big numbers:" + nl    
    a1 = num1                   ; See a1 +nl
    a2 = num2                   ; See a2 +nl       
    a3 = FuncMultiply(a1, a2)   ; See a3 +nl+nl      

    see "BinaryToDecimal of big number:" + nl
    a1 = numH                       ; See a1 +nl
    a3 = FuncBinaryToDecimal(a1)    ; See a3 +nl+nl
    
    see "DecimalToBinary of big number:" + nl
    a1 = numI                       ; See a1 +nl
    a3 = FuncDecimalToBinary(a1)    ; See a3 +nl+nl
    
    see "Power of big number:" + nl 
    a1 = num1                   ; See a1 +nl
    a2 = num5                   ; See a2 +nl       
    a3 = FuncPower(a1, a2)      ; See a3 +nl+nl
     
        
    See "Finished Calculations "+ nl   
return
        
###========================================================
###========================================================

###=========================================      
Func FuncAdd(num1, num2)

 #if isString(num1) See "String num1" +nl else See "Not string num1" +nl ok
 #if isString(num2) See "String num2" +nl else See "Not string num2" +nl ok

    lenN1 = len(num1)               ###  Num1 987
    lenN2 = len(num2)               ###  Num2  42

    ###----------------------------------------------
    ### Pad both numbers to make them the same length
    
    Pad = fabs(lenN1-lenN2)
    if lenN1 > lenN2
            for n = 1 to Pad
                num2 = "0" + num2   ### Pad 42 -> 042
            next
    else
            for n = 1 to Pad
                num1 = "0" + num1   ### Pad 987 -> 0987
            next
    ok  

    #SEE "StartADD_: "+ num1 +" + "+ num2 +nl 
        
    ###-------------------------------------------------
    ### Add digits in <== direction: left 1  <-- right 3
    
    result = ""   
    carry  = 0                      
    
    for n = len(num1) to 1  step -1         
        sum = carry + num1[n] + num2[n]
        #SEE "Sum: "+ carry +" "+ num1[n] +" + "+ num2[n] +" = "+ sum  +nl
        
        if sum > 9
            carry = 1
        else
            carry = 0
        ok     
        result = string( sum % 10 ) + result
        
        #SEE "Result: "+ n +" - "+ result +nl
    next
    
    ###-------------------------
    ### Add carry 1 to left side
    
    if carry = 1
        result = "1" + result       
    ok
    
    if result[1] = "0"      ### Remove any leading 0
        result = Right(result, len(result) -1 )
    ok
     
    #SEE "ResultADD: "+ result +nl
    
return result
    
###=========================================
Func FuncSubtract(num1, num2)

    ###------------------------------------------------------
    ### Use additive subtract method
    # 
    # Use Complement 10 on rightmost non-zero, then compliment 9 going left. rightmost 0 do NOT touch
    # Remove leftmost 1
    #              v---   Big   Comp    Rem 1  |   Swap  Comp    Rem 1 Change Sign |
    #     0123456789000   9876   9876          |   1234   5432                     | 9876  9876
    #     9876543211000  -4567  +5433          |  -5432  +8766                     |- 789 +9211
    #                   = 5309 =15309 => 5309  |  -4198  14198 => 4198 => -4198    | 9087 19087  
    #
    ###------------------------------------------------------
    
    lenN1 = len(num1)               ###  Num1 9876
    lenN2 = len(num2)               ###  Num2  789


    ###----------------------------------------------
    ### Find which number is bigger after the padding
    ### Flip if num2 is bigger
    
    numBig = FuncCompare( num1, num2)

    if numBig = 2
       temp = num1
       num1 = num2
       num2 = temp
    ok   

    
    #SEE "PAD and Swap: "+nl+ num1 +nl+ num2 +nl

    ###--------------------------------------------
    ### Compliment the digits in the Smaller Number
    
    flip = 0
    flipNum = ""
    compliment = 10
    
    for n = len(num2) to 1 step -1
        if num2[n] = 0
            if compliment = 10
                flipNum = "0" + flipNum     ### Rightmost Zeros
            else
                flipNum = "9" + flipNum     ### After Non-Zero digit detected   
            ok
        else
            flip    =  compliment - num2[n]
            flipNum = string(flip) + flipNum
            compliment = 9
        ok
        #SEE "FlipNum: "+ n +" "+ num1 +" "+ num2 +" > "+ flipNum +" "+ flip +nl 
    next
    
    ###------------------------------------------------------
    ### CALL FuncAdd - Ready for Subtract by Additive Method
    
    result = FuncAdd(num1, flipNum)
    
    ###-----------------------------
    ### Remove the Leading Digit -1
    
    digit     = result[1]
    digit     = digit - 1
    result[1] = string(digit)   

    ###---------------------------------
    ### Leave a "0" if result all Zeros
    
    lenR = len(result) -1   
    for n = 1 to lenR       
        if result[1] = "0"
            result =  Right( result, len(result) - 1)
        else
            exit
        ok
    next

    ###---------------------------------------
    ### ADD the Minus Sign if Num2 was Bigger
    
    if numBig = 2
        result = "-" + result
    ok
    
    #SEE "ResultSUB: "+ num1 +" + "+ num2 +nl 
    
return  result

      


###===================================================

Func FuncCompare( num1, num2 )
    
    ###----------------------------------------------
    ### Compare Numbers: Greater 1, Equal 0, Less -1

    lenN1 = len(num1)               ###  Num1 9876
    lenN2 = len(num2)               ###  Num2  789

    ###----------------------------------------------
    ### Pad both numbers to make them the same length 
    
    Pad = fabs(lenN1-lenN2)
    if lenN1 > lenN2
            for n = 1 to Pad
                num2 = "0" + num2   ### Pad  789 -> 0789
            next
    else
            for n = 1 to Pad
                num1 = "0" + num1   ### Pad 9876 -> 0987
            next
    ok  
    
    #SEE "StartGEL_: "+ num1 +" : "+ num2 +nl 
    
    ###----------   
    
    numBig = 0
    for n = 1 to len(num1)
        if num1[n] > num2[n] 
           numBig = 1
           exit
        else
            if num2[n] > num1[n] 
               numBig = -1           ### Flip num2 is Bigger
               temp = num1
               num1 = num2
               num2 = temp
               exit
            ok   
        ok  
    next
    
    #SEE "ResultGEL: "+ num1  +" "+ num2 +" "+  numBig +nl
    
return numBig
    
###===========================================    

func FuncDivide(num1,num2)

   
    ###---------------------------------------------------
    ### PAD 0's on right of divisor number =>  24 =>24000
    
    lenN1  = len(num1)      ### Dividend:  765432 len 6
    lenN2  = len(num2)      ### Divisor:       24 len 2 
    q3     = ""             ### Quotient:   31893
    Pad    = lenN1 - lenN2   

    if ( lenN2 < lenN1 )         
        for  i = 1 to Pad 
            num2 = num2 + "0"        
        next
    ok

    #SEE "STARTDIV_: "+ nl+ num1 +nl+ num2 +nl

    ###-----------------------------------
    ### Divide by Subtraction 
    
    for k = Pad to 0 step -1
        count  = 0
        result = 1

        while result
        
            ###------------------------------------------------------------
            ### Call FuncSubtract for Subtract, and FuncCompare for Great-Equal-Less
            
            result  = FuncSubtract(num1, num2)       ### Dividend - Divisor ==> 12345 - 24000
            GEL     = FuncCompare(num1, num2)
            
            if GEL = 0 OR GEL = 1               ### Equal 0, Great 1, Less -1
                count++
                num1 = result
                #SEE "Pad: "+ Pad +" Res: "+ result +" Count: "+ count +" Q3: "+ q3 +nl
            else
                ### result negative
                exit
            ok  
        end

        ###-------------------------------------------------------------------
        ### Shifting to the Left, Remove Right 0 Pad from num2, 24000 => 2400
        
        q3  = q3 + count
        Pad = Pad - 1
        num2  = Left(num2, len(num2)  - 1)
 
        #SEE nl +"NextLoop: "+nl+ "Pad: "+ Pad +" N1: "+ num1 +" Pad-N2: "+ num2  +" Count: "+ count +" Q3: "+ q3 +nl      
    next

        ### Remove leading Zero from Q3-Quotient
        lenQ3 = len(q3) -1   
        for n = 1 to lenQ3       
            if q3[1] = "0"
                q3 =  Right( q3, len(q3) - 1)
            else
                exit
            ok
        next 
     
    #SEE "ResultDIV: "+ q3 +" R: "+ num1 +nl +nl
    
return q3
    
    
###=========================================     

Func FuncMultiply(num1, num2)

    lenN1 = len(num1)               ###  Num1    765432   Multiplicand
    lenN2 = len(num2)               ###  Num2        24   Multiplier
                                    ###        15308640   ResultTotal
                                    
    #SEE "StartMUL_: "+nl+ num1 +nl+ num2 +nl+nl
   
    ###----------------------------
    ### From right to left <---
    
    result    = ""      ### Multiplicand X single Multiplier digit
    resultSum = "0"     ### Sum of each Multiplier result
    resultTot = "0"     ### Total of all Multiplier results
    carryA    = "0"     ### Add spacing Zeros for Carry loop right to left <---
    resultA   = ""      ### Add spacing Zeros for next Multiplier loop, right to left <---
     
    for b = lenN2 to 1 step -1
        carry   = carryA 
        result  = resultA

        for a = lenN1 to 1 step -1
            
            multiNum =  num1[a] * num2[b]       
            digit    = string(multiNum)    
            lenDigit = len(digit)
            
            if lenDigit = 1 
                carry      = "0" + carry
                rightDigit = digit[1]                 
            else
                carry      = digit[1] + carry       ###  Add to <--- left of carry field
                rightDigit = digit[2] 
            ok
            
            result = rightDigit + result            ### Add to <--- left of result field    
            #SEE "Result: "+ result +" Carry: "+ carry +nl
            
        next
    
        resultSum = FuncAdd( result, carry )        ### FuncAdd result field with carry field
        resultTot = FuncAdd( resultSum, resultTot)  ### FuncAdd to running Total
        
        #SEE "Sum: "+ resultSum +" Tot: "+ resultTot +nl
        
        carryA  = "0" + carryA
        resultA = "0" + resultA
    next
    
    #SEE "ResultMUL: "+ ResultTot +nl
    
return resultTot

###=========================================     


Func FuncPower(num1, num2)

    lenN1 = len(num1)               ###  Num1    24   Multiplicand
    lenN2 = len(num2)               ###  Num2     3   Power
                                    ###       13824   Result                            
    #SEE "StartPWR_: "+nl+ num1 +nl+ num2 +nl+nl

    ###----------------------------
    ### Repeated multiply on Num1
    
    result = "1"
    for n = num2 to 1 step -1
        result = FuncMultiply( result, num1)
        
        #SEE "Result "+ n +" - "+ num1 +" "+ result +nl
    next
    
    #SEE "ResultPWR: "+ result +nl+nl

return result


###========================================================

###--------------------------------------
### Func FuncBinaryToDecimal(num1)
### MultiplyBy2 method
###
### Binary 11011 => Dec 25  
### Double and Add next digit  11001
### From  left ----> right     
#
#  >11011  first digit    (1):   1    
#           double:              2    
#  
#  1>1011  add next digit (1):   3   
#           double:              6   
#  
#  11>011  add next digit (0):   6     
#           double:             12     
#  
#  110>11  add next digit (0):  12     
#           double:             24     
#  
#  1101>1  add last digit (1):  25     
#
###----------------------------------------

Func FuncBinaryToDecimal(num1)
    #SEE "Start: "+ num1 +nl
    
    result  = ""                         ### Decimal digits store here
    resultA = ""                         ### Binary position 1 left to right ---->
    pos     = 1       
                  
    result  = result + (num1[1] * 2)     ### Double first binary digit as string   
               
    for pos = 2 to len(num1)-1           ### Add next digit
  
        resultA = FuncAdd( result, num1[pos] )       ### Double it
        result  = FuncMultiply( resultA, "2" )

        #See "Rr "+ result +" n "+ num1[pos] +nl
        #See "RR "+ result +nl+nl
        #SEE "P "+ pos +" n "+ num1[pos] +" A "+ resultA +" D "+ result +nl
    next
       
    result = result + num1[pos] 
        #SEE nl +"Q "+ pos +" n "+ num1[pos] +" A "+ resultA +" D "+ result +nl
            
return result

###------------------------ 

###=================================================
### FuncDecimalToBinary(num1)
#
# Use: stringRet = FuncDecimalToBinary(stringNumber)
#
# Decimal string "N" to Convert 
# Dec 12345 => Bin: 11 0000 0011 1001
# Use DivideBy2 method

Func FuncDecimalToBinary(num1)

#See "Start: "+ num1 +nl
binDigits = ""      ### Bin digits result

while num1
    newNbr = ""
    next_additive = 0
    
    for pos = 1 to len(num1)
        nbr      = num1[pos]
        additive = next_additive
        
        if nbr % 2
           next_additive = 5   ### Odd nbr
        else
           next_additive = 0   ### Even nbr
        ok
    
        result = floor(nbr / 2)
        resultAdditive = result + additive
        newNbr = newNbr + string(resultAdditive)
    
        #SEE "newNbr: "+ newNbr + nl
    
    next

    
    if  num1[len(num1)] % 2                     ### Last digit odd or even
        binDigits = "1" + binDigits ###+ "1"    ### ODD
    else
        binDigits = "0" + binDigits ###+ "0"    ### Even
    ok

    #SEE "binDigits: "+ binDigits +nl
 
    if newNbr[1] = "0"                  ### remove leading 0
       newNbr = Right(newNbr, len(newNbr)-1)
    ok 

    if len(newNbr) = 0    
       return binDigits             ### EXIT -RETURN
    else     
       num1 = newNbr                ### recursive call  
       #SEE nl +"updatedNum1: "+ num1 +nl
    ok
end

return binDigits

###================================

###================================

Func printBinaryDigits( binList)
    for digit = 1 to len(binList)
        See  binList[digit]

        if !((len(binList) - digit) % 4)  ### Add a space every 4th char
            See " "
        ok
     next
   See nl
return

###------------------------ -------

Func printDecimalDigits( decList)
    for digit = 1 to len(decList)
        See  decList[digit]

        if !((len(decList) - digit) % 3)  ### Add a comma every 3th char
            See ","
        ok
    next
    See nl
return

###------------------------ 

###==============================================
###==============================================
class BigNumber 

    ### Variables
    aData = "468"

    ### Functions INIT default values
    func init aPara 
        ### ? "INIT aPara: " ? aPara

        if isString(aPara)
            aData = aPara 
        else 
            aData = "" + aPara
        ok

    ### Other Functions
    func operator cOperator, Para
            
            whatType = Type(Para)

            ### ? nl+"WhatType-PARA: "+ whatType ? Para 
            ### ? nl+"Operator: " ? cOperator  ? nl+"PARA: " ? Para ? "    ______" ? nl

 
                    if whatType = "STRING"
                       dataInfo = Para
                       ### ? "dataInfo String: " ? dataInfo
                    
                    but whatType = "NUMBER"
                       datinfo  = "" + Para
                       ### ? "dataInfo Number: " ? dataInfo
                    
                    else whatType = "OBJECT"
                       dataInfo = "" + Para.aData  
                       ### ? "dataInfo OBJECT: " ? dataInfo
                    ok

                      ### ? "dataInfo USING: " ? dataInfo  

            ### Para.aData does NOT exist on first pass
            ### Result isObject when assigned "self"

            result = self   
            
            switch cOperator
                on "+"

                    answer = FuncAdd( aData, dataInfo )
                     ### ? nl+"AnswerString - FunAdd aData, dataInfo: " ? answer  

                     ### result = self,  is Object
                     result.aData = answer 
   
                on "-"

                    answer = FuncSubtract( aData, dataInfo )
                     ### ? nl+"AnswerString - FunSubtract aData, dataInfo: " ? answer  

                     ### result = self,  is Object
                     result.aData = answer 
                     
                on "*"

                    answer = FuncMultiply( aData, dataInfo )
                     ### ? nl+"AnswerString - FuncMultiply aData, dataInfo: " ? answer  

                     ### result = self,  is Object
                     result.aData = answer 

                on "/"

                    answer = FuncDivide( aData, dataInfo )
                     ### ? nl+"AnswerString - FunDivide aData, dataInfo: " ? answer  

                     ### result = self,  is Object
                     result.aData = answer 

                on "^"

                    answer = FuncPower( aData, dataInfo )
                     ### ? nl+"AnswerString - FunPower aData, dataInfo: " ? answer  

                     ### result = self,  is Object
                     result.aData = answer                   
  
                on "%"

                    answer = FuncCompare( aData, dataInfo )
                     ### ? nl+"AnswerString - FuncCompare aData, dataInfo: " ? answer  

                     ### result = self,  is Object
                     result.aData = answer          
                     
                off

            ### Result = Self is Object
            return result   
            

    func print 
        ? aData 

    func Value 
        return aData 
	

###========================================================
###=========================================================







