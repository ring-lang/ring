/*
	Bug ID : 206
	Description : Crash in using = operator after see with objects from funcs.
	Status : Fixed
*/

mylist = []
o1 = new point {x=10 y=20 z=30}
mylist + o1

see f1() = f1()

func f1 
	return mylist[1]


class point x y z