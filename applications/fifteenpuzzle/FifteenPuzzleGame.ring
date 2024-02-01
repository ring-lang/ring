# Project : CalmoSoft Fifteen Puzzle Game 
# Date    : 2018/12/01
# Author  : Gal Zsolt (CalmoSoft), Bert Mariani
# Email   : calmosoft@gmail.com

load "lightguilib.ring"

app1 = new QApp {

        styleFusionBlack()
        empty = 16  
        nr_moves = 0
        nr_sleep = 1
        button_size = 4 
        current_button = 4
        temp = 0
        flag_init = 0
        flag_save = 0
        flag_move = 0
        button = list(52)   
        size_button = list(7)
        table1 = [] 
        table2 = [] 
        table3 = []
        n_degree = 0
        nr_degree = [0,90,180,270 ,-90,-180,-270]
        n_degreeRight = 0
        n_degreeLeft = 0
        btn_degree = list(52,2)
        counter_man = 0 
        t1 = 0

        win1 = new QWidget() {

		setWinIcon(self,"fifteen.png")
		move(0,0)
		resize(380,760)
		setWindowTitle("CalmoSoft Fifteen Puzzle Game")

		for n=1 to 52
			for m=1 to 2
				btn_degree[n][m] = 0
			next
		next 

		for n = 4 to 7
			size_button[n] = new qpushbutton(win1)   
			{
				col = n%4
				setgeometry(100+col*40,60,40,40)
				settext(string(n) + "x" + string(n))
				setclickevent("newsize(" + string(n) + ")")
			} 
		next    

		btnMoves = new qpushbutton(win1)
		{
			setgeometry(100,260,80,40)
			settext("0")
			show() 
		}

		scramblebtn = new qpushbutton(win1)
		{
			setgeometry(100,300,160,40)
			settext("Scramble")
			setclickevent("scramble()")                        
		}

		resetbtn = new qpushbutton(win1)   
		{
			setgeometry(100,340,160,40)
			settext("Reset")
			setclickevent("resettiles()")
		}

		savebtn = new qpushbutton(win1)   
		{
			setgeometry(100,380,160,40)  
			settext("Save Game")  
			setclickevent("pSave()")
		}

		playbtn = new qpushbutton(win1)   
		{
			setgeometry(100,420,160,40)  
			settext("Resume Game")  
			setclickevent("pPlay()")
		}

		sleepbtn = new qpushbutton(win1)   
		{
			setgeometry(100,460,160,40)  
			settext("Sleep Time: ")  
		}

		decbtn = new qpushbutton(win1)   
		{
			setgeometry(220,460,40,40)  
			settext("<-")  
			setclickevent("pDecSleep()")
		}

		incbtn = new qpushbutton(win1)   
		{
			setgeometry(260,460,40,40)  
			settext("->")  
			setclickevent("pIncSleep()")
		}

		rightbtn = new qpushbutton(win1)   
		{
			setgeometry(100,500,160,40)  
			settext("In the Right Place : ")  
		}

		timebtn = new qpushbutton(win1)   
		{
			setgeometry(100,540,160,40)  
			settext("Elapsed Time : ")  
		}

		TimerMan = new qtimer(win1)
		{
			setinterval(500)
			settimeoutevent("pTime()")
			stop()
		}
		newsize(4) 
		show()
	}
        exec()
}

func scramble

	for n= 1 to 1000   
		current_button=random(button_size*button_size-1)+1
		up = (empty = (current_button - button_size))
		down = (empty = (current_button + button_size))
		left = ((empty = (current_button - 1)) and ((current_button % button_size) != 1))
		right = ((empty = (current_button + 1)) and ((current_button % button_size) != 0))
		move = up or down or left  or right
		if move = 1 
			button[current_button] { temp2 = text() }
			col = empty%button_size
			if col = 0 col = button_size ok
			row = ceil(empty/button_size)
			button[empty] {
				setgeometry(60+col*40,60+row*40,40,40)
				rnd = random(6)+1
				n_degree = nr_degree[rnd]
				button[empty].setbuttoncolor("yellow")
				button[empty].settext(temp2)
				button[empty].setClickEvent("movetile(" + string(empty) +")")
				btn_degree[empty] [1] = temp2
				btn_degree[empty] [2] = n_degree
			}
			button[current_button].setbuttoncolor("yellow")
			btn_degree[current_button][2] = 0
			button[current_button]{settext("")}
			empty = current_button
            	ok
	next
	button[button_size*button_size+2]{settext("Here")}
	for n=1 to button_size*button_size
		button[n].setbuttoncolor("yellow")
	next
	table1 = []
	table2 = []
	table3 = []   
	for n = 1 to button_size*button_size
		add(table1, button[n].text())
		add(table2, button[n].text())
		add(table3, string(btn_degree[n][2]))
	next
	add(table1, string(empty))
	add(table2, string(empty))
	add(table3, string(empty))
	add(table1, "OK")
	add(table2, "OK")
	add(table3, "OK")
	flag_save = 0
	flag_move = 0
	nr_moves = 0
	btnMoves.settext(string(nr_moves))
	timebtn.settext("Elapsed Time : ")
	t1 = clock()
	rightPlace()

