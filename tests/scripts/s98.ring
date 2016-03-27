func main
	see "Enter numbers count : " give nMax
	nMax = num(nMax)
	see nl + " Max. : " + getmax(getnumbers(nMax))

func getnumbers nLimit
	aNum = []
	for t = 1 to nLimit
		add(aNum,0)
	next
	see nl
	for t = 1 to nLimit
		see "Enter number : " give aNum[t]
		aNum[t] = num(aNum[t])
	next
	return aNum
	
func getmax aNumbers
	nRes = 0
	nMax = len(aNumbers)
	for x = 1 to nMax
		if aNumbers[x] > nRes
			nRes = aNumbers[x]
		ok
	next
	return nRes

func num x 	x = 0 + x  return x
		

