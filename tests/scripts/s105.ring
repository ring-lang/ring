cDate = date()

see date() + nl
see time() + nl
see "Year : "
for x = 1 to 4
	see cDate[x]
next
see nl
see "Month : "
for x = 6 to 7
	see cDate[x]
next
see nl
see "Day : "
for x = 9 to 10
	see cDate[x]
next

see nl
see "Year : " + substr(cDate,1,4) + " Month : " + substr(cDate,6,7) + " Day " + substr(cDate,9,10)


func substr cStr,x,y
	cResult = ""
	for t = x to y
		cResult = cResult + cStr[t]
	next
	return cResult