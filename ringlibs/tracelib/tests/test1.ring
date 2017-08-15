load "tracelib.ring"

ringvm_settrace("mytrace()")

see "hello world" + nl
see "welcome" + nl
see "nice" +nl
mytest()
new myclass { mymethod() }

func mytest
	see "wow from mytest" + nl

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
	    "Method or Function : " + ringvm_tracedata()[TRACEDATA_METHODORFUNC] + nl +
	    Copy("=",42) + nl

class myclass
	func mymethod
		see "wow from mymethod" + nl
