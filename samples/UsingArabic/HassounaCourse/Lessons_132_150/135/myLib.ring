
func createFolder(path)
	System(    'mkdir "' + path + '" '    )
end

func deleteFolder(path)
	System(     'rmdir "' + path + '" '     )
end

func getRandom(min, max)
	randNum = Random(  max - min  ) + min
	return randNum
end

func deleteAllFiles(path)
	all = dir(path)
	for x=1 to len(all)
		Remove(path + "/" + all[x][1]  )
	next
end

func deleteAllFolders(path)
	all = dir(path)
	for x=1 to len(all)
		if all[x][2]=1
			deleteAllFiles(path + "/" + all[x][1])
			deleteFolder(path + "/" + all[x][1])
		ok
	next
end

func avg(numbers)
	av = sum(numbers) / len(numbers)
	return av
end

func sum(numbers)
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

func isNumberList(numberList)
	for x=1 to len(numberList)
		if Type( numberList[x] ) != "NUMBER"
			return false
		ok
	next
	return true
end

func isStringList(stringList)
	for x=1 to len(stringList)
		if Type( stringList[x] ) != "STRING"
			return false
		ok
	next
	return true
end


class myNote{

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

class empData{
	func init(id, name, address){
		empID = id
		empName = name
		empAddress = address
	}

	func addTask(taskText){
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

class formTools{
	func init(form){
		myForm = form
	}

	func changeForm(newForm){
		myForm = newForm
	}

	func center(){
		screenW = myDesktop.width()
		screenH = myDesktop.height()
		formW = myForm.width()
		formH = myform.height()
		x = ( screenW - formW ) / 2
		y = ( ( screenH - formH ) / 2 ) - 50
		myform.move( x , y )
	}

	private
	myForm 
	myDesktop = new qDesktopWidget() 
}








