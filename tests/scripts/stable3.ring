# Try/Catch/Done don't track Exit/Loop

for x = 1 to 1000000
	see "nice" + nl
	try
		for x = 1 to 10
			y = 1 / 0
		next
	catch
	done
next