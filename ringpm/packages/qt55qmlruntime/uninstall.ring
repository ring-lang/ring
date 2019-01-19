load "stdlib.ring"

func main
	? "Removing Files : Qt 5.5 QML runtime"
	cDir = CurrentDir()
	chdir(exefolder()+"../bin")
	OSDeleteFolder("qml")
	chdir(cDir)