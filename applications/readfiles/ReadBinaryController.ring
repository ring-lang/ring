###----------------------------------------------------------
### Read All Binary Files Application
### 2022-07-15  Ahmed Hassouna
### Video : Comming Soon in Hassouna Academy
###----------------------------------------------------------

# Form/Window Controller - Source Code File

load "ReadBinaryView.ring"

import System.GUI

if IsMainSourceFile() {
	oApp =	new App {
		StyleFusionBlack()
		oClipboard = clipboard()
		decimals(3)
		openWindow(:ReadBinaryController)
		exec()
	}
}

class ReadBinaryController from windowsControllerParent

	oView = new ReadBinaryView
	bytes_str1 = "" bytes_str2 = '[ ' bytes_str3 = '[ ' cName = ''
	f = ''  myLen=0   pages=0   pageSize=512

	func Choose_File
		oView.Label1.SetText("0")  oView.Label2.SetText("0")  oView.Label3.SetText("0")
		frm = oView.win
		new fileDialog(frm) { cName = getOpenFileName(frm,"open file",'',"All Files(*.*)") }
		if cName = "" ? 'Error when select file' return ok	
		f = read(cName)   myLen=len(f)
		fSize = getFileSize(cName)
		pages = ceil(fSize/pageSize)
		oView.ListWidgetP.Clear()
		for x=1 to pages  oView.ListWidgetP.addItem("Page " + x)  next
		oView.Label1.SetText("" + fSize + ' Bytes')
		oView.Label2.SetText("" + (fSize/1024) + ' KB')
		oView.Label3.SetText("" + (fSize/1024/1024) + ' MB')
		oView.LabelcName.SetText(cName)
		oView.ListWidgetP.setcurrentrow(1,3)

	func ShowPage pNum
		oView.win.blocksignals(True)
		myStart = ( (pNum-1)*pageSize ) + 1
		bytes_str1 = "" bytes_str2 = '[ ' bytes_str3 = '[ ' cName = ''
		oView.ListWidget1.Clear()
		oView.ListWidget2.Clear()
		bList = []
		cList = []
		length_required = myLen-myStart+1
		fForPage = upper(str2Hex( substr(f, myStart, min(pageSize,length_required) ) ))
		for x=1 to pageSize*2 step 2
			str = substr(fForPage, x, 2)
			add(bList, str)
			add(cList, hex2str(str) )
			bytes_str1 += str + ' '
			bytes_str2 += '"' + str + '"'
			bytes_str3 += '0x' + str
			bytes_str2 += ", "	  bytes_str3 += ", "
		next
		bytes_str2 = left(bytes_str2, len(bytes_str2)-2) + " ]"
		bytes_str3 = left(bytes_str3, len(bytes_str3)-2) + " ]"	
		oView.ListWidget1.addList(bList)
		oView.ListWidget2.addList(cList)
		oView.ListWidget1{setViewMode(1) setSpacing(2) SetFont( new qfont("Consolas",14,-1,0) ) }
		oView.ListWidget2{setViewMode(1) setSpacing(2) SetFont( new qfont("Consolas",14,-1,0) ) }
		oView.win.blocksignals(False)
		oView.ListWidget1.setcurrentrow(1,3)
		oView.ListWidget2.setcurrentrow(1,3)

	func ListWidgetP_ItemChanged
		ShowPage(oView.ListWidgetP.currentRow())

	func ListWidget1_ItemChanged
		oView.ListWidget2.setCurrentRow(oView.ListWidget1.CurrentRow(),3)

	func ListWidget2_ItemChanged
		oView.ListWidget1.setCurrentRow(oView.ListWidget2.CurrentRow(),3)

	func btn_copy1
		oClipboard.setText(bytes_str1,0)
	
	func btn_copy2
		oClipboard.setText(bytes_str2,0)
	
	func btn_copy3
		oClipboard.setText(bytes_str3,0)
	
	func Exit_Click
		oView.win.close()
		oApp.Quit()



