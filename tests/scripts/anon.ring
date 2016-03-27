
do10( func x { see "hello world" + nl + x + nl} ) 


Func do10 myfunc
	for x = 1 to 10
		call myfunc("Number : " + x)
	next