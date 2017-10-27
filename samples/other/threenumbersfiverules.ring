/*
	Purpose 	: Find 3 Numbers [? ? ?] according to 5 Rules.  
	Author		: Mahmoud Fayed 
	Date		: 2017.10.27
*/

func Main
	drawline()
	see "

	Program  : Find 3 Numbers according to 5 Rules

	Rule (1) : Correct Number in Correct Position 		 : [6 8 2]
	Rule (2) : Correct Number in Wrong Position 		 : [6 1 4]
	Rule (3) : Two Numbers are correct but in wrong position : [2 0 6]
	Rule (4) : Nothing is correct 				 : [7 3 8]
	Rule (5) : Correct Number in wrong Position 		 : [7 8 0]
	" + nl
	drawline()
	see nl
	for n1 = 0 to 9
		for n2 = 0 to 9
			for n3 = 0 to 9
				see copy(" ",8) + "Number : " + n1 + " - " + n2 + " - " + n3 
				if check(n1,n2,n3)
					exit 3
				ok
			next
		next
	next
	see nl
	drawline()

func DrawLine 
	see Copy("=",80) + nl

func check n1,n2,n3
	see " ---> "
	if 	rule1(n1,n2,n3) and 
		rule2(n1,n2,n3) and 
		rule3(n1,n2,n3) and 
		rule4(n1,n2,n3) and 
		rule5(n1,n2,n3) 
		see "True" + nl		
		return True
	ok
	see "False" + nl
	return False


# Rule (1) : Correct Number in Correct Position : [6 8 2]
func rule1 n1,n2,n3
	if n1=6 or n2=8 or n3=2
		return True 
	ok
	return false 

# Rule (2) : Correct Number in Wrong Position : [6 1 4]
func rule2 n1,n2,n3
	if (n2=6 or n3=6) or
	   (n1=1 or n3=1) or 
	   (n1=4 or n2=4)
		return True
	ok
	return false 

# Rule (3) : Two Numbers are correct but in wrong position : [2 0 6]
func rule3 n1,n2,n3
	aList = [n1,n2,n3]
	if 	find(aList,2) and find(aList,0) and not find(aList,6) 
		if n1 != 2 and n3 != 0 
			return True	
		ok   
	ok
	if	find(aList,2) and find(aList,6) and not find(aList,0)  
		if n1 != 2 and n3 != 6
			return True 
		ok
	ok
	if	find(aList,6) and find(aList,0) and not find(aList,2) 
		if n2 != 6 and n3 != 0
			return True 
		ok		
	ok
	return False

# Rule (4) : Nothing is correct : [7 3 8]
func rule4 n1,n2,n3
	aList = [n1,n2,n3]
	if not (find(aList,7) or find(aList,3) or find(aList,8))
		return True
	ok
	return false 

# Rule (5) : Correct Number in wrong Position : [7 8 0]
func rule5 n1,n2,n3
	if (n2=7 or n3=7) or 
	   (n1=8 or n3=8) or
	   (n1=0 or n2=0)
		return True 
	ok
	return false 
