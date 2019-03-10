================================================
Creating Extensions - Tutorial - Sum Two Numbers
================================================

In this extension we learn how to create a C function to sum two numbers 

This extension in an update to the (Hello World 2) extension in : ring/extensions/tutorial/helloworld2 folder

In mylib.c we update the file to add 

	RING_FUNC(ring_sumtwonumbers)
	{
		double nNum1,nNum2,nSum;
		// Check Parameters Count
			if (RING_API_PARACOUNT != 2) {
				RING_API_ERROR(RING_API_MISS2PARA);
				return;
			}
		// Check Parameters Type
			if ( ! (RING_API_ISNUMBER(1) && RING_API_ISNUMBER(2)) ) {
				RING_API_ERROR(RING_API_BADPARATYPE);
				return;
			}
		// Sum Numbers 
			nNum1 = RING_API_GETNUMBER(1);
			nNum2 = RING_API_GETNUMBER(2);
			nSum  = nNum1 + nNum2 ;
		// Return Output
			RING_API_RETNUMBER(nSum);
	}

Then we register the new function

	ring_vm_funcregister("sumtwonumbers",ring_sumtwonumbers);

The previous code is written to check errors, and to be easy to understand

We can write short code like

			RING_API_RETNUMBER(RING_API_GETNUMBER(1) + RING_API_GETNUMBER(2));

The file test.ring contains

	? "Loading Library"
	load "mylib.ring"

	? "Calling a C Function"
	myfunction()

	? "Sum Two Numbers (3,5)"
	? SumTwoNumbers(3,5)

Then we test the function using

	ring test.ring

Output

	Loading Library
	Calling a C Function
	Hello, World!
	Sum Two Numbers (3,5)
	8

