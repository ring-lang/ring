# The Ring Standard Library
# Trace Library
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>

load "tracelib.ring"

# Trace All Events

ringvm_settrace("mytrace()")

see "Hello, world!" + nl
see "Welcome" + nl
see "How are you?" +nl
mytest()
new myclass { mymethod() }

func mytest
	see "Message from mytest" + nl

func mytrace
	see "====== The Trace function is Active ======" + nl +
	    "Trace Function Name : " + ringvm_TraceFunc() + nl +
	    "Trace Event : " 
	switch ringvm_TraceEvent()
		on TRACEEVENT_NEWLINE 		see "New Line" 
		on TRACEEVENT_NEWFUNC		see "New Function"
		on TRACEEVENT_RETURN		see "Return"
		on TRACEEVENT_ERROR		see "Error"
		on TRACEEVENT_BEFORECFUNC	see "Before C Function"
		on TRACEEVENT_AFTERCFUNC	see "After C Function"
	off
	see nl +
		"Line Number : " + ringvm_tracedata()[TRACEDATA_LINENUMBER] + nl +
		"File Name   : " + ringvm_tracedata()[TRACEDATA_FILENAME] + nl +
		"Function Name : " + ringvm_tracedata()[TRACEDATA_FUNCNAME] + nl +
		"Method or Function : " 
		if ringvm_tracedata()[TRACEDATA_METHODORFUNC] = TRACEDATA_METHODORFUNC_METHOD
			see "Method"
		else
			if ringvm_tracedata()[TRACEDATA_FUNCNAME] = NULL
				see "Command"
			else
				see "Function"
			ok
		ok		
		see nl + Copy("=",42) + nl

class myclass
	func mymethod
		see "Message from mymethod" + nl
