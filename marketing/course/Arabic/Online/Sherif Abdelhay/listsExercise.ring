/*
		Application	: Variables (Lists-Exercise)
		Author		: Sherif Abdelhay
		Date		: 2018.5.27

*/

# Lists ---> Array, List, Nested List, MD Array, Hash|Dict

list = []

while true

	see "
			(1) Add Number
			(2)	Sum Numbers
			(3) Exit
	"

	give option

	switch option
		on "1" 
			see "Enter Numbers: "
			give number
			list + number

		on "2"
			sum = 0
			for num in list
				sum = sum + num
			next
			? "Sum = " + sum

		on "3" shutdown()

		other ? "Bad Option!"
	off	

end
