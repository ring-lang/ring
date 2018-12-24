new test {
	crash()
	? self
	? self.aItems
	? self.aItems[1].aItems
}

class test 
	aItems = []	
	func crash 
		aItems + self 
