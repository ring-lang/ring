func main

	# The example
	nDay = 7
	switch nDay
	on 6, 7
		? "work"
	other
		? "vacation"
	off

	line()
	? "Numbers"
	line()

	for nDay = 1 to 7
		see "" + nDay + " "
		switch nDay
		on 1, 2, 3, 4, 5
			? "work"
		on 6, 7
			? "vacation"
		off
	next

	line()
	? "Strings, CASE and ENDSWITCH"
	line()

	for cColor in ["red", "green", "Green", "blue", "black", "white"]
		see cColor + " "
		switch cColor
		case "red", "green", "blue"
			? "primary"
		case "black", "white"
			? "neutral"
		else
			? "other"
		endswitch
	next

	line()
	? "A single value"
	line()

	x = 3
	switch x
	on 3 ? "three"
	on 4 ? "four"
	off

	line()
	? "Values are checked in order, and stop at the first match"
	line()

	switch 2
	on f(1), f(2), f(3)
		? "matched"
	off

	line()
	? "Expressions, variables and a new line after a comma"
	line()

	nA = 10 nB = 20
	for n in [10, 20, 30, 31, 40]
		see "" + n + " "
		switch n
		on nA, nB,
		   nA + nB
			? "a, b or a+b"
		on 31 ? "31"
		other
			? "none"
		off
	next

	line()
	? "The same value twice, and a value that only matches later"
	line()

	switch 5
	on 1, 5, 5
		? "first on"
	on 5
		? "second on"
	off

	line()
	? "No match and no other"
	line()

	switch 100
	on 1, 2
		? "wrong"
	off
	? "nothing printed"

	line()
	? "Nested switch"
	line()

	for x = 1 to 3
		for y = 1 to 2
			switch x
			on 1, 3
				switch y
				on 1, 2
					? "x=" + x + " y=" + y + ": x is 1 or 3"
				off
			other
				? "x=" + x + " y=" + y + ": x is 2"
			off
		next
	next

	line()
	? "Inside a function, with return"
	line()

	for n = 1 to 4
		? "" + n + " " + kind(n)
	next

	line()
	? "Exit and loop inside the ON"
	line()

	for n = 1 to 10
		switch n
		on 2, 4
			loop
		on 6, 7
			exit
		off
		see "" + n + " "
	next
	? ""

	line()
	? "Inside braces"
	line()

	o = new Point { x = 2 }
	o {
		switch x
		on 1, 2
			? "x is 1 or 2"
		off
	}

	line()
	? "eval()"
	line()

	eval('switch 9 on 8, 9 ? "eval: 8 or 9" off')

	line()
	? "A list of values"
	line()

	aList = [1, 2]
	switch 2
	on aList[1], aList[2]
		? "from the list"
	off

	? "done"

func line
	
	? copy("=",70)

func f n

	? "check " + n
	return n

func kind n

	switch n
	on 1, 3
		return "odd"
	on 2, 4
		return "even"
	off
	return "?"

class Point
	x = 0
