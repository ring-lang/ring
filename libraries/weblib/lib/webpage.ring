# The Ring Standard Library
# Web Library
# 2016-2026, Mahmoud Fayed <msfclipper@yahoo.com>

Package System.Web

	Class WebPage from Application

		# Stack frames: [tag, contentBuf, extraClose, savedAttr, savedStyle, specialAttrs]
		aStack = []

		cAttrOutput  = ""
		cStyleOutput = ""

		AddAttribute(self, aObjsAttributes)
		AddAttribute(self, htmlcssattributes)

		StartHtml()

		Func braceend
			if len(aStack) > 0
				popTag()
			else
				WebPrint( cCookies + GetHTMLStart() +"<!DOCTYPE html>" + WindowsNL() +
				nl+ '<html lang="en">' + nl +
				"<head>"+nl+CHAR(9)+"<title>"+Title+"</title>"+nl+
				"<meta charset='UTF-8'>" + nl+
				nl+CHAR(9)+scriptlibs()+nl )
				if cCSS != NULL
					WebPrint( Char(9)+"<style>"+nl+CHAR(9)+CHAR(9)+cCSS+nl+Char(9)+"</style>"+nl )
				ok
				WebPrint( nl+"</head>" + nl +
				"<body"+ cBody + "> " + nl )
				WebPrint( cOutput + nl )
				WebPrint( nl + "</body>" + nl + "</html>" + nl )
			ok

		Func getdata
			return cOutput

