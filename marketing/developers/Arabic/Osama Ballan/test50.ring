/*
**	Application		: Functions .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 07 .
*/

func main
	while True
		see 	"
	(1) Hello
	(2) Exit
	
			"
		give nOption
		switch nOption
		on "1"	Hello()
		on "2"	closeApplication()
		other	? "Bad Option !"
		off
	end
	? "Thanks"

func Hello
	? "Enter Your Name ? " give cName ? "Hello " + cName
func closeApplication
	exit	# We Can Exit From Loop
