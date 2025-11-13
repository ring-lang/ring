# The Ring Natural Library
# 2025, Mahmoud Fayed <msfclipper@yahoo.com>

load "stdlibcore.ring"
load "naturallib.ring"

load "naturallib/iwantwindow.ring"
load "naturallib/iwantbutton.ring"
load "naturallib/windowtitleis.ring"

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
}

myo = new MyLanguage {
	for t=1 to nInsUsed
	 	 i want window	
	next
}
