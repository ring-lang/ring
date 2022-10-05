/*
          Application        :Functions
          Author             :Islam Deraz
          Date               :2018.03.02
          Application Number :11
*/

func main 
	
	while true 

		see " 
			(1)Hello
			(2)Exit
		    "
		give noption

		switch noption
		on "1" hello()
		on "2" closeapplication()
		other ? "Bad option!"
		off

	end 

			? "thanks"

func Hello	
		? "Enter your name:" give name ? "Hello " + name

func closeapplication
		exit    # we can exit from the loop
