# Exit/Loop don't track Try/Catch/Done

for x = 1 to 1000000
	see "nice" + nl
	for x = 1 to 10
		try
			exit	
		catch
		done
	next
next