# Project : FAST format
# Date    : 2017/09/14
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>
 
a = ">Rosetta_Example_1
THERECANBENOSPACE
>Rosetta_Example_2
THERECANBESEVERAL
LINESBUTTHEYALLMUST
BECONCATENATED"
 
i = 1
while i <= len(a)
      if substr(a,i,17) = ">Rosetta_Example_"  
         see nl 
         see substr(a,i,18) + ": " + nl
         i = i + 17
      else
         if ascii(substr(a,i,1)) > 20 
            see a[i] 
         ok
      ok
      i = i + 1
end
