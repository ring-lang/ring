load "rogueutil.ring"

setConsoleTitle("Using PrintXY()")

setColor(Black)
setBackgroundColor(Cyan)

cls()

printXY(10,2,'In Mathematics, we call multiplying a number by itself "squaring" the number.')

for t=1 to 12
	printXY(10,10+t, "Number: " + t + " x " + t + " = " + (t*t) )
next

printXY(10,22,"Press any key to continue!")
getch()