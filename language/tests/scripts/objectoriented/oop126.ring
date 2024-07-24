aList = [1,2]

? aList[1]
aList[1]++
? aList[1]

o = new point { x=10 y=20 z=30 }
? o.x
o.x++
? o.x


try
	myStr = "10"
	? myStr
	myStr++
	? myStr
catch
	? cCatchError
done

try
	myList = [1,2,3]
	myList++
catch
	? cCatchError
done

o = new myClass
o.Value++
? o.Value

o = new myClass2
o.Value++
? o.Value

? copy("*",50)


aList = [1,2]

? aList[1]
aList[1]--
? aList[1]

o = new point { x=10 y=20 z=30 }
? o.x
o.x--
? o.x


try
	myStr = "10"
	? myStr
	myStr--
	? myStr
catch
	? cCatchError
done

try
	myList = [1,2,3]
	myList--
catch
	? cCatchError
done

o = new myClass
o.Value--
? o.Value

o = new myClass2
o.Value--
? o.Value


class point x y z

class myClass 
	value=100
	func getValue 
		? "Getter"
		return value

class myClass2 
	value=1000
	func getValue 
		? "Getter"
		return value
	func setValue vValue
		? "Setter"
		value = vValue
	