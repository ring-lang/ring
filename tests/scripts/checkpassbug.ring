# test trying to discover a bug - but no bug is found!

func main

	mylist = [["one"],[["two"],["three"]]]
	test (mylist)
	see mylist
	see mylist[2][3]

	p1 = new point
	add(p1[2],["test",1,"nice"])
	see p1
	p1.test = "great"
	see p1.test + nl

	p2 = new point()
	see p2
	see p2.wow

func test aPara

	aPara[2] + [1,2,3,4]


Class Point from base
	 x y z 

class base

	func init

		add(self[2],["wow",1,"mmm.."])
