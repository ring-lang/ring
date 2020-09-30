load "ziplib.ring"

func main
	? "Extracting File : ringqt.zip"
	cDir = CurrentDir()
	chdir(exefolder()+"../extensions")
	zip_extract_allfiles("ringqt.zip","../extensions")
	remove("ringqt.zip")
	chdir(cDir)