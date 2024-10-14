/*
**     App:variables(numbers)
**     Author:Asmaa Samir
**     Date: 18-12-2017
*/
#==========================================================

# numbers type include integer, float,double,boalean(logical) data

	mynum1 = 1       # int
	mynum2 = 1.25    # float|Double
        mynum4 = 2.45    # we can put f or not in float
	mynum3 = True   # Boalean
	mynum5= 1000_000_000 # or mynum5=1000_000_000
        

	
	? mynum1
	? mynum2
	? mynum3
 	? mynum5

#======================================================

#Conversion.
  # use Functions
x = 95
mystr=string(x)  # for conversion to string
mynum=number(mystr) # for conversion to number
  #-----------------------------
  # use operators (faster in performance) such as follwing example
mystr2="" + x   # for convert number to string , add it to empty string
mynum2=0 + mystr2 # add string to 0 to convert it to number
