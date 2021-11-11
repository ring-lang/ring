load "tokenslib.ring"

func main

	oTokens = new RingTokens {
		setFileName("hello.ring")
		Start()
		PrintTokens()
		? Copy("=",50)
		setString("? 1+1")
		PrintTokens()
	}
