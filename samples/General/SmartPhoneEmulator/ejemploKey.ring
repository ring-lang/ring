load "guilib.ring"
load "stdlib.ring"

kb = new Teclado
nkb = new ButtonKey

app = new qapp {
	wtl = new qwidget() {
		setgeometry(500,300,205,330)
		setfixedsize(205, 330)
		setwindowtitle("SmartPhone")
		setstylesheet("border: 2px solid gray; background-color: black; color:white;")
		setwindowflags(Qt_CustomizeWindowHint )

		txt = new qTextedit(wtl) {
			setgeometry(4,296,160,24)
			settext("")
			setstylesheet("border: 1px solid gray; background-color: oldLace; color:darkblue; border-radius:11px")
			settextchangedevent("pAddLine()")
			verticalScrollBar().setDisabled(true)
			horizontalScrollbar().setDisabled(true)
			setverticalScrollBarPolicy(Qt_ScrollBarAlwaysOff)
			sethorizontalScrollbarpolicy(Qt_ScrollBarAlwaysOff)
			SetSelectionChangedEvent("showKBoard()")
		}

		btns = new qpushbutton(wtl) {
			setgeometry(175,296,24,24)
			settext("")
			setstylesheet("background-color: white; color:darkblue;border-radius:12px")
			setbtnimage(self, "images/send2.png")
			setclickevent("pAvanza()")
			hide()
		}

		btoff = new qpushbutton(wtl) {
			setgeometry(85,8,30,30)
			settext("")
			setstylesheet("border: 2px solid red; background-color: white; color:darkblue;border-radius:15px")
			setbtnimage(self, "images/send2.png")
			setclickevent("app.quit()")
			show()
		}
		str = '' 
		str1 = ''
		chk = 0
		Ab1 = [] Aln = [] sPe = []  elist = []
		lab = null dat = ' '
		lit = ''  
		let = ''
		show()
	}
	exec()
}

func showKBoard
	txt.setgeometry(4,180,160,24)
	btns.setgeometry(175,181,24,24)
	btns.show()
	kb {
		keyboard(wtl)
	}

func pSend para
	if (para = ' ')  
		lit = ' '	
  	but (para = 29)  
		lit = '' pBackSpace()
	but (isString(Ab1[para]) = 1)
		lit = Ab1[para]
	else
		lit = Aln[para]
	ok  
	if chk = 1 
		lit = (capitalized(lit))
	but chk = 0 
		lit = lower(lit)
	ok
	str = str + lit 
	//pAddLine()
	txt.settext(capitalized(str))
	return str

func pSendp(algu)
  	if (algu = 27)  
		let = null pBackSpace()
	but (isNumber(Aln[algu]) = 1)
		let = ""+Aln[algu]
	else
		let = Aln[algu]
	ok  
	str = str + let 
	txt.settext(capitalized(str))

func pSends(algu)
  	if (algu = 27)  
		les = null pBackSpace()
	but (isNumber(sPe[algu]) = 1)
		les = ""+sPe[algu]
	else
		les = sPe[algu]
	ok  
	str = str + les 
	txt.settext(capitalized(str))
	
func pShift
	if chk = 0 
		chk = 1 
	else
		chk = 0  
	ok	return chk 

func pEliminarSht
	str = left(str, len(str)-3)
	return str

func pSend3 para
	str = str + para
	txt.settext(str)


func pOpenNum
	kb{panel.Hide()}
	nkb{ButtonKeyNum(wtl) panel2.show()}

func pOpenNump2
	nkb{panel3.Hide()}
	nkb{ButtonKeyNum(wtl) panel2.show()}

func pOpenAlf
	nkb{ButtonKeyNum(wtl) panel2.Hide()}
	kb{keyboard(wtl) panel.show()}

func pOpenSpecial
	nkb{ButtonKeyNum(wtl) panel2.Hide()}
	nkb{ButtonKeySpec(wtl) panel3.show()}

func pBackSpace
	str = left(str, len(str)-1)
	txt.settext(str)

func pOpenEmo 
	kb{panel.Hide()}
	nkb{ButtonKeyNum(wtl) panel2.hide()}
	nkb{ButtonKeySpec(wtl) panel3.hide()}
	nkb{ButtonKeyEmo(wtl) panel4.show()}

func pAddLine
	txt.setgeometry(4,180,160,20)  
	if len(str) > 25
		ah = 48 al = 180-24
		txt.setgeometry(4,al,160,ah)
	else
		ah = 24 al = 180 
		txt.setgeometry(4,al,160,ah)
	ok

func pIntro 
	str = txt.toPlainText()
	txt.setgeometry(4,180,160,20)
	ah = 48 al = 180-24
   	txt.setPlainText(capitalized(str+Char(13)+Char(10)))//+Char(13)+Char(10)
	txt.setgeometry(4,al,160,ah)

def pAvanza 
	see " "+capitalized(str) 
	str = " "
	txt.settext(str)

