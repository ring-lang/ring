load "ziplib.ring"

func main
	? "Extracting File : Apache2.2.zip"
	cDir = CurrentDir()
	chdir(exefolder()+"../libdepwin")
	zip_extract_allfiles("Apache2.2.zip","../libdepwin")
	remove("Apache2.2.zip")
	chdir(cDir)