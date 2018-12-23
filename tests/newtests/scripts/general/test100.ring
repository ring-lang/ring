put new person {
	name = 10
	test()
}

put new point {x=10 y=20 z=30 print()}

new calc {
	sum(3,4)
	sum2(5,5)
}

class person
	name
	def test
		put "nice" + nl
	end
end

class point
	x y z
	def print()
		put self
	end
end

class calc
	def sum x,y
		put x+y + nl
	end
	def sum2(x,y)
		put x+y + nl
	end
end