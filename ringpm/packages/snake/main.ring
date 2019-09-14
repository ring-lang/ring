func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Snake Package"
	? copy("=",C_LINESIZE)
	? "Snake package for the Ring programming language"
	? "See the folder : ring/applications/snake"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/snake")
	system("ring snake.ring")
	chdir(cDir)