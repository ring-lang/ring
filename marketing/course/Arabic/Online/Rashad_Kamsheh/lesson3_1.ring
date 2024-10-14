/*
** Testing commands from lesson 3
** Author Rashad Kamsheh
** Date 2017-12-24
*/

 
? read("lesson3.ring")
# the code used to run this program is:
# ---------------------------------
List = []

While True

	see "
		(1) Add a number
		(2) sum all the number you have added
		(3) Exit 

	" give number
	switch number 
		# prompt the user the add a number to be
		# summed up later	
		on 1 ? "Enter a number" give newNumber 
		List + newNumber
		# sums up all the numbers in the list
		on 2 
		sum=0 for element in List sum += element
		next ? "The sum of your numbers is " + sum 
		# exits the program
		on 3 bye
		other ? "Bad option"
	off
end
# ---------------------------------
