load "ziplib.ring"

func main
	? "Extracting File : glew.zip"
	cDir = CurrentDir()
	chdir(exefolder()+"../libdepwin")
	zip_extract_allfiles("glew.zip","../libdepwin")
	remove("glew.zip")
	chdir(cDir)