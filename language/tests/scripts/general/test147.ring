? 0 = "0"
? 0 = ""
? 0 = "00000"
? 0 = "0x0"
? 255 = "0xFF"
? 0 = "0xFF"
? 0 = "red"
? Copy("*",10)
? 0 != "0"
? 0 != ""
? 0 != "00000"
? 0 != "0x0"
? 255 != "0xFF"
? 0 != "0xFF"
? 0 != "red"
? Copy("*",10)
aList = list(5)
aList[2] = 255
? aList[1] = "0"
? aList[1] = ""
? aList[1] = "00000"
? aList[1] = "0x0"
? aList[2] = "0xFF"
? aList[1] = "0xFF"
? aList[1] = "red"
? Copy("*",10)
? 1 = "0"
? 1 = ""
? 1 = "00000"
? 1 = "0x0"
? 1 = "0xFF"
? 1 = "0x1"
? 1 = "red"
? Copy("*",10)
? 0 >= "0"
? 0 >= ""
? 0 >= "00000"
? 0 >= "0x0"
? 255 >= "0xFF"
? 0 >= "0xFF"
try
	? 0 >= "red"
catch
	? cCatchError
done
? Copy("*",10)
? 0 <= "0"
? 0 <= ""
? 0 <= "00000"
? 0 <= "0x0"
? 255 <= "0xFF"
? 0 <= "0xFF"
try
	? 0 <= "red"
catch
	? cCatchError
done
? Copy("*",10)