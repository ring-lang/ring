line()
o = new point { ? :h0 test() ? :h1 ? self ? :h2 }
line()
o = new point { ? :h0 eval("y=20") ? :h1 ? self ? :h2 }
line()
o = new point { ? :h0 eval("z=30") ? :h1 ? self ? :h2 }
line()

func line ? copy("*",70)

class point 

	x y z

	func braceStart
		? :start

	func test

		eval("x=10")

	func setz v
		? :Setter
		z = v
		? :done
	
	func braceExprEval v
		? :braceexpreval
		? type(v)
		? "value: " + v
		if v=self
			? :yes
		ok

	func braceEnd
		? :end