New Account {
	see aFriends
}

Class Account
	name = "Mahmoud"
	aFriends = []
	aFriends + new Friend { 
		self.name = "Gal" 
	}
	aFriends + new Friend { 
		self.name = "Bert" 
	}
	
Class Friend
	name
