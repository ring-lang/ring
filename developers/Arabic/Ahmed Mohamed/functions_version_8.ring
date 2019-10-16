/*
	Application	: Functions Version 8
	Author		: Ahmed Mohamed
	Date		: 2019/10/16
*/


func main

	while true
		see "
			(1) Hello
			(2) Exit
		" 
		give nOption
		
		switch nOption
			on "1" hello()
			on "2" closeApplication()
			other ? "Bad Option!"
		off
	end
	

func hello
	? "Enter Your Name" give Name ? "Hello " + name

func closeApplication
	? "Thanks "
	bye
	











