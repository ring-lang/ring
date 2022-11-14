func main

	? "Create the list"
	myList = 1:5

	? "Create pointer to the list"
	ptr = object2pointer(myList)

	? "Add item to the list"
	mylist + "Six"

	? "Print the list!"
	? mylist

	? "Add another item using pointer2object()"
	pointer2object(ptr) + "Seven"
		
	? "Print the list using pointer2object()"
	? pointer2object(ptr)

	? "Store a reference to the list"
	ref = pointer2object(ptr)

	? "Print the list"
	? mylist

	? "Add item using the reference"
	ref + "Eight"

	? "Print the list using the reference"
	? ref

	? "Print the list using the original object"
	? mylist

	? :done