# The Ring Standard Library
# Web Library
# 2016-2018, Mahmoud Fayed <msfclipper@yahoo.com>

Package System.Web

	Class WebPage from Application

		aObjs = []  

		AddAttribute(self,aObjsAttributes)

		StartHtml()
		
		Func braceend

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
			for x in aObjs
				WebPrint( x.getdata() + nl )
			next
			WebPrint( nl + "</body>" + nl + "</html>" + nl )

