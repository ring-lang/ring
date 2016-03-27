oCounter3 = new Counter
oCounter = new Counter
oCounter.cChange = " see 'The number is : ' + nIndex + nl "

oCounter.start()

oCounter2 = oCounter
oCounter2.nStart = 11
oCounter2.nEnd = 15
oCounter2.start()

v = i_want_counter()
v.nStart = 20
v.nEnd = 25
v.cChange = oCounter.cChange
v.start()

func i_want_counter
	myobj = new Counter
	return myobj

Class Counter
	nStart = 1
	nEnd = 10
	cChange = ""
	Func Start
		for nIndex = nStart to nEnd
			eval(cChange)
		next

	 