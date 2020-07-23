# Project : Sierpinski triangle
# Date    : 2017/09/20
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>
 
norder=4
xy = list(40)
for i = 1 to 40
    xy[i] = "                               "
next 
triangle(1, 1, norder)
for i = 1 to 36
    see xy[i] + nl
next 
 
func triangle(x, y, n)
     if n = 0
        xy[y] = left(xy[y],x-1) + "*" + substr(xy[y],x+1)
     else
        n=n-1
        length=pow(2,n)
        triangle(x, y+length, n)
        triangle(x+length, y, n)
        triangle(x+length*2, y+length, n)
     ok
