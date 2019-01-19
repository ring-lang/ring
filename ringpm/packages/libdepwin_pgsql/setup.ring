load "ziplib.ring"

func main
	? "Extracting File : pgsql.zip"
	cDir = CurrentDir()
	chdir(exefolder()+"../libdepwin")
	zip_extract_allfiles("pgsql.zip","../libdepwin")
	remove("pgsql.zip")
	chdir(cDir)