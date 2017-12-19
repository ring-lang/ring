# بسم الله الرحمن الرحيم
// this is Lesson6 -  thanks to Mr.MAHMOUD FAYED
/*
  Application:  Functions 
  Author     :  S.BOURROU
  Date       :  17.12.2017  
*/
load "stdlib.ring"
func main
while true
	see "
		(1) Start counting
		(2) close
	                   "
        give Option
	switch Option
	on "1" ? Splash() count() 
	on "2" ? close()   
	other ? "Sorry !Bad option"
        off			
   end
end
func count
	  	
      ? 1:10
      ? "Done!" 


func Close
      ? "GOODbye!"  sleep(3) 
			 exit
func Splash
      ? "counting.." sleep(3)    
