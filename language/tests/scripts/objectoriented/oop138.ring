aList = [ new myclass ]

aList[1] += "test1"
aList[1] -= "test2"
aList[1] *= "test3"
aList[1] /= "test4"
aList[1] %= "test5"
aList[1] <<= "test6"
aList[1] >>= "test7"
aList[1] &= "test8"
aList[1] |= "test9"
aList[1] ^= "test10"
aList[1] **= "test11"


v = aList[1] = "test12"
aList[1] != "test13"
aList[1] <= "test14"
aList[1] >= "test15"

class myclass

	func operator cop,vvalue
		? "oo"
		? cop
		? vvalue