load "stdlibcore.ring"
load "naturallib.ring"

MyLanguage = New NaturalLanguage {
	SetLanguageName(:MyLanguage)
	SetCommandsPath("naturallib")
	SetPackageName("MyLanguage.Natural")
	UseCommand(:Hello)
	UseCommand(:Count)
	UseCommand(:Print)
	UseCommand(:IWantWindow)
	UseCommand(:WindowTitleIs)
	UseCommand(:IWantButton)
}

 
