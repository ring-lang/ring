load "stdlib.ring"
load "naturallib.ring"

New NaturalLanguage {
	SetLanguageName(:MyLanguage)
	setCommandsPath(CurrentDir()+"/../command")
	UseCommand(:Hello)
	UseCommand(:Count)
	RunFile("program.txt")
}
