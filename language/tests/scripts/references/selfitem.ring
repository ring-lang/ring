# Author: Ilir Liburn

ret = [new Temp { data="test" }] 
cnd = 0
do
	ret[1] = test(ret[1])
	? refcount(ret)
	? ret
again cnd

ret { data = NULL }
? ret
? :done

func test x
	return ref(x)

class Temp
	data
