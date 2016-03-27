FUNC MAIN

	cStr = "nice"
	cStr += "good"

	o1 = new myclass { gostart() }

func myproc

	
	cCode = '<%
	see "mmm len value : " + len(myaList) + nl
	for x = 1 to len(myaList)
		see "x value : " + x + nl
		see "len value : " + len(myaList) + nl
		see "type : " + type(myaList) + nl
		see "name : " +  myaList[x].name + nl
		see "age : " + myaList[x].age + nl
		t = 0
	next
	%>'

	see "The len value is : " + len(myaList) + nl

	#try
	SEE TEMPLATE(CCODE)
	#catch
	#done

	see "The len value : " + len(myaList) + nl

Func Template cStr
	r = 0
	aList = []
	cResult = ""
	cCode = ""
	nPos = substr(cStr,"<%")
	if nPos = 0
		aList + cStr
		cCode += "cResult += aList[" + len(aList) + "]" + nl
	ok
	while nPos > 0
		cText = left(cStr,nPos-1)
		if cText != ""
			aList + cText
			cCode += "cResult += aList[" + len(aList) + "]" + nl
		ok
		cStr = substr(cStr,nPos+2)
		nPos = substr(cStr,"%>")
		if nPos > 0					
			if left(cStr,1) = "="
				cCode += "cResult += (" + substr(cStr,2,nPos-2) + ")" + nl	
			else
				cCode += left(cStr,nPos-1) + nl						
			ok
			cStr = substr(cStr,nPos+2)
		ok
		nPos = substr(cStr,"<%")
		if nPos = 0
			aList + cStr
			cCode += "cResult += aList[" + len(aList) + "]" + nl
		ok
	end
	see "Code : " + nl
	see cCode
	eval(cCode)
	return cResult

class myclass
	
	myaList = list(10)
	
	myobj = new object {
		name = "mahmoud"
		age  = 28
	}

	for x = 1 to len(myaList)
		myaList[x] = new object {
			name = "object" + x
			age = x+20
		}
	next

	func gostart
	
		myproc()

class object name age
