(new animal).talk()		# Animal1
(new animal()).talk()		# Animal1

(new animal) {talk()}		# Animal1
(new animal()) {talk()}		# Animal1

# To use init() output we need the dot/braces after () directly
new animal().talk()		# Animal2
new animal() { talk() }		# Animal2

class animal

	func init
		return new animal2

	func talk
		? "Animal1"

class animal2

	x y z

	func talk
		? "Animal2"