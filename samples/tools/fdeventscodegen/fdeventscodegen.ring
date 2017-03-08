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

	aList = str2list(cGeneratedCode)

	cCode = `
	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddProperty("Set Click Event",False)

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# Set the Click Event 
			oPropertiesTable.item(8,1).settext(clickeventcode())
		oPropertiesTable.Blocksignals(False)

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		if nCol = 1 {
			switch nRow {
				case 8 	# Click Event 
					setClickEventCode(cValue)
			}
		}

	func ObjectDataAsString nTabsCount
		cOutput = ObjectDataAsString2(nTabsCount)
		cTabs = std_copy(char(9),nTabsCount) 
		cOutput += "," + nl + cTabs + ' :setClickEvent =  "' + ClickEventCode() + '"'
		return cOutput

	func GenerateCustomCode
		cOutput = 'setText("#{f1}")' + nl 
		cOutput += 'setClickEvent("#{f2}")' + nl
		cOutput = substr(cOutput,"#{f1}",text())
		cOutput = substr(cOutput,"#{f2}",ClickEventCode())
		return cOutput

	func RestoreProperties oDesigner,Item 
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		SetClickEventCode(itemdata[:setClickEvent])

`
