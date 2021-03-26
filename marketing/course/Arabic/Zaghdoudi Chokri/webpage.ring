# The Ring Standard Library
# Web Library
# 2016-2018, Mahmoud Fayed <msfclipper@yahoo.com>

Package System.Web

	Class WebPage from Application

		aObjs = []  

		AddAttribute(self,aObjsAttributes)

		StartHtml()
		
		Func braceend

			 cHtmlLang = 'lang="'+cCharset+'" ' 
			if cCharset = "ar" 
			    cHtmlLang += 'dir="rtl"' ok
			WebPrint( cCookies + GetHTMLStart() +"<!DOCTYPE html>"+WindowsNL()+
			nl+'<html ' + cHtmlLang +'>' + nl + 
			"<head>"+nl+CHAR(9)+'<meta charset="UTF-8">'+nl+
			scriptlibs()+nl+nl+CHAR(9)+"<title>"+Title+"</title>"+nl+nl)
			if cCSS != NULL
				WebPrint( Char(9)+"<style>"+nl+CHAR(9)+CHAR(9)+cCSS+nl+Char(9)+"</style>"+nl )
			ok
			WebPrint( nl+"</head>" + nl +
			"<body"+ cBody + "> " + nl )
			for x in aObjs
				WebPrint( x.getdata() + nl )
			next
			if lBootstrap
                         WebPrint('
			  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta3/dist/js/bootstrap.bundle.min.js"></script>
			 ') 
			ok
			WebPrint( nl + "</body>" + nl + "</html>" + nl )

