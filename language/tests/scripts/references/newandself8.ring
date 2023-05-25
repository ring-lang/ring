# Author: Ilir Liburn
# Updated by Fayed

test = NULL
pool = []

ref(new Obj) { 
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
}
? refcount(pool[1])
? pool[1].data

class Obj
	data = []
