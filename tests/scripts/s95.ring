func main

	while true
		see clock()
		see nl
		if clock() > 1000
			exit
		ok
	end

	see "welcome" + nl
	see get("PATH") + nl
	c1 = clock()
	for x = 1 to 1000000 next
	c2 = clock()
	see x see nl
	see "clock before : " + c1 + nl	
	see "clock after : " + c2 + nl
	see "total : " + (c2 - c1) + nl