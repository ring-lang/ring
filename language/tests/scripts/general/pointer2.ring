func main

	? "Create the list"
	myList = 1:5

	? "Store a reference to the list"
	ref = reference(myList)

	? "Print the list"
	? mylist

	? "Add item using the reference"
	ref + "Six"

	? "Add item using the original list"
	mylist + "Seven"

	? "Print the list using the reference"
	? ref

	? "Print the list using the original list"
	? mylist

	? :done

func reference mylist
	return pointer2object(object2pointer(myList))
