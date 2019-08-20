load "naturallib.ring"

MyLanguage=New NaturalLanguage {
        SetLanguageName(:MyLanguage)
        SetCommandsPath(CurrentDir())
        SetPackageName("MyLanguage.Natural")
        UseCommand("goto")
        UseCommand("theend")
       	UseCommand("execute")
	runfile("test7.ring")
}