func movetile current_button2

	if (current_button2 = button_size*button_size-1 and button[current_button2].text() = "In")
		pBack()
	else
		see char(7)
		up = (empty = (current_button2 - button_size))
		down = (empty = (current_button2 + button_size))
		left = ((empty = (current_button2- 1)) and ((current_button2 % button_size) != 1))
		right = ((empty = (current_button2 + 1)) and ((current_button2 % button_size) != 0))
		move = up or down or left  or right
		if move = 1 
			temp2 = button[current_button2].text() 
			btn_degree[empty][1] = temp2
			add(table1, temp2)
			add(table2, string(current_button2))              
			col = empty%button_size
			if col = 0 col = button_size ok
			row = ceil(empty/button_size)
			button[empty] {
				setgeometry(60+col*40,60+row*40,40,40)
				n_degree = btn_degree[current_button2][2]
				btn_degree[empty][2] = n_degree
				button[empty].setbuttoncolor("orange")
				button[empty].settext(temp2)                                   
			}
			add(table3, string(n_degree))
			button[current_button2].setbuttoncolor("cyan")
			button[current_button2]{settext("")}
			empty = current_button2
			nr_moves = nr_moves + 1
			btnMoves.settext(string(nr_moves))
			isGameOver()
		ok
	ok 
	flag_move = 1
	pElapsedTime()
	rightPlace()

func resettiles

        n_degree = 0  
        empty = button_size*button_size
        for empty = 1 to button_size*button_size-1
             btn_degree[empty][2] = 0
             n_degree = 0
             btn_degree[empty][1] = string(empty)
             button[empty].setstylesheet("background-color:yellow")
             button[empty] {settext(string(empty))}
        next
        button[button_size*button_size].setstylesheet("background-color:yellow")
        button[button_size*button_size] {settext("")}
        table1 = []
        table2 = []
        table3 = []   
        for n = 1 to button_size*button_size
             add(table1, button[n].text())
             add(table2, button[n].text())
             add(table3, string(btn_degree[n][2]))
        next
        add(table1, string(empty))
        add(table2, string(empty))
        add(table3, string(empty))
        add(table1, "OK")
        add(table2, "OK")
        add(table3, "OK")
        flag_save = 0
        flag_move = 0
        nr_moves = 0
        btnMoves.settext(string(nr_moves))
        timebtn.settext("Elapsed Time : ")
        t1 = clock()
        rightPlace()
        return

func pHere

        if button[button_size*button_size-1].text() != "" and button[button_size*button_size+2].text() = "Here"
           button[button_size*button_size-1] { temp = text() }
           button[button_size*button_size+2].close()
           button[button_size*button_size+2] = new ButtonWithRotatedText(win1)
           button[button_size*button_size+2] {
           setgeometry(60+(button_size-1)*40,60+(button_size+1)*40,40,40)
           setstylesheet("background-color:yellow")
           btn_degree[button_size*button_size+2][2] = btn_degree[button_size*button_size-1][2]
           n_degree = btn_degree[button_size*button_size+2][2]
           emptysave = empty
           empty = button_size*button_size+2
           btn_degree[empty][1] = temp
           settext(temp)
           }
           n_degree = 0
           empty = button_size*button_size-1
           btn_degree[empty][1] = "In"
           button[button_size*button_size-1]{settext("In")}
           for n = 1 to button_size*button_size
	   button[n].setenabled(false)
           next
           button[button_size*button_size-1].setenabled(true)
           scramblebtn.setenabled(false)
           resetbtn.setenabled(false)
           savebtn.setenabled(false)
           playbtn.setenabled(false)
           empty = emptysave
        ok

