fFunc = func {
	? x ? y ? z
}

new MyClass


class MyClass

	x=10 y=20 z=30

	? :before
	call { fFunc() }
	? :after