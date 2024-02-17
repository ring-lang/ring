# Author : Abdulrahman - https://github.com/AbdelrahmanGIT/RingSamples

Load "lightguilib.ring"

#Provide a list to save each button status in numeric readable format
#0=nothing 1=X 2=O
lst=[]

#Provide onScreen button status and style
btns=[]

#Define who has the turn
isXTurn=true


    app=new qApp
    {
	stylefusionBlack()
        frmMain=new qMainWindow()
		{
			setWinIcon(self,"icon.png")
			setWindowTitle("TicTacToe!")
			resize(300,320)
			move(200,200)
			//buttons
			pos=0
			for y=0 to 2
				for x=0 to 2
				//Creating Buttons on the screen
					pos++
					Add(lst,0)
					Add(btns,new qPushButton(frmMain)
						{
							setGeometry(x*100,y*100,100,100)
							setText("-")
							setclickevent("Disp(" + pos +")")
							setstylesheet("font-size:24pt ; font: bold ;")
						})
				next
            next
			//StatusBar
			status=new qStatusBar(frmMain)
			{
                showMessage("Ready",0)
            }
			setwindowflags(Qt_dialog)
			setStatusbar(status)
			show()
        }
		exec()
	}

//Restart the game by re init buttons status
func reStart
    for i=1 to 9
        lst[i]=0
        btns[i].setText("-")
    next  
isXTurn=true

func Disp x
    if isXTurn=true and lst[x]=0
		btns[x].setText("X")
		lst[x]=1
		isXTurn=false
	but isXTurn=false and lst[x]=0
        btns[x].setText("O")
        lst[x]=2
        isXTurn=true
    ok
	
	winner = CheckWinner()
	#if there is no Winner and still there is ability to winner
	#continue playing.
	if winner<1 return ok
	
	//Who is the winner!
    switch winner
        on 1
            new qMessagebox(frmMain)
            {
				SetWindowTitle("We have a winner!")
                SetText("Good job X you won!")
                show()
            }
        on 2
			new qMessagebox(frmMain)
            {
				SetWindowTitle("We have a winner!")
                SetText("Good job O you won!")
                show()
            }
        on 3
            new qMessagebox(frmMain)
            {
                SetWindowTitle("Oh no it's a tie")
                SetText("Oh no it's a tie!")
                show()
            }
    off
    reStart()

func CheckWinner
        //vertical check
        for v=1 to 9 step 3
            if lst[v]!=0 and lst[v+1]!=0 and lst[v+2]!=0
				if lst[v]=lst[v+1] and lst[v+1]=lst[v+2]
                    return lst[v]
                ok
            ok
        next
        //horizontal
        for h=1 to 3
            if lst[h]!=0 and lst[h+3]!=0 and lst[h+6]!=0
                if lst[h]=lst[h+3] and lst[h+3]=lst[h+6]
                    return lst[h]
                ok
            ok
        next
        //Cross
        if lst[1]!=0 and lst[5]!=0 and lst[9]!=0
            if lst[1]=lst[5] and lst[5]=lst[9] return lst[1] ok
        ok
        if lst[3]!=0 and lst[5]!=0 and lst[7]!=0
            if lst[3]=lst[5] and lst[5]=lst[7] return lst[3] ok
        ok
        //tie
        tie=true
        for i=1 to 9
            if lst[i]=0 tie=false exit ok
        next
        if tie=true return 3 ok return 0
