// In Ring (To, From & In) are Keywords
// But we can use them as identifiers/attributes
// This is useful for defining DSLs & Natural Commands
// This is possible because these keywords are used in the middle of instructions
// i.e. (for loop, class definition, etc.)

? :start

new mytest {
	to
	from
	in
}

? :done

class mytest

	to   from   in

	func getTo
		? "getTo()"

	func getFrom
		? "getFrom()"

	func getIn
		? "getIn()"