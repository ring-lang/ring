
e1 = new emp(111, "Omar")
e2 = new emp(222, "Amr")
e3 = new emp{id=333 name="Yasser"}


e1.printData()
e2.printData()
e3.printData()

class emp

	id
	name

	func init(empID , empName)
		id = empID
		name = empName
	end

	func printData
		see "ID:" + id + "  ;  Name:" + name + nl
	end

end

