/*
**	TokensLib Library
**	Author : Mahmoud Fayed <msfclipper@yahoo.com>
*/

func checkRingCode aPara

	try {
		oTokens = new RingTokens {
			fromString(aPara[:Code])
			aCodeTokens = getTokens()
		}
	catch 
		return False
	}

	lPass = True 

	aOperators = aPara[:operators]
	if ! aOperators {
		aOperators = "?(){}."
	}

	aSafeOperators = aPara[:safeoperators]

	aSafeKeywords  = aPara[:safekeywords]
	if ! isList(aSafeKeywords) { aSafeKeywords = [] }

	for aToken in aCodeTokens {
		switch aToken[C_TOKENTYPE] {
		case C_KEYWORD 
			if ! aPara[:keywords] {
				cKeyword = lower(aKeywords[0+aToken[C_TOKENVALUE]])
				if find(aSafeKeywords,cKeyword) { loop }
				lPass=False
				exit
			}
		case C_OPERATOR 
			cOp = aToken[C_TOKENVALUE]
			if substr(aSafeOperators,cOp) { loop }
			if substr(aOperators,cOp) {
				lPass=False
				exit
			}
		}
	}

	return lPass
