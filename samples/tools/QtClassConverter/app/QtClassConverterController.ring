# Application  : Qt Class Converter
# Author       : Majdi Sobain <MajdiSobain@gmail.com>

# Form/Window Controller - Source Code File

load "QtClassConverterView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		open_window(:QtClassConverterController)
		Last_window().PrepareMainWindow()
		exec()
	}
}

class QtClassConverterController from windowsControllerParent

	oView = new QtClassConverterView


func PrepareMainWindow
	oView{
		RBNormal.setChecked(True)
		ClassCodeNameLE.setEnabled(False)
		QtEventsOutputTE.SetEnabled(False)
		QtcfOutputTE.SetEnabled(False)
		QtEventsOutputTE.setAcceptRichText(False)
		QtcfOutputTE.setAcceptRichText(False)
		SignalsTE.setAcceptRichText(False)
		EnumsFlagsTE.setAcceptRichText(False)
		FunctionsTE.setAcceptRichText(False)
		PassVMPointerCB.SetEnabled(False)
	}

func RBNormalAction
	oView{
		ClassParaLE.SetEnabled(True)
		SignalsTE.SetEnabled(True)
	}

func RBNoNewAction
	oView{
		ClassParaLE.SetEnabled(False)
		SignalsTE.setText("")
		SignalsTE.SetEnabled(False)
	}

func RBAbstractAction
	oView{
		ClassParaLE.SetEnabled(True)
		SignalsTE.SetEnabled(True)
	}

func SignalsTEChangedAction
	oView{
		if this.TrimAll(SignalsTE.toPlaintext()) = NULL 
			ClassCodeNameLE.SetEnabled(False)
			QtEventsOutputTE.SetEnabled(False)
			PassVMPointerCB.SetEnabled(False)
			PassVMPointerCB.SetChecked(False)
			if this.TrimAll(EnumsFlagsTE.toPlaintext()) = NULL and this.TrimAll(FunctionsTE.toPlaintext()) = NULL
				QtcfOutputTE.SetEnabled(False)
			ok
		else
			ClassCodeNameLE.SetEnabled(True)
			QtEventsOutputTE.SetEnabled(True)
			QtcfOutputTE.SetEnabled(True)
			PassVMPointerCB.SetEnabled(True)
			PassVMPointerCB.SetChecked(True)
		ok
	}

func ClassNameLEChangedAction
	oView{
		if this.TrimAll(ClassNameLE.text()) = NULL
			ClassParaL.setText("")
			ClassCodeNameLE.setText("")
		else
			ClassParaL.setText("Parameters of first :  " + ClassNameLE.text() + "() Function")
			if len(ClassNameLE.text()) > 2
				ClassCodeNameLE.setText("G" + right(ClassNameLE.text(), len(ClassNameLE.text())-1) )
			else
				ClassCodeNameLE.setText("G" + ClassNameLE.text() )
			ok
		ok
	}

func FunctionsTEChangedAction
	oView {
		if this.TrimAll(FunctionsTE.toPlaintext()) = NULL And this.TrimAll(EnumsFlagsTE.toPlaintext()) = NULL 
			QtcfOutputTE.SetEnabled(False)
		else
			QtcfOutputTE.SetEnabled(True)
		ok
	}

func ConvertBtnAction
	oView{
		QtcfOutputTE.setText("")
		QtEventsOutputTE.setText("")
		cStr1 = ""
		if this.TrimAll(EnumsFlagsTE.toPlaintext()) != NULL
			cStr1 = EnumsFlagsTE.toPlaintext() + nl
		ok
		if this.TrimAll(FunctionsTE.toPlaintext()) != NULL
			cStr1 = cStr1 + FunctionsTE.toPlaintext()
		ok
		aList1 = str2list(cStr1)
		this.pFunctionsProcess(aList1)
		cStr2 = SignalsTE.toPlainText()
		aList2 = str2List(cStr2)
		this.pSignalsProcess(aList2)
	}

func TrimAll str 
	return substr(substr(substr(str,char(9), ""), nl, ""), " ", "")

