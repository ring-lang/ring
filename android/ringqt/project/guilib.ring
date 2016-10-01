Load "qt.rh"
Load "ring_qt.ring"
if iswindows()
	LoadLib("ringqt.dll")
but ismacosx()
	LoadLib("libringqt.dylib")
else
	LoadLib("libringqt.so")
ok

func setwinicon pWindow,cImage		
	pWindow.setWindowIcon(new qicon(new qpixmap(cImage)))
		
func setbtnimage pBtn,cImage
	pBtn.setIcon(new qicon(new qpixmap(cImage)))

#Class QWebView from QWebEngineView


