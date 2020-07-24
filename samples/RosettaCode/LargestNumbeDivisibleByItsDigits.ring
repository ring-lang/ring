# Project : Largest number divisible by its digits
# Date    : 2017/09/22
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>
 
for n = 9867000  to 9867400
    numbers = list(9)
    for t=1 to 9
        numbers[t] = 0
    next
    flag = 1
    flag2 = 1
    flag3 = 1
    str=string(n)
    for m=1 to len(str)
        if number(str[m]) > 0
           numbers[number(str[m])] = numbers[number(str[m])] + 1
        else
           flag2 = 0
        ok
    next
    if flag2 = 1
       for p=1 to 9
           if numbers[p] = 0 or numbers[p] = 1
           else
              flag = 0
           ok
       next
       if flag = 1
          for x=1 to len(str)
              if n%(number(str[x])) != 0
                 flag3 = 0
              ok
          next
          if flag3 = 1
             see n + nl
          ok            
       ok
    ok
next
