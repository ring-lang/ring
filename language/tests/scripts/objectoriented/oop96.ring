// Here we test (Return this)
// This test program is inspired by SoftanzaLib (Developed by Mansour Ayouni)

o = new myclass
o.one()

class myclass

	func one
		? :one
		two()
		this.three()

	func two
		? :two
		return this
		
	func three 
		? :three