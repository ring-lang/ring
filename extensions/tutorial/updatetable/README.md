Creating Extensions - Tutorial - Update Table
=============================================

In this extension we learn how to create a C function that update a table contains rows and columns

In mylib.c we update the file to add 

	RING_FUNC(ring_updatetable)
	{
		List *pList, *pRow;
		int nRow,nCol;
		// Check Parameters Count
			if (RING_API_PARACOUNT != 2) {
				RING_API_ERROR(RING_API_MISS2PARA);
				return;
			}
		// Check Parameters Type
			if ( ! ( RING_API_ISPOINTER(1) && RING_API_ISNUMBER(2) ) ) {
				RING_API_ERROR(RING_API_BADPARATYPE);
				return;
			}
		// Get the List (Represent a Table)
			pList = RING_API_GETLIST(1);
		// Update the Table Rows and Columns
			for (nRow = 1 ; nRow <= ring_list_getsize(pList) ; nRow++ ) {
				if ( ring_list_islist(pList,nRow) ) {
					pRow = ring_list_getlist(pList,nRow);
					for (nCol = 1 ; nCol <= ring_list_getsize(pRow) ; nCol++ ) {
						if ( ring_list_isdouble(pRow,nCol) ) {
							ring_list_setdouble(pRow,nCol,RING_API_GETNUMBER(2));
						} else {
							RING_API_ERROR("Error : We expect numbers!\n");
							return ;
						}
					}
				} else {
					RING_API_ERROR("Error : The parameter is not a table! \n");
					return ;
				}
			}
	}


Then we register the new function

	ring_vm_funcregister("updatetable",ring_updatetable);

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