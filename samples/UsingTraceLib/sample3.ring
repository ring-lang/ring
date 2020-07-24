# The Ring Standard Library
# Trace Library
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>

load "tracelib.ring"

# Pass Error
Trace(:PassError)

test1()

func test1
	x = 10
	see :test1 + nl
	test2()	# Runtime Error!
	see "We can continue!"
