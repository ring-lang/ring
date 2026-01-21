load "closure.ring"

func main

    inc = increment()

	? isClosure(inc)    # Prints 1

    ? invoke(inc)       # Prints 11
    ? invoke(inc)       # Prints 12

	for m=1 to 1000
		invoke(inc)
	next

	? invoke(inc)

	dec = decrement()
	? invoke(dec)
	? invoke(inc)
	? invoke(dec)

func increment

    x = 10

    return closure([ :x ], func {
      x++
      return x
    })

func decrement

    x = 100

    return closure([ :x ], func {
      x--
      return x
    })
