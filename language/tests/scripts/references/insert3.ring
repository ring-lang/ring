# Author: Ilir Liburn
# Updated by Fayed

a=[:a]
b=[:b]

insert(a,0,ref(b))
insert(b,0,ref(a))

line()
? "First"
line()

for y in b
	? y
	line2()
next

line()
? "Second"
line()

for y in b
	? y
	line2()
	b = []	
	# b reference stored in a will become a value
	? y
next

? :done

func line 
	? copy("=",10)

func line2
	? copy("*",10)