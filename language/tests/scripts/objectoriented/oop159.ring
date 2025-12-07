# Mix usage of (to, from & in) as attributes & keywords

? :start

new mytest {
	to
	from
	in

	for t=1 to 10 ? t next
	? copy("*",20)
	test()
}

? :done

class mytest

	to   from   in

	func getTo
		? "getTo()"

	func getFrom
		? "getFrom()"

	func getIn
		? "getIn()"

	func test

		for x=1 to 10 ? x next
		? copy("*",20)
		for m in 20:25 ? m next
		? copy("*",20)
		eval("class point from parent { x=10 y=20 z=30 }")
		? new point
		? copy("*",20)

class parent 
	type = "3D"

