myList = list(200)
mylist[1] = "what is this"

for i in myList
	? i
	? :before
	? len(mylist)
	myList = NULL
	? :after
	? len(mylist)
	? i
next
 
? i
? :done