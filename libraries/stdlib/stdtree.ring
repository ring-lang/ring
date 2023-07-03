# The Ring Standard Library
# Common Functions and classes for applications
# 2016-2023, Mahmoud Fayed <msfclipper@yahoo.com>

Load "stdfunctions.ring"
Load "stdbase.ring"
Load "stdlibcore.ring"

if IsMainSourceFile() 
	tree_class_test()
ok

func tree_class_test

	otree = new tree
	? "Test the tree Class Methods" 
	otree {
		set("The first step")	# set the root node value
		see value() + nl
		Add("one")
		Add("two")
		Add("three") {
			Add("3.1")
			Add("3.2")
			Add("3.3")
			see children
		}
		see children
		oTree.children[2] {
			Add("2.1") Add("2.2") Add("2.3") {
				Add("2.3.1") Add("2.3.2") Add("test")
			}
		}
		oTree.children[2].children[3].children[3].set("2.3.3")
	}
	? copy("*",60)
	oTree.print()

Class tree

	data parent
	children = []

	func set x
		data = x

	func value
		return data

	func add x
		children + new tree
		nMax = len(children)
		children[nMax].parent = ref(self)
		children[nMax].data = x
		return children[nMax]

	func parent
		if ! isObject(parent)
			raise("This node is the root!")
			return
		ok
		return parent

	func print
		for x in children
			? x.data
			x.print()
		next
