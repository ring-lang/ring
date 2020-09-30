test()

func test
	x = 10
	y = 20
	? "x = " + x + " y = " + y
	swap(:x , :y)
	? "x = " + x + " y = " + y

func swap cVar1,cVar2
	nCurrentScope = ringvm_ScopesCount()
	nTargetScope  = nCurrentScope-1
	ringvm_EvalInScope(nTargetScope,
		"vTemp = " + cVar1 + nl +
		 cVar1 + " = " + cVar2 + nl +
		 cVar2 + " = vTemp"
	)
