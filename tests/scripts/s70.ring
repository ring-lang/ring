see "define list :" + nl

mylist = [
[1,2,3],
[1,2,3],
[1,2,3]
]

see "see the list " + nl
see mylist

for x = 1 to 3
	for y = 1 to 3
		mylist [x] [y] = x * y
	next
next

see "see list after update" + nl
see mylist