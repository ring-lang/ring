Creating Extensions - Tutorial - Filter List Items
=====================================================

In this extension we learn how to create a C function that filter the list items.

This extension in an update to the (incrementlist) extension in : ring/extensions/tutorial/incrementlist folder

In mylib.c we update the file to add 

	RING_FUNC(ring_filterlist)
	{
		List *pList;
		int x;
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
		// Filter List Items
			pList = RING_API_GETLIST(1);
			for(x = ring_list_getsize(pList) ; x >= 1 ; x--) 
				if ( ring_list_isdouble(pList,x) ) 
					if ( ! (ring_list_getdouble(pList,x) > RING_API_GETNUMBER(2)) )
						ring_list_deleteitem(pList,x) ;
		// Return Output
			RING_API_RETLIST(pList);
	}


Then we register the new function

	ring_vm_funcregister("filterlist",ring_filterlist);

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

