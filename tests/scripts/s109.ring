for x = 0 to 255
	see "Decimal : " see x see " Hex : " + upper(hex(x)) + nl
next

aList = []
for x = 0 to 255
add(alist,hex(x))
next

for x = 1 to len(aList)
	see "Hex : " + aList[x] + " Decimal : " see dec(aList[x]) see nl
next