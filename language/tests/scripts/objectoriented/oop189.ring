new point(new MyClass { a b c a=100 a} ) { ? self }

class point x=10 y=20 z=30

	func init (vValue)
		? "Welcome to init()"
		return self


class MyClass

	a=100 b=200 c=300

	func getA

		? "A getter()"
		? a

	func getb

		? "B getter()"
		? b

	func getc

		? "C getter()"
		? c

	func setA vValue

		? "A Setter"
		a = vValue
		