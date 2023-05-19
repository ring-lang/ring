# Author: Ilir Liburn
# Updated by Fayed

cnd = 0
do
	x = ref(new Obj) { 
		self.data = [ref(self.data),ref(self.data),10] 
	}
again cnd
? refcount(x.data)
? x.data
? x.data[1][1][1][1][3]

class Obj
        data = NULL