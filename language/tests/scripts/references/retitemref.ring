# Author: Ilir Liburn

cnd = 0
do
	ret = test()
again cnd

? refcount(ret)
? ret

ret { data = NULL }
? ret

func test
	cls2 = [new Temp { data="test2" }]
	cls = ref(cls2[1])
	return cls

class Temp
	data
