# Function - Scope - Pass By Reference - Pass By Value
# ----------- Scope -------------

y = 20                        //Global Scope
# Main Function
func main                     //Code Begins Here
	x = 10                //Local Scope
	? "Hello, World"
	test()
	test2() //Cause An Error (Local Variable)

func test
	? y

func test2
	? x
