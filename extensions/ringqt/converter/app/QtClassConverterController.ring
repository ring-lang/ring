# Application  : Qt Class Converter
# Author       : Majdi Sobain <MajdiSobain@gmail.com>
#	       : Mahmoud Fayed <msfclipper@yahoo.com>

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
		QtcfHeaderOutputTE.SetEnabled(False)
		QtcfEnumOutputTE.SetEnabled(False)
		QtcfOutputTE.SetEnabled(False)
		QtEventsOutputTE.setAcceptRichText(False)
		QtcfHeaderOutputTE.setAcceptRichText(False)
		QtcfEnumOutputTE.setAcceptRichText(False)
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
				QtcfHeaderOutputTE.SetEnabled(False)
				QtcfEnumOutputTE.SetEnabled(False)
				QtcfOutputTE.SetEnabled(False)
			ok
		else
			ClassCodeNameLE.SetEnabled(True)
			QtEventsOutputTE.SetEnabled(True)
			QtcfHeaderOutputTE.SetEnabled(True)
			QtcfEnumOutputTE.SetEnabled(True)
			QtcfOutputTE.SetEnabled(True)
			PassVMPointerCB.SetEnabled(True)
			PassVMPointerCB.SetChecked(True)
		ok
	}

func ClassNameLEChangedAction
	oView{
		if this.TrimAll(ClassNameLE.text()) = NULL
			ClassCodeNameLE.setText("")
		else
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
			QtcfHeaderOutputTE.SetEnabled(False)
			QtcfEnumOutputTE.SetEnabled(False)
			QtcfOutputTE.SetEnabled(False)
		else
			QtcfHeaderOutputTE.SetEnabled(True)
			QtcfEnumOutputTE.SetEnabled(True)
			QtcfOutputTE.SetEnabled(True)
		ok
	}

