# Load the DLL files 
	if iswindows()
		LoadLib("ringqt_light.dll")
	but ismacosx()
		LoadLib("libringqt_light.dylib")
	but islinux()
		LoadLib("libringqt_light.so")
	ok

# Load the files
	load "guilibfiles.ring"