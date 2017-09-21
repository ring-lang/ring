# Project : Vector products
# Date    : 2017/09/21
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>
 
d = list(3)
e = list(3)
a = [3, 4, 5]
b = [4, 3, 5]
c = [-5, -12, -13]
 
see "a . b = " + dot(a,b) + nl
cross(a,b,d)
see "a x b = (" + d[1] + ", " + d[2] + ", " + d[3] + ")" + nl
see "a . (b x c) = " + scalartriple(a,b,c) + nl
vectortriple(a,b,c,d)
 
def dot(a,b)
    sum = 0
    for n=1 to len(a)
        sum = sum + a[n]*b[n]
    next
    return sum
 
func cross(a,b,d)
     d = [a[2]*b[3]-a[3]*b[2], a[3]*b[1]-a[1]*b[3], a[1]*b[2]-a[2]*b[1]]
 
func scalartriple(a,b,c)
     cross(b,c,d)
     return dot(a,d)
 
func vectortriple(a,b,c,d)
     cross(b,c,d)
     cross(a,d,e)
     see "a x (b x c) = (" + e[1] + ", " +e[2] + ", " + e[3] + ")" 
