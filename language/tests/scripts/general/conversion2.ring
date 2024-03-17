Try
	? number("abc")			# Error
Catch
	? cCatchError
Done
? 12500 = "abc"				# 0

? 12500 + "0012500"			# 25000
Try
	? 12500 + "0012500-PRY-09"	# Error
Catch
	? cCatchError
Done

? 12500 = "0012500-PRY-09" 		# 0
? "0012500-PRY-09" = 12500		# 0

? 12500 != "0012500-PRY-09" 		# 1
? "0012500-PRY-09" != 12500		# 1

Try
	? number("0012500-PRY-09")	# Error
Catch
	? cCatchError
Done
? number("0012500")			# 12500
aList = [1,2,3]
aList2 = ref(aList)
aList3 = [1,2,3]

? objectid(aList)  = objectid(aList2)	# 1
? objectid(aList2) = objectid(aList3)	# 0

? 1 = "1.02"				# 0
? 1 = 1.002				# 0

? 1 = number("1.02")			# 0
? 1 = number("1.002")			# 0

? 12 = "12.001"				# 0

? 0 = "abc"				# 0
? "abc" = 0				# 0
? "12abc" = 0				# 0
? "12abc" = 12				# 0
? 12 = "12abc"				# 0

? objectid(aList)  != objectid(aList2)	# 0
? objectid(aList2) != objectid(aList3)	# 1

? 1 != "1.02"				# 1
? 1 != 1.002				# 1

? 1 != number("1.02")			# 1
? 1 != number("1.002")			# 1

? 12 != "12.001"			# 1

? 0 != "abc"				# 1
? "abc" != 0				# 1
? "12abc" != 0				# 1
? "12abc" != 12				# 1
? 12 != "12abc"				# 1