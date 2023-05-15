# Author: Ilir Liburn

ret = [new Temp { data="test" }] 
cnd = 0
do
	ret[1] = test(ret[1])
	? refcount(ret)
	? ret
again cnd

try
	ret { data = NULL }
catch
	? "Using braces we access object (Not Lists)"
done
? ret
? :done

func test x
	return ref(x)

class Temp
	data
