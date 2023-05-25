mylist = []
myobj  = ref(new point) 
? :before
add(mylist,ref(myobj))
x=10 y=20 z=30
? :after
? :good
? mylist	
? len(mylist)
? refcount(myobj)
? :done

class point x y z
