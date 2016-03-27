MyFunc( [:x=10] )
MyFunc( [:x=10 , :z=20] )
MyFunc( [:x=10 , :y=20 , :z=30] )

Func MyFunc aPara
	See "Output:" + nl
	if aPara[:x] != NULL
		see "x Value = " + aPara[:x] + nl
	ok
	if aPara[:y] != NULL
		see "y Value = " + aPara[:y] + nl
	ok
	if aPara[:z] != NULL
		see "z Value = " + aPara[:z] + nl
	ok