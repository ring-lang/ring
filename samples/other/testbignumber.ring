load "bignumber.ring"

num1 = "62345678901234567891678345123456789"    ### Big
num2 =  "1237894567890123419871236545"          ### Small
num3 =     "64"                                 ### Divide Small
num4 = "765432"                 
num5 =      "3"                                  ### Power            
    
? "Add big numbers:" 
a1 = new BigNumber(num1)        a1.Print()
a2 = new BigNumber(num2)        a2.Print()
a3 = a1 + a2                    a3.Print() ? nl

? "Substract big numbers:" 
a1 = new BigNumber(num1)        a1.Print()
a2 = new BigNumber(num2)        a2.Print()
a3 = a1 - a2                    a3.Print() ? nl

? "Multiply big numbers:" 
a1 = new BigNumber(num1)        a1.print()
a2 = new BigNumber(num2)        a2.print()      
a3 = a1 * a2                    a3.print() ? nl

? "Divide big numbers:" 
a1 = new BigNumber(num1)        a1.print()
a2 = new BigNumber(num2)        a2.print()
a3 = a1 / a2                    a3.print() ? nl
    
? "Divide big numbers: by very small number" 
a1 = new BigNumber(num1)        a1.print()
a2 = new BigNumber(num3)        a2.print()
a3 = a1 / a2                    a3.print() ? nl

? "Power of big number:" 
a1 = new BigNumber(num1)        a1.print()
a2 = new BigNumber(num5)        a2.print()
a3 = a1 ^ a2                    a3.print() ? nl
    
