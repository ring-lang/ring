? "Loading Library"
load "fastpro.ring"

aList = [
list(5),
list(5),
list(5),
list(5),
list(5)
]

updateList(aList,:serial,:col,1,0)
updateList(aList,:serial,:col,2,5)
updateList(aList,:serial,:col,3,10)
updateList(aList,:serial,:col,4,15)
updateList(aList,:serial,:col,5,20)

? aList

? copy("*",20)

for x=1 to 5
	for y=1 to 5
		print(aList[x][y])
		if y != 5 print ("-") ok
	next
	? ""
next