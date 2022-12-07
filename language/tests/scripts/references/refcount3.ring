c = [:wow]
for t=1 to 3
	? :Start
	a = [1,NULL,NULL]
	? refcount(c)
	b = [2, ref(a)]
	? refcount(c)
	a[2] = ref(b)
	? refcount(c)
	a[3] = ref(c)
	? refcount(c)
	? c
	? :End
next