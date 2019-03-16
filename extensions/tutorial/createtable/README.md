Creating Extensions - Tutorial - Create Table
=============================================

In this extension we learn how to create a C function that create a table contains rows and columns

In mylib.c we update the file to add 

	RING_FUNC(ring_createtable)
	{
		List *pList, *pRow;
		int x,y,nRows,nCols;
		// Check Parameters Count
			if (RING_API_PARACOUNT != 2) {
				RING_API_ERROR(RING_API_MISS2PARA);
				return;
			}
		// Check Parameters Type
			if ( ! ( RING_API_ISNUMBER(1) && RING_API_ISNUMBER(2) ) ) {
				RING_API_ERROR(RING_API_BADPARATYPE);
				return;
			}
		// Create the List
			pList = RING_API_NEWLIST;
		// Create the table items
			nRows = (int) RING_API_GETNUMBER(1);
			nCols = (int) RING_API_GETNUMBER(2);
			if ( (nRows < 1) || (nCols < 1) ) {
				RING_API_ERROR("Error: The table rows and columns must be >= 1 \n");
				return;
			}
			for(x = 1 ; x <= nRows ; x++) {
				pRow = ring_list_newlist(pList);
				for(y = 1 ; y <= nCols ; y++) 
					ring_list_adddouble(pRow,0.0);
			}
		// Return Output
			RING_API_RETLIST(pList);
	}


Then we register the new function

	ring_vm_funcregister("createtable",ring_createtable);

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
	? ""

	? "Create List (2,2)"
	aList = newList(2,2)
	? "Update the list using C code - set all cells to 10"
	UpdateTable(aList,10)
	? "aList[1][1] : " + aList[1][1]
	? "aList[1][2] : " + aList[1][2]
	? "aList[2][1] : " + aList[2][1]
	? "aList[2][2] : " + aList[2][2]
	? ""

	? "Create List (3,3) using C code"
	aList = CreateTable(3,3)
	? "aList[1][1] : " + aList[1][1]
	? "aList[1][2] : " + aList[1][2]
	? "aList[1][3] : " + aList[1][3]
	? "aList[2][1] : " + aList[2][1]
	? "aList[2][2] : " + aList[2][2]
	? "aList[2][3] : " + aList[2][3]
	? "aList[3][1] : " + aList[3][1]
	? "aList[3][2] : " + aList[3][2]
	? "aList[3][3] : " + aList[3][3]

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

	Create List (2,2)
	Update the list using C code - set all cells to 10
	aList[1][1] : 10
	aList[1][2] : 10
	aList[2][1] : 10
	aList[2][2] : 10

	Create List (3,3) using C code
	aList[1][1] : 0
	aList[1][2] : 0
	aList[1][3] : 0
	aList[2][1] : 0
	aList[2][2] : 0
	aList[2][3] : 0
	aList[3][1] : 0
	aList[3][2] : 0
	aList[3][3] : 0
