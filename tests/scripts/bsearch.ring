N = 1000

aList = cFunctions()
see aList

#linear search

see "Linear Search Test" + nl

cFind = "sendemail"
nTime = clock()
for x  = 1 to N
	for t in aList
		if t = cFind
			exit
		ok
	next
next
see "Time : " + (clock() - nTime) + nl

#binary search

see "Binary Search Test" + nl
nTime = clock()
aList = sort(aList)
for x  = 1 to N
	first = 1
	last = len(aList)
	while first <= last
		middle = ceil((first+last) / 2)
		if strcmp(aList[middle],cFind) = 0
			exit
		but strcmp(aList[middle],cFind) < 0
			first = middle + 1
		else
			last = middle - 1
		ok
	end
next
see "Time : " + (clock() - nTime) + nl
