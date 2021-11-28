/*
	name	:	Darsh Adam
	Lesson	:	test50.ring
	Date 	:	16/12/2017
*/

#=====================================================
			# Functions
#=====================================================

func main

while true 
	see " 
		(1) Hello
		(2) Exit
	" 
	give input
	switch input
		on "1" hello()
		on "2" Exitapp()
		other ?"bad option"
	off
end 
? "Done" 

func hello 
	? "What is your name ?" give name ? "Hello "+name

func exitapp 
	# bye
	Exit
#========================End Of Lesson====================
