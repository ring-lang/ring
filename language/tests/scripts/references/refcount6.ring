a = [0]
b = [0]
c = [0]

x = ref(a)
y = ref(b)
z = ref(c)

? copy("=",10)
? a+b+c+[3]
? copy("=",10)
? "A RefCount: " + refcount(a)
? "B RefCount: " + refcount(b)
? "C RefCount: " + refcount(c)
? copy("=",10)