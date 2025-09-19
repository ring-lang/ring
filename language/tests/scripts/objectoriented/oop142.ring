oObj = new container

oObj.o += 1
oObj.o -= 2
oObj.o *= 3
oObj.o /= 4
oObj.o %= 5
oObj.o <<= 6
oObj.o >>= 7
oObj.o &= 8
oObj.o |= 9
oObj.o ^= 10
oObj.o **= 11
v = oObj.o = 12
oObj.o != 13
oObj.o <= 14
oObj.o >= 15

? copy("=",70)

oObj.o += "test1"
oObj.o -= "test2"
oObj.o *= "test3"
oObj.o /= "test4"
oObj.o %= "test5"
oObj.o <<= "test6"
oObj.o >>= "test7"
oObj.o &= "test8"
oObj.o |= "test9"
oObj.o ^= "test10"
oObj.o **= "test11"
v = oObj.o = "test12"
oObj.o != "test13"
oObj.o <= "test14"
oObj.o >= "test15"

? copy("=",70)

oObj.o += ["test1",2025,:nice]
oObj.o -= ["test2",2025,:nice]
oObj.o *= ["test3",2025,:nice]
oObj.o /= ["test4",2025,:nice]
oObj.o %= ["test5",2025,:nice]
oObj.o <<= ["test6",2025,:nice]
oObj.o >>= ["test7",2025,:nice]
oObj.o &= ["test8",2025,:nice]
oObj.o |= ["test9",2025,:nice]
oObj.o ^= ["test10",2025,:nice]
oObj.o **= ["test11",2025,:nice]
v = oObj.o = ["test12",2025,:nice]
oObj.o != ["test13",2025,:nice]
oObj.o <= ["test14",2025,:nice]
oObj.o >= ["test15",2025,:nice]


class container

	o = new myclass

class myclass

	func operator cop,vvalue
		? "Operator Overloading"
		? cop
		? vvalue
		return self