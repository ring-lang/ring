? ref(test()) {
	x=10 y=20 z=30 
	? self
	for t=1 to 10
	next
	? self
}

func test
	return new myclass

class myclass
	x y z