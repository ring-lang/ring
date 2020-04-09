#####################################
# Application  :  Functions
# Author        : Azzeddine Remmal            
# Date           : 08.01.2018                  
####################################



func main 

	while True
	 
		see "
	
			(1) Hello 
			(2) Exit 
	
		" give nOption 
	
		switch nOption
		on "1"  hello()
		on "2"  closeapplication()
		other   ? "Bad option!"
		off 
	end 

	? "Thanks!" 

func Hello 
	? "Enter your name: " give Name ? "Hello " + Name 

func CloseApplication 
	exit 		             # -----We can exit from the loop

