# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

if filename() = sysargv[2]
	eval("Load 'stdfunctions.ring'")
	eval("Load 'stdbase.ring'")
	eval("Load 'stdlist.ring'")
	tree_class_test()
ok

func tree_class_test
	
	otree = new tree
	See "Test the tree Class Methods" + nl
	otree { 

	}

Class tree from list
 
