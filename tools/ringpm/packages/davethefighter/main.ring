func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "DaveTheFighter Package"
	? copy("=",C_LINESIZE)
	? "DaveTheFighter package for the Ring programming language"
	? "See the folder : ring/samples/UsingAI/UsingClaude/games/davethefighter"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../samples/UsingAI/UsingClaude/games/davethefighter")
	system("ring davethefighter.ring")
	chdir(cDir)