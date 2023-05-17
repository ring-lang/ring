x = [1:10]
y = ref(x[1])

? refcount(x[1])	
ref(x[1])
? refcount(x[1])	

ref(test(ref(x[1])))

? refcount(x[1])	

test(ref(x[1]))		

? refcount(x[1])	

callgc()		

? refcount(x[1])	

func test x
	z = ref(x)
	return ref(x)