# The Ring Standard Library
# Web Library
# 2016-2018, Mahmoud Fayed <msfclipper@yahoo.com>

Package System.Web
			
	Class Application

		cStart = ""
		cCookies = ""
		cOutput = ""
		cCSS = ""
		Title = "Test"
		cBody = ""

		lBootstrap = False

		lPrint = True
		cPrintString = ""

		lContentType = True

		cJSJQueryPath = "https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js"
		cJSBootstrapPath = "https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.min.js"
		cCSSBootstrapPath = "https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css"

		lNoJavaScript = False

		func WebPrint cStr
			if lPrint
				see cStr
			else 
				cPrintString += cStr
			ok

		func NoOutput
			lPrint = False
			cPrintString = ""
			lContentType = False 

		func Output 			
			return cPrintString

		Func DecodeString cStr
			cStr = cStr + "&" 
			aOutput = [] 	
			aRes = [] 
			cValue = ""
			for x = 1 to len(cStr)
				t = cStr[x]
				if t = "="  
					aRes + cValue
					cValue = ""
				but t = "&" 
					aRes + cValue
					cValue = "" 
					aOutput + aRes
					aRes = []
				but t = "+"
					cValue = cValue + " "
				but t = "%"
					cValue = cValue + hex2str(cStr[x+1]+cStr[x+2])
					x = x+2
				but t = '"'
				else 
					cValue = cValue + t 
				ok
			next
			return aOutput

		Func Decode cInput
			if left(sysget("CONTENT_TYPE"),20) != "multipart/form-data;"
				return decodestring(cInput)
			ok

			# Decode (File Uploading)

			nPos = substr(cInput,"Content-Disposition") 
			cMark = left(cInput,nPos-3)

			VarsList = []

			while true

				NewVar = [] # List contains the new variable
				nPos = substr(cInput,'"')  # start of the name

				cInput = substr(cInput,nPos+1) #remove before start
				nPos = substr(cInput,'"')  # end of the name

				cVarName = left(cInput,nPos-1)
				NewVar + cVarName	# add Name to List
				cInput = substr(cInput,nPos+1) # after name	

				if left(cInput,1) = ";"

					nPos = substr(cInput,'"')  # start of the file name
					cInput = substr(cInput,nPos+1) # after file name
					nPos = substr(cInput,'"')  # end of the file name
					cFile = left(cInput,nPos-1)	# File Name to be added to the List
					
					for x = 1 to 3
						nPos = substr(cInput,nl)
						cInput = substr(cInput,nPos+1) # after new line
					next

					nPos = substr(cInput,cMark) 
					NewVar + left(cInput,nPos-2)    # Get File content

					VarsList + NewVar

					NewVar = [cVarName,:ExtraData]
					NewVar + cFile			# Add file Name
					cInput = substr(cInput,nPos)
					
				else

					for x = 1 to 2
						nPos = substr(cInput,nl)
						cInput = substr(cInput,nPos+1) # after new line
					next

					nPos = substr(cInput,nl)
					NewVar + left(cInput,nPos-1)

					cInput = substr(cInput,nPos+1) # after value

				ok

				VarsList + NewVar

				nPos = substr(cInput,cMark) 

				if substr(cInput,cMark+"--") = nPos
					exit
				ok
			end

			return VarsList
		
		Func GetFileName  aArray,cVar
			for x in aArray
				if len(x) = 3
					if x[1] = cVar
						return WL_justfilename(x[3])
					ok
				ok
			next
			return "NULL"

		Func setcookie name,value,expires,path,domain,secure
			cCookies += "Set-Cookie: "+name+"="+value+"; expires="+expires+
				    "; path="+path+"; domain="+domain+"; "+secure + "; HttpOnly"+ nl

		Func cookie name,value
			cCookies += "Set-Cookie: "+name+"="+value+";" + nl

		Func getcookies 
			cStr = sysget("HTTP_COOKIE")
			if cStr = "NULL" 	return 	OK 
			# var1=value; var2=value; var3=value
			cStr += ";"
			aOutput = [] 	 
			nPos = substr(cStr,";")
			While nPos > 0
				nPos2 = substr(cStr,"=") 
				if nPos2 = 0 exit ok
				aRes = []
				aRes + trim(left(cStr,nPos2-1))
				aRes + substr(cStr,nPos2+1,nPos-nPos2-1)
				aOutput + aRes 
				cStr = substr(cStr,nPos+1)
				nPos = substr(cStr,";")
			end
			return aOutput
			
		Func Redirect cStr
			see "Location: "+ cStr
			# This function will redirect the webpage. parameter requires destination page name.

		Func URLEncode cStr
			cOut = ""
			for x in cStr
				if isalnum(x)
					cOut += x
				but x = " "
					cOut += "+"
				else
					cOut += "%"+str2hex(x)
				ok
			next
			return cOut	
	
		Func NoJavaScript
			lNoJavaScript = True
	
		Func ScriptLibs
			if lNoJavaScript return ok
			if lBootstrap
				cStr = nl+'<meta name="viewport" content="width=device-width, initial-scale=1">' + nl +
  				       '<link rel="stylesheet" href="'+cCSSBootstrapPath+'">'+nl+
				       '<script src="'+cJSJQueryPath+'"></script>'+nl+
			 	       '<script src="'+cJSBootstrapPath+'"></script>'+nl
			else
				cStr = nl+'<script src="'+cJSJQueryPath+'"></script>'+nl
			ok	
			return TabMLString(cStr)

		Func Print
			WebPrint( cCookies + GetHTMLStart() +"<!DOCTYPE html>"+WindowsNL()+
			nl+'<html lang="en">' + nl +
			"<head>"+nl+CHAR(9)+scriptlibs()+nl+
			CHAR(9)+"<title>"+Title+"</title>"+nl+
			"<meta charset='UTF-8'>" + nl )
			if cCSS != NULL
				WebPrint( Char(9)+"<style>"+nl+CHAR(9)+CHAR(9)+cCSS+nl+Char(9)+"</style>"+nl )
			ok
			WebPrint( nl+"</head>" + nl +
			"<body"+ cBody + "> " + nl + cOutput + nl + "</body>" + nl + "</html>" )


		Func style cStyle
			cCSS += cStyle 

		Func starthtml 

			cStart = "Content-type: text/html" + nl + nl +
				   "<meta charset='UTF-8'>" + nl

		Func GetHTMLStart
			if lContentType 
				return cStart
			else 
				return ""
			ok

		Func UseLocalFiles
			cJSJQueryPath = "js/jquery.min.js"
			cJSBootstrapPath = "js/bootstrap.min.js"
			cCSSBootstrapPath = "css/bootstrap.min.css"

		Private

			nTabs = 1

			Func TabPush
				nTabs++

			Func TabPOP
				nTabs--

			Func GetTabs
				return copy(char(9),nTabs)

			Func TabMLString cStr
				aList = str2list(cStr)
				for t in aList
					t = GetTabs() + t
				next
				return list2str(aList)		
