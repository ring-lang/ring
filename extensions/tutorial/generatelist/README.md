Creating Extensions - Tutorial - Generate List
==============================================

In this extension we learn how to create a C function that create new list and add items to the list.

This extension is an update to the (replicatelist) extension in : ring/extensions/tutorial/replicatelist folder

In mylib.c we update the file to add 

	RING_FUNC(ring_generatelist)
	{
		List *pList;
		int x,nSize;
		// Check Parameters Count
			if (RING_API_PARACOUNT != 1) {
				RING_API_ERROR(RING_API_MISS1PARA);
				return;
			}
		// Check Parameters Type
			if ( ! RING_API_ISNUMBER(1) ) {
				RING_API_ERROR(RING_API_BADPARATYPE);
				return;
			}
		// Create the List
			pList = RING_API_NEWLIST;
		// Generate List Items
			nSize = (int) RING_API_GETNUMBER(1);
			if (nSize < 1) {
				RING_API_ERROR("Error: The list size must be >= 1 \n");
				return;
			}
			for(x = 1 ; x <= nSize ; x++) 
				ring_list_adddouble(pList,(double) x);
		// Return Output
			RING_API_RETLIST(pList);
	}


Then we register the new function

	ring_vm_funcregister("generatelist",ring_generatelist);

The file test.ring contains

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
