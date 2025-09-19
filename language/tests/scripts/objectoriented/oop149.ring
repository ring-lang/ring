o1 = new Point 

? o1

? "Increment x by 20"
o1.x += 20

? "x = " + o1.x

? "Decrement x by 20"
o1.x -= 20

? "x = " + o1.x

? "Multiply x by 2"
o1.x *= 2

? "x = " + o1.x

? "Divide x by 2"
o1.x /= 2

? "x = " + o1.x

? "Remainder o1.x %= 4000000"
o1.x %= 4000000

? "x = " + o1.x

? "Power Operator ( x ** 2)"
o1.x **= 2

? "x = " + o1.x

? "Shift-Left"
o1.x <<= 2

? "x = " + o1.x

? "Shift-Right"
o1.x >>= 2

? "x = " + o1.x

? "BitAnd o1.x &= 2250032250000"
o1.x &= 2250032250000 

? "x = " + o1.x

? "BitOr o1.x |= 1"
o1.x |= 1

? "x = " + o1.x

? "BitXor o1.x ^= 2250034250001"
o1.x ^= 2250034250001

? "x = " + o1.x

class Point

	x=10 y=10 z=10

	func getx
		? "Getter (value + 1000000)"
		return x + 1000_000

	func setx value
		? "Setter"
		? "value = " + value
		x = value

