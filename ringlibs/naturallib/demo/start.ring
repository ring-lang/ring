load "naturallib.ring"

New NaturalProgram {
	SetLanguageName(:MyLanguage)
	UseCommand(:Hello)
	UseCommand(:Count)
	RunFile("program.ring")
}
