# Author: Ilir liburn

a=[:a]
b=[]

for x in a
	? refcount(a)
	b + ref(a)
	for y in b
		? refcount(a)
		? copy("*",10)
		? b
		a = []
	next
	? x
	? refcount(b[1])
	? type(b[1])
	? copy("*",10)
	a + ref(b)
	? a
	b = NULL
	? refcount(a)
	? type(a[1])
next

? :done