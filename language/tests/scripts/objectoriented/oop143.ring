oObj = new container

oObj.aObjs[1] += 1
oObj.aObjs[1] -= 2
oObj.aObjs[1] *= 3
oObj.aObjs[1] /= 4
oObj.aObjs[1] %= 5
oObj.aObjs[1] <<= 6
oObj.aObjs[1] >>= 7
oObj.aObjs[1] &= 8
oObj.aObjs[1] |= 9
oObj.aObjs[1] ^= 10
oObj.aObjs[1] **= 11
v = oObj.aObjs[1] = 12
oObj.aObjs[1] != 13
oObj.aObjs[1] <= 14
oObj.aObjs[1] >= 15

? copy("=",70)

oObj.aObjs[2] += "test1"
oObj.aObjs[2] -= "test2"
oObj.aObjs[2] *= "test3"
oObj.aObjs[2] /= "test4"
oObj.aObjs[2] %= "test5"
oObj.aObjs[2] <<= "test6"
oObj.aObjs[2] >>= "test7"
oObj.aObjs[2] &= "test8"
oObj.aObjs[2] |= "test9"
oObj.aObjs[2] ^= "test10"
oObj.aObjs[2] **= "test11"
v = oObj.aObjs[2] = "test12"
oObj.aObjs[2] != "test13"
oObj.aObjs[2] <= "test14"
oObj.aObjs[2] >= "test15"

? copy("=",70)

oObj.aObjs[3] += ["test1",2025,:nice]
oObj.aObjs[3] -= ["test2",2025,:nice]
oObj.aObjs[3] *= ["test3",2025,:nice]
oObj.aObjs[3] /= ["test4",2025,:nice]
oObj.aObjs[3] %= ["test5",2025,:nice]
oObj.aObjs[3] <<= ["test6",2025,:nice]
oObj.aObjs[3] >>= ["test7",2025,:nice]
oObj.aObjs[3] &= ["test8",2025,:nice]
oObj.aObjs[3] |= ["test9",2025,:nice]
oObj.aObjs[3] ^= ["test10",2025,:nice]
oObj.aObjs[3] **= ["test11",2025,:nice]
v = oObj.aObjs[3] = ["test12",2025,:nice]
oObj.aObjs[3] != ["test13",2025,:nice]
oObj.aObjs[3] <= ["test14",2025,:nice]
oObj.aObjs[3] >= ["test15",2025,:nice]


class container

	aObjs = [new myclass {text=:part1},new myclass {text=:part2},new myclass {text=:part3}]

class myclass

	text 

	func operator cop,vvalue
		? text
		? "Operator Overloading"
		? cop
		? vvalue