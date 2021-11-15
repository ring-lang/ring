load "csvlib.ring"

aList = [ ["number", "square" ] ]

for t=1 to 10
	aList + [ t, t*t ]
next

write( "squares.csv", list2CSV(aList) )