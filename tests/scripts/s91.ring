aList = [1,2,3,4,5,6,7,8,9,10]
see "Print List" + nl
see aList

del(aList,5)
see "List after deleting item number 5 :" + nl
see aList

del(aList,10) # error item outside list size range
see "done" + nl