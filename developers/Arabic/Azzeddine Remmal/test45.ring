#####################################
# Application  :  Functions
# Author        : Azzeddine Remmal            
# Date           : 08.01.2018                  
####################################

#--------------Functions - Scope - Pass by value - Pass by reference 

? "Hello, World" 

$x = 10	       # -----global 

func main  {
	? "Welcome to the Main function"
	one() 
}

func one  {
	? $x
} 
