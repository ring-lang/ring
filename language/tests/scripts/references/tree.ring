tree_class_test()

func tree_class_test

	otree = new tree
	See "Test the tree Class Methods" + nl
	otree {
		set("The first step")	# set the root node value
		Add("one")
		Add("two")
		Add("three") {
			Add("3.1")
			Add("3.2")
			Add("3.3")
		}
		oTree.children[2] {
			Add("2.1") Add("2.2") Add("2.3") {
				Add("2.3.1") Add("2.3.2") Add("test")
			}
		}
		oTree.children[2].children[3].children[3].set("2.3.3")
	}

	? copy("*",60) 
	oTree.print()

	? copy("*",60) 

	# mynode is a copy from the node object (Not a reference)
	mynode = oTree.children[2].children[3].children[3]
	? mynode.value()
	mynode.parent() { ? data }

	? mynode.settheparent()
	mynode.parent() { ? data }

	Pointer2Object(mynode.parent) {data= "Let's modify the value!"}
	mynode.parent() { ? data }

	Pointer2Object(mynode.parent) {data= "Using Pointer2Object() is fun!"}
	mynode.printtheparent()

	mynode.parent().set("It's easy to modify the value")
	? mynode.parent().value()
	? mynode.parent().parent().value()
	mynode.parent().parent().parent().set("I was the first step")
	? mynode.parent().parent().parent().value()
	oTheFirstStep = mynode.parent().parent().parent()
	oTheFirstStep.set("I am still the first step!")
	? mynode.parent().parent().parent().value()
	oFirstStepCopy = oTheFirstStep
	oFirstStepCopy.set("We can copy the first step by reference")
	? mynode.parent().parent().parent().value()
	? "Delete the reference (This doesn't delete the real object)"
	oTheFirstStep = NULL
	oFirstStepCopy.set("I am still the first step!")
	? mynode.parent().parent().parent().value()

Class tree

	data parent

	children = []

	func set x
		data = x

	func value
		return data

	func add x
		children + new tree
		children[len(children)].parent = object2pointer(self)
		children[len(children)].data = x
		return children[len(children)]

	func parent
		if parent = "NULL"
			raise("This node is the root!")
			return
		ok
		return  pointer2object(parent)

	func settheparent
		pointer2object(parent) { data = "Another value!" }
	
	func printtheparent
		? pointer2object(parent).value()

	func print

		if parent = "NULL"
			? data 
		ok
		for x in children
			? x.data 
			x.print()
		next