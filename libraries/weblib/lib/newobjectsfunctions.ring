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

		Func PushNewObjToStack cObjType
			aStack + [cObjType, "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

		Func GetLink
			return PushNewObjToStack("a")

		Func GetDiv
			return PushNewObjToStack("div")

		Func GetForm
			return PushNewObjToStack("form")

		Func GetInput
			return PushNewObjToStack("input")

		Func GetTextArea
			return PushNewObjToStack("textarea")

		Func GetSelect
			return PushNewObjToStack("select")

		Func GetOption
			return PushNewObjToStack("option")

		Func GetImage
			return PushNewObjToStack("img")

		Func GetUL
			return PushNewObjToStack("ul")

		Func GetLI
			return PushNewObjToStack("li")

		Func GetTable
			return PushNewObjToStack("table")

		Func GetTr
			return PushNewObjToStack("tr")

		Func GetTd
			return PushNewObjToStack("td")

		Func GetTh
			return PushNewObjToStack("th")

		Func GetThead
			return PushNewObjToStack("thead")

		Func GetTBody
			return PushNewObjToStack("tbody")

		Func GetTFoot
			return PushNewObjToStack("tfoot")

		Func GetAudio
			return PushNewObjToStack("audio")

		Func GetVideo
			return PushNewObjToStack("video")

		Func GetH1
			return PushNewObjToStack("h1")

		Func GetH2
			return PushNewObjToStack("h2")

		Func GetH3
			return PushNewObjToStack("h3")

		Func GetH4
			return PushNewObjToStack("h4")

		Func GetH5
			return PushNewObjToStack("h5")

		Func GetH6
			return PushNewObjToStack("h6")

		Func GetP
			return PushNewObjToStack("p")

		Func GetNav
			return PushNewObjToStack("nav")

		Func GetSpan
			return PushNewObjToStack("span")

		Func GetButton
			return PushNewObjToStack("button")
