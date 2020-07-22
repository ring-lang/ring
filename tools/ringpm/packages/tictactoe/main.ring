func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "TicTacToe Package"
	? copy("=",C_LINESIZE)
	? "TicTacToe package for the Ring programming language"
	? "See the folder : ring/applications/tictactoe"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/tictactoe")
	system("ring TicTacToe.ring")
	chdir(cDir)