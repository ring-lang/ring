# Using (Catch, Done, Other, Else) keywords as identifiers (variables/attributes)

func main

	Catch   = 1
	Done    = 2
	Other   = 3
	Else    = 4
	? Catch
	? Done
	? Other
	? Else
	? copy("*",20)

	Try
		1/0
	Catch
		? "Pass Error!"
	Done	
	? copy("*",20)

	var = 1
	if var=1
		? :one
	elseif var=2
		? :two
	else
		? :three
	ok
	switch var
	on 1 ? :one
	on 2 ? :two
	other ? :three
	off 
	? copy("*",20)

	test()

func test
	new mytest { Catch Done Other Else ? self ? methods(self) }
	? copy("*",20)

class mytest

	Catch Done Other Else

	func getCatch
		? "getCatch()"

	func getDone
		? "getDone()"

	func getOther
		? "getOther()"

	func getElse
		? "getElse()"

