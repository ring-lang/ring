func main
	aList = [4,5,7,8,9,10,100]
	aList2 = RandomList(aList)
	? aList2

func RandomList aInput
	aOutput = []
	while len(aInput) > 1
		nIndex = random(len(aInput)-1)
		nIndex++
		aOutput + aInput[nIndex]
		del(aInput,nIndex)
	end
	aOutput + aInput[1]
	return aOutput