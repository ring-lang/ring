# Application  : Form Designer - Events Code Generator
# Usage         : Generate Code to Manage Object Events (Properties) in Form Designer
# Author        : Mahmoud Fayed <msfclipper@yahoo.com>

Load "guilib.ring"

New qApp
{

	win1 = new qWidget() {

		setWindowTitle("Form Designer - Events Code Generator")
		layout1 = new qhboxlayout() {
                       lbl1 = new qlabel(win1)  { settext("Input") }
                       lbl2 = new qlabel(win1) { settext("Output") }
                       addwidget(lbl1)
                       addwidget(lbl2)
                }
  
               layout2 = new qhboxlayout() {
                        textedit1 = new qtextedit(win1)
                        textedit2 = new qtextedit(win1)
                        addwidget(textedit1)
                        addwidget(textedit2)
                }

                layout3 = new qvboxlayout() {
                        addlayout(layout1)
                        addlayout(layout2)
                        btn1 = new qpushbutton(win1) {
                                setText("convert")
                                setClickEvent("pConvert()")
                        }
                        addwidget(btn1)
                }

                setlayout(layout3)
                showMaximized()

        }
        exec()
}

func pConvert
        cStr = textedit1.toPlainText()
        aList = str2List(cStr)
        pProcess(aList)
        cStr = list2str(aList)
        textedit2.setText(cStr)

func pProcess aList
	aEvents = aList
	cGeneratedCode = ""
	for cEvent in aEvents
		cEvent = Substr(cEvent,"void set","")
		cEvent = Substr(cEvent,"(const char *)","")
		cCode = `c#{f1} = ""` + nl
		cGeneratedCode += substr(cCode,"#{f1}",cEvent)
	next

	cCode = `
func Set#{f1}Code cValue
	c#{f1} = cValue

func #{f1}Code
	return c#{f1}
		`
	for cEvent in aEvents
		cGeneratedCode += substr(cCode,"#{f1}",cEvent)
	next 

	cCode = "
func AddObjectProperties  oDesigner
	AddObjectCommonProperties(oDesigner)" + nl
	cGeneratedCode += cCode 
	for cEvent in aEvents
		cCode = Char(9) + 'oDesigner.oView.AddProperty("#{f1}",False)' + nl
		cGeneratedCode += substr(cCode,"#{f1}",cEvent)
	next 

	cCode = `
func DisplayProperties oDesigner
	DisplayCommonProperties(oDesigner)
	oPropertiesTable = oDesigner.oView.oPropertiesTable
	oPropertiesTable.Blocksignals(True) 
`
	cGeneratedCode += cCode 
	nIndex = 8
	for cEvent in aEvents
		cCode = char(9) + 'oPropertiesTable.item(#{f1},1).settext(#{f2}code())' + nl
		cCode = substr(cCode,"#{f1}",""+nIndex)
		cCode = substr(cCode,"#{f2}",cEvent)
		nIndex++
		cGeneratedCode += cCode 
	next

	cCode = char(9) + "oPropertiesTable.Blocksignals(False)" + nl
	cGeneratedCode += cCode 

	cCode = `
func UpdateProperties oDesigner,nRow,nCol,cValue
	UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
	if nCol = 1 {
		switch nRow {
#{f1}
		}
	}
`
	cCode3 = ""
	nIndex = 8
	for cEvent in aEvents
		cCode2 = copy(char(9),3) + "case #{f1}
				set#{f2}Code(cValue)" + nl
		cCode2 = substr(cCode2,"#{f1}",""+nIndex)
		cCode2 = substr(cCode2,"#{f2}",cEvent)
		nIndex++
		cCode3 += cCode2
	next 
	cCode = substr(cCode,"#{f1}",cCode3)
	cGeneratedCode += cCode 

	cCode = `
func ObjectDataAsString nTabsCount
	cOutput = ObjectDataAsString2(nTabsCount)
	cTabs = std_copy(char(9),nTabsCount) 
`
	cGeneratedCode += cCode 

	for cEvent in aEvents 
		cCode = char(9) + `cOutput += "," + nl + cTabs + ' :set#{f1} =  "' + #{f1}Code() + '"'` + nl
		cCode = substr(cCode,"#{f1}",cEvent)
		cGeneratedCode += cCode 
	next 
	
	cCode = char(9) +  `return cOutput` + nl

	cGeneratedCode += cCode 

	cCode = `
func GenerateCustomCode
	cOutput = ""
`
	cGeneratedCode += cCode 

	for cEvent in aEvents
		cCode = char(9) + `cOutput += 'set#{f2}("#{f1}")' + nl
	cOutput = substr(cOutput,"#{f1}",#{f2}Code())` + nl
		cCode = substr(cCode,"#{f2}",cEvent)
		cGeneratedCode += cCode 
	next

	cCode = Char(9) + "return cOutput" + nl
	cGeneratedCode += cCode 

	cCode = `
func RestoreProperties oDesigner,Item 
	RestoreCommonProperties(oDesigner,item)
	itemdata = item[:data]
`
	cGeneratedCode += cCode 
	
	for cEvent in aEvents
		cCode = char(9) + "Set#{f1}Code(itemdata[:set#{f1}])" + nl
		cCode = substr(cCode,"#{f1}",cEvent)
		cGeneratedCode += cCode 
	next 

	aList = str2list(cGeneratedCode)
