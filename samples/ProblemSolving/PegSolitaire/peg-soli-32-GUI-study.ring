// peg-solitaire: peg-soli-1.ring
// This program solves the (English) peg solitaire board game.
// http://en.wikipedia.org/wiki/Peg_solitaire
// quell: https://golang.org/doc/play/solitaire.go

// at the beginning to May 2020 - nestor kuka / bert mariani (Graphics)

Load "stdlib.ring"
load "guilib.ring"


// solitaire board as string:
// The board must be surrounded by 2 illegal fields in each direction 
// so that move() doesn't need to check the board boundaries.
// Periods represent illegal fields, x are pegs, and o are holes.
b = "..........................xxx........xxx......xxxxxxx....xxxoxxx....xxxxxxx......xxx........xxx.........................."

N      = 11  		 			// length of a row (11x11)
pd     = [-1, -N, 1, N]	   		// possible directions
moves  = 0						// number of times move is called
center = 0					   	// empty hole
cnt    = 32						// count the successful moves

###---------------------------------------------------------------
 
moveX  = 100  moveY = 100
sizeX  = 440  SizeY = 440

width  = sizeX / N
height = sizeY / N
       

Button          = newlist(N,N)
LayoutButtonRow =    list(N)

C_ButtonInvalidStyle = 'border-radius: 2px; border-width: 2px; border-style: outset; color:black; background-color: rgb(255,102,102); '        ### Light Pink
C_ButtonPickStyle    = 'border-radius: 2px; border-width: 2px; border-style: outset; color:black; background-color: rgb(255,255,93); '         ### Yellow           
C_ButtonDestStyle    = 'border-radius: 2px; border-width: 2px; border-style: outset; color:black; background-color: rgb(204,255,204); '        ### Cyan
C_ButtonEmptyStyle   = 'border-radius: 2px; border-width: 2px; border-style: outset; '

timeDelay	= 1000		    ### 1=millisecs	 1000=second

FlagFirst = 0
	
###=====================================================

app = new qApp 
{
    win = new qWidget() 
    {
			
			myFilter = new qAllEvents(win)
			myFilter.setKeyPressEvent("pWork()")
			myFilter.setCloseevent("app.Quit()")
			installEventFilter(myFilter)

        setWindowTitle('Peg Solitaire: ')

          move(moveX, moveY)
        reSize(sizeX, sizeY)
        winHeight = win.height()
        fontSize  = 8 + (winHeight / 100)
		
		###>>> WITH QT Buttons		

 	    for Row = 1 to N
         	for Col = 1 to n
		    Button[Row][Col] = new QPushButton(win) {
				   x = (Row-1)*width
				   y = (Col-1)*height
				   setgeometry(x,y,width,height)
				   setStyleSheet(C_ButtonEmptyStyle)
				   setSizePolicy(1,1) 
				   installEventFilter(myFilter)
			}				       
			next
        next
			
  
        ###--------------------------------------------
		
  
	    show()
		startMain()
		        
   }
   exec()
 }


########################################

// ---------------------------------------------- program start
func startMain() {

	See "startMain: "+nl

	### Start initial display

	? " "
	? "Show board:"

	show_b(b)

	? " "
	? "Time : " +Time()
	//t1 = clock()
	? "Solution Steps: "
	
    //----------------------

	init(b)	
	if !solve() {
		? "No solution found"
	ok
	? ""
	? "Moves tried: " + moves
	? "Time : " +Time()
}

// ----------------------------------------------- init pos. 'o'
// center is the position of the center hole if
// there is a single one; otherwise it is -1.

func init(b) {

	nn = 0
	for i=1 to len(b)  
		pos = b[i]
		if pos = 'o' 
			center = i
			nn = nn+1
		ok
	next
	if nn != 1 
		center = -1 	// no single hole
	ok
}

// ---------------------------------------------- show the board

func show_b(b) {
	x = 1
	y = 11
	
	for j = 1 to 11
	  for i = x to y
			x = x + 1
			see b[i]
	  next
			y = x + 10
			? ""	 	
	next
	
	MapToButtons(b)
	
}


// ---------------------------------------------- move(pos, dir)
// moves = 0	// number of times move is called
// move tests if there is a peg at position pos that
// can jump over another peg in direction dir. If the
// move is valid, it is executed and move returns true.
// Otherwise, move returns false.

func move(pos, dir) {
	moves = moves+1
	if b[pos] = 'x' && b[pos+dir] = 'x' && b[pos+2*dir] = 'o' 
		b[pos] = 'o'
		b[pos+dir] = 'o'
		b[pos+2*dir] = 'x'
		return true
	ok
	return false
}

// -------------------------------------------- unmove(pos, dir)
// unmove reverts a previously executed valid move.

func unmove(pos, dir) {
	b[pos] = 'x'
	b[pos+dir] = 'x'
	b[pos+2*dir] = 'o'					
}

// ----------------------------------------------------- solve()
// solve tries to find a sequence of moves such that
// there is only one peg left at the end; if center is
// >= 0, that last peg must be in the center position.
// If a solution is found, solve prints the board after
// each move in a backward fashion (i.e., the last
// board position is printed first, all the way back to
// the starting board position).

func solve() {
	last =0 
	nn   =0
	
	for pos=1 to len(b)
		// try each board position
		field = b[pos]
		if field = 'x' 				// found a peg:
			for dir = 1 to len(pd)	// -1, -N, +1, +N (dir = 4)
				// try all directions in the mow:
				if move(pos, pd[dir]) 	
				/*
					// ------------- debug: -------------
					show_b(b)			// see all steps
					Sleep(1)			// wait 1 second
					? " count of tried move: "+moves
					// ------------ debug end -----------
				*/
					// a valid move was found and executed,
					// see if this new board has a solution.
					if solve() 					// recursion 
						unmove(pos, pd[dir])	// position & direction
						cnt = cnt - 1
						? ">>------->  Move no. :"+ cnt
						show_b(b)				// show the move
										
						return true
					ok
					unmove(pos, pd[dir])
				ok
			next // dir
			last = pos
			nn = nn+1
		ok
					
	next //pos
	
	// tried each possible moves
	if nn = 1 && (center = 0 || last = center)  
		// there's only one peg left
		show_b(b)
		return true
	ok
	// no solution found for this board
	
	return false
}
 // --------------------------------------------------  end program


//-------------------------------------------------
// May Array value to Button Display

Func MapToButtons(b)

    k = 1
	for i = 1 to 11
		for j = 1 to 11
         
			if  b[k] = 'o'
				Button[i][j] { setStyleSheet(C_ButtonDestStyle) }  
				 
			but  b[k]= 'x'
				Button[i][j] { setStyleSheet(C_ButtonPickStyle) }  
				 
			else
				Button[i][j] { setStyleSheet(C_ButtonEmptyStyle) }  
					 
			ok   
		
			k++
			
		next	
	next
	
	###--------------------------
    ### Update display of Squares
	
	app.processevents()
	sleep(1)

	
return

//--------------------------------------

