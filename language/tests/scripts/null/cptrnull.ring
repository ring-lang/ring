p = NULLPointer()

? 0+p[1]
? p[2]
? p[3]

if p
	? :What
ok

if ! p
	? "Ok, We have a C pointer = NULL"
ok

? p and p
? p and 1
? p or 1
? ! p

? isnull(p)
? type(p)
