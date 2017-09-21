# Project : Leanardo numbers
# Date    : 2017/09/21
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>
 
n0 = 1
n1 = 1
add = 1
see "" + n0 + " " + n1
for i=3 to 25
    temp=n1
    n1=n0+n1+add
    n0=temp
    see " "+ n1
next 
