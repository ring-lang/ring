mylist = 1:10
mytest(ref(mylist))			
? :Done

func mytest a
	? refcount(a)			# 2
	return ref(mytest2(ref(a)))	

func mytest2 a	
	? refcount(a)			# 3
	mylist = null			
	? refcount(a)			# 2
	return a
