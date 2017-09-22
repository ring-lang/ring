# Project : Longest Common Substring
# Date    : 2017/09/22
# Author : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>
 
str1 = "testing123testing" 
str2 = "tsitest"
see longest(str1, str2)
 
func  longest(str1, str2)
subarr = []
for n=1 to len(str1)
    for m=1 to len(str1)
        sub = substr(str1, n, m)
        if substr(str2, sub) > 0
           add(subarr, sub)
        ok
    next
next
 
temp = 0
for n=1 to len(subarr) 
    if len(subarr[n]) > temp
       temp = len(subarr[n])
       subend = subarr[n]
    ok
next
see subend + nl
