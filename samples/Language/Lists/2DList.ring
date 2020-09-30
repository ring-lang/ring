# Create 4x5 list

aList = [
	[1,2,3,4,5],
	[1,2,3,4,5],
	[1,2,3,4,5],
	[1,2,3,4,5]
]

nRows  = len(aList)
nCols  = len(aList[1])
? "Rows : " + nRows
? "Cols : " + nCols
for y=1 to nRows
	for x=1 to nCols
		see aList[y][x]
	next
	see nl
next