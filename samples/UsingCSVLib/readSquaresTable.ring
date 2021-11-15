load "csvlib.ring"

if ! fexists("squares.csv")
	? "The file squares.csv doesn't exist! - Run squaresTable.ring to create it"
	return
ok

aList = CSV2List( read("squares.csv") )

for subList in aList 
	? "" + subList[1] + " - " + subList[2]
next