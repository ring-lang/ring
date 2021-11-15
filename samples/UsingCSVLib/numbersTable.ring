load "csvlib.ring"

aList = [
	:one   = 1,
	:two   = 2,
	:three = 3,
	:four  = 4,
	:five  = 5
]

write( "numbers.csv", list2CSV(aList) )