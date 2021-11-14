

func CreateFolder(path)
	System(    'mkdir "' + path + '" '    )
end

func DeleteFolder(path)
	System(     'rmdir "' + path + '" '     )
end

func GetRandom(min, max)
	randNum = Random(  max - min  ) + min
	return randNum
end

func DeleteAllFiles(path)
	all = dir(path)
	for x=1 to len(all)
		Remove(path + "/" + all[x][1]  )
	next
end

func DeleteAllFolders(path)
	all = dir(path)
	for x=1 to len(all)
		if all[x][2]=1
			deleteAllFiles(path + "/" + all[x][1])
			deleteFolder(path + "/" + all[x][1])
		ok
	next
end

func AVG(numbers)
	av = sum(numbers) / len(numbers)
	return av
end

func SUM(numbers)
	if type(numbers)="LIST"
		s = 0
		for x=1 to len(numbers)
			if type(numbers[x])!="NUMBER"
				see "Error: Please Use Number Only" + nl
			else
				s += numbers[x]
			ok
		next
		return s
	else
		see "Please Send LIST Only" + nl
	ok
end

func IsNumberList(numberList)
	for x=1 to len(numberList)
		if Type( numberList[x] ) != "NUMBER"
			return false
		ok
	next
	return true
end

func IsStringList(stringList)
	for x=1 to len(stringList)
		if Type( stringList[x] ) != "STRING"
			return false
		ok
	next
	return true
end

func IsMatch( pattern , text )
	regex = new qRegularExpression()
	regex.setPattern(pattern)
	match = regex.match(text,0,0,0)
	if match.hasMatch() return True
	else return False 
	ok
end

class MyNote{

	func init(myPath){
		path = myPath + ".txt"
	}

	func addLine(line){
		f = fOpen(path , "a")
		fPuts( f , line + nl)
	}

	private
	path
}

class EmpData{
	func init(id, name, address){
		empID = id
		empName = name
		empAddress = address
	}

	func AddTask(taskText){
		mn = new myNote("" + empid + "_" + empname)
		if fExists("" + empid + "_" + empname + ".txt") = 0
			mn.addLine("ID: " + empid)
			mn.addLine("Name: " + empname)
			mn.addLine("Address: " + empaddress)
			mn.addline("=======================")
		ok
		mn.addLine(taskText)
		mn.addLine("--------------------------------")
	}

	private
	empID
	empName
	empAddress
}

class FormTools{

	func init(form){
		Load "stdlibcore.ring"
		Load "guilib.ring"

		import System.GUI

		myForm = form
	}

	func ChangeForm(newForm){
		myForm = newForm
	}

	func Center(){
		screenW = myDesktop.width()
		screenH = myDesktop.height()
		formW = myForm.width()
		formH = myform.height()
		x = ( screenW - formW ) / 2
		y = ( ( screenH - formH ) / 2 ) - 50
		myform.move( x , y )
	}

	func WinNormal(){
		myForm.shownormal()
	}

	func WinMax(){
		myForm.showmaximized()
	}

	func WinMin(){
		myForm.showminimized()
	}

	func WinFull(){
		myForm.showfullscreen()
	}

	func MsgBox(text){
		frm = myForm
		msg = new MessageBox(frm){
			setWindowTitle( frm.WindowTitle() )
			setText(text)
			show()
		}
	}

	func MsgBoxYesNo(text){
		frm = myForm
		msg = new MessageBox(frm){
			setWindowTitle( frm.WindowTitle() )
			setText(text)
			setStandardButtons( QMessageBox_Yes | QMessageBox_No )
			r = exec()
			if r=QMessageBox_Yes return True
			else return False
			ok
		}
	}

	func InputBox(text){
		frm = myForm
		inBox = new InputDialog(frm) {
			setWindowTitle( frm.WindowTitle() )
			setLabelText(text)
			exec()
		}
		return inBox.TextValue()
	}

	func InputBoxNum(text){
		frm = myForm
		inBox = new InputDialog(frm){
			setWindowTitle(frm.WindowTitle())
			setLabelText(text)
			setInputMode(2)
			exec()
		}
		return inBox.TextValue()
	}

	func InputBoxInt(text){
		frm = myForm
		inBox = new InputDialog(frm){
			setWindowTitle(frm.WindowTitle())
			setLabelText(text)
			setInputMode(1)
			exec()
		}
		return inBox.TextValue()
	}

	func InputBoxPass(text){
		frm = myForm
		inBox = new InputDialog(frm){
			setWindowTitle(frm.WindowTitle())
			setLabelText(text)
			setTextEchoMode(2)
			exec()
		}
		return inBox.TextValue()
	}

	func ShowNewForm(){
		frm = new Window() {
			setWindowTitle("New Form")
			show()
		}
		return frm
	}

	func GetNewForm(){
		frm = new Window() {
			setWindowTitle("New Form")
		}
		return frm
	}

	func FillListWidget( yListWidget , yList ){
		for x=1 to len(yList)
			yListWidget.AddItem( yList[x] )
		next
	}

