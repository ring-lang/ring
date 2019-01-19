load "ziplib.ring"

func main
	? "Extracting File : qml.zip"
	cDir = CurrentDir()
	chdir(exefolder()+"../bin")
	zip_extract_allfiles("qml.zip","../bin")
	remove("qml.zip")
	chdir(cDir)