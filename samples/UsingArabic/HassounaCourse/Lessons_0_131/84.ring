
func main

	str1 = ["Ahmed", "Amr", "Adel", "Ehab"]
	str2 = [5,8,9,6,"Ahmed",5,8,7,9]
	str3 = ["A", "B", 8, "D", "E", "F"]
	str4 = [88, "B", "C", "D", "E", "F"]
	str5 = ["A", "B", "C", "D", "E", 99]
	str6 = ["A", "B", 'C', "D", "E", "F"]
	see isStringList(str1) + nl
	see isStringList(str2) + nl
	see isStringList(str3) + nl
	see isStringList(str4) + nl
	see isStringList(str5) + nl
	see isStringList(str6) + nl


	/*
	nums1 = [1,5,2,33,66,9,8,7,4]
	nums2 = [5,2,33,6,8,9,"3",4,"A",8,8]
	nums3 = ["5",5,2,3,6,5]
	nums4 = [5,2,6,3,5,8,"w"]
	nums5 = [5,6,9,8,7,"4",5,6,8,7,4,9]
	nums6 = [8,7,9,6,4,true,5,2,false,5,6]
	see isNumberList(nums1) + nl
	see isNumberList(nums2) + nl
	see isNumberList(nums3) + nl
	see isNumberList(nums4) + nl
	see isNumberList(nums5) + nl
	see isNumberList(nums6) + nl
	*/
end


func isNumberList(numberList)
	for x=1 to len(numberList)
		if Type( numberList[x] ) != "NUMBER"
			return false
		ok
	next
	return true
end

func isStringList(stringList)
	for x=1 to len(stringList)
		if Type( stringList[x] ) != "STRING"
			return false
		ok
	next
	return true
end

