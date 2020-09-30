func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Questions Package"
	? copy("=",C_LINESIZE)
	? "Questions package for the Ring programming language"
	? "See the folder : ring/applications/questions"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/questions")
	system("ring QuestionsGame.ring")
	chdir(cDir)