# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

Load "stdfunctions.ring"
Load "stdbase.ring"
Load "stdlist.ring"
Load "stdlibcore.ring"

if IsMainSourceFile() 
	stack_class_test()
ok

func stack_class_test
	oStack = new Stack
	oStack.push(1)
	oStack.push(2)
	oStack.push(3)
	see oStack.pop() + nl
	see oStack.pop() + nl
	see oStack.pop() + nl	
	oStack.push(4)
	see oStack.pop() + nl
	oStack { push("one") push("two") push("three") }
	oStack.print()	

Class Stack From List

	Func Init x
		if isstring(x) or isnumber(x) or islist(x)
			super.init(x)
		else
			raise("Error: Stack Class - Init Method - Bad Parameter")
		ok

	Func Push x
		Add(x)

	Func Pop 
		item = item(size())
		delete(size())
		return item

	Func Print
		for x=len(vValue) to 1 step -1
			see vValue[x] + nl
		next
