# The Ring Standard Library
# Web Library
# 2016-2018, Mahmoud Fayed <msfclipper@yahoo.com>

load "globals.ring"
load "functions.ring"
load "prepare.ring"
load "application.ring"
load "page.ring"
load "scriptfunctions.ring"
load "stylefunctions.ring"
load "pagebuffer.ring"
load "html2pdf.ring"
load "bootstrappage.ring"
load "webpage.ring"
load "bootstrapwebpage.ring"
load "htmlpage.ring"
load "objsbase.ring"

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


	Class H1 from ObjsBase 
		Func braceend
			cOutput += nl+'<h1'
			addattributes()
			AddStyle()
			getobjsdata()
			cOutput += nl+"</h1>" + nl
			cOutput = TabMLString(cOutput)

	Class H2 from ObjsBase 
		Func braceend
			cOutput += nl+'<h2'
			addattributes()
			AddStyle()
			getobjsdata()
			cOutput += nl+"</h2>" + nl
			cOutput = TabMLString(cOutput)

	Class H3 from ObjsBase 
		Func braceend
			cOutput += nl+'<h3'
			addattributes()
			AddStyle()
			getobjsdata()
			cOutput += nl+"</h3>" + nl
			cOutput = TabMLString(cOutput)

	Class H4 from ObjsBase 
		Func braceend
			cOutput += nl+'<h4'
			addattributes()
			AddStyle()
			getobjsdata()
			cOutput += nl+"</h4>" + nl
			cOutput = TabMLString(cOutput)

	Class H5 from ObjsBase 
		Func braceend
			cOutput += nl+'<h5'
			addattributes()
			AddStyle()
			getobjsdata()
			cOutput += nl+"</h5>" + nl
			cOutput = TabMLString(cOutput)

	Class H6 from ObjsBase 
		Func braceend
			cOutput += nl+'<h6'
			addattributes()
			AddStyle()
			getobjsdata()
			cOutput += nl+"</h6>" + nl
			cOutput = TabMLString(cOutput)

	Class p from ObjsBase 
		Func braceend
			cOutput += nl+'<p'
			addattributes()
			AddStyle()
			getobjsdata()
			cOutput += nl+"</p>" + nl
			cOutput = TabMLString(cOutput)


	Class Link from ObjsBase
		title  link
		Func braceend
			cOutput = nl+GetTabs() + "<a href='" + Link + "'> "+ Title + " </a> " + nl			

	Class NewLine from ObjsBase
		cOutput = GetTabs() + "<br />"

	Class Div from ObjsBase 
		Func braceend
			cOutput += nl+'<div'
			addattributes()
			AddStyle()
			getobjsdata()
			cOutput += nl+"</div>" + nl
			cOutput = TabMLString(cOutput)

	Class Form from ObjsBase 
		action method target
		Func braceend
			cOutput += nl+'<form'
			addattributes()
			elementattribute(:action)
			elementattribute(:method)
			elementattribute(:target)
			AddStyle()
			getobjsdata()
			cOutput += nl+"</form>" + nl
			cOutput = TabMLString(cOutput)

	Class Input from ObjsBase 
		type min max checked=false
		Func braceend
			cOutput += nl+'<input'			
			elementattribute(:type)
			addattributes()			
			elementattribute(:min)
			elementattribute(:max)
			if checked
				cOutput += " checked"
			ok
			AddStyle()
			cOutput = TabMLString(cOutput)

	Class TextArea from ObjsBase 
		rows cols
		Func braceend
			cOutput += nl+'<textarea'
			addattributes()
			elementattribute(:rows)
			elementattribute(:cols)
			AddStyle()
			getobjsdata()
			cOutput += nl+"</textarea>" + nl
			cOutput = TabMLString(cOutput)

	Class Select from ObjsBase 
		multiple
		Func braceend
			cOutput += nl+'<select'
			addattributes()
			elementattribute(:multiple)
			AddStyle()
			getobjsdata()
			cOutput += nl+"</select>" + nl
			cOutput = TabMLString(cOutput)

	Class Option from ObjsBase 
		Func braceend
			cOutput += nl+'<option'
			addattributes()
			AddStyle()
			getobjsdata()
			cOutput += nl+"</option>" + nl
			cOutput = TabMLString(cOutput)

	Class Image from ObjsBase 
		src alt
		Func braceend
			cOutput += nl+'<img'
			addattributes()
			elementattribute(:src)
			elementattribute(:alt)
			AddStyle()
			getobjsdata()
			cOutput = TabMLString(cOutput)

	Class UL from ObjsBase 
		Func braceend
			cOutput += nl+'<ul'
			addattributes()
			AddStyle()
			getobjsdata()
			cOutput += nl+"</ul>" + nl
			cOutput = TabMLString(cOutput)

	Class LI from ObjsBase 
		Func braceend
			cOutput += nl+'<li'
			addattributes()
			AddStyle()
			getobjsdata()
			cOutput += nl+"</li>" + nl
			cOutput = TabMLString(cOutput)

	Class Table from ObjsBase 
		Func braceend
			cOutput += nl+'<table'
			addattributes()
			AddStyle()
			getobjsdata()
			cOutput += nl+"</table>" + nl
			cOutput = TabMLString(cOutput)

	Class TR from ObjsBase 
		Func braceend
			cOutput += nl+'<tr'
			addattributes()
			AddStyle()
			getobjsdata()
			cOutput += nl+"</tr>" + nl
			cOutput = TabMLString(cOutput)

	Class TD from ObjsBase 
		Func braceend
			cOutput += nl+'<td'
			addattributes()
			AddStyle()
			getobjsdata()
			cOutput += nl+"</td>" + nl
			cOutput = TabMLString(cOutput)

	Class TH from ObjsBase 
		Func braceend
			cOutput += nl+'<th'
			addattributes()
			AddStyle()
			getobjsdata()
			cOutput += nl+"</th>" + nl
			cOutput = TabMLString(cOutput)

	Class Audio from ObjsBase 
		src type
		Func braceend
			cOutput += nl+'<audio controls'
			addattributes()
			cOutput += '> <source '
			elementattribute(:src)
			elementattribute(:type)
			AddStyle()
			getobjsdata()
			cOutput += nl+"> Your browser does not support the audio element. </audio>" + nl
			cOutput = TabMLString(cOutput)

	Class Video from ObjsBase 
		src type
		Func braceend
			cOutput += nl+'<video controls'
			addattributes()
			elementattribute(:width)
			elementattribute(:height)
			cOutput += '> <source '
			elementattribute(:src)
			elementattribute(:type)
			AddStyle()
			getobjsdata()
			cOutput += nl+"> Your browser does not support the video tag. </video>" + nl
			cOutput = TabMLString(cOutput)

	Class NAV from ObjsBase 
		Func braceend
			cOutput += nl+'<nav'
			addattributes()
			AddStyle()
			getobjsdata()
			cOutput += nl+"</nav>" + nl
			cOutput = TabMLString(cOutput)

	Class Span from ObjsBase 
		Func braceend
			cOutput += nl+'<span'
			addattributes()
			AddStyle()
			getobjsdata()
			cOutput += nl+"</span>" + nl
			cOutput = TabMLString(cOutput)

	Class Button from ObjsBase 
		Func braceend
			cOutput += nl+'<button'
			addattributes()
			AddStyle()
			getobjsdata()
			cOutput += nl+"</button>" + nl
			cOutput = TabMLString(cOutput)
