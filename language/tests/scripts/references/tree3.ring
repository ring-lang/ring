#========================================================================================#
# This test program store a reference in the parent attribute 
# Instead of storing a pointer 
# I.e. we uses 
#	children[len(children)].parent = pointer2object(object2pointer(self))
# Instead of using
#	children[len(children)].parent = object2pointer(self)
# This will lead to a challenge in this line
# 	mynode = oTree.children[2].children[3].children[3]
# Because Ring must discover that the latest children[3] 
# contains the parent attribute - A reference to it's parent
# And the parent contains the the child 
# So the Assignment instruction must copy by reference to avoid infinite loop
# We already did this in this commit
# URL: https://github.com/ring-lang/ring/commit/b8e17532c5b8143d4cd02e78b1b046aeb80532db
#========================================================================================#

tree_class_test()

func tree_class_test

	See "Test the tree Class Methods" + nl
	otree = new tree  {
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
	see copy("*",60) + nl
	oTree.print()

	see copy("*",60) + nl
	? oTree.children[2].children[3].children[3].value()
	? oTree.children[2].children[3].children[3].parent().value()
	? oTree.children[2].children[3].children[3].parent().parent().value()
	? oTree.children[2].children[3].children[3].parent().parent().parent().value()

	? oTree.children[2].children[3].children[3]
	? oTree.children[2].children[3].children[3].data
	? oTree.children[2].children[3].children[3].children
	? type(oTree.children[2].children[3].children[3].parent)

	mynode = oTree.children[2].children[3].children[3]

	? mynode.value()
	mynode.parent() { ? data }

	? mynode.settheparent()
	mynode.parent() { ? data }

	mynode.parent {data= "Let's modify the value!"}
	mynode.parent() { ? data }

	mynode.parent {data= "Using references is fun!"}
	mynode.printtheparent()

	mynode.parent().set("It's easy to modify the value")
	? mynode.parent().value()
	? mynode.parent().parent().value()
	mynode.parent().parent().parent().set("I was the first step")
	? mynode.parent().parent().parent().value()
	oTheFirstStep = mynode.parent().parent().parent()
	oTheFirstStep.set("I am still the first step!")
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
		children[len(children)].parent = pointer2object(object2pointer(self))
		children[len(children)].data = x
		return children[len(children)]


	func parent
		if isnull(parent)
			raise("This node is the root!")
			return
		ok
		return  parent

	func settheparent
		parent { data = "Another value!" }
	
	func printtheparent
		? parent.value()

	func print
		if isnull(parent)
			? data 
		ok
		for x in children
			? x.data 
			x.print()
		next