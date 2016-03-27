cStr = "12 drummers drumming, 11 pipers piping, 10 lords a-leaping"
aRes = [] 
cBuffer = ""
for x in cStr
	if isdigit(x) 
		cBuffer += x 
	ELSE 
		if cBuffer != "" 
			aRes + cBuffer 
			cBuffer = "" 
		ok 
	ok
next
see aRes