// funtion to add image to a qTextedit
func pPress moj
	p = '"'+elist[moj]+'"' see p+nl
	txtM = txt.toHtml() + "<img src = 'p', hight=14, width=14>";
     txt.setHtml(txtM);

// Class that handle the panel in which the buttons are located
class Teclado from qwidget { 
	panel lab myEvent btn dat   

	func keyboard win
		posx = 0 posy = 0 wid = 0 
		panel = new qframe(win, 2) {
			move(4,205)
			resize(197,120)
			setstylesheet("border: 1px solid gray; background-color: darkgray; color:white;")
			super.show()
		}
// Add the Buttons to the panel for the letters key
		num = 1:29
		Ab1 = ["Q","W","E","R","T","Y","U","I","O","P",
				"A","S","D","F","G","H","J","K","L","Ñ",
					"Sht","Z","X","C","V","B","N","M","Bs"]
		n=0
			for x in num
				n = n++  bt = btn+n 
				bt = new qpushbutton(panel)
				if (n>=1 and n<=10)
					bt.move(4+19*(n-1),7) 
					bt.setfixedsize(18,22)
				but (n>=11 and n<=20)
					bt.move(4+19*(n-11),36)
					bt.setfixedsize(18,22) 
				but (n = 21)
					loop 
				but (n>=22 and n<=28)
					bt.move(4+10+19*(n-21),65)   
					bt.setfixedsize(18,22)
				but (n = 29)
					bt.move(166,65) 
					bt.setfixedsize(27,22)
				ok
				bt.settext(Ab1[x])
				bt.setstylesheet("background-color: white; color:black; font: bold;")
				bt.setclickevent("pSend"+"("+x+")")
				bt.show()
			next

			new qpushbutton(panel) {
				setgeometry(4,65,27,22)
 				settext("Sht")
				setstylesheet("background-color: white; color:black; font: bold;")
				setclickevent("pShift()")
				show()}

			new qpushbutton(panel) {
				setgeometry(4,94,24,22)
 				settext("123")
				setstylesheet("background-color: white; color:black; font: bold;")
				setclickevent("pOpenNum()")
				show()}
		
			new qpushbutton(panel) {
				setgeometry(30,94,24,22)
 				//settext("Emo")
				setbtnimage(self, "images/Emoji1.png")
				setstylesheet("background-color: white; color:black; font: bold;")
				setclickevent("pOpenEmo()")
				show()}

			new qpushbutton(panel) {
				setgeometry(55,94,86,22)
 				settext("Space")
				setstylesheet("background-color: white; color:black; font: bold;")
				setclickevent("pSend(' ')")
				show()}
		
			new qpushbutton(panel) {
				setgeometry(142,94,51,22)
 				settext("Enter")
				setstylesheet("background-color: white; color:black; font: bold;")
				setclickevent("pIntro()")
				show()} 
}
// Class that handle the panel, panel2, panel3 and panel4 in which the buttons are located
Class ButtonKey from Qwidget {
	panel2 panel3 panel4 lab btc bts let myEvent  

	func ButtonKeyNum win
		panel2 = new qframe(win, 2) {
			move(4,205)
			resize(197,120)
			setstylesheet("border: 1px solid gray; background-color: darkgray; color:white;")
			super.show()
		}
// Add the Buttons to the panel2 for the numbers key
		dNum = 1:27
		aln = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0,
				"-","/",":",";","(",")","€","&","@",'"',
					"#+",".",",","?","!","'","Bs"]
		n=0
			for x in dNum
				n = n++  bb = btc+n 
				bb = new qpushbutton(panel2)
				if (n>=1 and n<=10)
					bb.move(4+19*(n-1),7) 
					bb.setfixedsize(18,22)
				but (n>=11 and n<=20)
					bb.move(4+19*(n-11),36)
					bb.setfixedsize(18,22) 
				but (n = 21)
					loop 
				but (n>=22 and n<=26)
					bb.move(4+3+26*(n-21),65)   
					bb.setfixedsize(25,22)
				but (n = 27)
					bb.move(166,65) 
					bb.setfixedsize(25,22)
				ok
				bb.settext(""+(aln[x])) 
				bb.setstylesheet("background-color: white; color:black; font: bold;")
				bb.setclickevent("pSendp"+"("+x+")")
				bb.show()
			next

			new qpushbutton(panel2) {
				setgeometry(4,65,27,22)
 				settext("#+")
				setstylesheet("background-color: white; color:black; font: bold;")
				setclickevent("pOpenSpecial()")
				show()}

			new qpushbutton(panel2) {
				setgeometry(4,94,24,22)
 				settext("ABC")
				setstylesheet("background-color: white; color:black; font: bold;")
				setclickevent("pOpenAlf()")
				show()}
		
			 new qpushbutton(panel2) {
				setgeometry(30,94,24,22)
				setbtnimage(self, "images/Emoji1.png")
				setstylesheet("background-color: white; color:black; font: bold;")
				setclickevent("pOpenEmo()")
				show()}

			 new qpushbutton(panel2) {
				setgeometry(55,94,86,22)
 				settext("Space")
				setstylesheet("background-color: white; color:black; font: bold;")
				setclickevent("pSend(' ')")
				show()}
		
			 new qpushbutton(panel2) {
				setgeometry(142,94,51,22)
 				settext("Intro")
				setstylesheet("background-color: white; color:black; font: bold;")
				setclickevent("pIntro()")
				show()}
	return
