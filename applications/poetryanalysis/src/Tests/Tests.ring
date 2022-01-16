TestTarget = ""

func SetTestTarget(targerName)
	TestTarget = targerName
	? "Testing " + targerName + ":"

func AssertEqual(testNum, value1, value2)
	If value1 != value2
		msg = "" + value1 + "' and '" + value2 + "' are not equal!"
		raise(TestTarget + " Test" + testNum + " failed: '" + nl + msg)
	end

	? "  Test" + testNum + " OK."


Func AssertListEquals(testNum, list, str)
	L = len(list)
	sValue = ""
	for i = 1 to L
		svalue += list[i]
	next
	AssertEqual(testNum, sValue, str)


func AssertError(testCode, testNum, whenMsg)
   raisedErr = false
	try
		call testCode() 
	catch
		raisedErr = true
	end

	if raisedErr
	  	? "  Test" + "testNum" + " OK."
	else
      msg = "Must raise error when " + whenMsg
		raise(TestTarget + " Test" + testNum + " faild: " + nl + msg)
	end


func PassedTest()
	? ""
   ? TestTarget + " passed all tests."
	? "---------"
	? ""
