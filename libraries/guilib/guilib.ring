# Load the DLL files 
	if iswindows()
		LoadLib("ringqt.dll")
	but ismacosx()
		LoadLib("libringqt.dylib")
	but islinux()
		LoadLib("libringqt.so")
	ok

# Load the files
	load "guilibfiles.ring"