func ConvertBtnAction
	oView{
		# Prepare parameters 
			classNameLE.setText(Trim(classNameLE.text()))
			classParentLE.setText(Trim(classParentLE.text()))
			classParaLE.setText(Trim(classParaLE.text()))
		QtcfHeaderOutputTE.setText("")
		QtcfEnumOutputTE.setText("")
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

func ClearBtnAction
	oView {
		classNameLE.setText("")
		classParentLE.setText("")
		classParaLE.setText("")
		classCodeNameLE.setText("")
		enumsFlagsTE.setText("")
		functionsTE.setText("")
		signalsTE.setText("")
		qtcfHeaderOutputTE.setText("")
		qtcfEnumOutputTE.setText("")
		qtcfOutputTE.setText("")
		qteventsOutputTE.settext("")
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

	# Support using the Module name 
		cModuleName = TrimAll(oView.ModuleNameLE.text())
		if cModuleName != NULL
			cOutput = "#include <" + cModuleName + ">" 
		else 
			cOutput = "#include <" + cClassName + ">" 
		ok

	if oView.ClassCodeNameLE.IsEnabled()
		cOutput = cOutput + nl + '#include "' + lower(oView.ClassCodeNameLE.text()) + '.h"'
	ok
	
	oView.QtcfHeaderOutputTE.setText(cOutput)

	cOutput = "<class>" + nl + "name: " + cClassName

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

	cOutput = cOutput + nl + "</class>" 

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
		cEnumOutput = ""
		for cEnum in aEnum
			cEnumOutput += ' aEnumTypes + "' + cEnum + '"' + nl
		next
		oView.QtcfEnumOutputTE.setText(cEnumOutput)
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

	# Support using the Module name 
		cModuleName = TrimAll(oView.ModuleNameLE.text())
		if cModuleName != NULL
			cClassRealName = cModuleName + "::" + cClassRealName
		ok


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

		# Process class parameters for events 
			cInitParaParent = ""
			cNewClassPara = ""
			nCount = 0
			for cLetter in cClassPara 
				if cLetter = ","
					nCount++
					if nCount = 1
						cNewExpr = "x,"
					else 
						cNewExpr = "x" + nCount + ","
					ok
					cNewClassPara   += cNewExpr
					cInitParaParent += cNewExpr
				else 
					cNewClassPara += cLetter
				ok
			next 
			cClassPara = cNewClassPara

		cOutput = substr(cOutput, "<classparas>", NL + char(9) + char(9)  +
				 ':headerfile = "' + cModuleName + '",' + NL + char(9) + char(9)  +
				 ':initpara = "' + cClassPara + ' ",' + NL + char(9) + char(9) +
				 ':initparaparent = "'+ cInitParaParent  +'",' 
			  )
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

func LoadTestDataBtnAction
	oView {
		moduleNameLE.setText("QtCharts")
		folderNameLE.setText("charts")
		classNameLE.setText("QChart")
		classParentLE.setText("QGraphicsWidget")
		classParaLE.setText("QGraphicsItem *parent = nullptr, Qt::WindowFlags wFlags = Qt::WindowFlags()")
		classCodeNameLE.setText("GChart")
		enumsFlagsTE.setText(SubStr("
			enum 	AnimationOption { NoAnimation, GridAxisAnimations, SeriesAnimations, AllAnimations }
			flags 	AnimationOptions
			enum 	ChartTheme { ChartThemeLight, ChartThemeBlueCerulean, ChartThemeDark, ChartThemeBrownSand, ..., ChartThemeQt }
			enum 	ChartType { ChartTypeUndefined, ChartTypeCartesian, ChartTypePolar }
		",Tab,NULL))
		functionsTE.setText(SubStr("
			void 	addAxis(QAbstractAxis *axis, Qt::Alignment alignment)
			void 	addSeries(QAbstractSeries *series)
			int 	animationDuration() const
			QEasingCurve 	animationEasingCurve() const
			QChart::AnimationOptions 	animationOptions() const
			QList<QAbstractAxis *> 	axes(Qt::Orientations orientation = Qt::Horizontal|Qt::Vertical, QAbstractSeries *series = nullptr) const
			QBrush 	backgroundBrush() const
			QPen 	backgroundPen() const
			qreal 	backgroundRoundness() const
			QChart::ChartType 	chartType() const
			void 	createDefaultAxes()
			bool 	isBackgroundVisible() const
			bool 	isDropShadowEnabled() const
			bool 	isPlotAreaBackgroundVisible() const
			bool 	isZoomed()
			QLegend *	legend() const
			QLocale 	locale() const
			bool 	localizeNumbers() const
			QPointF 	mapToPosition(const QPointF &value, QAbstractSeries *series = nullptr)
			QPointF 	mapToValue(const QPointF &position, QAbstractSeries *series = nullptr)
			QMargins 	margins() const
			QRectF 	plotArea() const
			QBrush 	plotAreaBackgroundBrush() const
			QPen 	plotAreaBackgroundPen() const
			void 	removeAllSeries()
			void 	removeAxis(QAbstractAxis *axis)
			void 	removeSeries(QAbstractSeries *series)
			void 	scroll(qreal dx, qreal dy)
			QList<QAbstractSeries *> 	series() const
			void 	setAnimationDuration(int msecs)
			void 	setAnimationEasingCurve(const QEasingCurve &curve)
			void 	setAnimationOptions(QChart::AnimationOptions options)
			void 	setBackgroundBrush(const QBrush &brush)
			void 	setBackgroundPen(const QPen &pen)
			void 	setBackgroundRoundness(qreal diameter)
			void 	setBackgroundVisible(bool visible = true)
			void 	setDropShadowEnabled(bool enabled = true)
			void 	setLocale(const QLocale &locale)
			void 	setLocalizeNumbers(bool localize)
			void 	setMargins(const QMargins &margins)
			void 	setPlotArea(const QRectF &rect)
			void 	setPlotAreaBackgroundBrush(const QBrush &brush)
			void 	setPlotAreaBackgroundPen(const QPen &pen)
			void 	setPlotAreaBackgroundVisible(bool visible = true)
			void 	setTheme(QChart::ChartTheme theme)
			void 	setTitle(const QString &title)
			void 	setTitleBrush(const QBrush &brush)
			void 	setTitleFont(const QFont &font)
			QChart::ChartTheme 	theme() const
			QString 	title() const
			QBrush 	titleBrush() const
			QFont 	titleFont() const
			void 	zoom(qreal factor)
			void 	zoomIn()
			void 	zoomIn(const QRectF &rect)
			void 	zoomOut()
			void 	zoomReset()
		",Tab,NULL))
		signalsTE.setText(SubStr("
			void 	plotAreaChanged(const QRectF &plotArea)
		",Tab,NULL))
		qtcfHeaderOutputTE.setText("")
		qtcfEnumOutputTE.setText("")
		qtcfOutputTE.setText("")
		qteventsOutputTE.settext("")
	}

func WriteClassFiles

	cFolder = TrimAll(oView.folderNameLE.text())
	if cFolder = NULL 
		msginfo("Sorry","Write the folder name after the module name")
		return 
	ok

	cClassName = TrimAll(oView.classNameLE.text())
	if cClassName = NULL 
		msginfo("Sorry","Write the class name")
		return 
	ok

	cClassFile = exefolder()+
		   "../extensions/ringqt/classes/" + cFolder + "/" + 
		   lower(cClassName) + ".cf"

	cEventsFile = exefolder()+
		   "../extensions/ringqt/events/" + cFolder + "/" + 
		   lower(cClassName) + ".ring"

	write(cClassFile,oView.QtcfOutputTE.toplaintext())

	cEventsFileContent = oView.QteventsOutputTE.toplaintext()
	if trim(cEventsFileContent) != NULL
		write(cEventsFile,oView.QteventsOutputTE.toplaintext())
	ok

	msginfo("Writing Files","Operation done!")


func openEnumFile

	oView.qtcfEnumOutputTE { selectall() copy() }
	RunProcess("notepad.exe",exefolder()+
		   "../extensions/ringqt/classes/qt_enumtypes.cf")


func openHeaderFile

	oView.qtcfHeaderOutputTE { selectall() copy() }
	RunProcess("notepad.exe",exefolder()+
		   "../extensions/ringqt/classes/qt_headerfiles.cf")

func openModuleFile

	cFile = exefolder()+"../extensions/ringqt/classes/qt_module_"+
		oView.folderNameLE.text()+".cf"
	if fexists(cFile)
		RunProcess("notepad.exe",cFile)
	else
		msginfo("Sorry","Can't open the module file : " + cFile + nl +
			"Write the folder name after the module name")
	ok

func openEventsFile

	RunProcess("notepad.exe",exefolder()+
		   "../extensions/ringqt/events/qtevents_files.ring")

func openProFiles

	RunProcess("notepad.exe",exefolder()+
		   "../extensions/webassembly/ringqt/project/project.pro")

	RunProcess("notepad.exe",exefolder()+
		   "../extensions/android/ringqt/project/project.pro")

	RunProcess("notepad.exe",exefolder()+
		   "../extensions/ringqt/ring_qt515.pro")

	RunProcess("notepad.exe",exefolder()+
		   "../extensions/ringqt/ring_qt515_nobluetooth.pro")

	RunProcess("notepad.exe",exefolder()+
		   "../extensions/ringqt/ring_qt515_light.pro")

	RunProcess("notepad.exe",exefolder()+
		   "../extensions/ringqt/ring_qt515_core.pro")


func RunProcess cProgram,cArg
	aPara = split(cArg,",")
	oStringList = new qStringlist() {
		for cPara in aPara 
			append(cPara)
		next
	}
	oProcess = new qprocess(NULL) {
		setprogram( cProgram)
		setarguments(ostringlist)
		start_3(  QIODevice_ReadWrite )
	}
	return oProcess

func closeApplication
	oView.win.close() 

