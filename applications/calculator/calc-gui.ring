/*
 +---------------------------------------------------------------------------------------------------------
 +     Program Name : Calculator
 +     Date                : 2016-2017
 +     Author             : Magdy Ragab
 +                            : Gal Zsolt (~ CalmoSoft ~)
 +---------------------------------------------------------------------------------------------------------
*/

# Load Ring Libraries
	load "guilib.ring"
	load "odbclib.ring"
	load "sqlitelib.ring"

# Load Applications Functions
	load "functions.ring"

_style="border:1px solid #c0c0c0;background: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #eef, stop: 1 #ccf);font-size: 15pt"
num1=0
num2=0
m="+"
win2 = null
btn1=null

MyApp = New qApp {

        win1 = new qWidget() 
		{
				setwinicon(self,"images/calc.png")
                setwindowtitle("Ring Calculator")
                setwindowmodality(false)
                setFixedSize(290,280)
                setwindowflags( qt_dialog & ~ qt_WindowMaximizeButtonHint)
                //setGeometry(10,10,237,280)
                
                
                edit1 = new qlineedit(win1) {
					setGeometry(10,10,270,32)
					setalignment(Qt_AlignHCenter)
					setreturnpressedevent("checkEnter()")
                                                                   settextchangedevent("changedText()")
					//setDisabled(true)
					//QValidator("Acceptable")
					//clicked("ccc()")
					//connect("")
					setStyleSheet("background-color: lightyellow;color:darkyellow;font-size: 15pt;")
                }
                
               push =  new qpushbutton(win1) {
                        setGeometry(230,105,50,50)
                        settext("Memo")
                        setclickevent("memo()")
                        //setStyleSheet(_style)
						installeventfilter(ignorekey(push))
                }
                
              push2 =  new qpushbutton(win1) {
                        setGeometry(230,50,50,50)
                        settext("C")
                        setclickevent("clearCalc()")
                        setStyleSheet("font-weight:bold;font-size:28pt;color:red;border:1px solid #c0c0c0;background: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #fff, stop: 1 #fcc);")
						installeventfilter(ignorekey(push2))
                }
                
                btn1=new qpushbutton(win1) {
                        setGeometry(10,50,50,50)
                        settext("1")
                        setclickevent("typeNumbers(1)")
                        setStyleSheet(_style)
						installeventfilter(ignorekey(btn1))
                }
                
                
                btn2=new qpushbutton(win1) {
                        setGeometry(65,50,50,50)
                        settext("2")
                        setclickevent("typeNumbers(2)")
                        setStyleSheet(_style)
						installeventfilter(ignorekey(btn2))
                }
                
                
                btn3=new qpushbutton(win1) {
                        setGeometry(120,50,50,50)
                        settext("3")
                        setclickevent("typeNumbers(3)")
                        setStyleSheet(_style)
						installeventfilter(ignorekey(btn3))
                }
                
                
                btn4=new qpushbutton(win1) {
                        setGeometry(10,105,50,50)
                        settext("4")
                        setclickevent("typeNumbers(4)")
                        setStyleSheet(_style)
						installeventfilter(ignorekey(btn4))
                }
                
                btn5=new qpushbutton(win1) {
                        setGeometry(65,105,50,50)
                        settext("5")
                        setclickevent("typeNumbers(5)")
                        setStyleSheet(_style)
						installeventfilter(ignorekey(btn5))
                }
                
                btn6=new qpushbutton(win1) {
                        setGeometry(120,105,50,50)
                        settext("6")
                        setclickevent("typeNumbers(6)")
                        setStyleSheet(_style)	
						installeventfilter(ignorekey(btn6))
                }
                
                btn7=new qpushbutton(win1) {
                        setGeometry(10,160,50,50)
                        settext("7")
                        setclickevent("typeNumbers(7)")
                        setStyleSheet(_style)
						installeventfilter(ignorekey(btn7))
                }
                
                btn8=new qpushbutton(win1) {
                        setGeometry(65,160,50,50)
                        settext("8")
                        setclickevent("typeNumbers(8)")
                        setStyleSheet(_style)
						installeventfilter(ignorekey(btn8))
                }
                
                btn9=new qpushbutton(win1) {
                        setGeometry(120,160,50,50)
                        settext("9")
                        setclickevent("typeNumbers(9)")
                        setStyleSheet(_style)
						installeventfilter(ignorekey(btn9))
                }
                
                
                btn0=new qpushbutton(win1) {
                        setGeometry(10,215,50,50)
                        settext("0")
                        setclickevent("typeNumbers(0)")
                        setStyleSheet(_style)
						installeventfilter(ignorekey(btn0))
                }
                
                
                push3 = new qpushbutton(win1) {
                        setGeometry(65,215,50,50)
                        settext(".")
                        setclickevent("addPeriod()")
                        setStyleSheet(_style)
						installeventfilter(ignorekey(push3))
                }
                
                push4 = new qpushbutton(win1) {
                        setGeometry(120,215,50,50)
                        settext("%")
                        setclickevent("calcPercent()")
                        setStyleSheet(_style)
						installeventfilter(ignorekey(push4))
                }
                
                push5 = new qpushbutton(win1) {
                        setGeometry(175,50,50,50)
                        settext("+")
                        setclickevent("math('+')")
                        setStyleSheet(_style)
						installeventfilter(ignorekey(push5))
                }

                push6 = new qpushbutton(win1) {
                        setGeometry(175,105,50,50)
                        settext("-")
                        setclickevent("math('-')")
                        setStyleSheet(_style)
						installeventfilter(ignorekey(push6))
                }

                push7 = new qpushbutton(win1) {
                        setGeometry(175,160,50,50)
                        settext("*")
                        setclickevent("math('*')")
                        setStyleSheet(_style)
						installeventfilter(ignorekey(push7))
				}

               push9 =  new qpushbutton(win1) {
                        setGeometry(175,215,50,50)
                        settext("/")
                        setclickevent("math('/')")
                        setStyleSheet(_style)
						installeventfilter(ignorekey(push9))
                }

               push10 =  new qpushbutton(win1) {
                        setGeometry(230,160,50,25)
                        settext("(")
                        setclickevent("math('(')")
                        setStyleSheet(_style)
						installeventfilter(ignorekey(push10)) 
				}

                push11 = new qpushbutton(win1) {
                        setGeometry(230,185,50,25)
                        settext(")")
                        setclickevent("math(')')")
                        setStyleSheet(_style)
						installeventfilter(ignorekey(push11))
                }

                push8 = new qpushbutton(win1) {
                        setGeometry(230,215,50,50)
                        settext("=")
                        setclickevent("checkEnter()")
                        setStyleSheet("border:1px solid #c0c0c0;background: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #fff, stop: 1 #cfc);font-size: 15pt")
						installeventfilter(ignorekey(push8))
                }
                show()
        }		
        exec()
}

