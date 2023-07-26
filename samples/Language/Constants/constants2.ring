constants = new constants()

? constants.pi
? constants.count

constants {
	? pi
	? count
}

constants.count = 100 	# ERROR

class constants

	Pi = 3.142
	Count = 10

	func init
		aAttributes = attributes(self)
		for cAttribute in aAttributes 
			AddMethod(self, "set"+cAttribute, 
				func value { raise("Can't change a constant")}
			)
		next 