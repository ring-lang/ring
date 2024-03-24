load "fastpro.ring"

aList = [  1:5,  list(5) ]

/*
	aList = [
		[1,2,3,4,5],
		[0,0,0,0,0]
	]
*/

updateList(aList,:copy,:row,1,2)
updateList(aList,:mul,:row,2,10)

? aList