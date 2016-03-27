See " 
		Main Menu
		---------
		(1) Say Hello
		(2) About
		(3) Exit

	    " give nOption

	switch nOption
	on 1 see "Enter your name : " give name see "Hello " + name + nl
	on 2 see "Sample : using switch statement" + nl
	on 3 bye
	other see "bad option..." + nl
	off