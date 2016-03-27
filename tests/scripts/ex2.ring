func main

	lower = 0
	upper = 300
	step = 20

	fahr = lower
	while fahr <= upper
		celsius = 5 * (fahr-32) / 9
		see "" + fahr + "    " + celsius + nl
		fahr = fahr + step
	end