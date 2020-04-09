NEW CC{
COUNT
}


CLASS   CC
	COUNT
	NCOUNTCMD=0
	NSTART=0
	FUNC GETCOUNT
		IF NCOUNTCMD=0	
			NCOUNTCMD=1
		OK


	FUNC BRACeexpreval VALUE
		IF NCOUNTCMD=1 AND ISNUMber(VALUE)
			NSTART =VALUE 
			NCOUNTCMD++
		OK


new program {
	1 2 3
	4 5 6 
}

class program 
	alist =[]
	func Braceexpreval  value 
	if isnumber(value)
		alist + value 
	ok
	  
	

	func Braceend 
		nsum=0
		for nNumber in  alist 
		nsum += nNumber 
		next
		? "sum : " + nsum	




new counter{
count 3 5
}
class counter

	count 
	ncountcmd=0
nstart=0
	func getcount 

		if ncountcmd=0
		ncountcmd++
	ok


func Braceexpreval  value 
	if ncountcmd=1 and isnumber(value)
nstart = value
ncountcmd++
	ok
