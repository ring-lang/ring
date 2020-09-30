see "Enter Grade:"
give g

if g < 0
	see "No Grade"
but g < 50
	see "F"
but g < 60
	see "E"
but g < 70
	see "D"
but g < 80
	see "C"
but g < 90
	see "B"
but g <= 100
	see "A"
else
	see "No Grade"
ok
