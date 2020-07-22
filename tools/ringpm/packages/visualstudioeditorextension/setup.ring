load "ziplib.ring"

func main
	? "Extracting File : visualstudio.zip"
	cDir = CurrentDir()
	chdir(exefolder()+"../editor")
	zip_extract_allfiles("visualstudio.zip","../editor")
	remove("visualstudio.zip")
	chdir(cDir)