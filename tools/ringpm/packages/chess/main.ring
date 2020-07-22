func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Chess Package"
	? copy("=",C_LINESIZE)
	? "Chess package for the Ring programming language"
	? "See the folder : ring/applications/chess"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/chess")
	system("ring AA-ChessBoard.ring")
	chdir(cDir)