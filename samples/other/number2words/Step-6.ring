// *** Step-6
// number to words: with graphic UI  (n2w-Gr)
// efective (netto) approximately 30 lines of code for an arbitrary number of words.
// currently limited by tsds ["vigintillion"] (can be traced)
// File: C:\ring\Ring17\RingSamples\src\n2w03c.ring
// Datum: 20.02.2018 
// Author: nestor kuka

import System.GUI
// Load Ring Libraries
    Load "guilib.ring"
    Load "stdlib.ring"

MyApp = New qApp {
        win1 = new qWidget() {
                // window titel 
                setwindowtitle("Convert Digits to Words.")
                setGeometry(200,100,270,420)	// Pos Left/top - Right/bottom
                label1 = new qLabel(win1) {
                        //settext("Eingabe:")
						settext("Input:")
                        setGeometry(10,10,350,30)
                        setalignment(Qt_AlignLeft)
                }
                label1 = new qLabel(win1) {
                        //settext("Ausgabe in Worten:")
						settext("Output in Words:")
                        setGeometry(10,80,350,30)
                        setalignment(Qt_AlignLeft)
                }
		label2 = new textedit(win1) {
			setstylesheet("color:#0055ff;background-color:white;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("Arial")
			setfont(oFont)
			oFont.delete()
			setText("Ausgabe...")
			setGeometry(10,100,250,250)
		}
                btn1 = new qpushbutton(win1) {
                        setGeometry(10,360,110,37)
                        settext("Convert")
                        setclickevent("pConvert()")
                }
                btn1 = new qpushbutton(win1) {
                        setGeometry(150,360,110,37)
                        settext("Close")
                        setclickevent("pClose()")
                }
                lineedit1 = new qlineedit(win1) {
                        setGeometry(10,30,250,30)
                }
                show()
        }
        exec()
}

//----------------------------------------------------------------------------------------
//                                 F u n c t i o n s:
//----------------------------------------------------------------------------------------
Func pConvert
	n = lineedit1.text() 
	if len(n) < 63
		label2.settext(doGruppen(n) )
	else label2.settext("Haben Sie wirklich so viel Geld?") end

//----------------------------------------------------------------------------------------
Func pClose
        MyApp.quit()

//----------------------------------------------------------------------------------------
func doWord(n)
	ones=["one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
	tens=["" , "twenty",  "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"]
	if n="000" see " Zero-Grp "+nl return end
	if n="00" return end
	if number(n)< 20            // 1-19	
		n=n*1                   // convert to num 
		rtn = ones[n]           // ret value 
	elseif n < 100              // 20-99
		n=n*1                   // convert to num 
		x = n % 10              // for ones
		y = floor(n / 10)  	    // for tens
		if x = 0 rtn = tens[y]
		else rtn = tens[y] +" "+ ones[x]  // whole tens
		end 
	elseif len(n) = 3           // first place: hundreds
		z = right(n,2)
	 	h = (floor(n / 100)) *1 // find out the hundreds
		rtn = ones[h] +" hundert "
		rtn = rtn + doWord(z)   // and ..
	ok //if
return rtn                      // take it
//end	doWord()

//----------------------------------------------------------------------------------------
func doGruppen(n)   // groups
	rtn = ""
	anz_gr = floor((len(n)+2)/3)    // number of groups
	tsds = ["","thousand ", "million ", "billion ", "trillion ", "quadrillion ", "quintillion ", "sextillion", "septillion", "octillion", "nonillion", "decillion", "undecillion", "duodecillion", "tredecillion", "quattuordecillion", "sexdecillion", "septendecillion", "octodecillion", "novemdecillion", "vigintillion "]
	for x = 1 to anz_gr-1			// Process input
		gr = right(n,3)			    // investigate group
		n = left( n,len(n)-3 )		// generate new no
		if gr = "" gr = n end		// if gr empty take "n"
	  	rtn = doWord(gr) +" "+ tsds[x] + rtn
	next  //end-for
	rtn = doWord(n) +" "+ tsds[x] + rtn 
return rtn
//end	doGruppen()
//-----------------------------------------------------------------------------  end pgm