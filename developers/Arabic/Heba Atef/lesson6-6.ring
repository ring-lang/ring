/*     


functions 


*/


func main 

while true  
  see "
(1) hello
(2)exit

"  give noption 
switch noption
on "1" hello()
on "2" closeapp()
other ?"bad"
off
end 
?"thanks" 
func hello 
?"enter your name :" give name? " hello "+ name 
func closeapp 
exit 
