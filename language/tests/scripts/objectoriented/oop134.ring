# Using mergemethods() after some creating objects 

? :start

C_COUNT = 32

for x = 1 to C_COUNT
	eval("func test" + x + nl + " ? :welcome + " + x)
next

for x = 1 to C_COUNT
	eval("class test" + x + nl + "func test" + x + " ? :msg" + x + nl)
next

for x = 1 to C_COUNT
	cFunc = "test" + x
	call cFunc()
next

# create some objects
for x = 1 to C_COUNT
	eval("o1 = new test"+x)
	eval("o1.test" + x + "()")
next

# Using mergemethods
? "Merge Methods"
for x = 2 to C_COUNT
	mergemethods(:test1,"test"+x)
next

# create another object
myobj = new test1
? methods(myobj)

myobj.test1()

? ismethod(myobj,:test2)
myobj.test2()

for x = 1 to C_COUNT
	eval("myobj.test" + x + "()")
next
? :done
