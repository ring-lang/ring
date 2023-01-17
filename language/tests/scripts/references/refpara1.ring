tmp = 1:1000
test(ref(tmp))
? "Check the main value"
? type(tmp)
? refcount(tmp)
? len(tmp)
? tmp[500]

func test x
	? type(x)
	? refcount(x)
	? "Delete one reference"
	x = 0
	? "Check new value"
	? type(x)
	? refcount(x)
	? "Delete again!"
	x = 0
	? type(x)