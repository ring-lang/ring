load "stdlibcore.ring"
load "naturallib.ring"

New NaturalLanguage {
	SetLanguageName(:MyLanguage)
	SetCommandsPath("naturallib")
	SetPackageName("MyLanguage.Natural")
	UseCommand(:Hello)
	UseCommand(:Count)
	RunFile("naturallib/program.txt")
}
