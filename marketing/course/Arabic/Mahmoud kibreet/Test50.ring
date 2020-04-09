/*
          Application : Functions
          Author      : Mahmoud Kibreet
          Date        : 2018.01.27
*/

func main


while True

	see "

		(1)Hello
		(2)Exit
      "give nOption

	switch nOption
	on "1" hello()
	on "2" closeapplication()
	other ? "Bad option!"
	off
end

? "Thanks!"

func Hello 
? "Enter your name: " give Name ? "Hello" + Name

func closeapplication
	exit         # we can exit from the loop
