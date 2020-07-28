
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

	func InputBox(text){
		frm = myForm
		inBox = new InputDialog(frm) {
			setWindowTitle( frm.WindowTitle() )
			setLabelText(text)
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

	private
	myForm 
	myDesktop = new qDesktopWidget() 
}








