
/*
for x=1 to 10
	if x=6 loop ok
	see x + nl
	//if x=5 exit ok
next
*/



see "Enter Numbers Count: "
give c
all = 0
for x=1 to c
	see "Enter Number " + x + ": "
	give num
	if num=0 loop ok
	all += num
	see "Sum OK" + nl
next

see "============" + nl
see all + nl
see "============" + nl



