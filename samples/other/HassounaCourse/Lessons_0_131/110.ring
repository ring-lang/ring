
printData([])
printData([111])
printData([111,"Amr"])
printData([111,"Amr","Giza"])
printData([111,"Amr","Giza",7000])
printData([111,"Amr","Giza",7000, "Programmer"])
printData([111,null,null,7000])

func printData(allV){
	myStr = ""
	for x=1 to len(allV){
		if allV[x] != null
			myStr += "" + allV[x] + " , "
		ok
	}
	see myStr + nl
}
