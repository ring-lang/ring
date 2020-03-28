func main
	aList = [4,5,7,8,9,10,100]
	aList2 = RandomList(aList)
	? aList2

func RandomList aInput
    aOutput = []
    while len(aInput) > 0
       nIndex = max(random(len(aInput)) , 1)
       aOutput + aInput[nIndex]
       del(aInput,nIndex)
    end
   return aOutput