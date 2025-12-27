# The Ring Natural Library
# 2025, Mahmoud Fayed <msfclipper@yahoo.com>

load "stdlibcore.ring"
load "naturallib.ring"

load "../command/iwantwindow.ring"
load "../command/iwantbutton.ring"
load "../command/windowtitleis.ring"

nDefIns  = 1000
nInsUsed = 1000

DefineNaturalCommand.startCache(:MyDSL)
for m=1 to nDefIns
	DefineNaturalCommand.SyntaxIsCommand([
		:Package = "MyLanguage.Natural",
		:Command = "i want window"+m, 
		:Function = func {
			?  "Command: I want window" 
		}
	])
next
DefineNaturalCommand.endCache()

MyLang = New NaturalLanguage {

	SetLanguageName(:MyLanguage)
	SetPackageName("MyLanguage.Natural")
	loadCommand(:WindowTitleIs)
 	loadCommand(:IWantWindow)
	loadCommand(:IWantButton)
	
 	loadCommand(:MyDSL)
	
}

myo = new MyLanguage {
	for t=1 to nInsUsed
	 	 i want window	
	next
}
