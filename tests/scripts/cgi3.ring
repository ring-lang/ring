#!b:\mahmoud\apps\nova2\nova.exe 

func main

	starthtml()
	
	#see get("QUERY_STRING")
	#newline()
	
	mydata= decode2(get("QUERY_STRING"))
	see mydata
	
func starthtml
	see "Content-type: text/html"+nl+nl
	
func newline
	see "<br />"

func decode cStr
	cStr = cStr + "&"
	aOutput = []
	cValue = ""
	for t = 1 to len(cStr)
		if cStr[t] = "="  
			add(aOutput,cValue)
			cValue = ""
		but cStr[t] = "&"
			add(aOutput,cValue)
			cValue = ""
		else
			cValue = cValue + cStr[t]
		ok
	next
	return aOutput
	
func decode2 cStr
	cStr = cStr + "&"
	aOutput = []
	aRes = []
	cValue = ""
	for t = 1 to len(cStr)
		if cStr[t] = "="  
			add(aRes,cValue)
			cValue = ""
		but cStr[t] = "&"
			add(aRes,cValue)
			cValue = ""
			add(aOutput,aRes)
			aRes = []
		else
			cValue = cValue + cStr[t]
		ok
	next
	return aOutput