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

	for aToken in aCodeTokens {
		switch aToken[C_TOKENTYPE] {
		case C_KEYWORD 
			if ! aPara[:keywords] {
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
