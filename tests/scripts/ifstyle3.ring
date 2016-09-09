	Load "stdlib.ring"

	print(" 
		Main Menu
		---------
		(1) Say Hello
		(2) About
		(3) Exit
	    ")

	nOption = getnumber()

	if nOption = 1	{
		print("Enter your name : ") name = getstring() 	print("Hello #{name}\n")
	elseif nOption = 2 
		print("Sample : using if statement\n")
	elseif nOption = 3 
		bye
	else 
		print("bad option...\n")
	}