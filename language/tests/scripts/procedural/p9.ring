for m=1 to 10
	? test(m,m+1)
next
? Copy("*",25)
for m=1 to 10
	? test2(m,m+1)
next


func test n1,n2
	? "n1= " + n1 + " - n2= " +n2
	for n1=1 to 5
	next
	for n2=6 to 10
	next
	return n1+n2

func test2 n1,n2
	? "n1= " + n1 + " - n2= " +n2
	return n1+n2