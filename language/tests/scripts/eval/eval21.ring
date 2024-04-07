# Test using Eval() to define a function while being in the class region
o = new point {x=10 y=20 z=30}
? :msg2
? functions()
? o
? :msg3
test()
? :done

class point
	eval("func test ? :test for t=1 to 5 ? t next")
	? :msg1
	x y z
