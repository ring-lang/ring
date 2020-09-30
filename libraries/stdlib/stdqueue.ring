# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

Load "stdfunctions.ring"
Load "stdbase.ring"
Load "stdlist.ring"
Load "stdlibcore.ring"

if IsMainSourceFile() 
	queue_class_test()
ok

func queue_class_test
	oQueue = new Queue
	oQueue.add(1)
	oQueue.add(2)
	oQueue.add(3)
	see oQueue.remove() + nl
	see oQueue.remove() + nl
	see oQueue.remove() + nl
	oQueue.add(4)
	see oQueue.remove() + nl
	oQueue { add("one") add("two") add("three") }
	oQueue.print()

Class Queue From List

	Func Init x
		if isstring(x) or isnumber(x) or islist(x)
			super.init(x)
		else
			raise("Error: Queue Class - Init Method - Bad Parameter")
		ok

	Func Remove
		item = item(1)
		delete(1)
		return item
