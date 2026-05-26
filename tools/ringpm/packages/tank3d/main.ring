func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Tank3D Package"
	? copy("=",C_LINESIZE)
	? "Tank3D package for the Ring programming language"
	? "See the folder : ring/samples/UsingAI/UsingClaude/games/tank3d"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../samples/UsingAI/UsingClaude/games/tank3d")
	system("ring tank3d.ring")
	chdir(cDir)