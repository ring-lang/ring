obj = new test
{
	x++
	? :nice
	x = x+1
	? :good
	self.x++
	? :great
	self.x = self.x+1
	? x
}
x = 0
? x
class test
	x = 0
	func setx v { 
		? :setter
		x = v
	} 
	func getx  { 
		? :getter
		return x
	} 
