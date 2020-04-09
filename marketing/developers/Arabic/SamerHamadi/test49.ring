/*
**	Application    : functions 
**	Author 	       : Samer Hammadi
**	Date           : 15/12/2017
*/
#================================================================

func main

	while true
		see "
	
			(1)Hello
			(2)Exit
		"give nOption
	
		switch nOption
			on "1" hello()
			on "2" closeapplication()
			other ? "Bad option"
		end
	end
	? "Thanks!"
func hello 
	? "Enter your name: " give name ? "Hello " + name

func closeapplication
	 exit

	 
