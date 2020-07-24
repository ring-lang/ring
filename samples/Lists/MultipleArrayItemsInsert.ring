# Project : CalmoSoft Multiple Array Items Insert
# Date    : 26/02/2020
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>


aList = [2,3,5,8,9]
insertList = [4,6,7]
see "aList = "
showArray(aList)
see nl
see "insertlist = "
showArray(insertList)
see nl

updatedList = MultipleArrayItemsInsert(aList,insertList)

see "updatedList = "
showArray(updatedList)

func MultipleArrayItemsInsert(aList,insertList)
     for n = 1 to len(insertList)
         add(aList,insertList[n])
     next
     return aList

func showArray(array)
     txt = ""
     see "["
     for n = 1 to len(array)
         txt = txt + array[n] + ","
     next
     txt = left(txt,len(txt)-1)
     txt = txt + "]"
     see txt    
