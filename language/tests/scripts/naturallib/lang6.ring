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

	for m=1 to nDefIns
	 	loadCommand("iwantwindow"+m)
	next

	loadCommand(:IWantButton)
	setBeforeRun(`ChangeRingKeyword to 	towards`+nl)
	setAfterRun(`ChangeRingKeyword towards	to`+nl)

	addMethod(self,:testEval,func cCode {
		preparelanguage()
		nScopes = ringvm_Scopescount()-1
		ringvm_evalinscope(nScopes,"oLangObj { "+cCode+" }" )
	})
}

test()

func Test

	nYear = 2025
	nice = :great	
 
	MyLang.testEval(`
		? "Testing EvalInScope"
		i want window and the window title is nice
		i want window10
		window title is "Hello, World!"
		? :welcome
		? nYear
		i want window
		window title is 'I Love Programming'
		? :welcome
		? nYear
	`)
 
	? "done.."
	
