func main

	o1 = new a
	o1.text = "one"

	o2 = new b
	o2.text = "two"

	o1.set(o2)
	o2.set(o1)

	see o1.text + nl
	see o2.text + nl
	see o1.obj.text + nl
	see o2.obj.text + nl

	o1.text = "three"
	o2.text = "four"

	see o1.text + nl
	see o2.text + nl
	see o1.obj.text + nl
	see o2.obj.text + nl

Class a
	text
	obj
	func set x
		obj = x

Class b
	text
	obj
	func set x
		obj = x
		