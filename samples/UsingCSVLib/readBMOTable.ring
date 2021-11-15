load "csvlib.ring"

aList = CSV2List( read("BMO.csv") )

for subList in aList
	cStr = ""
	for item in subList
		cData = width(item, 10)
		if cStr = ""
			cStr += cData
		else
			cStr += " - " + cData
		ok
	next
	? cStr
next

func width vValue, nSize
	if ! ( isString(vValue) or isNumber(vValue) )
		raise("Bad parameter type! the width() function expect a String/Number")
	ok
	if isNumber(vValue) vValue = "" + vValue ok
	if len(vValue) < nSize  vValue = vValue + Copy(" ",nSize-len(vValue)) ok
	return vValue
		