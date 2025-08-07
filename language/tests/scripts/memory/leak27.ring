? ringvm_ismempool()
for t=1 to 110000
	new circular {
		v = myobj.myobj.myobj.myobj.x
		v = refcount(self)
	}
	o = new circular {
		v = myobj.myobj.myobj.myobj.x
		v = refcount(self)
	}
next
? ringvm_ismempool()

class circular
	myobj = ref(self)
	x = 10