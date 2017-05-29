load "naturallib.ring"

New NaturalLanguage {
	SetLanguageName(:MyLanguage)
	UseCommand(:Hello)
	UseCommand(:Count)
	RunFile("program.txt")
}
