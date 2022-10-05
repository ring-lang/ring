load "tokenslib.ring"

func main

	oTokens = new RingTokens {
		fromFile("hello.ring")
		PrintTokens()
		? Copy("=",50)
		fromString("? 1+1")
		PrintTokens()
	}
