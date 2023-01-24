# Author: Ilir Liburn

cnd = 0
do
	ret = test()
again cnd

? refcount(ret)

func test
	ret = test2()
	return ret

func test2
	cls2 = [new Temp { data="test2" }]
	cls = ref(cls2[1])
	return cls

class Temp
	data
