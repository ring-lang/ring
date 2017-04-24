# Natural Code
new program {
	Accept 2 numbers then print the sum
}

# Natural Code Implementation
class program
	# Keywords
		Accept=0 numbers=0 then=0 print=0 the=0 sum=0

	# Execution
	func braceexpreval x
		value = x
	func getnumbers
		for x=1 to value
			see "Enter Number ("+x+") :" give nNumber
			aNumbers + nNumber
		next
	func getsum
		nSUm = 0
		for x in aNumbers nSum+= x next
		see "The Sum : " + nSum
	private
		value=0	aNumbers=[]
	