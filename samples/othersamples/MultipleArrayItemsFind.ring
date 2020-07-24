# Project : CalmoSoft Multiple Array Items Find

# Date    : 24/02/2020
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>

aList = [2,1,3,5,3,8,3,9,3]

item = 3
see "aList = "
showArray(aList)
see nl
positionList = MultipleArrayItemsFind(aList,item)
see "positionList = "
showArray(positionList)

func MultipleArrayItemsFind(aList,item)

     cList = []
     nr = 0

     ind = find(aList,item)
     while ind > 0
           ind = find(aList,item)
           if ind > 0
              add(cList,ind+nr)
              del(aList,ind)

              nr = nr + 1
           ok
     end

     return cList

func showArray(array)

     txt = ""
     see "["
     for n = 1 to len(array)
         txt = txt + array[n] + ","
     next
     txt = left(txt,len(txt)-1)
     txt = txt + "]"
     see txt 