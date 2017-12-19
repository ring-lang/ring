# The Ring Standard Library
# Trace Library
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>

load "tracelib.ring"

# Interactive Debugger
Trace(:Debugger)

test1()
see "good bye!" + nl

func test1
	x = 10
	see :test1 + nl
	t = 12
	test2()	# Runtime Error!
	see "After Error!" +nl
	see "t = " see t see nl
	see "x = " see x see nl
