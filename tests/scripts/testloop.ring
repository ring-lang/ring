
for x = 1 to 10
	if x = 3 loop  ok
	see x + nl
	if x = 9 exit  ok
next
see "test 2 " + nl

for x = 1 to 10
	for y = 1 to 10
		if y = 5 loop  ok
		see " x = " + x + " y = " + y 
		if y = 9 
			loop 2 
		ok

	next
	see nl
	see " after inner loop" 
	see nl
next