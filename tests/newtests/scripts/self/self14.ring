New Account {
	name = "mahmoud"
	friend {
		name = "Gal"
	}
	friend {
		name = "bert"
	}
	see aFriends
}

Class Account
	name 
	aFriends = []
	friend
	func getfriend
		aFriends + new Friend
		return aFriends[len(aFriends)]
	
Class Friend
	name
