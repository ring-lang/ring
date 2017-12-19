load "ziplib.ring"

oZip = zip_openfile("myfile.zip",'r')
see zip_filescount(oZip)
zip_close(oZip)