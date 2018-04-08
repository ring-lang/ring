#####################################
# Application  : Ring Lessons
# Author        : Azzeddine Remmal            
# Date           : 10.01.2018                  
####################################

# -----------eval() and the variable scope 

eval("x = 10")		#----x is global 

? x 

func main 
	eval(" y = 20 " )	#-----y is local
	? y
	test()

func test 
	? x 
	? y			#-----Error 
