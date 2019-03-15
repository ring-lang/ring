Creating Extensions - Tutorial - Sum List of Numbers
====================================================

In this extension we learn how to create a C function that sum list of numbers.

This extension in an update to the (sayhello) extension in : ring/extensions/tutorial/sayhello folder

In mylib.c we update the file to add 

	RING_FUNC(ring_sumlist)
	{
		List *pList;
		int x,nSum;
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
		// Sum List Numbers 
			nSum = 0;
			pList = RING_API_GETLIST(1);
			for(x=1 ; x <= ring_list_getsize(pList) ; x++) {
				if ( ring_list_isnumber(pList,x) ) {
					nSum += (int) ring_list_getdouble(pList,x) ;
				}
			}
		// Return Output 
			RING_API_RETNUMBER(nSum);
	}


Then we register the new function

	ring_vm_funcregister("sumlist",ring_sumlist);

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
