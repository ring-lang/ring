# Project : Pythagorean quadruples
# Date    : 2017/12/17
# Author : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>
 
limit = 22
pq = list(limit)
for n = 1 to limit
      for m = 1 to limit
           for p = 1 to limit
                 for x = 1 to limit
                       if pow(x,2) = pow(n,2) + pow(m,2) + pow(p,2)
                          pq[x] = 1
                       ok
                 next
           next
      next
next
pqstr = ""
for d = 1 to limit
      if pq[d] = 0
         pqstr = pqstr + d + " "
      ok
next
see pqstr + nl
