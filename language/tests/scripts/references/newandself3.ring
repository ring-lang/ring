mylist = []
myobj  = mytest(new point) {
	? :before
	add(mylist,ref(self)) 
	? :after
	x=10 y=20 z=30
}
? :good
? mylist	
? len(mylist)
? refcount(myobj)
? :done

func mytest x
	return x

class point x y z
