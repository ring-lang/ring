func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "TextToSpeech Package"
	? copy("=",C_LINESIZE)
	? "TextToSpeech package for the Ring programming language"
	? "See the folder : ring/applications/texttospeech"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/text2speech")
	system("ring text2speechController.ring")
	chdir(cDir)