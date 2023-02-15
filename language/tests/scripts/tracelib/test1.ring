load "tracelib.ring"

# Trace All Events
trace(:AllEvents)

see "Hello, world!" + nl
see "Welcome" + nl
see "How are you?" +nl

mytest()

new myclass { mymethod() }

func mytest
	see "Message from mytest" + nl

class myclass
	func mymethod
		see "Message from mymethod" + nl
