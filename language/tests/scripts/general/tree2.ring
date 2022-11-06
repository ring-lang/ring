oReference = null

func main

	for t=1 to 10
		tree_class_test(t)
		? copy("*",60) 
		? "The Tree is deleted"
		? "We have a reference to the first node!"
		? oReference.value()
	next

func tree_class_test nIndex

	otree = new tree {
		set("The first step - " + nIndex)	# set the root node value
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

	oReference = oTree.children[2].children[3].children[3].parent().parent().parent()

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