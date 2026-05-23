# The Ring Standard Library
# Web Library
# 2016-2026, Mahmoud Fayed <msfclipper@yahoo.com>

Package System.Web

	Class NewObjectsFunctions

		Func Text x
			if isstring(x)
				x = htmlspecialchars(x)
			but isnumber(x)
				x = htmlspecialchars(string(x))
			ok
			if len(aStack) > 0
				aStack[len(aStack)][2] += nl + GetTabs() + x
			else
				cOutput += nl + GetTabs() + x
			ok

		Func HTML x
			if len(aStack) > 0
				aStack[len(aStack)][2] += nl + GetTabs() + x
			else
				cOutput += nl + GetTabs() + x
			ok


		Func GetNewLine
			if len(aStack) > 0
				aStack[len(aStack)][2] += "<br />"
			else
				cOutput += "<br />"
			ok

		# pops frame, renders element, restores parent attr/style buffers.
		# Uses cThisAttr/cThisStyle (this element's own buffers) for the tag,
		# then restores cAttrOutput/cStyleOutput to the parent's saved values.
		func PopTag
			if len(aStack) = 0 return ok
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
				cHref  = getSpecialAttr(aSpecial,"href")
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

		Func PushNewTag cObjType
			aStack + [cObjType, "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

		Func GetLink
			return PushNewTag("a")

		Func GetDiv
			return PushNewTag("div")

		Func GetForm
			return PushNewTag("form")

		Func GetInput
			return PushNewTag("input")

		Func GetTextArea
			return PushNewTag("textarea")

		Func GetSelect
			return PushNewTag("select")

		Func GetOption
			return PushNewTag("option")

		Func GetImage
			return PushNewTag("img")

		Func GetUL
			return PushNewTag("ul")

		Func GetLI
			return PushNewTag("li")

		Func GetTable
			return PushNewTag("table")

		Func GetTr
			return PushNewTag("tr")

		Func GetTd
			return PushNewTag("td")

		Func GetTh
			return PushNewTag("th")

		Func GetThead
			return PushNewTag("thead")

		Func GetTBody
			return PushNewTag("tbody")

		Func GetTFoot
			return PushNewTag("tfoot")

		Func GetAudio
			return PushNewTag("audio")

		Func GetVideo
			return PushNewTag("video")

		Func GetH1
			return PushNewTag("h1")

		Func GetH2
			return PushNewTag("h2")

		Func GetH3
			return PushNewTag("h3")

		Func GetH4
			return PushNewTag("h4")

		Func GetH5
			return PushNewTag("h5")

		Func GetH6
			return PushNewTag("h6")

		Func GetP
			return PushNewTag("p")

		Func GetNav
			return PushNewTag("nav")

		Func GetSpan
			return PushNewTag("span")

		Func GetButton
			return PushNewTag("button")
