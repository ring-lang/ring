New Account {
	see aFriends
}

Class Account
	name = "Mahmoud"
	aFriends = []
	friend("Gal")
	friend("Bert")

	func friend cName
		aFriends + new Friend { 
			name = cName
		}
	
Class Friend
	name
