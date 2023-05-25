mylist = []
myobj  = new point {
	? :before
	add(mylist,ref(self)) 
	? :After
	x=10 y=20 z=30
	data + "one"
	data + "two"
	Add(data,"three")
}
? :good
? mylist	
? len(mylist)
? refcount(myobj)
? myobj
? myobj.data
? :done

class point x y z
	data = []
