# Project : Literals/Integer
# Date    : 2017/09/13
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>

see "Decimal literal = " + 1234 + nl
see "Hexadecimal literal = " + dec("4D2") + nl
see "Octal Literal = " + octal(668) + nl
see "Binary literal = " + bintodec("10011010010")
 
func bintodec(bin)
     binsum = 0
     for n=1  to len(bin)
         binsum = binsum + number(bin[n]) *pow(2, len(bin)-n)
     next
     return binsum
 
func octal m
     output = ""
     w = m
     while fabs(w) > 0    
           oct = w & 7
           w = floor(w / 8)
           output = string(oct) + output
     end
     return output
