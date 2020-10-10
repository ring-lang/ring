load "ziplib.ring"

func main
	? "Extracting File : ringqt.zip"
	cDir = CurrentDir()
	chdir(exefolder()+"../extensions/webassembly")
	zip_extract_allfiles("ringqt.zip","../webassembly")
	remove("ringqt.zip")
	chdir(cDir)