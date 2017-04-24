load "guilib.ring"
load "stdlib.ring"
new qApp {
	win = new qWidget() {
		setWindowTitle("Using QCompleter Class")
		resize(400,400)
		myline = new qLineEdit(win)
		mylist = new qStringList()
		# Add some words one by one
			mylist.append("word1")
			mylist.append("word2")
			mylist.append("word3")
			mylist.append("anotherword1")
			mylist.append("anotherword2")
			mylist.append("anotherword3")
		# Get Ring Functions in a List
			aList = cFunctions()
		# Create a functions to add Ring List to qStringList
			AddItems = func aList,mylist { 
				for Item in aList 
					mylist.Append(Item)
				next
			}
		Call AddItems(aList,MyList)
		aList = split(read("usingqcompleter.ring")," ")
		Call AddItems(aList,MyList)
		mycompleter = new qCompleter3(mylist,win)
		mycompleter.setCaseSensitivity(Qt_CaseInsensitive)
		myline.setCompleter(mycompleter)
		Show()
	}
	exec() 
}
