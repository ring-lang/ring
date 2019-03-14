myapp = new test { start() }

class test

	obj

	func start
		myobj = new test3 {
			this.obj = new test2() {
				? type(this.obj)
				? "wow"
				obj2 = new test4(this.obj) {
				}
			}
			? type(this.obj)
		}

class test2

	func init return self

class test3

class test4

	func init o 
		? type(o)