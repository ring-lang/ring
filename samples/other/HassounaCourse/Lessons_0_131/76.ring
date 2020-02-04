
func main
	nums = [55,44,77,85,23,69,888,547,125,99,1024,4]
	printSum(nums)
end


func printSum(numbers)
	sum  = 0
	for x=1 to len(numbers)
		sum += numbers[x]
	next
	see sum + nl
end




/*
func main
	myNames = ["Ahmed", "Amr", "Khaled", "Omar", "Adel", "Yasser"]
	sayHello(myNames)
end

func sayHello(names)
	for x=1 to len(names)
		see "Hello " + names[x] + nl
	next
end
*/
