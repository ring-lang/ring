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
