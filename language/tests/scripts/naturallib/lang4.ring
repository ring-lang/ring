# The Ring Natural Library
# 2025, Mahmoud Fayed <msfclipper@yahoo.com>

load "stdlibcore.ring"
load "naturallib.ring"

load "naturallib/iwantwindow.ring"
load "naturallib/iwantbutton.ring"
load "naturallib/windowtitleis.ring"

mylang = null 

func main 

	nDefIns  = 1000
	nInsUsed = 1000
	
	for m=1 to nDefIns
		DefineNaturalCommand.SyntaxIsCommand([
			:Package = "MyLanguage.Natural",
			:Command = "i want window"+m, 
			:Function = func {
				?  "Command: I want window" 
			}
		])
	next
	
	MyLang = New NaturalLanguage {
		SetLanguageName(:MyLanguage)
		SetPackageName("MyLanguage.Natural")
		loadCommand(:WindowTitleIs)
	 	loadCommand(:IWantWindow)
		loadCommand(:IWantButton)
		for m=1 to nDefIns
		 	loadCommand("iwantwindow"+m)
		next
		setBeforeRun(`ChangeRingKeyword to 	towards`+nl)
		setAfterRun(`ChangeRingKeyword towards	to`+nl)
	}
	
	test()

func test

	MyLang.RunString('
		for t=1 towards 1000
	 		i want window 
			if t=995 
				window title is "Hello, World!"
			but t=1000
				window title is "I Love Programming!"
			ok
		next
	')
