load "ziplib.ring"

func main
	? "Extracting File : openssl.zip"
	cDir = CurrentDir()
	chdir(exefolder()+"../libdepwin")
	zip_extract_allfiles("openssl.zip","../libdepwin")
	remove("openssl.zip")
	chdir(cDir)