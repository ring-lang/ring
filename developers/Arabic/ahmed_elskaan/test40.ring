/*
**	Application Name : Function 6;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-17;		
*/
func main 
	while true
		see "
		(1)hello
		(2)exit
		"
		give nOption
		switch nOption
		on "1" hello()
		on "2" exitapp()
		other ? "bad option"
		off
	end
	? "thanks"
func hello 
	? "enter your name " give name ? "hello " + name
func exitapp 
	exit
	


