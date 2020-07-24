
func main
	my1 = getHello("Ahmed")
	my2 = getHello("Mahmoud")
	see my1 + nl
	see my2 + nl
	nums1 = [8,9,6,5,4,2,3,1,88,99]
	nums2 = [44,52,66,33,5,4,1]
	n1 = getSum(nums1)
	n2 = getSum(nums2)
	see n1 + nl
	see n2 + nl
	see (n1+n2) + nl
	see (n1*n2) +nl
	
	see isGreat100(50) + nl
	see isGreat100(100) + nl
	see isGreat100(101) + nl
	if isGreat100(150)
		see "Yes" + nl
	else
		see "No" + nl
	ok
end


func getHello(name)
	hello = "Hello " + name
	return hello
end

func getSum(numbers)
	sum = 0
	for x=1 to len(numbers)
		sum += numbers[x]
	next
	return sum
end

func isGreat100(num)
	if num>100
		return true
	else
		return false
	ok
end


