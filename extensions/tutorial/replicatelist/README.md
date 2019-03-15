Creating Extensions - Tutorial - Replicate List Items
=====================================================

In this extension we learn how to create a C function that add more items to the list.

This extension in an update to the (filterlist) extension in : ring/extensions/tutorial/filterlist folder

In mylib.c we update the file to add 

	RING_FUNC(ring_replicatelist)
	{
		List *pList;
		int x,y,nTimes,nSize;
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
		// Replicate List Items
			pList = RING_API_GETLIST(1);
			nSize = ring_list_getsize(pList);
			nTimes = (int) RING_API_GETNUMBER(2);
			if (nTimes < 1) {
				RING_API_ERROR("Error: The second parameter must be >= 1 \n");
				return;
			}
			for(x = 1 ; x <= nTimes ; x++) 
				for(y = 1 ; y <= nSize ; y++) 
					if ( ring_list_isdouble(pList,y) ) 
						ring_list_adddouble(pList,ring_list_getdouble(pList,y));
		// Return Output
			RING_API_RETLIST(pList);
	}

Then we register the new function

	ring_vm_funcregister("replicatelist",ring_replicatelist);

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
