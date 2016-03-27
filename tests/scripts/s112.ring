func main

	list = 1:10
	see list
	SEE 1:5

	FOR X = 1 TO LEN(1:5)
		SEE " number : " + x
		see nl
	next

	test2()
	test3()

func test2

	list = "a":"z"
	see list

	for x = 1 to len(list) 
		see asci(list[x]) 
		see nl 
	next

func test3

	list1 = "a":"x"
	list2 = "y":"z"

	see "Letters from a to x = " + len(list1) + nl
	see "Letters from y to z = " + len(list2) + nl
	see "Total letters from a to z = " + ( len(list1) + len(list2) ) + nl
