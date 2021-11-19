load "jsonlib.ring"

func main

	cJSON = read("sample.json")

	oTokens = new RingTokens {
		fromString(cJson)
		aList = GetTokens()
	}

	aList = JsonTokens2RingTokens(aList)

	oTokens.printTokensList(aList)
	? copy("*",40)

	cCode = RingTokens2Code(aList)

	? cCode
	eval("aTempList = " + cCode)

	? List2Code(aTempList)