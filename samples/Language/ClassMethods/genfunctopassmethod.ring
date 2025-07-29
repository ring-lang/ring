# Example about passing a Method to a Library like WebView that expect a Function!

aWebObjects = []

new test { start() }

func Method oObj,cName
	aWebObjects + ref(oObj)
	cCode = `
		cFunc = func (id, req) {
			aWebObjects[#{id}].#{cName}(id,req)
		}
	`
	cCode = substr(cCode,"#{id}",""+len(aWebObjects))
	cCode = substr(cCode,"#{cName}",cName)
	eval(cCode)
	return cFunc

class test

	func start

		cFuncName = Method(self,:MyMethod)
		call cFuncName(10,"test")

	func MyMethod id, req
		? "Hello from the Method!"
		? "ID  = " + id
		? "req = " + req 