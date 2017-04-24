
	see "if statement.." + nl
	x = 1
	if x = 1 {
		see "one" + nl
	elseif x=2 
		see "two" + nl
	elseif x=3 
		see "three" + nl
	}
	see "for loop.." + nl
	for t = 1 to 10 {
		see t 
	}
	see nl
	see "switch..." + nl
	x = 1

	switch x {
		on 1 see "one" + nl
		on 2 see "two" + nl
	}

	see "try catch..." + nl
	try {
		x = 1 / 0
	catch
		see "catching error" + nl
	}