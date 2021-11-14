# Project: NASA - Fibonacci
# Date   : 2018/07/06
# Author : Bert Mariani


Load "stdlib.ring"

startNbr = 5
endNbr   = 35
incNbr   = 5

Puts("Test ITERATIVE Fibonacci(), N=25, 35, 45 ")
Puts("")

for n = startNbr to endNbr step incNbr
        result = 0
        A = 0
        B = 1
    startTime = clock()

        for i = 2 to n
           result = A + B
           A = B
           B = result
        next

    endTime   = clock()
    diffTime  = endTime - startTime
    See "Fibonacci "+ n +": " + result +" Time-msec: "+ diffTime +nl
next

See nl +"=== Finished Iterative ===" +nl+nl

###------------------------------------------------

Puts("Test RECURSIVE FUNC Fibonacci(), N=25, 35, 45 ")
Puts("")

for n = startNbr to endNbr step incNbr
    result = 0
    startTime = clock()

    result    = FibR(n)

    endTime   = clock()
    diffTime  = endTime - startTime
    See "Fibonacci "+ n +": " + result +" Time-msec: "+ diffTime +nl

next

See nl +"=== Finished Recursive ===" +nl+nl

###------------------------------------------------

Puts("Test RECURSIVE BUILTIN Fibonacci(), N=25, 35, 45 ")
Puts("")

for n = startNbr to endNbr step incNbr
    result = 0
    startTime = clock()

    result    = Fibonacci(n)

    endTime   = clock()
    diffTime  = endTime - startTime
    See "Fibonacci "+ n +": " + result +" Time-msec: "+ diffTime +nl

next

See nl +"=== Finished Recursive ===" +nl+nl

###-------------------------------------------------------
### Func FibR(p) Fibonacci Recursive call. p = iterations

Func FibR(p)
	if ( p <= 2 )
		return (1)
	else
		return ( FibR(p-2) + FibR(p-1))
	ok
return

###============================================
### OUTPUT - Celeron N2840 @ 2.18 Ghz  4.00 GB
#
# Test ITERATIVE Fibonacci(), N=25, 35, 45
#
# Fibonacci 5: 5 Time-msec: 0
# Fibonacci 10: 55 Time-msec: 0
# Fibonacci 15: 610 Time-msec: 0
# Fibonacci 20: 6765 Time-msec: 0
# Fibonacci 25: 75025 Time-msec: 0
# Fibonacci 30: 832040 Time-msec: 0
# Fibonacci 35: 9227465 Time-msec: 0
# Fibonacci 40: 102334155 Time-msec: 0
# Fibonacci 45: 1134903170 Time-msec: 0
#
#  === Finished Iterative ===
#
# Test RECURSIVE Fibonacci(), N=25, 35, 45
#
# Fibonacci 5: 5 Time-msec: 0
# Fibonacci 10: 55 Time-msec: 2
# Fibonacci 15: 610 Time-msec: 30
# Fibonacci 20: 6765 Time-msec: 403
# Fibonacci 25: 75025 Time-msec: 3585
###
