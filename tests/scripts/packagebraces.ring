load "stdlib.ring"

import mypackage

new myclass {
	myfunc() 
}

package mypackage 
{
	class myclass 
	{
		func myfunc 
		{
			print("Hello, World\n") ;
		}
	}
}