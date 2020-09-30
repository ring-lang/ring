# The Ring Standard Library
# Trace Library
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>

load "tracelib.ring"

# Pass Error

ringvm_settrace("mytrace()")

test1()

func test1
	x = 10
	see :test1 + nl
	test2()	# Runtime Error!
	
func mytrace
	switch ringvm_TraceEvent() 
		on  TRACEEVENT_ERROR
			see nl
			see "After error ! " + nl
	off
