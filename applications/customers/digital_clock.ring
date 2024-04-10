#==================================#
# Customers Application
# Chokri <printhiver@gmail.com>
#==================================#

import System.GUI

Timer2Clock=null Timer1Clock=null lblSecondeClock=null 
lblMinuteClock=null LCD_SClock=null LCD_MClock=null 
LCD_HClock=null FrameClock=null

func setClinotClock()
	if lblSecondeClock.isVisible()
		lblSecondeClock.hide()
	else lblSecondeClock.show()
	ok

func showTimeClock()
	h = (0+timeList()[7])
	i = (0+timeList()[11])
	s = (0+timeList()[13])

	LCD_HClock.display(h) LCD_MClock.display(i) LCD_SClock.display(s)

class DegitClock{
	
	func init(form)
		this.frm = form

	func setColorClock(CSSColor,bg,border)
		cColor="color:"+CSSColor+";"
		if bg=true cColor += "background-color:#000000;" ok
		if border=false cColor += "border:non;" ok
		FrameClock{
			setStyleSheet(cColor)
		}

	func getLargeClock()
		FrameClock = new frame3(this.frm) {
			resize(172,52)
			move(0,0)
			oFont = new qfont("",0,0,0)
			oFont.fromstring("Arial")
			setfont(oFont)
			oFont.delete()
			setFrameStyle(QFrame_Plain | QFrame_WinPanel)
			show()
		}
		LCD_HClock = new lcdnumber(FrameClock) {
			resize(47,42)
			move(4,5)
			oFont = new qfont("",0,0,0)
			oFont.fromstring("Arial")
			setfont(oFont)
			oFont.delete()
			setDigitCount(2)
			Display(0)
			show()
		}
		lblMinuteClock = new label(FrameClock) {
			resize(9,42)
			move(52,5)
			oFont = new qfont("",0,0,0)
			oFont.fromstring("Arial,14,-1,5,75,0,0,0,0,0,Gras")
			setfont(oFont)
			oFont.delete()
			setText(":")
			setAlignment(Qt_AlignHCenter |  Qt_AlignVCenter)
			show()
		}
		LCD_MClock = new lcdnumber(FrameClock) {
			resize(47,42)
			move(62,5)
			oFont = new qfont("",0,0,0)
			oFont.fromstring("Arial")
			setfont(oFont)
			oFont.delete()
			setDigitCount(2)
			Display(0)
			show()
		}
		LCD_SClock = new lcdnumber(FrameClock) {
			resize(47,42)
			move(120,5)
			oFont = new qfont("",0,0,0)
			oFont.fromstring("Arial")
			setfont(oFont)
			oFont.delete()
			setDigitCount(2)
			Display(0)
			show()
		}
		lblSecondeClock = new label(FrameClock) {
			resize(9,42)
			move(110,5)
			oFont = new qfont("",0,0,0)
			oFont.fromstring("Arial,14,-1,5,75,0,0,0,0,0,Gras")
			setfont(oFont)
			oFont.delete()
			setText(":")
			setAlignment(Qt_AlignHCenter |  Qt_AlignVCenter)
			show()
		}
		Timer1Clock = new qtimer(FrameClock) {
			setInterval(1000)
			setTimeoutevent("showTimeClock()")
			start()
		}
		
		return FrameClock
	
	func getMediumClock()
		fMDClock = this.getLargeClock()
		LCD_HClock{
			resize(width()-7,height()-7)
			move(x(), y()) 
		}
		lblMinuteClock{
			resize(width()-3,height()-7)
			move(x()-7, y())
		}
		LCD_MClock{
			resize(width()-7,height()-7)
			move(x()-10, y())
		}
		lblSecondeClock{
			resize(width()-3,height()-7)
			move(x()-17, y())
		}
		LCD_SClock{
			resize(width()-7,height()-7)
			move(x()-20, y())
		}
 		fMDClock{ resize(width()-27,height()-7) }
		
		return fMDClock
	
	func getSmallClock()
		fSMLClock = this.getLargeClock()
		LCD_HClock{
			resize(width()-14,height()-14)
			move(x(), y()) 
		}
		lblMinuteClock{
			resize(width()-3,height()-14)
			move(x()-14, y())
		}
		LCD_MClock{
			resize(width()-14,height()-14)
			move(x()-17, y())
		}
		lblSecondeClock{
			resize(width()-3,height()-14)
			move(x()-31, y())
		}
		LCD_SClock{
			resize(width()-14,height()-14)
			move(x()-34, y())
		}
 		fSMLClock{ resize(width()-48,height()-14) }
		
		return fSMLClock
	

	private
	frm
	monEcran = new qDesktopWidget()
}
