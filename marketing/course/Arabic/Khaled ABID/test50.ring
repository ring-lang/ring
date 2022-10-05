/*
	Application	: Course of Essentials (Functions)
	Author		: Khaled ABID
	Date		: 22/01/2018
*/

func main

	while true
		see "
	
			(1) Hello
			(2) Exit
	
	
		" give nOption
	
		switch nOption
		on "1" hello()
		on "2" closeapplication()
		other ? "Bad Option!"
		off
	end

	? "Thanks!"

func Hello
	? "Enter your name: " give cName ? "Hello, " + cName
func closeapplication
	exit 		# we can exit from the loop
