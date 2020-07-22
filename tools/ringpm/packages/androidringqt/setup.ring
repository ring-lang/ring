load "ziplib.ring"

func main
	? "Extracting File : ringqt.zip"
	cDir = CurrentDir()
	chdir(exefolder()+"../android")
	zip_extract_allfiles("ringqt.zip","../android")
	remove("ringqt.zip")
	chdir(cDir)