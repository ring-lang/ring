put " 
		Main Menu
		---------
		(1) Say Hello
		(2) About
		(3) Exit

	    " get nOption

	if nOption = 1	put "Enter your name : " get name put "Hello " + name + nl
	elseif nOption = 2 put "Sample : using if statement" + nl
	elseif nOption = 3 bye
	else put "bad option..." + nl
	end