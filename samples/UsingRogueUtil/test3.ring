load "rogueutil.ring"

setConsoleTitle("Using GotoXY()")

setColor(White)
setBackgroundColor(Green)

cls()

gotoXY(30,2)
print("I Love Programming!")

for t=1 to 10
	gotoXY(10,10+t)
	print( "Number: " + t)
next

getch()
