==========================================
Creating Extensions - Tutorial - Say Hello
==========================================

In this extension we learn how to create a C function that get a name as string then say hello.

This extension in an update to the (sumtwonumbers) extension in : ring/extensions/tutorial/sumtwonumbers folder

In mylib.c we update the file to add 

	RING_FUNC(ring_sayhello)
	{
		// Check Parameters Count
			if (RING_API_PARACOUNT != 1) {
				RING_API_ERROR(RING_API_MISS1PARA);
				return;
			}
		// Check Parameters Type
			if ( ! RING_API_ISSTRING(1) ) {
				RING_API_ERROR(RING_API_BADPARATYPE);
				return;
			}
		printf("Hello %s\n",RING_API_GETSTRING(1));
	}

Then we register the new function

	ring_vm_funcregister("sayhello",ring_sayhello);

The file test.ring contains

	? "Loading Library"
	load "mylib.ring"

	? "Calling a C Function"
	myfunction()

	? "Sum Two Numbers (3,5)"
	? SumTwoNumbers(3,5)

	? "Say Hello"
	SayHello("Mahmoud")

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

