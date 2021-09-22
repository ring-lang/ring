obj = new test
{
	x++
	? :nice
	x = x+1
	? :good
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