func pBack

        button[button_size*button_size+2] { temp = text() }
        n_degree = btn_degree[button_size*button_size+2][2]
        btn_degree[button_size*button_size-1][2] = btn_degree[button_size*button_size+2][2]
        emptysave = empty
        empty = button_size*button_size-1
        btn_degree[empty][1] = temp
        button[button_size*button_size-1] {settext(temp)}
        button[button_size*button_size+2].close()
        button[button_size*button_size+2] = new qpushbutton(win1)
                {
                setgeometry(60+(button_size-1)*40,60+(button_size+1)*40,40,40)
                settext("Here")
                setclickevent("pHere()")   
                show() 
                } 
        for n = 1 to button_size*button_size
              button[n].setenabled(true)
        next
        scramblebtn.setenabled(true)
        resetbtn.setenabled(true)
        savebtn.setenabled(true)
        playbtn.setenabled(true)
        empty = emptysave
        isGameOver()

func rotateleft

        if button[button_size*button_size+2].text() != "Here" 
           button[button_size*button_size+2].close()
           button[button_size*button_size+2] = new ButtonWithRotatedText(win1)
                      button[button_size*button_size+2] {
                      setgeometry(60+(button_size-1)*40,60+(button_size+1)*40,40,40)
                      setstylesheet("background-color:yellow")
                      n_degreeLeft = (n_degreeLeft-90)%360
                      n_degree = n_degreeLeft
                      btn_degree[button_size*button_size+2][2] = n_degree
                      emptysave = empty
                      empty = button_size*button_size+2
                      btn_degree[empty][1] = temp
                      button[button_size*button_size+2]{settext(temp)}
                      } 
                      empty = emptysave
        ok

func rotateright

        if button[button_size*button_size+2].text() != "Here"  
           button[button_size*button_size+2].close()
           button[button_size*button_size+2] = new ButtonWithRotatedText(win1)
                      button[button_size*button_size+2] {
                      setgeometry(60+(button_size-1)*40,60+(button_size+1)*40,40,40)
                      setstylesheet("background-color:yellow")
                      n_degreeRight = (n_degreeRight+90)%360
                      n_degree = n_degreeRight
                      btn_degree[button_size*button_size+2][2] = n_degree
                      emptysave = empty
                      empty = button_size*button_size+2
                      btn_degree[empty][1] = temp
                      button[button_size*button_size+2]{settext(temp)}
                      }
                      empty = emptysave
        ok

