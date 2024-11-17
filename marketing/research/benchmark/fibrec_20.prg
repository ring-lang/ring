CLEAR

* Start the clock
t1 = SECONDS()

* Call the Fibonacci function
? fib(20)

* Display the elapsed time
? SECONDS() - t1

FUNCTION fib(n)
    IF n <= 2 THEN
        RETURN 1
    ENDIF
    RETURN fib(n - 1) + fib(n - 2)
ENDFUNC
