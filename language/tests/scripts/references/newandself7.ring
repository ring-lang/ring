# Author: Ilir Liburn
# Updated by Fayed

test = NULL
pool = []

x = ref(new Obj) { 
	add(pool,ref(self)) 
	? refcount(pool[1]) 
	pool[1] = ref(self) 
	? refcount(pool[1]) 
	test = ref(self) 
	? refcount(self) 
	test = ref(self) 
	? refcount(test) 
	try
		self = NULL 
	catch
		? cCatchError
	end
	mytest()
}

? refcount(x)
? x.data

class Obj
	data = []
	func mytest
		? "message from mytest"