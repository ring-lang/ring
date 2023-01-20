# Author: Ilir Liburn

c = [:wow]
for t=1 to 1
	? c
	a = [1,2,3]
	for e in a
		? "---"
		? a[1]
		? "---"
		if e = 1 e = ref(a) ok
		b = [2, ref(a)]
		b[1] = ref(b)
		if e = 2 e = ref(b) ok
		if e = 3 e = ref(c) ok
		? refcount(a)
		? refcount(b)
		? refcount(c)
	next
next