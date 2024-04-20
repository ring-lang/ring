if isWindows()
	LoadLib("ring_pdfgen.dll")
but ismacosx()
	LoadLib("libring_pdfgen.dylib")
else
	LoadLib("libring_pdfgen.so")
ok

load "ring_pdfgen.rh"
