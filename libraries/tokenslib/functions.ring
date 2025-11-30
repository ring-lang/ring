/*
**	TokensLib Library
**	Author : Mahmoud Fayed <msfclipper@yahoo.com>
*/

func checkRingCode aPara

	oTokens = new RingTokens {
		fromString(aPara[:Code])
		aCodeTokens = getTokens()
	}

	lPass = True 

	aOperators = aPara[:operators]
	if ! aOperators {
		aOperators = "?(){}."
	}

	for aToken in aCodeTokens {
		switch aToken[C_TOKENTYPE] {
		case C_KEYWORD 
			if ! aPara[:keywords] {
				lPass=False
				exit
			}
		case C_OPERATOR 
			if substr(aOperators,aToken[C_TOKENVALUE]) {
				lPass=False
				exit
			}
		}
	}

	return lPass
