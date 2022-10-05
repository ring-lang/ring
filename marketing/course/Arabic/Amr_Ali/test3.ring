/*
	Application	: My First App	
	Author    	: Amr Ali
	Date   		: 07/03/2018
		
*/
put "Enter number 1 : " get n1
put "Enter number 2 : " get n2
#n1 = number(n1)
#n2 = number(n2)
#see "Sum : " see n1 + n2
# Instead of conversion string to number you can use "Weakly Typed"
put "Sum : " + (0 + n1 + n2)
/* 
	you can use put and get instead of see and give
*/ 

// String + (String | Number) -----> String
# Number + (String | Number)  -----> Number
