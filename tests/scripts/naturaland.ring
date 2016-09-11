ChangeRingKeyword	and  _and

New App
{
        I want window and the window title = "hello world"
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
                the=0  and=0

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

	func getand
		see "Using : and" + nl