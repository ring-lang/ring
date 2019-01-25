/*
	Application : functions
	Author      : Salwa Abdrabu
*/

func main
	while true 
		see "
			(1) Hello
			(2) Exit
		"  give nOption

		switch  nOption
		on "1" hello()
		on "2" closeapplication()
		other ? "Bad Option"
		off
	end
		? "Thanks"

func Hello
	see "Enter Your Name :" give Name   ? "Hello " + Name

func closeapplication 
	exit     # We can exit from the loop	
