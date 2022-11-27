aList1 = [1,2,3]
aList2 = 1:3

? aList1 = aList2
? aList1 != aList2

o1 = new myclass
o2 = new myclass

? o1=o2
? o1!=o2

aList1ref = ref(aList1)

? aList1 = aList1ref
? aList1 != aList1ref

o1ref = ref(o1)
? o1 = o1ref
? o1 != o1ref

o3 = new myclass2
? o3 = o1
? o3 != o1

o3ref = ref(o3)
? o3 = o3ref
? o3 != o3ref

class myclass

class myclass2
	func operator cOP,vValue
		? "Using the Operator() Method"
		if cOP = "="
			return obj2Ptr(self) = obj2Ptr(vValue)
		but cOP = "!="		
			return obj2Ptr(self) != obj2Ptr(vValue)
		ok
	
