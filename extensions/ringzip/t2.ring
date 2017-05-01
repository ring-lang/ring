load "ziplib.ring"

oZip = zip_openfile("myfile.zip",'w')
zip_addfile(oZip,"test.c")
zip_addfile(oZip,"zip.c")
zip_addfile(oZip,"zip.h")
zip_addfile(oZip,"miniz.h")
zip_close(oZip)