func ccc
	see "x"

func memo
        win2 = new qWidget() {
                setwindowtitle("History Of Ring Calcuator")
                setwindowmodality(false)
                setparent(win1)
                setwinicon(self,"images/calc.png")
                setFixedSize(550,500)
                setwindowflags( qt_dialog & ~ qt_WindowMaximizeButtonHint)


				Table1 = new qTableWidget(win2) {
						setGeometry(10,10,530,450)
                                                                                setrowcount(0) setcolumncount(3)
						setHorizontalHeaderItem(0, new QTableWidgetItem("Function"))
						setHorizontalHeaderItem(1, new QTableWidgetItem("Result") )
						setHorizontalHeaderItem(2, new QTableWidgetItem("Date") )
						setcolumnwidth(2,200)
						setalternatingrowcolors(True)
						
						oDB = sqlite_init()
						n=sqlite_open(oDB,'calc.db')
						aResult = sqlite_execute(oDB,"select * from calc order by dateline desc")						
						x = 0
						for row in aResult
							insertrow(x)
							setitem(x,0,new qtablewidgetitem(row[:math]))
							setitem(x,1,new qtablewidgetitem(row[:result]))
							setitem(x,2,new qtablewidgetitem(row[:dateline]))
							x++
						next 
						sqlite_close(oDB)                }
		
				new qPushButton(win2) {
					setText("Delete History")
					move(340,465)
					resize(100,30)
					setClickevent("deletehistory()")
				}

				new qPushButton(win2) {
					setText("Close")
					move(440,465)
					resize(100,30)
					setClickevent("win2.close()")
				}
			show()
		}

func ignoreKey(obj)
        myfilter = new qallevents(obj)
        if myfilter.getkeycode() = 20 // Qt_Key_Space
           myfilter.setKeyPressEvent("donothing()")
        ok
        return myfilter

 func donothing()
         return null

func changedText
        enum = edit1.text()
        enum = substr(enum, " ", "")
        check = checkEdit()
        if check = 0
           new qmessagebox(win1) {
           setwindowtitle("Bad input") 
           settext("Bad input!")
           show()
           }
           edit1.settext(left(enum, len(enum) - 1))
        ok
