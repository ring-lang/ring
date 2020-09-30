func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "MoneyBoxes game Package"
	? copy("=",C_LINESIZE)
	? "MoneyBoxes game package for the Ring programming language"
	? "See the folder : ring/applications/moneyboxes"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/moneyboxes")
	system("ring moneyController.ring")
	chdir(cDir)