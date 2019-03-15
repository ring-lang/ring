Creating Extensions - Tutorial - Increment List Items
=====================================================

In this extension we learn how to create a C function that increment the list items.

This extension in an update to the (sumlist) extension in : ring/extensions/tutorial/sumlist folder

In mylib.c we update the file to add 

	RING_FUNC(ring_inclist)
	{
		List *pList;
		int x,nSum;
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
		// Increment List Items
			nSum = 0;
			pList = RING_API_GETLIST(1);
			for(x=1 ; x <= ring_list_getsize(pList) ; x++) {
				if ( ring_list_isdouble(pList,x) ) {
					ring_list_setdouble(pList,x,ring_list_getdouble(pList,x)+RING_API_GETNUMBER(2)) ;
				}	
			}
		// Return Output
			RING_API_RETLIST(pList);
	}


Then we register the new function

	ring_vm_funcregister("inclist",ring_inclist);

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