# Project : CalmoSoft Multiple Array Items Insert
# Date    : 24/02/2020
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>


aList = [2,3,5,8,9]
insertList = [4,6,7]
see "aList = "
showArray(aList)
see nl

MultipleArrayItemsInsert(aList)

func MultipleArrayItemsInsert(aList)
     for n = 1 to len(insertList)
         add(aList,insertList[n])
     next
     see "insert = "
     showArray(aList)

func showArray(array)
     txt = ""
     see "["
     for n = 1 to len(array)
         txt = txt + array[n] + ","
     next
     txt = left(txt,len(txt)-1)
     txt = txt + "]"
     see txt    
