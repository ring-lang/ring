constants = new constants

? constants.pi

constants {
	? pi
	pi = 3.2	# error
}

class constants

	Pi = 3.142

	func setpi value
		raise("Can't change a constant")