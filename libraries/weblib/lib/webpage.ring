# The Ring Standard Library
# Web Library
# 2016-2026, Mahmoud Fayed <msfclipper@yahoo.com>

Package System.Web

	Class WebPage from Application

		aObjs = []

		# Stack frames: [tag, contentBuf, extraClose, savedAttr, savedStyle, specialAttrs]
		aStack = []

		cAttrOutput  = ""
		cStyleOutput = ""

		AddAttribute(self, aObjsAttributes)
		AddAttribute(self, htmlcssattributes)

		StartHtml()

		Func braceend
			if len(aStack) > 0
				nTop      = len(aStack)
				frame     = aStack[nTop]
				cTag      = frame[1]
				cInner    = frame[2]
				cExtra    = frame[3]
				aSpecial  = frame[6]
				cInd      = copy(char(9), nTop - 1)
				cThisAttr  = cAttrOutput
				cThisStyle = cStyleOutput
				cAttrOutput  = frame[4]
				cStyleOutput = frame[5]
				del(aStack, nTop)
				switch cTag
				on "audio"
					cSrc   = getSpecialAttr(aSpecial,"src")
					cType  = getSpecialAttr(aSpecial,"type")
					cBlock = cInd + "<audio controls>" + nl
					cBlock += cInd + '<source src="' + cSrc + '" type="' + cType + '">' + nl
					cBlock += cInd + "Your browser does not support the audio element." + nl
					cBlock += cInd + "</audio>" + nl
				on "video"
					cSrc   = getSpecialAttr(aSpecial,"src")
					cType  = getSpecialAttr(aSpecial,"type")
					cBlock = cInd + "<video controls" + cThisAttr + ">" + nl
					cSource = cInd + '<source src="' + cSrc + '" type="' + cType + '"'
					if cThisStyle != "" cSource += ' style="' + cThisStyle + '"' ok
					cBlock += cSource + ">" + nl
					cBlock += cInd + "Your browser does not support the video tag." + nl
					cBlock += cInd + "</video>" + nl
				on "a"
					cHref      = getSpecialAttr(aSpecial,"href")
					cTitleText = getSpecialAttr(aSpecial,"linktitle")
					cBlock = cInd + "<a href='" + cHref + "'> " + cTitleText + " </a>" + nl
				on "img"
					cBlock = cInd + "<img" + specialAttrsToStr(aSpecial) + cThisAttr
					if cThisStyle != "" cBlock += ' style="' + cThisStyle + '"' ok
					cBlock += " />" + nl
				on "input"
					cBlock = cInd + "<input" + specialAttrsToStr(aSpecial) + cThisAttr
					if cThisStyle != "" cBlock += ' style="' + cThisStyle + '"' ok
					cBlock += " />" + nl
				on "textarea"
					cBlock = cInd + "<textarea" + specialAttrsToStr(aSpecial) + cThisAttr
					if cThisStyle != "" cBlock += ' style="' + cThisStyle + '"' ok
					cBlock += ">" + nl + cInner + cInd + "</textarea>" + nl
				on "form"
					cBlock = cInd + "<form" + specialAttrsToStr(aSpecial) + cThisAttr
					if cThisStyle != "" cBlock += ' style="' + cThisStyle + '"' ok
					cBlock += ">" + nl + cInner + cInd + "</form>" + nl
				on "select"
					cBlock = cInd + "<select" + specialAttrsToStr(aSpecial) + cThisAttr
					if cThisStyle != "" cBlock += ' style="' + cThisStyle + '"' ok
					cBlock += ">" + nl + cInner + cInd + "</select>" + nl
				other
					cBlock = cInd + "<" + cTag + specialAttrsToStr(aSpecial) + cThisAttr
					if cThisStyle != "" cBlock += ' style="' + cThisStyle + '"' ok
					cBlock += ">" + nl + cInner
					if cExtra != "" cBlock += cExtra ok
					cBlock += cInd + "</" + cTag + ">" + nl
				off
				if len(aStack) = 0
					cOutput += cBlock
				else
					aStack[len(aStack)][2] += cBlock
				ok
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
				for x in aObjs
					WebPrint( x.getdata() + nl )
				next
				WebPrint( nl + "</body>" + nl + "</html>" + nl )
			ok

		Func pushTag cTag
			aStack + [cTag, "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput  = ""
			cStyleOutput = ""

		Func pushTagExtra cTag, cExtraClose
			aStack + [cTag, "", cExtraClose, cAttrOutput, cStyleOutput, []]
			cAttrOutput  = ""
			cStyleOutput = ""

		Func getobjsdata
			# no-op

		Func getdata
			return cOutput