	func OpenFileDialog(filters){
		if IsList(filters)
			newFilter = "Required Files("
			for x=1 to len(filters) newFilter += "*." + filters[x] + ";" next
			newFilter = substr( newFilter , 1 , len(newFilter)-1 )
			newFilter += ")"
			filters = newFilter
		ok
		frm = myForm
		myPath = ""
		new FileDialog(frm){
			myPath = GetOpenFileName( frm , "Open File" , "" , filters  )
		}
		return myPath
	}

	func SaveFileDialog(filters){
		if IsList(filters)
			newFilter = "Required Files("
			for x=1 to len(filters) newFilter += "*." + filters[x] + ";" next
			newFilter = substr( newFilter , 1 , len(newFilter)-1 )
			newFilter += ")"
			filters = newFilter
		ok
		frm = myForm
		myPath = ""
		new FileDialog(frm){
			myPath = GetSaveFileName( frm , "Save File" , "File" , filters  )
		}
		return myPath
	}

	func GetScreenshot(){
		myForm{
			x = x() y = y()
			move( -3500 , -3500 )
			screen = windowHandle().screen()
		}
		pixMap = screen.grabWindow( 0 , 0 , 0 , -1 , -1 )
		myForm.move( x , y )
		return pixMap
	}

	func SaveScreenshot( path ){
		pixMap = GetScreenshot()
		image = pixMap.toImage()
		image.save( path + ".jpg" , "jpg" , 100 )
	}

	func GetWindowShot(){
		frm = myForm
		return frm.grab( new Rect(){ adjust( 0 , 0 , frm.width() , frm.height() ) } )
	}

	func SaveWindowShot( path ){
		pixMap = GetWindowShot()
		image = pixMap.toImage()
		image.save( path + ".jpg" , "jpg" , 100 )
	}

	func qDate_Now(){
		y = number( timelist()[19] )
		m = number( timelist()[10] )
		d = number( timelist()[6] )
		return new qDate(){ setDate( y , m , d ) }
	}
	
	func qTime_Now(){
		h = number( timelist()[7] )
		i = number( timelist()[11] )
		s = number( timelist()[13] )
		return new qTime(){ setHMS( h , i , s , 0) }
	}
	
	func qDateTime_Now(){
		return new qDateTime(){ setDate(this.qDate_Now()) setTime(this.qTime_Now()) }
	}

	func qDate_Val( year , month , day ){
		y = year
		m = month
		d = day
		return new qDate(){ setDate( y , m , d ) }
	}
	
	func qTime_Val( hour , minute , second ){
		h = hour
		i = minute
		s = second
		return new qTime(){ setHMS( h , i , s , 0) }
	}
	
	func qDateTime_Val( year , month , day ,  hour , minute , second ){
		return new qDateTime(){ setDate(this.qDate_Val(year , month , day)) setTime(this.qTime_Val(hour , minute , second)) }
	}

	private
	myForm 
	myDesktop = new qDesktopWidget() 
}

class DataTable{
	Columns=[]
	Rows=[]
	TableName=" "
	ReadOnly=True
	SelectAllRow=True

	func init(){ TableName="MyTable" }

	func SetTableName(Name){ this.TableName=Name }

	func SetReadOnly(state){ this.ReadOnly=state }

	func SetSelectAllRow(state){ this.SelectAllRow=state }

	func AddColumn(ColumnName){ Add( this.Columns , ColumnName ) }

	func AddRow(RowList){ Add( this.Rows , RowList ) }

	func ColumnsCount(){ return len(this.Columns) }

	func RowsCount(){ return len(this.Rows) }

	func LoadInto(TableWidgetTarget){
		if len(this.Columns)<1
			Raise("This table dose not contain any columns")
		ok		
		for x=1 to len(this.Rows)
			if len(this.Rows[x]) != len(this.Columns)
				Raise("One or more row has different values with number of columns")
			ok
		next 
		tbl = TableWidgetTarget
		if this.ReadOnly=True tbl.SetEditTriggers(0) ok
		if this.SelectAllRow=True tbl.SetSelectionBehavior(1) ok
		tbl.SetColumnCount( len(this.Columns) )
		tbl.SetRowCount( len(this.Rows) )
		for x=1 to len(this.Columns)
			colHeader = new qTableWidgetItem( this.Columns[x] )
			tbl.SetHorizontalHeaderItem( x , colHeader )
		next
		for row=1 to len(this.Rows)
			rowNum = string(row) + "     "
			cellRowNum = new qTableWidgetItem(rowNum)
			tbl.SetVerticalHeaderItem( row , cellRowNum )
			for col=1 to len(this.Columns)
				cell = new qTableWidgetItem( "" + this.Rows[row][col] )
				tbl.SetItem( row , col , cell )
			next
		next
	}

	func GetTableWidget(form){
		tbl = new TableWidget(form){ Resize(350,200) Show() }
		this.LoadInto(tbl)
		return tbl
	}

}
