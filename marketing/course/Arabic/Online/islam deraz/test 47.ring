/*
          Application        :Functions
          Author             :Islam Deraz
          Date               :2018.03.02
          Application Number :8
*/

# functions - scope -	pass by value - pass by reference

# Ring 
# string | number ----> pass by value
# list   | object ----> pass by reference

func main 
	alist= 1:10
	
	alist2= alist
	alist[1]= "one"

	? alist[1]
	? alist2[1]
	
          
