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

class myclass

//	func operator v1,v2
//		? :wow
