func Main

	cProgram = ' I want window and the window title is "hello world" '

	MyLanguage(cProgram)

Func MyLanguage cCode

	# We add to the code the instructions that change keywords and operators 
	# Because Eval() uses a new Compiler Object (the original keywords and operators).
	
	cCode = '
		ChangeRingKeyword	and  _and
		ChangeRingOperator	=    is
	' + cCode

	New App
	{
			eval(cCode)
	}


	Class App

			# Attributes for the instruction I want window
					i want window
					nIwantwindow = 0
			# Attributes for the instruction Window title
			# Here we don't define the window attribute again
					title
					nWindowTitle = 0
			# Keywords to ignore, just give them any value
					the=0  


			ChangeRingKeyword	and  _and
					and=0
			ChangeRingKeyword	_and  and

			func geti
				if nIwantwindow = 0
					nIwantwindow++
				ok

			func getwant
				if nIwantwindow = 1
					nIwantwindow++
				ok

			func getwindow
				if nIwantwindow = 2
					nIwantwindow= 0
					see "Instruction : I want window" + nl
				ok
				if nWindowTitle = 0
					nWindowTitle++
				ok

			func settitle cValue
				if nWindowTitle = 1
					nWindowTitle=0
					see "Instruction : Window Title = " + cValue + nl
				ok

