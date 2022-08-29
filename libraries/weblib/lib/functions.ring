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
			if sysget("CONTENT_LENGTH") > 0
				cInput = input(sysget("CONTENT_LENGTH"))
				if sysget("QUERY_STRING") != ""
					cInput += "&" + sysget("QUERY_STRING")

				ok
			else
				cInput = ""
			ok
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
