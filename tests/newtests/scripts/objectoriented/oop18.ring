cLastName = "Fayed"
x = 1
see "X = " + x + nl

func main

	cFirstName = "Mahmoud"

	cCode = '
	see "Message : " + MyVar + nl
	o1 = new Person  {
		sayhello(cFirstName+" "+cLastname)
		name = "Mahmoud"
		country = "Egypt"
		phone = "123456"
		x = x + 1
		test = x
		job = new Job {
			name = "Programmer"
			salary = "48000"
			x = x + 1
			test = x
			time = new Time {
				months = 6
				Daysperweek = 5
				x = x + 1
				test = x

			}
		}
	}

	see "Before print " + nl
	o1.print()
	' # end of cCode

	MyVar = "Welcome"

	eval(cCode)

	see "After eval " + nl
	see o1
	see o1.job
	see o1.job.time

Class Human
	test
	func sayhello name
		see "Hello " + name + nl

Class Person from Human
	name country phone job
	func print
		see "name : " + name + nl + "Country : " + country + nl + "Phone : " + phone + nl + "Test : " + test + nl

		job.print()

class job
	name salary time test
	func print
		see "Job name : " + name + nl + "Salary : " + salary + nl +
		"Test : " + test + nl
		time.print()

Class Time
	months DaysPerWeek test
	func print
		see "Months : " + months + nl + "Days per week : " + daysperweek + nl +
		"Test : " + test + nl
