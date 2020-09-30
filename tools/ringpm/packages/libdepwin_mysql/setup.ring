load "ziplib.ring"

func main
	? "Extracting File : MySQL.zip"
	cDir = CurrentDir()
	chdir(exefolder()+"../extensions/libdepwin")
	zip_extract_allfiles("MySQL.zip","../libdepwin")
	remove("MySQL.zip")
	chdir(cDir)