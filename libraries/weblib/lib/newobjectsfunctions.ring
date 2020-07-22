# The Ring Standard Library
# Web Library
# 2016-2018, Mahmoud Fayed <msfclipper@yahoo.com>

Package System.Web

	Class NewObjectsFunctions

		Func Text x

			if isstring(x)
				x = htmlspecialchars(x)
			but isnumber(x)
				x = htmlspecialchars(string(x))
			ok

			aObjs + new ObjsBase
			aObjs[len(aObjs)].cOutput =  NL+GetTabs()+x

		Func HTML x

			aObjs + new ObjsBase
			aObjs[len(aObjs)].cOutput =  NL+GetTabs()+x


		Func GetLink
			aObjs + new Link
			return aObjs[len(aObjs)]
		
		Func GetNewLine
			aObjs + new NewLine

		Func GetDiv
			aObjs + new Div
			return aObjs[len(aObjs)]

		Func GetForm
			aObjs + new Form
			return aObjs[len(aObjs)]

		Func GetInput
			aObjs + new Input
			return aObjs[len(aObjs)]

		Func GetTextArea
			aObjs + new TextArea
			return aObjs[len(aObjs)]

		Func GetSelect
			aObjs + new Select
			return aObjs[len(aObjs)]

		Func GetOption
			aObjs + new Option
			return aObjs[len(aObjs)]

		Func GetImage
			aObjs + new Image
			return aObjs[len(aObjs)]

		Func GetUL
			aObjs + new UL
			return aObjs[len(aObjs)]

		Func GetLI
			aObjs + new LI
			return aObjs[len(aObjs)]

		Func GetTable
			aObjs + new Table
			return aObjs[len(aObjs)]

		Func GetTr
			aObjs + new TR
			return aObjs[len(aObjs)]

		Func GetTd
			aObjs + new TD
			return aObjs[len(aObjs)]

		Func GetTh
			aObjs + new TH
			return aObjs[len(aObjs)]

		Func GetAudio
			aObjs + new Audio
			return aObjs[len(aObjs)]

		Func GetVideo
			aObjs + new Video
			return aObjs[len(aObjs)]
		Func GetH1
			aObjs + new H1
			return aObjs[len(aObjs)]

		Func GetH2
			aObjs + new H2
			return aObjs[len(aObjs)]

		Func GetH3
			aObjs + new H3
			return aObjs[len(aObjs)]

		Func GetH4
			aObjs + new H4
			return aObjs[len(aObjs)]

		Func GetH5
			aObjs + new H5
			return aObjs[len(aObjs)]

		Func GetH6
			aObjs + new H6
			return aObjs[len(aObjs)]

		Func GetP
			aObjs + new P
			return aObjs[len(aObjs)]

		Func GetNav
			aObjs + new Nav
			return aObjs[len(aObjs)]

		Func GetSpan
			aObjs + new Span
			return aObjs[len(aObjs)]

		Func GetButton
			aObjs + new Button
			return aObjs[len(aObjs)]
