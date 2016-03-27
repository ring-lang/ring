see "hello world" + nl
name = "ibrahim samir fayed"
see name + nl
name = name + " say hello
to you
how are you ?"
see name + nl
for x = 1 to 10 
		see x see nl 
		if x = 3 see "three " + nl ok
next
x = 10
while x >= 1
	see x see nl X = X - 1
end

mylist = ["","Mahmoud","Ahmed","Ibrahim"]
mylist[1] = "mohammed"
see seelist(mylist,2)[2] 

see nl
mylist = [1,2,3,4,5,["mahmoud","ahmed",3,["ibrahim",22]]]
see mylist[6][4][1] + nl

x = "123"
y = 2
see y + x see nl
see x + y + nl

x = 1.22
y = 1.78
see x + y 
see nl

func seelist list,size
	for x = 1 to size
		see list[x] + nl
	next
	list2 = list
	for x = 1 to size
		list2[x] = x * x
	next
	return list2
	