see "Testing For item in List" + nl
see "The first test " + nl
see "================" + nl

alist = ["one","two","three"]

for x in alist
	see "Item : " + x + nl
next

see "The second test " + nl
see "================" + nl

list = "a":"z"
for x in list
	see x 
next 
see nl

list = 1:10 for x in list see x see nl next

see "The third test " + nl
see "================" + nl

aList = [
[1,2,3,4],
["one","two","three"]
]

for x in aList[2]
	see "Item : " + x + nl
next

see "The test no. 4" + nl
see "================" + nl

for x in 1:10
	see x
	see nl
next

see "The test no. 5" + nl
see "================" + nl

for x in "a":"f"
	see x
	see nl
	for y in 1:5 see y next see nl
next

see "end of test" + nl


