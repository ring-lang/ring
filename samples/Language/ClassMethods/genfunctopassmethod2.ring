# Example about passing a Method to a Library like WebView that expect a Function!
# Using print2str() and returning the function directly from Eval() using return command

aWebObjects = []

new test { start() }

func Method oObj,cName
	aWebObjects + ref(oObj)
	return eval(print2str(`
		return func (id, req) { aWebObjects[#{len(aWebObjects)}].#{cName}(id,req) }
	`))

class test

	func start

		cFuncName = Method(self,:MyMethod)
		call cFuncName(10,"test")

	func MyMethod id, req
		? "Hello from the Method!"
		? "ID  = " + id
		? "req = " + req 