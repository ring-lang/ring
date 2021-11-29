/*  
 **      Application : Functions 
 **      Author      : Abdelrahman Adam
 **      Date        : 22/12/2017 
*/ 
#======================================================

func main
		while  true
				see "
					 (1) Hello					
				 	 (2) Exit 
							"
				give cOption

			switch cOption
				on "1" hello()
				on "2" closeApplication()
				other ? "bad number"
			off
		
		end
			 ?" thanks !"

func hello
		see "Enter your name : "	give cName
		? "hello " + cname

func closeApplication
		exit						# we can exit from the loop
