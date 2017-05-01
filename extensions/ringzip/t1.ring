load "ziplib.ring"

oZip = zip_openfile("myfile.zip",'w')
zip_entry_open(oZip,"test.c")
zip_entry_fwrite(oZip,"test.c")
zip_entry_close(oZip)
zip_close(oZip)