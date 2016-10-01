Load "qt.rh"
Load "ring_qt.ring"

func setwinicon pWindow,cImage		
	pWindow.setWindowIcon(new qicon(new qpixmap(cImage)))
		
func setbtnimage pBtn,cImage
	pBtn.setIcon(new qicon(new qpixmap(cImage)))

