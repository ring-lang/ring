clear
* Start the clock
t1 = SECONDS()

* Call the Fibonacci function
? Fibonacci(1200)

* Stop the clock
t2 = SECONDS()

* Display the time taken
? t2 - t1

FUNCTION Fibonacci(n)
    IF n = 0
        RETURN 0
    ENDIF
    IF n = 1
        RETURN 1
    ENDIF
    
    * Create an array to store Fibonacci results
    DECLARE aFibRes[2]
    aFibRes[1] = 0
    aFibRes[2] = 1

    IF n > 1
        FOR t = 2 TO n
            * Redimension the array to include the next Fibonacci number
            DIMENSION aFibRes[t + 1]
            aFibRes[t + 1] = aFibRes[t] + aFibRes[t - 1]
        ENDFOR
        RETURN aFibRes[n + 1]
    ENDIF
ENDFUNC
