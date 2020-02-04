/*
see "Enter Number:"
give num

switch num

	on 0
		see "Zero"
		see nl
	on 1
		see "One"
		see nl
	on 2
		see "Two"
		see nl
	on 3
		see "Three"
		see nl
	other
		see "Other Number" + nl

off
*/


/*
see "Enter Name Of Number: "
give name

switch name

	on "zero"
		see 0
		see nl
	on "one"
		see 1
		see nl
	on "two"
		see 2
		see nl
	other
		see -1
		see nl

off
*/



/*
see "Enter The Number: "
give num

switch num * 2

	on 2
		see num + " * 2 = " + (num*2)
		see nl
		see "Your Enter One"
	on 4	
		see num + " * 2 = " + (num*2)
		see nl
	on 6
		see num + " * 2 = " + (num*2)
		see nl
		see "Your Enter Three"
	other
		see num + " * 2 = " + (num*2)
		see nl
		
off
*/


see "

		Main Menu
		----------
		(1) Say Hello
		(2) About
		(3) Exit

	                  : "
give nOption
switch nOption

	on 1
		see "Enter Your Name:"
		give name
		see nl + "Hello " + name + nl
	on 2
		see "Using Switch Statement"
		see nl
	on 3
		bye
	other
		see "bad option!"
		see nl

off




