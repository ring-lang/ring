# Project : Verify distribution uniformity/Naive
# Date    : 2017/09/21
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>
 
maxrnd = 7
for r = 2 to 5
    check = distcheck(pow(10,r), 0.05)
    see "over " + pow(10,r) + " runs dice5 " + nl
    if check 
       see "failed distribution check with " + check + " bin(s) out of range" + nl
    else
       see "passed distribution check" + nl
    ok
next
 
func distcheck(repet, delta)
m = 1
s = 0
bins = list(maxrnd)
for i = 1 to repet
    r = dice5() + 1
    bins[r] = bins[r] + 1
    if r>m m = r ok
next
for i = 1 to m
    if bins[i]/(repet/m) > 1+delta s = s + 1 ok
    if bins[i]/(repet/m) < 1-delta s = s + 1 ok
next
return s
 
func dice5 
     return random(5)
