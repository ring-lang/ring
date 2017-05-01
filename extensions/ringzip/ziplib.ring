if iswindows()
	LoadLib("ring_libzip.dll")
but ismacosx()
	LoadLib("ring_libzip.dylib")
else
	LoadLib("ring_libzip.so")
ok

Load "ring_libzip.rh"

func zip_addfile oZip,cFile
	zip_entry_open(oZip,cFile)
	zip_entry_fwrite(oZip,cFile)
	zip_entry_close(oZip)