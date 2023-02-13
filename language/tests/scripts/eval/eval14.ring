# Nested Eval() - Three Levels

x=0 y=0 z=0

for t=1 to 10000
	test()
end

? "============"
? "x = " + x
? "y = " + y
? "z = " + z
? "============"

func test
	eval(`
		x++
		eval("
			y += 2
			eval('
				z += 3
			')
	
		")

	`)