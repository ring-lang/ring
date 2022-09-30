load "ziplib.ring"

func main
	? "Extracting File : randomuser.zip"
	cDir = CurrentDir()
	chdir(exefolder()+"../applications")
	zip_extract_allfiles("randomuser.zip","../applications")
	remove("randomuser.zip")
	chdir(cDir)