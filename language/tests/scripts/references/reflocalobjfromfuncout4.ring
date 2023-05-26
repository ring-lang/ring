? :start
? ref(test()) {
	x=10 y=20 z=30 
	? self
	test2()
	? self
}
? :end

func test
	return new myclass

func test2
	? :one
	for t=1 to 10
	next
	? :two
	ref(new myclass) {
		? self
		x=100 y=200 z=300
		? self
		for m=1 to 10 next
		? self
	}
	? :three
	for t=1 to 10
	next

class myclass
	x y z