func newsize current_button

        win1 { 
                sizenew = current_button%4
                win1.resize(360+sizenew*40,640+sizenew*40)
                if flag_init != 0
                   for nb = 1 to button_size*button_size+3
                         button[nb] {close()}
                   next
                   btnMoves.close()
                ok
                scramblebtn.close()
                resetbtn.close()
                savebtn.close()
                playbtn.close()
                btnMoves.close()
                sleepbtn.close()
                decbtn.close()
                incbtn.close()
                rightbtn.close()
                timebtn.close()

                for n = 1 to current_button*current_button
                     col = n%current_button
                     if col = 0 col = current_button ok
                     row = ceil(n/current_button)
                     button[n] = new ButtonWithRotatedText(win1)
                                       button[n] {
                                       setgeometry(60+col*40,60+row*40,40,40)
                                       button[n].setbuttoncolor("yellow")                                       
                                       n_degree = 0
                                       if n < current_button*current_button
                                          button[n].settext(string(n))
                                       but n = current_button*current_button
                                          button[n].settext("")
                                       ok 
                                       setClickEvent("movetile(" + string(n) +")")
                                       }
                next

                btnMoves = new qpushbutton(win1)
                {
                                        setgeometry(100,60+(current_button+1)*40,(current_button-3)*40,40)
                                        setStyleSheet("text-align:center")
                                        settext("0")
                                        show() 
                }

                button[current_button*current_button+1] = new qpushbutton(win1)
                {
                                              setgeometry(60+(current_button-2)*40,60+(current_button+1)*40,40,40)
                                              settext("<-")
                                              setclickevent("rotateLeft()")   
                                              show() 
                } 

                button[current_button*current_button+2] = new qpushbutton(win1)
                {
                                             setgeometry(60+(current_button-1)*40,60+(current_button+1)*40,40,40)
                                             settext("Here")
                                             setclickevent("pHere()")   
                                             show() 
                }

                button[current_button*current_button+3] = new qpushbutton(win1)
                {
                                             setgeometry(60+current_button*40,60+(current_button+1)*40,40,40)
                                             settext("->")
                                             setclickevent("rotateRight()")   
                                             show() 
                 }

                scramblebtn = new qpushbutton(win1)
                {
                                      setgeometry(100,100+(current_button+1)*40,current_button*40,40)
                                      settext("Scramble")
                                      setclickevent("scramble()")
                                      show()                        
                }

                resetbtn = new qpushbutton(win1)   
                {
                                 setgeometry(100,100+(current_button+2)*40,current_button*40,40)
                                 settext("Reset")
                                 setclickevent("resettiles()")
                                 show() 
                }

                savebtn = new qpushbutton(win1)   
                {
                                 setgeometry(100,100+(current_button+3)*40,current_button*40,40)
                                 settext("Save Game")
                                 setclickevent("pSave()")
                                 show() 
                }

                playbtn = new qpushbutton(win1)   
                {
                               setgeometry(100,100+(current_button+4)*40,current_button*40,40)  
                               settext("Resume Game")  
                               setclickevent("pPlay()")
                               show()
                }

                sleepbtn = new qpushbutton(win1)   
                {
                               setgeometry(100,100+(current_button+5)*40,(current_button-2)*40,40)  
                               settext("Sleep Time: " + string(nr_sleep) + " s")  
                               show()
                }

                decbtn = new qpushbutton(win1)   
                {
                               setgeometry(100+(current_button-2)*40,100+(current_button+5)*40,40,40)  
                               settext("<-")  
                               setclickevent("pDecSleep()")
                               show()
                }

                incbtn = new qpushbutton(win1)   
                {
                               setgeometry(100+(current_button-1)*40,100+(current_button+5)*40,40,40)  
                               settext("->")  
                               setclickevent("pIncSleep()")
                               show()
                }

               rightbtn = new qpushbutton(win1)   
                {
                               setgeometry(100,100+(current_button+6)*40,current_button*40,40)  
                               settext("In the Right Place : ")  
                               show()
                }

                timebtn = new qpushbutton(win1)   
                {
                               setgeometry(100,100+(current_button+7)*40,current_button*40,40)  
                               settext("Elapsed Time : ")  
                               show()
                }

                table1 = []
                table2 = []
                table3 = []   
                for n = 1 to button_size*button_size
                      add(table1, button[n].text())
                      add(table2, button[n].text())
                      add(table3, string(0))
                next
                add(table1, string(empty))
                add(table2, string(empty))
                add(table3, string(empty))
                add(table1, "OK")
                add(table2, "OK")
                add(table3, "OK")
                empty = current_button*current_button
                button_size = current_button
                flag_init = 1
                flag_save = 0
                flag_move = 0
                nr_moves = 0
                timebtn.settext("Elapsed Time : ")
                t1 = clock()
                scramble()
	}

func pSave

	textedit1 = list2str(table1)
        textedit2 = list2str(table2)
        textedit3 = list2str(table3)
        chdir(currentdir())
        cName1 = "CalmoSoftPuzzle1.txt"
        cName2 = "CalmoSoftPuzzle2.txt"
        cName3 = "CalmoSoftPuzzle3.txt"
        write(cName1,textedit1)
        write(cName2,textedit2)
        write(cName3,textedit3)
	flag_save = 1   
	timebtn.settext("Elapsed Time : ")
	t1 = clock()

func pPlay

        if  flag_save = 0 or flag_move = 0
		warning()  
        else
		chdir(currentdir())
		cName1 = "CalmoSoftPuzzle1.txt"
		textedit1 = read(cName1)
		table1 = str2list(textedit1)
		cName2 = "CalmoSoftPuzzle2.txt"
		textedit2 = read(cName2)
		table2 = str2list(textedit2)
		cName3 = "CalmoSoftPuzzle3.txt"
		textedit3 = read(cName3)
		table3 = str2list(textedit3)
		for empty = 1 to button_size*button_size
			button[empty].setbuttoncolor("yellow") 
			n_degree = number(table3[empty])
			btn_degree[empty][1] = table1[empty]
			button[empty] {settext(table1[empty])}
		next
		empty = number(table1[button_size*button_size + 1])
		counter_man = button_size*button_size+2
		nr_moves = 0
		t1 = clock()
		TimerMan.start()
       ok

func pTime

	if flag_save = 0 or flag_move = 0
		warning()    
        else
		counter_man++
		pPlaySleep()
		sleep(nr_sleep*1000) 
		pElapsedTime()
		if counter_man = len(table1)
			TimerMan.stop()
		ok
        ok

func pPlaySleep

        see char(7)
        value = table1[counter_man]
        place = table2[counter_man]
        n_degree = number(table3[counter_man])
        btn_degree[empty][1] = value
        button[empty].setbuttoncolor("orange")
        button[empty] {settext(value)}
        n_degree = 0
        button[number(place)].setbuttoncolor("cyan")
        button[number(place)] {settext("")}
        empty = number(place)        
        nr_moves = nr_moves + 1
        btnMoves.settext(string(nr_moves))

