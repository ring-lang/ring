
s1 = new subject {  code=1 name="OR" printData() }

s1{ code=2 name="IS" printData()}
s1{ code=3 name="CS" printData() }
//s1.code = 2
//s1.name = "IS"
//s1.printData()


class subject
	code
	name
	func printData see "Code: " + code + "  ;  Name: " + name + nl
end
