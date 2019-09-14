func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Maze Package"
	? copy("=",C_LINESIZE)
	? "Maze package for the Ring programming language"
	? "See the folder : ring/applications/maze"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/maze")
	system("ring maze.ring")
	chdir(cDir)