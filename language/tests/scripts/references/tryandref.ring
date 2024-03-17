Try
	? number("0012500-PRY-09")
Catch
	? cCatchError
Done

? number("0012500")			
aList = [1,2,3]
aList2 = ref(aList)
? aList
? aList2

Try
	ringvm_see( number("0012500-PRY-09") )
Catch
	? cCatchError
Done

? number("0012500")			
aList3 = [1,2,3]
aList4 = ref(aList3)
? aList3
? aList4

Try
	test( test2("0012500-PRY-09") )
Catch
	? cCatchError
Done

? number("0012500")			
aList5 = [1,2,3]
aList6 = ref(aList5)
? aList5
? aList6

Try
	test( read("what") )
Catch
	? cCatchError
Done

? number("0012500")			
aList7 = [1,2,3]
aList8 = ref(aList7)
? aList7
? aList8

func test a1

func test2 c1
	number(c1)