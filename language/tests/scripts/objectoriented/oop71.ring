new points {
	first  { x=10   y=20   z=30   }
	second { x=100  y=200  z=300  }
	third  { x=1000 y=2000 z=3000 }
	print()
}

class points

	aPoints = []

	func braceerror
		aPoints + new point
		return aPoints[len(aPoints)]

	func print
		? aPoints

class point x y z