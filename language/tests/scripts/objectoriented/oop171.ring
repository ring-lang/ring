changeRingKeyword main          TheMainFunction
ChangeRingKeyword init          start
changeRingKeyword operator      myoperators
ChangeRingKeyword braceStart    mystart
ChangeRingKeyword braceEnd      myend
ChangeRingKeyword braceError    myerror
ChangeRingKeyword braceExprEval myexpr

func TheMainFunction
	o1 = new test1() {
		100
		1/0
	}
	o1 + "TEST"

	? copy("*",20)

	o2 = new test2() {
		100
		1/0
	}
	o2 + "Test"

class test1
	func init
		? :test1
		return self
	func operator cOp,vValue
		? :test2
		? vValue
	func braceStart
		? :test3
	func braceExprEval value
		? :test4
		? value
	func braceError
		? :test5
	func braceEnd
		? :test6

class test2
	func start
		? :newname_test1
		return self
	func myoperators cOp,vValue
		? :newname_test2
		? vValue
	func myStart
		? :newname_test3
	func myExpr value
		? :newname_test4
		? value
	func myError
		? :newname_test5
	func myEnd
		? :newname_test6