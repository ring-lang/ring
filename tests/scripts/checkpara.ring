sum(3,4)
sum(3,NULL)

#sum(NULL,3,4)  # error calling function with extra number of paramters
#sum(3)			# error calling function with less number of paramters

SEE "NULL = " + NULL + nl
see "nice : " + good + nl

func sum x,y

	if not x = NULL
		see "x = " + x + nl 
	ok
	if not y = NULL
		see "y = " + y + nl 
	ok