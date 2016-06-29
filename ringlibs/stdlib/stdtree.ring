# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

if filename() = sysargv[2]
	eval("Load 'stdfunctions.ring'")
	eval("Load 'stdbase.ring'")
	tree_class_test()
ok

func tree_class_test
	
	otree = new tree
	See "Test the tree Class Methods" + nl
	otree { 

	}

Class tree 
 
	data parent
	children = []

	func set x
		data = x

	func value
		return data

	func add
		children + new tree
		children[len(children)].parent = object2pointer(self)

	func parent
		if parent = null
			raise("This node is the root!")
			return
		ok
		return pointer2object(parent)

	
