? "Before Test()"
myobj = test("test")
? "After Test()"
? myobj
? :done

func test cComponentName
	? "Before Eval()"
	eval("oObject = new " + cComponentName+:ComponentController ) 	
	? "After Eval()"
	? oObject
	return oObject

class testComponentController
	x=10 y=20 z=30