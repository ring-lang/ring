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

		Func GetLink
			aStack + ["a", "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

		Func GetDiv
			aStack + ["div", "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

		Func GetForm
			aStack + ["form", "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

		Func GetInput
			aStack + ["input", "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

		Func GetTextArea
			aStack + ["textarea", "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

		Func GetSelect
			aStack + ["select", "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

		Func GetOption
			aStack + ["option", "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

		Func GetImage
			aStack + ["img", "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

		Func GetUL
			aStack + ["ul", "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

		Func GetLI
			aStack + ["li", "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

		Func GetTable
			aStack + ["table", "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

		Func GetTr
			aStack + ["tr", "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

		Func GetTd
			aStack + ["td", "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

		Func GetTh
			aStack + ["th", "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

		Func GetThead
			aStack + ["thead", "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

		Func GetTBody
			aStack + ["tbody", "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

		Func GetTFoot
			aStack + ["tfoot", "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

		Func GetAudio
			aStack + ["audio", "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

		Func GetVideo
			aStack + ["video", "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

		Func GetH1
			aStack + ["h1", "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

		Func GetH2
			aStack + ["h2", "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

		Func GetH3
			aStack + ["h3", "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

		Func GetH4
			aStack + ["h4", "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

		Func GetH5
			aStack + ["h5", "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

		Func GetH6
			aStack + ["h6", "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

		Func GetP
			aStack + ["p", "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

		Func GetNav
			aStack + ["nav", "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

		Func GetSpan
			aStack + ["span", "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

		Func GetButton
			aStack + ["button", "", "", cAttrOutput, cStyleOutput, []]
			cAttrOutput = "" cStyleOutput = ""
			return self

