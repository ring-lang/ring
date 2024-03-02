load "stdlibclasses.ring"

new mytest { test() }

class mytest

	func test

		oStack = new stack 
		ostack.push("wow")
		oStack.push("great")

		see oStack.pop()
		see oStack.pop() 