func pIncSleep

        nr_sleep = nr_sleep + 1 
        sleepbtn.settext("Sleep Time: " + string(nr_sleep) + " s")

func pDecSleep

	if nr_sleep > 1 
		nr_sleep = nr_sleep - 1
		sleepbtn.settext("Sleep Time: " + string(nr_sleep) + " s")
        ok

func sleep(x)

        nTime = x 
        oTest = new qTest
        oTest.qsleep(nTime)

func isGameOver

	flagend = 1
        for n=1 to button_size*button_size-1
		if button[n].text() != n or btn_degree[n][2] != 0
			flagend = 0
			exit
		ok
        next
	if flagend = 1
		new qmessagebox(win1) {
			setwindowtitle("Game Over") 
			settext("Congratulations!")
			show()
		}   
        ok   

func rightPlace

	count = 0
        for n=1 to button_size*button_size
		if button[n].text() = n and btn_degree[n][2] = 0
			count = count + 1
		ok
        next   
        rightbtn.settext("In the Right Place : " + count)

func warning

	new qmessagebox(win1) {
                setwindowtitle("Warning!") 
                settext("First you must play and save the game.")
		show()
	}         

func pElapsedTime

        t2 = (clock() - t1)/1000
        timebtn.settext("Elapsed Time : " + t2 + " s")

Class ButtonWithRotatedText

	oButton oLabel  cText="We are here"  n_degree = 30  nTransX = 50   nTransY = 0

func init oParent

        oButton = new qPushButton(oParent)
        oLabel  = new qLabel(oParent)
        oLabel.setAttribute(Qt_WA_TransparentForMouseEvents,True)
        oLabel.setAttribute(Qt_WA_DeleteOnClose, True)
        oButton.setAttribute(Qt_WA_DeleteOnClose, True)
        oButton.Show()
    
func close

        oLabel.close()
        oButton.close()

func setstylesheet x

        oButton.setstylesheet(x)

func setgeometry x,y,width,height

        oButton.setgeometry(x,y,width,height)
        oLabel.setgeometry( x,y,width,height)
        
func setText cValue

	cText = cValue
    
func Text
	return cText

func setTranslate x,y    
 
	nTransX = x
	nTransY = y		

func TranslateOffsetX

        return nTransX 

func TranslateOffsetY

        return nTransY 
	
func setRotation_degree( nValue)

        n_degree = nValue
    
func Rotation_degree

        return n_degree

func setClickEvent cEvent

        oButton.setClickEvent(cEvent)
    
func braceend

        draw() 

func setEnabled(value)     
   
        oButton.setenabled(value)

func setButtonColor color  

	colorIt = "background-color:" + color  
	oButton.setstylesheet(colorIt) 
    	
func draw

	picture = new qpicture()
	color   = new qcolor() { setrgb(0,0,255,255) }
	pen     = new qpen()   { setcolor(color) setwidth(10) }
                    
	painter = new qpainter() 
	{
		begin(picture)        
		setpen(pen)
		oFont = new qfont("Courier New",12,75,0)
		oFont.setpointsize(20)
		setfont(oFont)
		if n_degree = 0
			if btn_degree[empty] [1]="In" p1 = -8 p2=0 
				translate(p1,p2) ok ok
		if n_degree = 0
			if btn_degree[empty] [1]<10 p1 = 10 p2=10 else p1=5 p2=10 ok
			translate(p1,p2)
		but n_degree = 90
			if btn_degree[empty] [1]<10 p=-10 else p=-15 ok
			translate(10,p)
		but n_degree = 180
			if btn_degree[empty] [1]<10 p1= 30 p2=-10 else p1=35 p2=-10 ok
			translate(p1,p2)
		but n_degree = 270
			if btn_degree[empty] [1]<10 p=10 else p=15 ok
			translate(30,p)
		but n_degree = -90
			if btn_degree[empty] [1]<10 p=10 else p=15 ok
			translate(30,p)
		but n_degree = -180
			if btn_degree[empty] [1]<10 p1=30 p2=-10 else p1=35 p2=-10 ok
			translate(p1,p2)
		but n_degree = -270
			if btn_degree[empty] [1]<10 p1=10 p2=-10 else p1=10 p2=-15 ok
			translate(p1,p2)
		ok						
		rotate(n_degree)
		drawText(0,0,this.Text())   
		endPaint()
	}
	oLabel {
		setPicture(picture)  
		show() 
	}

