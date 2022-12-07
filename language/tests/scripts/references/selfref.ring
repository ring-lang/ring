# Author: Ilir Liburn

tmp = new Temp { data="test2" }
cls2 = [ref(tmp)]
? refcount(tmp)
? "--------"
tmp=NULL
? refcount(cls2[1])
cls2[1] { tmp = ref(self) }
? tmp
? refcount(tmp)
? cls2[1]
? refcount(cls2[1])

class Temp
	data