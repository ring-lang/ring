cStr = ""
aList = cfunctions()
for x = 1 to len(aLisT)
	cStr += aList[x]
	if x != len(aList)
		cStr += "|"
	ok
next
write("functions.txt",cStr)
