
printData( [ :name=null , :address=null ] )
printData( [ :name="Amr" , :address="Giza" ] )
printData( [ :name="Ali" , :address=null ] )
printData( [ :name=null , :address="Alex" ] )

func printData(allP)
	vName = "Name"
	vAddress = "Address"
	if allP[:name] != null
		vName = allP[:name]
	ok
	if allP[:address] != null
		vAddress = allP[:address]
	ok
	see vName + " , " + vAddress + nl
end
