CSVLib Library
==============

Using this library we can generate and read CSV Files

# install

	ringpm install csvlib from ringpackages

# Functions

	List2CSV(aList) --> cCSVString
	CSV2List(cCSVString) --> aList

# Example

	load "csvlib.ring"

	aList = [ ["number", "square" ] ]

	for t=1 to 10
		aList + [ t, t*t ]
	next

	write( "squares.csv", list2CSV(aList) )

# Output

![squarestable](https://raw.githubusercontent.com/ring-lang/ring/master/documents/source/squarestable.png)

# Example (2)

	load "csvlib.ring"

	if ! fexists("squares.csv")
		? "The file squares.csv doesn't exist! - Run writeSquaresTable.ring to create it"
		return
	ok
	
	aList = CSV2List( read("squares.csv") )
	
	for subList in aList 
		? "" + subList[1] + " - " + subList[2]
	next

# Output

	number - square
	1 - 1
	2 - 4
	3 - 9
	4 - 16
	5 - 25
	6 - 36
	7 - 49
	8 - 64
	9 - 81
	10 - 100

# More Samples

URL: https://github.com/ring-lang/ring/tree/master/samples/UsingCSVLib
