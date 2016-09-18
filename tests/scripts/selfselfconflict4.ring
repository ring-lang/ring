New Account {
	see aFriends
}

Class Account
	name = "Mahmoud"
	aFriends = []
	aFriends + new Friend { 
		setname("Gal")
	}
	aFriends + new Friend { 
		setname("Bert")
	}
	
Class Friend
	name
	func setname cName
		name = cName