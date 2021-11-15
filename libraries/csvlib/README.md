CSVLib Library
==============

Using this library we can generate and read CSV Files

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


