# The Ring Standard Library
# Web Library
# 2016-2018, Mahmoud Fayed <msfclipper@yahoo.com>

Import System.Web

Func Template cFile,oObject

	cStr = Read(cFile) 
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
        if not isnull(oObject)
                oObject {
                        eval(cCode)
                }
        else
                eval(cCode)
        ok
	return cResult
