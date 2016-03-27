func main
	see "Enter numbers count : " give nMax
	nMax = num(nMax)
	aNumbers =  []
	getnumbers(aNumbers,nMax)
	getmax(aNumbers)

func getmax aNumbers
	nRes = 0
	nMax = len(aNumbers)
	for x = 1 to nMax
		if aNumbers[x] > nRes
			nRes = aNumbers[x]
		ok
	next
	see nl + " Max. : " + nRes

func getnumbers aNum,nLimit
	for t = 1 to nLimit
		add(aNum,0)
	next
	see nl
	for x = 1 to nLimit
		see "Enter number : " give aNum[x]
		aNum[x] = num(aNum[x])
	next

func num x x = 0 + x return x

		

