load "ziplib.ring"

oZip = zip_openfile("myfile.zip",'r')
for x=1 to zip_filescount(oZip) 
	see zip_getfilenamebyindex(oZip,x) + nl
next
zip_close(oZip)