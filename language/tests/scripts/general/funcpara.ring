aFuncs = ringvm_functionslist()
aCode  = ringvm_codelist()

for aFunc in aFuncs
	nID  = aFunc[2]
	aIns = aCode[nId]
	if aIns[2]
		cPara = substr(aIns[2]," ",",")
	else 
		cPara = ""
	ok
	? aFunc[1] + "(" + cPara  + ")"
next

func test

func test1 p1

func test2 p1,p2

func test3 p1,p2,p3

func test4 p1,p2,p3,p4

func test5 p1,p2,p3,p4,p5