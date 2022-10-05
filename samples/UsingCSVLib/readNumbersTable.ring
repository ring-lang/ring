load "csvlib.ring"

if ! fexists("numbers.csv")
	? "The file numbers.csv doesn't exist! - Run writeNumbersTable.ring to create it"
	return
ok

aList = CSV2List( read("numbers.csv") )

for subList in aList 
	? subList[1] + " - " + subList[2]
next