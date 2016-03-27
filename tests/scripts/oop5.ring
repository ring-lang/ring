o1 = new myclass
see o1.prop4[1] + nl
see o1.prop4[2].prop1 + nl
see o1.prop4[2].prop8 + nl
see o1.prop4[2].prop9[2] + nl
see o1.prop4[2].prop9[2][4] + nl
see o1.prop3[2].prop3 + nl

func test

	see o1.prop1 + nl
	see o1.prop2.prop1 + nl
	see o1.prop3
	see o1.prop2.prop2
	see "mix : " + o1.prop3[3] + " " + o1.prop2.prop2[3] + nl

class myclass
	prop1 = "one"
	prop2 = new myclass2
	prop3 = ["one","two","three"]
	prop4 = ["one",new myclass2] 
	prop3[2] = new myclass2

class myclass2
	prop1 = "nice"
	prop2 = 3
	prop3 = "good"
	prop4 = 6
	prop7 = 12
	prop8 = " mahmoud fayed "
	prop9 = ["four","five","six",1,2,3,4,5,6,7]