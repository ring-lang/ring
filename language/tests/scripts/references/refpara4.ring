# Author: Ilir Liburn

oid = NULL
tmp = [[:tmp]]

tmp2 = test(ref(tmp[1]))

? refcount(tmp2)
? tmp2
? :done

func test x
	y = ref(x)
	? refcount(x)
	tmp = NULL
	? refcount(x)
	return test2(x)

func test2 x
