func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "TypingQuiz Package"
	? copy("=",C_LINESIZE)
	? "TypingQuiz package for the Ring programming language"
	? "See the folder : ring/applications/typingquiz"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/typingquiz")
	system("ring typingquiz.ring")
	chdir(cDir)