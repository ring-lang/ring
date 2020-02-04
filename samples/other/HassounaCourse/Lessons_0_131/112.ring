
printData1()
printData2(111)
printData3(222, "Ahmed")
printData4(333, "Amr", "Giza")

func printData1(){
	see "id , name , address" + nl
}

func printData2(id){
	see "" + id + " , name , address" + nl
}

func printData3(id, name){
	see "" + id + " , " + name + nl
}

func printData4(id, name , address){
	see "" + id + " , " + name + " , " + address + nl
}

