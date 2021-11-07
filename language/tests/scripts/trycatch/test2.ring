# This test is based on Ring Code written by Mohammad Hamdy Ghanem in 17/01/2021

AssertError(func(){x = 1/0}, 1, "index < 1")

AnyObject = new AnyClass
AssertError(func(){ AnyObject.AnyMethod() }, 2, "index < 1")

func AssertError(testCode, testNum, whenMsg)
	raisedErr = false
	try
		call testCode()
	catch
		raisedErr = true
	end
	if raisedErr
	  	? "  Test" + testNum + " OK."
	else
		msg = "Must raise error when " + whenMsg
		raise(TestTarget + " Test" + testNum + " failed: " + nl + msg)
	end

Class AnyClass
	
	func AnyMethod
		raise("error")
