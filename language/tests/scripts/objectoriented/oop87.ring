? :start
o = new mytest()
? :end
? o.data

class mytest

	data

	func init
		data = "one"
		self.data = "two"
		this.data = "three"
		self {
			data = "four"
		}
		this {	
			data = "five"
		}
		this.data = "six"
		o.data = "seven"

	func setdata v
		data = v + " updated"
		? :Setter