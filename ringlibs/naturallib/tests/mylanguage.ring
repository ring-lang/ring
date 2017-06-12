load "stdlib.ring"
load "naturallib.ring"

MyLanguage = New NaturalLanguage {
	SetLanguageName(:MyLanguage)
	setCommandsPath(CurrentDir()+"/../command")
	SetPackageName("MyLanguage.Natural")
	UseCommand(:Hello)
	UseCommand(:Count)
	UseCommand(:Print)
	UseCommand(:IWantWindow)
	UseCommand(:WindowTitleIs)
	UseCommand(:IWantButton)
}

 