func pFunctionsProcess aList
	if TrimAll(oView.FunctionsTE.toPlaintext()) = NULL And TrimAll(oView.EnumsFlagsTE.toPlaintext()) = NULL
		return
	ok

	cClassName = TrimAll(oView.ClassNameLE.text())
	aEnum = []
	aFunctions = []

	for itr = len(aList) to 1 step -1
		curFunc = TrimAll(left(aList[itr], substr(aList[itr], "(")-1))
		if (curFunc = cClassName) Or (substr(aList[itr], "~" + cClassName)) Or (substr(aList[itr], "operator"))
			del(aList, itr)
		ok
	next

	cOutput = "#include <" + cClassName + ">" 
	if oView.ClassCodeNameLE.IsEnabled()
		cOutput = cOutput + nl + '#include "' + lower(oView.ClassCodeNameLE.text()) + '.h"'
	ok
	cOutput = cOutput + nl + nl + copy("-", 35) + nl

	cOutput = cOutput + nl + "<class>"
	cOutput = cOutput + nl + "name: " + cClassName

	if (oView.RBNormal.ischecked() Or oView.RBAbstract.ischecked()) and TrimAll(oView.ClassParaLE.text()) != NULL
		cClassPara = oView.ClassParaLE.text()
		if Len(cClassPara)
			cClassPara = Split(cClassPara, ",")
			for Par in cClassPara
				if substr(Par, "=")
					Par = trim(left(Par, substr(Par, "=") -1))
				ok
				for y = len(Par) to 1 step -1
					if Par[y] = " " or Par[y] = "&" or Par[y] = "*"
						Par = trim(left(Par, y))
						exit
					ok
				next
				Par = trim(Par)
				if right(Par, 1) = "&"
					Par = trim(left(Par, len(Par) -1))
				ok
			next
			cClassPara = substr(list2str(cClassPara), NL, ",")
		ok
		cOutput = cOutput + nl + "para: " + cClassPara
	ok
	
	if TrimAll(oView.ClassParentLE.text()) != NULL
		cOutput = cOutput + nl + "parent: " + oView.ClassParentLE.text()
	ok

	if oView.ClassCodeNameLE.isEnabled() and TrimAll(oView.ClassCodeNameLE.text()) != NULL
		cOutput = cOutput + nl + "codename: " + oView.ClassCodeNameLE.text()
	ok

	if oView.RBNoNew.IsChecked()
		cOutput = cOutput + nl + "nonew"
	ok

	if oView.RBAbstract.IsChecked()
		cOutput = cOutput + nl + "abstract"
	ok

	if oView.PassVMPointerCB.IsChecked()
		cOutput = cOutput + nl + "passvmpointer"
	ok

	cOutput = cOutput + nl + "</class>" + nl + nl

	for cLine in aList
		cLine = trim(cLine)
		cLine = trim(substr(cLine, "virtual", ""))
		cLine = substr(cLine,char(9)," ")
		cLine = substr(cLine,") const",")")
		cLine = substr(cLine,"()","(void)")
		cLine = substr(cLine,"&"," ")
		cLine = substr(cLine,"const ","")
		nPos = substr(cLine,"=")
		while nPos > 0
			cSub = substr(cLine,nPos+1)
			nPos2 = substr(cSub,",")
			if nPos2 = 0
				nPos2 = substr(cSub,")")
				if nPos2 = 0
					cLine = left(cLine, nPos -1)
				ok
			ok
			cLine = trim(left(cLine,nPos-1)) + substr(cLine,nPos+nPos2)
			nPos = substr(cLine,"=")
		end
		cLine = substr(cLine,"))",")")
		while True
			if substr(cLine, "  ")
				cLine = substr(cLine, "  ", " ")
			else
				exit
			ok
		end
		if  left(cLine,4) = "enum"  
			if not substr(cLine,"{")
				loop		# ignore invalid Enums
			ok
			cItem = trim(substr(cLine,5,substr(cLine,"{")-5))
			cItem = cClassName + "::" + cItem
			aEnum + cItem
		but  left(cLine,5) = "flags" 
			cItem = trim(substr(cLine,6))
			cItem = cClassName + "::" + cItem
			aEnum + cItem
		else
			cItem = trim(cLine)
			aFunctions + cItem
		ok
	next

	if len(aEnum)
		cOutput = cOutput + nl + "<runcode>"
		for cEnum in aEnum
			cOutput = cOutput + nl + ' aEnumTypes + "' + cEnum + '"' 
		next
		cOutput = cOutput + nl + "</runcode>"
	ok

	for i = 1 to Len(aFunctions)
		s1Func = left(aFunctions[i], substr(aFunctions[i], "(")-1) 
		if s1Func = NULL 
			del(aFunctions, i)
			loop
		ok
		Counter = 2
		for j = 1 to len(aFunctions)
			if i = j	 loop 	ok
			s2Func = left(aFunctions[j], substr(aFunctions[j], "(")-1)
			if s1Func = s2Func
				aFunctions[j] = s2Func + "@" + Counter + right(aFunctions[j], len(aFunctions[j]) - len(s2Func))
				Counter++
			ok
		next
	next

	if len(aEnum)
		for num in aEnum
			for fun in aFunctions
				jnum = right(num, len(num) - (substr(num, "::") + 1))
				if substr(fun, '(' + jnum)
					fun = substr(fun, '(' + jnum, '(' + num)
					# Avoid ClassName::ClassName::EnumName 
					fun = substr(fun, left(num,substr(num, "::") + 1 ) + num , num )
				ok
			next
		next
	ok

	if len(aFunctions)
		for cfunc in aFunctions
			cOutput = cOutput + nl + cfunc
		next 
	ok

	RingKWList = ["again", "and", "but", "bye", "call", "case", "catch", "changeringkeyword", "changeringoperator", "class", "def",
	"do", "done", "else", "elseif", "end", "exit", "for", "from", "func", "get", "give", "if", "import", "in", "load", "loadsyntax",
	"loop", "new", "next", "not", "off", "ok", "on", "or", "other", "package", "private", "put", "return", "see", "step", "switch",
	"to", "try", "while"]
	RingKwSimilar = []
	for i = 1 to Len(aFunctions)
		FuncName = left(aFunctions[i], substr(aFunctions[i], "(")-1)
		for j = 1 to len(RingKWList)
			if FuncName = RingKWList[j]
				RingKwSimilar + FuncName
			ok
		next 

	next
	if Len(RingKwSimilar)
		cOutput = cOutput + nl + nl + "<runcode>" + nl
		for kw in RingKwSimilar
			cOutput = cOutput + 'aNewMethodName + ["' + cClassName + '","' + kw + '","' + kw + 'func"]' + nl
		next
		cOutput = cOutput + "</runcode>" + nl
	ok

	oView.QtcfOutputTE.setText(cOutput)