// Add the buttons to the panel3 for the special chars..............................
	func ButtonKeySpec win
		panel3 = new qframe(win, 2) {
			move(4,205)
			resize(197,120)
			setstylesheet("border: 1px solid gray; background-color: darkgray; color:white;")
			super.show()
		}
 
		sNum = 1:27
		sPe = ["[","]","{","}","#","%","^","*","+",'=',
				"_","\","|","~","<",">","$","£","¥","½",
					"123",".",",","?","!","'","Bs"]
		n = 0
			for x in sNum
				n = n++  bp = bts+n 
				bp = new qpushbutton(panel3)
				if (n>=1 and n<=10)
					bp.move(4+19*(n-1),7) 
					bp.setfixedsize(18,22)
				but (n>=11 and n<=20)
					bp.move(4+19*(n-11),36)
					bp.setfixedsize(18,22) 
				but (n = 21)
 					loop
				but (n>=22 and n<=26)
					bp.move(4+3+26*(n-21),65)   
					bp.setfixedsize(25,22)
				but (n = 27)
					bp.move(166,65) 
					bp.setfixedsize(25,22)
				ok
				bp.settext(sPe[x])  
				bp.setstylesheet("background-color: white; color:black; font: bold;")
				bp.setclickevent("pSends"+"("+x+")")
				bp.show() 
			next
 ////
			new qpushbutton(panel3) {
				setgeometry(4,65,27,22)
 				settext("123")
				setstylesheet("background-color: white; color:black; font: bold;")
				setclickevent("pOpenNump2()")
				show()}

			new qpushbutton(panel3) {
				setgeometry(4,94,24,22)
 				settext("ABC")
				setstylesheet("background-color: white; color:black; font: bold;")
				setclickevent("pOpenAlf()")
				show()}
		
			 new qpushbutton(panel3) {
				setgeometry(30,94,24,22)
				setbtnimage(self, "images/Emoji1.png")
				setstylesheet("background-color: white; color:black; font: bold;")
				setclickevent("pOpenEmo()")
				show()}

			 new qpushbutton(panel3) {
				setgeometry(55,94,86,22)
 				settext("Space")
				setstylesheet("background-color: white; color:black; font: bold;")
				setclickevent("pSend(' ')")
				show()}
		
			 new qpushbutton(panel3) {
				setgeometry(142,94,51,22)
 				settext("Intro")
				setstylesheet("background-color: white; color:black; font: bold;")
				setclickevent("pIntro()")
				show()}
	return
// Add the buttons to the panel4 for the Emojis locate
	func ButtonKeyEmo win
		panel4 = new qframe(win, 2) {
			move(4,205)
			resize(197,120)
			setstylesheet("border: 1px solid gray; background-color: darkgray; color:white;")
		}
 		fl = "images/"
		elist = ["images/emo1.png","images/emo2.png","images/emo3.png","images/send.png"]
		n = 0

			for x in elist
				n = n++  la = lab+n 
				la = new Qlabel(panel4)
				if (n>=1 and n<=9)
					la.move(4+21*(n-1),5) 
					la.resize(20,20)
					pix = new Qpixmap(x)
					la.setpixmap(pix.scaled(20,20,0,0))
				but (n>=10 and n<=18)
					la.move(4+21*(n-10),26) 
					la.resize(20,20)
					pix = new Qpixmap(x)
					la.setpixmap(pix.scaled(20,20,0,0))
				but (n>=19 and n<=27)
					la.move(4+21*(n-19),47) 
					la.resize(20,20)
					pix = new Qpixmap(x)
					la.setpixmap(pix.scaled(20,20,0,0))
				but (n>=28 and n<=36)
					la.move(4+21*(n-28),68) 
					la.resize(20,20)
					pix = new Qpixmap(x)
					la.setpixmap(pix.scaled(20,20,0,0))
				ok
				la.setstylesheet("background-color: transparent;")
				myEvent = new QAllevents(la)
				myEvent.setMouseButtonPressEvent("pPress("+n+")")
				la.installeventfilter(myEvent)
				la.show() 
			next

			new qpushbutton(panel4) {
				setgeometry(4,94,24,22)
 				settext("ABC")
				setstylesheet("background-color: darkgray; color:black; font: bold;")
				setclickevent("pOpenAlf()")
				show()}
}

