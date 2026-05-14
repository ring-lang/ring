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
			cSavedAttr  = cAttrOutput
			cSavedStyle = cStyleOutput
			cAttrOutput = "" cStyleOutput = ""
			aStack + ["a", "", "", cSavedAttr, cSavedStyle, []]
			return self

		Func GetDiv
			cSavedAttr  = cAttrOutput
			cSavedStyle = cStyleOutput
			cAttrOutput = "" cStyleOutput = ""
			aStack + ["div", "", "", cSavedAttr, cSavedStyle, []]
			return self

		Func GetForm
			cSavedAttr  = cAttrOutput
			cSavedStyle = cStyleOutput
			cAttrOutput = "" cStyleOutput = ""
			aStack + ["form", "", "", cSavedAttr, cSavedStyle, []]
			return self

		Func GetInput
			cSavedAttr  = cAttrOutput
			cSavedStyle = cStyleOutput
			cAttrOutput = "" cStyleOutput = ""
			aStack + ["input", "", "", cSavedAttr, cSavedStyle, []]
			return self

		Func GetTextArea
			cSavedAttr  = cAttrOutput
			cSavedStyle = cStyleOutput
			cAttrOutput = "" cStyleOutput = ""
			aStack + ["textarea", "", "", cSavedAttr, cSavedStyle, []]
			return self

		Func GetSelect
			cSavedAttr  = cAttrOutput
			cSavedStyle = cStyleOutput
			cAttrOutput = "" cStyleOutput = ""
			aStack + ["select", "", "", cSavedAttr, cSavedStyle, []]
			return self

		Func GetOption
			cSavedAttr  = cAttrOutput
			cSavedStyle = cStyleOutput
			cAttrOutput = "" cStyleOutput = ""
			aStack + ["option", "", "", cSavedAttr, cSavedStyle, []]
			return self

		Func GetImage
			cSavedAttr  = cAttrOutput
			cSavedStyle = cStyleOutput
			cAttrOutput = "" cStyleOutput = ""
			aStack + ["img", "", "", cSavedAttr, cSavedStyle, []]
			return self

		Func GetUL
			cSavedAttr  = cAttrOutput
			cSavedStyle = cStyleOutput
			cAttrOutput = "" cStyleOutput = ""
			aStack + ["ul", "", "", cSavedAttr, cSavedStyle, []]
			return self

		Func GetLI
			cSavedAttr  = cAttrOutput
			cSavedStyle = cStyleOutput
			cAttrOutput = "" cStyleOutput = ""
			aStack + ["li", "", "", cSavedAttr, cSavedStyle, []]
			return self

		Func GetTable
			cSavedAttr  = cAttrOutput
			cSavedStyle = cStyleOutput
			cAttrOutput = "" cStyleOutput = ""
			aStack + ["table", "", "", cSavedAttr, cSavedStyle, []]
			return self

		Func GetTr
			cSavedAttr  = cAttrOutput
			cSavedStyle = cStyleOutput
			cAttrOutput = "" cStyleOutput = ""
			aStack + ["tr", "", "", cSavedAttr, cSavedStyle, []]
			return self

		Func GetTd
			cSavedAttr  = cAttrOutput
			cSavedStyle = cStyleOutput
			cAttrOutput = "" cStyleOutput = ""
			aStack + ["td", "", "", cSavedAttr, cSavedStyle, []]
			return self

		Func GetTh
			cSavedAttr  = cAttrOutput
			cSavedStyle = cStyleOutput
			cAttrOutput = "" cStyleOutput = ""
			aStack + ["th", "", "", cSavedAttr, cSavedStyle, []]
			return self

		Func GetThead
			cSavedAttr  = cAttrOutput
			cSavedStyle = cStyleOutput
			cAttrOutput = "" cStyleOutput = ""
			aStack + ["thead", "", "", cSavedAttr, cSavedStyle, []]
			return self

		Func GetTBody
			cSavedAttr  = cAttrOutput
			cSavedStyle = cStyleOutput
			cAttrOutput = "" cStyleOutput = ""
			aStack + ["tbody", "", "", cSavedAttr, cSavedStyle, []]
			return self

		Func GetTFoot
			cSavedAttr  = cAttrOutput
			cSavedStyle = cStyleOutput
			cAttrOutput = "" cStyleOutput = ""
			aStack + ["tfoot", "", "", cSavedAttr, cSavedStyle, []]
			return self

		Func GetAudio
			cSavedAttr  = cAttrOutput
			cSavedStyle = cStyleOutput
			cAttrOutput = "" cStyleOutput = ""
			aStack + ["audio", "", "", cSavedAttr, cSavedStyle, []]
			return self

		Func GetVideo
			cSavedAttr  = cAttrOutput
			cSavedStyle = cStyleOutput
			cAttrOutput = "" cStyleOutput = ""
			aStack + ["video", "", "", cSavedAttr, cSavedStyle, []]
			return self

		Func GetH1
			cSavedAttr  = cAttrOutput
			cSavedStyle = cStyleOutput
			cAttrOutput = "" cStyleOutput = ""
			aStack + ["h1", "", "", cSavedAttr, cSavedStyle, []]
			return self

		Func GetH2
			cSavedAttr  = cAttrOutput
			cSavedStyle = cStyleOutput
			cAttrOutput = "" cStyleOutput = ""
			aStack + ["h2", "", "", cSavedAttr, cSavedStyle, []]
			return self

		Func GetH3
			cSavedAttr  = cAttrOutput
			cSavedStyle = cStyleOutput
			cAttrOutput = "" cStyleOutput = ""
			aStack + ["h3", "", "", cSavedAttr, cSavedStyle, []]
			return self

		Func GetH4
			cSavedAttr  = cAttrOutput
			cSavedStyle = cStyleOutput
			cAttrOutput = "" cStyleOutput = ""
			aStack + ["h4", "", "", cSavedAttr, cSavedStyle, []]
			return self

		Func GetH5
			cSavedAttr  = cAttrOutput
			cSavedStyle = cStyleOutput
			cAttrOutput = "" cStyleOutput = ""
			aStack + ["h5", "", "", cSavedAttr, cSavedStyle, []]
			return self

		Func GetH6
			cSavedAttr  = cAttrOutput
			cSavedStyle = cStyleOutput
			cAttrOutput = "" cStyleOutput = ""
			aStack + ["h6", "", "", cSavedAttr, cSavedStyle, []]
			return self

		Func GetP
			cSavedAttr  = cAttrOutput
			cSavedStyle = cStyleOutput
			cAttrOutput = "" cStyleOutput = ""
			aStack + ["p", "", "", cSavedAttr, cSavedStyle, []]
			return self

		Func GetNav
			cSavedAttr  = cAttrOutput
			cSavedStyle = cStyleOutput
			cAttrOutput = "" cStyleOutput = ""
			aStack + ["nav", "", "", cSavedAttr, cSavedStyle, []]
			return self

		Func GetSpan
			cSavedAttr  = cAttrOutput
			cSavedStyle = cStyleOutput
			cAttrOutput = "" cStyleOutput = ""
			aStack + ["span", "", "", cSavedAttr, cSavedStyle, []]
			return self

		Func GetButton
			cSavedAttr  = cAttrOutput
			cSavedStyle = cStyleOutput
			cAttrOutput = "" cStyleOutput = ""
			aStack + ["button", "", "", cSavedAttr, cSavedStyle, []]
			return self

