# The Ring Standard Library
# Web Library
# 2016-2018, Mahmoud Fayed <msfclipper@yahoo.com>

Import System.Web

Func GetaPageVars
	return aPageVars 

Func Gethtmlcssattributes
	return htmlcssattributes

Func GetaObjsAttributes
	return aObjsAttributes

Func LoadVars
	if sysget("REQUEST_METHOD") = NULL
		# The Web Library is not called from Web Application (From the Browser)
		return 
	ok
	New Application
	{
	    	if sysget("REQUEST_METHOD") = "GET"
			cInput = sysget("QUERY_STRING")
		else
			cInput = input(sysget("CONTENT_LENGTH"))
		ok
		
		aPageVars = decode(cInput)
		aArray = getcookies()

		for x in aArray
			aPageVars+x
		next
	}

	return cInput

Func WebPage return new WebPage

Func BootStrapWebPage return new BootStrapWebPage

Func htmlspecialchars cStr
	cResult = ""
	if isstring(cStr) and len(cStr) > 0
		for x in cStr
			if x = '&'  cResult += '&amp;'
			but x = '"' cResult += '&quot;'
			but x = "'" cResult += '&#039;'
			but x = '<' cResult += '&lt;'
			but x = '>' cResult += '&gt;'
			but x = ' ' cResult += '&nbsp;'
			else 	    cResult += x
			ok
		next
	ok
	return cResult

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

Func Alert cMessage
	New Page
	{
		script( "document.onready = function() { alert(" +'"' + cMessage + '"' + ") }" )
	}

func HTML2PDF filepath,filefolder,cStr

	cTempName = WL_JustFileName(tempname())
	cFileName = filepath+cTempName
	cHTML = cFileName + ".html"
	cPDF =  cFileName + ".pdf"
	write(cHTML,cStr)
	system("wkhtmltopdf " + cHTML + " " + cPDF)
	New Page 
	{  
		text(cPDF)
		script(scriptredirection(filefolder+cTempName+".pdf"))  
	}

func WL_JustFileName cFile
	for x = len(cfile) to 1 step -1
		if cfile[x] = "\" or cfile[x] = "/"
			cfile = substr(cfile,x+1)
			exit
		ok
	next
	return cFile 
