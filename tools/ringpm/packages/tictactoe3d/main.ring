func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "TicTacToe3D Package"
	? copy("=",C_LINESIZE)
	? "TicTacToe3D package for the Ring programming language"
	? "See the folder : ring/applications/tictactoe3d"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/tictactoe3d")
	system("ring tictactoe3d.ring")
	chdir(cDir)