Func pSignalsProcess aList
	if TrimAll(oView.SignalsTE.toPlaintext()) = NULL
		return
	ok
	/* Output Example :
		aClasses + 
		[	:name = "GTextEdit" ,
			:realname = "QTextEdit" ,
			:events = [
				[ 	:signal = "collapsed(QModelIndex)" ,
					:slot = "collapsedSlot()" ,
					:event = "collapsed"
				] 
			]
		]
	*/

	cSetEvent =  "void set<name>Event(const char *)"
	cSetEvents = ""
	cGetEvent =  "const char *get<name>Event(void)"
	cGetEvents = ""

	cClassName = TrimAll(oView.ClassCodeNameLE.text())
	cClassRealName = TrimAll(oView.ClassNameLE.text())

	for itr = len(aList) to 1 step -1
		if TrimAll(left(aList[itr], substr(aList[itr], "(")-1)) = NULL
			del(aList, itr)
		ok
	next

	cOutput = 'aClasses + [
		:name = "<classcodename>" ,
		:realname = "<realclassname>" ,<classparas>
		:events = ['
	cOutput = substr(cOutput, "<realclassname>", cClassRealName)
	cOutput = substr(cOutput, "<classcodename>", cClassName)
	if oView.RBNormal.ischecked() and TrimAll(oView.ClassParaLE.text()) != NULL
		cClassPara = oView.ClassParaLE.text()
		if Len(cClassPara)
			cClassPara = Split(cClassPara, ",")
			for Par in cClassPara
				if substr(Par, "=")
					Par = trim(left(Par, substr(Par, "=") -1))
				ok
				for y = len(Par) to 1 step -1
					if Par[y] = " " or Par[y] = "&" or Par[y] = "*"
						Par = trim(left(Par, y))
						exit
					ok
				next
				Par = trim(Par)
				if right(Par, 1) = "&"
					Par = trim(left(Par, len(Par) -1))
				ok
			next
			cClassPara = substr(list2str(cClassPara), NL, ",")
		ok
		cOutput = substr(cOutput, "<classparas>", NL + char(9) + char(9) + char(9) + ':initpara = "' + cClassPara + '",')
	else
		cOutput = substr(cOutput, "<classparas>", "")
	ok
	oView.QtEventsOutputTE.setText(cOutput)
	
	for x=1 to len(aList)
		cLine = aList[x]
		cLine = trim(cLine)
		cLine = substr(cLine,char(9),"")
		cLine = substr(cLine,substr(cLine," ")+1)
		nPos = substr(cLine,"(")
		cName = trim(left(cLine,nPos-1))
		cParas = substr(cLine, nPos+1, (len(cLine)-1) - (nPos))
		if Len(cParas)
			cParas = Split(cParas, ",")
			for Par in cParas
				for y = len(Par) to 1 step -1
					if Par[y] = " " or Par[y] = "&" or Par[y] = "*"
						Par = trim(left(Par, y))
						exit
					ok
				next
				Par = trim(Par)
				if right(Par, 1) = "&"
					Par = trim(left(Par, len(Par) -1))
				ok
			next
			cParas = substr(list2str(cParas), NL, ",")
		ok
		cProtoType = cName + "(" + cParas + ")"
		cOutput = '
				[ 	:signal = "<prototype>" ,
					:slot = "<name>Slot()" ,
					:event = "<name>"
				]'

		if not x=len(aList) cOutput += "," ok
		cOutput = substr(cOutput,"<prototype>",cProtoType)
		cOutput = substr(cOutput,"<name>",cName)
		oView.QtEventsOutputTE.setText(oView.QtEventsOutputTE.toPlainText() + cOutput)
		cSetEvents += substr(cSetEvent,"<name>",cName) + nl
		cGetEvents += substr(cGetEvent,"<name>",cName) + nl
	next
	
	oView{
		QtEventsOutputTE.setText(QtEventsOutputTE.toPlainText() + '
		]
	]')

		QtcfOutputTE.setText(QtcfOutputTE.toPlainText() + nl + nl + cSetEvents + nl + cGetEvents)
	}



