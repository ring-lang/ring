see "Test Switch Statement" + nl
see "======================" + nl
for x = 1 to 5
	switch x
		on 1 see "one" + nl
		on 2 see "two" + nl
		on 3 see "three" + nl
		on 4 see "four" + nl
	off
	if x = 5
		see "end of test " + nl
	ok
next

