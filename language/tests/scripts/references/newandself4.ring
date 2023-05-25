mylist = []
myobj  = ref(new point) {
	? :before
	? self
	add(mylist,ref(self)) 
	x=10 y=20 z=30
	? self
	? :after
}
? :good
? mylist	
? len(mylist)
? refcount(myobj)
? :done

class point x y z
