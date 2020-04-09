/*
	name 		: Mostafa Abdullah Adam 
	App 		: Test 16 ( Lists v.4) 
	Date 		: 2017-12-11 
*/ 
#=======================================================
     // Variables types ( str , num ,[ list ], obj , c obj )
#=======================================================

		#===============================#
		//List -----> Aray , list , ...etc 
		      #==================#
# Number = (n)
# string = (c)
# list   = (a)

mylist = []
while true 
	see " 
		(1) Add Number    
		(2) Sum Number
		(3) Play Again 
		(4) Exit
	    "
	give cOpt
	switch copt
		on "1" see " inter Number " give add mylist+add   # Add Number to my list 
		on "2" sum=0 for Nsm in mylist sum = sum+Nsm next # convert (numbers) to Numbers to sum & sum
			? "sum = " + sum			  # Show message with sum 
		on "3" mylist=[] 				  # Empity my list again []
			? "Done"
		on "4" ? "GoodBye " bye				  # To Colse bye or / Shutdown()

		other ? " bad switch "
	off
end






	   		/* End of program */	
##======================================================##
