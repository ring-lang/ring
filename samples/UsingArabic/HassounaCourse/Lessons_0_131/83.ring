
func main
	nums1 = [20,30,"40",50,60,70,"Amr"]
	see sum(nums1) + nl
	nums2 = [50,60,80,90,100]
	see avg(nums2) + nl
end

func avg(numbers)
	av = sum(numbers) / len(numbers)
	return av
end

func sum(numbers)
	if type(numbers)="LIST"
		s = 0
		for x=1 to len(numbers)
			if type(numbers[x])!="NUMBER"
				see "Error: Please Use Number Only" + nl
			else
				s += numbers[x]
			ok
		next
		return s
	else
		see "Please Send LIST Only" + nl
	ok
end

