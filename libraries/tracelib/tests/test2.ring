# The Ring Standard Library
# Trace Library
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>

load "tracelib.ring"

# Trace control flow between functions

ringvm_settrace("mytrace()")
test1()

func test1
	see :test1 + nl
	test2()

func test2
	see :test2 + nl
	see test3() + nl

func test3
	see :test3 + nl
	return "test 3 output" 
	
func mytrace
	switch ringvm_TraceEvent() 
		on TRACEEVENT_NEWFUNC
			see "Open Func : " + 
			ringvm_TraceData()[TRACEDATA_FUNCNAME] + nl
		on TRACEEVENT_RETURN
			see "Return to Func : " + 
			ringvm_TraceData()[TRACEDATA_FUNCNAME] + nl
	off
