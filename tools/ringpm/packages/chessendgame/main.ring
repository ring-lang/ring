func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "ChessEndGame Package"
	? copy("=",C_LINESIZE)
	? "ChessEndGame package for the Ring programming language"
	? "See the folder : ring/applications/chessendgame"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/chessendgame")
	system("ring frmController.ring")
	chdir(cDir)