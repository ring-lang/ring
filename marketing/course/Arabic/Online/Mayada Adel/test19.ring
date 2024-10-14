# ------------ Variables (Lists) Part 5 ------------
aList = [
	:name = "Mayada",
	:Job  = "Programmer"
]
? "Size : " + len(aList)
for aItem in aList
	? aItem
	? aItem[1]
	? aItem[2]
next
