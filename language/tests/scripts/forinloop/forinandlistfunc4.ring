# Author: Ilir Liburn

func main

	mylist = list(300)

	myList[1] = "Hello"
	swap(myList,1,3)

	for l in myList
		test(myList)
		? "<< "+l
	next

	? mylist
	? :done

func test myList

	for i in myList
		myList = NULL
		i = 1
		? ">> "+i
	next


 
