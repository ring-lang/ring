aList = ["one","two","other","three"]
Del(aList,3)	# delete item number three
see aList   	# print one two three

aList = 1:20  see len(aList)  # print 20

see nl

aList = 1:10	# create list contains numbers from 1 to 10
aList + 11	# add number 11 to the list
see aList	# print the list

aList = ["cairo","riyadh"]
see "Egypt :" + aList[1] + nl +
     "KSA   :" + aList[2] + nl

aList = [10,12,3,5,31,15]
see "sorted list: " +nl
sort(aList)
see alist
aList = reverse(aList)
see alist
