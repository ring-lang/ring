o = new myclass

o += ["test1",2025,:nice]
o -= ["test2",2025,:nice]
o *= ["test3",2025,:nice]
o /= ["test4",2025,:nice]
o %= ["test5",2025,:nice]
o <<= ["test6",2025,:nice]
o >>= ["test7",2025,:nice]
o &= ["test8",2025,:nice]
o |= ["test9",2025,:nice]
o ^= ["test10",2025,:nice]
o **= ["test11",2025,:nice]


v = o = ["test12",2025,:nice]
o != ["test13",2025,:nice]
o <= ["test14",2025,:nice]
o >= ["test15",2025,:nice]

class myclass

	func operator cop,vvalue
		? "oo"
		? cop
		? vvalue