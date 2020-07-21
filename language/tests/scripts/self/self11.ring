New Account {
	see aFriends
}

Class Account
	name = "Mahmoud"
	aFriends = []
	aFriends + new Friend
	aFriends[len(aFriends)] { 
		aFriends[len(aFriends)].name = "Gal" 
	}
	aFriends + new Friend 
	aFriends[len(aFriends)] { 
		aFriends[len(aFriends)].name = "Bert" 
	}
	
Class Friend
	name