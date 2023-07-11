new circular {
	? myobj.myobj.myobj.myobj.x
	? refcount(self)
}

class circular
	myobj = ref(self)
	x = 10