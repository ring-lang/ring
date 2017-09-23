# Project : Idiomatically determine all the lowercase and uppercase letters
# Date    : 2017/09/20
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>
 
aList = "a":"z"
see "Lower case : "
for n=1 to len(aList)
    see aList[n]
next
see nl
see "Lower case : "
aList = "A":"Z"
for n=1 to len(aList)
    see aList[n]
next
