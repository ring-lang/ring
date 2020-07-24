
printData( [:name="Amr"] )
printData( [:name="Amr" , :address=null] )
printData( [:name=null, :address=null , :salary=70000] )
printData( [:name="Ahmed", :address=null , :salary=null] )
printData( [:name="Ahmed", :address=null , :salary=5000, :job="Programmer"] )

func printData(allP){
	myStr = ""
	for x=1 to len(allP)
		if allP[x][2] != null
			myStr += "" + allP[x][2] + " , "
		else
			myStr += "" + allP[x][1] + " , "
		ok
	next
	see myStr + nl
}
