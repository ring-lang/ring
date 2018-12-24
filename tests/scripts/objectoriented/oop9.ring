oPhone = new Phone
oPhone.cName = "Mahmoud" oPhone.cCountry = "Egypt" oPhone.cPhone = "123456"
oPhone.print()

func space cStr,nSize

	nMax = nSize-len(cStr)
	for t = 1 to nMax
		cStr = cStr + " "
	next
	return cStr
		
Class Phone

	cName = ""
	cCountry = ""
	cPhone = ""

	func print		
		see space("Name",10) + cName + nl
		see space("Country",10) + cCountry + nl
		see space("Phone",10) + cPhone + nl
	

