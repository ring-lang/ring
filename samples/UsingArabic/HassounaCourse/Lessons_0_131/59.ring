
myList = Dir("c:\windows")

for item in myList

	if item[2]
		see "Folder: " + item[1] + nl
	else
		see "File    : " + item[1] + nl
	ok

next


//see myList
