# Author: Ilir Liburn

a = [ref(a),2,3]

a = test2(a[1])

? refcount(a)
? a
? :done

func test x
	return test2(x)

func test2 x
	for e in a
		a = NULL
	next
	? x
	return x
