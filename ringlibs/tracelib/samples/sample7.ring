# The Ring Standard Library
# Trace Library
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>

# Disable BreakPoint

load "tracelib.ring"
NoBreakPoints()

test1()

func test1
	x = 10
	see :test1 + nl
	t = 12
	BreakPoint()
	see "After breakpoint!" +nl
	see "t = " + t + nl
	see "End of program!" + nl
	
