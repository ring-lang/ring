# Reference count overflow (List)

aList = []

nMax   = 8388608
aList2 = list(nMax)

for m=1 to nMax
	aList2 + ref(aList)
next
