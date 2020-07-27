? "
	select the operation 
	1 - sum 
	2 - mul 
" give op

if op = "1" myobject = new sum else myobject = new mul ok

? "Enter numbers : " give numbers 

load "stdlib.ring"
aNumbers = split(numbers," ")
? aNumbers 
myobject {
	for number in aNumbers 
		eval("return "+number)
	next 
}

new myMath {
	sum {
		1	2	3
		4	5	7
		7	8	9
		mul { 
			3 
			4 
		}
	}
	mul {
		2 3 4 5
	}
}

class mymath 

	sum mul

	func getsum 
		return new sum

	func getmul 
		return new mul


class mul from sum
	
	func braceend 
		nSum = 1
		for num in aList 
			nSum *= num 
			? "Number: " + Num
		next 
		? "Mul: " + nSum 


class sum from mymath 

	aList = []

	func braceexpreval x 
		if isnumber(x)
			aList + x
		ok

	func braceend 
		nSum = 0
		for num in aList 
			if isnumber(num)
				nSum += num 
				? "Number: " + Num
			ok
		next 
		? "Sum: " + nSum 
