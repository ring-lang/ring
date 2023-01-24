# Author: Ilir Liburn

ret = [new Temp { data="test" }] 

cnd = 0
do
	ret = test(ret)
	? refcount(ret)
	? ret
again cnd

ret[1] { data = NULL }
? ret
? :done

func test x
	return ref(x)

class Temp
	data
