aList = [ new myclass ]

aList[1] += ["test1",2025,:nice]
aList[1] -= ["test2",2025,:nice]
aList[1] *= ["test3",2025,:nice]
aList[1] /= ["test4",2025,:nice]
aList[1] %= ["test5",2025,:nice]
aList[1] <<= ["test6",2025,:nice]
aList[1] >>= ["test7",2025,:nice]
aList[1] &= ["test8",2025,:nice]
aList[1] |= ["test9",2025,:nice]
aList[1] ^= ["test10",2025,:nice]
aList[1] **= ["test11",2025,:nice]


v = aList[1] = ["test12",2025,:nice]
aList[1] != ["test13",2025,:nice]
aList[1] <= ["test14",2025,:nice]
aList[1] >= ["test15",2025,:nice]

class myclass

	func operator cop,vvalue
		? "oo"
		? cop
		? vvalue