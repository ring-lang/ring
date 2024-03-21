p = NULLPointer()

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
