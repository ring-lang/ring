// At first we wil use len() defined by Ring as a C function
// Ring VM will replace ICO_LOADFUNC with ICO_LOADFUNCP after execution
// Then using Eval() we define a Ring function that replace the C function
// Here ICO_LOADFUNCP must check for this change and call the Ring function

for t=1 to 2
	? len("test")
	if t=1 eval("func len value ? :wow ") ok
	? len("test")
next

// Here we check a Ring Function Call will be replaced by a Method call

myobj = new myclass
process (myobj)		// will call the Test() function

addmethod(myobj,:test,func { ? :great })

process (myobj)		// will call the Test() Method

func test
	? :test

func process obj
	obj {
		test()
	}

class myclass