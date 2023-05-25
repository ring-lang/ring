mylist = []
myobj  = new point {
	? :before
	add(mylist,ref(self)) 
	? :After
	x=10 y=20 z=30
}
? :good
? mylist	
? len(mylist)
? refcount(myobj)
? :done

class point x y z
