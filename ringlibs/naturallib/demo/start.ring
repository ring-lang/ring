load "stdlib.ring"
load "naturallib.ring"

New NaturalLanguage {
	SetLanguageName(:MyLanguage)
	SetCommandsPath("../command")
	SetPackageName("MyLanguage.Natural")
	UseCommand(:Hello)
	UseCommand(:Count)
	RunFile("program.txt")
}
