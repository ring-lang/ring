# Project : Proper divisors
# Date    : 2017/09/22
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>
 
limit = 10
for n=1 to limit
    if n=1
       see "" + 1 + " -> (None)" + nl
       loop
    ok
    see "" + n + " -> "
    for m=1 to n - 1
        if n%m = 0
           see " " + m 
        ok
    next
    see nl
next 
