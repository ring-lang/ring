# object attribute +=
o1 = new Person {
	incAge(10)
	incAge(5)
}
see o1.nAge + nl
Class Person
	nAge = 0
	func incAge x
		#nAge += x  # works fine
		self.nAge += x  # doesn't work
