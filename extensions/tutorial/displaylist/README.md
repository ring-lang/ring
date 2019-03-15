Creating Extensions - Tutorial - Display List
=============================================

In this extension we learn how to create a C function that display all of the list items including nested lists

In mylib.c we update the file to add 

	void mylib_displaylist(List *pList);

	RING_FUNC(ring_displaylist)
	{
		List *pList;
		// Check Parameters Count
			if (RING_API_PARACOUNT != 1) {
				RING_API_ERROR(RING_API_MISS1PARA);
				return;
			}
		// Check Parameters Type
			if ( ! RING_API_ISPOINTER(1) ) {
				RING_API_ERROR(RING_API_BADPARATYPE);
				return;
			}
		// Get the List
			pList = RING_API_GETLIST(1);
		// Display the List Items including Nested Lists
			mylib_displaylist(pList);
		// Return Output
			RING_API_RETLIST(pList);
	}

	void mylib_displaylist(List *pList) {
		int x;
		for (x=1; x <= ring_list_getsize(pList); x++) {
			if ( ring_list_isdouble(pList,x) ) {
				printf("Number : %f \n", ring_list_getdouble(pList,x) ) ;
			} else if ( ring_list_isstring(pList,x) ) {
				printf("String : %s \n", ring_list_getstring(pList,x) ) ;
			} else if ( ring_list_islist(pList,x) ) {
				printf("Sub List..\n");
				mylib_displaylist( ring_list_getlist(pList,x) );		
			}
		}
	}

Then we register the new function

	ring_vm_funcregister("displaylist",ring_displaylist);

The file test.ring contains

	load "stdlib.ring"

	? "Loading Library"
	load "mylib.ring"

	? "Calling a C Function"
	myfunction()

	? "Sum Two Numbers (3,5)"
	? SumTwoNumbers(3,5)

	? "Say Hello"
	SayHello("Mahmoud")

	? "Sum List contains numbers from 1 to 10"
	aList = 1:10
	? SumList(aList)

	? "Increment List Items"
	? inclist(aList,10)

	? "Filter List Items (Items > 15)"
	? filterlist(aList,15)

	aList = 1:3
	? "Replicate list (1:3) three times then print the items (We expect 12 items)"
	? replicatelist(aList,3)

	? "Create list contains 5 items using C code"
	aList = GenerateList(5)
	? aList

	? "Create List (3,2)"
	aList = newList(3,2)
	aList[1][1] = "R 1 C 1"
	aList[1][2] = "R 1 C 2"
	aList[2][1] = "R 2 C 1"
	aList[2][2] = "R 2 C 2"
	aList[3][1] = "R 3 C 1"
	aList[3][2] = "R 3 C 2"
	? "Print the List using Ring"
	? aList
	? "Print the List by calling C Code"
	displayList(aList)

Then we test the function using

	ring test.ring

Output

	Loading Library
	Calling a C Function
	Hello, World!
	Sum Two Numbers (3,5)
	8
	Say Hello
	Hello Mahmoud
	Sum List contains numbers from 1 to 10
	55
	Increment List Items
	11
	12
	13
	14
	15
	16
	17
	18
	19
	20


	Filter List Items (Items > 15)
	16
	17
	18
	19
	20

	Replicate list (1:3) three times then print the items (We expect 12 items)
	1
	2
	3
	1
	2
	3
	1
	2
	3
	1
	2
	3

	Create list contains 5 items using C code
	1
	2
	3
	4
	5

	Create List (3,2)
	Print the List using Ring
	R 1 C 1
	R 1 C 2
	R 2 C 1
	R 2 C 2
	R 3 C 1
	R 3 C 2

	Print the List by calling C Code
	Sub List..
	String : R 1 C 1
	String : R 1 C 2
	Sub List..
	String : R 2 C 1
	String : R 2 C 2
	Sub List..
	String : R 3 C 1
	String : R 3 C 2
