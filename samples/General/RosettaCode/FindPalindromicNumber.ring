# Project : Find palindromic number
# Date    : 2017/09/14
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>
 
decimals(0)
for n=1 to 7000
    flag1 = 0
    flag2 = 0
    strbin = decimaltobase(n, 2)
    if palindrome(strbin) = 1
       flag1 = 1
    ok
    strter = decimaltobase(n, 3)
    if palindrome(strter) = 1
       flag2 = 1  
    ok
    if flag1 = 1 and flag2 = 1
       see "Decimal : " + n + nl
       see "Binary : " + strbin + nl
       see "Ternary : " + strter + nl + nl
    ok
next
see "OK" + nl
 
func decimaltobase(nr, base) 
     binary = 0
     i = 1  
     while(nr != 0) 
          remainder = nr % base
          nr = floor(nr/base)
          binary= binary + (remainder*i)
          i = i*10
     end
     return string(binary)
 
Func palindrome aString
     bString = ""
     for i=len(aString) to 1 step -1
         bString = bString + aString[i]
     next
     if aString = bString return 1 ok
     return 0
